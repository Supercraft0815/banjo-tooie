#include "common.h"

OSThread *chnicecavemen_entrypoint_0(void)
{
    extern u8 D_80801A5C_chnicecavemen[];

    return (OSThread *) D_80801A5C_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_1(void)
{
    extern u8 D_80801AA4_chnicecavemen[];

    return (OSThread *) D_80801AA4_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_2(void)
{
    extern u8 D_80801AEC_chnicecavemen[];

    return (OSThread *) D_80801AEC_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_3(void)
{
    extern u8 D_80801B34_chnicecavemen[];

    return (OSThread *) D_80801B34_chnicecavemen;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800030_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800128_chnicecavemen.s")

void func_808003B8_chnicecavemen(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_808003D8_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800624_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_8080077C_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800AB8_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800BF8_chnicecavemen.s")

/* extern */

s32 func_80800C6C_chnicecavemen(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    void func_80102424(Actor*, s32);
    s32 func_80800BF8_chnicecavemen();
    if (func_80800BF8_chnicecavemen() != 0) {
        func_80102424(arg0, 4);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x17D8U, 0xEU, arg0->position, 0xA2U);
        return 1;
    }
    return 0;
}

void func_80800CC8_chnicecavemen(Actor *arg0) {
    typedef struct { s32 values[7]; } SoundParams;
    extern SoundParams D_80801B8C_chnicecavemen;
    extern u32 D_80801BA8_chnicecavemen[];
    extern s32 D_80801BC0_chnicecavemen[], D_80801BEC_chnicecavemen[], D_80801C1C_chnicecavemen[];
    extern s32 D_80801C60_chnicecavemen[], D_80801C8C_chnicecavemen[], D_80801CA0_chnicecavemen[];
    extern u32 D_80801C78_chnicecavemen[];
    extern s32 D_80801CB8_chnicecavemen[], D_80801CD0_chnicecavemen[];
    extern s32 D_80801CEC_chnicecavemen[], D_80801CF4_chnicecavemen[], D_80801D08_chnicecavemen[];
    extern f32 D_80801D1C_chnicecavemen[];
    extern u32 D_80801D28_chnicecavemen[], D_80801D38_chnicecavemen[];
    extern s32 D_80801D48_chnicecavemen[], D_80801D5C_chnicecavemen[], D_80801D70_chnicecavemen[];
    extern u32 D_80801D94_chnicecavemen[];
    extern s32 D_80801DA8_chnicecavemen[], D_80801DB8_chnicecavemen[];
    s32 func_801022E4(Actor *);
    f32 func_80101F24(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800EF1B8(f32 *, f32, f32);
    s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 _subaddieaudioquick_entrypoint_2(Actor *, f32 *, s32 *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieaudioquick_entrypoint_4(Actor *, f32 *, s32 *, s32 *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_800DC298(f32);
    s32 func_800DC128(s32, s32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    s32 animation;
    f32 progress;
    s32 loop;
    f32 start[3];
    f32 end[3];
    f32 mouth[3];
    SoundParams sound;
    s32 emit;
    s32 joint;
    f32 hit[3];
    f32 target[3];

    animation = func_801022E4(arg0);
    progress = func_80101F24(arg0);
    loop = 0;
    switch (animation) {
        case 0x2CD:
            if (func_80101E14(arg0, 0.7f)) {
                if (_subaddieskeleton_entrypoint_2(arg0->unk0, 4, start)) {
                    func_800EE7F8(end, start);
                    func_800EF1B8(end, *(f32 *)((u8 *)arg0 + 0x48), -50.0f);
                    end[1] += 30.0f;
                    func_800BABB8(0, start, end, 1.0f, D_80801BC0_chnicecavemen);
                }
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801CA0_chnicecavemen);
            }
            loop = 1;
            break;
        case 0x2CF:
            if (_subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801CB8_chnicecavemen, D_80801CD0_chnicecavemen)
                && func_800DC298(0.4f)
                && _subaddieskeleton_entrypoint_2(arg0->unk0, 5, mouth)) {
                func_800BBCB8(mouth, arg0->position, 1.0f, 3, D_80801BEC_chnicecavemen);
            }
            loop = progress > 0.4f;
            break;
        case 0x2CE:
            sound = D_80801B8C_chnicecavemen;
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801C60_chnicecavemen, sound.values);
            loop = progress < 0.6f;
            break;
        case 0x2D0:
        case 0x2D1:
        case 0x2D2:
            if (func_80101E4C(arg0, D_80801D1C_chnicecavemen)) {
                func_8010D930(4, *(u32 *)((u8 *)arg0 + 0x70) & 1, arg0->position, D_80801CEC_chnicecavemen);
            }
            if (func_80101E14(arg0, 0.83f)) {
                func_8010D930(4, *(u32 *)((u8 *)arg0 + 0x70) & 1, arg0->position, D_80801CF4_chnicecavemen);
            }
            if (func_80101E14(arg0, 0.08f)) {
                func_8010D930(4, *(u32 *)((u8 *)arg0 + 0x70) & 1, arg0->position, D_80801D08_chnicecavemen);
            }
            break;
        case 0x2D6:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801D28_chnicecavemen, 0.05f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801D38_chnicecavemen, 0.16f);
            break;
        case 0x2D4:
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801D48_chnicecavemen, D_80801D5C_chnicecavemen);
            break;
        case 0x2D3:
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801C60_chnicecavemen, D_80801D70_chnicecavemen);
            break;
        case 0x2E2:
            emit = 0;
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801C8C_chnicecavemen, D_80801DA8_chnicecavemen);
            if (_subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801C78_chnicecavemen, 0.3f)) {
                emit = 1;
                joint = 4;
            }
            if (_subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801D94_chnicecavemen, 0.84f)) {
                emit = 1;
                joint = 6;
            }
            if (emit && _subaddieskeleton_entrypoint_2(arg0->unk0, joint, hit)) {
                func_800EE7F8(target, hit);
                func_800EF1B8(target, *(f32 *)((u8 *)arg0 + 0x48) - 30.0f, -20.0f);
                target[1] -= 30.0f;
                func_800BBCB8(hit, target, 1.0f, func_800DC128(4, 8), D_80801C1C_chnicecavemen);
            }
            break;
        case 0x2E1:
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801C8C_chnicecavemen, D_80801DB8_chnicecavemen);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801C78_chnicecavemen, 0.3f);
            break;
    }
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, loop, D_80801BA8_chnicecavemen);
}

