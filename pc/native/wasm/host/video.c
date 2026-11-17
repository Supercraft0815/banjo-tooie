// Window: shows the framebuffer the VI scans out (16-bit RGBA5551, big-endian bytes).
// Runs on the main thread, which macOS requires for windows and events.
// The window has an OpenGL context. With the GPU renderer the picture is a texture of the renderer's
// share group (rdp_frame_texture) and never passes through the CPU; other pictures (software
// renderer, scale 1 from RDRAM) are uploaded once per retrace. ImGui draws over the window; key help
// and the FPS display use an SDL surface shown as a texture while visible.
//   BT_HEADLESS=1         no window (frames are still produced)
//   BT_DUMP=prefix        write every BT_DUMP_EVERY-th (default 30) displayed frame as prefix_NNNNN.bmp,
//                         from BT_DUMP_FROM seconds of game time on (default 0)
//   BT_EXIT_AFTER=secs    quit after that many seconds (game time, like BT_PRESS)
//   BT_SPEED=x            game clock at x times real time (fast-forward for scripted runs)
//   BT_PRESS=...          scripted controller input (input.c)
//   BT_SCALE=1..4         internal raster resolution (default 1); the game's widescreen option
//                         (game select screen) shows 16:9 and renders 4/3 as many columns
//   BT_WIDESCREEN=1       force that option on (the saved setting stays as it is)
//   BT_DUMP_HIRES=1       dump the enlarged image; otherwise dump the guest framebuffer
//   BT_RENDER_STATS=1     report raster time/tasks and observed framebuffer changes
//   BT_INTERP=1           frame interpolation: in-between pictures from the display list (gsp.c),
//                         shown one retrace before each game frame; game state is unaffected
// F11 toggles fullscreen, F2 opens the settings menu (menu.cpp), F12 saves a screenshot.
#include "glad/gl.h"
#include <SDL3/SDL.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "rdp.h"
#include "retrace.h"

static void convert(u32 fb, int w, int h, u32 *out) {
    const u8 *p = bt_mem + fb;
    if ((u64)fb + (u64)w * h * 2 > bt_inst.w2c_memory.size) return;
    for (int i = 0; i < w * h; i++, p += 2) {
        u32 v = (u32)p[0] << 8 | p[1], r = v >> 11 & 31, g = v >> 6 & 31, b = v >> 1 & 31;
        out[i] = 0xFF000000u | (r << 3 | r >> 2) << 16 | (g << 3 | g >> 2) << 8 | (b << 3 | b >> 2);
    }
}

static void controls(SDL_Renderer *ren) {
    SDL_FRect box = {8, 244, 464, 108};
    SDL_SetRenderScale(ren, 2, 2);
    SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 220);
    SDL_RenderFillRect(ren, &box);
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    static const char *lines[] = {
        "TASTATUR                         F1: Hilfe ausblenden", "",
        "WASD: Bewegen       Strg + WASD: Langsam gehen",
        "Leertaste: A        Shift / X: B     Q / Z: Z",
        "Enter / Esc: Start/Pause     E: R     Tab: L",
        "Pfeiltasten: C-Knoepfe/Kamera     IJKL: Steuerkreuz",
        "Freie Kamera: Pfeile drehen/neigen   C: Ego-Sicht", "",
        "F2: Einstellungen  F11: Vollbild  F12: Bildschirmfoto"};
    for (size_t i = 0; i < sizeof lines / sizeof *lines; i++)
        SDL_RenderDebugText(ren, 16, 252 + (float)i * 12, lines[i]);
    SDL_SetRenderScale(ren, 1, 1);
}

// F12: the shown picture at internal resolution, as a BMP in the user data directory.
static void screenshot(u32 *pixels, int w, int h) {
    char path[1024], stamp[32], *dir = SDL_GetPrefPath("", "BanjoTooie");
    time_t now = time(NULL);
    if (!dir) return;
    strftime(stamp, sizeof stamp, "%Y%m%d-%H%M%S", localtime(&now));
    snprintf(path, sizeof path, "%sscreenshot-%s.bmp", dir, stamp);
    SDL_free(dir);
    SDL_Surface *s = SDL_CreateSurfaceFrom(w, h, SDL_PIXELFORMAT_XRGB8888, pixels, w * 4);
    if (s && SDL_SaveBMP(s, path)) fprintf(stderr, "bt_native: screenshot %s\n", path);
    if (s) SDL_DestroySurface(s);
}

