#include "ch/factory/entrydoors.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/entrydoors/func_80800000_chfactoryentrydoors.s")

/* extern */

void func_808000CC_chfactoryentrydoors(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    s32 var_v0;

    if (arg1 == 0x95) {
        var_v0 = (arg0->unk74_7 == 0x33) ? 0x971 : 0x972;
        func_80103140(arg0, var_v0 & 0xFFFF, arg0->unk0->unk16);
    }
    _chdoor_entrypoint_1((s32)arg0, arg1, arg2);
}

OSThread *chfactoryentrydoors_entrypoint_0(void)
{
    extern u8 D_808002B0_chfactoryentrydoors[];

    return (OSThread *) D_808002B0_chfactoryentrydoors;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/entrydoors/func_8080014C_chfactoryentrydoors.s")

/* extern */

void func_808001A0_chfactoryentrydoors(u8 *arg0) {
    s32 func_800D90A4(s32);
    s32 func_800FFAB0(u8 *);
    s32 func_80101180(s32, s32, s32);
    if (func_800D90A4(arg0 + 0x58) != 0) {
        func_80101180(0x48B, 7, (s32) (*(f32 *)((s8 *)(arg0) + (0x34))));
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/entrydoors/func_808001F0_chfactoryentrydoors.s")

OSThread *chfactoryentrydoors_entrypoint_1(void)
{
    extern u8 D_808003A0_chfactoryentrydoors[];

    return (OSThread *) D_808003A0_chfactoryentrydoors;
}
