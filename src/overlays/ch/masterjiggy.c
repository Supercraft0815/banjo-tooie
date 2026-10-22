#include "common.h"

OSThread *chmasterjiggy_entrypoint_0(void)
{
    extern u8 D_8080164C_chmasterjiggy[];

    return (OSThread *) D_8080164C_chmasterjiggy;
}

void func_8080000C_chmasterjiggy(Actor *arg0) {
    Prop *_gccubesearch_entrypoint_0(u32, Actor *);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _glcutDll_entrypoint_20();
    s32 _sujiggy_entrypoint_13();
    s32 _sujiggy_entrypoint_14();
    s32 _sujiggy_entrypoint_17();
    s32 func_800A9C98(void);
    s32 func_800DA298(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_808001D0_chmasterjiggy(Unk80132ED0 **, s32);
    s32 func_80800220_chmasterjiggy(s32, s32);
    Prop *prop;

    prop = _gccubesearch_entrypoint_0(3, arg0);
    if (prop != NULL) {
        _gspropctrl_entrypoint_11(prop, (f32 *)((u8 *)arg0 + 0x18));
    } else {
        func_800EFA4C((f32 *)((u8 *)arg0 + 0x18), 1650.0f, 200.0f, 0.0f);
    }
    prop = _gccubesearch_entrypoint_0(4, arg0);
    if (prop != NULL) {
        _gspropctrl_entrypoint_11(prop, (f32 *)((u8 *)arg0 + 0x28));
    } else {
        func_800EFA4C((f32 *)((u8 *)arg0 + 0x28), 0.0f, 150.0f, 0.0f);
    }
    if (_glcutDll_entrypoint_20() || func_800A9C98()) {
        func_80800220_chmasterjiggy((s32)arg0, 9);
    } else if (_sujiggy_entrypoint_13()) {
        switch (_sujiggy_entrypoint_14()) {
        case 0:
            func_808001D0_chmasterjiggy((Unk80132ED0 **)arg0, 3);
            break;
        case 1:
            func_80800220_chmasterjiggy((s32)arg0, 5);
            break;
        case 2:
            func_808001D0_chmasterjiggy((Unk80132ED0 **)arg0, 9);
            break;
        case 3:
            func_80800220_chmasterjiggy((s32)arg0, 1);
            break;
        }
    } else if (!func_800DA298(0x35B)) {
        func_80800220_chmasterjiggy((s32)arg0, 2);
    } else if (!_sujiggy_entrypoint_17()) {
        func_80800220_chmasterjiggy((s32)arg0, 8);
    }
    func_800FE734(0);
}

void func_808001A8_chmasterjiggy(s32 arg0) 
{
}
/* extern */

void func_808001B0_chmasterjiggy(s32 arg0) {
    s32 _sujiggy_entrypoint_8();
    _sujiggy_entrypoint_8();
}

s32 func_808001D0_chmasterjiggy(Unk80132ED0 **arg0, s32 arg1) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    extern s16 D_80801620_chmasterjiggy[];
    s16 *entry = (s16 *)((s8 *)D_80801620_chmasterjiggy + arg1 * 4);
    return _subaddiedialog_entrypoint_11(*arg0, entry[0], entry[1], (f32 *)((s8 *)arg0 + 4), 0x97);
}

s32 func_80800220_chmasterjiggy(s32 arg0, s32 arg1) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    void func_8008F8B0(void);
    void func_8008F8D8(s32);
    void func_8008F904(void *, Unk80132ED0 *);
    void func_8008F938(s32);
    void func_8008F990(f32 *, f32);
    void func_8008F9F8(f32 *, f32);
    void func_80090658(s32);
    void func_80090734(s32, f32 *);
    s32 *func_800BEC10(void);
    void func_800C0658(void);
    void func_800DBEFC(s32 *, s32, f32 *);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_80108A30(s32, void *, f32, s32);
    extern s32 B_808017F0_chmasterjiggy;
    extern s32 func_8010D5DC;
    f32 sp24[3];

    func_80102424((Actor *)arg0, arg1);
    switch (arg1) {
    case 2:
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F904(&func_8010D5DC, ((Actor *)arg0)->unk0);
        func_8008F938(1);
        func_8008F990((f32 *)&((Actor *)arg0)->actorData[4], 500.0f);
        _capod_entrypoint_13(((Actor *)arg0)->unk0, 0, 0x11, 0x60);
        break;
    case 3:
        func_800C0658();
        func_8008F8B0();
        func_8008F904(&func_8010D5DC, ((Actor *)arg0)->unk0);
        func_8008F9F8((f32 *)((Actor *)arg0)->actorData, 300.0f);
        func_8008F938(0);
        func_80090658(1);
        break;
    case 4:
        func_800DBEFC(func_800BEC10(), 4, sp24);
        func_80090734(4, sp24);
        ((Actor *)arg0)->unk58 = 1.0f;
        break;
    case 5:
        func_80108A30(0x4B1, &B_808017F0_chmasterjiggy, 0.0f, 0x32);
        ((f32 *)((Actor *)arg0)->actorData)[7] = 1.0f;
        break;
    case 9:
        func_80101EE4((Actor *)arg0, 0.8f);
        break;
    }
}

