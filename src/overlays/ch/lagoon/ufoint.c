#include "common.h"

OSThread *chlagoonufoint_entrypoint_0(void)
{
    extern u8 D_80801948_chlagoonufoint[];

    return (OSThread *) D_80801948_chlagoonufoint;
}

void func_8080000C_chlagoonufoint(Actor *arg0, s32 arg1) {
    typedef struct {
        f32 unk0[3];
        f32 unkC;
        f32 unk10[3];
    } UfoIntData;
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, Unk80132ED0 *);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    void func_800FC63C(u32, u32);
    void *func_80100094(Actor *, u32);
    switch (arg1) {
        case 1:
            func_800DA524(0);
            break;
        case 2:
            func_800CE8D8(0, 20.0f, 0x14);
            func_800CE88C(0, 1);
            break;
        case 4:
            func_800CE88C(0, 0);
            func_800FC63C(0x10, 0x6D60);
            _susubgame_entrypoint_6(arg0, func_80100094(arg0, 0), 8, 0x30, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xFF5, 8, arg0->position, 0x62);
            func_800DA544(0x9F0);
            break;
        case 3:
            arg0->unk79_4 = 0;
            func_800FC63C(0x17, 0x6D60);
            func_800DA544(0);
            ((UfoIntData *)arg0->actorData)->unk10[0] = 0.0f;
            ((UfoIntData *)arg0->actorData)->unk10[1] = -0.33333334f;
            if (func_800DA298(0x9EF) == 0) {
                _susubgame_entrypoint_6(arg0, func_80100094(arg0, 0), 4, 0x30, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xFF4, 8, arg0->position, 0x62);
            }
            arg0->unk58 = 3.0f;
            break;
    }
    arg0->unk70_10 = arg1;
}

void func_808001A0_chlagoonufoint(Actor *arg0) {
    typedef struct {
        f32 unk0[3];
        f32 unkC;
        f32 unk10[3];
    } UfoIntData;
    s32 _glcutDll_entrypoint_20();
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 _susubgame_entrypoint_11(s32);
    s32 func_800DA298(s32);
    void func_800EFD24(f32 *);
    void *func_80100094(Actor *, u32);
    void func_8080000C_chlagoonufoint(Actor *, s32);
    UfoIntData *data = (UfoIntData *)arg0->actorData;

    data->unkC = 0.0f;
    func_800EFD24(data->unk10);
    if (func_800DA298(0x9F0) || _glcutDll_entrypoint_20()) {
        arg0->unk79_4 = 4;
        data->unkC = 1.0f;
    } else {
        func_8080000C_chlagoonufoint(arg0, 1);
    }
    _susubgame_entrypoint_0(arg0, func_80100094(arg0, 0), 0);
    _susubgame_entrypoint_11(0);
}

void func_80800240_chlagoonufoint(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void* func_80100094(Actor*, u32);
    if (_susubgame_entrypoint_2(arg0, func_80100094(arg0, 0U)) != 0) {
        _susubgame_entrypoint_4(arg0, func_80100094(arg0, 0U));
    }
    _susubgame_entrypoint_11(0);
}

