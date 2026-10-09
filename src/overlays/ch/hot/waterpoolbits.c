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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_80800030_chhotwaterpoolbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_80800078_chhotwaterpoolbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_80800124_chhotwaterpoolbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_808001A8_chhotwaterpoolbits.s")

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
