#include "actor_model_dependencies.h"
#include "native_custom_hits.h"
#include "native_assets.h"
#include "marker_world.h"
#include "core2/1EAF950.h"
#include "memory.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
static int frame=100;
s32 func_8001211C(void) {return frame;}
s32 func_800A9F14(s32 mode) {return 0;}
s32 func_800A9F30(void) {return 1;}
s32 func_800B0CFC(void *data) {CHECK(0);return 0;}
/* Skeleton narrow-phase is tested separately; this suite verifies installing its getter. */
s32 func_800AE0B8(void *skeleton) {CHECK(0);return 0;}
f32 *func_801027F4(Actor *actor) {CHECK(0);return NULL;}
NativeActorHit *func_80104124(void) {CHECK(0);return NULL;}
s16 func_800B1F8C(void *mesh,f32 *p,f32 *r,f32 scale,s32 zero,void *bones,f32 *q,f32 radius,f32 *normal,u32 flags) {CHECK(0);return 0;}

static void test_scratch(void) {
    CHECK(!func_80100480(-1,4) && !func_80100480(5,4) && !func_80100480(2,INT_MAX) && !func_80100480(2,-1));
    for(int i=0;i<5;++i){u8 *a=func_80100480(i,8);CHECK(a);a[0]=i;CHECK(func_80100480(i,4)==a && a[0]==i);a=func_80100480(i,32);CHECK(a[0]==i);}
    func_8010052C();func_801005B8();frame+=30;func_80100534();
    u8 *a=func_80100480(0,32);CHECK(a[0]==0);frame+=31;func_80100534();
    CHECK(func_80100480(0,32));func_80100610();func_80100670();
}
static void test_vertices(void *model) {
    NativeVertexList *source=func_800B2840(model);s32 tint[3]={128,255,255};u8 palette[4]={255,64,255,128};
    u8 *packed=glpackvtx_entrypoint_0(source,palette,tint);
    for(int i=0;i<3;++i){CHECK(!*(s16 *)(packed+i*10) && !*(s16 *)(packed+i*10+2) && !*(s16 *)(packed+i*10+4));CHECK(packed[i*10+6]==50 && packed[i*10+7]==98 && packed[i*10+8]==14 && !packed[i*10+9]);}
    glpackvtx_entrypoint_1(packed);
    s16 one=func_80100D24(model,148,2,1,0,NULL),two=func_80100D24(model,148,1,1,0,NULL);
    NativeVertexList *front=func_80100A74(one,0),*back=func_80100A74(one,1);
    CHECK(front && back && front!=back && front!=source && (front->count_flags&1));
    CHECK(front->vertices[0].v.ob[0]==source->vertices[0].v.ob[0] && !func_80100A74(two,1));
    CHECK(func_80100AC4(one)==func_80100AC4(two));
    func_80100B3C();func_80100F0C(one,palette);
    CHECK(func_80100AC4(one)!=func_80100AC4(two));
    CHECK(((u8 *)func_80100AC4(one))[6]==100 && ((u8 *)func_80100AC4(two))[6]==200);
    palette[3]=64;func_80100F0C(one,palette);CHECK(((u8 *)func_80100AC4(one))[6]==50);
    func_80100E18(one);func_80100C74();CHECK(func_80100A74(one,0)==front);func_80100C74();CHECK(!func_80100A74(one,0));
    CHECK(((u8 *)func_80100AC4(two))[6]==200);func_80100E54();func_80100B4C();func_80100B4C();
    s16 entries[400];
    for(int i=0;i<400;++i)entries[i]=func_80100D24(model,148,0,1,0,NULL);
    CHECK(func_80100AC4(entries[0])==func_80100AC4(entries[399]));
    for(int i=0;i<399;++i)func_80100E18(entries[i]);
    func_80100C74();func_80100C74();CHECK(((u8 *)func_80100AC4(entries[399]))[6]==200);
    func_80100B4C();
    CHECK(!func_80100D24(NULL,148,1,0,0,NULL) && !func_80100D24(model,148,3,0,0,NULL));
}
static Actor *spawn(void) {
    s32 position[3]={10,20,30},index;
    Unk80132ED0 *marker=func_800EBED4(position,1,5,0);CHECK(marker);
    Actor *actor=func_80106668(&index);CHECK(actor);rare_memset(actor,0,sizeof(*actor));actor->unk0=marker;actor->factory=model_test_factory;actor->flags74|=1u<<28;
    actor->position[0]=10;actor->position[1]=20;actor->position[2]=30;actor->scale=2;
    func_800EC340(marker,index);marker->unk18|=0x10000;marker->unk14=148;return actor;
}
static void test_model(void *model) {
    marker_world_reset();func_800EBB5C();func_800EBB94();func_801065E0();model_test_reset();
    Actor *actor=spawn();Unk80132ED0 *marker=actor->unk0;NativeVertexList *vertices=func_800B2840(model);f32 center[3],low[3],high[3];
    CHECK(func_80103964(marker)==model && func_801039A4(marker)==model && func_80103AA0(marker)==model && func_80103AE4(marker)==model && func_80103AC0(actor));
    func_80103328(actor);CHECK(actor->center_radius==200 && actor->model_radius==200 && actor->horizontal_radius==100 && actor->model_y_min==0 && actor->model_y_max==0);
    CHECK(func_80103FB8(actor)==400 && func_80103EAC(actor)==200 && func_80103EF4(actor)==0);
    CHECK(func_80103F38(actor,center)==400 && center[0]==10 && center[1]==20 && center[2]==30);
    func_80103DFC(actor,center);CHECK(center[1]==20);func_8010347C(marker);
    CHECK(func_80103BBC(actor)==vertices && func_80103C94(actor)==vertices && func_80103CB8(actor,model)==vertices);
    CHECK(func_80103CDC(actor,model)==vertices && func_80103D00(actor,model)==vertices && func_80103D24(actor)==vertices);
    CHECK(!func_80103CDC(actor,NULL));
    actor->flags70|=1u<<24;
    CHECK(func_80103CDC(actor,model)==vertices && !func_80103C94(actor));actor->flags70&=~(1u<<24);
    CHECK(func_801039E4(marker)==model && model_test_loads==1 && model_test_message==(uintptr_t)model && (actor->flags70&8));
    CHECK(func_80104004(actor,low,high) && low[0]==-200 && high[2]==200 && !low[1]);
    func_80103508(actor);CHECK(model_test_loads==1);func_8010381C(actor);CHECK(model_test_unloads==1);
    actor->flags70|=1u<<24;actor->flags7A|=0x40;actor->pad94|=0x8000;actor->flags74|=1u<<23;
    actor->unk70_10=7;marker->unk16=149;model_test_color[0]=128;
    model_test_settings.unk24=4;model_test_settings.unk26=0x5060;
    u32 generation=marker->unk10&0xFFFF;
    CHECK(func_801039E4(marker)==model && actor->vertex_handle && model_test_created==6 && marker->unk4);
    CHECK((marker->unk10>>16)==3 && (marker->unk10&0xFFFF)==generation && actor->attachment_handle==4 && actor->animation_handle==6 && actor->expression_handle==7);
    NativeVertexList *front=func_80103CDC(actor,model),*back=func_80103D00(actor,model);CHECK(front && back && front!=back);
    CHECK(front->vertices[0].v.cn[0]==100 && back->vertices[0].v.cn[0]==100);
    CHECK(((u8 *)func_80100AC4(actor->vertex_handle))[6]==50);
    actor->flags70|=1u<<23;CHECK(func_80103CDC(actor,model)==back && func_80103D00(actor,model)==front && func_80103D24(actor)==front);
    CHECK(func_801040A8(actor));s16 vertex_handle=actor->vertex_handle;
    func_8010381C(actor);CHECK(model_test_destroyed==6 && !actor->vertex_handle && !marker->unk4 && !(marker->unk10>>16) && (marker->unk10&0xFFFF)==generation);
    CHECK(func_80100A74(vertex_handle,0));func_80100C74();CHECK(func_80100A74(vertex_handle,0));func_80100C74();CHECK(!func_80100A74(vertex_handle,0));
    model_test_reset();actor->flags70=0;actor->flags7A=0;actor->flags74=0;actor->pad94=0;marker->unk16=0;
    CHECK(func_80103140(actor,0xABCD0000u|148,0)==148 && !model_test_loads);
    CHECK(func_80103140(actor,1500,0)==148 && marker->unk14==1500 && actor->center_radius==200);
    actor->animation_handle=6;CHECK(func_801032B0(actor,148,0)==1500 && actor->animation_handle==6);actor->animation_handle=0;
    CHECK(func_80103140(actor,149,0)==148 && !(((NativeMarkerProp *)marker->unk0)->flags&2) && !actor->center_radius);
    CHECK(func_80103140(actor,148,0)==149 && (((NativeMarkerProp *)marker->unk0)->flags&2));
    marker->unk14=0;CHECK(!func_80103964(marker) && !func_801039A4(marker) && !func_801039E4(marker));
    marker->unk14=0xFFFF;CHECK(!func_80103C94(actor));func_80103DFC(actor,center);CHECK(center[1]==20);marker->unk14=148;
    /* A native header offset is set temporarily to exercise automatic custom-table installation. */
    ((u32 *)model)[5]=80;actor->flags74&=~0x80000000u;CHECK(func_801039E4(marker)==model && marker->collision==subaddiecustomhits_entrypoint_1);
    marker->unk10=(marker->unk10&0xFFFF)|(3u<<16);CHECK(func_80103D98(marker)==(u8 *)model+80);marker->unk10&=0xFFFF;CHECK(!func_80103D98(marker));((u32 *)model)[5]=0;
    func_8010381C(actor);func_80100B4C();marker_world_cleanup();func_80106608();
}
static void test_archive(void) {
    marker_world_reset();func_800EBB5C();func_800EBB94();func_801065E0();model_test_reset();
    Actor *actor=spawn();int models=0,vertices=0;
    for(int id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=0 || native_asset_packed_size(id)<=0)continue;
        actor->unk0->unk14=id;actor->unk0->collision=NULL;actor->pad68=0;actor->flags74=1u<<28;actor->flags70=1u<<24;
        void *model=func_801039E4(actor->unk0);CHECK(model && model_test_message==(uintptr_t)model);
        NativeVertexList *source=func_800B2840(model),*front=func_80103CDC(actor,model),*back=func_80103D00(actor,model);
        CHECK(source && front && back && source!=front && front!=back);
        CHECK(actor->center_radius==source->center_radius && actor->model_radius==source->radius);
        CHECK(actor->model_y_min==source->minimum[1] && actor->model_y_max==source->maximum[1]);
        int count=source->count_flags>>1;vertices+=count;++models;
        for(int i=0;i<count;++i)for(int j=0;j<3;++j)CHECK(front->vertices[i].v.ob[j]==source->vertices[i].v.ob[j] && back->vertices[i].v.ob[j]==source->vertices[i].v.ob[j]);
        actor->flags70|=1u<<23;CHECK(func_80103CDC(actor,model)==back && func_80103D00(actor,model)==front);
        func_8010381C(actor);func_80100C74();func_80100C74();func_800D6CEC(id);func_800D5E74();func_800D5E74();
    }
    CHECK(models==1145 && vertices==739955 && model_test_loads==models && model_test_unloads==models);
    printf("Native actor model lifecycle: %d original models, %d vertices, both buffers copied/swapped/released.\n",models,vertices);
    marker_world_cleanup();func_80106608();
}
int main(int argc,char **argv) {
    CHECK((argc==2 || argc==3) && native_assets_open(argv[1]));
    if(argc==3)test_archive();
    else {void *model=func_800D674C(148);CHECK(model);test_scratch();test_vertices(model);test_model(model);}
    func_80100610();func_80100B4C();native_assets_shutdown();
    puts("native actor model checks passed");return 0;
}
