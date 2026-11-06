// libultra threads, message queues, events, timers and interrupt masking for the guest.
//
// Every OSThread runs on its own pthread, but only the thread in `running`
// executes guest code, as on the single N64 CPU; it owns the guest stack pointer.
// Game threads switch at OS calls. Host threads (VI retrace, timers) post events
// into guest queues; a woken thread with a higher priority than the running one
// takes the CPU at the running thread's next OS call (osGetTime and the VI line
// query count as OS calls). With no thread running it starts at once.
// Idle-priority threads run only at boot: the CPU is simply free when nothing else is ready.
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "guest.h"

#define MAX_THREADS 64
#define HOST_STACK_SIZE (16 << 20) // wasm2c code runs on the host stack
#define READY 1u                   // queue id of the ready queue (no guest address is odd)
#define OS_PRIORITY_IDLE 0
#define OS_STATE_STOPPED 1
#define OS_STATE_RUNNABLE 2
#define OS_STATE_RUNNING 4
#define OS_STATE_WAITING 8
#define OS_MESG_NOBLOCK 0
#define OS_NUM_EVENTS 15
#define OS_IM_NONE 1u
#define OS_IM_ALL 0x003FFF01u

typedef struct {
    u32 t;        // guest OSThread
    u32 entry, arg, sp;
    pthread_t pt;
    pthread_cond_t cv;
    int started;
} HostThread;

static HostThread threads[MAX_THREADS];
static pthread_mutex_t big = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t intr; // held while a game thread masks interrupts
static u32 running, ready;
static int booted, preempt;
static _Thread_local HostThread *self;
static struct { u32 mq, msg; } events[OS_NUM_EVENTS];
static struct timespec boot_time;

static GThread *T(u32 t) { return G(t); }
static u32 *slot(u32 q) { return q == READY ? &ready : (u32 *)G(q); }

static HostThread *host_of(u32 t) {
    for (int i = 0; i < MAX_THREADS; i++) {
        if (threads[i].t == t) return &threads[i];
    }
    return NULL;
}

// Inserts by priority, after threads of equal priority (libultra __osEnqueueThread).
static void enqueue(u32 q, u32 t) {
    u32 *p = slot(q);
    T(t)->queue = q;
    while (*p && T(*p)->priority >= T(t)->priority) p = &T(*p)->next;
    T(t)->next = *p;
    *p = t;
}

static void unlink_thread(u32 q, u32 t) {
    for (u32 *p = slot(q); *p; p = &T(*p)->next) {
        if (*p == t) { *p = T(t)->next; T(t)->next = 0; return; }
    }
}

static u32 pop(u32 q) {
    u32 *p = slot(q), t = *p;
    if (t) { *p = T(t)->next; T(t)->next = 0; }
    return t;
}

static void dispatch(void) {
    running = ready && T(ready)->priority > OS_PRIORITY_IDLE ? pop(READY) : 0;
    preempt = 0;
    if (running) {
        T(running)->state = OS_STATE_RUNNING;
        pthread_cond_signal(&host_of(running)->cv);
    }
}

// Waits until this thread owns the CPU again, then takes back its guest stack pointer.
static void wait_cpu(void) {
    while (running != self->t) pthread_cond_wait(&self->cv, &big);
    BT_SP = self->sp;
}

// The calling game thread gives up the CPU; with q it also waits on that queue.
static void block_self(u32 q, u16 state) {
    if (q) enqueue(q, self->t);
    T(self->t)->state = state;
    if (state == OS_STATE_RUNNABLE) enqueue(READY, self->t);
    dispatch();
    wait_cpu();
}

// Every OS call from the guest starts here. The caller owns the CPU; a pending
// preemption hands it to the higher-priority thread first.
static void enter(void) {
    pthread_mutex_lock(&big);
    if (!self) return; // boot context
    self->sp = BT_SP;
    if (preempt && ready && T(ready)->priority > T(self->t)->priority) block_self(0, OS_STATE_RUNNABLE);
}

static void leave(void) {
    pthread_mutex_unlock(&big);
}

