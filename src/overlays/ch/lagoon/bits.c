#include "common.h"

OSThread *chlagoonbits_entrypoint_0(void)
{
    extern u8 D_80800804_chlagoonbits[];

    return (OSThread *) D_80800804_chlagoonbits;
}

OSThread *chlagoonbits_entrypoint_1(void)
{
    extern u8 D_8080084C_chlagoonbits[];

    return (OSThread *) D_8080084C_chlagoonbits;
}

OSThread *chlagoonbits_entrypoint_2(void)
{
    extern u8 D_80800894_chlagoonbits[];

    return (OSThread *) D_80800894_chlagoonbits;
}

OSThread *chlagoonbits_entrypoint_3(void)
{
    extern u8 D_808008DC_chlagoonbits[];

    return (OSThread *) D_808008DC_chlagoonbits;
}

OSThread *chlagoonbits_entrypoint_4(void)
{
    extern u8 D_80800924_chlagoonbits[];

    return (OSThread *) D_80800924_chlagoonbits;
}

OSThread *chlagoonbits_entrypoint_5(void)
{
    extern u8 D_8080096C_chlagoonbits[];

    return (OSThread *) D_8080096C_chlagoonbits;
}

void func_80800048_chlagoonbits(s32 arg0) 
{
}
void func_80800050_chlagoonbits(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor*);
    if (func_800DA298(arg0->unk6C_9 == 0x368 ? 0xCB : 0xCC) != 0) {
        func_800FFAB0(arg0);
    }
}

void func_808000A4_chlagoonbits(s32 arg0) 
{
}
/* extern */

void func_808000AC_chlagoonbits(void *arg0) {
    s32 _subaddiesect_entrypoint_1();
    s32 func_800DA298(s32);
    s32 func_80101FDC(void *, s32);
    s32 func_80108B04(void *, s32);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = _subaddiesect_entrypoint_1();
    if (func_800DA298(0xCF) != 0) {
        func_80108B04(arg0, 0);
        func_80101FDC(arg0, 3);
        (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFFE);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/bits/func_80800108_chlagoonbits.s")

/* extern */

void func_808001F4_chlagoonbits(Actor *arg0) {
    s32 _subaddieDll_entrypoint_6(Actor*, s32);
    s32 func_8080023C_chlagoonbits(Actor *);
    if (((((u32) (*(u16 *)((s8 *)(arg0) + (0x72)))) >> 0xA) == 2) && (_subaddieDll_entrypoint_6(arg0, 0xB) != 0)) {
        func_8080023C_chlagoonbits(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/bits/func_8080023C_chlagoonbits.s")

void func_808002CC_chlagoonbits(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_808007D0_chlagoonbits;
    extern s32 D_808009B4_chlagoonbits;
    f32 sp24[3];

    func_800EE7F8(sp24, arg0->position);
    func_800EF1B8(sp24, arg0->rotation[1], -100.0f);
    _chexploder_entrypoint_3(arg0, sp24, 0xE);
    func_800BBCB8(arg0->position, sp24, 0.8f, 5, &D_808007D0_chlagoonbits);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808009B4_chlagoonbits);
    func_800DA544(0xCE);
}

void func_80800360_chlagoonbits(Actor *arg0)
{
  void _chexploder_entrypoint_3(void *, void *, u32);
  void _subaddieaudioquick_entrypoint_2(Actor *, f32 [3], void *);
  s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
  s32 func_800DA544(s32);
  void func_800EE7F8(f32 *, f32 *);
  void func_800EF1B8(f32 *, f32, f32);
  extern s32 D_808007D0_chlagoonbits;
  extern s32 D_808009CC_chlagoonbits;
  s32 sp3C;
  f32 sp30[3];
  f32 *sp2C[1];
  if (arg0->unk6C_9 == 0x368)
  {
    sp3C = 0xCB;
  }
  else
  {
    sp3C = 0xCC;
  }
  if (sp30)
  {
  }
  sp2C[0] = arg0->position;
  func_800EE7F8(sp30, sp2C[0]);
  func_800EF1B8(sp30, arg0->rotation[1], -100.0f);
  _subaddieaudioquick_entrypoint_2(arg0, sp2C[0], &D_808009CC_chlagoonbits);
  func_800BBCB8(sp2C[0], sp30, 0.8f, 5, &D_808007D0_chlagoonbits);
  _chexploder_entrypoint_3(arg0, sp30, 0xE);
  func_800DA544(sp3C);
}

void func_8080041C_chlagoonbits(Actor *volatile arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_808009E4_chlagoonbits;
    extern s32 D_808009FC_chlagoonbits;
    f32 sp24[3];
    f32 *sp20;

    sp20 = arg0->position;
    func_800EE7F8(sp24, sp20);
    sp24[1] -= 100.0f;
    _subaddieaudioquick_entrypoint_2(arg0, sp20, &D_808009E4_chlagoonbits);
    func_800BBCB8(sp20, sp24, 0.8f, 5, &D_808009FC_chlagoonbits);
    _chexploder_entrypoint_3(arg0, sp24, 0xE);
    func_800DA544(0xCD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/bits/func_808004B0_chlagoonbits.s")

void func_80800548_chlagoonbits(Actor *volatile arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    s32 func_800DA544(s32);
    void func_800FFAB0(Actor *);
    extern s32 D_808007D0_chlagoonbits;
    f32 *temp_s0;

    temp_s0 = arg0->position;
    func_800D1000(0x14, 0, temp_s0, 1, 0);
    _chexploder_entrypoint_3(arg0, temp_s0, 7);
    func_800BBCB8(temp_s0, temp_s0, 0.8f, 5, &D_808007D0_chlagoonbits);
    func_800DA544(0x45);
    func_800FFAB0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/bits/func_808005D0_chlagoonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/bits/func_80800658_chlagoonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/bits/func_80800730_chlagoonbits.s")
