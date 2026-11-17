#include "common.h"

OSThread *chfactoryprop_entrypoint_0(void)
{
    extern ActorData D_80800C20_chfactoryprop[];

    return (OSThread *) D_80800C20_chfactoryprop;
}

OSThread *chfactoryprop_entrypoint_1(void)
{
    extern ActorData D_80800C68_chfactoryprop[];

    return (OSThread *) D_80800C68_chfactoryprop;
}

OSThread *chfactoryprop_entrypoint_2(void)
{
    extern ActorData D_80800CB0_chfactoryprop[];

    return (OSThread *) D_80800CB0_chfactoryprop;
}                typedef struct { u8 pad0[0x18]; u8 unk18; u8 pad19[0x3]; u8 unk1C; u8 pad1D[0x7]; f32 unk24; u8 pad28[0xC]; f32 unk34; u8 pad38[0xC]; f32 unk44; } Objprop_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800024_chfactoryprop(u8 *arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2) BT_PASS2(, s32 bt_a3)) {
    s32 _subaddiefade_entrypoint_14(BtIntPtr);
    s32 func_8010A63C(BtIntPtr);
    (((Objprop_arg0 *)arg0)->unk34) = 1.0f;
    (((Objprop_arg0 *)arg0)->unk24) = 1.0f;
    _subaddiefade_entrypoint_14((BtIntPtr) arg0);
    func_8010A63C((BtIntPtr) arg0);
    (((Objprop_arg0 *)arg0)->unk44) = 30.0f;
}

