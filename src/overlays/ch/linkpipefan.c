#include "common.h"

/* extern */

void func_80800000_chlinkpipefan(Actor *arg0) {
    s32 func_800DA298(GameFlag);
    void func_800FFA88(Unk80132ED0 *);
    s32 value;

    value = arg0->unk74_7;
    if (value < 0x33 || value >= 0x3A) {
        func_800FFA88(arg0->unk0);
        value = arg0->unk74_7;
    }
    if (func_800DA298(value + 0x15C) != 0) {
        func_800FFA88(arg0->unk0);
    }
    *(f32 *)&arg0->actorData[7] = 1.5f;
}

void func_80800080_chlinkpipefan(u8 *arg0) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 func_800136E4(f32);
    void func_800C4208(s32, f32, u32, f32 *, f32, f32);
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    s32 func_800D90F8(f32 *, f32);
    s32 func_800D91EC(u8 *, f32);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13C4(f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    BtIntPtr func_801065A4();
    u32 func_8010A654(void ***arg0, s32 arg1);
    void func_808003B4_chlinkpipefan(u8 *, s32);
    extern u32 D_80800910_chlinkpipefan[3];
#ifdef BT_NATIVE
    void chlinkpipefan_entrypoint_0(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    extern s32 _chlinkpipefan_entrypoint_0;
#endif
    struct counter {
        BT_BITFIELD_ORDER(u32 : 23, u32 value : 9);
        BT_BITFIELD_ORDER(u32 value : 9, u32  : 23);
    };

    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 1:
            *(f32 *)(arg0 + 0x4C) = func_800F1FF0(*(f32 *)(arg0 + 0x4C), 0.0f, 0.1f, 0.1f, 3.0f);
            break;
        case 2:
            if (func_800D91EC(arg0 + 0x34, 1.5f)) {
                *(f32 *)(arg0 + 0x54) = 450.0f;
            } else {
                *(f32 *)(arg0 + 0x54) = func_800F10B4(*(f32 *)(arg0 + 0x34), 1.5f, 0, 450.0f, 0);
            }
            break;
        case 3:
            if (func_800D90F8((f32 *)(arg0 + 0x34), 0.75f)) {
                if (func_800D90A4((f32 *)(arg0 + 0x58))) {
                    func_808003B4_chlinkpipefan(arg0, 2);
                }
            } else {
                *(f32 *)(arg0 + 0x54) = func_800F10B4(*(f32 *)(arg0 + 0x34), 1.5f, 0, 450.0f, 0);
            }
            break;
        case 4:
            if (func_800D90A4((f32 *)(arg0 + 0x34))) {
                *(f32 *)(arg0 + 0x54) = 0.0f;
                if (func_800D90A4((f32 *)(arg0 + 0x58))) {
                    func_808003B4_chlinkpipefan(arg0, 2);
                }
            } else {
                *(f32 *)(arg0 + 0x54) = func_800F10B4(*(f32 *)(arg0 + 0x34), 1.5f, 0, 450.0f, 0);
            }
            break;
    }
    *(f32 *)(arg0 + 0x24) = *(f32 *)(arg0 + 0x4C);
    *(f32 *)(arg0 + 0x4C) = func_800136E4(*(f32 *)(arg0 + 0x4C) + *(f32 *)(arg0 + 0x54) * func_800D8FF8());
    if (func_800F13C4(*(f32 *)(arg0 + 0x24), 90.0f) > func_800F13C4(*(f32 *)(arg0 + 0x4C), 90.0f)) {
        if (*(f32 *)(arg0 + 0x54) > 225.0f) {
            func_800C4208(0x3FF, func_800F10B4(*(f32 *)(arg0 + 0x54), 225.0f, 450.0f, 0.3f, 0.6f) + func_800DC178(-0.05f, 0.05f), 0x4A38, (f32 *)(arg0 + 4), 200.0f, 1500.0f);
        }
    }
    if (*(f32 *)(arg0 + 0x54) != 0.0f) {
        _subaddieaudioloop_entrypoint_4((Actor *)arg0, (f32 *)(arg0 + 4), 1, D_80800910_chlinkpipefan);
        _subaddieaudioloop_entrypoint_0((Actor *)arg0, func_800F10B4(*(f32 *)(arg0 + 0x54), 225.0f, 450.0f, 0.4f, 0.8f));
    }
    if (((struct counter *)(arg0 + 0x6C))->value != 0) {
        ((struct counter *)(arg0 + 0x6C))->value--;
    }
    if (func_801065A4(arg0)) {
        _glid_entrypoint_0(func_801065A4(arg0), 1, &_chlinkpipefan_entrypoint_0, *(s32 *)arg0);
    }
    func_8010A654(arg0, ((u32)*(u16 *)(arg0 + 0x72) >> 10) == 4);
}

