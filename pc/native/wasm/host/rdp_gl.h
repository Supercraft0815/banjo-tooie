// GPU renderer (BT_RENDERER=gpu), included by rdp.c to share its command/TMEM state.
// Fast3D style: triangles and rectangles that land in a VI framebuffer become batched OpenGL draws
// into a high-resolution render target per framebuffer; TMEM tiles are decoded once (decode_texel)
// into a texture atlas keyed by their content. Everything else stays on the software path in RDRAM
// at N64 resolution: the player shadow's CI8 image (its depth tests deferred to the GPU, see
// gpu_mask_defer), the pause menu's copy into Z memory, any image that is not a registered VI
// framebuffer. The game sees N64 pixels where it looks for them:
//   - ordinary hosts resolve their drawn images to RDRAM before the DP event. An image-aware
//     guest can resolve them on first CPU or RDP access with BT_GPU_DEMAND=1. Software fallback
//     and debug-audio hosts keep eager synchronization;
//   - a texture load from a GPU image resolves it first (the bubble's view of the frame, the pause
//     copy), mid-task, instead of syncing every draw;
//   - CPU writes into a framebuffer (debug text, pixel fixes) differ from the last resolve and are
//     imported at the next task or buffer swap, keeping the other subpixels.
//   - the software path drawing into RDRAM resolves what is there first and marks GPU images it
//     overlaps stale (re-imported before the GPU draws into them again);
//   - depth is resolved into Z memory (compressed like the RDP stores it) before CPU reads
//     (1EC1AD0.c), and before the software path draws over Z
//     memory, loads it as a texture or depth-tests against it (the player shadow is a decal).
// The depth clear (fill 0xFFFC into the Z image) runs on both sides.
// CPU and software depth writes replace only changed guest pixels before the next depth draw.
static int gpu_on = -1;
static int gpu_barrier_available = -1;
static int gpu_enabled(void) {
    if (gpu_on < 0) {
        const char *name = getenv("BT_RENDERER");
        if (name && strcmp(name, "soft") && strcmp(name, "gpu")) bt_fatal("BT_RENDERER must be soft or gpu");
        gpu_on = name && !strcmp(name, "gpu");
#ifndef BT_IMAGE_ACCESS_HOST
        if (gpu_on && getenv("BT_GPU_DEMAND") && atoi(getenv("BT_GPU_DEMAND")))
            bt_fatal("BT_GPU_DEMAND=1 needs a release gen/ built with BT_GPU_IMAGE_ACCESS=1");
#endif
#ifndef BT_GPU_OPENGL
        if (gpu_on) bt_fatal("this build has no GPU renderer");
#endif
        if (!gpu_on) fprintf(stderr, "renderer: soft\n");
    }
#ifdef BT_GPU_OPENGL
    if (gpu_on && gpu_barrier_available == 0 && rdp_scale() == 1 &&
        !(atomic_load(&window_pixels) && bt_setting(BT_SET_GPU_WINDOW))) {
        fprintf(stderr, "renderer: soft (exact 1x GPU rendering needs a texture barrier)\n");
        gpu_on = 0;
    }
#endif
    return gpu_on;
}
int rdp_gpu(void) { return gpu_enabled(); }
static void *gpu_share;  // visible window: pictures are shown as textures

#ifdef BT_GPU_OPENGL
#include <SDL3/SDL.h>
#include "glad/gl.h"
#include "rdp_glsl.h"
static SDL_Window *gpu_window;
static PFNGLTEXTUREBARRIERPROC gpu_barrier;

enum { GPU_TRI, GPU_RECT, GPU_TEXRECT, GPU_COPY, GPU_FILL };  // material modes, as in the shader
#define GPU_ATLAS 4096      // texels per side of the texture atlas (RGBA8UI)
#define GPU_TEXTURES 16384  // texture cache slots; the atlas starts over at half load
#define GPU_RECORD 80       // u32 words of the largest material: 16 header + 8 tiles * 8

typedef struct { float pos[4], shade[4], st[2]; u32 mat; } GpuVertex;
typedef struct {
    u32 address;
    int width, height, pw, ph; // N64 dimensions and physical texels
    float sx, sy;
    int drawn, changed;         // since the last resolve / since the last publish
    int stale;                  // the software path drew into its RDRAM (import before the GPU draws again)
    int samples;
    GLuint ms_fbo, ms_color, ms_depth;
    GLuint color, fbo, depth;   // depth: the shared Z texture, or the in-between target's own
    u8 *shadow;                 // RDRAM bytes after the last resolve or import
} GpuTarget;
// rmw: the blender reads memory at scale 1; such batches draw one triangle at a time and blend in the
// shader against the target itself (texture barrier), so every blend step rounds to RGBA5551 like rdp.c.
typedef struct { GLuint name; GLint scale,frame,color16,rmw,soften; } DrawProgram;
typedef struct { const DrawProgram *program; GpuTarget *t; GLenum zfunc; GLboolean zmask; int decal, rmw, sc[4], first, count; } GpuBatch;
// border: what each of the 8 one-texel border pieces (L R T B, then corners LT RT LB RB) last got copied
// from, as atlas source x | y << 16 plus 1 (0: never written); see gpu_seams.
typedef struct { u64 key; u32 gen; u16 x, y; u32 border[8], stamp; int idx; } GpuTexture;
typedef struct { u64 gen; u32 tlut, agen; Tile desc; u16 x, y, w, h; int slot; } GpuTileMemo;
// A filtered triangle that maps one clamped tile edge to edge (gpu_seams); x, y, s, t per corner.
typedef struct { int slot; u16 w, h; u32 image; float v[3][4]; } GpuPiece;

static struct {
    SDL_GLContext context;
    GLuint draw, import, resolve, zresolve, maskcopy, maskfrag;  // programs
    GLint i_scale, i_every, i_depth, r_scale, z_scale, mc_off, mc_ia, mf_size;
    GLuint vao, vbo, empty_vao, mat_buffer, mat_texture, atlas, depth, import_tex[2], resolve_tex, resolve_fbo;
    GLuint blank;  // sampled as dst outside rmw batches (an empty unit makes the driver complain)
    GLuint atlas_fbo;  // the atlas as blit source and target for seam borders
    GpuPiece *piece; int npiece, cap_piece; u32 seam_stamp;
    int max_size, max_samples, depth_samples;
    u8 *zshadow; u32 zimage; int zw, zh, zvalid, zcheck;
    GLuint ms_depth;
    int depth_w, depth_h, resolve_w, resolve_h, import_w, import_h;
    GpuTarget t[3], ipt, pre, none;  // VI framebuffers, in-between image and its starting picture
    // The 8-bit image with its deferred fragments (rdp.c mdefer): R8 at N64 size, composed for loads
    // (mask_composed); mz: N64 depth (RDRAM bytes) the fragments test against, current while
    // mz_gen == zgen; mz_cpu: the same bytes on the CPU when they came from RDRAM.
    struct {
        float (*vertices)[4]; int n, capacity, other, ready, w, h;
        GLuint texture, fbo, vao, buffer, program;
        u32 clear_address;
    } shadow;
    GpuTarget mask; u32 mask_uid; int mask_composed;
    GLuint upbo, dpbo;  // texture uploads and readbacks go through them (gpu_upload, gpu_readback)
    // The task end's readbacks (gpu_end), queued behind one fence until gpu_finish: picture: the
    // target whose picture goes to scanout, else dst (and also) get the bytes.
    struct { GLuint pbo; size_t size, n; u8 *dst, *also; GpuTarget *picture; } rd[8];
    int nrd, queuing;
    GLsync fence;
    // Direct presentation (gpu_show): a copy of each published picture the renderer no longer draws
    // into. Only published, used sizes allocate texture storage.
    struct { GLuint tex; GLsync ready, consumed; int w, h; } show[
        sizeof scanout / sizeof *scanout + sizeof ip_out / sizeof *ip_out + 2];
    GLuint displayed;
    GLuint show_fbo;
    struct { GLuint fbo, tex, program; GLint size; u32 stored_at; int w,h,guest_w; u8 *bytes; size_t length,capacity; } backdrop;
    GLuint mz_tex, mz_fbo, frag_vao, frag_vbo; int mz_w, mz_h, mz_from_gpu; u32 zgen, mz_gen, mz_zimg;
    u8 *mz_cpu; size_t mz_cpu_n;
    GpuTarget *zt; u32 zaddr;  // depth drawn into t's Z texture since it was last written to RDRAM at zaddr
    GpuVertex *v; int nv, cap_v;
    u32 *m; int nm, cap_m, last_m, last_n, last_key[4];
    u64 last_gen;  // state_gen of the last material
    GpuBatch *b; int nb, cap_b;
    GpuTexture *tex; u32 atlas_gen; int ntex, ax, ay, shelf;
    GpuTileMemo memo[8];
    u64 hash_gen, hash;
    u32 *decode, *pixels, frame;
    size_t pixels_n;
    unsigned draws, batches, uploads, resolves, imports, mask_copies;  // BT_RENDER_STATS
} gpu = {.last_m = -1, .atlas_gen = 1};

static void gpu_check(const char *what) {
    GLenum error = glGetError();
    if (error) bt_fatal("OpenGL %s: 0x%x", what, error);
}

static GLuint gpu_build_program(const char *vs_text, const char *fs_text, int optional) {
    GLuint p = glCreateProgram();
    const char *text[2] = {vs_text, fs_text};
    for (int i = 0; i < 2; i++) {
        GLuint s = glCreateShader(i ? GL_FRAGMENT_SHADER : GL_VERTEX_SHADER);
        GLint ok;
        glShaderSource(s, 1, &text[i], NULL);
        glCompileShader(s);
        glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
        if (!ok) {
            char log[4096]; glGetShaderInfoLog(s, sizeof log, NULL, log);
            if (!optional) bt_fatal("OpenGL shader: %s",log);
            fprintf(stderr,"GPU shader specialization: %s\n",log);
            glDeleteShader(s); glDeleteProgram(p); return 0;
        }
        glAttachShader(p, s);
        glDeleteShader(s);
    }
    GLint ok;
    glLinkProgram(p);
    glGetProgramiv(p, GL_LINK_STATUS, &ok);
    if (!ok) {
        char log[4096]; glGetProgramInfoLog(p,sizeof log,NULL,log);
        if (!optional) bt_fatal("OpenGL link: %s",log);
        fprintf(stderr,"GPU shader specialization: %s\n",log); glDeleteProgram(p); return 0;
    }
    return p;
}

static GLuint gpu_program(const char *vs, const char *fs) { return gpu_build_program(vs, fs, 0); }
#include "rdp_gl_programs.h"

static void gpu_texture(GLuint *tex, GLenum internal, int w, int h, GLenum format, GLenum type) {
    if (!*tex) glGenTextures(1, tex);
    glBindTexture(GL_TEXTURE_2D, *tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, internal, w, h, 0, format, type, NULL);
}

// texel rows into the bound GL_TEXTURE_2D: through a buffer with new storage each time, so the copy is
// queued on the GPU instead of the CPU waiting until draws that use the texture are done.
static void gpu_upload(int x, int y, int w, int h, GLenum format, GLenum type, int bpp, const void *data) {
    if (!gpu.upbo) glGenBuffers(1, &gpu.upbo);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, gpu.upbo);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, (GLsizeiptr)w * h * bpp, data, GL_STREAM_DRAW);  // unpack alignment 1
    glTexSubImage2D(GL_TEXTURE_2D, 0, x, y, w, h, format, type, NULL);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}

// Rows of the bound read framebuffer into dst: the GPU copies them into a buffer (it converts the
// tiled image; glReadPixels into client memory converts on the CPU), then the CPU copies them out.
// While gpu.queuing (the task end) the copy waits in a buffer of its own for gpu_finish.
static void gpu_readback(int w, int h, GLenum format, GLenum type, int bpp, void *dst, void *also, GpuTarget *picture) {
    size_t n = (size_t)w * h * bpp;
    GLuint *pbo = &gpu.dpbo;
    if (gpu.queuing) {
        if (gpu.nrd == (int)(sizeof gpu.rd / sizeof gpu.rd[0])) bt_fatal("too many readbacks in one task");
        typeof(gpu.rd[0]) *r = &gpu.rd[gpu.nrd++];
        r->n = n; r->dst = dst; r->also = also; r->picture = picture;
        pbo = &r->pbo;
    }
    if (!*pbo) glGenBuffers(1, pbo);
    glBindBuffer(GL_PIXEL_PACK_BUFFER, *pbo);
    glBufferData(GL_PIXEL_PACK_BUFFER, (GLsizeiptr)n, NULL, GL_STREAM_READ);  // pack alignment 1
    glReadPixels(0, 0, w, h, format, type, NULL);
    if (!gpu.queuing) {
        const void *src = glMapBufferRange(GL_PIXEL_PACK_BUFFER, 0, (GLsizeiptr)n, GL_MAP_READ_BIT);
        if (!src) bt_fatal("OpenGL readback map: 0x%x", glGetError());
        memcpy(dst, src, n);
        if (also) memcpy(also, src, n);
        glUnmapBuffer(GL_PIXEL_PACK_BUFFER);
    }
    glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
}

// The task end's completion (gpu_finish, gpu_done_main).
static struct {
    SDL_GLContext context;  // the completion thread's, in the share group of gpu.context
    pthread_mutex_t lock; pthread_cond_t cond;
    int state;    // 0 nothing pending, 1 queued, 2 being completed (here by gpu_finish, or on the thread)
    int handoff;  // the thread's turn; it raises event when done
    u32 event;
} done = {.lock = PTHREAD_MUTEX_INITIALIZER, .cond = PTHREAD_COND_INITIALIZER};
static void *gpu_done_main(void *arg);

static void gpu_offscreen(void) {
    if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) bt_fatal("SDL video: %s", SDL_GetError());
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
    gpu_window = SDL_CreateWindow("Banjo-Tooie offscreen", 32, 32, SDL_WINDOW_HIDDEN | SDL_WINDOW_OPENGL);
    if (!gpu_window || !SDL_GL_CreateContext(gpu_window)) bt_fatal("SDL offscreen context: %s", SDL_GetError());
}

static void gpu_load_gl(void) {
    int version = gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);
    if (!version) bt_fatal("loading OpenGL functions: %s", SDL_GetError());
    int core_barrier = GLAD_VERSION_MAJOR(version) > 4 ||
                      (GLAD_VERSION_MAJOR(version) == 4 && GLAD_VERSION_MINOR(version) >= 5);
    if (core_barrier || GLAD_GL_ARB_texture_barrier)
        gpu_barrier = (PFNGLTEXTUREBARRIERPROC)SDL_GL_GetProcAddress("glTextureBarrier");
    if (!gpu_barrier && GLAD_GL_NV_texture_barrier) gpu_barrier = glTextureBarrierNV;
    gpu_barrier_available = gpu_barrier != NULL;
}

