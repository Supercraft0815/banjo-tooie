#include "common.h"

OSThread *chtntbox_entrypoint_0(void)
{
    extern u8 D_80800988_chtntbox[];

    return (OSThread *) D_80800988_chtntbox;
}

OSThread *chtntbox_entrypoint_1(void)
{
    extern u8 D_808009D0_chtntbox[];

    return (OSThread *) D_808009D0_chtntbox;
}

void func_80800018_chtntbox(u8 *arg0) {
    struct TntBoxData { u8 pad[0x76]; unsigned short index : 9; unsigned short rest : 7; };

    *(s16 *)(arg0 + 0x7C) = (((struct TntBoxData *)arg0)->index * 10) + 0x320;
    (*(u8 *)((s8 *)(arg0) + (0x95))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x95))) & 0xFFFE) | 1);
}

void func_80800044_chtntbox(Actor *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    f32 func_800D8FF8(void);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_80108B04(Actor *, u32);
    s32 func_8010C9B0(f32 *, s32);
    s32 result;

    switch (arg0->unk70_10) {
        case 1:
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= func_800D8FF8();
                return;
            }
            if (arg0->unk64_29) {
                result = _subaddiejoy_entrypoint_6((u8 *)arg0, 1) == 1;
            } else {
                result = func_8010C9B0(arg0->position, arg0->unk74_7 * 10);
            }
            if (result) {
                func_80102424(arg0, 2);
            }
            break;
        case 2:
            if (func_80101E14(arg0, 0.3f)) {
                func_80108B04(arg0, 0);
            }
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 1);
                arg0->unk58 = 0.8f;
            }
            break;
    }
}

void func_8080015C_chtntbox(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    int func_800F7A7C(s32, s32, s32, s32, f32 *);
    void func_800FFAB0(Actor *);
    s32 func_80107070(Actor *, u32);
    s32 func_8010CEF8(f32 *, s32);
    void func_808003F0_chtntbox(s32, f32[3]);
    void func_80800824_chtntbox(s32, f32);
    extern s32 D_808008D0_chtntbox;
    extern s32 D_808008F4_chtntbox;
    extern s32 D_80800938_chtntbox;
    extern s32 D_80800A18_chtntbox;
    f32 position[3];

    func_800EE7F8(position, arg0->position);
    position[1] += 80.0f;
    func_800BBCB8(position, NULL, arg0->scale * 1.2f, 4, &D_808008D0_chtntbox);
    func_800BBCB8(position, position, arg0->scale * 1.2f, 0x10, &D_808008F4_chtntbox);
    func_800BBCB8(position, position, arg0->scale, 0xA, &D_80800A18_chtntbox);
    func_808003F0_chtntbox((s32)arg0, position);
    func_80800824_chtntbox((s32)position, 1.2f);
    _subaddieaudioquick_entrypoint_2(arg0, position, &D_80800938_chtntbox);
    func_800E1610(0, 20.0f, 0.9f, position);
    func_80018820(0, 2.0f, 0.25f);
    if (func_8010CEF8((f32 *)arg0, (s32)(arg0->scale * 300.0f))) {
        func_800F7A7C(func_800F54E4(), -1, 2, 5, arg0->position);
    }
    if (!func_80107070(arg0, 3)) {
        func_800FFAB0(arg0);
    }
}

/* extern */

