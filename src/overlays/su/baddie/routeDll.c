#include "common.h"

/* extern */

void func_80800000_subaddierouteDll(void) {
    s16 func_8001B668(s32, s32);
    void func_8001B7F0(s16, u8, int);
    s32 func_800CC5E8(void);
    OSThread *func_801015B0(void);
    void func_801015BC(void);
    s32 sp1C;
    s16 *sp18;

    sp18 = (s16 *)func_801015B0();
    sp18[1] = func_800CC5E8();
    sp1C = sp18[1] * 4;
    if (sp1C != 0) {
        sp18[0] = func_8001B668(0, sp1C);
        func_8001B7F0(sp18[0], 0, sp1C);
        func_801015BC();
        return;
    }
    sp18[0] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/subaddierouteDll_entrypoint_0.s")

/* extern */

s32 func_8080011C_subaddierouteDll(s32 arg0, s16 *arg1) {
    u32 func_800CC5F4(s32);
    void *func_800CC63C(s32, s32);
    f32 func_800EFC7C(void *, void *);
    s16 *var_s7;
    s32 var_fp;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_s0;
    s32 var_s3;
    s32 var_s4;
    void *temp_s2;
    void *temp_v0_2;
    f32 distance;

    temp_v0 = func_800CC5F4(arg0);
    var_fp = ((temp_v0 * 2) + 3) & ~3;
    var_s4 = 0;
    if (temp_v0 > 0) {
        var_s7 = arg1;
        do {
            *var_s7 = var_fp;
            temp_s2 = func_800CC63C(arg0, var_s4);
            var_s3 = 1;
            var_s0 = 0;
            if (temp_v0 > 0) {
                do {
                    if (var_s4 != var_s0) {
                        temp_v0_2 = func_800CC63C(arg0, var_s0);
                        distance = func_800EFC7C(temp_s2, temp_v0_2);
                        temp_v0_3 = (*(s16 *)((s8 *)(temp_v0_2) + (0xC))) + (*(s16 *)((s8 *)(temp_s2) + (0xC)));
                        if (distance < (f32) (temp_v0_3 * temp_v0_3)) {
                            var_s3 += 1;
                        }
                    }
                    var_s0 += 1;
                } while (var_s0 != temp_v0);
            }
            var_s4 += 1;
            var_s7 += 1;
            var_fp += (var_s3 + 3) & ~3;
        } while (var_s4 < temp_v0);
    }
    return var_fp;
}

/* extern */

void func_8080024C_subaddierouteDll(s8 *arg0, s32 arg1, s32 arg2) {
    u32 func_800CC5F4(s32);
    void *func_800CC63C(s32, s32);
    f32 func_800EFC7C(void *, void *);
    s32 temp_s4;
    s32 temp_v0_2;
    s8 *var_s2;
    s32 var_s0;
    void *temp_s3;
    void *temp_v0;
    f32 distance;

    var_s2 = arg0 + 1;
    temp_s4 = func_800CC5F4(arg1);
    temp_s3 = func_800CC63C(arg1, arg2);
    var_s0 = 0;
    if (temp_s4 > 0) {
        do {
            if (arg2 != var_s0) {
                temp_v0 = func_800CC63C(arg1, var_s0);
                distance = func_800EFC7C(temp_s3, temp_v0);
                temp_v0_2 = (*(s16 *)((s8 *)(temp_v0) + (0xC))) + (*(s16 *)((s8 *)(temp_s3) + (0xC)));
                if (distance < (f32) (temp_v0_2 * temp_v0_2)) {
                    *var_s2 = var_s0;
                    var_s2 += 1;
                }
            }
            var_s0 += 1;
        } while (var_s0 != temp_s4);
    }
    *arg0 = (var_s2 - arg0) - 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/subaddierouteDll_entrypoint_1.s")

/* extern */

void subaddierouteDll_entrypoint_2(void *arg0) {
    void func_8001B754(s16);
    void *func_8001B798(s16);
    OSThread *func_801015B0(void);
    register s32 sp2C;
    s16 *temp_v0;

    sp2C = ((u32) (*(u32 *)((s8 *)(arg0) + (0x70))) >> 0x19) - 1;
    temp_v0 = func_8001B798(*(s16 *)func_801015B0());
    (*(s16 *)((u8 *)temp_v0 + sp2C * 4 + 2)) = (s16)(*(s16 *)((u8 *)temp_v0 + sp2C * 4 + 2) - 1);
    if ((*(s16 *)((u8 *)temp_v0 + sp2C * 4 + 2)) == 0) {
        arg0 = (s16 *)((s32)temp_v0 + sp2C * 4);
        func_8001B754(*(s16 *)arg0);
        *(s16 *)arg0 = 0;
    }
}

void subaddierouteDll_entrypoint_3(s32 arg0, void *arg1, f32 *arg2) {
    void func_80800564_subaddierouteDll(s32, void *);
    rare_memset(arg1, 0, 0xC);
    func_80800564_subaddierouteDll(arg0, arg1);
}

void func_80800564_subaddierouteDll(s32 arg0, void *arg1) {
    (*(s16 *)((s8 *)(arg1) + (6))) = 0;
    (*(s32 *)((s8 *)(arg1) + (8))) = 0;
}

/* extern */

s32 subaddierouteDll_entrypoint_4(void **arg0) {
    s32 func_8001210C(s32);
    u32 sp1C;

    sp1C = (u32)(*(u16 *)((s8 *)(*arg0) + 0x12)) >> 1 & 3;
    return func_8001210C(3) == sp1C;
}
/* extern */

void func_808005B0_subaddierouteDll(Actor *arg0, s16 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 func_800136E4(f32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_80102BF8(void *, f32, f32, f32);
    s32 func_80102CF4(Actor *, s32);
    f32 sp1C[3];

    func_800EE88C(sp1C, arg1);
    arg0->unk54 = func_800136E4(func_800F1DF4(arg0->position, sp1C) + 180.0f);
    if (func_80102CF4(arg0, 0x42200000) == 0) {
        func_80102BF8(arg0, arg2, arg3, arg4);
    }
}

/* extern */

void subaddierouteDll_entrypoint_5(Actor *arg0, void *arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    void func_80102BF8(void *, f32, f32, f32);
    if (arg2 & 4) {
        func_808005B0_subaddierouteDll(arg0, arg1, arg3, arg4, arg5);
        return;
    }
    func_80102BF8(arg0, arg3, arg4, arg5);
}

/* extern */

s32 subaddierouteDll_entrypoint_6(Actor *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6) {
    s32 func_80102D98(Actor *, s32, s32, f32, f32, f32);
    if (arg2 & 0x1C) {
        return 0;
    }
    return func_80102D98(arg0, arg3, 0, arg4, (f32) arg5, (f32) arg6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_808006D0_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_80800828_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_80800A74_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/subaddierouteDll_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_80800D88_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_80800F34_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/subaddierouteDll_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/subaddierouteDll_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_8080160C_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_808016F0_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_80801784_subaddierouteDll.s")

/* extern */

f32 func_8080183C_subaddierouteDll(u8 *arg0, f32 arg1) {
    f32 func_800EFBFC(void *, void *);
    f32 func_800F0E00(f32, f32);
    f32 func_800F13F0(f32, f32);
    f32 temp_f12;
    temp_f12 = func_800F13F0(arg1, func_800EFBFC(arg0 + 4, arg0 + 0x18));
    return func_800F0E00(temp_f12, (f32)(u32)*(u16 *)(arg0 + 0x62) * (*(f32 *)(arg0 + 0x38) * 1.2f));
}
