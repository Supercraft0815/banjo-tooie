#include "marker_world.h"
#include "native_actor.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "core2/1EC8070.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x); exit(1); } } while(0)

/* Sprite dimensions, drawing, clock and memory-pressure policy remain controlled boundaries. */
static struct NativeMarkerCollision *custom_collision(void) { return NULL; }
static void *model;
static int radius_reads;
s32 func_8001211C(void) { return 100; }
s32 func_800A9F14(s32 mode) { return mode==2 ? 3 : 18; }
s32 func_800A9F30(void) { return 1; }
s32 func_800B0CFC(void *data) { CHECK(data && data==func_800D6B0C(12));++radius_reads;return 21; }
void *func_801039E4(void *marker) { CHECK(func_80106790(marker));return model; }
static NativeMarkerProp *drawn[64];
static int draw_count, prepare_count;
void func_800E3A30(s16 *out) { func_800EFD4C(out); }
void _gspropprop_entrypoint_2(void *data) { ++prepare_count;((NativeMarkerProp *)data)->flags|=2; }
void _gspropprop_entrypoint_3(void *data,s32 mode) { CHECK(mode==7);drawn[draw_count++]=data; }
s32 func_8010A79C(Actor *actor,s32 mode) { CHECK(actor && mode==7);drawn[draw_count++]=(void *)actor->unk0->unk0;return 1; }

static void test_pool(void) {
    Unk80132ED0 *slots[200], unrelated={0};
    func_800EBB5C();func_800EBB94();CHECK(func_800EBB74());
    func_800EBB6C();func_800EBC04();
    for(int i=0;i<200;++i) {
        slots[i]=func_800EBD78();CHECK(slots[i]);
        if(i) CHECK((uintptr_t)slots[i]-(uintptr_t)slots[i-1]==sizeof(*slots[i]));
        slots[i]->unk10=0xABCDFEDFu;
    }
    CHECK(!func_800EBD78());
    func_800EBE24(NULL);func_800EBE24(&unrelated);func_800EBE24((u8 *)slots[3]+1);
    CHECK(!func_800EBD78());
    for(int i=199;i>=0;i-=2) func_800EBE24(slots[i]);
    for(int i=1;i<200;i+=2) { CHECK(slots[i]->unk10==0xABCD0001);CHECK(func_800EBD78()==slots[i]); }
    CHECK(!func_800EBD78());func_800EBB94();
    for(int i=0;i<200;++i) CHECK(slots[i]->unk10==0xABCD0001 && func_800EBD78()==slots[i]);
    func_800EBB94();
    func_800EC828();CHECK(func_800EC854()==0x7FFF);
    for(int i=0x6B7;i<0x8000;++i) CHECK(func_800EC854()==i);
    CHECK(func_800EC854()==0x6B7);func_800EBB5C();
}

