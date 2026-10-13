#include "common.h"

s16 *func_800D1FC0(s32 arg0) {
    s32 func_800D395C(void);
    extern s32 D_8012B260;
    extern s32 D_8012B290;
    s16 *result;

    arg0 -= 0x80;
    if (func_800D395C() != 0) {
        result = (s16 *) &D_8012B290 + arg0;
    } else {
        result = (s16 *) &D_8012B260 + arg0;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAB8B0/func_800D2014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAB8B0/func_800D2054.s")

/* extern */

s16 func_800D211C(void) {
    s16 *func_800D1FC0();
    return *func_800D1FC0();
}

s32 func_800D2140() 
{
    return 0x2E;
}

void func_800D2148(u8 *arg0, u32 arg1) {
    void rare_memcpy(void* dst, void* src, int length);
    extern s32 D_8012B260;
    u32 var_v1;

    var_v1 = arg1 >> 1;
    if ((s32) var_v1 >= 0x18) {
        var_v1 = 0x17;
    }
    rare_memcpy(&D_8012B260, arg0, var_v1 * 2);
}

void func_800D2188(u8 *arg0) {
    void rare_memcpy(void* dst, void* src, int length);
    extern s32 D_8012B260;
    rare_memcpy(arg0, &D_8012B260, 0x2E);
}

void func_800D21B0(s32 *arg0, s32 **arg1) {
    extern s32 D_8012B290;
    *arg0 = 0x2E;
    *arg1 = &D_8012B290;
}
