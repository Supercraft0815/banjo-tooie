#include "common.h"

typedef struct {
    u16 flag;
    s16 pad2;
    u16 pad4;
    u16 radius;
    f32 height;
    f32 threshold;
    f32 duration;
} PowerhutConfig;

typedef struct {
    s16 timer;
    s16 pad2;
    f32 height;
    f32 pad8;
    s16 state;
    s8 active;
    s8 padF;
    f32 pad10;
    f32 progress;
} PowerhutData;

s32 chpowerhut_entrypoint_0(Actor *arg0, PowerhutConfig *arg1) {
    Prop *_gccubesearch_entrypoint_0(u32, Actor *);
    s32 _glcutDll_entrypoint_20(void);
    s32 func_800D9058(f32);
    s32 func_800DA298(s32);
    void func_800EE88C(f32 *, s16 *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    PowerhutData *data;

    data = func_80100094(arg0, 0);
    func_800EE88C((f32 *)arg0->actorData, _gccubesearch_entrypoint_0(0x154, arg0)->position);
    data->height = arg1->height;
    data->timer = func_800D9058(1.5f);
    data->state = 1;
    data->active = 0;
    data->progress = 0.0f;
    if (func_800DA298(arg1->flag) != 0 || _glcutDll_entrypoint_20() != 0) {
        func_80101FDC(arg0, 5);
        data->state = 4;
        data->progress = 1.0f;
        return 1;
    }
    return 0;
}

s32 chpowerhut_entrypoint_1(Actor *arg0, PowerhutConfig *arg1) {
    s32 func_800DA298(s32);
    s32 _glcutDll_entrypoint_20(void);
    s32 _subaddieaudioloop_entrypoint_5(s32, s32, s32, s32, s32 *);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void func_8080047C_chpowerhut(Actor *, PowerhutConfig *);
    void func_80800698_chpowerhut(Actor *, PowerhutConfig *);
    s32 func_808005F4_chpowerhut(Actor *);
    extern s32 D_80800970_chpowerhut;
    s32 active;

    active = func_800DA298(arg1->flag) != 0;
    if (!active) {
        active = _glcutDll_entrypoint_20() != 0;
    }
    _subaddieaudioloop_entrypoint_5((s32)arg0, (s32)arg0->position, active, 0x708, &D_80800970_chpowerhut);
    active = arg0->unk70_10;
    switch (active) {
        case 2:
            func_8080047C_chpowerhut(arg0, arg1);
            break;
        case 3:
            func_8080047C_chpowerhut(arg0, arg1);
            func_80800698_chpowerhut(arg0, arg1);
            break;
        case 4:
            func_8080047C_chpowerhut(arg0, arg1);
            if (func_808005F4_chpowerhut(arg0)) {
                _subaddieDll_entrypoint_4(arg0, 0);
                return 1;
            }
            break;
    }
    return 0;
}

void chpowerhut_entrypoint_2(Actor *arg0, s32 arg1) {
    s32 _sumumbofx_entrypoint_8(u8 *, s32);
    s32 func_800D674C(s32);
    s32 func_800DC128(s32, s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF744(s32, s32);
    void func_800DF830(s32);
    void *func_80100094(Actor *, u32);
    extern f32 D_80800988_chpowerhut[];
    PowerhutData *data;
    s32 visible;
    s32 next;
    s32 chosen;
    s32 i;

    data = func_80100094(arg0, 0);
    if (func_80100094(arg0, 1) != NULL) {
        _sumumbofx_entrypoint_8(func_80100094(arg0, 1), arg1);
    }
    if (data->state == 3) {
        chosen = func_800DC128(0, 4);
        for (i = 0; i < 4; i++) {
            if (chosen == i) {
                visible = 1;
            } else {
                visible = 0;
            }
            func_800DF744(i + 1, visible);
        }
        func_800DF830(2);
        func_800DE448((f32 *)arg0->actorData, D_80800988_chpowerhut, 2.5f, NULL, func_800D674C(0x742));
    }
}

s32 chpowerhut_entrypoint_3(Actor *arg0, s32 arg1, s32 arg2, u16 *arg3) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _glcutDll_entrypoint_20(void);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    void func_80800400_chpowerhut(s32);
    extern f32 D_80800950_chpowerhut[];
    extern u32 D_80800958_chpowerhut[];
    extern u32 D_80800964_chpowerhut[];
    u32 *settings;

    switch (arg1) {
    case 0xA:
        if (func_800DA298(arg3[0]) || _glcutDll_entrypoint_20()) {
            return 0;
        }
        func_80101FDC(arg0, 2);
        _subaddieDll_entrypoint_4(arg0, 1);
        func_80103110(arg0, 1);
        func_80800400_chpowerhut((s32)arg0);
        _capod_entrypoint_13(arg0->unk0, NULL, arg3[1], arg3[2]);
        break;
    case 0x95:
        ((PowerhutData *)func_80100094(arg0, 0))->active = 0;
        arg0->actorData[4] = func_800C8A98();
        func_800C8D4C(arg0->actorData[4], D_80800950_chpowerhut);
        func_800C8CB8(arg0->actorData[4], (f32 *)arg0->actorData);
        if (func_800DA298(arg3[0]) || _glcutDll_entrypoint_20()) {
            settings = D_80800964_chpowerhut;
        } else {
            settings = D_80800958_chpowerhut;
        }
        func_800C8E84(arg0->actorData[4], settings);
        func_80103110(arg0, func_800DA298(arg3[0]));
        break;
    default:
        return 0;
        break;
    }
    return 1;
}

/* extern */

void func_80800400_chpowerhut(s32 arg0) {
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _sumumbofx_entrypoint_0(s32, s32, s32, s16);
    s32 _sumumbofx_entrypoint_15(s32, s32);
    s32 _sumumbofx_entrypoint_2(s32);
    s32 _sumumbofx_entrypoint_20(s32, s32);
    s32 _sumumbofx_entrypoint_24(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 sp1C;
    s32 temp_v0;

    _sumumbofx_entrypoint_0(arg0, 1, 0x14, _chmumbopad_entrypoint_0(3));
    temp_v0 = func_80100094(arg0, 1);
    sp1C = temp_v0;
    _sumumbofx_entrypoint_2(temp_v0);
    _sumumbofx_entrypoint_24(sp1C, 0x40100000);
    _sumumbofx_entrypoint_15(sp1C, 0x40400000);
    _sumumbofx_entrypoint_20(sp1C, 0x40400000);
}

void func_8080047C_chpowerhut(Actor *arg0, PowerhutConfig *arg1) {
    void _chglowbo_entrypoint_6(void);
    s32 _sumumbofx_entrypoint_14(s32);
    void _sumumbofx_entrypoint_16(void *, f32);
    void _sumumbofx_entrypoint_17(void *, f32);
    f32 _sumumbofx_entrypoint_21(s32);
    s32 _sumumbofx_entrypoint_5(s32, s32);
    void _sumumbofx_entrypoint_6(s32, f32, f32, s32, s32, u8 *, s32, s32);
    s32 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    void func_800EFD24(f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    extern u8 D_80800994_chpowerhut[];
    f32 sp34[3];
    void *sp30;
    PowerhutData *sp2C;

    sp30 = func_80100094(arg0, 1);
    sp2C = func_80100094(arg0, 0);
    func_800EFD24(sp34);
    if (func_800DA298(0x9DE)) {
        _sumumbofx_entrypoint_6(sp30, 500.0f, (f32)(u32)arg1->radius, 0, 0x14, sp34, arg0->position, D_80800994_chpowerhut);
        switch (arg0->unk70_10) {
        case 2:
            if (_sumumbofx_entrypoint_21(sp30) == 0.0f && _sumumbofx_entrypoint_5(sp30, 0x3FECCCCD)) {
                _sumumbofx_entrypoint_17(sp30, arg1->height);
                func_80101FDC(arg0, 3);
            }
            break;
        case 3:
            sp2C->pad8 = arg1->height - sp2C->height;
            if (func_800D9078(&sp2C->height)) {
                _chglowbo_entrypoint_6();
                _sumumbofx_entrypoint_16(sp30, 1.5f);
                func_80101FDC(arg0, 4);
            }
            break;
        }
        _sumumbofx_entrypoint_14(sp30);
    }
}

s32 func_808005F4_chpowerhut(Actor *arg0) {
    s32 _sumumbofx_entrypoint_1(void *, s32);
    f32 _sumumbofx_entrypoint_22(u8 *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_800DA524(s32);
    void func_800DA544(s32);
    u16 *data;
    s32 result = 0;

    if (_sumumbofx_entrypoint_22(func_80100094(arg0, 1)) < 0.05f) {
        data = func_80100094(arg0, 0);
        if (*data != 0) {
            *data -= 1;
            return 0;
        }
        _sumumbofx_entrypoint_1(arg0, 1);
        func_80101FDC(arg0, 5);
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        result = 1;
        return result;
    }
    return result;
}

void func_80800698_chpowerhut(Actor *arg0, PowerhutConfig *arg1) {
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void func_80018820(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    s32 func_800D9078(f32 *);
    void func_800DA544(s32);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    s32 func_800E15CC(s32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, s32);
    void func_80800870_chpowerhut(s32);
    extern u32 D_80800964_chpowerhut[];
    extern s32 D_808009A0_chpowerhut[];
    extern s32 D_808009B4_chpowerhut[];
    PowerhutData *data;
    s32 done;

    data = func_80100094(arg0, 0);
    data->active = _subaddieaudioloop_entrypoint_7(data->active, (f32 *)arg0->actorData, data->state == 3, D_808009A0_chpowerhut, arg0->unk70_0);
    switch (data->state) {
    case 1:
        if (arg1->threshold < arg1->height - data->height) {
            data->state = 2;
        }
        break;
    case 2:
        _subaddieaudioquick_entrypoint_2(arg0, (f32 *)arg0->actorData, D_808009B4_chpowerhut);
        data->state = 3;
        data->pad10 = arg1->duration;
        func_800C8E84(arg0->actorData[4], D_80800964_chpowerhut);
        func_80018820(0, 2.0f, 1.0f);
        func_800E15CC(0, 20.0f, 0.9f);
        func_800DA544(arg1->flag);
        func_80101180(0x33D, 10, 0);
        break;
    case 3:
        done = func_800D9078(&data->pad10);
        data->progress = 1.0f;
        if (func_800DC298(0.8f) && data->pad10 > 0.15f) {
            data->progress *= func_800DC178(0.25f, 0.5f);
        }
        if (done) {
            data->state = 4;
            data->progress = 1.0f;
        }
        func_80800870_chpowerhut((s32)arg0);
        break;
    }
}

void func_80800870_chpowerhut(s32 arg0) {
    s32 func_8001210C(s32);
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808009C0_chpowerhut;
    s32 temp_a0;

    if (func_8001210C(3) == 0) {
        temp_a0 = arg0 + 0x18;
        func_800BBCB8(temp_a0, temp_a0, 0x3F800000, 2, &D_808009C0_chpowerhut);
    }
}

/* extern */

int chpowerhut_entrypoint_4(Actor *arg0, f32 arg1, Actor *arg2) {
    void *func_80100094(Actor *, u32);
    PowerhutData *temp_v0;
    f32 upper;

    temp_v0 = func_80100094(arg0, 0);
    upper = arg2->position[1] - temp_v0->height;
    return (arg1 < upper) && (temp_v0->pad8 <= arg1);
}
