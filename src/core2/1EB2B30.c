#include "core2/1EB2B30.h"

/* extern */

void func_800D9240(s32 arg0) {
    void _glcutDll_entrypoint_10(u32 arg0);
    s32 func_800F89BC(void);
    s16 func_800F8A5C();
    s32 func_800F8E78(s32);
    s32 _glcutDll_entrypoint_12(s32);
    void func_800F9070(s32, s32);
    struct { s32 value; s32 unused; } sp18;
    s32 temp_v0;

    func_800F8E78(arg0);
    temp_v0 = func_800F89BC();
    sp18.value = temp_v0;
    _glcutDll_entrypoint_10(func_800F8A5C(temp_v0));
    func_800F9070(sp18.value, 1);
    _glcutDll_entrypoint_12(1);
}

/* extern */

void func_800D9290(void) {
    s32 func_800F5898();
    s32 func_800F6BE4(s32);
    s32 func_800F8EE4(s32);
    s32 var_s0;

    var_s0 = 0;
    if (func_800F5898() > 0) {
        do {
            if (func_800F6BE4(var_s0) != 0) {
                func_800F8EE4(var_s0);
            }
            var_s0 += 1;
        } while (var_s0 < func_800F5898());
    }
}

void func_800D92EC(void) {
}

/* extern */

void func_800D92F4(void) {
    s32 func_800F8AA4();
    s32 func_800F8DA8(s32);
    s32 func_800F8E78(s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F8AA4();
    sp1C = temp_v0;
    if (func_800F8DA8(temp_v0) != 0) {
        func_800F8E78(sp1C);
    }
}

/* extern */

void func_800D9330(u32 arg0) {
    s32 func_800F5898();
    s32 func_800F6BE4(s32);
    s32 func_800F78C8(s32, u32);
    s32 var_s0;

    var_s0 = 0;
    if (func_800F5898() > 0) {
        do {
            if (func_800F6BE4(var_s0) != 0) {
                func_800F78C8(var_s0, arg0);
            }
            var_s0 += 1;
        } while (var_s0 < func_800F5898());
    }
}
