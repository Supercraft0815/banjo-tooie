#ifndef __GL_SPLINEFIND_H__
#define __GL_SPLINEFIND_H__

#include "common.h"

#ifdef BT_NATIVE
s32 _glsplinefind_entrypoint_0(s32, f32*);
#else
s16 _glsplinefind_entrypoint_0(u32, f32*);
#endif
s32 _glsplinefind_entrypoint_3(f32*);

#endif
