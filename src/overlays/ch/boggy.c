#include "common.h"

/* extern */

void func_80800000_chboggy(void *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    s32 func_80101FDC(void *, s32);
    (*(f32 *)((s8 *)(arg0) + (0x38))) = 0.18f;
    if ((func_800DA298(0x439) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_80101FDC(arg0, 3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/func_80800054_chboggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/func_808000EC_chboggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/func_80800220_chboggy.s")

void func_80800504_chboggy(Actor *arg0, s32 arg1) {
    struct Flags { u32 pad : 19; u32 active : 1; u32 rest : 12; };
    void func_800DBEFC(s32 *, s32, s32);
    void func_801018A4(Actor *, s32);
    OSThread * func_80104130(void);
    func_801018A4(arg0, arg1);
    if (((struct Flags *)((s8 *)arg0 + 0x7C))->active) {
        func_800DBEFC((s32 *)func_80104130(), 4, (s32)arg0 + 0x18);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/func_80800554_chboggy.s")

OSThread *chboggy_entrypoint_0(void)
{
    extern u8 D_80800840_chboggy[];

    return (OSThread *) D_80800840_chboggy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/func_80800634_chboggy.s")

OSThread *chboggy_entrypoint_1(void)
{
    extern u8 D_80800888_chboggy[];

    return (OSThread *) D_80800888_chboggy;
}
