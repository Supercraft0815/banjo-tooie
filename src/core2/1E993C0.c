#include "common.h"

void func_800BFAD0(BtIntPtr arg0, f32 *arg1, f32 *arg2, f32 arg3, s32 arg4) {
    s32 func_800BFC34(s32);
    s32 func_800D2F20(void);
    s32 func_800D731C(s32 arg0);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF3E0(void);
    f32 func_800DF428(f32);
    void func_800DF470(s32);
    void func_800DF7E8(u8);
    void func_800DF830(s32);
    s32 model;

    model = func_800BFC34(arg4);
    func_800DF428((f32)func_800D2F20());
    func_800DF470(1);
    func_800DF830(1);
    func_800DF3E0();
    func_800DF7E8(func_800D731C(arg4));
    func_800DE448(arg1, arg2, arg3, NULL, model);
}

void func_800BFB58(BtIntPtr arg0, void *arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 func_800AF5A8(s16 *);
    BtIntPtr func_800BFC94(s32);
    s32 func_800D2F20(void);
    void func_800E249C(s32);
    void func_800E24C0(s32);
    void func_800E24F8(s32, s32, s32);
    void func_800E2588(u32);
    void func_800E2AA4(BtIntPtr, BtIntPtr, s32, s32, void *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 scale[3];
    BtIntPtr model;
    u32 mode;

    model = func_800BFC94(arg3);
    func_800EFA4C(scale, arg2, arg2, arg2);
    func_800E249C(func_800D2F20());
    func_800E24C0(1);
    func_800E24F8(0xFF - arg4 * 0x10, 0xFF - arg5 * 0x10, 0xFF - arg6 * 0x10);
    mode = (func_800AF5A8(model) & 0xB00) ? 1 : 3;
    func_800E2588(mode);
    func_800E2AA4(arg0, model, arg8, arg7, arg1, scale);
}

s32 func_800BFC34(s32 arg0)
{
    return func_800D674C(arg0);
}

u8 *func_800BFC54(s32 arg0)
{
    void *func_800D6B0C(s32);
    return func_800D6B0C(arg0);
}

void func_800BFC74(BT_NATIVE_ONLY(s32 bt_a0))
{
    BT_NATIVE_ONLY(void func_800D62E4(s32);)
    BT_IDO_ONLY(func_800D62E4();) BT_NATIVE_ONLY(func_800D62E4(bt_a0);)
}

BtIntPtr func_800BFC94(s32 arg0)
{
    return func_800D674C(arg0);
}

void func_800BFCB4(void) {
}

void func_800BFCBC(void) {
}

void func_800BFCC4(s32 arg0) {
}
