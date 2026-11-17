// Controllers for the guest's osContGetReadData. Port 1: keyboard, the first SDL gamepad, and for
// headless runs a timed script, BT_PRESS=secs:mask_hex,... (each mask held until the next entry;
// bits 0-15 buttons, 16-23 stick x, 24-31 stick y as s8, e.g. 50000000 = stick fully up).
// Ports 2-4: further gamepads in the order they were connected (multiplayer). Gamepads that can
// rumble act as Rumble Paks (BT_RUMBLE=0 turns that off).
// Keyboard: WASD stick (Ctrl half speed), arrows C, Space A, Shift/X B, Q/Z Z,
// E R, Tab L, Return/Escape Start, IJKL D-pad; F1 shows the bindings in video.c.
#include <SDL3/SDL.h>
#include <math.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"

enum { A = 0x8000, B = 0x4000, Z = 0x2000, START = 0x1000, DU = 0x0800, DD = 0x0400, DL = 0x0200, DR = 0x0100,
       L = 0x0020, R = 0x0010, CU = 0x0008, CD = 0x0004, CL = 0x0002, CR = 0x0001 };

static struct { SDL_Scancode key; u16 button; } KEYS[48] = {
    {SDL_SCANCODE_SPACE, A}, {SDL_SCANCODE_LSHIFT, B}, {SDL_SCANCODE_Q, Z}, {SDL_SCANCODE_RETURN, START},
    {SDL_SCANCODE_TAB, L}, {SDL_SCANCODE_E, R}, {SDL_SCANCODE_UP, CU}, {SDL_SCANCODE_DOWN, CD},
    {SDL_SCANCODE_LEFT, CL}, {SDL_SCANCODE_RIGHT, CR}, {SDL_SCANCODE_I, DU}, {SDL_SCANCODE_K, DD},
    {SDL_SCANCODE_J, DL}, {SDL_SCANCODE_L, DR}, {SDL_SCANCODE_ESCAPE, START},
    {SDL_SCANCODE_KP_ENTER, START}, {SDL_SCANCODE_RSHIFT, B}, {SDL_SCANCODE_X, B}, {SDL_SCANCODE_Z, Z},
    {SDL_SCANCODE_C, CU}};
static size_t nkeys = 20;
static const struct { const char *name; u16 button; } BUTTONS[] = {
    {"A", A}, {"B", B}, {"Z", Z}, {"Start", START}, {"L", L}, {"R", R}, {"CUp", CU}, {"CDown", CD},
    {"CLeft", CL}, {"CRight", CR}, {"DUp", DU}, {"DDown", DD}, {"DLeft", DL}, {"DRight", DR}};

// settings.ini "key.A=Space,X": keyboard keys (SDL key names) for one N64 button, replacing its
// defaults. Main thread, before the game starts. Returns 0 for an unknown button.
int bt_input_bind(const char *button, const char *names) {
    u16 b = 0;
    for (size_t i = 0; i < sizeof BUTTONS / sizeof *BUTTONS; i++)
        if (!SDL_strcasecmp(button, BUTTONS[i].name)) b = BUTTONS[i].button;
    if (!b) return 0;
    size_t n = 0;
    for (size_t i = 0; i < nkeys; i++)
        if (KEYS[i].button != b) KEYS[n++] = KEYS[i];
    char copy[128], *save = NULL;
    snprintf(copy, sizeof copy, "%s", names);
    for (char *t = strtok_r(copy, ",", &save); t && n < sizeof KEYS / sizeof *KEYS; t = strtok_r(NULL, ",", &save)) {
        while (*t == ' ') t++;
        SDL_Scancode k = SDL_GetScancodeFromName(t);
        if (k == SDL_SCANCODE_UNKNOWN) fprintf(stderr, "bt_native: settings.ini: unknown key \"%s\"\n", t);
        else KEYS[n].key = k, KEYS[n++].button = b;
    }
    nkeys = n;
    return 1;
}
static const struct { SDL_GamepadButton b; u16 button; } PAD[] = {
    {SDL_GAMEPAD_BUTTON_SOUTH, A}, {SDL_GAMEPAD_BUTTON_WEST, B}, {SDL_GAMEPAD_BUTTON_EAST, B},
    {SDL_GAMEPAD_BUTTON_START, START}, {SDL_GAMEPAD_BUTTON_LEFT_SHOULDER, L},
    {SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER, R}, {SDL_GAMEPAD_BUTTON_DPAD_UP, DU},
    {SDL_GAMEPAD_BUTTON_DPAD_DOWN, DD}, {SDL_GAMEPAD_BUTTON_DPAD_LEFT, DL}, {SDL_GAMEPAD_BUTTON_DPAD_RIGHT, DR}};

