#include "common.h"

s32 func_80098890() 
{
    return 0x1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_80098898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_800989E4.s")

void func_80098B4C(void *arg0, s32 arg1) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xBC)))) + (0x19))) = (s8) (arg1 == 0);
}

/* extern */

void func_80098B5C(void *arg0, s32 arg1, s32 arg2) {
    s32 func_800EE7F8(s32, s32);
    func_800EE7F8(arg1, (*(s32 *)((s8 *)(arg0) + (0xBC))) + 0xC);
    func_800EE7F8(arg2, (*(s32 *)((s8 *)(arg0) + (0xBC))));
}

s32 func_80098BA0() 
{
    return 0xC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_80098BA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_80098BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_80098C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_80098E64.s")

void func_8009919C(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB8)))) + (0))) = arg1;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB8)))) + (4))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_800991B0.s")

/* extern */

void func_80099544(void *arg0) {
    s32 baanim_defrag();
    s32 bakey_defrag(void *);
    s32 func_800934C4(void *);
    s32 func_80096728(void *);
    s32 func_800A266C(void *);
    s32 func_800A300C(void *);
    if ((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB8)))) + (8))) != 0) {
        baanim_defrag();
        func_800934C4(arg0);
        func_80096728(arg0);
        func_800A300C(arg0);
        bakey_defrag(arg0);
        func_800A266C(arg0);
    }
}
