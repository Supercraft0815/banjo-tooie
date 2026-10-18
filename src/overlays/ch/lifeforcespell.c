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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lifeforcespell/func_808000C8_chlifeforcespell.s")

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