void func_808003B4_chlinkpipefan(u8 *arg0, s32 arg1) {
    void _chskeletonexplode_entrypoint_7(Actor *, f32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800DA544(GameFlag);
    f32 func_800F13C4(f32, f32);
    void func_80101FDC(Actor *, u32);
    extern s32 D_8080091C_chlinkpipefan[17];
    extern s32 D_80800960_chlinkpipefan[13];
    extern s32 D_80800994_chlinkpipefan[3];
    extern s32 D_808009A0_chlinkpipefan[3];
    Actor *actor = (Actor *)arg0;
    f32 *position;

    switch ((u32)arg1) {
        case 1:
            actor->rotation[2] = func_800F13C4(actor->rotation[2], 90.0f);
            if (actor->rotation[2] > 45.0f) {
                actor->rotation[2] = 90.0f - actor->rotation[2];
            }
            func_800DA544(actor->unk74_7 + 0x15C);
            position = actor->position;
            func_800BBCB8(position, position, 1.0f, 4, D_8080091C_chlinkpipefan);
            func_800BBCB8(position, position, 1.0f, 10, D_80800960_chlinkpipefan);
            _subaddieaudioquick_entrypoint_2(actor, position, D_80800994_chlinkpipefan);
            _chskeletonexplode_entrypoint_7(actor, position);
            break;
        case 2:
            func_80101FDC(actor, arg1);
            break;
        case 3:
            func_80101FDC(actor, arg1);
            actor->unk58 = 5.0f;
            break;
        case 4:
            actor->unk58 = 5.0f;
            if (actor->unk70_10 != 4) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808009A0_chlinkpipefan);
                func_80101FDC(actor, arg1);
            }
            break;
    }
}

/* extern */

void chlinkpipefan_entrypoint_0(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, Unk80132ED0 *arg4) {
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 temp_f0;
    u8 *temp_v0;
    u8 alpha;

    temp_f0 = func_800F12D4(func_80106790(arg4)->unk54, 225.0f, 450.0f, 0.0, 255.0f);
    temp_v0 = (arg3 * 0x10) + arg2;
    if (arg2 < temp_v0) {
        alpha = (u32)temp_f0;
        do {
            arg2 += 0x10;
            arg2[-1] = alpha;
        } while (arg2 < temp_v0);
    }
}

