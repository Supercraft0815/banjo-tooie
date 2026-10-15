#include "ch/factory/entrydoors.h"

/* extern */

void func_80800000_chfactoryentrydoors(Actor *arg0) {
    void _chdoormake_entrypoint_0(void *, f32, u32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _glcutDll_entrypoint_19(u32);
    s32 _sujiggy_entrypoint_20(u32);
    s32 func_800D3E40(s32);
    s32 func_800DA544(s32);
    void func_80101FDC(Actor *, u32);
    f32 var_f0;
    s32 var_a3;

    if (_sujiggy_entrypoint_20(5) != 0) {
        func_800DA544(0x397);
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7F) == 0)) {
        var_a3 = -1;
        func_80101FDC(arg0, 4);
    } else {
        var_a3 = 0x397;
    }
    if (arg0->unk74_7 == 0x33) {
        var_f0 = -75.0f;
    } else {
        var_f0 = 75.0f;
    }
    _chdoormake_entrypoint_0(arg0, var_f0, 0, var_a3);
    _chdoormake_entrypoint_8(arg0, 1);
    _chdoormake_entrypoint_5(arg0, 0.0f);
}

/* extern */

void func_808000CC_chfactoryentrydoors(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    s32 var_v0;

    if (arg1 == 0x95) {
        var_v0 = (arg0->unk74_7 == 0x33) ? 0x971 : 0x972;
        func_80103140(arg0, var_v0 & 0xFFFF, arg0->unk0->unk16);
    }
    _chdoor_entrypoint_1((s32)arg0, arg1, arg2);
}

OSThread *chfactoryentrydoors_entrypoint_0(void)
{
    extern u8 D_808002B0_chfactoryentrydoors[];

    return (OSThread *) D_808002B0_chfactoryentrydoors;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/entrydoors/func_8080014C_chfactoryentrydoors.s")

/* extern */

void func_808001A0_chfactoryentrydoors(u8 *arg0) {
    s32 func_800D90A4(s32);
    s32 func_800FFAB0(u8 *);
    s32 func_80101180(s32, s32, s32);
    if (func_800D90A4(arg0 + 0x58) != 0) {
        func_80101180(0x48B, 7, (s32) (*(f32 *)((s8 *)(arg0) + (0x34))));
        func_800FFAB0(arg0);
    }
}

s32 func_808001F0_chfactoryentrydoors(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    void func_80103110(Actor *, u32);
    extern s32 D_808002F8_chfactoryentrydoors;
    extern s32 D_80800390_chfactoryentrydoors;

    if (arg1 == 7) {
        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, &D_808002F8_chfactoryentrydoors);
        func_800C4AF0(arg0->position, &D_80800390_chfactoryentrydoors);
        arg0->unk64_16 = 0;
        arg0->unk58 = 2.0f;
        func_80103110(arg0, 1);
        *(f32 *)&arg0->actorData[7] = (f32) arg2;
        return 1;
    }
    return 0;
}

OSThread *chfactoryentrydoors_entrypoint_1(void)
{
    extern u8 D_808003A0_chfactoryentrydoors[];

    return (OSThread *) D_808003A0_chfactoryentrydoors;
}
