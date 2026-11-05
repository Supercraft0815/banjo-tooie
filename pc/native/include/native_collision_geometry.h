#ifndef BT_NATIVE_COLLISION_GEOMETRY_H
#define BT_NATIVE_COLLISION_GEOMETRY_H
#include "native_model.h"
/* Queries consume collision and vertex scalars decoded by native_model_decode. */
typedef struct {u16 vertices[3],padding;u32 flags;} NativeCollisionTriangle;
typedef struct {u16 start,count;} NativeCollisionCell;
typedef struct {
    s16 minimum[3],maximum[3];u16 y_stride,z_stride,cell_count;s16 scale;
    u16 triangle_count,padding;NativeCollisionCell cells[];
} NativeCollisionMesh;
_Static_assert(sizeof(NativeCollisionTriangle)==12 && offsetof(NativeCollisionMesh,cells)==24,"collision resource layout");
void func_800AA2A0(s16 *,s32 *,f32 *);
void func_800AA3B4(void *,void *);
void func_800AA4D4(void *,f32 *,f32 *,void *,void *);
void func_800AA7FC(void *,s32 *,s32 *,void *,void *);
void func_800AAAE0(u8 *),func_800AAD28(f32 *);
s32 func_800AAD80(u16 *);
u32 func_800AADE4(u16 *);
s32 func_800AADEC(f32 *,f32 *,f32 *,f32),func_800AAEF4(f32 *,f32,f32 *,f32 *);
void func_800AAFEC(f32 *,f32 *,s32 *,s32 *,f32 *);
void *func_800AB0BC(void *,void *,f32 *,f32 *,f32 *,u32);
void *func_800AB868(void *,void *,f32 *,f32 *,f32,f32 *,f32 *,f32 *,s32);
void func_800AB980(void),func_800AB9D0(void),func_800ABA20(void),func_800ABA9C(void);
void func_800ABB34(void *,void **),func_800ABC0C(u8 **,u8 **);
void func_800ABC58(f32 *,f32 *,f32,f32 *,f32 *);
s32 func_800ABCE0(void *,void *,f32 *,f32 *,f32 *,f32,u32,void **);
void *func_800AC100(void *,f32 *,f32,f32 *);
void *func_800AC638(void *,void *,f32 *,f32 *,f32,f32 *,s32,u32);
void *func_800AC848(void *,void *,f32 *,f32 *,f32,f32 *,f32 *,f32,f32 *,s32,s32);
void *func_800AC978(void *,void *,f32 *,f32,f32 *,u32);
void *func_800AD1AC(void *,void *,f32 *,f32 *,f32,f32 *,f32,f32 *,u32);
s32 func_800AD2C8(void *,void *,f32 *,f32 *,f32 *,s16 (**)[3],s32,f32);
s32 func_800AD894(void *,void *,f32 *,f32 *,f32 *,f32 *,f32);
#endif
