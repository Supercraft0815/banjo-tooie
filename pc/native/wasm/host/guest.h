// Host view of the guest (wasm2c instance of the game).
#ifndef BT_HOST_GUEST_H
#define BT_HOST_GUEST_H
#include <stdint.h>
#include "game.h"
#include "image_memory.h"

extern w2c_bt bt_inst;
extern u8 *bt_mem;

// Guest address -> host pointer. Guest pointers are 32-bit offsets into linear memory.
static inline void *G(u32 addr) { bt_image_scalar(addr, 1); return bt_mem + addr; }
static inline void *G_range(u32 addr, u64 bytes) {
    (void)bytes;
    bt_image_range(addr, bytes);
    return bt_mem + addr;
}
// Guest memory is big-endian like N64 RDRAM (the bt-bigendian pass): values wider than a byte
// go through these.
static inline u16 gr16(u32 a) { bt_image_scalar(a, 2); const u8 *p = bt_mem + a; return (u16)(p[0] << 8 | p[1]); }
static inline u32 gr32(u32 a) { bt_image_scalar(a, 4); u32 v; __builtin_memcpy(&v, bt_mem + a, 4); return __builtin_bswap32(v); }
static inline u64 gr64(u32 a) { return (u64)gr32(a) << 32 | gr32(a + 4); }
static inline void gw16(u32 a, u32 v) { bt_image_scalar(a, 2); u8 *p = bt_mem + a; p[0] = (u8)(v >> 8); p[1] = (u8)v; }
static inline void gw32(u32 a, u32 v) { bt_image_scalar(a, 4); v = __builtin_bswap32(v); __builtin_memcpy(bt_mem + a, &v, 4); }
static inline void gw64(u32 a, u64 v) { gw32(a, (u32)(v >> 32)); gw32(a + 4, (u32)v); }

// Calls an OSThread entry with its initial guest registers.
void bt_call_guest(u32 fn, u32 arg, u32 thread);
// The guest stack pointer of the instance; the running game thread owns it.
#define BT_SP (*w2c_bt_0x5F_stack_pointer(&bt_inst))


_Noreturn void bt_fatal(const char *fmt, ...);
void bt_trap(wasm_rt_trap_t code);
void bt_backtrace(void);  // host call stack to stderr
void bt_os_post(u32 mq, u32 msg);  // from host threads: NOBLOCK send, dropped when full
void bt_os_event(u32 event);
double bt_speed(void);       // BT_SPEED: game clock rate relative to real time (default 1)
u64 bt_os_time(void);        // CPU counter ticks since boot; a preemption safe point
void bt_vi_init(void);
extern int bt_vclock_on;               // BT_VCLOCK: virtual clock (os.c)
u64 bt_vclock_ticks(void);             // virtual CPU counter ticks; call from the running guest thread
void bt_vi_retrace(u32 *mq, u32 *msg); // one retrace; the guest's VI event when due (vi.c)
void bt_vi_tick(void);                 // one retrace and its event, from a host thread (vi.c)
extern _Atomic int bt_vi_display;      // 1: video.c calls bt_vi_tick at the display's vsync, vi.c's timer rests
void bt_video_retrace(u32 count, u32 fb, u32 width, u32 age); // vclock: dumps and BT_EXIT_AFTER per retrace (video.c)
// retrace count; framebuffer being shown (0 = black), its width and retraces since it became current
int bt_video_save(const char *path, u32 fb, u32 width, u32 age, int hires); // BMP of a retrace's picture (video.c)
void bt_control_retrace(u32 count, u32 fb, u32 width, u32 age); // BT_CONTROL: stops for commands (control.c)
extern int bt_control_on;              // BT_CONTROL is set: input and warps come from it (control.c)
extern u32 bt_control_mask, bt_control_warp;
u32 bt_vi_frame(u32 *fb, u32 *width, u32 *age);
void bt_vi_display_swap(int paced);     // observe the time a window swap actually returned
int bt_vi_phases(float *phases);        // display instants inside the next game picture (vi.c)
float bt_vi_phase(u32 fb);              // desired phase at the next swap, negative for VI-based presentation
int bt_widescreen(void);                // the game's anamorphic 16:9 option is on (vi.c)
_Noreturn void bt_video_main(void);    // main-thread window loop (video.c)
void gsp_run(u32 dl);                  // runs a graphics task's display list (gsp.c)
void bt_audio_task(u32 task);          // execute an n_audio command list (mixer.c)
void bt_ai_open(void);                 // opens the audio device (ai.c; main thread, after SDL_Init)
void bt_ai_volume(float gain);         // ai.c: 0..1, the device only (BT_PCM stays as synthesized)
union SDL_Event;
void bt_input_event(const union SDL_Event *e);  // input.c: keys, focus and gamepad hotplug
void bt_input_update(double secs, int keyboard);  // input.c: samples the controllers
void bt_input_open_pads(void);  // input.c: main thread, after SDL_Init, before the game starts
void bt_video_init(void);       // video.c: SDL_Init on the main thread, before the game starts
void bt_video_window(void);     // video.c: the window and its OpenGL context; main thread, before the game starts
#include "menu.h"
void bt_rom_open(const char *path);
const char *bt_rom_title(void);
const char *bt_rom_find(void);
int bt_input_bind(const char *button, const char *names);  // input.c: settings.ini key.X=...  // io.c: no ROM argument (may show a file dialog)
void bt_trace_init(const char *rom);
const char *bt_host_path(const char *path);
void bt_trace_retrace(u32 retrace, u32 fb, u32 width);

#endif
