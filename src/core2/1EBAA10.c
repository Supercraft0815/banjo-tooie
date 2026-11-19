#include "common.h"

/* extern */

void func_800E1120(f32 *arg0, f32 *arg1, f32 arg2) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EF8BC(f32 *, f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp24[3];

    func_800EFA4C(sp24, 0.0f, arg2, 0.0f);
    func_800EF8BC(sp24, sp24, arg1[0]);
    func_800EF934(sp24, sp24, arg1[1]);
    func_800EF04C(arg0, sp24);
}

/* extern */

void func_800E119C(f32 *arg0, f32 *arg1, f32 arg2) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EF8BC(f32 *, f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp24[3];

    func_800EFA4C(sp24, 0.0f, 0.0f, arg2);
    func_800EF8BC(sp24, sp24, arg1[0]);
    func_800EF934(sp24, sp24, arg1[1]);
    func_800EF04C(arg0, sp24);
}

/* extern */

void func_800E1218(f32 *arg0, f32 *arg1, f32 arg2) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EF8BC(f32 *, f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp24[3];

    func_800EFA4C(sp24, arg2, 0.0f, 0.0f);
    func_800EF8BC(sp24, sp24, arg1[0]);
    func_800EF934(sp24, sp24, arg1[1]);
    func_800EF04C(arg0, sp24);
}

void func_800E1294(s32 arg0, f32 position[3], f32 rotation[3], f32 delta) {
    void func_800E1218(f32 *, f32 *, f32);
    void func_800E1120(f32 *, f32 *, f32);
    void func_800E119C(f32 *, f32 *, f32);
    switch (arg0) {
    case 1:
        func_800E1218(position, rotation, delta);
        return;
    case 0:
        func_800E1120(position, rotation, delta);
        return;
    case 2:
        func_800E119C(position, rotation, delta);
        return;
    case 3:
        position[1] += delta;
        return;
    }
}

typedef struct {
    f32 position[3];
    f32 min, max, floor;
    f32 unk18, unk1C, unk20, unk24;
    f32 strength, multiplier, unk30;
    u8 curve[8][8];
    s8 active;
    s8 unk75;
    s8 updated;
    u8 decay_phase;
    u8 curve_length;
    u8 pad79[3];
} CameraShake;
enum { CAMERA_SHAKE_COUNT = 10 };
BT_IDO_ONLY(extern) CameraShake D_8012CF90[CAMERA_SHAKE_COUNT];
BT_NATIVE_ONLY(_Static_assert(sizeof(CameraShake) == 124, "camera shake layout");)

f32 func_800E1338(s32 arg0) {
    BT_IDO_ONLY(extern f32 D_8012CFB8[];)
    return BT_DATA_FIELD(D_8012CF90[arg0].strength, *(f32 *)((BtIntPtr)&D_8012CFB8 + ((arg0 * 31) * 4)));
}

s32 func_800E1354(s32 arg0) {
    BT_IDO_ONLY(extern u8 D_8012D004[];)
    return BT_DATA_FIELD((u8)D_8012CF90[arg0].active, D_8012D004[(arg0 * 31) * 4]) != 1;
}

/* extern */

void func_800E1378(s32 arg0) {
    void func_800E13F0(s32, f32);
    void func_800E144C(s32, f32);
    void func_800E146C(s32, f32);
    void func_800E148C(s32, f32, f32);
    s32 func_800EA068(s32);
    func_800E13F0(arg0, 30.0f);
    func_800E144C(arg0, 0.65f);
    func_800E148C(arg0, 1000.0f, 2000.0f);
    if (func_800EA068(0x20) != 0) {
        func_800E146C(arg0, 0.0f);
        return;
    }
    func_800E146C(arg0, 0.5f);
}

void func_800E13F0(s32 arg0, f32 arg1) {
    BT_IDO_ONLY(extern f32 D_8012CFB8[];)
    BT_DATA_FIELD(D_8012CF90[arg0].strength, *(f32 *)((BtIntPtr)&D_8012CFB8 + ((arg0 * 31) * 4))) = arg1;
}



void func_800E1410(s32 arg0, f32 arg1, f32 arg2) {
    CameraShake *entry = &D_8012CF90[arg0];
    entry->unk24 = entry->strength;
    entry->unk20 = entry->strength + arg1;
    entry->unk30 = arg2;
    entry->unk18 = arg2;
}

