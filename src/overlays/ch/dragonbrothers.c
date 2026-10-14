#include "common.h"

/* extern */

void func_80800000_chdragonbrothers(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    u8 *data;
    s32 i;

    data = func_80100094(arg0, 0);
    for (i = 0; i < 4; i++) {
        if (data[i] != 2) {
            data[i] = arg1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800070_chdragonbrothers.s")

void func_808003D8_chdragonbrothers(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_808003F8_chdragonbrothers(Actor *arg0) {
    switch (arg0->unk70_10) {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 1;
    default:
        return 0;
    }
}

/* extern */

s32 func_80800438_chdragonbrothers(Actor *arg0) {
    s32 _ncpod_entrypoint_17(s32, s32);
    s32 func_800F5EF8(s32);
    void *func_80100094(Actor *, u32);
    s32 *temp_v1;

    temp_v1 = func_80100094(arg0, 0);
    if (!arg0->unk74_29) {
        return 0;
    }
    _ncpod_entrypoint_17(func_800F5EF8(temp_v1[8]), 0);
    arg0->unk74_29 = 0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808004A4_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808005A4_chdragonbrothers.s")

/* extern */

f32 func_8080063C_chdragonbrothers(Actor *arg0) {
    void func_8008FFBC(s32);
    f32 func_800EF030(void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    void *func_80100094(Actor *, u32);
    f32 sp3C;
    f32 sp38;
    f32 sp28[4];

    sp3C = ((f32 *)func_80100094(arg0, 0))[6];
    sp38 = func_800F1DCC(sp3C, ((f32 *)arg0->actorData)[0]) * 20.0f;
    func_8008FFBC((s32)sp28);
    sp28[1] = func_800EF030(sp28);
    sp38 *= func_800F10B4(sp28[1], 0.0f, 5000.0f, 0.0f, 1.0f);
    return sp3C + sp38;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808006C8_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_808008C8_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_8080098C_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800A80_chdragonbrothers.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800B34_chdragonbrothers.s")

/* extern */

void func_80800B9C_chdragonbrothers(u8 *arg0, s32 arg1, f32 *arg2) {
    void func_80090708(s32);
    void func_80090734(s32, f32 *);
    if (arg1 != 0) {
        if (arg0[0x64] == 0) {
            func_80090734(1, arg2);
        }
    } else if (arg0[0x64] != 0) {
        func_80090708(0);
    }
    arg0[0x64] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80800C08_chdragonbrothers.s")

void func_80800D20_chdragonbrothers(u8 *arg0, s16 arg1, s32 arg2) {
    s32 func_800C05B8(s32, s32, f32*, Unk80132ED0*, s32, s32, s16);
    s32 var_v0;
    Actor *actor = (Actor *)arg0;

    arg2 |= 6;
    if (actor->unk7A_8) {
        var_v0 = 0x75;
    } else {
        var_v0 = 0x76;
    }
    func_800C05B8(arg1, arg2, actor->position, actor->unk0, 0, 0, var_v0);
    actor->unk74_30 = 1;
}

void func_80800D98_chdragonbrothers(u8 *arg0, s32 arg1) {
    s32 _gcfrontend_entrypoint_9(s32);
    s32 _plsu_entrypoint_1(s32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    s32 func_800DA9E4(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_8080098C_chdragonbrothers(u8 *, s32, s32);
    void func_80800A80_chdragonbrothers(u8 *, s32, s32, s32);
    void func_80800B9C_chdragonbrothers(u8 *, s32, f32 *);
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

void func_808012B4_chdragonbrothers(u8 *arg0, s32 arg1) {
    s32 _chintrotext_entrypoint_1(s32, s32, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800DA9E4(s32, s32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    f32 func_800F1DCC(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80800A80_chdragonbrothers(u8 *, s32, s32, s32);
    void func_80800B9C_chdragonbrothers(u8 *, s32, f32 *);
    void func_80800D20_chdragonbrothers(u8 *, s16, s32);
    f32 func_808011C0_chdragonbrothers(u8 *, s32);
    extern s32 D_808053B0_chdragonbrothers;
    extern s32 D_80805558_chdragonbrothers;
    struct Flags { u32 pad : 12; u32 flag : 1; u32 rest : 19; };
    struct State { u16 state : 6; u16 rest : 10; };
    struct Count { u8 count : 4; u8 rest : 4; };
    struct Mode { u16 rest : 7; u16 mode : 9; };
    struct ByteFlags { u8 upper : 3; u8 flag4 : 1; u8 middle : 3; u8 flag0 : 1; };
    u8 *data;
    s32 flag;
    f32 vec[3];

    data = func_80100094(arg0, 0);
    switch (((struct State *)(arg0 + 0x72))->state) {
    case 3:
    case 4:
        ((struct ByteFlags *)(arg0 + 0x65))->flag0 = 1;
        break;
    case 5:
        func_80800B9C_chdragonbrothers(data, 0, arg0 + 4);
        break;
    case 6:
        func_80800B9C_chdragonbrothers(data, 0, arg0 + 4);
        func_80800000_chdragonbrothers(arg0, 1);
        data[0x5A] = 0;
        data[0x59] = 1;
        break;
    case 23:
        ((struct ByteFlags *)(arg0 + 0x65))->flag4 = 0;
        break;
    case 15:
    case 20:
    case 21:
        data[0x5A] = 0;
        break;
    case 16:
    case 17:
        data[0x54] = 0;
        break;
    }
    func_80102424(arg0, arg1);
    switch (((struct State *)(arg0 + 0x72))->state) {
    case 5:
        func_80800A80_chdragonbrothers(arg0, 0, 0x420, 0);
        func_800FDC28(1);
        if (arg0[0x7A] & 1) {
            if (!func_800DA298(0x1D3)) {
                _chintrotext_entrypoint_1(0x18B9, 9, 1, 0);
            }
        } else {
            if (!func_800DA298(0x1D4)) {
                _chintrotext_entrypoint_1(0x18B9, 10, 1, 0);
            }
        }
        break;
    case 6:
        func_80800A80_chdragonbrothers(arg0, 5, 0x420, 0);
        func_80800B9C_chdragonbrothers(data, 1, arg0 + 4);
        func_80101EE4(arg0, 0x3F000000);
        data[0x5A] = 1;
        break;
    case 8:
        ((struct Count *)(arg0 + 0x79))->count--;
        break;
    case 9:
        if (((struct Flags *)(arg0 + 0x64))->flag) {
            *(f32 *)(arg0 + 0x58) = 0.0f;
        } else {
            *(f32 *)(arg0 + 0x58) = 0.5f;
        }
        break;
    case 10:
        if (((struct Flags *)(arg0 + 0x64))->flag) {
            *(f32 *)(arg0 + 0x58) = 1.0f;
        } else {
            *(f32 *)(arg0 + 0x58) = 2.0f;
        }
        break;
    case 11:
        flag = (arg0[0x7A] & 1) ? 0x406 : 0x407;
        ((struct Mode *)(arg0 + 0x6E))->mode = 1;
        if (((struct Flags *)(arg0 + 0x64))->flag) {
            *(f32 *)(arg0 + 0x58) = 1.5f;
        } else {
            *(f32 *)(arg0 + 0x58) = 3.0f;
        }
        data[0x5D] = 1;
        if (!func_800DA9E4(flag, 1)) {
            func_80800D98_chdragonbrothers(arg0, 12);
        }
    case 12:
        _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80805558_chdragonbrothers);
        break;
    case 14:
        func_8010A570(arg0);
        func_80800000_chdragonbrothers(arg0, 0);
        if (!func_800DA298((arg0[0x7A] & 1) ? 0x404 : 0x405)) {
            func_80800B9C_chdragonbrothers(data, 1, arg0 + 4);
            func_80800A80_chdragonbrothers(arg0, 12, 0x420, 0);
        }
        *(f32 *)(arg0 + 0x54) = func_808011C0_chdragonbrothers(arg0, 1);
        data[0x5E] = 0;
        break;
    case 16:
        ((struct Mode *)(arg0 + 0x6E))->mode = 0;
        func_8010A590(arg0);
        *(f32 *)(arg0 + 0x24) = 0.0f;
        data[0x54] = 1;
        break;
    case 17:
        if (((struct Flags *)(arg0 + 0x64))->flag) {
            *(f32 *)(arg0 + 0x34) = 45.0f;
        } else {
            *(f32 *)(arg0 + 0x34) = 30.0f;
        }
        *(f32 *)(arg0 + 0x1C) = 0.0f;
        if (func_800F1DCC(*(f32 *)(arg0 + 0x48), *(f32 *)(data + 0x18)) < 0.0f) {
            func_80800D98_chdragonbrothers(arg0, 16);
        } else {
            func_80800D98_chdragonbrothers(arg0, 14);
        }
        data[0x5B] = 0;
        data[0x54] = 1;
        break;
    case 19:
        func_8010A570(arg0);
        _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_808053B0_chdragonbrothers);
        func_80800B9C_chdragonbrothers(data, 1, arg0 + 4);
        func_80800A80_chdragonbrothers(arg0, 9, 0x420, 0);
        func_800DA544((arg0[0x7A] & 1) ? 0x1D5 : 0x1D6);
        func_80800000_chdragonbrothers(arg0, 2);
        *(f32 *)(arg0 + 0x54) = func_808011C0_chdragonbrothers(arg0, 1);
        func_80800D98_chdragonbrothers(arg0, 10);
        break;
    case 20:
        data[0x59] = 0;
        data[0x5A] = 1;
        break;
    case 15:
    case 21:
        data[0x5A] = 1;
        break;
    case 22:
        ((struct ByteFlags *)(arg0 + 0x65))->flag4 = 1;
        *(f32 *)(arg0 + 0x48) = 0.0f;
        func_80800A80_chdragonbrothers(arg0, 24, 0x420, 0);
        break;
    case 23:
        func_80800D20_chdragonbrothers(arg0, (arg0[0x7A] & 1) ? 0x12CA : 0x12CB, 1);
        vec[1] = 1500.0f;
        func_800EFCD8(vec, *(f32 *)(arg0 + 0x48), -600.0f);
        func_800EF04C((f32 *)(arg0 + 4), vec);
        func_80800D98_chdragonbrothers(arg0, 7);
        break;
    case 2:
        ((struct ByteFlags *)(arg0 + 0x65))->flag0 = 0;
        break;
    }
}

/* extern */

void func_8080183C_chdragonbrothers(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s8 *data = func_80100094(arg0, 0U);

    if (arg0->unk64_19) {
        arg0->unk79_4 = 3;
    } else {
        arg0->unk79_4 = 3;
    }
    data[0x5E]++;
    func_8010A590((u8 *)arg0);
    func_808012B4_chdragonbrothers((u8 *)arg0, 8);
}

/* extern */

void func_808018BC_chdragonbrothers(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void func_808012B4_chdragonbrothers(u8 *, s32);
    u32 *data = func_80100094(arg0, 0U);
    data[5] = 0;
    if (arg0->unk64_19) {
        arg0->unk79_4 = 4;
    } else {
        arg0->unk79_4 = 2;
    }
    func_808012B4_chdragonbrothers((u8 *)arg0, 0xE);
}

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

/* extern */

int func_80802534_chdragonbrothers(s32 arg0) {
    s32 func_8008FA2C(s32, s32);
    return (func_80090248() != 0) && (func_8008FA2C(-1, 0) != 0);
}

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
void func_80804DB8_chdragonbrothers(Actor *arg0, u32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80101FDC(Actor *, u32);
    extern s32 D_80805488_chdragonbrothers;
    extern f32 D_80805A50_chdragonbrothers[3];
    Actor **actor = &arg0;
    switch (arg0->unk70_10) {
        case 1:
            break;
        case 2:
        case 4:
            _subaddieaudioquick_entrypoint_2(*actor, D_80805A50_chdragonbrothers, &D_80805488_chdragonbrothers);
            break;
    }
    func_80101FDC(*actor, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dragonbrothers/func_80804E1C_chdragonbrothers.s")

OSThread *chdragonbrothers_entrypoint_4(void)
{
    extern u8 D_80805A5C_chdragonbrothers[];

    return (OSThread *) D_80805A5C_chdragonbrothers;
}
