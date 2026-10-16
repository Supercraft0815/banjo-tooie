#include "common.h"

OSThread *chboggykidshome_entrypoint_0(void)
{
    extern u8 D_80800468_chboggykidshome[];

    return (OSThread *) D_80800468_chboggykidshome;
}

OSThread *chboggykidshome_entrypoint_1(void)
{
    extern u8 D_808004B0_chboggykidshome[];

    return (OSThread *) D_808004B0_chboggykidshome;
}

OSThread *chboggykidshome_entrypoint_2(void)
{
    extern u8 D_808004F8_chboggykidshome[];

    return (OSThread *) D_808004F8_chboggykidshome;
}

/* extern */

void func_80800024_chboggykidshome(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    if ((func_800DA298(0x1CD) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800FFAB0(arg0);
    }
}

void func_80800068_chboggykidshome(u8 *arg0)
{
  s32 _sudeflect_entrypoint_0(u8 *, s32, s32, s32);
  s32 _suexpression_entrypoint_10(s32, s32, s32);
  s32 _suexpression_entrypoint_20(u8 *);
  u8 *new_var;
  void func_80800214_chboggykidshome();
  void func_80800300_chboggykidshome(Actor *);
  if (((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFF) >> 0xA) == 1)
  {
    if (1)
    {
      func_80800214_chboggykidshome();
    }
  }
  _sudeflect_entrypoint_0(arg0 + 4, 0x42C80000, 0x42480000, 0xA);
  if (1)
  {
    new_var = arg0;
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(arg0), *((s32 *) (((s8 *) new_var) + 0)), 0);
    func_80800300_chboggykidshome(arg0);
  }
}

void func_808000DC_chboggykidshome(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/kidshome/func_808000FC_chboggykidshome.s")

void func_80800214_chboggykidshome(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    extern s32 D_808003C0_chboggykidshome;
    extern s32 D_808003E8_chboggykidshome;
    extern s32 D_80800408_chboggykidshome;
    extern s32 D_80800570_chboggykidshome;
    extern s32 D_80800580_chboggykidshome;
    extern s32 D_80800590_chboggykidshome;
    u32 id;

    id = arg0->unk6C_9;
    if (id != 0x34E) {
        if (id != 0x3E4) {
            if (id == 0x41D) {
                _subaddiedialog_entrypoint_8((s32)arg0, arg0->position, &D_80800570_chboggykidshome, &D_808003C0_chboggykidshome, 5);
            }
        } else {
            _subaddiedialog_entrypoint_8((s32)arg0, arg0->position, &D_80800580_chboggykidshome, &D_808003E8_chboggykidshome, 4);
        }
    } else {
        _subaddiedialog_entrypoint_8((s32)arg0, arg0->position, &D_80800590_chboggykidshome, &D_80800408_chboggykidshome, 3);
    }
}

s32 func_808002C0_chboggykidshome(void *arg0) {
    u32 temp_v0;

    temp_v0 = (u32) ((*(s32 *)((s8 *)(arg0) + (0x6C))) << 0xB) >> 0x14;
    if (temp_v0 == 0x41D) {
        return 0x3B;
    }
    if (temp_v0 == 0x3E4) {
        return 0x3C;
    }
    return 0x3D;
}

void func_80800300_chboggykidshome(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C4B7C(s32);
    s32 func_800DC128(s32, s32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    s32 func_801022E4(Actor *);
    extern s16 D_808005A0_chboggykidshome[];
    extern f32 D_808005AC_chboggykidshome[];
    extern s32 D_808005BC_chboggykidshome;
    extern s32 D_808005CC_chboggykidshome;
    extern s32 D_808005E8_chboggykidshome;
    if (func_801022E4(arg0) == 0x246) {
        if (func_80101E14(arg0, 0.0f) != 0) {
            func_800C4B7C(D_808005A0_chboggykidshome[func_800DC128(0, 5)]);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808005BC_chboggykidshome);
        }
        if (func_80101E14(arg0, 0.5f) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808005CC_chboggykidshome);
        }
        if (func_80101E4C(arg0, D_808005AC_chboggykidshome) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808005E8_chboggykidshome);
        }
    }
}
