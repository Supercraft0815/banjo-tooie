#include "common.h"

u16 func_8001D450(u16 arg0) {
    u16 r = ((arg0 & 0xF800) / 2) & 0xF800;
    u16 g = ((arg0 & 0x7C0) / 2) & 0x7C0;
    u16 b = ((arg0 & 0x3E) / 2) & 0x3E;
    return r | g | b | 1;
}

u8 func_8001D4C4(u8 arg0, u8 arg1, f32 arg2) {
    f32 start = arg0;
    return ((f32)arg1 - start) * arg2 + start;
}

void func_8001D5C4(u16 *arg0, u8 *arg1) {
    u16 r = (*arg0 >> 8) & 0xF8;
    u16 g = (*arg0 >> 3) & 0xF8;
    u16 b = (*arg0 << 2) & 0xF8;
    f32 blend;

    if (arg1[3] != 0) {
        blend = (u32)arg1[3] * 0.00390625f;
        r = func_8001D4C4(r, arg1[0], blend) & 0xF8;
        g = func_8001D4C4(g, arg1[1], blend) & 0xF8;
        b = func_8001D4C4(b, arg1[2], blend) & 0xF8;
    }
    *arg0 = (r << 8) | (g << 3) | (b >> 2) | 1;
}

void func_8001D6C0(u16 *arg0, int arg1, int arg2, u8 arg3) {
    u16 func_8001D450(u16);
    extern u16 D_8003F778[];
    int sp40;
    int var_s0;
    int var_s6;
    int var_s7;

    arg2++;
    arg1 += 2;
    arg0 += ((arg2 * 0x850) + (arg1 * 5) + 0x260);
    sp40 = ((arg3 * 5) - 0xA0) << 1;
    for (var_s6 = 0, var_s7 = 0; var_s6 != 0x850; var_s6 += 0x130, var_s7 += 0x1DC) {
        osInvalDCache((var_s6 + arg0), 5);
        for (var_s0 = 0; var_s0 != 0xA; var_s0 += 2) {
            u16 temp_v0;
            temp_v0 = *(u16 *)((u8 *)(D_8003F778 + var_s7) + sp40 + var_s0); if (temp_v0 != 0x11) { *(u16 *)((u8 *)(var_s6 + arg0) + var_s0) = temp_v0; } else { *(u16 *)((u8 *)(var_s6 + arg0) + var_s0) = func_8001D450(*(u16 *)((u8 *)(var_s6 + arg0) + var_s0)); }
        }
        osWritebackDCache((var_s6 + arg0), 5);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34F80/func_8001D800.s")

void func_8001D96C()
{
    func_8001D800(0xC);
}

void func_8001D98C(u16 arg0) {
    extern s32 D_8007D800;

    if (arg0 < 0x38) {
        D_8007D800 = arg0;
    }
}

void func_8001D9AC(u16 arg0) {
    extern s32 D_8007D804;

    if (arg0 < 0x1E) {
        D_8007D804 = arg0;
    }
}

void func_8001D9CC(u16 arg0, u16 arg1) {
    func_8001D98C(arg0);
    func_8001D9AC(arg1);
}

void func_8001DA00(u8 *arg0, s32 arg1) {
    extern s32 D_8007D810;
    D_8007D810 = 0;
    while (arg1--) {
        func_8001D800(*arg0++);
    }
}

void func_8001DA58(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34F80/func_8001DA60.s")

/* extern */

void func_8001DB90(u16 *arg0, int arg1, u32 arg2, u8 *arg3) {
    void func_8001D5C4(u16 *, u8 *);
    int var_s0;
    int var_s4;
    u16 *temp_s1;

    arg1 += 2;
    arg2++;
    arg0 += (arg2 * 0x850) + (arg1 * 5) + 0x260;
    for (var_s4 = 0; var_s4 != 0x850; var_s4 += 0x130) {
        temp_s1 = arg0 + var_s4;
        osInvalDCache(temp_s1, 5);
        for (var_s0 = 0; var_s0 != 5; var_s0++) {
            func_8001D5C4(temp_s1 + var_s0, arg3);
            osWritebackDCache(temp_s1, 5);
        }
    }
}

void func_8001DC6C(void) {
    extern s32 D_8007D170;
    if ((*(s32 *)((s8 *)(&D_8007D170) + (0x6A0))) != 0) {
        (*(s32 *)((s8 *)(&D_8007D170) + (0x6A0))) = 0;
        return;
    }
    (*(s32 *)((s8 *)(&D_8007D170) + (0x6A0))) = 1;
}
