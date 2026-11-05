#include "native_spline.h"
#include "native_actor.h"
#include "marker_world.h"
#include "native_spawn_queue.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "core2/anctrl.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#define CHECK(x) do { if (!(x)) { fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #x); exit(1); } } while (0)
typedef NativeActorPathState State;
typedef struct { f32 time; u32 w4, w8, wc, w10; } Node;
typedef struct { s32 count; Node nodes[3]; } Events;
typedef struct {
    s16 id;
    u8 count, mode, clock, padding[3];
    f32 length, loop;
    s16 ids, padding_end;
    f32 points[2][3];
} Path;
_Static_assert(sizeof(State) == 72 && offsetof(State, flags24) == 0x24, "shared path state layout");
_Static_assert(sizeof(Node) == 20 && offsetof(Path, points) == 20, "path data layout");
s16 func_8001B668(s32, s32);
void *func_8001B798(s16);
void func_8001B754(s16);
static Actor *actor_pointer;
static Unk80132ED0 actor_marker;
#define actor (*actor_pointer)
static State *path_state;
#define state (*path_state)
static AnimCtrl *controller;
static int forward, looped, flag_set, dialog_calls, clock_calls;
static int flag_ready, condition_ready;
/* World effects, metadata lookup, grid lookup and actor components remain controlled fixtures. */
static int completed, activated, path_updates;
void func_800FFAB0(Actor *a) { (void)a; ++completed; }
s32 func_8010B990(Actor *a, s32 flags) { (void)a; CHECK(flags==0x6000); ++path_updates; return 1; }
void func_8010A570(Actor *a) { CHECK(a==&actor); ++activated; }
static u32 intro_mode;
u32 func_800E6A00(void) { return intro_mode; }
f32 func_800D8FF8(void) { return 0.1f; }
f32 _glintrosyncDll_entrypoint_5(void) { ++clock_calls; return 0.2f; }
void func_80101D4C(Actor *a) { CHECK(a == &actor); ++forward; }
void func_80101D7C(Actor *a) { CHECK(a == &actor); ++looped; }
AnimCtrl *func_80104248(void *a) { CHECK(a == &actor); return controller; }
AnimCtrl *func_801042B8(Actor *a) { CHECK(a == &actor); controller = func_8008AD80(1); return controller; }
s32 _seqdat_entrypoint_0(s32 id, s32 unused) { CHECK(id == 7 && unused == 0); return 17; }
void func_800DA3B8(s32 flag, s32 value) { CHECK(value == 1); flag_set = flag; }
s32 func_800D035C(s32 x) { CHECK(x == 1); return 0; }
s32 func_800C04C8(s32 id, s32 kind, s32 value, s32 mode, void (*callback)(s32,s32,s32)) {
    CHECK(id == 37 && kind == 12 && value == 0xAB && mode == 0xC);
    callback(0,0,0); ++dialog_calls; return 1;
}
static Actor *spawned_pointer;
#define spawned (*spawned_pointer)
static Unk80132ED0 initial_spawn_marker;
static Unk80132ED0 *spawn_marker_pointer=&initial_spawn_marker;
#define spawn_marker (*spawn_marker_pointer)
static int spawn_calls, spawn_fail;
static Unk80132ED0 pressure_markers[120];
static int force_pool_growth;
static ActorData spawn_metadata={.unk0=42,.unk2=42,.unk4=-1,.unk38_func=func_80107C2C};
static ActorData *spawn_factory(void) { return &spawn_metadata; }
NativeActorFactory _gemarkersDll_entrypoint_0(s32 id) { CHECK(id==42); ++spawn_calls; return spawn_fail ? NULL : spawn_factory; }
u32 *func_80100074(void *a,u32 slot,u32 size) { CHECK(a && slot<2 && !size); return NULL; }
s32 _subaddieDll_entrypoint_1(void *a) { CHECK(a);return 0; }
void func_8010A800(void *a,s32 mode) { CHECK(a && mode==0); }
void func_8010A63C(void *a) { (void)a;CHECK(0); }
void func_8010381C(Actor *a) { (void)a;CHECK(0); }
void func_800F31FC(u8 *p,s32 a,s32 b,s32 c,s32 d) { p[0]=a;p[1]=b;p[2]=c;p[3]=d; }
void func_80102424(void *a,s32 state_id) { CHECK(a && state_id==0); }
void func_80103930(void *a) { CHECK(a); }
void func_8010A3E8(void *a,f32 scale) { CHECK(a && scale==1); }
void func_80106E88(void *a) { spawned_pointer=a; spawn_marker_pointer=spawned.unk0; }
void func_80104F2C(void *a,s32 first,s32 second) { CHECK(a && !first && !second); }
void _subaddiezone_entrypoint_0(void *a) { (void)a;CHECK(0); }
void func_80108F08(void *a,void *b,s32 c) { (void)a;(void)b;(void)c;CHECK(0); }

