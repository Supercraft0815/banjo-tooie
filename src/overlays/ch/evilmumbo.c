#include "common.h"

extern u32 D_80804090_chevilmumbo[];
void func_8080129C_chevilmumbo(Actor *);
void func_80105834(Actor *);
void func_801018A4(Actor *, s32);
void func_808023E8_chevilmumbo(Actor *);
OSThread *func_80108ED0(void);
void func_8080241C_chevilmumbo(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_80802618_chevilmumbo(Actor *, s32, s32);

u32 D_80804460_chevilmumbo[] = {
    0x005B037C, 0x06650001, (u32)D_80804090_chevilmumbo, (u32)func_8080129C_chevilmumbo,
    (u32)func_80105834, (u32)func_801018A4, 0x00000000, 0x00000000,
    0x00000000, 0x00800164, (u32)func_808023E8_chevilmumbo, (u32)func_80108ED0,
    0x00980000, (u32)func_8080241C_chevilmumbo, (u32)func_80107C2C, 0x80000400,
    (u32)func_80802618_chevilmumbo, 0x00000000,
};

s32 D_808044A8_chevilmumbo[] = {
    0x001D09E9, 0x00160200, 0x00150000, 0x0099002B,
    0x00C00100, 0x002200CC, 0x01000040, 0x0059002D,
    0x006400C8, 0x000E0028, 0x003C001B, 0xFF6AFF9C,
    0x0027FF38, 0xFF3800C8, 0x00C80000,
};

u32 D_808044E4_chevilmumbo[] = {
    0x000000FF, 0x00000060, 0x000000FF,
};

void func_80800000_chevilmumbo(Actor *arg0) {
    s32 _plcamera_entrypoint_9(s32, f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    s32 func_800F6C88(s32);
    void *func_80100094(Actor *, u32);
    void func_808000BC_chevilmumbo(Actor *);
    struct {
        u8 pad0[0x95];
        u8 unk95;
    } *data;
    f32 position[3];

    data = func_80100094(arg0, 0);
    if (data->unk95 == 3 && func_800F6C88(func_800F54E4()) == 0) {
        func_800EE7F8(position, arg0->position);
        position[1] += 100.0f;
        if (_plcamera_entrypoint_9(func_800F54E4(), position, 0.25f) == 0) {
            data->unk95 = 0;
            func_808000BC_chevilmumbo(arg0);
        }
    }
}

/* extern */

void func_80800098_chevilmumbo(s32 arg0) {
    s32 _capod_entrypoint_3(s32);
    _capod_entrypoint_3(0);
}

void func_808000BC_chevilmumbo(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    u32 func_800F54E4(void);
    s32 func_800F4AF4(u32, s32);
    void func_80800000_chevilmumbo(Actor *);
    struct {
        u8 pad0[0x95];
        u8 unk95;
    } *data;
    s32 state;

    data = func_80100094(arg0, 0);
    state = data->unk95;
    switch (state) {
    case 1:
    case 2:
        func_80800098_chevilmumbo((s32)arg0);
    case 0:
    case 3:
        data->unk95 = 3;
        func_800F4AF4(func_800F54E4(), 0x14);
        break;
    }
    func_80800000_chevilmumbo(arg0);
}

void func_80800144_chevilmumbo(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_6(Unk80132ED0 *);
    void _gcdialogcamera_entrypoint_8(void);
    s32 func_800F4B20(u32);
    u32 func_800F54E4(void);
    struct {
        u8 pad0[0x95];
        u8 unk95;
    } *sp1C, *temp_v0;
    s32 temp_v1;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    temp_v1 = temp_v0->unk95;
    switch (temp_v1) {
    case 3:
        func_800F4B20(func_800F54E4());
    case 0:
        _capod_entrypoint_2(arg0->unk0, 3, 0);
    case 1:
        _capod_entrypoint_8(1);
        sp1C->unk95 = 2;
        _gcdialogcamera_entrypoint_6(arg0->unk0);
        _gcdialogcamera_entrypoint_8();
    case 2:
        _capod_entrypoint_7(arg1, arg2);
    }
}

void func_808001F4_chevilmumbo(Actor *arg0, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
    s32 func_800F4B20(u32);
    u32 func_800F54E4(void);
    struct {
        u8 pad0[0x95];
        u8 unk95;
    } *sp1C, *temp_v0;
    s32 temp_v1;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    temp_v1 = temp_v0->unk95;
    switch (temp_v1) {
    case 3:
        func_800F4B20(func_800F54E4());
    case 0:
        _capod_entrypoint_2(arg0->unk0, 3, arg2);
    case 2:
        sp1C->unk95 = 1;
    case 1:
        _capod_entrypoint_6(arg3, arg1, arg2);
    }
}

void *func_80100094(Actor *, u32);

void func_80800290_chevilmumbo(Actor *arg0) {
    s32 func_800F4B20(u32);
    u32 func_800F54E4(void);
    struct {
        u8 pad0[0x95];
        u8 unk95;
    } *sp1C, *temp_v0;
    u8 temp_v1;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    temp_v1 = temp_v0->unk95;
    if ((temp_v1 != 1) && (temp_v1 != 2)) {
        if (temp_v1 == 3) {
            func_800F4B20(func_800F54E4());
        }
    } else {
        func_80800098_chevilmumbo(arg0);
    }
    sp1C->unk95 = 0;
}

void func_80800300_chevilmumbo(s32 *arg0) {
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, s32);
    s32 func_8008F938(s32);
    s32 func_8008F990(s32 *, s32);
    extern s32 D_80804294_chevilmumbo;
    extern s32 func_8010D5DC;
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *arg0);
    func_8008F990(&D_80804294_chevilmumbo, 0x43480000);
}

/* extern */

void func_80800354_chevilmumbo(Actor *arg0, s16 arg1, s32 arg2) {
    s32 func_800C05B8(s32, s32, f32 *, Unk80132ED0 *, s32, s32, s16);
    s32 var_a1;
    s32 var_v0;

    if (arg0->unk64_20) {
        var_v0 = 0x77;
    } else {
        var_v0 = 0x10;
    }
    if (arg2 != 0) {
        var_v0 = arg2;
    }
    if (arg1 == 0xCEB) {
        var_a1 = 0x46;
    } else {
        var_a1 = 7;
    }
    func_800C05B8(arg1, var_a1, arg0->position, arg0->unk0, 0, 0, var_v0);
    arg0->unk74_30 = 1;
}

void func_808003DC_chevilmumbo(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80090708(s32);
    s32 _suexpression_entrypoint_12(void *, f32, f32);
    u32 func_800F54E4(void);
    void func_800F4CC0(s32);
    u32 func_800FDC28(u32);
    void func_80800ECC_chevilmumbo(Actor *, s32);
    void func_80090734(s32, f32 *);
    void func_800F4CEC(s32, u32);
    void func_800DA544(s32);
    void func_8010A570(Actor *);
    s32 func_800D395C(void);
    s32 func_800D1000(s32, s32, s32 *, s32, Unk80132ED0 *);
    void func_800EE7F8(f32 *, f32 *);
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _gcfrontend_entrypoint_10(void);
    void func_800FFAB0(Actor *);
    struct {
        f32 points[12][3];
        u8 state;
        u8 pad91[5];
        u8 unk96;
    } *data;
    f32 position[3];

    data = func_80100094(arg0, 0);
    switch (data->state) {
        case 1:
            func_80090708(0);
            break;
        case 4:
            _suexpression_entrypoint_12(func_80100094(arg0, 1), 60.0f, 0.0f);
            break;
        case 8:
            func_800F4CC0(func_800F54E4());
            func_800FDC28(10);
            func_80800ECC_chevilmumbo(arg0, 1);
            break;
    }
    data->state = arg1;
    switch (data->state) {
        case 1:
            func_80090734(2, arg0->position);
            func_800F4CEC(func_800F54E4(), 0x3F);
            func_808001F4_chevilmumbo(arg0, 7, 0x20, NULL);
            break;
        case 10:
            func_80800354_chevilmumbo(arg0, 0x11E0, 0);
            break;
        case 6:
            func_800DA544(0xA33);
            if (data->unk96 == 0) {
                func_808001F4_chevilmumbo(arg0, 1, 0x20, NULL);
            }
            break;
        case 8:
            func_80800354_chevilmumbo(arg0, 0x11E3, 0);
            break;
        case 4:
            func_8010A570(arg0);
            if (func_800D395C() == 0) {
                func_800D1000(0x47, 1, NULL, 1, arg0->unk0);
                func_808001F4_chevilmumbo(arg0, 15, 0x20, NULL);
                arg0->unk58 = 2.0f;
            } else {
                func_808003DC_chevilmumbo(arg0, 9);
            }
            break;
        case 9:
            func_808001F4_chevilmumbo(arg0, 9, 0x20, NULL);
            func_800EE7F8(position, arg0->position);
            position[1] -= 100.0f;
            _chexploder_entrypoint_3(arg0, position, 3);
            break;
        case 5:
            if (func_800D395C() != 0) {
                _gcfrontend_entrypoint_10();
            } else {
                func_80800290_chevilmumbo(arg0);
                func_80090708(0);
            }
            func_800FFAB0(arg0);
            break;
        case 7:
            func_800DA544(0xA32);
            func_808001F4_chevilmumbo(arg0, 3, 0x20, NULL);
            break;
    }
}