// Main thread only; NULL creates a hidden surface for headless games and renderer tests.
void rdp_gpu_share(void *window) {
    gpu_share = window;
    gpu_window = window;
    if (!gpu_window) {
        if (!gpu_enabled()) return;
        gpu_offscreen();
    }
    SDL_GLContext display = SDL_GL_GetCurrentContext();
    gpu_load_gl();
    if (!gpu_enabled()) return;
    if (!SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1)) bt_fatal("SDL GL sharing: %s", SDL_GetError());
    gpu.context = SDL_GL_CreateContext(gpu_window);
    if (!gpu.context || !SDL_GL_MakeCurrent(gpu_window, display)) bt_fatal("SDL render context: %s", SDL_GetError());
    done.context = SDL_GL_CreateContext(gpu_window);
    if (!done.context || !SDL_GL_MakeCurrent(gpu_window, display)) bt_fatal("SDL completion context: %s", SDL_GetError());
    if (!getenv("BT_GPU_SPECIALIZE") || atoi(getenv("BT_GPU_SPECIALIZE"))) {
        programs.context=SDL_GL_CreateContext(gpu_window);
        if (!SDL_GL_MakeCurrent(gpu_window,display)) bt_fatal("restoring SDL display context: %s",SDL_GetError());
    }
    SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 0);
}

// VI buffer swaps and graphics tasks run on different host threads. WGL requires an
// explicit release by the previous owner before another thread can bind the context.
static _Thread_local SDL_GLContext previous_context;
static void gpu_release(void) {
    if (!SDL_GL_MakeCurrent(previous_context ? gpu_window : NULL, previous_context))
        bt_fatal("releasing SDL render context: %s", SDL_GetError());
}

static void gpu_init(void) {
    previous_context = SDL_GL_GetCurrentContext();
    if (!gpu.context || !SDL_GL_MakeCurrent(gpu_window, gpu.context)) bt_fatal("SDL render context: %s", SDL_GetError());
    if (gpu.draw) return;
    pthread_t completion;
    if (pthread_create(&completion, NULL, gpu_done_main, NULL)) bt_fatal("starting the GPU completion thread");
    pthread_detach(completion);

    GLint max_tex, max_rb;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_tex);
    glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, &max_rb);
    glGetIntegerv(GL_MAX_SAMPLES, &gpu.max_samples);
    gpu.max_size = max_tex < max_rb ? max_tex : max_rb;
    gpu.draw = gpu_program(gpu_vertex_shader, gpu_fragment_shader);
    programs.generic=draw_program(gpu.draw);
    if (programs.context) {
        pthread_t worker;
        if (!pthread_create(&worker,NULL,compile_draw_programs,NULL)) pthread_detach(worker);
        else programs.context=NULL;
    }
    gpu.import = gpu_program(gpu_fullscreen_shader, gpu_import_shader);
    gpu.resolve = gpu_program(gpu_fullscreen_shader, gpu_resolve_shader);
    gpu.zresolve = gpu_program(gpu_fullscreen_shader, gpu_zresolve_shader);
    gpu.maskcopy = gpu_program(gpu_fullscreen_shader, gpu_maskcopy_shader);
    gpu.maskfrag = gpu_program(gpu_maskfrag_vertex_shader, gpu_maskfrag_shader);
    glUseProgram(gpu.maskcopy);
    glUniform1i(glGetUniformLocation(gpu.maskcopy, "image"), 2);
    gpu.mc_off = glGetUniformLocation(gpu.maskcopy, "off");
    gpu.mc_ia = glGetUniformLocation(gpu.maskcopy, "ia");
    glUseProgram(gpu.maskfrag);
    glUniform1i(glGetUniformLocation(gpu.maskfrag, "mz"), 5);
    gpu.mf_size = glGetUniformLocation(gpu.maskfrag, "size");
    glUseProgram(gpu.import);
    glUniform1i(glGetUniformLocation(gpu.import, "image"), 2);
    glUniform1i(glGetUniformLocation(gpu.import, "shadow"), 3);
    gpu.i_scale = glGetUniformLocation(gpu.import, "scale");
    gpu.i_every = glGetUniformLocation(gpu.import, "every");
    gpu.i_depth = glGetUniformLocation(gpu.import, "isDepth");
    glUseProgram(gpu.resolve);
    glUniform1i(glGetUniformLocation(gpu.resolve, "color"), 2);
    gpu.r_scale = glGetUniformLocation(gpu.resolve, "scale");
    glUseProgram(gpu.zresolve);
    glUniform1i(glGetUniformLocation(gpu.zresolve, "depth"), 2);
    gpu.z_scale = glGetUniformLocation(gpu.zresolve, "scale");
    glActiveTexture(GL_TEXTURE4);
    gpu_texture(&gpu.blank, GL_RGBA8, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE);
    glActiveTexture(GL_TEXTURE5);
    gpu_texture(&gpu.mz_tex, GL_RG8UI, 1, 1, GL_RG_INTEGER, GL_UNSIGNED_BYTE);  // stays bound to unit 5
    glActiveTexture(GL_TEXTURE0);
    glGenVertexArrays(1, &gpu.empty_vao);
    glGenVertexArrays(1, &gpu.vao);
    glBindVertexArray(gpu.vao);
    glGenBuffers(1, &gpu.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, gpu.vbo);
    for (int i = 0; i < 3; i++) glEnableVertexAttribArray(i);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GpuVertex), (void *)offsetof(GpuVertex, pos));
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GpuVertex), (void *)offsetof(GpuVertex, shade));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(GpuVertex), (void *)offsetof(GpuVertex, st));
    glEnableVertexAttribArray(3);
    glVertexAttribIPointer(3, 1, GL_UNSIGNED_INT, sizeof(GpuVertex), (void *)offsetof(GpuVertex, mat));
    glGenBuffers(1, &gpu.mat_buffer);
    glBindBuffer(GL_TEXTURE_BUFFER, gpu.mat_buffer);
    glBufferData(GL_TEXTURE_BUFFER, 16, NULL, GL_STREAM_DRAW);
    glGenTextures(1, &gpu.mat_texture);
    glBindTexture(GL_TEXTURE_BUFFER, gpu.mat_texture);
    glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA32UI, gpu.mat_buffer);
    gpu_texture(&gpu.atlas, GL_RGBA8UI, GPU_ATLAS, GPU_ATLAS, GL_RGBA_INTEGER, GL_UNSIGNED_BYTE);
    gpu.tex = calloc(GPU_TEXTURES, sizeof *gpu.tex);
    glGenFramebuffers(1, &gpu.atlas_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, gpu.atlas_fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gpu.atlas, 0);
    gpu.decode = malloc(1024 * 1024 * sizeof *gpu.decode);
    if (!gpu.tex || !gpu.decode) bt_fatal("allocating the GPU texture cache");
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glEnable(GL_BLEND);
    glBlendFuncSeparate(GL_ONE, GL_SRC1_ALPHA, GL_ONE, GL_ZERO);  // shader term + memory * factor
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_CLAMP);  // the RDP clamps depth instead of clipping at the near/far planes
    glEnable(GL_SCISSOR_TEST);
    glDisable(GL_DITHER);
    gpu_check("setup");
    fprintf(stderr, "renderer: gpu (%s)\n", glGetString(GL_RENDERER));
}

// ---- Render targets
static void gpu_attach(GpuTarget *t) {
    if (!t->fbo) glGenFramebuffers(1, &t->fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, t->fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, t->color, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, t->depth, 0);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) bt_fatal("OpenGL incomplete framebuffer");
}

static int gpu_samples(int width, int height, int w, int h) {
    int level = bt_setting(BT_SET_MSAA);
    if (!level || (width == w && height == h)) return 0;
    int samples = 1 << level;
    while (samples > gpu.max_samples) samples /= 2;
    return samples > 1 ? samples : 0;
}

static GLuint gpu_draw_fbo(const GpuTarget *t) { return t->samples ? t->ms_fbo : t->fbo; }
static void gpu_renderbuffer(GLuint *rb, int samples, GLenum format, int w, int h) {
    if (!*rb) glGenRenderbuffers(1, rb);
    glBindRenderbuffer(GL_RENDERBUFFER, *rb);
    glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples, format, w, h);
}

// Use the same multisample Z buffer for every VI target, just as the guest does.
static void gpu_target_init(GpuTarget *t, u32 address, int width, int height, int w, int h, int own_depth) {
    int samples = gpu_samples(width, height, w, h);
    t->address = address;
    if (t->width == width && t->height == height && t->pw == w && t->ph == h && t->samples == samples && t->color) return;
    t->width = width; t->height = height; t->pw = w; t->ph = h; t->samples = samples;
    t->sx = (float)w / width; t->sy = (float)h / height;
    gpu_texture(&t->color, GL_RGBA8, w, h, GL_RGBA, GL_UNSIGNED_BYTE);
    if (own_depth) gpu_texture(&t->depth, GL_DEPTH_COMPONENT32F, w, h, GL_DEPTH_COMPONENT, GL_FLOAT);
    else {  // VI framebuffers share one Z buffer, as BT shares its Z image between them
        if (gpu.depth_w != w || gpu.depth_h != h || gpu.depth_samples != samples) {
            gpu_texture(&gpu.depth, GL_DEPTH_COMPONENT32F, w, h, GL_DEPTH_COMPONENT, GL_FLOAT);
            if (samples) gpu_renderbuffer(&gpu.ms_depth, samples, GL_DEPTH_COMPONENT32F, w, h);
            else if (gpu.ms_depth) { glDeleteRenderbuffers(1, &gpu.ms_depth); gpu.ms_depth = 0; }
            gpu.depth_w = w; gpu.depth_h = h; gpu.depth_samples = samples;
        }
        t->depth = gpu.depth;
        free(t->shadow);
        t->shadow = calloc((size_t)width * height, 2);
        if (!t->shadow) bt_fatal("allocating a GPU target");
    }
    gpu_attach(t);
    if (samples) {
        gpu_renderbuffer(&t->ms_color, samples, GL_RGBA8, w, h);
        if (own_depth) gpu_renderbuffer(&t->ms_depth, samples, GL_DEPTH_COMPONENT32F, w, h);
        if (!t->ms_fbo) glGenFramebuffers(1, &t->ms_fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, t->ms_fbo);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, t->ms_color);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, own_depth ? t->ms_depth : gpu.ms_depth);
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) bt_fatal("incomplete multisample target");
    } else if (t->ms_fbo) {
        glDeleteFramebuffers(1, &t->ms_fbo); t->ms_fbo = 0;
        glDeleteRenderbuffers(1, &t->ms_color); t->ms_color = 0;
        if (t->ms_depth) { glDeleteRenderbuffers(1, &t->ms_depth); t->ms_depth = 0; }
    }
    if (!own_depth && bt_setting(BT_SET_RENDER_STATS))
        fprintf(stderr, "renderer: target %dx%d -> %dx%d, MSAA %d (driver max %d)\n", width, height, w, h, samples, gpu.max_samples);
    glDisable(GL_SCISSOR_TEST);
    glClearColor(0, 0, 0, 1);
    glClearDepth(1);
    glDepthMask(GL_TRUE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_SCISSOR_TEST);
    if (!own_depth) gpu.zvalid = 0;
    gpu_check("render target");
}

// ---- Texture atlas: decoded tiles keyed by TMEM content, tile layout and TLUT mode
static void gpu_flush(void);
static void gpu_import(GpuTarget *t, int every);
static void gpu_import_depth(GpuTarget *t);
static void gpu_select_depth(GpuTarget *t);
static void gpu_resolve_depth(void);
static void gpu_mask_materialize(void);
static void gpu_mask_copy(const GpuTexture *e, int k, int w, int h, int ia);

// The load record all TMEM bytes of tile tl (w x h texels) come from (gpu_mask_load): its index + 1
// when the atlas can copy them from the CI8 image, 0 when none is owned, -1 otherwise (replay first).
static int gpu_tile_owner(const Tile *tl, int w, int h, int tlut) {
    if ((long)w * h > 65536) return -1;
    int own = -2, mixed = 0;  // -2: no byte seen yet
    for (int t = 0; t < h && !mixed; t++) {
        u32 base = (u32)(tl->tmem * 8 + t * tl->line * 8), x = t & 1 ? 4 : 0;
        for (int s = 0; s < w && !mixed; s++) {
            u32 a[4];
            int n = 1;
            if (tl->siz == 0) a[0] = (base + (u32)(s >> 1)) ^ x;
            else if (tl->siz == 1) a[0] = (base + (u32)s) ^ x;
            else if (tl->siz == 2) { a[0] = (base + (u32)s * 2) ^ x; a[1] = a[0] + 1; n = 2; }
            else { a[0] = ((base + (u32)s * 2) ^ x) & 0x7FF; a[1] = a[0] + 1; a[2] = a[0] | 0x800; a[3] = a[1] | 0x800; n = 4; }
            for (int i = 0; i < n; i++) {
                int o = R.tsrc[a[i] & 0xFFF];
                if (own == -2) own = o;
                else if (o != own) mixed = 1;
            }
        }
    }
    if (tlut) {  // the entries rdp.c's palette() reads: 16 at pal for 4-bit tiles, else all 256
        int first = tl->siz == 0 ? tl->pal << 4 : 0, n = tl->siz == 0 ? 16 : 256;
        for (int e = first; e < first + n && !mixed; e++) mixed = R.tsrc[0x800 + e * 8] || R.tsrc[0x801 + e * 8];
    }
    if (mixed) return -1;
    if (own <= 0) return 0;
    const typeof(R.trec[0]) *r = &R.trec[own - 1];
    return tl->siz == 1 && !tlut && tl->tmem == r->tmem && tl->line == r->line && w <= r->w && h <= r->h ? own : -1;
}

static void gpu_atlas_reset(void) {
    gpu_flush();  // queued draws still sample the old atlas
    gpu.atlas_gen++;
    gpu.ntex = gpu.ax = gpu.ay = gpu.shelf = 0;
}

static u64 gpu_mix(u64 h, u64 v) { h = (h ^ v) * 0x9E3779B97F4A7C15ull; return h ^ h >> 29; }

static u64 gpu_tmem_hash(void) {
    if (gpu.hash_gen != tmem_gen) {
        u64 h = 0x84222325CBF29CE4ull, w;
        for (int i = 0; i < 4096; i += 8) { memcpy(&w, R.tmem + i, 8); h = gpu_mix(h, w); }
        gpu.hash = h; gpu.hash_gen = tmem_gen;
    }
    return gpu.hash;
}