// The picture for a retrace. With frame interpolation the first retraces of a new game frame show
// its in-between images (rdp_interp_frame), the frame itself as many retraces later.
static int picture(u32 fb, u32 age, int w, int h, u32 *out, int *sx) {
    int s = bt_setting(BT_SET_INTERP) ? rdp_interp_frame(fb, w, h, (int)age, out, sx) : 0;
    return s ? s : rdp_frame(fb, w, h, out, sx);
}

// Saves the picture of a retrace as BMP: the guest framebuffer, or the enlarged image with hires.
int bt_video_save(const char *path, u32 fb, u32 width, u32 age, int hires) {
    static u32 out[640 * 480 * RDP_MAX_SX * RDP_MAX_SCALE];
    int w = width >= 16 && width <= 640 ? (int)width : 320, h = w * 3 / 4, sx = 1, sy = 0, ok = 0;
    if (!fb) return 0;
    if (bt_setting(BT_SET_INTERP)) rdp_interp_wait();  // dumps do not depend on the worker's timing
    if (hires || bt_setting(BT_SET_INTERP)) sy = picture(fb, age, w, h, out, &sx);
    if (sy && !hires && (sx > 1 || sy > 1)) sy = 0;  // guest-sized dumps stay the guest image
    if (sy) { w *= sx; h *= sy; } else convert(fb, w, h, out);
    SDL_Surface *s = SDL_CreateSurfaceFrom(w, h, SDL_PIXELFORMAT_XRGB8888, out, w * 4);
    if (s) { ok = SDL_SaveBMP(s, path); SDL_DestroySurface(s); }
    return ok;
}

// Virtual clock: dumps and the exit time follow retraces, so a rerun writes the same files.
void bt_video_retrace(u32 count, u32 fb, u32 width, u32 age) {
    const char *dump = getenv("BT_DUMP");
    int every = getenv("BT_DUMP_EVERY") ? atoi(getenv("BT_DUMP_EVERY")) : 30;
    double secs = count / 59.94, quit_after = getenv("BT_EXIT_AFTER") ? atof(getenv("BT_EXIT_AFTER")) : 0;
    if (quit_after > 0 && secs >= quit_after) exit(0);
    bt_control_retrace(count, fb, width, age);
    if (!dump || !fb || every <= 0 || count % (u32)every || secs < (getenv("BT_DUMP_FROM") ? atof(getenv("BT_DUMP_FROM")) : 0)) return;
    char path[512];
    snprintf(path, sizeof path, "%s_%05u.bmp", dump, count);
    bt_video_save(path, fb, width, age, getenv("BT_DUMP_HIRES") != NULL);
}

// Before the game threads start: osContInit already needs the connected gamepads.
void bt_video_init(void) {
    int headless = getenv("BT_HEADLESS") != NULL, audio = !headless && !getenv("BT_MUTE");
    if (!SDL_Init((headless ? 0 : SDL_INIT_VIDEO | SDL_INIT_GAMEPAD) | (audio ? SDL_INIT_AUDIO : 0)))
        bt_fatal("SDL_Init: %s", SDL_GetError());
    if (!headless) bt_input_open_pads();
}

static SDL_Window *win;
static int vsync, wanted_vsync;
static void apply_vsync(void) {
    wanted_vsync = bt_setting(BT_SET_VSYNC);
    int actual = 0;
    if (!SDL_GL_SetSwapInterval(wanted_vsync)) SDL_Log("VSync: %s", SDL_GetError());
    vsync = SDL_GL_GetSwapInterval(&actual) && actual != 0;
}
static struct { GLuint program, vao, sampler, picture, ui; } gl;

