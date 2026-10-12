#include "common.h"

typedef struct { f32 unk0; s16 unk4; f32 unk8; } ScrollEffect;

void idscroll_entrypoint_0(s16 arg0, u32 arg1, u8 *arg2, s32 arg3, s16 *arg4) {
    s32 offset = arg4[2];
    u32 end = (arg3 << 4) + arg1;
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
}
void idscroll_entrypoint_2(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(f32 *)((s8 *)(arg0) + (0))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) arg1;
}

void idscroll_entrypoint_3(ScrollEffect *arg0, void *model, s32 mesh_id) {
    f32 func_800D8FF8(void);
    void _glid_entrypoint_0(void *, s32, void *, s32);
    void _idscroll_entrypoint_0(void);
    arg0->unk0 += arg0->unk8 * 64.0f * func_800D8FF8();
    if ((s32)arg0->unk0 >= 0x2001) {
        arg0->unk0 -= 8192.0f;
    }
    arg0->unk4 = (s16)arg0->unk0;
    _glid_entrypoint_0(model, mesh_id, _idscroll_entrypoint_0, (s32) arg0);
}