static void test_lifecycle(void) {
    s32 pos[3]={12,23,34};
    f32 out[3], moved[3]={1003.9f,17.7f,35.1f}, angles[3]={-90,720,450};
    s16 shorts[3];
    marker_world_reset();
    Unk80132ED0 *first=func_800EBED4(pos,1,0x456,0), *second=func_800EBED4(pos,0,8,1);
    CHECK(first && second && first!=second && first->cube_index==0 && second->cube_index==-1);
    CHECK((first->unk24>>22)==0x56 && first->unk28==0x200 && !(first->unk10&1));
    CHECK((second->unk10&1) && (second->unk10>>1)==(first->unk10>>1)+1);
    NativeMarkerProp *prop=(void *)first->unk0;
    CHECK(prop->marker==first && prop->flags==(0x13|(17<<6)));
    CHECK(prop->position[0]==12 && prop->position[1]==23 && prop->position[2]==34);
    CHECK(first->callback==func_800EBB50);
    uintptr_t *callbacks=func_800EC3C4(first);
    for(int i=0;i<5;++i) CHECK(!callbacks[i]);
    func_800EC358(first,custom_collision);func_800EC360(first,0xFFFF);func_800EC368(first,17);
    CHECK(first->collision==custom_collision && first->unk14==0xFFFF && first->unk16==17);
    first->unk18=0xA55A001F;func_800EC340(first,0x1ABC);
    CHECK(first->unk18==((0xA55A001F&~0xFFE0u)|((0x1ABCu&0x7FF)<<5)));
    pos[0]=21;func_800EC058(pos,first);CHECK(first->unk0==(u32 *)prop && prop->position[0]==21);
    prop->flags=0xD7F7;first->unk28|=1<<10;
    func_800EC124(moved,first,angles);
    CHECK(first->cube_index==1 && marker_world_updates==1 && func_800E9DCC(marker_world[1])==0 && func_800E9DCC(marker_world[2])==1);
    CHECK(((NativeMarkerProp *)first->unk0)->flags==0xD7F7);
    CHECK(((first->unk24>>7)&0x1FF)==270 && (first->unk24>>22)==0x56);
    CHECK((first->unk28>>23)==0 && ((first->unk28>>14)&0x1FF)==90 && (first->unk28&0x600)==0x600);
    func_800EC370(first,shorts);func_800EC398(first,out);
    CHECK(shorts[0]==1003 && shorts[1]==17 && shorts[2]==35 && out[0]==shorts[0] && out[1]==shorts[1] && out[2]==shorts[2]);
    func_800EC0EC(moved,second);CHECK(second->cube_index==-1 && func_800E9DCC(marker_world[0])==1);
    Unk80132ED0 *third=func_800EBFD4(moved,1,19);
    u32 generation=first->unk10;
    func_800EBFF4(first);
    CHECK(!first->unk0 && !(first->unk10&0xFFFE) && func_800E9DCC(marker_world[2])==1);
    CHECK(((NativeMarkerProp *)third->unk0)->marker==third);
    CHECK(((NativeMarkerProp *)third->unk0)->position[0]==1003);
    Unk80132ED0 *reused=func_800EBF8C(moved,0,20,1);
    CHECK(reused==first && reused->unk10!=generation && reused->cube_index==-1);
    func_800EBFF4(second);func_800EBFF4(third);func_800EBFF4(reused);
    for(int i=0;i<3;++i) CHECK(!func_800E9DCC(marker_world[i]));
}

static void test_geometry(void) {
    s32 position[3]={10,20,30}, index;
    f32 center[3];
    Unk80132ED0 *marker=func_800EBED4(position,0,5,0);
    CHECK(!func_800EC3E8(marker) && !func_800EC428(marker) && !func_800EC48C(marker));
    CHECK(func_800EC504(marker)==1);
    func_800EC360(marker,-1);CHECK(!func_800EC3E8(marker) && !func_800EC48C(marker) && func_800EC504(marker)==1);
    func_800EC360(marker,12);model=func_800D674C(12);CHECK(model && func_800EC3E8(marker)==model && func_800EC428(marker)==model);
    CHECK(func_800EC708(marker)==10 && marker->model_center[1]==10 && radius_reads==1);
    CHECK(func_800EC708(marker)==10 && radius_reads==1);
    func_800D6CEC(12);CHECK(!func_800D73CC(12));
    func_800EC360(marker,148);
    marker->unk18&=0x1FFFFF;((NativeMarkerProp *)marker->unk0)->flags|=2;
    CHECK(func_800EC75C(marker,center)==17 && center[0]==7 && center[1]==24 && center[2]==35);
    CHECK(!func_800D73CC(148));
    marker->unk18&=0x1FFFFF;model=func_800D674C(148);CHECK(func_800EC708(marker)==17 && func_800D73CC(148));
    func_801065E0();Actor *actor=func_80106668(&index);actor->unk0=marker;actor->scale=2.5f;
    func_800EC340(marker,index);marker->unk18|=0x10000;
    CHECK(func_800EC800(marker) && func_800EC428(marker)==model);
    CHECK(func_800EC75C(marker,center)==42.5f && center[0]==2.5f && center[1]==30 && center[2]==42.5f);
    marker->unk14=0xFFFE;CHECK(func_800EC504(marker)==1);marker->unk14=148;
    func_801066C0(0);func_80106608();marker->unk18&=~0x10000u;CHECK(!func_800EC800(marker));
    func_800EBFF4(marker);
}

