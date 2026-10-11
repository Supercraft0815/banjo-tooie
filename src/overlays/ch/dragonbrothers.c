#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800000_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800070_chdragonbrothers.s")

void func_808003D8_chdragonbrothers(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808003F8_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800438_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808004A4_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808005A4_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_8080063C_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808006C8_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808008C8_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_8080098C_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800A80_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800B34_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800B9C_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800C08_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800D20_chdragonbrothers.s")

void func_80800D98_chdragonbrothers(u8 *arg0, s32 arg1) {
    s32 _gcfrontend_entrypoint_9(s32);
    s32 _plsu_entrypoint_1(s32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    s32 func_800DA9E4(s32, s32);
    u8 *func_80100094(u8 *, u32);
    void func_8080098C_chdragonbrothers(u8 *, s32, s32);
    void func_80800A80_chdragonbrothers(u8 *, s32, s32, s32);
    void func_80800B9C_chdragonbrothers(u8 *, s32, u8 *);
    void func_80800D20_chdragonbrothers(u8 *, s16, s32);
    u8 *data;
    s16 introText;
    s16 text;

    data = func_80100094(arg0, 0);
    if (*(s32 *)(data + 0x10) == 4) {
        *(s32 *)(data + 0x20) = _plsu_entrypoint_1(1);
    }
    *(s32 *)(data + 0x10) = arg1;
    switch (arg1) {
    case 1:
        _gcfrontend_entrypoint_9((arg0[0x7A] & 1) ? 0x29 : 0x2A);
        if (arg0[0x7A] & 1) {
            if (func_800DA9E4(0x1D3, 1) == 0) {
                if (func_800DA298(0x1D6)) {
                    introText = 0x129C;
                } else if (func_800DA298(0x1D4)) {
                    introText = 0x129A;
                } else {
                    introText = 0x1296;
                }
            } else {
                introText = 0x1298;
            }
        } else {
            if (func_800DA9E4(0x1D4, 1) == 0) {
                if (func_800DA298(0x1D5)) {
                    introText = 0x129D;
                } else if (func_800DA298(0x1D3)) {
                    introText = 0x129B;
                } else {
                    introText = 0x1297;
                }
            } else {
                introText = 0x1299;
            }
        }
        if (introText != 0) {
            func_80800D20_chdragonbrothers(arg0, introText, 1);
        }
        break;
    case 5:
        data[0x58] = 3;
        func_80800B9C_chdragonbrothers(data, 1, arg0 + 4);
        func_80800A80_chdragonbrothers(arg0, 2, 0x420, 0);
        break;
    case 6:
        func_80800D20_chdragonbrothers(arg0, (arg0[0x7A] & 1) ? 0x12A5 : 0x12A6, 1);
        func_8080098C_chdragonbrothers(arg0, 2, 1);
        break;
    case 3:
        if (arg0[0x7A] & 1) {
            if (func_800DA298(0x1D6)) {
                func_800DA544(0x1D2);
                text = 0x12A3;
            } else {
                text = 0x12A1;
            }
        } else {
            if (func_800DA298(0x1D5)) {
                func_800DA524(0x1D2);
                text = 0x12A4;
            } else {
                text = 0x12A2;
            }
        }
        func_8080098C_chdragonbrothers(arg0, 2, 1);
        func_80800D20_chdragonbrothers(arg0, text, 1);
        break;
    case 8:
        func_800FDC28(0);
        data[0x58] = 1;
        if (func_800D395C()) {
            func_80800A80_chdragonbrothers(arg0, 0x14, 0x420, 0);
        } else {
            func_80800A80_chdragonbrothers(arg0, 0x14, 0x400, 0);
        }
        break;
    case 11:
        *(f32 *)(arg0 + 0x58) = 3.0f;
        break;
    case 12:
        func_80800A80_chdragonbrothers(arg0, 0x1D, 0x430, 0);
        break;
    case 13:
        func_80800B9C_chdragonbrothers(data, 1, arg0 + 4);
        func_80800D20_chdragonbrothers(arg0, (arg0[0x7A] & 1) ? 0x12AE : 0x12AF, 1);
        break;
    case 14:
    case 15:
        data[0x5B]++;
    case 16:
    case 17:
        *(f32 *)(arg0 + 0x58) = 0.0f;
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_8080110C_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808011C0_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808012B4_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_8080183C_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808018BC_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80801924_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80801A4C_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80801C44_chdragonbrothers.s")

/* extern */

void func_80801CEC_chdragonbrothers(void *arg0) {
    f32 func_800F1DCC(f32, f32);
    s32 func_80801A4C_chdragonbrothers(void *, f32);
    func_80801A4C_chdragonbrothers(arg0, func_800F1DCC((*(f32 *)((s8 *)(arg0) + (0x54))), (*(f32 *)((s8 *)(arg0) + (0x48)))));
    func_80801A4C_chdragonbrothers(arg0, func_800F1DCC((*(f32 *)((s8 *)(arg0) + (0x54))), (*(f32 *)((s8 *)(arg0) + (0x48)))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80801D40_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80802534_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80802574_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808034DC_chdragonbrothers.s")

OSThread *chdragonbrothers_entrypoint_0(void)
{
    extern u8 D_808056A8_chdragonbrothers[];

    return (OSThread *) D_808056A8_chdragonbrothers;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80803574_chdragonbrothers.s")

void func_808036E4_chdragonbrothers(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808036EC_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808037B0_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808038AC_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80803DC4_chdragonbrothers.s")

/* extern */

void func_80803EFC_chdragonbrothers(void *arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(1, (u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) << 0xB) >> 0x1F);
    func_80101870(arg0, arg1);
}

OSThread *chdragonbrothers_entrypoint_1(void)
{
    extern u8 D_8080574C_chdragonbrothers[];

    return (OSThread *) D_8080574C_chdragonbrothers;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80803F4C_chdragonbrothers.s")

void func_808040A0_chdragonbrothers(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808040A8_chdragonbrothers.s")

/* extern */

void func_80804318_chdragonbrothers(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(1, 1);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80804350_chdragonbrothers.s")

OSThread *chdragonbrothers_entrypoint_2(void)
{
    extern u8 D_808058A8_chdragonbrothers[];

    return (OSThread *) D_808058A8_chdragonbrothers;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_8080449C_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80804610_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808046CC_chdragonbrothers.s")

void func_808048A4_chdragonbrothers(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808048AC_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808049D4_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80804AA4_chdragonbrothers.s")

s32 func_80804C6C_chdragonbrothers(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0xF) {
        return 0;
    }
    return 1;
}

/* extern */

void func_80804C90_chdragonbrothers(s32 arg0, s32 arg1) {
    s32 _subaddiedraw25d_entrypoint_2(s32, s32);
    s32 func_800E24D8(s32);
    func_800E24D8(1);
    _subaddiedraw25d_entrypoint_2(arg0, arg1);
}

OSThread *chdragonbrothers_entrypoint_3(void)
{
    extern u8 D_80805A08_chdragonbrothers[];

    return (OSThread *) D_80805A08_chdragonbrothers;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80804CD0_chdragonbrothers.s")

void func_80804DB0_chdragonbrothers(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80804DB8_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80804E1C_chdragonbrothers.s")

OSThread *chdragonbrothers_entrypoint_4(void)
{
    extern u8 D_80805A5C_chdragonbrothers[];

    return (OSThread *) D_80805A5C_chdragonbrothers;
}
