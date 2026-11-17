#include "common.h"

OSThread *chweldarbossfireball_entrypoint_0(void)
{
    extern ActorData D_80800410_chweldarbossfireball[];

    return (OSThread *) D_80800410_chweldarbossfireball;
}

void func_8080000C_chweldarbossfireball(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800C8A98(void);
    void func_800C8E54(s32, f32, f32);
    f32 func_800DC178(f32, f32);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    extern u8 D_80800458_chweldarbossfireball[];
    union {
        f64 pair;
        f32 values[2];
    } angles;

    arg0->actorData[7] = 0;
    arg0->unk50 = func_800DC178(0.0f, 360.0f);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800458_chweldarbossfireball);
    func_800EFB24(&arg0->actorData[4], arg0->actorData, arg0->position);
    func_800F18FC(arg0->position, (f32 *)arg0->actorData, angles.values);
    arg0->rotation[0] = -angles.values[0];
    arg0->rotation[1] = angles.values[1];
    func_800EF368((f32 *)&arg0->actorData[4], 1800.0f);
    arg0->actorData[7] = func_800C8A98();
    func_800C8E54(arg0->actorData[7], 500.0f, 800.0f);
}

void func_808000C4_chweldarbossfireball(Actor *arg0) {
    s32 func_8001210C(s32);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    f32 func_800D8FF8(void);
    s32 func_8010B990(Actor *, s32);
    void func_808002E0_chweldarbossfireball(Actor *);
    void func_80800404_chweldarbossfireball(BtIntPtr);
    extern u32 D_80800468_chweldarbossfireball[];
    extern u32 D_80800474_chweldarbossfireball[];
    u32 *color;
    s32 effect;

    arg0->unk50 += func_800D8FF8() * 500.0f;
    if (arg0->unk70_10 == 1) {
        if (func_8010B990(arg0, 0x400007) & 0x20) {
            func_808002E0_chweldarbossfireball(arg0);
        }
        func_80800404_chweldarbossfireball((BtIntPtr)arg0);
    }
    effect = arg0->actorData[7];
    if (effect != 0) {
        func_800C8CB8(effect, arg0->position);
        if (func_8001210C(1) != 0) {
            color = D_80800474_chweldarbossfireball;
        } else {
            color = D_80800468_chweldarbossfireball;
        }
        func_800C8E84(arg0->actorData[7], color);
    }
}    typedef struct { u8 pad0[0x34]; s32 unk34; } Objfireball_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080017C_chweldarbossfireball(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (((Objfireball_arg0 *)arg0)->unk34);
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (((Objfireball_arg0 *)arg0)->unk34) = 0;
    }
}

/* extern */

void func_808001B4_chweldarbossfireball(Actor *arg0, s32 arg1) {
    void* func_800DE448(f32* position, f32* arg1, f32 scale, f32* arg3, BtIntPtr arg4);
    void func_800DF830(s32 arg0);
    void func_801018A4(Actor *, BtIntPtr);
    BtIntPtr func_800D674C(s32);
    s32 func_80101970();
    Actor *actor;
    BtIntPtr asset;
    actor = arg0;
    func_80101970(actor);
    func_800DF830(2);
    asset = func_800D674C(0x89D);
    func_800DE448(actor->position, actor->rotation, actor->scale, NULL, asset);
    func_801018A4(actor, arg1);
}

/* extern */

void func_80800214_chweldarbossfireball(Actor *arg0, s32 arg1) {
    void func_800D93A0(f32[4], f32[3]);
    void func_800DF41C(BtIntPtr);
    void func_800DFF2C(u8 **, s32, f32[4]);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_801015D0(Actor *);
    BtIntPtr func_801040D0(void);
    BtIntPtr sp34;
    f32 sp28[3];
    f32 sp18[4];

    sp34 = func_801040D0();
    func_801015D0(arg0);
    func_800DF41C(sp34);
    func_800EFA4C(sp28, arg0->unk50, 0.0f, 0.0f);
    func_800D93A0(sp18, sp28);
    func_800DFF2C(sp34, 0x2A, sp18);
}

