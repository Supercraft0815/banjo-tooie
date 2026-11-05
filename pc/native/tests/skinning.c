#include "native_skinning.h"
#include "native_vertex_cache.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "memory.h"
#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
s32 func_8001211C(void) {return 100;}
static void put(u8 *p,u32 value,int width) {for(int i=0;i<width;++i)p[i]=value>>((width-i-1)*8);}
static void identity(MtxF *m) {for(int i=0;i<4;++i)for(int j=0;j<4;++j)m->m[i][j]=i==j;}
static void make_model(u8 *model) {
    rare_memset(model,0,224);put(model,11,4);put(model+16,80,4);put(model+24,152,4);put(model+40,176,4);put(model+102,6,2);
    for(int i=0;i<3;++i)for(int j=0;j<16;++j)model[104+i*16+j]=0xAA;
    put(model+152,0x3F800000,4);put(model+156,1,2);put(model+174,0xFFFF,2);
    s16 binding[]={1,1,0,2,3,1,2,3,-4,5,-6};
    for(unsigned i=0;i<sizeof(binding)/2;++i)put(model+176+i*2,(u16)binding[i],2);
    const u8 normals[]={127,0,0,17,0,127,0,18,0,0,129,19};rare_memcpy(model+198,(void *)normals,12);
    s16 indices[]={0,1,-1,2,-2};for(int i=0;i<5;++i)put(model+210+i*2,(u16)indices[i],2);
}
static void test_validation(void) {
    u64 raw[28],saved[28];u8 *bytes=(void *)raw;
    for(int size=0;size<220;++size) {
        make_model(bytes);rare_memcpy(saved,raw,sizeof(raw));CHECK(!native_model_decode(raw,size));
        for(int i=0;i<28;++i)CHECK(raw[i]==saved[i]);
    }
    const u32 changes[][3]={{40,177,4},{178,0xFFFF,2},{180,1,2},{180,0xFFFE,2},{182,0xFFFF,2},{184,0xFFFF,2},
        {182,100,2},{184,1,2},{210,3,2},{218,0,2},{210,0xFFFF,2},{212,0xFFFF,2},{156,0xFFFF,2},{24,216,4},{44,218,4},
        {24,153,4},{152,0x7FC00000,4},{160,0x7F800000,4},{172,109,2},{172,0xFFFF,2},{174,0,2},{174,0xFFFE,2}};
    for(unsigned i=0;i<sizeof(changes)/sizeof(*changes);++i) {
        make_model(bytes);put(bytes+changes[i][0],changes[i][1],changes[i][2]);rare_memcpy(saved,raw,sizeof(raw));
        CHECK(!native_model_decode(raw,220));for(int j=0;j<28;++j)CHECK(raw[j]==saved[j]);
    }
    make_model(bytes);CHECK(native_model_decode(raw,220));
    NativeSkeleton *skeleton=(NativeSkeleton *)(bytes+152);CHECK(skeleton->translation_scale==1 && skeleton->count==1 && skeleton->bones[0].parent==-1);
    CHECK(((s16 *)(bytes+176))[1]==1 && ((s16 *)(bytes+176))[8]==-4 && bytes[198]==127 && bytes[206]==0 && bytes[208]==129);
}
static void test_transforms(void) {
    MtxF matrix;identity(&matrix);s16 in[]={0,0,0,1,1,1,-1,-1,-1},out[9];
    matrix.m[3][0]=0.5f;matrix.m[3][1]=1.5f;matrix.m[3][2]=-0.5f;
    func_80116568(&matrix,in,out,3);s16 expected[]={0,2,0,2,2,0,0,0,-2};
    for(int i=0;i<9;++i)CHECK(out[i]==expected[i]);
    int mode=fegetround();CHECK(!fesetround(FE_UPWARD));func_80116568(&matrix,in,out,3);CHECK(!fesetround(mode));
    for(int i=0;i<9;++i)CHECK(out[i]==expected[i]);
    matrix.m[3][0]=32768;matrix.m[3][1]=NAN;matrix.m[3][2]=INFINITY;func_80116568(&matrix,in,out,1);
    CHECK(out[0]==-32768 && !out[1] && !out[2]);out[0]=123;func_80116568(&matrix,in,out,0);CHECK(out[0]==123);
    identity(&matrix);matrix.m[0][1]=2;matrix.m[3][0]=900;s8 normals[]={127,0,0,22,0,-127,0,23};f32 transformed[6];
    func_801163B0(normals,&matrix,transformed,2);CHECK(transformed[0]==1 && transformed[1]==2 && !transformed[2] && !transformed[3] && transformed[4]==-1);
}
static void test_bindings(void) {
    u64 raw[28];u8 *model=(void *)raw;make_model(model);CHECK(native_model_decode(model,220));
    NativeBoneMatrices *list=heap_alloc(sizeof(*list)+sizeof(MtxF));rare_memset(list,0,sizeof(*list)+sizeof(MtxF));
    list->count=list->capacity=1;identity(&list->base);identity(list->matrices);
    CHECK(func_800ADE2C(list,-1)==&list->base && func_800ADE2C(list,0)==list->matrices && !func_800ADE2C(list,1) && !func_800ADE2C(list,-2) && !func_800ADE2C(NULL,0));
    for(int i=0;i<3;++i){list->matrices[0].m[i][i]=i+2;list->matrices[0].m[3][i]=10*(i+1);}
    NativeVertexList *vertices=func_800B2840(model);u8 normals[12];rare_memset(normals,0xEE,sizeof(normals));
    _dbanim_entrypoint_0(model+176,vertices,list);s16 expected[3][3]={{12,26,42},{12,26,42},{2,35,6}};
    for(int i=0;i<3;++i)for(int j=0;j<3;++j)CHECK(vertices->vertices[i].v.ob[j]==expected[i][j]);
    _dbanim_entrypoint_1(model+176,vertices,list,normals);
    CHECK(normals[0]==254 && !normals[1] && !normals[2] && normals[5]==125 && normals[10]==4);
    for(int i=0;i<3;++i){CHECK(normals[i*4+3]==0xEE);for(int j=6;j<16;++j)CHECK(((u8 *)&vertices->vertices[i])[j]==0xAA);}
    ((s16 *)(model+176))[2]=-1;_dbanim_entrypoint_0(model+176,vertices,list);CHECK(vertices->vertices[0].v.ob[0]==1 && vertices->vertices[2].v.ob[0]==-4);
    heap_free(list);func_80100610();
}
static void test_archive(const char *path) {
    CHECK(native_assets_open(path));int models=0,groups=0,references=0;
    for(int id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=0 || native_asset_packed_size(id)<=0)continue;
        u8 *model=(void *)func_800D674C(id);CHECK(model);u8 *binding=func_800B26F0(model);
        if(binding) {
            NativeSkeleton *skeleton=(NativeSkeleton *)func_800B27E0(model);int count=skeleton ? skeleton->count : 0;
            NativeBoneMatrices *list=heap_alloc(sizeof(*list)+count*sizeof(MtxF));list->count=list->capacity=count;identity(&list->base);
            for(int i=0;i<count;++i)identity(list->matrices+i);
            NativeVertexList *vertices=func_800B2840(model),*expected=func_800B2400(vertices,0);s16 *entry=(s16 *)(binding+4);
            for(int i=0;i<((s16 *)binding)[1];++i) {
                s16 *position=entry+3,*index=position+entry[1]*3;if(*(s16 *)binding)index+=entry[2]*2;
                while(*index>=-1) {
                    if(*index==-1)position+=3;
                    else {for(int axis=0;axis<3;++axis)expected->vertices[*index].v.ob[axis]=position[axis];++references;}
                    ++index;
                }
                entry=index+1;++groups;
            }
            _dbanim_entrypoint_0(binding,vertices,list);
            for(u32 i=0;i<func_800B2344(vertices)*16;++i)CHECK(((u8 *)vertices->vertices)[i]==((u8 *)expected->vertices)[i]);
            if(*(s16 *)binding) {
                u32 size=func_800B2344(vertices)*4;u8 *normals=heap_alloc(size);rare_memset(normals,0xCD,size);
                _dbanim_entrypoint_1(binding,vertices,list,normals);for(u32 i=3;i<size;i+=4)CHECK(normals[i]==0xCD);heap_free(normals);
            }
            func_800B23E0(expected);heap_free(list);++models;
        }
        func_800D62E4(id);func_800D6CEC(id);func_800D5E74();func_800D5E74();
    }
    CHECK(models>0);func_80100610();native_assets_shutdown();
    printf("Native skinning: %d original bindings, %d groups, %d vertex references verified.\n",models,groups,references);
}
int main(int argc,char **argv) {
    if(argc==2)test_archive(argv[1]);else {CHECK(argc==1);test_validation();test_transforms();test_bindings();}
    puts("native skinning checks passed");return 0;
}
