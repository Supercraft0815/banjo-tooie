#include "common.h"

/* extern */

typedef struct { u8 pad0[0x2C]; s32 unk2C; } Obj1ED3880_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */ typedef struct { u8 pad0[0x4]; BtIntPtr unk4; } Obj1ED3880_func_800F9F90_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */ BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F9F90(s32 arg0, void *arg1) {
    BtIntPtr defrag(BtIntPtr);
    s32 temp_a0;
    u32 temp_s1;
    BtUIntPtr var_s0;

    var_s0 = arg0 + 8;
    temp_s1 = ((((Obj1ED3880_arg1 *)arg1)->unk2C) * 8) + arg0 + 8;
    if (var_s0 < temp_s1) {
        do {
            temp_a0 = (((Obj1ED3880_func_800F9F90_var_s0 *)var_s0)->unk4);
            if (temp_a0 != 0) {
                (((Obj1ED3880_func_800F9F90_var_s0 *)var_s0)->unk4) = defrag(temp_a0);
            }
            var_s0 += 8;
        } while (var_s0 < temp_s1);
    }
    BT_NATIVE_ONLY(return) defrag(arg0);
}
