#include "common.h"
struct Vector;
void vector_free(struct Vector *vec);
void gclightsDll_entrypoint_1();

void func_80800000_gclightsDll(s32 arg0)
{
    gclightsDll_entrypoint_1();
    _gclightsDll_entrypoint_0(arg0);
}
void gclightsDll_entrypoint_0(struct Vector **arg0) {
    void gclightsDll_entrypoint_5(f32 *);
    extern f32 D_80800560_gclightsDll[3];
    extern f32 D_8080056C_gclightsDll[3];
    extern f32 D_80800578_gclightsDll[3];
    *arg0 = vector_new(0x1C, 1);
    func_800C8C90((s32) D_80800560_gclightsDll);
    gclightsDll_entrypoint_5(D_8080056C_gclightsDll);
    func_800C8F08((s32) D_8080056C_gclightsDll, D_80800578_gclightsDll);
}

void gclightsDll_entrypoint_1(struct Vector **arg0) {
    vector_free(*arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/lightsDll/gclightsDll_entrypoint_2.s")

/* extern */

s32 gclightsDll_entrypoint_3(s32 *arg0, f32 *arg1) {
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEAD4(f32 *, f32 *);
    u32 vector_begin(s32);
    u32 vector_end(s32);
    u32 sp5C;
    f32 temp_f0;
    f32 var_f20;
    s32 var_v1;
    u32 temp_v0;
    u32 var_s0;
    f32 sp3C[3];
    u32 var_s2;

    sp5C = vector_begin(*arg0);
    temp_v0 = vector_end(*arg0);
    var_s0 = sp5C;
    var_f20 = -1.0f;
    var_s2 = 0;
    if (var_s0 < temp_v0) {
        do {
            if (((*(u8 *)((s8 *)(var_s0) + (0x15))) != 0) && ((*(u8 *)((s8 *)(var_s0) + (0x14))) != 0) && ((*(u8 *)((s8 *)(var_s0) + (0x17))) != 0) && ((func_800EE88C(sp3C, (s16 *) var_s0), temp_f0 = func_800EEAD4(arg1, sp3C), (var_s2 == 0)) || (temp_f0 < var_f20))) {
                var_s2 = var_s0;
                var_f20 = temp_f0;
            }
            var_s0 += 0x1C;
        } while (var_s0 < temp_v0);
    }
    if (var_s2 != 0) {
        var_v1 = (s32) ((var_s2 - sp5C) + 0x1C) / 28;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/lightsDll/gclightsDll_entrypoint_4.s")

/* extern */

void gclightsDll_entrypoint_5(f32 *arg0) {
    s32 func_800C911C();
    s32 func_800EE830(s32, f32 *);
    func_800EE830(func_800C911C() + 0x10, arg0);
}
