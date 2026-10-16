#include "common.h"

/* extern */

void func_80800000_chlakemonster(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_80801494_chlakemonster(s32, s32);
    func_800EFA4C((f32 *)(arg0 + 4), 0.0f, -3050.0f, 0.0f);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80801494_chlakemonster(arg0, 7);
        return;
    }
    func_80801494_chlakemonster(arg0, 1);
}

void func_80800064_chlakemonster(Actor *arg0) {
    u32 func_800FDC28(u32);
    u32* func_80100074(Actor*, u32, u32);
    func_80100074(arg0, 0U, 0U);
    func_800FDC28(0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800090_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_808001C0_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_808002FC_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800404_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_8080064C_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800724_chlakemonster.s")

/* extern */

void func_80800838_chlakemonster(Actor *arg0) {
    s32 _dbmorph_entrypoint_4(u8 *, u8 *, s32, u8, s32);
    s32 func_800AE080(s16);
    s32 func_800AE0E8(s16);
    u8 *func_800B2768(u8 *);
    s32 func_800B2840(s32);
    s32 func_801015D0(Actor *);
    s32 func_801039E4(Unk80132ED0 *);
    s32 func_80103CB8(Actor *, u32);
    s32 func_80800724_chlakemonster(Actor *);
    s32 sp34;
    u8 *sp30;
    struct {
        u8 pad[0x17];
        u8 unused : 7;
        u8 active : 1;
    } *sp2C;
    s32 sp28;

    sp34 = func_801039E4(arg0->unk0);
    sp30 = func_800B2768(sp34);
    sp2C = func_80103CB8(arg0, sp34);
    sp28 = func_800B2840(sp34);
    func_80800724_chlakemonster(arg0);
    if (func_801015D0(arg0)) {
    }
    sp2C->active = 1;
    if (func_800AE0E8(*(s16 *)&arg0->unk0->unk10) != 0) {
        _dbmorph_entrypoint_4(sp30, sp2C, sp28, 1, func_800AE080(*(s16 *)&arg0->unk0->unk10));
    }
}

void func_808008E8_chlakemonster(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800D8FF8(void);
    void *func_80100094(Actor *, u32);
    extern s32 D_80802030_chlakemonster;
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (*(f32 *)((s8 *)temp_v0 + 0x24) <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &D_80802030_chlakemonster);
        *(f32 *)((s8 *)temp_v0 + 0x24) = 2.5f;
    } else {
        *(f32 *)((s8 *)temp_v0 + 0x24) -= func_800D8FF8();
    }
}

void func_80800968_chlakemonster(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void *func_80100094(Actor *, u32);
    extern s32 D_80802044_chlakemonster;
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (*(f32 *)((s8 *)temp_v0 + 0x28) <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &D_80802044_chlakemonster);
        *(f32 *)((s8 *)temp_v0 + 0x28) = 1.5f;
    }
}

/* extern */

void func_808009CC_chlakemonster(void) {
    s32 _gcgoto_entrypoint_1(s32, s32);
    s32 func_800DA544(s32);
    s32 func_800F54E4();
    s32 func_800F7C9C(s32, s32, s32, s32);
    func_800F7C9C(func_800F54E4(), 0x95, 0x116, 0xA);
    _gcgoto_entrypoint_1(0x123, 1);
    func_800DA544(0x6E8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800A14_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800C88_chlakemonster.s")

void func_808013E8_chlakemonster(s32 *arg0) {
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, s32);
    s32 func_8008F938(s32);
    s32 func_8008F964(s32 *);
    s32 func_8008F9C4(s32 *, s32);
    extern s32 D_808020D4_chlakemonster;
    extern s32 func_8010D5DC;
    func_8008F8B0();
    func_8008F964(&D_808020D4_chlakemonster);
    func_8008F8D8(0);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *arg0);
    func_8008F9C4(&D_808020D4_chlakemonster, 0x3F400000);
}

