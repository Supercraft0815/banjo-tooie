#include "native_render.h"
#include "native_model_lighting.h"
#include "native_lights.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
s32 func_8001211C(void) {return 100;}
static uintptr_t callback_value;
static void callback(uintptr_t value) {callback_value=value;}
static void near(f32 value,f32 expected) {CHECK(fabsf(value-expected)<0.0001f);}
static void test_state(void) {
    func_800DF38C();CHECK(*func_800DF330() && func_8010E3B8());CHECK(D_80137060.lights==func_8010E3B8());if(sizeof(void *)==8)CHECK((uintptr_t)D_80137060.lights>UINT32_MAX);CHECK(native_render.look_at.current==native_render.look_at.buffer && native_render.look_at.end==native_render.look_at.buffer+32);
    CHECK(native_render.distance==30000 && native_render.range_scale==1 && native_render.cull && native_render.env[3]==255);
    CHECK(func_800DF33C(1)==1 && !func_800DF33C(2));
    BoneTransformList pose={0};NativeVertexList *vertices=heap_alloc(sizeof(*vertices));NativeBoneMatrices *bones=func_800ADF98();
    NativeVertexLight colors[1];s8 normals[4];u8 textures[8];Mtx matrices[1];Gfx modes[2];MtxF matrix={.m={{1,0,0,0},{0,2,0,0},{0,0,3,0},{4,5,6,1}}};
    NativeDisplayList *display=heap_alloc(sizeof(*display));
    func_800DF41C(&pose);func_800DF72C(bones);func_800DF818(vertices);func_800DF720(colors);func_800DF824(normals);func_800DF714(matrices);func_800DF7DC(textures);func_800DF4A4(display);
    CHECK(func_800DF324()==&pose && native_render.data.animation==bones && native_render.data.matrices==matrices && native_render.data.display_list==display);
    CHECK(func_800DF8B4(&native_render.data)==vertices && func_800DF8BC(&native_render.data)==colors && func_800DF8CC(&native_render.data)==normals);
    CHECK(func_800DF8D4(&native_render.data));native_render.data.animated_vertices=textures;CHECK(!func_800DF8D4(&native_render.data));
    func_800DF47C(callback,(uintptr_t)vertices);func_800DF490(callback,(uintptr_t)bones);
    native_render.before(native_render.before_arg);CHECK(callback_value==(uintptr_t)vertices);native_render.after(native_render.after_arg);CHECK(callback_value==(uintptr_t)bones);
    func_800DF660(2,(uintptr_t)colors,(uintptr_t)display,17);CHECK(native_render.callback_mode==1 && native_render.callback_type==2 && native_render.callback_args[1]==(uintptr_t)display && native_render.env[3]==17);
    func_800DF660(0,0,0,99);CHECK(!native_render.callback_mode && native_render.env[3]==17);
    func_800DF738(vertices);func_800DF83C(textures);func_800DF7F8(123,20,30);CHECK(native_render.attachments==vertices && native_render.zone_override==textures && native_render.radius==30);
    CHECK(func_800DF428(400)==30000);func_800DF440(0);func_800DF464(2);func_800DF470(1);
    f32 rotation[3]={10,20,30};func_800DF4CC(rotation);CHECK(native_render.transform_mode==1 && native_render.transform[2]==30);
    func_800DF500(2,3,4);CHECK(native_render.transform_mode==2 && native_render.transform[1]==3);
    func_800DF540(&matrix);CHECK(native_render.transform_mode==3 && native_render.extra_matrix.m[3][0]==4);
    func_800DF574(123);func_800DF4B0(2);func_800DF7E8(7);func_800DF848(modes,modes+1);CHECK(native_render.depth_mode==4 && native_render.custom_modes[1]==modes+1);
    s32 env[4]={1,2,3,4},prim[4]={5,6,7,8};func_800DF580(env,prim);CHECK(native_render.color_mode==1 && native_render.prim[3]==8 && native_render.env[0]==1);
    func_800DF5D8(300,22,UINT_MAX,55);CHECK(native_render.color_mode==2 && native_render.env[0]==255 && native_render.env[1]==22 && native_render.env[2]==-1 && native_render.env[3]==55);
    func_800DF6BC(500,33);CHECK(native_render.color_mode==3 && native_render.prim[0]==255 && native_render.env[3]==33);
    s32 switches[60];for(int i=0;i<60;++i)switches[i]=i+100;func_800DF744(0,9);func_800DF758(switches);CHECK(func_800DF33C(0)==9 && func_800DF33C(59)==159);
    func_800DF7C4(59,13);CHECK(func_800DF33C(59)==-13);func_800DF744(-1,5);func_800DF744(60,5);CHECK(!func_800DF33C(-1));
    func_800DF874();CHECK(*func_800DF330() && func_8010E3B8());
    func_800DE318();CHECK(!func_800DF324() && !native_render.data.animation && !native_render.data.vertices && !native_render.data.colors && !native_render.data.normals && !native_render.data.display_list);
    CHECK(!native_render.before && !native_render.after && !native_render.attachments && !native_render.zone_override && !native_render.geometry_mode);
    CHECK(func_800DF33C(0)==9 && func_800DF33C(1)==1 && !func_800DF33C(2) && func_800DF33C(59)==-13 && native_render.custom_modes[1]==modes+1);
    func_800DF3E0();for(int i=0;i<60;++i)CHECK(!func_800DF33C(i));
    native_render.visible=1;CHECK(func_800DF350());
    native_render.data.scale=2;native_render.data.position=rotation;CHECK(func_800DF8C4(&native_render.data)==2 && func_800DF8F8(&native_render.data)==rotation);
    mlMtxIdent();func_800DF900(&native_render.data);MtxF inverse;mlMtxGet(&inverse);near(inverse.m[0][0],0.5f);near(inverse.m[3][0],-5);mlMtxPop();
    func_800ADF5C(bones);heap_free(vertices);heap_free(display);func_800DF35C();CHECK(!*func_800DF330() && !func_8010E3B8());
}
static void test_light_lists(void) {
    s32 ambient[3]={10,20,30};func_800C8C90(ambient);
    CHECK(!func_800B3310(-1) && !func_800B3310(INT_MAX));
    NativeModelLightList *list=func_800B3310(2),*empty=func_800B3310(0);CHECK(list->ambient[1]==20 && !func_800B3390(empty,1));
    f32 direction[3]={1,0,0};s32 color[3]={100,150,200};CHECK(func_800B36C0(list,direction,color,20));CHECK(func_800B36C0(list,direction,color,40));CHECK(!func_800B36C0(list,direction,color,10));
    NativeModelLight *entry=func_800B3390(list,10);CHECK(entry==list->entries);*entry=(NativeModelLight){{0,1,0},{1,2,3},10};
    CHECK(func_800B3784(list)==2 && list->entries[1].distance==20 && list->entries[1].color[1]==150);
    CHECK(!func_800B3390(list,20));NativeModelLight *begin,*end;func_800B37A4(list,&begin,&end);CHECK(begin==list->entries && end==list->entries+2);
    NativeModelLightList *copy=func_800B3310(1);func_800B37E4(copy,list);CHECK(func_800B3784(copy)==1 && copy->entries[0].direction[1]==1 && copy->ambient[2]==30);
    func_800B388C(list,999);CHECK(list->end==list->entries+2);func_800B388C(list,-1);CHECK(!func_800B3784(list) && !func_800B36C0(list,direction,color,1));
    func_800B388C(list,2);func_800B3748(list);CHECK(func_800B3784(list)==1 && list->entries[0].distance==500);
    func_800B38A8(list,color);func_800B37B8(list,ambient);CHECK(ambient[0]==100 && ambient[2]==200);CHECK(func_800B38E8(list)==list);
    func_800B3370(copy);func_800B3370(empty);func_800B3370(list);
}
static void test_world_lights(void) {
    func_800C90D0();func_800C90AC();NativeModelLightList *list=func_800B3310(2);f32 object[3]={0};
    int distances[]={12,4,8};for(int i=0;i<3;++i){s32 id=func_800C8A98();f32 position[3]={distances[i],0,0};func_800C8CB8(id,position);func_800C8E54(id,5,15);func_800C8FB0(id,100,100,100);}
    CHECK(func_800B3494(list,object,0)==2);CHECK(list->entries[0].distance==4 && list->entries[1].distance==8);CHECK(list->entries[0].color[0]==100 && list->entries[1].color[0]==70);
    func_800DF38C();mlMtxIdent();
    NativeRenderData data={.scale=1};data.vertices=heap_alloc(sizeof(*data.vertices)+sizeof(Vtx));
    rare_memset(data.vertices,0,sizeof(*data.vertices)+sizeof(Vtx));data.vertices->count_flags=2;
    NativeVertexLight color={.color={128,128,128,255}};s8 normal[4]={127,0,0,0};data.colors=&color;data.normals=normal;
    func_8010E2C4(&data,2,NULL,0);s32 cursor=0;func_8010E4C4(NULL,&cursor,1);
    CHECK(cursor==1 && data.vertices->vertices[0].v.cn[0]==43 && func_800B3784(func_8010E3B8())==2);
    heap_free(data.vertices);func_800DF35C();
    f32 far[3]={100,0,0};CHECK(!func_800B3494(list,far,0));
    func_800C8CB8(1,object);CHECK(func_800B3494(list,object,0)==2);CHECK(!list->entries[0].distance && !list->entries[0].direction[0] && isfinite(list->entries[0].direction[1]));
    func_800B3370(list);func_800C90D0();
}
static void test_vertex_lighting(void) {
    func_800DF38C();mlMtxIdent();NativeRenderData data={.scale=1};
    data.vertices=heap_alloc(sizeof(*data.vertices)+2*sizeof(Vtx));rare_memset(data.vertices,0,sizeof(*data.vertices)+2*sizeof(Vtx));data.vertices->count_flags=4;
    NativeVertexLight colors[2]={{{0},{128,64,255,17}},{{0},{200,100,50,18}}};s8 normals[8]={127,0,0,99,-127,0,0,98};
    data.colors=colors;data.normals=normals;
    for(int i=0;i<2;++i){data.vertices->vertices[i].v.ob[0]=123;data.vertices->vertices[i].v.cn[3]=42;}
    NativeModelLightList *lights=func_800B3310(2);s32 ambient[3]={64,128,256};func_800B38A8(lights,ambient);
    func_8010E2C4(&data,2,lights,0);CHECK(D_80137060.render==&data && D_80137060.lights!=NULL);CHECK(D_80137060.start==D_80137060.lights->entries && D_80137060.end==D_80137060.lights->used);s32 cursor=0;func_8010E4C4(NULL,&cursor,2);CHECK(cursor==2);
    CHECK(data.vertices->vertices[0].v.cn[0]==32 && data.vertices->vertices[0].v.cn[1]==32 && data.vertices->vertices[0].v.cn[2]==255);
    f32 direction[3]={1,0,0};s32 color[3]={100,100,100};CHECK(func_800B36C0(lights,direction,color,10));
    func_8010E2C4(&data,2,lights,0);cursor=0;func_8010E4C4(NULL,&cursor,2);
    CHECK(data.vertices->vertices[0].v.cn[0]==81 && data.vertices->vertices[0].v.cn[1]==56 && data.vertices->vertices[0].v.cn[2]==255);
    CHECK(data.vertices->vertices[1].v.cn[0]==50 && colors[0].light[0]==163 && colors[1].light[0]==64);
    for(int i=0;i<2;++i)CHECK(data.vertices->vertices[i].v.ob[0]==123 && data.vertices->vertices[i].v.cn[3]==42);
    CHECK(func_800B36C0(lights,direction,color,30));func_8010E358();CHECK(D_80137060.start==D_80137060.lights->entries && D_80137060.end==D_80137060.lights->used);func_8010E2C4(&data,2,lights,0);
    CHECK(func_8010E3B8()->entries[0].color[0]==75 && func_8010E3B8()->entries[1].color[0]==25);
    data.animation=*func_800DF330();MtxF rotate={.m={{0,1,0,0},{-1,0,0,0},{0,0,1,0},{0,0,0,1}}};
    normals[0]=0;normals[1]=-127;func_8010E2C4(&data,2,lights,0);cursor=0;func_8010E4C4(&rotate.m[0][0],&cursor,1);CHECK(data.vertices->vertices[0].v.cn[0]>32);
    s32 output[3];f32 zero[16]={0};func_8010E3C4(zero,output,direction);CHECK(!output[0] && !output[1] && !output[2]);
    cursor=1;func_8010E4C4(&rotate.m[0][0],&cursor,2);CHECK(cursor==1);cursor=-1;func_8010E4C4(&rotate.m[0][0],&cursor,1);CHECK(cursor==-1);
    func_8010E7F4();cursor=0;func_8010E4C4(NULL,&cursor,1);CHECK(!cursor);
    func_800B3370(lights);heap_free(data.vertices);func_800DF35C();
}
int main(void) {test_state();test_light_lists();test_world_lights();test_vertex_lighting();puts("native render state and model lighting checks passed");return 0;}
