#include "common.h"

void func_80800000_chworlddoors(u8 *arg0) {
    BtIntPtr func_800BBCB8(f32 *arg0, f32 *arg1, f32 arg2, s32 arg3, s32 *arg4);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    extern s32 D_80800990_chworlddoors[18];
    f32 *sp20;
    f32 sp24[2];

    sp20 = (f32 *)(arg0 + 0x28);
    func_800EE7F8(sp24, sp20);
    func_800EF214(sp24, *(f32 *)(arg0 + 0x44), *(f32 *)(arg0 + 0x48), -50.0f);
    func_800BBCB8(sp20, sp24, 1.0f, 6, D_80800990_chworlddoors);
}

s32 func_80800068_chworlddoors(Actor *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _gspropctrl_entrypoint_12(Prop *);
    s32 _gspropctrl_entrypoint_13(Prop *);
    s32 _gspropctrl_entrypoint_8(Prop *);
    u8 _sujiggy_entrypoint_22(s32 arg0);
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
    BT_IDO_ONLY(if (count > 0)) BT_NATIVE_ONLY(if (!(count > 0)) { result = count; } else) {
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

void func_80800214_chworlddoors(Actor *arg0, s32 arg1) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    u16 _sujiggy_entrypoint_23(s32 arg0);
    void func_80018820(s32, f32, f32);
    void func_800C3F48(u32);
    s32 func_800E15CC(s32, f32, f32);
    BtIntPtr func_800E1720(s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80101FDC(Actor *, u32);
    void func_8010A800(Actor *, s32);
    s32 sp24;
    Unk80132ED0 *temp_a0;

    switch (arg1) {
    case 1:
        sp24 = func_80800068_chworlddoors(arg0);
        func_800EE7F8(arg0->position, (f32 *)arg0->actorData);
        temp_a0 = arg0->unk0;
        _capod_entrypoint_13(temp_a0, temp_a0, sp24, 0x6830);
        arg0->unk58 = 0.0f;
        break;
    case 2:
        *(u8 *)&arg0->actorData[7] = 0;
        arg0->unk58 = 1.0f;
        break;
    case 3:
        arg0->unk58 = 0.8f;
        *(u8 *)&arg0->actorData[7] = 0;
        func_800C3F48(0x7FFFFC90);
        break;
    case 4:
        func_800E1720(arg0->actorData[3] - 1);
        _subaddieaudioloop_entrypoint_2(arg0);
        arg0->unk58 = 2.0f;
        func_8010A800(arg0, 3);
        break;
    case 5:
        func_80101180(_sujiggy_entrypoint_23(arg0->unk79_4), 7, (s32)arg0->unk50);
        arg0->unk58 = arg0->unk50;
        break;
    case 6:
        if (arg0->unk79_4 == 0) {
            arg0->actorData[3] = func_800E15CC(2, 50.0f, 0.5f);
            func_80018820(0, 1.0f, 0.4f);
        }
        arg0->unk58 = arg0->unk54;
        break;
    }
    func_80101FDC(arg0, arg1);
}

void func_80800388_chworlddoors(Actor *arg0) {
    f32 _capod_entrypoint_18(void);
    void _glcutDll_entrypoint_17(void);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    void func_80018820(s32, f32, f32);
    void func_800C4B70(s32);
    s32 func_800D90A4(f32 *);
    void func_800E13F0(s32, f32);
    s32 func_800E15CC(s32, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern s32 D_808009D8_chworlddoors[4];
    extern u32 D_808009E8_chworlddoors[4];
    f32 sp34;

    switch (arg0->unk70_10) {
        case 1:
            sp34 = _capod_entrypoint_18();
            if (sp34 < 0.1f) {
                sp34 = 0.1f;
            }
            if (arg0->actorData[3] == 0) {
                arg0->actorData[3] = func_800E15CC(0, 0.0f, 1.0f) + 1;
            }
            func_800E13F0(arg0->actorData[3] - 1, sp34 * 10.0f);
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808009E8_chworlddoors);
            func_800C4B70((s32)(24000.0f * sp34));
            func_80018820(0, sp34, 0.1f);
            break;
        case 2:
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808009E8_chworlddoors);
            func_800C4B70(24000);
            func_80018820(0, 1.0f, 0.1f);
            if (func_800D90A4(&arg0->unk58)) {
                func_80800214_chworlddoors(arg0, 3);
                func_800EE7F8(arg0->position, (f32 *)&arg0->actorData[4]);
            } else {
                func_800EFE50(arg0->position, (f32 *)arg0->actorData, (f32 *)&arg0->actorData[4], func_800F10B4(arg0->unk58, 1.0f, 0.0f, 0.0f, 1.0f));
            }
            *(u8 *)&arg0->actorData[7] = _subaddieaudioloop_entrypoint_7(*(u8 *)&arg0->actorData[7], arg0->position, 1, D_808009D8_chworlddoors, 0);
            break;
        case 3:
            if (func_800D90A4(&arg0->unk58)) {
                func_80800214_chworlddoors(arg0, 4);
                *(u8 *)&arg0->actorData[7] = _subaddieaudioloop_entrypoint_3(*(u8 *)&arg0->actorData[7]);
                _subaddieaudioloop_entrypoint_2(arg0);
            } else {
                    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808009E8_chworlddoors);
                func_800C4B70(24000);
                func_80018820(0, 1.0f, 0.1f);
                func_80800000_chworlddoors((u8 *)arg0);
                arg0->scale = func_800F10B4(arg0->unk58, 0.8f, 0.0f, 1.0f, 0.001f);
                *(u8 *)&arg0->actorData[7] = _subaddieaudioloop_entrypoint_7(*(u8 *)&arg0->actorData[7], arg0->position, 1, D_808009D8_chworlddoors, 0);
                _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808009E8_chworlddoors);
                func_800C4B70(24000);
            }
            break;
        case 4:
            if (func_800D90A4(&arg0->unk58)) {
                func_80800214_chworlddoors(arg0, 5);
            }
            break;
        case 5:
            if (func_800D90A4(&arg0->unk58)) {
                func_80800214_chworlddoors(arg0, 6);
            }
            break;
        case 6:
            if (func_800D90A4(&arg0->unk58)) {
                _glcutDll_entrypoint_17();
            }
            break;
    }
}

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
    BtIntPtr func_800E1720(s32);
    u32 temp_v0;

    temp_v0 = arg0->actorData[3];
    if (temp_v0 != 0) {
        func_800E1720(temp_v0 - 1);
    }
    if (arg0->unk5F != 0) {
        _subaddieaudioloop_entrypoint_2(arg0);
    }
}

