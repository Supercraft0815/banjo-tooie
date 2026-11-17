// GPU renderer (BT_RENDERER=gpu), included by rdp.c to share its command/TMEM state.
// Fast3D style: triangles and rectangles that land in a VI framebuffer become batched OpenGL draws
// into a high-resolution render target per framebuffer; TMEM tiles are decoded once (decode_texel)
// into a texture atlas keyed by their content. Everything else stays on the software path in RDRAM
// at N64 resolution: the player shadow's CI8 image (its depth tests deferred to the GPU, see
// gpu_mask_defer), the pause menu's copy into Z memory, any image that is not a registered VI
// framebuffer. The game sees N64 pixels where it looks for them:
//   - every task ends with a resolve of the images it drew (average to 5-bit RGBA5551 in RDRAM),
//     which lands before the DP event (with the real clock after the task returns, see gpu_finish);
//   - a texture load from a GPU image resolves it first (the bubble's view of the frame, the pause
//     copy), mid-task, instead of syncing every draw;
//   - CPU writes into a framebuffer (debug text, pixel fixes) differ from the last resolve and are
//     imported at the next task or buffer swap, keeping the other subpixels.
//   - the software path drawing into RDRAM resolves what is there first and marks GPU images it
//     overlaps stale (re-imported before the GPU draws into them again);
//   - depth is resolved into Z memory (compressed like the RDP stores it) at the end of each task
//     that drew depth (the CPU samples it: 1EC1AD0.c), and before the software path draws over Z
//     memory, loads it as a texture or depth-tests against it (the player shadow is a decal).
// The depth clear (fill 0xFFFC into the Z image) runs on both sides.
// shortcut: depth written by the software path or the CPU is not imported into GPU depth (the game
// clears depth before drawing); import it if a scene draws against such depth.
static int gpu_on = -1;
static int gpu_barrier_available = -1;
static int gpu_enabled(void) {
    if (gpu_on < 0) {
        const char *name = getenv("BT_RENDERER");
        if (name && strcmp(name, "soft") && strcmp(name, "gpu")) bt_fatal("BT_RENDERER must be soft or gpu");
        gpu_on = name && !strcmp(name, "gpu");
#ifndef BT_GPU_OPENGL
        if (gpu_on) bt_fatal("this build has no GPU renderer");
#endif
        if (!gpu_on) fprintf(stderr, "renderer: soft\n");
    }
    if (gpu_on && gpu_barrier_available == 0 && rdp_scale() == 1) {
        fprintf(stderr, "renderer: soft (exact 1x GPU rendering needs a texture barrier)\n");
        gpu_on = 0;
    }
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
    int width, height, sx, sy;  // N64 size and scale
    int drawn, changed;         // since the last resolve / since the last publish
    int stale;                  // the software path drew into its RDRAM (import before the GPU draws again)
    GLuint color, fbo, depth;   // depth: the shared Z texture, or the in-between target's own
    u8 *shadow;                 // RDRAM bytes after the last resolve or import
} GpuTarget;
// rmw: the blender reads memory at scale 1; such batches draw one triangle at a time and blend in the
// shader against the target itself (texture barrier), so every blend step rounds to RGBA5551 like rdp.c.
typedef struct { GpuTarget *t; GLenum zfunc; GLboolean zmask; int decal, rmw, sc[4], first, count; } GpuBatch;
// border: what each of the 8 one-texel border pieces (L R T B, then corners LT RT LB RB) last got copied
// from, as atlas source x | y << 16 plus 1 (0: never written); see gpu_seams.
typedef struct { u64 key; u32 gen; u16 x, y; u32 border[8], stamp; int idx; } GpuTexture;
typedef struct { u64 gen; u32 tlut, agen; Tile desc; u16 x, y, w, h; int slot; } GpuTileMemo;
// A filtered triangle that maps one clamped tile edge to edge (gpu_seams); x, y, s, t per corner.
typedef struct { int slot; u16 w, h; float v[3][4]; } GpuPiece;

