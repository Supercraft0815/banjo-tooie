#define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE 700
#define _GNU_SOURCE 1
#ifdef __APPLE__
#define _DARWIN_C_SOURCE 1
#endif
#include "crash.h"
#include <SDL3/SDL.h>
#ifndef _WIN32
#include <execinfo.h>
#else
#include <windows.h>
#include <dbghelp.h>
#endif
#include <stdatomic.h>
#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "guest.h"
#include "plat.h"
#include "crash_map_names.h"
#ifndef _WIN32
#include <fcntl.h>
#include <sys/socket.h>
#include <signal.h>
#include <ucontext.h>
#include <unistd.h>
#else
#include <io.h>
#include <process.h>
#include <fcntl.h>
#define read _read
#define write _write
#define dup _dup
#define dup2 _dup2
#define close _close
#define pipe(p) _pipe((p), 4096, _O_BINARY)
#define STDERR_FILENO 2
#endif

#define LOG_LINES 200
#define LINE_SIZE 768
static char log_ring[LOG_LINES][LINE_SIZE];
static unsigned log_next, log_count;
static pthread_mutex_t log_lock = PTHREAD_MUTEX_INITIALIZER;
static char crash_path[1024], version_text[128], map_path[1024], native_map_path[1024];
static int interactive;
static atomic_uint_least16_t last_map = 0xffff;
#ifdef BT_CRASH_TEST
static int maptrap_test;
#endif

void bt_crash_map_update(uint16_t map_id) {
    if (map_id && strcmp(bt_crash_map_name(map_id), "unknown") != 0)
        atomic_store_explicit(&last_map, map_id, memory_order_release);
}

uint16_t bt_crash_current_map(void) {
    return atomic_load_explicit(&last_map, memory_order_acquire);
}

void bt_crash_test_guest_entry(void) {
#ifdef BT_CRASH_TEST
    if (maptrap_test && bt_crash_current_map() == 0x158)
        bt_trap(WASM_RT_TRAP_OOB);
#endif
}

int bt_crash_capture(void **frames, int capacity) {
#ifdef _WIN32
    return (int)CaptureStackBackTrace(0, (DWORD)capacity, frames, NULL);
#else
    return backtrace(frames, capacity);
#endif
}

#ifndef _WIN32
static int fault_pipe[2] = {-1, -1};
typedef struct { int sig; uintptr_t address, pc, fp; pthread_t thread; } FaultPacket;
static void fault_handler(int sig, siginfo_t *si, void *context) {
    FaultPacket p = {.sig = sig, .address = (uintptr_t)si->si_addr, .thread = pthread_self()};
    ucontext_t *u = context;
#if defined(__APPLE__) && defined(__arm64__)
    p.pc = (uintptr_t)u->uc_mcontext->__ss.__pc;
    p.fp = (uintptr_t)u->uc_mcontext->__ss.__fp;
#elif defined(__APPLE__) && defined(__x86_64__)
    p.pc = (uintptr_t)u->uc_mcontext->__ss.__rip;
    p.fp = (uintptr_t)u->uc_mcontext->__ss.__rbp;
#elif defined(__x86_64__) && defined(REG_RIP)
    p.pc = (uintptr_t)u->uc_mcontext.gregs[REG_RIP];
    p.fp = (uintptr_t)u->uc_mcontext.gregs[REG_RBP];
#elif defined(__aarch64__)
    p.pc = (uintptr_t)u->uc_mcontext.pc;
    p.fp = (uintptr_t)u->uc_mcontext.regs[29];
#endif
    if (fault_pipe[1] < 0 || write(fault_pipe[1], &p, sizeof p) != sizeof p) _exit(128 + sig);
    for (;;) pause();
}
static size_t fault_frame_chain(const FaultPacket *p, const void **frames, size_t capacity) {
    uintptr_t low = 0, high = 0;
#ifdef __APPLE__
    high = (uintptr_t)pthread_get_stackaddr_np(p->thread);
    size_t size = pthread_get_stacksize_np(p->thread);
    low = high > size ? high - size : 0;
#else
    pthread_attr_t attr;
    if (pthread_getattr_np(p->thread, &attr) == 0) {
        void *base = NULL; size_t size = 0;
        if (pthread_attr_getstack(&attr, &base, &size) == 0) {
            low = (uintptr_t)base; high = low + size;
        }
        pthread_attr_destroy(&attr);
    }
#endif
    size_t count = 0;
    if (p->pc && count < capacity) frames[count++] = (const void *)p->pc;
    uintptr_t fp = p->fp;
    while (low && high > low && fp >= low && fp <= high - 2 * sizeof(uintptr_t) &&
           !(fp & (sizeof(uintptr_t) - 1)) && count < capacity) {
        const uintptr_t *record = (const uintptr_t *)fp;
        uintptr_t next = record[0], ret = record[1];
        if (!ret || next <= fp || next > high - 2 * sizeof(uintptr_t)) break;
        frames[count++] = (const void *)ret;
        fp = next;
    }
    return count;
}
static int fault_main(void *unused) {
    (void)unused; FaultPacket p;
    if (read(fault_pipe[0], &p, sizeof p) == sizeof p) {
        char text[160]; snprintf(text, sizeof text, "signal %d, fault address 0x%llx, host PC 0x%llx",
            p.sig, (unsigned long long)p.address, (unsigned long long)p.pc);
        const void *frames[64]; size_t count = 0;
        count = fault_frame_chain(&p, frames, sizeof frames / sizeof frames[0]);
        if (!crash_path[0]) {
            fprintf(stderr, "bt_native: %s\n", text);
            backtrace_symbols_fd((void *const *)frames, (int)count, STDERR_FILENO);
        }
        bt_crash_report("native memory fault", text, frames, count);
        _exit(128 + p.sig);
    }
    return 0;
}
#endif
static int saved_stderr = -1, log_read = -1, log_write = -1;
static pthread_t log_thread;
#ifdef _WIN32
static pthread_mutex_t read_lock = PTHREAD_MUTEX_INITIALIZER;
static int reading, stopping;
#endif

