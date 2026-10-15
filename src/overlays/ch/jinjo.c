#include "common.h"
void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);

/* extern */

void func_80800000_chjinjo(Actor *arg0) {
    s16 chjinjo_entrypoint_2(s32);
    u8 func_800D0CC8(s32);
    u32 func_800D1338(u32);
    s32 func_800DA298(s32);
    void func_800FC660(u32);
    void func_800FFAB0(Actor *);
    s32 var_v0;

    arg0->unk79_4 = 1;
    if (func_800DA298(0x653) != 0) {
        func_800FFAB0(arg0);
    }
    if (arg0->unk6C_9 == 0x48F) {
        var_v0 = chjinjo_entrypoint_2(-1);
    } else {
        var_v0 = func_800D0CC8(arg0->unk6C_0);
    }
    if ((arg0->unk6C_9 == 0x48F) && ((f32) (s32) func_800D1338(var_v0) <= arg0->rotation[1])) {
        func_800FFAB0(arg0);
    }
    if (arg0->unk64_20) {
        func_800FC660(0x10);
    }
}

u8 func_800D0CC8(s32);
s32 chjinjo_entrypoint_0(s32);

s32 func_808000DC_chjinjo(Actor *arg0) {
    return chjinjo_entrypoint_0(func_800D0CC8(arg0->unk6C_0));
}

s32 chjinjo_entrypoint_0(s32 arg0) {
    extern s16 D_80801368_chjinjo[];
    return ((s16 *)&D_80801368_chjinjo)[arg0];
}

/* extern */

void func_80800120_chjinjo(Actor *arg0) {
    void _suexpression_entrypoint_8(Actor*, u32);
    void func_800FC74C(u32);
    s32 func_8080102C_chjinjo(Actor *, s32);
    if (arg0->actorData[5] != 0U) {
        func_800FC74C(0x1CU);
        arg0->actorData[5] = 0;
    }
    func_8080102C_chjinjo(arg0, 1);
    _suexpression_entrypoint_8(arg0, 1U);
}

/* extern */

void chjinjo_entrypoint_1(s32 arg0, s32 arg1) {
    s32 func_800D0C78(s32, s32, s32);
    func_800D0C78(arg0 + 0x51, 1, arg1);
}

s16 chjinjo_entrypoint_2(s32 arg0) {
    s32 func_800EA05C();
    extern s16 D_80801300_chjinjo;
    extern s16 D_80801302_chjinjo;
    extern s32 D_80801304_chjinjo;
    extern s32 D_80801324_chjinjo;
    s32 *var_v1;
    if (arg0 == -1) {
        arg0 = func_800EA05C();
    }
    var_v1 = &D_80801304_chjinjo;
    if (arg0 == D_80801300_chjinjo) {
        return D_80801302_chjinjo;
    }
loop_5:
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (0)))) {
        return (*(s16 *)((s8 *)(var_v1) + (2)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (4)))) {
        return (*(s16 *)((s8 *)(var_v1) + (6)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (8)))) {
        return (*(s16 *)((s8 *)(var_v1) + (0xA)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (0xC)))) {
        return (*(s16 *)((s8 *)(var_v1) + (0xE)));
    }
    var_v1 += 4;
    if (var_v1 == &D_80801324_chjinjo) {
        return -1;
    }
    goto loop_5;
}

s16 chjinjo_entrypoint_3(s32 arg0) {
    extern s16 D_80801300_chjinjo;
    extern s16 D_80801302_chjinjo;
    extern s32 D_80801304_chjinjo;
    extern s32 D_80801324_chjinjo;
    s32 *var_v1;

    var_v1 = &D_80801304_chjinjo;
    if (arg0 == D_80801302_chjinjo) {
        return D_80801300_chjinjo;
    }
loop_3:
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (2)))) {
        return (*(s16 *)((s8 *)(var_v1) + (0)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (6)))) {
        return (*(s16 *)((s8 *)(var_v1) + (4)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (0xA)))) {
        return (*(s16 *)((s8 *)(var_v1) + (8)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (0xE)))) {
        return (*(s16 *)((s8 *)(var_v1) + (0xC)));
    }
    var_v1 += 4;
    if (var_v1 == &D_80801324_chjinjo) {
        return -1;
    }
    goto loop_3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/func_808002E0_chjinjo.s")

