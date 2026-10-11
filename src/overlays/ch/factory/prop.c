#include "common.h"

OSThread *chfactoryprop_entrypoint_0(void)
{
    extern u8 D_80800C20_chfactoryprop[];

    return (OSThread *) D_80800C20_chfactoryprop;
}

OSThread *chfactoryprop_entrypoint_1(void)
{
    extern u8 D_80800C68_chfactoryprop[];

    return (OSThread *) D_80800C68_chfactoryprop;
}

OSThread *chfactoryprop_entrypoint_2(void)
{
    extern u8 D_80800CB0_chfactoryprop[];

    return (OSThread *) D_80800CB0_chfactoryprop;
}

void func_80800024_chfactoryprop(u8 *arg0) {
    s32 _subaddiefade_entrypoint_14(s32);
    s32 func_8010A63C(s32);
    (*(f32 *)((s8 *)(arg0) + (0x34))) = 1.0f;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 1.0f;
    _subaddiefade_entrypoint_14((s32) arg0);
    func_8010A63C((s32) arg0);
    (*(f32 *)((s8 *)(arg0) + (0x44))) = 30.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/prop/func_80800070_chfactoryprop.s")

/* extern */

void func_808001D8_chfactoryprop(void *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    (*(u8 *)((s8 *)(arg0) + (0x18))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x18))));
    (*(u8 *)((s8 *)(arg0) + (0x1C))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x1C))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/prop/func_80800214_chfactoryprop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/prop/func_80800324_chfactoryprop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/prop/chfactoryprop_entrypoint_3.s")

void func_80800674_chfactoryprop(u8 *arg0) {
    u8 _subaddieaudioquick_entrypoint_1(u8 *, u8 *);
    void func_8008FE68(f32 *);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    u8 func_800C4350(s32, u8 *, s32 *);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    f32 func_800D8FF8(void);
    s32 func_800D9154(f32 *, f32);
    s32 func_800DB9B0(void);
    f32 func_800DC178(f32, f32);
    void func_800E3980(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    s32 func_800F54E4(void);
    s32 func_800F55FC(s32);
    extern s32 D_80800D08_chfactoryprop;
    extern s32 D_80800D14_chfactoryprop;
    f32 sp54;
    f32 sp48[3];
    f32 temp_f12;
    f32 temp_f12_2;
    s32 sp3C;
    s32 sp38;

    if (func_800DB9B0() == 0) {
        sp38 = func_800F55FC(func_800F54E4());
        func_8008FE68(sp48);
        if (sp38 & 0x08000000) {
            *(f32 *)(arg0 + 0x34) = 0.3f;
        } else if (sp38 & 0x30000000) {
            *(f32 *)(arg0 + 0x34) = func_800F10B4(sp48[2], -1200.0f, -2400.0f, 1.0f, 0.3f);
        } else {
            *(f32 *)(arg0 + 0x34) = 1.0f;
        }
    } else {
        *(f32 *)(arg0 + 0x34) = 1.0f;
        func_800E3980(sp48);
    }
    *(f32 *)(arg0 + 0x24) = func_800F15F8(*(f32 *)(arg0 + 0x24), *(f32 *)(arg0 + 0x34), func_800D8FF8());
    temp_f12 = *(f32 *)(arg0 + 4) - sp48[0];
    if (temp_f12 < 0.0f) {
        sp3C = (s32)func_800F10B4(temp_f12, 0.0f, -8000.0f, 32767, 14000.0f);
    } else {
        sp3C = (s32)func_800F10B4(temp_f12, 0.0f, 2000.0f, 32767, 0);
    }
    if (arg0[0x5F] == 0) {
        arg0[0x5F] = func_800C4350(0, arg0 + 4, &D_80800D08_chfactoryprop);
    }
    sp54 = func_800F12D4(*(f32 *)(arg0 + 0x28), 0.0f, 400.0f, 0.4f, 1.0f);
    temp_f12_2 = func_800F12D4(*(f32 *)(arg0 + 0x28), 0.0f, 400.0f, 0.4f, 1.0f);
    sp3C *= *(f32 *)(arg0 + 0x24) * temp_f12_2;
    func_800C31DC(arg0[0x5F], sp54);
    func_800C3058(arg0[0x5F], sp3C);
    func_800C4350(arg0[0x5F], arg0 + 4, NULL);
    if (func_800D9154((f32 *)(arg0 + 0x30), func_800F10B4(*(f32 *)(arg0 + 0x28), 0.0f, 400.0f, 0.8f, 0.3f)) != 0) {
        temp_f12_2 = *(f32 *)(arg0 + 0x28);
        if ((temp_f12_2 > 80.0f) && (sp3C != 0)) {
            if (arg0[0x18] == 0) {
                arg0[0x18] = _subaddieaudioquick_entrypoint_1(arg0, arg0 + 4);
            }
            sp54 = func_800F12D4(*(f32 *)(arg0 + 0x28), 0.0f, 400.0f, 0.2f, 0.5f) + func_800DC178(-0.05f, 0.05f);
            func_800C4B70((s32)(*(f32 *)(arg0 + 0x24) * (f32)sp3C));
            func_800C4B64(sp54);
            func_800C4350(arg0[0x18], arg0 + 4, &D_80800D14_chfactoryprop);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/prop/func_80800988_chfactoryprop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/prop/func_80800B44_chfactoryprop.s")
