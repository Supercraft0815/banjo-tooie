#include "ch/minegrilldoor.h"

extern u32 D_80800190_chminegrilldoor;

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
    void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32);
    s32 _chdoor_entrypoint_1(Actor *, s32, s32);
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
}

/* extern */

void func_80800144_chminegrilldoor(void *arg0) {
    s32 _chdoor_entrypoint_0();
    if (((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) == 3) {
        _chdoor_entrypoint_0();
    }
}

void* chminegrilldoor_entrypoint_0(void) {
    return &D_80800190_chminegrilldoor;
}

