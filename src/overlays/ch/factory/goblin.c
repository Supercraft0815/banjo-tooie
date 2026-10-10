#include "common.h"

OSThread *chfactorygoblin_entrypoint_0(void)
{
    extern u8 D_80800298_chfactorygoblin[];

    return (OSThread *) D_80800298_chfactorygoblin;
}

/* extern */

void func_8080000C_chfactorygoblin(u8 *arg0) {
    void func_8010A3E8(void *arg0, f32 arg1);
    s32 _sucoaster_entrypoint_0(void *, s32);
    _sucoaster_entrypoint_0(arg0, 0);
    func_8010A3E8(arg0, 0.75f);
}

/* extern */

void func_8080003C_chfactorygoblin(s32 arg0, s32 arg1, s32 arg2) {
    s32 _sucoaster_entrypoint_21(s32, s32, s32);
    s32 func_8080007C_chfactorygoblin();
    if (arg1 == 0xB6) {
        func_8080007C_chfactorygoblin();
    }
    _sucoaster_entrypoint_21(arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/goblin/func_8080007C_chfactorygoblin.s")
