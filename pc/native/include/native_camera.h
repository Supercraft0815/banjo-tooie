#ifndef BT_NATIVE_CAMERA_H
#define BT_NATIVE_CAMERA_H
#include "core1/mlmtx.h"
#include <stddef.h>
typedef union {
    struct {
        f32 position[3],forward[3],rotation[3],planes[4][4];
        MtxF world_rotation,view_rotation;
        f32 fov,aspect,near_clip,far_clip,cotangent;
        f32 side[3],top[3],local_rays[2][3],world_rays[5][3],range_scale;
    };
    f32 values[90];
} NativeCamera;
_Static_assert(sizeof(NativeCamera)==0x168 && offsetof(NativeCamera,planes)==0x24 && offsetof(NativeCamera,world_rotation)==0x64 && offsetof(NativeCamera,fov)==0xE4 && offsetof(NativeCamera,world_rays)==0x128,"camera layout");
void func_800CA1B0(NativeCamera *);
void func_800CA218(NativeCamera *,f32);
void func_800CA2A8(NativeCamera *,f32);
void func_800CA314(NativeCamera *,NativeCamera *);
NativeCamera *func_800CA334(void);
void func_800CA364(void *);
void *func_800CA384(void *);
void func_800CA3A4(NativeCamera *,f32);
void func_800CA3F4(f32 *,f32 *,f32);
void func_800CA440(NativeCamera *);
void func_800CA510(NativeCamera *,f32);
void func_800CA558(NativeCamera *,f32);
void func_800CA5B8(NativeCamera *,f32 *);
void func_800CA5D8(NativeCamera *,s32 *);
void func_800CA5F8(NativeCamera *,f32,f32,f32);
void func_800CA628(NativeCamera *,f32 *,f32 *);
void func_800CA668(NativeCamera *,f32 *);
void func_800CA688(NativeCamera *,f32,f32,f32);
void func_800CA6C0(NativeCamera *,f32,f32);
void func_800CA6D4(NativeCamera *,f32 *,f32 *);
f32 func_800CA6E8(NativeCamera *);
void func_800CA6F0(NativeCamera *,f32);
f32 func_800CA6FC(NativeCamera *);
f32 func_800CA704(NativeCamera *,f32 *,f32 *);
void func_800CA740(NativeCamera *,f32 *);
f32 func_800CA768(NativeCamera *,f32 *);
f32 func_800CA794(NativeCamera *);
f32 func_800CA79C(NativeCamera *);
MtxF *func_800CA7A4(NativeCamera *);
MtxF *func_800CA7AC(NativeCamera *);
f32 func_800CA7B4(NativeCamera *);
void func_800CA7BC(NativeCamera *,f32 *,f32 *,f32 *,f32 *);
void func_800CA7E4(NativeCamera *,f32 *);
void func_800CA810(NativeCamera *,s32 *);
void func_800CA8B4(NativeCamera *,f32 *,f32 *);
void func_800CA8F4(NativeCamera *,f32 *,f32 *);
void func_800CA934(NativeCamera *,s16 *);
void func_800CA9D8(NativeCamera *,f32 *);
void func_800CAA00(NativeCamera *,f32 *,f32 *,f32 *);
f32 func_800CAA1C(NativeCamera *);
s32 func_800CAA24(f32 *,f32 *,f32 *);
s32 func_800CAB70(f32 *,s16 *,s16 *);
s32 func_800CACEC(f32 *,f32 *,f32);
s32 func_800CAD9C(NativeCamera *,f32,f32,f32);
int func_800CAEA4(NativeCamera *,f32,f32,f32);
f32 func_800CAF00(NativeCamera *,f32);
void func_800CAF34(NativeCamera *);
void func_800CB0E8(NativeCamera *,f32 *,s32);
/* Zero reports invalid/unrepresentable projection parameters; output is unchanged. */
u16 func_800CB124(NativeCamera *,MtxF *);
#endif