void func_80800070_chfactoryprop(Actor *arg0) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    f32 func_800F15F8(f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    BtIntPtr func_801065A4(void *);
    void func_80800324_chfactoryprop(Actor *);
    void func_80800674_chfactoryprop(u8 *);
    void func_80800988_chfactoryprop(Actor *);
#ifdef BT_NATIVE
    void chfactoryprop_entrypoint_3(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    extern s32 _chfactoryprop_entrypoint_3;
#endif
    f32 delta;

    delta = func_800D8FF8();
    if (((f32 *)arg0->actorData)[4] > 0.0f) {
        if (arg0->unk6C_9 == 0x3B2) {
            func_80800674_chfactoryprop((u8 *)arg0);
        } else {
            func_80800988_chfactoryprop(arg0);
        }
    } else {
        _subaddieaudioloop_entrypoint_2(arg0);
    }
    switch (arg0->unk70_10) {
        case 1:
            arg0->rotation[0] = func_800136E4(arg0->rotation[0] + ((f32 *)arg0->actorData)[4] * delta);
            func_80800324_chfactoryprop(arg0);
            break;
        case 2:
            ((f32 *)arg0->actorData)[4] = func_800F15F8(((f32 *)arg0->actorData)[4], 0.0f, 40.0f * delta);
            arg0->rotation[0] = func_800136E4(arg0->rotation[0] + ((f32 *)arg0->actorData)[4] * delta);
            if (((f32 *)arg0->actorData)[4] == 0.0f) {
                func_80101FDC(arg0, 3);
            }
            break;
    }
    if (func_801065A4(arg0)) {
        _glid_entrypoint_0(func_801065A4(arg0), 1, &_chfactoryprop_entrypoint_3, (BtIntPtr)arg0->unk0);
    }
}

/* extern */

void func_808001D8_chfactoryprop(void *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    (((Objprop_arg0 *)arg0)->unk18) = _subaddieaudioloop_entrypoint_3((((Objprop_arg0 *)arg0)->unk18));
    (((Objprop_arg0 *)arg0)->unk1C) = _subaddieaudioloop_entrypoint_3((((Objprop_arg0 *)arg0)->unk1C));
}

s32 func_80800214_chfactoryprop(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _glcutDll_entrypoint_19(s32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
        case 0x49:
            if (!_glcutDll_entrypoint_19(0x45)) {
                return 0;
            } else {
                func_80101FDC(arg0, 2);
                if (arg0->unk6C_9 == 0x3B2) {
                    _capod_entrypoint_13(arg0->unk0, NULL, 3, 0x2910);
                }
            }
            break;
        case 0x4F:
            func_80101FDC(arg0, 2);
            break;
        case 0x95:
            *(u8 *)&arg0->actorData[1] = 0;
            *(u8 *)&arg0->actorData[0] = 0;
            if (func_800DA298(0x18C) && !_glcutDll_entrypoint_19(0x45) && !_glcutDll_entrypoint_20()) {
                func_80101FDC(arg0, 3);
                *(f32 *)&arg0->actorData[4] = 0.0f;
            } else {
                *(f32 *)&arg0->actorData[4] = 400.0f;
                *(f32 *)&arg0->actorData[5] = 0.0f;
            }
            break;
    }
    return 0;
}

void func_80800324_chfactoryprop(Actor *arg0) {
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    void func_8008FE68(f32 *);
    void func_80090794(BtIntPtr arg0);
    void func_800907C0(f32 *);
    void func_800C3058(u8, s32);
    f32 func_800D8FF8(void);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    extern s32 D_80800CF8_chfactoryprop[4];
    f32 velocity[3];
    f32 position[3];
    f32 distance;
    f32 speed;
    f32 delta;
    s32 active;
    s32 rate;

    if (arg0->unk6C_9 == 0x3B2) {
        func_8008FE68(position);
        if (!(position[2] > 1700.0f) && !(position[2] < -1700.0f)) {
            distance = position[0] - arg0->position[0];
            if (distance <= -100.0f) {
                speed = func_800F10B4(distance, -500.0f, -100.0f, 0.0f, 800.0f);
            } else {
                speed = func_800F10B4(distance, -100.0f, 4000.0f, 800.0f, 0.0f);
            }
            delta = func_800D8FF8();
            *(f32 *)&arg0->actorData[5] = func_800F15F8(*(f32 *)&arg0->actorData[5], 0.0f, delta * 400.0f);
            if (position[0] < 1300.0f && position[0] > 0.0f && position[1] < arg0->position[1]) {
                *(f32 *)&arg0->actorData[5] = 600.0f;
            }
            func_80090794(velocity);
            func_800EF1B8(velocity, 90.0f, (*(f32 *)&arg0->actorData[5] + speed) * delta);
            func_800907C0(velocity);
            active = 0;
            if (*(f32 *)&arg0->actorData[5] + speed > 240.00002f) {
                active = 1;
            }
            if (active != 0 || (active == 0 && *(u8 *)&arg0->actorData[1] != 0)) {
                rate = func_800F10B4(*(f32 *)&arg0->actorData[5] + speed, 0.0f, 800.0f, 8000.0f, 22000.0f);
                *(u8 *)&arg0->actorData[1] = _subaddieaudioloop_entrypoint_7(*(u8 *)&arg0->actorData[1], position, active, D_80800CF8_chfactoryprop, arg0->unk70_0);
                if (*(u8 *)&arg0->actorData[1] != 0) {
                    func_800C3058(*(u8 *)&arg0->actorData[1], rate);
                }
            }
        }
    }
}

/* extern */

void chfactoryprop_entrypoint_3(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, Unk80132ED0 *arg4) {
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 temp_f0;
    u8 *temp_v0;
    u8 alpha;

    temp_f0 = func_800F12D4(*(f32 *)&func_80106790(arg4)->actorData[4], 0.0f, 160.0f, 0.0, 64.0f);
    temp_v0 = (arg3 * 0x10) + arg2;
    if (arg2 < temp_v0) {
        alpha = (u32)temp_f0;
        do {
            arg2 += 0x10;
            arg2[-1] = alpha;
        } while (arg2 < temp_v0);
    }
}

void func_80800674_chfactoryprop(u8 *arg0) {
    u8 _subaddieaudioquick_entrypoint_1(u8 *, u8 *);
    void func_8008FE68(f32 *);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    f32 func_800D8FF8(void);
    s32 func_800D9154(f32 *, f32);
    s32 func_800DB9B0(void);
    f32 func_800DC178(f32, f32);
    void func_800E3980(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    BtIntPtr func_800F54E4(void);
    s32 func_800F55FC(BtIntPtr);
    extern s32 D_80800D08_chfactoryprop[3];
    extern s32 D_80800D14_chfactoryprop[4];
    f32 sp54;
    f32 sp48[3];
    f32 temp_f12;
    f32 temp_f12_2;
    s32 sp3C;
    s32 sp38;

    if (func_800DB9B0() == 0) {
        sp38 = func_800F55FC(func_800F54E4());
        func_8008FE68(sp48);
        if (sp38 & 0x08000000) {
            *(f32 *)(arg0 + 0x34) = 0.3f;
        } else if (sp38 & 0x30000000) {
            *(f32 *)(arg0 + 0x34) = func_800F10B4(sp48[2], -1200.0f, -2400.0f, 1.0f, 0.3f);
        } else {
            *(f32 *)(arg0 + 0x34) = 1.0f;
        }
    } else {
        *(f32 *)(arg0 + 0x34) = 1.0f;
        func_800E3980(sp48);
    }
    *(f32 *)(arg0 + 0x24) = func_800F15F8(*(f32 *)(arg0 + 0x24), *(f32 *)(arg0 + 0x34), func_800D8FF8());
    temp_f12 = *(f32 *)(arg0 + 4) - sp48[0];
    if (temp_f12 < 0.0f) {
        sp3C = (s32)func_800F10B4(temp_f12, 0.0f, -8000.0f, 32767, 14000.0f);
    } else {
        sp3C = (s32)func_800F10B4(temp_f12, 0.0f, 2000.0f, 32767, 0);
    }
    if (arg0[0x5F] == 0) {
        arg0[0x5F] = func_800C4350(0, arg0 + 4, D_80800D08_chfactoryprop);
    }
    sp54 = func_800F12D4(*(f32 *)(arg0 + 0x28), 0.0f, 400.0f, 0.4f, 1.0f);
    temp_f12_2 = func_800F12D4(*(f32 *)(arg0 + 0x28), 0.0f, 400.0f, 0.4f, 1.0f);
    sp3C *= *(f32 *)(arg0 + 0x24) * temp_f12_2;
    func_800C31DC(arg0[0x5F], sp54);
    func_800C3058(arg0[0x5F], sp3C);
    func_800C4350(arg0[0x5F], arg0 + 4, NULL);
    if (func_800D9154((f32 *)(arg0 + 0x30), func_800F10B4(*(f32 *)(arg0 + 0x28), 0.0f, 400.0f, 0.8f, 0.3f)) != 0) {
        temp_f12_2 = *(f32 *)(arg0 + 0x28);
        if ((temp_f12_2 > 80.0f) && (sp3C != 0)) {
            if (arg0[0x18] == 0) {
                arg0[0x18] = _subaddieaudioquick_entrypoint_1(arg0, arg0 + 4);
            }
            sp54 = func_800F12D4(*(f32 *)(arg0 + 0x28), 0.0f, 400.0f, 0.2f, 0.5f) + func_800DC178(-0.05f, 0.05f);
            func_800C4B70((s32)(*(f32 *)(arg0 + 0x24) * (f32)sp3C));
            func_800C4B64(sp54);
            func_800C4350(arg0[0x18], arg0 + 4, D_80800D14_chfactoryprop);
        }
    }
}

void func_80800988_chfactoryprop(Actor *arg0) {
    void func_8008FE68(f32 *);
    void func_800C3058(u8, s32);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    s32 func_800DB9B0(void);
    void func_800E3980(f32 *);
    s32 func_800EA05C(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    extern s32 D_80800D24_chfactoryprop[7];
    f32 soundPosition[3];
    f32 playerPosition[3];
    f32 distance;
    s32 rate;

    if (func_800DB9B0() == 0) {
        func_8008FE68(playerPosition);
    } else {
        func_800E3980(playerPosition);
    }
    func_800EE7F8(soundPosition, arg0->position);
    soundPosition[0] = playerPosition[0];
    if (arg0->unk5F == 0) {
        arg0->unk5F = func_800C4350(0, soundPosition, D_80800D24_chfactoryprop);
    }
    switch (func_800EA05C()) {
        case 0x10F:
            distance = -1200.0f - playerPosition[0];
            if (distance < 0.0f) {
                rate = (s32)func_800F10B4(distance, 0.0f, -800.0f, 20000.0f, 0);
            } else {
                rate = 20000;
            }
            break;
        case 0x110:
            distance = arg0->position[1] - playerPosition[1];
            if (distance > 0.0f) {
                rate = (s32)func_800F10B4(distance, 0.0f, 4000.0f, 20000.0f, 0);
            } else {
                rate = 20000;
            }
            break;
    }
    rate *= func_800F12D4(*(f32 *)&arg0->actorData[4], 0.0f, 400.0f, 0.4f, 1.0f);
    func_800C3058(arg0->unk5F, rate);
    func_800C4350(arg0->unk5F, soundPosition, NULL);
}

/* extern */

void func_80800B44_chfactoryprop(BtIntPtr arg0) {
    void _chdoormake_entrypoint_12(Actor *arg0, s32 arg1, u16 arg2);
    s32 _chdoormake_entrypoint_3(BtIntPtr, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_6(Actor *arg0, f32 arg1);
    void _chdoormake_entrypoint_8(Actor *arg0, u32 arg1);
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *actor);
    s32 func_8010A63C();
    func_8010A63C();
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 200.0f, 0x20, 0x18C) != 0) {
        _chdoormake_entrypoint_6(arg0, 2.25f);
        _chdoormake_entrypoint_12(arg0, 0, 0x45);
        _chdoormake_entrypoint_8(arg0, 0xC);
    }
    if ((func_800DA298(0x18C) != 0) && (_glcutDll_entrypoint_19(0x45) == 0)) {
        func_800FFAB0(arg0);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/factory/prop.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
void _chdoor_entrypoint_0();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
ActorData D_80800C20_chfactoryprop [1] BT_DATA(4, overlays_ch_factory_prop, 0x0) = { { 791, 946, 1860, 1, 0, (void (*)(struct Actor *))func_80800070_chfactoryprop, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 5120, (void (*)(struct Actor *))func_808001D8_chfactoryprop, 0, 0, 0, (void (*)(struct Actor *))func_80800024_chfactoryprop, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9234, (void (*)(struct Actor *, long, long))func_80800214_chfactoryprop, 0 } };
ActorData D_80800C68_chfactoryprop [1] BT_DATA(4, overlays_ch_factory_prop, 0x48) = { { 792, 947, 1861, 1, 0, (void (*)(struct Actor *))func_80800070_chfactoryprop, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 17408, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800024_chfactoryprop, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9234, (void (*)(struct Actor *, long, long))func_80800214_chfactoryprop, 0 } };
ActorData D_80800CB0_chfactoryprop [1] BT_DATA(4, overlays_ch_factory_prop, 0x90) = { { 172, 1278, 2183, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 1024, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800B44_chfactoryprop, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
s32 D_80800CF8_chfactoryprop[4] BT_DATA(4, overlays_ch_factory_prop, 0xD8) = { 1246371, 655564, 131092, 0 };
s32 D_80800D08_chfactoryprop[3] BT_DATA(4, overlays_ch_factory_prop, 0xE8) = { 33947667, 104136706, 196608 };
s32 D_80800D14_chfactoryprop[4] BT_DATA(4, overlays_ch_factory_prop, 0xF4) = { 50724883, 67043357, 1966082, 1114112 };
s32 D_80800D24_chfactoryprop[7] BT_DATA(4, overlays_ch_factory_prop, 0x104) = { 33947667, 79626250, 11730946, 196608, 0, 0, 0 };
