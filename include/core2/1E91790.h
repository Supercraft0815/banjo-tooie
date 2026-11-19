#ifndef __CORE2_1E91790_H__
#define __CORE2_1E91790_H__

#include "common.h"
#include "gc/newoption.h"

s32 func_800B81CC(Gfx **gfx, s32 x, s32 y, u8 ch);
void func_800B8C50(void);
void func_800B8C8C(s32 Transparency);
void func_800B8C98(s32 Font);
void func_800B8CA4(s32 shakiness);

void func_800B8CE0(s32 color);
void func_800B8CF0(f32 size);
typedef struct {
    u8 color[4];
    u8 shakiness, active, font, proportional, firstGlyph, pattern;
    u8 patternWidth, patternHeight, fontReady;
    u8 padding[3];
    s32 textureFormat;
    f32 size;
} FontDrawState;
extern FontDrawState D_801282C0;
#ifndef BT_NATIVE
extern s8 D_801282C3, D_801282C4, D_801282C5, D_801282C6, D_801282C7, D_801282C9;
extern s32 D_801282D0;
extern f32 D_801282D4;
#endif

#endif
