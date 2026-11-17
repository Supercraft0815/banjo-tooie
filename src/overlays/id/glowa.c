#include "common.h"

typedef struct { s32 unk0; f32 unk4; f32 unk8; f32 unkC; } GlowEffect;     

void idglowa_entrypoint_0(u8 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, GlowEffect *arg4) {
    f32 scale = arg4->unk4;
    Vtx *end = arg1 + arg3;

    for (; arg1 < end; arg2++) {
        arg2->v.cn[3] = (u32)(arg1++)->v.cn[3] * scale;
    }
}

f32 idglowa_entrypoint_1(f32 *arg0) {
    return arg0[1];
}

void func_808000E8_idglowa(void *arg0, s32 arg1) {
    if (arg1 == 2) {
        (((GlowEffect *)arg0)->unkC) = 1.0f;
    }
    (((GlowEffect *)arg0)->unk0) = arg1;
}

void idglowa_entrypoint_2(s32 arg0) 
{
}               typedef struct { s32 unk0; f32 unk4; f32 unk8; } Objglowa_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
void idglowa_entrypoint_3(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (((Objglowa_arg0 *)arg0)->unk0) = 0;
    (((Objglowa_arg0 *)arg0)->unk4) = 0.5f;
    (((Objglowa_arg0 *)arg0)->unk8) = (f32) ((f32) (arg1 + 1) * 0.01f);
    func_808000E8_idglowa(arg0, 1);
}

void idglowa_entrypoint_4(GlowEffect *arg0, void *arg1, s32 arg2) {
    f32 func_800D8FF8(void);
    int func_800F1574(f32 *, f32);
    void _glid_entrypoint_0(void *, s32, void *, BtIntPtr);
#ifndef BT_NATIVE
    void _idglowa_entrypoint_0(void);
#endif
    f32 temp_f14;

    temp_f14 = func_800D8FF8();
    if (arg0->unk0 == 1) {
        arg0->unk4 += arg0->unk8 * temp_f14;
        if (arg0->unk4 >= 1.0f) {
            arg0->unk4 = 1.0f;
            arg0->unk8 = -arg0->unk8;
        }
        else if (arg0->unk4 < 0.0f) {
            arg0->unk4 = 0.0f;
            arg0->unk8 = -arg0->unk8;
            func_808000E8_idglowa(arg0, 2);
            return;
        }
    }

    if ((arg0->unk0 == 2) && func_800F1574(&arg0->unkC, temp_f14)) {
        func_808000E8_idglowa(arg0, 1);
    }
    _glid_entrypoint_0(arg1, arg2, _idglowa_entrypoint_0, (BtIntPtr) arg0);
}
