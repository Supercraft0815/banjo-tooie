#include "common.h"

typedef struct {
    u16 flag;
    s16 pad2;
    f32 pad4;
    f32 height;
} PowerhutConfig;

typedef struct {
    s16 timer;
    s16 pad2;
    f32 height;
    s32 pad8;
    s16 state;
    s8 active;
    s8 padF;
    s32 pad10;
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/chpowerhut_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/chpowerhut_entrypoint_3.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/func_8080047C_chpowerhut.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/func_80800698_chpowerhut.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/chpowerhut_entrypoint_4.s")
