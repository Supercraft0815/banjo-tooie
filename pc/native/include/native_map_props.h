#ifndef BT_NATIVE_MAP_PROPS_H
#define BT_NATIVE_MAP_PROPS_H
#include "native_world_grid.h"
void gspropsDll_entrypoint_0(NativeWorldCell *, Prop **, s32 *);
void gspropsDll_entrypoint_1(Prop **, s32);
void gspropsDll_entrypoint_2(NativeWorldCell *, s32);
s32 func_808004E0_gspropsDll(Prop *);
s32 func_80800524_gspropsDll(NativeWorldCell *);
void gspropsDll_entrypoint_3(Prop *);
void gspropsDll_entrypoint_4(NativeMarkerProp *);
void *gspropmarker_entrypoint_0(NativeWorldCell *, s32);
s32 gspropmarker_entrypoint_1(NativeWorldCell *, s32 *, Prop **, s32);
s32 gspropmarker_entrypoint_2(NativeWorldCell *, s32, f32 (*)[3], s32);
f32 gspropmarker_entrypoint_3(void *);
#endif
