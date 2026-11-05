#include "native_reflection.h"
#include "native_assets.h"
#include "native_model.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
s32 func_8001211C(void) {return 100;}
static void mirror(s32 map,f32 *out,const f32 *in) {
    for(int i=0;i<3;++i)out[i]=in[i];
    if(map==0x103)out[0]=2100-in[0];else out[1]=-in[1];
}
static void test_planes(void) {
    const s32 maps[]={0x151,0x103,0x15E},models[]={0x861,0x860,0x857};s16 water=99;
    CHECK(!func_800B5698(&water) && water==99);
    for(int mode=0;mode<3;++mode) {
        CHECK(native_reflection_load_map(maps[mode]) && func_800BCC84() && func_800BCC58());
        CHECK(native_reflection.model==models[mode] && native_reflection.alpha==255 && !native_reflection.bounds_valid);
        CHECK(native_reflection.buffers[0] && native_reflection.buffers[1] && native_reflection.buffers[0]!=native_reflection.buffers[1]);
        CHECK(func_800B5698(&water) && water==0);
        f32 fixed[4][4];guMtxL2F(fixed,&native_reflection.fixed);
        for(int i=0;i<16;++i)CHECK(((f32 *)fixed)[i]==((f32 *)&native_reflection.matrix)[i]);
        for(int i=-20;i<20;++i) {
            f32 input[3]={i*3,i*7,i*-11},expected[3],out[3];mirror(maps[mode],expected,input);
            func_800BCC28(out,input);for(int c=0;c<3;++c)CHECK(out[c]==expected[c]);
            func_800BCC28(out,out);for(int c=0;c<3;++c)CHECK(out[c]==input[c]);
        }
        func_800BC8A0();CHECK(!func_800BCC84() && !func_800BCC58() && !native_reflection.buffers[0]);
    }
    func_800B5680(70000);CHECK(func_800B5698(&water) && water==4464);
    CHECK(!native_reflection_load_map(-1) && !native_reflection_load_map(0x10000));
    CHECK(native_reflection_load_map(0x103) && func_800B5698(&water) && water==4464);
    CHECK(native_reflection_load_map(0x151) && func_800B5698(&water) && !water);
    CHECK(!native_reflection_load_map(0) && !func_800BCC84());func_800BC8A0();
}
static void test_camera(void) {
    NativeCamera camera;func_800CA440(&camera);func_800E42B4(&camera);
    const s32 maps[]={0x151,0x103,0x15E};
    for(int mode=0;mode<3;++mode) {
        CHECK(native_reflection_load_map(maps[mode]));f32 center=mode==1 ? 1045 : 0;
        func_800CA5F8(&camera,center,5,0);func_800CAF34(&camera);
        for(int x=-20;x<=20;x+=10)for(int y=-20;y<=20;y+=10)for(int z=-20;z<=20;z+=10) {
            f32 point[3]={center+x,y,z},reflected[3];mirror(maps[mode],reflected,point);
            CHECK(func_800E3E8C(point,1)==(func_800CACEC(camera.values,point,1) || func_800CACEC(camera.values,reflected,1)));
            CHECK(func_800E3EFC(point[0],point[1],point[2])==(func_800CAD9C(&camera,point[0],point[1],point[2]) || func_800CAD9C(&camera,reflected[0],reflected[1],reflected[2])));
            CHECK(func_800E3F8C(point[0],point[1],point[2])==(func_800CAEA4(&camera,point[0],point[1],point[2]) || func_800CAEA4(&camera,reflected[0],reflected[1],reflected[2])));
            f32 low[3],high[3],ref_low[3],ref_high[3];s16 short_low[3],short_high[3];
            for(int c=0;c<3;++c){low[c]=point[c]-1;high[c]=point[c]+1;short_low[c]=low[c];short_high[c]=high[c];}
            mirror(maps[mode],ref_low,low);mirror(maps[mode],ref_high,high);
            int axis=mode==1 ? 0 : 1;f32 swap=ref_low[axis];ref_low[axis]=ref_high[axis];ref_high[axis]=swap;
            int visible=func_800CAA24(camera.values,low,high) || func_800CAA24(camera.values,ref_low,ref_high);
            CHECK(func_800E3D0C(low,high)==visible && func_800E3DC0(short_low,short_high)==visible);
        }
    }
    func_800CA5F8(&camera,0,5,0);func_800CAF34(&camera);f32 point[3]={0,-5,-10};
    CHECK(!func_800CACEC(camera.values,point,1) && func_800E3E8C(point,1));
    native_reflection.cull_enabled=0;CHECK(!func_800E3E8C(point,1));
    func_800BC8A0();func_800E4290();
}
static void test_buffers(void) {
    NativeCamera camera;func_800CA440(&camera);func_800E42B4(&camera);
    NativeGraphicsMemory memory={0};Gfx packets[16];Mtx matrices[4];NativeGraphicsContext frame={packets,matrices,packets+16,matrices+4,&memory};
    CHECK(func_800BC8F8(NULL));CHECK(native_reflection_load_map(0x151));CHECK(!func_800BC8F8(NULL) && !func_800BC8F8(&frame));
    CHECK(native_graphics_register(&memory,matrices,sizeof(matrices)));CHECK(func_800E44FC(&frame));
    Gfx *main_cursor=frame.gfx,*main_end=frame.gfx_end;Mtx *matrix_cursor=frame.mtx;
    CHECK(func_800BC8F8(&frame));CHECK(frame.gfx==native_reflection.buffers[native_reflection.index] && frame.gfx_end-frame.gfx==2999 && frame.mtx==matrix_cursor);
    CHECK(!func_800BC8F8(&frame));native_graphics_bind(&memory);
    Gfx *start=frame.gfx;func_800E4640(&frame.gfx);CHECK(start[0].words.w0==0xDE000000 && start[0].words.w1==0x08000000);
    func_800BCC90(&frame.gfx);CHECK(start[1].words.w0==0xDA380005 && native_graphics_resolve(&memory,start[1].words.w1,sizeof(Mtx))==&native_reflection.fixed);
    for(int mode=0;mode<2;++mode) {
        Gfx *at=frame.gfx;u32 value=mode ? G_CULL_BACK : G_CULL_FRONT;func_800E7FF8(&frame.gfx,value);func_800E8078(&frame.gfx);
        CHECK(frame.gfx==at+3 && D_8012D5E0==value && at[0].words.w0==0xD9FFFFFF && at[0].words.w1==value && at[1].words.w0==0xDB06001C);
        CHECK(native_graphics_segment(&memory,7,at[1].words.w1));const Gfx *list=native_graphics_resolve(&memory,at[2].words.w1,2*sizeof(Gfx));
        CHECK(at[2].words.w0==0xDE000000 && at[2].words.w1==0x07000000 && list && list[0].words.w1==value && list[1].words.w0==0xDF000000);
    }
    ++frame.mtx;func_800BC8A0();CHECK(frame.gfx==main_cursor && frame.gfx_end==main_end && frame.mtx==matrix_cursor && !native_reflection.frame);
    func_800E4640(&frame.gfx);CHECK(main_cursor[0].words.w0==0xDA380007 && native_graphics_resolve(&memory,main_cursor[0].words.w1,sizeof(Mtx))==matrices);
    native_graphics_reset(&memory);CHECK(native_reflection_load_map(0x103));CHECK(!func_800BC8F8(&frame));
    CHECK(native_graphics_register(&memory,matrices,sizeof(matrices)));memory.next=0x7FFFFFF8;
    CHECK(!func_800BC8F8(&frame) && !native_reflection.frame && frame.gfx==main_cursor+1);
    func_800BC8A0();func_800E4628();func_800E4290();native_graphics_dispose(&memory);
}
static void test_archive(const char *path) {
    CHECK(native_assets_open(path));const s32 maps[]={0x151,0x103,0x15E};u32 total=0;
    for(int i=0;i<3;++i) {
        CHECK(native_reflection_load_map(maps[i]));s32 size;u8 *model=native_asset_load(native_reflection.model,&size);CHECK(model);
        NativeVertexList *vertices=func_800B2840(model);CHECK(vertices && func_800B2344(vertices));
        int axis=i==1 ? 0 : 1,value=i==1 ? 1050 : 0;
        CHECK(vertices->minimum[axis]==value && vertices->maximum[axis]==value);
        for(u32 v=0;v<func_800B2344(vertices);++v) {
            CHECK(vertices->vertices[v].v.ob[axis]==value);f32 point[3],out[3];
            for(int c=0;c<3;++c)point[c]=vertices->vertices[v].v.ob[c];func_800BCC28(out,point);
            for(int c=0;c<3;++c)CHECK(out[c]==point[c]);++total;
        }
        heap_free(model);
    }
    func_800BC8A0();native_assets_shutdown();CHECK(total==356);
    printf("Verified all three original reflection surfaces / %u vertices lie on their configured mirror planes.\n",total);
}
int main(int argc,char **argv) {
    CHECK(argc==1 || argc==2);test_planes();test_camera();test_buffers();if(argc==2)test_archive(argv[1]);
    puts("native reflection planes, camera culling, buffer switching and face-culling packets passed");return 0;
}
