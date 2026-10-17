#include "core2/1EA78C0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CDFD0.s")

int func_800CE1A8(void *arg0, void *arg1, s32 arg2) {
    extern f32 D_801259B0;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_f16;
    s32 temp_t0;
    s32 temp_v1;

    temp_f16 = (s32) ((f32) arg2 * D_801259B0);
    temp_v1 = ((*(s32 *)((s8 *)(arg0) + (0))) - (*(s32 *)((s8 *)(arg1) + (0)))) + temp_f16;
    temp_a3 = (*(s32 *)((s8 *)(arg0) + (8))) - (*(s32 *)((s8 *)(arg1) + (8)));
    temp_t0 = temp_v1 + temp_a3;
    temp_a0 = temp_v1 - temp_a3;
    temp_a1 = temp_f16 * 2;
    if ((temp_t0 < 0) || (temp_a1 < temp_t0)) {
        return 0;
    }
    return temp_a0 > 0 && temp_a0 < temp_a1;
}

s32 func_800CE21C(s32 arg0) {
    extern u16 D_8011AA10[7][2];
    s32 i;

    for (i = 0; i < 7; i++) {
        if (arg0 == D_8011AA10[i][0]) {
            return D_8011AA10[i][1];
        }
    }
    return -1;
}

void func_800CE2DC(void) {
    s32 func_800DAA8C(s32 *, s32, s32);
    extern s32 D_8012B020;
    func_800DAA8C(&D_8012B020, 7, 2);
}

void func_800CE308(void) {
    s32 func_800BE52C(u32 *, u32 *);
    s32 func_800DAAF8(s32 *, u8, s32);
    s32 func_800DAB8C(s32 *, s32);
    u32 func_800E9D68(u32);
    u32 func_800E9D90(u32);
    s32 func_800E9DD4(u32);
    extern s32 D_8012B020;
    u32 sp34;
    u32 sp30;
    u32 var_s0;
    u32 var_s1;

    func_800DAB8C(&D_8012B020, 0);
    func_800BE52C(&sp34, &sp30);
    for (; sp34 < sp30; sp34 += 8) {
        if (func_800E9DD4(sp34) != 0) {
            var_s0 = func_800E9D68(sp34);
            var_s1 = func_800E9D90(sp34);
            if (var_s0 < var_s1) {
                do {
                    if (!((*(s32 *)((s8 *)var_s0 + 4)) & 1)) {
                        func_800DAAF8(&D_8012B020, *(u8 *)((s8 *)var_s0 + 0xA), 1);
                    }
                    var_s0 += 0x14;
                } while (var_s0 < var_s1);
            }
        }
    }
}

void *func_800CE3E0(s32 arg0) {
    extern s32 D_8012B030;
    return (void *) ((arg0 << 5) + (s32) &D_8012B030);
}

void func_800CE3F4(u8 *arg0, s32 arg1) { extern s16 D_8011AA30;
    func_800D2498(*(s16 *)((s8 *)&D_8011AA30 + arg1 * 6), *(s16 *)(arg0 + 0xA), 0U);
}

/* extern */

s32 func_800CE438(u8 *arg0, s32 arg1) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    (*(f32 *)(arg0 + 0)) = func_800F10B4((f32) (*(s16 *)(arg0 + 0xA)), 0.0f, (f32) (*(s16 *)(arg0 + 0x10)), 0.0f, (*(f32 *)(arg0 + 0xC)));
    func_800CE3F4(arg0, arg1);
}

void func_800CE49C(u8 *arg0, s32 arg1, s32 arg2) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern f32 D_801259C0;
    (*(s16 *)(arg0 + 0xA)) = (s32) (func_800F10B4(*(f32 *)arg0, 0.0f, *(f32 *)(arg0 + 0xC), 1.0f, (f32) *(s16 *)(arg0 + 0x10) + 1.0f) - D_801259C0);
    if (arg2 != 0) {
        func_800CE3F4(arg0, arg1);
    }
}

/* extern */

void func_800CE524(void) {
    void *func_800CE3E0(s32);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_800CE3E0(var_s0);
        (*(s16 *)((s8 *)(temp_v0) + (8))) = 0;
        var_s0 += 1;
        (*(f32 *)((s8 *)(temp_v0) + (0))) = 0.0f;
        (*(f32 *)((s8 *)(temp_v0) + (4))) = 0.0f;
        (*(s8 *)((s8 *)(temp_v0) + (0x16))) = 0;
        (*(s8 *)((s8 *)(temp_v0) + (0x15))) = 0;
        (*(s8 *)((s8 *)(temp_v0) + (0x14))) = 0;
        (*(s8 *)((s8 *)(temp_v0) + (0x12))) = 0;
        (*(s8 *)((s8 *)(temp_v0) + (0x13))) = 0;
        (*(s32 *)((s8 *)(temp_v0) + (0x18))) = 0;
        (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = 0;
        (*(s16 *)((s8 *)(temp_v0) + (0xA))) = (s16) (*(s16 *)((s8 *)(temp_v0) + (8)));
    } while (var_s0 != 9);
}