// Atlas place of tile i as the shader samples it: texel (s, t) for s < w, t < h after wrapping.
static void gpu_tile_image(int i, u16 *x, u16 *y, u16 *pw, u16 *ph) {
    const Tile *tl = &R.tile[i & 7];
    GpuTileMemo *memo = &gpu.memo[i & 7];
    u32 tlut = R.om_h >> 14 & 3;
    if (memo->gen == tmem_gen && memo->agen == gpu.atlas_gen && memo->tlut == tlut && !memcmp(&memo->desc, tl, sizeof *tl)) {
        *x = memo->x; *y = memo->y; *pw = memo->w; *ph = memo->h;
        return;
    }
    int ms = (tl->lrs - tl->uls) >> 2, mt = (tl->lrt - tl->ult) >> 2;
    int w = tl->masks ? 1 << (tl->masks < 10 ? tl->masks : 10) : ms < 0 ? 1 : ms > 1023 ? 1024 : ms + 1;
    int h = tl->maskt ? 1 << (tl->maskt < 10 ? tl->maskt : 10) : mt < 0 ? 1 : mt > 1023 ? 1024 : mt + 1;
    int own = R.tsrc_live ? gpu_tile_owner(tl, w, h, (int)(R.om_h >> 15 & 1)) : 0;
    if (own < 0) { gpu_mask_materialize(); own = 0; }
    u64 key = own ? gpu_mix(gpu_mix(0x4D41534Bull << 32 | R.trec[own - 1].uid, (u64)(tl->fmt == 3)), (u64)w | (u64)h << 16) :
                    gpu_mix(gpu_mix(gpu_tmem_hash(), (u64)tl->fmt | (u64)tl->siz << 3 | (u64)tl->line << 5 | (u64)tl->tmem << 14 |
                                                     (u64)tl->pal << 23 | (u64)tlut << 27), (u64)w | (u64)h << 16);
    u32 slot = (u32)key & (GPU_TEXTURES - 1);
    while (gpu.tex[slot].gen == gpu.atlas_gen && gpu.tex[slot].key != key) slot = (slot + 1) & (GPU_TEXTURES - 1);
    GpuTexture *e = &gpu.tex[slot];
    if (e->gen != gpu.atlas_gen) {
        if (gpu.ax + w + 2 > GPU_ATLAS) { gpu.ay += gpu.shelf; gpu.ax = gpu.shelf = 0; }  // + 2: seam border
        if (gpu.ay + h + 2 > GPU_ATLAS || gpu.ntex * 2 > GPU_TEXTURES) {
            gpu_atlas_reset();  // the caller rebuilds its material: other tiles of it may be gone
            gpu_tile_image(i, x, y, pw, ph);
            return;
        }
        *e = (GpuTexture){.key = key, .gen = gpu.atlas_gen, .x = (u16)(gpu.ax + 1), .y = (u16)(gpu.ay + 1)};
        gpu.ax += w + 2; if (h + 2 > gpu.shelf) gpu.shelf = h + 2;
        gpu.ntex++;
        if (own) { gpu_mask_copy(e, own - 1, w, h, tl->fmt == 3); goto placed; }
        for (int t = 0; t < h; t++) for (int s = 0; s < w; s++) {
            int o[4];
            decode_texel(tl, s, t, o);
            gpu.decode[t * w + s] = (u32)o[0] | (u32)o[1] << 8 | (u32)o[2] << 16 | (u32)o[3] << 24;
        }
        glBindTexture(GL_TEXTURE_2D, gpu.atlas);
        gpu_upload(e->x, e->y, w, h, GL_RGBA_INTEGER, GL_UNSIGNED_BYTE, 4, gpu.decode);
        gpu.uploads++;
    }
placed:
    *memo = (GpuTileMemo){.gen = tmem_gen, .tlut = tlut, .agen = gpu.atlas_gen, .desc = *tl, .x = e->x, .y = e->y, .w = (u16)w, .h = (u16)h, .slot = (int)slot};
    *x = e->x; *y = e->y; *pw = (u16)w; *ph = (u16)h;
}

static u32 gpu_color(const int *c) { return (u32)c[0] << 24 | (u32)c[1] << 16 | (u32)c[2] << 8 | (u32)c[3]; }
static u32 gpu_sel(const u8 *s) { return (u32)s[0] << 24 | (u32)s[1] << 16 | (u32)s[2] << 8 | s[3]; }

// The shader's view of the RDP state for one draw (layout in rdp_glsl.h); returns its u32 count.
static int gpu_record(u32 *r, int mode, int tex, int tile, int seam) {
    int cycles = (R.om_h >> 20 & 3) == 1 ? 2 : 1, use0 = 0, use1 = 0;
    for (int cycle = cycles == 2 ? 0 : 1; cycle < 2; cycle++) for (int i = 0; i < 4; i++) {
        int rgb = R.rgb[cycle][i], alpha = R.alpha[cycle][i];
        use0 |= rgb == C_T0 || rgb == C_T0_A || alpha == C_T0 || alpha == C_T0_A;
        use1 |= rgb == C_T1 || rgb == C_T1_A || alpha == C_T1 || alpha == C_T1_A;
    }
    int lod = mode == GPU_TRI && tex && (R.om_h >> 16 & 1), cyc = R.om_h >> 20 & 3;
    int filter = cyc < 2 && (R.om_h >> 12 & 3) != 0, persp = mode == GPU_TRI && (R.om_h >> 19 & 1);
    int ntiles = mode == GPU_COPY ? 1 : mode == GPU_TEXRECT || (mode == GPU_TRI && tex) ? (lod ? R.tex_levels + 2 : 2) : 0;
    if (ntiles > 8) ntiles = 8;
    int need0 = mode == GPU_COPY || use0 || (use1 && cycles == 1), need1 = mode != GPU_COPY && use1 && cycles == 2;
    r[0] = R.om_h; r[1] = R.om_l; r[2] = gpu_sel(R.rgb[0]); r[3] = gpu_sel(R.rgb[1]);
    r[4] = gpu_sel(R.alpha[0]); r[5] = gpu_sel(R.alpha[1]);
    r[6] = (u32)mode | (u32)(ntiles > 0) << 3 | (u32)persp << 4 | (u32)filter << 5 | (u32)lod << 6 |
           (u32)(cycles == 2) << 7 | (u32)use0 << 8 | (u32)use1 << 9;
    r[7] = (u32)R.prim_lod | (u32)R.k4 << 8 | (u32)R.k5 << 17;
    r[8] = gpu_color(R.prim); r[9] = gpu_color(R.env); r[10] = gpu_color(R.fog); r[11] = gpu_color(R.blend);
    r[12] = R.fill; r[13] = (u32)tile; r[14] = (u32)ntiles; r[15] = (u32)R.tex_levels;
    for (int i = 0; i < ntiles; i++) {
        const Tile *tl = &R.tile[(tile + i) & 7];
        u32 *o = r + 16 + 8 * i;
        u16 x = 0, y = 0, w = 0, h = 0;
        if (lod ? need0 || need1 : i == 0 ? need0 : need1) gpu_tile_image(tile + i, &x, &y, &w, &h);
        o[0] = x | (u32)y << 16; o[1] = w | (u32)h << 16;
        o[2] = (u32)tl->uls | (u32)tl->ult << 16; o[3] = (u32)tl->lrs | (u32)tl->lrt << 16;
        o[4] = (u32)tl->cms | (u32)tl->cmt << 2 | (u32)tl->masks << 4 | (u32)tl->maskt << 8 |
               (u32)tl->shifts << 12 | (u32)tl->shiftt << 16;
        o[5] = i == 0 ? (u32)seam : 0;  // the shader may read tile 0's seam border (gpu_seams)
        o[6] = o[7] = 0;
    }
    return 16 + 8 * ntiles;
}

// Index (in uvec4 units) of the material for this draw; consecutive equal records are shared.
static u32 gpu_material(int mode, int tex, int tile, int seam) {
    int key[4] = {mode, tex, tile, seam};
    if (gpu.last_gen == state_gen && gpu.last_m >= 0 && !memcmp(key, gpu.last_key, sizeof key)) return (u32)gpu.last_m / 4;
    u32 r[GPU_RECORD], gen;
    int n;
    do { gen = gpu.atlas_gen; n = gpu_record(r, mode, tex, tile, seam); } while (gen != gpu.atlas_gen);
    if (gpu.last_m < 0 || gpu.last_n != n || memcmp(gpu.m + gpu.last_m, r, (size_t)n * 4)) {
        if (gpu.nm + n > gpu.cap_m) {
            gpu.cap_m = (gpu.nm + n) * 2;
            if (!(gpu.m = realloc(gpu.m, (size_t)gpu.cap_m * 4))) bt_fatal("allocating GPU materials");
        }
        memcpy(gpu.m + gpu.nm, r, (size_t)n * 4);
        gpu.last_m = gpu.nm; gpu.last_n = n;
        gpu.nm += n;
    }
    gpu.last_gen = state_gen;
    memcpy(gpu.last_key, key, sizeof key);
    return (u32)gpu.last_m / 4;
}

// ---- Draws
// The GPU image the current color image draws into; NULL: the software path; &gpu.none: nothing
// (in-between passes draw only their scanout image).
static void gpu_mask_finalize(void);
static int gpu_mask_defer(void);
static void gpu_mask_depth(int w, int h);
static int gpu_pick_triangle;  // gpu_pick is called for a triangle (the draws rdp.c can defer)

static GpuTarget *gpu_pick(int uses_depth) {
    mdefer.on = 0;
    if (ip.on) return R.cimg == ip.address && R.cimg_siz == 2 && R.cimg_width == gpu.ipt.width ? &gpu.ipt : &gpu.none;
    for (int i = 0; i < 3; i++) {
        GpuTarget *t = &gpu.t[i];
        if (t->color && R.cimg_siz == 2 && t->address == R.cimg && t->width == R.cimg_width) {
            if (t->stale) { t->stale = 0; gpu_import(t, 0); }
            if (uses_depth && R.zimg && (R.om_l & 0x30)) gpu_import_depth(t);
            return t;
        }
    }
    if (gpu_pick_triangle && gpu_mask_defer()) return NULL;  // rdp.c draws it, depth tests deferred
    // The software path reads TMEM, RDRAM and the noise state: deferred fragments are resolved and loads
    // from them replayed first; depth it may write is new.
    gpu_mask_materialize();
    gpu_mask_finalize();
    gpu.zgen++;
    // The software path draws into RDRAM (e.g. the player shadow's CI8 image in the third framebuffer,
    // the pause backdrop in Z memory): GPU images and depth there are written out first, and so is the
    // depth its Z test reads (the shadow is a decal against the scene's depth).
    gpu_resolve_address(R.cimg);
    if (R.cimg >= gpu.zimage && (u64)R.cimg < (u64)gpu.zimage + (u64)gpu.zw * gpu.zh * 2) gpu.zcheck = 1;
    if (R.om_l & 0x20) gpu.zcheck = 1;
    if (gpu.zt && R.zimg == gpu.zaddr && (R.om_l & 0x30)) gpu_resolve_depth();
    for (int i = 0; i < 3; i++)
        if (gpu.t[i].color && R.cimg >= gpu.t[i].address && (u64)R.cimg < (u64)gpu.t[i].address + (u64)gpu.t[i].width * gpu.t[i].height * 2)
            gpu.t[i].stale = 1;
    return NULL;
}

static void gpu_scissor(const GpuTarget *t, int *sc) {
    int x1 = R.sc_x1 * t->sx * .25f, y1 = R.sc_y1 * t->sy * .25f;
    sc[0] = R.sc_x0 * t->sx * .25f; sc[1] = R.sc_y0 * t->sy * .25f;
    sc[2] = x1 < t->pw ? x1 : t->pw;
    sc[3] = y1 < t->ph ? y1 : t->ph;
}

static void gpu_emit(GpuTarget *t, const GpuVertex *v, int n, int zon) {
    GLenum zfunc = zon && (R.om_l & 0x10) ? GL_LEQUAL : GL_ALWAYS;
    GLboolean zmask = zon && (R.om_l & 0x20);
    int decal = zfunc == GL_LEQUAL && (R.om_l >> 10 & 3) == 3, sc[4];
    u32 bl = R.om_l >> 16;
    int cyc = R.om_h >> 20 & 3, sh = cyc == 1 ? 0 : 2;  // the last blender cycle's selector shift
    int rmw = t->sx == 1 && t->sy == 1 && cyc < 2 &&
              ((cyc == 1 && ((bl >> 14 & 3) == 1 || (bl >> 6 & 3) == 1)) || (bl >> (12 + sh) & 3) == 1 ||
               ((R.om_l & 0x4000) && (bl >> (4 + sh) & 3) == 1));
    gpu_scissor(t, sc);
    const DrawProgram *program=select_draw_program(gpu.m+4*v[0].mat);
    GpuBatch *b = gpu.nb ? &gpu.b[gpu.nb - 1] : NULL;
    if (!b || b->program != program || b->t != t || b->zfunc != zfunc || b->zmask != zmask || b->decal != decal || b->rmw != rmw ||
        memcmp(b->sc, sc, sizeof sc)) {
        if (gpu.nb == gpu.cap_b && !(gpu.b = realloc(gpu.b, (size_t)(gpu.cap_b = gpu.cap_b * 2 + 64) * sizeof *gpu.b)))
            bt_fatal("allocating GPU batches");
        b = &gpu.b[gpu.nb++];
        *b = (GpuBatch){.program=program, .t = t, .zfunc = zfunc, .zmask = zmask, .decal = decal, .rmw = rmw, .first = gpu.nv};
        memcpy(b->sc, sc, sizeof sc);
    }
    if (gpu.nv + n > gpu.cap_v && !(gpu.v = realloc(gpu.v, (size_t)(gpu.cap_v = (gpu.nv + n) * 2) * sizeof *gpu.v)))
        bt_fatal("allocating GPU vertices");
    memcpy(gpu.v + gpu.nv, v, (size_t)n * sizeof *v);
    gpu.nv += n;
    b->count += n;
    t->drawn = t->changed = 1;
    if (zmask && t != &gpu.ipt) { gpu.zt = t; gpu.zaddr = R.zimg; gpu.zgen++; }
    gpu.draws++;
}

// x, y in N64 pixels of t, z in 18-bit depth units, w the clip w; st in texels * 32.
static void gpu_vertex(GpuVertex *o, const GpuTarget *t, float x, float y, float z, float w, const float *c, float s, float tt, u32 mat) {
    float nx = x * 2.0f / (float)t->width - 1, ny = y * 2.0f / (float)t->height - 1, nz = z * (2.0f / 0x40000) - 1;
    *o = (GpuVertex){{nx * w, ny * w, nz * w, w}, {0}, {s, tt}, mat};
    if (c) memcpy(o->shade, c, sizeof o->shade);
}

// ---- Tile seams (above 1x). Big images are drawn as a grid of triangles, one clamped tile each (the
// title logo: 32x32 RGBA32 pieces, st -0.5 .. 31.5). Bilinear filtering cannot reach the next tile's
// texels at a piece's edge, so the RDP clamps there: a flat half texel on each side and a hard step,
// invisible at 320x240 but a visible line at 4x. As other N64 renderers do for split images, pieces that
// share a screen edge with continuous texture coordinates are linked, and each tile's one-texel border
// in the atlas gets the neighbor's texels (unlinked edges replicate, exactly the clamp). Only these
// draws read the border (material flag), and 1x stays exact for the oracle.
enum { SEAM_L, SEAM_R, SEAM_T, SEAM_B };

// Edge kind of corners i, j on axis a (0 s, 1 t) of an n-texel tile: SEAM_L/T, SEAM_R/B or -1.
static int gpu_seam_edge(float (*v)[4], int i, int j, int a, int n) {
    float c = v[i][2 + a];
    if (fabsf(c - v[j][2 + a]) > 0.01f) return -1;
    if (c >= -1.01f && c <= 0.01f) return a ? SEAM_T : SEAM_L;
    if (c >= n - 1.01f && c <= n + 0.01f) return a ? SEAM_B : SEAM_R;
    return -1;
}

