#include "common.h"

OSThread *chhotwaterpoolbits_entrypoint_0(void)
{
    extern u8 D_80800930_chhotwaterpoolbits[];

    return (OSThread *) D_80800930_chhotwaterpoolbits;
}

OSThread *chhotwaterpoolbits_entrypoint_1(void)
{
    extern u8 D_80800978_chhotwaterpoolbits[];

    return (OSThread *) D_80800978_chhotwaterpoolbits;
}

OSThread *chhotwaterpoolbits_entrypoint_2(void)
{
    extern u8 D_808009C0_chhotwaterpoolbits[];

    return (OSThread *) D_808009C0_chhotwaterpoolbits;
}

OSThread *chhotwaterpoolbits_entrypoint_3(void)
{
    extern u8 D_80800A08_chhotwaterpoolbits[];

    return (OSThread *) D_80800A08_chhotwaterpoolbits;
}

/* extern */

void func_80800030_chhotwaterpoolbits(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    s32 sp1C;

    sp1C = _chswitch_entrypoint_7(arg0, 0x167);
    _chswitch_entrypoint_8(arg0, 0x200);
    if (sp1C != 0) {
        _chswitch_entrypoint_9(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_80800078_chhotwaterpoolbits.s")

/* extern */

void func_80800124_chhotwaterpoolbits(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 300.0f, 0x60, 0x167) != 0) {
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_6(arg0, 0x3E19999A);
        _chdoormake_entrypoint_9(arg0, 0, 0xD, 0x10);
        _chdoormake_entrypoint_8(arg0, 0xD);
    }
}

/* extern */

s32 func_808001A8_chhotwaterpoolbits(s32 arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_14();
    s32 _chdoor_entrypoint_1(s32);
    s32 _glcutDll_entrypoint_6(s32, s32);
    s32 func_800FFAB0(s32);
    if ((arg1 == 0xB) && (arg2 == 0xD)) {
        _capod_entrypoint_14();
        _glcutDll_entrypoint_6(0x1A7, 0x29);
        func_800FFAB0(arg0);
        return 4;
    }
    return _chdoor_entrypoint_1(arg0);
}

void func_80800204_chhotwaterpoolbits(u8 *arg0) {
    s32 func_800F2E60(s32, s32 *, u8 *);
    extern s32 D_80800A50_chhotwaterpoolbits;
    func_800F2E60(arg0 + 0x28, &D_80800A50_chhotwaterpoolbits, arg0);
    (*(f32 *)((s8 *)(arg0) + (0x1C))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 127.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_8080024C_chhotwaterpoolbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_808003E0_chhotwaterpoolbits.s")

void func_80800528_chhotwaterpoolbits(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_800BEA88(s32);
    extern s32 _chhotwaterpoolbits_entrypoint_4;
    s32 temp_v0;

    temp_v0 = func_800BEA88(1);
    if (temp_v0 != 0) {
        _glid_entrypoint_0(temp_v0, 0xA, &_chhotwaterpoolbits_entrypoint_4, *arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/chhotwaterpoolbits_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_808006BC_chhotwaterpoolbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_80800718_chhotwaterpoolbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/chhotwaterpoolbits_entrypoint_5.s")
