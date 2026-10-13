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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/lightsDll/gclightsDll_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/lightsDll/gclightsDll_entrypoint_4.s")

/* extern */

void gclightsDll_entrypoint_5(f32 *arg0) {
    s32 func_800C911C();
    s32 func_800EE830(s32, f32 *);
    func_800EE830(func_800C911C() + 0x10, arg0);
}