/* extern */

void chjinjo_entrypoint_4(s32 arg0, s32 arg1, s32 arg2) {
    s32 _glcutDll_entrypoint_6(s32, s32);
    _glcutDll_entrypoint_6(0x142, 0x84);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/func_80800C10_chjinjo.s")

void func_80800EE4_chjinjo(Actor *arg0) {
    extern u32 D_80801358_chjinjo;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801358_chjinjo, 0.6f);
}

void func_80800F14_chjinjo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_80101E14(Actor *, f32);
    extern s32 D_8080133C_chjinjo;
    extern s32 D_80801348_chjinjo;
    if (func_80101E14(arg0, 0.2f) != 0) {
        if (arg0->unk6C_9 == 0x48F) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801348_chjinjo);
            return;
        }
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080133C_chjinjo);
    }
}

void func_80800F80_chjinjo(Actor *arg0) {
    extern u32 D_80801330_chjinjo;
    if (arg0->unk6C_9 != 0x48F) {
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801330_chjinjo, 0.2f);
    }
}

void func_80800FC4_chjinjo(Actor *arg0) { extern u16 D_80801390_chjinjo[]; s32 sp2C; sp2C = func_800D0CC8(arg0->unk6C_0); func_800C05B8(D_80801390_chjinjo[sp2C], 0x44, NULL, NULL, 0, 0, func_808000DC_chjinjo((u8 *)arg0)); }

s32 func_8080102C_chjinjo(Actor *arg0, s32 arg1) {
    if (arg0->unk74_30) {
        chjinjo_entrypoint_1(func_800D0CC8(arg0->unk6C_0), arg1);
        *(u8 *)((s8 *)arg0 + 0x74) = (*(u8 *)((s8 *)arg0 + 0x74)) & 0xFFBF;
        return 1;
    }
    return 0;
}

/* extern */

u32 func_80801098_chjinjo(Actor *arg0, s32 arg1) {
    s32 func_800D035C(s32);
    u8 func_800D0CC8(s32);
    s32 func_800D129C(u32);
    u32 func_800D1338(u32);
    s32 func_800DA298(s32);
    s32 func_800DA7A8(s32, s32, s32);
    void func_800F82D4(s32, s32);
    s32 sp2C;
    s32 temp_v0;
    s32 sp24;
    u32 sp20;

    temp_v0 = func_800D0CC8(arg0->unk6C_0);
    sp24 = temp_v0;
    arg0->unk64_19 = 0;
    arg0->unk74_30 = 0;
    arg0->actorData[4] = arg1;
    sp20 = func_800D1338(temp_v0);
    sp2C = func_800D129C(sp24) == sp20;
    if (func_800D035C(0) == 1) {
        func_800DA7A8(0x6D0, func_800D0CC8(arg0->unk6C_0), 4);
    } else if (sp2C != 0) {
        arg0->unk74_30 = 1;
        if (func_800DA298(0x43D) == 0) {
            arg0->unk64_19 = 1;
            func_800F82D4(arg0->actorData[4], 2);
        } else {
            func_80800FC4_chjinjo(arg0);
        }
    }
    return arg0->unk74_30;
}

OSThread *chjinjo_entrypoint_5(void)
{
    extern u8 D_808013A4_chjinjo[];

    return (OSThread *) D_808013A4_chjinjo;
}

OSThread *chjinjo_entrypoint_6(void)
{
    extern u8 D_808013EC_chjinjo[];

    return (OSThread *) D_808013EC_chjinjo;
}
