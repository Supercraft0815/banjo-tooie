#ifndef __CORE1_1E2D890_H__
#define __CORE1_1E2D890_H__

#include "common.h"

//Is Pause Button Pressed
s32 func_80015FA0(s32);
void func_80015E80(s32 controller, void *buttons);
void func_80015F28(s32 controller, void *buttons);
s32 func_80015F84(s32 controller);
void func_80015FFC(s32 controller, void *buttons);
void func_80016068(u32, f32*);
u8 func_80016800(s32 controller);
void func_80016864();
//Get Number of Frames button held for
s32 func_80016B30(s32, s32);

#endif
