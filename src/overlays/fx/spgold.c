#include "common.h"
#ifdef BT_NATIVE
#include "core2/particle_script.h"
#endif

#ifdef BT_NATIVE
u8 D_80127120;
#define SPARKLE_HANDLE D_80127120
#else
extern s32 D_80127115;
#define SPARKLE_HANDLE (*((u8 *)&D_80127115 + 0xB))
#endif
void fxspgold_entrypoint_0(void) {
    void func_800B58D4(u8 index);

    func_800B58D4(SPARKLE_HANDLE);
}

void fxspgold_entrypoint_1(void) {
    BT_NATIVE_ONLY(u8) BT_IDO_ONLY(s8) func_800B5758(s32);

    SPARKLE_HANDLE = func_800B5758(0x14);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(BtIntPtr) fxspgold_entrypoint_2(BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(s32) arg0) {
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(s32) func_800B56D0(u8);
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, s32, s32 *);)

    extern s32 D_80800090_fxspgold[12];
    BT_NATIVE_ONLY(return) func_800BABB8(func_800B56D0(SPARKLE_HANDLE), arg0, 0, BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_80800090_fxspgold);
}
/* data_to_c.py: from asm/data/overlays/fx/spgold.data.s */
s32 D_80800090_fxspgold[12] BT_DATA(4, overlays_fx_spgold, 0x0) = { 1834758, -16383979, 6684876, 2228280, 3670023, 458791, 200, 240, 2818227, 11730966, 268435456, 0 };
