#include "common.h"

s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);

OSThread *chstatuebossbits_entrypoint_0(void)
{
    extern u8 D_808006F0_chstatuebossbits[];

    return (OSThread *) D_808006F0_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_1(void)
{
    extern u8 D_80800738_chstatuebossbits[];

    return (OSThread *) D_80800738_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_2(void)
{
    extern u8 D_80800780_chstatuebossbits[];

    return (OSThread *) D_80800780_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_3(void)
{
    extern u8 D_808007C8_chstatuebossbits[];

    return (OSThread *) D_808007C8_chstatuebossbits;
}

void func_80800030_chstatuebossbits(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_80800038_chstatuebossbits.s")

/* extern */

s32 func_80800224_chstatuebossbits(s32 *arg0, s32 arg1, s32 arg2) {
    s32 func_800FFA88(s32);
    void func_80800270_chstatuebossbits(Actor *);
    s32 ret;
    if (arg1 == 0x40) {
        func_80800270_chstatuebossbits((Actor *) arg0);
        func_800FFA88(*arg0);
        ret = 1;
    } else {
        return 0;
    }
    return ret;
}

void func_80800270_chstatuebossbits(Actor *arg0) {
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80800810_chstatuebossbits;
    extern s32 D_8080084C_chstatuebossbits;
    (void)&arg0;
    func_800BBCB8(arg0->position, 0, arg0->scale, 2, &D_80800810_chstatuebossbits);
    func_8010D930(4, -1, arg0->position, &D_8080084C_chstatuebossbits);
}

/* extern */

void func_808002CC_chstatuebossbits(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80101FDC(Actor *, u32);
    void func_8010A590(Actor *);
    s32 sp24;

    sp24 = func_800DA298(0x88);
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    *(s32 *)&arg0->unk54 = 0;
    ((f32 *)arg0->actorData)[5] -= 180.0f;
    if (sp24 != 0) {
        func_80101FDC(arg0, 1);
        func_8010A590(arg0);
        return;
    }
    arg0->position[1] = ((f32 *)arg0->actorData)[5];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_80800360_chstatuebossbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_8080040C_chstatuebossbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_808004D8_chstatuebossbits.s")

void func_80800604_chstatuebossbits(s32 arg0, s32 arg1) {
    s32 func_800EC398(s32, f32 *);
    extern s32 D_80800864_chstatuebossbits;
    f32 sp24[3];

    func_800EC398(arg1, sp24);
    func_800BBCB8(sp24, sp24, 1.0f, 4, &D_80800864_chstatuebossbits);
}

/* extern */

void func_8080064C_chstatuebossbits(s32 arg0) {
    s32 _chdoormake_entrypoint_3(s32, f32, f32, f32, s32, s32);
    s32 _chdoormake_entrypoint_5(s32, f32);
    s32 _chdoormake_entrypoint_8(s32, s32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    s32 var_v1;

    var_v1 = func_800DA298(0x88) != 0;
    if (var_v1 == 0) {
        var_v1 = _glcutDll_entrypoint_20() != 0;
    }
    if (var_v1 != 0) {
        func_80101FDC(arg0, 1);
    }
    _chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 180.0f, 0x102, -1);
    _chdoormake_entrypoint_5(arg0, 2.0f);
    _chdoormake_entrypoint_8(arg0, 0xD);
}
