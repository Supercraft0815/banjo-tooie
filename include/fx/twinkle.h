#ifndef __FX_TWINKLE_H__
#define __FX_TWINKLE_H__

#include "common.h"
#include "overlays/ba/assets.h"

#ifdef BT_NATIVE
void _fxtwinkle_entrypoint_0(s32 arg0);
#else
void _fxtwinkle_entrypoint_0(f32*);
#endif
void _fxtwinkle_entrypoint_1(f32*, AssetId);
void fxtwinkle_entrypoint_1(f32*, AssetId);

#endif

