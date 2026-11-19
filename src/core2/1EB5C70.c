#include "common.h"
BT_NATIVE_ONLY(void func_80020C08(s32, s16, s32);)

typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s16 unk10; } Obj1EB5C70_D_8012C800; /* offsets.py genstruct: fields from raw offsets on &D_8012C800; rename once understood */ void func_800DC380(void) {
    s32 func_80012EDC(s32 *);
    void func_8001EB10(s32 *arg0);
    extern s32 D_8012C800;
    (((Obj1EB5C70_D_8012C800 *)&D_8012C800)->unk0) = 0x32;
    (((Obj1EB5C70_D_8012C800 *)&D_8012C800)->unk4) = 0x100;
    (((Obj1EB5C70_D_8012C800 *)&D_8012C800)->unk10) = 0x40;
    (((Obj1EB5C70_D_8012C800 *)&D_8012C800)->unk8) = 0x18;
    (((Obj1EB5C70_D_8012C800 *)&D_8012C800)->unkC) = func_80012EDC(&D_8012C800);
    func_8001EB10(&D_8012C800);
}

/* extern */

void func_800DC3D4(s32 arg0, f32 arg1, u16 arg2, u8 arg3, u8 arg4, BtIntPtr arg5) {
    struct SfxState *func_80020790(s16 arg0, u16 arg1, u8 arg2, f32 arg3, u8 arg4, u8 arg5, BtIntPtr arg6);
    func_80020790((s16) (arg0 + 1), arg2, arg3, arg1, arg4, 0, arg5);
}

void func_800DC42C(s32 arg0, volatile s32 arg1) { func_80020C08(arg0, 0x10, arg1); }

void func_800DC454(s32 arg0, u16 arg1) {
    s32 var_a2;
    var_a2 = arg1;
    if (var_a2 >= 0x8000) var_a2 = 0x7FFF;
    func_80020C08(arg0, 8, var_a2);
}

void func_800DC48C(s32 arg0,s32 arg1)
{
    func_80020C08(arg0,0x100,arg1);
}

void func_800DC4B0(s32 arg0,s32 arg1)
{
    func_80020C08(arg0,0x4,arg1);
}

void func_800DC4D4(s32 arg0) { if (arg0 != 0) { if (func_80020760() != 0) func_80020A60(arg0); } }

void func_800DC508(BT_NATIVE_ONLY(s32 bt_a0))
{
    func_80020760(BT_NATIVE_ONLY(bt_a0));
}

void func_800DC528(void) {
    func_800E9054(NULL);
}

/* extern */

s32 func_800DC548(BT_PARAM_OR_VOID(s32 bt_a0) BT_PASS2(, s32 bt_a1)) { u8 *func_800E9320(); if ((*(s32 *)((s8 *)(func_800E9320(BT_PASS2(bt_a0, bt_a1))) + 4)) == -1) { return 1; } else { return 0; } }

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012C800 BT_DATA(4, bss_core2bss2, 0x10);
#endif
