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
    u32 spin_jumps;  // clock jumps its loop latches caused since its last OS call (hang watchdog)
} HostThread;

static HostThread threads[MAX_THREADS];
static pthread_mutex_t big = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t intr; // held while a game thread masks interrupts
static u32 running, ready, running_global;
static int booted, preempt;
unsigned bt_preempt_flag;  // preempt, for the loop safepoints in the guest (BT_SAFEPOINT)
static _Thread_local HostThread *self;
static struct { u32 mq, msg; } events[OS_NUM_EVENTS];
static struct timespec boot_time;
static _Thread_local u32 current_mask = OS_IM_ALL;

// BT_VCLOCK=1: virtual clock, so a BT_PRESS run repeats exactly. Time stands still while
// guest code runs and jumps to the next VI retrace or timer once every thread waits; events
// are then delivered by the thread that went idle, never by host threads. osGetTime advances
// it by VCLOCK_POLL; VCLOCK_SPINS loop latches without an OS call count as a busy wait and
// jump it to the next event. Windowed runs are paced to BT_SPEED x real time, headless ones
// run as fast as the host allows.
int bt_vclock_on;
static u64 vnow, vi_due;
static u32 spins;  // loop latches of the running thread since its last OS call
static int in_isr, vclock_paced;
#define VI_TICKS 782031ull  // 46.875 MHz / 59.94 Hz
#define VCLOCK_POLL 47      // 1 us per time query
#define VCLOCK_SPINS 100000
static void vclock_idle(void);
static void vclock_fire(void);
static u64 next_event(void);

// ILP32 OSThread: next 0, priority 4, queue 8, tlnext 12, u16 state 16, u16 flags 18, id 20.
// A thread's next link is at its own address, a queue's head at the queue's (OSThread **).
static s32 pri(u32 t) { return (s32)gr32(t + 4); }
static void set_state(u32 t, u32 s) { gw16(t + 16, s); }
static u32 state(u32 t) { return gr16(t + 16); }
static u32 queue_of(u32 t) { return gr32(t + 8); }
static u32 qlink(u32 l) { return l == READY ? ready : gr32(l); }
static void set_qlink(u32 l, u32 t) { if (l == READY) ready = t; else gw32(l, t); }

static HostThread *host_of(u32 t) {
    for (int i = 0; i < MAX_THREADS; i++) {
        if (threads[i].t == t) return &threads[i];
    }
    return NULL;
}

// Inserts by priority, after threads of equal priority (libultra __osEnqueueThread).
static void enqueue(u32 q, u32 t) {
    u32 l = q;
    gw32(t + 8, q);
    while (qlink(l) && pri(qlink(l)) >= pri(t)) l = qlink(l);
    gw32(t, qlink(l));
    set_qlink(l, t);
}

static void unlink_thread(u32 q, u32 t) {
    for (u32 l = q; qlink(l); l = qlink(l)) {
        if (qlink(l) == t) { set_qlink(l, gr32(t)); gw32(t, 0); return; }
    }
}

static u32 pop(u32 q) {
    u32 t = qlink(q);
    if (t) { set_qlink(q, gr32(t)); gw32(t, 0); }
    return t;
}

static int cpu_wanted(void) { return ready && pri(ready) > OS_PRIORITY_IDLE; }

