#include "core2/1EEC090.h"

s32 func_801127A0() 
{
    return 0x24;
}

void func_801127A8(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

void func_801127C8(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    f32 func_800F1DCC(f32, f32);
    f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
    f32 mlAbsF(f32);
    extern f32 D_80126590;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    sp2C = func_800F1DCC(arg0, *arg1);
    sp28 = mlAbsF(sp2C);
    if (D_80126590 < sp28) {
        sp24 = func_800FF060(sp2C, arg2, 1000.0f, -560.0f, 75.0f, func_800D8FF8());
        if ((sp28 < mlAbsF(sp24)) && ((*arg2 * sp2C) > 0.0f)) {
            sp24 = sp2C;
            *arg2 = 0.0f;
        }
        *arg1 = func_800136E4(*arg1 + sp24);
        return;
    }
    *arg2 = 0.0f;
    *arg1 = arg0;
}

void func_801128D4(f32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8();
    f32 func_800F1344(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    f32 mlAbsF(f32);
    f32 unused;
    f32 sp38;
    f32 acceleration;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    if (arg0 == *arg1) {
        *arg2 = 0.0f;
        return;
    }
    sp30 = func_800D8FF8();
    sp38 = func_800F1DCC(arg0, *arg1);
    if (mlAbsF(sp38) < arg5) {
        *arg2 = func_800F1344(sp38, 0.0f, arg5, 10.0f, arg4);
    } else {
        acceleration = arg3 * sp30;
        if (sp38 < 0.0f) {
            acceleration = -acceleration;
        }
        *arg2 += acceleration;
        if (*arg2 < 0.0f) {
            if (*arg2 < -arg4) {
                *arg2 = -arg4;
            }
        } else if (arg4 < *arg2) {
            *arg2 = arg4;
        }
    }
    sp2C = *arg2 * sp30;
    sp28 = mlAbsF(sp2C);
    if ((mlAbsF(sp38) < sp28) && ((sp2C * sp38) > 0.0f)) {
        *arg2 = 0.0f;
        sp2C = 0.0f;
        *arg1 = arg0;
    }
    *arg1 = func_800136E4(*arg1 + sp2C);
}

void func_80112A84(PlayerState *arg0) {
    f32 func_800D8FF8(void);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    void func_801107F0(void *, f32 *);
    void func_801160DC(PlayerState *, f32);
    void func_80112D08(void *, s32, f32, f32);
    f32 mlAbsF(f32);
    s32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp38[2];
    s32 sp34;

    if (*(s16 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0xC) != 0) {
        sp6C = 5;
        *(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x1C) += func_800D8FF8();
        func_801127A8(arg0, sp58);
        func_801107F0(arg0, sp40);
        func_800EFB24(sp4C, sp40, sp58);
        func_800F1A88(sp4C, sp38);
        if (*(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x20) <
            *(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x1C)) {
            sp38[1] = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x10);
        }
        sp34 = mlAbsF(*(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x10) - sp38[1]) < 1.0f;
        sp68 = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x14);
        sp64 = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x10);
        if (*(s16 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0xC) == 1) {
            func_801127C8(*(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x10),
                (f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x14),
                (f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x18), 50.0f, 3.0f);
            func_801160DC(arg0, 0.0f);
        } else {
            func_801128D4(*(f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x10),
                (f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x14),
                (f32 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x18), 800.0f, 160.0f, 100.0f);
            func_801160DC(arg0, 0.0f);
        }
        if (sp34 != 0) {
            *(s16 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0xC) = 0;
            *(s16 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0xE) = 0;
        }
    } else {
        sp6C = 0;
        sp64 = 0.0f;
        sp68 = 0.0f;
    }
    func_80112D08(arg0, sp6C, sp68, sp64);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80112C3C.s")

void func_80112D08(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (8))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (0))) = arg2;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (4))) = arg3;
}

void func_80112D2C(PlayerState *arg0) {
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    s32 func_800F1EA4(f32[3], f32 *);
    void func_801107F0(void *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_801107F0(arg0, sp34);
    func_801127A8(arg0, sp1C);
    func_800EFB24(sp28, sp34, sp1C);
    func_800F1EA4(sp28, (*(u8 **)((s8 *)(arg0) + (0x60))) + 0x14);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x60)))) + (0x18))) = 0.0f;
}

