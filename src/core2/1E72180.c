#include "common.h"

s32 func_80098890() 
{
    return 0x1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_80098898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_800989E4.s")

void func_80098B4C(void *arg0, s32 arg1) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xBC)))) + (0x19))) = (s8) (arg1 == 0);
}

/* extern */

void func_80098B5C(void *arg0, s32 arg1, s32 arg2) {
    s32 func_800EE7F8(s32, s32);
    func_800EE7F8(arg1, (*(s32 *)((s8 *)(arg0) + (0xBC))) + 0xC);
    func_800EE7F8(arg2, (*(s32 *)((s8 *)(arg0) + (0xBC))));
}

s32 func_80098BA0() 
{
    return 0xC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_80098BA8.s")

/* extern */

void func_80098BE0(void *arg0) {
    s32 _baeggcursor_entrypoint_1(void *);
    s32 _bsfirstp_entrypoint_37(void *);
    s32 func_8009AD78(void *, s32);
    s32 func_800A9420(s32);
    if (func_800A9420((*(s32 *)((s8 *)(arg0) + (0x184)))) != 0) {
        if (func_8009AD78(arg0, 8) != 0) {
            _baeggcursor_entrypoint_1(arg0);
        }
        if (func_8009AD78(arg0, 0xB) != 0) {
            _bsfirstp_entrypoint_37(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_80098C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72180/func_80098E64.s")

void func_8009919C(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB8)))) + (0))) = arg1;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB8)))) + (4))) = arg2;
}

