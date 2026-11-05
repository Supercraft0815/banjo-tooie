// libultra threads, message queues, events, timers and interrupt masking on host threads.
//
// Every OSThread runs on its own pthread, but only the thread in `running` may
// execute game code, as on the single N64 CPU. Game threads switch at OS calls
// (blocking receive/send, start, yield, priority changes). Events from host threads
// (VI retrace, timers, RCP completion) wake waiting threads; a woken thread with a
// higher priority than the running one takes the CPU at once. The interrupted thread
// keeps executing until its next OS call and then waits, which approximates the
// N64's preemption without stopping a host thread mid-instruction.
// Idle-priority threads only run at boot: the CPU is simply free when nothing else is ready.
// No <string.h>/<errno.h> here: they clash with libultra declarations (bzero, errno field).
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ultra64.h>
#include "native_os.h"

#define MAX_THREADS 64
#define HOST_STACK_SIZE (8 << 20)

typedef struct {
    OSThread *t;
    void (*entry)(void *);
    void *arg;
    pthread_t pt;
    pthread_cond_t cv;
    int started;
} HostThread;

static HostThread threads[MAX_THREADS];
static pthread_mutex_t big = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t intr; // held while a game thread masks interrupts
static OSThread *running;
static OSThread *ready;
static _Thread_local OSThread *self;
static struct { OSMesgQueue *mq; OSMesg msg; } events[OS_NUM_EVENTS];
static struct timespec boot_time;

static HostThread *host_of(OSThread *t) {
    for (int i = 0; i < MAX_THREADS; i++) {
        if (threads[i].t == t) return &threads[i];
    }
    return NULL;
}

// Inserts by priority, after threads of equal priority (libultra __osEnqueueThread).
static void enqueue(OSThread **q, OSThread *t) {
    t->queue = q;
    while (*q && (*q)->priority >= t->priority) q = &(*q)->next;
    t->next = *q;
    *q = t;
}

static void unlink_thread(OSThread **q, OSThread *t) {
    for (; *q; q = &(*q)->next) {
        if (*q == t) { *q = t->next; t->next = NULL; return; }
    }
}

static OSThread *pop(OSThread **q) {
    OSThread *t = *q;
    if (t) { *q = t->next; t->next = NULL; }
    return t;
}

static void dispatch(void) {
    running = ready && ready->priority > OS_PRIORITY_IDLE ? pop(&ready) : NULL;
    if (running) {
        running->state = OS_STATE_RUNNING;
        pthread_cond_signal(&host_of(running)->cv);
    }
}

static void wait_cpu(void) {
    HostThread *h = host_of(self);
    while (running != self) pthread_cond_wait(&h->cv, &big);
}

// Every OS call from a game thread starts here: a preempted thread waits for the CPU.
static void enter(void) {
    pthread_mutex_lock(&big);
    if (self) wait_cpu();
}

static void leave(void) {
    pthread_mutex_unlock(&big);
}

// The calling game thread gives up the CPU; with q it also waits on that queue.
static void block_self(OSThread **q, u16 state) {
    if (q) enqueue(q, self);
    self->state = state;
    if (state == OS_STATE_RUNNABLE) enqueue(&ready, self);
    dispatch();
    wait_cpu();
}

// Makes t ready; a higher-priority thread takes the CPU from the running one.
static void make_ready(OSThread *t) {
    t->state = OS_STATE_RUNNABLE;
    enqueue(&ready, t);
    if (running == NULL) {
        dispatch();
    } else if (t->priority > running->priority) {
        OSThread *old = running;
        enqueue(&ready, old);
        old->state = OS_STATE_RUNNABLE;
        dispatch();
        if (self == old) wait_cpu();
    }
}

static void *thread_main(void *p) {
    HostThread *h = p;
    self = h->t;
    pthread_mutex_lock(&big);
    wait_cpu();
    pthread_mutex_unlock(&big);
    h->entry(h->arg);
    osDestroyThread(NULL);
    return NULL;
}

void osCreateThread(OSThread *t, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri pri) {
    HostThread *h;
    (void)sp;
    pthread_mutex_lock(&big);
    h = host_of(t);
    if (!h) h = host_of(NULL);
    if (!h) {
        fprintf(stderr, "bt_native: more than %d threads\n", MAX_THREADS);
        abort();
    }
    *h = (HostThread){0};
    h->t = t;
    h->entry = entry;
    h->arg = arg;
    pthread_cond_init(&h->cv, NULL);
    t->next = NULL;
    t->queue = NULL;
    t->id = id;
    t->priority = pri;
    t->state = OS_STATE_STOPPED;
    t->flags = 0;
    pthread_mutex_unlock(&big);
}