void func_80112D90(PlayerState *arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    f32 func_800F1DCC(f32, f32);
    f32 mlAbsF(f32);
    extern f32 D_801265A8;
    void *var_v0;

    var_v0 = (*(void **)((s8 *)(arg0) + (0x60)));
    if (arg4 >= (*(s16 *)((s8 *)(var_v0) + (0xE)))) {
        if (arg3 != (*(s16 *)((s8 *)(var_v0) + (0xC)))) {
            func_80112D2C(arg0);
            var_v0 = (*(void **)((s8 *)(arg0) + (0x60)));
        }
        (*(f32 *)((s8 *)(var_v0) + (0x10))) = arg1;
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (0x1C))) = 0.0f;
        var_v0 = (*(void **)((s8 *)(arg0) + (0x60)));
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (0x20))) = (f32) ((mlAbsF(func_800F1DCC((*(f32 *)((s8 *)(var_v0) + (0x10))), (*(f32 *)((s8 *)(var_v0) + (0x14))))) * D_801265A8) / arg2);
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (0xC))) = (s16) arg3;
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x60)))) + (0xE))) = (s16) arg4;
    }
}

void func_80112E50(void *arg0, f32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x60)));
    if (((*(s16 *)((s8 *)(temp_v0) + (0xC))) != 0) && (arg2 == (*(s16 *)((s8 *)(temp_v0) + (0xE))))) {
        (*(f32 *)((s8 *)(temp_v0) + (0x10))) = (f32) ((*(f32 *)((s8 *)(temp_v0) + (0x14))) + arg1);
    }
}

s32 func_80112E84(void *arg0) {
    return *(s16 *)((u8 *)*(void **)((u8 *)arg0 + 96) + 12);
}

s32 func_80112E90() 
{
    return 0x80;
}

s32 func_80112E98(PlayerState *arg0, f32 *arg1, f32 *arg2, f32 arg3, s32 arg4, s32 arg5) {
    void func_800EE780(f32 *, f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA20(void *, void *, f32);
    f32 func_800F0E00(f32, f32);
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    void *func_800FB3C0(f32 *, f32 *, f32, f32 *, s32, u32);
    void func_80110770(void *, f32 *);
    void func_801113B8(void *);
    struct AngleTable { f32 *unk0; s32 unk4; };
    extern struct AngleTable D_80124A38, D_80124A40, D_80124A48;
    f32 sp9C[3];
    struct AngleTable *phi_s4;
    f32 *phi_s0;
    f32 sp88[3];
    f32 phi_f20;
    f32 sp78[3];
    f32 phi_f26;

    phi_f26 = func_800F0E00(150.0f, arg3 - 100.0f);
    switch (arg4) {
    case 1:
        phi_s4 = &D_80124A40;
        break;
    case 2:
    case 3:
        phi_s4 = &D_80124A48;
        break;
    case 0:
    default:
        phi_s4 = &D_80124A38;
        phi_f26 = 150.0f;
        break;
    }
    for (phi_s0 = phi_s4->unk0; phi_s0 < phi_s4->unk0 + phi_s4->unk4; phi_s0++) {
        phi_f20 = *phi_s0;
        if (arg4 == 3) {
            phi_f20 = -phi_f20;
        }
        func_800EFA20(sp9C, arg2, -arg3);
        func_800EF934(sp9C, sp9C, phi_f20);
        func_800EE780(sp78, arg1, sp9C);
        func_800FAB50(arg1, sp78, sp88, arg5, 50.0f);
        func_800FB3C0(arg1, sp78, 50.0f, sp88, 4, arg5);
        if (phi_f26 < func_800EEAD4(arg1, sp78)) {
            func_80110770(arg0, sp78);
            func_801113B8(arg0);
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011309C.s")

s32 func_8011329C(PlayerState *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    int func_800EECE0(f32 *, f32 *);
    u32 func_8010FFD0(u8 *);
    void func_80110770(void *, f32 *);
    void func_801107F0(void *, f32 *);
    s32 func_80110898(PlayerState *);
    void func_80113688(PlayerState *, struct ba_bounce_s *, f32 *);
    f32 sp34[3];
    f32 sp28[3];

    if (func_8010FFD0(func_80110898(arg0)) != 0) {
        return 0;
    }
    func_801107F0(arg0, sp28);
    func_800EE7F8(sp34, sp28);
    func_80113688(arg0, arg0->bounce, sp28);
    func_80110770(arg0, sp28);
    return func_800EECE0(sp34, sp28) == 0;
}

/* extern */
s32 func_80113320(PlayerState *arg0, f32 *arg1) { void func_800EE7F8(f32 *, f32 *); s32 func_80110840(PlayerState *); void *func_800C6A7C(f32 *, f32 *, f32 *, u32); s32 pad; f32 sp38[3]; f32 sp2C[3]; f32 sp20[3]; s32 pad2; func_800EE7F8(sp20, arg1); func_800F5B64(func_80110840(arg0), sp38); if (func_800C6A7C(sp38, sp20, sp2C, 0x860020) != 0) return 0; return 1; }

void func_8011337C(PlayerState *arg0) {
    u8 func_800E8714(s32);
    void func_800E8870(u8, f32);
    void func_801107F0(void *, f32 *);
    s32 i;

    func_801107F0(arg0, arg0->bounce);
    *(s32 *)((u8 *)arg0->bounce + 0x10) = 0;
    i = 0;
    *((u8 *)arg0->bounce + 0x14) = 0;
    do {
        ((u8 *)arg0->bounce)[i + 0x34] = func_800E8714(1);
        func_800E8870(((u8 *)arg0->bounce)[i + 0x34], 10.0f);
        i++;
    } while (i != 4);
}

/* extern */

void func_80113410(void *arg0) {
    s32 func_800E87E0(u8);
    s32 var_s0;
    u8 temp_a0;

    var_s0 = 0;
    do {
        temp_a0 = (*(u8 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x28))) + var_s0)) + (0x34)));
        if (temp_a0 != 0) {
            func_800E87E0(temp_a0);
            (*(s8 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x28))) + var_s0)) + (0x34))) = 0;
        }
        var_s0 += 1;
    } while (var_s0 != 4);
}

