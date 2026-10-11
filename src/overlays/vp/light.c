#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/vplight_entrypoint_0.s")

void vplight_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/func_80800134_vplight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/vplight_entrypoint_2.s")

void func_808004B0_vplight(void *arg0, s32 position[3]) {
    void func_800C8800(void *, f32 *);
    f32 pos[3];
    func_800C8800(arg0, pos);
    position[0] = (s32)pos[0];
    position[1] = (s32)pos[1];
    position[2] = (s32)pos[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/func_80800518_vplight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/vplight_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/vplight_entrypoint_4.s")
