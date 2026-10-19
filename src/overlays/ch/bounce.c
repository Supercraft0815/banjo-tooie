#include "common.h"

void chbounce_entrypoint_0(void) {
    extern f32 D_8012716C;
    f32 *temp_v0 = (f32 *)(u32)((u8 *)&D_8012716C + 28);
    temp_v0[0] = 0.0f;
    temp_v0[1] = 1.0f;
    temp_v0[2] = 0.0;
}

void chbounce_entrypoint_1(void) {
}

void chbounce_entrypoint_2(f32 arg0) {
    extern f32 D_8012716C;
    *(f32 *)((u8 *)&D_8012716C + 28) = arg0;
}

void chbounce_entrypoint_3(f32 arg0) {
    extern f32 D_8012716C;
    *(f32 *)((u8 *)&D_8012716C + 36) = arg0;
}

void chbounce_entrypoint_4(Actor *arg0, s32 *arg1) {
    void func_800EE84C(f32 dst[3], s32 src[3]);
    void chbounce_entrypoint_6(Actor *arg0, u32 arg1);
    f32 position[3];

    func_800EE84C(position, arg1);
    chbounce_entrypoint_6(arg0, (u32) position);
}

/* extern */

s32 func_80800078_chbounce(void) {
    u32 _gclevel_entrypoint_3(u32);
    s32 func_800D3E40(s32);
    s32 func_800DA9E4(s32, s32);
    f32 func_800DC0C0(void);
    s32 func_800EA068(s32);
    f32 sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = func_800DC0C0();
    sp20 = _gclevel_entrypoint_3(0x10);
    sp1C = _gclevel_entrypoint_3(0x12);
    if (func_800D3E40(9) != 0) {
        return 0x229;
    }
    if (func_800EA068(0x8000) != 0) {
        return 0x229;
    }
    if ((sp20 == 0) && (sp1C == 0)) {
        return 0x229;
    }
    if (sp20 != 0) {
        if (func_800DA9E4(0x31, 1) == 0) {
            return 0x197;
        }
        if (sp24 < 0.049987793f) {
            return 0x197;
        }
        goto block_12;
    }
block_12:
    if (sp1C != 0) {
        if (func_800DA9E4(0x30, 1) == 0) {
            return 0x196;
        }
        if (sp24 < 0.049987793f) {
            return 0x196;
        }
        goto block_17;
    }
block_17:
    return 0x229;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/func_80800190_chbounce.s")

void chbounce_entrypoint_5(s32 arg0, u8 *arg1) {
    extern s32 D_80801000_chbounce;
    u32* func_80800190_chbounce(Actor*, u32, u32);
    *(f32 *)((u8 *)&D_80801000_chbounce + arg0 * 0x24) = *(f32 *)(arg1 + 0x48);
    func_80800190_chbounce((Actor *)arg0, (u32)(arg1 + 4), (u32)arg1);
}

void chbounce_entrypoint_6(Actor *arg0, u32 arg1) {
    u32* func_80800190_chbounce(Actor*, u32, u32);
    func_80800190_chbounce(arg0, arg1, 0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/chbounce_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/func_808007B8_chbounce.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/chbounce_entrypoint_8.s")

/* extern */

s32 chbounce_entrypoint_9(Actor *arg0) {
    return (s32) ((s8 *) func_80100094(arg0, 2U) + 0xC);
}

s32 chbounce_entrypoint_10(Actor *arg0) {
    return ((u32) (*(u32 *)((s8 *)(func_80100094(arg0, 2U)) + (0x24))) >> 0x1F) == 0;
}

void func_80800F74_chbounce(Actor *arg0) {
    u32* func_80100074(Actor*, u32, u32);
    (*(u8 *)((s8 *)(arg0) + (0x7B))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x7B))) & 0xFFF7);
    func_80100074(arg0, 2U, 0U);
}
