#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoomboxdata/gczoomboxdata_entrypoint_0.s")

u16 gczoomboxdata_entrypoint_1(s32 arg0) {
    extern u8 D_80800AA8_gczoomboxdata[];
    return *(u16 *)(D_80800AA8_gczoomboxdata + arg0 * 0xC);
}

void gczoomboxdata_entrypoint_2(s32 arg0, s8 *arg1, s8 *arg2) {
    extern u8 D_80800AA8_gczoomboxdata[];
    typedef struct {
        u16 unk0;
        s8 unk2;
        s8 unk3;
        u8 padding[8];
    } Entry;
    Entry *entry;

    entry = &((Entry *)D_80800AA8_gczoomboxdata)[arg0];
    *arg1 = entry->unk2;
    *arg2 = entry->unk3;
}

u8 gczoomboxdata_entrypoint_3(s32 arg0) {
    extern u8 D_80800AB0_gczoomboxdata[];
    return D_80800AB0_gczoomboxdata[(arg0 * 3) * 4];
}

void gczoomboxdata_entrypoint_4(s32 arg0, s32 arg1, s16 *arg2, s16 *arg3, f32 *arg4) {
    extern u8 D_80800AA8_gczoomboxdata[];
    u8 *entry;
    entry = D_80800AA8_gczoomboxdata + arg0 * 0xC;
    *arg2 = *(s16 *)(*(s32 *)(entry + 4) + arg1 * 8);
    *arg3 = *(s16 *)(*(s32 *)(entry + 4) + arg1 * 8 + 2);
    *arg4 = *(f32 *)(*(s32 *)(entry + 4) + arg1 * 8 + 4);
}

s32 gczoomboxdata_entrypoint_5(register s32 arg0) {
    s32 func_800D58FC(s32 arg0);
    extern u8 D_80800AA8_gczoomboxdata[];
    union { struct { u16 pad; u16 value; } write; struct { u16 pad; volatile u16 value; } read; } saved;
    u16 asset;
    s32 flag;

    if (arg0 == 0x44) {
        return 0;
    }
    arg0 *= 0xC;
    asset = *(u16 *)(D_80800AA8_gczoomboxdata + arg0);
    if (asset == 0 || (saved.write.value = asset, flag = func_800D58FC(asset), asset = saved.read.value, flag == 4)) {
        return 0;
    }
    return asset;
}

/* extern */

s32 gczoomboxdata_entrypoint_6(void) {
    s32 gczoomboxdata_entrypoint_5();
    s32 temp_v0;

    temp_v0 = gczoomboxdata_entrypoint_5();
    if ((temp_v0 == 0) || (temp_v0 == 0xBAE)) {
        return 0;
    }
    return 1;
}