s32 _capod_entrypoint_16(f32 value) { CHECK(value == 3); return condition_ready; }
s32 _seqdefine_entrypoint_0(s32 id) { CHECK(id == 8); return 108; }
s32 func_800DA298(s32 id) { CHECK(id == 108); return flag_ready; }
s32 func_800DA524(s32 id) { CHECK(id == 108); return 0; }
void func_8008FE68(f32 *p) { p[0] = 10; p[1] = 20; p[2] = 30; }
void func_800A516C(f32 *out, f32 *target, f32 *origin) {
    CHECK(origin == actor.position); out[0] = target[1]; out[1] = target[0]; out[2] = 0;
}
static int fade_value, camera_mode, message_value, player_value, intro_calls, destroyed_actor;
void _subaddiefade_entrypoint_1(Actor *a,s32 value) { CHECK(a==&actor); fade_value=value; }
void func_8009086C(s32 value) { camera_mode=value; }
void func_80090708(s32 value) { camera_mode=value; }
s32 func_8008FFE8(void) { return 3; }
void func_8010FD38(s32 player,f32 value) { CHECK(player==3); player_value=value; }
void func_800DA544(s32 value) { message_value=value; }
void func_800A50B0(s32 value) { CHECK(value==2); }
void func_800FFA88(Unk80132ED0 *marker) { CHECK(marker==actor.unk0); ++destroyed_actor; }
void _chintrotext_entrypoint_1(s32 id,s32 value,s32 mode,s32 mode2) { CHECK(id==0x18BC && value==21 && mode==2 && mode2==2); ++intro_calls; }
static s16 target_coords[]={0,0,71,34,9};
static NativeMarkerProp target_prop={.position={71,34,9}};
static Unk80132ED0 target_marker;
static Actor target_actor;
Actor *_subaddiefind_entrypoint_12(s32 id) {
    target_marker.unk0=(u32 *)&target_prop; target_prop.marker=&target_marker;
    target_actor.unk0=&target_marker;
    return id==71 ? &target_actor : NULL;
}
void *_gccubesearch_entrypoint_17(s32 id,void *unused) { CHECK(unused==NULL); return id==72 ? target_coords : NULL; }
void _gspropctrl_entrypoint_10(void *prop,void *position) { CHECK(prop==target_coords); for(int i=0;i<3;++i) ((s16 *)position)[i]=target_coords[i+2]; }
static void flush_spawn_queue(void) {
    if(force_pool_growth) {
        for(int i=0;i<120;++i) {
            s32 index;
            Actor *extra=func_80106668(&index);
            extra->unk0=&pressure_markers[i];
            pressure_markers[i].unk18=0x10000u | ((u32)index<<5);
            func_8010556C(extra);
        }
        actor_pointer=func_80106790(&actor_marker);
        spawned_pointer=func_80106790(&spawn_marker);
        CHECK(actor_pointer && spawned_pointer);
    }
    chbaddieDll_entrypoint_3(func_800A5D60());
    if(force_pool_growth) {
        for(int i=119;i>=0;--i) {
            Actor *extra=func_80106790(&pressure_markers[i]);
            CHECK(extra);
            func_80105634(extra);
            func_801066C0((pressure_markers[i].unk18>>5)&0x7FF);
        }
        spawned_pointer=func_80106790(&spawn_marker);
        CHECK(spawned_pointer);
    }
}
s32 func_8001211C(void) { return 0; }
s32 func_800A9F14(s32 mode) { (void)mode; return 0; }
s32 func_800A9F30(void) { return 1; }