void func_80800670_chevilmumbo(Actor *arg0) {
    s32 func_800DC128(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    int func_800EECE0(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    struct {
        f32 position[3];
    } local;
    struct {
        f32 points[12][3];
        u8 unk90;
        u8 count;
    } *data;

    data = func_80100094(arg0, 0);
    func_800EE7F8(local.position, arg0->position);
    while (func_800EECE0(local.position, arg0->position) ||
        func_800EEB40(local.position, (f32 *)arg0->actorData) < 62500.0f) {
        func_800EE7F8(local.position, data->points[func_800DC128(0, data->count)]);
    }
    func_800EE7F8(arg0->position, local.position);
}

void func_80800774_chevilmumbo(Actor *arg0) {
    func_801032B0(arg0, 0x816, arg0->unk0->unk16);
    arg0->unk64_20 = 1;
    _suexpression_entrypoint_4(func_80100094(arg0, 1), 0x77);
}

s32 func_808007C4_chevilmumbo(Actor *arg0, s32 arg1) {
    s32 _chintrotext_entrypoint_1(s32, s32, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _suexpression_entrypoint_12(void *, f32, f32);
    void func_80090734(s32, f32 *);
    int func_800DC298(f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void func_80101CDC(Actor *, f32);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void func_8010A800(Actor *, s32);
    extern u8 D_80804140_chevilmumbo[];
    extern u8 D_8080414C_chevilmumbo[];
    extern u8 D_80804190_chevilmumbo[];
    extern u8 D_80804198_chevilmumbo[];
    extern u8 D_808041C0_chevilmumbo[];
    extern f32 D_8080427C_chevilmumbo[3];
    struct {
        u8 pad0[0x84];
        s8 pattern[10];
        u8 pad8E[4];
        u8 unk92;
        u8 unk93;
        u8 pad94;
        u8 unk95;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
    case 6:
        func_80800774_chevilmumbo(arg0);
        arg0->unk6C_0 = 0;
        _chintrotext_entrypoint_1(0x18B9, 8, 1, 0);
        func_800FDC28(1);
        break;
    case 4:
        arg0->unk74_29 = 0;
        break;
    case 9:
    case 19:
        arg0->unk74_29 = 0;
        break;
    case 12:
        func_8010A800(arg0, 1);
        break;
    case 11:
        func_8010A590(arg0);
        arg0->unk64_16 = 1;
        break;
    }
    func_80102424(arg0, arg1);
    switch (arg0->unk70_10) {
    case 21:
        data->pattern[0] = 2;
        data->pattern[1] = 1;
        data->pattern[2] = 2;
        data->pattern[3] = 1;
        data->pattern[4] = 2;
        data->pattern[5] = 2;
        data->pattern[6] = 1;
        data->pattern[7] = 2;
        data->pattern[8] = 2;
        data->pattern[9] = 2;
        func_800EE7F8(arg0->position, D_8080427C_chevilmumbo);
        func_80800774_chevilmumbo(arg0);
        arg0->unk74_29 = 1;
        break;
    case 2:
        func_80800300_chevilmumbo((s32 *)arg0);
        break;
    case 1:
        _suexpression_entrypoint_12(func_80100094(arg0, 1), 0.0f, 0.0f);
        break;
    case 5:
        func_808001F4_chevilmumbo(arg0, 5, 0x20, NULL);
        break;
    case 4:
        arg0->unk74_29 = 1;
        break;
    case 7:
    case 13:
        arg0->unk74_29 = 1;
        break;
    case 8:
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080414C_chevilmumbo);
        arg0->unk6C_0--;
        break;
    case 10:
        func_8010A800(arg0, 2);
        func_80101EE4(arg0, 0.677f);
        func_80101CDC(arg0, 0.75f);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804140_chevilmumbo);
        break;
    case 9:
        if (data->unk93 < 5) {
            arg0->unk58 = 0.0f;
        } else {
            arg0->unk58 = 0.5f;
        }
        break;
    case 19:
        if (data->unk93 < 5) {
            arg0->unk58 = 2.0f;
        } else {
            arg0->unk58 = 3.0f;
        }
        arg0->unk74_29 = 0;
        break;
    case 14:
        func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
        ((f32 *)arg0->actorData)[3] = 500.0f;
        if (func_800DC298(0.5f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804190_chevilmumbo);
        } else {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804198_chevilmumbo);
        }
        break;
    case 18:
        func_808001F4_chevilmumbo(arg0, 13, 0x30, NULL);
        func_80800354_chevilmumbo(arg0, 0x11E5, 0);
        break;
    case 12:
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804140_chevilmumbo);
        func_80800670_chevilmumbo(arg0);
        arg0->rotation[1] = func_800F1DF4(arg0->position, (f32 *)arg0->actorData);
        func_80101CDC(arg0, 0.75f);
        break;
    case 11:
        arg0->unk58 = 0.0f;
        func_8010A570(arg0);
        arg0->unk64_16 = 0;
        break;
    case 15:
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808041C0_chevilmumbo);
        func_80090734(2, arg0->position);
        data->unk92 = 0;
        func_80800144_chevilmumbo(arg0, 3, 1);
        func_80800354_chevilmumbo(arg0, 0x11E1, 0);
        arg0->unk50 = arg0->rotation[1];
        ((f32 *)arg0->actorData)[3] = 4.5f;
        break;
    case 16:
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808041C0_chevilmumbo);
        arg0->unk58 = 7.0f;
        break;
    case 20:
        if (data->unk95) {
            func_80800290_chevilmumbo(arg0);
        }
        func_800FDC28(0);
        break;
    }
}

void func_80800C50_chevilmumbo(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_800DC0C0(void);
    void _chexploder_entrypoint_3(void *, void *, u32);
    struct {
        u8 pad0[0x84];
        u8 pattern[10];
        u8 pad8E[5];
        u8 unk93;
        u8 unk94;
    } *data;

    data = func_80100094(arg0, 0);
    arg0->unk79_4++;
    data->unk93--;
    switch (arg0->unk79_4) {
    case 1:
        if (func_800DC0C0()) {
            data->pattern[3] = 2;
            data->unk94 = 0;
        } else {
            data->pattern[4] = 2;
            data->pattern[1] = 1;
            data->unk94 = 1;
        }
        break;
    case 2:
        if (func_800DC0C0()) {
            data->pattern[5] = 2;
            data->unk94 = 2;
        } else {
            data->pattern[6] = 2;
            data->unk94 = 3;
        }
        break;
    case 3:
        if (data->pattern[4] == 2) {
            data->pattern[3] = 2;
            data->unk94 = 0;
        } else {
            data->pattern[4] = 2;
            data->pattern[1] = 1;
            data->unk94 = 1;
        }
        break;
    case 4:
        data->pattern[2] = 2;
        data->unk94 = 5;
        break;
    case 5:
        data->pattern[7] = 2;
        data->pattern[8] = 2;
        data->unk94 = 6;
        break;
    case 6:
        if (data->pattern[6] == 2) {
            data->pattern[5] = 2;
            data->unk94 = 2;
        } else {
            data->pattern[6] = 2;
            data->unk94 = 3;
        }
        break;
    case 7:
        data->pattern[2] = 3;
        data->unk94 = 4;
        break;
    case 8:
        data->unk94 = 7;
        break;
    }
    if (data->unk93 > 0) {
        func_808007C4_chevilmumbo(arg0, 14);
        _chexploder_entrypoint_3(arg0, arg0->position, 3);
    } else {
        func_808007C4_chevilmumbo(arg0, 15);
    }
}

