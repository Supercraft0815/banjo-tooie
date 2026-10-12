#include "common.h"

void badialog_entrypoint_0(u8 *arg0, s32 arg1, s32 arg2)
{
  void func_8009AD20(void *arg0, s32 arg1);
  void func_8009AD2C(void *arg0, s32 arg1);
  s32 func_8009E7C8(u8 *, s32);
  u8 *func_800F53D0(u32);
  u8 *sp1C;
  int new_var;
  u8 *temp_v0;
  temp_v0 = func_800F53D0((((u16) (*((u16 *) (((s8 *) arg0) + 0x1A)))) & 0xFFFFFFFF) >> 5);
  sp1C = temp_v0;
  new_var = arg1;
  func_8009AD20(temp_v0, new_var);
  func_8009AD2C(sp1C, arg2);
  func_8009E7C8(sp1C, 0x81);
}

void badialog_entrypoint_1(s32 arg0, s32 arg1, s32 arg2) {
}
s32 badialog_entrypoint_2(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
s32 badialog_entrypoint_3(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_8008E938(void *arg0);
    u32 func_800C0534(u32, u32, f32*, Unk80132ED0*, s32, s32, s32, s32);
    void func_8009C128(void *, f32 *);
    extern s32 _badialog_entrypoint_0;
    extern s32 _badialog_entrypoint_1;
    extern s32 _badialog_entrypoint_2;
    f32 sp2C[3];

    func_8009C128((void *) arg0, sp2C);
    return func_800C0534((u32) arg1, (u32) arg2, sp2C, func_8008E938((u8 *) arg0), (s32) &_badialog_entrypoint_0, (s32) &_badialog_entrypoint_1, (s32) &_badialog_entrypoint_2, 0);
}

/* extern */

s32 badialog_entrypoint_4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 badialog_entrypoint_3(s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA3B8(s32, s32);
    if (func_800DA298(arg3) != 0) {
        return 0;
    }
    if (badialog_entrypoint_3(arg0, arg1, arg2) != 0) {
        func_800DA3B8(arg3, 1);
    }
    return func_800DA298(arg3);
}