void func_80801448_chlakemonster(u8 *arg0, u32 arg1, s32 arg2) {
    struct Flags { u8 pad[0x74]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    arg2 |= 7;
    _subaddiedialog_entrypoint_11((*(Unk80132ED0 **)((s8 *)(arg0) + (0))), arg1, arg2, (f32 *)(arg0 + 4), 0xB3U);
    ((struct Flags *)arg0)->flag = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801494_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_808016B0_chlakemonster.s")

OSThread *chlakemonster_entrypoint_0(void)
{
    extern u8 D_80802204_chlakemonster[];

    return (OSThread *) D_80802204_chlakemonster;
}

void func_80801790_chlakemonster();
void func_80801790_chlakemonster(Actor *arg0, u32 arg1) {
    struct Flags { u8 pad[0x7E]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    void func_80101FDC(Actor *, u32);
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);

    func_80101FDC(arg0, arg1);
    switch (arg0->unk70_10) {
        case 1:
            arg0->position[1] = -1000.0f;
            break;
        case 3:
            ((struct Flags *)arg0)->flag = 0;
            arg0->position[1] = 0.0f;
            break;
        case 2:
            _capod_entrypoint_13(arg0->unk0, NULL, 0, 0x10);
            *(f32 *)&arg0->actorData[7] = 0.0f;
            arg0->unk50 = 50.0f;
            break;
    }
}

/* extern */

void func_80801834_chlakemonster(s16 *arg0) {
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80801790_chlakemonster();

    func_800EE7F8((f32 *)(arg0 + 12), (f32 *)(arg0 + 2));
    func_800EFA4C((f32 *)(arg0 + 2), 0.0f, 0.0f, 0.0f);
    if (func_800DA298(0x187) != 0) {
        func_80801790_chlakemonster(arg0, 3);
        return;
    }
    func_80801790_chlakemonster(arg0, 1);
}

void func_808018AC_chlakemonster(s32 arg0) 
{
}
/* extern */

void chlakemonster_entrypoint_1(s32 arg0) {
    s32 _fxripple_entrypoint_0(s32);
    _fxripple_entrypoint_0(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/chlakemonster_entrypoint_2.s")

void chlakemonster_entrypoint_3(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 func_800B53A4(s32);
    s32 func_800BA1D0(s32, void *, void *, s32);
    s32 func_800BABB8(s32, void *, s32, s32, s32 *);
    extern s32 D_8080229C_chlakemonster;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(3);
    sp24 = temp_v0;
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) ((*(f32 *)((s8 *)(arg1) + (4))) + 200.0f);
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) ((*(f32 *)((s8 *)(arg0) + (4))) + 200.0f);
    func_800BABB8(temp_v0, arg1, 0, 0x3F800000, &D_8080229C_chlakemonster);
    func_800BA1D0(sp24, arg0, arg1, 3);
}

void func_80801A60_chlakemonster(void *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void chlakemonster_entrypoint_2(void *, void *, s32, s32);
    s32 func_800C2FDC(u8);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    u8 func_800C4350(s32, s32, s32 *);
    f32 func_800D8FF8(void);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern s32 D_808020BC_chlakemonster;
    extern s32 D_808022C8_chlakemonster;
    f32 start[3];
    f32 end[3];

    switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
    case 1:
        break;
    case 2:
        if (*(f32 *)((u8 *)arg0 + 8) >= 0.0f) {
            func_80801790_chlakemonster(arg0, 3);
            return;
        }
        *(f32 *)((u8 *)arg0 + 8) += func_800D8FF8() * *(f32 *)((u8 *)arg0 + 0x50);
        *(f32 *)((u8 *)arg0 + 0x50) += 5.0f;
        if (func_8001210C(1)) {
            start[1] = *(f32 *)((u8 *)arg0 + 8) + -3050.0f;
            end[1] = start[1];
            switch (func_800DC128(0, 3)) {
            case 0:
                start[0] = 30.0f;
                start[2] = 735.0f;
                end[0] = 504.0f;
                end[2] = 1423.0f;
                chlakemonster_entrypoint_2(start, end, 0x42480000, 0xC53EA000);
                chlakemonster_entrypoint_3(start, end, 0x42480000, 0xC53EA000);
                break;
            case 1:
                end[0] = 504.0f;
                end[2] = 1423.0f;
                start[0] = -194.0f;
                start[2] = 2263.0f;
                chlakemonster_entrypoint_2(start, end, 0x42480000, 0xC53EA000);
                chlakemonster_entrypoint_3(start, end, 0x42480000, 0xC53EA000);
                break;
            case 2:
                start[0] = -194.0f;
                start[2] = 2263.0f;
                end[0] = 4.0f;
                end[2] = 3081.0f;
                chlakemonster_entrypoint_2(start, end, 0x42480000, 0xC53EA000);
                chlakemonster_entrypoint_3(start, end, 0x42480000, 0xC53EA000);
                break;
            }
            if (*(f32 *)((u8 *)arg0 + 0x58) <= 0.0f) {
                _subaddieaudioquick_entrypoint_2(arg0, end, &D_808020BC_chlakemonster);
                *(f32 *)((u8 *)arg0 + 0x58) = func_800DC178(1.0f, 2.0f) * 0.15f;
            } else {
                *(f32 *)((u8 *)arg0 + 0x58) -= func_800D8FF8();
            }
        }
        if (*((u8 *)arg0 + 0x5F) == 0) {
            *((u8 *)arg0 + 0x5F) = func_800C4350(0, (s32)((u8 *)arg0 + 4), &D_808022C8_chlakemonster);
        } else {
            if (*(f32 *)((u8 *)arg0 + 8) < -750.0f) {
                *(f32 *)((u8 *)arg0 + 0x34) = func_800F10B4(*(f32 *)((u8 *)arg0 + 8), -1000.0f, -850.0f, 0.0f, 32000.0f);
            }
            *(f32 *)((u8 *)arg0 + 0x54) = func_800F10B4(*(f32 *)((u8 *)arg0 + 8), -1000.0f, 0.0f, 0.05f, 1.0f);
            func_800C3058(*((u8 *)arg0 + 0x5F), (s32)*(f32 *)((u8 *)arg0 + 0x34));
            func_800C31DC(*((u8 *)arg0 + 0x5F), *(f32 *)((u8 *)arg0 + 0x54));
            func_800C4350(*((u8 *)arg0 + 0x5F), (s32)((u8 *)arg0 + 0x18), NULL);
        }
        break;
    case 3:
        if (*((u8 *)arg0 + 0x5F) != 0) {
            if (*(f32 *)((u8 *)arg0 + 0x34) > 500.0f) {
                *(f32 *)((u8 *)arg0 + 0x34) *= 0.7f;
                if (*(f32 *)((u8 *)arg0 + 0x54) > 0.05f) {
                    *(f32 *)((u8 *)arg0 + 0x54) *= 0.7f;
                }
                func_800C3058(*((u8 *)arg0 + 0x5F), (s32)*(f32 *)((u8 *)arg0 + 0x34));
                func_800C31DC(*((u8 *)arg0 + 0x5F), *(f32 *)((u8 *)arg0 + 0x54));
                func_800C4350(*((u8 *)arg0 + 0x5F), (s32)((u8 *)arg0 + 0x18), NULL);
            } else {
                func_800C2FDC(*((u8 *)arg0 + 0x5F));
                *((u8 *)arg0 + 0x5F) = 0;
            }
        }
        break;
    }
}

int func_80801E60_chlakemonster(Actor *arg0, s32 arg1, s32 arg2) {
    switch (arg1) {
        case 7:
            func_80801790_chlakemonster((s16 *) arg0, 2);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chlakemonster_entrypoint_4(void)
{
    extern u8 D_808022E0_chlakemonster[];

    return (OSThread *) D_808022E0_chlakemonster;
}

/* extern */

void func_80801EA8_chlakemonster(s32 arg0) {
    s32 _chswitch_entrypoint_14(s32, s32);
    s32 func_800DA298(s32);
    _chswitch_entrypoint_14(arg0, 0x187);
    if (func_800DA298(0x187) != 0) {
        func_8010A570(arg0);
    }
}

void func_80801EE4_chlakemonster(s32 arg0) 
{
}
s32 func_80801EEC_chlakemonster(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x301, 7, 0);
        func_8010A570(arg0);
    } else {
        return 0;
    }
    return 1;
}

OSThread *chlakemonster_entrypoint_5(void)
{
    extern u8 D_80802328_chlakemonster[];

    return (OSThread *) D_80802328_chlakemonster;
}
