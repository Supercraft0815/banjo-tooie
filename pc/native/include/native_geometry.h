#ifndef BT_NATIVE_GEOMETRY_H
#define BT_NATIVE_GEOMETRY_H
#include "types.h"
#include "native_render.h"
#include "native_graphics_memory.h"
/* Validate the complete forward command graph before converting any scalar. */
int native_geometry_decode(u8 *,u32,u32,s32);
typedef void (*NativeGeometryVertexCallback)(f32 *,s32 *,s32);
typedef struct {
    Gfx *gfx,*gfx_end;
    Mtx *mtx,*mtx_end;
    NativeGraphicsMemory *memory;
    /* Original camera prefix: position[3], forward[3], rotation[3], four planes. */
    f32 *camera;
    MtxF base;
    MtxF *reflection;
    Gfx *mode_list;u32 mode_count;
    NativeGeometryVertexCallback vertex_callback;
    u32 remaining_commands;
} NativeGeometryContext;
/* Input is host-endian geometry validated by native_model_decode. Prepare the
 * original per-model vertex callbacks before drawing. Failure leaves partial
 * output/vertex edits; do not submit that batch. The CPU matrix stack is restored. */
int native_geometry_execute(NativeGeometryContext *,const u8 *,u32);
#endif