static void finish_log(void) {
    fflush(stderr);
    if (dup2(saved_stderr, STDERR_FILENO) < 0) return;
#ifdef _WIN32
    pthread_mutex_lock(&read_lock);
    stopping = 1;
    close(log_write);
    pthread_mutex_unlock(&read_lock);
    HANDLE thread = (HANDLE)pthread_gethandle(log_thread);
    // A child may still own a write handle. Interrupt only a read, preserving pending output.
    while (WaitForSingleObject(thread, 10) == WAIT_TIMEOUT) {
        pthread_mutex_lock(&read_lock);
        if (reading) CancelSynchronousIo(thread);
        pthread_mutex_unlock(&read_lock);
    }
#else
    // Half-close every inherited copy of the writer after the parent's last byte.
    shutdown(log_write, SHUT_WR);
    close(log_write);
#endif
    pthread_join(log_thread, NULL);
    close(log_read);
    close(saved_stderr);
}
static void capture_line(const char *line, size_t n) {
    pthread_mutex_lock(&log_lock);
    size_t m = n < LINE_SIZE - 1 ? n : LINE_SIZE - 1;
    memcpy(log_ring[log_next], line, m); log_ring[log_next][m] = 0;
    log_next = (log_next + 1) % LOG_LINES;
    if (log_count < LOG_LINES) log_count++;
    pthread_mutex_unlock(&log_lock);
}
static void *log_main(void *unused) {
    (void)unused;
    char chunk[2048], line[LINE_SIZE]; size_t used = 0;
#ifdef _WIN32
    int64_t left = -1;
#endif
    for (;;) {
        size_t wanted = sizeof chunk;
#ifdef _WIN32
        pthread_mutex_lock(&read_lock);
        if (stopping && left < 0) {
            DWORD bytes = 0;
            if (!PeekNamedPipe((HANDLE)_get_osfhandle(log_read), NULL, 0, NULL, &bytes, NULL)) bytes = 0;
            left = bytes;
        }
        reading = left < 0;
        pthread_mutex_unlock(&read_lock);
        if (left == 0) break;
        if (left > 0 && (uint64_t)left < wanted) wanted = (size_t)left;
#endif
        int n = (int)read(log_read, chunk, wanted);
#ifdef _WIN32
        pthread_mutex_lock(&read_lock);
        reading = 0;
        int interrupted = stopping && left < 0 && n <= 0;
        pthread_mutex_unlock(&read_lock);
        if (interrupted) continue;
        if (left >= 0 && n > 0) left -= n;
#endif
        if (n < 0 && errno == EINTR) continue;
        if (n <= 0) break;
        for (int pos = 0; pos < n;) {
            int sent = (int)write(saved_stderr, chunk + pos, (size_t)(n - pos));
            if (sent < 0 && errno == EINTR) continue;
            if (sent <= 0) break;
            pos += sent;
        }
        for (int i = 0; i < n; i++) {
            if (chunk[i] == '\n') {
                line[used++] = '\n';
                capture_line(line, used);
                used = 0;
            } else if (used < sizeof line - 2) line[used++] = chunk[i];
        }
    }
    if (used) capture_line(line, used);
    return NULL;
}

