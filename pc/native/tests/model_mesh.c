#include "core2/model_mesh.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr, "line %d: %s\n",__LINE__,#x); abort(); } } while (0)

static s16 indices[] = {2, 31, 2, 0, 2, 57, 1, 1};
static _Alignas(8) u8 vertices[2][24+48];
static _Alignas(2) u8 state[32];
static int calls[4], count;
static size_t allocated;
static int asset;

BtIntPtr func_800D674C(s32 id) { CHECK(id == 205); return (BtIntPtr)&asset; }
BtIntPtr func_800B274C(BtIntPtr model) { CHECK(model == (BtIntPtr)&asset); return (BtIntPtr)indices; }
BtIntPtr func_800B2840(BtIntPtr model) { CHECK(model == (BtIntPtr)&asset); return (BtIntPtr)vertices[0]; }
void *func_800B2190(void *v) { CHECK(v==vertices[0] || v==vertices[1]); return (u8 *)v+24; }
void aligned4_memcpy(void *out, void *in, int n) { __builtin_memcpy(out,in,n); }
void func_800EE7F8(f32 *out,f32 *in) { __builtin_memcpy(out,in,3*sizeof(*out)); }
void func_800EFD24(f32 *out) { __builtin_memset(out,0,3*sizeof(*out)); }
void *heap_alloc(s32 size) { allocated=size; return malloc(size); }
void *glidmake_entrypoint_5(s32,f32 *);
void glid_entrypoint_5(void *,void *);
void glid_entrypoint_6(void *,void *);
void idwater_entrypoint_0(s32,s16 *,u8 *,u8 *);
static void visit(s32 mesh,s16 *source,u8 *vertex,u8 *ctx) {
    CHECK(mesh==31 && ctx==state && (uintptr_t)source>UINT32_MAX);
    CHECK((uintptr_t)vertex>UINT32_MAX && count<2);
    calls[count++] = (vertex-(vertices[1]+24))/16;
    idwater_entrypoint_0(mesh,source,vertex,ctx);
}
int main(void) {
    f32 scale[]={1.5f,2.5f,3.5f};
    ((s16 *)(vertices[0]+24))[1]=17;
    ((s16 *)(vertices[0]+24+32))[1]=21;
    ((s16 *)state)[8]=5;
    ModelMesh *model=glidmake_entrypoint_5(205,scale);
    CHECK((uintptr_t)model>UINT32_MAX && (uintptr_t)state>UINT32_MAX);
    CHECK(model->asset_id==205 && model->mesh_count==2 && model->scale[2]==3.5f);
    CHECK(model->vertices==vertices[0] && !model->other_vertices);
    CHECK(allocated==offsetof(ModelMesh,meshes)+48+16+12);
    glid_entrypoint_6(model,vertices[0]); glid_entrypoint_5(model,vertices[1]);
    CHECK(model->other_vertices==vertices[0] && model->vertices==vertices[1]);
    _glid_entrypoint_2((u8 *)model,13,visit,state);
    CHECK(count==0);
    _glid_entrypoint_2((u8 *)model,31,visit,state);
    CHECK(count==2 && calls[0]==0 && calls[1]==2);
    CHECK(((s16 *)(vertices[1]+24))[1]==22 && ((s16 *)(vertices[1]+24+32))[1]==26);
    free(model);
    return 0;
}
