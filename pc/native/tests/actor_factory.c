#include "native_actor.h"
#include "native_map.h"
#include "native_cube.h"
#include "marker_world.h"
#include "native_spawn_queue.h"
#include "native_spline.h"
#include "native_assets.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x); exit(1); } } while(0)

/* Metadata selection, components and rendering are fixtures. */
static ActorData metadata;

static int modes, mode_calls, setup_calls, zone_calls, zone_enabled, hidden;
static int buffer_sizes[2], initial_state, fade_reads, fade_writes, released, flagged;
static int enabled_calls, component_calls, model_calls, animation_calls, body_calls;
static int collision_mode, collision_enabled;
static int loaded_maps;
void func_800CE308(void) { ++loaded_maps; }
s32 func_8001211C(void) { return 100; }
static ActorData *factory(void) { return &metadata; }
static ActorData *empty_factory(void) { return NULL; }
NativeActorFactory _gemarkersDll_entrypoint_0(s32 id) { return id==42 ? factory : id==43 ? empty_factory : NULL; }
u32 *func_80100074(void *actor,u32 slot,u32 size) { CHECK(actor && slot<2); buffer_sizes[slot]=size; return NULL; }
s32 _subaddieDll_entrypoint_1(void *actor) { CHECK(actor); ++enabled_calls; return 0; }
void func_8010A800(void *actor,s32 mode) { CHECK(actor && mode>=0 && mode<=4); modes|=1<<mode; ++mode_calls; }
void func_8010A63C(void *actor) { CHECK(actor); ++setup_calls; }
void func_800F31FC(u8 *color,s32 r,s32 g,s32 b,s32 a) { color[0]=r; color[1]=g; color[2]=b; color[3]=a; }
void func_80102424(void *actor,s32 state) { CHECK(((Actor *)actor)->unk70_10==state); initial_state=state; }
void func_80103930(void *actor) { CHECK(actor); ++component_calls; }
void func_8010A3E8(void *actor,f32 scale) { CHECK(actor && scale==1); ++animation_calls; }
void func_80106E88(void *actor) { CHECK(actor); ++model_calls; }
void func_80104F2C(void *actor,s32 first,s32 second) { CHECK(actor); ++body_calls; collision_mode=first; collision_enabled=second; }
void *_dbvpl_entrypoint_0(void *data,s32 index) { CHECK(0);return NULL; }
void _subaddiezone_entrypoint_0(void *actor) { CHECK(actor); ++zone_calls; }
void func_8010381C(Actor *actor) { CHECK(actor); ++hidden; }