// Main thread, before the game starts (the GPU renderer's contexts join this one's share group).
void bt_video_window(void) {
    if (getenv("BT_HEADLESS")) { rdp_gpu_share(NULL); return; }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
    win = SDL_CreateWindow("Banjo-Tooie | WASD: Bewegen | Leertaste: A | Enter: Start | F1: Tastenhilfe", 960, 720,
                           SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
    if (!win || !SDL_GL_CreateContext(win)) bt_fatal("SDL window: %s", SDL_GetError());
    apply_vsync();
    bt_menu_init(win, SDL_GL_GetCurrentContext());
    rdp_gpu_share(win);
    // One triangle over the viewport; texture row 0 is the top of the picture.
    static const char *vs = "#version 330 core\nout vec2 uv;void main(){vec2 p=vec2((gl_VertexID<<1)&2,gl_VertexID&2);"
                            "uv=vec2(p.x,1.0-p.y);gl_Position=vec4(p*2.0-1.0,0.0,1.0);}";
    static const char *fs = "#version 330 core\nuniform sampler2D t;in vec2 uv;out vec4 c;void main(){c=texture(t,uv);}";
    GLuint v = glCreateShader(GL_VERTEX_SHADER), f = glCreateShader(GL_FRAGMENT_SHADER);
    GLint ok;
    glShaderSource(v, 1, &vs, NULL); glCompileShader(v);
    glShaderSource(f, 1, &fs, NULL); glCompileShader(f);
    gl.program = glCreateProgram();
    glAttachShader(gl.program, v); glAttachShader(gl.program, f);
    glLinkProgram(gl.program);
    glGetProgramiv(gl.program, GL_LINK_STATUS, &ok);
    if (!ok) bt_fatal("OpenGL: the window's shader does not link");
    glGenVertexArrays(1, &gl.vao);
    glGenSamplers(1, &gl.sampler);  // the renderer's textures keep their own filter state
    glSamplerParameteri(gl.sampler, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glSamplerParameteri(gl.sampler, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glGenTextures(1, &gl.picture);
    glGenTextures(1, &gl.ui);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glDisable(GL_DEPTH_TEST);
    // Start the native event loop and audio device before the guest starts its VI timer.
    SDL_PollEvent(NULL);  // leave pending input queued for the first frame
    if (!getenv("BT_MUTE")) bt_ai_open();
}

// XRGB8888/ARGB8888 rows (top first) into tex.
static void upload(GLuint tex, int w, int h, const void *pixels) {
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, pixels);
}

static void draw(GLuint tex, int linear) {
    glSamplerParameteri(gl.sampler, GL_TEXTURE_MIN_FILTER, linear ? GL_LINEAR : GL_NEAREST);
    glSamplerParameteri(gl.sampler, GL_TEXTURE_MAG_FILTER, linear ? GL_LINEAR : GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, tex);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

// After each buffer swap: the display's vsync fires the retraces where its rate fits (retrace.h);
// otherwise, and with BT_SPEED far from a display multiple or the virtual clock, vi.c's timer does.
static void retrace_clock(void) {
    static RetraceClock clock;
    double now = (double)SDL_GetTicksNS() * 1e-9, since = now - clock.prev;
    const SDL_DisplayMode *mode = SDL_GetCurrentDisplayMode(SDL_GetDisplayForWindow(win));
    int n = vsync && !bt_vclock_on ? retrace_step(&clock, now, mode ? mode->refresh_rate : 0, 59.94 * bt_speed()) : -1;
    atomic_store(&bt_vi_display, n >= 0);
    if (n < 0) clock.on = 0;
    if (n < 0 && since < .002) SDL_Delay(2);  // nothing paces the loop
    for (; n > 0; n--) bt_vi_tick();
}

_Noreturn void bt_video_main(void) {
    int headless = getenv("BT_HEADLESS") != NULL, every = getenv("BT_DUMP_EVERY") ? atoi(getenv("BT_DUMP_EVERY")) : 30;
    const char *dump = getenv("BT_DUMP");
    double quit_after = getenv("BT_EXIT_AFTER") ? atof(getenv("BT_EXIT_AFTER")) : 0;
    double dump_from = getenv("BT_DUMP_FROM") ? atof(getenv("BT_DUMP_FROM")) : 0;
    SDL_Surface *ui = NULL;    // key help and FPS use SDL's software renderer
    SDL_Renderer *ren = NULL;
    char ui_key[64] = "";      // what the ui texture shows
    static u32 pixels[640 * 480 * RDP_MAX_SX * RDP_MAX_SCALE], dump_pixels[640 * 480];
    GLuint shown = 0;          // the picture's texture: the renderer's, or gl.picture with `pixels`
    int have_pixels = 0;       // `pixels` holds the shown picture
    int wide = 0, fullscreen = 0;
    int w = 320, h = 240;
    int show_controls = 0, shot = 0;
    u32 last = 0, frames = 0;
    u32 previous_fb = 0, swaps = 0, fps_swaps = 0, repeated = 0, skipped = 0;
    u64 stats_start = 0, fps_start = 0;
    char fps_text[16] = "";
    if (!headless) upload(shown = gl.picture, 1, 1, &(u32){0});
    u64 start = SDL_GetTicks();
    for (;;) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) exit(0);
            if (!headless && bt_menu_event(&e)) continue;
            if (e.type == SDL_EVENT_KEY_DOWN && !e.key.repeat && e.key.key == SDLK_F1)
                show_controls = !show_controls;
            if (e.type == SDL_EVENT_KEY_DOWN && !e.key.repeat && e.key.key == SDLK_F12) shot = 1;
            if (e.type == SDL_EVENT_KEY_DOWN && !e.key.repeat && e.key.key == SDLK_F11 && win)
                bt_setting_set(BT_SET_FULLSCREEN, !bt_setting(BT_SET_FULLSCREEN));
            bt_input_event(&e);
        }
        double secs = (SDL_GetTicks() - start) / 1000.0 * bt_speed();  // game time
        if (quit_after > 0 && secs >= quit_after && !bt_vclock_on) exit(0);
        bt_input_update(secs, !headless);
        u32 fb, width, age, count = bt_vi_frame(&fb, &width, &age);
        if (count == last) repeated++; else skipped += count - last - 1;  // presents without a new retrace; retraces never shown
        if (count != last) {
            last = count;
            if (fb && fb != previous_fb) swaps++, fps_swaps++;
            if (SDL_GetTicks() - fps_start >= 1000) {  // game pictures per second, for the FPS setting
                u64 now = SDL_GetTicks();
                snprintf(fps_text, sizeof fps_text, "%.0f FPS", fps_swaps * 1000.0 / (now - fps_start));
                fps_swaps = 0; fps_start = now;
            }
            previous_fb = fb;
            if (bt_setting(BT_SET_RENDER_STATS) && SDL_GetTicks() - stats_start >= 5000) {
                u64 now = SDL_GetTicks();
                fprintf(stderr, "video: observed framebuffer changes/s=%.1f presents repeated=%u retraces skipped=%u\n",
                        swaps * 1000.0 / (now - stats_start), repeated, skipped);
                swaps = repeated = skipped = 0; stats_start = now;
            }
            int base_w = width >= 16 && width <= 640 ? (int)width : 320, base_h = base_w * 3 / 4;
            int sx = 1, scale = 0;
            GLuint tex = win ? rdp_frame_texture(fb, base_w, base_h, bt_setting(BT_SET_INTERP) ? (int)age : -1, &sx, &scale) : 0;
            if (!tex) scale = picture(fb, age, base_w, base_h, pixels, &sx);
            w = base_w * (scale ? sx : 1); h = base_h * (scale ? scale : 1);
            if (!scale) {
                if (fb) convert(fb, w, h, pixels); else memset(pixels, 0, (size_t)w * h * sizeof *pixels);
            }
            have_pixels = !tex;
            if (win && !tex) upload(gl.picture, w, h, pixels);
            if (win) shown = tex ? tex : gl.picture;
            frames++;
            if (dump && !bt_vclock_on && every > 0 && frames % (u32)every == 0 && secs >= dump_from) {
                char path[512];
                int dw = w, dh = h;
                u32 *dp = pixels;
                if (scale && !getenv("BT_DUMP_HIRES")) {
                    dw = base_w; dh = base_h; dp = dump_pixels;
                    convert(fb, dw, dh, dp);
                } else if (!have_pixels) {
                    glBindTexture(GL_TEXTURE_2D, shown);
                    glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, pixels);
                    have_pixels = 1;
                }
                SDL_Surface *s = SDL_CreateSurfaceFrom(dw, dh, SDL_PIXELFORMAT_XRGB8888, dp, dw * 4);
                snprintf(path, sizeof path, "%s_%05u.bmp", dump, frames);
                if (s) { SDL_SaveBMP(s, path); SDL_DestroySurface(s); }
            }
        }
        if (headless) { usleep(4000); continue; }
        if (shot) {  // F12
            if (!have_pixels) {
                glBindTexture(GL_TEXTURE_2D, shown);
                glGetTexImage(GL_TEXTURE_2D, 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, pixels);
                have_pixels = 1;
            }
            screenshot(pixels, w, h);
            shot = 0;
        }
        if (fullscreen != bt_setting(BT_SET_FULLSCREEN))  // F11 or the settings menu
            SDL_SetWindowFullscreen(win, fullscreen = bt_setting(BT_SET_FULLSCREEN));
        if (bt_widescreen() != wide) {  // 304 columns are 16:9 wide in the game's widescreen mode
            int ww, wh;
            wide = !wide;
            if (!(SDL_GetWindowFlags(win) & SDL_WINDOW_FULLSCREEN) && SDL_GetWindowSize(win, &ww, &wh))
                SDL_SetWindowSize(win, wide ? wh * 16 / 9 : wh * 4 / 3, wh);
        }
        // The picture, letterboxed to 4:3 or 16:9.
        int pw, ph;
        SDL_GetWindowSizeInPixels(win, &pw, &ph);
        int vw = wide ? ph * 16 / 9 : ph * 4 / 3, vh = ph;
        if (vw > pw) { vw = pw; vh = wide ? pw * 9 / 16 : pw * 3 / 4; }
        glViewport(0, 0, pw, ph);
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport((pw - vw) / 2, (ph - vh) / 2, vw, vh);
        glUseProgram(gl.program);
        glBindVertexArray(gl.vao);
        glBindSampler(0, gl.sampler);
        glDisable(GL_BLEND);
        draw(shown, bt_setting(BT_SET_FILTER));
        // Overlays in a 960- or 1280-wide logical space over the picture; redrawn when they change.
        int fps = bt_setting(BT_SET_SHOW_FPS) && fps_text[0];
        if (show_controls || fps) {
            char key[64];
            int uw = wide ? 1280 : 960;
            snprintf(key, sizeof key, "%d %d %s", uw, show_controls, fps ? fps_text : "");
            if (!ui || ui->w != uw) {
                if (ren) SDL_DestroyRenderer(ren);
                if (ui) SDL_DestroySurface(ui);
                ui = SDL_CreateSurface(uw, 720, SDL_PIXELFORMAT_ARGB8888);
                ren = ui ? SDL_CreateSoftwareRenderer(ui) : NULL;
                if (!ren) bt_fatal("SDL overlay: %s", SDL_GetError());
            }
            if (strcmp(key, ui_key)) {
                snprintf(ui_key, sizeof ui_key, "%s", key);
                SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
                SDL_RenderClear(ren);
                if (show_controls) controls(ren);
                if (fps) {  // top right, 2x debug font (8 px per glyph)
                    float x = (wide ? 640 : 480) - 8 - 8 * (float)strlen(fps_text);
                    SDL_FRect box = {x - 4, 4, 8 * (float)strlen(fps_text) + 8, 16};
                    SDL_SetRenderScale(ren, 2, 2);
                    SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
                    SDL_SetRenderDrawColor(ren, 0, 0, 0, 160);
                    SDL_RenderFillRect(ren, &box);
                    SDL_SetRenderDrawColor(ren, 255, 255, 64, 255);
                    SDL_RenderDebugText(ren, x, 8, fps_text);
                    SDL_SetRenderScale(ren, 1, 1);
                }
                SDL_RenderPresent(ren);
                upload(gl.ui, ui->w, ui->h, ui->pixels);
            }
            glEnable(GL_BLEND);
            glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);  // the surface holds colour times alpha
            draw(gl.ui, 1);
        }
        if (bt_menu_open()) bt_menu_draw(fps_text, repeated, skipped);
        if (wanted_vsync != bt_setting(BT_SET_VSYNC)) apply_vsync();
        SDL_GL_SwapWindow(win);
        retrace_clock();
    }
}
