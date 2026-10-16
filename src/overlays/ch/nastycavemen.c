#include "common.h"

OSThread *chnastycavemen_entrypoint_0(void)
{
    extern u8 D_808010E8_chnastycavemen[];

    return (OSThread *) D_808010E8_chnastycavemen;
}

/* extern */

int func_8080000C_chnastycavemen(void) {
    s32 _plsu_entrypoint_1(s32);
    return (func_80090178(0x10000) != 0) &&
        (_plsu_entrypoint_1(1) == -1) &&
        (_plsu_entrypoint_1(0xB) == -1);
}

/* extern */

int func_80800060_chnastycavemen(void) {
    u32 func_800F54E4(void);
    s32 func_800F640C(s32, s32);
    s32 func_8008FE14();
    return (func_8008FE14() == 0x1D9) ||
        (func_800F640C(func_800F54E4(), 0x1D9) != 0);
}

int func_808000AC_chnastycavemen(int arg0, s32 *arg1, s32 *arg2) {
    switch (arg0) {
        default:
        case 1:
            *arg1 = 0xC5;
            *arg2 = 3;
            break;
        case 2:
            *arg1 = 0x112;
            *arg2 = 5;
            break;
        case 5:
            *arg1 = 0x112;
            *arg2 = 0xD;
            break;
    }
    return 1;
}

int func_8080010C_chnastycavemen(s32 arg0) {
    extern f32 D_80127194;
    u32 _gcgoto_entrypoint_1(u32, u32);
    s32 func_8008FD48();
    void func_800900D0(s32);
    void func_800904C8(s32);
    s32 sp24;
    s32 sp20;

    if (func_80800060_chnastycavemen() != 0) {
        func_800900D0(0x1D9);
    }
    switch (func_8008FD48()) {
        case 17:
            break;
        case 10:
        case 11:
            func_800904C8(0x97);
            break;
        default:
            func_808000AC_chnastycavemen(*(s16 *)((s8 *)&D_80127194 + 0x436), &sp24, &sp20);
            _gcgoto_entrypoint_1(sp24, sp20);
            break;
    }
    return 1;
}

/* extern */

int func_80800194_chnastycavemen(s32 arg0, s32 arg1) {
    s32 func_800F56AC(s32);
    s32 func_800F6478(s32);
    s32 func_800F64A4(s32, s32);
    s32 func_800F651C(s32);
    s32 func_800F6C5C(s32);
    int func_800F72DC(s32);
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_t8;
    s32 temp_t9;
    s32 var_v0;

    sp34 = func_800F64A4(arg1, 0x10000) == 0;
    sp30 = func_800F651C(arg1);
    sp2C = func_800F6C5C(arg1);
    sp28 = func_800F72DC(arg1);
    sp24 = func_800F56AC(arg1) == 0x10;
    return func_800F6478(arg1) && sp34 && sp24 && (sp28 || (sp2C && !sp30));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_80800268_chnastycavemen.s")

/* extern */

void func_808003FC_chnastycavemen(Actor *arg0) {
    void _glcutDll_entrypoint_17(void);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80105230();
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    void func_80105BAC(Actor *);
    void func_80800268_chnastycavemen(Actor *, s32, s32);
    f32 *data;

    data = func_80100094(arg0, 0);
    func_800EE7F8(arg0->position, data + 6);
    func_800EE7F8(arg0->rotation, data + 9);
    func_80105BAC(arg0);
    func_80105230(arg0, 0);
    func_80105834(arg0);
    func_800EE7F8(data + 6, arg0->position);
    func_800EE7F8(data + 9, arg0->rotation);
    func_800EE7F8(arg0->position, data);
    func_800EE7F8(arg0->rotation, data + 3);
    if (func_80105A5C(arg0) != 0) {
        func_80800268_chnastycavemen(arg0, 6, 1);
        _glcutDll_entrypoint_17();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_808004C4_chnastycavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_8080067C_chnastycavemen.s")

/* extern */

void func_80800968_chnastycavemen(void) {
    extern f32 D_80127194;
    s32 func_800EA090(void);
    s32 sp1C;
    sp1C = func_800EA090();
    if (((*(s16 *)((s8 *)(&D_80127194) + 0x436)) == 0) || ((sp1C != 0) && (func_80090178(0x10000) == 0))) {
        (*(s16 *)((s8 *)(&D_80127194) + 0x436)) = (s16) sp1C;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_808009BC_chnastycavemen.s")

/* extern */

void func_80800B10_chnastycavemen(Actor *arg0, void *arg1) {
    void func_800DF3E0(void);
    void func_800DF440(s32);
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);

    func_800DF3E0();
    func_800DF744(5, 2);
    func_800DF744(6, 2);
    func_800DF744(8, 1);
    func_800DF744(4, arg0->unk64_20 ? 0 : 2);
    func_800DF744(7, arg0->unk64_20 ? 2 : 0);
    if (arg0->unk70_10 == 5) {
        func_800DF440(0);
    }
    func_80101870(arg0, arg1);
}

OSThread *chnastycavemen_entrypoint_1(void)
{
    extern u8 D_808011BC_chnastycavemen[];

    return (OSThread *) D_808011BC_chnastycavemen;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_80800BE0_chnastycavemen.s")

void func_80800E68_chnastycavemen(u8 *arg0, s32 arg1) {
    extern s32 func_801017D0;
    s32 func_80101808(void *, s32 *);
    func_80101808(arg0, &func_801017D0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_80800E90_chnastycavemen.s")

void func_8080103C_chnastycavemen(s32 arg0) {
    _suexpression_entrypoint_8(arg0, 1);
}