static struct {
    SDL_GLContext context;
    GLuint draw, import, resolve, zresolve, maskcopy, maskfrag;  // programs
    GLint u_scale, u_frame, u_color16, u_rmw, u_soften, i_scale, i_every, r_scale, z_scale, mc_off, mc_ia, mf_size;
    GLuint vao, vbo, empty_vao, mat_buffer, mat_texture, atlas, depth, import_tex[2], resolve_tex, resolve_fbo;
    GLuint blank;  // sampled as dst outside rmw batches (an empty unit makes the driver complain)
    GLuint atlas_fbo;  // the atlas as blit source and target for seam borders
    GpuPiece *piece; int npiece, cap_piece; u32 seam_stamp;
    int depth_w, depth_h, resolve_w, resolve_h, import_w, import_h;
    GpuTarget t[3], ipt, pre, none;  // VI framebuffers, in-between image and its starting picture
    // The 8-bit image with its deferred fragments (rdp.c mdefer): R8 at N64 size, composed for loads
    // (mask_composed); mz: N64 depth (RDRAM bytes) the fragments test against, current while
    // mz_gen == zgen; mz_cpu: the same bytes on the CPU when they came from RDRAM.
    GpuTarget mask; u32 mask_uid; int mask_composed;
    GLuint upbo, dpbo;  // texture uploads and readbacks go through them (gpu_upload, gpu_readback)
    // The task end's readbacks (gpu_end), queued behind one fence until gpu_finish: picture: the
    // target whose picture goes to scanout, else dst (and also) get the bytes.
    struct { GLuint pbo; size_t size, n; u8 *dst, *also; GpuTarget *picture; } rd[8];
    int nrd, queuing;
    GLsync fence;
    // Direct presentation (gpu_show): a copy of each published picture the renderer no longer draws
    // into, 0..2 the VI framebuffers' and 3..5 the in-between images'.
    struct { GLuint tex; int w, h; } show[6];
    GLuint show_fbo;
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

static GLuint gpu_program(const char *vs_text, const char *fs_text) {
    GLuint p = glCreateProgram();
    const char *text[2] = {vs_text, fs_text};
    for (int i = 0; i < 2; i++) {
        GLuint s = glCreateShader(i ? GL_FRAGMENT_SHADER : GL_VERTEX_SHADER);
        GLint ok;
        glShaderSource(s, 1, &text[i], NULL);
        glCompileShader(s);
        glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
        if (!ok) { char log[4096]; glGetShaderInfoLog(s, sizeof log, NULL, log); bt_fatal("OpenGL shader: %s", log); }
        glAttachShader(p, s);
        glDeleteShader(s);
    }
    GLint ok;
    glLinkProgram(p);
    glGetProgramiv(p, GL_LINK_STATUS, &ok);
    if (!ok) { char log[4096]; glGetProgramInfoLog(p, sizeof log, NULL, log); bt_fatal("OpenGL link: %s", log); }
    return p;
}

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
    SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 0);
}

