#include "common.h"

OSThread *chjollyroger_entrypoint_0(void)
{
    extern u8 D_80801358_chjollyroger[];

    return (OSThread *) D_80801358_chjollyroger;
}

OSThread *chjollyroger_entrypoint_1(void)
{
    extern u8 D_808013A0_chjollyroger[];

    return (OSThread *) D_808013A0_chjollyroger;
}

OSThread *chjollyroger_entrypoint_2(void)
{
    extern u8 D_808013E8_chjollyroger[];

    return (OSThread *) D_808013E8_chjollyroger;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800024_chjollyroger.s")

/* extern */

void func_808002E8_chjollyroger(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddieitem_entrypoint_0(s32, s32, s32, s32);
    s32 _subaddieitem_entrypoint_1(s32, s32);
    s32 func_800DA298(s32);
    s32 func_80100094(s32, s32);
    void func_80102424(Actor *, s32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 9);
    } else if (func_800DA298(0xC0) != 0) {
        func_80102424(arg0, 4);
    }
    _subaddieitem_entrypoint_0(func_80100094(arg0, 0), 0x4E4, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(arg0, 0), 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800370_chjollyroger.s")

void func_8080056C_chjollyroger(void *arg0) {
    extern u32 D_80801430_chjollyroger;
    extern u32 D_8080143C_chjollyroger;
    _subaddieaudioquick_entrypoint_4(arg0, (u8 *)arg0 + 24, &D_80801430_chjollyroger, &D_8080143C_chjollyroger);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_8080059C_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800624_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800930_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800AEC_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800BA0_chjollyroger.s")

/* extern */

void func_80800CC4_chjollyroger(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800F54E4();
    s32 func_800F64A4(s32, s32);
    void func_80102424(Actor *, s32);
    s32 var_a1;

    var_a1 = func_800F64A4(func_800F54E4(), 0x200) ? 0x1054 : 0xFFB;
    _subaddiedialog_entrypoint_11(arg0->unk0, var_a1, 6, arg0->position, 0x56);
    func_80102424(arg0, 3);
}

/* extern */

void func_80800D28_chjollyroger(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800F54E4();
    s32 func_800F82D4(s32, s32);
    void func_80102424(Actor *, s32);
    s32 func_80105A9C(s32, s32);
    s32 func_80105BAC(s32);
    s32 func_80800F3C_chjollyroger(s32, s32, s32);
    if ((arg1 == 0xFFB) || (arg1 == 0x1054)) {
        func_80102424(arg0, 4);
        func_80105A9C(arg0, 0x43AF0000);
        func_80105BAC(arg0);
        func_800F82D4(func_800F54E4(), 0);
        func_80800F3C_chjollyroger(arg0, 4, 0x30);
        return;
    }
    func_80102424(arg0, 5);
}

void func_80800DB8_chjollyroger(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
/* extern */

s32 func_80800DD8_chjollyroger(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 func_80800E6C_chjollyroger(void *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 2) {
            func_80800E6C_chjollyroger(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80800E30_chjollyroger(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x28))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800E6C_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800F3C_chjollyroger.s")

void func_80800FBC_chjollyroger(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_20(Unk80132ED0 *, s32, s32);

    switch (arg0->actorData[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x10, arg2);
        case 1:
        case 2:
            arg0->actorData[4] = 1;
        case 3:
            _capod_entrypoint_20(arg0->unk0, arg1, arg2);
            break;
    }
}

/* extern */

void func_8080103C_chjollyroger(Actor *arg0) {
    s32 _chdoormake_entrypoint_0(void *, f32, u32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    void func_8010A63C(void ***);
    s32 func_8010A800(Actor *, s32);
    if (_chdoormake_entrypoint_0(arg0, -120.0f, 0x8000, 0xC2) != 0) {
        _chdoormake_entrypoint_8(arg0, 1);
        _chdoormake_entrypoint_5(arg0, 3.5f);
    }
    func_8010A800(arg0, 0);
    func_8010A63C(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_808010A0_chjollyroger.s")

/* extern */

void func_80801194_chjollyroger(s32 arg0) {
    s32 _chexploder_entrypoint_12(s32, s32);
    s32 func_800DA544(s32);
    s32 func_80101080();
    s32 func_80106790(s32);
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x3C);
    func_800DA544(0x41);
}
