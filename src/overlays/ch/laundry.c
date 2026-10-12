#include "common.h"

OSThread *chlaundry_entrypoint_0(void)
{
    extern u8 D_80800400_chlaundry[];

    return (OSThread *) D_80800400_chlaundry;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/laundry/func_8080000C_chlaundry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/laundry/func_80800058_chlaundry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/laundry/func_80800218_chlaundry.s")

s32 func_80800288_chlaundry(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/laundry/chlaundry_entrypoint_1.s")

void func_808003A0_chlaundry(u8 *volatile arg0) { s32 func_8010D930(s32, s32, f32 *, s32 *); extern s32 D_8080048C_chlaundry; u8 *sp1C; sp1C = arg0 + 4; func_8010D930(0, -1, (f32 *)sp1C, &D_8080048C_chlaundry); _fxsparkle_entrypoint_1((s32)sp1C, 0xD); }
