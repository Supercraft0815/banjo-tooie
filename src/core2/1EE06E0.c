#include "common.h"

void func_80106DF0(void) {
    s32 freelist_new(s32, s32);
    extern s32 D_80136F00;
    D_80136F00 = freelist_new(0x18, 12);
}

void func_80106E18(void) {
    s32 freelist_free(s32);
    extern s32 D_80136F00;
    if (D_80136F00 != 0) {
        freelist_free(D_80136F00);
        D_80136F00 = 0;
    }
}

void func_80106E50(void) {
    s32 freelist_defrag(s32);
    extern s32 D_80136F00;
    if (D_80136F00 != 0) {
        D_80136F00 = freelist_defrag(D_80136F00);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80106E88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80106EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80106F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80106F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801072A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801072E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107320.s")

/* extern */

s32 func_80107388(void) {
    void *func_80100368();
    return (*(s32 *)((s8 *)(func_80100368()) + (0x44)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801073AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801073F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_8010754C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801075E4.s")

/* extern */

void func_80107750(s32 arg0, s32 arg1) {
    s32 _subaddiefade_entrypoint_5();
    s32 func_8010A570(s32);
    s32 func_8010A624(s32);
    _subaddiefade_entrypoint_5();
    func_8010A570(arg0);
    func_8010A624(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107858.s")

/* extern */

s32 func_801078AC(s32 arg0, s32 arg1) {
    s32 func_800D90A4(s32);
    if (func_800D90A4(arg1) != 0) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801078DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107B70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107BB0.s")

f32 func_80107C00(void) {
    extern f32 D_80136F10;
    return *(f32 *)((u8 *)&D_80136F10 + 0);
}
