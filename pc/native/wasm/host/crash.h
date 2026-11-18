#ifndef BT_HOST_CRASH_H
#define BT_HOST_CRASH_H

#include <stddef.h>
#include <stdint.h>

void bt_crash_init(const char *version, const char *map_path, const char *native_map_path);
void bt_crash_report(const char *kind, const char *detail, const void *const *frames, size_t count);
int bt_crash_capture(void **frames, int capacity);
void bt_crash_install(void);
void bt_crash_map_update(uint16_t map_id);
uint16_t bt_crash_current_map(void);
void bt_crash_test_guest_entry(void);

#endif
