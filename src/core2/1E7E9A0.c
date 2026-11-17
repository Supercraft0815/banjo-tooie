#include "core2/1E7E9A0.h"

void func_800A50B0(s32 arg0)
{
    void func_8010F9C0(BtIntPtr, s32);
    func_8010F9C0(func_8008FFE8(),arg0);
}

void func_800A50DC()
{
    func_8010FAE4(func_8008FFE8());
}

void func_800A5104(BT_NATIVE_ONLY(s32 bt_a0) BT_PASS2(, s32 bt_a1))
{
    func_800A92A8(BT_NATIVE_ONLY(bt_a0) BT_PASS2(, bt_a1));
}

void func_800A5124(BT_NATIVE_ONLY(s32 bt_a0))
{
    func_800A9318(BT_NATIVE_ONLY(bt_a0));
}

void func_800A5144()
{
    func_8010FD88(func_8008FFE8());
}    typedef struct { f32 unk0; } Obj1E7E9A0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_800A516C(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 func_800136E4(f32);
    void func_800F18FC(f32 *arg0, f32 *arg1, f32 *arg2);
    func_800F18FC(arg1, arg2, arg0);
    (((Obj1E7E9A0_arg0 *)arg0)->unk0) = func_800136E4(-(((Obj1E7E9A0_arg0 *)arg0)->unk0));
    arg0[2] = 0.0f;
}
