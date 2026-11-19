#include "su/baddiedialog_descriptor.h"

OSThread *chbottlesfamily_entrypoint_0(void)
{
    extern ActorData D_80800DE0_chbottlesfamily[];

    return (OSThread *) D_80800DE0_chbottlesfamily;
}

OSThread *chbottlesfamily_entrypoint_1(void)
{
    extern ActorData D_80800E28_chbottlesfamily[];

    return (OSThread *) D_80800E28_chbottlesfamily;
}

OSThread *chbottlesfamily_entrypoint_2(void)
{
    extern ActorData D_80800E70_chbottlesfamily[];

    return (OSThread *) D_80800E70_chbottlesfamily;
}

void func_80800024_chbottlesfamily(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    void func_80102424(Actor *, s32);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale / 3.0f);
    arg0->unk64_20 = 1;
    if (_glcutDll_entrypoint_20(arg0) != 0) {
        func_80102424(arg0, 5);
    }
}

void func_80800080_chbottlesfamily(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    u32 *_suexpression_entrypoint_20(Actor *);
    s32 func_808009F0_chbottlesfamily(BtIntPtr, subaddiedialog_UnkStruct0 *);
    extern s16 D_80800EB8_chbottlesfamily[10];
    extern f32 D_80800ECC_chbottlesfamily[4];
    extern subaddiedialog_UnkStruct0 D_80800EDC_chbottlesfamily;
    _sudeflect_entrypoint_0(arg0->position, arg0->scale * 50.0f, arg0->scale * 50.0f, 0xA);
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80800EB8_chbottlesfamily, D_80800ECC_chbottlesfamily);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(arg0), arg0->unk0, 0);
    if (arg0->unk70_10 == 1) {
        func_808009F0_chbottlesfamily((BtIntPtr)arg0, &D_80800EDC_chbottlesfamily);
    }
}

void func_80800124_chbottlesfamily(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    void _subaddierouteDll_entrypoint_3(BtIntPtr arg0, void *arg1, f32 *arg2);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    struct {
        f32 unk0[3];
        f32 unkC;
    } *data;

    data = func_80100094(arg0, 0);
    _subaddierouteDll_entrypoint_3(arg0, data, arg0->position);
    data->unkC = func_800DC178(2.5f, 5.0f);
    arg0->unk58 = func_800DC178(5.0f, 10.0f);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 5);
    }
}

void func_808001B0_chbottlesfamily(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void _subaddierouteDll_entrypoint_5(Actor *, void *, u32, f32, f32, f32);
    s32 _subaddierouteDll_entrypoint_6(Actor *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    u32 *_suexpression_entrypoint_20(Actor *);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80102BF8(void *, f32, f32, f32);
    s32 func_80102CF4(Actor *, f32);
    s32 func_80105230(Actor *, f32 *);
    s32 func_8010B990(Actor *, s32);
    f32 func_8010CD28(Actor *);
    s32 func_808004B4_chbottlesfamily(BtIntPtr);
    void func_80800520_chbottlesfamily(Actor *);
    void func_808005D0_chbottlesfamily(Actor *);
    extern s16 D_80800EF8_chbottlesfamily[6];
    struct {
        u16 unk0[3];
        u16 unk6;
        f32 unk8;
        f32 unkC;
    } *data;

    data = func_80100094(arg0, 0);
    _sudeflect_entrypoint_0(arg0->position, arg0->scale * 50.0f, arg0->scale * 50.0f, 10);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(arg0), arg0->unk0, 0);
    switch (arg0->unk70_10) {
        case 1:
            func_808005D0_chbottlesfamily(arg0);
            if (!func_808004B4_chbottlesfamily((BtIntPtr)arg0) && func_800D90A4(&arg0->unk58)) {
                func_80800520_chbottlesfamily(arg0);
            }
            break;
        case 2:
            arg0->unk54 = func_8010CD28(arg0);
            func_80102BF8(arg0, 0.1f, 4.0f, 120.0f);
            break;
        case 3:
            if (func_800D9078(&data->unkC)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800EF8_chbottlesfamily);
                data->unkC = func_800DC178(2.5f, 5.0f);
            }
            func_80105230(arg0, NULL);
            _subaddierouteDll_entrypoint_7(arg0, data, arg0->rotation[1], arg0->unk54, 200.0f, 0x401);
            _subaddierouteDll_entrypoint_6(arg0, data, data->unk6, 7, 0.7f, 8, 12);
            _subaddierouteDll_entrypoint_5(arg0, data, data->unk6, 0.1f, 4.0f, 120.0f);
            ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], 200.0f, func_800D8FF8() * 300.0f);
            func_8010B990(arg0, 0x1305);
            if (!func_808004B4_chbottlesfamily((BtIntPtr)arg0) && func_800D90A4(&arg0->unk58)) {
                func_80102424(arg0, 1);
                arg0->unk58 = func_800DC178(5.0f, 10.0f);
            }
            break;
        case 4:
            func_80105230(arg0, NULL);
            func_80102BF8(arg0, 0.1f, 4.0f, 120.0f);
            if (!func_808004B4_chbottlesfamily((BtIntPtr)arg0) && func_80102CF4(arg0, 10.0f)) {
                func_80102424(arg0, 3);
            }
            break;
        case 5:
            func_808005D0_chbottlesfamily(arg0);
            break;
    }
}

