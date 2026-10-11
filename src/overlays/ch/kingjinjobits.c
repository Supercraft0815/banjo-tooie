#include "common.h"

OSThread *chkingjinjobits_entrypoint_0(void)
{
    extern u8 D_80800A80_chkingjinjobits[];

    return (OSThread *) D_80800A80_chkingjinjobits;
}

void func_8080000C_chkingjinjobits(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjobits/func_80800014_chkingjinjobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjobits/func_8080029C_chkingjinjobits.s")

void func_80800354_chkingjinjobits(Actor *arg0) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _capod_entrypoint_2(s32, s32, s32);
    s32 _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    s32 _gcdialogcamera_entrypoint_8(void);
    s32 _glcutDll_entrypoint_19(s32);
    s32 _subaddieDll_entrypoint_1(Actor *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    void func_800BF744(s32, s32);
    s32 func_800D0B68(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    s32 func_800DB9B0(void);
    s32 func_800EA05C(void);
    s32 func_800EA090(void);
    u32 func_800EA364(void);
    void func_800F497C(s32);
    void func_800F49A8(s32, s32);
    void func_800F49D4(s32, void *, s32);
    void func_800F4A58(s32, s32, f32);
    s32 func_800F54E4(void);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    extern s32 func_8010D5DC;
    s32 active;
    s32 flag360;
    s32 flag3B;
    s32 flag5A;
    s32 cameraFlags;
    f32 rotation[3];
    f32 position[3];
    s32 camera;

    active = 0;
    flag360 = func_800DA298(0x360);
    flag3B = func_800DA298(0x3B);
    flag5A = func_800D0B68(0x5A, 1);
    switch (func_800EA05C()) {
        case 0x142:
            if (_glcutDll_entrypoint_19(0x66)) {
                cameraFlags = 0x900;
                if (func_800EA364() == 0x143) {
                    cameraFlags = 0x2900;
                }
                _capod_entrypoint_13((s32)arg0->unk0, 0, 0x4B, cameraFlags);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x154D, 0x44, 0, 0xAE);
                active = 1;
            } else if (func_800DB9B0() == 0 && flag360 == 0 && flag3B == 0 &&
                       func_800EA090() == 1 && flag5A != 0) {
                camera = func_800F54E4();
                _subaddiemarker_entrypoint_1(arg0, 0x154, 0x32, position, 1);
                func_800F497C(camera);
                func_800F49A8(camera, 1);
                func_800F49D4(camera, &func_8010D5DC, (s32)arg0->unk0);
                func_800F4A58(camera, (s32)position, 200.0f);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x154C, 0x44, 0, 0xAE);
                func_80101FDC(arg0, 3);
                _capod_entrypoint_13((s32)arg0->unk0, 0, 0x4C, 0x2030);
                active = 1;
            }
            func_800BF744(1, flag360 == 0);
            func_800BF744(2, flag360);
            func_800BF744(3, 0);
            break;
        case 0x145:
        case 0x146:
        case 0x147:
        case 0x148:
        case 0x149:
        case 0x14A:
        case 0x14B:
        case 0x14C:
        case 0x14D:
        case 0x14E:
            if (flag5A == 0 && func_800DB9B0() == 0 && func_800DA9E4(0x67D, 1) == 0) {
                active = 1;
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1536, 0xE, 0, 0xAE);
            }
            break;
        case 0x14F:
            active = func_800DA298(0x367) == 0;
            func_80101FDC(arg0, 2);
            _subaddieDll_entrypoint_1(arg0);
            break;
        case 0x190:
            active = 1;
            func_80101FDC(arg0, 4);
            arg0->unk6C_0 = 0;
            arg0->unk58 = 12.0f;
            func_800BF744(1, 0);
            func_800BF744(2, 1);
            func_800BF744(3, 1);
            break;
        case 0x198:
            active = 1;
            func_80101FDC(arg0, 6);
            arg0->unk6C_0 = 1;
            arg0->unk58 = 12.0f;
            func_800BF744(1, 0);
            func_800BF744(2, 1);
            func_800BF744(3, 1);
            break;
        case 0x160:
            if (func_800EA090() == 4) {
                active = 1;
                _capod_entrypoint_2((s32)arg0->unk0, 0x15, 0x2000);
                _capod_entrypoint_8(1);
                _gcdialogcamera_entrypoint_8();
                _capod_entrypoint_7(5, 1);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x14D7, 0xC, 0, 0x22);
                func_80101FDC(arg0, 8);
            }
            break;
    }
    if (active == 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjobits/func_80800744_chkingjinjobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjobits/chkingjinjobits_entrypoint_1.s")
