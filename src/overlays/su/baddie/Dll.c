#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_3.s")

/* extern */

void subaddieDll_entrypoint_4(void *arg0, s32 arg1) {
    void *func_80100368();
    if (arg1 != 0) {
        (*(u16 *)((s8 *)(arg0) + (0x7C))) = 0U;
        return;
    }
    (*(u16 *)((s8 *)(arg0) + (0x7C))) = (u16) (*(u16 *)((s8 *)(func_80100368()) + (0x18)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/func_80800260_subaddieDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_6.s")

void subaddieDll_entrypoint_7()
{
    func_80800260_subaddieDll();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_8.s")

/* extern */

void subaddieDll_entrypoint_9(s32 arg0, s32 arg1) {
    s32 func_800DA544(s32);
    s32 subaddieDll_entrypoint_8(s32);
    func_800DA544(arg1);
    subaddieDll_entrypoint_8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/Dll/subaddieDll_entrypoint_11.s")

/* extern */

void subaddieDll_entrypoint_12(void *arg0, void *arg1) {
    s16 func_800DC128(s16, s16, void *);
    (*(s16 *)((s8 *)(arg1) + (0))) = func_800DC128((*(s16 *)((s8 *)(arg0) + (0))), (*(s16 *)((s8 *)(arg0) + (4))), arg0);
    (*(s16 *)((s8 *)(arg1) + (2))) = func_800DC128((*(s16 *)((s8 *)(arg0) + (2))), (*(s16 *)((s8 *)(arg0) + (6))), arg0);
}
