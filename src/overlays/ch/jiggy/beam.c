#include "common.h"

extern BtUIntPtr D_80800070_chjiggybeam[24];

void * chjiggybeam_entrypoint_0(void) {
    return D_80800070_chjiggybeam;
}    typedef struct { u8 pad0[0x18]; f32 unk18; } Objbeam_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080000C_chjiggybeam(void *arg0) {
    (((Objbeam_arg0 *)arg0)->unk18) = 1.0f;
}

void func_8080001C_chjiggybeam(void) {
}

/* extern */

void func_80800024_chjiggybeam(Actor *arg0, void *arg1) {
    void func_800E3A58(f32 *);
    void func_80101870(Actor *, void *);
    f32 sp1C[3];

    func_800E3A58(sp1C);
    func_80101870(arg0, arg1);
}

s32 func_80800058_chjiggybeam(s32 arg0, u32 arg1, u32 arg2) {
    return 0;
}
/* data_to_c.py: from asm/data/overlays/ch/jiggy/beam.data.s */
void func_80102EC0();
void func_80107C2C();
BtUIntPtr D_80800070_chjiggybeam[24] BT_DATA(4, overlays_ch_jiggy_beam, 0x0) = { 0x15804B3, 0x81B0001, 0, (BtUIntPtr)func_8080001C_chjiggybeam, (BtUIntPtr)func_80102EC0, (BtUIntPtr)func_80800024_chjiggybeam, 0, 0, 0, 0x20400, 0, 0, 0, (BtUIntPtr)func_8080000C_chjiggybeam, (BtUIntPtr)func_80107C2C, 0x80000402, (BtUIntPtr)func_80800058_chjiggybeam, 0, 0xFF, 0xFF, 0xFF, 0, 0, 0 };
