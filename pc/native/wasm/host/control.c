// BT_CONTROL=path (with BT_VCLOCK=1): play the game step by step from another process (play.py).
// The game stops at a retrace and reads one line from the FIFO path.in; the commands in it run in
// order (separated by ';'), and once they are done one reply goes to the FIFO path.out:
// their output, then "ready <retrace> map <hex> pos <x y z>". Commands:
//   run N [mask]    hold mask (BT_PRESS format: buttons, stick x << 16, stick y << 24) for N retraces
//   shot FILE [hi]  save the shown picture as BMP (hi: at internal resolution)
//   peek ADDR [N]   guest bytes at ADDR (hex), N at most 256
//   poke ADDR HEX   write guest bytes
//   warp MAP [EXIT] debug map change (map in hex)
//   quit
// The game is paused while it waits, holding the guest lock, so the run stays deterministic.
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"
#include "trace_symbols.h"

int bt_control_on = -1;
u32 bt_control_mask, bt_control_warp;
static u32 stop_at;
static char path_in[512], path_out[512], line[4096], *rest;
static char reply[16384];
static size_t used;
static int pending;  // a command line was read and needs its reply

static void say(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
static void say(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int n = vsnprintf(reply + used, sizeof reply - used, fmt, ap);
    va_end(ap);
    if (n > 0) used = used + (size_t)n < sizeof reply ? used + (size_t)n : sizeof reply - 1;
}

static float gf32(u32 a) { u32 v = gr32(a); float f; memcpy(&f, &v, 4); return f; }

static void status(u32 count) {
    u32 player = gr32(TRACE_D_80135490), pos = player ? gr32(player + 0xE4) : 0;
    say("ready %u map %X", count, gr16(TRACE_D_80132DC2));
    if (pos) say(" pos %.1f %.1f %.1f", gf32(pos), gf32(pos + 4), gf32(pos + 8));
    say("\n");
}

static void send_reply(void) {
    FILE *f = fopen(path_out, "w");  // blocks until the client opens it for reading
    if (f) { fwrite(reply, 1, used, f); fclose(f); }
    used = 0;
}

// Runs commands from `rest` until one lets the game go on (1) or the line is done (0).
static int execute(u32 count, u32 fb, u32 width, u32 age) {
    while (rest && *rest) {
        char *cmd = rest, *semi = strchr(rest, ';');
        if (semi) { *semi = 0; rest = semi + 1; } else rest = NULL;
        char op[16] = "", a[512] = "", b[512] = "";
        if (sscanf(cmd, " %15s %511s %511s", op, a, b) < 1) continue;
        if (!strcmp(op, "run")) {
            u32 n = (u32)strtoul(a, NULL, 0);
            bt_control_mask = (u32)strtoul(b, NULL, 16);
            if (n) { stop_at = count + n; return 1; }
        } else if (!strcmp(op, "shot")) {  // the path is the rest of the command and may hold spaces
            char *path = strstr(cmd, "shot") + 4, *end;
            while (*path == ' ') path++;
            end = path + strlen(path);
            while (end > path && end[-1] == ' ') *--end = 0;
            int hi = end - path > 3 && !strcmp(end - 3, " hi");
            if (hi) end[-3] = 0;
            if (!bt_video_save(path, fb, width, age, hi)) say("error: no picture\n");
        } else if (!strcmp(op, "peek")) {
            u32 addr = (u32)strtoul(a, NULL, 16), n = *b ? (u32)strtoul(b, NULL, 0) : 4;
            if (n > 256) n = 256;
            if ((u64)addr + n > bt_inst.w2c_memory.size) { say("error: address\n"); continue; }
            say("%08x:", addr);
            for (u32 i = 0; i < n; i++) say(" %02x", bt_mem[addr + i]);
            say("\n");
        } else if (!strcmp(op, "poke")) {
            u32 addr = (u32)strtoul(a, NULL, 16), n = (u32)strlen(b) / 2;
            if ((u64)addr + n > bt_inst.w2c_memory.size) { say("error: address\n"); continue; }
            for (u32 i = 0; i < n; i++) { char h[3] = {b[2 * i], b[2 * i + 1], 0}; bt_mem[addr + i] = (u8)strtoul(h, NULL, 16); }
        } else if (!strcmp(op, "warp")) {
            bt_control_warp = (u32)strtoul(a, NULL, 16) << 8 | ((u32)strtoul(b, NULL, 10) & 0xFF);
        } else if (!strcmp(op, "quit")) {
            say("bye\n");
            send_reply();
            exit(0);
        } else {
            say("error: unknown command %s\n", op);
        }
    }
    return 0;
}

void bt_control_retrace(u32 count, u32 fb, u32 width, u32 age) {
    if (bt_control_on < 0) {
        const char *p = getenv("BT_CONTROL");
        bt_control_on = p && *p && bt_vclock_on;
        if (p && *p && !bt_vclock_on) bt_fatal("BT_CONTROL needs BT_VCLOCK=1");
#ifdef _WIN32
        if (bt_control_on) bt_fatal("BT_CONTROL needs POSIX FIFOs");
#endif
        if (bt_control_on) {
            snprintf(path_in, sizeof path_in, "%s.in", p);
            snprintf(path_out, sizeof path_out, "%s.out", p);
        }
    }
    if (!bt_control_on || count < stop_at) return;
    for (;;) {
        if (execute(count, fb, width, age)) return;
        if (pending) { status(count); send_reply(); }
        pending = 1;
        FILE *f = fopen(path_in, "r");  // blocks until the client writes
        if (!f) bt_fatal("BT_CONTROL: cannot open %s", path_in);
        rest = fgets(line, sizeof line, f) ? line : NULL;
        fclose(f);
        if (rest) rest[strcspn(rest, "\n")] = 0;
    }
}