// The calling thread owns the context: tasks and buffer swaps come from one game thread at a time.
static void gpu_init(void) {
    if (!gpu.context || !SDL_GL_MakeCurrent(gpu_window, gpu.context)) bt_fatal("SDL render context: %s", SDL_GetError());
    if (gpu.draw) return;
    pthread_t completion;
    if (pthread_create(&completion, NULL, gpu_done_main, NULL)) bt_fatal("starting the GPU completion thread");
    pthread_detach(completion);

    gpu.draw = gpu_program(gpu_vertex_shader, gpu_fragment_shader);
    gpu.import = gpu_program(gpu_fullscreen_shader, gpu_import_shader);
    gpu.resolve = gpu_program(gpu_fullscreen_shader, gpu_resolve_shader);
    gpu.zresolve = gpu_program(gpu_fullscreen_shader, gpu_zresolve_shader);
    gpu.maskcopy = gpu_program(gpu_fullscreen_shader, gpu_maskcopy_shader);
    gpu.maskfrag = gpu_program(gpu_maskfrag_vertex_shader, gpu_maskfrag_shader);
    glUseProgram(gpu.draw);
    glUniform1i(glGetUniformLocation(gpu.draw, "atlas"), 0);
    glUniform1i(glGetUniformLocation(gpu.draw, "mats"), 1);
    gpu.u_scale = glGetUniformLocation(gpu.draw, "scale");
    gpu.u_frame = glGetUniformLocation(gpu.draw, "frame");
    gpu.u_color16 = glGetUniformLocation(gpu.draw, "color16");
    gpu.u_rmw = glGetUniformLocation(gpu.draw, "rmw");
    glUniform1i(glGetUniformLocation(gpu.draw, "dst"), 4);
    gpu.u_soften = glGetUniformLocation(gpu.draw, "soften");
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

// (Re)allocates t at width x height N64 pixels and scale sx, sy; own_depth for the in-between image.
static void gpu_target_init(GpuTarget *t, u32 address, int width, int height, int sx, int sy, int own_depth) {
    int w = width * sx, h = height * sy;
    t->address = address;
    if (t->width == width && t->height == height && t->sx == sx && t->sy == sy && t->color) return;
    t->width = width; t->height = height; t->sx = sx; t->sy = sy;
    gpu_texture(&t->color, GL_RGBA8, w, h, GL_RGBA, GL_UNSIGNED_BYTE);
    if (own_depth) gpu_texture(&t->depth, GL_DEPTH_COMPONENT32F, w, h, GL_DEPTH_COMPONENT, GL_FLOAT);
    else {  // VI framebuffers share one Z buffer, as BT shares its Z image between them
        if (gpu.depth_w != w || gpu.depth_h != h) {
            gpu_texture(&gpu.depth, GL_DEPTH_COMPONENT32F, w, h, GL_DEPTH_COMPONENT, GL_FLOAT);
            gpu.depth_w = w; gpu.depth_h = h;
            for (int i = 0; i < 3; i++) if (gpu.t[i].fbo && &gpu.t[i] != t) { gpu.t[i].depth = gpu.depth; gpu_attach(&gpu.t[i]); }
        }
        t->depth = gpu.depth;
        free(t->shadow);
        t->shadow = calloc((size_t)width * height, 2);
        if (!t->shadow) bt_fatal("allocating a GPU target");
    }
    gpu_attach(t);
    glDisable(GL_SCISSOR_TEST);
    glClearColor(0, 0, 0, 1);
    glClearDepth(1);
    glDepthMask(GL_TRUE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_SCISSOR_TEST);
    gpu_check("render target");
}

// ---- Texture atlas: decoded tiles keyed by TMEM content, tile layout and TLUT mode
static void gpu_flush(void);
static void gpu_import(GpuTarget *t, int every);
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
        o[5] = (u32)(i == 0 && seam);  // the shader may read tile 0's seam border (gpu_seams)
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

static GpuTarget *gpu_pick(void) {
    mdefer.on = 0;
    if (ip.on) return R.cimg == ip.address && R.cimg_siz == 2 && R.cimg_width == gpu.ipt.width ? &gpu.ipt : &gpu.none;
    for (int i = 0; i < 3; i++) {
        GpuTarget *t = &gpu.t[i];
        if (t->color && R.cimg_siz == 2 && t->address == R.cimg && t->width == R.cimg_width) {
            if (t->stale) { t->stale = 0; gpu_import(t, 0); }
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
    if (gpu.zt && R.zimg == gpu.zaddr && (R.om_l & 0x30)) gpu_resolve_depth();
    for (int i = 0; i < 3; i++)
        if (gpu.t[i].color && R.cimg >= gpu.t[i].address && (u64)R.cimg < (u64)gpu.t[i].address + (u64)gpu.t[i].width * gpu.t[i].height * 2)
            gpu.t[i].stale = 1;
    return NULL;
}

static void gpu_scissor(const GpuTarget *t, int *sc) {
    int x1 = R.sc_x1 * t->sx >> 2, y1 = R.sc_y1 * t->sy >> 2;
    sc[0] = R.sc_x0 * t->sx >> 2; sc[1] = R.sc_y0 * t->sy >> 2;
    sc[2] = x1 < t->width * t->sx ? x1 : t->width * t->sx;
    sc[3] = y1 < t->height * t->sy ? y1 : t->height * t->sy;
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
    GpuBatch *b = gpu.nb ? &gpu.b[gpu.nb - 1] : NULL;
    if (!b || b->t != t || b->zfunc != zfunc || b->zmask != zmask || b->decal != decal || b->rmw != rmw ||
        memcmp(b->sc, sc, sizeof sc)) {
        if (gpu.nb == gpu.cap_b && !(gpu.b = realloc(gpu.b, (size_t)(gpu.cap_b = gpu.cap_b * 2 + 64) * sizeof *gpu.b)))
            bt_fatal("allocating GPU batches");
        b = &gpu.b[gpu.nb++];
        *b = (GpuBatch){.t = t, .zfunc = zfunc, .zmask = zmask, .decal = decal, .rmw = rmw, .first = gpu.nv};
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

static int gpu_seam_tile(const GpuTarget *t, const RdpVtx *const *in) {
    if (t->sx == 1 && t->sy == 1) return 0;
    if ((R.om_h >> 20 & 3) >= 2 || !(R.om_h >> 12 & 3) || (R.om_h >> 16 & 1)) return 0;  // filtered, no LOD
    const Tile *tl = &R.tile[R.tex_tile & 7];
    int ms = (tl->lrs - tl->uls) >> 2, mt = (tl->lrt - tl->ult) >> 2;
    if (!(tl->cms & 2) || !(tl->cmt & 2) || tl->uls || tl->ult || tl->shifts || tl->shiftt) return 0;
    if (ms < 1 || mt < 1 || ms > 1023 || mt > 1023) return 0;
    if ((tl->masks && ms + 1 != 1 << tl->masks) || (tl->maskt && mt + 1 != 1 << tl->maskt)) return 0;
    float v[3][4];
    for (int i = 0; i < 3; i++) { v[i][0] = in[i]->x; v[i][1] = in[i]->y; v[i][2] = in[i]->s / 32; v[i][3] = in[i]->t / 32; }
    for (int i = 0; i < 3; i++)
        if (gpu_seam_edge(v, i, (i + 1) % 3, 0, ms + 1) >= 0 || gpu_seam_edge(v, i, (i + 1) % 3, 1, mt + 1) >= 0) return 1;
    return 0;
}

static void gpu_piece(const RdpVtx *const *in) {
    const GpuTileMemo *memo = &gpu.memo[R.tex_tile & 7];
    if (gpu.npiece == gpu.cap_piece &&
        !(gpu.piece = realloc(gpu.piece, (size_t)(gpu.cap_piece = gpu.cap_piece * 2 + 64) * sizeof *gpu.piece)))
        bt_fatal("allocating GPU seam pieces");
    GpuPiece *p = &gpu.piece[gpu.npiece++];
    p->slot = memo->slot; p->w = memo->w; p->h = memo->h;
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
            if (g->kind != f->kind + 1 || pf->slot == pg->slot || pf->w != pg->w || pf->h != pg->h ||
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
    GpuTarget *t = gpu_pick();
    gpu_pick_triangle = 0;
    if (!t) return 0;
    if (t == &gpu.none || (R.om_h >> 20 & 3) >= 2) return 1;  // no triangles in fill/copy mode
    const RdpVtx *in[3] = {a, b, c};
    int seam = (flags & RDP_TEX) && gpu_seam_tile(t, in);
    u32 mat = gpu_material(GPU_TRI, (flags & RDP_TEX) != 0, R.tex_tile, seam);
    if (seam) gpu_piece(in);
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

static int gpu_texrect(u32 w0, u32 w1, u32 st, u32 dsdt, int flip) {
    if (!gpu_enabled()) return 0;
    GpuTarget *t = gpu_pick();
    if (!t) return 0;
    if (t == &gpu.none) return 1;
    int kx = t->sx, ky = t->sy, cyc = R.om_h >> 20 & 3, tile = w1 >> 24 & 7;
    int xh = w0 >> 12 & 0xFFF, yh = w0 & 0xFFF, xl = w1 >> 12 & 0xFFF, yl = w1 & 0xFFF;
    float dsdx = (s16)(dsdt >> 16) / 32.0f, dtdy = (s16)dsdt / 32.0f;  // texels * 32 per N64 pixel
    int x0 = xl * kx >> 2, y0 = yl * ky >> 2, x1, y1;
    if (cyc >= 2) { x1 = ((xh >> 2) + 1) * kx; y1 = ((yh >> 2) + 1) * ky; dsdx /= 4; }
    else { x1 = (xh * kx + 3) >> 2; y1 = (yh * ky + 3) >> 2; }
    u32 mat = gpu_material(cyc == 2 ? GPU_COPY : GPU_TEXRECT, 1, tile, 0);
    gpu_quad(t, x0, y0, x1, y1, mat, (s16)(st >> 16), (s16)st, dsdx / kx, dtdy / ky, flip, cyc < 2 && (R.om_l >> 2 & 1));
    return 1;
}

// Fill rectangles; the Z clear (fill 0xFFFC into the Z image) clears the GPU depth and also runs
// on the software path in RDRAM (return 0), except in in-between passes.
static int gpu_fill(int ulx, int uly, int lrx, int lry) {
    if (!gpu_enabled()) return 0;
    mdefer.on = 0;
    int cyc = R.om_h >> 20 & 3;
    if (cyc == 3 && R.zimg && R.cimg == R.zimg && R.cimg_siz == 2 && R.fill == 0xFFFCFFFCu) {
        GpuTarget *t = ip.on ? &gpu.ipt : NULL;
        for (int i = 0; i < 3 && !t; i++) if (gpu.t[i].color && gpu.t[i].width == R.cimg_width) t = &gpu.t[i];
        if (!t || !t->color || t->width != R.cimg_width) return ip.on;
        int sc[4], x0 = ulx * t->sx >> 2, y0 = uly * t->sy >> 2, x1 = ((lrx >> 2) + 1) * t->sx, y1 = ((lry >> 2) + 1) * t->sy;
        gpu_scissor(t, sc);
        if (x0 < sc[0]) x0 = sc[0];
        if (y0 < sc[1]) y0 = sc[1];
        if (x1 > sc[2]) x1 = sc[2];
        if (y1 > sc[3]) y1 = sc[3];
        if (x1 > x0 && y1 > y0) {
            gpu_flush();
            glBindFramebuffer(GL_FRAMEBUFFER, t->fbo);
            glScissor(x0, y0, x1 - x0, y1 - y0);
            glDepthMask(GL_TRUE);
            glClear(GL_DEPTH_BUFFER_BIT);
        }
        if (!ip.on) gpu.zgen++;
        return ip.on;
    }
    GpuTarget *t = gpu_pick();
    if (!t) return 0;
    if (t == &gpu.none) return 1;
    int kx = t->sx, ky = t->sy, x0 = ulx * kx >> 2, y0 = uly * ky >> 2, x1, y1;
    if (cyc >= 2) { x1 = ((lrx >> 2) + 1) * kx; y1 = ((lry >> 2) + 1) * ky; }  // fill/copy: inclusive
    else { x1 = (lrx * kx + 3) >> 2; y1 = (lry * ky + 3) >> 2; }
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
    glUseProgram(gpu.draw);
    glBindVertexArray(gpu.vao);
    glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D, gpu.atlas);
    glActiveTexture(GL_TEXTURE1); glBindTexture(GL_TEXTURE_BUFFER, gpu.mat_texture);
    glUniform1ui(gpu.u_frame, gpu.frame);
    glUniform1i(gpu.u_soften, bt_setting(BT_SET_SMOOTH));
    GpuTarget *bound = NULL;
    int decal = -1;
    for (int i = 0; i < gpu.nb; i++) {
        GpuBatch *b = &gpu.b[i];
        if (b->t != bound) {
            bound = b->t;
            glBindFramebuffer(GL_FRAMEBUFFER, bound->fbo);
            glViewport(0, 0, bound->width * bound->sx, bound->height * bound->sy);
            glUniform2i(gpu.u_scale, bound->sx, bound->sy);
            glUniform1i(gpu.u_color16, bound->sx == 1 && bound->sy == 1);
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
        glUniform1i(gpu.u_rmw, 1);
        for (int k = 0; k < b->count; k += 3) { gpu_barrier(); glDrawArrays(GL_TRIANGLES, b->first + k, 3); }
        glUniform1i(gpu.u_rmw, 0);
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

// Draws program over t's N64-sized grid into the RG8UI resolve image and reads it into dst (and also).
static void gpu_resolve_pass(GpuTarget *t, GLuint program, GLint scale, GLuint source, u8 *dst, u8 *also) {
    gpu_pass_begin();
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
    glUniform2i(scale, t->sx, t->sy);
    glActiveTexture(GL_TEXTURE2); glBindTexture(GL_TEXTURE_2D, source);
    glBindVertexArray(gpu.empty_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    gpu_readback(t->width, t->height, GL_RG_INTEGER, GL_UNSIGNED_BYTE, 2, dst, also, NULL);  // N64 rows, big-endian pixels
    gpu_pass_end();
    gpu_check("resolve");
    gpu.resolves++;
}

static void gpu_resolve(GpuTarget *t) {
    int n = t->width * t->height * 2;
    u8 *dst = gptr(t->address, (u32)n);
    if (!t->drawn || !dst) return;
    gpu_resolve_pass(t, gpu.resolve, gpu.r_scale, t->color, dst, t->shadow);
    t->drawn = 0;
}

// Z memory gets the GPU's depth: at the end of a task (the game samples it with the CPU, 1EC1AD0.c)
// and before the software path draws over it or loads it as a texture.
static void gpu_resolve_depth(void) {
    GpuTarget *t = gpu.zt;
    u8 *dst = t ? gptr(gpu.zaddr, (u32)(t->width * t->height * 2)) : NULL;
    gpu.zt = NULL;
    if (dst) gpu_resolve_pass(t, gpu.zresolve, gpu.z_scale, t->depth, dst, NULL);
}

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
static void gpu_import(GpuTarget *t, int every) {
    int n = t->width * t->height * 2;
    const u8 *src = gptr(t->address, (u32)n);
    if (!src || (!every && !memcmp(src, t->shadow, (size_t)n))) return;
    gpu_pass_begin();
    int realloc_import = gpu.import_w != t->width || gpu.import_h != t->height;
    for (int i = 0; i < 2; i++) {
        glActiveTexture(GL_TEXTURE2 + i);
        if (realloc_import) gpu_texture(&gpu.import_tex[i], GL_RG8UI, t->width, t->height, GL_RG_INTEGER, GL_UNSIGNED_BYTE);
        glBindTexture(GL_TEXTURE_2D, gpu.import_tex[i]);
        gpu_upload(0, 0, t->width, t->height, GL_RG_INTEGER, GL_UNSIGNED_BYTE, 2, i ? t->shadow : src);
    }
    gpu.import_w = t->width; gpu.import_h = t->height;
    glBindFramebuffer(GL_FRAMEBUFFER, t->fbo);
    glViewport(0, 0, t->width * t->sx, t->height * t->sy);
    glUseProgram(gpu.import);
    glUniform2i(gpu.i_scale, t->sx, t->sy);
    glUniform1i(gpu.i_every, every);
    glBindVertexArray(gpu.empty_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    gpu_pass_end();
    gpu_check("import");
    memcpy(t->shadow, src, (size_t)n);
    t->changed = 1;  // not drawn: RDRAM already holds this content
    gpu.imports++;
}

// The picture of t at its resolution, as XRGB8888 rows (top first) in gpu.pixels.
static u32 *gpu_read_picture(GpuTarget *t) {
    size_t n = (size_t)t->width * t->sx * t->height * t->sy;
    if (gpu.pixels_n < n) {
        free(gpu.pixels);
        if (!(gpu.pixels = malloc(n * sizeof *gpu.pixels))) bt_fatal("allocating the GPU picture");
        gpu.pixels_n = n;
    }
    gpu_flush();
    glBindFramebuffer(GL_READ_FRAMEBUFFER, t->fbo);
    gpu_readback(t->width * t->sx, t->height * t->sy, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, 4, gpu.pixels, NULL, t);
    gpu_check("picture");
    return gpu.pixels;
}

// Hands the picture to rdp_frame: the pixel buffers are swapped, not copied, under the lock.
static void gpu_install(GpuTarget *t, u32 *pixels) {
    int slot = (int)(t - gpu.t);
    size_t n = (size_t)t->width * t->sx * t->height * t->sy;
    pthread_mutex_lock(&scanout_lock);
    if (scanout[slot].width * scanout[slot].sx * scanout[slot].height * scanout[slot].sy != (int)n) {
        free(scanout[slot].pixels);
        scanout[slot].pixels = NULL;
    }
    gpu.pixels = scanout[slot].pixels;
    gpu.pixels_n = gpu.pixels ? n : 0;
    scanout[slot].pixels = pixels;
    scanout[slot].address = t->address;
    scanout[slot].width = t->width; scanout[slot].height = t->height;
    scanout[slot].sx = t->sx; scanout[slot].sy = t->sy;
    pthread_mutex_unlock(&scanout_lock);
}

// CPU copies of the pictures (rdp_frame): without a window, and for the virtual clock's dumps, which
// the game threads write. A window with the real clock reads its texture when it needs pixels.
static int gpu_pictures(void) { return !gpu_share || bt_vclock_on; }

// Copies t into show texture k for the window; the copy is on the GPU, nothing waits for it.
static GLuint gpu_show(GpuTarget *t, int k) {
    int w = t->width * t->sx, h = t->height * t->sy;
    gpu_pass_begin();
    if (gpu.show[k].w != w || gpu.show[k].h != h) {  // same name: the window may be drawing with it
        gpu_texture(&gpu.show[k].tex, GL_RGBA8, w, h, GL_RGBA, GL_UNSIGNED_BYTE);
        gpu.show[k].w = w; gpu.show[k].h = h;
    }
    if (!gpu.show_fbo) glGenFramebuffers(1, &gpu.show_fbo);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, t->fbo);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, gpu.show_fbo);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gpu.show[k].tex, 0);
    glBlitFramebuffer(0, 0, w, h, 0, 0, w, h, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    gpu_pass_end();
    gpu_check("show");
    return gpu.show[k].tex;
}

// shortcut: the window draws with a show texture without waiting for the copy's fence; it relies on
// the GPU running the renderer's flushed commands first (the VI shows a picture only after the DP
// event, behind gpu_end's fence). Add a fence per texture if a stale picture ever shows.
static void gpu_publish(GpuTarget *t) {
    if (gpu_share) {
        int slot = (int)(t - gpu.t);
        GLuint tex = gpu_show(t, slot);
        if (!gpu.queuing) glFlush();  // gpu_end flushes behind its fence
        pthread_mutex_lock(&scanout_lock);
        if (!gpu_pictures()) { free(scanout[slot].pixels); scanout[slot].pixels = NULL; }
        scanout[slot].tex = tex;
        scanout[slot].address = t->address;
        scanout[slot].width = t->width; scanout[slot].height = t->height;
        scanout[slot].sx = t->sx; scanout[slot].sy = t->sy;
        pthread_mutex_unlock(&scanout_lock);
    }
    if (gpu_pictures()) {
        u32 *pixels = gpu_read_picture(t);
        if (!gpu.queuing) gpu_install(t, pixels);  // else gpu_finish does
    }
    t->changed = 0;
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
}

// The image with its fragments on the GPU, for loads from it: RDRAM bytes, then one point per fragment.
static void gpu_mask_compose(void) {
    GpuTarget *m = &gpu.mask;
    int w = mdefer.width, h = mdefer.height;
    gpu_pass_begin();
    glActiveTexture(GL_TEXTURE2);
    if (!m->color || m->width != w || m->height != h) {
        gpu_texture(&m->color, GL_R8, w, h, GL_RED, GL_UNSIGNED_BYTE);
        if (!m->fbo) glGenFramebuffers(1, &m->fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, m->fbo);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m->color, 0);
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) bt_fatal("OpenGL incomplete mask framebuffer");
        m->width = w; m->height = h; m->sx = m->sy = 1;
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
        glBindFramebuffer(GL_FRAMEBUFFER, gpu.mz_fbo);
        glViewport(0, 0, w, h);
        glDisable(GL_BLEND);
        glUseProgram(gpu.zresolve);
        glUniform2i(gpu.z_scale, z->sx, z->sy);
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
    gpu.frame++;
    
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
    gpu_flush();
    gpu.queuing = 1;
    gpu_mask_finalize();  // queues the mask's depth when its fragments need it
    for (int i = 0; i < 3; i++) {
        if (gpu.t[i].changed) gpu_publish(&gpu.t[i]);
        gpu_resolve(&gpu.t[i]);
    }
    gpu_resolve_depth();
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
    render_sx = sx;
    for (int i = 0; i < 3 && slot < 0; i++) if (gpu.t[i].color && gpu.t[i].address == address) slot = i;
    for (int i = 0; i < 3 && slot < 0; i++) if (!gpu.t[i].color) slot = i;
    if (slot < 0) slot = (int)(replace++ % 3);
    GpuTarget *t = &gpu.t[slot];
    int fresh = t->address != address || t->width != width || t->sx != sx || t->sy != sy;
    if (fresh) gpu_resolve(t);
    for (int i = 0; i < 3; i++)  // a new scale: every image starts over from RDRAM
        if (fresh && gpu.t[i].color && &gpu.t[i] != t && (gpu.t[i].sx != sx || gpu.t[i].sy != sy)) {
            gpu_resolve(&gpu.t[i]);
            gpu_target_init(&gpu.t[i], gpu.t[i].address, gpu.t[i].width, gpu.t[i].height, sx, sy, 0);
            gpu_import(&gpu.t[i], 1);
        }
    gpu_target_init(t, address, width, width * 3 / 4, sx, sy, 0);
    gpu_import(t, fresh);
    if (t->changed) gpu_publish(t);
}

// Frame interpolation: the in-between image is its own target, started from the picture the task
// drew over; its depth is its own too.
static void gpu_interp_target(void) {
    GpuTarget *t = gpu_pick();
    if (!t || t == &gpu.none) return;
    gpu_target_init(&gpu.pre, 0, t->width, t->height, t->sx, t->sy, 1);
    gpu_target_init(&gpu.ipt, R.cimg, t->width, t->height, t->sx, t->sy, 1);
    gpu_pass_begin();
    glBindFramebuffer(GL_READ_FRAMEBUFFER, t->fbo);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, gpu.pre.fbo);
    glBlitFramebuffer(0, 0, t->width * t->sx, t->height * t->sy, 0, 0, t->width * t->sx, t->height * t->sy, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    gpu_pass_end();
    gpu_check("in-between start");
    ip.address = R.cimg;
}

static void gpu_interp_begin(void) {
    gpu_finish();
    gpu_pass_begin();
    glBindFramebuffer(GL_READ_FRAMEBUFFER, gpu.pre.fbo);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, gpu.ipt.fbo);
    int w = gpu.ipt.width * gpu.ipt.sx, h = gpu.ipt.height * gpu.ipt.sy;
    glBlitFramebuffer(0, 0, w, h, 0, 0, w, h, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    glBindFramebuffer(GL_FRAMEBUFFER, gpu.ipt.fbo);
    glDepthMask(GL_TRUE);
    glClear(GL_DEPTH_BUFFER_BIT);
    gpu_pass_end();
}

static u32 *gpu_interp_end(int index, unsigned *tex, int *w, int *h, int *sx, int *sy) {
    *w = gpu.ipt.width; *h = gpu.ipt.height; *sx = gpu.ipt.sx; *sy = gpu.ipt.sy;
    if (gpu_share) { *tex = gpu_show(&gpu.ipt, 3 + index); glFlush(); }  // the pass ends here: the window may show it
    return gpu_pictures() ? gpu_read_picture(&gpu.ipt) : NULL;
}
#else
void rdp_gpu_share(void *window) { (void)window; }
static void gpu_begin(void) { gpu_enabled(); }
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
