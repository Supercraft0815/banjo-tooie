#include "ch/nicecavemenguard.h"

OSThread *chnicecavemenguard_entrypoint_0(void)
{
    extern u8 D_80800920_chnicecavemenguard[];

    return (OSThread *) D_80800920_chnicecavemenguard;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_8080000C_chnicecavemenguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_808000D4_chnicecavemenguard.s")

void func_80800388_chnicecavemenguard(Actor* arg0)
{
    func_8080080C_chnicecavemenguard(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_808003A8_chnicecavemenguard.s")

void func_808004FC_chnicecavemenguard(void *arg0)
{
  s32 func_800DF744(s32, s32);
  s32 func_801015D0();
  f32 func_80101F24(void *);
  u32 temp_t6;
  func_801015D0();
  func_800DF744(5, 1);
  func_800DF744(6, 1);
  func_800DF744(8, 3);
  temp_t6 = (u16) (*((u16 *) (((s8 *) arg0) + 0x72)));
  temp_t6 = temp_t6 >> 0xA;
  if (temp_t6 != 4)
  {
    if (temp_t6 == 5)
    {
      func_800DF744(4, 0);
      func_800DF744(7, 0);
      return;
    }
    goto block_5;
  }
  if (func_80101F24(arg0) > 0.26f)
  {
    func_800DF744(4, 0);
    func_800DF744(7, 1);
    return;
  }
  block_5:
  func_800DF744(4, 1);

  func_800DF744(7, 0);
}

void func_808005D4_chnicecavemenguard(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor*, s32);
    if (arg1 != 0x17E8) {
        func_80102424(arg0, 1);
    }
}

void func_80800600_chnicecavemenguard(s32 arg0) 
{
}
void func_80800608_chnicecavemenguard(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    f32 func_800DC178(f32, f32);
    s32 func_80101E14(Actor *, f32);
    extern u32 D_80800990_chnicecavemenguard;
    extern u32 D_8080099C_chnicecavemenguard;
    extern f32 D_808009AC_chnicecavemenguard[];
    extern f32 D_808009BC_chnicecavemenguard[];
    extern s16 D_808009CC_chnicecavemenguard[];
    extern s16 D_808009D4_chnicecavemenguard[];
    extern s32 D_808009DC_chnicecavemenguard;
    s32 i;

    if (arg0->unk5F == 0) {
        arg0->unk5F = func_800C4350(0, arg0->position, &D_808009DC_chnicecavemenguard);
    }
    for (i = 0; i < 4; i++) {
        if (func_80101E14(arg0, D_808009AC_chnicecavemenguard[i]) != 0) {
            func_800C301C(arg0->unk5F, D_808009CC_chnicecavemenguard[i]);
            func_800C31DC(arg0->unk5F, D_808009BC_chnicecavemenguard[i] + func_800DC178(-0.02f, 0.02f));
            func_800C3058(arg0->unk5F, D_808009D4_chnicecavemenguard[i]);
            func_800C3BDC(arg0->unk5F);
            break;
        }
    }
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80800990_chnicecavemenguard, &D_8080099C_chnicecavemenguard);
}

void func_80800730_chnicecavemenguard(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_808009E8_chnicecavemenguard;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808009E8_chnicecavemenguard, 0.0f);
}

void func_8080075C_chnicecavemenguard(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    struct AudioValues { u32 values[3]; };
    extern struct AudioValues D_808009F0_chnicecavemenguard;
    extern u32 D_808009FC_chnicecavemenguard;
    struct AudioValues sp1C;

    sp1C = D_808009F0_chnicecavemenguard;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808009FC_chnicecavemenguard, sp1C.values);
}

/* extern */

void func_808007A8_chnicecavemenguard(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 temp_v0;

    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x96);
        temp_v0 = func_80100094(arg0, 1U);
        _suexpression_entrypoint_12(temp_v0, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(temp_v0, 0x320);
    }
}

void func_8080080C_chnicecavemenguard(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
