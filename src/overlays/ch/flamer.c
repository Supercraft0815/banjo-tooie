#include "common.h"

OSThread *chflamer_entrypoint_0(void)
{
    extern u8 D_80800B20_chflamer[];

    return (OSThread *) D_80800B20_chflamer;
}

/* extern */

void func_8080000C_chflamer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_800BF8E4();
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    (*(s16 *)((s8 *)(temp_v0) + (0x16))) = 0;
    (*(s16 *)((s8 *)(temp_v0) + (0x18))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x1AC))) = 0;
    if (func_800BF8E4() > 0) {
        (*(s16 *)((s8 *)(sp1C) + (4))) = 0x190;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_80800050_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_80800434_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_80800594_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/chflamer_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/chflamer_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_80800738_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_808007A8_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_808008C0_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_8080098C_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_808009C0_chflamer.s")
