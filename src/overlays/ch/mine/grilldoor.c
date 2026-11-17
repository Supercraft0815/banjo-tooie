#include "ch/minegrilldoor.h"

extern BtUIntPtr D_80800190_chminegrilldoor[20];

void func_80800000_chminegrilldoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor*, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_8(void*, u32);
    (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, arg0->scale * 220.0f, 4, 0x43B) != 0) {
        _chdoormake_entrypoint_8(arg0, 2U);
    }
}

/* extern */

s32 func_80800068_chminegrilldoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _chdoor_entrypoint_1(Actor *, s32, BtIntPtr);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    s32 temp_v1;
    s32 var_v0;

    if ((func_800DA298(0x43B) == 0) && (arg1 >= 0x79)) {
        temp_v1 = arg1 - 0x79;
        if (arg1 < 0x7D) {
            if (temp_v1 & 2) {
                var_v0 = 2;
            } else {
                var_v0 = 1;
            }
            arg0->unk6C_0 = (arg0->unk6C_0 & (3 - var_v0)) + ((temp_v1 & 1) * var_v0);
            if (arg0->unk6C_0 == 3) {
                func_800DA544(0x43B);
                _capod_entrypoint_13(arg0->unk0, NULL, 8, 0x10);
            }
            return 1;
        }
    }
    return _chdoor_entrypoint_1(arg0, arg1, arg2);
}    typedef struct { u8 pad0[0x6C]; s32 unk6C; } Objgrilldoor_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800144_chminegrilldoor(void *arg0) {
    s32 _chdoor_entrypoint_0();
    if (((((Objgrilldoor_arg0 *)arg0)->unk6C) & 0x1FF) == 3) {
        _chdoor_entrypoint_0();
    }
}

void* chminegrilldoor_entrypoint_0(void) {
    return D_80800190_chminegrilldoor;
}

/* data_to_c.py: from asm/data/overlays/ch/mine/grilldoor.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
BtUIntPtr D_80800190_chminegrilldoor[20] BT_DATA(4, overlays_ch_mine_grilldoor, 0x0) = { 0xAC04C2, 0x96B0001, 0, (BtUIntPtr)func_80800144_chminegrilldoor, (BtUIntPtr)func_80105834, (BtUIntPtr)func_80101870, 0x7D00000, 0, 0x43B0000, 0xC00, 0, 0, 0, (BtUIntPtr)func_80800000_chminegrilldoor, (BtUIntPtr)func_80107C2C, 0x80002402, (BtUIntPtr)func_80800068_chminegrilldoor, 0, 0, 0 };
