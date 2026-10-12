#include "common.h"

s32 func_80800000_idflame(u8 *arg0, s16 arg1) {
    s32 var_v1;
    int temp_v0;
    temp_v0 = arg0[0xA];
    var_v1 = 0;
    if (temp_v0 <= 0) {
        goto end;
    }
loop:
    if (arg1 < ((s16 *)arg0)[var_v1 + 6]) {
        goto end;
    }
    var_v1++;
    if (var_v1 < temp_v0) {
        goto loop;
    }
end:
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/flame/idflame_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/flame/idflame_entrypoint_1.s")

void idflame_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/flame/idflame_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/flame/idflame_entrypoint_4.s")