void osStartThread(OSThread *t) {
    HostThread *h;
    enter();
    h = host_of(t);
    if (!h->started) {
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setstacksize(&attr, HOST_STACK_SIZE);
        h->started = 1;
        if (pthread_create(&h->pt, &attr, thread_main, h) != 0) {
            perror("bt_native: pthread_create");
            abort();
        }
        pthread_attr_destroy(&attr);
    }
    if (t->state == OS_STATE_STOPPED || t->state == OS_STATE_WAITING) {
        if (t->queue && t->queue != &ready) unlink_thread(t->queue, t);
        if (self == NULL && running == NULL) {
            // Boot: the first started thread gets the CPU whatever its priority.
            running = t;
            t->state = OS_STATE_RUNNING;
            pthread_cond_signal(&h->cv);
        } else {
            make_ready(t);
        }
    }
    leave();
}

void osStopThread(OSThread *t) {
    enter();
    if (t == NULL || t == self) {
        block_self(NULL, OS_STATE_STOPPED);
    } else {
        if (t->state == OS_STATE_RUNNABLE) unlink_thread(&ready, t);
        else if (t->queue) unlink_thread(t->queue, t);
        t->state = OS_STATE_STOPPED;
    }
    leave();
}

void osDestroyThread(OSThread *t) {
    enter();
    if (t == NULL || t == self) {
        HostThread *h = host_of(self);
        self->state = OS_STATE_STOPPED;
        h->t = NULL;
        dispatch();
        leave();
        pthread_exit(NULL);
    }
    if (t->state == OS_STATE_RUNNABLE) unlink_thread(&ready, t);
    else if (t->queue) unlink_thread(t->queue, t);
    t->state = OS_STATE_STOPPED;
    leave(); // the host thread of t stays parked; ids are not reused
}

void osYieldThread(void) {
    enter();
    block_self(NULL, OS_STATE_RUNNABLE);
    leave();
}

OSId osGetThreadId(OSThread *t) {
    return (t ? t : self)->id;
}

OSPri osGetThreadPri(OSThread *t) {
    return (t ? t : self)->priority;
}

void osSetThreadPri(OSThread *t, OSPri pri) {
    enter();
    if (t == NULL) t = self;
    if (t->priority != pri) {
        t->priority = pri;
        if (t != self && t->state == OS_STATE_RUNNABLE) {
            unlink_thread(&ready, t);
            enqueue(&ready, t);
        }
        if (self && ready && ready->priority > self->priority) block_self(NULL, OS_STATE_RUNNABLE);
    }
    leave();
}

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 count) {
    mq->mtqueue = NULL;
    mq->fullqueue = NULL;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msg;
}

static void wake_one(OSThread **q) {
    OSThread *t = pop(q);
    if (t) make_ready(t);
}

static s32 put(OSMesgQueue *mq, OSMesg msg, s32 flag, int jam) {
    while (mq->validCount >= mq->msgCount) {
        if (flag == OS_MESG_NOBLOCK || self == NULL) return -1;
        block_self(&mq->fullqueue, OS_STATE_WAITING);
    }
    if (jam) {
        mq->first = (mq->first + mq->msgCount - 1) % mq->msgCount;
        mq->msg[mq->first] = msg;
    } else {
        mq->msg[(mq->first + mq->validCount) % mq->msgCount] = msg;
    }
    mq->validCount++;
    wake_one(&mq->mtqueue);
    return 0;
}

s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flag) {
    s32 r;
    enter();
    r = put(mq, msg, flag, 0);
    leave();
    return r;
}

s32 osJamMesg(OSMesgQueue *mq, OSMesg msg, s32 flag) {
    s32 r;
    enter();
    r = put(mq, msg, flag, 1);
    leave();
    return r;
}

s32 osRecvMesg(OSMesgQueue *mq, OSMesg *msg, s32 flag) {
    enter();
    while (mq->validCount == 0) {
        if (flag == OS_MESG_NOBLOCK) { leave(); return -1; }
        block_self(&mq->mtqueue, OS_STATE_WAITING);
    }
    if (msg) *msg = mq->msg[mq->first];
    mq->first = (mq->first + 1) % mq->msgCount;
    mq->validCount--;
    wake_one(&mq->fullqueue);
    leave();
    return 0;
}

void osSetEventMesg(OSEvent e, OSMesgQueue *mq, OSMesg msg) {
    enter();
    events[e].mq = mq;
    events[e].msg = msg;
    leave();
}

void bt_os_post(OSMesgQueue *mq, OSMesg msg) {
    if (!mq) return;
    pthread_mutex_lock(&intr);
    pthread_mutex_lock(&big);
    put(mq, msg, OS_MESG_NOBLOCK, 0); // a full queue drops the event, as on hardware
    pthread_mutex_unlock(&big);
    pthread_mutex_unlock(&intr);
}

