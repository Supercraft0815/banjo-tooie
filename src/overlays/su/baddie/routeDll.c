#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_80800000_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/subaddierouteDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_8080011C_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_8080024C_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/subaddierouteDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/subaddierouteDll_entrypoint_2.s")

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
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_808005B0_subaddierouteDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/subaddierouteDll_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/subaddierouteDll_entrypoint_6.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_8080183C_subaddierouteDll.s")
