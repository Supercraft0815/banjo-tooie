#ifndef CORE2_MODEL_MESH_H
#define CORE2_MODEL_MESH_H

#include "common.h"

#ifdef BT_NATIVE
#include <stddef.h>

typedef struct {
    s32 asset_id;
    s32 mesh_count;
    f32 scale[3];
    u8 *vertices;
    u8 *other_vertices;
    u8 meshes[];
} ModelMesh;

typedef void (*MeshVertexVisitor)(s32 mesh, s16 *source, u8 *vertex, u8 *context);
void _glid_entrypoint_2(u8 *model, s32 mesh, MeshVertexVisitor visit, u8 *context);

#ifdef BT_ILP32
_Static_assert(offsetof(ModelMesh, vertices) == 0x14, "N64 vertex list");
_Static_assert(offsetof(ModelMesh, other_vertices) == 0x18, "N64 alternate vertex list");
_Static_assert(offsetof(ModelMesh, meshes) == 0x1C, "N64 mesh table");
#endif
#endif
#endif
