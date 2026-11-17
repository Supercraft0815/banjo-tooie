#include "common.h"

void idglow_entrypoint_0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, f32 *arg4) {
    f32 scale = *arg4;
    u8 *end = arg1 + arg3 * 0x10;

    for (; arg1 < end; arg1 += 0x10, arg2 += 0x10) {
        arg2[12] = (u32)((f32)(u32)arg1[12] * scale);
        arg2[13] = (u32)((f32)(u32)arg1[13] * scale);
        arg2[14] = (u32)((f32)(u32)arg1[14] * scale);
    }
}

void idglow_entrypoint_1(s32 arg0) 
{
}               typedef struct { f32 unk0; f32 unk4; } Objglow_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
void idglow_entrypoint_2(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (((Objglow_arg0 *)arg0)->unk0) = 0.5f;
    (((Objglow_arg0 *)arg0)->unk4) = (f32) (((f32) arg1 + 1.0f) * 0.01f);
}

void idglow_entrypoint_3(f32 *arg0, void *model, s32 mesh_id) {
    f32 func_800D8FF8(void);
    void _glid_entrypoint_0(void *, s32, void *, BtIntPtr);
#ifndef BT_NATIVE
    void _idglow_entrypoint_0(void);
#endif
    arg0[0] += arg0[1] * func_800D8FF8();
    if (arg0[0] >= 1.0f) {
        arg0[0] = 1.0f;
        arg0[1] = -arg0[1];
    } else if (arg0[0] < 0.3f) {
        arg0[0] = 0.3f;
        arg0[1] = -arg0[1];
    }
    _glid_entrypoint_0(model, mesh_id, _idglow_entrypoint_0, (BtIntPtr) arg0);
}
