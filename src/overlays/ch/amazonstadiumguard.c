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
s32 func_80800328_chamazonstadiumguard(Actor *arg0, s32 arg1, s32 arg2) {
    extern f32 D_808006B0_chamazonstadiumguard[];
    extern s32 D_80800760_chamazonstadiumguard[];
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    s32 _glcutDll_entrypoint_20(void);
    void _suexpression_entrypoint_12(void *, f32, f32);
    void *_suexpression_entrypoint_7(Actor *, u32, u32);
    s32 func_800EA090(void);
    void func_801020DC(void *, s32);
    void func_80102424(Actor *, s32);
    void func_80103014(u8 *);
    void func_80800488_chamazonstadiumguard(Actor *, s32, s32);

    switch (arg1) {
        case 0x2E:
            func_80800488_chamazonstadiumguard(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800760_chamazonstadiumguard, arg0->scale);
            break;
        case 0x95:
            if (_glcutDll_entrypoint_20()) {
                func_80102424(arg0, 8);
            } else if (func_800EA090() == 4) {
                arg0->position[0] = D_808006B0_chamazonstadiumguard[0];
                arg0->position[2] = D_808006B0_chamazonstadiumguard[1];
                func_80103014(arg0);
                func_801020DC(arg0, 0);
                func_80102424(arg0, 6);
            }
            break;
        case 0x29:
            _suexpression_entrypoint_7(arg0, 1, 0x30);
            _suexpression_entrypoint_12(func_80100094(arg0, 1), 65.0f, 15.0f);
            break;
        case 0x2A:
            if (func_80100094(arg0, 1) != 0) {
                _suexpression_entrypoint_8(arg0, 1);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800488_chamazonstadiumguard(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800C01A8(s16, s32);
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void func_80102424(Actor *, s32);

    switch (arg1) {
        case 0xF0A:
            func_800C01A8(0x64, 0);
            _capod_entrypoint_13(arg0->unk0, NULL, 0x24, 0x2010);
            func_80102424(arg0, 5);
            return;
        case 0xF0C:
            func_80102424(arg0, 6);
            return;
        case 0xF09:
        case 0xF0B:
            func_80102424(arg0, 3);
            return;
    }
}

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
