#include "common.h"

s32 dbskeleton_entrypoint_0(s16 *arg0) {
    return arg0[2];
}

f32 dbskeleton_entrypoint_1(f32 *arg0) {
    return arg0[0];
}

/* extern */

s32 dbskeleton_entrypoint_2(u8 *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    u8 *temp_v0;
    u8 *var_a3;

    var_a3 = arg0 + 8;
    temp_v0 = ((*(s16 *)((s8 *)(arg0) + (4))) * 0x10) + arg0 + 8;
    if ((u32) var_a3 < (u32) temp_v0) {
loop_1:
        if (arg1 == (*(s16 *)((s8 *)(var_a3) + (0xC)))) {
            func_800EE7F8(arg2, (f32 *)var_a3);
            return 1;
        }
        var_a3 += 0x10;
        if ((u32) var_a3 >= (u32) temp_v0) {
            goto block_4;
        }
        goto loop_1;
    }
block_4:
    func_800EFD24(arg2);
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/skeleton/dbskeleton_entrypoint_3.s")

s16 dbskeleton_entrypoint_4(s16 arg0[][8], s32 arg1) {
    return arg0[arg1][10];
}
