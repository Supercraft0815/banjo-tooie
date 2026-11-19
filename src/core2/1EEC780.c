#include "core2/1EEC090.h"
#include "camera_probe_angles.inc"
void func_80112E50(void *, f32, s32);

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


    f32 sp9C[3];
    CameraProbeAngles *phi_s4;
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
    for (phi_s0 = phi_s4->angles; phi_s0 < phi_s4->angles + phi_s4->count; phi_s0++) {
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

f32 func_800F5B64(s32, f32 *);

struct ba_bounce_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 unkC;
    u8 unkD;
    u8 padE[2];
    s32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

s32 func_8011309C(PlayerState *arg0, s32 arg1) {
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EF410(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA20(void *, void *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFD24(f32 *);
    void func_801107F0(void *, f32 *);
    s32 func_80110840(PlayerState *);
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;

    sp28 = func_800F5B64(func_80110840(arg0), sp60);
    func_801107F0(arg0, sp48);
    func_800EFB24(sp6C, sp60, sp48);
    func_800EF410(sp78, sp6C);
    func_800EE7F8(sp54, sp60);
    sp2C = func_800EEF94(sp6C);
    if (1500.0f < sp2C) {
        func_800EFA20(sp6C, sp78, 1500.0f);
        func_800EE780(sp54, sp48, sp6C);
    }
    switch (arg0->bounce->unk10) {
    case 0:
        func_800EFD24(sp3C);
        break;
    case 1:
        func_800EFA20(sp3C, sp78, sp28);
        func_800EF934(sp3C, sp3C, -90.0f);
        break;
    case 2:
        func_800EFA20(sp3C, sp78, sp28);
        func_800EF934(sp3C, sp3C, 90.0f);
        break;
    case 3:
        func_800EFA4C(sp3C, 0.0f, sp28, 0.0f);
        break;
    case 4:
        func_800EFD24(sp3C);
        break;
    }
    func_800EE780(sp30, sp3C, sp54);
    if (func_800C6A7C(sp48, sp30, sp84, 0x860020)) {
        arg0->bounce->unk10++;
        if (arg0->bounce->unk10 >= 5) {
            arg0->bounce->unk10 = 0;
            return func_80112E98(arg0, sp60, sp78, sp2C, arg1, 0x860020);
        }
    } else {
        arg0->bounce->unk10 = 0;
    }
    return 0;
}

s32 func_8011329C(PlayerState *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    int func_800EECE0(f32 *, f32 *);
    u32 func_8010FFD0(u8 *);
    void func_80110770(void *, f32 *);
    void func_801107F0(void *, f32 *);
    BtIntPtr func_80110898(PlayerState *);
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
    arg0->bounce->unk10 = 0;
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
    void func_800E87E0(u8 arg0);
    BtIntPtr var_s0;
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

void func_80113640(BtIntPtr unused, f32 *start, f32 *end) {
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
    BtIntPtr func_80110060(s32 *);
    BtIntPtr func_80110898(PlayerState *);
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
}    typedef struct { u8 pad0[0xC]; s16 unkC; s16 unkE; u8 pad10[0x4]; u8 unk14; } Obj1EEC780_func_801138A0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

s32 func_801138A0(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x28)));
    if ((((Obj1EEC780_func_801138A0_temp_v0 *)temp_v0)->unk14) != 0) {
        return 0;
    }
    if ((((Obj1EEC780_func_801138A0_temp_v0 *)temp_v0)->unkC) >= 4) {
        (((Obj1EEC780_func_801138A0_temp_v0 *)temp_v0)->unkE) = (s16) ((((Obj1EEC780_func_801138A0_temp_v0 *)temp_v0)->unkE) + 1);
    } else {
        (((Obj1EEC780_func_801138A0_temp_v0 *)temp_v0)->unkE) = 0;
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
    BT_NATIVE_ONLY(return) func_80112E98(arg0, sp4C, sp28, func_800EEF94(sp34), 0, 0x20020);
}    typedef struct { u8 pad0[0x28]; void * unk28; } Obj1EEC780_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8011396C(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Obj1EEC780_arg0 *)arg0)->unk28 + 20) = arg1;
}

