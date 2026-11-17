#include "common.h"


f32 func_800F2290(u8 *arg0, u8 *arg1) {
    return (*(f32 *)(arg0 + 0) * *(f32 *)(arg1 + 4)) -
           (*(f32 *)(arg0 + 4) * *(f32 *)(arg1 + 0));
}               typedef struct { f32 unk0; f32 unk4; } Obj1ECBB80_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
/* extern */

void func_800F22B4(void *arg0, f32 arg1) {
    f32 func_80013788();
    f32 func_800137F4(f32);
    (((Obj1ECBB80_arg0 *)arg0)->unk0) = func_800137F4(arg1);
    (((Obj1ECBB80_arg0 *)arg0)->unk4) = func_80013788();
}

f32 func_800F22EC(void *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = (((Obj1ECBB80_arg0 *)arg0)->unk4);
    temp_f2 = (((Obj1ECBB80_arg0 *)arg0)->unk0);
    return sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
}

f32 func_800F2320(void *arg0) {
    f32 mlAbsF(f32);
    extern f32 D_80125EE0;
    f32 sp1C;
    f32 temp_f0;
    f32 var_f12;

    sp1C = mlAbsF((((Obj1ECBB80_arg0 *)arg0)->unk0));
    temp_f0 = mlAbsF((((Obj1ECBB80_arg0 *)arg0)->unk4));
    if (sp1C < temp_f0) {
        var_f12 = sp1C;
    } else {
        var_f12 = temp_f0;
    }
    return (sp1C + temp_f0) - (var_f12 * D_80125EE0);
}               typedef struct { f32 unk0; f32 unk4; } Obj1ECBB80_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */ typedef struct { f32 unk0; f32 unk4; } Obj1ECBB80_arg2; /* offsets.py genstruct: fields from raw offsets on arg2; rename once understood */

void func_800F2388(void *arg0, void *arg1, void *arg2) {
    (((Obj1ECBB80_arg0 *)arg0)->unk0) = (f32) ((((Obj1ECBB80_arg1 *)arg1)->unk0) - (((Obj1ECBB80_arg2 *)arg2)->unk0));
    (((Obj1ECBB80_arg0 *)arg0)->unk4) = (f32) ((((Obj1ECBB80_arg1 *)arg1)->unk4) - (((Obj1ECBB80_arg2 *)arg2)->unk4));
}

void func_800F23AC(void *arg0, void *arg1) {
    (((Obj1ECBB80_arg0 *)arg0)->unk0) = (f32) (((Obj1ECBB80_arg1 *)arg1)->unk4);
    (((Obj1ECBB80_arg0 *)arg0)->unk4) = (f32) -(((Obj1ECBB80_arg1 *)arg1)->unk0);
}
