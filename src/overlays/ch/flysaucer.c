#include "common.h"

/* extern */

s32 func_80800000_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_800DA564(s32, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    sp1C[0x26] = func_800DA564(0xA34, 3);
    return sp1C[0x26];
}

/* extern */

void func_8080003C_chflysaucer(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 func_800DA7A8(s32, s32, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    func_800DA7A8(0xA34, arg1, 3);
    (*(s8 *)((s8 *)(sp1C) + (0x26))) = (s8) arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800080_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_8080013C_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808001B4_chflysaucer.s")

void func_80800388_chflysaucer(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_6(Unk80132ED0 *);
    void _gcdialogcamera_entrypoint_8(void);
    u8 *data;

    data = func_80100094(arg0, 0U);
    switch (data[0x28]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 5, 0);
        case 2:
            _capod_entrypoint_8(1);
            data[0x28] = 1;
            _gcdialogcamera_entrypoint_6(arg0->unk0);
            _gcdialogcamera_entrypoint_8();
        case 1:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80800424_chflysaucer(Actor *arg0, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
    u8 *data;

    data = func_80100094(arg0, 0U);
    switch (data[0x28]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 5, arg2);
        case 1:
            data[0x28] = 2;
        case 2:
            _capod_entrypoint_6(arg3, arg1, arg2);
            break;
    }
}

void func_808004B0_chflysaucer(Actor *arg0) {
    void _capod_entrypoint_3(u32);
    void* func_80100094(Actor*, u32);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x28))) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_3(0U);
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + (0x28))) = 0;
    }
}

void func_808004F0_chflysaucer(void) {
    s32 func_808017D0_chflysaucer();
    extern s32 D_80127194;
    (*(s16 *)((s8 *)(&D_80127194) + (0x434))) = 0;
    func_808017D0_chflysaucer();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800514_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808005FC_chflysaucer.s")

s16 func_80800728_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    extern s16 D_808045DA_chflysaucer[];
    return D_808045DA_chflysaucer[*((u8 *)func_80100094(arg0, 0U) + 0x26)];
}

/* extern */

s32 func_80800758_chflysaucer(s16 arg0) {
    s32 func_800A5800(s32);
    s32 _cadbfunc_entrypoint_16(s16 *);
    s32 var_s0;

    var_s0 = 0;
    if (arg0 != -1) {
        do {
            func_800A5800(arg0);
            _cadbfunc_entrypoint_16(&arg0);
            var_s0 += 1;
        } while (arg0 != -1);
    }
    return var_s0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808007C4_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808009DC_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800C3C_chflysaucer.s")

s32 func_80800DAC_chflysaucer(Actor *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void *func_80100094(Actor *, u32);
    f32 _suspline_entrypoint_6(void *);
    void _suspline_entrypoint_15(void *, f32);
    void _suspline_entrypoint_17(void *);
    void _suspline_entrypoint_3(void *, s32, f32 *);
    void _suspline_entrypoint_8(void *, f32);
    void *data;
    f32 sp20;

    data = func_80100094(arg0, 1U);
    sp20 = _suspline_entrypoint_6(data);
    _suspline_entrypoint_15(data, arg3);
    _suspline_entrypoint_17(data);
    _suspline_entrypoint_3(data, 0, arg1);
    _suspline_entrypoint_3(data, 1, arg2);
    arg2[1] += 180.0f;
    _suspline_entrypoint_8(data, sp20);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800E48_chflysaucer.s")

/* extern */

void func_80800F98_chflysaucer(void) {
    s32 func_800FC6B0(s32);
    u32 func_80800E48_chflysaucer();
    u32 temp_v0;

    temp_v0 = func_80800E48_chflysaucer();
    switch (temp_v0) {
    case 0:
    case 5:
        func_800FC6B0(0x17);
        return;
    case 1:
    case 2:
    case 3:
    case 4:
        func_800FC6B0(0x16);
        /* fallthrough */
    default:
        return;
    }
}

s32 func_80800FF0_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 temp_v1;

    temp_v1 = (*(u8 *)((s8 *)(func_80100094(arg0, 0U)) + (0x24)));
    switch (temp_v1) {
    case 1:
    case 2:
    case 3:
        return 1;
    default:
        return 0;
    }
}

void func_80801034_chflysaucer(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (4))) = -7800.0f;
    (*(f32 *)((s8 *)(arg0) + (8))) = 1700.0f;
    (*(f32 *)((s8 *)(arg0) + (0xC))) = -2900.0f;
}

/* extern */

