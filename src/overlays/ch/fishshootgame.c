#include "common.h"

OSThread *chfishshootgame_entrypoint_0(void)
{
    extern ActorData D_808018C0_chfishshootgame[];

    return (OSThread *) D_808018C0_chfishshootgame;
}

void func_8080000C_chfishshootgame(Actor *arg0) {
    f32 _dbskeleton_entrypoint_1(void *);
    Prop *_gccubesearch_entrypoint_0(u32, Actor *);
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 _glcutDll_entrypoint_20();
    void _gspropctrl_entrypoint_10(Prop *, s16 *);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    void _susubgame_entrypoint_0(BtIntPtr arg0, u8 *arg1, s32 arg2);
    s32 _susubgame_entrypoint_11(s32);
    void _susubgame_entrypoint_12(void *arg0, void *arg1);
    u8 *func_800B27E0(u8 *);
    f32 func_800BED50(f32 *);
    s32 func_800D0A9C(u32, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    u8 *func_801039E4(Unk80132ED0 *);
    void func_80108B04(Actor *, u32);
    extern s32 D_808018B0_chfishshootgame[4];
    struct FishShootData {
        f32 position[3];
        f32 target[3];
        f32 unk18[2];
        f32 height;
        f32 unk24;
        f32 skeleton;
        f32 distance;
        s16 unk30;
        s16 current;
        s16 count;
        s16 positions[20][3];
        s16 unkAE;
        u32 subgame[1];
    };
    s32 i;
    struct FishShootData *data;
    Prop *props[20];
    u32 *subgame;
    u8 *skeleton;
    f32 *position[1];

    data = func_80100094(arg0, 0);
    _susubgame_entrypoint_11(0);
    if (func_800D0A9C(0x21, 1) && !_glcutDll_entrypoint_20()) {
        func_800FFAB0(arg0);
        return;
    }
    position[0] = arg0->position;
    func_800EE7F8(data->position, position[0]);
    data->count = _gccubesearch_entrypoint_9(0x1C0, props, 20);
    data->current = -1;
    for (i = 0; i < data->count; i++) {
        _gspropctrl_entrypoint_10(props[i], data->positions[i]);
    }
    props[0] = _gccubesearch_entrypoint_0(0x1C1, arg0);
    _gspropctrl_entrypoint_11(props[0], data->target);
    data->height = func_800BED50(position[0]);
    skeleton = func_800B27E0(func_801039E4(arg0->unk0));
    data->skeleton = _dbskeleton_entrypoint_1(skeleton);
    data->distance = 32000.0f;
    func_80108B04(arg0, 1);
    subgame = data->subgame;
    _susubgame_entrypoint_0(arg0, subgame, 0);
    _susubgame_entrypoint_12(subgame, D_808018B0_chfishshootgame);
}

void func_80800178_chfishshootgame(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    s32 _susubgame_entrypoint_2(void *, BtIntPtr);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    s32 func_800FCCD4(s32);
    void *func_80100094(Actor *, u32);
    s32 data[2];

    data[1] = (BtIntPtr)func_80100094(arg0, 0);
    _susubgame_entrypoint_11(0);
    if (func_800FCCD4(0x53) != 0) {
        func_800FCAE0(0x53, 0, 0xFA0);
        func_800FCA90(0x53);
    }
    data[0] = data[1] + 0xB0;
    if (_susubgame_entrypoint_2(arg0, data[0]) != 0) {
        _susubgame_entrypoint_4(arg0, data[0]);
    }
}

void func_808001F0_chfishshootgame(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800B5BE4(s32);
    void func_800BA4D0(s16 *, s16);
    void func_800BA544(s32 *, BtIntPtr);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    extern s32 D_80801908_chfishshootgame[2];
    extern s32 D_80801910_chfishshootgame[];
    extern s32 D_80801934_chfishshootgame[];
    extern s32 _fxsplash_entrypoint_0;
    u8 *sp44;
    f32 sp38[3];
    f32 sp2C[3];
    BtIntPtr sp28;

    sp44 = func_80100094(arg0, 0);
    func_800EE7F8(sp38, arg0->position);
    sp38[1] = *(f32 *)(sp44 + 0x20);
    func_800BBCB8(sp38, NULL, 1.0f, 1, D_80801910_chfishshootgame);
    sp28 = func_800B5BE4(1);
    func_800BA4D0((s16 *)sp28, (s16)(s32)sp38[1]);
    func_800BA544((s32 *)sp28, (BtIntPtr)&_fxsplash_entrypoint_0);
    func_800EE7F8(sp2C, sp38);
    sp2C[1] -= 200.0f;
    func_800BABB8(sp28, sp38, sp2C, 1.0f, D_80801934_chfishshootgame);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801908_chfishshootgame);
}