void func_8011347C(PlayerState *arg0) {
    void func_801107F0(void *, f32 *);
    func_801107F0(arg0, arg0->bounce);
}

s32 func_8011349C(f32 *start, f32 *end) {
    void func_800EE7F8(f32 *, f32 *);
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    f32 destination[3];
    f32 normal[3];
    func_800EE7F8(destination, end);
    if (func_800FAB50(start, destination, normal, 0x820020, 50.0f)) return 0;
    return 1;
}

void func_801134F0(f32 *arg0, f32 arg1) {
    void *func_800C6C94(f32[3], f32, f32[3], u32);
    f32 func_800EEFD4(f32 *);
    void func_800EF174(f32[3], f32[3], f32);
    f32 normal[3];
    f32 threshold;
    s32 count;

    count = 0;
    if (func_800C6C94(arg0, arg1, normal, 0x820020) != 0) {
        threshold = 0.01f;
loop:
        if (!(func_800EEFD4(normal) < threshold)) {
            func_800EF174(arg0, normal, 1.5f);
            count += 1;
            if (func_800C6C94(arg0, arg1, normal, 0x820020) != 0) {
                if (count != 1) {
                    goto loop;
                }
            }
        }
    }
}

void func_801135D0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, f32 *arg4) {
    f32 func_800EEAA4(f32 a[3], f32 b[3]);
    void func_800EF174(f32[3], f32[3], f32);
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EFB24(sp34, arg3, arg2);
    func_800EFB24(&sp28, arg1, arg0);
    func_800EFB24(&sp1C, sp34, &sp28);
    func_800EF174((f32 *)arg3, arg4, -func_800EEAA4(arg4, &sp1C));
}

void func_80113640(s32 unused, f32 *start, f32 *end) {
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    f32 normal[3];
    func_800FAB50(start, end, normal, 0x820020, 45.0f);
}