void func_80800798_chworlddoors(Actor *arg0, void *arg1) {
    void func_800B99CC(Gfx **, s32, s32 *);
    void *func_800D674C(s32);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, void *);
    void func_800DF830(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101870(Actor *, void *);
    f32 func_80103EAC(Actor *);
    extern s32 D_808009F8_chworlddoors[];
    f32 sp44[3];
    f32 sp40;
    s32 sp3C;
    f32 *sp2C;

    sp2C = arg0->position;
    func_800EE7F8(sp44, sp2C);
    func_800EF214(sp2C, arg0->rotation[0], arg0->rotation[1], func_80103EAC(arg0));
    switch (arg0->unk70_10) {
        case 3:
            sp40 = func_800F10B4(arg0->unk58, 0.8f, 0.0f, 0.0001f, 20.0f);
            sp3C = (s32)func_800F10B4(arg0->unk58, 0.8f, 0.0f, 0.0f, 255.0f);
            func_800DF830(0);
            func_800DE498(arg1, (f32 *)&arg0->actorData[4], arg0->rotation, sp40, NULL, func_800D674C(0x8CB));
            func_80101870(arg0, arg1);
            func_800B99CC(arg1, sp3C, D_808009F8_chworlddoors);
            break;
        case 2:
            func_80101870(arg0, arg1);
            break;
        case 4:
            func_800B99CC(arg1, (s32)func_800F10B4(arg0->unk58, 2.0f, 0.0f, 255.0f, 0.0f), D_808009F8_chworlddoors);
            break;
    }
    func_800EE7F8(sp2C, sp44);
}

OSThread *chworlddoors_entrypoint_0(void)
{
    extern ActorData D_80800A04_chworlddoors[];

    return (OSThread *) D_80800A04_chworlddoors;
}
/* data_to_c.py: from asm/data/overlays/ch/worlddoors.data.s */
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_80800990_chworlddoors[18] BT_DATA(4, overlays_ch_worlddoors, 0x0) = { 1903077, 1834208, -39321555, 52429800, 917504, 2621462, 268566562, 3342412, 10027238, 1376256, 13369387, 12583296, 262220, 458754, 0, -1019936768, -1022361600, -1022689280 };
s32 D_808009D8_chworlddoors[4] BT_DATA(4, overlays_ch_worlddoors, 0x48) = { 1246835, 2097154, 655577, 0 };
u32 D_808009E8_chworlddoors[4] BT_DATA(4, overlays_ch_worlddoors, 0x58) = { 0x1304A9, 0x2001E, 0xA0100, 0 };
s32 D_808009F8_chworlddoors [3] BT_DATA(4, overlays_ch_worlddoors, 0x68) = { 255, 255, 255 };
ActorData D_80800A04_chworlddoors [1] BT_DATA(4, overlays_ch_worlddoors, 0x74) = { { 344, 1307, 2406, 1, 0, (void (*)(struct Actor *))func_80800388_chworlddoors, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800798_chworlddoors, 0, 0, 0, 0, 2, 4096, (void (*)(struct Actor *))func_80800750_chworlddoors, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32704, 1026, (void (*)(struct Actor *, long, long))func_808006A8_chworlddoors, 0 } };
