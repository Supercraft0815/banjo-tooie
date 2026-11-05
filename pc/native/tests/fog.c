#include "native_fog.h"
#include "native_camera_frame.h"
#include "native_world_grid.h"
#include "memory.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
static void packet(s32 visible,u32 factors,u32 color) {
    struct {Gfx commands[3];u64 guard;} out={.guard=0xABCDEF0123456789ULL};Gfx *cursor=out.commands;
    native_fog_apply(&cursor,visible);CHECK(cursor==out.commands+1);
    CHECK(out.commands[0].words.w0==0xDB080000 && out.commands[0].words.w1==factors);
    func_800D2C54(&cursor);CHECK(cursor==out.commands+2 && out.commands[1].words.w0==0xF8000000 && out.commands[1].words.w1==color);
    func_800D2C54(&cursor);CHECK(cursor==out.commands+2);
    func_800D2CC4();func_800D2C54(&cursor);CHECK(cursor==out.commands+3 && out.commands[2].words.w1==color);
    CHECK(out.guard==0xABCDEF0123456789ULL);
}
static void test_factors(void) {
    NativeCamera camera;func_800CA440(&camera);func_800E42B4(&camera);func_800E3C8C(1,3);
    NativeFogConfig hidden={0,1,0,2,3,{1,2,3,4}},visible={0,2,0,1,3,{255,170,85,1}};
    func_800D2970();func_800D2910(0,&hidden);func_800D2910(1,&visible);
    packet(0,0x0200FF00,0x01020304);packet(1,0x00800080,0xFFAA5501);
    visible.start=10;visible.end=20;func_800D2910(1,&visible);packet(1,0,0xFFAA5501);
    visible.start=-1;visible.end=-3;func_800D2910(1,&visible);packet(1,0xFF800280,0xFFAA5501);
    func_800E3C8C(1,30000);visible.start=20000;visible.end=25000;func_800D2910(1,&visible);packet(1,0x7FFF8001,0xFFAA5501);
    func_800E3C8C(1,3);visible.start=visible.end=2;func_800D2910(1,&visible);packet(1,0x80018001,0xFFAA5501);
    visible.start=NAN;func_800D2910(1,&visible);packet(1,0x80018001,0xFFAA5501);
    Gfx command={{0x12345678,0x87654321}},*cursor=&command;
    func_800E3C8C(3,3);native_fog_apply(&cursor,1);CHECK(cursor==&command && command.words.w0==0x12345678);
    func_800E3C8C(1,3);func_800D2970();func_800D2910(0,&hidden);native_fog_apply(&cursor,1);CHECK(cursor==&command);
    func_800D2970();func_800D2910(-1,&hidden);func_800D2910(2,&hidden);func_800D2910(0,NULL);
    native_fog_apply(&cursor,0);CHECK(cursor==&command);func_800D2C54(&cursor);CHECK(command.words.w1==0xFFAA5501);
    func_800D2910(1,&visible);func_800E4290();cursor=&command;native_fog_apply(&cursor,1);CHECK(cursor==&command);
    native_fog_apply(NULL,1);cursor=NULL;native_fog_apply(&cursor,1);func_800D2C54(NULL);func_800D2C54(&cursor);func_800D2970();
}
static void test_maps(void) {
    NativeCamera camera;func_800CA440(&camera);func_800E42B4(&camera);func_800E3C8C(1,3);
    for(int map=-1;map<=0x300;++map) {
        native_fog_load_map(map);
        if(map==0x181 || map==0xFC)for(int visible=0;visible<2;++visible)packet(visible,0,map==0x181 ? 0x404080C0 : 0x0F3F537F);
        else {Gfx command,*cursor=&command;native_fog_apply(&cursor,0);native_fog_apply(&cursor,1);CHECK(cursor==&command);}
    }
    func_800E4290();func_800D2970();
}
static void test_layers(void) {
    NativeWorldCell cells[12]={0};u8 counts[12]={0};
    native_world_grid=(NativeWorldGrid){.cells=cells,.model_counts=counts,.count=12,.dimensions={2,3,2},.row_stride=2,.plane_stride=6};
    func_800E9728();*func_800E9A24(cells+1)=(Prop){0};*func_800E9A24(cells+10)=(Prop){0};
    *func_800E9A24(&native_world_grid.fallback)=(Prop){0};
    func_800D2CD0();CHECK(func_800D2E90(0) && !func_800D2E90(1) && func_800D2E90(2));
    CHECK(!func_800D2E90(-1) && !func_800D2E90(3) && !func_800D2E90(INT_MAX));
    func_800D2EE4();CHECK(func_800D2E90(2));
    func_800E9C44(cells+1);*func_800E9A24(cells+8)=(Prop){0};
    func_800D2CD0();CHECK(!func_800D2E90(0) && func_800D2E90(1) && func_800D2E90(2));
    native_world_grid.plane_stride=INT_MAX;func_800D2CD0();CHECK(!func_800D2E90(1));native_world_grid.plane_stride=6;
    native_world_grid.dimensions[1]=INT_MAX;func_800D2CD0();CHECK(!func_800D2E90(0));native_world_grid.dimensions[1]=3;
    for(int i=0;i<12;++i)func_800E9C44(cells+i);func_800E9C44(&native_world_grid.fallback);func_800E9774();
    native_world_grid=(NativeWorldGrid){0};func_800D2CD0();func_800D2EE4();func_800D2E4C();func_800D2E4C();CHECK(!func_800D2E90(0));
}
int main(void) {test_factors();test_maps();test_layers();puts("native fog factors, view selection, map data, color caching and real world layers passed");return 0;}
