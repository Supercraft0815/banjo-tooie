#include "core2/1ED8C80.h"
#include "core2/1EDA900.h"
#include "core2/1EAF950.h"
#include "native_actor_animation.h"
#include "native_render.h"
#include "core2/animation.h"
#include "native_custom_hits.h"
#include "native_assets.h"
#include "actor_model_dependencies.h"
#include "marker_world.h"
#include "memory.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
/* Player/camera, animation containers, effects and render consumers are observed boundaries. */
extern f32 D_80127194;
extern s32 D_80135A50,D_80124390;
static ActorData settings;
static int initialized,updated,alternate,destroyed,activated,loads,unloads,stop_init,stop_activate;
static int prepared,finished,camera_mode,camera_reads,player_reads,zones,fade,bounce,expression,effects,audio,path_target;
static int starts,ends,reset_calls,auto_calls,glid_updates,log_count,log_ids[128];
static AnimCtrl *animation;
static int clock_reads;
static int chance_result=1,phase_result,boost;
static NativeActorAnimation dynamic_animations[]={{1,152,1}};
static f32 observer[3]={100,100,100};
static void record(Actor *actor,int phase) {CHECK(log_count<128);log_ids[log_count++]=actor->actorData[0]*10+phase;}
static void initialize(Actor *actor) {++initialized;record(actor,1);if(stop_init)func_800FFAB0(actor);}
static void update(Actor *actor) {++updated;record(actor,3);}
static void alternate_update(Actor *actor) {++alternate;record(actor,4);}
static void destroy(Actor *actor) {++destroyed;record(actor,5);}
static intptr_t message(Actor *actor,s32 id,uintptr_t data) {
    if(id==0x95){CHECK(!data);++activated;record(actor,2);if(stop_activate)func_800FFAB0(actor);}
    else if(id==0x29){CHECK(data && (actor->flags70&8));++loads;}
    else if(id==0x2A){CHECK(!data && !(actor->flags70&8));++unloads;}
    else if(id==0x99){CHECK(!data);func_80101074(dynamic_animations);}
    else CHECK(id==0x93 && !data);
    return 0;
}
static ActorData *factory(void) {return &settings;}
s32 func_8001211C(void) {return 100;}
f32 func_800D8FF8(void) {++clock_reads;return 0.1f;}
f32 _glintrosyncDll_entrypoint_5(void) {return 0.1f;}
s32 func_800DC298(f32 chance) {CHECK(chance==0.5f);return chance_result;}
s32 func_8001210C(s32 period) {CHECK(period==10);return phase_result;}
s32 func_800D3E40(s32 id) {CHECK(id==8);return boost;}
s32 func_800A9F14(s32 mode) {return 0;}
s32 func_800A9F30(void) {return 1;}
s32 func_800B0CFC(void *data) {CHECK(0);return 0;}
f32 *func_801027F4(Actor *actor) {CHECK(0);return NULL;}
NativeActorHit *func_80104124(void) {CHECK(0);return NULL;}
s16 func_800B1F8C(void *mesh,f32 *p,f32 *r,f32 scale,s32 zero,void *bones,f32 *q,f32 radius,f32 *normal,u32 flags) {CHECK(0);return 0;}
void func_80104350(void) {++starts;}
void func_80106A20(void) {++starts;}
void func_80106DF0(void) {++starts;}
void func_80107BB0(void) {++starts;}
void func_80104378(void) {++ends;}
void func_80106A28(void) {++ends;}
void func_80106E18(void) {++ends;}
void func_8010DF98(void) {++ends;}
void func_80106EE0(void *data) {Actor *actor=data;actor->pad94&=~0x3FF00000u;}
void _subaddieaudioloop_entrypoint_2(Actor *actor) {CHECK(actor);++audio;}
void func_800D8808(s32 target) {path_target=target;}
s32 func_8010D1E8(void) {++prepared;return 0;}
void func_8010DF3C(void) {++finished;}
void func_8010DEFC(void) {++reset_calls;}
int func_800DB9B0(void) {return camera_mode;}
void func_800E3980(f32 *out) {++camera_reads;rare_memcpy(out,observer,sizeof(observer));}
void func_8010D254(f32 *out) {++player_reads;rare_memcpy(out,observer,sizeof(observer));}
void *func_800BEC1C(void) {return zones ? observer : NULL;}
void _subaddiezone_entrypoint_0(void *actor) {CHECK(actor);++zones;}
void _subaddiefade_entrypoint_7(Actor *actor) {CHECK(actor->flags79&3);++fade;}
void _chbounce_entrypoint_8(Actor *actor) {CHECK(actor->flags7A&8);++bounce;}
void func_80104780(Actor *actor) {CHECK(actor->expression_handle==7);++expression;}
void func_80106F70(Actor *actor) {CHECK(actor->pad94&0x3FF00000);++effects;}
u32 func_800E6A00(void) {return 0;}
s32 _chbadshad_entrypoint_1(Actor *actor,f32 *position,f32 scale) {CHECK(0);return 0;}
s32 _suautobaddies_entrypoint_1(void) {++auto_calls;return 0;}
s32 _subaddieDll_entrypoint_1(void *actor) {CHECK(0);return 0;}
void func_8010A800(void *actor,s32 mode) {CHECK(actor && mode>=0 && mode<=4);}
void func_8010A63C(void *actor) {CHECK(actor);}
void func_800F31FC(u8 *color,s32 r,s32 g,s32 b,s32 a) {color[0]=r;color[1]=g;color[2]=b;color[3]=a;}
void func_8010A3E8(void *actor,f32 scale) {CHECK(actor && scale==1);}
void func_80106E88(void *actor) {CHECK(actor);}
void func_80104F2C(void *actor,s32 first,s32 second) {CHECK(actor && !first && !second);}
void func_80108F08(void *a,void *b,s32 c) {CHECK(0);}
void *_dbvpl_entrypoint_0(void *data,s32 index) {CHECK(0);return NULL;}
NativeActorItemType D_80124440[11];
static s16 empty_meshes[]={0};
void *_glidmake_entrypoint_5(u16 asset,void *scale) {CHECK(asset==148 && !scale);return heap_alloc(16);}
s16 *_glidmake_entrypoint_1(void *model) {CHECK(model);return empty_meshes;}
void _glidmake_entrypoint_4(void *model) {CHECK(model);heap_free(model);}
void _glid_entrypoint_5(void *model,void *vertices) {CHECK(model && vertices);++glid_updates;}
void _glid_entrypoint_6(void *model,void *vertices) {CHECK(model && vertices);++glid_updates;}

