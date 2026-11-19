#include "common.h"
#include "core2/world_effect.h"

 void idtwinklea_entrypoint_0(void *data, s32 variant, void *model, s32 mesh, s32 flags) {
    (((TwinkleRange *)data)->begin) = 0;
    (((TwinkleRange *)data)->end) = 0;
}

void idtwinklea_entrypoint_1(void *data) {
}
void idtwinklea_entrypoint_2(void *data, void *model, s32 mesh) {
    BtIntPtr arg0 = (BtIntPtr)data;
    BtIntPtr arg1 = (BtIntPtr)model;
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*mesh)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    BT_NATIVE_ONLY(void _idtwinkle_entrypoint_6(void *, u8 **, u8 **);) BT_IDO_ONLY(void _idtwinkle_entrypoint_6(u8 *, s32 *, s32 *);)
    BtIntPtr _idworld_entrypoint_2(s32);
#ifdef BT_NATIVE
    void idtwinklea_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *mesh, s32 arg3, u8 *arg4);
#else
    extern s32 _idtwinklea_entrypoint_3;
#endif
    BtIntPtr temp_v0;

    temp_v0 = _idworld_entrypoint_2(mesh - 0xC8);
    if (temp_v0 != 0) {
        BT_NATIVE_ONLY(_idtwinkle_entrypoint_6((void *)temp_v0, &((TwinkleRange *)arg0)->begin, &((TwinkleRange *)arg0)->end);) BT_IDO_ONLY(_idtwinkle_entrypoint_6(temp_v0, arg0, arg0 + 4);)
        _glid_entrypoint_0(arg1, mesh, &_idtwinklea_entrypoint_3, arg0);
    }
}              

void idtwinklea_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, u8 *arg4) {
    f32 var_f0;
    u8 *temp_a2;
    Vtx *temp_v0;
    u8 *var_v1;

    temp_v0 = arg1 + arg3;
    for (; arg1 < temp_v0; arg1++, arg2++) {
            var_v1 = ((TwinkleRange *)arg4)->begin;
            temp_a2 = ((TwinkleRange *)arg4)->end;
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
