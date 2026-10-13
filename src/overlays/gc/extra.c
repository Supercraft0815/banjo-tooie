#include "common.h"

/* extern */

 s32 gcextra_entrypoint_0(void) {
    s32 func_800DA564(s32, s32);
    return func_800DA564(0x4EA, 3);
}

s32 gcextra_entrypoint_1() 
{
    return 0x5;
}

void gcextra_entrypoint_2(s32 arg0) { s32 bound, value, other; value = gcextra_entrypoint_0(); bound = value + arg0; other = gcextra_entrypoint_1(); if (other < bound) bound = other; func_800DA7A8(0x4EA, bound, 3); func_800D517C(); }