void func_80800294_chlagoonufoint(Actor *arg0) {
    typedef struct {
        f32 unk0[3];
        f32 unkC;
        f32 unk10[3];
    } UfoIntData;
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_800BEA88(s32);
    void func_800C3FC0(s32, f32, s32);
    void func_800C4B70(s32);
    s32 func_800CEAD0(s32);
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern u32 D_80801990_chlagoonufoint;
#ifdef BT_NATIVE
    void chlagoonufoint_entrypoint_5(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    extern s32 _chlagoonufoint_entrypoint_5;
#endif
    f32 delta;

    delta = func_800D8FF8();
    if (((UfoIntData *)arg0->actorData)->unk10[1] != 0.0f) {
        ((UfoIntData *)arg0->actorData)->unkC += ((UfoIntData *)arg0->actorData)->unk10[1] * delta;
        if ((((UfoIntData *)arg0->actorData)->unk10[1] > 0.0f && ((UfoIntData *)arg0->actorData)->unk10[0] < ((UfoIntData *)arg0->actorData)->unkC) ||
            (((UfoIntData *)arg0->actorData)->unk10[1] < 0.0f && ((UfoIntData *)arg0->actorData)->unkC < ((UfoIntData *)arg0->actorData)->unk10[0])) {
            ((UfoIntData *)arg0->actorData)->unkC = ((UfoIntData *)arg0->actorData)->unk10[0];
            ((UfoIntData *)arg0->actorData)->unk10[1] = 0.0f;
        }
    }
    if (((UfoIntData *)arg0->actorData)->unkC != 0) {
        func_800C4B70((s32)func_800F10B4(((UfoIntData *)arg0->actorData)->unk10[0], 0.0f, 1.0f, 12000.0f, 20000.0f));
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_80801990_chlagoonufoint);
        if (((UfoIntData *)arg0->actorData)->unk10[2] <= 0) {
            func_800C3FC0(0x67A, func_800F10B4(((UfoIntData *)arg0->actorData)->unk10[0], 0.0f, 1.0f, 0.4f, 1.0f), 0x4650);
            ((UfoIntData *)arg0->actorData)->unk10[2] = func_800F10B4(((UfoIntData *)arg0->actorData)->unk10[0], 0.0f, 1.0f, 0.95f, 0.25f);
        } else {
            ((UfoIntData *)arg0->actorData)->unk10[2] -= delta;
        }
    }
    switch (arg0->unk70_10) {
        case 2:
            if (arg0->unk79_4 == 4) {
                func_8080000C_chlagoonufoint(arg0, 4);
            } else if (func_800CEAD0(0)) {
                func_8080000C_chlagoonufoint(arg0, 3);
            }
            break;
        case 3:
            arg0->unk58 -= func_800D8FF8();
            if (arg0->unk58 < 0) {
                func_8080000C_chlagoonufoint(arg0, 1);
            }
            break;
    }
    _glid_entrypoint_0(func_800BEA88(0), 0x11, &_chlagoonufoint_entrypoint_5, (s32)arg0->unk0);
}

void func_808004D8_chlagoonufoint(Unk80132ED0 *arg0, Unk80132ED0 *arg1) {
    typedef struct {
        f32 unk0[3];
        f32 unkC;
        f32 unk10[3];
    } UfoIntData;
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, Unk80132ED0 *);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8080000C_chlagoonufoint(Actor *, s32);
    Actor *actor = func_80106790(arg0);
    UfoIntData *data = (UfoIntData *)actor->actorData;

    actor->unk79_4++;
    data->unk10[0] = actor->unk79_4 / (f32)4;
    data->unk10[1] = 0.33333334f;
    if (actor->unk79_4 == 1) {
        if (func_800DA298(0x9EE) == 0) {
            _susubgame_entrypoint_6(actor, func_80100094(actor, 0), 0, 0x38, arg1);
            _subaddiedialog_entrypoint_11(actor->unk0, 0xFF3, 0, actor->position, 0x62);
        } else {
            func_8080000C_chlagoonufoint(actor, 2);
        }
    }
}

