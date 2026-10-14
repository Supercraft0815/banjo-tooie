#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/usefeather/func_80800000_chusefeather.s")

void chusefeather_entrypoint_0(s32 arg0, s32 arg1) {
    f32 func_800DC0C0(void);
    void func_800F5A00(s32, f32 *);
    f32 func_800F5F24(u32);
    void func_80102FDC(Actor *, f32);
    Actor *func_80108474(u32, f32 *, s32);
    Actor *sp2C;
    f32 sp20[3];
    s32 var_v0;
    f32 sp18;

    func_800F5A00(arg0, sp20);
    sp18 = func_800F5F24(arg0);
    var_v0 = (func_800DC0C0() > 0.5f) ? 0x1E : -0x1E;
    sp2C = func_80108474(arg1, sp20, (s32) (var_v0 + sp18));
    func_80102FDC(sp2C, 0.45f);
    ((f32 *)sp2C->actorData)[3] = 22.0f;
    ((f32 *)sp2C->actorData)[1] = 48.0f;
    sp2C->unk58 = 1.2f;
}

void chusefeather_entrypoint_1(s32 arg0, s32 arg1) {
    s32 _chbaddiesetup_entrypoint_2(s32 *, s32, s32);
    s32 func_800D3948();
    extern s32 _chusefeather_entrypoint_0;
    s32 var_a2;

    if (func_800D3948() == 0) {
        if (arg1 == 0) {
            var_a2 = 0x26A;
        } else {
            var_a2 = 0x26B;
        }
        _chbaddiesetup_entrypoint_2(&_chusefeather_entrypoint_0, arg0, var_a2);
    }
}

OSThread *chusefeather_entrypoint_2(void)
{
    extern u8 D_80800364_chusefeather[];

    return (OSThread *) D_80800364_chusefeather;
}

OSThread *chusefeather_entrypoint_3(void)
{
    extern u8 D_808003AC_chusefeather[];

    return (OSThread *) D_808003AC_chusefeather;
}
