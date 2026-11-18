// Controllers for the guest's osContGetReadData. Port 1: keyboard, the first SDL gamepad, and for
// headless runs a timed script, BT_PRESS=secs:mask_hex,... (each mask held until the next entry;
// bits 0-15 buttons, 16-23 stick x, 24-31 stick y as s8, e.g. 50000000 = stick fully up).
// Ports 2-4: further gamepads in connection order, or BT_PRESS2..BT_PRESS4 on the virtual clock. Gamepads that can
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

enum { PORTS = BT_PORTS };
static _Atomic u32 state[PORTS];  // buttons << 16 | (u8)stick_x << 8 | (u8)stick_y, read by the game thread
static _Atomic u32 presses[PORTS];
static _Atomic int captured;
static int wait_for_release[PORTS];
static _Atomic u32 camera_xy;    // port 1 right stick for the free camera: (u8)x | (u8)y << 8, up positive
static _Atomic u32 last_buttons; // port 1 buttons as the game last read them
static bool keys[SDL_SCANCODE_COUNT];
// Free camera: arrow up/down tilt the camera (camera_xy) instead of pressing their C buttons.
static bool tilt_key(SDL_Scancode k) {
    return (k == SDL_SCANCODE_UP || k == SDL_SCANCODE_DOWN) && bt_setting(BT_SET_CAMERA);
}
typedef struct { int set; SDL_GamepadButton button; SDL_Scancode key; } PadBind;
static PadBind bindings[PORTS][BT_BUTTONS];
static int deadzone[PORTS] = {20, 20, 20, 20}, sensitivity[PORTS] = {100, 100, 100, 100};
static _Atomic unsigned keyboard_ports;
static _Atomic u32 menu_warp;

const char *bt_input_button(int index) { return BUTTONS[index].name; }
int bt_input_stick_option(int port, int sens) { return sens ? sensitivity[port] : deadzone[port]; }

int bt_input_option(const char *key, const char *value) {
    if (!strncmp(key, "key.", 4)) return bt_input_bind(key + 4, value);
    if (strncmp(key, "pad", 3) || key[3] < '1' || key[3] > '4' || key[4] != '.') return 0;
    int port = key[3] - '1';
    const char *name = key + 5;
    int sens = !strcmp(name, "sensitivity");
    if (sens || !strcmp(name, "deadzone")) {
        char *end;
        long v = strtol(value, &end, 10);
        if (end == value || *end) return 0;
        int min = sens ? 25 : 0, max = sens ? 200 : 90;
        (sens ? sensitivity : deadzone)[port] = (int)(v < min ? min : v > max ? max : v);
        return 1;
    }
    for (int i = 0; i < BT_BUTTONS; i++) {
        if (SDL_strcasecmp(name, BUTTONS[i].name)) continue;
        PadBind b = {.set = 1, .button = SDL_GAMEPAD_BUTTON_INVALID};
        if (!strcmp(value, "default")) b.set = 0;
        else if (!strncmp(value, "key:", 4)) {
            b.key = SDL_GetScancodeFromName(value + 4);
            if (b.key == SDL_SCANCODE_UNKNOWN) return 0;
        } else {
            b.button = SDL_GetGamepadButtonFromString(value);
            if (b.button == SDL_GAMEPAD_BUTTON_INVALID) return 0;
        }
        bindings[port][i] = b;
        unsigned mask = 0;
        for (int j = 0; j < PORTS; j++)
            for (int n = 0; n < BT_BUTTONS; n++)
                if (bindings[j][n].key) mask |= 1u << j;
        atomic_store(&keyboard_ports, mask);
        return 1;
    }
    return 0;
}