static void test_groups(void) {
    marker_world_reset();func_800EB70C();CHECK(func_800EB854()==-1);
    func_800EB51C(-1,7);func_800EB51C(7,7);func_800EB51C(0,7);CHECK(!draw_count);
    NativeWorldCell *cube=marker_world[1];
    for(int i=0;i<20;++i) *func_800E9804(cube)=(NativeMarkerProp){.position={i,0,0},.flags=0x10};
    NativeMarkerProp *props=func_800E9E88(cube);
    func_800EB5E0(cube,0);CHECK(prepare_count==20);
    func_800EB7A8();func_800EB51C(0,7);CHECK(draw_count==20 && func_800EB854()==0);
    for(int i=0;i<20;++i) CHECK(drawn[i]==&props[19-i]);
    func_800EB800();draw_count=0;func_800EB51C(0,7);CHECK(!draw_count);
    s16 origin[3]={0};props[0].position[0]=props[1].position[0]=5;
    func_800EB3D0(&props[0],3,origin);func_800EB3D0(&props[1],3,origin);
    func_800EB3D0(&props[2],-1,origin);func_800EB3D0(&props[2],7,origin);
    func_800EB51C(3,7);CHECK(draw_count==2 && drawn[0]==&props[1] && drawn[1]==&props[0]);
    func_800EB800();draw_count=0;marker_world_reset();func_801065E0();
    s32 position[3]={8,0,0}, index;
    Unk80132ED0 *marker=func_800EBED4(position,1,5,0);
    Actor *actor=func_80106668(&index);actor->unk0=marker;
    func_800EC340(marker,index);marker->unk18|=0x10000;marker->unk14=12;marker->unk28|=(1<<2)|(1<<7);
    func_800EB5E0(marker_world[1],0);func_800EB51C(1,7);func_800EB51C(6,7);
    CHECK(draw_count==2 && drawn[0]==(void *)marker->unk0 && drawn[1]==drawn[0]);
    func_800EB750();func_800EB750();func_800EB51C(1,7);CHECK(draw_count==2);
    func_800EBFF4(marker);func_801066C0(0);func_80106608();
}

static uintptr_t filter_token;
static int filter_calls;
static s32 filter(s16 *position,uintptr_t token) {
    CHECK(token==filter_token);++filter_calls;
    if(position[0]==1) return 0;
    position[0]=30;return 1;
}
static void test_search(void) {
    _Static_assert(sizeof(Prop)==20,"world model prop stride");
    marker_world_reset();func_800EB874();
    NativeWorldCell *cube=marker_world[1];
    for(int i=0;i<4;++i) *func_800E9804(cube)=(NativeMarkerProp){0};
    NativeMarkerProp *props=func_800E9E88(cube);
    props[0]=(NativeMarkerProp){.position={1,0,0},.flags=1};
    props[1]=(NativeMarkerProp){.position={5,0,0},.flags=0};
    props[2]=(NativeMarkerProp){.position={3,0,0},.flags=2};
    props[3]=(NativeMarkerProp){.position={2,0,0},.flags=0};
    s32 position[3]={0};void *found_cube,*found_prop;
    func_800EB880(position,1,10);func_800EB8C0(cube);
    CHECK(func_800EBB30(&found_cube,&found_prop)==1 && found_cube==cube && found_prop==&props[3]);
    func_800EB880(position,2,10);func_800EB8C0(cube);
    CHECK(func_800EBB30(&found_cube,&found_prop)==2 && found_prop==&props[2]);
    func_800EB880(position,1,2);func_800EB8C0(cube);
    CHECK(!func_800EBB30(&found_cube,&found_prop) && !found_cube && !found_prop);
    func_800E9A24(cube);func_800E9A24(cube);
    Prop *models=func_800E9D68(cube);for(int i=0;i<2;++i) { models[i].position[0]=i+1;models[i].position[1]=models[i].position[2]=0; }
    filter_token=(uintptr_t)&position;func_800EB860(filter,filter_token);
    func_800EB880(position,3,10);func_800EB8C0(cube);
    CHECK(func_800EBB30(&found_cube,&found_prop)==3 && found_prop==&models[1] && filter_calls==2);
    CHECK(models[1].position[0]==30);
    func_800EB874();func_800EB880(position,3,10);func_800EB8C0(cube);
    CHECK(func_800EBB30(&found_cube,&found_prop)==3 && found_prop==&models[0] && filter_calls==2);
    func_800EB880(position,0,100);func_800EB8C0(cube);CHECK(!func_800EBB30(&found_cube,&found_prop));
    props[0].flags&=~1u;
}
int main(int argc,char **argv) {
    CHECK(argc==3 && native_assets_open(argv[1]));func_800D66AC();
    test_pool();test_lifecycle();test_geometry();test_groups();test_search();
    marker_world_cleanup();func_800D6C64();native_assets_close();
    puts("Native marker pool, generation reuse, cell movement, bounds, grouping and search passed");
    return 0;
}
