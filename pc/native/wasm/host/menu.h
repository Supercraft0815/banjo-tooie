#ifndef BT_MENU_H
#define BT_MENU_H
#include <SDL3/SDL.h>
#ifdef __cplusplus
extern "C" {
#endif
enum { BT_SET_SCALE, BT_SET_WIDESCREEN, BT_SET_FULLSCREEN, BT_SET_FILTER, BT_SET_RUMBLE, BT_SET_VOLUME, BT_SET_FPS, BT_SET_INTERP, BT_SET_CAMERA, BT_SET_CAM_INVERT, BT_SET_RENDERER, BT_SET_SHOW_FPS, BT_SET_SMOOTH, BT_SET_LANGUAGE, BT_SET_AUDIO_LATENCY, BT_SET_VSYNC, BT_SET_RENDER_STATS, BT_SET_GPU_WINDOW, BT_SET_MSAA, BT_SET_WINDOW_RES, BT_SET_BORDERLESS, BT_SET_COUNT };
enum { BT_PORTS = 4, BT_BUTTONS = 14 };
typedef struct {
    const char *key, *env, *label;
    int min, max, value;
    const char *names[4];
} BtSetting;
int bt_setting(int id);
const BtSetting *bt_setting_info(int id);
void bt_setting_set(int id, int value);
void bt_settings_load(void);
const char *bt_fullscreen_mode(void);
void bt_fullscreen_mode_set(const char *mode);
const char *bt_mod_order(void);
int bt_mod_order_set(const char *order);
void bt_menu_display_changed(void);
void bt_settings_option(const char *key, const char *value);

const char *bt_input_button(int index);
void bt_input_binding_text(int port, int index, char *out, size_t capacity);
int bt_input_option(const char *key, const char *value);
int bt_input_stick_option(int port, int sensitivity);
void bt_input_capture(int opened);
void bt_input_warp(int map, int exit_id);

int bt_menu_init(SDL_Window *window, SDL_GLContext context);
int bt_menu_open(void);
int bt_menu_event(const SDL_Event *event);
void bt_menu_draw(const char *fps, unsigned repeated, unsigned skipped);
#ifdef __cplusplus
}
#endif
#endif