void bt_input_binding_text(int port, int index, char *out, size_t cap) {
    char pad[100] = "";
    u16 mask = BUTTONS[index].button;
    PadBind b = bindings[port][index];
    if (b.set) snprintf(pad, sizeof pad, "%s", b.key ? SDL_GetScancodeName(b.key) : SDL_GetGamepadStringForButton(b.button));
    else {
        for (size_t n = 0; n < sizeof PAD / sizeof *PAD; n++)
            if (PAD[n].button == mask) {
                if (pad[0]) SDL_strlcat(pad, "/", sizeof pad);
                SDL_strlcat(pad, SDL_GetGamepadStringForButton(PAD[n].b), sizeof pad);
            }
        const char *axis_name = mask == Z ? "LT" : mask == R ? "RT" : mask == CU ? "RS oben" :
                                mask == CD ? "RS unten" : mask == CL ? "RS links" : mask == CR ? "RS rechts" : NULL;
        if (axis_name) { if (pad[0]) SDL_strlcat(pad, "/", sizeof pad); SDL_strlcat(pad, axis_name, sizeof pad); }
    }
    out[0] = '\0';
    if (!port) {
        for (size_t n = 0; n < nkeys; n++) if (KEYS[n].button == mask) {
            if (out[0]) SDL_strlcat(out, "/", cap);
            SDL_strlcat(out, SDL_GetScancodeName(KEYS[n].key), cap);
        }
        if (out[0] && pad[0]) SDL_strlcat(out, "  ·  ", cap);
    }
    SDL_strlcat(out, pad, cap);
}

void bt_input_capture(int opened) {
    memset(keys, 0, sizeof keys);
    for (int i = 0; i < PORTS; i++) {
        atomic_store(&presses[i], 0);
        atomic_store(&state[i], 0);
        wait_for_release[i] = 1;
    }
    atomic_store(&camera_xy, 0);
    atomic_store(&last_buttons, 0);
    atomic_store(&captured, opened);
}
void bt_input_warp(int map, int exit_id) {
    if (map > 0 && map <= 0x1ff && exit_id >= 0 && exit_id <= 255)
        atomic_store(&menu_warp, (unsigned)map << 8 | (unsigned)exit_id);
}

static SDL_Gamepad *pads[PORTS];  // written on the main thread under pad_lock
static pthread_mutex_t pad_lock = PTHREAD_MUTEX_INITIALIZER;

