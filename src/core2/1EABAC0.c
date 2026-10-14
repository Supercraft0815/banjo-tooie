#include "core2/1EABAC0.h"

extern struct D_8011B45C_entry { u32 start; u32 count; } D_8011B45C[];

u8 *func_800D21D0(s32 arg0) {
    extern s32 D_8011AFB0;
    return (u8 *)&D_8011AFB0 + (arg0 * 12 - 0x900);
}

s32 func_800D21F0(s32 arg0, s32 arg1) {
    extern s32 D_8012B2C0;
    u32 i;
    u32 end;
    u8 value;

    i = D_8011B45C[arg1].count;
    end = D_8011B45C[arg1].start + i;
    if (i < end) {
        do {
            value = *(u8 *)i;
            i++;
            if (arg0 == ((s16 *)&D_8012B2C0)[value]) {
                return value;
            }
        } while (i < end);
    }
    return -1;
}

s32 func_800D225C(s32 arg0) {
    extern s32 D_8012B2C0;
    u32 i;
    u32 end;
    u8 value;

    i = D_8011B45C[arg0].count;
    end = D_8011B45C[arg0].start + i;
    if (i < end) {
        do {
            value = *(u8 *)i;
            i++;
            if (((s16 *)&D_8012B2C0)[value] == -1) {
                return value;
            }
        } while (i < end);
    }
    return -1;
}

u8 func_800D22C8(s32 arg0) { extern struct D_8011B460_entry { u8 *ptr; u32 pad; } D_8011B460[]; return D_8011B460[arg0].ptr[0]; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D22E0.s")

/* extern */

int func_800D2398(void *arg0, s32 arg1) {
    s32 func_800D21F0(s32, s32);
    s32 func_800FA8E8(s32, u8);
    s32 temp_v0;

    temp_v0 = func_800D21F0(arg1, (*(u8 *)((s8 *)(arg0) + (0))));
    return temp_v0 >= 0 && func_800FA8E8(temp_v0, (*(u8 *)((s8 *)(arg0) + (1)))) == 1;
}

/* extern */

int func_800D23E8(void *arg0, s32 arg1) {
    s32 func_800D21F0(s32, s32);
    s32 func_800FA874(s32, u8);
    s32 temp_v0;

    temp_v0 = func_800D21F0(arg1, (*(u8 *)((s8 *)(arg0) + (0))));
    return temp_v0 >= 0 && func_800FA874(temp_v0, (*(u8 *)((s8 *)(arg0) + (1)))) == 1;
}

void func_800D2438(void) { extern s32 D_8011AFB0; extern s32 D_8011B3F4; extern s32 D_8012B2C0; extern s32 D_8012B320; u32 end; u32 ptr; end = (u32)&D_8011B3F4;
    ptr = (u32)&D_8011AFB0; for (;;) { *(s16 *)(ptr + 4) = -1; *(s16 *)(ptr + 6) = 0; *(f32 *)(ptr + 8) = 0.0f; ptr += 12; if (ptr >= end) break; } end = (u32)&D_8012B320; ptr = (u32)&D_8012B2C0; for (;;) { ptr += 8; *(s16 *)(ptr - 6) = -1; *(s16 *)(ptr - 4) = -1; *(s16 *)(ptr - 2) = -1; *(s16 *)(ptr - 8) = -1; if (ptr == end) break; } }

/* extern */

void func_800D2498(u32 itemDisplayUI, s32 value, u32 a2) {
    s32 func_800D22E0(u8 *, u32);
    u8 *temp_v0;

    temp_v0 = func_800D21D0((s32) itemDisplayUI);
    (*(s16 *)((s8 *)(temp_v0) + (4))) = (s16) value;
    (*(f32 *)((s8 *)(temp_v0) + (8))) = (f32) value;
    (*(s16 *)((s8 *)(temp_v0) + (6))) = (s16) a2;
    func_800D22E0(temp_v0, itemDisplayUI);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D24E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EABAC0/func_800D2574.s")

void func_800D2748(s32 arg0, s32 arg1) {
    (*(s8 *)((s8 *)(func_800D21D0(arg0)) + (1))) = (s8) arg1;
}

void func_800D2770(s32 arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = func_800D21D0(arg0);
    (*(s16 *)((s8 *)(temp_v0) + (4))) = (s16) arg1;
    (*(f32 *)((s8 *)(temp_v0) + (8))) = (f32) arg1;
}

s32 func_800D27A4(s32 arg0) {
    return (s32) (*(u8 *)((s8 *)(func_800D21D0(arg0)) + (1)));
}

void func_800D27C8(s32 arg0) {
    func_800D21F0(arg0, (s32) *func_800D21D0(arg0));
}

void func_800D27F4(s32 arg0)
{
    func_800D23E8(func_800D21D0(arg0),arg0);
}

void func_800D2820(s32 arg0)
{
    func_800D2398(func_800D21D0(arg0),arg0);
}

/* extern */

int func_800D284C(s32 a0) {
    s32 func_800FA818(s32, s32);
    u8 *sp1C;
    s32 temp_v0_2;
    u8 *temp_v0;

    temp_v0 = func_800D21D0((s32) a0);
    sp1C = temp_v0;
    temp_v0_2 = func_800D21F0((s32) a0, (s32) *temp_v0);
    return temp_v0_2 >= 0 && func_800FA818(temp_v0_2, sp1C[1]) == 1;
}

/* extern */

s32 func_800D28A0(s32 arg0) {
    s32 func_800FAA74(s32);
    s32 temp_v0;

    temp_v0 = func_800D21F0(arg0, (s32) *func_800D21D0(arg0));
    if (temp_v0 >= 0) {
        func_800FAA74(temp_v0);
        return 1;
    }
    return 0;
}

u32 func_800D28E8(s32 arg0) {
    return (u32) (*(u8 *)((s8 *)(func_800D21D0(arg0)) + (2)));
}
