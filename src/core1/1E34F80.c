#include "common.h"

u16 func_8001D450(u16 arg0) {
    u16 r = ((arg0 & 0xF800) / 2) & 0xF800;
    u16 g = ((arg0 & 0x7C0) / 2) & 0x7C0;
    u16 b = ((arg0 & 0x3E) / 2) & 0x3E;
    return r | g | b | 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34F80/func_8001D4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34F80/func_8001D5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34F80/func_8001D6C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34F80/func_8001D800.s")

void func_8001D96C()
{
    func_8001D800(0xC);
}

void func_8001D98C(u16 arg0) {
    extern s32 D_8007D800;

    if (arg0 < 0x38) {
        D_8007D800 = arg0;
    }
}

void func_8001D9AC(u16 arg0) {
    extern s32 D_8007D804;

    if (arg0 < 0x1E) {
        D_8007D804 = arg0;
    }
}

void func_8001D9CC(u16 arg0, u16 arg1) {
    func_8001D98C(arg0);
    func_8001D9AC(arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34F80/func_8001DA00.s")

void func_8001DA58(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34F80/func_8001DA60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34F80/func_8001DB90.s")

void func_8001DC6C(void) {
    extern s32 D_8007D170;
    if ((*(s32 *)((s8 *)(&D_8007D170) + (0x6A0))) != 0) {
        (*(s32 *)((s8 *)(&D_8007D170) + (0x6A0))) = 0;
        return;
    }
    (*(s32 *)((s8 *)(&D_8007D170) + (0x6A0))) = 1;
}
