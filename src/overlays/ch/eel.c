#include "common.h"

/* extern */

void func_80800000_cheel(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct {
        s32 unk0;
        f32 unk4[9];
        f32 unk28[9];
        f32 unk4C[9];
        f32 unk70[9];
        f32 unk94[9];
        f32 unkB8[9];
    } *data;
    s32 i;

    data = func_80100094(arg0, 0U);
    for (i = 0; i < 9; i++) {
        data->unk28[i] = 0.0f;
        data->unk4[i] = 0.0f;
        data->unk94[i] = 0.0f;
        data->unk70[i] = 0.0f;
        data->unk4C[i] = 0.0f;
        data->unkB8[i] = 0.0f;
    }
}

/* extern */

void func_808000B4_cheel(Actor *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_80801200_cheel(Actor *, s32);
    union {
        Actor actor;
        struct {
            u8 pad0[0x18];
            f32 pad18[3];
            f32 unk24;
            f32 unk28[3];
            f32 unk34;
            u8 pad38[0x3B];
            u8 pad73 : 7;
            u8 unk73_0 : 1;
        } eel;
    } *data = (void *)arg0;

    func_80800000_cheel(arg0);
    data->eel.unk34 = 0.0f;
    func_80801200_cheel(arg0, 1);
    func_800EE7F8(data->eel.unk28, arg0->position);
    data->eel.unk73_0 = 1;
    arg0->unk64_25 = 1;
    data->eel.unk24 = arg0->scale * 1000.0f;
}

void func_80800128_cheel(Actor *arg0) {
    void func_800C8B84(s32);
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;
    u8 *sp1C;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(s32 *)((s8 *)(temp_v0) + (0xDC))) != 0) {
        sp1C = temp_v0;
        func_800C8B84((*(s32 *)((s8 *)(temp_v0) + (0xDC))));
        (*(s32 *)((s8 *)(sp1C) + (0xDC))) = 0;
    }
}

void func_80800168_cheel(Actor *arg0) {
    void func_80102B2C(Actor *, f32);
    void func_80102B6C(u8 *, f32);
    s32 func_8010B990(Actor *, s32);
    void func_80801200_cheel(Actor *, s32);
    union {
        Actor actor;
        struct {
            u8 pad0[0x64];
            u32 pad64_30 : 2;
            u32 unk64_29 : 1;
            u32 pad64_0 : 29;
        } eel;
    } *data = (void *)arg0;

    if (data->eel.unk64_29) {
        func_80102B6C((u8 *)arg0, 8.0f);
        func_80102B2C(arg0, 4.0f);
    } else {
        func_80102B6C((u8 *)arg0, 5.0f);
        func_80102B2C(arg0, 3.0f);
    }
    if ((func_8010B990(arg0, 0x500006) & 0x24) && arg0->unk70_10 != 2) {
        func_80801200_cheel(arg0, 2);
    }
}

/* extern */

typedef union {
    Actor actor;
    struct {
        u8 pad0[0x70];
        u32 unk70_25 : 7;
        u32 pad70_10 : 15;
        u32 unk70_4 : 6;
        u32 pad70_0 : 4;
    } eel;
} EelActor;

s32 func_8080020C_cheel(EelActor *arg0) {
    s32 func_800CC338(f32 (*)[3], s32, s32);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 sp24[3];
    s32 result;

    func_800EEC30(sp24, arg0->actor.rotation[0], arg0->actor.rotation[1], 200.0f);
    func_800EF04C(sp24, arg0->actor.position);
    result = func_800CC338(&sp24, arg0->eel.unk70_25 - 1, arg0->eel.unk70_4 - 1);
    if (result != -1) {
        arg0->eel.unk70_4 = result + 1;
        return 1;
    }
    return 0;
}

/* extern */

s32 func_808002A0_cheel(u8 *arg0) {
    s32 func_800EFFB4(u8 *, s32, u8 *, u8 *);
    f32 func_800F1DCC(f32, f32);
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = func_800F1DCC((*(f32 *)((s8 *)(arg0) + (0x48))), (*(f32 *)((s8 *)(arg0) + (0x54))));
    var_f2 = temp_f0;
    if (temp_f0 < 0.0f) {
        var_f2 = -temp_f0;
    }
    if ((var_f2 < 30.0f) || (func_800EFFB4(arg0 + 0x18, 0x43480000, arg0 + 4, arg0) != 0)) {
        return 1;
    }
    return 0;
}

