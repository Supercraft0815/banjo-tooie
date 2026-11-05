#include "native_model.h"
#include "native_palette.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)

s32 func_8001211C(void) {return 100;}
static void put(u8 *p,u32 value,int width) {
    for(int i=0;i<width;++i)p[i]=value>>((width-1-i)*8);
}
static void make_model(u8 *bytes) {
    rare_memset(bytes,0,256);
    put(bytes,11,4);put(bytes+4,144,4);put(bytes+8,136,2);
    put(bytes+144,4,4); /* Empty geometry command; display list at 152 is empty. */
    put(bytes+10,0xA501,2);put(bytes+12,152,4);put(bytes+16,80,4);
    for(int i=20;i<=64;i+=4)put(bytes+i,160,4);
    put(bytes+28,224,4);put(bytes+240,1,2); /* One empty collision cell. */
    put(bytes+68,123,2);put(bytes+70,456,2);put(bytes+72,0x42F70000,4);
    s16 header[]={-101,-202,-303,404,505,606,-3,4,5,17,700,5};
    for(int i=0;i<12;++i)put(bytes+80+i*2,(u16)header[i],2);
    for(int i=0;i<2;++i) {
        u8 *v=bytes+104+i*16;
        put(v,(u16)(-100-i),2);put(v+2,200+i,2);put(v+4,300+i,2);
        put(v+6,0xE123,2);put(v+8,(u16)-12345,2);put(v+10,23456,2);
        v[12]=200;v[13]=100;v[14]=60;v[15]=42+i;
    }
}
static void test_vertices(void) {
    u64 storage[32];u8 *model=(void *)storage,*begin,*end;
    s32 minimum[3],maximum[3];f32 a[3],b[3],radius;
    make_model(model);CHECK(native_model_decode(model,sizeof(storage)));
    CHECK(func_800B270C((s16 *)model)==(s16)0xA501);
    CHECK(func_800B2714(model)==model+152 && func_800B27FC(model)==model+136);
    CHECK(func_800B27D8((f32 *)model)==123.5f);
    u8 *(*accessors[])(u8 *)={func_800B26F0,func_800B2720,func_800B274C,func_800B2768,
        func_800B2784,func_800B27A0,func_800B27BC,func_800B27E0,func_800B2808,
        func_800B2824,func_800B284C,func_800B2868};
    for(int i=0;i<12;++i)CHECK(accessors[i](model)==model+(i==1 ? 224 : 160));
    CHECK(!func_800B2720(NULL));
    NativeVertexList *v=func_800B2840(model);
    CHECK((void *)v==model+80 && func_800B2190(v)==v->vertices);
    CHECK(func_800B2324((u8 *)v,&begin,&end)==begin && begin==(u8 *)v->vertices && end-begin==32);
    CHECK(func_800B2344(v)==2 && (v->count_flags&1) && func_800B2354(v)==700);
    func_800B2198(v,minimum,maximum);func_800B21CC(v,a,b);
    for(int i=0;i<3;++i)CHECK(minimum[i]==-101*(i+1) && maximum[i]==404+101*i && a[i]==minimum[i] && b[i]==maximum[i]);
    CHECK(func_800B2248(v)==606);
    func_800B237C(v,a,&radius);CHECK(a[0]==-3 && a[1]==4 && a[2]==5 && radius==17);
    CHECK(v->vertices[1].v.ob[0]==-101 && v->vertices[1].v.ob[1]==201 && v->vertices[1].v.ob[2]==301);
    CHECK(v->vertices[0].v.flag==0xE123 && v->vertices[0].v.tc[0]==-12345 && v->vertices[0].v.tc[1]==23456);
    NativeVertexList *copy=func_800B2400(v,1);
    CHECK(copy!=v && func_800B2344(copy)==2);
    for(int i=0;i<56;++i)CHECK(((u8 *)copy)[i]==((u8 *)v)[i]);
    s32 white[]={255,255,255},tint[]={128,64,256};
    func_800B2464(copy,white,v);CHECK(copy->vertices[0].v.cn[0]==200);
    func_800B2464(copy,tint,v);
    for(int i=0;i<2;++i)CHECK(copy->vertices[i].v.cn[0]==100 && copy->vertices[i].v.cn[1]==25 && copy->vertices[i].v.cn[2]==60 && copy->vertices[i].v.cn[3]==42+i);
    CHECK(v->vertices[0].v.cn[0]==200);
    u8 palette[512*4]={0};s32 color[]={128,64,255,255},decoded[4];
    _dbpalette_entrypoint_1(palette,0x123,color);
    CHECK(palette[0x123*4]==255 && palette[0x123*4+1]==255 && palette[0x123*4+2]==64 && palette[0x123*4+3]==128);
    _dbpalette_entrypoint_0(palette,0x123,decoded);
    for(int i=0;i<4;++i)CHECK(decoded[i]==color[i]);
    func_800B25D8(copy,v,palette);CHECK(copy->vertices[1].v.cn[0]==100 && copy->vertices[1].v.cn[1]==25 && copy->vertices[1].v.cn[2]==59 && copy->vertices[1].v.cn[3]==43);
    s32 flat[]={257,-1,17};func_800B2540(copy,flat);
    CHECK(copy->vertices[0].v.cn[0]==1 && copy->vertices[0].v.cn[1]==255 && copy->vertices[1].v.cn[2]==17 && copy->vertices[1].v.cn[3]==43);
    for(int i=0;i<2;++i)for(int j=0;j<12;++j)
        CHECK(((u8 *)&copy->vertices[i])[j]==((u8 *)&v->vertices[i])[j]);
    CHECK(copy->count_flags==v->count_flags);
    func_800B23E0(copy);copy=func_800B2400(v,0);func_800B23E0(copy);func_800B26C8();
    for(int i=20;i<=64;i+=4)((u32 *)model)[i/4]=0;
    for(int i=0;i<12;++i)CHECK(!accessors[i](model));
    v->count_flags=1;copy=func_800B2400(v,0);
    func_800B2324((u8 *)copy,&begin,&end);CHECK(begin==end);
    func_800B2540(copy,flat);func_800B25D8(copy,copy,NULL);func_800B23E0(copy);
}
static void test_invalid(void) {
    u64 a[32],b[32];u8 *bytes=(void *)a;
    for(int size=0;size<=136;++size) {
        make_model(bytes);
        for(int i=4;i<=64;i+=4)if(i!=16)put(bytes+i,0,4);
        rare_memcpy(b,a,sizeof(a));CHECK(native_model_decode(a,size)==(size==136));
        if(size<136)for(int i=0;i<32;++i)CHECK(a[i]==b[i]);
    }
    const u32 mutations[][3]={{0,12,4},{16,0,4},{16,81,4},{16,0xFFFFFFF0,4},
        {16,248,4},{102,0xFFFE,2},{20,64,4},{20,256,4},{20,104,4},
        {8,104,2},{8,0xFFFF,2},{44,240,4},{80,1000,2},{32,255,4},{160,255,1},{144,25,4},{148,4,4},{148,0xFFFFFFFC,4},{152,1,4},{4,152,4},{12,144,4},{136,9,4},{140,1,2},{8,137,2}};
    for(unsigned i=0;i<sizeof(mutations)/sizeof(*mutations);++i) {
        make_model(bytes);put(bytes+mutations[i][0],mutations[i][1],mutations[i][2]);
        rare_memcpy(b,a,sizeof(a));CHECK(!native_model_decode(a,sizeof(a)));
        for(int j=0;j<32;++j)CHECK(a[j]==b[j]);
    }
    CHECK(!native_model_decode(NULL,256));
    CHECK(!native_model_decode(bytes+1,255));
}
static void test_render_data(void) {
    u64 raw[18],saved[18];u8 *p=(void *)raw;
    rare_memset(p,0,sizeof(raw));put(p,11,4);put(p+4,128,4);put(p+12,104,4);put(p+16,80,4);
    put(p+104,2,4);put(p+112,0xDE000000,4);put(p+116,0x01002000,4);put(p+120,0xDF000000,4);
    put(p+128,3,4);put(p+136,1,2);rare_memcpy(saved,raw,sizeof(raw));
    for(int size=0;size<140;++size) {
        rare_memcpy(raw,saved,sizeof(raw));CHECK(!native_model_decode(raw,size));
        for(int i=0;i<18;++i)CHECK(raw[i]==saved[i]);
    }
    const u32 mutations[][3]={{104,3,4},{136,2,2},{132,4,4}};
    for(int i=0;i<3;++i) {
        rare_memcpy(raw,saved,sizeof(raw));put(p+mutations[i][0],mutations[i][1],mutations[i][2]);
        u64 before[18];rare_memcpy(before,raw,sizeof(raw));CHECK(!native_model_decode(raw,sizeof(raw)));
        for(int j=0;j<18;++j)CHECK(raw[j]==before[j]);
    }
    rare_memcpy(raw,saved,sizeof(raw));CHECK(native_model_decode(raw,140));
    CHECK(((u32 *)p)[1]==128 && *(u32 *)(p+104)==2 && *(u32 *)(p+128)==3 && *(s16 *)(p+136)==1);
    Gfx *commands=(void *)(p+112);CHECK(commands[0].words.w0==0xDE000000 && commands[0].words.w1==0x01002000 && commands[1].words.w0==0xDF000000);
}
static void test_archive(const char *path) {
    int models=0;unsigned vertices=0;CHECK(native_assets_open(path));
    for(int id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=0 || native_asset_packed_size(id)<=0)continue;
        void *model=func_800D674C(id);CHECK(model);
        NativeVertexList *v=func_800B2840(model);s32 a[3],b[3];
        func_800B2198(v,a,b);
        for(int i=0;i<3;++i)CHECK(a[i]<=b[i]);
        vertices+=func_800B2344(v);++models;
        func_800D62E4(id);func_800D6CEC(id);func_800D5E74();func_800D5E74();
    }
    CHECK(models>0);printf("Decoded %d original models and %u vertices through the game cache.\n",models,vertices);
    native_assets_close();
}
int main(int argc,char **argv) {
    test_vertices();test_invalid();test_render_data();if(argc==2)test_archive(argv[1]);
    puts("Native model sections, vertex bounds, copies, colors and validation passed.");return 0;
}
