#include "common.h"

/* extern */

void func_80800000_chfactorystationdoors(Actor *arg0) {
    s32 _glcutDll_entrypoint_19(u32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    if (_glcutDll_entrypoint_19(0x44) == 0) {
        if (func_800DA298(0x163) != 0) {
            func_800FFAB0(arg0);
            return;
        }
        func_80101FDC(arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/stationdoors/func_80800054_chfactorystationdoors.s")

/* extern */

void func_80800158_chfactorystationdoors(s32 arg0, s32 arg1) {
    s32 func_800DF500(f32, f32, s32);
    s32 func_80101870(s32, s32);
    func_800DF500(1.07f, 1.65f, 0x3F800000);
    func_80101870(arg0, arg1);
}

s32 func_8080019C_chfactorystationdoors(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _glcutDll_entrypoint_19(u32);
    void func_80101FDC(Actor *, u32);

    if ((arg1 == 0x49) && (_glcutDll_entrypoint_19(0x44) != 0)) {
        ((f32 *)arg0->actorData)[7] = arg0->position[1];
        func_80101FDC(arg0, 2);
        arg0->unk58 = 9.0f;
        if (arg0->rotation[1] == 90.0f) {
            _capod_entrypoint_13(arg0->unk0, NULL, 5, 0x900);
        }
        return 1;
    }
    return 0;
}

OSThread *chfactorystationdoors_entrypoint_0(void)
{
    extern u8 D_80800268_chfactorystationdoors[];

    return (OSThread *) D_80800268_chfactorystationdoors;
}
