#include "common.h"

OSThread *chtalontorpedoboulder_entrypoint_0(void)
{
    extern u8 D_808002B4_chtalontorpedoboulder[];

    return (OSThread *) D_808002B4_chtalontorpedoboulder;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/talontorpedoboulder/func_8080000C_chtalontorpedoboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/talontorpedoboulder/func_80800070_chtalontorpedoboulder.s")

/* extern */

void func_80800194_chtalontorpedoboulder(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(2, 1);
    func_80101870(arg0, arg1);
}

s32 func_808001CC_chtalontorpedoboulder(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = ((u32) *(u16 *)(arg0 + 0x76) >> 7) - 0x32;
    if ((temp_v1 < 0) || (temp_v1 >= 5)) {
        return 0;
    }
    return temp_v1 + 0x3EF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/talontorpedoboulder/func_808001F8_chtalontorpedoboulder.s")
