#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/zone/dbzone_entrypoint_0.s")

int func_8080010C_dbzone(s16 *arg0, s16 *arg1) {
    s32 temp_v1;

    temp_v1 = arg1[0];
    return temp_v1 >= arg0[0] && arg0[3] >= temp_v1 &&
        (temp_v1 = arg1[1]) >= arg0[1] && arg0[4] >= temp_v1 &&
        (temp_v1 = arg1[2]) >= arg0[2] && arg0[5] >= temp_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/zone/dbzone_entrypoint_1.s")

/* extern */

void dbzone_entrypoint_2(s16 arg0[][7], f32 *arg1, s32 arg2) {
    void func_800EE940(s16 dst[3], f32 src[3]);
    int func_8080010C_dbzone(s16 *, s16 *);
    s16 sp1C[6];
    s16 (*temp)[7];

    func_800EE940(sp1C, arg1);
    temp = arg0;
    temp += arg2;
    func_8080010C_dbzone(temp[0] + 1, sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/zone/dbzone_entrypoint_3.s")

s32 dbzone_entrypoint_4(u8 *arg0, f32 *arg1, u8 *arg2) {
    void func_800EE940(s16 dst[3], f32 src[3]);
    s32 count;
    u8 *start;
    u8 *cursor;
    s16 sp44[3];
    u8 *end;

    count = 0;
    end = arg0 + *arg0 * 14 + 2;
    func_800EE940(sp44, arg1);
    start = arg0 + 2;
    cursor = start;
    if ((u32)start < (u32)end) {
        do {
            if (func_8080010C_dbzone((s16 *)cursor, sp44) != 0) {
                arg2[count++] = (s32)(cursor - start) / 14;
            }
            cursor += 14;
        } while ((u32)cursor < (u32)end);
    }
    return count;
}