void func_808002E8_chfishshootgame(Actor *arg0, f32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor*, f32[3], void*);
    void func_800C4B64(f32);
    extern s32 D_80801978_chfishshootgame[3];
    func_800C4B64(arg1);
    _subaddieaudioquick_entrypoint_2(arg0, &arg0->position[0], D_80801978_chfishshootgame);
}

void func_80800320_chfishshootgame(Actor *arg0) {
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    u8 *sp34;
    f32 sp28[3];

    sp34 = func_80100094(arg0, 0);
    func_800EE7F8(sp28, arg0->position);
    sp28[1] -= 100.0f;
    func_800D1000(0x21, 1, arg0->position, 4, arg0->unk0);
    _susubgame_entrypoint_6(arg0, sp34 + 0xB0, 0, 0x2090, 0);
}

Actor *func_80106790(Unk80132ED0 *);

void func_808003B0_chfishshootgame(Actor *arg0, s32 arg1) {
    void _gcdialogcamera_entrypoint_4(BtIntPtr arg0);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    s32 _susubgame_entrypoint_5(BtIntPtr arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    s32 func_80090270(void);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800DA3B8(s32, s32);
    void func_800DA544(s32 index);
    void func_800FC6B0(u32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    void func_800FFA88(Unk80132ED0 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80800A90_chfishshootgame(Actor *, f32 *);
    extern s32 D_80801984_chfishshootgame[2];
    struct FishShootData {
        f32 position[3];
        f32 target[3];
        f32 unk18[2];
        f32 height;
        f32 unk24;
        f32 skeleton;
        f32 distance;
        s8 unk30;
        s8 unk31;
        s16 current;
        s16 count;
        s16 positions[20][3];
        s16 unkAE;
        u32 subgame[1];
    };
    struct FishShootData *data;
    s32 dialog;
    s32 flag;
    u32 oldState;
    f32 position[3];

    data = func_80100094(arg0, 0);
    dialog = 0;
    flag = 0;
    oldState = arg0->unk70_10;
    if (arg1 != oldState) {
        switch (arg1) {
        case 13:
            _susubgame_entrypoint_4(arg0, (BtIntPtr)data->subgame);
            func_808002E8_chfishshootgame(arg0, 0.8f);
            func_800FFAB0(arg0);
            func_800FFA88(arg0->unk3C);
            return;
        case 2:
            if (oldState != 1) {
                _susubgame_entrypoint_5(arg0, data->subgame, 3, 1, 0);
                dialog = 0xFEF;
            }
            break;
        case 10:
            data->unk18[0] = 0.0f;
            data->unk18[1] = 0.05f;
            data->unk30 = 0;
            func_800DA3B8(0, 0);
            break;
        case 12:
            if (oldState == 4) {
                func_800FC6B0(0x16);
                func_800FCAE0(0x53, 0, 0xFA0);
                func_800FCA90(0x53);
                func_800DA3B8(0, 1);
                dialog = 0x1024;
                _susubgame_entrypoint_5(arg0, data->subgame, 3, 1, 0);
                func_80800A90_chfishshootgame(arg0, position);
                position[1] -= 60.0f;
                _gcdialogcamera_entrypoint_4(position);
            } else {
                dialog = 0x1023;
                func_808002E8_chfishshootgame(arg0, 1.2f);
                _susubgame_entrypoint_5(arg0, data->subgame, 5, 1, 0);
            }
            break;
        case 11:
            _susubgame_entrypoint_6(arg0, data->subgame, 11, 0x2090, 0);
            func_800DA3B8(0, 1);
            break;
        case 4:
            _susubgame_entrypoint_4(arg0, (BtIntPtr)data->subgame);
            arg0->unk58 = 0.0f;
            func_800CE8D8(0, 60.0f, 60);
            func_800CE88C(0, 1);
            func_800FC6B0(0x53);
            break;
        case 5:
            func_800CE88C(0, 0);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801984_chfishshootgame);
            data->unk30 = 1;
            flag = 1;
            break;
        case 7:
            flag = 1;
            func_808001F0_chfishshootgame(arg0);
            break;
        case 3:
            func_808002E8_chfishshootgame(arg0, 1.0f);
            break;
        case 6:
            data->unk18[1] = 0.1f;
            if (data->unk18[0] < 0.5f) {
                data->unk18[0] = 1.0f - data->unk18[0];
            }
            break;
        case 8:
            dialog = 0xFEE;
            _susubgame_entrypoint_5(arg0, data->subgame, 3, 1, 0);
            break;
        case 9:
            data->unk18[0] = 0.5f;
            data->target[1] = data->position[1];
            data->position[1] += 900.0f;
            data->unk18[1] = 0.1f;
            _susubgame_entrypoint_6(arg0, data->subgame, 4, 0x2090, 0);
            break;
        }
        func_80102424(arg0, arg1);
        func_80102424(func_80106790(arg0->unk3C), arg1);
        if (dialog != 0 && func_80090270() == 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 0xA, arg0->position, 0x63);
        }
        if (flag != 0) {
            func_800DA544(0);
        }
    }
}

void func_8080076C_chfishshootgame(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_800DA544(s32 index);
    s32 _susubgame_entrypoint_2(void *, BtIntPtr);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    s32 _susubgame_entrypoint_5(BtIntPtr arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    struct FishShootData {
        f32 position[3];
        f32 target[3];
        f32 unk18[2];
        f32 height;
        f32 unk24;
        f32 skeleton;
        f32 distance;
        s16 unk30;
        s16 current;
        s16 count;
        s16 positions[20][3];
        s16 unkAE;
        u32 subgame[1];
    };
    s32 state;
    s32 dialog;
    union { s32 value; volatile s32 access; } flags;
    struct FishShootData *data;

    flags.value = 0xE;
    state = 0;
    dialog = 0;
    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0xFEC:
        dialog = 0x105E;
        flags.value = 0x4E;
        break;
    case 0x105E:
        func_800DA544(0x449);
    case 0xFED:
        if (arg2 == 1) { dialog = 0x1025; } else { dialog = 0x1026; }
        break;
    case 0xFEE:
        func_80800320_chfishshootgame(arg0);
        break;
    case 0xFEF:
        _susubgame_entrypoint_5(arg0, data->subgame, 5, 1, 0);
        dialog = 0x105F;
        flags.value = 0x4E;
        break;
    case 0x105F:
        if (arg2 == 1) {
            dialog = 0x1025;
        } else {
            dialog = 0x1026;
        }
        flags.access = 0xE;
        break;
    case 0xFF0:
        state = 9;
        break;
    case 0x1023:
        state = 4;
        break;
    case 0x1024:
        state = 0xB;
        break;
    case 0x1025:
        if (_susubgame_entrypoint_2(arg0, (BtIntPtr)data->subgame)) {
            _susubgame_entrypoint_4(arg0, (BtIntPtr)data->subgame);
        }
        state = 3;
        break;
    case 0x1026:
        if (_susubgame_entrypoint_2(arg0, (BtIntPtr)data->subgame)) {
            _susubgame_entrypoint_4(arg0, (BtIntPtr)data->subgame);
        }
    case 0x1060:
        state = 1;
        break;
    default:
        break;
    }
    if (state != 0) {
        func_808003B0_chfishshootgame(arg0, state);
    }
    if (dialog != 0) {
        _subaddiedialog_entrypoint_11(arg0->unk0, dialog, flags.value, arg0->position, 0x63);
    }
}

void func_808009C0_chfishshootgame(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 _subaddiedialog_entrypoint_7(BtIntPtr, BtIntPtr, s32 *);
    extern s32 D_8080198C_chfishshootgame[5];
    extern u16 D_808019A0_chfishshootgame[];
    s32 i;

    if (func_800DA298(0x449)) { for (i = 0; i < 1; i = 1) { D_808019A0_chfishshootgame[i] |= 0x42; } }
    else { for (i = 0; i < 1; i = 1) { D_808019A0_chfishshootgame[i] &= ~0x40; } }
    _subaddiedialog_entrypoint_7((BtIntPtr)arg0, (BtIntPtr)arg0 + 4, D_8080198C_chfishshootgame);
}

void func_80800A28_chfishshootgame(Actor *arg0) {
    void *func_8008AEDC(void *);
    s32 *func_8008C27C(void *);
    void *func_80100094(Actor *, u32);
    struct anctrl_s *func_80104248(void *);
    void func_800DFC20(s32 *, s32, f32 *);
    s32 pad;
    s32 *sp30;
    u8 *sp2C;
    f32 sp20[3];

    sp30 = func_8008C27C(func_8008AEDC(func_80104248(arg0)));
    sp2C = func_80100094(arg0, 0U);
    func_800DFC20(sp30, 0x5D, sp20);
    *(f32 *)(sp2C + 0x24) = *(f32 *)(sp2C + 0x28) * sp20[1];
}    typedef struct { u8 pad0[0x24]; f32 unk24; } Objfishshootgame_func_80800A90_chfishshootgame_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

void func_80800A90_chfishshootgame(Actor *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    func_800EE7F8(arg1, arg0->position);
    arg1[1] += (((Objfishshootgame_func_80800A90_chfishshootgame_sp1C *)sp1C)->unk24) + 60.0f;
}

/* extern */

void func_80800AF0_chfishshootgame(Actor *arg0) {
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    arg0->unk3C = func_80108528(0x1D0, arg0->position, 0, &arg0)->unk0;
}

void func_80800B30_chfishshootgame(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    void func_800EE88C(f32 *, s16 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    f32 position[3];
    struct FishShootData {
        f32 unk0;
        f32 unk4;
        f32 unk8[2];
        f32 unk10;
        f32 unk14;
        f32 unk18;
        f32 unk1C;
        f32 unk20;
        u8 unk24[14];
        s16 unk32;
        s16 unk34;
        s16 unk36[1][3];
    };
    Actor *actor;
    struct FishShootData *data;

    data = func_80100094(arg0, 0);
    func_800EE88C(position, data->unk36[data->unk32]);
    position[1] = arg0->position[1] + func_800DC178(-200.0f, 0.0f);
    if (position[1] < data->unk10) {
        position[1] = data->unk10;
    } else {
        if (data->unk4 < position[1]) {
            position[1] = data->unk4;
        }
    }
    actor = func_80108528(0x1BF, position, 0, &arg0);
    actor->unk3C = arg0->unk0;
    actor->unk58 = data->unk18 * 100.0f + 100.0f;
    actor->unk50 = data->unk20;
}

void func_80800C24_chfishshootgame(u8 *arg0) {
    u8 func_800C4350(u8, f32[3], s32 *);
    extern s32 D_808019A8_chfishshootgame[4];
    if (arg0[0x5F] == 0) {
        arg0[0x5F] = func_800C4350(0, NULL, D_808019A8_chfishshootgame);
    }
    func_800C4350(arg0[0x5F], NULL, NULL);
}

void func_80800C78_chfishshootgame(Actor *arg0, s32 arg1, f32 arg2) {
    f32 func_800D8FF8(void);
    void *func_80100094(Actor *, u32);
    void func_808003B0_chfishshootgame(Actor *, s32);
    struct FishShootData {
        f32 unk0;
        f32 unk4;
        f32 unk8[2];
        f32 unk10;
        f32 unk14;
        f32 unk18;
        f32 unk1C;
    };
    struct FishShootData *data;
    f32 start;
    f32 fraction;
    f32 progress;
    f32 delta;

    data = func_80100094(arg0, 0);
    delta = func_800D8FF8();
    data->unk18 += data->unk1C * delta;
    progress = data->unk18;
    if (arg2 < progress) {
        data->unk18 = arg2;
        func_808003B0_chfishshootgame(arg0, arg1);
        progress = data->unk18;
    }
    if (progress > 0.5f) {
        fraction = 1.0f - progress;
    } else {
        fraction = progress;
    }
    start = data->unk4;
    arg0->position[1] = (data->unk10 - start) * (2.0f * fraction) + start;
    func_80800C24_chfishshootgame((u8 *)arg0);
}

void func_80800D48_chfishshootgame(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 func_8008FB10(f32 *, f32, f32, f32);
    f32 func_800CEA60(s32);
    s32 func_800CEAD0(s32);
    f32 func_800D8FF8(void);
    s32 func_800DC128(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800FC6B0(u32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80108B04(Actor *, u32);
    void func_8010C788(BtIntPtr, f32, f32, f32);
    extern u32 D_808019B8_chfishshootgame[];
    extern u32 D_808019C8_chfishshootgame[];
    struct FishShootData {
        f32 position[3];
        f32 target[3];
        f32 unk18[2];
        f32 height;
        f32 unk24;
        f32 skeleton;
        f32 distance;
        u8 active;
        u8 pad31;
        s16 current;
        s16 count;
    };
    struct FishShootData *data;
    f32 delta;
    f32 position[3];
    f32 offset[3];
    s32 current;
    s32 state;
    Unk80132ED0 *marker;

    data = func_80100094(arg0, 0);
    delta = func_800D8FF8();
    func_80800A28_chfishshootgame(arg0);
    func_80800A90_chfishshootgame(arg0, position);
    position[1] -= 60.0f;
    func_800EFA4C(offset, position[0] - 1.0f, position[1], position[2] - 17.0f);
    func_8010C788(offset, 340.0f, 0.0f, 160.0f);
    position[1] += 340.0f;
    func_8008FB10(position, 2500.0f, 0.0f, 10.0f);
    switch (arg0->unk70_10) {
        case 1:
            func_808009C0_chfishshootgame(arg0);
            break;
        case 4:
            if (func_800CEAD0(0)) {
                func_808003B0_chfishshootgame(arg0, 12);
            } else {
                arg0->unk58 -= delta;
                if (arg0->unk58 < 0.0f) {
                    do {
                        current = func_800DC128(0, data->count);
                    } while (current == data->current);
                    data->current = current;
                    func_80108B04(arg0, 0);
                    arg0->unk58 = (1.0f - func_800CEA60(0) / 60.0f) * -1.5f + 4.0f;
                }
            }
            break;
        case 5:
            if (func_80101E14(arg0, 0.999f)) {
                func_800FC6B0(0x17);
                func_800FCAE0(0x53, 0, 4000);
                func_800FCA90(0x53);
                func_808003B0_chfishshootgame(arg0, 6);
            }
            break;
        case 6:
        case 11:
            func_80800C78_chfishshootgame(arg0, 7, 1.0f);
            break;
        case 9:
            func_80800C78_chfishshootgame(arg0, 13, 1.0f);
        case 8:
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_808019C8_chfishshootgame, D_808019B8_chfishshootgame);
            break;
        case 3:
            if (func_80101E14(arg0, 0.02f)) {
                func_808001F0_chfishshootgame(arg0);
            }
            if (func_80101E14(arg0, 0.8f)) {
                func_808002E8_chfishshootgame(arg0, 1.1f);
            }
            if (func_80101F24(arg0) > 0.2f && func_80101F24(arg0) < 0.8f) {
                func_80800C24_chfishshootgame((u8 *)arg0);
            }
            if (func_80101E14(arg0, 0.999f)) {
                func_808003B0_chfishshootgame(arg0, 10);
            }
            break;
        case 10:
            func_80800C78_chfishshootgame(arg0, 12, 0.5f);
            break;
        case 7:
            if (func_80101F24(arg0) < 0.8f) {
                func_80800C24_chfishshootgame((u8 *)arg0);
            }
            if (func_80101E14(arg0, 0.9f)) {
                func_808002E8_chfishshootgame(arg0, 1.0f);
            }
            if (func_80101E14(arg0, 0.999f)) {
                state = data->active ? 2 : 8;
                func_808003B0_chfishshootgame(arg0, state);
            }
            break;
    }
    marker = arg0->unk3C;
    if (marker != NULL) {
        func_800EE7F8(func_80106790(marker)->position, arg0->position);
    }
}

s32 func_80801110_chfishshootgame(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_19(f32[3]);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    s32 _glcutDll_entrypoint_20();
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    s32 _susubgame_entrypoint_5(BtIntPtr arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
    Unk80132ED0 *func_800D0634(u32, u32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    extern s32 D_808018B0_chfishshootgame[4];
    struct FishShootData {
        f32 position[3];
        f32 target[3];
        f32 unk18[2];
        f32 height;
        f32 unk24;
        f32 skeleton;
        f32 distance;
        s16 unk30;
        s16 current;
        s16 count;
        s16 positions[20][3];
        s16 unkAE;
        u32 subgame[1];
    };
    Unk80132ED0 *marker;
    f32 position[3];
    struct FishShootData *data;
    struct FishShootData *initial;

    initial = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x95:
            func_8080000C_chfishshootgame(arg0);
            if (_glcutDll_entrypoint_20()) {
                func_80102424(arg0, 8);
            }
            break;
        case 0x3D:
            switch (arg2) {
                case 1:
                    func_80800AF0_chfishshootgame(arg0);
                    break;
                case 0:
                    func_80800B30_chfishshootgame(arg0);
                    break;
            }
            break;
        case 0x2E:
            func_8080076C_chfishshootgame(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0xE:
            if (arg2 == 0) {
                data = func_80100094(arg0, 0);
                marker = func_800D0634(0x21, 1);
                if (marker != NULL) {
                    func_800EE7F8(position, func_80106790(marker)->position);
                    if (position[1] < data->distance) {
                        data->distance = position[1];
                    }
                    position[1] = data->distance;
                } else {
                    func_800EE7F8(position, arg0->position);
                }
                _capod_entrypoint_19(position);
                return 3;
            }
            func_80800A90_chfishshootgame(arg0, position);
            _capod_entrypoint_19(position);
            return 3;
        case 0xB:
            if (arg2 == 0) {
                _susubgame_entrypoint_5(arg0, initial->subgame, 3, 1, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xFF0, 0xE, arg0->position, 0x63);
                return 4;
            }
            return 3;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808018B0_chfishshootgame, arg0->scale);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(arg0, initial->subgame, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        default:
            return 0;
    }
    return 1;
}

OSThread *chfishshootgame_entrypoint_1(void)
{
    extern ActorData D_80801A00_chfishshootgame[];

    return (OSThread *) D_80801A00_chfishshootgame;
}

void func_80801358_chfishshootgame(Actor *arg0) { union { f32 values[2]; f64 alignment; } result; Actor *actor = func_80106790(arg0->unk3C); func_80800A90_chfishshootgame(actor, (f32 *)arg0->actorData); func_800F18FC(arg0->position, (f32 *)arg0->actorData, result.values); arg0->rotation[1] = result.values[1]; arg0->rotation[0] = -result.values[0]; }

void func_808013B8_chfishshootgame(void *arg0)
{
  f32 func_800D8FF8();
  s32 func_8010B990(void *, s32);
  f32 temp_f0;
  *((f32 *) (((s8 *) arg0) + 0x24)) = (f32) ((((Actor *)arg0)->unk58) * func_800D8FF8());
  func_8010B990(arg0, 0x100008);
  temp_f0 = ((Actor *)arg0)->unk50;
  if (temp_f0 < ((((Actor *)arg0)->position[1]) + 40.0f))
  {
    ((Actor *)arg0)->position[1] = (f32) (temp_f0 - 40.0f);
  }
}

void func_80801424_chfishshootgame(Actor *arg0, s32 arg1) {
    BtIntPtr _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefade_entrypoint_3(Actor *);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    extern s32 D_80801A48_chfishshootgame[];
    extern u8 D_80801A64_chfishshootgame[];
    extern u8 D_80801A6C_chfishshootgame[];
    s32 sp2C = 0;
    s32 *state = &arg1;

    if (arg1 != arg0->unk70_10) {
        switch (arg1 = *state) {
            case 1:
                func_800BABB8(_fxairbub_entrypoint_1(arg0->position, 40.0f, arg0->unk50, 4.0f), arg0->position, NULL, 1.0f, D_80801A48_chfishshootgame);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801A64_chfishshootgame);
                break;
            case 3:
                break;
            case 4:
                func_800BABB8(_fxairbub_entrypoint_1(arg0->position, 30.0f, arg0->unk50, 4.0f), arg0->position, NULL, 1.0f, D_80801A48_chfishshootgame);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801A6C_chfishshootgame);
                sp2C = 1;
                break;
            case 5:
                sp2C = 1;
                _subaddiefade_entrypoint_3(arg0);
                break;
        }
        func_80102424(arg0, *state);
        if (sp2C != 0) {
            func_8010A570(arg0);
        }
    }
}

/* extern */

void func_80801568_chfishshootgame(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    void func_80801424_chfishshootgame(Actor *, s32);
    arg0->scale = 0.3f;
    if (arg0->unk58 < 100.0f) {
        arg0->unk58 = func_800DC178(100.0f, 200.0f);
    }
    func_80801358_chfishshootgame(arg0);
    arg0->unk70_10 = 0;
    func_80801424_chfishshootgame(arg0, 1);
}

void func_808015DC_chfishshootgame(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefade_entrypoint_3(Actor *);
    s32 func_800DA298(s32);
    f32 func_800EEAD4(f32 *, f32 *);
    s32 func_80101E14(Actor *, f32);
    void func_80101FDC(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor *);
    void func_808003B0_chfishshootgame(Actor *, s32);
    extern u8 D_80801A74_chfishshootgame[];

    switch (arg0->unk70_10) {
        case 1:
            func_80101FDC(arg0, 2);
            break;
        case 2:
            func_80801358_chfishshootgame(arg0);
            func_808013B8_chfishshootgame(arg0);
            if (func_800DA298(0) != 0) {
                func_80801424_chfishshootgame(arg0, 5);
            } else if (func_800EEAD4(arg0->position, (f32 *)arg0->actorData) < 100.0f) {
                func_80801424_chfishshootgame(arg0, 3);
            }
            break;
        case 4:
            if (0.0f != arg0->rotation[0]) {
                arg0->rotation[0] *= 0.75f;
            }
            if (func_80101E14(arg0, 0.999f) != 0) {
                _subaddiefade_entrypoint_3(arg0);
            }
            break;
        case 3:
            if (func_80101E14(arg0, 0.54f) != 0) {
                func_808003B0_chfishshootgame(func_80106790(arg0->unk3C), 5);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801A74_chfishshootgame);
                func_8010A570(arg0);
            }
            if (func_80101E14(arg0, 0.999f) != 0) {
                _subaddiefade_entrypoint_3(arg0);
            }
            break;
    }
}

/* extern */

s32 func_80801768_chfishshootgame(BtIntPtr arg0, s32 arg1, s32 arg2) {
    void func_80801424_chfishshootgame(Actor *, s32);
    if (arg1 == 0x40) {
        func_80801424_chfishshootgame(arg0, 4);
        return 1;
    }
    return 0;
}

OSThread *chfishshootgame_entrypoint_2(void)
{
    extern ActorData D_80801A7C_chfishshootgame[];

    return (OSThread *) D_80801A7C_chfishshootgame;
}
/* data_to_c.py: from asm/data/overlays/ch/fishshootgame.data.s */
extern u8 D_80801840_chfishshootgame[];
void func_80102EC0();
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
extern u8 D_808019D0_chfishshootgame[];
OSThread *func_80108ED0(void);
u8 D_80801840_chfishshootgame[112] BT_DATA(4, overlays_ch_fishshootgame, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x40, 0x00, 0x00, 0x01, 0x70, 0x00, 0x00, 0x41, 0x40, 0x00, 0x00, 0x01, 0x70, 0x00, 0x00, 0x40, 0x95, 0x58, 0x10, 0x01, 0x6F, 0x00, 0x02, 0x40, 0xAE, 0xB8, 0x52, 0x01, 0x6E, 0x00, 0x00, 0x3F, 0x99, 0x99, 0x9A, 0x01, 0x6D, 0x00, 0x02, 0x40, 0xAE, 0xB8, 0x52, 0x01, 0x6E, 0x00, 0x00, 0x3F, 0xA6, 0x66, 0x66, 0x01, 0x6B, 0x00, 0x02, 0x40, 0x80, 0x00, 0x00, 0x01, 0x6C, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x01, 0x6C, 0x00, 0x00, 0x40, 0xAE, 0xB8, 0x52, 0x01, 0x6E, 0x00, 0x00, 0x40, 0xAE, 0xB8, 0x52, 0x01, 0x6E, 0x00, 0x00, 0x40, 0xAE, 0xB8, 0x52, 0x01, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
s32 D_808018B0_chfishshootgame[4] BT_DATA(4, overlays_ch_fishshootgame, 0x70) = { 1128136704, 1126170624, 1126170624, 1120403456 };
ActorData D_808018C0_chfishshootgame [1] BT_DATA(4, overlays_ch_fishshootgame, 0x80) = { { 344, 446, 1745, 1, (void *)D_80801840_chfishshootgame, (void (*)(struct Actor *))func_80800D48_chfishshootgame, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_80101870, 327680000, 1073741824, 0, 0, 0, 256, (void (*)(struct Actor *))func_80800178_chfishshootgame, 0, 200, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80801110_chfishshootgame, 0 } };
s32 D_80801908_chfishshootgame[2] BT_DATA(4, overlays_ch_fishshootgame, 0xC8) = { 1246555, 1769472 };
s32 D_80801910_chfishshootgame [9] BT_DATA(4, overlays_ch_fishshootgame, 0xD0) = { 1903067, 1445889, 2752512, 512, 41943061, 128, 2228736, 33555968, 100663296 };
s32 D_80801934_chfishshootgame [17] BT_DATA(4, overlays_ch_fishshootgame, 0xF4) = { 1903066, 2162687, -21757925, -85132564, 458753, 1376256, 13369378, 327690, 131074, 2818560, 33554454, 268435501, 26215100, 720996, 7864320, 7706, 0 };
s32 D_80801978_chfishshootgame[3] BT_DATA(4, overlays_ch_fishshootgame, 0x138) = { 1246554, 1900571, 0 };
s32 D_80801984_chfishshootgame[2] BT_DATA(4, overlays_ch_fishshootgame, 0x144) = { 1246558, 1769472 };
s32 D_8080198C_chfishshootgame[5] BT_DATA(4, overlays_ch_fishshootgame, 0x14C) = { 71893592, 267128813, 1, 274726912, 6488066 };
u16 D_808019A0_chfishshootgame [4] BT_DATA(4, overlays_ch_fishshootgame, 0x160) = { 0xA, 0xE28, 0x200, 0 };
s32 D_808019A8_chfishshootgame[4] BT_DATA(4, overlays_ch_fishshootgame, 0x168) = { 33947667, 85327894, 1310720027, 0 };
u32 D_808019B8_chfishshootgame [4] BT_DATA(4, overlays_ch_fishshootgame, 0x178) = { 0x3E23D70A, 0x3E8F5C29, 0x3ECCCCCD, 0xBF800000 };
u32 D_808019C8_chfishshootgame [2] BT_DATA(4, overlays_ch_fishshootgame, 0x188) = { 0x13055F, 0 };
u8 D_808019D0_chfishshootgame[48] BT_DATA(4, overlays_ch_fishshootgame, 0x190) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x01, 0xC2, 0x00, 0x00, 0x3F, 0x1C, 0x28, 0xF6, 0x01, 0xC2, 0x00, 0x00, 0x3F, 0x1C, 0x28, 0xF6, 0x01, 0xC3, 0x00, 0x02, 0x40, 0x0A, 0x3D, 0x71, 0x01, 0xC4, 0x00, 0x02, 0x3F, 0x80, 0x00, 0x00, 0x01, 0xC2, 0x00, 0x00 };
ActorData D_80801A00_chfishshootgame [1] BT_DATA(4, overlays_ch_fishshootgame, 0x1C0) = { { 456, 447, 1758, 1, (void *)D_808019D0_chfishshootgame, (void (*)(struct Actor *))func_808015DC_chfishshootgame, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_80101870, 327680000, 1077936128, 0, 0, 0, 268, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80801568_chfishshootgame, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32736, 0, (void (*)(struct Actor *, long, long))func_80801768_chfishshootgame, 0 } };
s32 D_80801A48_chfishshootgame [7] BT_DATA(4, overlays_ch_fishshootgame, 0x208) = { 2949080, -2555944, 2621480, 2621474, 786455, 786455, 337248256 };
u8 D_80801A64_chfishshootgame [8] BT_DATA(4, overlays_ch_fishshootgame, 0x224) = { 0, 0x13, 5, 0x5D, 0, 0x1B, 0, 0 };
u8 D_80801A6C_chfishshootgame [8] BT_DATA(4, overlays_ch_fishshootgame, 0x22C) = { 0, 0x13, 5, 0x5C, 0, 0x1B, 0, 0 };
u8 D_80801A74_chfishshootgame [8] BT_DATA(4, overlays_ch_fishshootgame, 0x234) = { 0, 0x13, 4, 0x9C, 0, 0x1B, 0, 0 };
ActorData D_80801A7C_chfishshootgame [1] BT_DATA(4, overlays_ch_fishshootgame, 0x23C) = { { 344, 464, 1779, 1, (void *)D_80801840_chfishshootgame, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_80101870, 327680000, 0, 0, 0, 0, 1028, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, 0, 0 } };