/* extern */

int func_80800E50_chevilmumbo(Actor *arg0) {
    f32 func_800F1DCC(f32, f32);
    f32 temp_f0;
    int var_v0;

    temp_f0 = func_800F1DCC(arg0->unk54, arg0->rotation[1]);
    if ((temp_f0 < -3.0f) || (var_v0 = 1, (temp_f0 > 3.0f))) {
        var_v0 = 0;
        arg0->rotation[1] += temp_f0 * 0.1f;
        return var_v0;
    }
    return var_v0;
}

/* extern */

void func_80800ECC_chevilmumbo(Actor *arg0, s32 arg1) {
    s32 func_808007C4_chevilmumbo(Actor *, s32);
    if ((s32) (*(u8 *)((s8 *)(func_80100094(arg0, 0U)) + (0x93))) < 5) {
        if (!((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF)) {
            (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) (((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00) | 4);
        }
    } else {
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) (((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00) | 4);
    }
    if (arg1 != 0) {
        func_808007C4_chevilmumbo(arg0, 7);
        return;
    }
    func_808007C4_chevilmumbo(arg0, 8);
}

void func_80800F60_chevilmumbo(Actor *arg0, f32 *arg1, f32 *arg2) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F1B78(f32 *, f32 *, f32, f32);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp34, arg1);
    func_800EE7F8(sp28, arg1);
    sp34[1] += 50.0f;
    sp28[1] -= 50.0f;
    if (func_800BEF00(sp34, sp28, sp1C, arg0->unk14) != 0) {
        arg1[1] = sp28[1];
        func_800F1B78(arg2, sp1C, arg0->rotation[1], 1.0f);
    }
}

