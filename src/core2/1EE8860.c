#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "1EE8860_native.inc"
#else
#include "common.h"

void func_8010EF70(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800192FC(s32 *, s32 *);
    u8 func_800DF8D4();
    s32 func_800DF8F8(s32);
    s32 func_800EE97C(s32 *, s32 *, s32 *);
    s32 func_800EF2A0(s32 *);
    s32 func_800EF368(s32 *, f32);
    s32 func_800EFA4C(s32 *, f32, f32, f32);
    s32 func_800EFB24(s32 *, s32, s32);
    extern s32 D_80137210;
    extern s32 D_80137214;
    extern s32 D_80137220;
    extern s32 D_8013722C;
    extern u8 D_80137238;
    D_80137210 = arg0;
    D_80137238 = func_800DF8D4();
    func_800EFB24(&D_80137214, func_800DF8F8(arg0), arg3);
    func_800EF368(&D_80137214, -1.0f);
    func_800EFA4C(&D_8013722C, 0.0f, 1.0f, 0.0f);
    func_800EE97C(&D_80137220, &D_8013722C, &D_80137214);
    func_800EF2A0(&D_80137220);
    func_800EE97C(&D_8013722C, &D_80137214, &D_80137220);
    func_800EF2A0(&D_8013722C);
    if (D_80137238 == 0) {
        func_800192FC(&D_8013722C, &D_8013722C);
        func_800192FC(&D_80137220, &D_80137220);
    }
}

void func_8010F070(s32 arg0, s32 *arg1, s32 arg2)
{
  s32 func_800DF8B4(s32 *);
  s32 func_800DF8CC(s32 *);
  s32 func_800EE7F8(s32 *, s32 *);
  s32 func_800EF2A0(s32 *);
  s32 func_800F24D0(s32, s32 *, s32 *);
  void *func_80100480(s32, s32);
  s32 func_8011649C(s32 *, f32 *, s32);
  s32 func_801164E0(s32 *, s32, f32 *, f32 *, s32);
  extern s32 D_80137210;
  extern s32 D_80137220;
  extern s32 D_8013722C;
  extern u8 D_80137238;
  s32 sp6C;
  Vtx *end;
  Vtx *vtx;
  f32 *var_s1;
  f32 *var_s2;
  s32 sp50[3];
  s32 sp44[3];
  sp6C = func_800DF8CC((s32 *) D_80137210);
  sp6C = ((*arg1) * 4) + sp6C;
  vtx = (Vtx *) ((func_800DF8B4((s32 *) D_80137210) + ((*arg1) * 0x10)) + 0x18);
  end = vtx + arg2;
  *arg1 += arg2;
  var_s1 = func_80100480(2, arg2);
  var_s2 = func_80100480(1, arg2);
  if (D_80137238 != 0)
  {
    func_800F24D0(arg0, sp50, &D_80137220);
    if (D_80137210)
    {
    }
    func_800EF2A0(sp50);
    func_800F24D0(arg0, sp44, &D_8013722C);
    func_800EF2A0(sp44);
  }
  else
  {
    func_800EE7F8(sp50, &D_80137220);
    func_800EE7F8(sp44, &D_8013722C);
  }
  func_801164E0(sp50, sp6C, var_s1, var_s2, arg2);
  func_8011649C(sp44, var_s1, arg2);
  while (vtx < end)
  {
    vtx->v.tc[0] = ((*var_s2) * 992.0f) + 992.0f;
    vtx->v.tc[1] = ((*var_s1) * 992.0f) + 992.0f;
    vtx++;
    var_s1 += 3;
    var_s2++;
  }

}

void func_8010F270(void)
{
    extern s32 D_80137210;

    D_80137210 = 0;
}

#endif