void func_80113688(PlayerState *arg0, struct ba_bounce_s *arg1, f32 *arg2) {
    void func_800AAD28(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    void *func_800FB3C0(f32 *, f32 *, f32, f32 *, s32, u32);
    s32 func_80110060(s32 *);
    s32 func_80110898(PlayerState *);
    void func_801134F0(f32 *, f32);
    void func_80114CF4(u8 *, f32 *, s32, f32 *);
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    s32 *sp58;
    s32 *sp54;
    f32 sp30[9];

    func_801134F0(arg1, 45.0f);
    if (!(func_800EEB40(arg1, arg2) < 0.0001f)) {
        func_800EE7F8(sp68, arg1);
        func_800EE7F8(sp5C, arg2);
        sp58 = func_800FAB50(sp68, sp5C, sp74, 0x820020, 45.0f);
        if (sp58 == NULL) {
            sp54 = func_800FB3C0(sp68, sp5C, 45.0f, sp74, 3, 0x820020);
        }
        if (sp58 != NULL || sp54 != NULL) {
            func_800AAD28(sp30);
            func_80114CF4(func_80110060(func_80110898(arg0)), sp30,
                sp58 != NULL ? sp58[2] : sp54[2], sp74);
            func_801135D0(sp68, sp5C, arg1, arg2, sp74);
            func_800FAB50(arg1, arg2, sp74, 0x820020, 45.0f);
        }
    }
}

s32 func_801137E4(PlayerState *arg0, f32 *arg1, f32 *arg2, void *arg3, f32 *arg4) {
    f32 func_80013A7C(f32);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 sp2C[3];
    f32 sp20[3];
    f32 temp_f0;

    if (func_800C6A7C(arg1, arg3, sp2C, 0x860020) != 0) {
        func_800EFB24(sp20, arg3, arg2);
        func_800EF2A0(sp20);
        temp_f0 = func_800EEAA4(sp20, sp2C);
        if (temp_f0 < 0.0f) {
            return 0;
        }
        *arg4 = (90.0f - func_80013A7C(temp_f0)) + 5.0f;
        return 1;
    }
    return 0;
}

s32 func_801138A0(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x28)));
    if ((*(u8 *)((s8 *)(temp_v0) + (0x14))) != 0) {
        return 0;
    }
    if ((*(s16 *)((s8 *)(temp_v0) + (0xC))) >= 4) {
        (*(s16 *)((s8 *)(temp_v0) + (0xE))) = (s16) ((*(s16 *)((s8 *)(temp_v0) + (0xE))) + 1);
    } else {
        (*(s16 *)((s8 *)(temp_v0) + (0xE))) = 0;
    }
    return (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x28)))) + (0xE))) >= 5;
}

s32 func_801138F4(PlayerState *arg0) {
    f32 func_800EEF94(f32 *);
    void func_800EF410(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_801107F0(void *, f32 *);
    s32 func_80112E98(PlayerState *, f32 *, f32 *, f32, s32, s32);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    func_80112550(arg0, sp4C);
    func_801107F0(arg0, sp40);
    func_800EFB24(sp34, sp4C, sp40);
    func_800EF410(sp28, sp34);
    func_80112E98(arg0, sp4C, sp28, func_800EEF94(sp34), 0, 0x20020);
}

void func_8011396C(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 40) + 20) = arg1;
}

