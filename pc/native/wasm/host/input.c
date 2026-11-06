// Controller 1 for the guest's osContGetReadData: keyboard, the first SDL gamepad, and for
// headless runs a timed script, BT_PRESS=secs:mask_hex,... (each mask held until the next entry;
// bits 0-15 buttons, 16-23 stick x, 24-31 stick y as s8, e.g. 50000000 = stick fully up).
// Keyboard: WASD stick, arrows C buttons, Space A, Left Shift B, Q Z, E R, Tab L, Return Start, IJKL D-pad.
#include <SDL3/SDL.h>
#include <stdatomic.h>
#include <stdlib.h>
#include "guest.h"

enum { A = 0x8000, B = 0x4000, Z = 0x2000, START = 0x1000, DU = 0x0800, DD = 0x0400, DL = 0x0200, DR = 0x0100,
       L = 0x0020, R = 0x0010, CU = 0x0008, CD = 0x0004, CL = 0x0002, CR = 0x0001 };

static const struct { SDL_Scancode key; u16 button; } KEYS[] = {
    {SDL_SCANCODE_SPACE, A}, {SDL_SCANCODE_LSHIFT, B}, {SDL_SCANCODE_Q, Z}, {SDL_SCANCODE_RETURN, START},
    {SDL_SCANCODE_TAB, L}, {SDL_SCANCODE_E, R}, {SDL_SCANCODE_UP, CU}, {SDL_SCANCODE_DOWN, CD},
    {SDL_SCANCODE_LEFT, CL}, {SDL_SCANCODE_RIGHT, CR}, {SDL_SCANCODE_I, DU}, {SDL_SCANCODE_K, DD},
    {SDL_SCANCODE_J, DL}, {SDL_SCANCODE_L, DR}};
static const struct { SDL_GamepadButton b; u16 button; } PAD[] = {
    {SDL_GAMEPAD_BUTTON_SOUTH, A}, {SDL_GAMEPAD_BUTTON_WEST, B}, {SDL_GAMEPAD_BUTTON_EAST, B},
    {SDL_GAMEPAD_BUTTON_START, START}, {SDL_GAMEPAD_BUTTON_LEFT_SHOULDER, L},
    {SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER, R}, {SDL_GAMEPAD_BUTTON_DPAD_UP, DU},
    {SDL_GAMEPAD_BUTTON_DPAD_DOWN, DD}, {SDL_GAMEPAD_BUTTON_DPAD_LEFT, DL}, {SDL_GAMEPAD_BUTTON_DPAD_RIGHT, DR}};

static _Atomic u32 state;  // buttons << 16 | (u8)stick_x << 8 | (u8)stick_y, read by the game thread
static SDL_Gamepad *pad;
static struct { double t; u32 mask; } script[2048];
static int nscript = -1;

void bt_input_event(const SDL_Event *e) {
    if (e->type == SDL_EVENT_GAMEPAD_ADDED && !pad) pad = SDL_OpenGamepad(e->gdevice.which);
    if (e->type == SDL_EVENT_GAMEPAD_REMOVED && pad && e->gdevice.which == SDL_GetGamepadID(pad)) {
        SDL_CloseGamepad(pad);
        pad = NULL;
    }
}

static int axis(int v) { return abs(v) < 7000 ? 0 : v * 80 / 32767; }  // shortcut: square deadzone, N64 range +-80

void bt_input_update(double t, int keyboard) {
    u32 buttons = 0;
    int x = 0, y = 0;
    if (nscript < 0) {
        const char *s = getenv("BT_PRESS");
        char *end;
        nscript = 0;
        while (s && *s && nscript < 2048) {
            script[nscript].t = strtod(s, &end);
            if (*end != ':') break;
            script[nscript++].mask = (u32)strtoul(end + 1, &end, 16);
            s = *end == ',' ? end + 1 : end;
        }
    }
    for (int i = 0; i < nscript && t >= script[i].t; i++) {
        buttons = script[i].mask & 0xFFFF;
        x = (s8)(script[i].mask >> 16);
        y = (s8)(script[i].mask >> 24);
    }
    if (keyboard) {
        const bool *k = SDL_GetKeyboardState(NULL);
        for (size_t i = 0; i < sizeof KEYS / sizeof *KEYS; i++)
            if (k[KEYS[i].key]) buttons |= KEYS[i].button;
        x += (k[SDL_SCANCODE_D] - k[SDL_SCANCODE_A]) * 80;
        y += (k[SDL_SCANCODE_W] - k[SDL_SCANCODE_S]) * 80;
    }
    if (pad) {
        for (size_t i = 0; i < sizeof PAD / sizeof *PAD; i++)
            if (SDL_GetGamepadButton(pad, PAD[i].b)) buttons |= PAD[i].button;
        if (SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFT_TRIGGER) > 16000) buttons |= Z;
        if (SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER) > 16000) buttons |= R;
        int cx = axis(SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_RIGHTX));
        int cy = axis(SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_RIGHTY));
        buttons |= (cx > 40 ? CR : 0) | (cx < -40 ? CL : 0) | (cy > 40 ? CD : 0) | (cy < -40 ? CU : 0);
        x += axis(SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTX));
        y -= axis(SDL_GetGamepadAxis(pad, SDL_GAMEPAD_AXIS_LEFTY));  // SDL y grows downwards
    }
    x = x < -80 ? -80 : x > 80 ? 80 : x;
    y = y < -80 ? -80 : y > 80 ? 80 : y;
    atomic_store(&state, buttons << 16 | (u32)(u8)x << 8 | (u8)y);
}

u32 w2c_env_pad_read(struct w2c_env *env) { (void)env; return atomic_load(&state); }