void func_8080105C_chflysaucer(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);
    void func_80800388_chflysaucer(Actor *, s32, s32);
    arg2 |= 6;
    if (func_80800FF0_chflysaucer(arg0) == 0) {
        arg2 |= 8;
    }
    switch (arg1) {
    case 0x10C6:
    case 0x10C7:
    case 0x10C8:
    case 0x10C9:
    case 0x10E2:
    case 0x10E3:
    case 0x10E4:
    case 0x10E5:
    case 0x10E6:
    case 0x10E7:
    case 0x10E8:
        func_80800388_chflysaucer(arg0, 2, 1);
        break;
    case 0x10DB:
    case 0x10DD:
        func_80800388_chflysaucer(arg0, 4, 0);
        break;
    case 0x10DC:
    case 0x10DE:
        func_80800388_chflysaucer(arg0, 2, 1);
        break;
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x41);
    arg0->unk74_30 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80801130_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808012A4_chflysaucer.s")

struct anctrl_s;
enum asset_e;
void func_808013B4_chflysaucer(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct anctrl_s *func_80104200(s16);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void func_8008B188(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    s16 *data;
    struct anctrl_s *control;

    data = func_80100094(arg0, 0);
    control = func_80104200(data[1]);
    anctrl_reset(control);
    anctrl_setPlaybackType(control, 3);
    anctrl_setIndex(control, 0x481);
    anctrl_setDuration(control, 1.0f);
    func_8008B188(control, 1);
    anctrl_start(control);
}

void func_80801428_chflysaucer(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct anctrl_s *func_80104200(s16);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void func_8008B188(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    s16 *data;
    struct anctrl_s *control;

    data = func_80100094(arg0, 0);
    control = func_80104200(data[0]);
    anctrl_reset(control);
    anctrl_setPlaybackType(control, 3);
    anctrl_setIndex(control, 0x486);
    anctrl_setDuration(control, 1.0f);
    func_8008B188(control, 1);
    anctrl_start(control);
}

void func_8080149C_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_801042D8(s32);
    s16 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (*temp_v0 != 0) {
        func_801042D8((s32) temp_v0);
    }
}

/* extern */

struct anctrl_s;

void chflysaucer_entrypoint_0(Unk80132ED0 *arg0, f32 arg1) {
    int anctrl_getIndex(struct anctrl_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    void *func_80100094(Actor *, u32);
    struct anctrl_s *func_80104200(s16);
    Actor *func_80106790(Unk80132ED0 *);
    struct anctrl_s *sp1C[3];
    s16 *temp_v0;
    struct anctrl_s *temp_v0_2;
    Actor *actor;

    actor = func_80106790(arg0);
    temp_v0 = func_80100094(actor, 0);
    if (*temp_v0 != 0) {
        temp_v0_2 = func_80104200(*temp_v0);
        sp1C[0] = temp_v0_2;
        if (anctrl_getIndex(temp_v0_2) == 0x486) {
            func_8008B10C(sp1C[0], arg1);
        }
    }
}

void func_80801534_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_801042D8(s32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(s16 *)((s8 *)(temp_v0) + (2))) != 0) {
        func_801042D8((s32) (temp_v0 + 2));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80801568_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808017D0_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_8080185C_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80801E98_chflysaucer.s")

/* extern */

void func_80802014_chflysaucer(s32 arg0) {
    void func_8008FB10(s32, f32, f32, f32);
    func_8008FB10(arg0 + 4, 65.0f, 0.0f, 90.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80802044_chflysaucer.s")

void func_80802114_chflysaucer(Actor *arg0, f32 arg1) {
    void func_800C31DC(u8, f32);
    u8 func_800C4350(s32, f32[3], s32 *);
    extern s32 D_80804634_chflysaucer;
    u8 index;

    index = arg0->unk5F;
    if (index == 0) {
        arg0->unk5F = func_800C4350(0, arg0->position, &D_80804634_chflysaucer);
    } else {
        if (arg1 < 0.5f) {
            arg1 = 0.5f;
        }
        if (arg1 > 1.5f) {
            arg1 = 1.5f;
        }
        func_800C31DC(index, arg1);
        func_800C4350(arg0->unk5F, arg0->position, NULL);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808021C0_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80802290_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808024E0_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80802CF0_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80802ED8_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80803150_chflysaucer.s")

void func_808031C8_chflysaucer(Actor *arg0) {
    u8 func_800D731C(u16);
    s32 func_800DBE60(u8, s32, s32);
    u8 sp1F;

    if ((sp1F = func_800D731C(arg0->unk0->unk14)) != 0) {
        func_800DBE60(sp1F, 0, 0);
        func_800DBE60(sp1F, 1, 4);
        func_800DBE60(sp1F, 2, 8);
    }
}

/* extern */

void func_80803224_chflysaucer(Actor *arg0) {
    s32 func_800AE080(s16 arg0);
    f32 func_800F1828(f32*, f32*);
    s32 func_801039E4(s32);
    s32 func_800AE630(s32, u8 *, s32, f32 *);
    u8 *func_800B27E0(u8 *);
    u8 *sp3C;
    f32 sp30[3];
    f32 sp24[3];
    s32 pad;
    s32 sp1C;

    sp3C = func_800B27E0(func_801039E4((s32)arg0->unk0));
    sp1C = func_800AE080(*(s16 *)&arg0->unk0->unk10);
    func_800AE630(sp1C, sp3C, 0x2A, sp30);
    func_800AE630(sp1C, sp3C, 0x2B, sp24);
    func_800F1828(sp30, sp24);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_8080329C_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808035C4_chflysaucer.s")

OSThread *chflysaucer_entrypoint_1(void)
{
    extern u8 D_80804668_chflysaucer[];

    return (OSThread *) D_80804668_chflysaucer;
}

/* extern */

int func_80803844_chflysaucer(void) {
    s32 func_800DA298(s32);
    f32 func_800DC0C0(void);
    f32 sp1C;

    sp1C = func_800DC0C0();
    if (func_800DA298(0x6E9) != 0) {
        return 2;
    }
    if (sp1C < 0.5f) {
        return 0;
    }
    if (sp1C < 0.8333333f) {
        return 1;
    }
    return 2;
}

/* extern */

void func_808038C4_chflysaucer(Unk80132ED0 *arg0, f32 *arg1, f32 *arg2, s32 arg3, s32 arg4, f32 arg5) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
    Actor *func_80108474(u32, f32 *, s32);
    f32 sp24[3];
    Actor *sp20;

    sp20 = func_80108474(0x2A4, arg1, (s32)(arg2[1] + 180.0f));
    sp24[0] = arg2[0];
    sp24[1] = arg2[1];
    sp24[2] = (f32)arg3 - arg2[2];
    sp20->unk3C = arg0;
    sp20->rotation[0] = -sp24[0];
    sp20->unk79_4 = arg4;
    func_800EF6A8(sp20->position, sp24, 0.0f, 150.0f, 1000.0f);
    func_800EF04C(sp20->position, arg1);
    func_800EE7F8((f32 *)&sp20->actorData[4], arg1);
    sp20->unk58 = arg5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808039B8_chflysaucer.s")

void func_80803AF0_chflysaucer(s32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 func_80800DAC_chflysaucer(Actor *, f32 *, f32 *, f32);
    s32 func_808039B8_chflysaucer(s32, s32 *, f32 *, s32 *, s32, f32);
    extern s32 D_808046C4_chflysaucer;
    s32 sp34[3];
    f32 sp28[3];
    s32 sp20[2];

    sp20[0] = *arg0;
    func_80800DAC_chflysaucer(arg0, sp34, sp28, 1000.0f);
    sp28[0] = -sp28[0];
    func_808039B8_chflysaucer(sp20[0], sp34, sp28, &D_808046C4_chflysaucer, arg1, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80803B60_chflysaucer.s")

void func_80803BE8_chflysaucer(s32 arg0) 
{
}
void func_80803BF0_chflysaucer(Actor *arg0, s32 arg1) {
    func_80102424(arg0, arg1);
    if (arg0->unk70_10 == 2) {
        _subaddiefade_entrypoint_3(arg0);
        func_8010A800(arg0, 2);
    }
}

void func_80803C3C_chflysaucer(Actor *arg0) {
    f32 func_800D8FF8(void);
    void _subaddiefade_entrypoint_6(Actor *, s32);

    switch (arg0->unk70_10) {
        case 1:
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= func_800D8FF8();
            } else {
                func_80803BF0_chflysaucer(arg0, 2);
            }
            break;
        case 2:
            _subaddiefade_entrypoint_6(arg0, -0x3C);
            break;
    }
}

void func_80803CC4_chflysaucer(s32 arg0, s32 arg1) {
    s32 func_800B53A4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808046DC_chflysaucer;
    s32 sp24;
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = func_800B53A4(6);
    temp_a1 = arg0 + 4;
    sp24 = temp_v0;
    func_800BABB8(temp_v0, temp_a1, temp_a1, 0x3FB33333, &D_808046DC_chflysaucer);
    func_800BA3FC(sp24, arg1);
    func_800BA22C(sp24, 6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80803D30_chflysaucer.s")

OSThread *chflysaucer_entrypoint_2(void)
{
    extern u8 D_8080470C_chflysaucer[];

    return (OSThread *) D_8080470C_chflysaucer;
}
