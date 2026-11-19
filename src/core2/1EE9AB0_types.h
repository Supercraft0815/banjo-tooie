#ifndef CORE2_1EE9AB0_TYPES_H
#define CORE2_1EE9AB0_TYPES_H

#include "core2/1EE9AB0.h"

typedef struct {
    u8 pad0[0x34];
    union { f32 * unk34; void * unk34_voidp; };
    u8 pad38[0x2C];
    s32 * unk64;
    s32 unk68;
    s32 unk6C;
} Obj1EE9AB0_arg0;

#endif
