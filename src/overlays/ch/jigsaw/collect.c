#include "common.h"

OSThread *chjigsawcollect_entrypoint_0(void)
{
    extern ActorData D_80800670_chjigsawcollect[];

    return (OSThread *) D_80800670_chjigsawcollect;
}

void func_8080000C_chjigsawcollect(Actor *arg0) {
    typedef struct {
        f32 angle;
        f32 rotation;
        f32 speed;
        s32 unkC;
        s32 light;
    } CollectData;
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32[3]);
    void func_800CF9E4(s32 arg0, s32 arg1, s32 arg2);
    s32 func_800CFA70(s32, s32);
    void func_800FC660(u32);
    void *func_80100094(Actor *, u32);
    s32 light;
    CollectData *data;

    data = func_80100094(arg0, 0);
    if (func_800CFA70(data->unkC, 1) != -1) {
        light = func_800C8A98();
        data->light = light;
        func_800CF9E4(data->unkC, 1, light);
        func_800C8CB8(data->light, arg0->position);
    } else {
        data->light = 0;
    }
    data->rotation = 0.0f;
    data->angle = -70.0f;
    data->speed = 500.0f;
    func_800FC660(0x1C);
    func_800FC660(5);
    arg0->unk64_20 = 1;
}

void func_808000CC_chjigsawcollect(Actor *arg0) {
    typedef struct {
        u8 unk0[4];
        f32 position[3];
        u8 unk10[0x38];
        f32 yaw;
        u8 unk4C[0x18];
        BT_BITFIELD_ORDER(u32 unk64_0 : 11, u32 unk64_12 : 20);
        u32 music : 1;
        BT_BITFIELD_ORDER(u32 unk64_12 : 20, u32 unk64_0 : 11);
        u8 unk68[0xA];
        BT_BITFIELD_ORDER(u16 state : 6, u16 unk72_6 : 10);
        BT_BITFIELD_ORDER(u16 unk72_6 : 10, u16 state : 6);
    } CollectActor;
    typedef struct {
        f32 angle;
        f32 rotation;
        f32 speed;
        f32 unkC;
        s32 light;
    } CollectData;
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 _fxsparkle_entrypoint_1(BtIntPtr, s32);
    void _fxtwinkle_entrypoint_0(f32 *);
    s32 _subaddieaudioquick_entrypoint_2(BtIntPtr, s32, s32 *);
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    void func_800C4B64(f32);
    void func_800C8CB8(s32, f32 *);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800FFAB0(BtIntPtr);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s32 func_80103DFC(u8 *, f32 *);
    void func_808005B8_chjigsawcollect(BtIntPtr, BtIntPtr);
    extern s32 D_808006B8_chjigsawcollect[3];
    extern s32 D_808006C4_chjigsawcollect[3];
    f32 dt;
    f32 player[3];
    f32 position[3];
    f32 oldRotation;
    f32 randomAngle;
    f32 twinkleAngle;
    f32 speed;
    s32 i;
    CollectData *data;
    CollectActor *actor = (CollectActor *)arg0;

    data = func_80100094(arg0, 0);
    dt = func_800D8FF8();
    func_800F5A00(func_800F54E4(), player);
    player[1] += 120.0f;
    switch (actor->state) {
        case 1:
            oldRotation = data->rotation;
            data->rotation += 600.0f * dt;
            data->angle += 60.0f * dt;
            if (data->angle >= 90.0f) {
                data->angle = 90.0f;
                func_80101FDC(arg0, 2);
                if (actor->music) {
                    func_800FCAE0(0x1C, 0, 500);
                    func_800FCA90(0x1C);
                    actor->music = 0;
                }
                _subaddieaudioquick_entrypoint_2((BtIntPtr)arg0, (BtIntPtr)actor->position, D_808006B8_chjigsawcollect);
            } else if (func_80013728(oldRotation) <= 0.0f &&
                       func_80013728(data->rotation) > 0.0f &&
                       func_80013728(data->angle) < 70.0f) {
                func_800C4B64(func_800F10B4(func_80013728(data->angle), -70.0f, 70.0f, 1.0f, 1.2f));
                _subaddieaudioquick_entrypoint_2((BtIntPtr)arg0, (BtIntPtr)actor->position, D_808006C4_chjigsawcollect);
            }
            data->angle = func_80013728(data->angle);
            data->rotation = func_80013728(data->rotation);
            actor->yaw = func_800136E4(func_800F1DF4(actor->position, player));
            func_80103DFC((u8 *)arg0, position);
            randomAngle = func_800DC178(0.0f, 360.0f);
            func_800EF214(position, randomAngle, func_800DC178(0.0f, 360.0f), 20.0f);
            func_808005B8_chjigsawcollect((BtIntPtr)arg0, (BtIntPtr)position);
            break;
        case 2:
            speed = func_800F15F8(data->speed, 1600.0f, dt * 1000.0f);
            data->speed = speed;
            actor->yaw += dt * speed;
            for (i = 0; i != 4; i++) {
                if (func_800DC0C0() < 0.08f) {
                    func_80103DFC((u8 *)arg0, position);
                    twinkleAngle = func_800DC178(0.0f, 360.0f);
                    func_800EF214(position, twinkleAngle, func_800DC178(0.0f, 360.0f), 20.0f);
                    _fxtwinkle_entrypoint_0(position);
                }
            }
            if (func_8001210C(3) == 0) {
                func_80103DFC((u8 *)arg0, position);
                func_808005B8_chjigsawcollect((BtIntPtr)arg0, (BtIntPtr)position);
            }
            if (data->speed == 1600.0f) {
                _fxsparkle_entrypoint_1((BtIntPtr)actor->position, 10);
                if (data->light != 0) {
                    data->light = _chlightfader_entrypoint_1(data->light, 2.2f, 2);
                }
                func_800FFAB0((BtIntPtr)arg0);
            }
            break;
    }
    func_800EE7F8(actor->position, player);
    dt = func_800F10B4(data->angle, -70.0f, 90.0f, 10.0f, 40.0f);
    func_800EF214(actor->position, data->angle, data->rotation, 120.0f + dt);
    if (data->light != 0) {
        func_800EE7F8(position, actor->position);
        position[1] += 100.0f;
        func_800C8CB8(data->light, position);
    }
}