s32 func_808002FC_chtntbox(Actor *arg0, s32 arg1, s32 arg2) {
    void func_8080015C_chtntbox(Actor *, s32);
    void func_808004F8_chtntbox(Actor *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x40:
            func_8080015C_chtntbox(arg0, *data);
            break;
        case 0x3D:
            func_808004F8_chtntbox(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_80800358_chtntbox(Actor *arg0) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    s32 func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF410(s32);
    void func_800DF830(s32);
    s32 func_80101870();
    s32 func_80101970();
    f32 *func_801027F4(Actor *);
    s32 pad;
    f32 *sp28;

    func_80101870();
    if (arg0->unk7C_12) {
        func_80101970(arg0);
        func_800DF830(3);
        func_800DF410(_subaddiefade_entrypoint_0(arg0));
        sp28 = func_801027F4(arg0);
        func_800DE448(arg0->position, sp28, arg0->scale * 0.25f, NULL, func_800D674C(0x6AC));
    }
}

void func_808003F0_chtntbox(s32 arg0, f32 arg1[3]) {
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    extern s32 D_80800A3C_chtntbox;
    s32 temp_s5;
    f32 sp60[3];
    s32 var_s1;

    temp_s5 = func_800B53A4(8);
    for (var_s1 = 0; var_s1 != 8; var_s1++) {
        func_800EEB9C(sp60, (f32) var_s1 * 45.0f, func_800DC178(60.0f, 80.0f));
        func_800EF04C(sp60, arg1);
        func_800BABB8(temp_s5, sp60, arg1, 0.6f, &D_80800A3C_chtntbox);
    }
}

void func_808004F8_chtntbox(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    f32 func_800EFB8C(f32 *, f32 *);
    f32 func_800F0E00(f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    f32 func_80103EAC(Actor *);
    Actor *func_801084B0(s32, Actor **);
    void func_8010D254(f32 *);
    f32 sqrtf(f32);
    extern s32 D_80800A78_chtntbox;
    s32 pad0;
    f32 distance;
    f32 height;
    f32 horizontal;
    f32 speed;
    f32 range;
    s32 pad1;
    s32 fade[3];
    Actor *actor;

    actor = func_801084B0(0x200, &arg0);
    func_8010D254((f32 *)actor->actorData);
    actor->position[1] += 180.0f;
    range = func_80103EAC(arg0);
    horizontal = func_800EFB8C(actor->position, (f32 *)actor->actorData);
    distance = func_800F0E00(range, horizontal);
    height = actor->position[1] - ((f32 *)actor->actorData)[1];
    if (height <= -distance) {
        height = distance - 10.0f;
    }
    actor->rotation[1] = func_80102D78(actor, (f32 *)actor->actorData);
    speed = sqrtf((distance * distance * 3800.0f) / (distance + height));
    func_800EEC30((f32 *)&actor->actorData[4], 45.0f, actor->rotation[1], speed);
    _subaddiefade_entrypoint_9(arg0, fade);
    _subaddiefade_entrypoint_11(actor, fade);
    _subaddieaudioquick_entrypoint_2(arg0, actor->position, &D_80800A78_chtntbox);
}

void func_80800624_chtntbox(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    void func_80090494(s32, f32 *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800BFA1C();
    f32 func_800D8FF8(void);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    s32 func_8010B990(Actor *, s32);
    s32 func_8010CEF8(f32 *, s32);
    void func_808007B0_chtntbox(f32 *);
    void func_80800824_chtntbox(s32, f32);
    extern s32 D_808008D0_chtntbox;
    extern s32 D_808008F4_chtntbox;
    extern s32 D_80800938_chtntbox;
    f32 dt;
    f32 position[3];

    dt = func_800D8FF8();
    arg0->rotation[0] += 750.0f * dt;
    arg0->rotation[2] += 40.0f * dt;
    func_808007B0_chtntbox((f32 *)arg0);
    if (func_8010B990(arg0, 0x400007) & 0x20) {
        func_800EE7F8(position, arg0->position);
        position[1] += 80.0f;
        func_800BBCB8(position, NULL, arg0->scale, 4, &D_808008D0_chtntbox);
        func_800BBCB8(position, position, arg0->scale, 0x10, &D_808008F4_chtntbox);
        func_80800824_chtntbox((s32)position, 1.0f);
        _subaddieaudioquick_entrypoint_2(arg0, position, &D_80800938_chtntbox);
        func_800E1610(0, 20.0f, 0.9f, arg0->position);
        func_80018820(0, 2.0f, 0.25f);
        if (func_8010CEF8((f32 *)arg0, 0xA0)) {
            func_80090494(5, arg0->position);
        }
        func_800FFAB0(arg0);
        return;
    }
    if (!func_800BFA1C(arg0->position)) {
        func_800FFAB0(arg0);
        return;
    }
    ((f32 *)arg0->actorData)[5] += -3800.0f * dt;
}

void func_808007B0_chtntbox(f32 *arg0) {
    s32 func_8001211C();
    void func_800BA22C(s32, s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800A80_chtntbox;
    s32 sp24;

    sp24 = func_800BABB8(0, arg0 + 1, 0, 1.4f, &D_80800A80_chtntbox);
    func_800BA3FC(sp24, (func_8001211C() & 1) ? 0x9E3 : 0x9E2);
    func_800BA22C(sp24, 1);
}

void func_80800824_chtntbox(s32 arg0, f32 arg1) {
    s32 _chlightfader_entrypoint_1(s32, s32, s32);
    s32 func_800C8A98();
    s32 func_800C8CB8(s32, s32);
    s32 func_800C8E54(s32, f32, f32);
    s32 func_800C8E84(s32, s32 *);
    extern s32 D_80800AC8_chtntbox;
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800C8A98();
    sp1C = temp_v0;
    func_800C8CB8(temp_v0, arg0);
    func_800C8E84(sp1C, &D_80800AC8_chtntbox);
    func_800C8E54(sp1C, arg1 * 400.0f, arg1 * 800.0f);
    _chlightfader_entrypoint_1(sp1C, 0x3FB33333, 5);
}