enum { PORTS = 4 };
static _Atomic u32 state[PORTS];  // buttons << 16 | (u8)stick_x << 8 | (u8)stick_y, read by the game thread
static _Atomic u32 presses;
static _Atomic u32 camera_xy;    // port 1 right stick for the free camera: (u8)x | (u8)y << 8, up positive
static _Atomic u32 last_buttons; // port 1 buttons as the game last read them
static bool keys[SDL_SCANCODE_COUNT];
// Free camera: arrow up/down tilt the camera (camera_xy) instead of pressing their C buttons.
static bool tilt_key(SDL_Scancode k) {
    return (k == SDL_SCANCODE_UP || k == SDL_SCANCODE_DOWN) && bt_setting(BT_SET_CAMERA);
}
static SDL_Gamepad *pads[PORTS];  // written on the main thread under pad_lock
static pthread_mutex_t pad_lock = PTHREAD_MUTEX_INITIALIZER;

static void pad_open(SDL_JoystickID id) {
    if (SDL_GetGamepadFromID(id)) return;  // already on a port
    pthread_mutex_lock(&pad_lock);
    for (int i = 0; i < PORTS; i++)
        if (!pads[i]) { pads[i] = SDL_OpenGamepad(id); break; }
    pthread_mutex_unlock(&pad_lock);
}

// Main thread after SDL_Init, before the game probes its controllers (osContInit).
void bt_input_open_pads(void) {
    int n = 0;
    SDL_JoystickID *ids = SDL_GetGamepads(&n);
    for (int i = 0; ids && i < n; i++) pad_open(ids[i]);
    SDL_free(ids);
}
enum { SCRIPT_MAX = 1 << 16 };  // soak.py: one entry per half second for hours
static struct { double t; u32 mask; } script[SCRIPT_MAX];
static int nscript = -1;

void bt_input_event(const SDL_Event *e) {
    if (e->type == SDL_EVENT_WINDOW_FOCUS_LOST) {
        memset(keys, 0, sizeof keys);
        atomic_store(&presses, 0);
        atomic_store(&state[0], 0);
        return;
    }
    if (e->type == SDL_EVENT_KEY_DOWN || e->type == SDL_EVENT_KEY_UP) {
        SDL_Scancode key = e->key.scancode;
        if (key <= SDL_SCANCODE_UNKNOWN || key >= SDL_SCANCODE_COUNT) return;
        keys[key] = e->type == SDL_EVENT_KEY_DOWN;
        if (!keys[key] || e->key.repeat) return;
        // Keep taps between two polls until the guest has read them once.
        for (size_t i = 0; i < nkeys; i++)
            if (key == KEYS[i].key && !tilt_key(key)) atomic_fetch_or(&presses, KEYS[i].button);
        return;
    }
    if (e->type == SDL_EVENT_GAMEPAD_ADDED) pad_open(e->gdevice.which);
    if (e->type == SDL_EVENT_GAMEPAD_REMOVED) {
        pthread_mutex_lock(&pad_lock);
        for (int i = 0; i < PORTS; i++)
            if (pads[i] && e->gdevice.which == SDL_GetGamepadID(pads[i])) {
                SDL_CloseGamepad(pads[i]);
                pads[i] = NULL;
                atomic_store(&state[i], 0);
            }
        pthread_mutex_unlock(&pad_lock);
    }
}

static int axis(int v) { return abs(v) < 7000 ? 0 : v * 80 / 32767; }  // right stick as C buttons

// Left stick: round deadzone, then the N64's octagonal gate (80 on the axes, 65 on the
// diagonals), so a round modern stick reaches the same diagonals as the original controller.
static void gate(int raw_x, int raw_y, int *x, int *y) {
    float fx = raw_x / 32767.0f, fy = -raw_y / 32767.0f;  // SDL y grows downwards
    float m = sqrtf(fx * fx + fy * fy), dz = 0.2f;
    if (m < dz) return;
    float ax = fabsf(fx) / m, ay = fabsf(fy) / m, edge = 5200 / (15 * fminf(ax, ay) + 65 * fmaxf(ax, ay));
    float r = fminf(1, (m - dz) / (1 - dz)) * edge / m;
    *x += (int)lroundf(fx * r);
    *y += (int)lroundf(fy * r);
}

