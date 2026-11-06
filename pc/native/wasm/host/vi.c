// Video interface: a host thread produces the 60 Hz NTSC retrace and swaps framebuffers.
#include <pthread.h>
#include <time.h>
#include "guest.h"

static pthread_mutex_t vi_lock = PTHREAD_MUTEX_INITIALIZER;
static u32 vi_mq, vi_msg, vi_retrace = 1;
static u32 vi_current, vi_next, vi_mode;
static int vi_black;
static u32 vi_count;

void w2c_env_osViSetEvent(struct w2c_env *env, u32 mq, u32 msg, u32 retrace) {
    (void)env;
    pthread_mutex_lock(&vi_lock);
    vi_mq = mq;
    vi_msg = msg;
    vi_retrace = retrace ? retrace : 1;
    pthread_mutex_unlock(&vi_lock);
}

void w2c_env_osViSetMode(struct w2c_env *env, u32 mode) { (void)env; vi_mode = mode; }
void w2c_env_osViBlack(struct w2c_env *env, u32 black) { (void)env; vi_black = (int)black; }

void w2c_env_osViSwapBuffer(struct w2c_env *env, u32 fb) {
    (void)env;
    pthread_mutex_lock(&vi_lock);
    vi_next = fb;
    pthread_mutex_unlock(&vi_lock);
}

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

static void *vi_main(void *unused) {
    struct timespec next;
    (void)unused;
    clock_gettime(CLOCK_MONOTONIC, &next);
    for (;;) {
        u32 mq = 0, msg = 0;
        next.tv_nsec += (long)(16683333 / bt_speed()); // 59.94 Hz of game time
        if (next.tv_nsec >= 1000000000) { next.tv_sec++; next.tv_nsec -= 1000000000; }
        sleep_until(&next);
        pthread_mutex_lock(&vi_lock);
        vi_count++;
        if (vi_next) vi_current = vi_next;
        if (vi_count % vi_retrace == 0) { mq = vi_mq; msg = vi_msg; }
        pthread_mutex_unlock(&vi_lock);
        bt_os_post(mq, msg);
    }
    return NULL;
}

u32 bt_vi_frame(u32 *fb, u32 *width) {
    u32 n;
    pthread_mutex_lock(&vi_lock);
    *fb = vi_black ? 0 : vi_current;
    *width = vi_mode ? gr32(vi_mode + 8) : 320;  // OSViMode.comRegs.width
    n = vi_count;
    pthread_mutex_unlock(&vi_lock);
    return n;
}

void bt_vi_init(void) {
    pthread_t t;
    pthread_create(&t, NULL, vi_main, NULL);
    pthread_detach(t);
}
