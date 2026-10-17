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

/* extern */

void func_800A56A4(void) {
    void func_8001B754(s16);
    s16 temp_a0;
    s32 temp_a1;
    s32 var_s0;
    s32 var_s1;
    s32 var_v0;
    s32 var_v1;

    temp_a1 = D_80119540;
    if (temp_a1 != 0) {
        var_s0 = 1;
        var_s1 = 2;
        do {
            temp_a0 = (*(s16 *)((s8 *)((temp_a1 + var_s1)) + (0x1E)));
            if (temp_a0 != 0) {
                func_8001B754(temp_a0);
                (*(s16 *)((s8 *)((D_80119540 + var_s1)) + (0x1E))) = 0;
                (*(s32 *)((s8 *)((D_80119540 + (var_s0 * 4))) + (-4))) = 0;
                temp_a1 = D_80119540;
            }
            var_s0 += 1;
            var_s1 += 2;
        } while (var_s0 != 9);
        var_v1 = 0;
        var_v0 = 0;
        if ((*(s32 *)((s8 *)(temp_a1) + (0x38))) >= 0) {
            do {
                (*(u8 *)((s8 *)((temp_a1 + var_v0)) + (0x3C))) = 0;
                var_v1 += 1;
                (*(u8 *)((s8 *)((D_80119540 + var_v0)) + (0x3D))) = 0xFF;
                temp_a1 = D_80119540;
                var_v0 += 2;
            } while ((*(s32 *)((s8 *)(temp_a1) + (0x38))) >= var_v1);
        }
        (*(s32 *)((s8 *)(temp_a1) + (0x30))) = -1;
        (*(s32 *)((s8 *)(D_80119540) + (0x34))) = 0;
    }
}

s32 func_800A5790(s32 arg0, s32 arg1) { extern s32 D_8011951C[]; s32 func_8001B798(s16); s32 result; result = arg1 * D_8011951C[arg0] + func_8001B798(*(s16 *)((s8 *)D_80119540 + arg0 * 2 + 0x1E)); return result; }

s32 func_800A57EC(s32 arg0) {
    extern s32 D_8011951C[];
    return ((s32 *)&D_8011951C)[arg0];
}

/* extern */

s32 func_800A5800(s32 arg0) {
    s32 func_800A5790(s32, s32);
    void *temp_v0;
    s32 temp_v1;

    (*(s32 *)((s8 *)(D_80119540) + (0x30))) = arg0;
    temp_v1 = arg0 * 2;
    temp_v0 = D_80119540 + temp_v1;
    (*(s32 *)((s8 *)(D_80119540) + (0x34))) = func_800A5790((*(u8 *)((s8 *)(temp_v0) + (0x3C))), (*(u8 *)((s8 *)(temp_v0) + (0x3D))));
    return (*(s32 *)((s8 *)(D_80119540) + (0x34)));
}

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