/* extern */

s32 func_80801178_chnicecavemen(Actor *arg0) {
    typedef struct { u8 pad[0x824]; s32 unk824; } CavemanData;
    s32 _subaddieitem_entrypoint_3(Actor *, f32 *, void *);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    void func_800DA544(s32);
    u32 func_800F54E4(void);
    void func_800F8300();
    void *func_80100094(Actor *, u32);
    CavemanData *sp34;
    f32 sp28[3];

    sp34 = func_80100094(arg0, 0U);
    _subaddieskeleton_entrypoint_3(arg0->unk0, 4, sp28);
    if (_subaddieitem_entrypoint_3(arg0, sp28, sp34) != 0) {
        sp34->unk824 = 1;
        func_800F8300(func_800F54E4(), 2, arg0->position);
        func_800DA544(arg0->actorData[5]);
        return 1;
    }
    return 0;
}

/* extern */

void func_80801200_chnicecavemen(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddiepalette_entrypoint_0(void *, void *, s32);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    s32 var_v0;

    sp1C = func_80100094(arg0, 0U);
    if ((func_800DA298((*(s32 *)((s8 *)(arg0) + (0x28)))) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        var_v0 = 0x7E7;
    } else {
        var_v0 = 0x7E6;
    }
    _subaddiepalette_entrypoint_0(arg0, sp1C + 0x14, var_v0 & 0xFFFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_8080126C_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_8080134C_chnicecavemen.s")

/* extern */

s32 func_808013D0_chnicecavemen(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 func_80801464_chnicecavemen(void *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x18))) != 2) {
            func_80801464_chnicecavemen(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80801428_chnicecavemen(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80801464_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80801508_chnicecavemen.s")

/* extern */

int func_80801580_chnicecavemen(f32 *arg0) {
    u32 func_800F54E4(void);
    s32 func_800F640C(s32, s32);
    s32 func_800F64A4(s32, s32);
    s32 func_8010CB84(f32 *, u32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F64A4(temp_v0, 0x201) == 0) {
        return 0;
    }
    if (func_8010CB84(arg0 + 1, 0x12C) == 0) {
        return 0;
    }
    return func_800F640C(sp1C, 0x3CA) > 0 || func_800F640C(sp1C, 0x3CB) > 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80801604_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_808016E8_chnicecavemen.s")
