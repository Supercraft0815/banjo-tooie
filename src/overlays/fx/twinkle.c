#include "fx/twinkle.h"
#ifdef BT_NATIVE
#include "core2/particle_script.h"
#endif

void fxtwinkle_entrypoint_0(BtIntPtr arg0)
{
    fxtwinkle_entrypoint_1(arg0, GOLD_SPARKLE);
}

void fxtwinkle_entrypoint_1(f32 *arg0, enum asset_e arg1) {
    BtIntPtr func_800B53A4(s32);
    s32 func_800BA22C(BtIntPtr, s32);
    BT_IDO_ONLY(s32 func_800BA3FC(BtIntPtr, s16);) BT_NATIVE_ONLY(void func_800BA3FC(BtIntPtr, s32);)
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, f32 *, BtIntPtr, s32, s32 *);)
    extern s32 D_808000F0_fxtwinkle[7];
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(1);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg0, 0, BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_808000F0_fxtwinkle);
    func_800BA3FC(sp24, (s16) arg1);
    func_800BA22C(sp24, 1);
}

void fxtwinkle_entrypoint_2(f32 *arg0, enum asset_e arg1) {
    BtIntPtr func_800B53A4(s32);
    s32 func_800BA22C(BtIntPtr, s32);
    BT_IDO_ONLY(s32 func_800BA3FC(BtIntPtr, s16);) BT_NATIVE_ONLY(void func_800BA3FC(BtIntPtr, s32);)
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, f32 *, BtIntPtr, s32, s32 *);)
    extern s32 D_8080010C_fxtwinkle[9];
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(1);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg0, 0, BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_8080010C_fxtwinkle);
    func_800BA3FC(sp24, (s16) arg1);
    func_800BA22C(sp24, 1);
}
/* data_to_c.py: from asm/data/overlays/fx/twinkle.data.s */
s32 D_808000F0_fxtwinkle[7] BT_DATA(4, overlays_fx_twinkle, 0x0) = { 2818227, 11730978, 6684774, 458759, 2555904, 17694720, 17694720 };
s32 D_8080010C_fxtwinkle[9] BT_DATA(4, overlays_fx_twinkle, 0x1C) = { 2818227, 11730966, 268697634, 6684774, 458759, 2555904, 17694720, 17694720, 0 };
