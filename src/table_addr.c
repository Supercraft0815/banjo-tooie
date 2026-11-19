#include <ultra64.h>

extern u8 overlay_table_compressed_ROM_START[];

/* The overlay loader reads the first word from cartridge offset 0x50E0. */
struct {
    const u8 *compressed_overlay_table;
    u32 reserved[3];
} D_00000000 = {overlay_table_compressed_ROM_START, {0, 0, 0}};
