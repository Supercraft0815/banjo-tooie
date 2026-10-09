#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800000_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_8080008C_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800128_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800338_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800584_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800698_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808006D4_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800710_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800A98_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800B28_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800D10_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801058_ncpoddialog.s")

/* extern */

void ncpoddialog_entrypoint_0(s16 arg0) {
    s32 func_8001B798(s16);
    func_8001B798(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808012A0_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801310_ncpoddialog.s")

/* extern */

void ncpoddialog_entrypoint_3(s16 arg0) {
    s32 func_8001B754(s16);
    func_8001B754(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808013C0_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801504_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808015CC_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808017F4_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_8080189C_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801A30_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801AC0_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801B98_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801DB8_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801E78_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801F88_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80802048_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_8080230C_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808023B4_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_6.s")

void ncpoddialog_entrypoint_7(void *arg0, s32 arg1) {
    if (arg1 >= 0) {
        (*(s8 *)((s8 *)(arg0) + (0x215))) = 1;
        if (arg1 == 0) {
            (*(s8 *)((s8 *)(arg0) + (0x214))) = 0;
            return;
        }
        (*(s8 *)((s8 *)(arg0) + (0x214))) = 1;
        return;
    }
    (*(s8 *)((s8 *)(arg0) + (0x215))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_9.s")

/* extern */

void ncpoddialog_entrypoint_10(s32 arg0) {
    s32 ncpoddialog_entrypoint_11(s32, u32, s32, s32);
    ncpoddialog_entrypoint_11(arg0 & 0xFFFF, (u32) (arg0 & 0xFFFF0000) >> 0x10, 1, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_11.s")