void _subaddiefade_entrypoint_9(Actor *actor,s32 *out) { CHECK(actor); out[0]=10; out[1]=20; out[2]=30; ++fade_reads; }
void _subaddiefade_entrypoint_11(Actor *actor,s32 *in) { CHECK(actor && in[0]==10 && in[1]==20 && in[2]==30); ++fade_writes; }
void func_80108F08(void *a,void *b,s32 c) { (void)a;(void)b;(void)c; CHECK(0); }
static OSThread *marker_callback(void) { return (OSThread *)&metadata; }
s32 func_800DA298(s32 flag) { return flag==99; }
void func_800FFAB0(Actor *actor) { CHECK(actor); ++flagged; actor->unk64_17=1; }
void func_800819B4(void *entry) { CHECK(entry==(void *)factory); ++released; }
static uintptr_t pending_marker;
s32 func_800FF564(void) { CHECK(!func_80106730()); return 0; }
void func_800CB9D8(void) { }
static int delivered, message, message_value;
static intptr_t observe_event(Actor *actor,s32 id,uintptr_t value) { CHECK(actor->unk0==(Unk80132ED0 *)pending_marker); ++delivered;message=id;message_value=value;return 1; }
static u32 world_nodes[4][5];
void *_gccubesearch_entrypoint_17(s32 id,void *unused) { CHECK(!unused); return id>=1 && id<=4 ? world_nodes[id-1] : NULL; }
void _gspropctrl_entrypoint_9(void *node,s32 *position) { CHECK(node==world_nodes[1]); position[0]=10;position[1]=0;position[2]=0; }
u32 func_800E6A00(void) { return 0; }
static void set_metadata(u32 flags,u32 second) {
    metadata=(ActorData){.unk0=12,.unk2=0x123,.unk4=-1,.unk6=3,.unk18=0x12340000,.unk22=17,
        .unk24=flags>>16,.unk26=flags,.unk30=8,.unk32=12,.unk38_func=func_80107C2C,
        .unk3C=second>>16,.unk3E=second};
}
static Actor *spawn(void) { s32 position[]={11,-22,33}; return func_80108454(42,position,(u32)-90); }
static void clear_actors(void) {
    while(func_80106730()) { Actor *actor=func_80106768(func_80106730()-1);func_80105634(actor);func_800EBFF4(actor->unk0);func_801066C0(func_80106730()-1); }

}
static void test_constructor(void) {
    set_metadata(0,0);
    Actor *actor=spawn(); CHECK(actor && func_80106790(actor->unk0)==actor);
    NativeMarkerProp *prop=(void *)actor->unk0->unk0;
    CHECK(prop->marker==actor->unk0 && prop->position[0]==11 && prop->position[1]==-22 && prop->position[2]==33);
    CHECK(actor->factory==factory && actor->position[0]==11 && actor->position[1]==-22 && actor->position[2]==33);
    CHECK(actor->rotation[1]==-90 && actor->unk54==-90 && actor->scale==1 && actor->unk14==0x4A0021);
    CHECK(actor->flags64==0x50000 && actor->flags6C==(0x123<<9));
    CHECK(actor->flags70==(0x100000|(3<<10)) && actor->flags74==0x080B0000);
    CHECK(actor->flags7A==0x4000 && actor->flags7C==0x12344000 && actor->pad94==0);
    CHECK(actor->pad5C==99 && actor->pad5D==99 && actor->pad5E==99);
    CHECK(actor->pad98==255 && actor->pad99==255 && actor->pad9A==255 && actor->alpha==255);
    CHECK((actor->unk0->unk24>>22)==12 && (((NativeMarkerProp *)actor->unk0->unk0)->flags&2) && !(actor->unk0->unk10&1) && actor->unk0->unk14==0xFFFF && actor->unk0->unk16==17);
    CHECK(buffer_sizes[0]==8 && buffer_sizes[1]==12 && initial_state==3 && modes==1 && mode_calls==1);
    CHECK(component_calls==1 && animation_calls==1 && model_calls==1 && body_calls==1);
    CHECK(actor->unk0->callback==func_80107C20);
    void (**callbacks)(void *,void *,s32)=(void *)func_80107C20();
    for(int i=0;i<8;++i) CHECK(callbacks[i]==(i==3 ? func_80108F08 : NULL));
    metadata.marker_callback=marker_callback; metadata.shadow_scale=2;
    actor=spawn(); CHECK(actor->unk0->callback==marker_callback && (actor->flags74&(1u<<20)) && (actor->pad94&(1u<<16)));
    int count=func_80106730(), occupied_count=0;
    void *occupied[200], *slot;
    while ((slot=func_800EBD78())) occupied[occupied_count++]=slot;
    CHECK(occupied_count==200-count && !spawn() && func_80106730()==count);
    CHECK(buffer_sizes[0]==0 && buffer_sizes[1]==0);
    for(int i=0;i<occupied_count;++i) func_800EBE24(occupied[i]);
    s32 position[3]={0}; CHECK(!func_80108454(41,position,0) && !func_80108454(43,position,0));
    metadata.unk38_func=NULL;CHECK(!spawn());set_metadata(0,0);
    clear_actors();
}
static void test_constructor_flags(void) {
    struct Case {u32 meta;unsigned word,bit;} cases[]={
        {0x800000,70,21},{8,70,24},{0x200000,64,25},{0x4000000,70,22},{0x8000000,70,18},
        {0x80000004,64,31},{0x80000008,64,30},{0x80000400,70,17},{0x80001000,70,16},
        {0x80002000,74,5},{0x80004000,0x7C,13},{0x80000100,74,26},{0x80100000,74,23},
        {0x80000001,64,24},{0x80400000,94,31},{0x80800000,94,30},{0x80000040,70,2},
        {0x80200000,94,17},{0x84000000,94,14},{0x80000080,70,19}
    };
    for(int i=0;i<ARRLEN(cases);++i) {
        u32 flag=cases[i].meta;set_metadata(flag&0x80000000 ? 0 : flag,flag&0x80000000 ? flag : 0);
        Actor *actor=spawn();u32 word=cases[i].word==64 ? actor->flags64 : cases[i].word==70 ? actor->flags70 : cases[i].word==74 ? actor->flags74 : cases[i].word==94 ? actor->pad94 : actor->flags7C;
        CHECK(word&(1u<<cases[i].bit));
    }
    set_metadata(0x40000811,0x80040010);zone_enabled=1;native_map.zone_state=&zone_enabled;
    int before=enabled_calls;Actor *actor=spawn();CHECK(enabled_calls==before+1 && setup_calls && zone_calls);
    CHECK(actor->unk79_3 && (actor->flags7A&2) && collision_mode && collision_enabled);
    CHECK(!(actor->unk0->unk10&1));zone_enabled=0;native_map.zone_state=NULL;
    set_metadata(0x104,0x82000A02);actor=spawn();CHECK((actor->flags74&15)==1 && !(actor->flags74&(1<<17)));
    CHECK(!(actor->flags64&(1<<16)) && !(actor->flags7C&(1<<14)) && !(actor->pad94&(1<<16)) && !(actor->unk0->unk28&(1<<9)));
    set_metadata(0x400,0);actor=spawn();CHECK((actor->unk0->unk10&1));
    for(int mode=2;mode<=4;++mode) {
        set_metadata(mode==2 ? 0x20000 : mode==3 ? 0x400000 : 0,mode==4 ? 0x80008000 : 0);
        modes=0;spawn();CHECK(modes==(1|(1<<mode)));
    }
    clear_actors();
}
static void test_flag_copy(void) {
    Actor from={0},to={0};Prop prop={.unk12=(2<<2)|(1<<4)};
    from.flags70=8;func_80108658(&from,0x10000000,0x80090000,NULL);
    CHECK(from.pad7A_7==1 && (from.flags70&(1<<21)) && (from.flags74&(1<<25)) && (from.pad94&(1<<15)) && hidden==1);
    func_80108658(&from,0,0,&prop);CHECK(from.pad7A_7==2 && (from.flags74&(1<<6)) && !(from.flags74&(1<<25)) && !(from.pad94&(1<<15)));
    from.flags7A|=2;from.pad94|=1<<15;func_80108944(&to,&from);
    CHECK(to.pad7A_7==2 && (to.flags74&(1<<6)) && (to.flags7A&2) && (to.pad94&(1<<15)) && fade_reads==1 && fade_writes==1);
    native_map.lighting_type=0;func_801088A8(&to,0x30000000,0x80090000,&prop);CHECK(!to.pad7A_7 && !(to.flags74&((1<<6)|(1<<25))) && !(to.pad94&(1<<15)));
    native_map.lighting_type=1;func_801088A8(&to,0x30000000,0x80090000,&prop);CHECK(to.pad7A_7==3 && (to.flags74&(1<<25)) && (to.pad94&(1<<15)));
}
static void test_wrappers(void) {
    set_metadata(0,0);Actor *owner=spawn();Unk80132ED0 *marker=owner->unk0;
    for(int i=0;i<80;++i) {
        Actor *child=func_801084B0(42,&owner);
        CHECK(owner==func_80106790(marker) && child && child->position[0]==11 && child->rotation[1]==-90);
    }
    f32 position[]={-1.75f,2.9f,3.1f};Actor *actor=func_80108528(42,position,55,&owner);
    CHECK(actor && actor->position[0]==-1 && actor->position[1]==2 && actor->position[2]==3 && actor->rotation[1]==55);
    CHECK(owner==func_80106790(marker));s16 small[]={-300,12,32767};actor=func_801085CC(42,small,45);
    CHECK(actor && actor->position[0]==-300 && actor->position[2]==32767);
    func_80108A30(42,position,12.75f,7);CHECK(((NativeSpawnQueue *)func_800A5D60())->count==1);
    chbaddieDll_entrypoint_3(func_800A5D60());
    actor=func_80106768(func_80106730()-1);CHECK(actor->rotation[1]==12.75f && actor->unk74_7==7 && actor->position[0]==-1);
    int count=flagged;CHECK(!func_80108618(actor,98));CHECK(func_80108618(actor,99) && flagged==count+1);
    clear_actors();
}
static void deliver(void) { chbaddieDll_entrypoint_3(func_800A5D60()); }
static void test_messages(void) {
    set_metadata(0,0);metadata.unk40_func=observe_event;Actor *actor=spawn();pending_marker=(uintptr_t)actor->unk0;
    func_80108B04(actor,17);CHECK(!delivered);deliver();CHECK(delivered==1 && message==0x3D && message_value==17);
    func_80108B04(actor,19);actor->unk0->unk10+=2;deliver();CHECK(delivered==1);actor->unk0->unk10-=2;
    func_80108BD4(actor,23);deliver();CHECK(delivered==2 && message==0x59 && message_value==23);
    func_80108BD4(actor,24);func_800EBFF4(actor->unk0);func_801066C0(0);
    actor=spawn();CHECK((uintptr_t)actor->unk0==pending_marker);deliver();CHECK(delivered==2);
    clear_actors();
    for(int i=0;i<5;++i) spawn();metadata.unk20=99;int before=flagged;func_80108C14();CHECK(flagged==before+5 && released==5);
    metadata.unk20=0;func_80108C14();CHECK(flagged==before+5);clear_actors();
}
static Prop *expected_prop;
static int custom_calls;
static Actor *custom_spawn(s32 *position,s32 yaw,ActorData *data,NativeActorFactory entry,Prop *prop) {
    CHECK(position && yaw==77 && data==&metadata && entry==factory && prop==expected_prop);++custom_calls;
    return func_80107C2C(position,yaw,data,entry,prop);
}
static void test_path_assignment(void) {
    typedef struct {
        s16 id;u8 count,mode,clock,padding[3];f32 length,loop;s16 ids,padding_end;f32 points[2][3];
    } Path;
    s16 func_8001B668(s32,s32);void *func_8001B798(s16);void func_8001B754(s16);
    s16 path_handle=func_8001B668(0,sizeof(Path)),events_handle=func_8001B668(0,sizeof(s32));
    *(Path *)func_8001B798(path_handle)=(Path){.count=2,.points={{0,0,0},{10,0,0}}};
    *(s32 *)func_8001B798(events_handle)=0;
    native_spline_context.handle0=func_8001B668(0,0);native_spline_context.handle1=func_8001B668(0,0);
    CHECK(func_800D7488(path_handle,events_handle)==0);
    world_nodes[0][1]=1;world_nodes[0][4]=2<<10;CHECK(func_80108CF4(1)==world_nodes[1]);
    world_nodes[0][4]=1<<10;CHECK(!func_80108CF4(1));world_nodes[0][4]=7<<10;CHECK(!func_80108CF4(1));
    world_nodes[0][4]=0;CHECK(!func_80108CF4(1));CHECK(!func_80108CF4(0));world_nodes[0][4]=2<<10;
    set_metadata(0,0);s32 position[3]={0};
    Actor *actor=func_80108DC0(42,position,77,1,0,NULL);NativeActorPathState *path=func_80105494(actor);
    CHECK(actor && path && ((path->first>>1)&0x3FF)==0 && path->time==0 && (actor->pad74_0&16));
    f32 pos[3]={0},rotation[]={30,77,0};actor=func_8010856C(42,pos,rotation);
    CHECK(actor && actor->rotation[0]==30 && actor->rotation[1]==77 && func_80105494(actor));
    CHECK(!func_8010856C(43,pos,rotation));
    pos[0]=8;actor=func_8010856C(42,pos,rotation);CHECK(actor && !func_80105494(actor) && !(actor->pad74_0&16));
    Prop prop={.unk10=5<<5,.unk12=(1<<1)|(2<<2)|(1<<4)};expected_prop=&prop;metadata.unk38_func=custom_spawn;
    actor=func_80108C90(42,position,77,&prop);
    CHECK(actor && custom_calls==1 && actor->pad6C_21==5 && actor->unk70_0 && actor->pad7A_7==2 && (actor->flags74&(1<<6)));
    clear_actors();func_8001B754(path_handle);func_8001B754(events_handle);
    func_8001B754(native_spline_context.handle0);func_8001B754(native_spline_context.handle1);
    native_spline_context=(NativeSplineContext){0};
}
static void test_archive_marker_kinds(const char *archive) {
    CHECK(native_assets_open(archive));
    unsigned kinds=0;
    for(s32 id=0;id<native_asset_count() && kinds!=3;++id) {
        unsigned kind=(native_asset_flags(id)&15)==7 ? 0 : 1;
        if(kinds&(1u<<kind)) continue;
        set_metadata(0,0);metadata.unk4=id;Actor *actor=spawn();
        CHECK(actor && ((((NativeMarkerProp *)actor->unk0->unk0)->flags>>1)&1)==kind && actor->unk0->unk14==id);
        kinds|=1u<<kind;
    }
    CHECK(kinds==3);clear_actors();native_assets_close();
    puts("Original asset metadata selects both actor marker kinds");
}
static void test_loaded_map_actor(void) {
    u8 bytes[]={10,0,0,0,1, 0,11,0,22,0,33, 0x0C,0x8C,0,42,0,0,
        0x26,0x80,0,0xFA,0,0,0,0, 8,0,0,0,0,1};
    GsFile *stream=gsmaker_entrypoint_4(bytes,sizeof(bytes));
    set_metadata(0,0);
    func_800BDC90(stream);CHECK(!stream->failed && loaded_maps==1);
    gsmaker_entrypoint_0(stream);
    CHECK(!func_80106730() && marker_world[1]->models[1]==1);
    func_800BDCB8();CHECK(func_80106730()==1);
    Actor *actor=func_80106768(0);
    CHECK(actor && actor->position[0]==11 && actor->position[1]==22 && actor->position[2]==33);
    CHECK(actor->rotation[1]==77 && actor->scale==2.5f && actor->unk74_7==25 && actor->unk7A_5);
    CHECK(actor->unk0 && ((NativeMarkerProp *)actor->unk0->unk0)->marker==actor->unk0);
    clear_actors();func_800E9C44(marker_world[1]);
}
int main(int argc,char **argv) {
    marker_world_reset();func_800EBB5C();func_800EBB94();
    func_800A5BE0();func_800A5C04();func_801065E0();func_80105410();
    test_constructor();test_constructor_flags();test_flag_copy();test_wrappers();test_messages();test_path_assignment();test_loaded_map_actor();
    CHECK(argc==1 || argc==2);if(argc==2) test_archive_marker_kinds(argv[1]);
    chbaddieDll_entrypoint_2(func_800A5D60());
    func_80105438();func_80106608();set_metadata(0,0);CHECK(!spawn());
    marker_world_cleanup();
    puts("Native actor constructor, metadata flags, wrappers, marker callbacks and deferred messages passed");return 0;
}
