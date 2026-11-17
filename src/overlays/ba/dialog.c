#include "common.h"

typedef struct { u8 pad0[0x1A]; u16 unk1A; } Objdialog_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void badialog_entrypoint_0(u8 *arg0, s32 arg1, s32 arg2)
{
  void func_8009AD20(void *arg0, s32 arg1);
  void func_8009AD2C(void *arg0, s32 arg1);
  s32 func_8009E7C8(u8 *, s32);
  u8 *func_800F53D0(BtUIntPtr);
  u8 *sp1C;
  int new_var;
  u8 *temp_v0;
  temp_v0 = func_800F53D0((((u16) (((Objdialog_arg0 *)arg0)->unk1A)) & 0xFFFFFFFF) >> 5);
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
s32 badialog_entrypoint_3(BtIntPtr arg0, s32 arg1, s32 arg2) {
    BtIntPtr func_8008E938(void *arg0);
    u32 func_800C0534(u32, u32, f32*, Unk80132ED0*, BtIntPtr, BtIntPtr, BtIntPtr, s32);
    void func_8009C128(void *, f32 *);
#ifndef BT_NATIVE
    extern s32 _badialog_entrypoint_0;
#endif
#ifndef BT_NATIVE
    extern s32 _badialog_entrypoint_1;
#endif
#ifndef BT_NATIVE
    extern s32 _badialog_entrypoint_2;
#endif
    f32 sp2C[3];

    func_8009C128((void *) arg0, sp2C);
    return func_800C0534((u32) arg1, (u32) arg2, sp2C, func_8008E938((u8 *) arg0), (BtIntPtr) &_badialog_entrypoint_0, (BtIntPtr) &_badialog_entrypoint_1, (BtIntPtr) &_badialog_entrypoint_2, 0);
}

/* extern */

s32 badialog_entrypoint_4(BtIntPtr arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 badialog_entrypoint_3(BtIntPtr, s32, s32);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32 index, s32 set);
    if (func_800DA298(arg3) != 0) {
        return 0;
    }
    if (badialog_entrypoint_3(arg0, arg1, arg2) != 0) {
        func_800DA3B8(arg3, 1);
    }
    return func_800DA298(arg3);
}
