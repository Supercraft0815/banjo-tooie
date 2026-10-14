#include "common.h"

s32 func_800260B0(void *arg0) {
    if (*(void **)((s8 *)arg0 + 0x18) == NULL) {
        return 0;
    }
    return (s32) ((f32) (*(s32 *)((s8 *)arg0 + 0x24)) / (*(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x18) + 8)));
}
