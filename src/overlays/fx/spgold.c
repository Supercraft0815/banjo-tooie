#include "common.h"

typedef struct { u8 pad0[0xB]; u8 unkB; } Objspgold_D_80127115; /* offsets.py genstruct: fields from raw offsets on &D_80127115; rename once understood */ void fxspgold_entrypoint_0(void) {
    void func_800B58D4(u8 index);
    extern s32 D_80127115;
    func_800B58D4((((Objspgold_D_80127115 *)&D_80127115)->unkB));
}

void fxspgold_entrypoint_1(void) {
    s8 func_800B5758(s32);
    extern s32 D_80127115;
    (*(s8 *)((s8 *)(&D_80127115) + (0xB))) = func_800B5758(0x14);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) fxspgold_entrypoint_2(s32 arg0) {
    s32 func_800B56D0(u8);
    BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, s32, s32 *);
    extern s32 D_80127115;
    extern s32 D_80800090_fxspgold[12];
    BT_NATIVE_ONLY(return) func_800BABB8(func_800B56D0((((Objspgold_D_80127115 *)&D_80127115)->unkB)), arg0, 0, 0x3F800000, D_80800090_fxspgold);
}
/* data_to_c.py: from asm/data/overlays/fx/spgold.data.s */
s32 D_80800090_fxspgold[12] BT_DATA(4, overlays_fx_spgold, 0x0) = { 1834758, -16383979, 6684876, 2228280, 3670023, 458791, 200, 240, 2818227, 11730966, 268435456, 0 };

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_80127115 BT_DATA(4, bss_core2bss1_0_1, 0xB5);
#endif
