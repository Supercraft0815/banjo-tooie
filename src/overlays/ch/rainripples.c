#include "common.h"

OSThread *chrainripples_entrypoint_0(void)
{
    extern u8 D_80800290_chrainripples[];

    return (OSThread *) D_80800290_chrainripples;
}

/* extern */

void func_8080000C_chrainripples(void *arg0) {
    f32 func_808001FC_chrainripples();
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (func_808001FC_chrainripples() + 4.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainripples/func_80800040_chrainripples.s")

/* extern */

f32 func_808001FC_chrainripples(f32 *arg0) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp34, arg0 + 1);
    func_800EE7F8(sp28, arg0 + 1);
    sp34[1] += 100.0f;
    sp28[1] -= 100.0f;
    if (func_800BEF00(sp34, sp28, sp1C, 0x1F00) != 0) {
        return sp28[1];
    }
    return arg0[2];
}