static void dispatch(void) {
    if (bt_vclock_on) vclock_idle();
    running = cpu_wanted() ? pop(READY) : 0;
    if (running_global) gw32(running_global, running);
    preempt = 0;
    __atomic_store_n(&bt_preempt_flag, (unsigned)bt_vclock_on, __ATOMIC_RELAXED); // vclock counts every latch
    if (running) {
        set_state(running, OS_STATE_RUNNING);
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
    set_state(self->t, state);
    if (state == OS_STATE_RUNNABLE) enqueue(READY, self->t);
    dispatch();
    wait_cpu();
}

// Every OS call from the guest starts here. The caller owns the CPU; a pending
// preemption hands it to the higher-priority thread first.
static void preempt_point(void) {
    if (bt_vclock_on && current_mask != OS_IM_NONE && next_event() <= vnow) vclock_fire();
    if ((preempt || bt_vclock_on) && ready && pri(ready) > pri(self->t)) block_self(0, OS_STATE_RUNNABLE);
}

static void enter(void) {
    pthread_mutex_lock(&big);
    if (!self) return; // boot context
    self->sp = BT_SP;
    spins = 0;
    self->spin_jumps = 0;
    preempt_point();
}

static void leave(void) {
    pthread_mutex_unlock(&big);
}

// Makes t ready. From a game thread a higher priority takes the CPU at once; from a
// host thread it waits for the running thread's next OS call.
static void make_ready(u32 t) {
    set_state(t, OS_STATE_RUNNABLE);
    enqueue(READY, t);
    if (in_isr) return; // vclock event delivery: the caller dispatches afterwards
    if (!running) {
        dispatch();
    } else if (pri(t) > pri(running)) {
        if (self && self->t == running) block_self(0, OS_STATE_RUNNABLE);
        else { preempt = 1; __atomic_store_n(&bt_preempt_flag, 1, __ATOMIC_RELAXED); }
    }
}

static void *thread_main(void *p) {
    HostThread *h = p;
    self = h;
    wasm_rt_init_thread();
    pthread_mutex_lock(&big);
    wait_cpu();
    pthread_mutex_unlock(&big);
    bt_call_guest(h->entry, h->arg, h->t);
    w2c_env_osDestroyThread(NULL, 0);
    return NULL;
}

void w2c_env_osCreateThread(struct w2c_env *env, u32 t, u32 id, u32 entry, u32 arg, u32 sp, u32 pr) {
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
    gw32(t, 0);
    gw32(t + 8, 0);
    gw32(t + 20, id);
    gw32(t + 4, pr);
    set_state(t, OS_STATE_STOPPED);
    gw16(t + 18, 0);
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
    if (state(t) == OS_STATE_STOPPED || state(t) == OS_STATE_WAITING) {
        if (queue_of(t) && queue_of(t) != READY) unlink_thread(queue_of(t), t);
        if (!self && !booted) {
            // Boot: the first started thread gets the CPU whatever its priority, and the
            // boot context ends here, as on the N64 (it must not touch the guest stack again).
            booted = 1;
            running = t;
            if (running_global) gw32(running_global, running);
            set_state(t, OS_STATE_RUNNING);
            pthread_cond_signal(&h->cv);
            leave();
            bt_video_main();  // the main thread owns the window from here
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
        if (state(t) == OS_STATE_RUNNABLE) unlink_thread(READY, t);
        else if (queue_of(t)) unlink_thread(queue_of(t), t);
        set_state(t, OS_STATE_STOPPED);
    }
    leave();
}

void w2c_env_osDestroyThread(struct w2c_env *env, u32 t) {
    (void)env;
    enter();
    if (t == 0 || t == self->t) {
        set_state(self->t, OS_STATE_STOPPED);
        self->t = 0;
        dispatch();
        leave();
        pthread_exit(NULL);
    }
    if (state(t) == OS_STATE_RUNNABLE) unlink_thread(READY, t);
    else if (queue_of(t)) unlink_thread(queue_of(t), t);
    set_state(t, OS_STATE_STOPPED);
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
    return gr32((t ? t : self->t) + 20);
}

u32 w2c_env_osGetThreadPri(struct w2c_env *env, u32 t) {
    (void)env;
    return (u32)pri(t ? t : self->t);
}

void w2c_env_osSetThreadPri(struct w2c_env *env, u32 t, u32 pr) {
    (void)env;
    enter();
    if (t == 0) t = self->t;
    if (pri(t) != (s32)pr) {
        gw32(t + 4, pr);
        if (t != self->t && state(t) == OS_STATE_RUNNABLE) {
            unlink_thread(READY, t);
            enqueue(READY, t);
        }
        if (ready && pri(ready) > pri(self->t)) block_self(0, OS_STATE_RUNNABLE);
    }
    leave();
}

static void wake_one(u32 q) {
    u32 t = pop(q);
    if (t) make_ready(t);
}

// ILP32 OSMesgQueue: mtqueue 0, fullqueue 4, validCount 8, first 12, msgCount 16, msg 20.
static s32 put(u32 mq, u32 msg, s32 flag, int jam) {
    while (gr32(mq + 8) >= gr32(mq + 16)) {
        if (flag == OS_MESG_NOBLOCK || !self) return -1;
        block_self(mq + 4, OS_STATE_WAITING); // fullqueue
    }
    u32 buf = gr32(mq + 20), first = gr32(mq + 12), count = gr32(mq + 16), valid = gr32(mq + 8);
    if (jam) {
        first = (first + count - 1) % count;
        gw32(mq + 12, first);
        gw32(buf + 4 * first, msg);
    } else {
        gw32(buf + 4 * ((first + valid) % count), msg);
    }
    gw32(mq + 8, valid + 1);
    wake_one(mq); // mtqueue
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

u32 w2c_env_osRecvMesg(struct w2c_env *env, u32 mq, u32 msg, u32 flag) {
    (void)env;
    enter();
    while (gr32(mq + 8) == 0) {
        if (flag == OS_MESG_NOBLOCK) { leave(); return (u32)-1; }
        block_self(mq, OS_STATE_WAITING); // mtqueue
    }
    u32 first = gr32(mq + 12);
    if (msg) gw32(msg, gr32(gr32(mq + 20) + 4 * first));
    gw32(mq + 12, (first + 1) % gr32(mq + 16));
    gw32(mq + 8, gr32(mq + 8) - 1);
    wake_one(mq + 4); // fullqueue
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
u32 w2c_env_osSetIntMask(struct w2c_env *env, u32 mask) {
    u32 old = current_mask;
    int was_off = old == OS_IM_NONE, off = mask == OS_IM_NONE;
    (void)env;
    if (off && !was_off) pthread_mutex_lock(&intr);
    if (!off && was_off) pthread_mutex_unlock(&intr);
    current_mask = mask;
    return old;
}

// A loop latch with a preemption pending; with interrupts off the N64 would not switch either.
void w2c_env_safepoint(struct w2c_env *env) {
    (void)env;
    if (current_mask == OS_IM_NONE) return;
    if (bt_vclock_on && ++spins < VCLOCK_SPINS) return; // only the running thread counts
    u32 jumps = self ? self->spin_jumps + 1 : 0;
    enter();  // counts as an OS call: restore the count of clock jumps
    if (bt_vclock_on && self) {
        u64 d = next_event();
        if (d > vnow) vnow = d;
        // A thread that keeps looping across this many events without an OS call hangs; the
        // virtual clock would otherwise run on to BT_EXIT_AFTER and the run would look fine.
        if ((self->spin_jumps = jumps) > 1200 && pri(self->t) > 0) {  // priority 0: the idle thread
            fprintf(stderr, "bt_native: guest thread (priority %d) loops without an OS call (hang)\n", (int)pri(self->t));
            bt_backtrace();
            abort();
        }
        preempt_point();
    }
    leave();
}

double bt_speed(void) {
    static double speed;
    if (!speed) speed = getenv("BT_SPEED") && atof(getenv("BT_SPEED")) > 0 ? atof(getenv("BT_SPEED")) : 1;
    return speed;
}

// Time runs at the N64 CPU counter rate (46.875 MHz = 3/64 per nanosecond).
static u64 now_ticks(void) {
    struct timespec now;
    if (bt_vclock_on) return vnow;
    clock_gettime(CLOCK_MONOTONIC, &now);
    u64 ns = (u64)(now.tv_sec - boot_time.tv_sec) * 1000000000ull + (u64)(now.tv_nsec - boot_time.tv_nsec);
    return (u64)(ns * bt_speed()) * 3 / 64;
}

// Time queries are safe points for pending preemption, since games poll them in loops.
u64 bt_os_time(void) {
    u64 t;
    enter();
    if (bt_vclock_on && self) {
        vnow += VCLOCK_POLL;
        preempt_point();
    }
    t = now_ticks();
    leave();
    return t;
}

u64 bt_vclock_ticks(void) { return vnow; }  // read by the running guest thread

u64 w2c_env_osGetTime(struct w2c_env *env) {
    (void)env;
    return bt_os_time();
}

// Timers: a host thread fires them in expiry order.
static u32 timers;
static pthread_cond_t timer_cv = PTHREAD_COND_INITIALIZER;
// ILP32 OSTimer: next 0, prev 4, u64 interval 8, u64 value 16, mq 24, msg 28.
static u32 tm_next(u32 t) { return gr32(t); }
static u32 tm_prev(u32 t) { return gr32(t + 4); }
static u64 tm_value(u32 t) { return gr64(t + 16); }

static void timer_unlink(u32 t) {
    if (tm_prev(t)) gw32(tm_prev(t), tm_next(t)); else timers = tm_next(t);
    if (tm_next(t)) gw32(tm_next(t) + 4, tm_prev(t));
    gw32(t, 0);
    gw32(t + 4, 0);
}

u32 w2c_env_osSetTimer(struct w2c_env *env, u32 t, u64 countdown, u64 interval, u32 mq, u32 msg) {
    (void)env;
    pthread_mutex_lock(&big);
    gw64(t + 8, interval);
    gw64(t + 16, now_ticks() + (countdown ? countdown : interval));
    gw32(t + 24, mq);
    gw32(t + 28, msg);
    gw32(t, timers);
    gw32(t + 4, 0);
    if (timers) gw32(timers + 4, t);
    timers = t;
    pthread_cond_signal(&timer_cv);
    pthread_mutex_unlock(&big);
    return 0;
}

u32 w2c_env_osStopTimer(struct w2c_env *env, u32 t) {
    (void)env;
    pthread_mutex_lock(&big);
    for (u32 i = timers; i; i = tm_next(i)) {
        if (i == t) {
            timer_unlink(t);
            pthread_mutex_unlock(&big);
            return 0;
        }
    }
    pthread_mutex_unlock(&big);
    return (u32)-1;
}

static u32 earliest_timer(void) {
    u32 next = 0;
    for (u32 i = timers; i; i = tm_next(i)) {
        if (!next || tm_value(i) < tm_value(next)) next = i;
    }
    return next;
}

// Takes the timer's event and rearms or removes it.
static void timer_expire(u32 t, u32 *mq, u32 *msg) {
    *mq = gr32(t + 24);
    *msg = gr32(t + 28);
    if (gr64(t + 8)) gw64(t + 16, tm_value(t) + gr64(t + 8));
    else timer_unlink(t);
}

static u64 next_event(void) {
    u32 t = earliest_timer();
    return t && tm_value(t) < vi_due ? tm_value(t) : vi_due;
}

// Delivers every event due at vnow in time order, as interrupts: woken threads only become ready.
static void vclock_fire(void) {
    in_isr = 1;
    for (u64 d; (d = next_event()) <= vnow;) {
        u32 mq, msg, t = earliest_timer();
        if (t && tm_value(t) == d) {
            timer_expire(t, &mq, &msg);
        } else {
            vi_due += VI_TICKS;
            bt_vi_retrace(&mq, &msg);
        }
        if (mq) put(mq, msg, OS_MESG_NOBLOCK, 0);
    }
    in_isr = 0;
}

static void vclock_pace(void) {
    struct timespec now, d;
    if (!vclock_paced) return;
    u64 ns = (u64)(vnow * 64 / 3 / bt_speed());
    clock_gettime(CLOCK_MONOTONIC, &now);
    int64_t left = (int64_t)ns - ((int64_t)(now.tv_sec - boot_time.tv_sec) * 1000000000 + (now.tv_nsec - boot_time.tv_nsec));
    if (left <= 0) return;
    d.tv_sec = left / 1000000000;
    d.tv_nsec = left % 1000000000;
    nanosleep(&d, NULL);
}

// No thread wants the CPU: time jumps to the next event.
static void vclock_idle(void) {
    while (!cpu_wanted()) {
        u64 d = next_event();
        if (d > vnow) vnow = d;
        vclock_pace();
        vclock_fire();
    }
}

static void *timer_main(void *unused) {
    (void)unused;
    pthread_mutex_lock(&big);
    for (;;) {
        u32 next = earliest_timer();
        if (!next) {
            pthread_cond_wait(&timer_cv, &big);
            continue;
        }
        u64 now = now_ticks();
        if (tm_value(next) > now) {
            u64 ns = (u64)((tm_value(next) - now) * 64 / 3 / bt_speed());
            struct timespec until;
            clock_gettime(CLOCK_REALTIME, &until);
            until.tv_sec += ns / 1000000000ull;
            until.tv_nsec += ns % 1000000000ull;
            if (until.tv_nsec >= 1000000000) { until.tv_sec++; until.tv_nsec -= 1000000000; }
            pthread_cond_timedwait(&timer_cv, &big, &until);
            continue;
        }
        u32 mq, msg;
        timer_expire(next, &mq, &msg);
        pthread_mutex_unlock(&big);
        bt_os_post(mq, msg);
        pthread_mutex_lock(&big);
    }
    return NULL;
}

void w2c_env_osInitialize(struct w2c_env *env, u32 running_address) {
    static int done;
    pthread_mutexattr_t attr;
    pthread_t timer;
    (void)env;
    if (done) return;
    done = 1;
    running_global = running_address;
    gw32(running_global, running);
    clock_gettime(CLOCK_MONOTONIC, &boot_time);
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&intr, &attr);
    pthread_mutexattr_destroy(&attr);
    bt_vclock_on = getenv("BT_VCLOCK") != NULL;
    if (bt_vclock_on) {
        vi_due = VI_TICKS;
        vclock_paced = !getenv("BT_HEADLESS");
        bt_preempt_flag = 1;
        return; // no host threads: vclock_fire delivers timers and retraces
    }
    pthread_create(&timer, NULL, timer_main, NULL);
    pthread_detach(timer);
    bt_vi_init();
}
