#include "common.h"

OSThread *chhotwatersteam_entrypoint_0(void)
{
    extern u8 D_80800240_chhotwatersteam[];

    return (OSThread *) D_80800240_chhotwatersteam;
}

/* extern */

void func_8080000C_chhotwatersteam(s32 *arg0) {
    s32 func_800FFA88(s32);
    s32 func_808001E8_chhotwatersteam();
    if (func_808001E8_chhotwatersteam() == 0) {
        func_800FFA88(*arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/watersteam/func_8080003C_chhotwatersteam.s")

s32 func_808000C4_chhotwatersteam(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/watersteam/func_808000D8_chhotwatersteam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/watersteam/func_8080014C_chhotwatersteam.s")

/* extern */

s32 func_808001E8_chhotwatersteam(void *arg0) {
    s32 func_800DA298(s32);
    if (((u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7) == 0x33) {
        return func_800DA298(0x31B) == 0;
    } else {
        return 1;
    }
}
