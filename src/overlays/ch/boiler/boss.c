#include "common.h"

OSThread *chboilerboss_entrypoint_0(void)
{
    extern u8 D_80802C0C_chboilerboss[];

    return (OSThread *) D_80802C0C_chboilerboss;
}

OSThread *chboilerboss_entrypoint_1(void)
{
    extern u8 D_80802C54_chboilerboss[];

    return (OSThread *) D_80802C54_chboilerboss;
}

OSThread *chboilerboss_entrypoint_2(void)
{
    extern u8 D_80802C9C_chboilerboss[];

    return (OSThread *) D_80802C9C_chboilerboss;
}

OSThread *chboilerboss_entrypoint_3(void)
{
    extern u8 D_80802CE4_chboilerboss[];

    return (OSThread *) D_80802CE4_chboilerboss;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80800030_chboilerboss.s")

void func_80800304_chboilerboss(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80800324_chboilerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_808008B0_chboilerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80800B94_chboilerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80800D50_chboilerboss.s")

/* extern */

void func_80800E64_chboilerboss(void *arg0) {
    s32 func_800D2498(s32, u8, s32, void *);
    func_800D2498(0xC7, (*(u8 *)((s8 *)(arg0) + (0x5E))), 0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80800E90_chboilerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80800F34_chboilerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_808010F4_chboilerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_808012C8_chboilerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_808013C4_chboilerboss.s")

void func_80801464_chboilerboss(Actor *arg0, f32 *arg1, f32 arg2) {
    f32 func_800136E4(f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80100094(Actor *, u32);

    func_800EE7F8(arg1, func_80100094(arg0, 0));
    func_800EF1B8(arg1, func_800136E4(arg0->rotation[1] + 90.0f), 15.0f);
    func_800EF1B8(arg1, arg0->rotation[1], arg2);
    arg1[1] -= 10.0f;
}

void func_808014F4_chboilerboss(Actor *arg0, f32 *arg1, f32 arg2) {
    f32 func_800136E4(f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 *data;

    data = func_80100094(arg0, 0);
    func_800EE7F8(arg1, data + 3);
    func_800EF1B8(arg1, func_800136E4(arg0->rotation[1] - 90.0f), 15.0f);
    func_800EF1B8(arg1, arg0->rotation[1], arg2);
    arg1[1] -= 10.0f;
}

void func_80801584_chboilerboss(Actor *arg0, s32 arg1)
{
  void func_80102424(Actor *, s32);
  void func_80102FDC(void *, f32);
  void func_80105A9C(Actor *, f32);
  Actor *func_801084B0(s32, Actor **);
  extern f32 D_80802B4C_chboilerboss[];
  Actor *sp1C;
  u32 flags;
  s32 index;
  Actor *temp_v0;
  temp_v0 = func_801084B0(arg1, &arg0);
  sp1C = temp_v0;
  temp_v0->unk3C = arg0->unk0;
  func_80102424(temp_v0, temp_v0->unk70_10);
  func_80102FDC(sp1C, arg0->scale);
  flags = arg0->unk0->unk28;
  index = ((3 - ((s32) ((flags << 20) >> 31))) - ((s32) ((flags << 19) >> 31))) - ((s32) ((flags << 18) >> 31));
  func_80105A9C(arg0, *((f32 *) (((u8 *) D_80802B4C_chboilerboss) + ((((index < 0) ? (index) : (index)) << 1) << 1))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80801628_chboilerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_808017F0_chboilerboss.s")

void func_808019C8_chboilerboss(s32 arg0, f32 *arg1) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80802ACC_chboilerboss;
    func_800BBCB8(arg1, 0, 1.0f, 1, &D_80802ACC_chboilerboss);
}

void func_80801A08_chboilerboss(s32 arg0, f32 *arg1) {
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802ACC_chboilerboss;
    extern s32 D_80802D68_chboilerboss;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(1);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg1, 0, 1.0f, &D_80802ACC_chboilerboss);
    func_800BABB8(sp24, arg1, 0, 1.0f, &D_80802D68_chboilerboss);
}

void func_80801A74_chboilerboss(Actor *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    void func_800BA22C(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802D88_chboilerboss;
    extern s32 D_80802DA4_chboilerboss;
    extern s32 D_80802DB0_chboilerboss;
    s32 emitter;
    s32 *settings;

    emitter = func_800BABB8(0, arg1, arg2, arg0->scale, &D_80802D88_chboilerboss);
    if (arg3 != 0) {
        settings = &D_80802DA4_chboilerboss;
    } else {
        settings = &D_80802DB0_chboilerboss;
    }
    func_800BABB8(emitter, arg1, arg2, arg0->scale, settings);
    func_800BA22C(emitter, 0x10);
}

void func_80801B00_chboilerboss(Actor *arg0, f32 *arg1) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80802DBC_chboilerboss;
    func_800BBCB8(arg1, 0, arg0->scale, 4, &D_80802DBC_chboilerboss);
}

void func_80801B44_chboilerboss(Actor *arg0, f32 *arg1) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80802E00_chboilerboss;
    func_800BBCB8(arg1, 0, arg0->scale, 8, &D_80802E00_chboilerboss);
}

void func_80801B88_chboilerboss(Actor *arg0, s32 *arg1) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EC398(s32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    extern s32 D_80802E44_chboilerboss;
    extern s32 D_80802E6C_chboilerboss;
    f32 sp34[3];
    f32 sp28[3];
    f32 sp20[2];

    func_800EC398(arg1, sp34);
    func_800F18FC(sp34, arg0->position, sp20);
    func_800EEBF0(sp28, sp20, 40.0f);
    func_800EF04C(sp28, sp34);
    func_800BBCB8(sp34, sp28, 0.7f, 6, &D_80802E44_chboilerboss);
    func_800BBCB8(sp34, sp28, 1.0f, 3, &D_80802E6C_chboilerboss);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80801C24_chboilerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80801CE8_chboilerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80801D80_chboilerboss.s")

void func_80801EB4_chboilerboss(Actor *arg0) { void func_80101CDC(Actor *, f32); f32 func_8010203C(Actor *, u32); f32 func_80105AC4(Actor *); f32 sp1C; f32 sp18; extern f32 D_80802B58_chboilerboss; sp18 = func_8010203C(arg0, (u32)arg0->unk70_10); sp1C = D_80802B58_chboilerboss / func_80105AC4(arg0); func_80101CDC(arg0, sp18 * sp1C); }

/* extern */

void func_80801F10_chboilerboss(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    if (func_800DA298(0x86) != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80801F44_chboilerboss.s")

void func_80802098_chboilerboss(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    extern u32 D_80802EB0_chboilerboss;
    extern u32 D_80802EC4_chboilerboss;
    extern u32 D_80802ED0_chboilerboss;

    switch (arg0->unk6C_9) {
    case 0x223:
    case 0x224:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80802EB0_chboilerboss, &D_80802EC4_chboilerboss);
        return;
    case 0x225:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80802EB0_chboilerboss, &D_80802ED0_chboilerboss);
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80802114_chboilerboss.s")

/* extern */

void func_8080221C_chboilerboss(Actor *arg0, s32 arg1, volatile s32 arg2) {
    s32 _chboilerid_entrypoint_5(Actor *);
    s32 _chboilerid_entrypoint_6(Actor *, s32);
    Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 pad[2];
    f32 *sp24;
    Actor *temp_v0;
    if (arg0->unk3C == NULL) {
        temp_v0 = _subaddiefind_entrypoint_0(arg0->position, 0x321, -1, 0);
        if (temp_v0 == NULL) {
            return;
        }
        arg0->unk3C = temp_v0->unk0;
    }
    sp24 = arg0->position;
    arg0 = func_80106790(arg0->unk3C);
    if (arg1 != 0) {
        _chboilerid_entrypoint_6(arg0, arg2);
    } else {
        _chboilerid_entrypoint_5(arg0);
    }
    func_800EE7F8((f32 *)arg0->actorData, sp24);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_808022BC_chboilerboss.s")

void func_8080238C_chboilerboss(Unk80132ED0 **arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    arg2 |= 0x104;
    _subaddiedialog_entrypoint_11(*arg0, arg1, arg2, (f32 *)(arg0 + 1), 0x42);
}

/* extern */

s32 func_808023C8_chboilerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_80800F34_chboilerboss(s32, s32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if (((*(s32 *)((s8 *)(temp_v0) + (0x60))) == 0) && ((*(s16 *)((s8 *)(temp_v0) + (0x64))) != 0)) {
        func_80800F34_chboilerboss(arg0, 2);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80802414_chboilerboss.s")

void func_808024B8_chboilerboss(s32 arg0)
{
    func_800FDC28(0x1);
}

/* extern */

void func_808024DC_chboilerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_80802538_chboilerboss(s32);
    u8 *temp_v0;
    u8 *saved[1];

    temp_v0 = func_80100094(arg0, 0);
    if (temp_v0[0x57] == 0 && temp_v0[0x58] != 0 && temp_v0[0x59] == 0) {
        func_80802538_chboilerboss(arg0);
        if (0) {
            saved[0] = temp_v0;
        }
        temp_v0[0x58] = 0;
    }
}

/* extern */

void func_80802538_chboilerboss(s32 arg0) {
    u32 func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    s32 func_800F4AF4(u32, s32);
    s32 func_808025DC_chboilerboss(s32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    if ((*(u8 *)((s8 *)(temp_v0) + (0x57))) == 0) {
        func_800F4AF4(func_800F54E4(), 0x14);
        (*(s8 *)((s8 *)(sp1C) + (0x57))) = 1;
    }
    func_808025DC_chboilerboss(arg0);
}

/* extern */

void func_80802594_chboilerboss(s32 arg0) {
    u32 func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    s32 func_800F4B20(u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    if ((*(u8 *)((s8 *)(temp_v0) + (0x57))) != 0) {
        func_800F4B20(func_800F54E4());
        (*(s8 *)((s8 *)(sp1C) + (0x57))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_808025DC_chboilerboss.s")

/* extern */

s32 func_80802690_chboilerboss(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80802730_chboilerboss(s32, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(u8 *)((s8 *)(func_80100094(arg0, 0)) + (0x59))) != 2) {
            func_80802730_chboilerboss(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_808026F0_chboilerboss(s32 arg0) {
    void _capod_entrypoint_3(u32);
    void *func_80100094(Actor *, u32);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x59))) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_3(0);
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + (0x59))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_80802730_chboilerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/boss/func_808027E4_chboilerboss.s")
