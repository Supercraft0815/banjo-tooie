#include "common.h"

OSThread *chsignpost_entrypoint_0(void)
{
    extern u8 D_808002E0_chsignpost[];

    return (OSThread *) D_808002E0_chsignpost;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/signpost/func_8080000C_chsignpost.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/signpost/func_80800058_chsignpost.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/signpost/func_8080019C_chsignpost.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/signpost/func_80800230_chsignpost.s")

void func_80800264_chsignpost(s32 arg0, s32 arg1, s32 arg2) {
}
/* extern */

s32 func_80800274_chsignpost(u8 *arg0) {
    s32 _subaddiedialog_entrypoint_11(s32, s32, s32, u8 *, s32);
    s32 func_800D3E40(s32, s32);
    s32 sp20;
    s32 var_a1;

    var_a1 = (*(s32 *)((s8 *)(arg0) + (0x28))) + 0x1686;
    if ((var_a1 >= 0x16B7) && (var_a1 < 0x16BF)) {
        sp20 = var_a1;
        if (func_800D3E40(6, var_a1) == 0) {
            var_a1 = 0x16BF;
        }
    }
    _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(arg0) + (0))), var_a1, 0xF, arg0 + 4, 0x28);
    return 1;
}
