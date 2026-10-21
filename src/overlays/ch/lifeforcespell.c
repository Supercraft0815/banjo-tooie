#include "common.h"

OSThread *chlifeforcespell_entrypoint_0(void)
{
    extern u8 D_80800460_chlifeforcespell[];

    return (OSThread *) D_80800460_chlifeforcespell;
}

void func_8080000C_chlifeforcespell(Actor *arg0) {
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
    s32 _sumumbofx_entrypoint_2(void *);
    void _sumumbofx_entrypoint_25(void *, s32, s32 *);
    s32 _sumumbofx_entrypoint_24(void *, f32);
    s32 _sumumbofx_entrypoint_15(void *, f32);
    s32 _sumumbofx_entrypoint_20(void *, f32);
    void *func_80100094(Actor *, u32);
    struct SpellColor { s32 values[3]; } color;
    extern struct SpellColor D_808004A8_chlifeforcespell;
    void *data;

    color = D_808004A8_chlifeforcespell;
    _sumumbofx_entrypoint_0(arg0, 1, 0x14, _chmumbopad_entrypoint_0(0xD));
    data = func_80100094(arg0, 1U);
    _sumumbofx_entrypoint_2(data);
    _sumumbofx_entrypoint_25(data, 0x96, color.values);
    _sumumbofx_entrypoint_24(data, 0.7f);
    _sumumbofx_entrypoint_15(data, 2.0f);
    _sumumbofx_entrypoint_20(data, 3.0f);
}

void func_808000C8_chlifeforcespell(Actor *arg0) {
    void _chglowbo_entrypoint_6(void);
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    s32 _sumumbofx_entrypoint_14(s32);
    void _sumumbofx_entrypoint_16(void *, f32);
    void _sumumbofx_entrypoint_17(void *, f32);
    f32 _sumumbofx_entrypoint_21(s32);
    f32 _sumumbofx_entrypoint_22(u8 *);
    s32 _sumumbofx_entrypoint_5(void *, f32);
    void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, f32 *, s32 *);
    s32 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    void func_800EFD24(f32 *);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(s32, s32, s32);
    void func_80101FDC(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_808004B4_chlifeforcespell[];
    f32 sp44[3];
    void *sp40;
    Actor *sp3C;

    sp40 = func_80100094(arg0, 1U);
    sp3C = func_80106790(arg0->unk3C);
    func_800EFD24(sp44);
    if (func_800DA298(0x9DE)) {
        _subaddieskeleton_entrypoint_0(sp3C, arg0->unk6C_0, arg0->position);
        _sumumbofx_entrypoint_7(sp40, ((f32 *)arg0->actorData)[3], 0, 0x14, sp44, arg0->position, D_808004B4_chlifeforcespell);
        switch (arg0->unk70_10) {
            case 1:
                if (_sumumbofx_entrypoint_21(sp40) == 0.0f) {
                    func_800D9078(&arg0->unk58);
                    if (_sumumbofx_entrypoint_5(sp40, 1.85f)) {
                        _sumumbofx_entrypoint_17(sp40, ((f32 *)arg0->actorData)[4]);
                        func_80101FDC(arg0, 2);
                        arg0->unk58 = ((f32 *)arg0->actorData)[4];
                    }
                }
                break;
            case 2:
                if (func_800D9078(&arg0->unk58)) {
                    _chglowbo_entrypoint_6();
                    _sumumbofx_entrypoint_16(sp40, 1.5f);
                    func_80101FDC(arg0, 3);
                }
                break;
            case 3:
                if (_sumumbofx_entrypoint_22(sp40) < 0.05f) {
                    _sumumbofx_entrypoint_1(arg0, 1);
                    func_8010114C(arg0->unk3C, 0x4C, 0);
                    func_800FFA88(arg0->unk0);
                    func_800DA544(0x9DF);
                    func_800DA524(0x9DE);
                    return;
                }
                break;
        }
        _sumumbofx_entrypoint_14(sp40);
    }
}

/* extern */

void func_8080028C_chlifeforcespell(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 _sumumbofx_entrypoint_8(u8 *, s32);
    s32 _sumumbofx_entrypoint_9(u8 *, s32);
    _sumumbofx_entrypoint_9(func_80100094(arg0, 1U), arg1);
    _sumumbofx_entrypoint_8(func_80100094(arg0, 1U), arg1);
}

/* extern */

Unk80132ED0 *chlifeforcespell_entrypoint_1(Actor **arg0, f32 arg1[3], s32 arg2, f32 arg3, s32 arg4) {
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    Actor *actor;

    actor = func_80108528(0x45C, arg1, 0, arg0);
    ((f32 *)actor->actorData)[3] = arg2;
    actor->unk6C_0 = arg4;
    ((f32 *)actor->actorData)[4] = arg3;
    actor->unk58 = 1.85f;
    actor->unk3C = (*arg0)->unk0;
    return actor->unk0;
}

s32 chlifeforcespell_entrypoint_2(Actor *arg0, Unk80132ED0 *arg1, s32 *arg2) {
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    f32 _sumumbofx_entrypoint_22(u8 *);
    s32 func_800DA298(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    int func_800F3214(void *, void *, void *, f32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    extern f32 D_808004C0_chlifeforcespell[3];
    Actor *sp3C;
    u8 *sp38;
    s32 sp2C[3];
    Actor *temp_v0;

    temp_v0 = func_80106790(arg1);
    sp3C = temp_v0;
    sp38 = func_80100094(temp_v0, 1);
    if (func_800DA298(0x9DE) && sp38) {
        _subaddiefade_entrypoint_9(arg0, sp2C);
        if (sp3C->unk70_10 == 1) {
            func_800F3214(arg2, sp2C, D_808004C0_chlifeforcespell,
                func_800F10B4(sp3C->unk58, 0.0f, 1.85f, 1.0f, 0.0f));
            return 1;
        }
        func_800F3214(arg2, sp2C, D_808004C0_chlifeforcespell,
            _sumumbofx_entrypoint_22(sp38));
        return 1;
    }
    _subaddiefade_entrypoint_9(arg0, arg2);
    return 0;
}
