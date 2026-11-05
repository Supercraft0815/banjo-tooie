#include "native_cube.h"
#include "native_world_collision.h"
#include "native_actor.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "native_camera_db.h"
#include "native_lights.h"
#include "native_world_load.h"
#include "native_map.h"
#include "native_fog.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1); } } while(0)

/* Actor animation/deformation and effect creation remain observed boundaries. */
static s32 lower[3]={-1,0,-1},upper[3]={1,1,1},level=0x123,cell_size=1000;
static int real_geometry;
static int finishes,collections,actors,stage,effects[3],special,reset_calls;
static s32 actor_ids[700];
static Actor actor;
void func_8001A2B0(void) { }
void func_800E3A58(f32 *v) {v[0]=v[1]=v[2]=0;}
void func_80103328(Actor *actor) { CHECK(0); }
void func_80103508(Actor *actor) { CHECK(0); }
void *func_80103AA0(Unk80132ED0 *marker) { CHECK(0);return NULL; }
void *func_80103CDC(Actor *actor,void *model) { CHECK(0);return NULL; }
void *func_801039E4(void *marker) { CHECK(0);return NULL; }
void func_800EA400(s32 context,Unk80132ED0 *marker,f32 *point,void *hit) { CHECK(0); }
void func_800CE2DC(void) { }
void func_800CE308(void) { ++finishes; }
s32 func_800EA05C(void) { return level; }
void func_800EA370(void) { ++reset_calls; }
s32 func_800DC214(s32 a,s32 b) { CHECK(a==0 && b==32);return 17; }
f32 func_800DC0C0(void) { return 0.25f; }
s32 func_8001211C(void) { return 100; }
u32 func_800E6A00(void) { return 0; }
void _gccollectDll_entrypoint_8(NativeWorldCell *cell) {
    CHECK(cell==native_world_grid.cells+collections);++collections;
}
void func_800CBA20(void) { CHECK(stage==0);stage=1; }
void func_800CB9FC(void) { CHECK(stage==1);stage=2; }
void func_800CBA44(void) { CHECK(stage==2);stage=3; }
void func_800CBA68(s32 id,Prop *p,s32 size,s32 duration,s32 link,s32 flag,s32 pass) {
    CHECK(id==70+pass && p->ItemID==id && stage==pass && size==15 && duration==300 && link==9 && flag==1);++effects[0];
}
void func_800CBAC8(s32 id,Prop *p,s32 size,s32 flag,s32 duration) {
    CHECK(id==90 && p->ItemID==id && stage==0 && size==4 && duration==35 && flag==2);++effects[1];
}
void func_800CBB18(s32 id,Prop *p,s32 size,s32 duration,s32 flag,s32 other) {
    CHECK(id==120 && p->ItemID==id && stage==0 && size==25 && duration==300 && flag==3 && other==1);++effects[2];
}
static s32 expected_node;
static ActorData metadata;
static ActorData *factory(void) { return &metadata; }
NativeActorFactory _gemarkersDll_entrypoint_0(s32 id) { return factory; }
void *_gccubesearch_entrypoint_17(s32 id,void *unused) { CHECK(id==expected_node && !unused);return NULL; }
void _gspropctrl_entrypoint_9(void *node,s32 *position) { CHECK(0); }
static Actor *spawn_fixture(s32 *position,s32 yaw,ActorData *data,NativeActorFactory entry,Prop *prop) {
    CHECK(actors<700 && prop && data==&metadata && entry==factory);
    for(int i=0;i<3;++i) CHECK(position[i]==prop->position[i]);
    expected_node=prop->unk10>>5;
    if(special) CHECK(yaw==77 && expected_node==17 && ((((u32)prop->unk10<<16)|prop->unk12)>>10&0x7FF)==29);
    actor_ids[actors++]=prop->ItemID;
    return &actor;
}
static void setup(void) {
    func_800C6A68();
    cell_size=gcmapDll_entrypoint_5();
    if(!real_geometry)for(int i=0;i<3;++i) {
        native_map.minimum[i]=lower[i]*cell_size+(lower[i]<0);
        native_map.maximum[i]=upper[i]*cell_size+(upper[i]<0);
        native_map.config.padding[i]=native_map.config.padding[i+3]=0;
    }
    native_world_grid=(NativeWorldGrid){0};
    func_800E9728();func_800EBB5C();func_800EBB94();func_800BD570();
    f32 a[3]={0},b[3]={1,2,3},normal[3];
    CHECK(!func_800C6A7C(a,b,normal,0x123));
    CHECK(native_world_grid.count>0 && reset_calls>0);
    for(int i=0;i<native_world_grid.count;++i) {
        NativeWorldCell *cell=native_world_grid.cells+i;
        CHECK(!cell->models[0] && !cell->models[1] && !cell->dynamic[0] && !cell->dynamic[1]);
        CHECK(!native_world_grid.model_counts[i]);
    }
}
static void cleanup(void) {
    func_800D2E4C();func_800D2970();
    func_800BD5DC();CHECK(!native_world_grid.cells && !native_world_grid.model_counts && !native_world_grid.count);
    func_800E9774();func_800C6A68();
}
static void put(GsFile *file,u32 value,int width) {
    u8 bytes[4];for(int i=0;i<width;++i) bytes[i]=value>>((width-i-1)*8);
    gsmaker_entrypoint_13(file,bytes,width);
}
static void record(GsFile *file,int type,int id,int x,u32 extra) {
    put(file,x,2);put(file,100,2);put(file,100,2);put(file,(50<<7)|(type<<1),2);
    put(file,id,2);put(file,0x1234,2);put(file,(77u<<23)|250,4);put(file,extra,4);
}
static GsFile *reader(GsFile *writer,void **buffer) {
    s32 size;gsmaker_entrypoint_6(writer,buffer,&size);return gsmaker_entrypoint_4(*buffer,size);
}
static void test_flat(void) {
    void *buffer;GsFile *w=gsmaker_entrypoint_5(),*r;
    put(w,10,1);put(w,4,4);
    record(w,6,42,100,(17u<<21)|(29<<10));record(w,2,3,100,0);
    record(w,6,41,1100,0);record(w,1,4,100,0);
    put(w,8,1);put(w,2,4);
    put(w,0x12345678,4);put(w,100,2);put(w,100,2);put(w,100,2);put(w,0x22,2);
    put(w,0x87654321,4);put(w,5000,2);put(w,100,2);put(w,100,2);put(w,0x20,2);
    put(w,1,1);r=reader(w,&buffer);int before=finishes;
    func_800BDC90(r);CHECK(!r->failed && r->current_ptr==r->end_ptr && finishes==before+1);
    s32 position[3]={100,100,100};NativeWorldCell *cell=func_800BDBC4(position);
    CHECK(cell->models[1]==3 && *func_800BE5C4(cell)==2);
    Prop *p=func_800E9D68(cell);CHECK(p[0].ItemID==3 && p[1].ItemID==4 && p[2].ItemID==42);
    CHECK(p[2].position[0]==100 && p[2].unkA==0x1234 && p[2].FlagOrRotation==77 && (p[2].unk12&0x100));
    CHECK(gspropmarker_entrypoint_3(p+2)==2.5f && gspropmarker_entrypoint_0(cell,42)==p+2);
    s32 ids[]={42,42,-1};Prop *found[2]={0};f32 positions[2][3]={{0}};
    CHECK(gspropmarker_entrypoint_1(cell,ids,found,2)==1 && found[0]==p+2 && !found[1]);
    CHECK(gspropmarker_entrypoint_2(cell,42,positions,1)==1 && positions[0][0]==100 && positions[0][1]==100);
    CHECK(!gspropmarker_entrypoint_0(NULL,42) && !gspropmarker_entrypoint_1(cell,ids,NULL,0));
    CHECK(!gspropmarker_entrypoint_2(cell,42,NULL,-1));
    p[2].unk12&=~0x100;CHECK(!gspropmarker_entrypoint_0(cell,42));p[2].flags6|=1;CHECK(gspropmarker_entrypoint_0(cell,42)==p+2);
    NativeMarkerProp *sprite=func_800E9E88(cell);
    CHECK(sprite->sprite==0x12345678 && sprite->position[0]==100 && sprite->flags==0x12);
    sprite=func_800E9E88(func_800BDC44());CHECK(sprite->sprite==0x87654321 && sprite->position[0]==5000 && sprite->flags==0x30);
    CHECK(gccubeDll_entrypoint_7()==17);
    actors=0;func_800BDCB8();CHECK(actors==2 && actor_ids[0]==41 && actor_ids[1]==42);
    CHECK(actor.unk74_7==50 && actor.unk7A_5 && actor.scale==2.5f);
    Prop *one=p+2;actors=0;special=1;gspropsDll_entrypoint_1(&one,1);CHECK(actors==1);special=0;
    collections=0;func_800BDCDC();CHECK(collections==native_world_grid.count);
    gsmaker_entrypoint_0(r);heap_free(buffer);
}
static void test_legacy(void) {
    void *buffer;GsFile *w=gsmaker_entrypoint_5(),*r;
    put(w,1,1);for(int i=0;i<6;++i) put(w,0,4);
    put(w,0,1);for(int i=0;i<6;++i) put(w,i-3,4);
    put(w,2,1);for(int i=0;i<3;++i) put(w,i,4);
    put(w,3,1);put(w,10,1);put(w,1,1);put(w,11,1);record(w,6,55,-500,0);
    put(w,8,1);put(w,0,1);put(w,9,1);put(w,1,1);put(w,0,1);
    r=reader(w,&buffer);int before=finishes;func_800BDC68(r);
    CHECK(!r->failed && r->current_ptr==r->end_ptr && finishes==before+1);
    s32 pos[3]={-500,100,100};CHECK(func_800E9D68(func_800BDBC4(pos))->ItemID==55);
    gsmaker_entrypoint_0(r);heap_free(buffer);
    u8 skipped[]={10,0,11,8,0,9,1};r=gsmaker_entrypoint_4(skipped,sizeof(skipped));
    func_808003A0_gccubeDll(r,1);CHECK(r->failed);gsmaker_entrypoint_0(r); /* Missing block tag 3. */
    r=gsmaker_entrypoint_4(skipped,sizeof(skipped));CHECK(func_808000B8_gccubeDll(r,1));
    CHECK(gsmaker_entrypoint_16(r,1));gsmaker_entrypoint_0(r);
    u8 empty[]={10,0,8,0,1};r=gsmaker_entrypoint_4(empty,sizeof(empty));
    CHECK(func_808000B8_gccubeDll(r,0) && gsmaker_entrypoint_16(r,1) && !r->failed);
    gsmaker_entrypoint_0(r);
}
static void test_effects(void) {
    s32 pos[3]={500,100,500};NativeWorldCell *cell=func_800BDBC4(pos);
    const int types[]={7,7,9,12},ids[]={70,71,90,120};
    const u32 flags[]={(9u<<21)|0x220,(9u<<21)|0x260,2,0x223};
    for(int i=0;i<4;++i) {
        Prop p={.position={500,100,500},.flags6=((i<2 ? 3 : i==2 ? 4 : 5)<<7)|(types[i]<<1),.ItemID=ids[i],
            .flagsC=i==2 ? 7u<<23 : 0,.unk10=flags[i]>>16,.unk12=flags[i]};
        gspropsDll_entrypoint_3(&p);
    }
    stage=0;func_800BDD00();CHECK(stage==3 && effects[0]==2 && effects[1]==1 && effects[2]==1);
    CHECK(cell->models[1]>=4);
}
static void test_large_collection(void) {
    s32 pos[3]={100,100,100};NativeWorldCell *cell=func_800BDBC4(pos);
    for(int i=0;i<600;++i) {
        Prop *p=func_800E9A24(cell);*p=(Prop){.position={100,100,100},.flags6=6<<1,.ItemID=600-i};
    }
    actors=0;func_800BDCB8();CHECK(actors==600);
    for(int i=0;i<600;++i) CHECK(actor_ids[i]==i+1);
}
static void test_malformed(void) {
    const u8 bad[][9]={{10,0xFF,0xFF,0xFF,0xFF},{10,0x7F,0xFF,0xFF,0xFF},{10,0,0,0,1},{99},{8,0,0,0,1}};
    for(int i=0;i<5;++i) {
        GsFile *r=gsmaker_entrypoint_4((void *)bad[i],sizeof(bad[i]));int before=finishes;
        func_800BDC90(r);CHECK(r->failed && finishes==before);gsmaker_entrypoint_0(r);
    }
    u8 unknown[]={99},short_header[]={1,0};
    GsFile *r=gsmaker_entrypoint_4(unknown,sizeof(unknown));func_808003A0_gccubeDll(r,0);CHECK(r->failed);gsmaker_entrypoint_0(r);
    r=gsmaker_entrypoint_4(short_header,sizeof(short_header));func_800BDC68(r);CHECK(r->failed);gsmaker_entrypoint_0(r);
    void *buffer;GsFile *w=gsmaker_entrypoint_5();
    put(w,8,1);put(w,1,4);for(int i=0;i<10;++i) put(w,0,1);put(w,1,2);put(w,1,1);
    r=reader(w,&buffer);func_800BDC90(r);CHECK(r->failed);gsmaker_entrypoint_0(r);heap_free(buffer);
    s32 pos[3]={100,100,100};NativeWorldCell *cell=func_800BDBC4(pos);
    for(int i=0;i<255;++i) { Prop p={.position={100,100,100},.flags6=2<<1};gspropsDll_entrypoint_3(&p); }
    CHECK(*func_800BE5C4(cell)==255);
    w=gsmaker_entrypoint_5();put(w,10,1);put(w,1,4);record(w,2,7,100,0);put(w,1,1);
    r=reader(w,&buffer);func_800BDC90(r);CHECK(r->failed && cell->models[1]==255);
    gsmaker_entrypoint_0(r);heap_free(buffer);
}
static void check_layers(void) {
    func_800D298C();func_800D2CD0();
    s16 *counts=heap_alloc(native_world_grid.dimensions[1]*sizeof(*counts));
    rare_memset(counts,0,native_world_grid.dimensions[1]*sizeof(*counts));
    for(int i=0;i<native_world_grid.count;++i)counts[(i/native_world_grid.row_stride)%native_world_grid.dimensions[1]]+=native_world_grid.cells[i].models[1];
    for(int y=0;y<native_world_grid.dimensions[1];++y)CHECK(func_800D2E90(y)==(counts[y]!=0));
    CHECK(!func_800D2E90(-1) && !func_800D2E90(native_world_grid.dimensions[1]));heap_free(counts);
}
static void test_archive(const char *path) {
    CHECK(native_assets_open(path));int maps=0,total_models=0,total_sprites=0;
    for(s32 id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=10) continue;
        GsFile *file=gsmaker_entrypoint_1(id);CHECK(file);
        if(file->asset_base_ptr[0]!=1) {gsmaker_entrypoint_0(file);continue;}
        CHECK(gsmaker_entrypoint_16(file,1));
        GsFile *header=gsmaker_entrypoint_4(file->asset_current_ptr,file->end_ptr-file->asset_current_ptr);
        CHECK(gsmaker_entrypoint_22(header,1,lower,3));gsmaker_entrypoint_12(header,upper,3);CHECK(!header->failed);gsmaker_entrypoint_0(header);
        setup();func_800BDC68(file);
        if(file->failed) fprintf(stderr,"Original asset %x failed at byte %td, cached tag %d\n",id,file->asset_current_ptr-file->asset_base_ptr,file->last_expected);
        CHECK(!file->failed);
        check_layers();
        for(int i=0;i<native_world_grid.count;++i) {total_models+=native_world_grid.cells[i].models[1];total_sprites+=native_world_grid.cells[i].dynamic[1];}
        total_models+=native_world_grid.fallback.models[1];total_sprites+=native_world_grid.fallback.dynamic[1];
        cleanup();gsmaker_entrypoint_0(file);++maps;
    }
    CHECK(maps>0 && total_models>0);native_assets_close();
    printf("Loaded legacy cube sections from %d original assets: %d models, %d sprites.\n",maps,total_models,total_sprites);
}
static void test_world_fixture(const char *path) {
    CHECK(native_assets_open(path));setup();func_800C90AC();
    CHECK(gsworldDll_entrypoint_0(1,0));
    check_layers();
    s32 pos[3]={100,100,100};NativeWorldCell *cell=func_800BDBC4(pos);
    CHECK(cell->models[1]==1 && cell->dynamic[1]==1 && func_800E9D68(cell)->ItemID==42);
    CHECK(func_800E9E88(cell)->sprite==0x12345678);
    CHECK(func_800A5854(0)==2 && func_800A5800(0));f32 camera[3];CHECK(cadbfunc_entrypoint_0(camera));
    CHECK(camera[0]==1 && camera[1]==2 && camera[2]==3);
    CHECK(func_800C8BF4()==1 && func_800C8C18()==1);f32 light_position[3];func_800C8800(1,light_position);
    CHECK(light_position[0]==10 && light_position[1]==20 && light_position[2]==30);
    CHECK(!func_800D73CC(0x956));
    CHECK(!gsworldDll_entrypoint_0(2,0) && !func_800D73CC(0x957));
    CHECK(!gsworldDll_entrypoint_0(3,0) && !func_800D73CC(0x958));
    CHECK(!gsworldDll_entrypoint_0(INT32_MAX,0));
    func_800A5630();func_800C90D0();cleanup();native_assets_close();
}
static void test_world_archive(const char *path) {
    CHECK(native_assets_open(path));int maps=0,models=0,sprites=0,cameras=0,lights=0;
    real_geometry=1;
    for(s32 id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=10)continue;
        GsFile *header=gsmaker_entrypoint_1(id);CHECK(header);
        int current_format=header->asset_base_ptr[0]==6;gsmaker_entrypoint_0(header);
        if(!current_format)continue;
        level=id-0x955;
        CHECK(gcmapDll_entrypoint_3(&native_map));
        setup();func_800C90AC();
        int ok=gsworldDll_entrypoint_0(id-0x955,0);
        if(!ok)fprintf(stderr,"World asset %x failed to load\n",id);
        CHECK(ok);
        check_layers();
        for(int i=0;i<native_world_grid.count;++i){models+=native_world_grid.cells[i].models[1];sprites+=native_world_grid.cells[i].dynamic[1];}
        models+=native_world_grid.fallback.models[1];sprites+=native_world_grid.fallback.dynamic[1];
        for(int i=0;i<func_800A58F0();++i)if(func_800A5854(i))++cameras;
        lights+=func_800C8BF4();++maps;
        func_800A5630();func_800C90D0();cleanup();gcmapDll_entrypoint_4(&native_map);
        func_800D5E74();func_800D5E74();CHECK(!func_800D73CC(id));
    }
    native_assets_close();real_geometry=0;CHECK(maps>0);
    printf("World dispatcher loaded %d original assets: %d models, %d sprites, %d cameras, %d lights.\n",maps,models,sprites,cameras,lights);
}
int main(int argc,char **argv) {
    metadata.unk38_func=spawn_fixture;
    setup();CHECK(native_world_grid.count==18);test_flat();test_legacy();test_effects();cleanup();
    level=0xD7;setup();test_large_collection();cleanup();
    setup();test_malformed();cleanup();
    CHECK(argc>=1 && argc<=3);
    if(argc==3)test_world_fixture(argv[1]);
    else if(argc==2){test_archive(argv[1]);test_world_archive(argv[1]);}
    puts("Native cube loading, serialized props, cell allocation, collection and cleanup passed.");return 0;
}
