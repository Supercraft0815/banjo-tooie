#ifndef BT_NATIVE_REFLECTION_H
#define BT_NATIVE_REFLECTION_H
#include "native_camera_frame.h"
enum {NATIVE_REFLECTION_PACKETS=3000};
typedef struct {
    Gfx *buffers[2],*saved_gfx,*saved_end;
    Mtx *saved_mtx;
    NativeGraphicsContext *frame;
    u8 index,active,bounds_valid,bounds_cached,cull_enabled,alpha;
    s16 model;
    MtxF matrix;Mtx fixed;
    f32 point[3],normal[3],minimum[3],maximum[3];
    Gfx restore[2][6];
} NativeReflection;
extern NativeReflection native_reflection;
int native_reflection_load_map(s32);
void func_800BC690(void);
void func_800BC8A0(void);
/* Begin/end return zero on invalid state/capacity; discard a failed batch.
 * Keep the buffers alive until graphics using this batch have finished. */
int func_800BC8F8(NativeGraphicsContext *);
int func_800BC948(NativeGraphicsContext *);
void func_800BCC28(f32 *,f32 *);
int func_800BCC58(void);
u32 func_800BCC84(void);
void func_800BCC90(Gfx **);
void func_800B5680(s32);
s32 func_800B5698(s16 *);
extern Gfx D_80123418[2],D_80123428[2];
extern u32 D_8012D5E0;
/* Register both static lists before using the original packet helpers. */
void func_800E7FF8(Gfx **,u32);
void func_800E8078(Gfx **);
#endif
