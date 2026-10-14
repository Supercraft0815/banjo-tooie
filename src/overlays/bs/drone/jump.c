#include "common.h"

/* extern */

void bsdronejump_entrypoint_0(void *arg0, void *arg1, f32 arg2) {
    f32 _bamovegoto_entrypoint_3();
    f32 func_80013970(f32);
    void func_8008C990(void *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 pad[1];
    f32 sp20;
    f32 new_var;

    func_8008C990(arg0, func_800F10B4(arg2, 0.0f, 1.0f, *(f32 *)((s8 *)arg0 + 0x190), *(f32 *)((s8 *)arg0 + 0x194)));
    sp20 = _bamovegoto_entrypoint_3(arg0);
    new_var = func_80013970(arg2 * 180.0f) * sp20 * 0.5f;
    (*(f32 *)((s8 *)(arg1) + (4))) += new_var;
}

void bsdronejump_entrypoint_1(s32 arg0)
{
    func_800961A0(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/jump/bsdronejump_entrypoint_2.s")

void bsdronejump_entrypoint_3()
{
    func_80099AA8();
}

/* extern */

void bsdronejump_entrypoint_4(s32 arg0) {
    s32 _badata_entrypoint_34(s32);
    s32 bs_setState(s32, s32);
    s32 _bamovegoto_entrypoint_4();
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_bamovegoto_entrypoint_4() != 0) {
        var_a1 = _badata_entrypoint_34(arg0);
    }
    bs_setState(arg0, var_a1);
}
