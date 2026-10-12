#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonedartgunhead/func_80800000_chstonedartgunhead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonedartgunhead/func_808000A8_chstonedartgunhead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonedartgunhead/func_808001B4_chstonedartgunhead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonedartgunhead/func_80800224_chstonedartgunhead.s")

void func_80800364_chstonedartgunhead(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, s32 *);
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, s32 *, f32);
    s32 _subaddiejoy_entrypoint_6(Actor *, s32);
    void func_80016068(u32, f32 *);
    f32 func_800D8FF8();
    u8 func_800D9078(f32 *);
    f32 func_800F11E4(f32, f32, f32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, f32);
    void func_80108B04(Actor *, s32);
    void func_8010C820(Actor *, s32, s32);
    s32 func_8010CB0C(f32 *, s32, s32, s32);
    f32 func_8010CD28(Actor *);
    s32 func_8010D248();
    void func_808001B4_chstonedartgunhead(Actor *);
    void func_80800224_chstonedartgunhead(Actor *, s32);
    extern s32 D_80800E80_chstonedartgunhead;
    extern s32 D_80800E8C_chstonedartgunhead;
    extern s32 D_80800E9C_chstonedartgunhead;
    extern s32 D_80800EAC_chstonedartgunhead;
    typedef struct {
        u8 pad[0x2A];
        u8 pad2A:2;
        u8 enabled:1;
        u8 pad2B:5;
    } HeadMarker;
    typedef struct {
        u32 pad:2;
        u32 controlled:1;
        u32 player:2;
        u32 rest:27;
    } HeadFlags;
    typedef struct {
        f32 yaw;
        f32 limit;
        f32 count;
        f32 unused[3];
        f32 tilt;
        f32 soundTimer;
    } HeadData;
    s32 sp4C;
    f32 sp44[2];
    f32 sp3C[2];
    s32 sp38;
    f32 sp34;
    s32 padding;

    func_8010C820(arg0, 0x154, 0x64);
    (*(HeadMarker **)arg0)->enabled = 1;
    switch (arg0->unk70_10) {
    case 1:
        if (func_8010CB0C(arg0->position, (s32) ((HeadData *)arg0->actorData)->yaw, 0x190, -0x190) != 0) {
            func_80800224_chstonedartgunhead(arg0, 2);
        }
        break;
    case 2:
        if (func_80101E14(arg0, 0.856f) != 0) {
            func_80800224_chstonedartgunhead(arg0, 3);
        }
        break;
    case 3:
        if (func_8010CB0C(arg0->position, (s32) ((HeadData *)arg0->actorData)->yaw, 0x190, -0x190) == 0) {
            func_80800224_chstonedartgunhead(arg0, 5);
        } else {
            sp4C = (s32) arg0->rotation[1];
            if (((HeadFlags *)((u8 *)arg0 + 0x64))->controlled) {
                func_80016068(((HeadFlags *)((u8 *)arg0 + 0x64))->player, sp44);
                arg0->unk54 = arg0->rotation[1] + sp44[0] * 4.0f;
            } else {
                arg0->unk54 = func_8010CD28(arg0);
            }
            func_80102B2C(arg0, 4.0f);
            if (sp4C != (s32) arg0->rotation[1]) {
                ((HeadData *)arg0->actorData)->soundTimer = 0.2f;
            }
            if (((HeadFlags *)((u8 *)arg0 + 0x64))->controlled) {
                if ((_subaddiejoy_entrypoint_6(arg0, 1) != 0) && (arg0->unk58 <= 0.0f)) {
                    func_80800224_chstonedartgunhead(arg0, 4);
                }
            } else if ((arg0->unk58 <= 0.0f) && (func_80102CF4(arg0, 15.0f) != 0) && (func_8010D248() != 0)) {
                ((HeadData *)arg0->actorData)->count += 1.0f;
                if (((HeadData *)arg0->actorData)->count >= ((HeadData *)arg0->actorData)->limit) {
                    ((HeadData *)arg0->actorData)->count = 0.0f;
                    func_80800224_chstonedartgunhead(arg0, 4);
                }
            }
        }
        break;
    case 4:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800E80_chstonedartgunhead, 0.45f);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800E8C_chstonedartgunhead, 0.7f);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800E9C_chstonedartgunhead, 0.989f);
        if (((HeadFlags *)((u8 *)arg0 + 0x64))->controlled) {
            sp38 = (s32) arg0->rotation[1];
            if ((func_80101F24(arg0) >= 0.2f) && (arg0->unk58 <= 0.0f) && (_subaddiejoy_entrypoint_6(arg0, 1) != 0)) {
                func_80800224_chstonedartgunhead(arg0, 4);
            }
            func_80016068(((HeadFlags *)((u8 *)arg0 + 0x64))->player, sp3C);
            arg0->unk54 = arg0->rotation[1] + sp3C[0] * 4.0f;
            func_80102B2C(arg0, 4.0f);
            if (sp38 != (s32) arg0->rotation[1]) {
                ((HeadData *)arg0->actorData)->soundTimer = 0.2f;
            }
        }
        if (func_80101E14(arg0, 0.999f) != 0) {
            func_80800224_chstonedartgunhead(arg0, 3);
            break;
        }
        if (func_80101E14(arg0, 0.052f) != 0) {
            func_80108B04(arg0, 0);
        }
        break;
    case 5:
        if (func_80101E14(arg0, 0.999f) != 0) {
            func_80800224_chstonedartgunhead(arg0, 1);
        }
        break;
    case 6:
        (*(HeadMarker **)arg0)->enabled = 0;
        func_808001B4_chstonedartgunhead(arg0);
        ((HeadData *)arg0->actorData)->tilt += 7.4444447f;
        if (((HeadData *)arg0->actorData)->tilt > 87.0f) {
            ((HeadData *)arg0->actorData)->tilt = 87.0f;
            func_80800224_chstonedartgunhead(arg0, 7);
        }
        break;
    case 7:
        (*(HeadMarker **)arg0)->enabled = 0;
        func_808001B4_chstonedartgunhead(arg0);
        if (arg0->unk58 <= 0.0f) {
            ((HeadData *)arg0->actorData)->tilt -= 1.74f;
            if (((HeadData *)arg0->actorData)->tilt < 0.0f) {
                func_80800224_chstonedartgunhead(arg0, 8);
            }
        }
        break;
    case 8:
        (*(HeadMarker **)arg0)->enabled = 0;
        if (arg0->unk58 <= 0.0f) {
            func_80800224_chstonedartgunhead(arg0, 1);
        }
        break;
    }
    if (((HeadData *)arg0->actorData)->soundTimer > 0) {
        sp34 = func_800F11E4(((HeadData *)arg0->actorData)->tilt, 0, 87.0f, 0.7f, 1.0f);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_80800EAC_chstonedartgunhead);
        _subaddieaudioloop_entrypoint_0(arg0, sp34);
        ((HeadData *)arg0->actorData)->soundTimer = ((HeadData *)arg0->actorData)->soundTimer - func_800D8FF8();
    }
    func_800D9078(&arg0->unk58);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonedartgunhead/func_80800908_chstonedartgunhead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonedartgunhead/func_80800AA4_chstonedartgunhead.s")

/* extern */

void func_80800B6C_chstonedartgunhead(Actor *arg0, void *arg1) {
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);
    s32 var_a1;

    func_800DF744(2, 1);
    func_800DF744(3, 0);
    if ((s32)(arg0->unk0->unk28 << 18) >> 31) {
        var_a1 = 1;
    } else {
        var_a1 = 2;
    }
    func_800DF744(4, var_a1);
    func_80101870(arg0, arg1);
}

OSThread *chstonedartgunhead_entrypoint_0(void)
{
    extern u8 D_80800F10_chstonedartgunhead[];

    return (OSThread *) D_80800F10_chstonedartgunhead;
}

/* extern */

void func_80800BE8_chstonedartgunhead(u8 *arg0) {
    s32 func_800EE7F8(s32, s32, u8 *);
    func_800EE7F8(arg0 + 0x18, arg0 + 4, arg0);
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 4.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonedartgunhead/func_80800C28_chstonedartgunhead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonedartgunhead/func_80800D50_chstonedartgunhead.s")

OSThread *chstonedartgunhead_entrypoint_1(void)
{
    extern u8 D_80800FB0_chstonedartgunhead[];

    return (OSThread *) D_80800FB0_chstonedartgunhead;
}
