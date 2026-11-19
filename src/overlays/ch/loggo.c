#include "common.h"

OSThread *chloggo_entrypoint_0(void)
{
    extern ActorData D_80800648_chloggo[];

    return (OSThread *) D_80800648_chloggo;
}

OSThread *chloggo_entrypoint_1(void)
{
    extern ActorData D_80800690_chloggo[];

    return (OSThread *) D_80800690_chloggo;
}

/* extern */

void func_80800018_chloggo(BtIntPtr arg0) {
    void *_gccubesearch_entrypoint_0(s32 actor_id, Actor *actor);
    s32 _glcutDll_entrypoint_20();
    s32 func_800D0A9C(u32, u32);
    s32 func_800DA298(s32);
    void func_800EE88C(f32 dst[3], s16 src[3]);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    s32 func_8010A5B0(BtIntPtr, s32);
    func_800EE88C(arg0 + 0x18, _gccubesearch_entrypoint_0(0x201, arg0));
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 4);
        return;
    }
    if (func_800D0A9C(0x10, 4) != 0) {
        func_8010A570(arg0);
        return;
    }
    func_8010A5B0(arg0, func_800DA298(0x169));
}

void func_808000AC_chloggo(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    s32 func_800D0A9C(u32, u32);
    s32 func_800F52B8(BtIntPtr, Unk80132ED0 *);
    u32 func_800F54E4(void);
    void func_80800398_chloggo(Actor *);
    void func_80800460_chloggo(Actor *);
    extern s32 D_808005E0_chloggo[];
    extern s32 D_80800610_chloggo[];
    extern s32 D_808006D8_chloggo[];

    switch (arg0->unk70_10) {
        case 1:
            func_80800460_chloggo(arg0);
            if (func_800D0A9C(0x10, 4) != 0) {
                _subaddiedialog_entrypoint_8(arg0, arg0->position, D_808006D8_chloggo, D_80800610_chloggo, 2);
            } else {
                _subaddiedialog_entrypoint_8(arg0, arg0->position, D_808006D8_chloggo, D_808005E0_chloggo, 6);
            }
            break;
        case 2:
        case 4:
            func_80800460_chloggo(arg0);
            break;
        case 3:
            if (func_800F52B8(func_800F54E4(), arg0->unk0) != 0xB) {
                func_80800398_chloggo(arg0);
            }
            break;
    }
    *(u8 *)&arg0->pad94 &= ~0x40;
}

s32 func_808001B8_chloggo(Actor *arg0, s32 arg1, void *arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _capod_entrypoint_14(void);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    u8 _subaddiedialog_entrypoint_9(void *arg0, s32 arg1, void *arg2, s32 arg3);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4);
    s32 func_800F52B8(BtIntPtr, Unk80132ED0 *);
    void func_80102424(Actor *, s32);
    void func_8010A590(Actor *);
    void func_80800398_chloggo(Actor *);
    extern s32 D_808005E0_chloggo[];
    extern s32 D_808006E8_chloggo[];
    Unk80132ED0 *temp;

    switch (arg1) {
        case 0x2E:
            switch (*(s16 *)&arg2) {
                case 0x1343:
                case 0x1380:
                    func_800D1000(0x10, 4, (s32 *)arg0->actorData, 1, 0);
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808006E8_chloggo);
                    _capod_entrypoint_14();
                    _capod_entrypoint_13(arg0->unk0, NULL, 6, 0x2030);
                    break;
                case 0x1367:
                    _capod_entrypoint_14();
                    func_80102424(arg0, 1);
                    break;
                default:
                    if (_subaddiedialog_entrypoint_9((BtIntPtr)arg0, *(s16 *)&arg2, D_808005E0_chloggo, 6) == 1) {
                        func_8010A590(arg0);
                    }
                    func_80102424(arg0, 1);
                    break;
            }
            break;
        case 0x3E:
            temp = arg2;
            if (((u16 *)&temp->unk18)[0] & 1) {
                return 0;
            }
            if (func_800F52B8((u32)((u16 *)&temp->unk18)[1] >> 5, arg0->unk0) == 0xB && arg0->unk70_10 != 3) {
                func_80102424(arg0, 3);
            }
            break;
        case 0x40:
            func_80800398_chloggo(arg0);
            break;
        case 0xB:
            if (arg2 == (void *)6) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1367, 6, arg0->position, 0xAD);
            }
            return 3;
        case 0x91:
            *(u8 *)&arg0->pad94 = (u8)((*(u8 *)&arg0->pad94 & ~0x40) | 0x40);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800398_chloggo(Actor *arg0) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_800F77E8(BtIntPtr, f32 *);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    f32 sp34[3];
    s32 dialog;
    BtIntPtr sp2C;

    sp2C = func_800F54E4();
    func_800EE7F8(sp34, arg0->position);
    func_800EF1B8(sp34, arg0->rotation[1] - 40.0f, 200.0f);
    func_800F77E8(sp2C, sp34);
    if (func_800F64A4(sp2C, 0x201) != 0) {
        dialog = 0x1343;
    } else {
        dialog = 0x1380;
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 6, arg0->position, 0xAD);
    func_80102424(arg0, 2);
    func_8010A570(arg0);
    _capod_entrypoint_13(arg0->unk0, NULL, 3, 0x30);
}