static u32 script_at(double t) {
    u32 m = 0;
    if (nscript < 0) {
        const char *s = getenv("BT_PRESS");
        char *end;
        nscript = 0;
        while (s && *s && nscript < SCRIPT_MAX) {
            script[nscript].t = strtod(s, &end);
            if (*end != ':') break;
            script[nscript++].mask = (u32)strtoul(end + 1, &end, 16);
            s = *end == ',' ? end + 1 : end;
        }
    }
    for (int i = 0; i < nscript && t >= script[i].t; i++) m = script[i].mask;
    return m;
}

static void read_pad(SDL_Gamepad *pad, u32 *buttons, int *x, int *y) {
    for (size_t i = 0; i < sizeof PAD / sizeof *PAD; i++)
        if (SDL_GetGamepadButton(pad, PAD[i].b)) *buttons |= PAD[i].button;
    if (SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFT_TRIGGER) > 16000) *buttons |= Z;
    if (SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER) > 16000) *buttons |= R;
    int cx = axis(SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_RIGHTX));
    int cy = axis(SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_RIGHTY));
    if (pad == pads[0] && bt_setting(BT_SET_CAMERA)) {  // free camera: the stick is the camera, its click first person
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_RIGHT_STICK)) *buttons |= CU;
    } else {
        *buttons |= (cx > 40 ? CR : 0) | (cx < -40 ? CL : 0) | (cy > 40 ? CD : 0) | (cy < -40 ? CU : 0);
    }
    gate(SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTX), SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTY), x, y);
}

static u32 pack(u32 buttons, int x, int y) {
    x = x < -80 ? -80 : x > 80 ? 80 : x;
    y = y < -80 ? -80 : y > 80 ? 80 : y;
    return buttons << 16 | (u32)(u8)x << 8 | (u8)y;
}

static double last_t;  // game time of the last update, for BT_WARP under the wall clock
void bt_input_update(double t, int keyboard) {
    last_t = t;
    u32 buttons = 0;
    int x = 0, y = 0;
    if (bt_menu_open()) keyboard = 0;  // the settings menu takes keys and gamepad 1
    for (int i = 1; i < PORTS; i++) {
        u32 b = 0;
        int px = 0, py = 0;
        if (pads[i]) read_pad(pads[i], &b, &px, &py);
        atomic_store(&state[i], pack(b, px, py));
    }
    if (!bt_vclock_on) {  // with the virtual clock pad_read applies the script
        u32 m = script_at(t);
        buttons = m & 0xFFFF;
        x = (s8)(m >> 16);
        y = (s8)(m >> 24);
    }
    if (keyboard) {
        const bool *k = keys;
        for (size_t i = 0; i < nkeys; i++)
            if (k[KEYS[i].key] && !tilt_key(KEYS[i].key)) buttons |= KEYS[i].button;
        int speed = k[SDL_SCANCODE_LCTRL] || k[SDL_SCANCODE_RCTRL] ? 40 : 80;
        x += (k[SDL_SCANCODE_D] - k[SDL_SCANCODE_A]) * speed;
        y += (k[SDL_SCANCODE_W] - k[SDL_SCANCODE_S]) * speed;
    }
    if (pads[0] && keyboard) read_pad(pads[0], &buttons, &x, &y);
    int cx = 0, cy = 0;
    if (pads[0] && keyboard) {
        cx = axis(SDL_GetGamepadAxis(pads[0], SDL_GAMEPAD_AXIS_RIGHTX));
        cy = -axis(SDL_GetGamepadAxis(pads[0], SDL_GAMEPAD_AXIS_RIGHTY));
    }
    if (keyboard && !cy) cy = (keys[SDL_SCANCODE_UP] - keys[SDL_SCANCODE_DOWN]) * 80;
    atomic_store(&camera_xy, (u32)(u8)cx | (u32)(u8)cy << 8);
    atomic_store(&state[0], pack(buttons, x, y));
}

u32 w2c_env_pad_mask(struct w2c_env *env) {
    u32 mask = 1;  // port 1 always: keyboard and BT_PRESS
    (void)env;
    pthread_mutex_lock(&pad_lock);
    for (int i = 1; i < PORTS; i++) mask |= (u32)(pads[i] != NULL) << i;
    pthread_mutex_unlock(&pad_lock);
    return mask;
}