static int gpu_clamped_tile(const GpuTarget *t, int tile) {
    if (t->sx == 1 && t->sy == 1) return 0;
    if ((R.om_h >> 20 & 3) >= 2 || !(R.om_h >> 12 & 3) || (R.om_h >> 16 & 1)) return 0;  // filtered, no LOD
    const Tile *tl = &R.tile[tile & 7];
    int ms = (tl->lrs - tl->uls) >> 2, mt = (tl->lrt - tl->ult) >> 2;
    if (!(tl->cms & 2) || !(tl->cmt & 2) || tl->shifts || tl->shiftt) return 0;
    if (ms < 1 || mt < 1 || ms > 1023 || mt > 1023) return 0;
    if ((tl->masks && ms + 1 != 1 << tl->masks) || (tl->maskt && mt + 1 != 1 << tl->maskt)) return 0;
    return 1;
}
static int gpu_seam_tile(const GpuTarget *t, const RdpVtx *const *in) {
    const Tile *tl = &R.tile[R.tex_tile & 7];
    if (!gpu_clamped_tile(t, R.tex_tile) || tl->uls || tl->ult) return 0;
    int ms = (tl->lrs - tl->uls) >> 2, mt = (tl->lrt - tl->ult) >> 2;
    float v[3][4];
    for (int i = 0; i < 3; i++) { v[i][0] = in[i]->x; v[i][1] = in[i]->y; v[i][2] = in[i]->s / 32; v[i][3] = in[i]->t / 32; }
    for (int i = 0; i < 3; i++)
        if (gpu_seam_edge(v, i, (i + 1) % 3, 0, ms + 1) >= 0 || gpu_seam_edge(v, i, (i + 1) % 3, 1, mt + 1) >= 0) return 1;
    return 0;
}

static void gpu_piece(const RdpVtx *const *in, int tile, u32 image) {
    const GpuTileMemo *memo = &gpu.memo[tile & 7];
    if (memo->gen != tmem_gen || memo->agen != gpu.atlas_gen ||
        memcmp(&memo->desc, &R.tile[tile & 7], sizeof memo->desc)) return;
    if (gpu.npiece == gpu.cap_piece &&
        !(gpu.piece = realloc(gpu.piece, (size_t)(gpu.cap_piece = gpu.cap_piece * 2 + 64) * sizeof *gpu.piece)))
        bt_fatal("allocating GPU seam pieces");
    GpuPiece *p = &gpu.piece[gpu.npiece++];
    p->image = image; p->slot = memo->slot; p->w = memo->w; p->h = memo->h;
    for (int i = 0; i < 3; i++) {
        p->v[i][0] = in[i]->x; p->v[i][1] = in[i]->y; p->v[i][2] = in[i]->s / 32; p->v[i][3] = in[i]->t / 32;
    }
}

typedef struct { int p0[2], p1[2], piece, kind; float a, b; } GpuSeamEdge;  // a, b: the other coordinate at p0, p1

static int gpu_seam_cmp(const void *x, const void *y) {
    const GpuSeamEdge *e = x, *f = y;
    int d = e->p0[0] != f->p0[0] ? e->p0[0] - f->p0[0] : e->p0[1] != f->p0[1] ? e->p0[1] - f->p0[1] :
            e->p1[0] != f->p1[0] ? e->p1[0] - f->p1[0] : e->p1[1] - f->p1[1];
    return d ? d : e->kind - f->kind;
}

// Copies a w x h atlas block from src (x | y << 16) to border piece k of e unless it already came from there.
static void gpu_border(GpuTexture *e, int k, u32 src, int dx, int dy, int w, int h) {
    if (e->border[k] == src + 1) return;
    e->border[k] = src + 1;
    int sx = (int)(src & 0xFFFF), sy = (int)(src >> 16);
    glBlitFramebuffer(sx, sy, sx + w, sy + h, dx, dy, dx + w, dy + h, GL_COLOR_BUFFER_BIT, GL_NEAREST);
}

static void gpu_seams(void) {
    if (!gpu.npiece) return;
    static GpuSeamEdge *edge;
    static int cap_edge, cap_ent, (*nb)[4], *ent;  // per entry of this flush: its first piece, its neighbors' entries
    if (cap_edge < gpu.npiece * 3 && !(edge = realloc(edge, (size_t)(cap_edge = gpu.npiece * 3) * sizeof *edge)))
        bt_fatal("allocating GPU seams");
    if (cap_ent < gpu.npiece && (!(nb = realloc(nb, (size_t)gpu.npiece * sizeof *nb)) ||
                                 !(ent = realloc(ent, (size_t)(cap_ent = gpu.npiece) * sizeof *ent))))
        bt_fatal("allocating GPU seams");
    gpu.seam_stamp++;
    int ne = 0, nent = 0;
    for (int i = 0; i < gpu.npiece; i++) {
        GpuPiece *p = &gpu.piece[i];
        GpuTexture *e = &gpu.tex[p->slot];
        if (e->stamp != gpu.seam_stamp) {
            e->stamp = gpu.seam_stamp; e->idx = nent;
            ent[nent] = i;
            for (int k = 0; k < 4; k++) nb[nent][k] = -1;
            nent++;
        }
        for (int c = 0; c < 3; c++) for (int a = 0; a < 2; a++) {
            int j = (c + 1) % 3, kind = gpu_seam_edge(p->v, c, j, a, a ? p->h : p->w);
            if (kind < 0) continue;
            int q[2][2] = {{(int)lrintf(p->v[c][0] * 16), (int)lrintf(p->v[c][1] * 16)},
                           {(int)lrintf(p->v[j][0] * 16), (int)lrintf(p->v[j][1] * 16)}};
            int sw = q[0][0] > q[1][0] || (q[0][0] == q[1][0] && q[0][1] > q[1][1]);
            GpuSeamEdge *g = &edge[ne++];
            memcpy(g->p0, q[sw], sizeof g->p0); memcpy(g->p1, q[!sw], sizeof g->p1);
            g->piece = i; g->kind = kind;
            g->a = p->v[sw ? j : c][3 - a]; g->b = p->v[sw ? c : j][3 - a];
        }
    }
    qsort(edge, (size_t)ne, sizeof *edge, gpu_seam_cmp);
    for (int i = 0; i < ne; i++) {  // pairs L-R and T-B on the same screen edge, texture continuous across it
        GpuSeamEdge *f = &edge[i];
        if (f->kind != SEAM_L && f->kind != SEAM_T) continue;
        for (int j = i + 1; j < ne && !memcmp(edge[j].p0, f->p0, sizeof f->p0) && !memcmp(edge[j].p1, f->p1, sizeof f->p1); j++) {
            GpuSeamEdge *g = &edge[j];
            const GpuPiece *pf = &gpu.piece[f->piece], *pg = &gpu.piece[g->piece];
            if (pf->image != pg->image || g->kind != f->kind + 1 || pf->slot == pg->slot || pf->w != pg->w || pf->h != pg->h ||
                fabsf(f->a - g->a) > 0.01f || fabsf(f->b - g->b) > 0.01f) continue;
            int A = gpu.tex[pg->slot].idx, B = gpu.tex[pf->slot].idx;  // A's R/B edge meets B's L/T edge
            int *ab = &nb[A][g->kind], *ba = &nb[B][f->kind];
            *ab = *ab == -1 || *ab == B ? B : -2;  // -2: different neighbors in one flush, clamp
            *ba = *ba == -1 || *ba == A ? A : -2;
        }
    }
    glBindFramebuffer(GL_FRAMEBUFFER, gpu.atlas_fbo);
    glDisable(GL_SCISSOR_TEST);
    for (int i = 0; i < nent; i++) {
        const GpuPiece *p = &gpu.piece[ent[i]];
        GpuTexture *e = &gpu.tex[p->slot];
        int x = e->x, y = e->y, w = p->w, h = p->h, n[4];
        GpuTexture *o[4];
        for (int k = 0; k < 4; k++) { n[k] = nb[i][k] >= 0 ? nb[i][k] : -1; o[k] = n[k] >= 0 ? &gpu.tex[gpu.piece[ent[n[k]]].slot] : NULL; }
#define XY(a, b) ((u32)(a) | (u32)(b) << 16)
        gpu_border(e, 0, o[SEAM_L] ? XY(o[SEAM_L]->x + w - 1, o[SEAM_L]->y) : XY(x, y), x - 1, y, 1, h);
        gpu_border(e, 1, o[SEAM_R] ? XY(o[SEAM_R]->x, o[SEAM_R]->y) : XY(x + w - 1, y), x + w, y, 1, h);
        gpu_border(e, 2, o[SEAM_T] ? XY(o[SEAM_T]->x, o[SEAM_T]->y + h - 1) : XY(x, y), x, y - 1, w, 1);
        gpu_border(e, 3, o[SEAM_B] ? XY(o[SEAM_B]->x, o[SEAM_B]->y) : XY(x, y + h - 1), x, y + h, w, 1);
        // corners: the diagonal tile through either neighbor, else the nearer edge texel
        static const int cs[4][2] = {{SEAM_L, SEAM_T}, {SEAM_R, SEAM_T}, {SEAM_L, SEAM_B}, {SEAM_R, SEAM_B}};
        for (int c = 0; c < 4; c++) {
            int hs = cs[c][0], vs = cs[c][1], right = hs == SEAM_R, bottom = vs == SEAM_B, d = -1;
            if (n[hs] >= 0 && nb[n[hs]][vs] >= 0) d = nb[n[hs]][vs];
            else if (n[vs] >= 0 && nb[n[vs]][hs] >= 0) d = nb[n[vs]][hs];
            int ix = right ? 0 : w - 1, iy = bottom ? 0 : h - 1;  // texel of a tile beyond this corner
            u32 src;
            if (d >= 0) src = XY(gpu.tex[gpu.piece[ent[d]].slot].x + ix, gpu.tex[gpu.piece[ent[d]].slot].y + iy);
            else if (o[hs]) src = XY(o[hs]->x + ix, o[hs]->y + (bottom ? h - 1 : 0));
            else if (o[vs]) src = XY(o[vs]->x + (right ? w - 1 : 0), o[vs]->y + iy);
            else src = XY(x + (right ? w - 1 : 0), y + (bottom ? h - 1 : 0));
            gpu_border(e, 4 + c, src, right ? x + w : x - 1, bottom ? y + h : y - 1, 1, 1);
        }
#undef XY
    }
    glEnable(GL_SCISSOR_TEST);
    gpu.npiece = 0;
}

static int gpu_triangle(const RdpVtx *a, const RdpVtx *b, const RdpVtx *c, int flags) {
    if (!gpu_enabled()) return 0;
    gpu_pick_triangle = 1;
    GpuTarget *t = gpu_pick(flags & RDP_Z);
    gpu_pick_triangle = 0;
    if (!t) return 0;
    if (t == &gpu.none || (R.om_h >> 20 & 3) >= 2) return 1;  // no triangles in fill/copy mode
    const RdpVtx *in[3] = {a, b, c};
    int seam = (flags & RDP_TEX) && gpu_seam_tile(t, in);
    u32 mat = gpu_material(GPU_TRI, (flags & RDP_TEX) != 0, R.tex_tile, seam);
    if (seam) gpu_piece(in, R.tex_tile, 0);
    GpuVertex v[3];
    for (int i = 0; i < 3; i++)
        gpu_vertex(&v[i], t, in[i]->x, in[i]->y, R.om_l >> 2 & 1 ? (float)R.prim_z : in[i]->z, in[i]->w,
                   flags & RDP_SHADE ? in[i]->c : NULL, in[i]->s, in[i]->t, mat);
    gpu_emit(t, v, 3, (flags & RDP_Z) && R.zimg);
    return 1;
}

// A rectangle in high-resolution pixels [x0, x1) x [y0, y1); st0 and the steps in texels * 32 per pixel.
static void gpu_quad(GpuTarget *t, int x0, int y0, int x1, int y1, u32 mat, float s0, float t0, float ds, float dt, int flip, int zon) {
    if (x1 <= x0 || y1 <= y0) return;
    float kx = (float)t->sx, ky = (float)t->sy;
    int xs[6] = {x0, x1, x0, x0, x1, x1}, ys[6] = {y0, y0, y1, y1, y0, y1};
    GpuVertex v[6];
    for (int i = 0; i < 6; i++) {
        float a = ((float)(xs[i] - x0) - 0.5f) * ds, b = ((float)(ys[i] - y0) - 0.5f) * dt;  // centers sample like rdp.c
        gpu_vertex(&v[i], t, (float)xs[i] / kx, (float)ys[i] / ky, (float)R.prim_z, 1, NULL,
                   s0 + (flip ? b : a), t0 + (flip ? a : b), mat);
    }
    gpu_emit(t, v, 6, zon && R.zimg);
}

// Texrect strips from a single source image use the same padded tile borders as
// triangles. Local texel coordinates remove the load tile's origin. The endpoints
// describe the command's geometric edges, independently of subpixel sample centers.
static int gpu_rect_pieces(GpuTarget *t, int tile, int xl, int yl, int xh, int yh,
                           u32 st, float ds, float dt, int flip, RdpVtx corners[4]) {
    if (!gpu_clamped_tile(t, tile)) return 0;
    const Tile *tl = &R.tile[tile];
    float s0 = (s16)(st >> 16) - tl->uls * 8, t0 = (s16)st - tl->ult * 8;
    for (int i = 0; i < 4; i++) {
        RdpVtx *v = &corners[i];
        v->x = (i & 1 ? xh : xl) * .25f; v->y = (i & 2 ? yh : yl) * .25f;
        v->s = s0 + (flip ? v->y - yl*.25f : v->x - xl*.25f) * ds;
        v->t = t0 + (flip ? v->x - xl*.25f : v->y - yl*.25f) * dt;
    }
    int w = ((tl->lrs - tl->uls) >> 2) + 1, h = ((tl->lrt - tl->ult) >> 2) + 1;
    // Only full tiles qualify: adjacent glyphs and cropped sprites commonly
    // share a screen edge without sharing the edge of their source image.
    float lo_s = fminf(corners[0].s,corners[3].s)/32, hi_s = fmaxf(corners[0].s,corners[3].s)/32;
    float lo_t = fminf(corners[0].t,corners[3].t)/32, hi_t = fmaxf(corners[0].t,corners[3].t)/32;
    return lo_s >= -1.01f && lo_s <= .01f && hi_s >= w-1.01f && hi_s <= w+.01f &&
           lo_t >= -1.01f && lo_t <= .01f && hi_t >= h-1.01f && hi_t <= h+.01f;
}

