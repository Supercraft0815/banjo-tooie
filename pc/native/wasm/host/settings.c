// Settings menu (F2, or the gamepad's Back button) and settings.ini in the user data directory.
// Environment variables (BT_SCALE, BT_WIDESCREEN, BT_RUMBLE, BT_FPS60, BT_INTERP, BT_FREECAM) win over the file; scripted runs
// (BT_HEADLESS) ignore the file, so their results never depend on the player's choices.
#include <SDL3/SDL.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"
#include "rdp.h"

typedef struct { const char *key, *env, *label; int min, max, value; const char *names[4]; } Setting;
static Setting S[BT_SET_COUNT] = {
    [BT_SET_SCALE] = {"scale", "BT_SCALE", "Interne Aufloesung", 1, RDP_MAX_SCALE, 1, {"1x (N64)", "2x", "3x", "4x"}},
    [BT_SET_WIDESCREEN] = {"widescreen", "BT_WIDESCREEN", "Bildformat", 0, 1, 0, {"wie im Spiel", "immer 16:9"}},
    [BT_SET_FULLSCREEN] = {"fullscreen", NULL, "Vollbild", 0, 1, 0, {"aus", "an"}},
    [BT_SET_FILTER] = {"filter", NULL, "Bildfilter", 0, 1, 0, {"scharf", "weich"}},
    [BT_SET_RUMBLE] = {"rumble", "BT_RUMBLE", "Vibration", 0, 1, 1, {"aus", "an"}},
    [BT_SET_VOLUME] = {"volume", NULL, "Lautstaerke", 0, 10, 10, {NULL}},  // tenths
    [BT_SET_FPS] = {"fps60", "BT_FPS60", "Spieltakt", 0, 1, 0, {"original", "60 Hz (experimentell)"}},
    [BT_SET_INTERP] = {"interp", "BT_INTERP", "Bildinterpolation", 0, 1, 0, {"aus", "an (60 FPS)"}},
    [BT_SET_CAMERA] = {"camera", "BT_FREECAM", "Kamera", 0, 1, 0, {"original (45-Grad-Schritte)", "frei (rechter Stick)"}},
    [BT_SET_CAM_INVERT] = {"camera_invert", NULL, "Kamera invertieren", 0, 3, 0, {"aus", "horizontal", "vertikal", "beide"}},
    [BT_SET_RENDERER] = {"renderer", NULL, "Renderer (Neustart)", 0, 1, 1, {"Software", "GPU (OpenGL)"}},
    [BT_SET_SHOW_FPS] = {"show_fps", "BT_SHOW_FPS", "FPS-Anzeige", 0, 1, 0, {"aus", "an"}},
    [BT_SET_SMOOTH] = {"smooth", "BT_SMOOTH", "Textglaettung (GPU, ab 2x)", 0, 1, 1, {"aus", "an"}},
};
static _Atomic int values[BT_SET_COUNT];
static int menu_open, cursor;
static char path[1024];
static char binds[16][160];  // key.X=... lines, written back unchanged
static int nbinds;

int bt_setting(int id) { return atomic_load(&values[id]); }
int bt_menu_open(void) { return menu_open; }

static int clamp(const Setting *s, int v) { return v < s->min ? s->min : v > s->max ? s->max : v; }

// Main thread, first thing in main(): file values become the environment the subsystems read.
void bt_settings_load(void) {
    char *dir = getenv("BT_HEADLESS") ? NULL : SDL_GetPrefPath("", "BanjoTooie");
    if (dir) {
        snprintf(path, sizeof path, "%ssettings.ini", dir);
        SDL_free(dir);
        FILE *f = fopen(path, "r");
        char line[200], key[64], text[128];
        while (f && fgets(line, sizeof line, f)) {
            if (line[0] == '#' || sscanf(line, "%63[^=]=%127[^\r\n]", key, text) != 2) continue;
            if (!strncmp(key, "key.", 4)) {
                if (bt_input_bind(key + 4, text) && nbinds < 16) snprintf(binds[nbinds++], sizeof *binds, "%s=%s", key, text);
                continue;
            }
            for (int i = 0; i < BT_SET_COUNT; i++)
                if (!strcmp(key, S[i].key)) {
                    S[i].value = clamp(&S[i], atoi(text));
                    snprintf(text, sizeof text, "%d", S[i].value);
                    if (S[i].env) setenv(S[i].env, text, 0);  // a variable already set wins
                }
        }
        if (f) fclose(f);
        // BT_RENDERER takes a name, not a number; scripted runs (no file) keep the software reference.
        setenv("BT_RENDERER", S[BT_SET_RENDERER].value ? "gpu" : "soft", 0);
    }
    if (getenv("BT_RENDERER")) S[BT_SET_RENDERER].value = !strcmp(getenv("BT_RENDERER"), "gpu");
    for (int i = 0; i < BT_SET_COUNT; i++) {
        if (S[i].env && getenv(S[i].env)) S[i].value = clamp(&S[i], atoi(getenv(S[i].env)));
        atomic_store(&values[i], S[i].value);
    }
}

