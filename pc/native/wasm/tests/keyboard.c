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
enum { BT_SET_SCALE, BT_SET_WIDESCREEN, BT_SET_FULLSCREEN, BT_SET_FILTER, BT_SET_RUMBLE, BT_SET_VOLUME, BT_SET_FPS, BT_SET_CAMERA, BT_SET_CAM_INVERT, BT_SET_COUNT };
static int bt_setting(int id) { return id == BT_SET_RUMBLE; }
static int bt_menu_open(void) { return 0; }
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
    gate(4000, -4000, &sx, &sy); assert(sx == 0 && sy == 0);
    gate(32767, 0, &sx, &sy); assert(sx == 80 && sy == 0);
    sx = sy = 0; gate(23170, -23170, &sx, &sy); assert(sx == 65 && sy == 65);
    sx = sy = 0; gate(-32768, 32767, &sx, &sy); assert(sx == -65 && sy == -65);  // square-gated pad
    sx = sy = 0; gate(0, 16384, &sx, &sy); assert(sx == 0 && sy == -30);
    // Without gamepads only port 1 exists, nothing rumbles and the other ports read zero.
    assert(w2c_env_pad_mask(NULL) == 1 && w2c_env_rumble(NULL, 0, 2) == 0 && w2c_env_pad_read(NULL, 1) == 0);
    SDL_Quit();
    puts("Keyboard events, aliases, combinations, short taps, slow walk, focus loss and stick gate: PASS");
}
