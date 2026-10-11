#include "common.h"

void func_800CB840(s32 arg0, s32 arg1) {
    extern s32 D_8012AE70;
    (*(s16 *)((s8 *)(&D_8012AE70) + (0))) = arg0;
    (*(s32 *)((s8 *)(&D_8012AE70) + (4))) = arg1;
}

s16 func_800CB854(s32 *arg0) {
    extern s32 D_8012AE70;
    extern s32 D_8012AE74;
    if (arg0 != NULL) {
        *arg0 = D_8012AE74;
    }
    return *(s16 *)&D_8012AE70;
}

void func_800CB870(void) {
    extern s32 D_8012AE70;
    (*(s16 *)((s8 *)(&D_8012AE70) + (0))) = 0;
    (*(s32 *)((s8 *)(&D_8012AE70) + (4))) = 0;
}