f32 func_80113978(PlayerState *arg0, s32 arg1, s32 arg2) {
    f32 func_800136E4(f32);
    void func_800CA7E4(BtIntPtr, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F0DC0(f32, f32);
    void func_800F1A88(f32 *, f32 *);
    s32 func_800F711C(s32);
    BtIntPtr func_8010FF80(s32 *);
    s32 func_80110840(PlayerState *);
    BtIntPtr func_80110898(PlayerState *);
    void func_80112D90(PlayerState *, f32, f32, s32, s32);
    s32 func_801137E4(PlayerState *, f32 *, f32 *, void *, f32 *);
    f32 sp94[3];
    f32 sp88[3];
    s32 sp84;
    f32 sp80;
    BtIntPtr sp7C;

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
            func_800EF934(sp54, sp48, sp68 * 0.2f);
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

void func_80113D30(PlayerState *arg0) {
    s32 func_8001211C(void);
    void func_80019224(f32 *, f32 *);
    s32 func_800A940C(s32);
    void *func_800CA7A4(void *);
    void func_800CA7E4(BtIntPtr, f32 *);
    void func_800E8830(u8, f32 *);
    s32 func_800E8918(u8, s32, BtIntPtr, BtIntPtr);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF410(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    BtIntPtr func_8010FF80(s32 *);
    s32 func_80110840(PlayerState *);
    BtIntPtr func_80110898(PlayerState *);
    void mlMtxSet(void *);
    f32 spBC[3], spB0[3], spA4[3], sp98[3], sp8C[3], sp80[3], sp74[3];
    BtIntPtr model;
    s32 object;
    s32 i;
    f32 radius;
    s32 collision;

    object = func_80110840(arg0);
    model = func_8010FF80((s32 *)func_80110898(arg0));
    collision = func_800A940C(object);
    radius = func_80112550(arg0, spA4);
    func_800CA7E4(model, sp8C);
    func_800EFB24(spB0, spA4, sp8C);
    func_800EF410(spBC, spB0);
    func_800EE7F8(sp98, spA4);
    mlMtxSet(func_800CA7A4((void *)model));
    for (i = 0; i < 4; i++) {
        switch (i) {
            case 0: func_800EFA4C(sp80, 0.0f, -radius, 0.0f); break;
            case 1: func_800EFA4C(sp80, radius, 0.0f, 0.0f); break;
            case 2: func_800EFA4C(sp80, 0.0f, radius, 0.0f); break;
            case 3: func_800EFA4C(sp80, -radius, 0.0f, 0.0f); break;
        }
        func_80019224(sp80, sp80);
        func_800EE780(sp74, sp80, sp98);
        func_800E8830(((u8 *)arg0->bounce)[0x34 + i], sp74);
        ((s8 *)arg0->bounce)[0x38 + i] = func_800E8918(((u8 *)arg0->bounce)[0x34 + i], collision, (BtIntPtr)((u8 *)arg0->bounce + 0x4C + i * 12), 0);
        if (((s8 *)arg0->bounce)[0x38 + i] == 0) {
            if (((s32 *)((u8 *)arg0->bounce + 0x18))[i] == 0) {
                ((s32 *)((u8 *)arg0->bounce + 0x18))[i] = func_8001211C();
            }
            ((s32 *)((u8 *)arg0->bounce + 0x3C))[i]++;
        } else {
            ((s32 *)((u8 *)arg0->bounce + 0x18))[i] = 0;
            ((s32 *)((u8 *)arg0->bounce + 0x3C))[i] = ((s32 *)((u8 *)arg0->bounce + 0x18))[i];
        }
    }
    *(s16 *)((u8 *)arg0->bounce + 0xC) = 0;
    for (i = *(s16 *)((u8 *)arg0->bounce + 0xC); i < 4; i++) {
        if (((s32 *)((u8 *)arg0->bounce + 0x3C))[i] >= 4) {
            (*(s16 *)((u8 *)arg0->bounce + 0xC))++;
        }
    }
}
