#include "ch/factory/roofbits.h"

/* extern */

void func_80800000_chfactoryroofbits(s32 arg0) {
    s32 func_800EFA4C(s32, s32, s32, s32);
    func_800EFA4C(arg0 + 4, 0xC48C8000, 0x460CA800, 0x44C78000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/roofbits/func_8080003C_chfactoryroofbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/roofbits/func_808000D4_chfactoryroofbits.s")

OSThread *chfactoryroofbits_entrypoint_0(void)
{
    extern u8 D_80800974_chfactoryroofbits[];

    return (OSThread *) D_80800974_chfactoryroofbits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/roofbits/func_8080015C_chfactoryroofbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/roofbits/func_808001C0_chfactoryroofbits.s")

/* extern */

void func_808003C4_chfactoryroofbits(u8 *arg0) {
    s32 func_800FFA88(s32);
    s32 func_808001C0_chfactoryroofbits(u32, u8 *, u8 *, u8 *);
    if (func_808001C0_chfactoryroofbits((u32) (*(u32 *)((s8 *)(arg0) + (0x6C))) >> 0x15, arg0 + 4, arg0 + 0x28, arg0 + 0x44) != 0) {
        func_800FFA88((*(s32 *)((s8 *)(arg0) + (0))));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/roofbits/func_80800414_chfactoryroofbits.s")

/* extern */

void func_808005DC_chfactoryroofbits(void *arg0, s32 arg1) {
    s32 func_800DF500(f32, f32, s32);
    s32 func_80101870(void *, s32);
    func_800DF500((*(f32 *)((s8 *)(arg0) + (0x28))), (*(f32 *)((s8 *)(arg0) + (0x2C))), (*(s32 *)((s8 *)(arg0) + (0x30))));
    func_80101870(arg0, arg1);
}

OSThread *chfactoryroofbits_entrypoint_1(void)
{
    extern u8 D_80800A08_chfactoryroofbits[];

    return (OSThread *) D_80800A08_chfactoryroofbits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/roofbits/func_80800624_chfactoryroofbits.s")

OSThread *chfactoryroofbits_entrypoint_2(void)
{
    extern u8 D_80800A50_chfactoryroofbits[];

    return (OSThread *) D_80800A50_chfactoryroofbits;
}

void func_808006E8_chfactoryroofbits(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_A08_UNK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/roofbits/func_80800708_chfactoryroofbits.s")

OSThread *chfactoryroofbits_entrypoint_3(void)
{
    extern u8 D_80800AA4_chfactoryroofbits[];

    return (OSThread *) D_80800AA4_chfactoryroofbits;
}

void func_808007B8_chfactoryroofbits(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_163_STATION_UNLOCKED_GI);
    _chswitch_entrypoint_9(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/roofbits/func_808007E4_chfactoryroofbits.s")

OSThread *chfactoryroofbits_entrypoint_4(void)
{
    extern u8 D_80800AEC_chfactoryroofbits[];

    return (OSThread *) D_80800AEC_chfactoryroofbits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/roofbits/func_80800840_chfactoryroofbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/roofbits/func_80800890_chfactoryroofbits.s")

OSThread *chfactoryroofbits_entrypoint_5(void)
{
    extern u8 D_80800B34_chfactoryroofbits[];

    return (OSThread *) D_80800B34_chfactoryroofbits;
}