static void pad_open(SDL_JoystickID id) {
    for (int i = 0; i < PORTS; i++)
        if (pads[i] && SDL_GetGamepadID(pads[i]) == id) return;
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
static struct { double t; u32 mask; } *script[PORTS];
static int nscript[PORTS] = {-1, -1, -1, -1};
static const char *const script_names[PORTS] = {"BT_PRESS", "BT_PRESS2", "BT_PRESS3", "BT_PRESS4"};

void bt_input_event(const SDL_Event *e) {
    if (e->type == SDL_EVENT_WINDOW_FOCUS_LOST) {
        memset(keys, 0, sizeof keys);
        for (int i = 0; i < PORTS; i++) atomic_store(&presses[i], 0);
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
            if (key == KEYS[i].key && !tilt_key(key)) atomic_fetch_or(&presses[0], KEYS[i].button);
        for (int p = 0; p < PORTS; p++)
            for (int i = 0; i < BT_BUTTONS; i++)
                if (bindings[p][i].key == key) atomic_fetch_or(&presses[p], BUTTONS[i].button);
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
static void gate(int raw_x, int raw_y, int *x, int *y, int port) {
    float fx = raw_x / 32767.0f, fy = -raw_y / 32767.0f;  // SDL y grows downwards
    float m = sqrtf(fx * fx + fy * fy), dz = deadzone[port] / 100.0f;
    if (m <= dz) return;
    float ax = fabsf(fx) / m, ay = fabsf(fy) / m, edge = 5200 / (15 * fminf(ax, ay) + 65 * fmaxf(ax, ay));
    float r = fminf(1, (m - dz) / (1 - dz) * (sensitivity[port] / 100.0f)) * edge / m;
    *x += (int)lroundf(fx * r);
    *y += (int)lroundf(fy * r);
}

static u32 script_at(u32 port, double t) {
    u32 m = 0;
    if (nscript[port] < 0) {
        const char *s = getenv(script_names[port]);
        char *end;
        size_t capacity = 0;
        free(script[port]);
        script[port] = NULL;
        nscript[port] = 0;
        if (s && *s) {
            capacity = 1;
            for (const char *p = s; *p; p++) capacity += (*p == ',');
            if (capacity > SCRIPT_MAX) capacity = SCRIPT_MAX;
            script[port] = calloc(capacity, sizeof *script[port]);
            if (!script[port]) bt_fatal("BT_PRESS script allocation failed");
        }
        while (s && *s && (size_t)nscript[port] < capacity) {
            script[port][nscript[port]].t = strtod(s, &end);
            if (*end != ':') break;
            script[port][nscript[port]++].mask = (u32)strtoul(end + 1, &end, 16);
            s = *end == ',' ? end + 1 : end;
        }
    }
    for (int i = 0; i < nscript[port] && t >= script[port][i].t; i++) m = script[port][i].mask;
    return m;
}

static void read_pad(int port, u32 *buttons, int *x, int *y) {
    SDL_Gamepad *pad = pads[port];
    if (pad) {
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
        gate(SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTX), SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTY), x, y, port);
    }
    for (int i = 0; i < BT_BUTTONS; i++) {
        PadBind b = bindings[port][i];
        if (!b.set) continue;
        *buttons &= ~BUTTONS[i].button;
        if ((b.key && keys[b.key]) || (pad && b.button != SDL_GAMEPAD_BUTTON_INVALID && SDL_GetGamepadButton(pad, b.button)))
            *buttons |= BUTTONS[i].button;
    }
    if (wait_for_release[port]) {
        if (!*buttons && !*x && !*y) wait_for_release[port] = 0;
        *buttons = 0; *x = 0; *y = 0;
    }
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
    if (atomic_load(&captured)) return;
    for (int i = 1; i < PORTS; i++) {
        u32 b = 0;
        int px = 0, py = 0;
        if (keyboard) read_pad(i, &b, &px, &py);
        atomic_store(&state[i], pack(b, px, py));
    }
    if (!bt_vclock_on) {  // with the virtual clock pad_read applies the script
        u32 m = script_at(0, t);
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
    if (keyboard) {
        u32 pad_buttons = 0; int px = 0, py = 0;
        read_pad(0, &pad_buttons, &px, &py); buttons |= pad_buttons; x += px; y += py;
    }
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
    if (bt_vclock_on) {
        for (int i = 1; i < PORTS; i++) {
            const char *value = getenv(script_names[i]);
            if (value && *value) mask |= 1u << i;
        }
    }
    if (getenv("BT_TRACE")) return mask;
    mask |= atomic_load(&keyboard_ports);
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
    u32 requested = atomic_exchange(&menu_warp, 0);
    if (!requested && bt_control_warp) {
        requested = bt_control_warp;
        bt_control_warp = 0;
    }
    if (requested) {
        fprintf(stderr, "bt_native: warp to map %X exit %u\n", requested >> 8, requested & 0xff);
        return requested;
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
    if (port >= PORTS || atomic_load(&captured)) return 0;
    u32 s = atomic_load(&state[port]) | atomic_exchange(&presses[port], 0) << 16;
    int trace = getenv("BT_TRACE") != NULL;
    if (port && !trace && (!bt_vclock_on || !getenv(script_names[port]))) return s;
    if (trace) s = 0;
    if (bt_vclock_on) {
        u32 m = !port && bt_control_on > 0 && bt_control_mask ? bt_control_mask
                : script_at(port, bt_vclock_ticks() / 46875000.0);
        s |= (m & 0xFFFF) << 16;
        if (m >> 16) s = (s & 0xFFFF0000u) | (m >> 16 & 0xFF) << 8 | (m >> 24 & 0xFF);
    }
    if (!port) atomic_store(&last_buttons, s >> 16);
    return s;
}

// Free camera (setting "Kamera"): (u8)x | (u8)y << 8, each -80..80, for this frame. The gamepad's
// right stick is analog; without it C-Left/Right from keys or scripts turn at full speed (the game
// skips its 45 degree steps meanwhile).
u32 w2c_env_camera_stick(struct w2c_env *env) {
    (void)env;
    if (atomic_load(&captured) || !bt_setting(BT_SET_CAMERA)) return 0;
    u32 xy = atomic_load(&camera_xy), b = atomic_load(&last_buttons);
    if (!(xy & 0xFF)) xy |= (u8)((b & CR ? 80 : 0) - (b & CL ? 80 : 0));
    int inv = bt_setting(BT_SET_CAM_INVERT), x = (s8)xy, y = (s8)(xy >> 8);  // bit 0 horizontal, bit 1 vertical
    return (u32)(u8)(inv & 1 ? -x : x) | (u32)(u8)(inv & 2 ? -y : y) << 8;
}
