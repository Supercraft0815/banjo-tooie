#include "common.h"

void func_80800000_chbkcart(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(BtIntPtr arg0, void *arg1, f32 *arg2);
    s32 func_800D1A04(s32);
    s32 func_800DA298(s32);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);

    switch (arg0->unk74_7 - 0x32) {
        case 0:
            if (func_800D1A04(0x53) || func_800DA298(0x3E2)) {
                func_800FFA88(arg0->unk0);
                return;
            }
            break;
        case 1:
            if (func_800DA298(0x3E3) || func_800DA298(0x3E4)) {
                func_800FFA88(arg0->unk0);
                return;
            }
            break;
        case 2:
            if (func_800DA298(0x3E5) || func_800DA298(0x3E6)) {
                func_800FFA88(arg0->unk0);
                return;
            }
            break;
    }
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0), arg0->position);
    if (!func_800DA298(0x342)) {
        func_80102424(arg0, 1);
    } else {
        func_80102424(arg0, 2);
    }
}
typedef struct Vec3s32 { f32 x, y, z; } Vec3s32;
void func_80800130_chbkcart(Actor *arg0) {



    typedef struct {
        f32 unused[3];
        f32 speed;
        f32 route;
        f32 targetSpeed;
    } CartData;
    typedef struct {
        u32 unused;
        u16 unused4;
        u16 node;
    } CartRoute;
    typedef struct {
        BT_BITFIELD_ORDER(u32 unused : 29, u32 unused2 : 2);
        u32 stopped : 1;
        BT_BITFIELD_ORDER(u32 unused2 : 2, u32 unused : 29);
    } CartFlags;
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void _subaddiefade_entrypoint_3(Actor *);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
    s32 _subaddierouteDll_entrypoint_6(Actor *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6);
    s32 _subaddierouteDll_entrypoint_7(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
    void func_800C4140(u32, f32 *, u32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F3780(f32, u8 *, s16);
    BtUIntPtr func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    void func_80102424(Actor *, s32);
    void func_801026CC(Actor *, Vec3s32, f32);
    s32 func_8010C3A8(Actor *, u32, f32);
    s32 func_8010C500(Actor *);
    s32 func_8010C710(Actor *);
    s32 func_8010CA74(f32 *, u32);
    s32 func_8010CB84(f32 *, u32);
    f32 func_8010CD50(Actor *, BtUIntPtr);
    void func_8010CEAC(Actor *);
    extern u8 D_80800828_chbkcart[];
    extern f32 D_80800858_chbkcart[];
    extern Vec3s32 D_80800864_chbkcart;
    CartRoute *route;

    route = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 1:
            if (func_8010CA74(arg0->position, 600) && !arg0->unk74_30) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x154B, 0xF, arg0->position, 0x6F);
                arg0->unk74_30 = 1;
            }
            func_8010CEAC(arg0);
            if (func_800DA298(0x342)) {
                func_80102424(arg0, 2);
            }
            break;
        case 2:
            if (!((CartFlags *)&arg0->unk78)->stopped) {
                if (_subaddierouteDll_entrypoint_4(arg0)) {
                    if (func_8010C500(arg0) || (f32)func_8010C710(arg0) < 1000000.0f) {
                        arg0->unk54 = func_8010CD50(arg0, func_800F54E4()) - 180.0f;
                    } else {
                        _subaddierouteDll_entrypoint_6(arg0, route, (s32)((CartData *)arg0->actorData)->route, 0x3F, 0.4f, 20, 40);
                    }
                    _subaddierouteDll_entrypoint_7(arg0, route, arg0->rotation[1], arg0->unk54, 200.0f, 0x4803);
                    ((CartData *)arg0->actorData)->route = (u32)route->node;
                }
                _subaddierouteDll_entrypoint_5(arg0, route, (s32)((CartData *)arg0->actorData)->route, 0.15f, 8.0f, 200.0f);
                if (func_8010CB84(arg0->position, 1500)) {
                    ((CartData *)arg0->actorData)->targetSpeed = 400.0f;
                } else {
                    ((CartData *)arg0->actorData)->targetSpeed = 150.0f;
                }
                ((CartData *)arg0->actorData)->speed = func_800F15F8(((CartData *)arg0->actorData)->speed, ((CartData *)arg0->actorData)->targetSpeed, func_800D8FF8() * 300.0f);
                func_801026CC(arg0, D_80800864_chbkcart, ((CartData *)arg0->actorData)->speed);
                func_8010C3A8(arg0, 0x305425, func_800F3780(func_80101F24(arg0), D_80800828_chbkcart, 6));
                if (func_80101E4C(arg0, D_80800858_chbkcart)) {
                    func_800C4140(0xBFCFA447, arg0->position, 0x04B000FA);
                }
            }
            break;
        case 3:
            if (func_80101E14(arg0, 0.58f)) {
                func_800C4140(0xBFD77447, arg0->position, 0x04B000FA);
            } else if (func_80101DDC(arg0)) {
                func_80102424(arg0, 2);
            }
            break;
        case 4:
            if (func_80101E14(arg0, 0.58f)) {
                func_800C4140(0xBFD77447, arg0->position, 0x04B000FA);
            } else if (func_80101DDC(arg0)) {
                _subaddiefade_entrypoint_3(arg0);
            }
            break;
    }
}

