#include "common.h"

OSThread *chcamwaypoint_entrypoint_0(void)
{
    extern u8 D_80800130_chcamwaypoint[];

    return (OSThread *) D_80800130_chcamwaypoint;
}

void func_8080000C_chcamwaypoint(u8 *arg0) {
    f32 func_800EEAA4(f32 a[3], f32 b[3]);
    void func_800EEBF0(f32*, f32*, f32);
    func_800EEBF0((f32 *)(arg0 + 0x18), (f32 *)(arg0 + 0x44), 1.0f);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = func_800EEAA4(arg0 + 4, (f32 *)(arg0 + 0x18));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/camwaypoint/func_8080005C_chcamwaypoint.s")