void func_80800FF8_chevilmumbo(Actor *arg0) {
    void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_800BA22C(s32, s32);
    s32 func_800BA994(s32, s32, s16, s32, s32, s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    int func_800DC298(f32);
    extern s32 D_808042A0_chevilmumbo;
    f32 sp34[3];
    s32 sp30;

    _subaddieskeleton_entrypoint_2(arg0->unk0, 0xC, sp34);
    sp30 = func_800BABB8(0, sp34, 0, arg0->scale, &D_808042A0_chevilmumbo);
    func_800BA994(sp30, -0x4B, (s16)arg0->unk50, 0x96, -0x4B, (s16)arg0->unk50, 0xFA);
    func_800BA22C(sp30, 8);
    arg0->unk50 += ((f32 *)arg0->actorData)[3];
    if (func_800DC298(0.2f) != 0) {
        ((f32 *)arg0->actorData)[3] = -((f32 *)arg0->actorData)[3];
    }
}

void func_808010C4_chevilmumbo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_800BA22C(s32, s32);
    void func_800BA77C(s32, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_80800F60_chevilmumbo(Actor *, f32 *, f32 *);
    extern s32 D_808042D0_chevilmumbo;
    extern s32 D_808042F4_chevilmumbo;
    f32 sp3C[3];
    f32 sp30[3];
    s32 sp2C;
    s32 temp_v0;

    _subaddieskeleton_entrypoint_2(arg0->unk0, 0xC, sp30);
    sp3C[1] = arg0->rotation[1];
    sp3C[0] = 0.0f;
    sp3C[2] = 0.0f;
    func_80800F60_chevilmumbo(arg0, sp30, sp3C);
    temp_v0 = func_800BABB8(0, sp30, 0, arg0->scale * 0.25f, &D_808042D0_chevilmumbo);
    sp2C = temp_v0;
    func_800BA77C(temp_v0, (s16) (s32) sp3C[0], (s16) (s32) sp3C[1], (s16) (s32) sp3C[2]);
    func_800BA22C(sp2C, 1);
    _subaddieaudioquick_entrypoint_2(arg0, sp30, &D_808042F4_chevilmumbo);
}

void func_808011B8_chevilmumbo(Actor *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80804304_chevilmumbo;
    f32 *temp_a0;

    temp_a0 = arg0->position;
    func_800BBCB8(temp_a0, temp_a0, 1.0f, 1, &D_80804304_chevilmumbo);
}

void func_808011F4_chevilmumbo(Actor *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    int func_800DC298(f32);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    extern s32 D_8080434C_chevilmumbo;
    s32 sp34;
    f32 sp28[3];
    f32 angle;

    sp34 = func_800B53A4(4);
    angle = arg0->unk58 * 720.0f;
    func_800EEB9C(sp28, angle, 30.0f);
    func_800EF04C(sp28, arg0->position);
    func_800BABB8(sp34, sp28, NULL, 1.0f, &D_8080434C_chevilmumbo);
    func_800BA22C(sp34, 4);
    if (func_800DC298(0.4f) != 0) {
        func_808011B8_chevilmumbo(arg0);
    }
}

void func_8080129C_chevilmumbo(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _gcfrontend_entrypoint_9(s32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    s32 _subaddiedialog_entrypoint_3(f32 *, s32, s32, s32, s32);
    s32 _subaddiefade_entrypoint_1(Actor *, s32);
    void _subaddiefade_entrypoint_8(Actor *, s32);
    void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, u32);
    s32 func_8001210C(s32);
    s32 func_8008FA60(s32, s32);
    s32 func_8008FB10(f32 *, f32, f32, f32);
#ifdef BT_NATIVE
    s32 func_80090178(s32);
#else
    s32 func_80090178(AllowedTransformation);
#endif
    s32 func_80090248(void);
    void func_80090734(s32, f32 *);
    void func_800C4140(u32, f32 *, u32);
    s32 func_800D2498(u32, s32, u32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
#ifndef BT_NATIVE
    void func_800DA544(GameFlag);
#endif
    s32 func_800DA9E4(GameFlag, s32);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    u32 func_800FDC28(u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, u32 *);
    f32 func_80101F24(Actor *);
    s32 func_801022E4(Actor *);
    void func_80108B04(Actor *, s32);
    s32 func_8010D23C(void);
    void func_8010D254(f32 *);
    s32 func_8010D278(void);
    void func_808003DC_chevilmumbo(Actor *, s32);
    extern u32 D_8080415C_chevilmumbo[], D_8080416C_chevilmumbo[];
    extern u32 D_80804178_chevilmumbo[], D_80804184_chevilmumbo[];
    extern u32 D_808041A4_chevilmumbo[], D_808041D0_chevilmumbo[];
    extern u32 D_808041DC_chevilmumbo[], D_808041E8_chevilmumbo[];
    extern u32 D_808041F8_chevilmumbo[], D_80804244_chevilmumbo[];
    extern u32 D_80804254_chevilmumbo[], D_8080426C_chevilmumbo[];
    extern f32 D_8080427C_chevilmumbo[3];
    extern u32 D_80804388_chevilmumbo[], D_80804398_chevilmumbo[];
    extern u32 D_808043A4_chevilmumbo[], D_808043B4_chevilmumbo[];
    extern u32 D_808043C4_chevilmumbo[], D_808043D4_chevilmumbo[];
    struct MumboFlags {
        u8 pad0[0x70];
        u32 pad70_23 : 9;
        u32 unk70_22 : 1;
        u32 pad70_0 : 22;
        u32 pad74_4 : 28;
        u32 unk74_0 : 4;
        u32 pad78_14 : 18;
        u32 unk78_12 : 2;
        u32 pad78_0 : 12;
    };
    f32 dt;
    struct {
        u8 pad0[0x78];
        f32 position[3];
        u8 unk84;
        u8 unk85;
        u8 pad86[7];
        u8 unk8D;
        s8 unk8E;
        s8 unk8F;
        u8 unk90;
        u8 unk91;
        u8 unk92;
        u8 unk93;
    } *data;
    f32 position[3];
    f32 progress;

    dt = func_800D8FF8();
    data = func_80100094(arg0, 0);
    if (arg0->unk7C_12) {
        if (data->unk85 == 1) {
            _subaddieskeleton_entrypoint_2(arg0->unk0, 11, data->position);
        } else {
            _subaddieskeleton_entrypoint_2(arg0->unk0, 10, data->position);
        }
    }
    if (func_8010D23C() && func_8010D278() != 17) {
        func_8010D254((f32 *)arg0->actorData);
    }
    arg0->unk54 = func_800F1DF4(arg0->position, (f32 *)arg0->actorData);
    func_8008FB10(arg0->position, arg0->scale * 300.0f, arg0->scale * -25.0f, arg0->scale * 150.0f);
    _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    switch (arg0->unk70_10) {
    case 20:
        break;
    case 1:
        ((struct MumboFlags *)arg0)->unk74_0 = 2;
        data->unk8F = 1;
        data->unk8E = 0;
        if (func_80101E14(arg0, 0.3f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080416C_chevilmumbo);
        } else if (func_80101E14(arg0, 0.7f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804178_chevilmumbo);
        }
        if (!data->unk90 && func_80090178(1) && _subaddiedialog_entrypoint_3(arg0->position, (s32)arg0->rotation[1], 500, 90, 6)) {
            func_808007C4_chevilmumbo(arg0, 2);
        }
        break;
    case 2:
        ((struct MumboFlags *)arg0)->unk74_0 = 2;
        data->unk8F = 1;
        data->unk8E = 0;
        if (func_80101E14(arg0, 0.3f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080416C_chevilmumbo);
        } else if (func_80101E14(arg0, 0.7f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804178_chevilmumbo);
        }
        if (data->unk90 == 1 && func_80101E14(arg0, 0.999f)) {
            func_808003DC_chevilmumbo(arg0, 0);
            ((struct MumboFlags *)arg0)->unk74_0 = 1;
            arg0->unk7A_11 = 3;
            ((struct MumboFlags *)arg0)->unk78_12 = 3;
            arg0->unk6C_0 = 0;
            ((struct MumboFlags *)arg0)->unk70_22 = 1;
            func_808007C4_chevilmumbo(arg0, 3);
        }
        break;
    case 3:
        if (func_80101E14(arg0, 0.2f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804184_chevilmumbo);
        }
        if (arg0->unk6C_0 < 100) {
            arg0->unk6C_0++;
            if (arg0->unk6C_0 < 20) {
                arg0->unk7A_11 = 3;
            } else if (arg0->unk6C_0 < 40) {
                arg0->unk7A_11 = 2;
            } else if (arg0->unk6C_0 < 60) {
                arg0->unk7A_11 = 1;
            } else {
                arg0->unk7A_11 = 0;
                ((struct MumboFlags *)arg0)->unk78_12 = 1;
            }
        } else if (func_800DC298(0.3f) && arg0->unk7A_11 < 3) {
            ((struct MumboFlags *)arg0)->unk78_12 = 1;
        } else if (func_800DC298(0.05f) && arg0->unk7A_11 > 0) {
            ((struct MumboFlags *)arg0)->unk78_12 = 2;
        }
        if (func_80101E14(arg0, 0.999f)) {
            ((struct MumboFlags *)arg0)->unk74_0 = 1;
            func_80800354_chevilmumbo(arg0, 0x11DF, 0);
            func_80800144_chevilmumbo(arg0, 3, 1);
            func_808007C4_chevilmumbo(arg0, 4);
        }
        break;
    case 5:
        if (func_80101DDC(arg0)) {
            data->unk8F = 0;
            func_808007C4_chevilmumbo(arg0, 6);
            func_800EE7F8(arg0->position, D_8080427C_chevilmumbo);
        } else if (func_80101E14(arg0, 0.87f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808041D0_chevilmumbo);
        } else if (func_80101E14(arg0, 0.76f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808041DC_chevilmumbo);
        } else if (func_80101E4C(arg0, D_80804388_chevilmumbo)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808041E8_chevilmumbo);
        }
        break;
    case 17:
        if (!arg0->unk74_30) {
            func_8010D254(position);
            if (position[1] >= -70.0f && func_8008FA60(1, 0) && func_80090248()) {
                func_800FDC28(1);
                func_80090734(1, arg0->position);
                func_808001F4_chevilmumbo(arg0, 11, 0x20, NULL);
                func_80800354_chevilmumbo(arg0, 0x11E2, 0);
                func_800DA544(0xA33);
            }
        }
        break;
    case 6:
        if (func_80101E14(arg0, 0.79f)) {
            data->unk8E = 1;
        }
        if (func_800DC298(0.2f)) {
            if (data->unk8D == 1) {
                data->unk8D = 2;
            } else {
                data->unk8D = 1;
            }
        }
        if (func_80101DDC(arg0)) {
            _gcfrontend_entrypoint_9(0x2B);
            func_800DA544(0x408);
            func_808007C4_chevilmumbo(arg0, 8);
        } else if (func_80101E4C(arg0, D_80804398_chevilmumbo)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808041F8_chevilmumbo);
        }
        break;
    case 7:
        func_80800E50_chevilmumbo(arg0);
        if (data->unk90 == 3) {
            arg0->unk74_29 = 0;
            if (func_80800E50_chevilmumbo(arg0)) {
                func_808003DC_chevilmumbo(arg0, 0);
                func_808007C4_chevilmumbo(arg0, 8);
            }
        } else {
            arg0->unk74_29 = 1;
            if (func_80101E14(arg0, 0.999f)) {
                func_808003DC_chevilmumbo(arg0, 3);
            }
        }
        break;
    case 8:
        if (func_80101E14(arg0, 0.25f)) {
            func_80108B04(arg0, 2);
        } else if (func_80101E14(arg0, 0.52f)) {
            func_80108B04(arg0, 1);
            func_800C4140(0x48F + ((((s32)func_800DC178(18000.0f, 24000.0f) >> 5) & 0x3FF) << 11) + (((u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21), arg0->position, 0x138809C4);
        } else if (func_80101E14(arg0, 0.3f)) {
            func_800C4140(0x5F9 + ((((s32)func_800DC178(18000.0f, 24000.0f) >> 5) & 0x3FF) << 11) + (((u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21), arg0->position, 0x138809C4);
        } else if (func_80101DDC(arg0)) {
            if (!arg0->unk64_19) {
                func_808003DC_chevilmumbo(arg0, 2);
                func_808007C4_chevilmumbo(arg0, 13);
            } else if (arg0->unk6C_0) {
                func_808007C4_chevilmumbo(arg0, 9);
            } else {
                func_808007C4_chevilmumbo(arg0, 19);
            }
        }
        func_80800E50_chevilmumbo(arg0);
        break;
    case 13:
        switch (data->unk90) {
        case 2:
            if (!func_800DA298(0x6AD)) {
                func_808003DC_chevilmumbo(arg0, 10);
            }
            break;
        case 6:
            if (func_800DA298(0xA33)) {
                func_808003DC_chevilmumbo(arg0, 8);
            }
            break;
        case 8:
        case 10:
            break;
        }
        break;
    case 9:
        if (!data->unk90) {
            if (arg0->unk58 >= 0.0f) {
                arg0->unk58 -= dt;
            } else if (data->unk93 >= 5) {
                func_808007C4_chevilmumbo(arg0, 8);
            } else {
                func_808007C4_chevilmumbo(arg0, 10);
            }
        }
        func_80800E50_chevilmumbo(arg0);
        break;
    case 19:
        switch (data->unk90) {
        case 0:
            if (arg0->unk58 >= 0.0f) {
                arg0->unk58 -= dt;
            } else if (data->unk93 >= 5) {
                func_808007C4_chevilmumbo(arg0, 10);
            } else {
                func_808007C4_chevilmumbo(arg0, 10);
            }
            break;
        case 2:
            break;
        }
        func_80800E50_chevilmumbo(arg0);
        break;
    case 10:
        arg0->unk58 += dt;
        if (func_80101DDC(arg0)) {
            func_808007C4_chevilmumbo(arg0, 11);
            _subaddiefade_entrypoint_1(arg0, 0);
        } else {
            _subaddiefade_entrypoint_1(arg0, (s32)func_800F10B4(func_80101F24(arg0), 0.66f, 0.95f, 255.0f, 0.0f));
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80804244_chevilmumbo, 0.19f);
        }
        if (func_80101F24(arg0) < 0.95f) {
            func_808011F4_chevilmumbo(arg0);
        }
        break;
    case 11:
        arg0->unk58 += dt;
        if (arg0->unk58 >= 1.0f) {
            func_808007C4_chevilmumbo(arg0, 12);
        }
        break;
    case 12:
        arg0->unk58 += dt;
        if (func_80101DDC(arg0)) {
            _subaddiefade_entrypoint_8(arg0, 255);
            func_80800ECC_chevilmumbo(arg0, 0);
        } else {
            progress = func_80101F24(arg0);
            _subaddiefade_entrypoint_1(arg0, (s32)func_800F10B4(progress, 0.0f, 0.8f, 0.0, 255.0f));
            if (func_80101F24(arg0) < 0.75f) {
                func_808011F4_chevilmumbo(arg0);
            }
        }
        break;
    case 14:
        if (((f32 *)arg0->actorData)[3] > 0.0f || arg0->position[1] > ((f32 *)arg0->actorData)[5]) {
            arg0->position[1] += ((f32 *)arg0->actorData)[3] * dt;
            ((f32 *)arg0->actorData)[3] -= 2500.0f * dt;
        }
        if (arg0->position[1] < ((f32 *)arg0->actorData)[5]) {
            arg0->position[1] = ((f32 *)arg0->actorData)[5];
        }
        if (arg0->position[1] == ((f32 *)arg0->actorData)[5] && func_80101DDC(arg0)) {
            if (!func_800DA9E4(0x423, 1)) {
                func_808007C4_chevilmumbo(arg0, 18);
            } else {
                func_808007C4_chevilmumbo(arg0, 10);
            }
        }
        break;
    case 18:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80804244_chevilmumbo, 0.19f);
        break;
    case 15:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80804244_chevilmumbo, D_808043A4_chevilmumbo);
        break;
    case 16:
        switch (data->unk90) {
        case 0:
            progress = func_80101F24(arg0);
            if (progress > 0.25f && progress < 0.6f) {
                _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808041A4_chevilmumbo);
            }
            if (func_80101E14(arg0, 0.6f)) {
                _chexploder_entrypoint_3(arg0, arg0->position, 0);
            }
            if (arg0->unk7C_12) {
                if (func_80101F24(arg0) > 0.38f && func_8001210C(1)) {
                    func_80800FF8_chevilmumbo(arg0);
                }
                if (func_80101E14(arg0, 0.9f)) {
                    func_808010C4_chevilmumbo(arg0);
                }
            }
            if (func_80101E14(arg0, 0.8f)) {
                func_800FDC28(0);
            }
            arg0->unk58 -= func_800D8FF8();
            if (func_80101DDC(arg0) && arg0->unk58 <= 0.0f) {
                func_808003DC_chevilmumbo(arg0, 4);
            }
            break;
        case 7:
            if (!func_800DA298(0xA32)) {
                func_808003DC_chevilmumbo(arg0, 5);
            }
            break;
        case 4:
        case 9:
            break;
        }
        break;
    }
    switch (func_801022E4(arg0)) {
    case 0x36E:
        if (arg0->unk74_29) {
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_8080415C_chevilmumbo, D_808043B4_chevilmumbo);
        }
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_8080426C_chevilmumbo, 0.78f);
        break;
    case 0x480:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80804254_chevilmumbo, D_808043C4_chevilmumbo);
        break;
    case 0x36C:
        if (func_80101E4C(arg0, D_808043D4_chevilmumbo)) {
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80804254_chevilmumbo, D_808043D4_chevilmumbo);
        }
        break;
    }
    if ((s32)arg0->unk70_10 >= 7 && arg0->unk7A_11 == 3) {
        data->unk8D = 2;
    }
    if (data->unk92 == 1) {
        func_800D2498(0xFB, data->unk93, 0);
    }
    func_80800000_chevilmumbo(arg0);
}

