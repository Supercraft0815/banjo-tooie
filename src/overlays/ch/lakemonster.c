#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800000_chlakemonster.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800838_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_808008E8_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800968_chlakemonster.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801448_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801494_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_808016B0_chlakemonster.s")

OSThread *chlakemonster_entrypoint_0(void)
{
    extern u8 D_80802204_chlakemonster[];

    return (OSThread *) D_80802204_chlakemonster;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801790_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801834_chlakemonster.s")

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
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
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
                _subaddieaudioquick_entrypoint_2((s32)arg0, (s32)end, &D_808020BC_chlakemonster);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801E60_chlakemonster.s")

OSThread *chlakemonster_entrypoint_4(void)
{
    extern u8 D_808022E0_chlakemonster[];

    return (OSThread *) D_808022E0_chlakemonster;
}

/* extern */

void func_80801EA8_chlakemonster(s32 arg0) {
    s32 _chswitch_entrypoint_14(s32, s32);
    s32 func_800DA298(s32);
    s32 func_8010A570(s32);
    _chswitch_entrypoint_14(arg0, 0x187);
    if (func_800DA298(0x187) != 0) {
        func_8010A570(arg0);
    }
}

void func_80801EE4_chlakemonster(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801EEC_chlakemonster.s")

OSThread *chlakemonster_entrypoint_5(void)
{
    extern u8 D_80802328_chlakemonster[];

    return (OSThread *) D_80802328_chlakemonster;
}