/* extern */

s32 func_8080046C_chbottlesfamily(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddierouteDll_entrypoint_1(Actor*);
    s32 func_80800720_chbottlesfamily(Actor*, s32, s32);
    s32 ret;
    if (arg1 == 0x95) {
        func_80800720_chbottlesfamily(arg0, arg1, arg2);
        _subaddierouteDll_entrypoint_1(arg0);
        ret = 1;
    } else {
        return func_80800720_chbottlesfamily(arg0, arg1, arg2);
    }
    return ret;
}

s32 func_808004B4_chbottlesfamily(BtIntPtr arg0) {
    s32 func_800DA298(s32);
    s32 func_808009F0_chbottlesfamily(BtIntPtr, subaddiedialog_UnkStruct0 *);
    extern subaddiedialog_UnkStruct0 D_80800F04_chbottlesfamily;
    BT_IDO_ONLY(extern s16 D_80800F08_chbottlesfamily;)
    if (func_800DA298(0x3B) != 0) {
        return 0;
    }
    if (func_800DA298(0x1A5) != 0) {
        BT_DATA_FIELD(D_80800F04_chbottlesfamily.unk4, D_80800F08_chbottlesfamily) = 0x1539;
    } else {
        BT_DATA_FIELD(D_80800F04_chbottlesfamily.unk4, D_80800F08_chbottlesfamily) = 0x1501;
    }
    return func_808009F0_chbottlesfamily(arg0, &D_80800F04_chbottlesfamily);
}

void func_80800520_chbottlesfamily(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void *data;
    f32 rotation;

    data = func_80100094(arg0, 0);
    rotation = arg0->rotation[1];
    arg0->unk54 = rotation;
    if (_subaddierouteDll_entrypoint_7(arg0, data, rotation, rotation + 180.0f, 200.0f, 0x401) == 0) {
        func_80102424(arg0, 3);
    } else {
        func_80102424(arg0, 4);
    }
    arg0->unk58 = func_800DC178(5.0f, 10.0f);
    ((f32 *)arg0->actorData)[3] = 0.0f;
}

void func_808005D0_chbottlesfamily(Actor *arg0) {
    extern s16 D_80800F20_chbottlesfamily[6];
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800F20_chbottlesfamily, 0x3DA3D70A);
}

/* extern */

void func_80800600_chbottlesfamily(Actor *arg0) {
    void func_80102424(Actor *, s32);
    s32 _glcutDll_entrypoint_20();
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 5);
    }
}

void func_80800630_chbottlesfamily(Actor *arg0) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    u32 *_suexpression_entrypoint_20(Actor *);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    s32 func_80101E4C(Actor *, f32 *);
    s32 func_808009F0_chbottlesfamily(BtIntPtr, subaddiedialog_UnkStruct0 *);
    extern subaddiedialog_UnkStruct0 D_80800F2C_chbottlesfamily;
    extern s16 D_80800F48_chbottlesfamily[8];
    extern s16 D_80800F58_chbottlesfamily[8];
    extern f32 D_80800F68_chbottlesfamily[4];
    extern f32 D_80800F78_chbottlesfamily[4];

    _sudeflect_entrypoint_0(arg0->position, arg0->scale * 50.0f, arg0->scale * 50.0f, 0xA);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(arg0), arg0->unk0, 0);
    if (arg0->unk70_10 == 1) {
        func_808009F0_chbottlesfamily((BtIntPtr) arg0, &D_80800F2C_chbottlesfamily);
    }
    if (func_80101E4C(arg0, D_80800F68_chbottlesfamily) != 0) {
        if (arg0->unk5F == 0) {
            arg0->unk5F = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
        }
        func_800C4350(arg0->unk5F, arg0->position, (s32 *)D_80800F48_chbottlesfamily);
    }
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80800F58_chbottlesfamily, D_80800F78_chbottlesfamily);
}

