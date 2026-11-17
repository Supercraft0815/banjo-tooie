#include "common.h"

void func_80800000_chcanarymarycage(Actor *arg0, s32 arg1) {
    void func_800DA3B8(s32, s32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    void func_800F497C(BtIntPtr);
    void func_800F49A8(BtIntPtr, s32);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4A00(BtIntPtr, s32);
    void func_800F4AC0(BtIntPtr, f32 *, f32);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6438(BtUIntPtr);
    void func_80101FDC(Actor *, u32);
    void func_8010A570(Actor *);
    extern f32 D_80800610_chcanarymarycage[3];
    extern f32 D_8080061C_chcanarymarycage[3];
    void func_8010D5DC(s32, s32);
    f32 position[3];
    s32 limit;

    func_80101FDC(arg0, arg1);
    switch ((int)arg0->unk70_10) {
    case 2:
        break;
    case 3:
        for (arg1 = 0, limit = 8; arg1 != limit; arg1++) {
            if (func_800F6438(arg1)) {
                func_800F5A00(arg1, position);
                if (func_800EFFB4(position, 420.0f, D_80800610_chcanarymarycage)) {
                    func_800F497C(arg1);
                    func_800F49A8(arg1, 1);
                    func_800F4A00(arg1, 1);
                    func_800F49D4(arg1, func_8010D5DC, arg0->unk0);
                    func_800F4AC0(arg1, D_8080061C_chcanarymarycage, 200.0f);
                    arg0->unk79_4++;
                }
            }
        }
        if (arg0->unk79_4 == 0) {
            func_80800000_chcanarymarycage(arg0, 4);
        }
        break;
    case 4:
        func_800DA3B8(0, 1);
        func_8010A570(arg0);
        break;
    }
}

void func_8080018C_chcanarymarycage(Actor *arg0) {
    void func_8008FAC8(f32 *, f32, f32, f32);
    s32 func_8008FB10(f32 *, f32, f32, f32);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_80800000_chcanarymarycage(Actor *, s32);
    switch (arg0->unk70_10) {
    case 1: {
        func_800EEB9C((f32 *)arg0->actorData, arg0->rotation[1] + 180.0f, 60.0f);
        func_800EF04C((f32 *)arg0->actorData, arg0->position);
        func_8008FB10((f32 *)arg0->actorData, 440.0f, 0.0f, 280.0f);
        func_800EEB9C((f32 *)arg0->actorData, arg0->rotation[1], 145.0f);
        func_800EF04C((f32 *)arg0->actorData, arg0->position);
        *(f32 *)&arg0->actorData[1] += 150.0f;
        func_8008FAC8((f32 *)arg0->actorData, 150.0f, 300.0f, 50.0f);
        break;
    }
    case 2:
        func_80800000_chcanarymarycage(arg0, 3);
    case 4:
        break;
    }
}

/* extern */

void func_80800284_chcanarymarycage(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    void _subaddielink_entrypoint_0(void *arg0);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    void func_80800000_chcanarymarycage(Actor *, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0);
    if ((func_800DA298(0x66) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_80800000_chcanarymarycage(arg0, 4);
    }
    _subaddielink_entrypoint_0(sp1C);
}

/* extern */

void func_808002E0_chcanarymarycage(s32 arg0) {
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    s32 func_800DB9B0();
    if ((func_800DB9B0() == 0) && (func_800DA298(1) != 0) && (func_800DA298(0x507) == 0)) {
        func_800DA544(0x66);
        func_800DA544(0x507);
    }
}

void func_80800338_chcanarymarycage(Actor *arg0, s32 *arg1) {
    void _chexploder_entrypoint_4(Actor *arg0, s16 *arg1, s32 arg2);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800DA544(s32 index);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_80800000_chcanarymarycage(Actor *, s32);
    extern s32 D_80800628_chcanarymarycage[16];
    extern s32 D_80800668_chcanarymarycage[3];
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800668_chcanarymarycage);
    func_800EEB9C((f32 *)arg0->actorData, arg0->rotation[1] - 100.0f, 300.0f);
    ((f32 *)arg0->actorData)[1] = 180.0f;
    func_800EF04C((f32 *)arg0->actorData, arg0->position);
    func_800BBCB8((f32 *)arg0->actorData, NULL, 1.0f, 0xA, D_80800628_chcanarymarycage);
    _chexploder_entrypoint_4(arg0, *arg1 + 4, 0x44);
    arg0->unk64_16 = 1;
    func_800DA544(1);
    func_80800000_chcanarymarycage(arg0, 2);
}

s32 func_80800410_chcanarymarycage(Actor *arg0, s32 arg1, s32 *arg2) {
    void _chexploder_entrypoint_6(Actor *arg0, f32 arg1, f32 arg2);
    void _chexploder_entrypoint_9(Actor *arg0, s32 arg1, s32 arg2);
    void _subaddielink_entrypoint_1(u8 *arg0, u8 *arg1);
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 func_80090270(void);
    void func_800DF744(s32, s32);
    void *func_80100094(Actor *, u32);
    void *func_80101080(void);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 func_801015D0(Actor *);
    void func_801018A4(Actor *, BtIntPtr);
    Actor *func_80106790(Unk80132ED0 *);
    void *sp24;
    Actor *sp20;
    Actor *sp1C;

    sp24 = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x90:
            sp20 = func_80106790(func_80101080());
            _chexploder_entrypoint_9(sp20, 1, 0);
            _chexploder_entrypoint_9(sp20, 2, 1);
            _chexploder_entrypoint_9(sp20, 3, 0);
            _chexploder_entrypoint_6(sp20, 200.0f, 300.0f);
            _subaddielink_entrypoint_1(sp24, sp20->unk0);
            break;
        case 0xAB:
            sp1C = _subaddielink_entrypoint_4(sp24);
            func_801018A4(arg0, (BtIntPtr)func_80101080());
            if (sp1C != NULL) {
                func_8010114C((BtIntPtr)sp1C->unk0, 0xAB, 0);
            }
            break;
        case 0x1F:
            func_801015D0(arg0);
            if (arg0->unk70_10 == 1) {
                func_800DF744(1, 1);
            } else {
                func_800DF744(1, 2);
            }
            func_800DF744(2, 0);
            func_800DF744(3, 1);
            break;
        case 0x32:
            arg0->unk79_4--;
            if (arg0->unk79_4 == 0) {
                func_80800000_chcanarymarycage(arg0, 4);
            }
            break;
        case 0x40:
            if (func_80090270() == 0) {
                func_80800338_chcanarymarycage(arg0, *(s32 **)&arg2);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chcanarymarycage_entrypoint_0(void)
{
    extern ActorData D_80800674_chcanarymarycage[];

    return (OSThread *) D_80800674_chcanarymarycage;
}
/* data_to_c.py: from asm/data/overlays/ch/canarymarycage.data.s */
void func_80105834(Actor*);
void func_8010A730();
OSThread *func_80108ED0(void);
void func_80107C2C();
f32 D_80800610_chcanarymarycage [ 3 ] BT_DATA(4, overlays_ch_canarymarycage, 0x0) = { 0.0f, 0.0f, 1592.0f };
f32 D_8080061C_chcanarymarycage [ 3 ] BT_DATA(4, overlays_ch_canarymarycage, 0xC) = { 145.0f, -16.0f, 390.0f };
s32 D_80800628_chcanarymarycage[16] BT_DATA(4, overlays_ch_canarymarycage, 0x18) = { 1903068, 1638401, 402178, 720746, -13041814, 9830450, 9830444, -5242784, -5242800, 14155856, 2228736, 67109376, 50331691, 67110656, 1441796, 0 };
s32 D_80800668_chcanarymarycage[3] BT_DATA(4, overlays_ch_canarymarycage, 0x58) = { 1246408, 1473792, 0 };
ActorData D_80800674_chcanarymarycage [1] BT_DATA(4, overlays_ch_canarymarycage, 0x64) = { { 602, 374, 1661, 1, 0, (void (*)(struct Actor *))func_8080018C_chcanarymarycage, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 163840000, 0, 0, 0, 8, 3076, (void (*)(struct Actor *))func_808002E0_chcanarymarycage, (BtIntPtr)func_80108ED0, 8, 0, (void (*)(struct Actor *))func_80800284_chcanarymarycage, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8192, (void (*)(struct Actor *, long, long))func_80800410_chcanarymarycage, 0 } };