void func_808023E8_chevilmumbo(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_8080241C_chevilmumbo(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _glcutDll_entrypoint_20(void);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800D0A9C(u32, u32);
    s32 func_800D395C(void);
    s32 _chintrotext_entrypoint_2(s32);
    void func_800FFAB0(Actor *);
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void func_800EE88C(f32 *, s16 *);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    void func_80108B04(Actor *, s32);
    void func_800DA524(s32);
    s32 func_800DA298(s32);
    extern f32 D_8080427C_chevilmumbo[3], D_80804288_chevilmumbo[3];
    Prop *props[10];
    s32 i;
    s32 cutscene;
    struct {
        f32 positions[11][3];
        u8 unk84, unk85, unk86, unk87, unk88, unk89, unk8A, unk8B;
        u8 unk8C, unk8D, unk8E, unk8F, unk90, unk91, unk92, unk93;
        u8 unk94, unk95, unk96;
    } *data;

    data = func_80100094(arg0, 0);
    cutscene = _glcutDll_entrypoint_20();
    func_800EE7F8(arg0->position, D_80804288_chevilmumbo);
    if (func_800D0A9C(0x47, 1) && !cutscene && !func_800D395C()) {
        _chintrotext_entrypoint_2(1);
        func_800FFAB0(arg0);
        return;
    }
    data->unk91 = _gccubesearch_entrypoint_9(0x226, props, 10);
    for (i = 0; i < data->unk91; i++) {
        func_800EE88C(data->positions[i], props[i]->position);
    }
    arg0->scale = 0.5f;
    data->unk84 = 1;
    data->unk85 = 0;
    data->unk86 = 1;
    data->unk87 = 1;
    data->unk88 = 1;
    data->unk89 = 1;
    data->unk8A = 1;
    data->unk8B = 1;
    data->unk8C = 1;
    data->unk8D = 1;
    _suexpression_entrypoint_7(arg0, 1, 0x10);
    if (!cutscene) {
        func_80108B04(arg0, 0);
    }
    func_800DA524(0xA32);
    func_800DA524(0xA33);
    data->unk93 = 8;
    data->unk92 = 0;
    arg0->unk64_19 = func_800DA298(0x408);
    if (cutscene) {
        func_808007C4_chevilmumbo(arg0, 0x15);
    } else if (func_800DA298(0x408)) {
        func_80800774_chevilmumbo(arg0);
        func_808007C4_chevilmumbo(arg0, 0x11);
        data->unk96 = 1;
        func_800EE7F8(arg0->position, D_8080427C_chevilmumbo);
    } else {
        func_808007C4_chevilmumbo(arg0, 1);
    }
}

s32 func_80802618_chevilmumbo(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_6(Actor *, f32, f32);
    void _chexploder_entrypoint_9(Actor *, s32, s32);
    void _chexploder_entrypoint_10(Actor *, s32 *);
    void _chexploder_entrypoint_12(Actor *, s32);
    void _chexploder_entrypoint_13(Actor *, u32);
    void _chexploder_entrypoint_14(Actor *, s32);
    void _chexploder_entrypoint_15(Actor *, u32, f32);
    void _chexploder_entrypoint_16(Actor *, s32);
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void func_80090708(s32);
    void func_800A51C0(void);
    void func_800C4140(u32, f32 *, u32);
    void func_800C9C70(f32, u32, f32, u32, f32 *, f32, f32);
    s32 func_800D395C(void);
    void func_800DF3E0(void);
    void func_800DF744(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800FDC28(u32);
    void *func_80101080(void);
    s32 func_801015D0(Actor *);
    f32 func_80101F24(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_801084B0(s32, Actor **);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_808003DC_chevilmumbo(Actor *, s32);
    void func_80800C50_chevilmumbo(Actor *);
    extern u32 D_808043E4_chevilmumbo[];
    extern f32 D_808043F4_chevilmumbo[], D_80804400_chevilmumbo[];
    extern s32 D_8080440C_chevilmumbo[], D_80804414_chevilmumbo[];
    extern s32 D_8080441C_chevilmumbo[], D_80804428_chevilmumbo[];
    extern s32 D_80804430_chevilmumbo[], D_80804434_chevilmumbo[];
    extern s32 D_80804438_chevilmumbo[], D_8080443C_chevilmumbo[];
    extern s32 D_80804440_chevilmumbo[];
    struct {
        u8 pad0[0x78];
        f32 position[3];
        u8 unk84;
        u8 unk85;
        u8 unk86;
        u8 unk87;
        u8 unk88;
        u8 unk89;
        u8 unk8A;
        u8 unk8B;
        u8 unk8C;
        u8 unk8D;
        u8 unk8E;
        u8 unk8F;
        u8 unk90;
        u8 unk91;
        u8 unk92;
        u8 unk93;
        u8 unk94;
    } *data;
    s32 camera;
    s32 mode;
    s16 *dialog;
    Actor *actor;
    f32 position[3];
    Actor *actor2;
    Actor *exploder;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x32:
        func_808003DC_chevilmumbo(arg0, 1);
        break;
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        func_80800354_chevilmumbo(arg0, 0xCEB, 0);
        break;
    case 0x9F:
        func_808007C4_chevilmumbo(arg0, 0x14);
        break;
    case 0x2E:
        dialog = (s16 *)&arg2;
        switch (dialog[0]) {
        case 0x11DF:
            func_808007C4_chevilmumbo(arg0, 5);
            break;
        case 0x11E2:
            data->unk92 = 1;
            func_80800ECC_chevilmumbo(arg0, 1);
            func_80090708(0);
            func_800FDC28(0xA);
            func_808000BC_chevilmumbo(arg0);
            break;
        case 0x11E0:
            arg0->unk64_19 = 1;
            data->unk92 = 1;
            func_808003DC_chevilmumbo(arg0, 6);
            break;
        case 0x11E1:
            func_80800144_chevilmumbo(arg0, 2, 1);
            func_808003DC_chevilmumbo(arg0, 0);
            func_808007C4_chevilmumbo(arg0, 0x10);
            func_808001F4_chevilmumbo(arg0, 0x11, 0x20, NULL);
            break;
        case 0x11E3:
            func_800A51C0();
            func_808003DC_chevilmumbo(arg0, 0);
            func_808000BC_chevilmumbo(arg0);
            break;
        case 0x11E5:
            func_808000BC_chevilmumbo(arg0);
            func_808007C4_chevilmumbo(arg0, 0xA);
            break;
        case 0xCEB:
            if (dialog[1] == 1) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
            break;
        }
        arg0->unk74_30 = 0;
        break;
    case 0xB:
        switch (arg2) {
        case 1:
            func_80800144_chevilmumbo(arg0, 3, 1);
            break;
        case 3:
            func_80800290_chevilmumbo(arg0);
            break;
        case 15:
            func_808003DC_chevilmumbo(arg0, 9);
            break;
        case 9:
            func_808003DC_chevilmumbo(arg0, 7);
            break;
        case 2:
        default:
            return 3;
        }
        return 4;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808043E4_chevilmumbo, arg0->scale);
        if ((s32)arg0->unk70_10 < 5) {
            _gcdialogcamera_entrypoint_4(D_808043F4_chevilmumbo);
        }
        break;
    case 0x57:
        camera = arg2 & 0xFFFF;
        mode = (arg2 & 0xFFFF0000) >> 16;
        if (_gcdialogcamera_entrypoint_0(camera, mode)) {
            func_80800144_chevilmumbo(arg0, camera, mode);
        }
        break;
    case 0x40:
        switch (arg0->unk70_10) {
        case 7:
        case 8:
        case 9:
        case 19:
            func_80800C50_chevilmumbo(arg0);
            break;
        case 10:
            if (func_80101F24(arg0) < 0.75f) {
                func_80800C50_chevilmumbo(arg0);
            }
            break;
        case 12:
            if (func_80101F24(arg0) > 0.25f) {
                func_80800C50_chevilmumbo(arg0);
            }
            break;
        }
        break;
    case 0x3D:
        switch (arg2) {
        case 2:
            if (arg0->unk7C_12) {
                actor = func_801084B0(0x380, &arg0);
                actor->unk3C = arg0->unk0;
            }
            break;
        case 1:
            if (arg0->unk7C_12) {
                func_800EE7F8(position, data->position);
            } else {
                func_800EE7F8(position, arg0->position);
                position[1] += 100.0f;
            }
            actor2 = func_80108528(0x37D, position, 0, &arg0);
            actor2->unk3C = arg0->unk0;
            break;
        case 0:
            actor2 = func_80108528(0x37E, D_80804400_chevilmumbo, 0, &arg0);
            actor2->unk3C = arg0->unk0;
            break;
        }
        break;
    case 0x90:
        exploder = func_80106790(func_80101080());
        arg0->unk64_16 = 1;
        _chexploder_entrypoint_9(exploder, 0x15, 0);
        switch (data->unk94) {
        case 0:
            _chexploder_entrypoint_10(exploder, D_8080440C_chevilmumbo);
            _chexploder_entrypoint_9(exploder, 0xA, 3);
            _chexploder_entrypoint_15(exploder, 3, 0.25f);
            break;
        case 1:
            _chexploder_entrypoint_10(exploder, D_80804414_chevilmumbo);
            _chexploder_entrypoint_9(exploder, 0xB, 3);
            _chexploder_entrypoint_15(exploder, 3, 0.25f);
            break;
        case 2:
            _chexploder_entrypoint_10(exploder, D_8080441C_chevilmumbo);
            _chexploder_entrypoint_9(exploder, 0xD, 3);
            _chexploder_entrypoint_15(exploder, 3, 0.25f);
            break;
        case 3:
            _chexploder_entrypoint_10(exploder, D_80804428_chevilmumbo);
            _chexploder_entrypoint_9(exploder, 0xC, 3);
            _chexploder_entrypoint_15(exploder, 3, 0.25f);
            break;
        case 4:
            _chexploder_entrypoint_10(exploder, D_80804430_chevilmumbo);
            _chexploder_entrypoint_9(exploder, 8, 5);
            _chexploder_entrypoint_15(exploder, 3, 0.5f);
            break;
        case 5:
            _chexploder_entrypoint_10(exploder, D_80804434_chevilmumbo);
            _chexploder_entrypoint_9(exploder, 8, 4);
            _chexploder_entrypoint_15(exploder, 3, 0.5f);
            break;
        case 6:
            _chexploder_entrypoint_10(exploder, D_80804438_chevilmumbo);
            _chexploder_entrypoint_9(exploder, 0xE, 3);
            _chexploder_entrypoint_15(exploder, 3, 0.4f);
            break;
        case 7:
            _chexploder_entrypoint_16(exploder, 0x697);
            _chexploder_entrypoint_10(exploder, D_8080443C_chevilmumbo);
            _chexploder_entrypoint_15(exploder, 2, 0.4f);
            _chexploder_entrypoint_6(exploder, 600.0f, 800.0f);
            _chexploder_entrypoint_13(exploder, 7);
            _chexploder_entrypoint_14(exploder, 4);
            _chexploder_entrypoint_12(exploder, 0x3C);
            func_800C4140(0x7FF19413, arg0->position, 0x138801F4);
            data->unk94 = 8;
            break;
        case 8:
            func_800C4140(0x7FFF4413, arg0->position, 0x138801F4);
            _chexploder_entrypoint_9(exploder, 0xA, 4);
            _chexploder_entrypoint_9(exploder, 0xB, 4);
            _chexploder_entrypoint_9(exploder, 0xD, 4);
            _chexploder_entrypoint_9(exploder, 0xC, 4);
            _chexploder_entrypoint_9(exploder, 8, 0);
            _chexploder_entrypoint_9(exploder, 0xE, 4);
            _chexploder_entrypoint_15(exploder, 2, 0.35f);
            _chexploder_entrypoint_10(exploder, D_80804440_chevilmumbo);
            _chexploder_entrypoint_6(exploder, 600.0f, 800.0f);
            func_800C9C70(0.4f, 0x5F3, 1.0f, 0x7FFF, arg0->position, 250.0f, 5400.0f);
            arg0->unk64_16 = 0;
            break;
        }
        break;
    case 0x1F:
        func_800DF3E0();
        func_801015D0(arg0);
        if (arg0->unk64_20) {
            func_800DF744(0x21, arg0->unk7A_11 + 1);
            func_800DF744(4, data->unk84);
            func_800DF744(0x14, data->unk85);
            func_800DF744(8, data->unk86);
            func_800DF744(0xA, data->unk87);
            func_800DF744(0xB, data->unk88);
            func_800DF744(0xD, data->unk89);
            func_800DF744(0xC, data->unk8A);
            func_800DF744(0xE, data->unk8B);
            func_800DF744(0x15, data->unk8C);
            func_800DF744(0x11, data->unk8D);
            func_800DF744(0x16, 1);
        } else {
            if (data->unk8F) {
                func_800DF744(5, 1);
                func_800DF744(6, 1);
            } else {
                func_800DF744(5, 0);
                func_800DF744(6, 0);
            }
            if (data->unk8E) {
                func_800DF744(4, 1);
            } else {
                func_800DF744(4, 0);
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}

OSThread *chevilmumbo_entrypoint_0(void)
{


    return (OSThread *) D_80804460_chevilmumbo;
}

void func_8080300C_chevilmumbo(Actor *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_8010A570(Actor *);
    void func_800FFAB0(Actor *);
    extern s32 D_80804220_chevilmumbo;


    if (arg0->unk6C_0 != 0) {
        arg0->unk6C_0 = _chlightfader_entrypoint_1(arg0->unk6C_0, 1.4f, 3);
    }
    func_800BBCB8(arg0->position, arg0->position, 1.0f, 12, D_808044A8_chevilmumbo);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804220_chevilmumbo);
    func_8010A570(arg0);
    func_800FFAB0(arg0);
}

void func_808030AC_chevilmumbo(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddiefade_entrypoint_3(Actor *);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    s32 func_800D0A9C(u32, u32);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    f32 func_800F1828(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010B990(Actor *, s32);
    extern u32 D_80804208_chevilmumbo[];
    f32 dt;
    Actor *parent;
    void *volatile data;
    f32 pos[3];
    f32 turn;

    dt = func_800D8FF8();
    parent = func_80106790(arg0->unk3C);
    data = func_80100094(parent, 0);
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80804208_chevilmumbo);
    ((f32 *)arg0->actorData)[0] += dt * 500.0f;
    if (arg0->unk70_10 == 1) {
        func_800C8E54(arg0->unk6C_0, arg0->scale * 400.0f, arg0->scale * 1000.0f);
        func_800C8E84(arg0->unk6C_0, D_808044E4_chevilmumbo);
        func_800C8CB8(arg0->unk6C_0, arg0->position);
        if (!func_800D0A9C(0x47, 1)) {
            func_800EE7F8(pos, (f32 *)parent->actorData);
            pos[1] += 100.0f;
            arg0->unk54 = func_800F1DF4(arg0->position, pos);
            arg0->unk50 = func_800F1828(arg0->position, pos);
            turn = ((f32 *)arg0->actorData)[7] * func_800F1DCC(arg0->unk54, arg0->rotation[1]);
            arg0->rotation[1] += turn;
            arg0->rotation[0] += func_800F1DCC(arg0->unk50, arg0->rotation[0]) * ((f32 *)arg0->actorData)[7];
            if ((*(u16 *)&arg0->unk78 & 3) == 0) {
                ((f32 *)arg0->actorData)[1] += turn > 0.0f ? turn : -turn;
                if (((f32 *)arg0->actorData)[1] > 720.0f) {
                    _subaddiefade_entrypoint_3(arg0);
                }
            }
            if (((f32 *)arg0->actorData)[2] > 0.0f) {
                ((f32 *)arg0->actorData)[2] -= dt;
            } else {
                ((f32 *)arg0->actorData)[7] *= 0.5f;
            }
        }
        func_800EEC30(&((f32 *)arg0->actorData)[4], arg0->rotation[0], arg0->rotation[1], ((f32 *)arg0->actorData)[3]);
        if (func_8010B990(arg0, 0x400007) & 0x20) {
            func_8080300C_chevilmumbo(arg0);
        }
        ((f32 *)arg0->actorData)[3] -= 200.0f * dt;
        if (arg0->unk58 > 0.0f) {
            arg0->unk58 -= dt;
        } else {
            func_800FFAB0(arg0);
        }
    }
}

void func_80803358_chevilmumbo(u8 *arg0) {
    void func_800C8B84(s32);
    if (((Actor *)arg0)->unk6C_0 != 0) {
        func_800C8B84(((Actor *)arg0)->unk6C_0);
    }
}

void func_80803388_chevilmumbo(Actor *arg0) {
    s32 func_800C8A98(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F1828(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *sp34;
    struct {
        u8 pad0[0x93];
        u8 unk93;
    } *sp30;
    f32 sp24[3];

    sp34 = func_80106790(arg0->unk3C);
    sp30 = func_80100094(sp34, 0);
    arg0->scale = 0.4f;
    arg0->unk6C_0 = func_800C8A98();
    if (sp30->unk93 < 5) {
        ((f32 *)arg0->actorData)[3] = 1000.0f;
    } else {
        ((f32 *)arg0->actorData)[3] = 1000.0f;
    }
    arg0->unk58 = 2.5f;
    if (sp30->unk93 < 5) {
        ((f32 *)arg0->actorData)[2] = 0.5f;
    } else {
        ((f32 *)arg0->actorData)[2] = 0.25f;
    }
    if (sp30->unk93 < 5) {
        ((f32 *)arg0->actorData)[7] = 0.799987793f;
    } else {
        ((f32 *)arg0->actorData)[7] = 0.3999938965f;
    }
    func_800EE7F8(sp24, (f32 *)sp34->actorData);
    sp24[1] += 100.0f;
    arg0->rotation[1] = func_800F1DF4(arg0->position, sp24);
    arg0->rotation[0] = func_800F1828(arg0->position, sp24);
}

s32 func_808034C8_chevilmumbo(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800D93A0(f32[4], f32[3]);
    void func_800DF41C(s32);
    void func_800DFF2C(u8 **, s32, f32[4]);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_801015D0(Actor *);
    s32 func_801040D0(void);
    Actor *func_80106790(Unk80132ED0 *);
    s32 pad;
    s32 sp38;
    f32 sp2C[3];
    f32 sp1C[4];

    switch (arg1) {
    case 0x40:
        func_8080300C_chevilmumbo(arg0);
        break;
    case 0x1C:
        if (func_80106790(arg0->unk3C)->unk64_19) {
            return 2;
        }
        return 1;
    case 0x1F:
        sp38 = func_801040D0();
        func_801015D0(arg0);
        func_800DF41C(sp38);
        func_800EFA4C(sp2C, ((f32 *)arg0->actorData)[0], 0.0f, 0.0f);
        func_800D93A0(sp1C, sp2C);
        func_800DFF2C(sp38, 0x2A, sp1C);
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_808035A8_chevilmumbo(u8 *arg0, s32 arg1) {
    s32 func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF830(s32);
    void func_801018A4(Actor *, s32);
    s32 func_80101970();
    (*(f32 *)((s8 *)(arg0) + (0x44))) = (f32) -(*(f32 *)((s8 *)(arg0) + (0x44)));
    func_80101970();
    func_800DF830(2);
    func_800DE448((f32 *)(arg0 + 4), (f32 *)(arg0 + 0x44), (*(f32 *)((s8 *)(arg0) + (0x38))), 0, func_800D674C(0x69E));
    func_801018A4(arg0, arg1);
    (*(f32 *)((s8 *)(arg0) + (0x44))) = (f32) -(*(f32 *)((s8 *)(arg0) + (0x44)));
}

OSThread *chevilmumbo_entrypoint_1(void)
{
    extern u8 D_808044F0_chevilmumbo[];

    return (OSThread *) D_808044F0_chevilmumbo;
}

void func_8080362C_chevilmumbo(Actor *arg0, s32 arg1) {
#ifndef BT_NATIVE
    void func_800DA524(GameFlag);
#endif
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80102424(Actor *, s32);

    func_80102424(arg0, arg1);
    switch (arg0->unk70_10) {
        case 4:
            arg0->unk64_19 = 1;
            break;
        case 2:
            arg0->unk64_16 = 1;
            arg0->unk64_19 = 1;
            break;
        case 3:
            func_800DA524(0xA33);
            func_800EFA4C(arg0->position, 0.0f, 0.0f, 0.0f);
            break;
        case 1:
            func_800DA524(0xA32);
            func_800EE7F8(arg0->position, (f32 *)arg0->actorData);
            arg0->unk64_16 = 0;
            break;
    }
    arg0->unk58 = 0.0f;
}

void func_80803700_chevilmumbo(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void func_800C4140(u32, f32 *, u32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    void func_800EFA20(void *, void *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern f32 D_80804538_chevilmumbo[];
    extern u32 D_80804234_chevilmumbo[];
    f32 dt;

    dt = func_800D8FF8();
    switch (arg0->unk70_10) {
        case 1:
            if (func_800DA298(0xA33)) {
                func_8080362C_chevilmumbo(arg0, 2);
            }
            break;
        case 2:
            if (arg0->unk58 <= 2.5f) {
                func_800EFA20(arg0->position, arg0->actorData,
                    func_800F10B4(arg0->unk58, 0.0f, 2.5f, 1.0f, 0.0f));
                arg0->unk58 += dt;
                _subaddieaudioloop_entrypoint_4(arg0, D_80804538_chevilmumbo, 1, D_80804234_chevilmumbo);
            } else {
                if (arg0->unk64_19) {
                    func_800C4140(0x665194CC, D_80804538_chevilmumbo, 0x138809C4);
                    arg0->unk64_19 = 0;
                }
                func_8080362C_chevilmumbo(arg0, 3);
            }
            break;
        case 3:
            if (func_800DA298(0xA32)) {
                func_8080362C_chevilmumbo(arg0, 4);
            }
            break;
        case 4:
            if (arg0->unk58 <= 3.0f) {
                func_800EFA20(arg0->position, arg0->actorData,
                    func_800F10B4(arg0->unk58, 0.0f, 3.0f, 0.0f, 1.0f));
                arg0->unk58 += dt;
                _subaddieaudioloop_entrypoint_4(arg0, D_80804538_chevilmumbo, 1, D_80804234_chevilmumbo);
            } else {
                if (arg0->unk64_19) {
                    func_800C4140(0x7FEBBCCC, D_80804538_chevilmumbo, 0x138809C4);
                    arg0->unk64_19 = 0;
                }
                func_8080362C_chevilmumbo(arg0, 1);
            }
            break;
    }
}

void func_80803918_chevilmumbo(s32 arg0) 
{
}
/* extern */

void func_80803920_chevilmumbo(Actor *arg0) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    void func_8080362C_chevilmumbo(Actor *, s32);
    func_800EFA4C((f32 *)arg0->actorData, -130.0f, 0.0f, -430.0f);
    func_8080362C_chevilmumbo(arg0, 1);
}

s32 func_8080395C_chevilmumbo(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0xB) {
        return 3;
    }
    return 0;
}

OSThread *chevilmumbo_entrypoint_2(void)
{
    extern u8 D_80804544_chevilmumbo[];

    return (OSThread *) D_80804544_chevilmumbo;
}

void func_8080398C_chevilmumbo(Actor *arg0, s32 arg1) {
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF47C(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_801017D0(Actor *);
    u8 *func_801039E4(Unk80132ED0 *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 *sp2C;
    f32 sp38[3];
    void *temp_v0;

    temp_v0 = func_80100094(func_80106790(arg0->unk3C), 0U);
    sp2C = arg0->position;
    func_800EE7F8(sp2C, (f32 *)((u8 *)temp_v0 + 0x78));
    func_800EFA4C(sp38, 0.0f, 0.0f, 0.0f);
    func_800DF47C(func_801017D0, arg0);
    func_800DE448(sp2C, sp38, arg0->scale, 0, func_801039E4(arg0->unk0));
}

void func_80803A24_chevilmumbo(s32 arg0, s32 arg1) {
    struct State {
        u8 pad[0x72];
        u8 state : 6;
        u8 other : 2;
    };
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 temp;

    switch (arg1) {
    case 2:
        *(f32 *)(arg0 + 0x28) = 0.3f;
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        break;
    case 3:
        *(f32 *)(arg0 + 0x2C) = 1.0f;
        *(f32 *)(arg0 + 0x38) = 1.0f;
        *(f32 *)(arg0 + 0x28) = 0.15f;
        break;
    case 4:
        *(f32 *)(arg0 + 0x38) = 1.0f;
        temp = func_800F10B4(*(f32 *)(arg0 + 0x2C), 0.0f, 1.0f, 0.0f, 0.2f);
        *(f32 *)(arg0 + 0x28) = temp;
        if (temp == 0.0f) {
            *(f32 *)(arg0 + 0x28) += 0.01f;
        }
        break;
    case 5:
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        break;
    }
    ((struct State *)arg0)->state = arg1;
}

void func_80803B28_chevilmumbo(s32 arg0)
{
    func_80803A24_chevilmumbo(arg0,0x2);
}

void func_80803B48_chevilmumbo(s32 arg0) 
{
}
void func_80803B50_chevilmumbo(Actor *arg0) {
    s32 func_800D9078(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FFAB0(Actor *);

    switch (arg0->unk70_10) {
    case 2:
        *(f32 *)&arg0->actorData[5] = func_800F10B4(*(f32 *)&arg0->actorData[4], 0.0f, 0.3f, 1, 0.0f);
        if (func_800D9078((f32 *)&arg0->actorData[4])) {
            func_80803A24_chevilmumbo((s32)arg0, 3);
        }
        return;
    case 3:
        if (arg0->scale == 1.0f) {
            arg0->scale = 0.75f;
        } else {
            arg0->scale = 1.0f;
        }
        if (func_800D9078((f32 *)&arg0->actorData[4])) {
            func_80803A24_chevilmumbo((s32)arg0, 4);
        }
        break;
    case 4:
        *(f32 *)&arg0->actorData[5] = func_800F10B4(*(f32 *)&arg0->actorData[4], 0.0f, 0.2f, 0.0f, 1);
        if (func_800D9078((f32 *)&arg0->actorData[4])) {
            func_80803A24_chevilmumbo((s32)arg0, 5);
        }
        break;
    case 5:
        func_800FFAB0(arg0);
        break;
    }
}

s32 func_80803C88_chevilmumbo(void *arg0, s32 arg1, s32 arg2) {
    s32 result;
    void func_800DF410(s32);
    void func_800DF830(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);

    if (arg1 == 0x1F) {
        func_800DF410((s32)func_800F10B4(*(f32 *)((u8 *)arg0 + 0x2C), 0.0f, 1.0f, 0.0f, 255.0f));
        func_800DF830(2);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

OSThread *chevilmumbo_entrypoint_3(void)
{
    extern u8 D_8080458C_chevilmumbo[];

    return (OSThread *) D_8080458C_chevilmumbo;
}