/* extern */

s32 func_80800284_chweldarbossfireball(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80800214_chweldarbossfireball(Actor *, s32);
    void func_808002E0_chweldarbossfireball(Actor *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x40:
            func_808002E0_chweldarbossfireball(arg0);
            break;
        case 0x1F:
            func_80800214_chweldarbossfireball(arg0, *data);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808002E0_chweldarbossfireball(Actor *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800C8CB8(s32, f32[3]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void func_80103DFC(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor *);
    extern f32 B_808004E0_chweldarbossfireball[3];
    extern s32 D_80800480_chweldarbossfireball[17];
    extern s32 D_808004C4_chweldarbossfireball[7];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp44;
    Actor *sp40;
    f32 sp34[3];

    sp40 = func_80106790(arg0->unk3C);
    func_80103DFC(arg0, sp54);
    func_800EE7F8(sp48, sp54);
    sp44 = func_800F1DF4(arg0->position,
        sp40 != NULL ? sp40->position : B_808004E0_chweldarbossfireball);
    func_800EF1B8(sp48, sp44, 60.0f);
    sp48[1] -= 40.0f;
    func_800BBCB8(sp54, sp48, 1.0f, 0xA, D_80800480_chweldarbossfireball);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808004C4_chweldarbossfireball);
    if (arg0->actorData[7] != 0) {
        func_800EE7F8(sp34, arg0->position);
        sp34[1] += 100.0f;
        func_800C8CB8(arg0->actorData[7], sp34);
        arg0->actorData[7] = _chlightfader_entrypoint_1(arg0->actorData[7], 1.4f, 1);
    }
    func_8010A570(arg0);
    func_800FFAB0(arg0);
}

void func_80800404_chweldarbossfireball(BtIntPtr arg0) {
}
/* data_to_c.py: from asm/data/overlays/ch/weldarboss/fireball.data.s */
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800410_chweldarbossfireball [1] BT_DATA(4, overlays_ch_weldarboss_fireball, 0x0) = { { 768, 292, 2204, 1, 0, (void (*)(struct Actor *))func_808000C4_chweldarbossfireball, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808001B4_chweldarbossfireball, 0, 0, 0, 0, 0, 4100, (void (*)(struct Actor *))func_8080017C_chweldarbossfireball, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chweldarbossfireball, (void (*)(void *, long, void *, long, void *))func_80107C2C, 0, 0, (void (*)(struct Actor *, long, long))func_80800284_chweldarbossfireball, 0 } };
u8 D_80800458_chweldarbossfireball [16] BT_DATA(4, overlays_ch_weldarboss_fireball, 0x48) = { 0, 0x13, 6, 1, 0, 0x18, 0, 2, 0, 0xD, 0, 0xF3, 1, 0xC, 0, 0 };
u32 D_80800468_chweldarbossfireball [3] BT_DATA(4, overlays_ch_weldarboss_fireball, 0x58) = { 0, 0xE0, 0xFF };
u32 D_80800474_chweldarbossfireball [3] BT_DATA(4, overlays_ch_weldarboss_fireball, 0x64) = { 0xFF, 0xFF, 0xFF };
s32 D_80800480_chweldarbossfireball[17] BT_DATA(4, overlays_ch_weldarboss_fireball, 0x70) = { 1903077, 1443206, 2818355, 26804263, 13107400, 26214800, 2949620, 39321627, -65471264, 2228480, 20119680, 10027029, 204, 917534, 3276804, 13369351, 196608 };
s32 D_808004C4_chweldarbossfireball[7] BT_DATA(4, overlays_ch_weldarboss_fireball, 0xB4) = { 1246227, 1466792, 131085, 19267904, 0, 0, 0 };

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
f32 B_808004E0_chweldarbossfireball [ 3 ] BT_DATA(16, bss_weldarboss_fireball, 0x0);
#endif
