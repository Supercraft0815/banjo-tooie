#include "core2/1EB2840.h"

extern u32 D_8012C764;
extern f32 D_8012C760;

void func_800D8F50(f32 arg0) {
    extern f32 D_80125D10;
    if (arg0 < D_80125D10) {
        D_8012C760 = arg0;
        return;
    }
    D_8012C760 = D_80125D10;
}

void func_800D8F84(void) {
    extern f32 D_80125D14;
    D_8012C760 = D_80125D14;
    D_8012C764 = 0;
}

void func_800D8FA0(s32 arg0) {
    extern f32 D_80125D18;

    D_8012C764 = func_800F0D90(arg0, 1, 0xF);
    func_800D8F50((f32) (s32) D_8012C764 * D_80125D18);
}

u32 func_800D8FEC()
{
	return D_8012C764;
}
//Get Gamespeed
f32 func_800D8FF8()
{
	return D_8012C760;
}

f32 func_800D9004(void) {
    extern f32 D_80125D1C;
    return (s32)D_8012C764 * D_80125D1C;
}

f32 func_800D902C(void) {
    return func_800D8FF8() * 30.0f;
}

s32 func_800D9058(f32 arg0) {
    return (s32) (arg0 * 30.0f);
}

/* extern */

u8 func_800D9078(f32 *arg0) {
    u8 func_800F1574(f32 *, f32);
    return func_800F1574(arg0, func_800D8FF8());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2840/func_800D90A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2840/func_800D90F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2840/func_800D9154.s")

f32 func_800D91B8(f32 *arg0) {
    *arg0 += func_800D8FF8();
    return *arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2840/func_800D91EC.s")