s32 func_80800720_chbottlesfamily(Actor *arg0, s32 arg1, s32 arg2) {
    BT_IDO_ONLY(BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);) BT_NATIVE_ONLY(void *_suexpression_entrypoint_7(Actor *, s32, s16);)
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    void func_8080088C_chbottlesfamily(Actor *, s32, s32);
    void func_8080099C_chbottlesfamily(Actor *, s32, s32);
    s32 func_80800A44_chbottlesfamily(Actor *);
    void func_80800A84_chbottlesfamily(Actor *);
    s32 func_80800B64_chbottlesfamily(void *, s32, s32);
    void *expression;

    switch (arg1) {
        case 0x2E:
            func_8080088C_chbottlesfamily(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x2F:
            func_8080099C_chbottlesfamily(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x52:
            func_80800A84_chbottlesfamily(arg0);
            break;
        case 0x57:
            return func_80800B64_chbottlesfamily(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x95:
            expression = (void *)_suexpression_entrypoint_7(arg0, 1, (s16)func_80800A44_chbottlesfamily(arg0));
            _suexpression_entrypoint_12(expression, 0x42700000, 0x41A00000);
            _suexpression_entrypoint_17(expression, 1000);
            break;
        case 0x1F:
            func_800DF744(3, arg0->unk64_20);
            func_801015D0(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080086C_chbottlesfamily(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
void func_8080088C_chbottlesfamily(Actor *arg0, s32 arg1, s32 arg2) {
    void _glcutDll_entrypoint_6(u32, u32);
    void func_8009032C(s32);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800FC6B0(u32);
    void func_80101FDC(Actor *, u32);
    void func_80800520_chbottlesfamily(Actor *);
    void func_80800BC0_chbottlesfamily(void *);

    switch (arg1) {
        case 0x1503:
            func_80800BC0_chbottlesfamily(arg0);
            func_8009032C(0x2B);
            func_800FC6B0(0xE);
            break;
        case 0x1501:
            func_80800BC0_chbottlesfamily(arg0);
            _glcutDll_entrypoint_6(0x142, 0x66);
            break;
        default:
            if (arg0->unk6C_0) {
                func_80800BC0_chbottlesfamily(arg0);
            }
            break;
    }
    if (arg0->unk6C_9 == 0x43C) {
        if (func_800DC298(0.5f)) {
            func_80800520_chbottlesfamily(arg0);
        } else {
            func_80101FDC(arg0, 1);
            arg0->unk58 = func_800DC178(5.0f, 10.0f) * 0.5f;
        }
    } else {
        func_80101FDC(arg0, 1);
    }
}

/* extern */

void func_8080099C_chbottlesfamily(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800C07F4();
    void func_80800CA4_chbottlesfamily(Actor *, s32, s32);
    if (((arg1 == 0x1501) || (arg1 == 0x1539)) && (arg2 == 1) && (func_800C07F4() == 0)) {
        func_80800CA4_chbottlesfamily(arg0, 4, 0x2020);
    }
}

s32 func_808009F0_chbottlesfamily(BtIntPtr arg0, subaddiedialog_UnkStruct0 *arg1) {
    s32 _subaddiedialog_entrypoint_7(BtIntPtr, BtIntPtr, subaddiedialog_UnkStruct0 *);
    void func_80800C08_chbottlesfamily(Actor *, s32, s32);
    s32 temp_v0;
    s32 var_v1;
    s32 sp1C;

    temp_v0 = _subaddiedialog_entrypoint_7(arg0, arg0 + 4, arg1);
    var_v1 = temp_v0;
    if ((temp_v0 != 0) && (temp_v0 != 0x1208)) {
        sp1C = temp_v0;
        func_80800C08_chbottlesfamily((u8 *) arg0, 3, 0);
        var_v1 = sp1C;
    }
    return var_v1 != 0;
}

 s32 func_80800A44_chbottlesfamily(Actor *arg0) { u32 temp_t7; temp_t7 = arg0->unk6C_9; switch (temp_t7) { case 0x43C: return 0xB0; case 0x43D: return 0xB1; default: return 0xAF; } }

void func_80800A84_chbottlesfamily(Actor *arg0) {
    s32 _gcdialogcamera_entrypoint_3(f32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_8010CD28(Actor *);
    extern f32 D_80800F88_chbottlesfamily[4];
    extern f32 D_80800F98_chbottlesfamily[4];
    extern f32 D_80800FA8_chbottlesfamily[4];
    f32 sp2C[3];
    u32 temp_t7;

    temp_t7 = arg0->unk6C_9;
    if (temp_t7 != 0x43B) {
        if (temp_t7 != 0x43C) {
            if (temp_t7 == 0x43D) {
                _gcdialogcamera_entrypoint_3(D_80800F88_chbottlesfamily, arg0->scale);
                _gcdialogcamera_entrypoint_5(arg0->rotation);
            }
        } else {
            func_800EFA4C(sp2C, 0.0f, func_8010CD28(arg0), 0.0f);
            _gcdialogcamera_entrypoint_3(D_80800F98_chbottlesfamily, arg0->scale);
            _gcdialogcamera_entrypoint_5(sp2C);
        }
    } else {
        _gcdialogcamera_entrypoint_3(D_80800FA8_chbottlesfamily, arg0->scale * 3.0f);
        _gcdialogcamera_entrypoint_5(arg0->rotation);
    }
    _gcdialogcamera_entrypoint_4(arg0->position);
}

/* extern */

s32 func_80800B64_chbottlesfamily(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_80800C08_chbottlesfamily(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if (((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) != 2) {
            func_80800C08_chbottlesfamily(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80800BC0_chbottlesfamily(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

void func_80800C08_chbottlesfamily(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_8(void);

    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x18, 0);
        case 1:
            _capod_entrypoint_8(1);
            arg0->unk6C_0 = 2;
            func_80800A84_chbottlesfamily(arg0);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80800CA4_chbottlesfamily(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x18, arg2);
        case 2:
            arg0->unk6C_0 = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}
#include "family_data.inc"