void func_80800460_chloggo(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    extern u32 D_808006F8_chloggo[6];
    extern u32 D_80800710_chloggo[6];
    extern u32 D_80800728_chloggo[6];
    extern u32 D_80800740_chloggo[8];
    f32 *temp_s1;

    temp_s1 = &arg0->position[0];
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_808006F8_chloggo, 0.09f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80800740_chloggo, 0.16f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80800710_chloggo, 0.22f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80800728_chloggo, 0.6f);
}

/* extern */

void func_808004F8_chloggo(BtIntPtr arg0) {
    s32 _glcutDll_entrypoint_20();
    void func_800FFAB0(Actor *actor);
    if (_glcutDll_entrypoint_20() != 0) {
        func_800FFAB0(arg0);
    }
}

int func_80800528_chloggo(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _chexploder_entrypoint_13(BtIntPtr, u32);
    void func_800DA544(GameFlag);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    f32 sp24[3];

    switch (arg1) {
    case 0x40:
        func_800EE7F8(sp24, arg0->position);
        func_800EF1B8(sp24, arg0->rotation[1], -200.0f);
        _chexploder_entrypoint_3(arg0, sp24, 0xF);
        func_800DA544(0x181);
        break;
    case 0x90:
        _chexploder_entrypoint_13(func_80106790(func_80101080()), 1);
        break;
    default:
        return 0;
    }
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/loggo.data.s */
extern u8 D_80800620_chloggo[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
void func_80102EC0();
s32 D_808005E0_chloggo [12] BT_DATA(4, overlays_ch_loggo, 0x0) = { 1, 323027200, 1025, 323092992, 512, 327221504, 512, 327352832, 1024, 327287040, -73729, 302711552 };
s32 D_80800610_chloggo [4] BT_DATA(4, overlays_ch_loggo, 0x30) = { 1537, 325583360, -73729, 302711552 };
u8 D_80800620_chloggo[40] BT_DATA(4, overlays_ch_loggo, 0x40) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x4C, 0xCC, 0xCD, 0x02, 0x38, 0x00, 0x00, 0x3F, 0x4C, 0xCC, 0xCD, 0x02, 0x38, 0x00, 0x00, 0x3F, 0x4C, 0xCC, 0xCD, 0x02, 0x38, 0x00, 0x00, 0x3F, 0x4C, 0xCC, 0xCD, 0x02, 0x38, 0x00, 0x00 };
ActorData D_80800648_chloggo [1] BT_DATA(4, overlays_ch_loggo, 0x68) = { { 173, 1077, 1598, 1, (void *)D_80800620_chloggo, (void (*)(struct Actor *))func_808000AC_chloggo, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 1075838976, 0, 0, 16384, 2316, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800018_chloggo, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9362, (void (*)(struct Actor *, long, long))func_808001B8_chloggo, 0 } };
ActorData D_80800690_chloggo [1] BT_DATA(4, overlays_ch_loggo, 0xB0) = { { 342, 1078, 1967, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 385, 0, 16384, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808004F8_chloggo, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 10256, (void (*)(struct Actor *, long, long))func_80800528_chloggo, 0 } };
s32 D_808006D8_chloggo [4] BT_DATA(4, overlays_ch_loggo, 0xF8) = { 23658496, 19660973, 12, 37487104 };
s32 D_808006E8_chloggo [4] BT_DATA(4, overlays_ch_loggo, 0x108) = { 1246251, 655488, 1572866, 0 };
u32 D_808006F8_chloggo[6] BT_DATA(4, overlays_ch_loggo, 0x118) = { 0x130627, 0x10190, 0x3E8000D, 0xF3010C, 0x1655F0, 0 };
u32 D_80800710_chloggo[6] BT_DATA(4, overlays_ch_loggo, 0x130) = { 0x1305C1, 0x10190, 0x3E8000D, 0x1A601C0, 0x162EE0, 0 };
u32 D_80800728_chloggo[6] BT_DATA(4, overlays_ch_loggo, 0x148) = { 0x130555, 0x10190, 0x3E8000D, 0xF3010C, 0x161F40, 0 };
u32 D_80800740_chloggo[8] BT_DATA(4, overlays_ch_loggo, 0x160) = { 0x130556, 0x10190, 0x3E8000D, 0xF3010C, 0x161F40, 0, 0, 0 };
