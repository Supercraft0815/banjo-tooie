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

void func_80800024_chbilldrillplate(Actor *arg0) {
    s32 _subaddiefade_entrypoint_14(s32);
    s32 func_800DA298(s32);
    int func_800DC298(f32);
    void func_800FFAB0(Actor *);
    void *func_80800FCC_chbilldrillplate(void);
    f32 direction;

    if (func_800DA298(((u16 *)func_80800FCC_chbilldrillplate())[6])) {
        func_800FFAB0(arg0);
        return;
    }
    _subaddiefade_entrypoint_14(arg0);
    if (func_800DC298(0.5f)) {
        direction = -1.0f;
    } else {
        direction = 1.0f;
    }
    *(f32 *)&arg0->actorData[4] = direction * 200.0f;
}

void func_808000B0_chbilldrillplate(Actor *arg0) {
    void _chbounce_entrypoint_3(f32);
    void _chbounce_entrypoint_5(s32, void *);
    s32 _subaddieDll_entrypoint_6(Actor *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefade_entrypoint_3(Actor *);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    void func_8010A570(Actor *);
    void func_8010A624(Actor *);
    void func_808002A0_chbilldrillplate(s32);
    extern u8 D_808011B4_chbilldrillplate[];
    struct PlateFlags {
        u32 unused:28;
        u32 active:1;
        u32 unused2:3;
    };

    switch (arg0->unk70_10) {
    case 1:
        break;
    case 2:
        if (func_800D90A4((f32 *)&arg0->actorData[5])) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808011B4_chbilldrillplate);
            *(f32 *)&arg0->actorData[5] = 0.4f;
        }
        arg0->rotation[1] = func_800136E4(arg0->rotation[1] + func_800D8FF8() * 600.0f);
        arg0->position[1] += func_800D8FF8() * 50.0f;
        if (_subaddieDll_entrypoint_6(arg0, 0xB)) {
            _chbounce_entrypoint_3(arg0->rotation[1]);
            _chbounce_entrypoint_5(0x1B, arg0);
            func_80101FDC(arg0, 3);
            func_8010A624(arg0);
            func_8010A570(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808011B4_chbilldrillplate);
            *(f32 *)&arg0->actorData[6] = 1.2f;
        }
        break;
    case 3:
        arg0->rotation[0] = func_800136E4(arg0->rotation[0] + func_800D8FF8() * *(f32 *)&arg0->actorData[4]);
        if (func_800D9078((f32 *)&arg0->actorData[6])) {
            func_808002A0_chbilldrillplate((s32)arg0);
        }
        if (!((struct PlateFlags *)&arg0->unk78)->active) {
            _subaddiefade_entrypoint_3(arg0);
            func_80101FDC(arg0, 4);
            func_80103110(arg0, 0);
        }
        break;
    }
}

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

void func_808002A0_chbilldrillplate(s32 arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    void func_800DA544(GameFlag);
    void *func_80800FCC_chbilldrillplate(void);
    u8 *actors[4];
    s32 found;
    s32 state;
    s32 count;
    u16 *data;

    found = _subaddiefind_entrypoint_4(0x3DC, actors, 4);
    count = found;
    for (state = 0; state < found; state++) {
        if ((s32)((Actor *)actors[state])->unk70_10 >= 3) {
            count--;
        }
    }
    if (count == 3 || count == 0) {
        data = func_80800FCC_chbilldrillplate();
        if (count == 0) {
            func_800DA544(data[6]);
        }
        _glcutDll_entrypoint_6(data[1], data[7]);
    }
}

void func_80800358_chbilldrillplate(Actor *arg0) {
    s32 _subaddiefade_entrypoint_14(s32);
    s32 _subaddielink_entrypoint_0(u8 *);
    void *func_80100094(Actor *, u32);
    void *func_80801020_chbilldrillplate(void);
    u16 *sp24;
    f32 *sp20;

    sp24 = func_80801020_chbilldrillplate();
    sp20 = func_80100094(arg0, 0);
    *(f32 *)&arg0->actorData[7] = 600.0f;
    *(f32 *)&arg0->actorData[4] = arg0->position[1];
    arg0->position[1] += sp24[2];
    _subaddielink_entrypoint_0(sp20);
    _subaddiefade_entrypoint_14(arg0);
    if (sp24[8] != 0) {
        sp20[2] = 25.0f;
    }
}

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

void func_80800B9C_chbilldrillplate(Actor *arg0) {
    s32 func_800EA05C(void);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_80101010(f32 *);
    s32 func_80101180(s32, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern u8 D_80801220_chbilldrillplate[];
    f32 sp2C[3];
    f32 sp20[3];

    switch (func_800EA05C()) {
        case 0x101:
            func_800EFA4C(sp2C, 180.0f, 680.0f, 180.0f);
            func_800EF04C(sp2C, arg0->position);
            func_80101010(sp2C);
            func_80101180(0x473, 5, 0);
            _subaddieaudioquick_entrypoint_2(arg0, sp2C, D_80801220_chbilldrillplate);
            break;
        case 0x107:
            func_800EFA4C(sp20, 130.0f, 220.0f, 130.0f);
            func_800EF04C(sp20, arg0->position);
            func_80101010(sp20);
            func_80101180(0x473, 5, 0);
            _subaddieaudioquick_entrypoint_2(arg0, sp20, D_80801220_chbilldrillplate);
            break;
    }
}

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
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void *func_80800FCC_chbilldrillplate();
    if (func_800DA298((*(u16 *)((s8 *)(func_80800FCC_chbilldrillplate()) + (0xC)))) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    _subaddiefade_entrypoint_14(arg0);
}

void func_80800DA4_chbilldrillplate(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800D9078(f32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_80801234_chbilldrillplate;
    extern s32 D_80801244_chbilldrillplate;
    f32 sp7C[3];
    f32 sp70[3];
    s32 temp_s5;
    s32 var_s1;

    if (arg0->unk70_10 == 2 && func_800D9078(&arg0->unk58)) {
        func_800EE7F8(sp7C, arg0->position);
        sp7C[1] -= 150.0f;
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801234_chbilldrillplate);
        temp_s5 = func_800B53A4(5);
        for (var_s1 = 0; var_s1 != 5; var_s1++) {
            func_800EE7F8(sp70, arg0->position);
            func_800EF1B8(sp70, (f32)var_s1 * 72.0f, func_800DC178(100.0f, 120.0f));
            func_800BABB8(temp_s5, sp70, sp7C, 1.4f, &D_80801244_chbilldrillplate);
        }
        _chexploder_entrypoint_3(arg0, sp7C, 8);
    }
}

/* extern */

s32 func_80800F24_chbilldrillplate(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_6(Actor *, f32, f32);
    s32 func_800DA298(s32);
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
