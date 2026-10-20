#include "common.h"

void func_80800000_chworlddoors(u8 *arg0) {
    void func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    extern s32 D_80800990_chworlddoors;
    f32 *sp20;
    f32 sp24[2];

    sp20 = (f32 *)(arg0 + 0x28);
    func_800EE7F8(sp24, sp20);
    func_800EF214(sp24, *(f32 *)(arg0 + 0x44), *(f32 *)(arg0 + 0x48), -50.0f);
    func_800BBCB8(sp20, sp24, 1.0f, 6, &D_80800990_chworlddoors);
}

s32 func_80800068_chworlddoors(Actor *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _gspropctrl_entrypoint_12(Prop *);
    s32 _gspropctrl_entrypoint_13(Prop *);
    s32 _gspropctrl_entrypoint_8(Prop *);
    s32 _sujiggy_entrypoint_22(u32);
    void func_800EEBF0(f32 *, f32 *, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    Prop *props[2];
    f32 angles[2];
    s32 result;
    s32 count;
    s32 i;
    s32 world;
    Prop **prop;

    world = _sujiggy_entrypoint_22(arg0->unk79_4);
    count = _gccubesearch_entrypoint_9(0x4DC, props, 2);
    i = 0;
    if (count > 0) {
        prop = props;
        do {
        if (_gspropctrl_entrypoint_8(*prop) == world + 0x32) {
            _gspropctrl_entrypoint_11(*prop, (f32 *)&arg0->actorData[0]);
            result = _gspropctrl_entrypoint_13(*prop) - 1;
            arg0->rotation[2] = _gspropctrl_entrypoint_12(*prop);
        }
        i++;
        prop++;
        } while (i != count);
    }
    count = _gccubesearch_entrypoint_9(0x4DD, props, 2);
    i = 0;
    if (count > 0) {
        prop = props;
        do {
        if (_gspropctrl_entrypoint_8(*prop) == world + 0x32) {
            _gspropctrl_entrypoint_11(*prop, (f32 *)&arg0->actorData[4]);
            arg0->unk54 = _gspropctrl_entrypoint_13(*prop) / 10.0f;
            arg0->unk50 = _gspropctrl_entrypoint_12(*prop) / 10.0f;
        }
        i++;
        prop++;
        } while (i != count);
    }
    func_800F18FC((f32 *)&arg0->actorData[4], (f32 *)&arg0->actorData[0], angles);
    arg0->rotation[0] = angles[0];
    arg0->rotation[1] = angles[1];
    func_800EEBF0((f32 *)&arg0->actorData[0], angles, 4000.0f);
    func_800EF04C((f32 *)&arg0->actorData[0], (f32 *)&arg0->actorData[4]);
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800214_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800388_chworlddoors.s")

s32 func_808006A8_chworlddoors(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800FFAB0(Actor *);
    void func_8010A800(Actor *, s32);
    void func_80800214_chworlddoors(Actor *, s32);
    switch (arg1) {
        case 0x49:
            if (arg2 >= 0x7A && arg2 < 0x84) {
                arg0->unk79_4 = arg2 - 0x7A;
                func_8010A800(arg0, 0);
                func_80800214_chworlddoors(arg0, 1);
                return 1;
            }
            func_800FFAB0(arg0);
            return 0;
        case 0xB:
            if (arg0->unk70_10 == 1) {
                func_80800214_chworlddoors(arg0, 2);
            }
            return 3;
    }
    return 0;
}

void func_80800750_chworlddoors(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_2(Actor*);
    s32 func_800E1720(s32);
    u32 temp_v0;

    temp_v0 = arg0->actorData[3];
    if (temp_v0 != 0) {
        func_800E1720(temp_v0 - 1);
    }
    if (arg0->unk5F != 0) {
        _subaddieaudioloop_entrypoint_2(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800798_chworlddoors.s")

OSThread *chworlddoors_entrypoint_0(void)
{
    extern u8 D_80800A04_chworlddoors[];

    return (OSThread *) D_80800A04_chworlddoors;
}
