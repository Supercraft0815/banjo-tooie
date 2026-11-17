#include "common.h"

/* extern */

void fxairbub_entrypoint_0(BT_IDO_ONLY(s32 arg0) BT_PASS2(s32 arg0, s32 bt_a1)) {
    s32 _fxripple_entrypoint_0(s32);
    _fxripple_entrypoint_0(0);
}

BtIntPtr fxairbub_entrypoint_1(f32 arg0[3], f32 arg1, f32 arg2, f32 arg3) {
    BtIntPtr func_800B5BE4(s32);
    void func_800BA544(s32 *, BtIntPtr);
    void func_800BA568(s16 *, s16);
    void func_800BA6B0(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s16 *);
    extern s16 D_80800100_fxairbub[];
#ifndef BT_NATIVE
    extern s32 _fxairbub_entrypoint_0;
#endif
    BtIntPtr sp2C;
    s32 temp_f10;
    int temp_f16;
    BtIntPtr temp_v0;

    temp_v0 = func_800B5BE4(2);
    sp2C = temp_v0;
    func_800BA568(temp_v0, (s16) (s32) arg2);
    temp_f16 = (s32) arg1;
    temp_f10 = (s32) -arg1;
    func_800BA6B0(sp2C, (s16) temp_f10, 0, (s16) temp_f10, (s32) (s16) temp_f16, 0, (s32) (s16) temp_f16);
    func_800BA544(sp2C, &_fxairbub_entrypoint_0);
    return func_800BABB8(sp2C, arg0, 0, arg3, D_80800100_fxairbub);
}
/* data_to_c.py: from asm/data/overlays/fx/airbub.data.s */
s16 D_80800100_fxairbub [40] BT_DATA(4, overlays_fx_airbub, 0x0) = { 29, 2521, 22, 4100, 27, 150, 150, 7, 1, 21, 0, 204, 43, 768, 768, 44, 0, 0, 0, 0, 0, 0, 32, -1, -257, 34, 12, 23, 12, 23, 47, 64, 64, 0, 0, 25, 0, 51, 0, 0 };
