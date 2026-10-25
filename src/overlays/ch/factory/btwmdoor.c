#include "common.h"

/* extern */

void func_80800000_chfactorybtwmdoor(Actor *arg0) {
    u32 func_800F54E4(void);
    s32 func_800F64A4(s32, s32);
    s32 func_8010C500(Actor *);
    *(f32 *)&arg0->actorData[7] = arg0->position[1];
    if (func_8010C500(arg0) && func_800F64A4(func_800F54E4(), 0x40)) {
        arg0->unk58 = 3.0f;
    } else {
        arg0->unk58 = 0.0f;
    }
}

void func_80800068_chfactorybtwmdoor(Actor *arg0) {
    s32 _chmrtannoy_entrypoint_0(void);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800D90A4(f32 *);
    int func_800D91EC(f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(s32, s32);
    void func_80101FDC(Actor *, u32);
    f32 func_80103EF4(Actor *);
    s32 func_8010C500(Actor *);
    extern u32 D_80800320_chfactorybtwmdoor[];
    extern u32 D_8080032C_chfactorybtwmdoor[];
    extern u32 D_80800338_chfactorybtwmdoor[];

    switch (arg0->unk70_10) {
        case 1:
            if (func_800D90A4((f32 *)&arg0->actorData[3])) {
                *(f32 *)&arg0->actorData[3] = 0.5f;
                if (func_8010C500(arg0) && arg0->unk58 != 3.0f) {
                    if (func_800F64A4(func_800F54E4(), 0x40)) {
                        if (!arg0->unk74_30) {
                            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1336, 7, arg0->position, 0xA3);
                            arg0->unk74_30 = 1;
                            _chmrtannoy_entrypoint_0();
                        }
                        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800338_chfactorybtwmdoor);
                        func_80101FDC(arg0, 2);
                    } else if (!arg0->unk74_29) {
                        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1335, 7, arg0->position, 0xA3);
                        arg0->unk74_29 = 1;
                        _chmrtannoy_entrypoint_0();
                    }
                } else if ((!func_8010C500(arg0) || !func_800F64A4(func_800F54E4(), 0x40)) && arg0->unk58 != 0.0f) {
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800338_chfactorybtwmdoor);
                    func_80101FDC(arg0, 3);
                }
            }
            break;
        case 2:
            if (func_800D91EC(&arg0->unk58, 3.0f)) {
                *(f32 *)&arg0->actorData[3] = 0.5f;
                _subaddieaudioloop_entrypoint_2(arg0);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080032C_chfactorybtwmdoor);
                func_80101FDC(arg0, 1);
            } else {
                _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800320_chfactorybtwmdoor);
            }
            break;
        case 3:
            if (func_800D90A4(&arg0->unk58)) {
                *(f32 *)&arg0->actorData[3] = 0.5f;
                _subaddieaudioloop_entrypoint_2(arg0);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080032C_chfactorybtwmdoor);
                func_80101FDC(arg0, 1);
            } else {
                _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800320_chfactorybtwmdoor);
            }
            break;
    }
    arg0->position[1] = *(f32 *)&arg0->actorData[7] + func_800F10B4(arg0->unk58, 0.0f, 3.0f, 0.0f, func_80103EF4(arg0));
}

OSThread *chfactorybtwmdoor_entrypoint_0(void)
{
    extern u8 D_80800344_chfactorybtwmdoor[];

    return (OSThread *) D_80800344_chfactorybtwmdoor;
}