s32 func_800CE59C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern u16 D_8011AA34[][3];
    u16 temp_v0;

    temp_v0 = D_8011AA34[arg0][0];
    if ((arg1 != 0) && (temp_v0 & 4)) {
        return 0;
    }
    if ((arg2 != 0) && (temp_v0 & 1)) {
        return 0;
    }
    if ((arg3 != 0) && (temp_v0 & 2)) {
        return 0;
    }
    if ((arg4 != 0) && (temp_v0 & 8)) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE628.s")

void func_800CE7DC(void) {
    s32 func_800C2FDC(u8);
    s32 func_800FC74C(s32);
    extern s32 D_8012B030;
    if ((*(u8 *)((s8 *)(&D_8012B030) + (0x120))) != 0) {
        func_800C2FDC((*(u8 *)((s8 *)(&D_8012B030) + (0x120))));
        (*(u8 *)((s8 *)(&D_8012B030) + (0x120))) = 0U;
    }
    if ((*(u8 *)((s8 *)(&D_8012B030) + (0x121))) != 0) {
        func_800FC74C(0x92);
        (*(u8 *)((s8 *)(&D_8012B030) + (0x121))) = 0U;
    }
}

s32 func_800CE83C(s32 arg0, s32 arg1) {
    void *func_800CE3E0(s32);
    s8 *ptr;

    ptr = func_800CE3E0(arg0);
    ptr[0x13] = arg1;
    return (s32) ptr;
}

/* extern */

void func_800CE864(void) {
    void *func_800CE3E0();
    (*(s8 *)((s8 *)(func_800CE3E0()) + (0x14))) = 1;
}

void func_800CE88C(s32 arg0, s32 arg1) { void *temp_v0; s8 temp_v1; temp_v0 = func_800CE3E0(arg0); if (arg1 != 0) { *(s8 *)((s8 *)temp_v0 + 0x12) = *(s8 *)((s8 *)temp_v0 + 0x12) + 1; } else { temp_v1 = *(s8 *)((s8 *)temp_v0 + 0x12); if (temp_v1 != 0) *(s8 *)((s8 *)temp_v0 + 0x12) = temp_v1 - 1; } }

