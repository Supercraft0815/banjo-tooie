#include "common.h"

void bamotor_entrypoint_0(void *arg0, s32 arg1, s32 arg2) {
    s32 bakey_getControllerIndex(void *);
    void func_80018820(s32, s32, s32);
    func_80018820(bakey_getControllerIndex(arg0), arg1, arg2);
}

void bamotor_entrypoint_1(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 bakey_getControllerIndex(void *);
    void func_800187B4(s32, f32, f32, f32);
    func_800187B4(bakey_getControllerIndex(arg0), arg1, arg2, arg3);
}

void bamotor_entrypoint_2(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 bakey_getControllerIndex(void *);
    void func_800187E8(s32, f32, f32, f32);
    func_800187E8(bakey_getControllerIndex(arg0), arg1, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/motor/bamotor_entrypoint_3.s")
