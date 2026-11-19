#include "common.h"

OSThread *changlerbossflare_entrypoint_0(void)
{
    extern ActorData D_80800480_changlerbossflare[];

    return (OSThread *) D_80800480_changlerbossflare;
}

void func_8080000C_changlerbossflare(Actor *arg0) {
    struct FlareActorFields {
        u8 pad0[0x54];
        s32 unk54;
        u8 pad58[0x18];
        BT_BITFIELD_ORDER(u32 pad70:31, u32 initialized : 1);
        BT_BITFIELD_ORDER(u32 initialized:1, u32 pad70 : 31);
    } *self = (void *)arg0;
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800C8A98(void);
    void func_8010A3E8(void *, f32);
    extern s32 D_808004C8_changlerbossflare[5];
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808004C8_changlerbossflare);
    func_8010A3E8(arg0, 0.3f);
    self->unk54 = func_800C8A98();
    self->initialized = 1;
}

void func_80800068_changlerbossflare(Actor *arg0) {
    struct FlareActorFields {
        u8 pad0[0x18];
        f32 angle;
        u8 pad1C[0x38];
        s32 unk54;
    };
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32 id,u32 *color);
    f32 func_800D8FF8(void);
    s32 func_8010B990(Actor *, s32);
    void func_80800190_changlerbossflare(Actor *);
    void func_8080021C_changlerbossflare(Actor *);
    void func_808003A4_changlerbossflare(Actor *);
    extern u32 D_808004DC_changlerbossflare[6];
    extern s32 D_808004F4_changlerbossflare[3];

    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808004DC_changlerbossflare);
    ((struct FlareActorFields *)arg0)->angle += func_800D8FF8() * 300.0f;
    if (arg0->unk70_10 == 1) {
        func_800C8E54(((struct FlareActorFields *)arg0)->unk54, arg0->scale * 400.0f, arg0->scale * 1000.0f);
        func_800C8E84(((struct FlareActorFields *)arg0)->unk54, D_808004F4_changlerbossflare);
        func_800C8CB8(((struct FlareActorFields *)arg0)->unk54, arg0->position);
        func_8080021C_changlerbossflare(arg0);
        func_808003A4_changlerbossflare(arg0);
        if (func_8010B990(arg0, 0x400007) & 0x20) {
            func_80800190_changlerbossflare(arg0);
        }
    }
}

/* extern */

s32 func_80800154_changlerbossflare(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80800190_changlerbossflare(Actor *);
    switch (arg1) {
    case 0x40:
        func_80800190_changlerbossflare(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800190_changlerbossflare(Actor *arg0) {
    struct FlareActorFields {
        u8 pad0[0x54];
        s32 unk54;
    };
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800FFAB0(Actor *);
    void func_8010A570(Actor *);
    extern s32 D_80800500_changlerbossflare[15];
    extern s32 D_8080053C_changlerbossflare[5];

    if (((struct FlareActorFields *)arg0)->unk54 != 0) {
        ((struct FlareActorFields *)arg0)->unk54 = _chlightfader_entrypoint_1(((struct FlareActorFields *)arg0)->unk54, 1.4f, 2);
    }
    func_800BBCB8(arg0->position, arg0->position, 1.0f, 0xC, D_80800500_changlerbossflare);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080053C_changlerbossflare);
    func_8010A570(arg0);
    func_800FFAB0(arg0);
}

void func_8080021C_changlerbossflare(Actor *arg0) {
    s32 func_8001210C(s32);
    BtIntPtr func_800B53A4(s32);
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
    void func_800F1A88(f32 *, f32 *);
    f32 func_80103EAC(Actor *);
    extern s32 D_80800550_changlerbossflare[];
    f32 rotation[3];
    f32 position[3];
    f32 offset[3];
    f32 distance;
    f32 angle;
    BtIntPtr emitter;
    s32 i;

    func_800F1A88((f32 *)&arg0->actorData[4], rotation);
    rotation[2] = 0.0f;
    rotation[0] += 90;
    if (func_8001210C(1) == 0) {
        distance = func_80103EAC(arg0) * 0.35f;
        emitter = func_800B53A4(4);
        func_800BA3FC(emitter, 0x9E2);
        for (angle = 0.0f, i = 0; i < 4; i++, angle += 90.0f) {
            func_800EEB9C(offset, ((f32 *)arg0->actorData)[0] + angle, distance);
            func_800EF5A0(offset, rotation, offset[0], offset[1], offset[2]);
            func_800EE780(position, arg0->position, offset);
            func_800BABB8(emitter, position, NULL, 1.0f, D_80800550_changlerbossflare);
        }
    }
}

void func_808003A4_changlerbossflare(Actor *arg0) {
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6438(BtUIntPtr);
    f32 sp34[3];
    f32 sp2C[2];

    if (arg0->unk64_20 && func_800F6438(arg0->unk6C_0)) {
        func_800F5A00(arg0->unk6C_0, sp34);
        if (func_800EEB40(arg0->position, sp34) < 1440000.0f) {
            arg0->unk64_20 = 0;
            return;
        }
        func_800F18FC(arg0->position, sp34, sp2C);
        func_800EEBF0((f32 *)&arg0->actorData[4], sp2C, func_800EEF94((f32 *)&arg0->actorData[4]));
    }
}
/* data_to_c.py: from asm/data/overlays/ch/anglerboss/flare.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800480_changlerbossflare [1] BT_DATA(4, overlays_ch_anglerboss_flare, 0x0) = { { 680, 1119, 2043, 1, 0, (void (*)(struct Actor *))func_80800068_changlerbossflare, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 2, 4100, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_changlerbossflare, (void (*)(void *, long, void *, long, void *))func_80107C2C, 0, 0, (void (*)(struct Actor *, long, long))func_80800154_changlerbossflare, 0 } };
s32 D_808004C8_changlerbossflare[5] BT_DATA(4, overlays_ch_anglerboss_flare, 0x48) = { 1246688, 1769496, 131085, 20971865, 0 };
u32 D_808004DC_changlerbossflare[6] BT_DATA(4, overlays_ch_anglerboss_flare, 0x5C) = { 0x13052E, 0x1B0018, 0x103E8, 0x1F40000E, 0xC000D9, 0x1800000 };
s32 D_808004F4_changlerbossflare[3] BT_DATA(4, overlays_ch_anglerboss_flare, 0x74) = { 255, 255, 96 };
s32 D_80800500_changlerbossflare[15] BT_DATA(4, overlays_ch_anglerboss_flare, 0x80) = { 1903082, 1442304, 1376256, 10027051, 12583168, 2228428, 16777280, 5832749, 6553800, 917544, 3932187, -9764964, 2621240, -13107000, 13107200 };
s32 D_8080053C_changlerbossflare[5] BT_DATA(4, overlays_ch_anglerboss_flare, 0xBC) = { 1246227, 1769496, 131085, 19267904, 0 };
s32 D_80800550_changlerbossflare [12] BT_DATA(4, overlays_ch_anglerboss_flare, 0xD0) = { 1441796, 2228377, 13369382, 3342357, 1638553, 2818201, 13369383, 1310740, 3932220, 18481152, 0, 0 };
