#include "common.h"

OSThread *chbilldrillplate_entrypoint_0(void)
{
    extern u8 D_808010DC_chbilldrillplate[];

    return (OSThread *) D_808010DC_chbilldrillplate;
}

OSThread *chbilldrillplate_entrypoint_1(void)
{
    extern u8 D_80801124_chbilldrillplate[];

    return (OSThread *) D_80801124_chbilldrillplate;
}

OSThread *chbilldrillplate_entrypoint_2(void)
{
    extern u8 D_8080116C_chbilldrillplate[];

    return (OSThread *) D_8080116C_chbilldrillplate;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800024_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_808000B0_chbilldrillplate.s")

/* extern */

s32 func_80800240_chbilldrillplate(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_5(Actor *, s32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    s32 *value = &arg2;
    switch (arg1) {
    case 0x3F:
        if (_subaddieDll_entrypoint_5(arg0, *value) != 0) {
            func_80103110(arg0, 1);
            func_80101FDC(arg0, 2);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_808002A0_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800358_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800408_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800738_chbilldrillplate.s")

/* extern */

void func_80800924_chbilldrillplate(void *arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(void *, s32);
    void *func_80801020_chbilldrillplate();
    s32 var_a1;

    if ((*(u8 *)((s8 *)(func_80801020_chbilldrillplate()) + (0x13))) != 0) {
        var_a1 = 0;
    } else {
        var_a1 = (*(s32 *)((s8 *)(arg0) + (0x2C)));
    }
    func_800DF744(1, var_a1);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800978_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800B9C_chbilldrillplate.s")

/* extern */

s32 func_80800C98_chbilldrillplate(Actor *volatile arg0, f32 *arg1, f32 arg2) {
    void *func_800C6A7C(f32[3], f32[3], f32[3], u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_8010A624(Actor *);
    void func_8010A63C(Actor *);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    s32 var_v1;
    union {
        f32 *position;
        void *collision;
    } sp1C;
    Actor *actor;

    sp1C.position = arg0->position;
    func_800EE7F8(sp3C, sp1C.position);
    func_800EE7F8(sp30, sp1C.position);
    sp3C[1] += 20.0f + arg2;
    sp30[1] -= 20.0f;
    func_8010A624(arg0);
    sp1C.collision = func_800C6A7C(sp3C, sp30, sp24, 0x20020);
    actor = arg0;
    if (sp1C.collision) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    func_8010A63C(actor);
    if (var_v1 != 0) {
        *arg1 = sp30[1];
    }
    return var_v1;
}

/* extern */

void func_80800D5C_chbilldrillplate(s32 arg0) {
    s32 _subaddiefade_entrypoint_14(s32);
    s32 func_800DA298(u16);
    s32 func_800FFAB0(s32);
    void *func_80800FCC_chbilldrillplate();
    if (func_800DA298((*(u16 *)((s8 *)(func_80800FCC_chbilldrillplate()) + (0xC)))) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    _subaddiefade_entrypoint_14(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800DA4_chbilldrillplate.s")

/* extern */

s32 func_80800F24_chbilldrillplate(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_6(Actor *, f32, f32);
    s32 func_800DA298(u16);
    Unk80132ED0 *func_80101080(void);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80800FCC_chbilldrillplate(void);
    switch (arg1) {
    case 0x95:
        if (func_800DA298(((u16 *)func_80800FCC_chbilldrillplate())[6])) {
            func_80101FDC(arg0, 2);
            arg0->unk58 = 0.16f;
            func_80103110(arg0, 1);
        }
        break;
    case 0x90:
        _chexploder_entrypoint_6(func_80106790(func_80101080()), 500.0f, 600.0f);
        break;
    default:
        return 0;
    }
    return 1;
}

void *func_80800FCC_chbilldrillplate(void)
{
  s32 func_800EA05C();
  extern u16 D_808010A0_chbilldrillplate;
  extern u8 D_808010DC_chbilldrillplate[];
  s32 temp_v0;
  u16 *var_v1;
  temp_v0 = func_800EA05C();
 var_v1 = &D_808010A0_chbilldrillplate; loop_1: if (temp_v0 == (*var_v1)) {
    return var_v1;
  }

  var_v1 += 0xA;
  if (((u8 *) var_v1) == D_808010DC_chbilldrillplate)
  {
    return NULL;
  }
  goto loop_1;
}

void *func_80801020_chbilldrillplate(void)
{
  s32 func_800EA05C();
  extern u16 D_808010A0_chbilldrillplate;
  extern u8 D_808010DC_chbilldrillplate[];
  u16 *var_v1;
  s32 temp_v0;
  temp_v0 = func_800EA05C();
 var_v1 = &D_808010A0_chbilldrillplate; loop_1: if (temp_v0 == var_v1[1]) {
    return var_v1;
  }

  var_v1 += 0xA;
  if (((u8 *) var_v1) == D_808010DC_chbilldrillplate)
  {
    return NULL;
  }
  goto loop_1;
}
