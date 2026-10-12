#include "common.h"

extern s32 D_80119540;

/* extern */

void func_800A5550(s32 arg0, void *arg1) {
    s32 _ncbaspline_entrypoint_5(s32, s32, void *);
    s32 func_800A93E4(u32);
    s32 func_80110014(s32);
    _ncbaspline_entrypoint_5(func_80110014(func_800A93E4((u32) (*(u16 *)((s8 *)(arg1) + 0x1A)) >> 5)), arg0, arg1);
}

/* extern */

void func_800A5598(s32 arg0, void *arg1) {
    s32 _ncbaspline_entrypoint_6(s32, s32, void *);
    s32 func_800A93E4(u32);
    s32 func_80110014(s32);
    _ncbaspline_entrypoint_6(func_80110014(func_800A93E4((u32) (*(u16 *)((s8 *)(arg1) + 0x1A)) >> 5)), arg0, arg1);
}

/* extern */

void func_800A55E0(void) {
    s32 _cadbmgrDll_entrypoint_0(s32 *, s32);
    _cadbmgrDll_entrypoint_0(&D_80119540, 0x7D);
}

/* extern */

void func_800A5608(s32 arg0) {
    s32 _cadbmgrDll_entrypoint_0(s32 *, s32);
    _cadbmgrDll_entrypoint_0(&D_80119540, arg0);
}

void func_800A5630()
{
    _cadbmgrDll_entrypoint_1(&D_80119540);
}

/* extern */

void func_800A5654(void) {
    s32 defrag(s32);

    if (D_80119540 != 0) {
        D_80119540 = defrag(D_80119540);
        (*(s32 *)((s8 *)(D_80119540) + (0x30))) = -1;
        (*(s32 *)((s8 *)(D_80119540) + (0x34))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A56A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A5790.s")

s32 func_800A57EC(s32 arg0) {
    extern s32 D_8011951C[];
    return ((s32 *)&D_8011951C)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EE40/func_800A5800.s")

s32 func_800A5854(s32 arg0) {
    return ((u8 *)D_80119540)[arg0 * 2 + 0x3C];
}

s32 func_800A586C(void) {
    return (*(s32 *)((s8 *)(D_80119540) + (0x34)));
}

u8 func_800A587C(void) {
    struct Data {
        u8 pad[0x30];
        s32 index;
        u8 pad34[8];
        u8 entries[1][2];
    };
    return ((struct Data *)D_80119540)->entries[((struct Data *)D_80119540)->index][0];
}

s32 func_800A5898(void) {
    return (*(s32 *)((s8 *)(D_80119540) + (0x30)));
}

/* extern */

void func_800A58A8(s32 arg0, s32 arg1) {
    s32 _cadbmgrDll_entrypoint_2(s32, s32, s32);
    if (arg1 != (*(u8 *)((s8 *)D_80119540 + (arg0 * 2) + 0x3C)) && arg1 != 0) {
        _cadbmgrDll_entrypoint_2(D_80119540, arg1, arg0);
    }
}

s32 func_800A58F0(void) {
    return (*(s32 *)((s8 *)(D_80119540) + (0x38))) + 1;
}

/* extern */

s32 func_800A5904(void) {
    s32 func_800A5854();
    return func_800A5854() != 0;
}
