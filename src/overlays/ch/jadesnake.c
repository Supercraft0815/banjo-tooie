#include "common.h"

void func_80800000_chjadesnake(Actor *arg0) {
    void func_8010A85C(u8 *, s32);
    func_8010A85C((u8 *) arg0, 2);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 9);
        func_8010A85C((u8 *) arg0, 1);
    }
}

void func_80800048_chjadesnake(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    extern u32 D_80800938_chjadesnake[];

    func_800D1000(0xA, 1, (f32 *)&arg0->actorData[4], 3, arg0->unk0);
    _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], D_80800938_chjadesnake);
}

/* extern */

int func_8080009C_chjadesnake(BtIntPtr arg0) {
    s32 pad;
    u32 func_800F54E4(void);
    s32 func_800F56AC(BtIntPtr);
    s32 func_800F6478(BtIntPtr);
    s32 func_800F651C(BtIntPtr);
    s32 func_800F6C5C(BtIntPtr);
    int func_800F72DC(BtIntPtr);
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 temp_t8;
    s32 temp_t9;
    BtIntPtr temp_v0;
    s32 var_v0;

    temp_v0 = func_800F54E4();
    sp30 = func_800F651C(temp_v0);
    sp2C = func_800F6C5C(temp_v0);
    sp28 = func_800F72DC(temp_v0);
    sp24 = func_800F56AC(temp_v0) == 0x10;
    var_v0 = func_800F6478(temp_v0);
    if (sp24 == 0) {
        return 0;
    }
    return var_v0 && (sp28 || (sp2C && !sp30));
}

