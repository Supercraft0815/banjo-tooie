#include "common.h"

/* extern */

void func_80800000_chdeflect(s32 arg0) {
    s32 func_800C6E38(s32);
    s32 func_800FFAB0(s32);
    if (func_800C6E38(0x14) != 0) {
        func_800FFAB0(arg0);
    }
}

void func_80800034_chdeflect(u8 *arg0) {
    void _sudeflect_entrypoint_0(f32*, f32, f32, s32);
    _sudeflect_entrypoint_0(arg0 + 4, 0.0f, (*(f32 *)((s8 *)(arg0) + (0x38))) * 100.0f, 2);
}

OSThread *chdeflect_entrypoint_0(void)
{
    extern u8 D_80800090_chdeflect[];

    return (OSThread *) D_80800090_chdeflect;
}
