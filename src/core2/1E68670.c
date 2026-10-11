#include "common.h"

s32 func_8008ED80(void)
{
	return 0x1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E68670/func_8008ED88.s")

s32 func_8008EE04(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        return arg1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E68670/func_8008EE1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E68670/func_8008EE88.s")

void func_8008EEC4(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_8008E938(void *);
    s32 func_800CB840(s32, s32);
    s32 func_800CB870();
    s32 func_80109C4C(s32, s32, s32, s32 *, s32, s32, s32);
    extern s32 func_8008EE1C;
    func_800CB840(1, (*(s32 *)((s8 *)(arg0) + (0x184))));
    func_80109C4C(arg1, arg2, 2, &func_8008EE1C, (*(s32 *)((s8 *)(arg0) + (0x184))), func_8008E938(arg0), arg3);
    func_800CB870();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E68670/func_8008EF3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E68670/func_8008F4F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E68670/func_8008F568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E68670/func_8008F62C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E68670/func_8008F6B8.s")

/* extern */

void func_8008F748(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gccubesearch_entrypoint_0(s32, s32);
    s32 _gspropctrl_entrypoint_11(s32, s32 *);
    s32 func_800A3514(s32, s32 *);
    s32 sp1C[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_0(arg1, arg2), sp1C);
    func_800A3514(arg0, sp1C);
}

/* extern */

void func_8008F788(s32 arg0, s32 arg1) {
    s32 func_800D1844(s32);
    s32 func_800D1B34(s32);
    func_800D1844(func_800D1B34(arg1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E68670/func_8008F7B4.s")

/* extern */

void func_8008F828(s32 arg0, s32 arg1) {
    s32 func_800D1A04(s32);
    s32 func_800D1B34(s32);
    func_800D1A04(func_800D1B34(arg1));
}

/* extern */

void func_8008F854(s32 arg0, s32 arg1) {
    s32 func_800D1824(s32);
    s32 func_800D1B34(s32);
    func_800D1824(func_800D1B34(arg1));
}

void func_8008F880(Unk80132ED0 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    Actor* func_80106790(Unk80132ED0 *);
    func_800EE7F8(arg1, (f32 *)((u8 *)func_80106790(arg0) + 4));
}
