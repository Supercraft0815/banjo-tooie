#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/idmake/func_80800000_glidmake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/idmake/glidmake_entrypoint_0.s")

/* extern */

void glidmake_entrypoint_1(s32 *arg0) {
    s32 func_800B274C(s32);
    s32 func_800D674C(s32);
    func_800B274C(func_800D674C(*arg0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/idmake/glidmake_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/idmake/glidmake_entrypoint_3.s")

void glidmake_entrypoint_4(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/idmake/glidmake_entrypoint_5.s")
