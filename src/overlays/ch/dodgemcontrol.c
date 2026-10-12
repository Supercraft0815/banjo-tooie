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

void func_808017F0_chdodgemcontrol(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    struct {
        s32 words[12];
        u8 bytes[0x92];
        u8 count;
    } *temp_v0;
    s32 var_v1;

    temp_v0 = func_80100094(arg0, 0U);
    for (var_v1 = 0; var_v1 < temp_v0->count; var_v1++) {
        temp_v0->bytes[var_v1] = 0;
        temp_v0->words[var_v1] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801844_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801928_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808019C4_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801A3C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801A8C_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801B94_chdodgemcontrol.s")

void func_80801C18_chdodgemcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiefade_entrypoint_5();
    func_80102424(arg0, arg2);
    if ((arg0->unk70_10) == 3) {
        _subaddiefade_entrypoint_5(arg0);
    }
}

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

void func_80802180_chdodgemcontrol(Actor *arg0) {
    f32 func_800138D0(f32);
    f32 func_800D8FF8(void);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    f32 func_800F1DCC(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, f32);
    void func_80802104_chdodgemcontrol(Actor *);
    void func_808039B8_chdodgemcontrol(Actor *);
    f32 func_808046EC_chdodgemcontrol(Actor *);
    f32 mlAbsF(f32);
    f32 *sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    sp8C = func_80100094(arg0, 0);
    sp88 = func_800D8FF8();
    sp84 = func_800F1DCC(*(f32 *)((u8 *)arg0 + 0x48), *(f32 *)((u8 *)arg0 + 0x54));
    *(f32 *)((u8 *)arg0 + 0x24) *= 0.95f;
    sp84 = mlAbsF(func_800138D0(sp84));
    sp80 = func_808046EC_chdodgemcontrol(arg0) * (1.1f - sp84) * sp88;
    sp8C[3] *= 0.8f;
    func_800EEB9C(sp74, *(f32 *)((u8 *)arg0 + 0x48), -40.0f);
    func_800EF04C((f32 *)((u8 *)arg0 + 4), sp74);
    if (func_80102CF4(arg0, sp80) == 0) {
        func_80102B2C(arg0, sp80);
    }
    *(f32 *)((u8 *)arg0 + 0x48) += sp8C[3];
    func_800EEB9C(sp74, *(f32 *)((u8 *)arg0 + 0x48), 40.0f);
    func_800EF04C((f32 *)((u8 *)arg0 + 4), sp74);
    func_800EEB9C(sp5C, *(f32 *)((u8 *)arg0 + 0x48), 48.75f);
    func_800EF04C(sp5C, (f32 *)((u8 *)arg0 + 4));
    func_800EEB9C(sp68, *(f32 *)((u8 *)arg0 + 0x48), *(f32 *)((u8 *)arg0 + 0x24));
    func_800EF04C(sp68, sp8C);
    if (sp68[0] < 0.0f) {
        sp68[0] = -sp68[0];
    }
    if (sp68[2] < 0.0f) {
        sp68[2] = -sp68[2];
    }
    if (*(f32 *)((u8 *)arg0 + 4) < -629.0f) {
        *(f32 *)((u8 *)arg0 + 4) = -629.0f;
        func_800EEB9C(sp8C, 90.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[0] < -655.0f) {
        sp5C[0] = -655.0f;
        func_800EEB9C(sp50, *(f32 *)((u8 *)arg0 + 0x48), 48.75f);
        *(f32 *)((u8 *)arg0 + 4) = sp5C[0] - sp50[0];
        func_800EEB9C(sp8C, 90.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (*(f32 *)((u8 *)arg0 + 4) > 629.0f) {
        *(f32 *)((u8 *)arg0 + 4) = 629.0f;
        func_800EEB9C(sp8C, 270.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[0] > 655.0f) {
        sp5C[0] = 655.0f;
        func_800EEB9C(sp44, *(f32 *)((u8 *)arg0 + 0x48), 48.75f);
        *(f32 *)((u8 *)arg0 + 4) = sp5C[0] - sp44[0];
        func_800EEB9C(sp8C, 270.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (*(f32 *)((u8 *)arg0 + 0xC) > 629.0f) {
        *(f32 *)((u8 *)arg0 + 0xC) = 629.0f;
        func_800EEB9C(sp8C, 180.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[2] > 655.0f) {
        sp5C[2] = 655.0f;
        func_800EEB9C(sp38, *(f32 *)((u8 *)arg0 + 0x48), 75.0f);
        *(f32 *)((u8 *)arg0 + 0xC) = sp5C[2] - sp38[2];
        func_800EEB9C(sp8C, 180.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (*(f32 *)((u8 *)arg0 + 0xC) < -629.0f) {
        *(f32 *)((u8 *)arg0 + 0xC) = -629.0f;
        func_800EEB9C(sp8C, 0.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[2] < -655.0f) {
        sp5C[2] = -655.0f;
        func_800EEB9C(sp2C, *(f32 *)((u8 *)arg0 + 0x48), 48.75f);
        *(f32 *)((u8 *)arg0 + 0xC) = sp5C[2] - sp2C[2];
        func_800EEB9C(sp8C, 0.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    func_800EEB9C((f32 *)((u8 *)arg0 + 0x28), *(f32 *)((u8 *)arg0 + 0x48), *(f32 *)((u8 *)arg0 + 0x24));
    func_800EF04C((f32 *)((u8 *)arg0 + 0x28), sp8C);
    func_800EF334((f32 *)((u8 *)arg0 + 0x28), sp88);
    func_800EF04C((f32 *)((u8 *)arg0 + 4), (f32 *)((u8 *)arg0 + 0x28));
    func_800EF334(sp8C, 0.7f);
    if (sp8C[6] != 0.0f) {
        sp8C[6] = sp8C[6] - sp88;
    }
    func_808039B8_chdodgemcontrol(arg0);
}

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

/* extern */

void func_80802764_chdodgemcontrol(Actor *arg0) {
    s32 anctrl_setIndex(s32, s32);
    s32 func_80101CDC(s32, s32);
    s32 func_80104248();
    s32 func_808026D0_chdodgemcontrol(s32);
    s32 func_808000B8_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x10B);
    func_80101CDC((s32)arg0, 0x3F666666);
    func_808026D0_chdodgemcontrol((s32)arg0);
    if (arg0->unk64_20) {
        func_808000B8_chdodgemcontrol(0);
    }
}

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

void func_808039B8_chdodgemcontrol(Actor *arg0) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    f32 func_800EEF94(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    Actor *func_8080000C_chdodgemcontrol(Actor *, s32);
    void func_80801084_chdodgemcontrol(f32 *, f32 *, f32);
    void func_80802104_chdodgemcontrol(Actor *);
    void func_80802764_chdodgemcontrol(Actor *);
    void func_80802824_chdodgemcontrol(Actor *);
    void func_80802884_chdodgemcontrol(Actor *);
    extern s32 D_80804D5C_chdodgemcontrol;
    s32 i;
    Actor *controller;
    u8 *control_data;
    Actor *other;
    f32 *data;
    f32 *other_data;
    f32 other_pos[3];
    f32 front[3];
    f32 other_front[3];
    f32 speed;
    f32 difference;
    s32 angle;
    f32 anglef;
    f32 point[3];
    f32 other_point[3];
    f32 offset[3];
    f32 other_offset[3];

    data = func_80100094(arg0, 0);
    controller = func_80106790(*(Unk80132ED0 **)((u8 *)arg0 + 0x3C));
    control_data = func_80100094(controller, 0);
    for (i = 0; i < control_data[0xC2]; i++) {
        if (i != (*(u32 *)((u8 *)arg0 + 0x6C) & 0x1FF)) {
            other = func_8080000C_chdodgemcontrol(controller, i);
            other_data = func_80100094(other, 0);
            other_pos[0] = ((f32 *)other)[1];
            other_pos[1] = ((f32 *)other)[2];
            other_pos[2] = ((f32 *)other)[3];
            func_800EEB9C(front, ((f32 *)arg0)[0x12], 75.0f);
            func_800EF04C(front, ((f32 *)arg0 + 1));
            func_800EEB9C(other_front, ((f32 *)other)[0x12], 48.75f);
            func_800EF04C(other_front, ((f32 *)other + 1));
            if (func_800EFFB4(((f32 *)arg0 + 1), 182.0f, other_pos) ||
                func_800EFFB4(front, 156.0f, other_pos) ||
                func_800EFFB4(((f32 *)arg0 + 1), 156.0f, other_front) ||
                func_800EFFB4(front, 130.0f, other_front)) {
                speed = func_800EEF94((f32 *)arg0 + 10);
                if (i == (s32)((f32 *)arg0)[13]) {
                    ((f32 *)arg0)[20] = 0.0f;
                }
                if (func_800EEF94((f32 *)other + 10) <= speed) {
                    angle = (s32)func_800F1DF4(((f32 *)other + 1), ((f32 *)arg0 + 1));
                    difference = func_800F1DCC(((f32 *)other)[18], (f32)angle);
                    if (data[6] <= 0.0f) {
                        func_8010D930(1, 0, ((f32 *)arg0 + 1), &D_80804D5C_chdodgemcontrol);
                        data[6] = 1.0f;
                    }
                    if (difference > -45.0f && difference < 45.0f) {
                        func_80802764_chdodgemcontrol(other);
                    }
                    if (difference < -45.0f && difference > -135.0f) {
                        func_80802824_chdodgemcontrol(other);
                    }
                    if (difference > 45.0f && difference < 135.0f) {
                        func_80802884_chdodgemcontrol(other);
                    }
                    if (difference < -135.0f || difference > 135.0f) {
                        func_808027C4_chdodgemcontrol((s32)other);
                    }
                    if (((f32 *)arg0)[9] < 150.0f) {
                        ((f32 *)arg0)[9] = 150.0f;
                    }
                    if (!(*(u32 *)((u8 *)arg0 + 0x6C) & 0x1FF) &&
                        ((u32)((u8 *)controller)[0x79] >> 4) != 3) {
                        ((f32 *)arg0)[9] *= 0.8999938965f;
                        anglef = (f32)angle;
                        func_800EEB9C(data, anglef, ((f32 *)arg0)[9] * 0.5f);
                    } else {
                        ((f32 *)arg0)[9] *= 0.6999969482f;
                        anglef = (f32)angle;
                        func_800EEB9C(data, anglef, ((f32 *)arg0)[9] / 1.0f);
                    }
                    if (i == 0 && ((u32)((u8 *)controller)[0x79] >> 4) != 3) {
                        ((f32 *)other)[9] *= 0.5f;
                        func_800EEB9C(other_data, anglef, -((f32 *)arg0)[9] * 3.0f);
                    } else {
                        ((f32 *)other)[9] *= 0.6999969482f;
                        func_800EEB9C(other_data, anglef, -((f32 *)arg0)[9] / 1.0f);
                    }
                    func_800EEB9C(offset, ((f32 *)arg0)[18], 48.75f);
                    func_800EEB9C(other_offset, ((f32 *)other)[18], 48.75f);
                    func_80801084_chdodgemcontrol(((f32 *)arg0 + 1), ((f32 *)other + 1), 170.625f);
                    func_800EE780(point, offset, ((f32 *)arg0 + 1));
                    func_80801084_chdodgemcontrol(point, ((f32 *)other + 1), 170.625f);
                    func_800EFB24(((f32 *)arg0 + 1), point, offset);
                    func_800EE780(other_point, other_offset, ((f32 *)other + 1));
                    func_80801084_chdodgemcontrol(((f32 *)arg0 + 1), other_point, 136.5f);
                    func_800EFB24(((f32 *)other + 1), other_point, other_offset);
                    func_800EE780(point, offset, ((f32 *)arg0 + 1));
                    func_800EE780(other_point, other_offset, ((f32 *)other + 1));
                    func_80801084_chdodgemcontrol(point, other_point, 136.5f);
                    func_800EFB24(((f32 *)other + 1), other_point, other_offset);
                    func_800EFB24(((f32 *)arg0 + 1), point, offset);
                    difference = func_800F1DCC(((f32 *)arg0)[18], (f32)(angle + 180));
                    if (difference > -45.0f && difference < 45.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    if (difference < -45.0f && difference > -135.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    if (difference > 45.0f && difference < 135.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    if (difference < -135.0f || difference > 135.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    difference = func_800F1DCC(((f32 *)arg0)[18], anglef);
                    if (difference > -80.0f && difference < 10.0f) {
                        data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    if (difference < 80.0f && difference > 10.0f) {
                        data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                    if (difference > -170.0f && difference < -100.0f) {
                        data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                    if (difference < 170.0f && difference > 80.0f) {
                        data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    difference = func_800F1DCC(((f32 *)other)[18], anglef);
                    if (difference > -80.0f && difference < 10.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                    if (difference < 80.0f && difference > 10.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    if (difference > -170.0f && difference < -100.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    if (difference < 170.0f && difference > 80.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                }
            }
        }
    }
}

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
