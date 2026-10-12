#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/func_80800000_sulights.s")

void func_808000D0_sulights(s8 *arg0) {
    arg0[0] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/func_808000D8_sulights.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/func_80800194_sulights.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/func_8080021C_sulights.s")

void func_80800340_sulights(u8 *arg0) {
    s32 i;
    s32 *p;
    s32 value;
    i = 0;
    p = (s32 *)arg0;
    *(f32 *)(arg0 + 0x34) = 0.0f;
    do {
        value = p[4];
        i++;
        p++;
        p[0] += value;
        p[3] = value * -1;
    } while (i != 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/func_8080038C_sulights.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/sulights_entrypoint_0.s")

/* extern */

void sulights_entrypoint_1(s32 arg0, s32 arg1, s32 arg2) {
    void func_800C8900(s32, u8 *);
    s32 sulights_entrypoint_0(s32, s32 *, s32, s32);
    s32 sp1C[3];

    func_800C8900(arg0, (u8 *) sp1C);
    sulights_entrypoint_0(arg0, sp1C, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/sulights_entrypoint_2.s")

/* extern */

void sulights_entrypoint_3(s32 arg0, s32 arg1, s32 arg2) {
    void func_800C883C(s32 arg0, void *arg1);
    s32 sulights_entrypoint_2(s32, s32 *, s32, s32);
    s32 sp18[2];

    func_800C883C(arg0, &sp18);
    sulights_entrypoint_2(arg0, &sp18, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/sulights_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/sulights_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/sulights_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/lights/sulights_entrypoint_7.s")

void sulights_entrypoint_8(void) {
    s32 vector_free(s32);
    extern s32 D_80127EF0;
    if (D_80127EF0 != 0) {
        vector_free(D_80127EF0);
        D_80127EF0 = 0;
    }
}

void sulights_entrypoint_9(void) {
    f32 func_800D8FF8();
    u32 vector_begin(s32);
    u32 vector_end(s32);
    extern s32 D_80127EF0;
    typedef struct {
        s32 (*update)(u32);
        s32 (*finish)(u32);
    } LightCallbacks;
    extern LightCallbacks D_80800A00_sulights[];
    s32 (*temp_v0_2)(u32);
    f32 temp_f0;
    f32 temp_f20;
    u32 temp_s2;
    u32 temp_v0;
    u32 var_s0;

    temp_f20 = func_800D8FF8();
    temp_s2 = vector_end(D_80127EF0);
    temp_v0 = vector_begin(D_80127EF0);
    var_s0 = temp_v0;
    if (temp_v0 < temp_s2) {
        do {
            if ((*(u8 *)((s8 *)(var_s0) + (0))) != 0) {
                temp_f0 = (*(f32 *)((s8 *)(var_s0) + (0x38)));
                (*(f32 *)((s8 *)(var_s0) + (0x34))) = (f32) ((*(f32 *)((s8 *)(var_s0) + (0x34))) + temp_f20);
                if (temp_f0 < (*(f32 *)((s8 *)(var_s0) + (0x34)))) {
                    (*(f32 *)((s8 *)(var_s0) + (0x34))) = temp_f0;
                }
                D_80800A00_sulights[*(u8 *)var_s0 - 1].update(var_s0);
                if ((*(f32 *)((s8 *)(var_s0) + (0x38))) <= (*(f32 *)((s8 *)(var_s0) + (0x34)))) {
                    temp_v0_2 = D_80800A00_sulights[*(u8 *)var_s0 - 1].finish;
                    if (temp_v0_2 != NULL) {
                        temp_v0_2(var_s0);
                    }
                }
            }
            var_s0 += 0x3C;
        } while (var_s0 < temp_s2);
    }
}
