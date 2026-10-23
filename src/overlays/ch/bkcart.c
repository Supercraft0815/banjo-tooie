#include "common.h"

void func_80800000_chbkcart(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bkcart/func_80800130_chbkcart.s")

s32 func_808004DC_chbkcart(Actor *arg0, s32 arg1, s32 arg2) {
    void _chbounce_entrypoint_3(f32);
    Actor *_chbounce_entrypoint_5(s32, Actor *);
    Actor *_chbounce_entrypoint_7(s32, f32 *, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    void func_800C4140(u32, f32 *, u32);
    void func_800DA544(GameFlag);
    u32 func_800F54E4(void);
    void func_80102424(Actor *, s32);
    s32 func_80103140(Actor *, u32, u16);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    f32 func_8010CD50(Actor *, u32);
    extern s32 D_80800870_chbkcart;
    struct CartFlags {
        u32 unused : 29;
        u32 active : 1;
        u32 unused2 : 2;
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
            _gcdialogcamera_entrypoint_3(&D_80800870_chbkcart, arg0->scale);
            return 3;
        default:
            return 0;
    }
}

OSThread *chbkcart_entrypoint_0(void)
{
    extern u8 D_80800880_chbkcart[];

    return (OSThread *) D_80800880_chbkcart;
}
