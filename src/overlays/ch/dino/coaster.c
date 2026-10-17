#include "common.h"

OSThread *chdinocoaster_entrypoint_0(void)
{
    extern u8 D_808004E0_chdinocoaster[];

    return (OSThread *) D_808004E0_chdinocoaster;
}

/* extern */

void func_8080000C_chdinocoaster(void *arg0) {
    s32 _sucoaster_entrypoint_0(void *, s32);
    s32 func_80102FDC(void *, f32);
    _sucoaster_entrypoint_0(arg0, 0);
    func_80102FDC(arg0, (*(f32 *)((s8 *)(arg0) + (0x38))) * 1.25f);
    (*(f32 *)((s8 *)(arg0) + (0x50))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/coaster/func_80800064_chdinocoaster.s")

s32 func_808001C8_chdinocoaster(Actor *arg0, s32 arg1, s32 arg2) {
    extern s32 D_80800468_chdinocoaster[];
    extern s32 D_80800544_chdinocoaster[];
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_5(f32 *);
    s32 _sucoaster_entrypoint_21(Actor *, s32, s32);
    void func_8009032C(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80101074(void *);
    void func_80101FDC(Actor *, u32);
    void func_8010A590(Actor *);
    f32 func_8010CD28(Actor *);
    f32 sp2C[3];

    switch (arg1) {
        case 0x2E:
            func_80101FDC(arg0, 0x14);
            func_8010A590(arg0);
            if (((s16 *)&arg2)[0] == 0x17B8) {
                func_8009032C(0x20);
            }
            break;
        case 0x38:
            func_80101074(D_80800468_chdinocoaster);
            return 0xA;
        case 0x52:
            func_800EFA4C(sp2C, 0.0f, func_8010CD28(arg0), 0.0f);
            _gcdialogcamera_entrypoint_3(D_80800544_chdinocoaster, arg0->scale);
            _gcdialogcamera_entrypoint_5(sp2C);
            break;
        case 0x95:
            arg0->unk64_20 = 0;
        default:
            return _sucoaster_entrypoint_21(arg0, arg1, arg2);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/coaster/func_808002CC_chdinocoaster.s")
