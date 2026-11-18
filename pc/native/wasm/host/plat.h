#ifndef BT_HOST_PLAT_H
#define BT_HOST_PLAT_H

#include <stdlib.h>
#include <stdio.h>

const char *bt_path_env(const char *name);
FILE *bt_disk_open(const char *path, const char *mode);

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
// Keep getenv() and settings.ini overrides in the same C runtime environment.
static inline int bt_setenv(const char *name, const char *value, int overwrite) {
    if (!overwrite && getenv(name)) return 0;
    return _putenv_s(name, value);
}
#define bt_unsetenv(name) _putenv_s(name, "")
static inline long bt_cpu_count(void) { return (long)GetActiveProcessorCount(ALL_PROCESSOR_GROUPS); }
static inline int bt_guard_low_memory(void *base) {
    DWORD old;
    return VirtualProtect(base, 0x80000000u, PAGE_NOACCESS, &old) != 0;
}
#else
#include <sys/mman.h>
#include <unistd.h>
#define bt_setenv setenv
#define bt_unsetenv unsetenv
static inline long bt_cpu_count(void) { return sysconf(_SC_NPROCESSORS_ONLN); }
static inline int bt_guard_low_memory(void *base) { return mprotect(base, 0x80000000u, PROT_NONE) == 0; }
#endif

#endif