static int gpu_texrect(u32 w0, u32 w1, u32 st, u32 dsdt, int flip) {
    if (!gpu_enabled()) return 0;
    GpuTarget *t = gpu_pick((R.om_h >> 20 & 3) < 2 && (R.om_l & 4));
    if (!t) return 0;
    if (t == &gpu.none) return 1;
    float kx = t->sx, ky = t->sy;
    int cyc = R.om_h >> 20 & 3, tile = w1 >> 24 & 7;
    int xh = w0 >> 12 & 0xFFF, yh = w0 & 0xFFF, xl = w1 >> 12 & 0xFFF, yl = w1 & 0xFFF;
    float dsdx = (s16)(dsdt >> 16) / 32.0f, dtdy = (s16)dsdt / 32.0f;  // texels * 32 per N64 pixel
    int x0 = xl * kx * .25f, y0 = yl * ky * .25f, x1, y1;
    if (cyc >= 2) { x1 = ((xh >> 2) + 1) * kx; y1 = ((yh >> 2) + 1) * ky; dsdx /= 4; }
    else { x1 = (int)ceilf(xh * kx * .25f); y1 = (int)ceilf(yh * ky * .25f); }
    RdpVtx corners[4];
    int seam = gpu_rect_pieces(t,tile,xl,yl,xh,yh,st,dsdx,dtdy,flip,corners);
    int record = R.tsrc[(R.tile[tile].tmem * 8) & 4095];
    int silhouette = gpu.shadow.ready && record && R.trec[record-1].timg == R.timg &&
        R.tile[tile].fmt == 2 && R.tile[tile].siz == 1 && !flip && dsdt == 0x04000400 &&
        (s16)(st >> 16) == xl * 8 && (s16)st == yl * 8 && t->pw == gpu.shadow.w && t->ph == gpu.shadow.h;
    u32 mat = gpu_material(cyc == 2 ? GPU_COPY : GPU_TEXRECT, 1, tile, seam | (silhouette ? 2 : 0));
    if (seam) {
        const RdpVtx *first[] = {corners,corners+1,corners+2};
        const RdpVtx *second[] = {corners+2,corners+1,corners+3};
        gpu_piece(first,tile,R.timg); gpu_piece(second,tile,R.timg);
    }
    gpu_quad(t, x0, y0, x1, y1, mat, (s16)(st >> 16), (s16)st, dsdx / kx, dtdy / ky, flip, cyc < 2 && (R.om_l >> 2 & 1));
    return 1;
}

// Fill rectangles; the Z clear (fill 0xFFFC into the Z image) clears the GPU depth and also runs
// on the software path in RDRAM (return 0), except in in-between passes.
static int gpu_fill(int ulx, int uly, int lrx, int lry) {
    if (!gpu_enabled()) return 0;
    mdefer.on = 0;
    int cyc = R.om_h >> 20 & 3;
    if (!ip.on && R.cimg_siz == 1) {
        gpu.shadow.clear_address = cyc == 3 && R.fill == 0xFFFEFFFEu && ulx == 0 && uly == 0 &&
            R.sc_x0 == 0 && R.sc_y0 == 0 && lrx/4+1 == R.cimg_width && lry/4+1 >= R.sc_y1/4 ? R.cimg : 0;
    }
    if (cyc == 3 && R.zimg && R.cimg == R.zimg && R.cimg_siz == 2 && R.fill == 0xFFFCFFFCu) {
        GpuTarget *t = ip.on ? &gpu.ipt : NULL;
        for (int i = 0; i < 3 && !t; i++) if (gpu.t[i].color && gpu.t[i].width == R.cimg_width) t = &gpu.t[i];
        if (!t || !t->color || t->width != R.cimg_width) return ip.on;
        int sc[4], x0 = ulx * t->sx * .25f, y0 = uly * t->sy * .25f, x1 = ((lrx >> 2) + 1) * t->sx, y1 = ((lry >> 2) + 1) * t->sy;
        gpu_scissor(t, sc);
        if (x0 < sc[0]) x0 = sc[0];
        if (y0 < sc[1]) y0 = sc[1];
        if (x1 > sc[2]) x1 = sc[2];
        if (y1 > sc[3]) y1 = sc[3];
        if (x1 > x0 && y1 > y0) {
            if (!ip.on) {
                gpu_select_depth(t);
                if (x0 == 0 && y0 == 0 && x1 == t->pw && y1 == t->ph) {
                    // The CPU fill immediately below writes the same guest words.
                    for (int i = 0; i < t->width * t->height; i++) wr16(gpu.zshadow + 2*i, 0xFFFC);
                    gpu.zvalid = 1;
                    gpu.zcheck = 0;
                } else {
                    // Apply older CPU writes first; this partial clear also changes RDRAM.
                    gpu_import_depth(t);
                    gpu.zcheck = 1;
                }
            }
            gpu_flush();
            glBindFramebuffer(GL_FRAMEBUFFER, gpu_draw_fbo(t));
            glScissor(x0, y0, x1 - x0, y1 - y0);
            glDepthMask(GL_TRUE);
            glClear(GL_DEPTH_BUFFER_BIT);
        }
        if (!ip.on) gpu.zgen++;
        return ip.on;
    }
    GpuTarget *t = gpu_pick(cyc < 3 && (R.om_l & 4));
    if (!t) return 0;
    if (t == &gpu.none) return 1;
    float kx = t->sx, ky = t->sy;
    int x0 = ulx * kx * .25f, y0 = uly * ky * .25f, x1, y1;
    if (cyc >= 2) { x1 = ((lrx >> 2) + 1) * kx; y1 = ((lry >> 2) + 1) * ky; }  // fill/copy: inclusive
    else { x1 = (int)ceilf(lrx * kx * .25f); y1 = (int)ceilf(lry * ky * .25f); }
    gpu_quad(t, x0, y0, x1, y1, gpu_material(cyc == 3 ? GPU_FILL : GPU_RECT, 0, 0, 0), 0, 0, 0, 0, 0, cyc < 3 && (R.om_l >> 2 & 1));
    return 1;
}

static void gpu_flush(void) {
    if (!gpu.nb) return;
    gpu_seams();
    glBindBuffer(GL_ARRAY_BUFFER, gpu.vbo);
    glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)gpu.nv * (GLsizeiptr)sizeof *gpu.v, gpu.v, GL_STREAM_DRAW);
    glBindBuffer(GL_TEXTURE_BUFFER, gpu.mat_buffer);
    glBufferData(GL_TEXTURE_BUFFER, (GLsizeiptr)gpu.nm * 4, gpu.m, GL_STREAM_DRAW);
    glBindVertexArray(gpu.vao);
    glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D, gpu.atlas);
    glActiveTexture(GL_TEXTURE1); glBindTexture(GL_TEXTURE_BUFFER, gpu.mat_texture);
    glActiveTexture(GL_TEXTURE6); glBindTexture(GL_TEXTURE_2D, gpu.shadow.texture ? gpu.shadow.texture : gpu.blank);
    glActiveTexture(GL_TEXTURE0);
    const DrawProgram *program=NULL;
    GpuTarget *bound = NULL;
    int decal = -1;
    for (int i = 0; i < gpu.nb; i++) {
        GpuBatch *b = &gpu.b[i];
        if (program!=b->program) {
            program=b->program;
            glUseProgram(program->name);
            glUniform1ui(program->frame,gpu.frame);
            glUniform1i(program->soften,bt_setting(BT_SET_SMOOTH));
            bound=NULL;
        }
        if (b->t != bound) {
            bound = b->t;
            glBindFramebuffer(GL_FRAMEBUFFER, gpu_draw_fbo(bound));
            glViewport(0, 0, bound->pw, bound->ph);
            glUniform2f(program->scale, bound->sx, bound->sy);
            glUniform1i(program->color16, bound->sx == 1 && bound->sy == 1);
        }
        glDepthFunc(b->zfunc);
        glDepthMask(b->zmask);
        if (b->decal != decal) {
            decal = b->decal;
            if (decal) { glEnable(GL_POLYGON_OFFSET_FILL); glPolygonOffset(-1, -2); }
            else glDisable(GL_POLYGON_OFFSET_FILL);
        }
        glScissor(b->sc[0], b->sc[1], b->sc[2] > b->sc[0] ? b->sc[2] - b->sc[0] : 0, b->sc[3] > b->sc[1] ? b->sc[3] - b->sc[1] : 0);
        if (!b->rmw) { glDrawArrays(GL_TRIANGLES, b->first, b->count); continue; }
        glActiveTexture(GL_TEXTURE4); glBindTexture(GL_TEXTURE_2D, b->t->color);
        glUniform1i(program->rmw, 1);
        for (int k = 0; k < b->count; k += 3) { gpu_barrier(); glDrawArrays(GL_TRIANGLES, b->first + k, 3); }
        glUniform1i(program->rmw, 0);
        glBindTexture(GL_TEXTURE_2D, gpu.blank);
        glActiveTexture(GL_TEXTURE0);
    }
    glDisable(GL_POLYGON_OFFSET_FILL);
    gpu.batches += (unsigned)gpu.nb;
    gpu.nv = gpu.nm = gpu.nb = gpu.npiece = 0;
    gpu.last_m = -1;
    gpu_check("draw");
}

// ---- RDRAM and window
// Passes that are not draws: no blending, depth or scissor (blits obey the scissor too).
static void gpu_pass_begin(void) { gpu_flush(); glDisable(GL_SCISSOR_TEST); glDisable(GL_DEPTH_TEST); }
static void gpu_pass_end(void) { glEnable(GL_SCISSOR_TEST); glEnable(GL_DEPTH_TEST); glEnable(GL_BLEND); }

// Readable color/depth are regular textures. Draws retain per-sample data until a reader needs it.
static void gpu_samples_resolve(GpuTarget *t, GLbitfield mask) {
    if (!t->samples) return;
    glBindFramebuffer(GL_READ_FRAMEBUFFER, t->ms_fbo);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, t->fbo);
    glBlitFramebuffer(0, 0, t->pw, t->ph, 0, 0, t->pw, t->ph, mask, GL_NEAREST);
}

// Draws program over t's N64-sized grid into the RG8UI resolve image and reads it into dst (and also).
static void gpu_resolve_pass(GpuTarget *t, GLuint program, GLint scale, GLuint source, u8 *dst, u8 *also) {
    gpu_pass_begin();
    gpu_samples_resolve(t, source == t->depth ? GL_DEPTH_BUFFER_BIT : GL_COLOR_BUFFER_BIT);
    if (gpu.resolve_w != t->width || gpu.resolve_h != t->height) {
        gpu_texture(&gpu.resolve_tex, GL_RG8UI, t->width, t->height, GL_RG_INTEGER, GL_UNSIGNED_BYTE);
        if (!gpu.resolve_fbo) glGenFramebuffers(1, &gpu.resolve_fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, gpu.resolve_fbo);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gpu.resolve_tex, 0);
        gpu.resolve_w = t->width; gpu.resolve_h = t->height;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, gpu.resolve_fbo);
    glViewport(0, 0, t->width, t->height);
    glDisable(GL_BLEND);
    glUseProgram(program);
    glUniform2i(scale, t->width, t->height);
    glActiveTexture(GL_TEXTURE2); glBindTexture(GL_TEXTURE_2D, source);
    glBindVertexArray(gpu.empty_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    gpu_readback(t->width, t->height, GL_RG_INTEGER, GL_UNSIGNED_BYTE, 2, dst, also, NULL);  // N64 rows, big-endian pixels
    gpu_pass_end();
    gpu_check("resolve");
    gpu.resolves++;
}

// A guarded guest notifies raw scalar and bulk CPU accesses. Marks persist for
// pages where images have lived. Only still-pending exact ranges cause a sync.
#ifdef BT_IMAGE_ACCESS_HOST
unsigned char bt_image_pages[4096];
static _Atomic u64 pending_images[4];
static int demand_images;
static int demand_requested(void) {
    const char *setting = getenv("BT_GPU_DEMAND");
    return setting && atoi(setting);
}
static int defer_image(int slot, u32 address, GpuTarget *t) {
    u64 bytes = (u64)t->width * t->height * 2;
    u64 limit = address + bytes;
    if (!demand_images || !bytes || address < 0x80000000u || limit > 0x81000000ull) return 0;
    u64 range = (u64)address << 32 | bytes;
    if (atomic_load(&pending_images[slot]) != range) {
        u32 first = (address - 0x80000000u) >> 12;
        u32 last = (u32)((limit - 1 - 0x80000000u) >> 12);
        if (first) first--;  // a scalar on the preceding page may straddle this image
        for (u32 i = first; i <= last; i++)
            __atomic_store_n(&bt_image_pages[i], 1, __ATOMIC_RELAXED);
        atomic_store(&pending_images[slot], range);
    }
    return 1;
}
static int pending_overlap(int slot, u64 address, u64 bytes) {
    u64 range = atomic_load(&pending_images[slot]);
    u64 start = range >> 32;
    return range && address < start + (u32)range && start < address + bytes;
}
#endif
static void gpu_resolve(GpuTarget *t) {
    int n = t->width * t->height * 2;
    u8 *dst = gptr(t->address, (u32)n);
    if (!t->drawn || !dst) return;
    gpu_resolve_pass(t, gpu.resolve, gpu.r_scale, t->color, dst, t->shadow);
    t->drawn = 0;
#ifdef BT_IMAGE_ACCESS_HOST
    if (demand_images) atomic_store(&pending_images[t - gpu.t], 0);
#endif
}

// Z memory gets the GPU's depth: at the end of a task (the game samples it with the CPU, 1EC1AD0.c)
// and before the software path draws over it or loads it as a texture.
static void gpu_resolve_depth(void) {
    GpuTarget *t = gpu.zt;
    u8 *dst = t ? gptr(gpu.zaddr, (u32)(t->width * t->height * 2)) : NULL;
    gpu.zt = NULL;
    if (dst) gpu_resolve_pass(t, gpu.zresolve, gpu.z_scale, t->depth, dst, gpu.zshadow);
#ifdef BT_IMAGE_ACCESS_HOST
    if (demand_images) atomic_store(&pending_images[3], 0);  // allow readers through after the bytes are in RDRAM
#endif
}

#ifdef BT_IMAGE_ACCESS_HOST
void bt_image_access(u64 address, u64 bytes) {
    if (!bytes || (!pending_overlap(0, address, bytes) && !pending_overlap(1, address, bytes) &&
                   !pending_overlap(2, address, bytes) && !pending_overlap(3, address, bytes))) return;
    if (!in_render_task) {
        pthread_mutex_lock(&frame_lock);
        gpu_init();
        gpu_finish();
    }
    for (int i = 0; i < 3; i++)
        if (pending_overlap(i, address, bytes)) gpu_resolve(&gpu.t[i]);
    if (pending_overlap(3, address, bytes)) gpu_resolve_depth();
    if (!in_render_task) {
        gpu_release();
        pthread_mutex_unlock(&frame_lock);
    }
}
#endif
static void gpu_resolve_address(u32 address) {
    for (int i = 0; i < 3; i++) {
        GpuTarget *t = &gpu.t[i];
        if (t->color && address >= t->address && (u64)address < (u64)t->address + (u64)t->width * t->height * 2) gpu_resolve(t);
    }
    if (gpu.zt && address >= gpu.zaddr && (u64)address < (u64)gpu.zaddr + (u64)gpu.zt->width * gpu.zt->height * 2)
        gpu_resolve_depth();
}

// A TMEM load from address (rdp.c load_*; not SetTextureImage, the load may still come from the GPU):
// RDRAM gets the deferred image first.
static void gpu_mask_touch(u32 address) {
    if ((mdefer.n || R.tsrc_live) && address >= mdefer.base && address < mdefer.base + (u32)(mdefer.width * mdefer.height)) {
        gpu_mask_materialize(); gpu_mask_finalize();
    }
}