// Makes t ready. From a game thread a higher priority takes the CPU at once; from a
// host thread it waits for the running thread's next OS call.
static void make_ready(u32 t) {
    T(t)->state = OS_STATE_RUNNABLE;
    enqueue(READY, t);
    if (!running) {
        dispatch();
    } else if (T(t)->priority > T(running)->priority) {
        if (self && self->t == running) block_self(0, OS_STATE_RUNNABLE);
        else preempt = 1;
    }
}

static void *thread_main(void *p) {
    HostThread *h = p;
    self = h;
    wasm_rt_init_thread();
    pthread_mutex_lock(&big);
    wait_cpu();
    pthread_mutex_unlock(&big);
    bt_call_guest(h->entry, h->arg);
    w2c_env_osDestroyThread(NULL, 0);
    return NULL;
}

void w2c_env_osCreateThread(struct w2c_env *env, u32 t, u32 id, u32 entry, u32 arg, u32 sp, u32 pri) {
    HostThread *h;
    (void)env;
    pthread_mutex_lock(&big);
    h = host_of(t);
    if (!h) h = host_of(0);
    if (!h) bt_fatal("more than %d threads", MAX_THREADS);
    *h = (HostThread){0};
    h->t = t;
    h->entry = entry;
    h->arg = arg;
    h->sp = sp & ~15u;
    pthread_cond_init(&h->cv, NULL);
    T(t)->next = 0;
    T(t)->queue = 0;
    T(t)->id = (s32)id;
    T(t)->priority = (s32)pri;
    T(t)->state = OS_STATE_STOPPED;
    T(t)->flags = 0;
    pthread_mutex_unlock(&big);
}

void w2c_env_osStartThread(struct w2c_env *env, u32 t) {
    HostThread *h;
    (void)env;
    enter();
    h = host_of(t);
    if (!h->started) {
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setstacksize(&attr, HOST_STACK_SIZE);
        h->started = 1;
        if (pthread_create(&h->pt, &attr, thread_main, h) != 0) bt_fatal("pthread_create failed");
        pthread_attr_destroy(&attr);
    }
    if (T(t)->state == OS_STATE_STOPPED || T(t)->state == OS_STATE_WAITING) {
        if (T(t)->queue && T(t)->queue != READY) unlink_thread(T(t)->queue, t);
        if (!self && !booted) {
            // Boot: the first started thread gets the CPU whatever its priority, and the
            // boot context ends here, as on the N64 (it must not touch the guest stack again).
            booted = 1;
            running = t;
            T(t)->state = OS_STATE_RUNNING;
            pthread_cond_signal(&h->cv);
            leave();
            for (;;) pause();
        }
        make_ready(t);
    }
    leave();
}

void w2c_env_osStopThread(struct w2c_env *env, u32 t) {
    (void)env;
    enter();
    if (t == 0 || (self && t == self->t)) {
        block_self(0, OS_STATE_STOPPED);
    } else {
        if (T(t)->state == OS_STATE_RUNNABLE) unlink_thread(READY, t);
        else if (T(t)->queue) unlink_thread(T(t)->queue, t);
        T(t)->state = OS_STATE_STOPPED;
    }
    leave();
}

void w2c_env_osDestroyThread(struct w2c_env *env, u32 t) {
    (void)env;
    enter();
    if (t == 0 || t == self->t) {
        T(self->t)->state = OS_STATE_STOPPED;
        self->t = 0;
        dispatch();
        leave();
        pthread_exit(NULL);
    }
    if (T(t)->state == OS_STATE_RUNNABLE) unlink_thread(READY, t);
    else if (T(t)->queue) unlink_thread(T(t)->queue, t);
    T(t)->state = OS_STATE_STOPPED;
    leave(); // the host thread of t stays parked; ids are not reused
}

void w2c_env_osYieldThread(struct w2c_env *env) {
    (void)env;
    enter();
    block_self(0, OS_STATE_RUNNABLE);
    leave();
}

u32 w2c_env_osGetThreadId(struct w2c_env *env, u32 t) {
    (void)env;
    return (u32)T(t ? t : self->t)->id;
}

