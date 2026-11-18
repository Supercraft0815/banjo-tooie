// Guest and native CPU access to an image owned by the GPU. Pages are only
// a fast rejection filter. The slow path checks exact overlapping byte ranges.
#ifndef BT_HOST_IMAGE_MEMORY_H
#define BT_HOST_IMAGE_MEMORY_H
#include <stdint.h>
#ifdef BT_IMAGE_ACCESS_HOST
extern unsigned char bt_image_pages[4096];
void bt_image_access(uint64_t address, uint64_t bytes);
static inline void bt_image_scalar(uint64_t address, unsigned bytes) {
    if ((address >> 24) == 0x80 && __atomic_load_n(&bt_image_pages[(address >> 12) & 4095], __ATOMIC_RELAXED))
        bt_image_access(address, bytes);
}
static inline void bt_image_range(uint64_t address, uint64_t bytes) {
    if (!bytes || address >= 0x81000000ull || address + bytes <= 0x80000000ull) return;
    if (bytes <= 4096 && address >= 0x80000000ull) {
        bt_image_scalar(address, (unsigned)bytes);
        return;
    }
    bt_image_access(address, bytes);
}
#else
#define bt_image_scalar(address, bytes) ((void)0)
#define bt_image_range(address, bytes) ((void)0)
#endif
#endif
