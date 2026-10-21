#include "common.h"

OSThread *chfloater_entrypoint_0(void)
{
    extern u8 D_808002A0_chfloater[];

    return (OSThread *) D_808002A0_chfloater;
}

/* extern */

void func_8080000C_chfloater(Actor *arg0) {
    s32 _mlwave_entrypoint_1(u8 *);
    f32 _mlwave_entrypoint_5(u8 *, f32, f32);
    f32 func_800136E4(f32);
    void *func_80100094(Actor *, u32);
    void *sp2C = func_80100094(arg0, 0);
    u8 *wave[3];

    _mlwave_entrypoint_1(sp2C);
    wave[1] = (u8 *)sp2C + 0x1C;
    _mlwave_entrypoint_1(wave[1]);
    wave[0] = (u8 *)sp2C + 0x38;
    _mlwave_entrypoint_1(wave[0]);
    arg0->rotation[2] = func_800136E4(*(f32 *)&arg0->actorData[4] + _mlwave_entrypoint_5(wave[1], -7.5f, 7.5f));
    arg0->rotation[0] = func_800136E4(*(f32 *)&arg0->actorData[5] + _mlwave_entrypoint_5(sp2C, -3.0f, 3.0f));
    arg0->position[1] = *(f32 *)&arg0->actorData[6] + _mlwave_entrypoint_5(wave[0], -20.0f, 20.0f);
}

void func_808000C0_chfloater(Actor *arg0) {
    s32 _gccubesearch_entrypoint_16(s32 *, s32 *, s16 **, s32, s32);
    s32 _gsproplookup_entrypoint_0();
    void _mlwave_entrypoint_0(void *, f32, f32);
    void _mlwave_entrypoint_2(void *, f32, f32);
    f32 func_800136E4(f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EE904(s32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102FDC(Actor *, f32);
    s32 func_80103140(Actor *, u32, u16);
    s32 func_80104E78(Actor *);
    void func_8010A800(Actor *, s32);
    struct FloaterProp {
        u16 id;
        u8 yaw;
        u8 pitch;
        s16 position[3];
        u8 scale;
        u8 pad : 2;
        u8 enabled : 1;
        u8 hidden : 1;
        u8 rest : 4;
    };
    void *sp4C;
    s32 sp48;
    s16 *sp44;
    s32 sp38[3];
    struct FloaterProp *prop;

    sp4C = func_80100094(arg0, 0);
    func_800EE904(sp38, arg0->position);
    if (_gccubesearch_entrypoint_16(sp38, &sp48, &sp44, 2, 500)) {
        prop = (struct FloaterProp *)sp44;
        prop->enabled = 1;
        prop->hidden = 0;
        func_800EE88C(arg0->position, prop->position);
        arg0->rotation[1] = func_800136E4(2.0f * (u32)prop->yaw);
        arg0->rotation[0] = func_800136E4(2.0f * (u32)prop->pitch);
        *(f32 *)&arg0->actorData[5] = arg0->rotation[0];
        *(f32 *)&arg0->actorData[4] = 0.0f;
        *(f32 *)&arg0->actorData[6] = arg0->position[1];
        func_80102FDC(arg0, (u32)prop->scale * 0.01f);
        func_80103140(arg0, _gsproplookup_entrypoint_0(prop) & 0xFFFF, 0);
        _mlwave_entrypoint_0(sp4C, 100.0f, 30.0f);
        _mlwave_entrypoint_0((u8 *)sp4C + 0x1C, 100.0f, 20.0f);
        _mlwave_entrypoint_0((u8 *)sp4C + 0x38, 100.0f, 20.0f);
        _mlwave_entrypoint_2(sp4C, 0.0f, 5.0f);
        _mlwave_entrypoint_2((u8 *)sp4C + 0x1C, 5.0f, 10.0f);
        _mlwave_entrypoint_2((u8 *)sp4C + 0x38, 3.0f, 7.0f);
        func_8010A800(arg0, 2);
        func_80104E78(arg0);
    }
}
