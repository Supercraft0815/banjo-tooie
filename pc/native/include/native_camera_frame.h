#ifndef BT_NATIVE_CAMERA_FRAME_H
#define BT_NATIVE_CAMERA_FRAME_H
#include "native_camera.h"
#include "native_graphics_memory.h"
typedef struct NativeGraphicsContext {
    Gfx *gfx;
    Mtx *mtx;
    Gfx *gfx_end;
    Mtx *mtx_end;
    NativeGraphicsMemory *memory;
} NativeGraphicsContext;
/* Projection builders return zero without emitting on invalid input/capacity/mapping. */
s32 func_800E36D0(s32 *arg0, s32 *arg1, f32 *arg2, f32 *arg3);
void func_800E37E8(s32 *arg0, s32 *arg1, s32 arg2);
void func_800E3900(f32 arg0);
f32 func_800E3928(f32 *arg0, f32 *arg1);
void func_800E3958(f32 *arg0);
void func_800E3980(f32 *arg0);
void func_800E39A8(f32 *arg0, f32 *arg1);
void func_800E39D8(f32 *arg0, f32 *arg1);
void func_800E3A08(s32 *arg0);
void func_800E3A30(s16 *arg0);
void func_800E3A58(f32 *arg0);
f32 func_800E3A80(void);
s32 func_800E3AA4(f32 x);
void func_800E3B50(f32 *arg0, f32 *arg1, f32 *arg2);
void func_800E3B88(void);
void func_800E3BAC(f32 *arg0);
void func_800E3BD4(s32 *arg0);
void func_800E3BFC(f32 arg0, f32 arg1, f32 arg2);
void func_800E3C30(f32 *arg0);
void func_800E3C58(f32 arg0, f32 arg1, f32 arg2);
void func_800E3C8C(f32 arg0, f32 arg1);
void func_800E3CB8(f32 *arg0, f32 *arg1);
void func_800E3CE8(void);
s32 func_800E3D0C(f32 *arg0, f32 *arg1);
s32 func_800E3DC0(s16 *arg0, s16 *arg1);
s32 func_800E3E8C(f32 *arg0, f32 arg1);
s32 func_800E3EFC(f32 arg0, f32 arg1, f32 arg2);
s32 func_800E3F8C(f32 arg0, f32 arg1, f32 arg2);
MtxF *func_800E401C(void);
MtxF *func_800E4040(void);
f32 func_800E4064(void);
f32 func_800E4088(void);
f32 func_800E40AC(s32 arg0, f32 arg1);
f32 func_800E40DC(f32 arg0, f32 arg1, f32 *arg2, f32 *arg3);
int func_800E4140(f32 *arg0, f32 *arg1);
void func_800E4190(f32 *arg0, f32 *arg1, s32* arg2);
void func_800E41CC(void);
void func_800E4208(void);
void func_800E4244(f32 *arg0, f32 arg1);
void func_800E4278(void);
void func_800E4290(void);
NativeCamera *func_800E42A8(void);
void func_800E42B4(NativeCamera *arg0);
f32 func_800E42C0(void);
void func_800E42E4(s32 arg0);
int func_800E42F0(NativeGraphicsContext *frame, s32 use_widescreen);
void func_800E443C(MtxF* base_matrix, f32* translation, f32 scale);
int func_800E44FC(NativeGraphicsContext *frame);
void func_800E4628(void);
void func_800E4640(Gfx** gfx);
void func_800E46A4(f32 out[4], f32 in[4]);
u16 func_800E46D4(void);
void func_800E46E0(Gfx** gfx, void* addr);
extern MtxF D_8012D510;
extern u16 D_8012D550;
#endif