static void report_path_init(void) {
    const char *override = bt_path_env("BT_CRASH_REPORT");
    if (override && *override) { snprintf(crash_path, sizeof crash_path, "%s", override); return; }
    // Headless/scripted runs never create files in a player's preferences directory.
    if (!interactive) return;
    char *dir = SDL_GetPrefPath("", "BanjoTooie");
    if (dir) { snprintf(crash_path, sizeof crash_path, "%scrash.txt", dir); SDL_free(dir); }
}

static void resolve_asset_path(char *dst, size_t cap, const char *path) {
    if (!path || !*path) { dst[0] = 0; return; }
#ifdef _WIN32
    int drive = ((path[0] >= 'A' && path[0] <= 'Z') || (path[0] >= 'a' && path[0] <= 'z')) && path[1] == ':';
    int absolute = path[0] == '/' || path[0] == '\\' || drive;
#else
    int absolute = path[0] == '/';
#endif
    if (absolute) { snprintf(dst, cap, "%s", path); return; }
    const char *base = SDL_GetBasePath();
    if (base) snprintf(dst, cap, "%s%s", base, path);
    else snprintf(dst, cap, "%s", path);
}

void bt_crash_init(const char *version, const char *map, const char *native_map) {
    snprintf(version_text, sizeof version_text, "%s", version ? version : "unknown");
    resolve_asset_path(map_path, sizeof map_path, map ? map : "game.map");
    resolve_asset_path(native_map_path, sizeof native_map_path, native_map);
    interactive = getenv("BT_HEADLESS") == NULL;
#ifdef BT_CRASH_TEST
    maptrap_test = getenv("BT_CRASH_TEST") && !strcmp(getenv("BT_CRASH_TEST"), "maptrap");
#endif
    report_path_init();
    if (crash_path[0]) {
        int p[2];
#ifdef _WIN32
        int rc = pipe(p);
#else
        int rc = socketpair(AF_UNIX, SOCK_STREAM, 0, p);
#endif
        if (rc == 0) {
            saved_stderr = dup(STDERR_FILENO);
            log_read = p[0];
            log_write = p[1];
            if (saved_stderr >= 0 && dup2(log_write, STDERR_FILENO) >= 0 &&
                pthread_create(&log_thread, NULL, log_main, NULL) == 0) {
                atexit(finish_log);
            } else {
                if (saved_stderr >= 0) { dup2(saved_stderr, STDERR_FILENO); close(saved_stderr); }
                close(log_read); close(log_write);
                saved_stderr = log_read = log_write = -1;
            }
        }
    }
#ifndef _WIN32
    if (!pipe(fault_pipe)) {
        SDL_Thread *t = SDL_CreateThread(fault_main, "crash-report", NULL);
        if (t) SDL_DetachThread(t); else { close(fault_pipe[0]); close(fault_pipe[1]); fault_pipe[0] = fault_pipe[1] = -1; }
    }
#endif
}

static void map_excerpt(FILE *f, const char *symbols) {
    FILE *m = bt_disk_open(map_path, "r");
    if (!m) { fprintf(f, "game.map: unavailable (%s)\n", map_path); return; }
    fprintf(f, "game.map symbol matches:\n");
    char line[2048]; unsigned shown = 0;
    while (fgets(line, sizeof line, m) && shown < 32) {
        if (!strstr(line, "func_")) continue;
        for (const char *p = symbols; p && *p;) {
            const char *end = strchr(p, '\n'); size_t n = end ? (size_t)(end - p) : strlen(p);
            char name[256];
            if (n && n < sizeof name) {
                memcpy(name, p, n); name[n] = 0;
                if (strstr(line, name)) { fprintf(f, "%s", line); shown++; break; }
            }
            if (!end) break; p = end + 1;
        }
    }
    fclose(m);
    if (!shown) fputs("(no guest function names matched host frames)\n", f);
}

