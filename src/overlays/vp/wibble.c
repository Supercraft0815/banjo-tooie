#include "common.h"

s32 *func_80800000_vpwibble(s32 arg0) {
    struct WibbleEntry {
        s32 words[3];
        s16 unkC;
        s16 id;
    };
    extern struct WibbleEntry D_80800700_vpwibble[];
    struct WibbleEntry *temp_v1;
    s32 i;

    arg0 -= arg0 % 100;
    for (i = 0; i < 6; i++) {
        temp_v1 = &D_80800700_vpwibble[i];
        if (arg0 == temp_v1->id) {
            return temp_v1->words;
        }
    }
    return D_80800700_vpwibble[0].words;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/wibble/func_808000B0_vpwibble.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/wibble/vpwibble_entrypoint_0.s")

void vpwibble_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
/* extern */

void vpwibble_entrypoint_2(u8 *arg0, u8 *arg1) {
    f32 func_800D8FF8(void);
    s32 i;
    s16 *indices;
    u8 *base;
    f32 delta;

    delta = func_800D8FF8();
    i = 0;
    *(f32 *)(arg0 + 0x24) += delta * *(f32 *)(arg0 + 0x2C);
    base = arg1;
    base += *(s32 *)(arg1 + 0x1C);
    if (*(s32 *)(arg0 + 0x34) > 0) {
        indices = (s16 *)(arg0 + 0x38);
        do {
            i++;
            (base + *indices++ * 0x14)[3] = 1;
        } while (i < *(s32 *)(arg0 + 0x34));
    }
}

/* extern */

f32 func_808003F0_vpwibble(void *arg0, void *arg1, void *arg2) {
    f32 func_800136D0(f32);
    f32 func_80013788(f32);
    f32 func_800137D4(f32);
    f32 func_800EEF94(f32 *);
    f32 sp3C;
    f32 temp_f12;
    f32 vec[4];
    f32 temp_f0_2;
    f32 temp_f2;

    vec[0] = (f32) (*(s16 *)((s8 *)(arg1) + (0)));
    vec[1] = (f32) (*(s16 *)((s8 *)(arg1) + (2)));
    vec[2] = (f32) (*(s16 *)((s8 *)(arg1) + (4)));
    sp3C = func_800EEF94(vec);
    temp_f12 = (sp3C - (*(f32 *)((s8 *)(arg0) + (0x24)))) * (*(f32 *)((s8 *)(arg0) + (0x28)));
    temp_f12 = func_800136D0(temp_f12);
    temp_f12 = func_800137D4(temp_f12);
    temp_f12 *= (f32) (*(s16 *)((s8 *)(arg0) + (0x1A)));
    if ((*(u8 *)((s8 *)(arg0) + (0x33))) != 0) {
        temp_f2 = (*(f32 *)((s8 *)(arg0) + (0x28))) * ((f32) (*(s16 *)((s8 *)(arg0) + (0x1A))) * func_80013788(temp_f12));
        if (sp3C > 0.0001f) {
            temp_f0_2 = temp_f2 / sp3C;
            (*(f32 *)((s8 *)(arg2) + (0))) = (f32) (vec[0] * temp_f0_2);
            (*(f32 *)((s8 *)(arg2) + (4))) = (f32) (vec[2] * temp_f0_2);
        } else {
            (*(f32 *)((s8 *)(arg2) + (0))) = (f32) (vec[0] * temp_f2);
            (*(f32 *)((s8 *)(arg2) + (4))) = (f32) (vec[2] * temp_f2);
        }
    }
    return temp_f12;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/wibble/vpwibble_entrypoint_3.s")
