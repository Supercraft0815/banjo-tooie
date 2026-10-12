#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/zone/dbzone_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/zone/func_8080010C_dbzone.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/zone/dbzone_entrypoint_1.s")

/* extern */

void dbzone_entrypoint_2(s16 arg0[][7], f32 *arg1, s32 arg2) {
    void func_800EE940(s16 dst[3], f32 src[3]);
    s32 func_8080010C_dbzone(s16 *, s16 *);
    s16 sp1C[6];
    s16 (*temp)[7];

    func_800EE940(sp1C, arg1);
    temp = arg0;
    temp += arg2;
    func_8080010C_dbzone(temp[0] + 1, sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/zone/dbzone_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/zone/dbzone_entrypoint_4.s")
