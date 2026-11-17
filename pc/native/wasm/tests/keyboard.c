#define BT_HOST_GUEST_H
#include <stdint.h>
#include <assert.h>
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef uint32_t u32;
struct w2c_env;
typedef uint64_t u64;
static int bt_vclock_on;
#include "../host/menu.h"
int bt_setting(int id) { return id == BT_SET_RUMBLE; }
static u64 bt_vclock_ticks(void) { return 0; }
static int bt_control_on;
static u32 bt_control_mask, bt_control_warp;
#include "../host/input.c"

static void key(SDL_Scancode code, bool down) {
    SDL_Event e = {.type = down ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP};
    e.key.scancode = code;
    assert(SDL_PushEvent(&e));
}
static void poll_keys(void) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) bt_input_event(&e);
    bt_input_update(0, 1);
}
int main(void) {
    unsetenv("BT_PRESS");
    assert(SDL_Init(SDL_INIT_EVENTS | SDL_INIT_GAMEPAD));
    key(SDL_SCANCODE_W, true); key(SDL_SCANCODE_D, true); key(SDL_SCANCODE_SPACE, true);
    poll_keys();
    u32 v = w2c_env_pad_read(NULL, 0);
    assert(v >> 16 == A && (s8)(v >> 8) == 80 && (s8)v == 80);
    assert(w2c_env_pad_read(NULL, 0) == v); // held buttons persist
    key(SDL_SCANCODE_LCTRL,true); poll_keys();
    v = w2c_env_pad_read(NULL, 0);
    assert((s8)(v >> 8) == 40 && (s8)v == 40);
    key(SDL_SCANCODE_W,false); key(SDL_SCANCODE_D,false);
    key(SDL_SCANCODE_SPACE,false); key(SDL_SCANCODE_LCTRL,false);
    // A complete tap between video frames must reach exactly one controller poll.
    key(SDL_SCANCODE_ESCAPE,true); key(SDL_SCANCODE_ESCAPE,false); poll_keys();
    assert(w2c_env_pad_read(NULL, 0) >> 16 == START);
    assert(w2c_env_pad_read(NULL, 0) == 0);
    key(SDL_SCANCODE_Q,true); key(SDL_SCANCODE_SPACE,true); poll_keys();
    assert(w2c_env_pad_read(NULL, 0) >> 16 == (Z | A));
    SDL_Event lost = {.type = SDL_EVENT_WINDOW_FOCUS_LOST};
    assert(SDL_PushEvent(&lost)); poll_keys();
    assert(w2c_env_pad_read(NULL, 0) == 0);
    for (size_t i=0; i<nkeys; i++) {
        key(KEYS[i].key,true); poll_keys();
        assert(w2c_env_pad_read(NULL, 0) >> 16 == KEYS[i].button);
        key(KEYS[i].key,false); poll_keys();
        assert(w2c_env_pad_read(NULL, 0) == 0);
    }
    // settings.ini key.A=F,G replaces Space; unknown buttons are refused.
    assert(bt_input_bind("a", "F, G") && !bt_input_bind("Turbo", "H"));
    key(SDL_SCANCODE_SPACE,true); key(SDL_SCANCODE_G,true); poll_keys();
    assert(w2c_env_pad_read(NULL, 0) >> 16 == A);
    key(SDL_SCANCODE_G,false); poll_keys();
    assert(w2c_env_pad_read(NULL, 0) == 0);
    key(SDL_SCANCODE_SPACE,false); poll_keys();
    // A trace must ignore live buttons and stick while still applying BT_PRESS.
    setenv("BT_TRACE", "fixture.jsonl", 1);
    setenv("BT_PRESS", "0:50008000", 1);
    nscript = -1; bt_vclock_on = 1;
    key(SDL_SCANCODE_Q,true); key(SDL_SCANCODE_D,true); poll_keys();
    v = w2c_env_pad_read(NULL, 0);
    assert(v >> 16 == A && (s8)(v >> 8) == 0 && (s8)v == 80);
    unsetenv("BT_TRACE"); unsetenv("BT_PRESS");
    // Stick: round deadzone, axes reach 80, a round stick's full diagonal reaches the N64's 65/65.
    int sx = 0, sy = 0;
    gate(4000, -4000, &sx, &sy, 0); assert(sx == 0 && sy == 0);
    gate(32767, 0, &sx, &sy, 0); assert(sx == 80 && sy == 0);
    sx = sy = 0; gate(23170, -23170, &sx, &sy, 0); assert(sx == 65 && sy == 65);
    sx = sy = 0; gate(-32768, 32767, &sx, &sy, 0); assert(sx == -65 && sy == -65);  // square-gated pad
    sx = sy = 0; gate(0, 16384, &sx, &sy, 0); assert(sx == 0 && sy == -30);
    // Without gamepads only port 1 exists, nothing rumbles and the other ports read zero.
    assert(w2c_env_pad_mask(NULL) == 1 && w2c_env_rumble(NULL, 0, 2) == 0 && w2c_env_pad_read(NULL, 1) == 0);
    // A keyboard binding on port 2 also exposes that N64 port without a physical pad.
    bt_vclock_on = 0; nscript = -1;
    assert(SDL_PushEvent(&lost)); poll_keys();
    assert(bt_input_option("pad2.A", "key:H"));
    assert(!bt_input_option("pad2.A", "not-a-real-button"));
    assert(w2c_env_pad_mask(NULL) == 3);
    key(SDL_SCANCODE_H, true); key(SDL_SCANCODE_H, false); poll_keys();
    assert(w2c_env_pad_read(NULL, 1) >> 16 == A && w2c_env_pad_read(NULL, 1) == 0);
    assert(bt_input_option("pad2.A", "y") && w2c_env_pad_mask(NULL) == 1);
    assert(bt_input_option("pad2.A", "default") && w2c_env_pad_mask(NULL) == 1);
    assert(bt_input_option("pad2.deadzone", "40") && bt_input_option("pad2.sensitivity", "150"));
    sx = sy = 0; gate(10000, 0, &sx, &sy, 1); assert(sx == 0);
    gate(24575, 0, &sx, &sy, 1); assert(sx == 70);
    assert(bt_input_option("pad2.deadzone", "0"));
    sx = sy = 0; gate(0, 0, &sx, &sy, 1); assert(sx == 0 && sy == 0);
    assert(!bt_input_option("pad0.A", "south") && !bt_input_option("pad5.A", "south"));
    // A tap already held for the guest must not leak across opening or closing the menu.
    key(SDL_SCANCODE_G, true); poll_keys(); bt_input_capture(1);
    for (unsigned port = 0; port < 4; port++) assert(w2c_env_pad_read(NULL, port) == 0);
    bt_input_capture(0); poll_keys();
    assert(w2c_env_pad_read(NULL, 0) == 0);
    bt_input_warp(0xb8, 1);
    assert(w2c_env_warp_poll(NULL) == 0xb801 && w2c_env_warp_poll(NULL) == 0);
    SDL_Quit();
    puts("Keyboard events, aliases, combinations, short taps, slow walk, focus loss and stick gate: PASS");
}
