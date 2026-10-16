#include "common.h"

OSThread *chfishshootgame_entrypoint_0(void)
{
    extern u8 D_808018C0_chfishshootgame[];

    return (OSThread *) D_808018C0_chfishshootgame;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_8080000C_chfishshootgame.s")

void func_80800178_chfishshootgame(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    s32 func_800FCCD4(s32);
    void *func_80100094(Actor *, u32);
    s32 data[2];

    data[1] = (s32)func_80100094(arg0, 0);
    _susubgame_entrypoint_11(0);
    if (func_800FCCD4(0x53) != 0) {
        func_800FCAE0(0x53, 0, 0xFA0);
        func_800FCA90(0x53);
    }
    data[0] = data[1] + 0xB0;
    if (_susubgame_entrypoint_2(arg0, data[0]) != 0) {
        _susubgame_entrypoint_4(arg0, data[0]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_808001F0_chfishshootgame.s")

void func_808002E8_chfishshootgame(Actor *arg0, f32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor*, f32[3], void*);
    void func_800C4B64(f32);
    extern s32 D_80801978_chfishshootgame;
    func_800C4B64(arg1);
    _subaddieaudioquick_entrypoint_2(arg0, (f32 *)((u8 *)arg0 + 4), &D_80801978_chfishshootgame);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_80800320_chfishshootgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_808003B0_chfishshootgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_8080076C_chfishshootgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_808009C0_chfishshootgame.s")

void func_80800A28_chfishshootgame(Actor *arg0) {
    void *func_8008AEDC(void *);
    s32 *func_8008C27C(void *);
    void *func_80100094(Actor *, u32);
    struct anctrl_s *func_80104248(void *);
    void func_800DFC20(s32 *, s32, f32 *);
    s32 pad;
    s32 *sp30;
    u8 *sp2C;
    f32 sp20[3];

    sp30 = func_8008C27C(func_8008AEDC(func_80104248(arg0)));
    sp2C = func_80100094(arg0, 0U);
    func_800DFC20(sp30, 0x5D, sp20);
    *(f32 *)(sp2C + 0x24) = *(f32 *)(sp2C + 0x28) * sp20[1];
}

void func_80800A90_chfishshootgame(Actor *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    func_800EE7F8(arg1, arg0->position);
    arg1[1] += (*(f32 *)((s8 *)(sp1C) + (0x24))) + 60.0f;
}

/* extern */

void func_80800AF0_chfishshootgame(u8 *arg0) {
    s32 *func_80108528(s32, s32, s32, u8 **);
    (*(s32 *)((s8 *)(arg0) + (0x3C))) = (s32) *func_80108528(0x1D0, arg0 + 4, 0, &arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_80800B30_chfishshootgame.s")

void func_80800C24_chfishshootgame(u8 *arg0) {
    u8 func_800C4350(u8, f32[3], s32 *);
    extern s32 D_808019A8_chfishshootgame;
    if (arg0[0x5F] == 0) {
        arg0[0x5F] = func_800C4350(0, NULL, &D_808019A8_chfishshootgame);
    }
    func_800C4350(arg0[0x5F], NULL, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_80800C78_chfishshootgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_80800D48_chfishshootgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_80801110_chfishshootgame.s")

OSThread *chfishshootgame_entrypoint_1(void)
{
    extern u8 D_80801A00_chfishshootgame[];

    return (OSThread *) D_80801A00_chfishshootgame;
}

void func_80801358_chfishshootgame(Actor *arg0) { union { f32 values[2]; f64 alignment; } result; Actor *actor = func_80106790(arg0->unk3C); func_80800A90_chfishshootgame(actor, (f32 *)arg0->actorData); func_800F18FC(arg0->position, (f32 *)arg0->actorData, result.values); arg0->rotation[1] = result.values[1]; arg0->rotation[0] = -result.values[0]; }

void func_808013B8_chfishshootgame(void *arg0)
{
  f32 func_800D8FF8();
  s32 func_8010B990(void *, s32);
  f32 temp_f0;
  *((f32 *) (((s8 *) arg0) + 0x24)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x58))) * func_800D8FF8());
  func_8010B990(arg0, 0x100008);
  temp_f0 = *((f32 *) (((s8 *) arg0) + 0x50));
  if (temp_f0 < ((*((f32 *) (((s8 *) arg0) + 8))) + 40.0f))
  {
    *((f32 *) (((s8 *) arg0) + 8)) = (f32) (temp_f0 - 40.0f);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_80801424_chfishshootgame.s")

/* extern */

void func_80801568_chfishshootgame(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    s32 func_80801424_chfishshootgame(s32, s32);
    arg0->scale = 0.3f;
    if (arg0->unk58 < 100.0f) {
        arg0->unk58 = func_800DC178(100.0f, 200.0f);
    }
    func_80801358_chfishshootgame(arg0);
    arg0->unk70_10 = 0;
    func_80801424_chfishshootgame(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fishshootgame/func_808015DC_chfishshootgame.s")

/* extern */

s32 func_80801768_chfishshootgame(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80801424_chfishshootgame(s32, s32);
    if (arg1 == 0x40) {
        func_80801424_chfishshootgame(arg0, 4);
        return 1;
    }
    return 0;
}

OSThread *chfishshootgame_entrypoint_2(void)
{
    extern u8 D_80801A7C_chfishshootgame[];

    return (OSThread *) D_80801A7C_chfishshootgame;
}
