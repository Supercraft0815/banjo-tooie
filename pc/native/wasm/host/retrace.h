// The retrace clock of the window (video.c), apart from SDL so tests/retrace.c can step it.
// Where the display's rate is a multiple of the game's 59.94 Hz (60, 120, 240 Hz) the retrace
// follows the display's vsync: every game picture is then shown for the same number of refreshes.
// Two free-running clocks drift through each other, and a picture is dropped or shown twice every
// few seconds. The game's audio follows (its buffer sizes track the AI queue, 1E2A0E0.c).
#ifndef BT_HOST_RETRACE_H
#define BT_HOST_RETRACE_H
#include <math.h>

typedef struct { double prev, due; int unpaced, on, pending; } RetraceClock;

// A buffer swap returned at `now` seconds on a display with `refresh` Hz (0: unknown); the game wants
// `rate` retraces per second. Returns the retraces to fire now, or -1 when vi.c's timer has to be the
// clock: another display rate, or swaps that do not wait for the display (a hidden window).
static inline int retrace_step(RetraceClock *c, double now, double refresh, double rate) {
    double dt = now - c->prev;
    int n = (int)(refresh / rate + .5);  // refreshes per retrace
    int lock = n >= 1 && fabs(refresh / n - rate) < rate * .01;
    c->prev = now;
    c->unpaced = lock && dt < .5 / refresh ? c->unpaced + 1 : 0;
    if (!lock || c->unpaced > 10) { c->on = 0; return -1; }
    double period = n / refresh, slack = .5 / refresh;
    if (!c->on) { c->pending = 0; c->on = 1; c->due = now + period; }
    int fired = 0;
    for (; now >= c->due - slack && fired < 4; fired++) c->due += period;  // more than one: refreshes were missed
    if (fired == 1 || fired == 4) c->due = now + period;  // follow the display; far behind: start over
    // A late swap return can be followed immediately by the next buffered swap.
    // Give that presentation its own VI. A genuinely missed refresh is caught up
    // on the following swap, so the guest keeps display time.
    int pending = fired > 1;
    fired += c->pending - pending;
    c->pending = pending;
    return fired;
}
// Observed swap times and the next presentation on that timeline. Interpolation
// uses display time even when the VI itself is driven by its 59.94 Hz timer.
enum { BT_POSES_PER_PICTURE = 32 };
typedef struct { double last, period; } DisplayCadence;
static inline void display_swap(DisplayCadence *c, double now, int paced) {
    double dt = now - c->last;
    c->last = now;
    c->period = paced && dt >= .001 && dt <= .05 ? dt : 0;
}

// Sample the expected display instants inside one game picture. The real
// picture is already available at t=1. If the game stalls, bound both the
// number of extra display-list passes and the associated frame storage.
static inline int display_phases(DisplayCadence c, double start, double duration, float *phases) {
    if (c.period <= 0 || duration <= 0) return 0;
    double step = c.period * fmax(1, ceil(duration / (c.period * (BT_POSES_PER_PICTURE + 1))));
    double first = c.last + (floor((start - c.last) / c.period) + 1) * c.period;
    int n = 0;
    for (double t = first; t < start + duration && n < BT_POSES_PER_PICTURE; t += step) {
        double phase = (t - start) / duration;
        if (phase > .0001 && phase < .9999) phases[n++] = (float)phase;
    }
    return n;
}
#endif
