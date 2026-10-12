#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbmgrDll/cadbmgrDll_entrypoint_0.s")

/* extern */

void cadbmgrDll_entrypoint_1(s32 *arg0) {
    s32 func_800A56A4();
    s32 heap_free(s32);
    func_800A56A4();
    heap_free(*arg0);
    *arg0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbmgrDll/func_808000F4_cadbmgrDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbmgrDll/cadbmgrDll_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbmgrDll/func_808003D8_cadbmgrDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbmgrDll/func_808004C4_cadbmgrDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbmgrDll/func_80800528_cadbmgrDll.s")

/* extern */

void func_808005AC_cadbmgrDll(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_8001B798(s16);
    s32 func_800A57EC(s32);
    void rare_memcpy(void *, void *, int);
    s32 sp1C;
    s32 temp_v0;

    sp1C = func_800A57EC(arg1);
    temp_v0 = func_8001B798(*(s16 *)((s8 *)arg0 + (arg1 << 1) + 0x1E));
    rare_memcpy((void *)((s8 *)temp_v0 + arg3 * sp1C), (void *)((s8 *)temp_v0 + arg2 * sp1C), sp1C);
}
