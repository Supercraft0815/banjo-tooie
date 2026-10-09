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

/* extern */

s16 glidmake_entrypoint_3(s32 *arg0, s32 arg1) {
    void *_dbid_entrypoint_2(s32, s32);
    s32 func_800B274C(s32);
    s32 func_800D674C(s32);
    s16 var_v1;
    void *temp_v0;

    temp_v0 = _dbid_entrypoint_2(func_800B274C(func_800D674C(*arg0)), arg1);
    if (temp_v0 != NULL) {
        var_v1 = (*(s16 *)((s8 *)(temp_v0) + (2)));
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void glidmake_entrypoint_4(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/idmake/glidmake_entrypoint_5.s")
