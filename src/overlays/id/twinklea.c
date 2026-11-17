#include "common.h"

typedef struct { s32 unk0; s32 unk4; } Objtwinklea_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void idtwinklea_entrypoint_0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (((Objtwinklea_arg0 *)arg0)->unk0) = 0;
    (((Objtwinklea_arg0 *)arg0)->unk4) = 0;
}

void idtwinklea_entrypoint_1(s32 arg0) 
{
}
void idtwinklea_entrypoint_2(BtIntPtr arg0, BtIntPtr arg1, s32 arg2) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    void _idtwinkle_entrypoint_6(u8 *arg0, s32 *arg1, s32 *arg2);
    BtIntPtr _idworld_entrypoint_2(s32);
#ifdef BT_NATIVE
    void idtwinklea_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, u8 *arg4);
#else
    extern s32 _idtwinklea_entrypoint_3;
#endif
    BtIntPtr temp_v0;

    temp_v0 = _idworld_entrypoint_2(arg2 - 0xC8);
    if (temp_v0 != 0) {
        _idtwinkle_entrypoint_6(temp_v0, arg0, arg0 + 4);
        _glid_entrypoint_0(arg1, arg2, &_idtwinklea_entrypoint_3, arg0);
    }
}              

void idtwinklea_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, u8 *arg4) {
    f32 var_f0;
    u8 *temp_a2;
    Vtx *temp_v0;
    u8 *var_v1;

    temp_v0 = arg1 + arg3;
    for (; arg1 < temp_v0; arg1++, arg2++) {
            var_v1 = (*(u8 **)((s8 *)(arg4) + (0)));
            temp_a2 = (*(u8 **)((s8 *)(arg4) + (4)));
            if (var_v1 < temp_a2) {
loop_4:
                if (((*(s16 *)((s8 *)(arg1) + (0))) != (*(s16 *)((s8 *)(var_v1) + (8)))) || ((*(s16 *)((s8 *)(arg1) + (2))) != (*(s16 *)((s8 *)(var_v1) + (0xA)))) || ((*(s16 *)((s8 *)(arg1) + (4))) != (*(s16 *)((s8 *)(var_v1) + (0xC))))) {
                    var_v1 += 0x10;
                    if (var_v1 < temp_a2) {
                        goto loop_4;
                    }
                }
            }
            if (var_v1 == temp_a2) {
                var_f0 = 0.0f;
            } else {
                var_f0 = 1.0f;
            }
            if (var_f0 > 1.0f) {
                var_f0 = 1.0f;
            }
            arg2->v.cn[3] = var_f0 * 255.0f;
    }
}
