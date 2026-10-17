#include "common.h"

void glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), s32 arg3) {
    void *func_800B2190(void *);
    s32 temp_a0;
    u8 *temp_s4;
    u32 var_v1;
    u8 *temp_s3;
    u8 *var_s0;
    u8 *var_s1;
    u8 *var_s2;

    temp_s4 = func_800B2190(*(void **)(arg0 + 0x14));
    temp_a0 = *(s32 *)(arg0 + 4);
    var_s1 = arg0 + 0x1C;
    var_v1 = 0;
    while ((s32)var_v1 < temp_a0) {
        var_v1 += 1;
        if (arg1 == *(s16 *)(var_s1 + 0)) {
            var_s0 = var_s1 + 8;
            temp_s3 = (*(s16 *)(var_s1 + 2) * 4) + var_s1 + 8;
            var_s2 = temp_s3;
            if ((u32)var_s0 < (u32)temp_s3) {
                do {
                    arg2(*(s16 *)(var_s1 + 0), var_s2, (*(s16 *)(var_s0 + 0) * 0x10) + temp_s4, *(s16 *)(var_s0 + 2), arg3);
                    var_s2 += *(s16 *)(var_s0 + 2) * 0x10;
                    var_s0 += 4;
                } while ((u32)var_s0 < (u32)temp_s3);
            }
            break;
        } else {
            var_s1 += *(s32 *)(var_s1 + 4);
        }
    }
}

/* extern */

void glid_entrypoint_1(u8 *arg0, s32 arg1, s32 (*arg2)(u8 *, u8 *, u8 *, s16, s32), s32 arg3) {
    void *func_800B2190(void *);
    s32 temp_a1;
    u8 *temp_s3;
    u8 *temp_s4;
    s32 temp_t9;
    u32 var_a0;
    u8 *temp_s2;
    u8 *var_s0;
    u8 *var_s1;
    u8 *var_v1;

    temp_s3 = func_800B2190(*(void **)(arg0 + 0x14));
    temp_s4 = func_800B2190(*(void **)(arg0 + 0x18));
    temp_a1 = (*(s32 *)((s8 *)(arg0) + (4)));
    var_v1 = arg0 + 0x1C;
    var_a0 = 0;
    while ((s32)var_a0 < temp_a1) {
        var_a0++;
        if (arg1 == (*(s16 *)((s8 *)(var_v1) + (0)))) {
            var_s0 = var_v1 + 8;
            temp_s2 = ((*(s16 *)((s8 *)(var_v1) + (2))) * 4) + var_v1 + 8;
            var_s1 = temp_s2;
            if ((u32) var_s0 < (u32) temp_s2) {
                do {
                    temp_t9 = (*(s16 *)((s8 *)(var_s0) + (0))) * 0x10;
                    arg2(var_s1, temp_t9 + temp_s3, temp_t9 + temp_s4, (*(s16 *)((s8 *)(var_s0) + (2))), arg3);
                    var_s1 += (*(s16 *)((s8 *)(var_s0) + (2))) * 0x10;
                    var_s0 += 4;
                } while ((u32) var_s0 < (u32) temp_s2);
            }
            break;
        }
        var_v1 += (*(s32 *)((s8 *)(var_v1) + (4)));
    }
}

/* extern */

void glid_entrypoint_2(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s32), s32 arg3) {
    void *func_800B2190(void *);
    s32 temp_a0;
    u8 *temp_fp;
    s32 var_v1;
    u8 *temp_s2;
    u8 *var_s0;
    u8 *temp_s7;
    u8 *var_s1;
    u8 *var_s3;
    u8 *var_s6;

    temp_fp = func_800B2190(*(void **)(arg0 + 0x14));
    temp_a0 = (*(s32 *)((s8 *)(arg0) + (4)));
    var_s3 = arg0 + 0x1C;
    var_v1 = 0;
    if (temp_a0 > 0) {
loop_1:
        var_v1 += 1;
        if (arg1 == (*(s16 *)((s8 *)(var_s3) + (0)))) {
            var_s6 = var_s3 + 8;
            temp_s7 = ((*(s16 *)((s8 *)(var_s3) + (2))) * 4) + var_s3 + 8;
            var_s1 = temp_s7;
            if ((u32) var_s6 < (u32) temp_s7) {
                do {
                    var_s0 = ((*(s16 *)((s8 *)(var_s6) + (0))) * 0x10) + temp_fp;
                    temp_s2 = ((*(s16 *)((s8 *)(var_s6) + (2))) * 0x10) + var_s0;
                    if (var_s0 < temp_s2) {
                        do {
                            arg2((*(s16 *)((s8 *)(var_s3) + (0))), var_s1, var_s0, arg3);
                            var_s0 += 0x10;
                            var_s1 += 0x10;
                        } while (var_s0 < temp_s2);
                    }
                    var_s6 += 4;
                } while ((u32) var_s6 < (u32) temp_s7);
            }
        } else {
            var_s3 += (*(s32 *)((s8 *)(var_s3) + (4)));
            if (var_v1 < *(s32 *)(arg0 + 4)) {
                goto loop_1;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/id/glid_entrypoint_3.s")

/* extern */

void glid_entrypoint_4(u8 *arg0, s32 (*arg1)(s16, u8 *, u8 *, s32), s32 arg2) {
    void *func_800B2190(void *);
    s32 sp44[5];
    u8 *temp_v0;
    s32 var_v1;
    u8 *temp_s2;
    u8 *var_s0;
    u8 *temp_s7;
    u8 *var_s1;
    u8 *var_s3;
    u8 *var_s6;

    temp_v0 = func_800B2190(*(void **)(arg0 + 0x14));
    sp44[0] = 0;
    var_v1 = (*(s32 *)((s8 *)(arg0) + (4)));
    var_s3 = arg0 + 0x1C;
    if (var_v1 > 0) {
        do {
            var_s6 = var_s3 + 8;
            temp_s7 = ((*(s16 *)((s8 *)(var_s3) + (2))) * 4) + var_s3 + 8;
            var_s1 = temp_s7;
            if ((u32) var_s6 < (u32) temp_s7) {
                do {
                    var_s0 = ((*(s16 *)((s8 *)(var_s6) + (0))) * 0x10) + temp_v0;
                    temp_s2 = ((*(s16 *)((s8 *)(var_s6) + (2))) * 0x10) + var_s0;
                    if (var_s0 < temp_s2) {
                        do {
                            arg1((*(s16 *)((s8 *)(var_s3) + (0))), var_s1, var_s0, arg2);
                            var_s0 += 0x10;
                            var_s1 += 0x10;
                        } while (var_s0 < temp_s2);
                    }
                    var_s6 += 4;
                } while ((u32) var_s6 < (u32) temp_s7);
                var_v1 = (*(s32 *)((s8 *)(arg0) + (4)));
            }
            var_s3 += (*(s32 *)((s8 *)(var_s3) + (4)));
            sp44[0]++;
        } while (sp44[0] < var_v1);
    }
}

void glid_entrypoint_5(s32 *arg0, s32 arg1) {
    arg0[5] = arg1;
}

void glid_entrypoint_6(s32 *arg0, s32 arg1) {
    arg0[6] = arg1;
}