/* extern */

void func_80800524_chjigsawcollect(Actor *arg0) {
    typedef struct {
        f32 angle;
        f32 rotation;
        f32 speed;
        f32 unkC;
        s32 light;
    } CollectData;
    void func_800C8B84(volatile s32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    void *func_80100094(Actor *, u32);
    CollectData *data;

    data = func_80100094(arg0, 0);
    if (data->light != 0) {
        func_800C8B84(data->light);
        data->light = 0;
    }
    if (arg0->unk64_20) {
        func_800FCAE0(0x1C, 0, 0x1F4);
        func_800FCA90(0x1C);
        arg0->unk64_20 = 0;
    }
}

s32 func_808005A4_chjigsawcollect(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
void func_808005B8_chjigsawcollect(BtIntPtr arg0, BtIntPtr arg1) {
    BtIntPtr func_800BBCB8(BtIntPtr, BtIntPtr, s32, s32, s32 *);
    extern s32 D_808006D0_chjigsawcollect[12];
    func_800BBCB8(arg1, 0, 0x3F800000, 1, D_808006D0_chjigsawcollect);
}

void chjigsawcollect_entrypoint_1(Actor **arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x73];
        BT_BITFIELD_ORDER(u8 pad73_1 : 7, u8 unk73_0 : 1);
        BT_BITFIELD_ORDER(u8 unk73_0 : 1, u8 pad73_1 : 7);
    } CollectActor;
    typedef struct {
        s32 unk0[3];
        s32 unkC;
    } CollectData;
    void *func_80100094(Actor *, u32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    Actor *actor;

    actor = func_80108528(0x4EF, (*arg0)->position, 0, arg0);
    ((CollectActor *)actor)->unk73_0 = arg2;
    ((CollectData *)func_80100094(actor, 0))->unkC = arg1;
}
/* data_to_c.py: from asm/data/overlays/ch/jigsaw/collect.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800670_chjigsawcollect [1] BT_DATA(4, overlays_ch_jigsaw_collect, 0x0) = { { 344, 1263, 1552, 1, 0, (void (*)(struct Actor *))func_808000CC_chjigsawcollect, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 4, (void (*)(struct Actor *))func_80800524_chjigsawcollect, 0, 20, 0, (void (*)(struct Actor *))func_8080000C_chjigsawcollect, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, (void (*)(struct Actor *, long, long))func_808005A4_chjigsawcollect, 0 } };
s32 D_808006B8_chjigsawcollect[3] BT_DATA(4, overlays_ch_jigsaw_collect, 0x48) = { 1246821, 1467792, 1769472 };
s32 D_808006C4_chjigsawcollect[3] BT_DATA(4, overlays_ch_jigsaw_collect, 0x54) = { 1246820, 1900571, 0 };
s32 D_808006D0_chjigsawcollect[12] BT_DATA(4, overlays_ch_jigsaw_collect, 0x60) = { 1903074, 1834608, -19660757, 13369651, 2228326, 6684679, 458791, 270, 270, 0, 0, 0 };
