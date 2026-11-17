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

int main(void) {
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