void func_80800150_chjadesnake(Actor *arg0) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _capod_entrypoint_14(void);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_80090708(s32);
    void func_80090734(s32, f32 *);
    void func_800C4B7C(s32);
    Unk80132ED0 *func_800D0634(u32, u32);
    s32 func_800D0A9C(u32, u32);
    s32 func_800D0B68(u32, u32);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    void func_800D119C(u32, u32);
    s32 func_800DA298(GameFlag);
    void func_800DA544(GameFlag);
    s32 func_800DA9E4(GameFlag, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    u32 func_800F54E4(void);
    s32 func_800F56AC(BtIntPtr);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    void func_80101EE4(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80102FE8(void *, s32);
    void func_80103014(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A85C(u8 *, s32);
    void func_8010D254(f32 *);
    void func_80800048_chjadesnake(Actor *);
    extern u32 D_80800910_chjadesnake[];
    extern u32 D_80800920_chjadesnake[];
    extern u32 D_8080092C_chjadesnake[];
    extern u32 D_80800948_chjadesnake[];
    extern u32 D_80800958_chjadesnake[];
    extern u32 D_80800964_chjadesnake[];
    extern f32 D_808009C0_chjadesnake[];
    extern u32 D_808009DC_chjadesnake[];
    f32 sp54[3];
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    f32 sp44;
    f32 sp38[3];
    Actor *sp34;

    sp50 = func_800D0B68(0xA, 1);
    sp4C = func_800D0A9C(0xA, 1);
    func_8010D254(sp54);
    switch (arg0->unk70_10) {
        case 1:
            if (arg0->unk7C_12 && !sp50 && !sp4C) {
                func_800D1000(0xA, 1, (f32 *)arg0->actorData, 3, arg0->unk0);
            }
            sp48 = func_80101E4C(arg0, D_808009C0_chjadesnake);
            if (sp48) {
                func_800C4B7C((sp48 & 1) ? 0x5C6 : 0x5C7);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800964_chjadesnake);
            }
            if (!sp50 && sp4C && func_8080009C_chjadesnake((BtIntPtr)arg0)) {
                _subaddieaudioquick_entrypoint_2(arg0, sp54, D_80800910_chjadesnake);
                func_80090734(2, arg0->position);
                func_8010A85C((u8 *)arg0, 1);
                func_80102424(arg0, 2);
                if (!func_800DA9E4(0x677, 1)) {
                    arg0->unk64_20 = 1;
                    _capod_entrypoint_13(arg0->unk0, NULL, 2, 0x10);
                } else {
                    arg0->unk64_20 = 0;
                }
            }
            break;
        case 2:
            if (sp50) {
                func_8010A85C((u8 *)arg0, 2);
                func_80102424(arg0, 1);
                func_80090708(0);
            }
            if (func_80101E14(arg0, 0.73f)) {
                func_800D119C(0xA, 1);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080092C_chjadesnake);
            }
            if (func_80101DDC(arg0)) {
                if (func_800DA298(0x434)) {
                    func_80102424(arg0, 3);
                    func_80090708(0);
                } else {
                    func_800DA544(0x434);
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0xF3C, 0xC, arg0->position, 0x46);
                    func_80102424(arg0, 5);
                }
            }
            break;
        case 6:
            _capod_entrypoint_14();
            func_80090708(0);
            func_80102424(arg0, 3);
            break;
        case 3:
            sp44 = func_80101F24(arg0);
            func_8010D254(sp38);
            if (func_800F56AC(func_800F54E4()) != 0x10 && sp38[1] < 1160.0f) {
                func_80102424(arg0, 4);
                if (arg0->unk64_20) {
                    _capod_entrypoint_13(arg0->unk0, NULL, 0, 0x10);
                }
            }
            if (sp44 > 0.13f && sp44 < 0.64f) {
                _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800948_chjadesnake);
            }
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80800958_chjadesnake, D_808009DC_chjadesnake);
            break;
        case 4:
            if (func_80101E14(arg0, 0.18f) && !sp4C) {
                if (func_800DA298(0x435)) {
                    func_80800048_chjadesnake(arg0);
                } else {
                    func_800DA544(0x435);
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0xF3D, 0xC, arg0->position, 0x46);
                    func_80102424(arg0, 7);
                }
            }
            if (func_80101DDC(arg0)) {
                if (!func_800DA298(0x435)) {
                    func_80102424(arg0, 7);
                } else {
                    func_8010A85C((u8 *)arg0, 2);
                    func_80102424(arg0, 1);
                }
            }
            if (!sp50 && sp4C && func_8080009C_chjadesnake((BtIntPtr)arg0)) {
                _subaddieaudioquick_entrypoint_2(arg0, sp54, D_80800910_chjadesnake);
                func_80090734(2, arg0->position);
                func_8010A85C((u8 *)arg0, 1);
                func_80102424(arg0, 2);
                func_80101EE4(arg0, 0.57f);
            }
            break;
        case 7:
            if (!sp4C) {
                func_80800048_chjadesnake(arg0);
            }
            break;
        case 8:
            if (func_80101DDC(arg0)) {
                if (sp4C) {
                    func_8010A85C((u8 *)arg0, 2);
                    func_80102424(arg0, 1);
                } else {
                    func_80800048_chjadesnake(arg0);
                    func_80090708(0);
                    func_80102424(arg0, 4);
                }
            }
            break;
    }
    if (arg0->unk6C_0 && func_800D0634(0xA, 1)) {
        sp34 = func_80106790(func_800D0634(0xA, 1));
        func_800EF04C(sp34->position, (f32 *)&sp34->actorData[4]);
        arg0->unk6C_0--;
        if (arg0->unk6C_0 == 2) {
            _subaddieaudioquick_entrypoint_2(sp34, sp34->position, D_80800920_chjadesnake);
        } else if (!arg0->unk6C_0) {
            func_800EE7F8(sp34->position, (f32 *)arg0->actorData);
            func_80102FE8(sp34, 1);
            func_80103014(sp34);
        }
    }
}

void func_80800728_chjadesnake(Actor *arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0xF3C) {
        if (arg1 == 0xF3D) {
            func_80102424(arg0, 8);
        }
    } else {
        func_80102424(arg0, 6);
    }
}

void func_80800770_chjadesnake(Actor *arg0, u8 *arg1) {
    void func_800DBEFC(void *data,s32 index,f32 *out);
    void func_80101870(Actor* arg0, void* arg1);
    OSThread * func_80104130(void);
    func_80101870(arg0, arg1);
    if (((struct { BT_BITFIELD_ORDER(u32 unused : 19, u32 rest : 12); u32 active : 1; BT_BITFIELD_ORDER(u32 rest : 12, u32 unused : 19); } *)((u8 *)arg0 + 0x7C))->active) {
        func_800DBEFC(func_80104130(), 4, (BtIntPtr) arg0->actorData);
        func_800DBEFC(func_80104130(), 5, (BtIntPtr) &arg0->actorData[4]);
    }
}