static void save(void) {
    FILE *f = path[0] ? fopen(path, "w") : NULL;
    if (!f) return;
    for (int i = 0; i < BT_SET_COUNT; i++) fprintf(f, "%s=%d\n", S[i].key, S[i].value);
    fputs("# Tastatur: key.KNOPF=Taste,Taste (SDL-Tastennamen, z. B. key.A=Space,X). Knoepfe: A B Z Start\n"
          "# L R CUp CDown CLeft CRight DUp DDown DLeft DRight. Bewegen bleibt WASD (Strg: langsam).\n", f);
    for (int i = 0; i < nbinds; i++) fprintf(f, "%s\n", binds[i]);
    fclose(f);
}

void bt_setting_set(int id, int v) {
    S[id].value = clamp(&S[id], v);
    atomic_store(&values[id], S[id].value);
    if (id == BT_SET_SCALE) rdp_request_scale(S[id].value);
    if (id == BT_SET_VOLUME) bt_ai_volume(S[id].value / 10.0f);
    save();
}

// Returns 1 when the event belongs to the menu (the game does not see it).
int bt_settings_event(const SDL_Event *e) {
    int key = e->type == SDL_EVENT_KEY_DOWN ? (int)e->key.key : 0, button = -1;
    if (e->type == SDL_EVENT_GAMEPAD_BUTTON_DOWN) button = e->gbutton.button;
    if (key == SDLK_F2 || button == SDL_GAMEPAD_BUTTON_BACK) { menu_open = !menu_open; return 1; }
    if (!menu_open) return 0;
    int up = key == SDLK_UP || button == SDL_GAMEPAD_BUTTON_DPAD_UP;
    int down = key == SDLK_DOWN || button == SDL_GAMEPAD_BUTTON_DPAD_DOWN;
    int left = key == SDLK_LEFT || button == SDL_GAMEPAD_BUTTON_DPAD_LEFT;
    int right = key == SDLK_RIGHT || key == SDLK_RETURN || key == SDLK_SPACE || button == SDL_GAMEPAD_BUTTON_DPAD_RIGHT ||
                button == SDL_GAMEPAD_BUTTON_SOUTH;
    if (key == SDLK_ESCAPE || button == SDL_GAMEPAD_BUTTON_EAST) menu_open = 0;
    cursor = (cursor + up * (BT_SET_COUNT - 1) + down) % BT_SET_COUNT;
    if (left || right) {
        Setting *s = &S[cursor];
        int span = s->max - s->min + 1, v = s->value - s->min + (right ? 1 : span - 1);
        bt_setting_set(cursor, s->min + v % span);
    }
    return e->type == SDL_EVENT_KEY_DOWN || e->type == SDL_EVENT_KEY_UP ||
           e->type == SDL_EVENT_GAMEPAD_BUTTON_DOWN || e->type == SDL_EVENT_GAMEPAD_BUTTON_UP;
}

// Drawn over the game in the renderer's 960- or 1280-wide logical space.
void bt_settings_draw(SDL_Renderer *ren) {
    if (!menu_open) return;
    SDL_FRect box = {8, 8, 464, 40 + BT_SET_COUNT * 14};
    SDL_SetRenderScale(ren, 2, 2);
    SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 220);
    SDL_RenderFillRect(ren, &box);
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    SDL_RenderDebugText(ren, 16, 16, "EINSTELLUNGEN           F2/Esc: schliessen");
    for (int i = 0; i < BT_SET_COUNT; i++) {
        char line[96], number[16];
        snprintf(number, sizeof number, "%d %%", S[i].value * 10);
        snprintf(line, sizeof line, "%c %-20s < %s >", i == cursor ? '>' : ' ', S[i].label,
                 S[i].names[0] ? S[i].names[S[i].value - S[i].min] : number);
        if (i == cursor) SDL_SetRenderDrawColor(ren, 255, 220, 64, 255);
        SDL_RenderDebugText(ren, 16, 34 + (float)i * 14, line);
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    }
    SDL_SetRenderScale(ren, 1, 1);
}
