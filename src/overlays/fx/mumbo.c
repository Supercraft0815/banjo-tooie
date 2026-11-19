#include "common.h"
#ifdef BT_NATIVE
#include "core2/particle_script.h"
#endif

void fxmumbo_entrypoint_0(BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(s32) arg0, s32 arg1) {
    BtIntPtr func_800B5BE4(s32);
    s32 func_800BA22C(BtIntPtr, s32);
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, s32, s32 *);)
    extern s32 D_80800060_fxmumbo[20];
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    temp_v0 = func_800B5BE4(0xD);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg0, 0, BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_80800060_fxmumbo);
    func_800BA22C(sp24, arg1);
}
/* data_to_c.py: from asm/data/overlays/fx/mumbo.data.s */
s32 D_80800060_fxmumbo[20] BT_DATA(4, overlays_fx_mumbo, 0x0) = { 1903081, 1376307, 6684706, 786444, 1638425, 2555904, 26214400, 28835862, 268435499, 4980825, 2949095, 2686951, 1638480, 1638427, -6488164, 786440, 0, 0, 0, 0 };