#ifdef _WIN32
static int native_guest_symbol(uintptr_t pc, char *symbol, size_t cap, uintptr_t *start) {
    FILE *m = bt_disk_open(native_map_path, "r");
    if (!m) return 0;
    uintptr_t image_base = (uintptr_t)GetModuleHandleA(NULL);
    IMAGE_DOS_HEADER *dos = (IMAGE_DOS_HEADER *)image_base;
    IMAGE_NT_HEADERS *nt = (IMAGE_NT_HEADERS *)(image_base + (uintptr_t)dos->e_lfanew);
    uintptr_t image_end = image_base + nt->OptionalHeader.SizeOfImage;
    if (pc < image_base || pc >= image_end) { fclose(m); return 0; }
    uintptr_t target = pc >= image_base ? pc - image_base : pc;
    char line[4096]; uintptr_t best = 0; char best_name[256] = "";
    while (fgets(line, sizeof line, m)) {
        char *p = line; while (*p == ' ' || *p == '\t') p++;
        char *end; unsigned long long address = strtoull(p, &end, 16);
        if (end == p || address > target) continue;
        p = end; while (*p == ' ' || *p == '\t') p++;
        unsigned long long size = strtoull(p, &end, 16);
        if (end == p || size != 0) continue;
        char *tail = line + strlen(line);
        while (tail > line && (tail[-1] == '\n' || tail[-1] == '\r' || tail[-1] == ' ' || tail[-1] == '\t')) tail--;
        *tail = 0;
        char *name = tail;
        while (name > line && name[-1] != ' ' && name[-1] != '\t') name--;
        size_t n = (size_t)(tail - name); if (!n || n >= sizeof best_name) continue;
        if (address < best || (address == best && strncmp(name, "w2c_bt_func_", 12) != 0)) continue;
        memcpy(best_name, name, n); best_name[n] = 0; best = (uintptr_t)address;
    }
    fclose(m);
    if (strncmp(best_name, "w2c_bt_func_", 12)) return 0;
    snprintf(symbol, cap, "%s", best_name); if (start) *start = image_base + best; return 1;
}
#endif

void bt_crash_report(const char *kind, const char *detail, const void *const *frames, size_t count) {
    if (!crash_path[0]) return;
    FILE *f = bt_disk_open(crash_path, "w");
    if (!f) { fprintf(stderr, "bt_native: cannot write crash report %s\n", crash_path); return; }
    time_t now = time(NULL); struct tm tmv; char stamp[64] = "unknown";
#ifdef _WIN32
    if (localtime_s(&tmv, &now) == 0) strftime(stamp, sizeof stamp, "%Y-%m-%d %H:%M:%S %z", &tmv);
#else
    if (localtime_r(&now, &tmv)) strftime(stamp, sizeof stamp, "%Y-%m-%d %H:%M:%S %z", &tmv);
#endif
    unsigned map_id = bt_crash_current_map();
    fprintf(f, "Banjo-Tooie crash report\nTime: %s\nVersion: %s\nMap ID: ", stamp, version_text);
    if (map_id == 0xffff || map_id == 0) fputs("unknown\n", f);
    else fprintf(f, "%s (0x%04x)\n", bt_crash_map_name(map_id), map_id);
    fprintf(f, "Type: %s\nDetails: %s\nNative map: %s\n\nHost stack:\n",
            kind ? kind : "failure", detail ? detail : "", native_map_path[0] ? native_map_path : "unavailable");
    char guest_names[8192] = ""; size_t names_used = 0;
    if (frames && count) {
#ifndef _WIN32
        char **names = backtrace_symbols((void *const *)frames, (int)count);
#endif
        for (size_t i = 0; i < count; i++) {
#ifndef _WIN32
            const char *s = names ? names[i] : "(symbol unavailable)";
            fprintf(f, "%s\n", s);
#else
            char resolved[256]; uintptr_t start = 0;
            int found = native_guest_symbol((uintptr_t)frames[i], resolved, sizeof resolved, &start);
            if (found) fprintf(f, "%p %s+0x%llx\n", frames[i], resolved,
                               (unsigned long long)((uintptr_t)frames[i] - start));
            else fprintf(f, "%p (native guest symbol unavailable)\n", frames[i]);
            const char *s = found ? resolved : "";
#endif
            const char *p = strstr(s, "w2c_bt_");
            if (p) p += sizeof("w2c_bt_") - 1;
            if (p && names_used + strlen(p) + 2 < sizeof guest_names) {
                const char *end = strpbrk(p, " +)]"); size_t n = end ? (size_t)(end - p) : strlen(p);
                if (!strncmp(p, "func_", 5) && n >= 13) n = 13;
                memcpy(guest_names + names_used, p, n); names_used += n; guest_names[names_used++] = '\n'; guest_names[names_used] = 0;
            }
        }
#ifndef _WIN32
        free(names);
#endif
    }
    fputs("\nGuest symbol map excerpt (game.map addresses are wasm addresses):\n", f);
    map_excerpt(f, guest_names);
    fputs("\nLast captured log lines:\n", f);
    if (saved_stderr >= 0 && pthread_mutex_trylock(&log_lock) == 0) {
        unsigned first = (log_next + LOG_LINES - log_count) % LOG_LINES;
        for (unsigned i = 0; i < log_count; i++) fputs(log_ring[(first + i) % LOG_LINES], f);
        pthread_mutex_unlock(&log_lock);
    } else fputs("(log tail unavailable: capture lock was busy)\n", f);
    fprintf(f, "\nReport file: %s\n", crash_path); fclose(f);
    fprintf(stderr, "bt_native: crash report written to %s\n", crash_path);
    if (interactive) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Banjo-Tooie", crash_path, NULL);
}

