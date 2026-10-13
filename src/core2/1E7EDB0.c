#include "common.h"

/* extern */

void func_800A54C0(s32 arg0) {
    s32 func_8011001C(s32 *);
    void _ncfixposrot_entrypoint_2(s32, s32);
    s32 temp_v0;

    temp_v0 = func_8011001C((s32 *)func_8008FFE8());
    if (temp_v0 != 0) {
        _ncfixposrot_entrypoint_2(temp_v0, arg0);
    }
}

void func_800A54F8(s32 arg0)
{
    _ncfixposrot_entrypoint_8(func_8008FFE8(),arg0);
}

/* extern */

void func_800A5524(void) {
    void _ncfixposrot_entrypoint_9(s32);
    _ncfixposrot_entrypoint_9(func_8008FFE8());
}
