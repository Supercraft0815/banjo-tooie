#include "common.h"

extern s32 D_80127110;

void func_800A5BE0()
{
    _chbaddieDll_entrypoint_0(&D_80127110);
}

/* extern */

void func_800A5C04(void) {
    s32 heap_alloc(s32);
    D_80127110 = heap_alloc(0x2C0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F4D0/func_800A5C28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F4D0/func_800A5C94.s")

/* extern */

void func_800A5CC4(void) {
    s32 _chbaddieDll_entrypoint_2(s32 *);
    s32 _subaddietaxi_entrypoint_3();
    _subaddietaxi_entrypoint_3();
    _chbaddieDll_entrypoint_2(&D_80127110);
}

void func_800A5CF0(s32 arg0) {
    extern s8 D_80127115;
    *(s8 *)((u8 *)&D_80127115 + 0) = arg0;
}

void func_800A5CFC()
{
    func_800FF62C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F4D0/func_800A5D1C.s")

void * func_800A5D60(void) {
    return &D_80127110;
}

/* extern */

void func_800A5D6C(void) {
    s32 defrag(s32);
    if (D_80127110 != 0) {
        D_80127110 = defrag(D_80127110);
    }
}
