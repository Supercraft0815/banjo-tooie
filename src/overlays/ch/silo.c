#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800000_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800104_chsilo.s")

/* extern */

s32 func_8080015C_chsilo(void *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    if (arg1 == ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF)) {
        return 0;
    }
    if (func_800DA298(arg1 + 0x32C) == 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_808001A8_chsilo.s")

/* extern */

void func_80800210_chsilo(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_32(s32, s32);
    _gcnewoption_entrypoint_32(arg1, 111);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800238_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_808002E8_chsilo.s")

/* extern */

void func_80800378_chsilo(s32 arg0) {
    s32 func_800903D0(s32);
    func_800903D0(arg0 + 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800398_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800420_chsilo.s")

s32 func_808004C0_chsilo(u8 *arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_10(s32, s32);
    s32 _gcnewoption_entrypoint_11(s32);
    s32 _gcnewoption_entrypoint_14(s32, s32, s32, s32, f32);
    s32 _gcnewoption_entrypoint_4(u8 *, s32, s32 *, s32, s32);
    s32 _gcnewoption_entrypoint_40(s32, s32, s32, s32, f32, f32);
    s32 _gcnewoption_entrypoint_42(s32, f32);
    s32 _gcnewoption_entrypoint_6(u8 *, s32);
    s32 _gcnewoption_entrypoint_8(s32, s32);
    s32 _gcnewoption_entrypoint_9(s32, s32);
    s32 _plcamera_entrypoint_3(s32, s32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, f32 *, s32 *);
    void func_8008FE68(f32 *);
    s32 func_80090708(s32);
    void func_800907C0(f32 *);
    void func_800C964C(s32);
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F54E4(void);
    s32 func_800F82D4(s32, s32);
    s32 func_80100094(s32, s32);
    s32 func_80102424(u8 *, s32);
    void func_8010A828(void **, s32);
    s32 func_80800398_chsilo(u8 *, s32);
    s32 func_80800420_chsilo(u8 *, s32);
    extern s32 D_808012C0_chsilo;
    extern s32 _gcnewoption_entrypoint_35;
    s32 camera;
    s32 count;
    s32 option;
    struct SiloFlag { u8 high : 3; u8 active : 1; u8 low : 4; };

    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 1:
            _subaddieDll_entrypoint_4(arg0, 1);
            break;
        case 2:
            func_800DA544((*(s32 *)(arg0 + 0x6C) & 0x1FF) + 0x32C);
            ((struct SiloFlag *)(arg0 + 0x65))->active = 1;
            *(f32 *)(arg0 + 0x24) = 5.0f;
            break;
        case 6:
            *(f32 *)(arg0 + 0x24) = 0.5f;
            break;
        case 5:
            _gcnewoption_entrypoint_6(arg0, 0);
            func_80090708(0);
            func_8010A828((void **)arg0, 2);
            break;
        case 8:
            func_80800420_chsilo(arg0, 0);
            break;
        case 11:
            _plcamera_entrypoint_3(func_800F54E4(), 1);
            break;
    }
    func_80102424(arg0, arg1);
    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 1:
            _subaddieDll_entrypoint_4(arg0, 0);
            break;
        case 2:
            _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), &D_808012C0_chsilo);
            break;
        case 6:
            _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), &D_808012C0_chsilo);
            break;
        case 4:
            camera = func_800F54E4();
            func_800F82D4(camera, 1);
            _plcamera_entrypoint_3(camera, 0);
            func_80800398_chsilo(arg0, 1);
            func_8008FE68((f32 *)(arg0 + 0x28));
            break;
        case 5:
            count = func_808001A8_chsilo((s32)arg0);
            _gcnewoption_entrypoint_4(arg0, 0, &_gcnewoption_entrypoint_35, 0, 0x184F);
            option = func_80100094((s32)arg0, 0);
            _gcnewoption_entrypoint_8(option, count >= 6 ? 5 : count);
            _gcnewoption_entrypoint_9(option, count);
            _gcnewoption_entrypoint_10(option, 0);
            func_80800210_chsilo((s32)arg0, option);
            _gcnewoption_entrypoint_14(option, 0, 1, 3, 4.0f);
            _gcnewoption_entrypoint_40(option, 0x41, 0x22, 0x20, 0.8f, 1.0f);
            _gcnewoption_entrypoint_42(option, 0.1f);
            _gcnewoption_entrypoint_11(option);
            func_8010A828((void **)arg0, 10);
            break;
        case 10:
            func_80090708(2);
            _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), &D_808012C0_chsilo);
            break;
        case 8:
            func_800C964C(0x10);
            func_80800420_chsilo(arg0, 1);
            func_80800398_chsilo(arg0, 1);
            func_800EE7F8((f32 *)(arg0 + 0x28), (f32 *)(arg0 + 4));
            *(f32 *)(arg0 + 0x2C) -= 150.0f;
            func_800907C0((f32 *)(arg0 + 0x28));
            _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), &D_808012C0_chsilo);
            break;
        case 11:
            func_80800398_chsilo(arg0, 1);
            func_80800420_chsilo(arg0, 1);
            func_800EE7F8((f32 *)(arg0 + 0x28), (f32 *)(arg0 + 4));
            *(f32 *)(arg0 + 0x2C) -= 150.0f;
            func_800907C0((f32 *)(arg0 + 0x28));
            break;
        case 9:
            func_80800398_chsilo(arg0, 0);
            *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 8) - 25.0f;
            func_800907C0((f32 *)(arg0 + 0x28));
            func_80800378_chsilo((s32)arg0);
            break;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_8080087C_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_808009E8_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800A40_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800B80_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80801080_chsilo.s")

/* extern */

void func_808011C8_chsilo(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_1(s32, s32);
    s32 func_800EB854();
    s32 func_80100094(s32, s32);
    s32 func_801018A4(s32, s32);
    s32 temp_v0;

    if (func_800EB854() == 3) {
        temp_v0 = func_80100094(arg0, 0);
        if (temp_v0 != 0) {
            _gcnewoption_entrypoint_1(temp_v0, arg1);
        }
    } else {
        func_801018A4(arg0, arg1);
    }
}

OSThread *chsilo_entrypoint_0(void)
{
    extern u8 D_80801384_chsilo[];

    return (OSThread *) D_80801384_chsilo;
}