// RDRAM pixels that differ from the last resolve were written by the CPU (every: all of them).
static int gpu_import_image(GpuTarget *t, u32 address, u8 *shadow, int every, int depth_image) {
    int n = t->width * t->height * 2;
    const u8 *src = gptr(address, (u32)n);
    if (!src || (!every && !memcmp(src, shadow, (size_t)n))) return 0;
    gpu_pass_begin();
    int realloc_import = gpu.import_w != t->width || gpu.import_h != t->height;
    for (int i = 0; i < 2; i++) {
        glActiveTexture(GL_TEXTURE2 + i);
        if (realloc_import) gpu_texture(&gpu.import_tex[i], GL_RG8UI, t->width, t->height, GL_RG_INTEGER, GL_UNSIGNED_BYTE);
        glBindTexture(GL_TEXTURE_2D, gpu.import_tex[i]);
        gpu_upload(0, 0, t->width, t->height, GL_RG_INTEGER, GL_UNSIGNED_BYTE, 2, i ? shadow : src);
    }
    gpu.import_w = t->width; gpu.import_h = t->height;
    glBindFramebuffer(GL_FRAMEBUFFER, gpu_draw_fbo(t));
    glViewport(0, 0, t->pw, t->ph);
    glUseProgram(gpu.import);
    glUniform2f(gpu.i_scale, t->sx, t->sy);
    glUniform1i(gpu.i_every, every);
    glUniform1i(gpu.i_depth, depth_image);
    if (depth_image) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_ALWAYS);
        glDepthMask(GL_TRUE);
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    }
    glBindVertexArray(gpu.empty_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    if (depth_image) glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    gpu_pass_end();
    gpu_check("import");
    memcpy(shadow, src, (size_t)n);
    gpu.imports++;
    return 1;
}

static void gpu_import(GpuTarget *t, int every) {
    if (gpu_import_image(t, t->address, t->shadow, every, 0)) t->changed = 1;
}

// The GPU depth storage is shared by all VI images. Preserve each address before
// selecting a new guest Z image and retain high-resolution samples at unchanged pixels.
static void gpu_select_depth(GpuTarget *t) {
    if (gpu.zimage == R.zimg && gpu.zw == t->width && gpu.zh == t->height) return;
    gpu_resolve_depth();
    if (gpu.zw != t->width || gpu.zh != t->height) {
        free(gpu.zshadow);
        gpu.zshadow = calloc((size_t)t->width * t->height, 2);
        if (!gpu.zshadow) bt_fatal("allocating GPU depth shadow");
        gpu.zw = t->width;
        gpu.zh = t->height;
    }
    gpu.zimage = R.zimg;
    gpu.zvalid = 0;
}

static void gpu_import_depth(GpuTarget *t) {
    gpu_select_depth(t);
    if (!gpu.zcheck && gpu.zvalid) return;
    if (gpu_import_image(t, R.zimg, gpu.zshadow, !gpu.zvalid, 1)) gpu.zgen++;
    gpu.zcheck = 0;
    gpu.zvalid = 1;
}

// The picture of t at its resolution, as XRGB8888 rows (top first) in gpu.pixels.
static u32 *gpu_read_picture(GpuTarget *t) {
    size_t n = (size_t)t->pw * t->ph;
    if (gpu.pixels_n < n) {
        free(gpu.pixels);
        if (!(gpu.pixels = malloc(n * sizeof *gpu.pixels))) bt_fatal("allocating the GPU picture");
        gpu.pixels_n = n;
    }
    gpu_pass_begin();
    gpu_samples_resolve(t, GL_COLOR_BUFFER_BIT);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, t->fbo);
    gpu_readback(t->pw, t->ph, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, 4, gpu.pixels, NULL, t);
    gpu_pass_end();
    gpu_check("picture");
    return gpu.pixels;
}

// Hands the picture to rdp_frame: the pixel buffers are swapped, not copied, under the lock.
static void gpu_install(GpuTarget *t, u32 *pixels) {
    int slot = (int)(t - gpu.t);
    size_t n = (size_t)t->pw * t->ph;
    pthread_mutex_lock(&scanout_lock);
    if ((size_t)scanout[slot].pixel_w * scanout[slot].pixel_h != n) {
        free(scanout[slot].pixels);
        scanout[slot].pixels = NULL;
    }
    gpu.pixels = scanout[slot].pixels;
    gpu.pixels_n = gpu.pixels ? n : 0;
    scanout[slot].pixels = pixels;
    scanout[slot].address = t->address;
    scanout[slot].width = t->width; scanout[slot].height = t->height;
    scanout[slot].pixel_w = t->pw; scanout[slot].pixel_h = t->ph;
    pthread_mutex_unlock(&scanout_lock);
}

// CPU copies of the pictures (rdp_frame): without a window, and for the virtual clock's dumps, which
// the game threads write. A window with the real clock reads its texture when it needs pixels.
static int gpu_pictures(void) { return !gpu_share || bt_vclock_on; }

// The window keeps its current texture across refreshes. When it selects a new
// one, order writes after its last read and new reads after the producer's copy.
static void gpu_window_picture(unsigned texture) {
    if (texture == gpu.displayed) return;
    for (size_t k=0; k<sizeof gpu.show/sizeof *gpu.show; k++) {
        if (!gpu.show[k].tex) continue;
        if (gpu.show[k].tex == gpu.displayed) {
            if (gpu.show[k].consumed) glDeleteSync(gpu.show[k].consumed);
            gpu.show[k].consumed = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE,0);
            glFlush();
        }
        if (gpu.show[k].tex == texture) glWaitSync(gpu.show[k].ready,0,GL_TIMEOUT_IGNORED);
    }
    gpu.displayed=texture;
}

static int gpu_published_texture(GLuint texture) {
    if (!texture) return 0;
    if (texture==gpu.displayed) return 1;
    for (size_t i=0;i<sizeof scanout/sizeof *scanout;i++)
        if (scanout[i].address && scanout[i].tex==texture) return 1;
    for (size_t i=0;i<sizeof ip_out/sizeof *ip_out;i++)
        if (ip_out[i].address && ip_out[i].tex==texture) return 1;
    return 0;
}

// A spare surface permits a new copy while the previously published or selected
// texture is still visible in another context. No CPU wait is needed.
static GLuint gpu_show(GpuTarget *t) {
    size_t k=0;
    pthread_mutex_lock(&scanout_lock);
    while (k<sizeof gpu.show/sizeof *gpu.show && gpu_published_texture(gpu.show[k].tex)) k++;
    if (k==sizeof gpu.show/sizeof *gpu.show) bt_fatal("no spare presentation texture");
    if (gpu.show[k].consumed) {
        glWaitSync(gpu.show[k].consumed,0,GL_TIMEOUT_IGNORED);
        glDeleteSync(gpu.show[k].consumed);
        gpu.show[k].consumed=NULL;
    }
    if (gpu.show[k].ready) { glDeleteSync(gpu.show[k].ready); gpu.show[k].ready=NULL; }
    pthread_mutex_unlock(&scanout_lock);
    int w = t->pw, h = t->ph;
    gpu_pass_begin();
    pthread_mutex_lock(&scanout_lock);
    if (gpu.show[k].w != w || gpu.show[k].h != h) {
        gpu_texture(&gpu.show[k].tex, GL_RGBA8, w, h, GL_RGBA, GL_UNSIGNED_BYTE);
        gpu.show[k].w = w; gpu.show[k].h = h;
    }
    pthread_mutex_unlock(&scanout_lock);
    if (!gpu.show_fbo) glGenFramebuffers(1, &gpu.show_fbo);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, gpu_draw_fbo(t));
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, gpu.show_fbo);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gpu.show[k].tex, 0);
    glBlitFramebuffer(0, 0, w, h, 0, 0, w, h, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    gpu_pass_end();
    gpu_check("show");
    pthread_mutex_lock(&scanout_lock);
    gpu.show[k].ready=glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE,0);
    glFlush();  // make the sync visible to the window before its texture is published
    pthread_mutex_unlock(&scanout_lock);
    return gpu.show[k].tex;
}

static void gpu_publish(GpuTarget *t) {
    if (gpu_share) {
        int slot = (int)(t - gpu.t);
        GLuint tex = gpu_show(t);
        pthread_mutex_lock(&scanout_lock);
        if (!gpu_pictures() || scanout[slot].pixel_w != t->pw || scanout[slot].pixel_h != t->ph) {
            free(scanout[slot].pixels); scanout[slot].pixels = NULL;
        }
        scanout[slot].tex = tex;
        scanout[slot].address = t->address;
        scanout[slot].width = t->width; scanout[slot].height = t->height;
            scanout[slot].pixel_w = t->pw; scanout[slot].pixel_h = t->ph;
        pthread_mutex_unlock(&scanout_lock);
    }
    if (gpu_pictures()) {
        u32 *pixels = gpu_read_picture(t);
        if (!gpu.queuing) gpu_install(t, pixels);  // else gpu_finish does
    }
    t->changed = 0;
}

// Remember the higher-resolution version of the guest's explicit framebuffer copy into Z
// memory. Restore it only if the complete guest copy is still intact; the regular tile pass
// already handled cropped, modified, resized or otherwise unsupported copies in RDRAM.
void rdp_framebuffer_copy(void) {
    if (!gpu_enabled() || R.cimg_siz != 2 || R.timg_siz != 2 || R.cimg_width != R.timg_width) return;
    GpuTarget *src = NULL, *dst = NULL;
    for (int i = 0; i < 3; i++) {
        GpuTarget *t = &gpu.t[i];
        if (!t->color || t->width != R.cimg_width || (t->pw == t->width && t->ph == t->height)) continue;
        if (t->address == R.cimg) dst = t;
        if (t->address == R.timg) src = t;
    }
    if (ip.on) {
        src = NULL; // an interpolation pass never changes the guest's snapshot
        dst = R.cimg == ip.address ? &gpu.ipt : NULL;
    }
    if (src && R.cimg == R.zimg) {
        size_t bytes = (size_t)src->width * src->height * 2;
        const u8 *copy = gptr(R.cimg, (u32)bytes);
        if (!copy) return;
        if (gpu.backdrop.capacity < bytes) {
            u8 *data = realloc(gpu.backdrop.bytes, bytes);
            if (!data) bt_fatal("allocating pause backdrop");
            gpu.backdrop.bytes = data; gpu.backdrop.capacity = bytes;
        }
        memcpy(gpu.backdrop.bytes, copy, bytes);
        gpu_pass_begin();
        if (gpu.backdrop.w != src->pw || gpu.backdrop.h != src->ph) {
            gpu_texture(&gpu.backdrop.tex, GL_RGBA8, src->pw, src->ph, GL_RGBA, GL_UNSIGNED_BYTE);
            gpu.backdrop.w = src->pw; gpu.backdrop.h = src->ph;
        }
        if (!gpu.backdrop.fbo) glGenFramebuffers(1, &gpu.backdrop.fbo);
        glBindFramebuffer(GL_READ_FRAMEBUFFER, gpu_draw_fbo(src));
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, gpu.backdrop.fbo);
        glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gpu.backdrop.tex, 0);
        glBlitFramebuffer(0,0,src->pw,src->ph,0,0,src->pw,src->ph,GL_COLOR_BUFFER_BIT,GL_NEAREST);
        gpu.backdrop.stored_at = R.cimg;
        gpu.backdrop.length = bytes;
        gpu.backdrop.guest_w = src->width;
        gpu_pass_end();
        gpu_check("capture backdrop");
    } else if (dst && gpu.backdrop.stored_at && R.timg == gpu.backdrop.stored_at) {
        size_t bytes = (size_t)dst->width * dst->height * 2;
        const u8 *copy = gptr(R.timg, (u32)bytes);
        if (dst->width != gpu.backdrop.guest_w || bytes != gpu.backdrop.length ||
            !copy || memcmp(gpu.backdrop.bytes, copy, bytes)) return;
        gpu_pass_begin();
        if (!gpu.backdrop.program) {
            static const char shader[] =
                "#version 330\nuniform sampler2D image; uniform ivec2 dest; out vec4 color;\n"
                "void main(){color=texelFetch(image,ivec2(gl_FragCoord.xy)*textureSize(image,0)/dest,0);}";
            gpu.backdrop.program = gpu_program(gpu_fullscreen_shader, shader);
            glUseProgram(gpu.backdrop.program);
            glUniform1i(glGetUniformLocation(gpu.backdrop.program, "image"), 2);
            gpu.backdrop.size = glGetUniformLocation(gpu.backdrop.program, "dest");
        }
        glBindFramebuffer(GL_FRAMEBUFFER, gpu_draw_fbo(dst));
        glViewport(0,0,dst->pw,dst->ph);
        glDisable(GL_BLEND);
        glUseProgram(gpu.backdrop.program);
        glUniform2i(gpu.backdrop.size,dst->pw,dst->ph);
        glActiveTexture(GL_TEXTURE2); glBindTexture(GL_TEXTURE_2D,gpu.backdrop.tex);
        glBindVertexArray(gpu.empty_vao); glDrawArrays(GL_TRIANGLES,0,3);
        dst->drawn = dst->changed = 1;
        gpu_pass_end();
        gpu_check("restore backdrop");
    }
}

// ---- The 8-bit image (1E7F6A0.c, func_800A6250): the player model, flattened along the light, drawn
// as a mask into its own buffer below Z memory and pasted over the scene in strips (func_800A5EC4). Its
// triangles test depth (decal) against the scene, which is on the GPU: rdp.c used to need it in RDRAM
// mid-task, a full CPU/GPU sync every frame. Now rdp.c still rasterizes and shades them, but defers the
// depth test (mdefer): the fragments are tested on the GPU against the N64 depth the resolve would have
// written (mz), with rdp.c's integer compare, when the paste loads the image (gpu_mask_compose, then the
// loads are recorded in R.tsrc and copied into the atlas), and on the CPU at the end of the task, after
// the readbacks the task ends with anyway (gpu_mask_finalize). Same bytes, no mid-task sync.