/* extern */

int func_80800374_chmasterjiggy(s32 arg0) {
    s32 func_8008FD48();
    void func_8008FE68(f32 *);
    f32 sp1C[3];

    func_8008FE68(sp1C);
    return sp1C[0] >= 1576.0f && func_8008FD48() == 1;
}

int func_808003D4_chmasterjiggy(s32 arg0) {
    s32 func_80016B30(s32, s32);
    s32 func_80090080();
    return func_80090080() && (func_80016B30(0, 1) == 1);
}

/* extern */

void func_80800414_chmasterjiggy(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_808001D0_chmasterjiggy(Unk80132ED0 **, s32);
    s32 func_80800220_chmasterjiggy(s32, s32);
    int func_80800374_chmasterjiggy();
    int func_808003D4_chmasterjiggy(s32);
    if (func_80800374_chmasterjiggy() != 0) {
        if ((func_800DA298(0x533) == 0) && (func_808001D0_chmasterjiggy(arg0, 3) != 0)) {
            func_800DA544(0x533);
        }
        if (func_808003D4_chmasterjiggy(arg0) != 0) {
            func_80800220_chmasterjiggy(arg0, 3);
        }
    }
}

/* extern */

void func_8080047C_chmasterjiggy(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _sujiggy_entrypoint_0();
    s32 _sujiggy_entrypoint_2(s32);
    s32 func_800C0638();
    s32 func_800D035C(s32);
    s32 func_800D2498(s32, s32, s32);
    s32 func_800DA298(s32);
    if ((func_800C0638() == 0) && (func_800DA298(0xD4E) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800D2498(0x10E, func_800D035C(1), 0);
        func_800D2498(0x106, _sujiggy_entrypoint_2(_sujiggy_entrypoint_0()), 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_808004FC_chmasterjiggy.s")

/* extern */

void func_80800704_chmasterjiggy(s32 *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    void _capod_entrypoint_14(void);
    _capod_entrypoint_14();
    _capod_entrypoint_13(*arg0, 0, arg2, 0x2030);
}

void func_80800744_chmasterjiggy(s32 arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_14(void);
    s32 func_800DA544(s32);
    s32 func_80800220_chmasterjiggy(s32, s32);

    switch (arg1) {
    case 0x14F6:
        _capod_entrypoint_14();
        func_800DA544(0x35B);
        func_80800220_chmasterjiggy(arg0, 1);
        return;
    case 0x14FC:
    case 0x155B:
    case 0x155C:
    case 0x155D:
    case 0x155E:
        func_80800220_chmasterjiggy(arg0, 1);
        return;
    case 0x1511:
        func_80800220_chmasterjiggy(arg0, 8);
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_808007F0_chmasterjiggy.s")

OSThread *chmasterjiggy_entrypoint_1(void)
{
    extern u8 D_808016F8_chmasterjiggy[];

    return (OSThread *) D_808016F8_chmasterjiggy;
}

void func_8080095C_chmasterjiggy(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x38))) = 1.0f;
}

void func_8080096C_chmasterjiggy(Actor *arg0) {
    typedef struct {
        f32 amount;
        s32 pad4[2];
        u8 sound;
    } MasterJiggyData;
    void _subaddieaudioloop_entrypoint_1(u8 *, s32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    f32 func_800F1214(f32, f32, f32);
    extern u32 D_80801740_chmasterjiggy;
    extern s32 D_80801750_chmasterjiggy;
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position,
        arg0->unk64_20 && ((MasterJiggyData *)arg0->actorData)->amount > 0.0f, &D_80801740_chmasterjiggy);
    _subaddieaudioloop_entrypoint_1((u8 *)arg0,
        (s32)func_800F1214(((MasterJiggyData *)arg0->actorData)->amount, 5000.0f, 13000.0f));
    ((MasterJiggyData *)arg0->actorData)->sound = _subaddieaudioloop_entrypoint_7(((MasterJiggyData *)arg0->actorData)->sound, arg0->position,
        ((MasterJiggyData *)arg0->actorData)->amount > 0.0f, &D_80801750_chmasterjiggy, 0);
}

void func_80800A40_chmasterjiggy(Actor *arg0) {
    typedef struct {
        f32 amount;
        f32 fade;
        f32 progress;
        u32 sound;
        f32 speed;
        s32 pad14[2];
        f32 timer;
    } MasterJiggyData;
    void _capod_entrypoint_14(void);
    s32 _sujiggy_entrypoint_0();
    void _sujiggy_entrypoint_15(s32, s32);
    void func_80018820(s32, f32, f32);
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    f32 func_800F3780(f32, u8 *, s16);
    void func_80800E58_chmasterjiggy(Actor *, s32);
    void func_808010E4_chmasterjiggy(Actor *);
    void func_80801448_chmasterjiggy(s32 *);
    void func_80801488_chmasterjiggy(Actor *);
    extern f32 D_808016B0_chmasterjiggy[][2];
    extern f32 D_808016E8_chmasterjiggy[][2];
    extern f32 D_80801760_chmasterjiggy[][2];
    extern f32 D_80801770_chmasterjiggy[][2];
    f32 delta;
    s32 finished;

    delta = func_800D8FF8();
    finished = 0;
    if (((MasterJiggyData *)arg0->actorData)->progress < 1.0f) {
        ((MasterJiggyData *)arg0->actorData)->progress += delta * ((MasterJiggyData *)arg0->actorData)->speed;
        if (((MasterJiggyData *)arg0->actorData)->progress >= 1.0f) {
            ((MasterJiggyData *)arg0->actorData)->progress = 1.0f;
            finished = 1;
        }
    }
    func_808010E4_chmasterjiggy(arg0);
    func_80801448_chmasterjiggy((s32 *)arg0);
    func_80801488_chmasterjiggy(arg0);
    func_8080096C_chmasterjiggy(arg0);
    switch (arg0->unk70_10) {
    case 2:
        if (func_800D90A4(&((MasterJiggyData *)arg0->actorData)->timer)) {
            func_80800E58_chmasterjiggy(arg0, 3);
        }
        break;
    case 3:
        ((MasterJiggyData *)arg0->actorData)->amount = func_800F3780(((MasterJiggyData *)arg0->actorData)->progress, (u8 *)D_808016B0_chmasterjiggy, 7);
        if (finished) {
            func_80800E58_chmasterjiggy(arg0, 4);
        }
        break;
    case 4:
        ((MasterJiggyData *)arg0->actorData)->amount = func_800F3780(((MasterJiggyData *)arg0->actorData)->progress, (u8 *)D_80801760_chmasterjiggy, 2);
        func_80018820(0, 0.75f, 0.5f);
        if (finished) {
            func_808001D0_chmasterjiggy(&arg0->unk0, 6);
        }
        break;
    case 5:
        ((MasterJiggyData *)arg0->actorData)->fade = func_800F3780(((MasterJiggyData *)arg0->actorData)->progress, (u8 *)D_80801770_chmasterjiggy, 4);
        if (finished) {
            _capod_entrypoint_14();
            _sujiggy_entrypoint_15(_sujiggy_entrypoint_0() - 1, 1);
        }
        break;
    case 6:
        ((MasterJiggyData *)arg0->actorData)->fade = func_800F3780(((MasterJiggyData *)arg0->actorData)->progress, (u8 *)D_808016E8_chmasterjiggy, 2);
        ((MasterJiggyData *)arg0->actorData)->amount = ((MasterJiggyData *)arg0->actorData)->fade;
        break;
    }
}

void func_80800C08_chmasterjiggy(Actor *arg0, void *arg1) {
    typedef struct {
        f32 amount;
        f32 fade;
    } MasterJiggyData;
    void _sufade_entrypoint_0(s32, void *);
    void func_800E3980(f32 *);
    void func_800E3A58(f32 *);
    f32 func_800F1DCC(f32, f32);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void func_80101870(Actor *, void *);
    f32 mlAbsF(f32);
    extern s32 D_80801790_chmasterjiggy;
    f32 rotation[3];
    f32 yaw;
    f32 position[3];
    f32 fade;
    f32 difference;

    func_800E3A58(rotation);
    arg0->rotation[1] = rotation[1];
    arg0->alpha = (u32)(((MasterJiggyData *)arg0->actorData)->amount * 255.0f);
    if (arg0->unk64_20) {
        func_80101870(arg0, arg1);
    }
    fade = ((MasterJiggyData *)arg0->actorData)->fade;
    if (fade > 0.0f) {
        _sufade_entrypoint_0((s32)(fade * 255.0f), &D_80801790_chmasterjiggy);
    }
    if (((MasterJiggyData *)arg0->actorData)->amount > 0.0f && arg0->unk64_20) {
        func_800E3980(position);
        if (func_800F1E6C(arg0->position, position, &yaw)) {
            difference = mlAbsF(func_800F1DCC(yaw, rotation[1])) / 25.0f;
            if (difference < 1.0f) {
                _sufade_entrypoint_0((s32)(((MasterJiggyData *)arg0->actorData)->amount * ((1.0f - difference) * 100.0f)), &D_80801790_chmasterjiggy);
            }
        }
    }
}

/* extern */

void func_80800DDC_chmasterjiggy(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void func_800B5450(void *);
    s32 func_800E1720(s32);
    void *temp_a2;
    s32 temp_v0;
    u8 temp_a0;

    temp_a2 = (*(void **)((s8 *)(arg0) + (0x2C)));
    if (temp_a2 != NULL) {
        func_800B5450(temp_a2);
        (*(void **)((s8 *)(arg0) + (0x2C))) = NULL;
    }
    temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x30)));
    if (temp_v0 != 0) {
        func_800E1720(temp_v0 - 1);
        (*(s32 *)((s8 *)(arg0) + (0x30))) = 0;
    }
    temp_a0 = (*(u8 *)((s8 *)(arg0) + (0x24)));
    if (temp_a0 != 0) {
        (*(u8 *)((s8 *)(arg0) + (0x24))) = _subaddieaudioloop_entrypoint_3(temp_a0);
    }
    arg0->unk54 = 0.0f;
}