s32 func_80800638_chlinkpipefan(Actor *arg0, u32 arg1, Unk80132ED0 *volatile arg2) {
    void _chskeletonexplode_entrypoint_3(Actor *, s32, s32);
    void _chskeletonexplode_entrypoint_4(Actor *, s32);
    void _chskeletonexplode_entrypoint_5(Actor *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800DF6BC(s32, s32);
    void func_800DF744(s32, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F79DC(BtIntPtr, s32, BtIntPtr);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80101080(void);
    s32 func_801015D0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_808009AC_chlinkpipefan[3];
    extern s32 D_808009B8_chlinkpipefan[4];
    Actor *sp2C;

    switch (arg1) {
        case 0x3E:
            if (arg0->unk70_10 != 4) {
                if (15 == (arg0->unk0->unk18 << 11) >> 28) {
                    func_800F79DC(func_800F54E4(), 6, (BtIntPtr)arg0->unk0);
                    return 1;
                }
                if (((arg0->unk0->unk18 << 11) >> 28) == 1) {
                    func_800F79DC(func_800F54E4(), 3, (BtIntPtr)arg0->unk0);
                }
            }
            return 1;
        case 0x3F:
            if (func_80106790(arg2)->unk6C_9 == 0x15C) {
                func_808003B4_chlinkpipefan((u8 *)arg0, 4);
            } else if (((arg0->unk0->unk18 << 11) >> 28) == 1 && arg0->unk70_10 != 4) {
                func_808003B4_chlinkpipefan((u8 *)arg0, 3);
            }
            if (!arg0->unk6C_0) {
                if (arg0->unk70_10 == 4) {
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808009B8_chlinkpipefan);
                } else {
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808009AC_chlinkpipefan);
                }
            }
            arg0->unk6C_0 = 8;
            return 1;
        case 0x40:
            if (arg0->unk70_10 == 4 && arg0->unk54 <= 45.0f) {
                func_808003B4_chlinkpipefan((u8 *)arg0, 1);
            }
            return 1;
        case 0x1F:
            func_801015D0(arg0);
            func_800DF6BC((s32)func_800F10B4(arg0->unk54, 0.0f, 225.0f, 255.0f, 0.0f), 255);
            func_800DF744(1, 1);
            return 1;
        case 0xF:
            sp2C = func_80106790(func_80101080());
            _chskeletonexplode_entrypoint_3(sp2C, 1, 0);
            _chskeletonexplode_entrypoint_4(sp2C, 7);
            _chskeletonexplode_entrypoint_5(sp2C, (s32)func_800F10B4(arg0->unk54, 0.0f, 225.0f, 255.0f, 0.0f));
            func_800FFA88(arg0->unk0);
            return 1;
        default:
            return 0;
    }
}

OSThread *chlinkpipefan_entrypoint_1(void)
{
    extern ActorData D_808009C8_chlinkpipefan[];

    return (OSThread *) D_808009C8_chlinkpipefan;
}
/* data_to_c.py: from asm/data/overlays/ch/linkpipefan.data.s */
void func_80105834(Actor*);
void func_801018A4();
OSThread *func_80108ED0(void);
void func_80107C2C();
u32 D_80800910_chlinkpipefan[3] BT_DATA(4, overlays_ch_linkpipefan, 0x0) = { 0x1304A9, 0x165DC0, 0x1B0000 };
s32 D_8080091C_chlinkpipefan[17] BT_DATA(4, overlays_ch_linkpipefan, 0xC) = { 1903069, 2819072, 100663330, 33555072, 100665344, 1376256, 2490393, 7, 2949100, 1376236, 1310760, 1310752, 1616928896, 720876, -3211284, 1310770, 1310720 };
s32 D_80800960_chlinkpipefan[13] BT_DATA(4, overlays_ch_linkpipefan, 0x50) = { 1903065, 1769672, 26214414, 3276950, 1376256, 16580651, 67110400, 2154206, -2228190, 786457, 1638438, 2949320, 26214400 };
s32 D_80800994_chlinkpipefan[3] BT_DATA(4, overlays_ch_linkpipefan, 0x84) = { 1246408, 1469792, 1769472 };
s32 D_808009A0_chlinkpipefan[3] BT_DATA(4, overlays_ch_linkpipefan, 0x90) = { 1246507, 1461792, 1769472 };
s32 D_808009AC_chlinkpipefan[3] BT_DATA(4, overlays_ch_linkpipefan, 0x9C) = { 1246368, 1469792, 1769472 };
s32 D_808009B8_chlinkpipefan[4] BT_DATA(4, overlays_ch_linkpipefan, 0xA8) = { 1246534, 655488, 1469792, 1769472 };
ActorData D_808009C8_chlinkpipefan [1] BT_DATA(4, overlays_ch_linkpipefan, 0xB8) = { { 307, 668, 1777, 2, 0, (void (*)(struct Actor *))func_80800080_chlinkpipefan, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 393216000, 0, 0, 0, 130, 4096, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chlinkpipefan, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1024, (void (*)(struct Actor *, long, long))func_80800638_chlinkpipefan, 0 } };