s32 func_808005D0_chlagoonufoint(Actor *volatile arg0, s32 arg1, s32 arg2) {
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void func_800DA3B8(s32, s32);
    void *func_80100094(Actor *, u32);

    Actor **actor = (Actor **)&arg0;
    s16 *data = (s16 *)&arg2;

    switch (arg1) {
        case 0xB:
            if (arg2 != 0) {
                if (arg2 == 4) {
                    func_800DA3B8(0x9EF, 1);
                }
                _susubgame_entrypoint_5(*actor, func_80100094(*actor, 0), 5, 1, 0);
                return 4;
            }
            return 3;
        case 0x2E:
            switch (data[0]) {
                case 0xFF4:
                case 0xFF5:
                    _susubgame_entrypoint_4(*actor, func_80100094(*actor, 0));
                    break;
                case 0xFF3:
                    func_800DA3B8(0x9EE, 1);
                    func_8080000C_chlagoonufoint(*actor, 2);
                    _susubgame_entrypoint_4(*actor, func_80100094(*actor, 0));
                    break;
            }
            break;
        case 0x57:
            return _susubgame_entrypoint_3(*actor, func_80100094(*actor, 0),
                                         arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        default:
            return 0;
    }
    return 1;
}

OSThread *chlagoonufoint_entrypoint_1(void)
{
    extern u8 D_808019C0_chlagoonufoint[];

    return (OSThread *) D_808019C0_chlagoonufoint;
}

OSThread *chlagoonufoint_entrypoint_2(void)
{
    extern u8 D_80801A28_chlagoonufoint[];

    return (OSThread *) D_80801A28_chlagoonufoint;
}

OSThread *chlagoonufoint_entrypoint_3(void)
{
    extern u8 D_80801A90_chlagoonufoint[];

    return (OSThread *) D_80801A90_chlagoonufoint;
}

void func_80800744_chlagoonufoint(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 func_800DA298(s32);
    extern s32 D_80801AD8_chlagoonufoint;
    extern s32 D_80801AF4_chlagoonufoint;
    s32 *var_a2;

    if (func_800DA298(0x9F0) != 0) {
        var_a2 = &D_80801AF4_chlagoonufoint;
    } else {
        var_a2 = &D_80801AD8_chlagoonufoint;
    }
    _subaddiedialog_entrypoint_7(arg0, arg0 + 4, var_a2);
}

/* extern */

s32 func_8080078C_chlagoonufoint(void) {
    s32 *_subaddiefind_entrypoint_2(s32, s32);
    return *_subaddiefind_entrypoint_2(0x1C5, 0);
}

/* extern */

void func_808007B4_chlagoonufoint(void *arg0) {
    s32 _glcutDll_entrypoint_20();
    f32 func_800DC0C0();
    s32 func_80101EE4(void *, f32);
    void func_80102424(Actor *, s32);
    (*(s32 *)((s8 *)(arg0) + (0x3C))) = func_8080078C_chlagoonufoint();
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 3);
    }
    if (((u32) ((*(s32 *)((s8 *)(arg0) + (0x6C))) << 0xB) >> 0x14) == 0x1C7) {
        func_80101EE4(arg0, func_800DC0C0());
    }
}

void func_80800820_chlagoonufoint(Actor *arg0, f32 *arg1) {
    u8 func_800C4350(s32, f32[3], s32 *);
    extern s32 D_80801B10_chlagoonufoint;
    u8 var_a3;
    Actor *actor;
    Actor **saved_actor = &arg0;
    u8 handle;

    var_a3 = arg0->unk5F;
    if (var_a3 == 0) {
        handle = func_800C4350(0, arg1, &D_80801B10_chlagoonufoint);
        actor = *saved_actor;
        actor->unk5F = handle;
        var_a3 = actor->unk5F;
    }
    func_800C4350(var_a3 & 0xFF, arg1, NULL);
}

/* extern */

void func_80800878_chlagoonufoint(s32 arg0, s32 arg1) {
    s32 func_800C4104(s32, s32, s32, s32, f32, f32);
    func_800C4104(arg1, 0x3F800000, 0x55F0, arg0 + 4, 500.0f, 1000.0f);
}

