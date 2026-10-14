#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_80800000_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/subaddierouteDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_8080011C_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_8080024C_subaddierouteDll.s")

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
