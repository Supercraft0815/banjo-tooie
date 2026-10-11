#include "common.h"

OSThread *chdodgemcontrol_entrypoint_0(void)
{
    extern u8 D_80804DB4_chdodgemcontrol[];

    return (OSThread *) D_80804DB4_chdodgemcontrol;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080000C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80800044_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808000B8_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080010C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80800350_chdodgemcontrol.s")

/* extern */

void func_808003B0_chdodgemcontrol(void *arg0) {
    f32 func_800DC178(f32, f32);
    (*(f32 *)((s8 *)(arg0) + (0))) = func_800DC178(-645.0f, 645.0f);
    (*(f32 *)((s8 *)(arg0) + (4))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800DC178(-645.0f, 645.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080040C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808004E4_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808005CC_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080061C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808006CC_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808008EC_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80800938_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80800CA0_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80800FC4_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801084_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801214_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801258_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808012C8_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801344_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808013D0_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808015E8_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080160C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801744_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808017F0_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801844_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801928_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808019C4_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801A3C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801A8C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801B94_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801C18_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801C60_chdodgemcontrol.s")

void func_80801F00_chdodgemcontrol(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x50)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801F2C_chdodgemcontrol.s")

OSThread *chdodgemcontrol_entrypoint_1(void)
{
    extern u8 D_80804EDC_chdodgemcontrol[];

    return (OSThread *) D_80804EDC_chdodgemcontrol;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080207C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80802104_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80802180_chdodgemcontrol.s")

s32 func_808026D0_chdodgemcontrol(s32 arg0) {
    s32 func_80104248();
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_start(s32);
    s32 func_8008B188(s32, s32);
    anctrl_setPlaybackType(func_80104248(), 1);
    func_8008B188(func_80104248(arg0), 1);
    return anctrl_start(func_80104248(arg0));
}

/* extern */

void func_80802720_chdodgemcontrol(s32 arg0) {
    s32 anctrl_setIndex(s32, s32);
    s32 func_80101CDC(s32, s32);
    s32 func_80104248();
    s32 func_808026D0_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x105);
    func_80101CDC(arg0, 0x4B189680);
    func_808026D0_chdodgemcontrol(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80802764_chdodgemcontrol.s")

/* extern */

void func_808027C4_chdodgemcontrol(s32 arg0) {
    struct Flags {
        u8 pad[0x64];
        u32 : 11;
        u32 active : 1;
        u32 : 20;
    };
    s32 anctrl_setIndex(s32, s32);
    s32 func_80101CDC(s32, s32);
    s32 func_80104248();
    s32 func_808000B8_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x108);
    func_80101CDC(arg0, 0x3F666666);
    func_808026D0_chdodgemcontrol(arg0);
    if (((struct Flags *)arg0)->active) {
        func_808000B8_chdodgemcontrol(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80802824_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80802884_chdodgemcontrol.s")

void func_808028E4_chdodgemcontrol(s32 arg0) {
    struct Flags {
        u8 pad[0x64];
        u32 : 11;
        u32 active : 1;
        u32 : 20;
    };
    s32 anctrl_isStopped(s32);
    s32 anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_start(s32);
    s32 func_8008B188(s32, s32);
    s32 func_8008B28C(s32);
    void func_800904C8(s32);
    f32 func_800F1DCC(f32, f32);
    s32 func_80101CDC(s32, s32);
    s32 func_801022E4(s32);
    s32 func_80104248();
    f32 difference;

    difference = func_800F1DCC(*(f32 *)(arg0 + 0x48), *(f32 *)(arg0 + 0x54));
    if (((struct Flags *)arg0)->active) {
        if (difference > 10.0f) {
            func_800904C8(0x75);
        } else if (difference < -10.0f) {
            func_800904C8(0x76);
        } else {
            func_800904C8(0x74);
        }
    } else if (difference > 10.0f) {
        switch (func_801022E4(arg0)) {
        case 0x105:
            anctrl_setIndex(func_80104248(arg0), 0x106);
            func_80101CDC(arg0, 0x3F000000);
            anctrl_setPlaybackType(func_80104248(arg0), 1);
            func_8008B188(func_80104248(arg0), 1);
            anctrl_start(func_80104248(arg0));
            break;
        case 0x107:
            if (func_8008B28C(func_80104248(arg0))) {
                func_8008B188(func_80104248(arg0), 0);
                func_80101CDC(arg0, 0x40400000);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x108:
        case 0x109:
        case 0x10A:
        case 0x10B:
            if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        }
    } else if (difference < -10.0f) {
        switch (func_801022E4(arg0)) {
        case 0x105:
            anctrl_setIndex(func_80104248(arg0), 0x107);
            func_80101CDC(arg0, 0x3F000000);
            anctrl_setPlaybackType(func_80104248(arg0), 1);
            func_8008B188(func_80104248(arg0), 1);
            anctrl_start(func_80104248(arg0));
            break;
        case 0x106:
            if (func_8008B28C(func_80104248(arg0))) {
                func_80101CDC(arg0, 0x40400000);
                func_8008B188(func_80104248(arg0), 0);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x108:
        case 0x109:
        case 0x10A:
        case 0x10B:
            if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        }
    } else {
        switch (func_801022E4(arg0)) {
        case 0x105:
            break;
        case 0x106:
            if (func_8008B28C(func_80104248(arg0))) {
                func_80101CDC(arg0, 0x40400000);
                func_8008B188(func_80104248(arg0), 0);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x107:
            if (func_8008B28C(func_80104248(arg0))) {
                func_80101CDC(arg0, 0x40400000);
                func_8008B188(func_80104248(arg0), 0);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x108:
        case 0x109:
        case 0x10A:
        case 0x10B:
            if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80802D04_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80803200_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080349C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080372C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808037C8_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808039B8_chdodgemcontrol.s")

/* extern */

void func_8080422C_chdodgemcontrol(s32 arg0, s32 arg1) {
    s32 anctrl_setPlaybackType(s32, s32);
    s32 func_80101FDC();
    s32 func_80104248(s32, s32);
    func_80101FDC();
    if ((arg1 == 5) || (arg1 == 6) || (arg1 == 7)) {
        anctrl_setPlaybackType(func_80104248(arg0, arg1), 2);
        return;
    }
    anctrl_setPlaybackType(func_80104248(arg0, arg1), 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808042A4_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080440C_chdodgemcontrol.s")

void func_8080455C_chdodgemcontrol(void *arg0) {
    struct Flags {
        u8 pad[0x64];
        u32 : 11;
        u32 active : 1;
        u32 : 20;
    };
    void func_800904C8(s32);
    if (((struct Flags *)arg0)->active) {
        func_800904C8(0x28);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080458C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080460C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808046EC_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080476C_chdodgemcontrol.s")

OSThread *chdodgemcontrol_entrypoint_2(void)
{
    extern u8 D_80804FAC_chdodgemcontrol[];

    return (OSThread *) D_80804FAC_chdodgemcontrol;
}
