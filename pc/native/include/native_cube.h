#ifndef BT_NATIVE_CUBE_H
#define BT_NATIVE_CUBE_H
#include "native_gsfile.h"
#include "native_map_props.h"
#include "native_collision.h"
typedef NativeCollisionLineQuery NativeCubeLineQuery;
typedef NativeCollisionSweepQuery NativeCubeSweepQuery;
typedef NativeCollisionSphereQuery NativeCubeSphereQuery;
void gccubeDll_entrypoint_0(NativeWorldGrid *);
void gccubeDll_entrypoint_1(NativeWorldGrid *);
void gccubeDll_entrypoint_2(NativeWorldGrid *);
void gccubeDll_entrypoint_3(NativeWorldGrid *, void *);
void gccubeDll_entrypoint_4(NativeWorldGrid *, void *);
void gccubeDll_entrypoint_5(NativeWorldGrid *);
void gccubeDll_entrypoint_6(NativeWorldGrid *);
u32 gccubeDll_entrypoint_7(void);
s32 func_808000B8_gccubeDll(GsFile *, s32);
s32 func_80800230_gccubeDll(GsFile *, s32);
void func_808003A0_gccubeDll(GsFile *, s32);
void func_80800868_gccubeDll(NativeWorldGrid *, GsFile *);
#endif
