#include "common.h"

OSThread *chamazonstadiumguard_entrypoint_0(void)
{
    extern u8 D_80800700_chamazonstadiumguard[];

    return (OSThread *) D_80800700_chamazonstadiumguard;
}

void func_8080000C_chamazonstadiumguard(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x28))) = (f32) (*(f32 *)((s8 *)(arg0) + (4)));
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0x30))) = (f32) (*(f32 *)((s8 *)(arg0) + (0xC)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazonstadiumguard/func_80800028_chamazonstadiumguard.s")

void func_808002F4_chamazonstadiumguard(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazonstadiumguard/func_80800328_chamazonstadiumguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazonstadiumguard/func_80800488_chamazonstadiumguard.s")

/* extern */

void func_80800530_chamazonstadiumguard(Actor *arg0) {
    s32 func_800DA298(GameFlag);
    void func_80102424(Actor *, s32);
    s32 func_8010CAC0(f32 *, u32);
    s32 func_8010D278();
    s32 func_8010D284();

    if ((func_8010CAC0(arg0->position, 0x1F4) != 0) && (func_8010D284() != 5) && (func_8010D284() != 0xA)) {
        if (func_8010D278() == 8) {
            func_80102424(arg0, func_800DA298(0x59) ? 5 : 2);
            return;
        }
        func_80102424(arg0, 2);
    }
}

void func_808005CC_chamazonstadiumguard(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 func_8010D278();
    extern s32 D_80800770_chamazonstadiumguard;
    extern s32 D_8080078C_chamazonstadiumguard;
    if (func_8010D278() == 8) {
        _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80800770_chamazonstadiumguard);
        return;
    }
    _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_8080078C_chamazonstadiumguard);
}

void func_80800620_chamazonstadiumguard(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    extern s32 D_808007A8_chamazonstadiumguard;
    _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_808007A8_chamazonstadiumguard);
}

void func_80800648_chamazonstadiumguard(Actor *arg0) {
    extern u32 D_808007C4_chamazonstadiumguard;
    extern u32 D_808007D0_chamazonstadiumguard;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808007C4_chamazonstadiumguard, &D_808007D0_chamazonstadiumguard);
}