static Actor *spawn(int id) {
    s32 position[3]={100,100,100},index;
    Unk80132ED0 *marker=func_800EBED4(position,1,5,0);CHECK(marker);marker->unk14=148;
    Actor *actor=func_80106668(&index);rare_memset(actor,0,sizeof(*actor));
    actor->unk0=marker;actor->factory=factory;actor->actorData[0]=id;actor->scale=1;
    for(int i=0;i<3;++i)actor->position[i]=100;
    actor->flags74=1u<<28;actor->flags7C=0x4000;actor->unk6C_9=12;
    func_800EC340(marker,index);marker->unk18|=0x10000;return actor;
}
static void reset(void) {
    func_800DF38C();marker_world_reset();func_800EBB5C();func_800EBB94();model_test_reset();
    settings=(ActorData){.unk34_func=initialize,.unkC_func=update,.unk10_func=alternate_update,.unk28_func=destroy,.unk40_func=message};
    initialized=updated=alternate=destroyed=activated=loads=unloads=stop_init=stop_activate=0;
    prepared=finished=camera_mode=camera_reads=player_reads=zones=fade=bounce=expression=effects=audio=0;
    starts=ends=reset_calls=auto_calls=glid_updates=log_count=clock_reads=0;D_80127194=123;D_80124390=0;
    func_800FF390();CHECK(starts==4 && !func_80106730() && !D_80135A50);
}
static void cleanup(void) {
    CHECK(!func_800FF564() && ends==4 && !D_80127194 && !func_80106730());
    marker_world_cleanup();func_80100B4C();
    func_800DF35C();CHECK(!*func_800DF330());
}
static void test_buffers(void) {
    reset();Actor *actor=spawn(0);actor->attachment_handle=0x1234;
    for(int i=0;i<3;++i) {
        u32 *data=func_80100074(actor,i,5);CHECK(data && !data[0] && !data[1]);data[0]=0xAABBCCDD;data[1]=17;
        CHECK(func_801000D8(actor,i,100)==data && func_80100094(actor,i)==data);
        data=func_80100074(actor,i,17);CHECK(data[0]==0xAABBCCDD && data[1]==17 && !data[2] && !data[3] && !data[4]);
        data=func_80100074(actor,i,1);CHECK(data[0]==0xAABBCCDD);
        data=func_80100074(actor,i,5);CHECK(data[0]==0xAABBCCDD && !data[1]);
    }
    CHECK(actor->attachment_handle==0x1234 && actor->buffer_handle0 && actor->buffer_handle1 && actor->buffer_handle2);
    CHECK((actor->pad84>>16)==actor->buffer_handle1 && (actor->pad84&0xFFFF)==actor->buffer_handle2);
    CHECK(!func_80100074(actor,3,4) && !func_80100074(actor,0,UINT32_MAX) && !func_800FFECC(actor,0,-1));
    CHECK(!func_80100094(actor,UINT32_MAX) && !func_801000D8(actor,-1,4) && !func_80100074(NULL,0,4));
    for(int i=0;i<3;++i){CHECK(!func_80100074(actor,i,0));CHECK(!func_80100094(actor,i));}
    actor->attachment_handle=0;CHECK(!actor->pad84 && !actor->buffer_handle0);cleanup();
}
static void test_activation(void) {
    reset();Actor *actor=spawn(0);func_80100120(actor);func_80100120(actor);CHECK(initialized==1 && (actor->flags74&(1u<<21)));
    actor->flags7C=(10u<<16)|0x4000;f32 point[3]={110,100,100};
    CHECK(func_8010038C(actor,point) && activated==1 && !func_80100230(actor,point));
    point[0]=110.01f;CHECK(!func_8010038C(actor,point) && activated==1 && func_80100230(actor,point));
    actor->flags7C|=0x3000;CHECK(func_8010038C(actor,point));actor->flags7C&=~0x4000u;CHECK(!func_8010038C(actor,point) && !func_80100230(actor,point));
    actor->flags7C=0x4000;CHECK(func_8010038C(actor,point) && func_80100230(actor,point));
    actor=spawn(1);stop_init=1;func_80100120(actor);CHECK(actor->unk64_17 && (actor->flags7C&0xC000)==0x8000);
    CHECK(!func_8010038C(actor,point));stop_init=0;
    actor=spawn(2);stop_activate=1;CHECK(!func_8010038C(actor,point) && actor->unk64_17);stop_activate=0;
    func_800FFB74();CHECK(func_80106730()==1 && destroyed==2);
    actor=func_80106768(0);actor->flags74&=~(1u<<21);actor->flags70=8;settings.unk3C=8;
    func_80100120(actor);CHECK(unloads==1 && !(actor->flags70&8) && initialized==3);
    cleanup();CHECK(destroyed==3);
}
static void test_frame(void) {
    reset();Actor *first=spawn(0),*second=spawn(1),*disabled=spawn(2);
    disabled->unk64_17=1;second->flags74|=0x30;
    second->rotation[0]=-90;second->rotation[1]=725;second->rotation[2]=181;
    second->unk0->unk24=0xA5A50055;second->unk0->unk28=0x1234;
    first->flags79=3;first->flags7A=8;first->expression_handle=7;first->pad94=1u<<20;
    animation=func_801042B8(first);CHECK(animation);anctrl_setPlaybackType(animation,2);first->flags74|=1u<<27;
    zones=1;func_800FF62C();CHECK(initialized==1 && activated==2 && updated==1 && alternate==1);
    CHECK(log_count==5 && log_ids[0]==12 && log_ids[1]==14 && log_ids[2]==1 && log_ids[3]==2 && log_ids[4]==3);
    CHECK(prepared==1 && finished==1 && player_reads==1 && !camera_reads && fade==1 && bounce==1 && expression==1 && effects==1 && zones==2 && clock_reads==1);
    CHECK(second->unk0->unk24==((0xA5A50055u&~0xFF80u)|(270u<<7)));
    CHECK(second->unk0->unk28==(0x1234u|(5u<<23)|(181u<<14)));
    camera_mode=1;zones=0;func_800FF62C();CHECK(camera_reads==1 && initialized==1 && activated==2 && updated==2 && alternate==2);
    first->flags74&=~(1u<<27);func_800FF62C();CHECK(clock_reads==2);
    cleanup();animation=NULL;
}
static void test_resources_and_delete(void) {
    reset();Actor *actor=spawn(0);settings.unk26=0x1000;actor->flags70=1u<<24;
    CHECK(func_801039E4(actor->unk0) && loads==1 && actor->vertex_handle && ((s16 *)&actor->pad90)[0]);
    actor->unk7C_12=1;func_800FFC90();CHECK(actor->flags70&(1u<<23));func_800FFC90();CHECK(!(actor->flags70&(1u<<23)));
    func_800FF62C();CHECK(glid_updates==2);
    func_800FFBEC();CHECK(!actor->unk7C_12 && reset_calls==1);func_800FFC14();CHECK(reset_calls==2);
    func_80100074(actor,0,8);func_80100074(actor,1,8);func_80100074(actor,2,8);
    NativeActorPathState *path=func_8010556C(actor);CHECK(path);path->flags24=5u<<6;
    func_800FF3EC(actor);func_800FF3EC(actor);CHECK(destroyed==1);
    func_800FFA88(actor->unk0);CHECK(actor->unk64_17 && D_80135A50==1);func_800FFB74();
    CHECK(!func_80106730() && destroyed==1 && unloads==1 && !D_80135A50 && path_target==5);
    actor=spawn(1);Actor *parent=spawn(2);actor->parent_marker=parent->unk0;parent->parent_marker=actor->unk0;
    actor->flags7A=4;actor->flags74|=1u<<24;func_800FFAB0(actor);
    CHECK(actor->unk64_17 && parent->unk64_17 && !actor->parent_marker && !parent->parent_marker && !(actor->flags7A&4) && !(actor->flags74&(1u<<24)));
    func_800FFB74();CHECK(!func_80106730());
    actor=spawn(3);parent=spawn(4);actor->unk6C_9=0x243;actor->parent_marker=parent->unk0;
    func_800FFAB0(actor);CHECK(!parent->unk64_17);func_800FFB74();CHECK(func_80106730()==1);
    func_801002C0();CHECK(auto_calls==1);func_800FF44C();int count=destroyed;func_800FF44C();CHECK(destroyed==count);
    cleanup();CHECK(destroyed==count);
}
static void test_purge(void) {
    reset();
    for(int i=0;i<12;++i) {Actor *actor=spawn(i);actor->flags70=8;actor->unk0->unk14=0;}
    func_800FFD10(1);CHECK(unloads==10);func_800FFD10(1);CHECK(unloads==12);
    for(int i=0;i<12;++i)func_80106768(i)->flags70=8;
    func_800FFD10(0);CHECK(unloads==24);
    Actor *actor=func_80106768(0);actor->unk0->unk14=148;CHECK(func_801039E4(actor->unk0));
    func_800FFD10(0);CHECK(actor->flags70&8);func_800FFE08();CHECK(actor->flags70&8);
    func_800FFDBC();CHECK(!(actor->flags70&8) && unloads==25);cleanup();
}
static void test_constructor(void) {
    reset();s32 position[3]={10,20,30};
    settings.unk0=5;settings.unk2=12;settings.unk4=-1;settings.unk30=5;settings.unk32=9;
    Actor *actor=func_80107C2C(position,45,&settings,factory,NULL);CHECK(actor && func_80106730()==1);
    u32 *first=func_80100094(actor,0),*second=func_80100094(actor,1);
    CHECK(first && second && first!=second && !first[0] && !first[1] && !second[0] && !second[1] && !second[2]);
    CHECK(func_8001B7B8(actor->buffer_handle0)==8 && func_8001B7B8(actor->buffer_handle1)==12 && !actor->buffer_handle2);
    CHECK(actor->position[0]==10 && actor->position[1]==20 && actor->position[2]==30 && actor->rotation[1]==45);
    func_801001D8();CHECK(initialized==1);func_800FFA88(actor->unk0);func_800FFB74();CHECK(!func_80106730() && destroyed==1);
    cleanup();
}
static void test_animation_pool(void) {
    reset();Actor actors[96]={0};s16 handles[96];
    for(int i=0;i<96;++i) {
        actors[i].expression_handle=1000+i;
        AnimCtrl *c=func_801042B8(&actors[i]);CHECK(c && (uintptr_t)c%_Alignof(AnimCtrl)==0);
        c->duration=i+0.5f;handles[i]=actors[i].animation_handle;
        CHECK(actors[i].expression_handle==1000+i && handles[i]>0);
    }
    func_801041C8();
    for(int i=0;i<96;++i)CHECK(func_80104248(&actors[i])->duration==i+0.5f);
    for(int i=0;i<96;i+=2){func_80104328(&actors[i]);CHECK(!actors[i].animation_handle && !func_80104200(handles[i]));func_80104328(&actors[i]);}
    CHECK(!func_80104200(-1) && !func_80104200(32767) && !func_80104248(NULL));
    for(int i=0;i<96;i+=2){CHECK(func_801042B8(&actors[i]));CHECK(actors[i].expression_handle==1000+i);}
    for(int i=0;i<96;++i)func_80104328(&actors[i]);
    s16 handle=0;CHECK(func_80104268(&handle));func_801042D8(&handle);CHECK(!handle);
    cleanup();CHECK(!func_80104200(1));
}
static void test_animation_states(void) {
    reset();Actor *actor=spawn(0);
    NativeActorAnimation table[]={{1,151,1},{2,152,2},{3,151,4},{0,0,0}};settings.unk8=table;
    CHECK(func_80102394(actor)==table && func_801023E4(actor,1)==2 && func_8010203C(actor,1)==2);
    CHECK(func_801021BC(actor,0) && !func_801021BC(actor,3) && func_80101F64(actor,0));
    func_80102424(actor,0);AnimCtrl *c=func_80104248(actor);CHECK(c && func_801022E4(actor)==151 && func_80101D0C(actor)==1);
    CHECK(anctrl_getPlaybackType((u8 *)c)==2 && (actor->flags74&(1u<<27)));
    func_8008ADE4(c);CHECK(func_80101F24(actor)>0.09f && func_80101F24(actor)<0.11f);
    f32 times[]={0.9f,0.05f,-1};CHECK(func_80101E14(actor,0.05f) && func_80101E4C(actor,times)==2);
    f32 before=func_80101F24(actor);func_80101FDC(actor,0);CHECK(func_80101F24(actor)==before);
    func_80101FDC(actor,1);CHECK(func_801022E4(actor)==152 && func_80101F24(actor)==0);
    func_80101EE4(actor,0.4f);CHECK(func_80101F24(actor)==0.4f && c->previous_timer==0.4f && func_80102320(actor,0.4f,0.4f));
    CHECK(!func_80102320(actor,0.5f,1));func_80101D4C(actor);CHECK(anctrl_getPlaybackType((u8 *)c)==1);
    func_80101D7C(actor);CHECK(anctrl_getPlaybackType((u8 *)c)==2);func_80101DAC(actor,0);func_80101DAC(actor,1);
    func_80102078(actor,0x3F000000);CHECK(c->transition_duration==0.5f);func_801020A8(actor);CHECK(c->transition_duration==0.2f);
    func_801020DC(actor,2);CHECK(!(c->flags&0x40));func_801020DC(actor,1);CHECK(c->flags&0x40);
    table[0].flags=1|0x100|0x10|0x20|0x40|0x200;func_80102424(actor,0);
    CHECK(!(actor->flags74&(1u<<27)) && !(c->flags&4) && !func_80101F24(actor));
    table[0].flags=2|0x80;func_80102424(actor,0);CHECK(anctrl_getPlaybackType((u8 *)c)==1 && func_80101F24(actor)==0.999f);
    table[0].flags=4|0x400|0x800;chance_result=0;func_80102424(actor,0);CHECK(anctrl_getPlaybackType((u8 *)c)==3 && func_80101F24(actor)==0.25f);
    chance_result=1;func_80102424(actor,0);phase_result=3;
    CHECK(!func_80102128(actor,10,2,0.5f,1));CHECK(func_80102128(actor,10,3,0.5f,1) && actor->unk70_10==1);
    chance_result=0;CHECK(!func_80102128(actor,10,3,0.5f,0));chance_result=1;
    CHECK(func_80102128(actor,10,3,0.5f,-1) && actor->unk70_10==1);
    Vec3s32 duration={2,-0.01f,0.5f};boost=0;func_801026CC(actor,duration,50);CHECK(c->duration==2);
    func_801026CC(actor,duration,200);CHECK(c->duration==1);boost=1;func_801026CC(actor,duration,200);CHECK(c->duration==0.5f);boost=0;
    actor->unk79_3=1;CHECK(func_80102394(actor)==dynamic_animations);func_80102424(actor,0);CHECK(func_801022E4(actor)==152);actor->unk79_3=0;
    func_80102424(actor,3);CHECK(!actor->animation_handle && !func_801022E4(actor) && !func_80101F24(actor) && !func_80101DDC(actor));
    settings.unk8=NULL;CHECK(!func_80101BE0(actor,0) && !func_8010203C(actor,0) && !func_801023E4(actor,0));
    cleanup();
}
static void test_animation_render(void) {
    reset();Actor *actor=spawn(0);NativeActorAnimation table[]={{1,151,1}};settings.unk8=table;
    actor->flags70=1u<<24;func_80102424(actor,0);func_80101EE4(actor,0.5f);
    native_render.pose=(void *)actor;native_render.data.animation=native_render.scratch;func_80102204(actor);
    NativeVertexList *front=func_80103C94(actor),*back=func_80103D24(actor);
    CHECK(!func_800DF324() && !native_render.data.animation && front!=back);
    CHECK(native_render.scratch->count==1 && fabsf(native_render.scratch->matrices[0].m[3][0]-1.5f)<0.0001f);
    CHECK(front->vertices[0].v.ob[0]==-98 && front->vertices[0].v.ob[1]==0 && front->vertices[0].v.ob[2]==-100);
    for(int i=0;i<3;++i)for(int axis=0;axis<3;++axis)CHECK(front->vertices[i].v.ob[axis]==back->vertices[i].v.ob[axis]);
    actor->flags70&=~(1u<<24);func_80102204(actor);CHECK(!func_800DF324() && !native_render.data.animation);
    CHECK(!func_8010262C(actor->unk0,2));
    s16 handle=func_800AE020();actor->unk0->unk10=(u32)(u16)handle<<16|0xBEEF;
    CHECK(!func_8010262C(actor->unk0,0));
    Unkfunc_800E0960_1 *expr=func_8010262C(actor->unk0,2);CHECK(expr && expr->unk6==2 && expr->unkC==1);
    func_800E0C20(expr,0,1,10,20,30);CHECK(expr->unk4==1);
    CHECK(func_8010262C(actor->unk0,2)==expr && !expr->unk4 && !expr->unkA && expr->unkC==1);
    func_800ADFE0(handle);actor->unk0->unk10&=0xFFFF;cleanup();
}
static void test_animation_archive(void) {
    reset();Actor *actor=spawn(0);NativeActorAnimation table[]={{1,0,0x201}};settings.unk8=table;
    int count=0,samples=0,model_id=0,model_bones=0;
    for(int id=1;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=0 || native_asset_packed_size(id)<=0)continue;
        u8 *model=(void *)func_800D674C(id);CHECK(model);
        NativeSkeleton *s=(NativeSkeleton *)func_800B27E0(model);
        if(s && s->count>model_bones && func_800B26F0(model)){model_id=id;model_bones=s->count;}
        func_800D62E4(id);func_800D6CEC(id);func_800D5E74();func_800D5E74();
    }
    CHECK(model_id);actor->unk0->unk14=model_id;
    for(int id=1;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=6 || native_asset_packed_size(id)<=0)continue;
        table[0].index=id;func_80102424(actor,0);CHECK(func_801022E4(actor)==id);
        for(int step=0;step<4;++step) {
            func_80101EE4(actor,0.25f*step);func_8008ADE4(func_80104248(actor));func_8008BA5C();
            func_8008B304(func_80104248(actor));BoneTransformList *pose=func_8008B4D4(func_80104248(actor));
            CHECK(pose && pose->ptr && pose->count>0);
            for(int bone=0;bone<pose->count;++bone) {
                for(int axis=0;axis<4;++axis)CHECK(isfinite(pose->ptr[bone].unk0[axis]));
                for(int axis=0;axis<3;++axis)CHECK(isfinite(pose->ptr[bone].scale[axis]) && isfinite(pose->ptr[bone].unk1C[axis]));
            }
            func_80102204(actor);CHECK(native_render.scratch && native_render.scratch->count>0);
            for(int i=0;i<native_render.scratch->count;++i)for(int row=0;row<4;++row)for(int col=0;col<4;++col)
                CHECK(isfinite(native_render.scratch->matrices[i].m[row][col]));
            CHECK(func_80103C94(actor));++samples;
        }
        func_800D6CEC(id);++count;
    }
    CHECK(count>0);cleanup();
    printf("Original actor animations: %d resources, %d poses through controllers, skeleton and vertex deformation (model %d).\n",count,samples,model_id);
}
int main(int argc,char **argv) {
    CHECK((argc==2 || argc==3) && native_assets_open(argv[1]));
    if(argc==3)test_animation_archive();
    else {test_buffers();test_activation();test_frame();test_resources_and_delete();test_purge();test_constructor();test_animation_pool();test_animation_states();test_animation_render();}
    func_8008B64C();func_80100610();native_assets_shutdown();
    puts("native actor lifecycle: buffers, activation, frame callbacks, model/items and deferred deletion passed");return 0;
}