void func_808008C8_chlagoonufoint(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    s32 func_8008FB10(f32 *, f32, f32, f32);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    void func_800C8F64(s32, s32);
    void func_800C8FE0(s32, s32);
    s32 func_800DA298(s32);
    f32 func_800DC0C0(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101E4C(Actor *, f32 *);
    s32 func_80101EE4(void *, f32);
    f32 func_80101F24(Actor *);
    void func_80102424(Actor *, s32);
    extern f32 D_80801B1C_chlagoonufoint[];
    extern f32 D_80801B2C_chlagoonufoint[];
    extern f32 D_80801B38_chlagoonufoint[];
    extern u32 D_80801B44_chlagoonufoint[];
    extern f32 D_80801B50_chlagoonufoint[];
    f32 progress;
    s32 *sp50;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    func_8008FB10(arg0->position, 240.0f, 0.0f, 100.0f);
    switch (arg0->unk70_10) {
        case 1:
            func_80800744_chlagoonufoint((s32)arg0);
        case 2:
            switch (arg0->unk6C_9) {
                case 0x1C6:
                    if (func_80101E4C(arg0, D_80801B1C_chlagoonufoint)) {
                        func_80800878_chlagoonufoint((s32)arg0, 0x5C1);
                    }
                    break;
                case 0x1C7:
                    if (func_80101E4C(arg0, D_80801B2C_chlagoonufoint)) {
                        func_80800878_chlagoonufoint((s32)arg0, 0x5BF);
                    }
                    break;
                default:
                    if (func_80101E4C(arg0, D_80801B38_chlagoonufoint)) {
                        func_80800878_chlagoonufoint((s32)arg0, 0x5C0);
                    }
                    break;
            }
            if (func_800DA298(0x9F0)) {
                func_80102424(arg0, 3);
                if (arg0->unk6C_9 == 0x1C7) {
                    func_80101EE4(arg0, func_800DC0C0());
                }
            }
            break;
        case 3:
            if (arg0->unk6C_9 == 0x1C7) {
                progress = func_80101F24(arg0);
                arg0->unk79_4 = 0;
                arg0->unk6C_0 = 0;
                if (progress > 0.05f && progress < 0.120000005f) {
                    arg0->unk79_4 = 1;
                } else if (progress > 0.23f && progress < 0.3f) {
                    arg0->unk6C_0 = 1;
                } else if ((progress > 0.39f && progress < 0.45000002f) ||
                           (progress > 0.48f && progress < 0.53999996f) ||
                           (progress > 0.58000004f && progress < 0.64f)) {
                    arg0->unk79_4 = arg0->unk6C_0 = 1;
                }
                sp50 = func_80100094(arg0, 0);
                if (*sp50 == 0) {
                    *sp50 = func_800C8A98();
                    func_800C8E84(*sp50, D_80801B44_chlagoonufoint);
                    func_800C8D4C(*sp50, D_80801B50_chlagoonufoint);
                    func_800C8F64(*sp50, 1);
                }
                _subaddieskeleton_entrypoint_3(arg0->unk0, 4, sp38);
                _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp44);
                if (arg0->unk79_4 && arg0->unk6C_0) {
                    func_800EFE50(sp2C, sp44, sp38, 0.5f);
                } else if (arg0->unk79_4) {
                    func_800EE7F8(sp2C, sp44);
                } else {
                    func_800EE7F8(sp2C, sp38);
                }
                func_800C8CB8(*sp50, sp2C);
                func_800C8FE0(*sp50, (arg0->unk79_4 || arg0->unk6C_0) ? 1 : 0);
                if (arg0->unk79_4 || arg0->unk6C_0) {
                    func_80800820_chlagoonufoint(arg0, sp2C);
                }
            }
            func_80800744_chlagoonufoint((s32)arg0);
            break;
    }
}

void func_80800CD4_chlagoonufoint(Actor *arg0, void *arg1) {
    void func_800DF3E0(void);
    void func_800DF5D8(u32, u32, u32, s32);
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 color;

    func_800DF3E0();
    switch (arg0->unk6C_9) {
        case 0x1C6:
            func_800DF744(3, 1);
            func_800DF744(4, 1);
            break;
        case 0x1C7:
            func_800DF744(6, 1);
            func_800DF744(7, 1);
            func_800DF744(8, arg0->unk79_4);
            func_800DF744(9, arg0->unk6C_0);
            break;
        default:
            func_800DF744(5, 1);
            break;
    }
    if (arg0->unk3C != NULL) {
        color = (((f32 *)func_80106790(arg0->unk3C)->actorData)[3] * 0.8f + 0.2f) * 255.0f;
        func_800DF5D8(color, color, color, 255);
    }
    func_80101870(arg0, arg1);
}

