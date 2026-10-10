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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grilldoor/func_80800068_chminegrilldoor.s")

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