// Can rdp.c draw this triangle with deferred depth? Only 8-bit images outside the VI framebuffers,
// without depth updates, memory reads in the blender or noise in the combiner (fragments are written
// later, in order, and owe their noise steps).
static int gpu_mask_defer(void) {
    if (R.cimg_siz != 1 || ((R.om_l & 0x20) && R.zimg)) return 0;
    // memory as a blender input, as pixel() uses them: cycle 0 blends fully in 2-cycle mode, the last
    // cycle only with FORCE_BL (else it passes its first input)
    u32 bl = R.om_l >> 16;
    int cyc2 = (R.om_h >> 20 & 3) == 1, force = (R.om_l & 0x4000) != 0;
    int p0 = (bl >> 14 & 3) == 1, m0 = (bl >> 6 & 3) == 1, p1 = (bl >> 12 & 3) == 1, m1 = (bl >> 4 & 3) == 1;
    if (cyc2 ? p0 || m0 || p1 || (force && m1) : p0 || (force && m0)) return 0;
    for (int c = 0; c < 2; c++) for (int i = 0; i < 4; i++) if (R.rgb[c][i] == C_NOISE || R.alpha[c][i] == C_NOISE) return 0;
    int w = R.cimg_width, h = R.sc_y1 >> 2;
    if (w < 16 || w > 640 || h <= 0 || h > 480) return 0;
    if (mdefer.n && mdefer.base == R.cimg && mdefer.width == w && h < mdefer.height) h = mdefer.height;
    u8 *bp = gptr(R.cimg, (u32)(w * h));
    int ztest = (R.om_l & 0x10) && R.zimg;
    if (!bp || (ztest && !gptr(R.zimg, (u32)(w * h * 2)))) return 0;
    for (int i = 0; i < 3; i++) {
        const GpuTarget *t = &gpu.t[i];
        if (t->color && (u64)R.cimg < (u64)t->address + (u64)t->width * t->height * 2 && t->address < (u64)R.cimg + (u64)w * h)
            return 0;
    }
    gpu_mask_materialize();  // loads from it before this draw keep its old bytes
    if (mdefer.n && (mdefer.base != R.cimg || mdefer.width != w || h > mdefer.height || gpu.mask_composed)) gpu_mask_finalize();
    if (ztest && (gpu.mz_gen != gpu.zgen || gpu.mz_zimg != R.zimg || gpu.mz_w != w || gpu.mz_h < h)) {
        gpu_mask_finalize();  // pending fragments test against the depth they were drawn with
        gpu_mask_depth(w, h);
    }
    if (!mdefer.n) { mdefer.base = R.cimg; mdefer.width = w; mdefer.height = h; mdefer.bp = bp; }
    mdefer.on = 1;
    return 1;
}

// The pending fragments on the CPU (gpu_mask_compose's test in rdp.c's code), into RDRAM; noise steps.
static void gpu_mask_finalize(void) {
    if (!mdefer.n) return;
    const u8 *z = gpu.mz_cpu;
    int any = 0;
    for (int i = 0; i < mdefer.n && !any; i++) any = mdefer.f[i].ztest != 0;
    if (any && gpu.mz_from_gpu) {  // the resolved depth, as the GPU holds it
        size_t n = (size_t)gpu.mz_w * gpu.mz_h * 2;
        if (gpu.mz_cpu_n < n && !(gpu.mz_cpu = realloc(gpu.mz_cpu, gpu.mz_cpu_n = n))) bt_fatal("allocating mask depth");
        gpu_flush();
        glBindFramebuffer(GL_READ_FRAMEBUFFER, gpu.mz_fbo);
        gpu_readback(gpu.mz_w, gpu.mz_h, GL_RG_INTEGER, GL_UNSIGNED_BYTE, 2, gpu.mz_cpu, NULL, NULL);
        if (gpu.queuing) { gpu.mz_from_gpu = 0; return; }  // gpu_finish finalizes once the bytes are in
        gpu_check("mask depth readback");
        gpu.mz_from_gpu = 0;
        z = gpu.mz_cpu;
    }
    u8 *bp = gptr(mdefer.base, (u32)(mdefer.width * mdefer.height));
    u32 passed = 0;
    for (int i = 0; i < mdefer.n && bp; i++) {
        const MaskFrag *f = &mdefer.f[i];
        if (f->ztest) {
            u32 cz = z_compress(f->z), oz = z_decompress(rd16(z + f->off * 2) >> 2), zq = z_decompress(cz);
            u32 tol = f->zdz + (1u << Z_SHIFT[cz >> 11]) * 2;
            if (f->decal ? zq > oz + tol || zq + tol < oz : zq > oz) continue;
            passed++;
            if (f->ztest == 2) continue;
        }
        bp[f->off] = (u8)f->value;
    }
    while (passed--) noise_state = noise_state * 1664525u + 1013904223u;
    mdefer.n = 0;
    gpu.mask_composed = 0;
    gpu.shadow.n = gpu.shadow.other = gpu.shadow.ready = 0;
}

// The image with its fragments on the GPU, for loads from it: RDRAM bytes, then one point per fragment.
// The projected player model uses one untextured, black decal pass. Keep its
// actual triangles for presentation. The guest still receives every original CI8 byte.
static void gpu_shadow_triangle(const RdpVtx *const v[3], int flags, u32 dz) {
    if (!mdefer.on || !gpu.zt || (gpu.zt->sx == 1 && gpu.zt->sy == 1)) return;
    if (flags != (RDP_SHADE|RDP_Z) || R.om_h != 0x00982C00 || R.om_l != 0x0C192E10 ||
        R.sc_x0 || R.sc_y0 || R.sc_x1 < mdefer.width*4 || R.sc_y1 < mdefer.height*4) {
        gpu.shadow.other = 1;
        return;
    }
    if (gpu.shadow.n + 3 > gpu.shadow.capacity) {
        gpu.shadow.capacity = (gpu.shadow.n + 3) * 2;
        gpu.shadow.vertices = realloc(gpu.shadow.vertices,(size_t)gpu.shadow.capacity*sizeof *gpu.shadow.vertices);
        if (!gpu.shadow.vertices) bt_fatal("allocating shadow triangles");
    }
    for (int i=0; i<3; i++) {
        float *p=gpu.shadow.vertices[gpu.shadow.n++];
        p[0]=v[i]->x; p[1]=v[i]->y; p[2]=v[i]->z; p[3]=(float)dz;
    }
}

static void gpu_shadow_geometry(void) {
    GpuTarget *t=gpu.zt;
    gpu.shadow.ready=0;
    if (!t || gpu.shadow.clear_address != mdefer.base || !gpu.shadow.n || gpu.shadow.other || !gpu.mz_from_gpu || !mdefer.n) return;
    // Other draws into this borrowed image retain their normal CI8 sampling.
    for (int i=0; i<mdefer.n; i++) if (mdefer.f[i].value || mdefer.f[i].ztest != 1 || !mdefer.f[i].decal) return;
    if (!gpu.shadow.program) {
        gpu.shadow.program=gpu_program(gpu_shadow_vertex_shader,gpu_shadow_fragment_shader);
        glGenFramebuffers(1,&gpu.shadow.fbo);
        glGenVertexArrays(1,&gpu.shadow.vao);
        glGenBuffers(1,&gpu.shadow.buffer);
        glBindVertexArray(gpu.shadow.vao);
        glBindBuffer(GL_ARRAY_BUFFER,gpu.shadow.buffer);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,sizeof *gpu.shadow.vertices,0);
    }
    gpu_pass_begin();
    gpu_samples_resolve(t,GL_DEPTH_BUFFER_BIT);
    glActiveTexture(GL_TEXTURE6);
    if (gpu.shadow.w!=t->pw || gpu.shadow.h!=t->ph) {
        gpu_texture(&gpu.shadow.texture,GL_R8,t->pw,t->ph,GL_RED,GL_UNSIGNED_BYTE);
        gpu.shadow.w=t->pw; gpu.shadow.h=t->ph;
    }
    glBindFramebuffer(GL_FRAMEBUFFER,gpu.shadow.fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,gpu.shadow.texture,0);
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER)!=GL_FRAMEBUFFER_COMPLETE) bt_fatal("incomplete shadow target");
    glViewport(0,0,t->pw,t->ph);
    glClearBufferfv(GL_COLOR,0,(const GLfloat[4]){0,0,0,0});
    glDisable(GL_BLEND);
    glUseProgram(gpu.shadow.program);
    glUniform2f(glGetUniformLocation(gpu.shadow.program,"viewport"),(float)t->width,(float)t->height);
    glUniform1i(glGetUniformLocation(gpu.shadow.program,"scene"),2);
    glActiveTexture(GL_TEXTURE2); glBindTexture(GL_TEXTURE_2D,t->depth);
    glBindVertexArray(gpu.shadow.vao);
    glBindBuffer(GL_ARRAY_BUFFER,gpu.shadow.buffer);
    glBufferData(GL_ARRAY_BUFFER,(size_t)gpu.shadow.n*sizeof *gpu.shadow.vertices,gpu.shadow.vertices,GL_STREAM_DRAW);
    glDrawArrays(GL_TRIANGLES,0,gpu.shadow.n);
    glActiveTexture(GL_TEXTURE0);
    gpu_pass_end();
    gpu_check("projected shadow");
    gpu.shadow.ready=1;
}

static void gpu_mask_compose(void) {
    GpuTarget *m = &gpu.mask;
    int w = mdefer.width, h = mdefer.height;
    gpu_shadow_geometry();
    gpu_pass_begin();
    glActiveTexture(GL_TEXTURE2);
    if (!m->color || m->width != w || m->height != h) {
        gpu_texture(&m->color, GL_R8, w, h, GL_RED, GL_UNSIGNED_BYTE);
        if (!m->fbo) glGenFramebuffers(1, &m->fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, m->fbo);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m->color, 0);
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) bt_fatal("OpenGL incomplete mask framebuffer");
        m->width = w; m->height = h; m->pw = w; m->ph = h; m->sx = m->sy = 1;
    }
    glBindTexture(GL_TEXTURE_2D, m->color);
    gpu_upload(0, 0, w, h, GL_RED, GL_UNSIGNED_BYTE, 1, mdefer.bp);
    glActiveTexture(GL_TEXTURE0);
    static u32 *pts; static int cap;
    if (cap < mdefer.n && !(pts = realloc(pts, (size_t)(cap = mdefer.n * 2) * 16))) bt_fatal("allocating mask points");
    for (int i = 0; i < mdefer.n; i++) {
        const MaskFrag *f = &mdefer.f[i];
        u32 *o = pts + i * 4;
        o[0] = f->off % (u32)w | (f->off / (u32)w) << 16; o[1] = f->z; o[2] = f->zdz;
        o[3] = f->value | (u32)f->ztest << 8 | (u32)f->decal << 10;
    }
    if (!gpu.frag_vao) {
        glGenVertexArrays(1, &gpu.frag_vao);
        glBindVertexArray(gpu.frag_vao);
        glGenBuffers(1, &gpu.frag_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, gpu.frag_vbo);
        glEnableVertexAttribArray(0);
        glVertexAttribIPointer(0, 4, GL_UNSIGNED_INT, 16, (void *)0);
    }
    glBindVertexArray(gpu.frag_vao);
    glBindBuffer(GL_ARRAY_BUFFER, gpu.frag_vbo);
    glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)mdefer.n * 16, pts, GL_STREAM_DRAW);
    glBindFramebuffer(GL_FRAMEBUFFER, m->fbo);
    glViewport(0, 0, w, h);
    glDisable(GL_BLEND);
    glUseProgram(gpu.maskfrag);
    glUniform2i(gpu.mf_size, w, h);
    glDrawArrays(GL_POINTS, 0, mdefer.n);  // in order: the last passing fragment of a pixel wins, as in rdp.c
    gpu_pass_end();
    gpu_check("mask compose");
    gpu.mask_composed = 1;
}

// The image's replay of loads from it (TMEM bytes still owned get the values load_tile reads from RDRAM).
static void gpu_mask_materialize(void) {
    if (!R.tsrc_live) return;
    gpu_mask_finalize();
    for (int k = 0; k < 8; k++) {
        typeof(R.trec[0]) *r = &R.trec[k];
        for (int row = 0; row < r->h && r->bytes; row++) {
            const u8 *src = gptr(r->timg + (u32)((r->y0 + row) * r->width + r->x0), (u32)r->w);
            u32 x = row & 1 ? 4 : 0, rb = (u32)r->tmem * 8 + (u32)(row * r->line * 8);
            for (int i = 0; i < r->w; i++) {
                u32 a = ((rb + (u32)i) ^ x) & 0xFFF;
                if (R.tsrc[a] != k + 1) continue;
                if (src) R.tmem[a] = src[i];  // load_tile skips rows outside memory
                R.tsrc[a] = 0; r->bytes--; R.tsrc_live--;
            }
        }
    }
    tmem_gen++; texture_epoch++;
}

// A load tile from the image while it has pending fragments: composed on the GPU, TMEM bytes recorded.
// Only plain 8-bit loads whose rows neither overlap nor wrap TMEM, so a replay is exact.
static int gpu_mask_load(void) {
    if (!gpu_enabled() || !mdefer.n || R.timg_siz != 1 || R.timg != mdefer.base || R.timg_width != mdefer.width) return 0;
    const Tile *tl = &R.tile[load_tile_tile];
    int sl = tl->uls >> 2, tt = tl->ult >> 2, sh = tl->lrs >> 2, th = tl->lrt >> 2, w = sh - sl + 1, h = th - tt + 1;
    if (w <= 0 || h <= 0 || sh >= mdefer.width || th >= mdefer.height || tl->line * 8 < w ||
        tl->tmem * 8 + h * tl->line * 8 > 4096) return 0;
    if (!gpu.mask_composed) gpu_mask_compose();
    int k = 0;
    while (k < 8 && R.trec[k].bytes) k++;
    if (k == 8) { gpu_mask_materialize(); return 0; }  // finalized: an ordinary load
    typeof(R.trec[0]) *r = &R.trec[k];
    *r = (typeof(*r)){.timg = R.timg, .width = R.timg_width, .x0 = sl, .y0 = tt, .w = w, .h = h, .tmem = tl->tmem,
                      .line = tl->line, .uid = ++gpu.mask_uid};
    for (int row = 0; row < h; row++) {
        u32 x = row & 1 ? 4 : 0, rb = (u32)tl->tmem * 8 + (u32)(row * tl->line * 8);
        for (int i = 0; i < w; i++) {
            u32 a = ((rb + (u32)i) ^ x) & 0xFFF;
            if (R.tsrc[a]) { R.trec[R.tsrc[a] - 1].bytes--; R.tsrc_live--; }
            R.tsrc[a] = (u8)(k + 1); r->bytes++; R.tsrc_live++;
        }
    }
    return 1;
}