void func_800CE8D8(s32 arg0, f32 arg1, s32 arg2) {
    void *func_800CE3E0(s32);
    u8 *temp_v0;

    temp_v0 = func_800CE3E0(arg0);
    (*(s8 *)((s8 *)(temp_v0) + (0x15))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = 0;
    (*(s16 *)((s8 *)(temp_v0) + (0x10))) = (s16) arg2;
    (*(s16 *)((s8 *)(temp_v0) + (0xA))) = (s16) arg2;
    (*(s16 *)((s8 *)(temp_v0) + (8))) = (s16) arg2;
    (*(f32 *)((s8 *)(temp_v0) + (0xC))) = arg1;
    (*(f32 *)((s8 *)(temp_v0) + (4))) = arg1;
    (*(f32 *)((s8 *)(temp_v0) + (0))) = arg1;
}

void func_800CE928(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_800CE3E0(arg0);
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = arg1;
    (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = arg2;
}

/* extern */

s32 func_800CE95C(void) {
    void *func_800CE3E0();
    return (*(s32 *)((s8 *)(func_800CE3E0()) + (0x18)));
}

void func_800CE980(s32 arg0, f32 arg1, s32 arg2) {
    u8 *temp_v0;

    temp_v0 = func_800CE3E0(arg0);
    if ((*(f32 *)((s8 *)(temp_v0) + (0xC))) < arg1) {
        (*(f32 *)((s8 *)(temp_v0) + (0xC))) = arg1;
    }
    (*(f32 *)((s8 *)(temp_v0) + (4))) = arg1;
    (*(f32 *)((s8 *)(temp_v0) + (0))) = arg1;
    func_800CE49C(temp_v0, arg0, arg2 == 0);
}

s32 func_800CE9E8(s32 arg0, s32 arg1) {
    void *func_800CE3E0();
    s32 func_800CE438();
    u8 *temp_v0;

    temp_v0 = func_800CE3E0();
    if ((*(s16 *)((s8 *)(temp_v0) + (0x10))) < arg1) {
        (*(s16 *)((s8 *)(temp_v0) + (0x10))) = (s16) arg1;
    }
    (*(s16 *)((s8 *)(temp_v0) + (8))) = (s16) arg1;
    (*(s16 *)((s8 *)(temp_v0) + (0xA))) = (s16) arg1;
    return func_800CE438(temp_v0, arg0, arg1);
}

void func_800CEA38(s32 arg0, s32 arg1) {
    (*(s8 *)((s8 *)(func_800CE3E0(arg0)) + (0x15))) = (s8) arg1;
}

f32 func_800CEA60(s32 arg0) {
    return *(f32 *) func_800CE3E0(arg0);
}

s16 func_800CEA84(s32 arg0) {
    return (*(s16 *)((s8 *)(func_800CE3E0(arg0)) + (0xA)));
}

/* extern */

s32 func_800CEAA8(s32 arg0) {
    void *func_800CE3E0(s32);
    return (*(s8 *)((s8 *)(func_800CE3E0(arg0)) + (0x12))) > 0;
}

s32 func_800CEAD0(s32 arg0) {
    return func_800CEA60(arg0) == 0.0f;
}

s32 func_800CEB08(void *arg0, f32 arg1) {
    if (((*(s8 *)((s8 *)(arg0) + (0x12))) != 0) && (arg1 <= (*(f32 *)((s8 *)(arg0) + (4)))) && ((*(f32 *)((s8 *)(arg0) + (0))) < arg1)) {
        return 1;
    }
    return 0;
}

void func_800CEB54(s32 arg0, f32 arg1) {
    func_800CEB08(func_800CE3E0(arg0), arg1);
}

s32 func_800CEB80(s32 arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = func_800CE3E0(arg0);
    if (((*(s8 *)((s8 *)(temp_v0) + (0x12))) != 0) && (arg1 < (*(s16 *)((s8 *)(temp_v0) + (8)))) && (arg1 >= (*(s16 *)((s8 *)(temp_v0) + (0xA))))) {
        return 1;
    }
    return 0;
}

void func_800CEBD8(s32 arg0, s32 arg1) {
    int func_800D284C(s32);
    int func_800DB9B0(void);
    u32 func_800F54E4(void);
    s32 func_800F68B8(s32);
    s32 func_800F6D24(s32);
    int func_800F8004(s32);
    extern s16 D_8011AA30;
    s32 sp34;
    s32 pad30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 pad20;

    sp34 = func_800F54E4();
    if (arg1 != 0) {
        sp24 = func_800DB9B0();
        sp28 = func_800F6D24(sp34);
        sp2C = func_800F8004(sp34);
        if (func_800CE59C(arg0, sp24, sp28, sp2C, func_800F68B8(sp34)) != 0) {
            func_800CE3F4(func_800CE3E0(arg0), arg0);
            return;
        }
    }
    func_800D284C(*(s16 *)((u8 *)&D_8011AA30 + arg0 * 6));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEC94.s")

f32 func_800CEF00(s32 arg0) {
    extern f32 D_8011AA80;
    extern s32 func_800CF6D0(void);
    return *(f32 *) ((u8 *) &D_8011AA80 + arg0 * 20) * (f32) func_800CF6D0();
}

f32 func_800CEF48(s32 arg0) {
    extern s16 D_8011AA8E;
    return (f32) *(s16 *) ((u8 *) &D_8011AA8E + arg0 * 20);
}

void func_800CEF6C(void) {
    extern f32 D_8012B170;
    D_8012B170 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEF7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF01C.s")

void func_800CF160(f32 arg0, s32 arg1) {
    extern s32 D_8012B160;
    (*(s8 *)((s8 *)(&D_8012B160) + (0xC))) = 1;
    (*(f32 *)((s8 *)(&D_8012B160) + (0x14))) = arg0;
    (*(s32 *)((s8 *)(&D_8012B160) + (0x1C))) = arg1;
    (*(f32 *)((s8 *)(&D_8012B160) + (0x18))) = 0.0f;
}

void func_800CF184(void)
{
    extern u8 D_8012B16C;

    D_8012B16C = 0;
}

void func_800CF190(void) {
    void func_8008FBC0(void);
    void func_8008FBE0(u32);
    s32 func_8008FC00(void);
    s32 func_800CF580(void);
    f32 func_800CF67C(void);
    s32 func_800D9078(f32 *);
    u32 func_800F54E4(void);
    void func_800F7B9C(s32, u32);
    extern f32 D_8012B174;
    extern s32 D_8012B160;
    extern f32 D_8012B178;
    extern s32 D_8012B17C;

    if (func_800CF67C() != 0.0f) {
        func_800CF184();
        return;
    }
    if (func_800CF580() != 0) {
        func_800CF7F4(1U);
        func_8008FBE0(1);
        func_800D9078(&D_8012B178);
        if (D_8012B178 <= 0.0f) {
            *(f32 *)((u8 *)&D_8012B160 + 0x18) = D_8012B174;
            func_8008FBC0();
            if (func_8008FC00() == 0) {
                func_800F7B9C(func_800F54E4(), D_8012B17C);
                func_800CF184();
            }
        }
    }
}

void func_800CF264(void) {
    s32 func_800CF01C();
    void func_800CF190(void);
    s32 func_800EA09C();
    extern u8 D_8012B16C;
    if (func_800EA09C() == 2) {
        func_800CF01C();
        if (D_8012B16C != 0) {
            func_800CF190();
        }
    }
}

void func_800CF2B0(void) {
    f32 func_800CEA60(s32);
    extern f32 D_8012B170;
    D_8012B170 = func_800CEA60(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF2D4.s")

void func_800CF40C(s32 arg0) {
    s16 func_800CF640(void);
    s32 func_800CF6D0(void);
    f32 sp1C;
    f32 sp18;

    sp1C = func_800CEA60(1);
    sp18 = func_800CEF00(func_800CF640());
    sp1C += ((f32) arg0 * sp18) / (f32) func_800CF6D0();
    if (sp18 < sp1C) {
        sp1C = sp18;
    }
    func_800CE980(1, sp1C, 0);
}

void func_800CF494(void) {
    s32 func_800D3E40(s32);
    u32 func_800F54E4(void);
    s32 func_800F6604(s32);
    void func_800F7B9C(s32, u32);
    s16 func_800CF640(void);
    f32 func_800CF67C(void);
    s32 func_800CF6D0(void);
    extern s32 D_8012B160;
    s32 pad;
    f32 sp20;
    f32 sp1C;
    s32 temp_a0;
    s32 temp_v0;

    if (func_800D3E40(9) == 0) {
        temp_v0 = func_800CEAA8(1);
        temp_a0 = temp_v0;
        if (((s16 *)&D_8012B160)[4] != 0) {
            ((s16 *)&D_8012B160)[4]--;
            return;
        }
        if (temp_v0 > 0) {
            ((s16 *)&D_8012B160)[temp_a0] = 9;
            sp20 = func_800CF67C();
            func_800CE88C(1, 0);
            sp1C = func_800CEF00(func_800CF640());
            func_800CE8D8(1, sp1C, func_800CF6D0());
            func_800CE980(1, sp20 * sp1C, 0);
            if (func_800F6604(func_800F54E4()) != 0) {
                func_800F7B9C(func_800F54E4(), 0x57);
            }
        }
    }
}

/* extern */

s32 func_800CF580(void) {
    s32 func_800A9C98();
    s32 func_800D3E40(s32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(s32, s32);
    s32 func_800F6BE4(s32);
    s32 func_800F6D24(s32);
    s32 func_800F8B88();
    s32 sp1C;
    s32 temp_v0;

    if (func_800A9C98() != 0) {
        return 0;
    }
    if (func_800D3E40(9) != 0) {
        return 0;
    }
    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F6BE4(temp_v0) == 0) {
        return 0;
    }
    if (func_800F6D24(sp1C) != 0) {
        return 0;
    }
    if (func_800F64A4(sp1C, 0x1A000) != 0) {
        return 0;
    }
    if (func_800F8B88() == 3) {
        return 0;
    }
    return 1;
}

s16 func_800CF640(void) {
    s32 func_800CEAA8();
    extern s32 D_8012B15E;
    s16 var_v1;
    s32 temp_v0;

    temp_v0 = func_800CEAA8(1);
    if (temp_v0 != 0) {
        var_v1 = ((s16 *)&D_8012B15E)[temp_v0];
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

f32 func_800CF67C(void) {
    f32 func_800CEF00(s32);
    f32 sp18[2];

    sp18[0] = func_800CEA60(1);
    return sp18[0] / func_800CEF00(func_800CF640());
}

void func_800CF6B0()
{
    func_800CEA84(0x1);
}

/* extern */

s32 func_800CF6D0(void) {
    s32 func_800DA298(s32);
    s32 var_v1;

    if (func_800DA298(0x1BF) != 0) {
        var_v1 = 0xA;
    } else {
        var_v1 = 6;
    }
    return var_v1;
}

/* extern */

void func_800CF700(void) {
    s32 func_800CE9E8(s32, s32);
    s32 func_800DA544(s32);
    func_800DA544(0x1BF);
    func_800CE9E8(1, func_800CF6D0());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF734.s")

/* extern */

void func_800CF7F4(u32 a0) {
    s32 func_800A16A4();
    void func_800CEBD8(s32, s32);
    s32 func_800CF580();
    if (((func_800CF580() != 0) && (func_800A16A4() == 0)) || (a0 == 0)) {
        func_800CEBD8(1, a0);
    }
}

/* extern */

void func_800CF840(s32 arg0) {
    s32 func_800CE83C(s32, s32);
    func_800CE83C(1, arg0);
}
