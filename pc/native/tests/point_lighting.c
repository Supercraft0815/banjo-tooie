#include "native_point_lighting.h"
#include "native_lights.h"
#include "native_assets.h"
#include "memory.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
s32 func_8001211C(void) {return 100;}
void func_80019750(f32 *,f32 *,f32,f32 *),func_800193C4(f32 *,f32 *);
static NativeVertexLight colors[6];
static NativeRenderData data;
static void reset(void) {
    func_800C90D0();func_800C90AC();mlMtxIdent();
    s32 ambient[3]={128,64,32};func_800C8C90(ambient);
    rare_memset(data.vertices,0,sizeof(*data.vertices)+6*sizeof(Vtx));
    data.vertices->count_flags=12;data.vertices->center_radius=40;
    data.scale=1;data.position=data.rotation=data.origin=NULL;
    for(int i=0;i<6;++i) {
        colors[i]=(NativeVertexLight){{0},{128,64,255,17}};
        Vtx *v=data.vertices->vertices+i;v->v.ob[0]=i*10;
        for(int c=0;c<4;++c)v->v.cn[c]=77;
    }
    data.vertices->vertices[5].v.flag=0x1000;
}
static s32 light(f32 x,s32 mask,u32 r,u32 g,u32 b) {
    s32 id=func_800C8A98();f32 position[3]={x,0,0};
    func_800C8CB8(id,position);func_800C8E54(id,10,30);
    func_800C8FB0(id,r,g,b);func_800C8F64(id,mask);return id;
}
static void rgb(int vertex,int r,int g,int b) {
    Vtx *v=data.vertices->vertices+vertex;
    if(v->v.cn[0]!=r || v->v.cn[1]!=g || v->v.cn[2]!=b)fprintf(stderr,"vertex %d: RGB %u,%u,%u, expected %d,%d,%d\n",vertex,v->v.cn[0],v->v.cn[1],v->v.cn[2],r,g,b);
    CHECK(v->v.cn[0]==r && v->v.cn[1]==g && v->v.cn[2]==b && v->v.cn[3]==77);
    CHECK(v->v.ob[0]==vertex*10);
}
static void test_colors(void) {
    reset();s32 id=light(0,1,100,64,32);MtxF *stack=mlMtx_get_stack_pointer();
    func_8010EECC(&data,1,0,NULL);CHECK(stack==mlMtx_get_stack_pointer());
    rgb(0,114,32,63);rgb(1,114,32,63);rgb(2,89,24,47);rgb(3,64,16,31);rgb(4,64,16,31);rgb(5,77,77,77);
    func_800C8FB0(id,255,255,255);func_8010EECC(&data,-1,0,NULL);rgb(0,191,79,255);
    func_800C8FE0(id,0);func_8010EECC(&data,1,0,NULL);rgb(0,64,16,31);
    s32 ambient[3]={512,-4,256};func_800C8C90(ambient);
    func_8010EECC(&data,0,0,NULL);rgb(0,0,255,255);CHECK(!func_8010E810()->count);

    reset();id=light(0,2,100,64,32);
    func_8010F950(&data,1,0,NULL);CHECK(D_80137240.used!=NULL);if(sizeof(void *)==8)CHECK((uintptr_t)D_80137240.used>UINT32_MAX);CHECK(D_80137240.render==&data);CHECK(D_80137240.used>=D_80137240.entries && D_80137240.used<=D_80137240.end);CHECK(stack==mlMtx_get_stack_pointer());
    rgb(0,228,128,255);rgb(1,228,128,255);rgb(2,178,96,255);rgb(3,128,64,255);rgb(5,77,77,77);
    CHECK(data.vertices->count_flags==13);
    func_8010F950(&data,-1,0,NULL);rgb(0,228,128,255);
    func_800C8F64(id,1);func_8010F950(&data,1,0,NULL);rgb(0,128,64,255);CHECK(data.vertices->count_flags==12);
    data.vertices->vertices[0].v.cn[0]=42;func_8010F950(&data,0,0,NULL);rgb(0,42,64,255);
}
static void test_selection(void) {
    reset();light(12,1,10,0,0);light(4,1,20,0,0);light(8,1,30,0,0);light(1,2,255,255,255);
    NativePointLighting *list=func_8010E810();CHECK(list==&D_80137080);if(sizeof(void *)==8)CHECK((uintptr_t)list>UINT32_MAX);func_8010EECC(&data,-2,0,NULL);
    CHECK(list->count==2 && list->entries[0].distance==4 && list->entries[1].distance==8);rgb(0,89,16,31);
    CHECK(!func_8010E81C(8));NativePointLight *entry=func_8010E81C(6);CHECK(entry==list->entries+1);entry->distance=6;
    CHECK(list->used==list->entries+2 && list->entries[0].color[0]==20);
    reset();for(int i=12;i>0;--i)func_800C8E54(light(i,3,1,1,1),20,30);
    func_8010EECC(&data,INT_MIN,0,NULL);CHECK(list->count==9 && list->entries[8].distance==9);
    func_8010F950(&data,INT_MAX,0,NULL);rgb(0,133,69,255);
    CHECK(!func_8010F280(INT_MIN));entry=func_8010F280(INT_MAX);CHECK(entry);entry->score=INT_MAX;
    reset();light(0,2,20,0,0);light(0,2,0,40,0);light(0,2,0,0,30);
    func_8010F950(&data,1,0,NULL);rgb(0,128,104,255);
    light(0,2,40,0,0);func_8010F950(&data,1,0,NULL);rgb(0,128,104,255);
    reset();light(0,2,0,40,0);light(60,2,200,0,0);
    func_8010F950(&data,1,0,NULL);rgb(0,128,104,255);
}
static void test_transform_and_angler(void) {
    reset();s32 id=light(0,1,100,50,25);f32 position[3]={100,20,-40},origin[3]={3,4,5},rotation[3]={0,90,0};
    data.position=position;data.origin=origin;data.rotation=rotation;data.scale=2;
    mlMtxIdent();func_80019750(position,rotation,2,origin);
    f32 world[3],local[3]={10,20,30};func_800193C4(world,local);func_800C8CB8(id,world);func_800C8E54(id,20,100);
    MtxF before;mlMtxGet(&before);MtxF *stack=mlMtx_get_stack_pointer();
    func_8010EECC(&data,1,0,NULL);CHECK(stack==mlMtx_get_stack_pointer());
    for(int i=0;i<16;++i)CHECK(((f32 *)stack)[i]==((f32 *)&before)[i]);
    NativePointLighting *list=func_8010E810();CHECK(list->count==1 && list->entries[0].inner==2560 && list->entries[0].outer_squared==2500);
    for(int i=0;i<3;++i)CHECK(abs(list->entries[0].position[i]-(s32)local[i])<=1);
    reset();s32 forced=light(10,1,100,0,0);light(0,1,0,100,0);
    trangler_entrypoint_0(&data,0x10000|forced,0,NULL);
    CHECK(list->count==1 && list->entries[0].distance==-1);rgb(0,114,16,31);
    trangler_entrypoint_0(&data,0x20000|forced,0,NULL);CHECK(list->count==2);rgb(0,114,41,31);
    trangler_entrypoint_0(&data,forced,0,NULL);CHECK(!list->count);rgb(0,64,16,31);
    trangler_entrypoint_0(&data,0x1FFFF,0,NULL);CHECK(list->count==1 && list->entries[0].distance==0);
    func_800C8F64(2,2);trangler_entrypoint_0(&data,0x20000|forced,0,NULL);
    CHECK(list->count==2 && list->entries[1].color[0]==100);rgb(0,164,16,31);
    f32 far[3]={10000,0,0};func_800C8CB8(forced,far);
    trangler_entrypoint_0(&data,0x10000|forced,0,NULL);CHECK(!list->count);
}
static void same_vertices(const Vtx *a,const Vtx *b,u32 count) {
    for(size_t i=0;i<count*sizeof(*a);++i)CHECK(((const u8 *)a)[i]==((const u8 *)b)[i]);
}
static void test_archive(const char *path) {
    CHECK(native_assets_open(path));reset();s32 id=light(0,3,128,64,32);func_800C8E54(id,100,1000);
    unsigned models=0,vertices=0;
    for(s32 asset=0;asset<native_asset_count();++asset) {
        if((native_asset_flags(asset)&15) || native_asset_packed_size(asset)<=0)continue;
        s32 size;u8 *model=native_asset_load(asset,&size);CHECK(model);
        NativeVertexList *v=func_800B2840(model);CHECK(v);u32 count=func_800B2344(v);
        NativeVertexLight *base=heap_alloc(count*sizeof(*base));Vtx *saved=heap_alloc(count*sizeof(*saved)),*point=heap_alloc(count*sizeof(*point));
        rare_memcpy(saved,v->vertices,count*sizeof(*saved));
        for(u32 i=0;i<count;++i){base[i]=(NativeVertexLight){0};for(int c=0;c<4;++c)base[i].color[c]=saved[i].v.cn[c];}
        f32 center[3]={v->center[0],v->center[1],v->center[2]};func_800C8CB8(id,center);
        NativeRenderData model_data={.scale=1,.vertices=v,.colors=base};MtxF *stack=mlMtx_get_stack_pointer();
        func_8010EECC(&model_data,3,0,NULL);CHECK(func_8010E810()->count==1);
        rare_memcpy(point,v->vertices,count*sizeof(*point));
        trangler_entrypoint_0(&model_data,0x30000,0,NULL);
        same_vertices(v->vertices,point,count);
        func_8010F950(&model_data,3,0,NULL);CHECK(v->count_flags==((count<<1)|1));
        rare_memcpy(point,v->vertices,count*sizeof(*point));func_8010F950(&model_data,3,0,NULL);
        same_vertices(v->vertices,point,count);
        func_8010F950(&model_data,0,0,NULL);CHECK(v->count_flags==count<<1);
        same_vertices(v->vertices,saved,count);
        CHECK(stack==mlMtx_get_stack_pointer());++models;vertices+=count;
        heap_free(point);heap_free(saved);heap_free(base);heap_free(model);
    }
    native_assets_shutdown();CHECK(models && vertices);
    printf("Checked point, additive and Angler lighting on %u original models / %u vertices.\n",models,vertices);
}
int main(int argc,char **argv) {
    CHECK(argc==1 || argc==2);data.vertices=heap_alloc(sizeof(*data.vertices)+6*sizeof(Vtx));data.colors=colors;
    test_colors();test_selection();test_transform_and_angler();if(argc==2)test_archive(argv[1]);
    func_800C90D0();heap_free(data.vertices);puts("native point-light selection, transforms, colors and restore checks passed");return 0;
}