// Atlas entry e (w x h texels) from load record k: the composed image's texels as decode_texel makes them.
static void gpu_mask_copy(const GpuTexture *e, int k, int w, int h, int ia) {
    gpu_pass_begin();
    glBindFramebuffer(GL_FRAMEBUFFER, gpu.atlas_fbo);
    glViewport(e->x, e->y, w, h);
    glDisable(GL_BLEND);
    glUseProgram(gpu.maskcopy);
    glUniform2i(gpu.mc_off, R.trec[k].x0 - e->x, R.trec[k].y0 - e->y);
    glUniform1i(gpu.mc_ia, ia);
    glActiveTexture(GL_TEXTURE2); glBindTexture(GL_TEXTURE_2D, gpu.mask.color);
    glBindVertexArray(gpu.empty_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glActiveTexture(GL_TEXTURE0);
    gpu_pass_end();
    gpu_check("mask copy");
    gpu.mask_copies++;
}

// N64 depth (w x h, rows of w) for the fragments: what rdp.c would read from Z memory now.
static void gpu_mask_depth(int w, int h) {
    GpuTarget *z = gpu.zt;
    int on_gpu = z && R.zimg == gpu.zaddr;
    if (on_gpu && (z->width != w || z->height < h)) { gpu_resolve_depth(); on_gpu = 0; }  // other layout: via RDRAM
    const u8 *src = on_gpu ? NULL : gptr(R.zimg, (u32)(w * h * 2));
    gpu_pass_begin();
    glActiveTexture(GL_TEXTURE5);
    if (gpu.mz_w != w || gpu.mz_h != h) {
        gpu_texture(&gpu.mz_tex, GL_RG8UI, w, h, GL_RG_INTEGER, GL_UNSIGNED_BYTE);
        if (!gpu.mz_fbo) glGenFramebuffers(1, &gpu.mz_fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, gpu.mz_fbo);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gpu.mz_tex, 0);
        gpu.mz_w = w; gpu.mz_h = h;
    }
    if (on_gpu) {
        gpu_samples_resolve(z, GL_DEPTH_BUFFER_BIT);
        glBindFramebuffer(GL_FRAMEBUFFER, gpu.mz_fbo);
        glViewport(0, 0, w, h);
        glDisable(GL_BLEND);
        glUseProgram(gpu.zresolve);
        glUniform2i(gpu.z_scale, z->width, z->height);
        glActiveTexture(GL_TEXTURE2); glBindTexture(GL_TEXTURE_2D, z->depth);
        glBindVertexArray(gpu.empty_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    } else {
        size_t n = (size_t)w * h * 2;
        if (gpu.mz_cpu_n < n && !(gpu.mz_cpu = realloc(gpu.mz_cpu, gpu.mz_cpu_n = n))) bt_fatal("allocating mask depth");
        memcpy(gpu.mz_cpu, src, n);  // gpu_mask_defer checked the range
        gpu_upload(0, 0, w, h, GL_RG_INTEGER, GL_UNSIGNED_BYTE, 2, gpu.mz_cpu);
    }
    glActiveTexture(GL_TEXTURE0);
    gpu_pass_end();
    gpu_check("mask depth");
    gpu.mz_from_gpu = on_gpu;
    gpu.mz_gen = gpu.zgen; gpu.mz_zimg = R.zimg;
}

// ---- Task hooks (rdp.c)
static void gpu_begin(void) {
    if (!gpu_enabled()) return;
    gpu_init();
    gpu_finish();
    gpu.shadow.n = gpu.shadow.other = gpu.shadow.ready = 0;
    gpu.frame++;
    
    gpu.zcheck = 1;
    gpu.zgen++;  // the CPU may have written Z memory since
    for (int i = 0; i < 3; i++) if (gpu.t[i].color) gpu_import(&gpu.t[i], 0);
}

// ---- The task end without waiting for the GPU. Its readbacks (the mask's depth, pictures, colour and
// depth for RDRAM) are queued behind one fence (gpu.queuing); gpu_finish copies them out, finalizes the
// 8-bit image and replays TMEM, all that rdp.c leaves behind. With the real clock, rdp_done_later
// hands that to the completion thread, which raises the DP event after it: the game goes on (the next
// frame's logic) while the GPU draws, as the N64 CPU does beside its RDP, and touches the RDP's output
// only after that event, as on the N64. Everything that uses the context or that state first waits
// (gpu_finish): the next task, buffer swaps, in-between passes. With the virtual clock gpu_end finishes
// before the task returns, so scripted runs repeat exactly.

static void gpu_complete(void) {
    while (glClientWaitSync(gpu.fence, GL_SYNC_FLUSH_COMMANDS_BIT, 1000000000ull) == GL_TIMEOUT_EXPIRED) {}
    glDeleteSync(gpu.fence);
    for (int i = 0; i < gpu.nrd; i++) {
        typeof(gpu.rd[0]) *r = &gpu.rd[i];
        glBindBuffer(GL_PIXEL_PACK_BUFFER, r->pbo);
        const void *src = glMapBufferRange(GL_PIXEL_PACK_BUFFER, 0, (GLsizeiptr)r->n, GL_MAP_READ_BIT);
        if (!src) bt_fatal("OpenGL readback map: 0x%x", glGetError());
        if (r->picture) {  // gpu.pixels as gpu_read_picture left it; each install swaps in another
            if (gpu.pixels_n * 4 < r->n) {
                free(gpu.pixels);
                if (!(gpu.pixels = malloc(r->n))) bt_fatal("allocating the GPU picture");
                gpu.pixels_n = r->n / 4;
            }
            memcpy(gpu.pixels, src, r->n);
            gpu_install(r->picture, gpu.pixels);
        } else {
            memcpy(r->dst, src, r->n);
            if (r->also) memcpy(r->also, src, r->n);
        }
        glUnmapBuffer(GL_PIXEL_PACK_BUFFER);
    }
    glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
    gpu.nrd = 0;
    gpu_mask_materialize();  // RDRAM, TMEM and noise as rdp.c leaves them
    gpu_mask_finalize();
}

static void gpu_finish(void) {
    pthread_mutex_lock(&done.lock);
    while (done.state == 2) pthread_cond_wait(&done.cond, &done.lock);
    int queued = done.state == 1;
    if (queued) done.state = 2;
    pthread_mutex_unlock(&done.lock);
    if (!queued) return;
    gpu_complete();  // on the context gpu_init made current
    pthread_mutex_lock(&done.lock);
    done.state = 0;
    pthread_cond_broadcast(&done.cond);
    pthread_mutex_unlock(&done.lock);
}

static void *gpu_done_main(void *arg) {
    (void)arg;
    if (!SDL_GL_MakeCurrent(gpu_window, done.context)) bt_fatal("SDL completion context: %s", SDL_GetError());
    pthread_mutex_lock(&done.lock);
    for (;;) {
        while (!done.handoff) pthread_cond_wait(&done.cond, &done.lock);
        done.handoff = 0;
        pthread_mutex_unlock(&done.lock);
        gpu_complete();
        pthread_mutex_lock(&done.lock);
        done.state = 0;
        u32 event = done.event;
        pthread_cond_broadcast(&done.cond);
        pthread_mutex_unlock(&done.lock);
        bt_os_event(event);  // after state 0: the next task may start at once
        pthread_mutex_lock(&done.lock);
    }
    return NULL;
}

// rcp.c, after the SP event: 1 when the completion thread raises event once the task's output is in.
static int gpu_done_later(u32 event) {
    if (!gpu_enabled()) return 0;
    pthread_mutex_lock(&done.lock);
    while (done.state == 2) pthread_cond_wait(&done.cond, &done.lock);
    int later = done.state == 1;
    if (later) { done.state = 2; done.handoff = 1; done.event = event; pthread_cond_broadcast(&done.cond); }
    pthread_mutex_unlock(&done.lock);
    return later;
}

static void gpu_end(void) {
    if (!gpu_enabled()) return;
#ifdef BT_IMAGE_ACCESS_HOST
    static int checked;
    if (!checked) {
        demand_images = demand_requested() && gpu_barrier_available > 0;
        if (demand_requested() && !demand_images)
            fprintf(stderr, "gpu: using eager image resolves on a driver that may switch to software at 1x\n");
        checked = 1;
    }
#endif
    gpu_flush();
    gpu.queuing = 1;
    gpu_mask_finalize();  // queues the mask's depth when its fragments need it
    for (int i = 0; i < 3; i++) {
        GpuTarget *t = &gpu.t[i];
        if (t->changed) gpu_publish(t);
#ifdef BT_IMAGE_ACCESS_HOST
        if (t->drawn && defer_image(i, t->address, t)) continue;
#endif
        gpu_resolve(t);
    }
#ifdef BT_IMAGE_ACCESS_HOST
    if (!gpu.zt || !defer_image(3, gpu.zaddr, gpu.zt)) gpu_resolve_depth();
#else
    gpu_resolve_depth();
#endif
    gpu.queuing = 0;
    gpu.fence = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
    glFlush();  // the completion thread waits for this fence from its own context
    gpu_check("task end");
    done.state = 1;
    if (bt_vclock_on) gpu_finish();

    int stats = bt_setting(BT_SET_RENDER_STATS);
    static unsigned tasks;
    if (stats && ++tasks % 300 == 0) {
        fprintf(stderr, "gpu: per task draws=%u batches=%u texture uploads=%u resolves=%u imports=%u mask copies=%u\n",
                gpu.draws / 300, gpu.batches / 300, gpu.uploads / 300, gpu.resolves / 300, gpu.imports / 300, gpu.mask_copies / 300);
        fprintf(stderr,"gpu: specialized %u draws, %u programs ready\n",programs.draws,atomic_load(&programs.ready));
        programs.draws=0;
        gpu.draws = gpu.batches = gpu.uploads = gpu.resolves = gpu.imports = gpu.mask_copies = 0;
    }
}

// A VI buffer swap: the framebuffer gets a GPU image at the current scale; widescreen widens columns.
static void gpu_register(u32 address, int width, int widescreen) {
    static unsigned replace;
    if (width < 16 || width > 640 || !gptr(address, (u32)(width * (width * 3 / 4) * 2))) return;
    gpu_init();
    gpu_finish();
    int sy = rdp_scale(), sx = widescreen ? (sy * 4 + 1) / 3 : sy, slot = -1;
    int height = width * 3 / 4, pw = width * sx, ph = height * sy;
    if (widescreen == 2) pw = height * sy * 21 / 9;
    u32 backing = atomic_load(&window_pixels);
    int window_mode = bt_setting(BT_SET_GPU_WINDOW);
    if (gpu_share && backing && window_mode) {
        int ww = (int)(backing >> 16), wh = (int)(backing & 0xffff);
        if (ww > gpu.max_size) ww = gpu.max_size;
        if (wh > gpu.max_size) wh = gpu.max_size;
        int cap_h = window_mode == 2 ? 1440 : window_mode == 3 ? 2160 : wh;
        if (wh > cap_h) wh = cap_h;
        int aspect_w = widescreen == 2 ? 21 : widescreen ? 16 : 4, aspect_h = widescreen ? 9 : 3;
        ph = wh < ww * aspect_h / aspect_w ? wh : ww * aspect_h / aspect_w;
        if (ph < height) ph = height;
        pw = ph * aspect_w / aspect_h;
        if (!gpu_barrier && pw == width && ph == height) {
            // A minimized window can request native size. Only the exact renderer can do 1x blending.
            gpu_on = 0;
            fprintf(stderr, "renderer: soft (exact 1x GPU rendering needs a texture barrier)\n");
            return;
        }
    }
    render_sx = sx;
    for (int i = 0; i < 3 && slot < 0; i++) if (gpu.t[i].color && gpu.t[i].address == address) slot = i;
    for (int i = 0; i < 3 && slot < 0; i++) if (!gpu.t[i].color) slot = i;
    if (slot < 0) slot = (int)(replace++ % 3);
    GpuTarget *t = &gpu.t[slot];
    int samples = gpu_samples(width, height, pw, ph);
    int fresh = t->address != address || t->width != width || t->pw != pw || t->ph != ph || t->samples != samples;
    if (fresh) {
        // Complete reads from the old Z storage before resizing the shared renderbuffer.
        gpu_resolve_depth();
        for (int i = 0; i < 3; i++) gpu_resolve(&gpu.t[i]);
        for (int i = 0; i < 3; i++) {
            GpuTarget *other = &gpu.t[i];
            if (!other->color || other == t || (other->pw == pw && other->ph == ph && other->samples == samples)) continue;
            gpu_target_init(other, other->address, other->width, other->height, pw, ph, 0);
            gpu_import(other, 1);
        }
    }
    gpu_target_init(t, address, width, height, pw, ph, 0);
    gpu_import(t, fresh);
    if (t->changed) gpu_publish(t);
    gpu_release();
}

// Frame interpolation: the in-between image is its own target, started from the picture the task
// drew over; its depth is its own too.
static void gpu_interp_target(void) {
    GpuTarget *t = gpu_pick(0);
    if (!t || t == &gpu.none) return;
    gpu_target_init(&gpu.pre, 0, t->width, t->height, t->pw, t->ph, 1);
    gpu_target_init(&gpu.ipt, R.cimg, t->width, t->height, t->pw, t->ph, 1);
    gpu_pass_begin();
    glBindFramebuffer(GL_READ_FRAMEBUFFER, gpu_draw_fbo(t));
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, gpu_draw_fbo(&gpu.pre));
    glBlitFramebuffer(0, 0, t->pw, t->ph, 0, 0, t->pw, t->ph, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    gpu_pass_end();
    gpu_check("in-between start");
    ip.address = R.cimg;
}

static void gpu_interp_begin(void) {
    gpu_init();
    gpu_finish();
    gpu_pass_begin();
    glBindFramebuffer(GL_READ_FRAMEBUFFER, gpu_draw_fbo(&gpu.pre));
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, gpu_draw_fbo(&gpu.ipt));
    int w = gpu.ipt.pw, h = gpu.ipt.ph;
    glBlitFramebuffer(0, 0, w, h, 0, 0, w, h, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    glBindFramebuffer(GL_FRAMEBUFFER, gpu_draw_fbo(&gpu.ipt));
    glDepthMask(GL_TRUE);
    glClear(GL_DEPTH_BUFFER_BIT);
    gpu_pass_end();
}

static u32 *gpu_interp_end(int index, unsigned *tex, int *w, int *h, int *sx, int *sy) {
    *w = gpu.ipt.width; *h = gpu.ipt.height; *sx = gpu.ipt.sx; *sy = gpu.ipt.sy;
    if (gpu_share) *tex = gpu_show(&gpu.ipt);  // the pass ends here: the window may show it
    u32 *picture = gpu_pictures() ? gpu_read_picture(&gpu.ipt) : NULL;
    gpu_release();
    return picture;
}
#else
#ifdef BT_IMAGE_ACCESS_HOST
unsigned char bt_image_pages[4096];
void bt_image_access(u64 a, u64 n) { (void)a; (void)n; }
#endif
void rdp_framebuffer_copy(void) {}
static void gpu_window_picture(unsigned tex) { (void)tex; }
void rdp_gpu_share(void *window) { (void)window; }
static void gpu_begin(void) { gpu_enabled(); }
static void gpu_release(void) {}
static void gpu_end(void) {}
static int gpu_triangle(const RdpVtx *a, const RdpVtx *b, const RdpVtx *c, int flags) { (void)a; (void)b; (void)c; (void)flags; return 0; }
static int gpu_texrect(u32 w0, u32 w1, u32 st, u32 dsdt, int flip) { (void)w0; (void)w1; (void)st; (void)dsdt; (void)flip; return 0; }
static int gpu_fill(int ulx, int uly, int lrx, int lry) { (void)ulx; (void)uly; (void)lrx; (void)lry; return 0; }
static int gpu_mask_load(void) { return 0; }
static void gpu_mask_touch(u32 address) { (void)address; }
static void gpu_finish(void) {}
static int gpu_done_later(u32 event) { (void)event; return 0; }
static void gpu_resolve_address(u32 address) { (void)address; }
static void gpu_register(u32 address, int width, int widescreen) { (void)address; (void)width; (void)widescreen; }
static void gpu_interp_target(void) {}
static void gpu_interp_begin(void) {}
static u32 *gpu_interp_end(int index, unsigned *tex, int *w, int *h, int *sx, int *sy) { (void)index; (void)tex; (void)w; (void)h; (void)sx; (void)sy; return NULL; }
#endif
