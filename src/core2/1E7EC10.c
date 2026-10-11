#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7EC10/func_800A5320.s")

void func_800A5430(f32 rotation[3], f32 position[3], f32 arg2, f32 dest[3]) {
    void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    f32 sp24[3];
    func_800EF4E4(sp24, rotation[0], rotation[1], 0.0f, 0.0f, -arg2);
    func_800EE780(dest, sp24, position);
}

/* extern */

void func_800A5490(void) {
    s32 func_8008FFE8();
    s32 func_8010FFD8(s32);
    func_8010FFD8(func_8008FFE8());
}
