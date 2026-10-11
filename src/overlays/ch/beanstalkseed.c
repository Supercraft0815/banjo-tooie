#include "common.h"

/* extern */

void func_80800000_chbeanstalkseed(void *arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFA88(s32);
    if (func_800DA298(((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) + 0x33D) != 0) {
        func_800FFA88((*(s32 *)((s8 *)(arg0) + (0))));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beanstalkseed/func_8080003C_chbeanstalkseed.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beanstalkseed/func_8080026C_chbeanstalkseed.s")

OSThread *chbeanstalkseed_entrypoint_0(void)
{
    extern u8 D_80800C00_chbeanstalkseed[];

    return (OSThread *) D_80800C00_chbeanstalkseed;
}

/* extern */

s32 func_80800328_chbeanstalkseed(void) {
    s32 func_800D1A04(s32);
    s32 func_800F54E4();
    s32 func_800F64A4(s32, s32);
    s32 func_800F66F0(s32);
    s32 func_800F6720(s32);
    s32 func_8010C500();
    if (func_8010C500() == 0) {
        return 0;
    }
    if (func_800D1A04(0x50) == 0) {
        return 0;
    }
    if (func_800F64A4(func_800F54E4(), 0x201) == 0) {
        return 0;
    }
    if (func_800F6720(func_800F54E4()) != 0) {
        return 0;
    }
    if (func_800F66F0(func_800F54E4()) != 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beanstalkseed/func_808003D8_chbeanstalkseed.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beanstalkseed/func_80800804_chbeanstalkseed.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beanstalkseed/func_80800950_chbeanstalkseed.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beanstalkseed/func_80800A0C_chbeanstalkseed.s")

OSThread *chbeanstalkseed_entrypoint_1(void)
{
    extern u8 D_80800C54_chbeanstalkseed[];

    return (OSThread *) D_80800C54_chbeanstalkseed;
}
