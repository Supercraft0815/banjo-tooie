#include "common.h"

OSThread *changlerbossflare_entrypoint_0(void)
{
    extern u8 D_80800480_changlerbossflare[];

    return (OSThread *) D_80800480_changlerbossflare;
}

void func_8080000C_changlerbossflare(Actor *arg0) {
    struct FlareActorFields {
        u8 pad0[0x54];
        s32 unk54;
        u8 pad58[0x18];
        u32 pad70:31;
        u32 initialized:1;
    } *self = (void *)arg0;
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800C8A98(void);
    void func_8010A3E8(void *, f32);
    extern s32 D_808004C8_changlerbossflare;
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808004C8_changlerbossflare);
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
    s32 func_800C8E84(s32, s32 *);
    f32 func_800D8FF8(void);
    s32 func_8010B990(Actor *, s32);
    void func_80800190_changlerbossflare(Actor *);
    void func_8080021C_changlerbossflare(Actor *);
    void func_808003A4_changlerbossflare(Actor *);
    extern u32 D_808004DC_changlerbossflare;
    extern s32 D_808004F4_changlerbossflare;

    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_808004DC_changlerbossflare);
    ((struct FlareActorFields *)arg0)->angle += func_800D8FF8() * 300.0f;
    if (arg0->unk70_10 == 1) {
        func_800C8E54(((struct FlareActorFields *)arg0)->unk54, arg0->scale * 400.0f, arg0->scale * 1000.0f);
        func_800C8E84(((struct FlareActorFields *)arg0)->unk54, &D_808004F4_changlerbossflare);
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
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800FFAB0(Actor *);
    void func_8010A570(Actor *);
    extern s32 D_80800500_changlerbossflare;
    extern s32 D_8080053C_changlerbossflare;

    if (((struct FlareActorFields *)arg0)->unk54 != 0) {
        ((struct FlareActorFields *)arg0)->unk54 = _chlightfader_entrypoint_1(((struct FlareActorFields *)arg0)->unk54, 1.4f, 2);
    }
    func_800BBCB8(arg0->position, arg0->position, 1.0f, 0xC, &D_80800500_changlerbossflare);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080053C_changlerbossflare);
    func_8010A570(arg0);
    func_800FFAB0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/flare/func_8080021C_changlerbossflare.s")

void func_808003A4_changlerbossflare(Actor *arg0) {
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6438(u32);
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
