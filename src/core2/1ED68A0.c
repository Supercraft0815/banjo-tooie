#include "core2/1ED68A0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FCFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FD2A0.s")

void func_800FDBB8(s32 arg0) {
    s32 func_800FCFB0(s32, s32, s32 *, s32, f32);
    extern s32 D_80123E84;
    extern s32 D_80124010;
    extern s32 D_80124224[][2];
    extern u8 D_80135A00[];
    extern s32 *D_80135A04;
    s32 sp20;
    s32 temp_t9;
    s32 *temp_v0;

    temp_t9 = D_80124224[D_80135A00[0]][0];
    sp20 = temp_t9;
    if (temp_t9 != -1) {
        func_800FCFB0(temp_t9, D_80124224[D_80135A00[0]][1], &D_80123E84, arg0, 0.0f);
        D_80135A04 = &D_80124010;
    }
}

u32 func_800FDC28(u32 arg0) {
    extern s32 D_801359C0;
    extern u8 D_80135A10[];
    u32 result = (u32)&D_801359C0;
    if (arg0 != ((u8 *)result)[0x40]) {
        ((u8 *)result)[0x40] = arg0;
        if (!(arg0 & 0xFF)) {
            ((s8 *)result)[0x18] = 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FDC58.s")

void func_800FE3EC(void) {
    void func_800FCA90(u32);
    extern s16 D_801359C8;
    extern s32 D_80135A20[3];
    extern f32 D_80135A30[3];
    extern u8 D_80135A3C;
    extern s32 D_80135A40;
    u32 temp_a0;
    s32 var_s1;

    temp_a0 = D_801359C8;
    if (temp_a0 != -1U) {
        func_800FCA90(temp_a0);
    }
    if (D_80135A40 > 0) {
        for (var_s1 = 0; var_s1 < 3; var_s1++) {
            temp_a0 = D_80135A20[var_s1];
            if ((temp_a0 != 0) && ((&D_80135A3C)[var_s1] != 0)) {
                func_800FCA90(temp_a0);
                D_80135A20[var_s1] = 0;
                (&D_80135A3C)[var_s1] = 0;
                D_80135A30[var_s1] = 0.0f;
                D_80135A40 -= 1;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FE4E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FE614.s")

void func_800FE6F8(s32 arg0) {
    extern u8 D_801359D6;
    if ((arg0 == 0) && (D_801359D6 != 0)) {
        func_800FE4E4();
    }
    D_801359D6 = (u8) arg0;
}

void func_800FE734(u32 arg0) {
    extern s8 D_801359D7;
    D_801359D7 = (s8) arg0;
}

void func_800FE740(void) {
    extern s32 D_801359C0;
    extern u8 D_80135A10[];
    s16 _cothemedll_entrypoint_1(s32);
    s32 _cothemedll_entrypoint_3(s32 *, s32);
    s32 func_800EA05C();
    extern s16 D_801359E2;
    extern s32 D_80135A08;
    extern f32 D_80135A0C;
    s32 sp1C[2];
    s32 temp_a1;

    temp_a1 = func_800EA05C();
    if (D_80135A10[6] != 0) {
        D_80135A10[6] = 0U;
    }
    D_80135A08 = 0;
    D_80135A0C = 0.0f;
    sp1C[1] = temp_a1; _cothemedll_entrypoint_3(&D_801359C0, temp_a1);
    D_801359E2 = _cothemedll_entrypoint_1(sp1C[1]);
}

s32 func_800FE7A8(s32 arg0) { extern s16 D_801359C8; extern s32 D_80135A20[]; extern u8 D_80135A3C; extern s32 D_80135A40; s32 var_v0; u8 *var_v1; if (arg0 == D_801359C8) { return 1; } var_v0 = 0; var_v1 = &D_80135A3C; if (D_80135A40 > 0) {
        for (; var_v0 < 3; var_v0++, var_v1++) {
            if ((*var_v1 != 0) && (arg0 == D_80135A20[var_v0])) {
                return 1;
            }
        }
    }
    return 0;
}

void func_800FE820(f32 arg0) {
    extern s32 D_801359C0;
    (*(u8 *)((s8 *)(&D_801359C0) + (0x10))) = 0xFF;
    (*(f32 *)((s8 *)(&D_801359C0) + (4))) = (f32) (1.0f / arg0);
}

void func_800FE844(u32 arg0) {
    extern s8 D_801359CE;
    D_801359CE = (s8) arg0;
}

void func_800FE850()
{
    func_800DA544(FLAG2_674_UNK);
}

void func_800FE870()
{
    func_800DA544(FLAG2_675_UNK);
}

u32 func_800FE890(void) {
    extern s8 D_801359CE;
    return *(u8 *)((u8 *)&D_801359CE + 0);
}

void func_800FE89C(void) {
    extern s8 D_801359CF;
    D_801359CF = 1;
}

void func_800FE8AC(void) {
    extern s8 D_801359D8;
    D_801359D8 = 1;
}

void func_800FE8BC(s32 arg0, s32 arg1) {
    s32 _cothemedll_entrypoint_5(s32 *, s32, s32);
    extern s32 D_801359C0;
    _cothemedll_entrypoint_5(&D_801359C0, arg0, arg1);
}

void func_800FE8EC(s32 arg0) {
    s32 _cothemedll_entrypoint_4(s32 *, s32);
    extern s32 D_801359C0;
    _cothemedll_entrypoint_4(&D_801359C0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FE914.s")

void func_800FEC1C(f32 arg0) {
    extern f32 D_801359F0;
    *(f32 *)((u8 *)&D_801359F0 + 0) = arg0;
}

s32 func_800FEC28(s32 arg0) {
    extern u8 D_8012762C;
    if (arg0 == 0) {
        return D_8012762C == 0xD ? 7 : 0;
    }
    return arg0;
}
void func_800FEC60(u32 arg0) {
    extern f32 D_801359F0;
    extern s32 D_80123E60;
    extern u8 D_80135A10[];
    s32 temp_v0;
    u8 *temp_v1;
    temp_v0 = func_800FEC28((s32)arg0);
    temp_v1 = D_80135A10 + temp_v0;
    *temp_v1 = *temp_v1 + 1;
    if (temp_v0 == 3) {
        D_801359F0 = 1.0f;
    }
    D_80123E60 = 1;
}

void func_800FECB8(u32 arg0) {
    extern s32 D_80123E60;
    extern u8 D_80135A10[];
    s32 i;
    u8 *p;
    p = D_80135A10 + func_800FEC28((s32)arg0);
    *p = *p - 1;
    for (i = 0; i < 14; i++) {}
    D_80123E60 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FED0C.s")

void func_800FED70(s32 arg0)
{
    func_800FED0C(arg0,1);
}

s32 func_800FED90(s32 arg0) {
    s32 var_v0;

    func_800FED0C(arg0, -1);
    var_v0 = 2;
    while (var_v0 != 0xE) {
        var_v0 += 4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FEDC4.s")

void func_800FEF94(s32 arg0, s32 arg1, s32 arg2, s32 *arg3, s16 *arg4) {
    extern s32 D_80123E84;
    u8 *temp_v0;
    u8 *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (arg1 * 0xC) + (u8 *)&D_80123E84;
        *arg3 = (*(s32 *)((s8 *)(temp_v0) + (4)));
        *arg4 = (*(s16 *)((s8 *)(temp_v0) + (0xA)));
        return;
    }
    temp_v0_2 = (arg1 * 0xC) + (u8 *)&D_80123E84;
    *arg3 = (*(s32 *)((s8 *)(temp_v0_2) + (0)));
    *arg4 = (*(s16 *)((s8 *)(temp_v0_2) + (8)));
}

void func_800FF000(s32 arg0) {
    extern s32 D_801359C0;
    extern f32 D_80126420;
    (*(s8 *)((s8 *)(&D_801359C0) + (0x13))) = (s8) arg0;
    (*(f32 *)((s8 *)(&D_801359C0) + (0))) = D_80126420;
}

void func_800FF01C(f32 arg0) {
    extern s32 D_801359C0;
    (*(s8 *)((s8 *)(&D_801359C0) + (0x13))) = 1;
    (*(s8 *)((s8 *)(&D_801359C0) + (0x14))) = 1;
    (*(f32 *)((s8 *)(&D_801359C0) + (0))) = arg0;
}

void func_800FF038(s32 arg0) {
    s32 _cothemedll_entrypoint_2(s32 *, s32);
    extern s32 D_801359C0;
    _cothemedll_entrypoint_2(&D_801359C0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FF060.s")
