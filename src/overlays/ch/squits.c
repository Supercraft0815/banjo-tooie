#include "common.h"

OSThread *chsquits_entrypoint_0(void)
{
    extern u8 D_808006D8_chsquits[];

    return (OSThread *) D_808006D8_chsquits;
}

void func_8080000C_chsquits(u8 *arg0) {
    f32 func_800DC178(f32, f32);
    (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) (((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00) | 1);
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = func_800DC178(5.0f, 8.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/squits/func_80800054_chsquits.s")

s32 func_80800108_chsquits(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800BF744(s32, s32);
    int func_800DC298(f32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
        case 0x2E:
            func_80101FDC(arg0, 1);
            return 1;
        case 0x95:
            if (func_800DC298(0.2f) == 0) {
                func_800BF744(1, 0);
                func_800FFAB0(arg0);
                break;
            } else {
                func_800BF744(1, 1);
                break;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/squits/func_808001A4_chsquits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/squits/func_80800358_chsquits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/squits/func_808003C4_chsquits.s")

s32 func_80800528_chsquits(f32 arg0, f32 arg1, f32 arg2) {
    if ((arg2 < arg0) && (arg1 <= arg2)) {
        return 1;
    }
    return 0;
}

/* extern */

void func_80800564_chsquits(void *arg0) {
    s32 func_800DC128(s32, s32);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = func_800DC128(0, 4);
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 0.0f;
}
