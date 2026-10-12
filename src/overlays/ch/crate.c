#include "common.h"

OSThread *chcrate_entrypoint_0(void)
{
    extern u8 D_80800410_chcrate[];

    return (OSThread *) D_80800410_chcrate;
}

OSThread *chcrate_entrypoint_1(void)
{
    extern u8 D_80800458_chcrate[];

    return (OSThread *) D_80800458_chcrate;
}

OSThread *chcrate_entrypoint_2(void)
{
    extern u8 D_808004A0_chcrate[];

    return (OSThread *) D_808004A0_chcrate;
}

/* extern */

void func_80800024_chcrate(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    s32 func_80800380_chcrate();
    s32 temp_v0;

    temp_v0 = func_80800380_chcrate();
    if ((temp_v0 != 0) && (func_800DA298(temp_v0) != 0)) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crate/func_80800064_chcrate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crate/func_80800104_chcrate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crate/chcrate_entrypoint_3.s")

s32 func_80800380_chcrate(u8 *arg0) {
    struct CrateData { u8 pad[0x76]; unsigned short index : 9; unsigned short rest : 7; };
    s32 ret = 0;
    s32 temp;

    if (((struct CrateData *)arg0)->index < 0x32) {
        temp = 0x31 - ((struct CrateData *)arg0)->index;
        ret = temp + 0xA40;
        return ret;
    }
    return ret;
}

s16 func_808003AC_chcrate(s32 arg0) {
    extern s16 D_8080053C_chcrate[];
    s32 index;

    index = arg0 - 0x32;
    if (index > 0) {
        return D_8080053C_chcrate[index];
    }
    return 0;
}
