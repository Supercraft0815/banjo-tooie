#ifndef BT_NATIVE_WORLD_GRID_H
#define BT_NATIVE_WORLD_GRID_H
#include "native_world_props.h"
typedef struct {
    NativeWorldCell *cells;
    s32 lower[3], upper[3];
    s32 row_stride, plane_stride, count;
    s32 dimensions[3];
    NativeWorldCell fallback;
    s16 cell_size;
    u8 fallback_models, padding;
    f32 scale;
    u8 *model_counts;
} NativeWorldGrid;
extern NativeWorldGrid native_world_grid;
void func_800BD570(void);
void func_800BD594(s32);
void func_800BD5DC(void);
void func_800BD600(void);
void func_800BD64C(s32 *,f32 *);
void func_800BD708(s32 *,s32 *,f32 *,f32 *,f32);
void func_800BD860(NativeWorldCell *,s32 *);
s32 func_800BD948(void *);
s32 func_800BD97C(s32 *);
NativeWorldCell *func_800BDAD4(s32 *);
NativeWorldCell *func_800BDB9C(s32);
NativeWorldCell *func_800BDBC4(s32 *);
NativeWorldCell *func_800BDBEC(f32 *);
NativeWorldCell *func_800BDC44(void);
s32 func_800BDC50(void);
s32 func_800BDC5C(void);
void func_800BDC68(void *);
void func_800BDC90(void *);
void func_800BDCB8(void);
void func_800BDCDC(void);
void func_800BDD00(void);
NativeWorldCell **func_800BDD24(s32 *);
s32 func_800BE09C(NativeWorldCell **,s32 *);
NativeWorldCell **func_800BE3F8(f32 *);
NativeWorldCell **func_800BE444(f32 *);
s32 func_800BE4C4(void);
void func_800BE52C(NativeWorldCell **,NativeWorldCell **);
void func_800BE554(s32 *,s32 *);
void func_800BE58C(s32 *,s32 *);
u8 *func_800BE5C4(void *);
#endif