u32 w2c_env_osGetThreadPri(struct w2c_env *env, u32 t) {
    (void)env;
    return (u32)T(t ? t : self->t)->priority;
}

void w2c_env_osSetThreadPri(struct w2c_env *env, u32 t, u32 pri) {
    (void)env;
    enter();
    if (t == 0) t = self->t;
    if (T(t)->priority != (s32)pri) {
        T(t)->priority = (s32)pri;
        if (t != self->t && T(t)->state == OS_STATE_RUNNABLE) {
            unlink_thread(READY, t);
            enqueue(READY, t);
        }
        if (ready && T(ready)->priority > T(self->t)->priority) block_self(0, OS_STATE_RUNNABLE);
    }
    leave();
}

static void wake_one(u32 q) {
    u32 t = pop(q);
    if (t) make_ready(t);
}

static s32 put(u32 mqa, u32 msg, s32 flag, int jam) {
    GMesgQueue *mq = G(mqa);
    while (mq->validCount >= mq->msgCount) {
        if (flag == OS_MESG_NOBLOCK || !self) return -1;
        block_self(mqa + 4, OS_STATE_WAITING); // fullqueue
    }
    u32 *buf = G(mq->msg);
    if (jam) {
        mq->first = (mq->first + mq->msgCount - 1) % mq->msgCount;
        buf[mq->first] = msg;
    } else {
        buf[(mq->first + mq->validCount) % mq->msgCount] = msg;
    }
    mq->validCount++;
    wake_one(mqa); // mtqueue
    return 0;
}

u32 w2c_env_osSendMesg(struct w2c_env *env, u32 mq, u32 msg, u32 flag) {
    s32 r;
    (void)env;
    enter();
    r = put(mq, msg, (s32)flag, 0);
    leave();
    return (u32)r;
}

u32 w2c_env_osJamMesg(struct w2c_env *env, u32 mq, u32 msg, u32 flag) {
    s32 r;
    (void)env;
    enter();
    r = put(mq, msg, (s32)flag, 1);
    leave();
    return (u32)r;
}

u32 w2c_env_osRecvMesg(struct w2c_env *env, u32 mqa, u32 msg, u32 flag) {
    GMesgQueue *mq = G(mqa);
    (void)env;
    enter();
    while (mq->validCount == 0) {
        if (flag == OS_MESG_NOBLOCK) { leave(); return (u32)-1; }
        block_self(mqa, OS_STATE_WAITING); // mtqueue
    }
    if (msg) *(u32 *)G(msg) = ((u32 *)G(mq->msg))[mq->first];
    mq->first = (mq->first + 1) % mq->msgCount;
    mq->validCount--;
    wake_one(mqa + 4); // fullqueue
    leave();
    return 0;
}

void w2c_env_osSetEventMesg(struct w2c_env *env, u32 e, u32 mq, u32 msg) {
    (void)env;
    enter();
    if (e < OS_NUM_EVENTS) {
        events[e].mq = mq;
        events[e].msg = msg;
    }
    leave();
}

void bt_os_post(u32 mq, u32 msg) {
    if (!mq) return;
    pthread_mutex_lock(&intr);
    pthread_mutex_lock(&big);
    put(mq, msg, OS_MESG_NOBLOCK, 0); // a full queue drops the event, as on hardware
    pthread_mutex_unlock(&big);
    pthread_mutex_unlock(&intr);
}

void bt_os_event(u32 e) {
    u32 mq, msg;
    pthread_mutex_lock(&big);
    mq = events[e].mq;
    msg = events[e].msg;
    pthread_mutex_unlock(&big);
    bt_os_post(mq, msg);
}

// An event raised by the running guest thread (SI completion) is delivered like an interrupt.
void w2c_env_event(struct w2c_env *env, u32 e) {
    (void)env;
    if (e < OS_NUM_EVENTS) bt_os_event(e);
}

// Interrupt masking: a game thread that disables interrupts holds `intr`, so host
// events wait until it restores them. The mutex is recursive for nested sections.
static _Thread_local u32 current_mask = OS_IM_ALL;

