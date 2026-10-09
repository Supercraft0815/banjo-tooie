#include "common.h"

OSThread *chboggykidshome_entrypoint_0(void)
{
    extern u8 D_80800468_chboggykidshome[];

    return (OSThread *) D_80800468_chboggykidshome;
}

OSThread *chboggykidshome_entrypoint_1(void)
{
    extern u8 D_808004B0_chboggykidshome[];

    return (OSThread *) D_808004B0_chboggykidshome;
}

OSThread *chboggykidshome_entrypoint_2(void)
{
    extern u8 D_808004F8_chboggykidshome[];

    return (OSThread *) D_808004F8_chboggykidshome;
}

/* extern */

void func_80800024_chboggykidshome(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    if ((func_800DA298(0x1CD) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/kidshome/func_80800068_chboggykidshome.s")

void func_808000DC_chboggykidshome(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/kidshome/func_808000FC_chboggykidshome.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/kidshome/func_80800214_chboggykidshome.s")

s32 func_808002C0_chboggykidshome(void *arg0) {
    u32 temp_v0;

    temp_v0 = (u32) ((*(s32 *)((s8 *)(arg0) + (0x6C))) << 0xB) >> 0x14;
    if (temp_v0 == 0x41D) {
        return 0x3B;
    }
    if (temp_v0 == 0x3E4) {
        return 0x3C;
    }
    return 0x3D;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/kidshome/func_80800300_chboggykidshome.s")
