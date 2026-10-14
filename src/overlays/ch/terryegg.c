#include "common.h"

OSThread *chterryegg_entrypoint_0(void)
{
    extern u8 D_80801260_chterryegg[];

    return (OSThread *) D_80801260_chterryegg;
}

OSThread *chterryegg_entrypoint_1(void)
{
    extern u8 D_80801328_chterryegg[];

    return (OSThread *) D_80801328_chterryegg;
}

OSThread *chterryegg_entrypoint_2(void)
{
    extern u8 D_80801370_chterryegg[];

    return (OSThread *) D_80801370_chterryegg;
}

OSThread *chterryegg_entrypoint_3(void)
{
    extern u8 D_808013B8_chterryegg[];

    return (OSThread *) D_808013B8_chterryegg;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/terryegg/func_80800030_chterryegg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/terryegg/func_808000A8_chterryegg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/terryegg/func_8080023C_chterryegg.s")

/* extern */

void func_8080057C_chterryegg(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    s32 func_801088A8(Actor *, s32, s32, s32);
    f32 func_80801188_chterryegg(Actor *, s32);
    func_80102FDC(arg0, func_80801188_chterryegg(arg0, 0));
    func_801088A8(arg0, 0x10002000, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/terryegg/func_808005C4_chterryegg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/terryegg/func_808009B4_chterryegg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/terryegg/func_80800A2C_chterryegg.s")

void func_80800BD0_chterryegg(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor*, s32);
    if ((arg1 != 0x17E1) && (arg1 == 0x17FE)) {
        func_80102424(arg0, 6);
    }
}

void func_80800C08_chterryegg(Actor *arg0) {
    s16 _glsplinefind_entrypoint_0(u32, f32*);
    void* func_80100094(Actor*, u32);
    s32 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    *sp1C = _glsplinefind_entrypoint_0(0x357U, arg0->position);
}

void func_80800C48_chterryegg(s32 arg0)
{
    func_8010C964();
    func_80801080_chterryegg(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/terryegg/func_80800C70_chterryegg.s")

s32 func_80800CF4_chterryegg(Actor *arg0, f32 arg1) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg1);
    return 1;
}

void func_80800D20_chterryegg(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    s32 func_800DA298(s32);
    extern s32 _subaddietaxi_entrypoint_16;
    if (func_800DA298(arg0 + 0x16E) == 0) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, (*(s32 *)((s8 *)(arg1) + (0))), (*(s32 *)((s8 *)(arg1) + (4))), (*(s32 *)((s8 *)(arg1) + (8))), arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/terryegg/func_80800D88_chterryegg.s")

/* extern */

s32 func_80800E0C_chterryegg(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800C05B8(s32, s32, s32, s32, s32, s32, s32);
    s32 func_800CBD84(s32);
    s32 func_800EA05C();
    s32 func_80800D88_chterryegg(s32, s32);
    if ((func_800EA05C() == 0x113) && (func_800CBD84(arg1) != -1)) {
        func_80800D88_chterryegg(arg0, arg2);
        return 2;
    }
    func_800C05B8(0x17E0, 1, 0, 0, 0, 0, 0);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/terryegg/func_80800E88_chterryegg.s")

void func_80800FE0_chterryegg(u8 *arg0) {
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    s32 func_800D9078(s32);
    f32 func_800DC178(f32, f32);
    extern s32 D_80801410_chterryegg;
    func_800D9078(arg0 + 0x58);
    if ((*(f32 *)((s8 *)(arg0) + (0x58))) <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80801410_chterryegg);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = func_800DC178(1.5f, 2.5f);
    }
}

void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);

void func_80801050_chterryegg(Actor *arg0) {
    extern u32 D_80801424_chterryegg;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801424_chterryegg, 0.81f);
}

int func_80801080_chterryegg(s32 arg0) {
    extern u32 D_8080126C_chterryegg;
    extern u32 D_80801438_chterryegg;
    _subaddieaudioquick_entrypoint_4(arg0, (f32 *) (arg0 + 4), &D_8080126C_chterryegg, &D_80801438_chterryegg);
}

void func_808010B0_chterryegg(Actor *arg0) {
    extern u32 D_80801450_chterryegg;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801450_chterryegg, 0.0f);
}

/* extern */

s32 func_808010DC_chterryegg(void) {
    s32 func_800DA564(s32, s32);
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_800DA564(0x175, 4);
    var_v1 = 0;
    if (temp_v0 & 1) {
        var_v1 = 1;
    }
    if (temp_v0 & 2) {
        var_v1 += 1;
    }
    if (temp_v0 & 4) {
        var_v1 += 1;
    }
    if (temp_v0 & 8) {
        var_v1 += 1;
    }
    return 4 - var_v1;
}

s32 func_80801138_chterryegg(void *arg0)
{
  s32 func_800DA564(s32, s32);
  s32 temp_v0;
  temp_v0 = func_800DA564(0x361, 3);
  if (temp_v0 == 0)
  {
    return 0;
  }
  return (temp_v0 + 0x31) == (((unsigned long) ((u16) (*((u16 *) (((s8 *) arg0) + 0x76))))) >> 7);
}

f32 func_80801188_chterryegg(Actor *arg0, s32 arg1) {
    f32 var_f2;

    if (arg1 != 0) {
        if (func_808010DC_chterryegg() == 1) {
            var_f2 = 4.0f;
        } else {
            var_f2 = 2.0f;
        }
        return var_f2;
    } else if (func_80801138_chterryegg(arg0) != 0) {
        var_f2 = 4.0f;
    } else {
        var_f2 = 2.0f;
    }
    return var_f2;
}