void func_800E144C(s32 arg0, f32 arg1) {
    BT_IDO_ONLY(extern f32 D_8012CFAC[];)
    BT_DATA_FIELD(D_8012CF90[arg0].unk1C, *(f32 *)((BtIntPtr)&D_8012CFAC + ((arg0 * 31) * 4))) = arg1;
}

void func_800E146C(s32 arg0, f32 arg1) {
    BT_IDO_ONLY(extern f32 D_8012CFA4[];)
    BT_DATA_FIELD(D_8012CF90[arg0].floor, *(f32 *)((BtIntPtr)&D_8012CFA4 + ((arg0 * 31) * 4))) = arg1;
}

void func_800E148C(s32 arg0, f32 arg1, f32 arg2) {
    BT_IDO_ONLY(extern f32 D_8012CFA4[];)
#ifdef BT_NATIVE
    D_8012CF90[arg0].min = arg1;
    D_8012CF90[arg0].max = arg2;
#else
    f32 *entry;

    entry = (f32 *)((BtIntPtr)((u8 *)D_8012CFA4 - 0x14) + ((arg0 * 31) * 4));
    entry[3] = arg1;
    entry[4] = arg2;
#endif
}

void func_800E14B8(s32 arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);

    func_800EE7F8(D_8012CF90[arg0].position, arg1);
    D_8012CF90[arg0].updated = 1;
}

void func_800E14F8(s32 arg0, u8 *arg1, s16 arg2) {
    void rare_memcpy(void *, void *, int);
    CameraShake *entry = &D_8012CF90[arg0];
    s16 *countPtr = &arg2;
    s16 count = *countPtr;
    entry->curve_length = count;
    rare_memcpy(entry->curve, arg1, count * 8);
}

s32 func_800E1540(s32 arg0) {
    s32 func_800DC128(s32, s32);
    s32 index;
    CameraShake *entry;

    for (index = 0; index < CAMERA_SHAKE_COUNT; index++) {
        if ((u8)D_8012CF90[index].active == 1) {
            break;
        }
    }
    if (index == CAMERA_SHAKE_COUNT) {
        index = func_800DC128(0, 10);
    }
    entry = &D_8012CF90[index];
    entry->unk75 = arg0;
    entry->active = 2;
    entry->decay_phase = 0;
    return index;
}

s32 func_800E15CC(s32 arg0, f32 arg1, f32 arg2) {
    s32 func_800E1540(s32);
    s32 entry = func_800E1540(arg0);
    func_800E13F0(entry, arg1);
    func_800E144C(entry, arg2);
    return entry;
}

s32 func_800E1610(s32 arg0, f32 arg1, f32 arg2, f32 *arg3) { s32 func_800E1540(s32); s32 entry = func_800E1540(arg0); func_800E13F0(entry, arg1); func_800E144C(entry, arg2); func_800E14B8(entry, arg3); return entry; }

s32 func_800E1664(s32 arg0, f32 arg1, f32 arg2, f32 *arg3, u8 *arg4, s16 arg5) {
    s32 sp1C;
    s32 temp_v0;
    CameraShake *temp_v0_2;

    temp_v0 = func_800E1540(arg0);
    sp1C = temp_v0;
    func_800E14F8(temp_v0, arg4, arg5);
    temp_v0_2 = &D_8012CF90[sp1C];
    temp_v0_2->active = 4;
    (temp_v0_2->unk20) = arg1;
    (temp_v0_2->unk30) = 0.0f;
    (temp_v0_2->unk18) = arg2;
    if (arg1 >= 0.0f) {
        (temp_v0_2->multiplier) = 1.0f;
    } else {
        (temp_v0_2->multiplier) = -1.0f;
    }
    if (arg3 != 0) {
        func_800E14B8(sp1C, arg3);
    }
    return sp1C;
}

BtIntPtr func_800E1720(s32 arg0) {
    CameraShake *entry;

    entry = &D_8012CF90[arg0];
    entry->active = 1;
    entry->updated = 0;
    return (BtIntPtr)entry;
}

/* extern */

void func_800E1748(void) {
    BtIntPtr func_800E1720(s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        func_800E1720(var_s0);
        var_s0 += 1;
    } while (var_s0 != CAMERA_SHAKE_COUNT);
}

/* extern */