f32 func_80113978(PlayerState *arg0, s32 arg1, s32 arg2) {
    f32 func_800136E4(f32);
    void func_800CA7E4(s32, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F0DC0(f32, f32);
    void func_800F1A88(f32 *, f32 *);
    s32 func_800F711C(s32);
    s32 func_8010FF80(s32 *);
    s32 func_80110840(PlayerState *);
    s32 func_80110898(PlayerState *);
    void func_80112D90(PlayerState *, f32, f32, s32, s32);
    s32 func_801137E4(PlayerState *, f32 *, f32 *, void *, f32 *);
    extern f32 D_801265D0;
    f32 sp94[3];
    f32 sp88[3];
    s32 sp84;
    f32 sp80;
    s32 sp7C;

    sp84 = func_80110840(arg0);
    sp80 = 0.0f;
    sp7C = func_8010FF80((s32 *)func_80110898(arg0));
    if (func_800F711C(sp84) == 0 || *(u8 *)((u8 *)arg0->bounce + 0x14) != 0) {
        return 0.0f;
    }
    func_80112550(arg0, sp94);
    func_800CA7E4(sp7C, sp88);
    if (arg1 != 0) {
        s32 direction;
        s32 count;
        s32 hit;
        f32 sp6C;
        f32 sp68;
        f32 sp60[2];
        f32 sp54[3];
        f32 sp48[3];

        count = 0;
        direction = 0;
        hit = 0;
        if (*(s32 *)((u8 *)arg0->bounce + 0x40) >= 4) {
            count++;
            direction--;
        }
        if (*(s32 *)((u8 *)arg0->bounce + 0x48) >= 4) {
            count++;
            direction++;
        }
        sp6C = 0.0f;
        if (count != 0) {
            if (direction == 0) {
                if (*(s32 *)((u8 *)arg0->bounce + 0x24) < *(s32 *)((u8 *)arg0->bounce + 0x1C)) {
                    direction = 1;
                } else {
                    direction = -1;
                }
            }
            if (direction < 0) {
                if (func_801137E4(arg0, sp94, sp88, (u8 *)arg0->bounce + 0x58, &sp6C)) {
                    hit = 1;
                }
            } else {
                if (func_801137E4(arg0, sp94, sp88, (u8 *)arg0->bounce + 0x70, &sp6C)) {
                    hit = 1;
                }
            }
        }
        if (hit != 0) {
            func_800EFB24(sp48, sp88, sp94);
            func_800F1A88(sp48, sp60);
            sp68 = (direction < 0 ? -1.0f : 1.0f) * sp6C;
            func_800EF934(sp54, sp48, sp68 * D_801265D0);
            func_800EF04C(sp54, sp94);
            if (func_8011349C(sp88, sp54)) {
                func_80112D90(arg0, func_800136E4(sp60[1] + sp68), sp6C * 0.25f, 1, 1);
                *(s32 *)((u8 *)arg0->bounce + 0x7C) = direction;
            }
        } else {
            if (*(s32 *)((u8 *)arg0->bounce + 0x7C) != 0) {
                func_80112E50(arg0, (f32)*(s32 *)((u8 *)arg0->bounce + 0x7C) * 2.5f, 1);
                *(s32 *)((u8 *)arg0->bounce + 0x7C) = 0;
            }
        }
    }
    if (arg2 != 0) {
        s32 direction;
        s32 count;
        s32 hit;
        f32 sp38;

        count = 0;
        direction = 0;
        hit = 0;
        if (*(s32 *)((u8 *)arg0->bounce + 0x44) >= 4) {
            count++;
            direction--;
        }
        if (*(s32 *)((u8 *)arg0->bounce + 0x3C) >= 4) {
            count++;
            direction++;
        }
        sp38 = 0.0f;
        if (count != 0) {
            if (direction == 0) {
                if (*(s32 *)((u8 *)arg0->bounce + 0x18) < *(s32 *)((u8 *)arg0->bounce + 0x20)) {
                    direction = 1;
                } else {
                    direction = -1;
                }
            }
            if (direction < 0) {
                if (func_801137E4(arg0, sp94, sp88, (u8 *)arg0->bounce + 0x64, &sp38)) {
                    hit = 1;
                }
            } else {
                if (func_801137E4(arg0, sp94, sp88, (u8 *)arg0->bounce + 0x4C, &sp38)) {
                    hit = 1;
                }
            }
        }
        if (hit != 0) {
            sp80 = func_800F0DC0(sp38, 10.0f);
        }
    }
    return sp80;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80113D30.s")

s32 func_80113FF0(void *arg0) {
    typedef struct {
        s32 unk;
        f32 value;
        u8 active;
        u8 pad[3];
    } Entry;
    typedef struct {
        u8 pad[0x48];
        Entry entries[7];
    } Data;
    Data *data = arg0;
    s32 i;
    s32 best = -1;
    f32 value = -1.0f;
    f32 current;

    for (i = 0; i < 7; i++) {
        if (data->entries[i].active != 0) {
            current = data->entries[i].value;
            if (best == -1 || current < value) {
                value = current;
                best = i;
            }
        }
    }
    return best;
}

void func_8011413C(s32 camera, f32 rotation[3], f32 scale, s32 index) {
    void func_800CA740(s32, f32 *);
    void func_800CB0E8(s32, f32 *, s32);
    void func_800EF334(f32 *, f32);
    if (index != 0) {
        func_800CB0E8(camera, rotation, index - 1);
    } else {
        func_800CA740(camera, rotation);
    }
    func_800EF334(rotation, scale);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80114184.s")

/* extern */

s32 func_801143A4(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3) {
    void func_800CA8F4(f32 *, f32 *, f32 *);
    s32 func_800CACEC(f32 *, f32 *, f32);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];
    f32 temp_f12;

    func_800CA8F4(arg0, sp34, sp28);
    func_800EFB24(sp1C, arg1, sp34);
    temp_f12 = func_800EEAA4(sp1C, sp28) - arg2;
    if (temp_f12 < *arg3) {
        if (func_800CACEC(arg0, arg1, arg2) != 0) {
            *arg3 = temp_f12;
            return 1;
        }
    }
    return 0;
}

f32 func_80114444(s32 arg0) {
    s32 func_800F5410(s32);
    extern f32 D_801265E4;
    extern f32 D_801265E8;
    if (func_800F5410(arg0) == 0xD) {
        return D_801265E4;
    }
    return D_801265E8;
}

/* extern */

s32 func_8011447C(f32 *arg0, f32 *arg1) {
    s32 func_800F5898();
    s32 func_800F5EF8(s32);
    s32 func_800F6438(u32);
    int func_800F6640(s32);
    s32 func_800F6690(s32);
    s32 func_800F6BE4(s32);
    PlayerState *func_80110014(s32);
    f32 temp_f20;
    s32 var_s0;
    f32 sp4C[3];
    s32 var_s2;

    var_s2 = 0;
    var_s0 = 0;
    if (func_800F5898() > 0) {
        do {
            if ((func_800F6BE4(var_s0) != 0) && (func_800F6BE4(var_s0) != 0) && (func_800F6438(var_s0) != 0) && (func_800F6640(var_s0) != 0) && (func_800F6690(var_s0) != 0)) {
                temp_f20 = func_80112550(func_80110014(func_800F5EF8(var_s0)), sp4C);
                var_s2 |= func_801143A4(arg0, sp4C, func_80114444(var_s0) * temp_f20, arg1);
            }
            var_s0 += 1;
        } while (var_s0 < func_800F5898());
    }
    return var_s2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011458C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_80114774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEC090/func_8011490C.s")

void *func_80114BD4(void) {
    void *heap_alloc(s32);
    u8 *ptr;
    s32 i;

    ptr = heap_alloc(0x9C);
    *(s8 *)(ptr + 2) = 0;
    *(s16 *)(ptr + 0) = 0;
    *(s8 *)(ptr + 3) = 0;
    *(s8 *)(ptr + 4) = 0;
    *(f32 *)(ptr + 8) = 0.0f;
    for (i = 0; i < 7; i++) {
        *(s32 *)(ptr + 0x48 + i * 0xC) = 0;
        *(f32 *)(ptr + 0x4C + i * 0xC) = -1.0f;
        *(s8 *)(ptr + 0x50 + i * 0xC) = 0;
    }
    return ptr;
}

void func_80114C7C(void* arg0) 
{
    heap_free(arg0);
}
void func_80114C9C(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (*(f32 *)((s8 *)(arg0) + (0xC)));
    *arg2 = (*(f32 *)((s8 *)(arg0) + (0x10)));
}

void func_80114CB0(void *arg0, f32 arg1) {
    (*(s8 *)((s8 *)(arg0) + (4))) = 0;
    (*(f32 *)((s8 *)(arg0) + (8))) = arg1;
}

void func_80114CC0(void *arg0, f32 arg1) {
    (*(s8 *)((s8 *)(arg0) + (4))) = 1;
    (*(f32 *)((s8 *)(arg0) + (8))) = arg1;
}

void* func_80114CD4(void* arg0) 
{
    return defrag(arg0);
}
/* extern */

void func_80114CF4(u8 *arg0, f32 *arg1, s32 arg2, f32 *arg3) {
    void func_800EE7F8(f32 *, f32 *);
    s32 var_s0;
    f32 *var_s1;
    f32 *var_s2;

    if (!(arg2 & 0x40000)) {
        var_s0 = 0;
        var_s1 = (f32 *)(arg0 + 0x14);
        var_s2 = arg1;
        do {
            func_800EE7F8(var_s1, var_s2);
            var_s0 += 0xC;
            var_s1 += 3;
            var_s2 += 3;
        } while (var_s0 != 0x24);
        func_800EE7F8((f32 *)(arg0 + 0x3C), arg3);
        (*(s32 *)((s8 *)(arg0) + (0x38))) = arg2;
        (*(s8 *)((s8 *)(arg0) + (3))) = 1;
    }
}
