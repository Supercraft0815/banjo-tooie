#include "plat.h"
// Persistent option table for the window menu and settings.ini in the user data directory.
// Environment variables (BT_SCALE, BT_WIDESCREEN, BT_RUMBLE, BT_FPS60, BT_INTERP, BT_FREECAM) win over the file; scripted runs
// (BT_HEADLESS) ignore the file, so their results never depend on the player's choices.
#include <SDL3/SDL.h>
#include <stdatomic.h>
#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"
#include "rdp.h"

static BtSetting S[BT_SET_COUNT] = {
    [BT_SET_SCALE] = {"scale", "BT_SCALE", "Interne Auflösung", 1, RDP_MAX_SCALE, 1, {"1x (N64)", "2x", "3x", "4x"}},
    [BT_SET_WIDESCREEN] = {"widescreen", "BT_WIDESCREEN", "Bildformat", 0, 2, 0, {"wie im Spiel", "immer 16:9", "immer 21:9"}},
    [BT_SET_FULLSCREEN] = {"fullscreen", NULL, "Vollbild", 0, 1, 0, {"aus", "an"}},
    [BT_SET_FILTER] = {"filter", NULL, "Bildfilter", 0, 1, 0, {"scharf", "weich"}},
    [BT_SET_RUMBLE] = {"rumble", "BT_RUMBLE", "Vibration", 0, 1, 1, {"aus", "an"}},
    [BT_SET_AUDIO_LATENCY] = {"audio_latency", "BT_AUDIO_LATENCY", "Audiopuffer", 0, 3, 1,
                              {"512 Samples", "1024 Samples", "2048 Samples", "4096 Samples"}},
    [BT_SET_VOLUME] = {"volume", NULL, "Lautstärke", 0, 10, 10, {NULL}},  // tenths
    [BT_SET_FPS] = {"fps60", "BT_FPS60", "Spieltakt", 0, 1, 0, {"original", "60 Hz (experimentell)"}},
    [BT_SET_INTERP] = {"interp", "BT_INTERP", "Bildinterpolation", 0, 1, 0, {"aus", "an (60 FPS)"}},
    [BT_SET_CAMERA] = {"camera", "BT_FREECAM", "Kamera", 0, 1, 0, {"original (45-Grad-Schritte)", "frei (rechter Stick)"}},
    [BT_SET_CAM_INVERT] = {"camera_invert", NULL, "Kamera invertieren", 0, 3, 0, {"aus", "horizontal", "vertikal", "beide"}},
    [BT_SET_RENDERER] = {"renderer", NULL, "Renderer (Neustart)", 0, 1, 1, {"Software", "GPU (OpenGL)"}},
    [BT_SET_SHOW_FPS] = {"show_fps", "BT_SHOW_FPS", "FPS-Anzeige", 0, 1, 0, {"aus", "an"}},
    [BT_SET_SMOOTH] = {"smooth", "BT_SMOOTH", "Textglättung (GPU, ab 2x)", 0, 1, 1, {"aus", "an"}},
    [BT_SET_GPU_WINDOW] = {"gpu_window_size", "BT_GPU_WINDOW", "GPU-Zielgröße", 0, 3, 0, {"fester Faktor", "Fensterauflösung", "Fenster bis 1440p", "Fenster bis 2160p"}},
    [BT_SET_MSAA] = {"msaa", "BT_MSAA", "Kantenglättung (GPU)", 0, 3, 0, {"aus", "2x MSAA", "4x MSAA", "8x MSAA"}},
    [BT_SET_WINDOW_RES] = {"window_size", "BT_WINDOW_SIZE", "Fenstergröße", 0, 2, 0, {"frei", "1440p", "2160p"}},
    [BT_SET_BORDERLESS] = {"borderless", "BT_BORDERLESS", "Fensterrand", 0, 1, 0, {"mit Rahmen", "rahmenlos"}},
    [BT_SET_VSYNC] = {"vsync", NULL, "VSync", 0, 1, 1, {"aus", "an"}},
    [BT_SET_RENDER_STATS] = {"render_stats", "BT_RENDER_STATS", "Render-Statistik", 0, 1, 0, {"aus", "an"}},
    // Indexes into the dialog assets of the European ROM (io.c rom_add_language)
    [BT_SET_LANGUAGE] = {"language", "BT_LANG", "Sprache (Neustart, EU-ROM)", 0, 3, 0, {"Englisch", "Französisch", "Deutsch", "Spanisch"}},
};
static _Atomic int values[BT_SET_COUNT];
static char path[1024], fullscreen_mode[80], mod_order[256];
static void save_option(const char *key, const char *value);
const char *bt_fullscreen_mode(void) { return fullscreen_mode; }
const char *bt_mod_order(void) { return mod_order; }

static int valid_mod_order(const char *order) {
    size_t total = 0;
    while (*order) {
        size_t n = 0;
        while (order[n] && order[n] != ',') {
            unsigned char c = (unsigned char)order[n];
            if (!(isalnum(c) || c == '_' || c == '-') || ++n > 63) return 0;
        }
        if (order[n] == ',' && !order[n + 1]) return 0;
        if (!n || (total += n + (order[n] == ',')) > sizeof mod_order - 1) return 0;
        order += n;
        if (*order == ',') order++;
    }
    return 1;
}

