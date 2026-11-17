#include "common.h"

BT_IDO_ONLY(void) BT_NATIVE_ONLY(BtIntPtr) fxdlsmoke_entrypoint_0(s32 arg0) {
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, s32, s32 *);
    extern s32 D_80800050_fxdlsmoke[20];
    BT_NATIVE_ONLY(return) func_800BABB8(func_800B5BE4(8), arg0, 0, 0x3F800000, D_80800050_fxdlsmoke);
}
/* data_to_c.py: from asm/data/overlays/fx/dlsmoke.data.s */
s32 D_80800050_fxdlsmoke[20] BT_DATA(4, overlays_fx_dlsmoke, 0x0) = { 1903068, 2948970, 6618986, 9830700, 9830427, -6488214, 1376256, 6684704, -432, 2228275, 6684928, 23461931, 20119910, 1572864, 1248426, 212467734, 268435456, 0, 0, 0 };
