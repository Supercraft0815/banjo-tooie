#include "common.h"

typedef struct { f32 unk0; s16 unk4; f32 unk8; } ScrollEffect;     

void idscroll_entrypoint_0(s16 arg0, BtUIntPtr arg1, u8 *arg2, s32 arg3, s16 *arg4) {
    s32 offset = arg4[2];
    BtUIntPtr end = (arg3 << 4) + arg1;
    s32 value;

    if (arg1 < end) {
        do {
            value = *(s16 *)(arg1 + 10) + offset;
            arg1 += 16;
            value -= 0x2000;
            arg2 += 16;
            *(s16 *)(arg2 - 6) = value;
        } while (arg1 < end);
    }
}

void idscroll_entrypoint_1(s32 arg0) 
{
}               typedef struct { f32 unk0; u8 pad4[0x4]; f32 unk8; } Objscroll_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
void idscroll_entrypoint_2(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (((Objscroll_arg0 *)arg0)->unk0) = 0.0f;
    (((Objscroll_arg0 *)arg0)->unk8) = (f32) arg1;
}

void idscroll_entrypoint_3(ScrollEffect *arg0, void *model, s32 mesh_id) {
    f32 func_800D8FF8(void);
    void _glid_entrypoint_0(void *, s32, void *, BtIntPtr);
#ifndef BT_NATIVE
    void _idscroll_entrypoint_0(void);
#endif
    arg0->unk0 += arg0->unk8 * 64.0f * func_800D8FF8();
    if ((s32)arg0->unk0 >= 0x2001) {
        arg0->unk0 -= 8192.0f;
    }
    arg0->unk4 = (s16)arg0->unk0;
    _glid_entrypoint_0(model, mesh_id, _idscroll_entrypoint_0, (BtIntPtr) arg0);
}