void func_800E1788(void) {
    void func_800E1378(s32);
    void func_800EFD24(f32 vec[3]);
    CameraShake *var_s0;
    s32 var_s1;

    var_s0 = D_8012CF90;
    var_s1 = 0;
    do {
        var_s0->active = 1;
        (var_s0->unk30) = 0.0f;
        var_s0->updated = 0;
        func_800EFD24(var_s0->position);
        func_800E1378(var_s1);
        var_s1 += 1;
        var_s0++;
    } while (var_s1 != CAMERA_SHAKE_COUNT);
}

void func_800E1804(void) {
    f32 func_800D8FF8(void);
    f32 func_800F0E00(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13F0(f32, f32);
    f32 func_800F3780(f32, u8 *, s16);
    f32 mlAbsF(f32);
    f32 decay;
    f32 dt;
    f32 value;
    s32 i;

    dt = func_800D8FF8();
    for (i = 0; i < CAMERA_SHAKE_COUNT; i++) {
        switch ((u8)D_8012CF90[i].active) {
            case 2:
                if (D_8012CF90[i].strength >= 0.0f) {
                    D_8012CF90[i].multiplier = (f32)1.0;
                } else {
                    D_8012CF90[i].multiplier = (f32)-1.0;
                }
                *(u8 *)&D_8012CF90[i].active = 3;
                D_8012CF90[i].decay_phase = 0;
                break;
            case 3:
                if (D_8012CF90[i].unk30 != 0.0f) {
                    D_8012CF90[i].unk30 = func_800F0E00(0.0f, D_8012CF90[i].unk30 - dt);
                    if ((u8)D_8012CF90[i].decay_phase) {
                        D_8012CF90[i].strength = func_800F10B4(D_8012CF90[i].unk30, D_8012CF90[i].unk18, 0.0f, D_8012CF90[i].unk24, D_8012CF90[i].unk20);
                    }
                } else if ((u8)D_8012CF90[i].decay_phase) {
                    decay = D_8012CF90[i].unk1C;
                    D_8012CF90[i].strength *= decay * decay;
                }
                D_8012CF90[i].decay_phase = (u8)D_8012CF90[i].decay_phase ^ 1;
                D_8012CF90[i].multiplier = -D_8012CF90[i].multiplier;
                if (D_8012CF90[i].unk1C != 1.0f && mlAbsF(D_8012CF90[i].strength) < 0.001f) {
                    func_800E1720(i);
                }
                break;
            case 4:
                if (D_8012CF90[i].unk30 < D_8012CF90[i].unk18) {
                    value = func_800F13F0(D_8012CF90[i].unk18, D_8012CF90[i].unk30 + dt);
                    D_8012CF90[i].unk30 = value;
                    D_8012CF90[i].strength = D_8012CF90[i].unk20 * func_800F3780(value / D_8012CF90[i].unk18, D_8012CF90[i].curve[0], D_8012CF90[i].curve_length);
                    D_8012CF90[i].multiplier = -D_8012CF90[i].multiplier;
                } else {
                    func_800E1720(i);
                }
                break;
        }
    }
}

void func_800E1A58(f32 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800F0E00(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    BT_IDO_ONLY(extern u8 D_8012D468[];)
    CameraShake *entry;
    f32 position[3];
    f32 scale;
    f32 distance;
    s32 type;
    s32 index;

    func_800EE7F8(position, arg0);
    index = 0;
    do {
        entry = &D_8012CF90[index];
        scale = 1.0;
        if ((u8)entry->active != 1) {
            if ((u8)entry->updated != 0) {
                distance = func_800EEAD4(position, entry->position);
                scale = func_800F10B4(distance, entry->min, entry->max, 1.0f, 0.0f);
                scale = func_800F0E00(scale, entry->floor);
                if (!scale) {
                    goto next;
                }
            }
            type = (u8)entry->active;
            switch (type) {
                case 2:
                    func_800E1294((u8)entry->unk75, arg0, arg1, entry->strength * scale);
                    break;
                case 3:
                case 4:
                    func_800E1294((u8)entry->unk75, arg0, arg1, (entry->strength * entry->multiplier) * scale);
                    break;
            }
        }
    next:
        index++;
    } while (BT_DATA_FIELD(index != CAMERA_SHAKE_COUNT, (void *)D_8012D468 != (void *)&D_8012CF90[index]));
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_8012D468 [ 8 ] BT_DATA(4, bss_core2bss2_1, 0xB28);
#endif
