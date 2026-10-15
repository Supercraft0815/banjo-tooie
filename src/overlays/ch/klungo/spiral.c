#include "common.h"

OSThread *chklungospiral_entrypoint_0(void)
{
    extern u8 D_80800620_chklungospiral[];

    return (OSThread *) D_80800620_chklungospiral;
}

/* extern */

void func_8080000C_chklungospiral(Actor *arg0) {
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    void _subaddieDll_entrypoint_2(Actor *, f32 *);
    void func_80105A9C(Actor *, f32);
    void func_80105BAC(Actor *);
    f32 sp20[6];

    _subaddiemarker_entrypoint_1(arg0, 0x154, 0x33, sp20, 1);
    _subaddieDll_entrypoint_2(arg0, sp20);
    func_80105A9C(arg0, 300.0f);
    func_80105BAC(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/spiral/func_80800060_chklungospiral.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/spiral/func_8080015C_chklungospiral.s")

/* extern */

s32 func_808002A0_chklungospiral(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 func_808002FC_chklungospiral(void *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if (((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) != 2) {
            func_808002FC_chklungospiral(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/spiral/func_808002FC_chklungospiral.s")

void func_808003AC_chklungospiral(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xC, arg2);
        case 2:
            arg0->unk6C_0 = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

int func_80800430_chklungospiral(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
        return 1;
    }
    return 0;
}

void func_80800480_chklungospiral(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    extern s32 D_80800674_chklungospiral;
    extern f32 D_80800688_chklungospiral;
    if (arg0->unk7C_12) {
        if (func_80101E4C(arg0, &D_80800688_chklungospiral) != 0) {
            func_80018820(0, 0.8f, 0.3f);
            func_800E15CC(0, 5.0f, 0.7f);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800674_chklungospiral);
            return;
        }
        if (func_80101E14(arg0, 0.7f) != 0) {
            func_80018820(0, 1.0f, 0.4f);
            func_800E15CC(0, 10.0f, 0.8f);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800674_chklungospiral);
        }
    }
}