s32 func_808004DC_chbkcart(Actor *arg0, s32 arg1, s32 arg2) {
    void _chbounce_entrypoint_3(f32);
    Actor *_chbounce_entrypoint_5(BtIntPtr, Actor *);
    Actor *_chbounce_entrypoint_7(BtIntPtr, f32 *, s32);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void _gcdialogcamera_entrypoint_4(BtIntPtr arg0);
    void _subaddierouteDll_entrypoint_1(Actor *);
    void func_800C4140(u32, f32 *, u32);
    void func_800DA544(GameFlag);
    BtUIntPtr func_800F54E4(void);
    void func_80102424(Actor *, s32);
    s32 func_80103140(Actor *, u32, u16);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    f32 func_8010CD50(Actor *, BtUIntPtr);
    extern s32 D_80800870_chbkcart[4];
    struct CartFlags {
        BT_BITFIELD_ORDER(u32 unused : 29, u32 unused2 : 2);
        u32 active : 1;
        BT_BITFIELD_ORDER(u32 unused2 : 2, u32 unused : 29);
    };
    Actor *sp24;

    switch (arg1) {
        case 0x40:
            if (!((struct CartFlags *)&arg0->unk78)->active) {
                func_80102424(arg0, 4);
                _chbounce_entrypoint_3(func_8010CD50(arg0, func_800F54E4()) + 210.0f);
                arg0 = _chbounce_entrypoint_5(0x13, arg0);
                func_80108B04(arg0, 0);
                func_8010A570(arg0);
                func_800C4140(0x7FFB5C16, arg0->position, 0x04B000FA);
            }
            return 1;
        case 0x3F:
            if (!((struct CartFlags *)&arg0->unk78)->active) {
                func_80102424(arg0, 3);
                func_800C4140(0x7FFB5C16, arg0->position, 0x04B000FA);
            }
            return 1;
        case 0x95:
            _subaddierouteDll_entrypoint_1(arg0);
            return 1;
        case 0x3D:
            _chbounce_entrypoint_3(func_8010CD50(arg0, func_800F54E4()) + 150.0f);
            switch (arg0->unk74_7 - 0x32) {
                case 0:
                    sp24 = _chbounce_entrypoint_7(0x14, arg0->position, 0x513);
                    sp24->rotation[0] = 90.0f;
                    sp24->scale = 0.5f;
                    break;
                case 1:
                    sp24 = _chbounce_entrypoint_7(0x12, arg0->position, 0x517);
                    func_80103140(sp24, 0x975, arg0->unk0->unk16);
                    func_80102424(sp24, 1);
                    break;
                case 2:
                    sp24 = _chbounce_entrypoint_7(0x12, arg0->position, 0x517);
                    func_80103140(sp24, 0x974, arg0->unk0->unk16);
                    func_80102424(sp24, 1);
                    break;
            }
            func_8010A590(sp24);
            return 1;
        case 0x2E:
            func_800DA544(0x342);
            func_80102424(arg0, 2);
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_3(D_80800870_chbkcart, arg0->scale);
            return 3;
        default:
            return 0;
    }
}

OSThread *chbkcart_entrypoint_0(void)
{
    extern ActorData D_80800880_chbkcart[];

    return (OSThread *) D_80800880_chbkcart;
}
/* data_to_c.py: from asm/data/overlays/ch/bkcart.data.s */
extern u8 D_80800800_chbkcart[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80108ED0();
void func_80107C2C();
u8 D_80800800_chbkcart[40] BT_DATA(4, overlays_ch_bkcart, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x04, 0x9F, 0x00, 0x44, 0x3F, 0x40, 0x00, 0x00, 0x04, 0x9E, 0x00, 0x00, 0x3F, 0xC0, 0x00, 0x00, 0x04, 0x9F, 0x00, 0x4A, 0x3F, 0xC0, 0x00, 0x00, 0x04, 0x9F, 0x00, 0x4A };
u8 D_80800828_chbkcart [48] BT_DATA(4, overlays_ch_bkcart, 0x28) = { 0, 0, 0, 0, 0x3E, 0x4C, 0xCC, 0xCD, 0x3E, 0x19, 0x99, 0x9A, 0x3F, 0x80, 0, 0, 0x3E, 0xB3, 0x33, 0x33, 0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0, 0, 0, 0x3E, 0x4C, 0xCC, 0xCD, 0x3F, 0x26, 0x66, 0x66, 0x3F, 0x80, 0, 0, 0x3F, 0x59, 0x99, 0x9A, 0x3F, 0x4C, 0xCC, 0xCD };
f32 D_80800858_chbkcart [3] BT_DATA(4, overlays_ch_bkcart, 0x58) = { 0.0f, 0.5f, -1.0f };
Vec3s32 D_80800864_chbkcart BT_DATA(4, overlays_ch_bkcart, 0x64) = { 1.5f, -0.00235f, 0.3f };
s32 D_80800870_chbkcart[4] BT_DATA(4, overlays_ch_bkcart, 0x70) = { 1120403456, 1120403456, 1112014848, 1112014848 };
ActorData D_80800880_chbkcart [1] BT_DATA(4, overlays_ch_bkcart, 0x80) = { { 855, 1306, 2320, 2, (void *)D_80800800_chbkcart, (void (*)(struct Actor *))func_80800130_chbkcart, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 327680000, 1058642330, 0, 0, 773, 801, 0, (BtIntPtr)func_80108ED0, 12, 0, (void (*)(struct Actor *))func_80800000_chbkcart, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32766, 5140, (void (*)(struct Actor *, long, long))func_808004DC_chbkcart, 0 } };
