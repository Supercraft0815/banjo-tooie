#include "common.h"

/* extern */
void func_80101FDC(Actor *, u32);

void func_80800000_chswampplatform(Actor *arg0) {
    typedef struct {
        f32 position[3];
        u32 unk24;
        f32 scale[3];
        f32 unk34;
    } PlatformData;
    s32 _gccubesearch_entrypoint_10(s32, u32);
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);

    if (func_800DA298(0x160) == 0) {
        if (_gccubesearch_entrypoint_10(0x28E, arg0->pad6C_21) == 0) {
            func_80101FDC(arg0, 0);
        }
        arg0->scale = 2.0f;
    } else {
        arg0->scale = 7.0f;
    }
    func_800EE7F8(((PlatformData *)arg0->actorData)->position, arg0->position);
    func_800EFA4C(((PlatformData *)arg0->actorData)->scale, 1.0f, 1.0f, 1.0f);
    arg0->unk64_20 = 0;
    arg0->unk64_19 = 0;
    ((PlatformData *)arg0->actorData)->unk34 = 0.0f;
}

void func_808000BC_chswampplatform(Actor *arg0) {
    typedef struct {
        s32 marker;
        f32 position[3];
        u8 pad10[0x18];
        f32 scale[3];
        f32 unk34;
        f32 height;
        u8 pad3C[0x1C];
        f32 progress;
        u8 pad5C[8];
        u32 pad64:11;
        u32 sound1:1;
        u32 sound2:1;
        u32 pad65:19;
        u8 pad68[0xA];
        u16 state:6;
        u16 pad72:10;
    } Platform;
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    void _chglowbo_entrypoint_6(void);
    s16 _chmumbopad_entrypoint_0(s32);
    void _subaddieaudioquick_entrypoint_2(void *, f32 *, s32 *);
    void _sumumbofx_entrypoint_0(void *, s32, s32, s16);
    void _sumumbofx_entrypoint_1(void *, s32);
    void _sumumbofx_entrypoint_2(void *);
    void _sumumbofx_entrypoint_5(void *, f32);
    void _sumumbofx_entrypoint_14(void *);
    void _sumumbofx_entrypoint_15(void *, f32);
    void _sumumbofx_entrypoint_16(void *, f32);
    void _sumumbofx_entrypoint_17(void *, f32);
    void _sumumbofx_entrypoint_18(void *, f32);
    f32 _sumumbofx_entrypoint_21(void *);
    void _sumumbofx_entrypoint_24(void *, f32);
    void _sumumbofx_entrypoint_25(void *, s32, s32 *);
    s32 _sumumbofx_entrypoint_27(void *);
    f32 func_800138D0(f32);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    void func_800DA544(s32);
    void func_8010A800(void *, s32);
    void func_80800804_chswampplatform(void *);
    f32 mlAbsF(f32);
    extern s32 D_808009D0_chswampplatform;
    extern s32 D_808009E4_chswampplatform;
    s32 position[3];
    Platform *self = (Platform *)arg0;

    switch (self->state) {
    case 0:
        func_80103110(arg0, 0);
        break;
    case 1:
        if (func_800DA298(0x9DE)) {
            position[0] = 0;
            position[1] = 0;
            position[2] = 0;
            _sumumbofx_entrypoint_0(arg0, 1, 0x32, _chmumbopad_entrypoint_0(8));
            _sumumbofx_entrypoint_2(func_80100094(arg0, 1));
            _sumumbofx_entrypoint_25(func_80100094(arg0, 1), 0x7D, position);
            _sumumbofx_entrypoint_24(func_80100094(arg0, 1), 0.65f);
            _sumumbofx_entrypoint_15(func_80100094(arg0, 1), 3.0f);
            _capod_entrypoint_13(self->marker, 0, 0xA, 0x210);
            func_80101FDC(arg0, 2);
            func_8010A800(arg0, 2);
        }
        break;
    case 2:
        func_80800804_chswampplatform(arg0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            _sumumbofx_entrypoint_18(func_80100094(arg0, 1), 4.0f);
            func_80101FDC(arg0, 3);
        }
        break;
    case 3:
        func_80800804_chswampplatform(arg0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        _sumumbofx_entrypoint_5(func_80100094(arg0, 1), 2.0f);
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            _sumumbofx_entrypoint_17(func_80100094(arg0, 1), 4.0f);
            func_80101FDC(arg0, 4);
        }
        break;
    case 4:
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 1)) > 2.0f) {
            if (!self->sound1) {
                _subaddieaudioquick_entrypoint_2(arg0, self->position, &D_808009D0_chswampplatform);
                self->sound1 = 1;
            }
            self->progress = func_800138D0((_sumumbofx_entrypoint_21(func_80100094(arg0, 1)) - 2.0f) * 0.5f * 90.0f);
            self->height = self->progress * 5.0f * 0.5f + 2.0f;
            self->scale[2] = self->scale[1] = self->scale[0] = 2.0f * self->progress + 1.0f;
        } else {
            if (!self->sound2) {
                _subaddieaudioquick_entrypoint_2(arg0, self->position, &D_808009E4_chswampplatform);
                self->sound2 = 1;
            }
            self->progress = 1.0f - func_800138D0(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)) * 0.5f * 90.0f);
            self->height = (1.0f - self->progress) * 5.0f * 0.5f + 2.0f + 2.5f;
            self->scale[0] = mlAbsF(func_800138D0(self->progress * 1.5f * 360.0f)) * (2.0f * self->progress) + 1.0f;
            self->scale[1] = mlAbsF(func_800138D0(self->progress * 2.5f * 360.0f)) * (2.0f * self->progress) + 1.0f;
            self->scale[2] = mlAbsF(func_800138D0(self->progress * 2.0f * 360.0f)) * (2.0f * self->progress) + 1.0f;
        }
        func_80800804_chswampplatform(arg0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            _chglowbo_entrypoint_6();
            func_80101FDC(arg0, 5);
            _sumumbofx_entrypoint_16(func_80100094(arg0, 1), 3.0f);
        }
        break;
    case 5:
        func_80800804_chswampplatform(arg0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80101FDC(arg0, 6);
        }
        break;
    case 6:
        _sumumbofx_entrypoint_1(arg0, 1);
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        func_8010A800(arg0, 0);
        func_800DA544(0x160);
        func_80101FDC(arg0, 7);
        break;
    case 7:
        func_80103110(arg0, 0);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swampplatform/func_8080061C_chswampplatform.s")

/* extern */

s32 func_808007A4_chswampplatform(Actor *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0x4B) {
        if ((arg2 == 8) && (arg0->unk70_10 == 0)) {
            func_80101FDC(arg0, 1);
            func_80103110(arg0, 1);
        }
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swampplatform/func_80800804_chswampplatform.s")

OSThread *chswampplatform_entrypoint_0(void)
{
    extern u8 D_808009F8_chswampplatform[];

    return (OSThread *) D_808009F8_chswampplatform;
}