#ifdef _WIN32
static size_t windows_exception_frames(EXCEPTION_POINTERS *e, void **frames, size_t capacity) {
    HANDLE process = GetCurrentProcess(), thread = GetCurrentThread();
    CONTEXT context = *e->ContextRecord;
    STACKFRAME64 frame = {0};
#if defined(_M_X64) || defined(__x86_64__) || defined(__MINGW64__)
    DWORD machine = IMAGE_FILE_MACHINE_AMD64;
    frame.AddrPC.Offset = context.Rip; frame.AddrFrame.Offset = context.Rbp; frame.AddrStack.Offset = context.Rsp;
#elif defined(_M_IX86) || defined(__i386__)
    DWORD machine = IMAGE_FILE_MACHINE_I386;
    frame.AddrPC.Offset = context.Eip; frame.AddrFrame.Offset = context.Ebp; frame.AddrStack.Offset = context.Esp;
#else
    return (size_t)CaptureStackBackTrace(0, (DWORD)capacity, frames, NULL);
#endif
    frame.AddrPC.Mode = frame.AddrFrame.Mode = frame.AddrStack.Mode = AddrModeFlat;
    if (!SymInitialize(process, NULL, TRUE))
        return (size_t)CaptureStackBackTrace(0, (DWORD)capacity, frames, NULL);
    size_t count = 0;
    while (count < capacity && StackWalk64(machine, process, thread, &frame, &context, NULL,
                                            SymFunctionTableAccess64, SymGetModuleBase64, NULL)) {
        if (!frame.AddrPC.Offset) break;
        if (!count || (uintptr_t)frames[count - 1] != (uintptr_t)frame.AddrPC.Offset)
            frames[count++] = (void *)(uintptr_t)frame.AddrPC.Offset;
    }
    SymCleanup(process);
    return count;
}

static LONG WINAPI bt_windows_fault(EXCEPTION_POINTERS *e) {
    void *frames[49];
    size_t n = windows_exception_frames(e, frames, 48);
    if (!n || (uintptr_t)frames[0] != (uintptr_t)e->ExceptionRecord->ExceptionAddress) {
        memmove(frames + 1, frames, n * sizeof frames[0]);
        frames[0] = e->ExceptionRecord->ExceptionAddress;
        n++;
    }
    char text[192]; snprintf(text, sizeof text, "exception 0x%08lx at 0x%llx",
        e->ExceptionRecord->ExceptionCode, (unsigned long long)(uintptr_t)e->ExceptionRecord->ExceptionAddress);
    bt_crash_report("Windows unhandled exception", text, (const void *const *)frames, n);
    return EXCEPTION_EXECUTE_HANDLER;
}
#endif

void bt_crash_install(void) {
#ifdef _WIN32
    SetUnhandledExceptionFilter(bt_windows_fault);
#else
    if (fault_pipe[1] >= 0) {
        struct sigaction sa = {.sa_sigaction = fault_handler, .sa_flags = SA_SIGINFO | SA_ONSTACK};
        sigemptyset(&sa.sa_mask);
        sigaction(SIGSEGV, &sa, NULL); sigaction(SIGBUS, &sa, NULL);
    }
#endif
}
