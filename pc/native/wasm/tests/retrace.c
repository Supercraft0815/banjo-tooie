// The window's retrace clock (host/retrace.h) on simulated displays.
#include <assert.h>
#include <stdio.h>
#include "../host/retrace.h"

// Swaps at `refresh` Hz with jitter for `seconds`; the retraces fired, -1 if the clock ever gave up.
static int run(double refresh, double seconds, int *worst) {
    RetraceClock c = {0};
    int total = 0, i = 0;
    *worst = 0;
    for (double t = 1; t < 1 + seconds; t += 1 / refresh, i++) {
        int n = retrace_step(&c, t + (i * 7 % 5 - 2) * .0004, refresh, 59.94);  // +-0.8 ms
        if (n < 0) return -1;
        if (n > *worst) *worst = n;
        total += n;
    }
    return total;
}

static void poses(double refresh) {
    double start = 3.0021, duration = 1.0 / 29.97, period = 1.0 / refresh;
    DisplayCadence c = {.last = 3, .period = period};
    float phases[BT_POSES_PER_PICTURE];
    int n = display_phases(c, start, duration, phases);
    assert(n >= (int)(duration * refresh) && n <= (int)ceil(duration * refresh));
    for (int i = 0; i < n; i++) {
        double t = start + duration * phases[i];
        assert(fabs((t - c.last) / period - round((t - c.last) / period)) < .00001);
        assert(phases[i] > 0 && phases[i] < 1 && (!i || phases[i] > phases[i-1]));
    }
    printf("%.0f Hz, %d intermediate poses, first t=%.6f\n", refresh, n, phases[0]);
}
int main(void) {
    poses(75); poses(144); poses(165);
    DisplayCadence d = {0};
    display_swap(&d, 1, 1);
    display_swap(&d, 1.007, 1);  // 143 Hz, then 89 Hz
    assert(fabs(d.period - .007) < 1e-9);
    float before[BT_POSES_PER_PICTURE], after[BT_POSES_PER_PICTURE];
    int a = display_phases(d, 1.0187, 1.0/30, before);
    display_swap(&d, 1.0182, 1);
    int b = display_phases(d, 1.0187, 1.0/30, after);
    assert(fabs(d.period - .0112) < 1e-9 && a == 5 && b == 3 && fabs(before[0]-after[0]) > .1);
    display_swap(&d, 1.0183, 1);
    assert(!d.period && !display_phases(d, 1.019, 1.0/30, after));
    display_swap(&d, 1.03, 0);
    assert(!d.period);  // no pacing when vsync is disabled

    int worst, n = run(60, 100, &worst);
    assert(n >= 5999 && n <= 6000 && worst == 1);  // one retrace per refresh, none dropped or doubled
    n = run(120, 100, &worst);
    assert(n >= 5999 && n <= 6000 && worst == 1);  // every second refresh
    assert(run(144, 1, &worst) == -1 && run(50, 1, &worst) == -1 && run(0, 1, &worst) == -1);

    RetraceClock c = {0};
    assert(retrace_step(&c, 1, 60, 59.94) == 0);
    assert(retrace_step(&c, 1 + 1 / 60., 60, 59.94) == 1);
    assert(retrace_step(&c, 1 + 3 / 60., 60, 59.94) == 2);  // a missed refresh: the game keeps its time
    assert(retrace_step(&c, 1 + 4 / 60., 60, 59.94) == 1);
    assert(retrace_step(&c, 9, 60, 59.94) == 4);            // a long stall is not caught up
    assert(retrace_step(&c, 9 + 1 / 60., 60, 59.94) == 1);
    int r = 0;
    for (int i = 0; i < 20; i++) r = retrace_step(&c, 10 + i * .0001, 60, 59.94);  // swaps stop waiting
    assert(r == -1);
    assert(retrace_step(&c, 10.1, 60, 59.94) == 0 && c.on);  // and wait again
    puts("Retrace clock at 60/120 Hz, missed refreshes, other rates: PASS");
    return 0;
}
