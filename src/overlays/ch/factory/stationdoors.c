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

void func_80800054_chfactorystationdoors(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800D90A4(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    f32 func_80103EF4(Actor *);
    extern u32 D_80800250_chfactorystationdoors[];
    extern u32 D_8080025C_chfactorystationdoors[];

    switch (arg0->unk70_10) {
        case 1:
            func_80103110(arg0, 0);
            break;
        case 2:
            if (func_800D90A4(&arg0->unk58)) {
                _subaddieaudioloop_entrypoint_2(arg0);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080025C_chfactorystationdoors);
                func_80101FDC(arg0, 3);
            } else {
                _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800250_chfactorystationdoors);
            }
            arg0->position[1] = ((f32 *)arg0->actorData)[7] + func_800F10B4(arg0->unk58, 9.0f, 0.0f, 0.0f, func_80103EF4(arg0) * 1.65f);
            break;
        case 3:
            func_80103110(arg0, 0);
            break;
    }
}

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