// on: 0 stop, 1 run (the game pulses it for weaker strengths), 2 only ask whether it can rumble.
u32 w2c_env_rumble(struct w2c_env *env, u32 port, u32 on) {
    u32 ok = 0;
    (void)env;
    if (!bt_setting(BT_SET_RUMBLE) || port >= PORTS) return 0;  // BT_RUMBLE or the settings menu
    pthread_mutex_lock(&pad_lock);
    if (pads[port] && SDL_GetBooleanProperty(SDL_GetGamepadProperties(pads[port]), SDL_PROP_GAMEPAD_CAP_RUMBLE_BOOLEAN, false)) {
        ok = 1;
        // A run of pulses keeps it going; the timeout stops it if the game's stop never comes.
        if (on < 2) SDL_RumbleGamepad(pads[port], on ? 0xC000 : 0, on ? 0xC000 : 0, on ? 250 : 0);
    }
    pthread_mutex_unlock(&pad_lock);
    return ok;
}

// BT_WARP=secs:map_hex:exit,... asks the game for a map change at that game time (debug warp).
// Returns map << 8 | exit once per entry, else 0.
u32 w2c_env_warp_poll(struct w2c_env *env) {
    static const char *next;
    static double due = -1;
    (void)env;
    if (bt_control_warp) {
        u32 w = bt_control_warp;
        bt_control_warp = 0;
        fprintf(stderr, "bt_native: warp to map %X exit %u\n", w >> 8, w & 0xFF);
        return w;
    }
    if (due < 0) {
        if (!next && !(next = getenv("BT_WARP"))) return 0;
        char *end;
        due = strtod(next, &end);
        if (*end != ':') { next = ""; due = 1e300; return 0; }
        next = end + 1;
    }
    if ((bt_vclock_on ? bt_vclock_ticks() / 46875000.0 : last_t) < due) return 0;
    char *end;
    u32 map = (u32)strtoul(next, &end, 16), exit = *end == ':' ? (u32)strtoul(end + 1, &end, 10) : 0;
    next = *end == ',' ? end + 1 : "";
    due = -1;
    fprintf(stderr, "bt_native: warp to map %X exit %u\n", map, exit);
    return map << 8 | (exit & 0xFF);
}

// The game waits at least `game` retraces per frame (usually 2); 60 FPS lets it run every retrace.
u32 w2c_env_frame_interval(struct w2c_env *env, u32 game) {
    (void)env;
    return bt_setting(BT_SET_FPS) && game > 1 ? 1 : game;
}

u32 w2c_env_widescreen_forced(struct w2c_env *env) {
    (void)env;
    return (u32)bt_setting(BT_SET_WIDESCREEN);  // BT_WIDESCREEN or the settings menu
}

u32 w2c_env_pad_read(struct w2c_env *env, u32 port) {
    (void)env;
    if (port) return port < PORTS && !getenv("BT_TRACE") ? atomic_load(&state[port]) : 0;
    u32 s = atomic_load(&state[0]) | atomic_exchange(&presses, 0) << 16;
    if (getenv("BT_TRACE")) s = 0; // The trace oracle accepts scripted input only.
    if (bt_vclock_on) {  // script at virtual time, buttons combined, its stick wins when set
        u32 m = bt_control_on > 0 && bt_control_mask ? bt_control_mask : script_at(bt_vclock_ticks() / 46875000.0);  // BT_PRESS runs under BT_CONTROL too
        s |= (m & 0xFFFF) << 16;
        if (m >> 16) s = (s & 0xFFFF0000u) | (m >> 16 & 0xFF) << 8 | (m >> 24 & 0xFF);
    }
    atomic_store(&last_buttons, s >> 16);
    return s;
}

// Free camera (setting "Kamera"): (u8)x | (u8)y << 8, each -80..80, for this frame. The gamepad's
// right stick is analog; without it C-Left/Right from keys or scripts turn at full speed (the game
// skips its 45 degree steps meanwhile).
u32 w2c_env_camera_stick(struct w2c_env *env) {
    (void)env;
    if (!bt_setting(BT_SET_CAMERA)) return 0;
    u32 xy = atomic_load(&camera_xy), b = atomic_load(&last_buttons);
    if (!(xy & 0xFF)) xy |= (u8)((b & CR ? 80 : 0) - (b & CL ? 80 : 0));
    int inv = bt_setting(BT_SET_CAM_INVERT), x = (s8)xy, y = (s8)(xy >> 8);  // bit 0 horizontal, bit 1 vertical
    return (u32)(u8)(inv & 1 ? -x : x) | (u32)(u8)(inv & 2 ? -y : y) << 8;
}
