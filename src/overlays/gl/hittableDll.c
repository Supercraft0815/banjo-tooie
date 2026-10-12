#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/hittableDll/glhittableDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/hittableDll/glhittableDll_entrypoint_1.s")

int glhittableDll_entrypoint_2(s32 arg0) {
    return ((arg0 + 1) != 0) && ((arg0 + 2) != 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/hittableDll/glhittableDll_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/hittableDll/glhittableDll_entrypoint_4.s")

typedef struct {
    u16 header[2];
    u16 entries[32];
} HitTable;
extern HitTable D_80800530_glhittableDll[];

s32 glhittableDll_entrypoint_5(s32 arg0) {
    HitTable *table;
    u16 *entry;

    table = &D_80800530_glhittableDll[(arg0 >> 16) & 0xFFFF];
    entry = &table->entries[arg0 & 0xFFFF];
    return ((u32)table->header[1] >> 12) | ((u32)*entry >> 12);
}

s32 glhittableDll_entrypoint_6(s32 arg0) {
    HitTable *table;

    table = &D_80800530_glhittableDll[(arg0 >> 16) & 0xFFFF];
    return ((u32)(table->header[1] << 20) >> 30) |
           ((u32)(table->entries[arg0 & 0xFFFF] << 20) >> 30);
}

s32 glhittableDll_entrypoint_7(s32 arg0) {
    HitTable *table;

    table = &D_80800530_glhittableDll[(arg0 >> 16) & 0xFFFF];
    return ((u32)(table->header[1] << 22) >> 29) |
           ((u32)(table->entries[arg0 & 0xFFFF] << 22) >> 29);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/hittableDll/glhittableDll_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/hittableDll/glhittableDll_entrypoint_9.s")

s32 glhittableDll_entrypoint_10(s32 arg0) {
    HitTable *table;

    table = &D_80800530_glhittableDll[(arg0 >> 16) & 0xFFFF];
    return (table->header[1] & 3) |
           (table->entries[arg0 & 0xFFFF] & 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/hittableDll/func_80800444_glhittableDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/hittableDll/func_808004D8_glhittableDll.s")
