// Video interface: a host thread produces the 60 Hz NTSC retrace and swaps framebuffers.
#include <pthread.h>
#include <stdatomic.h>
#include <time.h>
#include "rdp.h"
#include "trace_symbols.h"
#include "crash.h"

static pthread_mutex_t vi_lock = PTHREAD_MUTEX_INITIALIZER;
static u32 vi_mq, vi_msg, vi_retrace = 1;
static u32 vi_current, vi_next, vi_mode;
static int vi_black;
static DisplayCadence display;
static double picture_start;
static double monotonic_seconds(void) {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (double)t.tv_sec + t.tv_nsec * 1e-9;
}
static u32 vi_count, vi_since, vi_interval = 2;  // retrace of the last picture change, and the one before

void w2c_env_osViSetEvent(struct w2c_env *env, u32 mq, u32 msg, u32 retrace) {
    (void)env;
    pthread_mutex_lock(&vi_lock);
    vi_mq = mq;
    vi_msg = msg;
    vi_retrace = retrace ? retrace : 1;
    pthread_mutex_unlock(&vi_lock);
}

void w2c_env_osViSetMode(struct w2c_env *env, u32 mode) {
    (void)env;
    pthread_mutex_lock(&vi_lock); vi_mode = mode; pthread_mutex_unlock(&vi_lock);
}
void w2c_env_osViBlack(struct w2c_env *env, u32 black) {
    (void)env;
    pthread_mutex_lock(&vi_lock); vi_black = (int)black; pthread_mutex_unlock(&vi_lock);
}

void w2c_env_osViSwapBuffer(struct w2c_env *env, u32 fb) {
    (void)env;
    pthread_mutex_lock(&vi_lock);
    vi_next = fb;
    u32 width = vi_mode ? gr32(vi_mode + 8) : 320;
    pthread_mutex_unlock(&vi_lock);
    rdp_register_framebuffer(fb, (int)width, bt_widescreen());
}

int bt_widescreen(void) { return gr16(TRACE_widescreen_enabled) ? (bt_setting(BT_SET_WIDESCREEN) == 2 ? 2 : 1) : 0; }

u32 w2c_env_osViGetCurrentFramebuffer(struct w2c_env *env) {
    u32 fb;
    (void)env;
    pthread_mutex_lock(&vi_lock);
    fb = vi_current;
    pthread_mutex_unlock(&vi_lock);
    return fb;
}

u32 w2c_env_osViGetNextFramebuffer(struct w2c_env *env) {
    u32 fb;
    (void)env;
    pthread_mutex_lock(&vi_lock);
    fb = vi_next;
    pthread_mutex_unlock(&vi_lock);
    return fb;
}

// A moving beam position, so busy-waits on the scanline terminate (525 NTSC lines).
u32 w2c_env_osViGetCurrentLine(struct w2c_env *env) {
    u64 t = bt_os_time();
    (void)env;
    return (u32)(t % 781250ull * 525 / 781250ull); // 46.875 MHz / 60 Hz
}

static void sleep_until(const struct timespec *t) {
    struct timespec now, d;
    clock_gettime(CLOCK_MONOTONIC, &now);
    d.tv_sec = t->tv_sec - now.tv_sec;
    d.tv_nsec = t->tv_nsec - now.tv_nsec;
    if (d.tv_nsec < 0) { d.tv_sec--; d.tv_nsec += 1000000000; }
    if (d.tv_sec >= 0) nanosleep(&d, NULL);
}

// One retrace: the next framebuffer is shown; returns the guest's VI event when it is due.
void bt_vi_retrace(u32 *mq, u32 *msg) {
    u32 count, fb, width;
    pthread_mutex_lock(&vi_lock);
    count = ++vi_count;
    if (vi_next && vi_next != vi_current) {
        vi_interval = count - vi_since;
        vi_since = count;
        if (!bt_vclock_on) picture_start = monotonic_seconds();
    }
    if (vi_next) vi_current = vi_next;
    fb = vi_black ? 0 : vi_current;
    width = vi_mode ? gr32(vi_mode + 8) : 320;
    *mq = 0; *msg = 0;
    if (vi_count % vi_retrace == 0) { *mq = vi_mq; *msg = vi_msg; }
    u32 age = count - vi_since;
    pthread_mutex_unlock(&vi_lock);
    if (bt_mem) bt_crash_map_update(gr16(TRACE_D_80132DC2));
    if (bt_vclock_on) {
        bt_trace_retrace(count, fb, width);
        bt_video_retrace(count, fb, width, age);
    }
}

_Atomic int bt_vi_display;  // the window fires the retraces at the display's vsync (video.c retrace_clock)

void bt_vi_tick(void) {
    u32 mq, msg;
    bt_vi_retrace(&mq, &msg);
    bt_os_post(mq, msg);
}

static void *vi_main(void *unused) {
    struct timespec next;
    (void)unused;
    clock_gettime(CLOCK_MONOTONIC, &next);
    for (;;) {
        next.tv_nsec += (long)(16683333 / bt_speed()); // 59.94 Hz of game time
        if (next.tv_nsec >= 1000000000) { next.tv_sec++; next.tv_nsec -= 1000000000; }
        sleep_until(&next);
        if (!atomic_load(&bt_vi_display)) bt_vi_tick();
    }
    return NULL;
}

u32 bt_vi_frame(u32 *fb, u32 *width, u32 *age) {
    u32 n;
    pthread_mutex_lock(&vi_lock);
    *fb = vi_black ? 0 : vi_current;
    *width = vi_mode ? gr32(vi_mode + 8) : 320;  // OSViMode.comRegs.width
    n = vi_count;
    *age = n - vi_since;
    pthread_mutex_unlock(&vi_lock);
    return n;
}

void bt_vi_display_swap(int paced) {
    pthread_mutex_lock(&vi_lock);
    display_swap(&display, monotonic_seconds(), paced);
    pthread_mutex_unlock(&vi_lock);
}

int bt_vi_phases(float *phases) {
    pthread_mutex_lock(&vi_lock);
    DisplayCadence cadence = display;
    double begin = picture_start;
    u32 interval = vi_interval;
    pthread_mutex_unlock(&vi_lock);
    double duration = interval / (59.94 * bt_speed());
    if (begin > 0 && cadence.period > 0 && monotonic_seconds() - cadence.last < .1) {
        // This task draws a future VI buffer. Use the next predicted game swap
        // on the current game timeline, even when the render thread started late.
        double intervals = fmax(1, ceil((cadence.last - begin) / duration));
        return display_phases(cadence, begin + intervals * duration, duration, phases);
    }
    // No paced window: retain the deterministic per-VI sequence used by dumps.
    int n = interval < 2 ? 0 : interval > 4 ? 3 : (int)interval - 1;
    for (int i = 0; i < n; i++) phases[i] = (i + 1.0f) / (n + 1);
    return n;
}

float bt_vi_phase(u32 fb) {
    pthread_mutex_lock(&vi_lock);
    double duration = vi_interval / (59.94 * bt_speed());
    double next = display.last + display.period;
    float phase = -1;
    if (fb && fb == vi_current && display.period > 0 && picture_start > 0 &&
        monotonic_seconds() - display.last < .1)
        phase = (float)fmin(1, fmax(0, (next - picture_start) / duration));
    pthread_mutex_unlock(&vi_lock);
    return phase;
}

void bt_vi_init(void) {
    pthread_t t;
    pthread_create(&t, NULL, vi_main, NULL);
    pthread_detach(t);
}
