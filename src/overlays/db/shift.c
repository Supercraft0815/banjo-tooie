#include "common.h"

/* extern */

typedef struct { f32 unk0; f32 unk4; } Objshift_arg4; /* offsets.py genstruct: fields from raw offsets on arg4; rename once understood */ void func_80800000_dbshift(BtIntPtr arg0, s32 *arg1, BtIntPtr arg2, s32 *arg3, void *arg4) {
    f32 func_800F2290(s32 *, s32 *);
    void func_800F2388(void *arg0, void *arg1, void *arg2);
    f32 sp24;
    s32 sp1C[2];

    sp24 = func_800F2290(arg1, arg3);
    func_800F2388(sp1C, arg2, arg0);
    (((Objshift_arg4 *)arg4)->unk0) = (f32) (func_800F2290(sp1C, arg3) / sp24);
    (((Objshift_arg4 *)arg4)->unk4) = (f32) (func_800F2290(sp1C, arg1) / sp24);
}

s32 dbshift_entrypoint_0(s32 *arg0) {
    return arg0[0];
}

void dbshift_entrypoint_1(s32 *arg0, void *arg1, s32 arg2, s32 arg3) {
    void *func_800B2190(void *);
    u8 *record;
    u8 *vertices;
    s32 i;
    u8 *point;
    f32 coords[2];

    if (arg2 >= 0) {
        record = (u8 *)(arg0 + 1);
        if (arg2 < *arg0) {
            for (i = 0; i < arg2; i++) {
                record += *(s16 *)(record + 0x1A) * 8 + 0x1C;
            }
            vertices = func_800B2190(arg1);
            point = record + 0x1C;
            vertices += *(s16 *)(record + 0x18) * 0x10;
            for (i = 0; i < *(s16 *)(record + 0x1A); i++) {
                func_80800000_dbshift((BtIntPtr)point, (s32 *)record, arg3, (s32 *)(record + 8), coords);
                *(s16 *)(vertices + 8) = (s32)((-coords[0] * *(f32 *)(record + 0x10) - 0.5f) * 64.0f);
                *(s16 *)(vertices + 0xA) = (s32)((coords[1] * *(f32 *)(record + 0x14) - 0.5f) * 64.0f);
                point += 8;
                vertices += 0x10;
            }
        }
    }
}
