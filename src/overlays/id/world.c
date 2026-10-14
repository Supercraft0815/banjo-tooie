#include "common.h"

s32 func_80800000_idworld(s32 arg0, s32 arg1) {
    u32 vector_begin(s32);
    u32 vector_end(s32);
    extern s32 D_80127EF8;
    s32 pad;
    u32 sp20;
    s32 sp1C = D_80127EF8;
    u32 temp_v0;
    u32 var_v1;

    if (sp1C == 0) {
        return 0;
    }
    sp20 = vector_end(sp1C);
    temp_v0 = vector_begin(D_80127EF8);
    var_v1 = temp_v0;
    if (temp_v0 < sp20) {
loop_3:
        if ((arg1 == (*(u8 *)((s8 *)(var_v1) + (6)))) && (arg0 == (*(s16 *)((s8 *)(var_v1) + (4))))) {
            return var_v1;
        }
        var_v1 += 0xA8;
        if (var_v1 >= sp20) {
            goto block_7;
        }
        goto loop_3;
    }
block_7:
    return NULL;
}

/* extern */

s32 idworld_entrypoint_0(s32 arg0) {
    s32 func_80800000_idworld(s32, s32);
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_80800000_idworld(arg0, 6);
    if (temp_v0 != 0) {
        var_v1 = temp_v0 + 8;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

s32 idworld_entrypoint_1(s32 arg0) {
    s32 func_80800000_idworld(s32, s32);
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_80800000_idworld(arg0, 8);
    if (temp_v0 != 0) {
        var_v1 = temp_v0 + 8;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

s32 idworld_entrypoint_2(s32 arg0) {
    s32 func_80800000_idworld(s32, s32);
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_80800000_idworld(arg0, 12);
    if (temp_v0 != 0) {
        var_v1 = temp_v0 + 8;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

s32 idworld_entrypoint_3(s32 arg0) {
    s32 func_80800000_idworld(s32, s32);
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_80800000_idworld(arg0, 2);
    if (temp_v0 != 0) {
        var_v1 = temp_v0 + 8;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

s32 idworld_entrypoint_4(s32 arg0, s32 arg1) {
    u32 vector_begin(s32);
    u32 vector_end(s32);
    extern s32 D_80127EF8;
    s32 pad;
    u32 sp20;
    s32 sp1C = D_80127EF8;
    u32 temp_v0;
    u32 var_v1;

    if (sp1C == 0) {
        return 0;
    }
    sp20 = vector_end(sp1C);
    temp_v0 = vector_begin(D_80127EF8);
    var_v1 = temp_v0;
    if (temp_v0 < sp20) {
loop_4:
        if (((*(u8 *)((s8 *)(var_v1) + (6))) == 0xA) && (arg0 == (*(s32 *)((s8 *)(var_v1) + (0)))) && (arg1 == (*(s16 *)((s8 *)(var_v1) + (4))))) {
            return var_v1 + 8;
        }
        var_v1 += 0xA8;
        if (var_v1 >= sp20) {
            goto block_9;
        }
        goto loop_4;
    }
block_9:
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/world/idworld_entrypoint_5.s")