void func_8080031C_cheel(Actor *arg0) {
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800E0AF0(void *, f32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    f32 func_800F1828(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_8010262C(Unk80132ED0 *, u32);
    s32 func_80107070(Actor *, s32);
    s32 func_8010C500(void *);
    void func_8010CE28(s32, f32 *);
    void func_80800D60_cheel(Actor *);
    void func_80801120_cheel(Actor *);
    void func_80801200_cheel(Actor *, s32);
    void *model;
    s32 i;
    struct { f32 values[55]; } *data;
    f32 dt;
    f32 angles3[2];
    f32 angles5[2];
    f32 angles6[2];
    typedef union {
        Actor actor;
        EelActor base;
        struct {
            u8 pad0[0x18];
            f32 position[3];
            f32 speed;
        } eel;
    } EelUpdateActor;

    data = func_80100094(arg0, 0);
    dt = func_800D8FF8();
    model = (void *)func_8010262C(((EelUpdateActor *)arg0)->actor.unk0, 10);
    if (model != NULL) {
        if (((EelUpdateActor *)arg0)->actor.unk64_20) {
            if (data->values[0] < 1) {
                data->values[0] += dt;
                if (data->values[0] > 1) {
                    data->values[0] = 1;
                }
            }
        } else {
            if (data->values[0] > 0) {
                data->values[0] -= dt;
                if (data->values[0] < 0) {
                    data->values[0] = 0;
                }
            }
        }
        func_800E0AF0(model, data->values[0]);
        /* IDO: this always-true guard preserves AS1's original block weights.
         * Its unsigned arithmetic and the aligned marker self-copy preserve
         * scratch-register order; AS1 removes all of their instructions. */
        if (((u64)(((((u32)arg0->pointerToSyscallEntry + 1U) ^ 1U) + 1U) ^ 1U) & 0xffffffffULL) <= 0xffffffffULL) {
            /* Markers have four-byte alignment; the mask preserves the pointer. */
            i = (s32)((u32)arg0->unk0 & ~3U);
            *(Unk80132ED0 *)i = *(Unk80132ED0 *)i;
            i = 8;
            do {
                data->values[1 + i + 1] += func_800F1DCC(data->values[1 + i], data->values[1 + i + 1]) * 0.25f;
                data->values[28 + i + 1] += func_800F1DCC(data->values[28 + i], data->values[28 + i + 1]) * 0.25f;
            } while (--i >= 0);
            data->values[1 + 0] = func_800136E4(data->values[1 + 0]);
            data->values[1 + 0] += func_800F1DCC(((EelUpdateActor *)arg0)->actor.rotation[1], data->values[1 + 0]) * 0.25f;
            data->values[10 + 0] = func_800F1DCC(data->values[1 + 0], ((EelUpdateActor *)arg0)->actor.rotation[1]);
            data->values[28 + 0] = func_800136E4(data->values[28 + 0]);
            data->values[28 + 0] += func_800F1DCC(((EelUpdateActor *)arg0)->actor.rotation[0], data->values[28 + 0]) * 0.25f;
            data->values[37 + 0] = -func_800F1DCC(data->values[28 + 0], ((EelUpdateActor *)arg0)->actor.rotation[0]);
            for (i = 1; i < 9; i++) {
                data->values[10 + i] = func_800F1DCC(data->values[1 + i], data->values[1 + i - 1]);
                data->values[37 + i] = -func_800F1DCC(data->values[28 + i], data->values[28 + i - 1]);
            }
            i = 0;
            do {
                data->values[19 + i] += func_800F1DCC(data->values[10 + i], data->values[19 + i]) * 0.25f;
                data->values[46 + i] += func_800F1DCC(data->values[37 + i], data->values[46 + i]) * 0.25f;
            } while (++i < 9);
            func_800E0AFC(model, 3, -1, 0.0, 0.0, 0.0);
            func_800E0AFC(model, 0x2A, 1, data->values[46 + 0], data->values[19 + 0], 0.0);
            func_800E0AFC(model, 0x2B, 1, data->values[46 + 1], data->values[19 + 1], 0.0);
            func_800E0AFC(model, 0x2C, 1, data->values[46 + 2], data->values[19 + 2], 0.0);
            func_800E0AFC(model, 0x2D, 1, data->values[46 + 3], data->values[19 + 3], 0.0);
            func_800E0AFC(model, 0x2E, 1, data->values[46 + 4], data->values[19 + 4], 0.0);
            func_800E0AFC(model, 0x2F, 1, data->values[46 + 5], data->values[19 + 5], 0.0);
            func_800E0AFC(model, 0x30, 1, data->values[46 + 6], data->values[19 + 6], 0.0);
            func_800E0AFC(model, 0x31, 1, data->values[46 + 7], data->values[19 + 7], 0.0);
            func_800E0AFC(model, 0x32, 1, data->values[46 + 8], data->values[19 + 8], 0.0);
        }
    }
    switch (((EelUpdateActor *)arg0)->actor.unk70_10) {
    case 1:
        func_80800168_cheel(arg0);
        if (!func_8080020C_cheel(&((EelUpdateActor *)arg0)->base)) {
            func_80801200_cheel(arg0, 2);
        } else if (func_8010C500(arg0)) {
            func_80801200_cheel(arg0, 3);
        } else if (((EelUpdateActor *)arg0)->eel.speed > 1000.0f * ((EelUpdateActor *)arg0)->actor.scale) {
            ((EelUpdateActor *)arg0)->eel.speed -= 10.0f * ((EelUpdateActor *)arg0)->actor.scale;
        }
        func_80800D60_cheel(arg0);
        if (((EelUpdateActor *)arg0)->actor.unk64_29) {
            ((EelUpdateActor *)arg0)->eel.speed = _subaddiejoy_entrypoint_9(arg0, &((EelUpdateActor *)arg0)->actor.unk54, 3) * 1000.0f * ((EelUpdateActor *)arg0)->actor.scale;
            if (((EelUpdateActor *)arg0)->eel.speed < 250.0f * ((EelUpdateActor *)arg0)->actor.scale) {
                ((EelUpdateActor *)arg0)->eel.speed = 250.0f * ((EelUpdateActor *)arg0)->actor.scale;
            }
        }
        break;
    case 2:
        func_80801120_cheel(arg0);
        ((EelUpdateActor *)arg0)->actor.unk54 = func_800F1DF4(((EelUpdateActor *)arg0)->actor.position, ((EelUpdateActor *)arg0)->eel.position);
        ((EelUpdateActor *)arg0)->actor.unk50 = func_800F1828(((EelUpdateActor *)arg0)->actor.position, ((EelUpdateActor *)arg0)->eel.position);
        func_80800168_cheel(arg0);
        if (func_808002A0_cheel((u8 *)arg0)) {
            if (func_8080020C_cheel(&((EelUpdateActor *)arg0)->base)) {
                func_80801200_cheel(arg0, 1);
            }
        } else if (((EelUpdateActor *)arg0)->eel.speed > 800.0f * ((EelUpdateActor *)arg0)->actor.scale) {
            ((EelUpdateActor *)arg0)->eel.speed -= 30.0f * ((EelUpdateActor *)arg0)->actor.scale;
        }
        func_80800D60_cheel(arg0);
        break;
    case 3:
        func_8010CE28((s32)arg0, angles3);
        ((EelUpdateActor *)arg0)->actor.unk50 = -angles3[0];
        if (((EelUpdateActor *)arg0)->actor.unk64_29) {
            ((EelUpdateActor *)arg0)->eel.speed = _subaddiejoy_entrypoint_9(arg0, &((EelUpdateActor *)arg0)->actor.unk54, 3) * 1000.0f * ((EelUpdateActor *)arg0)->actor.scale;
            if (((EelUpdateActor *)arg0)->eel.speed < 250.0f * ((EelUpdateActor *)arg0)->actor.scale) {
                ((EelUpdateActor *)arg0)->eel.speed = 250.0f * ((EelUpdateActor *)arg0)->actor.scale;
            }
        } else {
            ((EelUpdateActor *)arg0)->actor.unk54 = angles3[1];
            if (func_800DC298(0.05f)) {
                ((EelUpdateActor *)arg0)->actor.unk54 += func_800DC178(-90.0f, 90.0f);
            }
        }
        func_80800168_cheel(arg0);
        if (!func_8010C500(arg0)) {
            func_80801200_cheel(arg0, 1);
        } else if (!func_8080020C_cheel(&((EelUpdateActor *)arg0)->base)) {
            func_80801200_cheel(arg0, 4);
        } else if (((EelUpdateActor *)arg0)->eel.speed < 1600.0f * ((EelUpdateActor *)arg0)->actor.scale) {
            ((EelUpdateActor *)arg0)->eel.speed += 10.0f * ((EelUpdateActor *)arg0)->actor.scale;
        }
        func_80800D60_cheel(arg0);
        break;
    case 4:
        func_80801120_cheel(arg0);
        ((EelUpdateActor *)arg0)->actor.unk54 = func_800F1DF4(((EelUpdateActor *)arg0)->actor.position, ((EelUpdateActor *)arg0)->eel.position);
        ((EelUpdateActor *)arg0)->actor.unk50 = func_800F1828(((EelUpdateActor *)arg0)->actor.position, ((EelUpdateActor *)arg0)->eel.position);
        func_80800168_cheel(arg0);
        if (func_808002A0_cheel((u8 *)arg0)) {
            if (func_8080020C_cheel(&((EelUpdateActor *)arg0)->base)) {
                func_80801200_cheel(arg0, 1);
            }
        } else if (((EelUpdateActor *)arg0)->eel.speed > 800.0f * ((EelUpdateActor *)arg0)->actor.scale) {
            ((EelUpdateActor *)arg0)->eel.speed -= 30.0f * ((EelUpdateActor *)arg0)->actor.scale;
        }
        func_80800D60_cheel(arg0);
        break;
    case 5:
        func_8010CE28((s32)arg0, angles5);
        ((EelUpdateActor *)arg0)->actor.unk50 = angles5[0];
        ((EelUpdateActor *)arg0)->actor.unk54 = -angles5[1];
        func_80800168_cheel(arg0);
        if (!func_8010C500(arg0)) {
            func_80801200_cheel(arg0, 1);
        } else if (!func_8080020C_cheel(&((EelUpdateActor *)arg0)->base)) {
            func_80801200_cheel(arg0, 2);
        } else if (((EelUpdateActor *)arg0)->eel.speed < 1600.0f * ((EelUpdateActor *)arg0)->actor.scale) {
            ((EelUpdateActor *)arg0)->eel.speed += 10.0f * ((EelUpdateActor *)arg0)->actor.scale;
        }
        func_80800D60_cheel(arg0);
        break;
    case 6:
        func_8010CE28((s32)arg0, angles6);
        ((EelUpdateActor *)arg0)->actor.unk50 = angles6[0];
        ((EelUpdateActor *)arg0)->actor.unk54 = -angles6[1];
        func_80800168_cheel(arg0);
        if (((EelUpdateActor *)arg0)->actor.unk58 > 0.0f) {
            ((EelUpdateActor *)arg0)->actor.unk58 -= func_800D8FF8();
            if (!func_8080020C_cheel(&((EelUpdateActor *)arg0)->base)) {
                func_80801200_cheel(arg0, 7);
            } else if (((EelUpdateActor *)arg0)->eel.speed < 1600.0f * ((EelUpdateActor *)arg0)->actor.scale) {
                ((EelUpdateActor *)arg0)->eel.speed += 10.0f * ((EelUpdateActor *)arg0)->actor.scale;
            }
        } else {
            func_80801200_cheel(arg0, 1);
        }
        break;
    case 7:
        func_80801120_cheel(arg0);
        ((EelUpdateActor *)arg0)->actor.unk54 = func_800F1DF4(((EelUpdateActor *)arg0)->actor.position, ((EelUpdateActor *)arg0)->eel.position);
        ((EelUpdateActor *)arg0)->actor.unk50 = func_800F1828(((EelUpdateActor *)arg0)->actor.position, ((EelUpdateActor *)arg0)->eel.position);
        func_80800168_cheel(arg0);
        if (((EelUpdateActor *)arg0)->actor.unk58 > 0.0f) {
            ((EelUpdateActor *)arg0)->actor.unk58 -= func_800D8FF8();
        } else {
            func_80801200_cheel(arg0, 1);
        }
        if (((EelUpdateActor *)arg0)->eel.speed > 800.0f * ((EelUpdateActor *)arg0)->actor.scale) {
            ((EelUpdateActor *)arg0)->eel.speed -= 30.0f * ((EelUpdateActor *)arg0)->actor.scale;
        }
        if (func_808002A0_cheel((u8 *)arg0)) {
            if (func_8080020C_cheel(&((EelUpdateActor *)arg0)->base)) {
                func_80801200_cheel(arg0, 6);
            }
        }
        break;
    case 8:
        if (func_80101DDC(arg0)) {
            func_80801200_cheel(arg0, 2);
        }
        break;
    case 9:
        if (func_80101DDC(arg0)) {
            if (!func_80107070(arg0, 2)) {
                func_800FFAB0(arg0);
            }
        }
        break;
    }
}

void func_80800D60_cheel(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    s32 func_800B53A4(s32);
    void func_800BA1D0(s32, f32 *, f32 *, s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
    s32 func_800C8A98(void);
    void func_800C8B84(s32);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8FB0(s32, u32, u32, u32);
    f32 func_800D8FF8(void);
    void func_800DBEFC(s32 *, s32, f32 *);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    u32 func_8010A610(void **);
    extern u32 D_808015DC_cheel[];
    extern s32 D_80801608_cheel[];
    struct {
        s32 unk0;
        f32 unk4[9];
        f32 unk28[9];
        f32 unk4C[9];
        f32 unk70[9];
        f32 unk94[9];
        f32 unkB8[9];
        s32 unkDC;
    } *data;
    f32 position[3];
    s32 emitter1;
    s32 emitter2;

    data = func_80100094(arg0, 0);
    if (func_8010A610(arg0)) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808015DC_cheel);
        if (!arg0->unk64_29) {
            if (func_800DC0C0() < 0.5f && arg0->unk70_10 != 3) {
                func_8010A570(arg0);
                arg0->unk64_19 = 0;
            }
        } else if (!_subaddiejoy_entrypoint_6(arg0, 1)) {
            func_8010A570(arg0);
            arg0->unk64_19 = 0;
        }
        if (!func_8010A610(arg0)) {
            if (data->unkDC) {
                func_800C8B84(data->unkDC);
                data->unkDC = 0;
            }
        } else {
            if (func_800DC0C0() < 0.5f) {
                arg0->unk64_19 = (arg0->unk64_19 ^ 1) & 1;
            }
            if (arg0->unk58 > -0.15f) {
                arg0->unk58 -= func_800D8FF8();
            } else {
                arg0->unk58 = func_800DC178(0.15f, 0.5f);
                if (arg0->unk7C_12) {
                    emitter1 = func_800B53A4(4);
                    emitter2 = func_800B53A4(4);
                    func_800DBEFC(arg0->unk0->unk4, 4, position);
                    func_800DBEFC(arg0->unk0->unk4, 5, (void *)&arg0->actorData[4]);
                    func_800BABB8(emitter1, arg0->position, NULL, 1.0f, D_80801608_cheel);
                    func_800BA3FC(emitter1, 0x9E7);
                    func_800BA1D0(emitter1, arg0->position, (void *)&arg0->actorData[4], 4);
                    func_800BABB8(emitter2, (void *)&arg0->actorData[4], NULL, 1.0f, D_80801608_cheel);
                    func_800BA3FC(emitter2, 0x9E7);
                    func_800BA1D0(emitter2, (void *)&arg0->actorData[4], position, 4);
                }
            }
            if (data->unkDC) {
                if (arg0->unk64_19) {
                    func_800C8FB0(data->unkDC, 0x60, 0x60, 0x80);
                } else {
                    func_800C8FB0(data->unkDC, 0x40, 0x40, 0x60);
                }
                func_800C8CB8(data->unkDC, (void *)&arg0->actorData[4]);
            }
        }
    } else {
        if (arg0->unk64_29) {
            if (_subaddiejoy_entrypoint_6(arg0, 1)) {
                func_8010A590(arg0);
            }
        } else if (func_800DC0C0() < 0.5f || (arg0->unk70_10 == 3 && func_800DC0C0() < 0.2f)) {
            func_8010A590(arg0);
        }
        if (func_8010A610(arg0) && !data->unkDC) {
            data->unkDC = func_800C8A98();
            func_800C8E54(data->unkDC, 200.0f, 500.0f);
            func_800C8CB8(data->unkDC, (void *)&arg0->actorData[4]);
        }
    }
}

/* extern */

void func_80801120_cheel(Actor *arg0) {
    void *func_800CC63C(s32, s32);
    f32 func_800EEB40(f32 *, f32 *);
    struct EelRegion {
        f32 position[3];
        s16 unkC;
        s16 height;
        f32 radius;
    } *region;
    f32 y;
    f32 actorY;
    f32 height;
    s32 flag;
    union EelActorView {
        Actor actor;
        struct {
            u32 prefix[28];
            u32 regionGroup : 7;
            u32 unused : 15;
            u32 regionIndex : 6;
            u32 remaining : 4;
        } regions;
    } *eel = (void *)arg0;

    region = func_800CC63C(eel->regions.regionGroup - 1, eel->regions.regionIndex - 1);
    y = region->position[1];
    actorY = arg0->position[1];
    height = region->height;
    if (y + height <= actorY || actorY <= y - height) {
        ((f32 *)arg0->actorData)[1] = y;
    }
    flag = func_800EEB40(arg0->position, region->position) == 0.0f;
    if ((f32)flag < region->radius) {
        ((f32 *)arg0->actorData)[0] = region->position[0];
        ((f32 *)arg0->actorData)[2] = region->position[2];
    }
}

/* extern */

void func_80801200_cheel(Actor *arg0, s32 arg1) {
    s32 func_8008FD48();
    f32 func_800DC178(f32, f32);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    arg0->unk64_20 = 1;
    func_80102424(arg0, arg1);
    switch (arg1) {
    case 1:
        arg0->unk54 = arg0->rotation[1] + func_800DC178(-90.0f, 90.0f);
        arg0->unk50 = arg0->rotation[0] + func_800DC178(-90.0f, 90.0f);
        return;
    case 2:
        func_80801120_cheel(arg0);
        return;
    case 3:
        if (func_8008FD48() == 0xC) {
            arg0->unk70_10 = 5;
            return;
        }
    default:
        return;
    case 4:
        func_80801120_cheel(arg0);
        return;
    case 8:
        func_8010A570(arg0);
        return;
    case 6:
        func_8010A570(arg0);
        arg0->unk64_19 = 0;
        return;
    case 9:
    case 10:
    case 11:
    case 12:
        func_8010A570(arg0);
        arg0->unk64_20 = 0;
        break;
    }
}

s32 func_80801330_cheel(Actor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_8008FD48();
    void func_80090460(s32, s32);
    void func_800904C8(s32);
    void func_800DF5D8(u32, u32, u32, s32);
    void func_800DF744(s32, s32);
    void func_80101010(f32 *);
    s32 func_801015D0(Actor *);
    extern s32 D_808015F4_cheel;
    extern f32 D_80801638_cheel[];

    if (arg1 == 0x1F) goto event_1f;
    if (arg1 == 0x3E) goto event_3e;
    if (arg1 == 0x3F) goto event_3f;
    if (arg1 == 0x40) goto event_40;
    if (arg1 == 0x8F) goto event_8f;
    if (arg1 != 0x97) goto event_default;
    func_80101010(D_80801638_cheel);
    goto done;
event_1f:
        func_800DF744(3, arg0->unk64_19);
        if (arg0->unk64_19) {
            func_800DF5D8(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            func_800DF5D8(0x60, 0x60, 0x60, 0xFF);
        }
        func_801015D0(arg0);
        goto done;
event_3f:
        if ((arg2->unk24 >> 22) == 0x26E) {
            func_80801200_cheel(arg0, 6);
            arg0->unk58 = 10.0f;
        } else {
            func_80801200_cheel(arg0, 8);
        }
        goto done;
event_3e:
        if ((arg2->unk24 >> 22) == 0) {
            if (func_8008FD48() == 0xC) {
                func_800904C8(0x54);
            } else {
                func_80090460(0xF, (s32)arg0->unk0);
            }
        }
        goto done;
event_40:
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808015F4_cheel);
        func_80801200_cheel(arg0, 9);
        goto done;
event_8f:
        if (arg2 == (Unk80132ED0 *)4) {
            func_80800000_cheel(arg0);
        }
        goto done;
event_default:
        return 0;
done:
    return 1;
}

OSThread *cheel_entrypoint_0(void)
{
    extern u8 D_80801644_cheel[];

    return (OSThread *) D_80801644_cheel;
}
