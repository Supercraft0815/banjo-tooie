#include "common.h"

OSThread *chstarspinnerctrl_entrypoint_0(void)
{
    extern u8 D_8080092C_chstarspinnerctrl[];

    return (OSThread *) D_8080092C_chstarspinnerctrl;
}

OSThread *chstarspinnerctrl_entrypoint_1(void)
{
    extern u8 D_80800974_chstarspinnerctrl[];

    return (OSThread *) D_80800974_chstarspinnerctrl;
}

void func_80800018_chstarspinnerctrl(s32 *arg0) {
    s32 _chpowerhut_entrypoint_0();
    extern s32 D_80800918_chstarspinnerctrl;
    _chpowerhut_entrypoint_0(arg0, &D_80800918_chstarspinnerctrl);
}

void func_8080003C_chstarspinnerctrl(Actor *arg0) {
    s32 _chpowerhut_entrypoint_1(Actor *, s32 *);
    s32 _chpowerhut_entrypoint_4(Actor *, f32, s32 *);
    void func_800BF744(s32, s32);
    void func_800C8F08(s32, f32 *);
    s32 func_800DA544(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    int func_800F3214(void *, void *, void *, f32);
    void *func_80100094(Actor *, u32);
    void func_808002B4_chstarspinnerctrl(s32 *);
    void func_8080069C_chstarspinnerctrl(Actor *);
    extern s32 D_80800900_chstarspinnerctrl;
    extern s32 D_8080090C_chstarspinnerctrl;
    extern s32 D_80800918_chstarspinnerctrl;
    f32 sp34[3];
    struct SpinnerData {
        u8 pad0[0xC];
        s16 state;
        u8 padE[6];
        f32 input;
        f32 value;
    } *input, *data;

    _chpowerhut_entrypoint_1(arg0, &D_80800918_chstarspinnerctrl);
    switch (arg0->unk70_10) {
    case 1:
        break;
    case 3:
        if (((struct SpinnerData *)func_80100094(arg0, 0))->state == 2) {
            func_800BF744(2, 0);
            func_800BF744(1, 1);
        }
        if (((struct SpinnerData *)func_80100094(arg0, 0))->state == 3) {
            data = func_80100094(arg0, 0);
            input = func_80100094(arg0, 0);
            data->value = func_800F10B4(input->input, 0.0f, 1.0f, 0.3f, 1.0f);
            func_800F3214(sp34, &D_80800900_chstarspinnerctrl, &D_8080090C_chstarspinnerctrl, ((struct SpinnerData *)func_80100094(arg0, 0))->value);
            func_800C8F08((s32)sp34, NULL);
            func_808002B4_chstarspinnerctrl((s32 *)arg0);
        }
        if (_chpowerhut_entrypoint_4(arg0, 10.75f, &D_80800918_chstarspinnerctrl)) {
            func_800DA544(0);
        }
        break;
    }
    func_8080069C_chstarspinnerctrl(arg0);
}

s32 func_80800184_chstarspinnerctrl(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chpowerhut_entrypoint_3(Actor *, s32, s32, s32 *);
    s32 _glcutDll_entrypoint_20();
    void func_800BF744(s32, s32);
    void func_800C8F08(s32, f32 *);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_808002B4_chstarspinnerctrl(s32 *);
    extern s32 D_80800900_chstarspinnerctrl;
    extern s32 D_80800918_chstarspinnerctrl;
    s32 active;
    struct SpinnerData {
        u8 pad[0x14];
        f32 input;
        f32 value;
    } *input, *data;

    if (arg1 == 0x95) {
        active = func_800DA298(0xEA) != 0 || _glcutDll_entrypoint_20() != 0;
        func_800BF744(2, !active);
        func_800BF744(1, active);
        data = func_80100094(arg0, 0);
        input = func_80100094(arg0, 0);
        data->value = func_800F10B4(input->input, 0.0f, 1.0f, 0.3f, 1.0f);
        if (!active) {
            func_808002B4_chstarspinnerctrl((s32 *)arg0);
            func_800C8F08((s32)&D_80800900_chstarspinnerctrl, NULL);
        } else {
            func_800DA544(0);
        }
        _chpowerhut_entrypoint_3(arg0, arg1, arg2, &D_80800918_chstarspinnerctrl);
        func_80103110(arg0, 1);
        return 1;
    }
    return _chpowerhut_entrypoint_3(arg0, arg1, arg2, &D_80800918_chstarspinnerctrl);
}

void func_808002B4_chstarspinnerctrl(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_800BEA88(s32);
    extern s32 _chstarspinnerctrl_entrypoint_2;
    _glid_entrypoint_0(func_800BEA88(0), 1, &_chstarspinnerctrl_entrypoint_2, *arg0);
}

/* extern */

void chstarspinnerctrl_entrypoint_2(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Unk80132ED0 *arg4) {
    s32 func_800F2FD0(s32, s32, f32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    struct SpinnerData {
        u8 pad[0x18];
        f32 value;
    } *data;
    f32 temp_f20;

    data = func_80100094(func_80106790(arg4), 0);
    temp_f20 = data->value;
    if (arg3 > 0) {
        do {
            func_800F2FD0(arg2 + 0xC, arg1 + 0xC, temp_f20);
            arg3 -= 1;
            arg1 += 0x10;
            arg2 += 0x10;
        } while (arg3 > 0);
    }
}

/* extern */

void func_80800374_chstarspinnerctrl(Actor *arg0) {
    void func_8010A570(Actor*);
    s32 func_800DA298(s32);
    if (func_800DA298(0x679) != 0) {
        func_8010A570(arg0);
        arg0->unk64_20 = 1;
    }
}

void func_808003B8_chstarspinnerctrl(Actor *arg0) {
    s32 func_8001210C(s32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_808009BC_chstarspinnerctrl;
    f32 sp24[3];

    if (arg0->unk64_20 && (func_8001210C(3) == 0)) {
        func_800EE7F8(sp24, arg0->position);
        func_800EF1B8(sp24, arg0->rotation[1], 40.0f);
        sp24[1] += 30.0f;
        func_800BBCB8(sp24, sp24, 0.8f, 1, &D_808009BC_chstarspinnerctrl);
    }
}

void func_8080044C_chstarspinnerctrl(Actor *arg0, s32 arg1) {
    void func_800DF744(s32, s32);
    s32 func_80101808(void *, s32 (*)(Actor *));
    s32 func_801015D0(Actor *);

    func_800DF744(1, arg0->unk64_20 ? 0 : 1);
    func_800DF744(2, arg0->unk64_20 ? 1 : 0);
    func_80101808(arg0, &func_801015D0);
}

/* extern */

s32 func_808004CC_chstarspinnerctrl(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800DA544(s32);
    void func_800FC660(u32);
    void func_8010A570(Actor *);
    void func_80800554_chstarspinnerctrl(Actor *);
    s32 result;
    if (arg1 == 0x40) {
        func_8010A570(arg0);
        arg0->unk64_20 = 1;
        func_800DA544(0x679);
        func_80800554_chstarspinnerctrl(arg0);
        func_800FC660(0xE);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x10F4, 4, arg0->position, 0x22);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

void func_80800554_chstarspinnerctrl(Actor *arg0) {
    void func_80018820(s32, f32, f32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800C4AF0(f32 *, void *);
    s32 func_800E1610(s32, f32, f32, f32 *);
    extern s32 D_80800A00_chstarspinnerctrl;
    extern s32 D_80800A50_chstarspinnerctrl;
    extern s32 D_80800A98_chstarspinnerctrl;
    extern s32 D_80800AA8_chstarspinnerctrl;
    f32 *temp_s0;

    temp_s0 = arg0->position;
    func_800BBCB8(temp_s0, NULL, 1.0f, 8, &D_80800A50_chstarspinnerctrl);
    func_800BBCB8(temp_s0, NULL, 1.0f, 0xC, &D_80800A00_chstarspinnerctrl);
    func_800C4AF0(temp_s0, &D_80800A98_chstarspinnerctrl);
    func_800C4AF0(temp_s0, &D_80800AA8_chstarspinnerctrl);
    func_800E1610(0, 10.0f, 0.9f, temp_s0);
    func_80018820(0, 2.0f, 0.25f);
}

s32 chstarspinnerctrl_entrypoint_3(s32 arg0, s32 arg1) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800C8A98();
    s32 func_800C8CB8(s32, s32);
    s32 func_800C8D4C(s32, s32 *);
    s32 func_800C8E84(s32, s32 *);
    s32 func_800C8F64(s32, s32);
    s32 func_800DA298(s32);
    extern s32 D_808008E0_chstarspinnerctrl;
    extern s32 D_808008F4_chstarspinnerctrl;
    s32 temp_v0;

    if ((func_800DA298(0xEA) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        return 0;
    }
    temp_v0 = func_800C8A98();
    func_800C8D4C(temp_v0, &D_808008E0_chstarspinnerctrl);
    func_800C8E84(temp_v0, &D_808008F4_chstarspinnerctrl);
    func_800C8CB8(temp_v0, arg1);
    func_800C8F64(temp_v0, 9);
    return temp_v0;
}

void func_8080069C_chstarspinnerctrl(Actor *arg0) {
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    void func_800F2E60(s32 *, s32 *);
    int func_800F3214(void *, void *, void *, f32);
    void *func_80100094(Actor *, u32);
    extern s32 D_808008E8_chstarspinnerctrl;
    extern s32 D_808008F4_chstarspinnerctrl;
    f32 value;
    s32 iterator;
    s32 color[3];
    Actor *actor;
    struct SpinnerData {
        u8 pad0[0xC];
        s16 state;
        u8 padE[6];
        f32 input;
        f32 value;
    };

    switch (arg0->unk70_10) {
    case 1:
    case 2:
        func_800F2E60(color, &D_808008E8_chstarspinnerctrl);
        break;
    case 3:
        value = ((struct SpinnerData *)func_80100094(arg0, 0))->input;
        func_800F3214(color, &D_808008E8_chstarspinnerctrl,
                     &D_808008F4_chstarspinnerctrl, value);
        break;
    case 4:
    case 5:
        func_800F2E60(color, &D_808008F4_chstarspinnerctrl);
        break;
    }
    actor = _subaddiefind_entrypoint_2(0x336, &iterator);
    while (actor != NULL) {
        _subaddiefade_entrypoint_11(actor, color);
        actor = _subaddiefind_entrypoint_3(0x336, &iterator);
    }
}

s32 chstarspinnerctrl_entrypoint_4(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _glcutDll_entrypoint_20();
    void func_800C8B84(s32);
    s32 func_800C8CB8(s32, s32);
    s32 func_800C8E84(s32, s32 *);
    s32 func_800DA298(s32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_808008E8_chstarspinnerctrl;
    extern s32 D_808008F4_chstarspinnerctrl;
    Actor *actor;
    s32 pad;
    s32 active;
    s32 scratch[2];

    active = func_800DA298(0xEA) != 0;
    if (!active) {
        active = _glcutDll_entrypoint_20() != 0;
    }
    if (arg0->unk3C == NULL) {
        return 0;
    }
    actor = func_80106790(arg0->unk3C);
    if (active && !arg2) {
        arg2 = chstarspinnerctrl_entrypoint_3((s32)arg0, arg1);
        if (arg2) {
            func_800C8E84(arg2, &D_808008E8_chstarspinnerctrl);
        }
    }
    if (!arg2) {
        return 0;
    }
    func_800C8CB8(arg2, arg1);
    switch (actor->unk70_10) {
    case 1:
    case 2:
        func_800C8B84(arg2);
        arg2 = 0;
        break;
    case 3:
        func_800C8E84(arg2, &D_808008F4_chstarspinnerctrl);
        break;
    case 4:
    case 5:
        func_800C8E84(arg2, &D_808008F4_chstarspinnerctrl);
        break;
    }
    return arg2;
}
