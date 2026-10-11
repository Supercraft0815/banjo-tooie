#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6A58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6BAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6CA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6DB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6DD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E705C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E70DC.s")

void func_800E715C(u8 *arg0, u8 *arg1) {
    u8 var_v0;

    var_v0 = *arg1;
    if (var_v0 != 0) {
        do {
            *arg0 = var_v0;
            var_v0 = arg1[1];
            arg0++;
            arg1++;
        } while (var_v0 != 0);
    }
    *arg0 = 0;
}

s32 func_800E7188(u8 *arg0) {
    u8 temp_v0;
    s32 var_v1 = 0;

    temp_v0 = *arg0++;
    if (temp_v0 != 0) {
        do {
            temp_v0 = *arg0;
            var_v1++;
            arg0++;
        } while (temp_v0 != 0);
    }
    return var_v1;
}

/* extern */

s32 func_800E71B8(s32 arg0) {
    s32 _gldialog_entrypoint_1();
    if (_gldialog_entrypoint_1() != 0) {
        return arg0 += 2;
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E71EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E7254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E729C.s")

void func_800E72E0(u8 *arg0) {
    u8 *ptr;

    ptr = arg0;
    while (*ptr != 0) {
        if (*ptr >= 0x61 && *ptr < 0x7B) {
            *ptr -= 0x20;
        }
        ptr++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E7324.s")

/* extern */

void func_800E7368(s32 arg0, s32 arg1) {
    s32 func_800E6A58(s32, s32);
    s32 var_s0;
    s32 var_v0;

    var_s0 = 0x1F;
    do {
        if ((1 << var_s0) & arg1) {
            var_v0 = 0x31;
        } else {
            var_v0 = 0x30;
        }
        func_800E6A58(arg0, var_v0 & 0xFF);
        var_s0 -= 1;
    } while (var_s0 >= 0);
}

void func_800E73D4(s8 *arg0) {
    arg0[0] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E73DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E7428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E7480.s")