void func_80800E58_chmasterjiggy(Actor *arg0, s32 arg1) {
    typedef struct {
        f32 amount;
        f32 fade;
        f32 progress;
        u32 sound;
        f32 rate;
        u32 emitter;
        u32 handle;
        f32 timer;
    } MasterJiggyData;
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    void func_800189A8(s32, f32[][2], s16, f32, f32);
    void func_800FC660(u32);
    void func_800FC74C(u32);
    void func_800FCAE0(u32, u32, u32);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, s32);
    void func_80101FDC(Actor *, u32);
    extern f32 D_80801690_chmasterjiggy[];
    extern f32 D_808016B0_chmasterjiggy[][2];
    extern f32 D_808016E8_chmasterjiggy[][2];
    f32 duration;

    func_80101FDC(arg0, arg1);
    ((MasterJiggyData *)arg0->actorData)->progress = 0.0f;
    if (arg1 > 0) {
        duration = D_80801690_chmasterjiggy[arg1];
        if (duration > 0.0f) {
            ((MasterJiggyData *)arg0->actorData)->rate = 1.0f / duration;
        } else {
            ((MasterJiggyData *)arg0->actorData)->rate = 0.0f;
        }
    }
    switch (arg1) {
        case 2:
            _capod_entrypoint_13(arg0->unk0, NULL, 9, 0x6030);
            arg0->unk64_20 = 0;
            ((MasterJiggyData *)arg0->actorData)->timer = 7.5f;
            break;
        case 3:
            arg0->unk64_20 = 0;
            func_800189A8(0, D_808016B0_chmasterjiggy, 7, duration, 2.0f);
            arg0->unk54 = 0.0f;
            break;
        case 4:
            arg0->unk64_20 = 1;
            func_800FC660(0x1C);
            break;
        case 5:
            arg0->unk64_20 = 1;
            break;
        case 6:
            _capod_entrypoint_13(arg0->unk0, NULL, 0x17, 0x2030);
            arg0->unk64_20 = 1;
            func_800189A8(0, D_808016E8_chmasterjiggy, 2, duration, 2.0f);
            func_800FCAE0(0x1C, 0, 0x1BC);
            break;
        case 7:
            arg0->unk64_20 = 0;
            func_80101180(0x1E1, 0x31, 0);
            func_800FFAB0(arg0);
            _subaddieaudioloop_entrypoint_2(arg0);
            func_800FC74C(0x1C);
            break;
    }
}

