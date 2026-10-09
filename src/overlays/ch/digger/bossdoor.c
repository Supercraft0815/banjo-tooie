#include "common.h"

OSThread *chdiggerbossdoor_entrypoint_0(void)
{
    extern u8 D_80800430_chdiggerbossdoor[];

    return (OSThread *) D_80800430_chdiggerbossdoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossdoor/func_8080000C_chdiggerbossdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossdoor/func_808000B0_chdiggerbossdoor.s")

/* extern */

void func_808002A8_chdiggerbossdoor(void *arg0) {
    s32 _capod_entrypoint_22();
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_22();
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossdoor/func_808002E8_chdiggerbossdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossdoor/func_80800370_chdiggerbossdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossdoor/chdiggerbossdoor_entrypoint_1.s")
