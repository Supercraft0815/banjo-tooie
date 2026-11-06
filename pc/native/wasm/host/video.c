// Window: shows the framebuffer the VI scans out (16-bit RGBA5551, big-endian bytes).
// Runs on the main thread, which macOS requires for windows and events.
//   BT_HEADLESS=1         no window (frames are still produced)
//   BT_DUMP=prefix        write every BT_DUMP_EVERY-th (default 30) displayed frame as prefix_NNNNN.bmp
//   BT_EXIT_AFTER=secs    quit after that many seconds (game time, like BT_PRESS)
//   BT_SPEED=x            game clock at x times real time (fast-forward for scripted runs)
//   BT_PRESS=...          scripted controller input (input.c)
#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "guest.h"

static void convert(u32 fb, int w, int h, u32 *out) {
    const u8 *p = bt_mem + fb;
    if ((u64)fb + (u64)w * h * 2 > bt_inst.w2c_memory.size) return;
    for (int i = 0; i < w * h; i++, p += 2) {
        u32 v = (u32)p[0] << 8 | p[1], r = v >> 11 & 31, g = v >> 6 & 31, b = v >> 1 & 31;
        out[i] = 0xFF000000u | (r << 3 | r >> 2) << 16 | (g << 3 | g >> 2) << 8 | (b << 3 | b >> 2);
    }
}

_Noreturn void bt_video_main(void) {
    int headless = getenv("BT_HEADLESS") != NULL, every = getenv("BT_DUMP_EVERY") ? atoi(getenv("BT_DUMP_EVERY")) : 30;
    const char *dump = getenv("BT_DUMP");
    double quit_after = getenv("BT_EXIT_AFTER") ? atof(getenv("BT_EXIT_AFTER")) : 0;
    SDL_Window *win = NULL;
    SDL_Renderer *ren = NULL;
    SDL_Texture *tex = NULL;
    static u32 pixels[640 * 480];
    int tw = 0, th = 0;
    u32 last = 0, frames = 0;
    if (!SDL_Init(headless ? 0 : SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) bt_fatal("SDL_Init: %s", SDL_GetError());
    if (!headless) {
        win = SDL_CreateWindow("Banjo-Tooie", 960, 720, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
        ren = win ? SDL_CreateRenderer(win, NULL) : NULL;
        if (!ren) bt_fatal("SDL window: %s", SDL_GetError());
        SDL_SetRenderVSync(ren, 1);
    }
    u64 start = SDL_GetTicks();
    for (;;) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) exit(0);
            bt_input_event(&e);
        }
        double secs = (SDL_GetTicks() - start) / 1000.0 * bt_speed();  // game time
        if (quit_after > 0 && secs >= quit_after) exit(0);
        bt_input_update(secs, !headless);
        u32 fb, width, count = bt_vi_frame(&fb, &width);
        int w = width >= 16 && width <= 640 ? (int)width : 320, h = w * 3 / 4;  // BT: 304 x 228
        if (count != last) {
            last = count;
            if (fb) convert(fb, w, h, pixels); else memset(pixels, 0, sizeof pixels);
            frames++;
            if (dump && every > 0 && frames % (u32)every == 0) {
                char path[512];
                SDL_Surface *s = SDL_CreateSurfaceFrom(w, h, SDL_PIXELFORMAT_XRGB8888, pixels, w * 4);
                snprintf(path, sizeof path, "%s_%05u.bmp", dump, frames);
                if (s) { SDL_SaveBMP(s, path); SDL_DestroySurface(s); }
            }
        }
        if (headless) { usleep(4000); continue; }
        if (w != tw || h != th) {
            if (tex) SDL_DestroyTexture(tex);
            tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
            SDL_SetTextureScaleMode(tex, SDL_SCALEMODE_NEAREST);
            SDL_SetRenderLogicalPresentation(ren, 4 * h / 3 * 3, h * 3, SDL_LOGICAL_PRESENTATION_LETTERBOX);
            tw = w; th = h;
        }
        SDL_UpdateTexture(tex, NULL, pixels, w * 4);
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);
        SDL_RenderTexture(ren, tex, NULL, NULL);
        SDL_RenderPresent(ren);
    }
}