u32 w2c_env_osSetIntMask(struct w2c_env *env, u32 mask) {
    u32 old = current_mask;
    int was_off = old == OS_IM_NONE, off = mask == OS_IM_NONE;
    (void)env;
    if (off && !was_off) pthread_mutex_lock(&intr);
    if (!off && was_off) pthread_mutex_unlock(&intr);
    current_mask = mask;
    return old;
}

// Time runs at the N64 CPU counter rate (46.875 MHz = 3/64 per nanosecond).
static u64 now_ticks(void) {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    u64 ns = (u64)(now.tv_sec - boot_time.tv_sec) * 1000000000ull + (u64)(now.tv_nsec - boot_time.tv_nsec);
    return ns * 3 / 64;
}

// Time queries are safe points for pending preemption, since games poll them in loops.
u64 bt_os_time(void) {
    enter();
    leave();
    return now_ticks();
}

u64 w2c_env_osGetTime(struct w2c_env *env) {
    (void)env;
    return bt_os_time();
}

// Timers: a host thread fires them in expiry order.
static u32 timers;
static pthread_cond_t timer_cv = PTHREAD_COND_INITIALIZER;
static GTimer *TM(u32 t) { return G(t); }

static void timer_unlink(u32 t) {
    if (TM(t)->prev) TM(TM(t)->prev)->next = TM(t)->next; else timers = TM(t)->next;
    if (TM(t)->next) TM(TM(t)->next)->prev = TM(t)->prev;
    TM(t)->next = TM(t)->prev = 0;
}

u32 w2c_env_osSetTimer(struct w2c_env *env, u32 t, u64 countdown, u64 interval, u32 mq, u32 msg) {
    (void)env;
    pthread_mutex_lock(&big);
    TM(t)->interval = interval;
    TM(t)->value = now_ticks() + (countdown ? countdown : interval);
    TM(t)->mq = mq;
    TM(t)->msg = msg;
    TM(t)->next = timers;
    TM(t)->prev = 0;
    if (timers) TM(timers)->prev = t;
    timers = t;
    pthread_cond_signal(&timer_cv);
    pthread_mutex_unlock(&big);
    return 0;
}

u32 w2c_env_osStopTimer(struct w2c_env *env, u32 t) {
    (void)env;
    pthread_mutex_lock(&big);
    for (u32 i = timers; i; i = TM(i)->next) {
        if (i == t) {
            timer_unlink(t);
            pthread_mutex_unlock(&big);
            return 0;
        }
    }
    pthread_mutex_unlock(&big);
    return (u32)-1;
}

static void *timer_main(void *unused) {
    (void)unused;
    pthread_mutex_lock(&big);
    for (;;) {
        u32 next = 0;
        for (u32 i = timers; i; i = TM(i)->next) {
            if (!next || TM(i)->value < TM(next)->value) next = i;
        }
        if (!next) {
            pthread_cond_wait(&timer_cv, &big);
            continue;
        }
        u64 now = now_ticks();
        if (TM(next)->value > now) {
            u64 ns = (TM(next)->value - now) * 64 / 3;
            struct timespec until;
            clock_gettime(CLOCK_REALTIME, &until);
            until.tv_sec += ns / 1000000000ull;
            until.tv_nsec += ns % 1000000000ull;
            if (until.tv_nsec >= 1000000000) { until.tv_sec++; until.tv_nsec -= 1000000000; }
            pthread_cond_timedwait(&timer_cv, &big, &until);
            continue;
        }
        u32 mq = TM(next)->mq, msg = TM(next)->msg;
        if (TM(next)->interval) TM(next)->value += TM(next)->interval;
        else timer_unlink(next);
        pthread_mutex_unlock(&big);
        bt_os_post(mq, msg);
        pthread_mutex_lock(&big);
    }
    return NULL;
}

void w2c_env_osInitialize(struct w2c_env *env) {
    static int done;
    pthread_mutexattr_t attr;
    pthread_t timer;
    (void)env;
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
