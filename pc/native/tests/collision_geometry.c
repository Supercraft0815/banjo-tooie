#include "native_collision_geometry.h"
#include "native_map_runtime.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "core1/mlmtx.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
static int frame=100,map_level;
s32 func_800EA05C(void) {return map_level;}
s32 func_8001211C(void) {return frame;}
void func_80019224(f32 *,f32 *),func_80019750(f32 *,f32 *,f32,f32 *),func_8001980C(f32 *,f32 *,f32,f32 *);
static void put(u8 *p,u32 value,int width) {for(int i=0;i<width;++i)p[i]=value>>((width-i-1)*8);}
static u8 *make_model(int triangles,int *size) {
    *size=228+12*triangles;u8 *bytes=heap_alloc(*size);rare_memset(bytes,0,*size);
    put(bytes,11,4);put(bytes+16,80,4);put(bytes+28,200,4);
    s16 bounds[12]={-100,0,-100,100,10,100,0,5,0,200,200,12};
    for(int i=0;i<12;++i)put(bytes+80+2*i,bounds[i],2);
    for(int i=0;i<6;++i) {
        put(bytes+104+16*i,i%3==2 ? 100 : -100,2);put(bytes+106+16*i,i>=3 ? 10 : 0,2);
        put(bytes+108+16*i,i%3==1 ? 100 : -100,2);
        for(int j=0;j<4;++j)bytes[116+16*i+j]=40*i+j;
    }
    put(bytes+216,1,2);put(bytes+220,triangles,2);put(bytes+226,triangles,2);
    for(int i=0;i<triangles;++i) {
        for(int j=0;j<3;++j)put(bytes+228+12*i+2*j,(i%2)*3+j,2);
        put(bytes+236+12*i,i%2 ? 4 : 0,4);
    }
    return bytes;
}
static void test_decoder(void) {
    int size;u8 *raw=make_model(2,&size),*copy=heap_alloc(size);
    for(int n=0;n<size;++n){rare_memcpy(copy,raw,size);CHECK(!native_model_decode(copy,n));for(int i=0;i<size;++i)CHECK(copy[i]==raw[i]);}
    int fields[]={216,220,224,226,228,212,218,204};u32 values[]={0,65535,3,3,6,2,0xFFFF,1};
    for(int i=0;i<8;++i){rare_memcpy(copy,raw,size);put(copy+fields[i],values[i],2);if(i==5 || i==7)put(copy+218,100,2);CHECK(!native_model_decode(copy,size));}
    rare_memcpy(copy,raw,size);put(copy+32,200,4);CHECK(!native_model_decode(copy,size));
    rare_memcpy(copy,raw,size);put(copy+8,208,2);CHECK(!native_model_decode(copy,size));
    rare_memcpy(copy,raw,size);CHECK(native_model_decode(copy,size));
    NativeCollisionMesh *mesh=(void *)(copy+200);CHECK(mesh->cell_count==1 && mesh->triangle_count==2 && mesh->cells[0].count==2);
    NativeCollisionTriangle *tri=(void *)(mesh->cells+1);CHECK(tri[1].vertices[0]==3 && tri[1].flags==4);
    CHECK(func_800AADE4((u16 *)mesh)==2 && !func_800AAD80((u16 *)mesh));tri[1].flags=0x20020;CHECK(func_800AAD80((u16 *)mesh)==1);
    heap_free(copy);heap_free(raw);
}
static void test_matrix(void) {
    f32 translation[3]={10,20,30},rotation[3]={20,90,-15},point[3]={1,2,3},world[3],local[3];
    mlMtxIdent();func_80019750(translation,rotation,2,NULL);func_80019224(world,point);
    mlMtxIdent();func_8001980C(translation,rotation,2,NULL);func_80019224(local,world);
    for(int i=0;i<3;++i)CHECK(fabsf(local[i]-point[i])<0.00001f);
    mlMtxIdent();mlMtxTranslate(10,20,30);mlMtx_push_duplicate();mlMtxScale_xyz(2,3,4);func_80019224(local,point);
    CHECK(local[0]==12 && local[1]==26 && local[2]==42);mlMtxPop();func_80019224(local,point);CHECK(local[0]==11 && local[1]==22 && local[2]==33);
    MtxF saved;mlMtxGet(&saved);mlMtxIdent();mlMtxSet(&saved);func_80019224(local,point);CHECK(local[1]==22);
}
static void test_queries(void) {
    int size;u8 *model=make_model(70,&size);CHECK(native_model_decode(model,size));
    u16 *mesh=(void *)func_800B2720(model),*vertices=func_800B2840(model);
    NativeCollisionTriangle *tri=(void *)((u8 *)mesh+28);
    f32 a[3]={-25,20,-25},b[3]={-25,-20,-25},normal[3]={0},positions[9];u8 colors[12];
    CHECK(func_800AB0BC(mesh,vertices,a,b,normal,0)==tri+1 && b[1]==10 && normal[1]==1);
    func_800AAD28(positions);func_800AAAE0(colors);CHECK(positions[1]==10 && colors[0]==120 && colors[11]==203);
    b[1]=-20;CHECK(func_800AB0BC(mesh,vertices,a,b,normal,4)==tri && b[1]==0);
    a[1]=-5;b[1]=5;CHECK(!func_800AB0BC(mesh,vertices,a,b,normal,0));
    tri[0].flags=0x10000;CHECK(func_800AB0BC(mesh,vertices,a,b,normal,0)==tri && b[1]==0 && normal[1]==-1);tri[0].flags=0;
    a[0]=b[0]=150;a[1]=20;b[1]=-20;CHECK(!func_800AB0BC(mesh,vertices,a,b,normal,0));a[0]=b[0]=-25;
    f32 point[3]={-25,1,-25};CHECK(func_800AC978(mesh,vertices,point,2,normal,4) && normal[1]==1);
    point[1]=2;CHECK(!func_800AC978(mesh,vertices,point,2,normal,4));point[1]=1;
    point[0]=point[2]=1;CHECK(func_800AC978(mesh,vertices,point,2,normal,4) && normal[1]==1);
    point[0]=point[2]=-101;CHECK(func_800AC978(mesh,vertices,point,2,normal,4) && normal[1]==1);
    point[0]=point[2]=-102;CHECK(!func_800AC978(mesh,vertices,point,2,normal,4));
    func_800AB980();a[1]=5;b[1]=1;
    CHECK(func_800AC638(mesh,vertices,a,b,2,normal,8,4) && b[1]>=1.5f && b[1]<1.52f && normal[1]==1);
    func_800ABA20();frame=141;func_800ABA9C();a[1]=5;b[1]=1;CHECK(func_800AC638(mesh,vertices,a,b,2,normal,8,4));
    func_800AB980();a[1]=5;b[1]=4;CHECK(!func_800AC638(mesh,vertices,a,b,2,normal,8,4));
    f32 translation[3]={1000,100,2000},world_a[3]={950,140,1950},world_b[3]={950,60,1950};
    CHECK(func_800AB868(mesh,vertices,translation,NULL,2,world_a,world_b,normal,0)==tri+1 && world_b[1]==120 && normal[1]==1);
    func_800AAD28(positions);CHECK(positions[0]==800 && positions[1]==120 && positions[2]==1800);
    f32 rotation[3]={20,60,-15},local_a[3]={-25,20,-25},local_b[3]={-25,-20,-25},expected[3]={-25,10,-25};
    mlMtxIdent();func_80019750(translation,rotation,2,NULL);
    func_80019224(world_a,local_a);func_80019224(world_b,local_b);func_80019224(expected,expected);
    CHECK(func_800AB868(mesh,vertices,translation,rotation,2,world_a,world_b,normal,0));
    for(int i=0;i<3;++i)CHECK(fabsf(world_b[i]-expected[i])<0.001f);
    world_a[0]=world_b[0]=950;world_a[2]=world_b[2]=1950;
    f32 world_point[3]={950,102,1950};CHECK(func_800AD1AC(mesh,vertices,translation,NULL,2,world_point,4,normal,4) && normal[1]==1);
    world_a[1]=110;world_b[1]=102;CHECK(func_800AC848(mesh,vertices,translation,NULL,2,world_a,world_b,4,normal,8,4) && world_b[1]>=103 && world_b[1]<103.04f);
    f32 minimum[3]={-100,-1,-100},maximum[3]={100,11,100},origin[3]={0};s16 output[6][3],(*cursor)[3]=output;
    CHECK(func_800AD2C8(mesh,vertices,minimum,maximum,origin,&cursor,2,0.9f)==2 && cursor==output+6);
    CHECK(output[0][1]==0 && output[3][1]==10);
    f32 edge_a[3]={-100,0,100},edge_b[3]={-100,0,-100},direction[3]={0,-1,0};
    CHECK(!func_800AD894(mesh,vertices,edge_a,edge_b,direction,origin,0.9f));edge_a[0]=400;edge_b[0]=400;
    CHECK(func_800AD894(mesh,vertices,edge_a,edge_b,direction,origin,0.9f));
    f32 p[3]={0},q[3]={10,0,0},r[3]={5,1,0};CHECK(func_800AADEC(p,q,r,2) && !func_800AADEC(p,q,r,0.5f));CHECK(func_800AAEF4(r,2,p,q));
    func_800AB9D0();func_800AB9D0();heap_free(model);
}
static void test_grid(void) {
    NativeCollisionMesh *mesh=heap_alloc(sizeof(*mesh)+125*sizeof(NativeCollisionCell));
    *mesh=(NativeCollisionMesh){.minimum={-2,-2,-2},.maximum={2,2,2},.y_stride=5,.z_stride=25,.cell_count=125,.scale=100};
    f32 a[3]={-100,-100,-100},b[3]={0,0,0};void **begin,**end;s32 point[3];
    func_800AA2A0((s16 *)mesh,point,a);CHECK(point[0]==-2 && point[1]==-2 && point[2]==-2);
    func_800AA4D4(mesh,a,b,&begin,&end);CHECK(end-begin==27 && begin[0]==mesh->cells && begin[26]==mesh->cells+62);
    s32 lower[3]={-999,-999,-999},upper[3]={999,999,999};func_800AA7FC(mesh,lower,upper,&begin,&end);CHECK(end-begin==100);
    mesh->scale=0;func_800AA4D4(mesh,a,b,&begin,&end);CHECK(end-begin==1 && begin[0]==mesh->cells);heap_free(mesh);
}
static void test_archive(const char *path) {
    CHECK(native_assets_open(path));int models=0,triangles=0,queries=0,hits=0;
    func_800AB980();
    for(int id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=0 || native_asset_packed_size(id)<=0)continue;
        void *model=func_800D674C(id);if(!model)fprintf(stderr,"Collision model load failed: %x\n",id);CHECK(model);
        NativeCollisionMesh *mesh=(void *)func_800B2720(model);NativeVertexList *v=func_800B2840(model);
        if(mesh) {
            ++models;triangles+=mesh->triangle_count;NativeCollisionTriangle *tri=(void *)(mesh->cells+mesh->cell_count);
            for(int i=0,samples=0;i<mesh->triangle_count && samples<3;++i) {
                f32 center[3],ab[3],ac[3],normal[3],a[3],b[3];
                for(int j=0;j<3;++j) {
                    s16 x=v->vertices[tri[i].vertices[0]].v.ob[j],y=v->vertices[tri[i].vertices[1]].v.ob[j],z=v->vertices[tri[i].vertices[2]].v.ob[j];
                    center[j]=(x+y+z)/3.0f;ab[j]=y-x;ac[j]=z-x;
                }
                for(int j=0;j<3;++j)normal[j]=ab[(j+1)%3]*ac[(j+2)%3]-ab[(j+2)%3]*ac[(j+1)%3];
                f32 length=sqrtf(normal[0]*normal[0]+normal[1]*normal[1]+normal[2]*normal[2]);if(length<1)continue;
                for(int j=0;j<3;++j){normal[j]/=length;a[j]=center[j]+normal[j]*10;b[j]=center[j]-normal[j]*10;}
                NativeCollisionTriangle *hit=func_800AB0BC((u16 *)mesh,(u16 *)v,a,b,normal,0);++queries;++samples;
                if(hit){++hits;CHECK(hit>=tri && hit<tri+mesh->triangle_count);for(int j=0;j<3;++j)CHECK(isfinite(normal[j]) && isfinite(b[j]));}
                for(int j=0;j<3;++j){a[j]=center[j];b[j]=center[j];}
                func_800AC978((u16 *)mesh,(u16 *)v,a,5,normal,0);func_800AC638(mesh,v,a,b,5,normal,4,0);
            }
        }
        func_800D6CEC(id);func_800D5E74();func_800D5E74();
    }
    func_800AB9D0();native_assets_close();CHECK(models==546 && triangles==653004 && queries>0 && hits==queries);
    printf("Queried %d original collision meshes (%d triangles): %d/%d sampled rays hit.\n",models,triangles,hits,queries);
}
static void test_map_integration(const char *path) {
    CHECK(native_assets_open(path));func_800AB980();int maps=0,hits=0;
    for(const NativeMapConfig *config=native_map_configs;config->id;++config) {
        map_level=config->id;func_800C6A68();
        int loaded=func_800BF444();if(!loaded)fprintf(stderr,"Map collision integration load failed: %x\n",map_level);
        CHECK(loaded && native_map.config.id==map_level && native_map.vectors);
        f32 a[3],b[3],normal[3]={0};
        for(int i=0;i<3;++i)a[i]=b[i]=(native_map.combined_minimum[i]+native_map.combined_maximum[i])*0.5f;
        a[1]=native_map.combined_maximum[1]+100;b[1]=native_map.combined_minimum[1]-100;
        if(func_800C6A7C(a,b,normal,0)) {
            ++hits;for(int i=0;i<3;++i)CHECK(isfinite(b[i]) && isfinite(normal[i]));
            func_800C6C94(b,20,normal,0);
            for(int i=0;i<3;++i)a[i]=b[i];a[1]+=30;b[1]-=1;
            func_800C6B78(a,b,20,normal,8,0);
            for(int i=0;i<3;++i)CHECK(isfinite(b[i]) && isfinite(normal[i]));
        }
        func_800BF710();func_800BF420();func_800C6A68();func_800D5E74();func_800D5E74();++maps;
    }
    func_800AB9D0();native_assets_close();CHECK(maps==228 && hits>0);
    printf("Native map runtime/dispatcher queried all %d configured maps; %d center rays hit geometry.\n",maps,hits);
}
int main(int argc,char **argv) {
    test_decoder();test_matrix();test_grid();test_queries();if(argc==2){test_archive(argv[1]);test_map_integration(argv[1]);}
    puts("Native collision geometry: decoding, line/sphere/sweep queries, transforms and cache growth passed.");return 0;
}