s32 func_80801030_chmasterjiggy(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_14(void);
    void func_80800E58_chmasterjiggy(Actor *, s32);

    switch (arg1) {
        case 0x95:
            if (arg0->unk70_10 == 1) {
                func_80800E58_chmasterjiggy(arg0, 2);
            } else {
                func_80800E58_chmasterjiggy(arg0, 6);
            }
            break;
        case 0x2E:
            func_80800E58_chmasterjiggy(arg0, 5);
            break;
        case 0xB:
            if (arg2 == 0x17) {
                _capod_entrypoint_14();
                func_80800E58_chmasterjiggy(arg0, 7);
                return 4;
            }
            return 3;
        default:
            return 0;
    }
    return 1;
}

void func_808010E4_chmasterjiggy(Actor *arg0) {
    typedef struct {
        f32 amount;
        s32 unused[4];
        s32 emitter;
    } MasterJiggyData;
    s32 func_800B53A4(s32);
    void func_800B5534(s8 *);
    void func_800BA22C(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE780(f32 *, f32 *, f32 *);
    extern s32 D_8080179C_chmasterjiggy[];
    extern f32 D_808017E0_chmasterjiggy[3];
    f32 sp2C[3];
    if ((((MasterJiggyData *)arg0->actorData)->amount > 0.0f) && arg0->unk64_20) {
        if (((MasterJiggyData *)arg0->actorData)->emitter == 0) {
            func_800EE780(sp2C, arg0->position, D_808017E0_chmasterjiggy);
            ((MasterJiggyData *)arg0->actorData)->emitter = func_800B53A4(0x32);
            func_800B5534(((MasterJiggyData *)arg0->actorData)->emitter);
            ((MasterJiggyData *)arg0->actorData)->emitter = func_800BABB8(((MasterJiggyData *)arg0->actorData)->emitter, arg0->position, sp2C, 1.0f, D_8080179C_chmasterjiggy);
        }
        func_800BA22C(((MasterJiggyData *)arg0->actorData)->emitter, 4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/chmasterjiggy_entrypoint_2.s")

void func_80801448_chmasterjiggy(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_800BEA88(s32);
    extern s32 _chmasterjiggy_entrypoint_2;
    _glid_entrypoint_0(func_800BEA88(0), 1, &_chmasterjiggy_entrypoint_2, *arg0);
}

/* extern */

void func_80801488_chmasterjiggy(Actor *arg0) {
    typedef struct {
        f32 amount;
        s32 unused[5];
        s32 handle;
    } MasterJiggyData;
    void func_800E13F0(s32, f32);
    s32 func_800E15CC(s32, f32, f32);
    s32 func_800E1720(s32);
    f32 var_f0;
    s32 var_v1;

    var_f0 = ((MasterJiggyData *)arg0->actorData)->amount;
    if (var_f0 > 0.0f) {
        var_v1 = ((MasterJiggyData *)arg0->actorData)->handle;
        if (var_v1 == 0) {
            var_v1 = func_800E15CC(0, 0.0f, 1.0f) + 1;
            ((MasterJiggyData *)arg0->actorData)->handle = var_v1;
            var_f0 = ((MasterJiggyData *)arg0->actorData)->amount;
        }
        func_800E13F0(var_v1 - 1, var_f0 * 10.0f);
        return;
    }
    var_v1 = ((MasterJiggyData *)arg0->actorData)->handle;
    if (var_v1 != 0) {
        func_800E1720(var_v1 - 1);
        ((MasterJiggyData *)arg0->actorData)->handle = 0;
    }
}
