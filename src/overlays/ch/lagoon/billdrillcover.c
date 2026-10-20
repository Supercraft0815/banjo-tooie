#include "common.h"

OSThread *chlagoonbilldrillcover_entrypoint_0(void)
{
    extern u8 D_80800330_chlagoonbilldrillcover[];

    return (OSThread *) D_80800330_chlagoonbilldrillcover;
}

/* extern */

void func_8080000C_chlagoonbilldrillcover(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A624(Actor *);
    if (func_800DA298(arg0->unk74_7 + 0x3C2) != 0) {
        if ((s32) arg0->unk74_7 >= 0x35) {
            func_8010A570(arg0);
            func_8010A624(arg0);
            arg0->unk64_16 = 0;
            func_80108B04(arg0, 0);
            return;
        }
        func_800FFAB0(arg0);
    }
}

/* extern */

void func_80800094_chlagoonbilldrillcover(Actor *arg0) {
    s32 _subaddieDll_entrypoint_6(Actor*, s32);
    void func_8080024C_chlagoonbilldrillcover(Actor *);
    if (((((u32) (*(u16 *)((s8 *)(arg0) + (0x72)))) >> 0xA) == 2) && (_subaddieDll_entrypoint_6(arg0, 0xB) != 0)) {
        func_8080024C_chlagoonbilldrillcover(arg0);
    }
}

s32 func_808000DC_chlagoonbilldrillcover(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chexploder_entrypoint_12(Actor *, s32);
    s32 _subaddieDll_entrypoint_5(Actor *, s32);
    s32 func_800D10D4(u32, u32, f32 *, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80101080(void);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_80108474(u32, f32 *, s32);
    void func_8080024C_chlagoonbilldrillcover(Actor *);
    s32 pad;
    s32 *arg2p = &arg2;
    f32 sp2C[3];
    u32 sp28;

    switch (arg1) {
    case 0x40:
        if (_subaddieDll_entrypoint_5(arg0, *arg2p)) {
            func_80103110(arg0, 1);
            func_80101FDC(arg0, 2);
        } else {
            func_8080024C_chlagoonbilldrillcover(arg0);
        }
        break;
    case 0x90:
        _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x28);
        break;
    case 0x3D:
        sp28 = arg0->unk74_7 - 0x32;
        func_800EE7F8(sp2C, arg0->position);
        sp2C[1] -= 100.0f;
        func_800FFAB0(arg0);
        switch (sp28) {
        case 0:
        case 1:
        case 2:
            func_800D10D4(sp28 + 0x13, 7, sp2C, 3, 0);
            break;
        case 3:
            func_80108474(0x210, sp2C, 0x10E);
            break;
        case 4:
            func_80108474(0x210, sp2C, 0);
            break;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080024C_chlagoonbilldrillcover(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80108B04(Actor *, u32);
    void func_8010A624(Actor *);
    extern s32 D_80800378_chlagoonbilldrillcover;
    extern s32 D_808003B0_chlagoonbilldrillcover;
    f32 sp2C[3];

    func_800EE7F8(sp2C, arg0->position);
    sp2C[1] -= 200.0f;
    _chexploder_entrypoint_3(arg0, sp2C, 5);
    func_800BBCB8(arg0->position, sp2C, 1.0f, 3, &D_80800378_chlagoonbilldrillcover);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808003B0_chlagoonbilldrillcover);
    func_8010A624(arg0);
    arg0->unk64_16 = 0;
    func_80108B04(arg0, 0);
    func_800DA544(arg0->unk74_7 + 0x3C2);
}