s32 glsplinenode_entrypoint_1(void *, Actor *, void *, void *);
void func_800D7754(Actor *, s32);
void func_800D7948(void *, s32, s32, s32);
s32 func_800D7DE8(Actor *);
s32 func_800D7E38(void *, s32, s32, s32, s32, s32);
s32 func_800D8070(void *, s32, s32, s32);
s32 func_800D8588(Actor *, s32, s32, s32);
static void near(float a, float b) { if (!isfinite(a) || fabsf(a-b) >= 0.001f) { fprintf(stderr, "actual %g, expected %g\n", a,b); abort(); } }
static void reset(void) {
    func_80105634(&actor);
    rare_memset(&actor, 0, sizeof(actor)); actor.unk0=&actor_marker; actor.unk14 = 0x12345678; actor.scale = 2;
    path_state=func_8010556C(&actor);
    CHECK(path_state && state.first==(0x3FF<<1) && state.flags28==(7u<<29));
    near(state.speed,100);
    rare_memset(&state,0,sizeof(state)); state.speed=10;
}
static void dispatch(Node *node, Events *events) {
    CHECK(glsplinenode_entrypoint_1(&native_spline_context, &actor, node, events) == 0);
}
static void test_lifecycle(void) {
    Actor actors[64] = {0};
    intro_mode=1;
    CHECK(((State *)func_8010556C(&actors[0]))->flags18==(1u<<30));
    func_80105634(&actors[0]); intro_mode=0;
    for (int i=0;i<64;++i) {
        actors[i].pad74_0=3;
        func_801058C4(&actors[i],0,10+i,0);
        CHECK(actors[i].unk7C_0 && (actors[i].pad74_0 & 16));
    }
    func_8010545C();
    for (int i=0;i<64;++i) {
        CHECK(func_8010568C(&actors[i],0)); near(func_80105AC4(&actors[i]),10+i);
        ((State *)func_80105494(&actors[i]))->first |= 0xABFF0000u;
        func_801056EC(&actors[i],.4f); near(actors[i].position[0],4);
        CHECK(func_80105998(&actors[i],.2f)); CHECK(!func_80105998(&actors[i],.4f));
        func_8010573C(&actors[i],1); CHECK(func_80105A5C(&actors[i]));
        near(func_80105AE8(&actors[i]),1); near(func_80105B0C(&actors[i],0),90);
        func_80105A9C(&actors[i],-5); near(func_80105AC4(&actors[i]),-5);
        func_80105BAC(&actors[i]); func_80105BE0(&actors[i],1);
        CHECK(((State *)func_80105494(&actors[i]))->flags18==(1u<<31));
        CHECK(((State *)func_80105494(&actors[i]))->flags24==32);
        func_80105634(&actors[i]); CHECK(!func_80105494(&actors[i])); CHECK(actors[i].pad74_0==3);
        func_80105634(&actors[i]);
    }
    CHECK(!func_8010568C(&actors[0],1)); CHECK(completed==1);
}
static void test_nodes(Events *registered) {
    Events events = {.count = 2};
    Node node = {0};
    reset();
    node.wc = (5u << 24) | 1; native_spline_context.value0 = 83;
    dispatch(&node, &events);
    CHECK(state.first == 5u << 24); near(state.timer, 83);
    node.w4 = (0x1234u << 16) | (6 << 1); node.wc = 1;
    dispatch(&node, &events); CHECK(flag_set == 0x1234);
    node.w4 = (20 << 16) | 0xABC0 | (7 << 1);
    node.wc = (1 << 21) | (37 << 13) | 1; node.w10 = (12 << 4) | 8;
    dispatch(&node, &events);
    CHECK(actor.unk79_1 && !actor.unk79_0 && dialog_calls == 1);
    near(*(f32 *)&actor.actorData[0], 5); near(*(f32 *)&actor.actorData[1], 0);
    node.w4 |= 1u << 31; dispatch(&node, &events);
    CHECK(!actor.unk79_1 && actor.unk79_0);
    registered->count=1;
    registered->nodes[0]=(Node){.time=.6f,.w4=1|(7<<4)|(45<<7),.wc=123u<<23,.w10=9<<21};
    node = (Node){.w4 = 0, .wc = (9 << 1) | 1};
    CHECK(glsplinenode_entrypoint_1(&native_spline_context, &actor, &node, &events) == 2);
    near(state.time, .6f); near(actor.position[0], 6); near(actor.unk54,123); near(actor.unk50,45);
    node.wc=(99<<1)|1;
    CHECK(!glsplinenode_entrypoint_1(&native_spline_context,&actor,&node,&events));
    near(state.time,.6f); near(actor.position[0],6);
    for (int type = 2; type <= 6; ++type) {
        node = (Node){.w4 = (type << 1) | (7 << 4), .wc = (90u << 23)};
        dispatch(&node, &events);
        CHECK(((state.flags28 >> 26) & 3) == (type < 4 ? 0 : type < 6 ? 1 : 2));
        CHECK(type == 6 || ((state.speed < 0) == (type == 3 || type == 5)));
        near(actor.unk54, 90);
    }
    CHECK(forward == 2 && looped == 2);
    node = (Node){.w4 = 2 << 18, .w8 = 1 << 8, .wc = 20 << 1};
    dispatch(&node, &events); near(state.delay, 5); CHECK(state.flags28 >> 29 == 6);
    node.w10 = 1 << 7; node.wc = 108 << 1; dispatch(&node,&events);
    CHECK(((state.flags24 >> 9) & 15) == 3);
    node = (Node){.w8 = (7u << 22) | (8 << 11) | (1 << 10)};
    dispatch(&node,&events); CHECK(state.flags24 >> 17 == 17); near(state.duration,2);
    CHECK(controller != NULL && anctrl_getIndex(controller) == 17); near(controller->duration,2);
    node = (Node){.w4 = (15 << 21) | (3 << 16)};
    dispatch(&node,&events); /* An absent link must never read past the list. */
    CHECK(state.end == 0);
    reset();
    events.nodes[0] = (Node){.time=.2f,.w4=(15<<21)|(3<<16)|(20<<7),.wc=(30u<<23)};
    events.nodes[1] = (Node){.time=.8f,.w4=40<<7,.wc=(60u<<23)|(8<<12),.w10=15<<21};
    dispatch(&events.nodes[0],&events);
    near(state.start,.2f); near(state.end,.8f); near(state.start_speed,10); near(state.end_speed,1);
    CHECK(state.angles40 == (60u<<23 | 30<<14 | 20<<5)); CHECK(state.angles44 == (3u<<29 | 40<<20));
    state.time=.5f; func_800D7948(&actor,0x1800,0,0);
    near(actor.unk54,45); near(actor.unk50,30); near(state.speed,5.5f);
    CHECK(actor.unk14 == 0x12345678 && actor.scale == 2);
}
static void test_targets(void) {
    NativeSplineTarget targets[7] = {0};
    reset();
    native_spline_context.cache = targets;
    targets[0].fixed = 1; targets[0].position[0] = 71; targets[0].position[1] = 34;
    state.flags24 = 1 << 6;
    func_800D7948(&actor,0,0,0); near(actor.unk54,71); near(actor.unk50,34);
    state.flags24 = 1 << 13;
    func_800D7948(&actor,0,0,0); near(actor.unk54,10); near(actor.unk50,20);
    state.flags24 = 0; state.flags28 = 5; actor.position[0] = 42; actor.position[1] = 17;
    func_800D87D4(&actor,5);
    func_800D7948(&actor,0,0,0); near(actor.unk54,42); near(actor.unk50,17);
    CHECK(actor.unk0 == &actor_marker && actor.unk14 == 0x12345678);
    native_spline_context.cache = NULL; native_spline_context.actors[5] = NULL;
    func_800D7948(&actor,0,0,0); near(actor.unk54,42); near(actor.unk50,17);
    Unk80132ED0 stale={.unk18=0x10000};
    native_spline_context.actors[5]=&stale;
    func_800D7948(&actor,0,0,0); near(actor.unk54,42); near(actor.unk50,17);
    native_spline_context.actors[5]=NULL;
}
f32 func_80013728(f32);
static void test_angles(void) {
    near(func_80013728(180),-180); near(func_80013728(-180),-180);
    near(func_80013728(540),-180); near(func_80013728(-540),-180);
    near(func_80013728(359),-1); near(func_80013728(-359),1);
    near(func_80013728(720),0); near(func_80013728(-720),0);
}
static void test_motion(Events *events) {
    reset(); events->count=0;
    CHECK(func_800D8070(&actor,0x300,0,0)); near(state.time,.1f); near(actor.position[0],1);
    near(state.previous,0); CHECK(state.first & 1); CHECK(actor.unk14==0x12345678);
    state.flags18 = 1u<<30; state.delay=.3f;
    CHECK(func_800D8070(&actor,0x300,0,0)); near(state.delay,.1f); near(state.time,.1f);
    CHECK(func_800D8070(&actor,0x300,0,0)); near(state.delay,0); CHECK(clock_calls==2);
    state.flags28 = (9<<7) | (1<<6); flag_ready=0;
    CHECK(func_800D8070(&actor,0x300,0,0)); near(state.time,.1f);
    flag_ready=1; CHECK(func_800D8070(&actor,0x300,0,0)); CHECK(state.flags28==0);
    state.flags28 = 8<<18; native_spline_context.counters[7]=1;
    CHECK(func_800D8070(&actor,0x300,0,0)); CHECK(state.flags28);
    native_spline_context.counters[7]=0; CHECK(func_800D8070(&actor,0x300,0,0)); CHECK(!state.flags28);
    state.pod=3; condition_ready=1; CHECK(func_800D8070(&actor,0x300,0,0)); CHECK(!state.pod);
    u32 commands[]={0x10005,0,0x300001,0,2}; s32 offsets[]={0};
    native_spline_context.commands=commands; native_spline_context.offsets=offsets;
    native_spline_context.command_size=sizeof(commands); native_spline_context.unk1A0=1;
    state.first|=1u<<24; CHECK(func_800D8588(&actor,0x300,0,0));
    CHECK(actor.unk64_19 && !(state.first>>24));
    native_spline_context.commands=NULL; native_spline_context.offsets=NULL;
    reset(); events->count=2;
    events->nodes[0]=(Node){.time=.25f,.w4=(31<<16)|(6<<1),.wc=1};
    events->nodes[1]=(Node){.time=.75f,.w4=(47<<16)|(6<<1),.wc=1,.w10=1};
    CHECK(func_800D7E38(&actor,0,0,2,0,1)==0); CHECK(flag_set==31);
    CHECK(func_800D7E38(&actor,0,-9999,-1,0,-1)==0); CHECK(flag_set==47);
    flag_set=0; state.time=.2f;
    CHECK(func_800D8070(&actor,0x300,0,0)); CHECK(flag_set==31); near(state.time,.3f);
    state.time=.8f; state.speed=-10; flag_set=0;
    CHECK(func_800D8070(&actor,0x300,0,0)); CHECK(flag_set==47); near(state.time,.7f);
    func_800D7754(&actor,7); CHECK(func_800D7DE8(&actor)==0x1800);
    func_800D7754(&actor,6); CHECK(func_800D7DE8(&actor)==0x300);
    CHECK(func_800D7E38(&actor,0,0,2,0,0)==0);
    state.first = 0x3FF << 1; CHECK(!func_800D8070(&actor,0x300,0,0));
    state.first = 0; state.flags28 = 255 << 18;
    CHECK(!func_800D8070(&actor,0x300,0,0));
    reset(); events->count=0;
    
    func_80105BAC(&actor); func_8010588C(&actor);
    CHECK(activated==1 && path_updates==1 && (actor_marker.unk28 & (1<<10)));
    near(actor.position[0],1);
    func_801056EC(&actor,1); func_80105BE0(&actor,1);
    CHECK(func_801054D4(&actor)); CHECK(completed==2 && path_updates==2);
    actor.unk0=NULL;
}
static void test_path_lookup(Events *first, Events *second) {
    s32 path=-1; f32 t=-1,pos[3]={-1,-1,-1},yaw,pitch;
    *first=(Events){.count=1,.nodes={{.time=.6f,.w4=1|(7<<4)|(45<<7),.wc=123u<<23,.w10=9<<21}}};
    *second=(Events){.count=1,.nodes={{.time=.4f,.w4=1|(7<<4)|(11<<7),.wc=70u<<23,.w10=9<<21}}};
    CHECK(glsplinefuncs_entrypoint_0(9,&path,&t,pos,1,&yaw,&pitch));
    CHECK(path==1); near(t,.4f); near(pos[0],14); near(yaw,70); near(pitch,11);
    CHECK(glsplinefuncs_entrypoint_0(9,&path,&t,pos,-1,&yaw,&pitch));
    CHECK(path==0); near(pos[0],6);
    first->count=0;
    CHECK(glsplinefuncs_entrypoint_0(9,&path,&t,pos,0,&yaw,&pitch)); CHECK(path==1);
    glsplinefuncs_entrypoint_1(42,(SplineSpawnWord){9|(5<<12)},1);
    CHECK(spawn_calls==1 && func_800D87EC(5)==&spawn_marker);
    NativeActorPathState *s=func_80105494(&spawned);
    CHECK(s && ((s->first>>1)&0x3FF)==1 && (spawned.pad74_0 & 16));
    near(s->time,.4f); near(spawned.position[0],14); near(spawned.unk50,11); near(spawned.rotation[1],70);
    CHECK(spawned.unk14==0x4A0021);
    glsplinefuncs_entrypoint_1(42,(SplineSpawnWord){99},1); CHECK(spawn_calls==1);
    glsplinefuncs_entrypoint_1(42,(SplineSpawnWord){9|(63<<12)},1); CHECK(spawn_calls==1);
    spawn_fail=1; glsplinefuncs_entrypoint_1(42,(SplineSpawnWord){9},1); CHECK(spawn_calls==2);
    func_80105634(&spawned); native_spline_context.actors[5]=NULL;
    first->count=second->count=3;
    for(int i=0;i<3;++i) {first->nodes[i].w10=(i+1)<<21;second->nodes[i].w10=(i+1)<<21;}
    path=81; t=.123f;
    CHECK(!glsplinefuncs_entrypoint_0(99,&path,&t,pos,0,&yaw,&pitch));
    CHECK(path==81); near(t,.123f); near(yaw,-9999); near(pitch,-9999);
    CHECK(!glsplinefuncs_entrypoint_0(1,&path,&t,pos,2,&yaw,&pitch));
    native_spline_context.count=0;
    CHECK(!glsplinefuncs_entrypoint_0(1,&path,&t,pos,-1,&yaw,&pitch));
    native_spline_context.count=2;
}
#define CMD(op,value) (((u32)(op)<<16) | ((value)&0xFFFF))
static s32 script_offset;
static void install_script(u32 *commands,s32 words,f32 clock) {
    NativeSplineContext *c=&native_spline_context;
    c->commands=commands; c->offsets=&script_offset; c->command_size=words*4; c->unk1A0=1; c->value0=clock;
    script_offset=0; state.first=(state.first & 0x7FF) | (1u<<24); state.timer=state.elapsed=0;
}
static void run_script(void) { glsplinecs_entrypoint_1(&native_spline_context,&actor); }
static void test_script_actions(void) {
    u32 commands[]={0x10005,
        0,CMD(9,7),0,CMD(7,123),0,CMD(8,45),0,CMD(0x30,1),0,CMD(0x38,1),
        0,CMD(0x36,3),0,CMD(0x37,9),0,CMD(0x28,0xFFF8),0,CMD(0x31,11),
        0,CMD(0x35,1),0,CMD(0x34,0),0,CMD(0x1E,0),0,CMD(0x2F,1),0,CMD(0x2E,13),
        0,CMD(0xD,1),0,CMD(0xC,4),0,CMD(0x33,21),0,CMD(0x1B,0x4008),
        0,CMD(0x29,37),(12u<<24)|(12<<16)|0xAB,
        0,CMD(0xE,7),8000000,0,CMD(0xF,0),2000000,0,CMD(0x10,0),0,CMD(0x11,0),0,2};
    reset(); install_script(commands,ARRLEN(commands),0); run_script();
    CHECK(!(state.first>>24)); near(actor.unk54,123); near(actor.unk50,45);
    CHECK(actor.unk64_19 && actor.unk64_18 && actor.unk7A_11==3 && (actor.pad74_0&15)==9);
    CHECK(actor.unk79_1 && !actor.unk79_0); near(*(f32 *)&actor.actorData[0],2);
    CHECK(fade_value==11 && player_value==5 && camera_mode==13 && message_value==0x644 && intro_calls==1);
    CHECK(flag_set==108 && state.flags28>>29==4 && (state.flags24&32));
    CHECK(anctrl_getIndex(controller)==17); near(controller->duration,2); near(controller->transition_duration,.5f);
    CHECK(controller->playback_type==2);
}
static void test_script_time(void) {
    u32 timed[]={0x10005,10,CMD(7,90),20,CMD(8,45),0,2};
    reset(); func_800D7754(&actor,7); install_script(timed,ARRLEN(timed),9); run_script();
    CHECK(state.first>>24==1 && ((state.first>>11)&0x1FFF)==1); near(actor.unk54,0);
    native_spline_context.value0=10; run_script(); near(actor.unk54,90);
    CHECK(((state.first>>11)&0x1FFF)==3);
    native_spline_context.value0=20; run_script(); near(actor.unk50,45); CHECK(!(state.first>>24));
    u32 path_time[]={0x10006,2000000,CMD(0x30,1),0,2};
    reset(); state.time=.49f; install_script(path_time,ARRLEN(path_time),999); run_script(); CHECK(!actor.unk64_19);
    state.time=.5f; run_script(); CHECK(actor.unk64_19 && !(state.first>>24));
    u32 wait[]={0x10005,10,CMD(0x13,4),11,CMD(7,90),0,2};
    reset(); func_800D7754(&actor,7); install_script(wait,ARRLEN(wait),10); run_script(); near(state.delay,1);
    CHECK(state.first>>24==1); near(state.elapsed,10);
    for(int i=0;i<10;++i) { native_spline_context.value0=11+i; CHECK(func_800D8588(&actor,0x1800,0,0)); }
    near(state.delay,0); near(state.timer,10); CHECK(state.first>>24==1);
    native_spline_context.value0=21; CHECK(func_800D8588(&actor,0x1800,0,0));
    CHECK(!(state.first>>24)); near(actor.unk54,90);
}
static void test_script_conditions(void) {
    u32 commands[]={0x10005,1,CMD(0x20,7),2,CMD(0x30,1),0,2};
    reset(); native_spline_context.counters[7]=2; install_script(commands,ARRLEN(commands),1); run_script();
    CHECK(native_spline_context.counters[7]==1 && ((state.flags28>>18)&255)==8);
    CHECK(!actor.unk64_19); native_spline_context.counters[7]=0;
    CHECK(func_800D8588(&actor,0,0,0)); CHECK(((state.flags28>>18)&255)==0);
    native_spline_context.value0=2; CHECK(func_800D8588(&actor,0,0,0)); CHECK(actor.unk64_19);
    u32 reset_counter[]={0x10005,0,CMD(0x21,7),0,2};
    reset(); native_spline_context.initial_counters[7]=9;
    install_script(reset_counter,ARRLEN(reset_counter),0); run_script(); CHECK(native_spline_context.counters[7]==9);
    u32 message[]={0x10005,1,CMD(0x1D,8),2,CMD(0x30,1),0,2};
    reset(); install_script(message,ARRLEN(message),1); run_script(); CHECK((state.flags28 & 0xFFC0)==((9<<7)|64));
    flag_ready=0; CHECK(func_800D8588(&actor,0,0,0)); CHECK(state.flags28);
    flag_ready=1; CHECK(func_800D8588(&actor,0,0,0)); CHECK(!state.flags28);
    native_spline_context.value0=2; CHECK(func_800D8588(&actor,0,0,0)); CHECK(actor.unk64_19);
    message[2]=CMD(0x1C,8); reset(); install_script(message,ARRLEN(message),1); run_script(); CHECK(state.flags28==(9<<7));
    u32 pod[]={0x10005,0,CMD(0x1F,3),0,CMD(0x30,1),0,2};
    reset(); install_script(pod,ARRLEN(pod),0); run_script(); near(state.pod,3); CHECK(!actor.unk64_19);
    condition_ready=1; CHECK(func_800D8588(&actor,0,0,0)); CHECK(!state.pod && actor.unk64_19);
    u32 pause[]={0x10005,0,CMD(0x14,108),0,CMD(0x30,1),0,2};
    reset(); install_script(pause,ARRLEN(pause),0); run_script(); CHECK(((state.flags24>>9)&15)==3);
    state.flags24 &= ~(15u<<9); run_script(); CHECK(actor.unk64_19);
}
static void test_script_interpolation(void) {
    u32 angles[]={0x10005,10,CMD(0x26,0),(100<<16)|50,999,0,2};
    reset(); actor.rotation[1]=20; actor.rotation[0]=10; func_800D7754(&actor,7);
    install_script(angles,ARRLEN(angles),10); run_script();
    near(state.start,10); near(state.end,20); CHECK(state.angles44>>29==5);
    native_spline_context.value0=15; func_800D7948(&actor,0x1800,0,0);
    near(actor.unk54,60); near(actor.unk50,30);
    u32 speed[]={0x10006,1000000,CMD(0x27,0),4,3000000,0,2};
    reset(); state.time=.25f; install_script(speed,ARRLEN(speed),0); run_script();
    near(state.start,.25f); near(state.end,.75f); near(state.start_speed,10); near(state.end_speed,2.5f);
    state.time=.5f; func_800D7948(&actor,0,0,0); near(state.speed,6.25f);
    u32 duration[]={0x10005,0,CMD(0x12,8),0,CMD(0x2D,1),0,2};
    reset(); install_script(duration,ARRLEN(duration),0); run_script(); near(state.speed,5);
    CHECK(((u8 *)func_800D7520(0))[3]==1);
    duration[4]=CMD(0x2D,0); install_script(duration,ARRLEN(duration),0); run_script();
}
static void test_script_targets(void) {
    NativeSplineTarget targets[7]={0};
    u32 commands[]={0x10005,0,CMD(0xB,72),0,2};
    reset(); native_spline_context.cache=targets;
    install_script(commands,ARRLEN(commands),0); run_script();
    CHECK(targets[0].used && targets[0].fixed && ((state.flags24>>6)&7)==1);
    func_800D7948(&actor,0,0,0); near(actor.unk54,71); near(actor.unk50,34);
    commands[2]=CMD(0xB,0); install_script(commands,ARRLEN(commands),0); run_script(); CHECK(!targets[0].used);
    install_script(commands,ARRLEN(commands),0); run_script(); /* Clearing no target is valid. */
    commands[2]=CMD(0xB,71); install_script(commands,ARRLEN(commands),0); run_script();
    CHECK(targets[0].used && !targets[0].fixed && targets[0].marker==&target_marker);
    func_800D7948(&actor,0,0,0); near(actor.unk54,71);
    NativeMarkerProp moved={.marker=&target_marker,.position={62,48,9}};
    target_marker.unk0=(u32 *)&moved;
    func_800D7948(&actor,0,0,0); near(actor.unk54,62); near(actor.unk50,48);
    target_marker.unk0=NULL;actor.rotation[1]=-7;
    func_800D7948(&actor,0,0,0);near(actor.unk54,62);near(actor.rotation[1],62);
    native_spline_context.cache=NULL;actor.rotation[0]=-7;
    func_800D7948(&actor,0,0,0);near(actor.rotation[0],48);
    native_spline_context.cache=targets;target_marker.unk0=(u32 *)&target_prop;
    for(int i=0;i<7;++i) targets[i].used=1;
    install_script(commands,ARRLEN(commands),0); run_script(); CHECK(((state.flags24>>6)&7)==1);
    commands[2]=CMD(0xB,99); install_script(commands,ARRLEN(commands),0); run_script(); CHECK(((state.flags24>>6)&7)==1);
    u32 registry[]={0x10005,0,CMD(0x25,5),0,CMD(0xA,5<<6),0,CMD(0x22,0),0,CMD(0x23,5),0,2};
    install_script(registry,ARRLEN(registry),0); run_script();
    CHECK(native_spline_context.actors[5]==&actor_marker && (state.flags28&63)==5 && destroyed_actor==2);
    native_spline_context.cache=NULL; native_spline_context.actors[5]=NULL; actor.unk0=NULL;
}
static void test_script_other_actor(void) {
    u32 commands[]={0x10005,0,CMD(0x2A,(5<<12)|2),0,2,0x10005,0,CMD(0x30,1),0,2};
    s32 offsets[]={0,20};
    reset(); func_801058C4(&spawned,0,0,0); spawned.unk0=&spawn_marker;
    native_spline_context.actors[5]=&spawn_marker;
    install_script(commands,ARRLEN(commands),0); native_spline_context.offsets=offsets; native_spline_context.unk1A0=2;
    run_script(); CHECK(((State *)func_80105494(&spawned))->first>>24==2);
    glsplinecs_entrypoint_1(&native_spline_context,&spawned); CHECK(spawned.unk64_19);
    u32 stop[]={0x10005,0,CMD(0x2B,5),0,2};
    install_script(stop,ARRLEN(stop),0); run_script(); near(((State *)func_80105494(&spawned))->delay,1700000);
    stop[2]=CMD(0x2C,5); install_script(stop,ARRLEN(stop),0); run_script(); near(((State *)func_80105494(&spawned))->delay,0);
    func_80105634(&spawned); native_spline_context.actors[5]=NULL;
}
static void test_script_spawn(Events *events) {
    u32 commands[]={0x10005,0,CMD(0x24,42),9|(5<<12),0,CMD(0x30,1),0,2};
    reset(); *events=(Events){.count=1,.nodes={{.time=.4f,.w4=1|(7<<4)|(11<<7),.wc=70u<<23,.w10=9<<21}}};
    install_script(commands,ARRLEN(commands),0); spawn_fail=0; force_pool_growth=1;
    int previous_spawns=spawn_calls;
    func_80105854(&actor);
    CHECK(spawn_calls==previous_spawns && ((NativeSpawnQueue *)func_800A5D60())->count==1);
    flush_spawn_queue();CHECK(spawn_calls==previous_spawns+1);
    force_pool_growth=0; path_state=func_80105494(&actor);
    CHECK(actor.unk64_19 && !(state.first>>24)); CHECK(func_800D87EC(5)==&spawn_marker);
    near(spawned.position[0],4); near(((State *)func_80105494(&spawned))->time,.4f);
    func_80105634(&spawned); native_spline_context.actors[5]=NULL;
    u32 jump[]={0x10005,0,CMD(0x15,9),0,2};
    reset(); install_script(jump,ARRLEN(jump),0); run_script(); near(state.time,.4f); near(actor.position[0],4);
    jump[2]=CMD(0x15,99); install_script(jump,ARRLEN(jump),0); run_script(); near(state.time,.4f);
    events->count=0;
}
static void test_script_invalid(void) {
    u32 commands[]={0x10005,0,CMD(0x26,0),0,2};
    reset(); install_script(commands,3,0); run_script(); CHECK(!(state.first>>24));
    commands[2]=CMD(0xE,7); install_script(commands,3,0); run_script(); CHECK(!(state.first>>24));
    commands[2]=CMD(0x20,128); install_script(commands,ARRLEN(commands),0); run_script(); CHECK(!(state.first>>24));
    commands[2]=CMD(0x25,33); install_script(commands,ARRLEN(commands),0); run_script(); CHECK(!(state.first>>24));
    commands[2]=CMD(0x2B,5); native_spline_context.actors[5]=NULL;
    install_script(commands,ARRLEN(commands),0); run_script(); CHECK(!(state.first>>24));
    install_script(commands,ARRLEN(commands),0); script_offset=0x7FFFFFFC; run_script(); CHECK(!(state.first>>24));
    install_script(commands,ARRLEN(commands),0); state.first |= 0x1FFF<<11; run_script(); CHECK(!(state.first>>24));
    u32 boundary[]={0x10005,0,CMD(0xE,7),0x10005,0,2}; s32 offsets[]={0,12};
    install_script(boundary,ARRLEN(boundary),0); native_spline_context.offsets=offsets; native_spline_context.unk1A0=2;
    run_script(); CHECK(!(state.first>>24)); /* The next script cannot supply a missing operand. */
    native_spline_context.commands=NULL; native_spline_context.offsets=NULL;
}
static void test_scripts(Events *events) {
    events->count=0;
    test_script_actions(); test_script_time(); test_script_conditions(); test_script_interpolation();
    test_script_targets(); test_script_other_actor(); test_script_spawn(events); test_script_invalid();
}

