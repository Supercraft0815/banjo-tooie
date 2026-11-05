// Video interface: a host thread produces the 60 Hz NTSC retrace and swaps framebuffers.
#include <pthread.h>
#include <time.h>
#include <ultra64.h>
#include "native_os.h"

static pthread_mutex_t vi_lock = PTHREAD_MUTEX_INITIALIZER;
static OSMesgQueue *vi_mq;
static OSMesg vi_msg;
static u32 vi_retrace = 1;
static void *vi_current, *vi_next;
static OSViMode *vi_mode;
static int vi_black;
static volatile u32 vi_count;

void osCreateViManager(OSPri pri) { (void)pri; }

void osViSetEvent(OSMesgQueue *mq, OSMesg msg, u32 retrace) {
    pthread_mutex_lock(&vi_lock);
    vi_mq = mq;
    vi_msg = msg;
    vi_retrace = retrace ? retrace : 1;
    pthread_mutex_unlock(&vi_lock);
}

void osViSetMode(OSViMode *mode) { vi_mode = mode; }
void osViBlack(u8 black) { vi_black = black; }
void osViSetSpecialFeatures(u32 f) { (void)f; }
void osViSetXScale(f32 s) { (void)s; }
void osViSetYScale(f32 s) { (void)s; }

void osViSwapBuffer(void *fb) {
    pthread_mutex_lock(&vi_lock);
    vi_next = fb;
    pthread_mutex_unlock(&vi_lock);
}

void *osViGetCurrentFramebuffer(void) {
    void *fb;
    pthread_mutex_lock(&vi_lock);
    fb = vi_current;
    pthread_mutex_unlock(&vi_lock);
    return fb;
}

void *osViGetNextFramebuffer(void) {
    void *fb;
    pthread_mutex_lock(&vi_lock);
    fb = vi_next;
    pthread_mutex_unlock(&vi_lock);
    return fb;
}

// A moving beam position, so busy-waits on the scanline terminate (525 NTSC lines).
u32 osViGetCurrentLine(void) {
    return (u32)(osGetTime() % 781250ull * 525 / 781250ull); // 46.875 MHz / 60 Hz
}

int bt_vi_is_black(void) { return vi_black; }

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
        OSMesgQueue *mq = NULL;
        OSMesg msg = 0;
        next.tv_nsec += 16683333; // 59.94 Hz
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

void bt_vi_init(void) {
    pthread_t t;
    pthread_create(&t, NULL, vi_main, NULL);
    pthread_detach(t);
}