int bt_mod_order_set(const char *order) {
    if (!order || !valid_mod_order(order)) return 0;
    SDL_strlcpy(mod_order, order, sizeof mod_order);
    save_option("mod_order", mod_order);
    return 1;
}
int bt_setting(int id) { return atomic_load(&values[id]); }
const BtSetting *bt_setting_info(int id) { return &S[id]; }

static int clamp(const BtSetting *s, int v) { return v < s->min ? s->min : v > s->max ? s->max : v; }

// Main thread, first thing in main(): file values become the environment the subsystems read.
void bt_settings_load(void) {
    const char *order_env = getenv("BT_MOD_ORDER");
    if (order_env && valid_mod_order(order_env)) SDL_strlcpy(mod_order, order_env, sizeof mod_order);
    if (!getenv("BT_HEADLESS")) {
        const char *override = getenv("BT_SETTINGS");
        if (override && *override) snprintf(path, sizeof path, "%s", override);
        else {
            char *dir = SDL_GetPrefPath("", "BanjoTooie");
            if (dir) snprintf(path, sizeof path, "%ssettings.ini", dir);
            SDL_free(dir);
        }
    }
    if (path[0]) {
        FILE *f = fopen(path, "r");
        char line[512], key[64], text[256];
        while (f && fgets(line, sizeof line, f)) {
            if (line[0] == '#' || sscanf(line, "%63[^=]=%255[^\r\n]", key, text) != 2) continue;
            if (!strcmp(key, "fullscreen_mode")) {
                SDL_strlcpy(fullscreen_mode, text, sizeof fullscreen_mode);
                continue;
            }
            if (!strcmp(key, "mod_order")) {
                if (!order_env && valid_mod_order(text)) SDL_strlcpy(mod_order, text, sizeof mod_order);
                continue;
            }
            if (bt_input_option(key, text)) continue;
            for (int i = 0; i < BT_SET_COUNT; i++)
                if (!strcmp(key, S[i].key)) {
                    S[i].value = clamp(&S[i], atoi(text));
                    snprintf(text, sizeof text, "%d", S[i].value);
                    if (S[i].env) bt_setenv(S[i].env, text, 0);  // a variable already set wins
                }
        }
        if (f) fclose(f);
        // BT_RENDERER takes a name, not a number; scripted runs (no file) keep the software reference.
        bt_setenv("BT_RENDERER", S[BT_SET_RENDERER].value ? "gpu" : "soft", 0);
    }
    if (!order_env && mod_order[0]) bt_setenv("BT_MOD_ORDER", mod_order, 0);
    if (getenv("BT_RENDERER")) S[BT_SET_RENDERER].value = !strcmp(getenv("BT_RENDERER"), "gpu");
    for (int i = 0; i < BT_SET_COUNT; i++) {
        if (S[i].env && getenv(S[i].env)) S[i].value = clamp(&S[i], atoi(getenv(S[i].env)));
        atomic_store(&values[i], S[i].value);
    }
}

// Change only this key. Keep comments, keyboard aliases, other ports and unknown options.
static void save_option(const char *key, const char *value) {
    if (!path[0]) return;
    char tmp[sizeof path + 8];
    snprintf(tmp, sizeof tmp, "%s.tmp", path);
    FILE *in = fopen(path, "r");
    if (!in && errno != ENOENT) { SDL_Log("Cannot read %s", path); return; }
    FILE *out = fopen(tmp, "w");
    if (!out) { if (in) fclose(in); SDL_Log("Cannot save %s", path); return; }
    char line[1024];
    size_t n = strlen(key);
    int found = 0, newline = 1;
    while (in && fgets(line, sizeof line, in)) {
        if (newline && !strncmp(line, key, n) && line[n] == '=') {
            if (!found) fprintf(out, "%s=%s\n", key, value);
            found = 1;
            while (!strchr(line, '\n') && fgets(line, sizeof line, in)) {}
            newline = 1;
        } else {
            fputs(line, out);
            newline = strchr(line, '\n') != NULL;
        }
    }
    int ok = !in || !ferror(in);
    if (in) fclose(in);
    if (!found) fprintf(out, "%s%s=%s\n", newline ? "" : "\n", key, value);
    ok = !ferror(out) && ok;
    if (fclose(out) || !ok || !SDL_RenamePath(tmp, path)) {
        SDL_Log("Cannot replace %s: %s", path, SDL_GetError());
        SDL_RemovePath(tmp);
    }
}

void bt_fullscreen_mode_set(const char *mode) {
    SDL_strlcpy(fullscreen_mode, mode, sizeof fullscreen_mode);
    save_option("fullscreen_mode", mode);
}

void bt_settings_option(const char *key, const char *value) {
    if (bt_input_option(key, value)) save_option(key, value);
}

void bt_setting_set(int id, int v) {
    char text[32];
    S[id].value = clamp(&S[id], v);
    atomic_store(&values[id], S[id].value);
    if (id == BT_SET_SCALE) rdp_request_scale(S[id].value);
    if (id == BT_SET_VOLUME) bt_ai_volume(S[id].value / 10.0f);
    snprintf(text, sizeof text, "%d", S[id].value);
    save_option(S[id].key, text);
}