u8 D_8012762C=13;
static void check_archive_scripts(const char *archive) {
    CHECK(native_assets_open(archive)); func_800D66AC();
    glsplineDll_entrypoint_2((u8 *)&native_spline_context);
    CHECK(native_spline_context.commands && native_spline_context.unk1A0>0);
    int commands=0;
    for(int id=1;id<=native_spline_context.unk1A0;++id) {
        s32 count,index=1,*script=native_spline_script(&native_spline_context,id,&count);
        CHECK(script);
        for(;;) {
            s32 size=native_spline_command_words(script,count,index);
            CHECK(size);
            if(script[index+1]==2) break;
            ++commands; index+=size;
        }
    }
    printf("Validated %d original scripts and %d command records\n",native_spline_context.unk1A0,commands);
    native_spline_clear_commands(&native_spline_context); func_800D6C64(); native_assets_close();
}
s32 func_800FF564(void) { return 0; }
void func_800CB9D8(void) { }
int main(int argc,char **argv) {
    marker_world_reset();func_800EBB5C();func_800EBB94();
    func_800A5BE0();func_800A5C04();
    s16 path_handle=func_8001B668(0,sizeof(Path)), events_handle=func_8001B668(0,sizeof(Events));
    Path *path=func_8001B798(path_handle); Events *events=func_8001B798(events_handle);
    *path=(Path){.count=2,.points={{0,0,0},{10,0,0}}}; *events=(Events){0};
    native_spline_context.handle0=func_8001B668(0,0);
    native_spline_context.handle1=func_8001B668(0,0);
    CHECK(func_800D7488(path_handle,events_handle)==0);
    func_801065E0();
    s32 actor_index;
    actor_pointer=func_80106668(&actor_index); actor.unk0=&actor_marker;
    actor_marker.unk18=0x10000u | ((u32)actor_index<<5);
    spawned_pointer=func_80106668(&actor_index); spawned.unk0=&spawn_marker;
    spawn_marker.unk18=0x10000u | ((u32)actor_index<<5);
    func_80105410(); test_lifecycle();
    test_nodes(events); test_targets(); test_angles(); test_motion(events);
    s16 second_path=func_8001B668(0,sizeof(Path)), second_events=func_8001B668(0,sizeof(Events));
    *(Path *)func_8001B798(second_path)=(Path){.count=2,.points={{10,0,0},{20,0,0}}};
    *(Events *)func_8001B798(second_events)=(Events){0};
    CHECK(func_800D7488(second_path,second_events)==1);
    test_path_lookup(events,func_8001B798(second_events));
    test_scripts(events);
    CHECK(argc==1 || argc==2); if(argc==2) check_archive_scripts(argv[1]);
    func_8001B754(second_path); func_8001B754(second_events);
    func_80105634(&actor); func_80105438(); func_8010545C();
    for(s32 i=0;i<func_80106730();++i) {
        Actor *a=func_80106768(i);
        if(a->unk0!=&actor_marker && a->unk0!=&initial_spawn_marker) func_800EBFF4(a->unk0);
    }
    func_80106608();
    chbaddieDll_entrypoint_2(func_800A5D60());
    if(controller) func_8008ADBC(controller);
    func_8001B754(path_handle); func_8001B754(events_handle);
    func_8001B754(native_spline_context.handle0); func_8001B754(native_spline_context.handle1);
    marker_world_cleanup();
    puts("Native path motion, event dispatch, waits and interpolation passed"); return 0;
}
