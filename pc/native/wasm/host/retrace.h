// The retrace clock of the window (video.c), apart from SDL so tests/retrace.c can step it.
// Where the display's rate is a multiple of the game's 59.94 Hz (60, 120, 240 Hz) the retrace
// follows the display's vsync: every game picture is then shown for the same number of refreshes.
// Two free-running clocks drift through each other, and a picture is dropped or shown twice every
// few seconds. The game's audio follows (its buffer sizes track the AI queue, 1E2A0E0.c).
#ifndef BT_HOST_RETRACE_H
#define BT_HOST_RETRACE_H
#include <math.h>

typedef struct { double prev, due; int unpaced, on; } RetraceClock;

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
    if (!c->on) { c->on = 1; c->due = now + period; }
    int fired = 0;
    for (; now >= c->due - slack && fired < 4; fired++) c->due += period;  // more than one: refreshes were missed
    if (fired == 1 || fired == 4) c->due = now + period;  // follow the display; far behind: start over
    return fired;
}
#endif