s32 func_808007DC_chjadesnake(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    void func_800EFB24(void *, void *, void *);
    void func_800EF334(f32 *, f32);
    void func_80102FE8(void *, s32);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    extern s32 D_808009E4_chjadesnake[4];
    Actor *sp1C;

    switch (arg1) {
        case 0xD:
            switch (arg0->unk70_10) {
                default:
                    sp1C = func_80106790(func_80101080());
                    func_800EFB24(&sp1C->actorData[4], arg0->actorData, &arg0->actorData[4]);
                    func_800EF334((f32 *)&sp1C->actorData[4], 1.0f / 7.0f);
                    arg0->unk6C_0 = 7;
                    func_80102FE8(sp1C, 0);
                    break;
                case 1:
                    break;
            }
            break;
        case 0x2E:
            func_80800728_chjadesnake(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808009E4_chjadesnake, arg0->scale);
            return 1;
        default:
            return 0;
    }
    return 1;
}

OSThread *chjadesnake_entrypoint_0(void)
{
    extern ActorData D_808009F4_chjadesnake[];

    return (OSThread *) D_808009F4_chjadesnake;
}
/* data_to_c.py: from asm/data/overlays/ch/jadesnake.data.s */
extern u8 D_80800970_chjadesnake[];
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
u32 D_80800910_chjadesnake [4] BT_DATA(4, overlays_ch_jadesnake, 0x0) = { 0x1304AA, 0xD00F3, 0x10C0016, 0x79180000 };
u32 D_80800920_chjadesnake [3] BT_DATA(4, overlays_ch_jadesnake, 0x10) = { 0x1303E9, 0x165208, 0 };
u32 D_8080092C_chjadesnake [3] BT_DATA(4, overlays_ch_jadesnake, 0x1C) = { 0x1304A4, 0x167918, 0 };
u32 D_80800938_chjadesnake [4] BT_DATA(4, overlays_ch_jadesnake, 0x28) = { 0x130430, 0xA0133, 0x167918, 0 };
u32 D_80800948_chjadesnake [4] BT_DATA(4, overlays_ch_jadesnake, 0x38) = { 0x13051F, 0x165DC0, 0x101F4, 0x13880000 };
u32 D_80800958_chjadesnake [3] BT_DATA(4, overlays_ch_jadesnake, 0x48) = { 0x13051E, 0x165DC0, 0 };
u32 D_80800964_chjadesnake [3] BT_DATA(4, overlays_ch_jadesnake, 0x54) = { 0x21000D, 0x1260140, 0 };
u8 D_80800970_chjadesnake[80] BT_DATA(4, overlays_ch_jadesnake, 0x60) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x10, 0x00, 0x00, 0x01, 0x93, 0x00, 0x01, 0x3F, 0xB3, 0x33, 0x33, 0x01, 0x94, 0x00, 0x02, 0x41, 0x00, 0x00, 0x00, 0x01, 0x95, 0x00, 0x01, 0x40, 0xAB, 0x85, 0x1F, 0x01, 0x96, 0x00, 0x02, 0x41, 0x00, 0x00, 0x00, 0x01, 0x95, 0x00, 0x01, 0x41, 0x00, 0x00, 0x00, 0x01, 0x95, 0x00, 0x01, 0x40, 0xAB, 0x85, 0x1F, 0x01, 0x96, 0x00, 0x02, 0x40, 0xAB, 0x85, 0x1F, 0x01, 0x96, 0x00, 0x02, 0x41, 0x00, 0x00, 0x00, 0x01, 0x95, 0x00, 0x01 };
f32 D_808009C0_chjadesnake [7] BT_DATA(4, overlays_ch_jadesnake, 0xB0) = { 0.1f, 0.25f, 0.4f, 0.55f, 0.75f, 0.9f, -1.0f };
u32 D_808009DC_chjadesnake [2] BT_DATA(4, overlays_ch_jadesnake, 0xCC) = { 0x3F23D70A, 0xBF800000 };
s32 D_808009E4_chjadesnake[4] BT_DATA(4, overlays_ch_jadesnake, 0xD4) = { 1136525312, 0, 1132920832, 0 };
ActorData D_808009F4_chjadesnake [1] BT_DATA(4, overlays_ch_jadesnake, 0xE4) = { { 340, 268, 1631, 1, (void *)D_80800970_chjadesnake, (void (*)(struct Actor *))func_80800150_chjadesnake, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800770_chjadesnake, 0, 0, 0, 0, 8, 46, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chjadesnake, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8192, (void (*)(struct Actor *, long, long))func_808007DC_chjadesnake, 0 } };