void bt_os_event(OSEvent e) {
    OSMesgQueue *mq;
    OSMesg msg;
    pthread_mutex_lock(&big);
    mq = events[e].mq;
    msg = events[e].msg;
    pthread_mutex_unlock(&big);
    bt_os_post(mq, msg);
}

// Interrupt masking: a game thread that disables interrupts holds `intr`, so host
// events wait until it restores them. The mutex is recursive for nested sections.
static _Thread_local OSIntMask current_mask = OS_IM_ALL;

OSIntMask osSetIntMask(OSIntMask mask) {
    OSIntMask old = current_mask;
    int was_off = old == OS_IM_NONE, off = mask == OS_IM_NONE;
    if (off && !was_off) pthread_mutex_lock(&intr);
    if (!off && was_off) pthread_mutex_unlock(&intr);
    current_mask = mask;
    return old;
}

u32 __osDisableInt(void) {
    return osSetIntMask(OS_IM_NONE) != OS_IM_NONE;
}

void __osRestoreInt(u32 enabled) {
    if (enabled) osSetIntMask(OS_IM_ALL);
}

// Time runs at the N64 CPU counter rate (46.875 MHz = 3/64 per nanosecond).
static u64 elapsed_ns(void) {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return (u64)(now.tv_sec - boot_time.tv_sec) * 1000000000ull + (u64)(now.tv_nsec - boot_time.tv_nsec);
}

OSTime osGetTime(void) {
    return elapsed_ns() * 3 / 64;
}

u32 osGetCount(void) {
    return (u32)osGetTime();
}

// Timers: a host thread fires them in expiry order.
static OSTimer *timers;
static pthread_cond_t timer_cv = PTHREAD_COND_INITIALIZER;

int osSetTimer(OSTimer *t, OSTime countdown, OSTime interval, OSMesgQueue *mq, OSMesg msg) {
    pthread_mutex_lock(&big);
    t->interval = interval;
    t->value = osGetTime() + (countdown ? countdown : interval);
    t->mq = mq;
    t->msg = msg;
    t->next = timers;
    t->prev = NULL;
    if (timers) timers->prev = t;
    timers = t;
    pthread_cond_signal(&timer_cv);
    pthread_mutex_unlock(&big);
    return 0;
}

int osStopTimer(OSTimer *t) {
    pthread_mutex_lock(&big);
    for (OSTimer *i = timers; i; i = i->next) {
        if (i == t) {
            if (t->prev) t->prev->next = t->next; else timers = t->next;
            if (t->next) t->next->prev = t->prev;
            t->next = t->prev = NULL;
            pthread_mutex_unlock(&big);
            return 0;
        }
    }
    pthread_mutex_unlock(&big);
    return -1;
}

static void *timer_main(void *unused) {
    (void)unused;
    pthread_mutex_lock(&big);
    for (;;) {
        OSTimer *next = NULL;
        for (OSTimer *i = timers; i; i = i->next) {
            if (!next || i->value < next->value) next = i;
        }
        if (!next) {
            pthread_cond_wait(&timer_cv, &big);
            continue;
        }
        OSTime now = osGetTime();
        if (next->value > now) {
            u64 ns = (next->value - now) * 64 / 3;
            struct timespec until;
            clock_gettime(CLOCK_REALTIME, &until);
            until.tv_sec += ns / 1000000000ull;
            until.tv_nsec += ns % 1000000000ull;
            if (until.tv_nsec >= 1000000000) { until.tv_sec++; until.tv_nsec -= 1000000000; }
            pthread_cond_timedwait(&timer_cv, &big, &until);
            continue;
        }
        OSMesgQueue *mq = next->mq;
        OSMesg msg = next->msg;
        if (next->interval) {
            next->value += next->interval;
        } else {
            if (next->prev) next->prev->next = next->next; else timers = next->next;
            if (next->next) next->next->prev = next->prev;
            next->next = next->prev = NULL;
        }
        pthread_mutex_unlock(&big);
        bt_os_post(mq, msg);
        pthread_mutex_lock(&big);
    }
    return NULL;
}

void osInitialize(void) {
    static int done;
    pthread_mutexattr_t attr;
    pthread_t timer;
    if (done) return;
    done = 1;
    clock_gettime(CLOCK_MONOTONIC, &boot_time);
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&intr, &attr);
    pthread_mutexattr_destroy(&attr);
    pthread_create(&timer, NULL, timer_main, NULL);
    pthread_detach(timer);
    bt_vi_init();
}

u32 osGetMemSize(void) {
    return 0x800000; // Expansion Pak present
}

// The host has coherent caches.
void osWritebackDCache(void *p, s32 n) { (void)p; (void)n; }
void osWritebackDCacheAll(void) {}
void osInvalDCache(void *p, s32 n) { (void)p; (void)n; }
void osInvalICache(void *p, s32 n) { (void)p; (void)n; }