s32 func_80800E00_chlagoonufoint(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor *, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    extern s32 D_80801B58_chlagoonufoint;
    s32 *data = &arg2;
    switch (arg1) {
        case 0x2E:
            func_80102424(arg0, 1);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80801B58_chlagoonufoint, arg0->scale);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chlagoonufoint_entrypoint_4(void)
{
    extern u8 D_80801B68_chlagoonufoint[];

    return (OSThread *) D_80801B68_chlagoonufoint;
}

void func_80800E80_chlagoonufoint(Actor *arg0, s32 arg1) {
    void func_808004D8_chlagoonufoint(Unk80132ED0 *, Unk80132ED0 *);

    switch (arg1) {
        case 2:
            arg0->unk6C_0 = 3;
            break;
        case 3:
            func_808004D8_chlagoonufoint(arg0->unk3C, arg0->unk0);
            ((f32 *)arg0->actorData)[5] = 0.33333334f;
            break;
        case 4:
            ((f32 *)arg0->actorData)[3] = 1.0f;
            break;
        case 5:
            ((f32 *)arg0->actorData)[5] = -0.33333334f;
            arg0->unk79_4 = 0;
            break;
    }
    arg0->unk70_10 = arg1;
}

void func_80800F48_chlagoonufoint(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    s32 func_800DA298(s32);
    void func_800EFD24(f32 *);
    void *func_80100094(Actor *, u32);
    s32 *sp24;
    s32 temp_v0;

    sp24 = func_80100094(arg0, 0);
    arg0->unk3C = func_8080078C_chlagoonufoint();
    ((f32 *)arg0->actorData)[3] = 0.0f;
    func_800EFD24((f32 *)arg0->actorData);
    temp_v0 = func_800C8A98();
    *sp24 = temp_v0;
    func_800C8CB8(temp_v0, arg0->position);
    if (func_800DA298(0x9F0) != 0 || _glcutDll_entrypoint_20() != 0) {
        func_80800E80_chlagoonufoint(arg0, 4);
    }
}

void func_80800FD4_chlagoonufoint(Actor *arg0) {
    f32 func_800D8FF8(void);
    void *func_80100094(Actor *, u32);
    int func_800F3214(void *, void *, void *, f32);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    s32 func_800DA298(s32);
    s32 func_800BEA88(s32);
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    extern u32 D_80801BB0_chlagoonufoint[];
    extern u32 D_80801BBC_chlagoonufoint[];
#ifdef BT_NATIVE
    void chlagoonufoint_entrypoint_5(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    extern s32 _chlagoonufoint_entrypoint_5;
#endif
    void _chlagoonufoint_entrypoint_6(s32, u8 *, u8 *, s32, Unk80132ED0 *);
    f32 dt;
    f32 speed;
    s32 i;
    s32 *light;
    f32 range[2];
    u32 color[3];
    s32 id;
    s32 base;

    dt = func_800D8FF8();
    speed = ((f32 *)arg0->actorData)[3] * dt;
    ((f32 *)arg0->actorData)[0] += 640.0f * speed;
    ((f32 *)arg0->actorData)[1] += 3200.0f * speed;
    ((f32 *)arg0->actorData)[2] += 2560.0f * speed;
    for (i = 0; i < 3; i++) {
        if (((f32 *)arg0->actorData)[i] > 16384.0f) {
            ((f32 *)arg0->actorData)[i] -= 16384.0f;
        }
    }
    light = func_80100094(arg0, 0);
    range[0] = ((f32 *)arg0->actorData)[3] * 350.0f + 150.0f;
    range[1] = ((f32 *)arg0->actorData)[3] * 350.0f + 250.0f;
    func_800F3214(color, D_80801BB0_chlagoonufoint, D_80801BBC_chlagoonufoint, ((f32 *)arg0->actorData)[3]);
    func_800C8D4C(*light, range);
    func_800C8E84(*light, color);
    switch (arg0->unk70_10) {
        case 2:
            if (--arg0->unk6C_0 == 0) {
                func_80800E80_chlagoonufoint(arg0, 1);
            }
            break;
        case 3:
            ((f32 *)arg0->actorData)[3] += dt * ((f32 *)arg0->actorData)[5];
            if (((f32 *)arg0->actorData)[3] > 1.0f) {
                func_80800E80_chlagoonufoint(arg0, 4);
            }
            break;
        case 4:
            if (func_800DA298(0)) {
                func_80800E80_chlagoonufoint(arg0, 5);
            }
            break;
        case 5:
            ((f32 *)arg0->actorData)[3] += dt * ((f32 *)arg0->actorData)[5];
            if (((f32 *)arg0->actorData)[3] < 0.0f) {
                func_80800E80_chlagoonufoint(arg0, 1);
            }
            break;
    }
    id = func_800BEA88(0);
    base = arg0->unk74_7 * 4 - 4;
    _glid_entrypoint_0(id, base + 1, &_chlagoonufoint_entrypoint_5, (s32)arg0->unk0);
    _glid_entrypoint_0(id, base + 2, (s32 *)_chlagoonufoint_entrypoint_6, (s32)arg0->unk0);
    _glid_entrypoint_0(id, base + 3, (s32 *)_chlagoonufoint_entrypoint_6, (s32)arg0->unk0);
    _glid_entrypoint_0(id, base + 4, (s32 *)_chlagoonufoint_entrypoint_6, (s32)arg0->unk0);
}

void func_808012A4_chlagoonufoint(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FC63C(u32, u32);
    void func_80800E80_chlagoonufoint(Actor *, s32);
    extern s16 D_80801940_chlagoonufoint[];

    if (arg0->unk70_10 == 1 && func_800DA298(0) == 0) {
        arg0->unk79_4++;
        func_800FC63C(0xE, 0x6D60);
        if (arg0->unk79_4 == D_80801940_chlagoonufoint[arg0->unk74_7 - 1]) {
            func_80800E80_chlagoonufoint(arg0, 3);
            return;
        }
        func_80800E80_chlagoonufoint(arg0, 2);
    }
}

/* extern */

s32 func_8080135C_chlagoonufoint(Actor *arg0, s32 arg1, s32 arg2) {
    void func_808012A4_chlagoonufoint();
    switch (arg1) {
    case 0x40:
        func_808012A4_chlagoonufoint(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void chlagoonufoint_entrypoint_5(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    f32 scale = *(f32 *)((u8 *)func_80106790(arg4) + 0x24) * 0.8f + 0.2f;
    u8 *end = arg1 + arg3 * 0x10;

    for (; arg1 < end; arg1 += 0x10, arg2 += 0x10) {
        arg2[12] = (u32)((f32)(u32)arg1[12] * scale);
        arg2[13] = (u32)((f32)(u32)arg1[13] * scale);
        arg2[14] = (u32)((f32)(u32)arg1[14] * scale);
    }
}

void chlagoonufoint_entrypoint_6(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor = func_80106790(arg4);
    f32 scale = *(f32 *)((u8 *)actor + 0x24) * 0.8f + 0.2f;
    s16 offset = (s16)*(f32 *)((u8 *)actor + 0x14 + ((arg0 - 1) % 4) * 4);
    u8 *end = arg1 + arg3 * 0x10;
    for (; arg1 < end; arg1 += 0x10, arg2 += 0x10) {
        arg2[12] = (u32)((f32)(u32)arg1[12] * scale);
        arg2[13] = (u32)((f32)(u32)arg1[13] * scale);
        arg2[14] = (u32)((f32)(u32)arg1[14] * scale);
        *(s16 *)(arg2 + 10) = *(s16 *)(arg1 + 10) + offset;
    }
}
