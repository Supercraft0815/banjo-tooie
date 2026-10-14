#include "common.h"

OSThread *chpumproomswitch_entrypoint_0(void)
{
    extern u8 D_80800380_chpumproomswitch[];

    return (OSThread *) D_80800380_chpumproomswitch;
}

OSThread *chpumproomswitch_entrypoint_1(void)
{
    extern u8 D_808003C8_chpumproomswitch[];

    return (OSThread *) D_808003C8_chpumproomswitch;
}

/* extern */

void func_80800018_chpumproomswitch(void *arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    void func_80103110(void *, s32);
    s32 func_8080016C_chpumproomswitch(u8 *);
    Actor *actor = arg0;

    if (func_800DA298(0xB2) != 0) {
        func_800DA544(func_8080016C_chpumproomswitch(arg0));
    }
    _chswitch_entrypoint_7(arg0, func_8080016C_chpumproomswitch(arg0));
    _chswitch_entrypoint_8(arg0, actor->unk74_7 == 0x32 ? 0x400 : 0x200);
    if (func_800DA298(0xB2) != 0) {
        _chswitch_entrypoint_9(arg0);
        func_80103110(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pumproomswit/func_808000BC_chpumproomswitch.s")

s32 func_8080016C_chpumproomswitch(u8 *arg0) {
    u32 value = *(u16 *)((u8 *)arg0 + 0x76);
    s32 result = 0x9E7;
    return ((value & 0xFFFF) >> 7 == 0x32) ? 0x9E6 : result;
}

/* extern */

void func_80800194_chpumproomswitch(void *arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    s32 func_80101FDC(void *, s32);
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 0.0f;
    if ((func_800DA298(0xB2) != 0) || (_glcutDll_entrypoint_19(0x20) != 0)) {
        func_80101FDC(arg0, 2);
    }
}

void func_808001E4_chpumproomswitch(Actor *arg0) {
    void func_800C31DC(u8, f32);
    u8 func_800C4350(s32, f32[3], s32 *);
    u8 func_800D9078(f32 *);
    s32 func_800EA05C();
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    extern s32 D_80800410_chpumproomswitch;
    extern s32 D_80800424_chpumproomswitch;
    s32 *var_a2;

    if (arg0->unk70_10 == 2) {
        if (arg0->unk5F == 0) {
            if (func_800EA05C() == 0xE3) {
                var_a2 = &D_80800410_chpumproomswitch;
            } else {
                var_a2 = &D_80800424_chpumproomswitch;
            }
            arg0->unk5F = func_800C4350(0U, arg0->position, var_a2);
        }
        func_800D9078(&arg0->unk58);
        func_800C31DC(arg0->unk5F, func_800F12D4(arg0->unk58, 0.0f, 3.5f, 1.0f, 0.3f));
        func_800C4350(arg0->unk5F, NULL, NULL);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pumproomswit/func_808002A0_chpumproomswitch.s")