void func_800991B0(void *arg0)
{
  s32 _bacough_entrypoint_5(void *);
  s32 _badeathmatch_entrypoint_3(void *);
  s32 _baduo_entrypoint_13(void *);
  s32 _badust_entrypoint_13(void *);
  s32 _baeggcursor_entrypoint_11(void *);
  s32 _bafpctrl_entrypoint_15(void *);
  s32 _bahold_entrypoint_3(void *);
  s32 _bainvisible_entrypoint_6(void *);
  s32 _bamum_entrypoint_3(void *);
  s32 _bashoes_entrypoint_13(void *);
  s32 _basquash_entrypoint_4(void *);
  s32 _batranslate_entrypoint_4(void *);
  s32 baanim_update(void *);
  s32 bainput_update(void *);
  s32 bakey_update(void *);
  s32 baroll_update(void *);
  s32 bastatetimerlist_update(void *);
  s32 bastick_update(void *);
  s32 func_8008DAA8(void *);
  s32 func_8008E124(void *);
  s32 func_8008E454(void *);
  s32 func_8008E6F0(void *);
  s32 func_80090A4C(void *);
  s32 func_80091110(void *);
  s32 func_80091E80(void *, s32);
  void func_80091F30(void *);
  s32 func_80092AB0(void *);
  s32 func_80093448(void *);
  s32 func_80094864(void *);
  s32 func_800951F4(void *);
  s32 func_8009561C(void *);
  s32 func_80095C94(void *);
  s32 func_800987CC(void *);
  s32 func_800989E4(void *);
  s32 func_80099970(void *);
  s32 func_8009AD78(void *, s32);
  s32 func_8009B590(void *);
  s32 func_8009BDE4(void *);
  s32 func_8009BF34(void *);
  s32 func_8009C08C(void *);
  s32 func_8009C25C(void *);
  s32 func_8009CF04(void *);
  s32 func_8009D088(void *);
  s32 func_8009E83C(void *);
  s32 func_800A0DDC(void *);
  s32 func_800A10A0(void *);
  s32 func_800A18E8(void *);
  s32 func_800A2060(void *);
  s32 func_800A2534(void *);
  s32 func_800A3A80(void *);
  s32 func_800A4B08(void *);
  s32 func_800D3E40(s32);
  s32 func_800DA298(s32);
  s32 func_800EA068(s32);
  s32 sp24;
  s32 sp20;
  void *temp_v0;
  void (*temp_v1)(s32);
  sp24 = func_800EA068(8) == 0;
  sp20 = func_800DA298(0x6B5);
  if (func_80091E80(arg0, 0x20) != 0)
  {
    func_80092AB0(arg0);
    func_80099970(arg0);
    func_8009CF04(arg0);
    bastatetimerlist_update(arg0);
    func_800A0DDC(arg0);
    bakey_update(arg0);
    bastick_update(arg0);
    bainput_update(arg0);
    if (func_8009AD78(arg0, 2) != 0)
    {
      _baduo_entrypoint_13(arg0);
    }
    func_8009E83C(arg0);
    if ((func_80091E80(arg0, 2) != 0) && (func_8008E454(arg0) != 0))
    {
      func_8009B590(arg0);
    }
    if (func_8009AD78(arg0, 6) != 0)
    {
      _batranslate_entrypoint_4(arg0);
    }
    func_8009C25C(arg0);
    if (sp24 != 0)
    {
      func_8009561C(arg0);
    }
    func_80095C94(arg0);
    if (func_80091E80(arg0, 2) != 0)
    {
      func_8009BF34(arg0);
      baroll_update(arg0);
      func_8009D088(arg0);
    }
    if (sp20 != 0)
    {
      func_80091110(arg0);
    }
    if (func_80091E80(arg0, 0x10) != 0)
    {
      baanim_update(arg0);
    }
    func_800A2060(arg0);
    if (sp24 != 0)
    {
      func_800987CC(arg0);
    }
    if (func_8009AD78(arg0, 4) != 0)
    {
      func_80090A4C(arg0);
    }
    if (sp24 != 0)
    {
      func_800951F4(arg0);
    }
    if (func_8009AD78(arg0, 3))
    {
      _badust_entrypoint_13(arg0);
    }
    func_8009C08C(arg0);
    func_8008E6F0(arg0);
    if (func_8009AD78(arg0, 0xE) != 0)
    {
      _bahold_entrypoint_3(arg0);
    }
    func_800A10A0(arg0);
    func_8009BDE4(arg0);
    func_800A3A80(arg0);
    func_800A4B08(arg0);
    if ((*((s32 *) (((s8 *) arg0) + 0x158))) == 0)
    {
      func_80094864(arg0);
    }
    else
    {
      _badeathmatch_entrypoint_3(arg0);
    }
    if (func_8009AD78(arg0, 9) != 0)
    {
      _bacough_entrypoint_5(arg0);
    }
    if (func_8009AD78(arg0, 8) != 0)
    {
      _baeggcursor_entrypoint_11(arg0);
    }
    if (func_8009AD78(arg0, 0xC) != 0)
    {
      _bainvisible_entrypoint_6(arg0);
    }
    if (func_8009AD78(arg0, 5) != 0)
    {
      _bamum_entrypoint_3(arg0);
    }
    if (func_8009AD78(arg0, 7) != 0)
    {
      _bafpctrl_entrypoint_15(arg0);
    }
    if (func_8009AD78(arg0, 0xA) != 0)
    {
      _basquash_entrypoint_4(arg0);
    }
    if (func_8009AD78(arg0, 0xD) != 0)
    {
      _bashoes_entrypoint_13(arg0);
    }
    func_80093448(arg0);
    func_800A2534(arg0);
    if (((func_800D3E40(4) != 0) && (func_8008DAA8(arg0) != 0)) && (func_8008E124(arg0) == 0))
    {
      func_800A18E8(arg0);
    }
    func_80091F30(arg0);
    temp_v0 = *((void **) (((s8 *) arg0) + 0xB8));
    temp_v1 = *((void (**)(s32)) (((s8 *) temp_v0) + 0));
    if (temp_v1 != NULL)
    {
      temp_v1(*((s32 *) (((s8 *) temp_v0) + 4)));
      *((void (**)(s32)) (((s8 *) (*((void **) (((s8 *) arg0) + 0xB8)))) + 0)) = NULL;
    }
    func_800989E4(arg0);
  }
}

/* extern */

void func_80099544(void *arg0) {
    s32 baanim_defrag();
    s32 bakey_defrag(void *);
    s32 func_800934C4(void *);
    s32 func_80096728(void *);
    s32 func_800A266C(void *);
    s32 func_800A300C(void *);
    if ((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xB8)))) + (8))) != 0) {
        baanim_defrag();
        func_800934C4(arg0);
        func_80096728(arg0);
        func_800A300C(arg0);
        bakey_defrag(arg0);
        func_800A266C(arg0);
    }
}
