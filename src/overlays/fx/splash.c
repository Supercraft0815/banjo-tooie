#include "common.h"

/* extern */

void fxsplash_entrypoint_0(s32 arg0 BT_PASS2(, s32 bt_a1)) {
    s32 _fxripple_entrypoint_0(s32);
    _fxripple_entrypoint_0(0);
}

void fxsplash_entrypoint_1(f32 arg0[3]) {
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    BtIntPtr fxsplash_entrypoint_2(f32[3], f32);
    extern s32 D_80800130_fxsplash[5];
    func_800BABB8(fxsplash_entrypoint_2(arg0, 20.0f), 0, 0, 1.0f, D_80800130_fxsplash);
}

BtIntPtr fxsplash_entrypoint_2(f32 arg0[3], f32 arg1) {
    BtIntPtr func_800B5BE4(s32);
    void func_800BA4D0(s16 *, s16);
    void func_800BA544(s32 *, BtIntPtr);
    void func_800BA6B0(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800144_fxsplash[15];
#ifndef BT_NATIVE
    extern s32 _fxsplash_entrypoint_0;
#endif
    BtIntPtr sp2C;
    s32 temp_f6;
    s32 temp_f8;
    BtIntPtr temp_v0;

    temp_v0 = func_800B5BE4(1);
    sp2C = temp_v0;
    temp_f8 = (s32) arg1;
    temp_f6 = (s32) -arg1;
    func_800BA6B0(temp_v0, (s16) temp_f6, 0, (s16) temp_f6, (s16) temp_f8, 0, (s16) temp_f8);
    func_800BA4D0(sp2C, (s16) (s32) arg0[1]);
    func_800BA544(sp2C, &_fxsplash_entrypoint_0);
    return func_800BABB8(sp2C, arg0, 0, 1.0f, D_80800144_fxsplash);
}
/* data_to_c.py: from asm/data/overlays/fx/splash.data.s */
s32 D_80800130_fxsplash[5] BT_DATA(4, overlays_fx_splash, 0x0) = { 2948940, 26279756, 11797180, 11801626, 0 };
s32 D_80800144_fxsplash[15] BT_DATA(4, overlays_fx_splash, 0x14) = { 1903066, 2162687, -21757925, -85132564, 458753, 1376256, 13369378, 327690, 131074, 2818560, 33554454, 268435456, 0, 0, 0 };
