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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/billdrillcover/func_808000DC_chlagoonbilldrillcover.s")

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
