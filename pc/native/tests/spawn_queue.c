#include "native_spawn_queue.h"
#include "native_world_grid.h"
#include "marker_world.h"
#include "memory.h"
#include "core2/1EC3810.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1); } } while(0)
static int trace[256],used,intro;
static uintptr_t token;
static void event(int id) { CHECK(used<ARRLEN(trace));trace[used++]=id; }
/* World initialization/update and spawn targets are observable test dependencies. */
void _gccollectDll_entrypoint_4(void) { event(10);}
void func_800CB9B4(void) { event(11);}
void func_800CBA20(void) { event(12); }
void func_800CB9FC(void) { }
void func_800CBA44(void) { }
void func_800CBA68(s32 id,Prop *p,s32 a,s32 b,s32 c,s32 d,s32 e) { CHECK(0); }
void func_800CBAC8(s32 id,Prop *p,s32 a,s32 b,s32 c) { CHECK(0); }
void func_800CBB18(s32 id,Prop *p,s32 a,s32 b,s32 c,s32 d) { CHECK(0); }
void func_800FF390(void) { event(13);}
u8 func_8001E204(void) { return intro; }
void _suautobaddies_entrypoint_0(void) { event(15);}
s32 _subaddietaxi_entrypoint_4(void) { event(16);return 0; }
MapId func_800EA05C(void) { return 7; }
void _cosectionstor_entrypoint_4(s32 id) { CHECK(id==7);event(17); }
void func_80108C14(void) { event(18); }
void func_800FFB74(void) { event(19);}
void _gccollectDll_entrypoint_8(NativeWorldCell *cell) { if(cell->models[1]) event(20); }
void func_801002C0(void) { event(21);}
void _subaddietaxi_entrypoint_3(void) { event(22);}
s32 func_800FF564(void) { event(23);return 0; }
void func_800CB9D8(void) { event(24);}
void func_800FF62C(void) { event(25); }
s32 func_8010D1E8(void) { event(26);return 0; }
static Actor spawned;
Actor *func_80108DC0(s32 id,s32 *position,u32 yaw,s32 a,s32 b,Prop *prop) {
    CHECK(id==42 && prop==func_800E9D68(marker_world[1]));event(14);return &spawned;
}
Actor *func_80108474(u32 id,f32 *position,s32 yaw) { CHECK(id==42 && !yaw); for(int i=0;i<3;++i) spawned.position[i]=position[i];event(30);return &spawned; }
Actor *func_80108454(s32 id,s32 *position,u32 yaw) { CHECK(id==42 && !yaw);for(int i=0;i<3;++i) spawned.position[i]=position[i];event(31);return &spawned; }
Actor *_chbounce_entrypoint_6(s32 id,f32 *position) { CHECK(id==42);for(int i=0;i<3;++i) spawned.position[i]=position[i];event(32);return &spawned; }
void _chbounce_entrypoint_2(f32 yaw) { spawned.rotation[1]=yaw;event(33); }
void chbaddiesetup_entrypoint_7(s32,s32,s32,s32);
void chbaddiesetup_entrypoint_8(s32,s32,s32,s32);
void chbaddiesetup_entrypoint_9(s32,s32,s32,s32);
Actor *chbaddiesetup_entrypoint_10(s32,s32,s32,s32,s32);
static void c0(void) { event(0); }
static void c1(uintptr_t a) { CHECK(a==token);event(1); }
static void c2(uintptr_t a,uintptr_t b) { CHECK(a==token && (s32)b==-77);event(2); }
static void c3(uintptr_t a,uintptr_t b,uintptr_t c) { CHECK(a==token && b==2 && c==3);event(3); }
static void c4(uintptr_t a,uintptr_t b,uintptr_t c,uintptr_t d) { CHECK(a==token && b==2 && c==3 && d==4);event(4); }
static void c5(uintptr_t a,uintptr_t b,uintptr_t c,uintptr_t d,uintptr_t e) { CHECK(a==token && b==2 && c==3 && d==4 && e==5);event(5); }
static void c6(uintptr_t a,uintptr_t b,uintptr_t c,uintptr_t d,uintptr_t e,uintptr_t f) { CHECK(a==token && b==2 && c==3 && d==4 && e==5 && f==6);event(6); }
static NativeSpawnQueue *queue(void) { return func_800A5D60(); }
static void append_and_reenter(void) { event(7);_chbaddiesetup_entrypoint_1(c1,token);chbaddieDll_entrypoint_3(queue()); }
static void close_queue(void) { chbaddieDll_entrypoint_2(queue()); }
static void test_dispatch(void) {
    _chbaddiesetup_entrypoint_0(c0);_chbaddiesetup_entrypoint_1(c1,token);
    _chbaddiesetup_entrypoint_2(c2,token,(uintptr_t)-77);_chbaddiesetup_entrypoint_3(c3,token,2,3);
    _chbaddiesetup_entrypoint_4(c4,token,2,3,4);_chbaddiesetup_entrypoint_5(c5,token,2,3,4,5);
    _chbaddiesetup_entrypoint_6(c6,token,2,3,4,5,6);
    CHECK(queue()->count==7 && !used);NativeSpawnCall *buffer=queue()->callbacks;
    func_800A5C04();func_800A5D6C();CHECK(queue()->callbacks==buffer && queue()->count==7);
    func_800A5D1C();CHECK(used==9 && trace[0]==26 && trace[8]==19);
    for(int i=0;i<7;++i) CHECK(trace[i+1]==i);
    CHECK(!queue()->count && !queue()->processing);
    used=0;_chbaddiesetup_entrypoint_0(append_and_reenter);chbaddieDll_entrypoint_3(queue());
    CHECK(used==2 && trace[0]==7 && trace[1]==1 && !queue()->count && !queue()->processing);
    used=0;_chbaddiesetup_entrypoint_0(NULL);_chbaddiesetup_entrypoint_6(NULL,0,0,0,0,0,0);CHECK(!queue()->count);
    for(int i=0;i<30;++i) _chbaddiesetup_entrypoint_0(c0);
    CHECK(queue()->count==NATIVE_SPAWN_CAPACITY);chbaddieDll_entrypoint_3(queue());CHECK(used==22);
    used=0;_chbaddiesetup_entrypoint_0(c0);queue()->callbacks[0].count=7;chbaddieDll_entrypoint_3(queue());CHECK(!used && !queue()->count);
    queue()->count=23;chbaddieDll_entrypoint_3(queue());CHECK(!used && !queue()->count);
    _chbaddiesetup_entrypoint_0(close_queue);_chbaddiesetup_entrypoint_0(c0);chbaddieDll_entrypoint_3(queue());
    CHECK(used==2 && trace[0]==23 && trace[1]==24 && !queue()->count && !queue()->callbacks && !queue()->processing);
    used=0;_chbaddiesetup_entrypoint_0(c0);chbaddieDll_entrypoint_3(queue());CHECK(!used);func_800A5C04();
}
static void test_lifecycle(void) {
    used=0;intro=0;_chbaddiesetup_entrypoint_0(c0);func_800A5C28();CHECK(!queue()->count && used==11);
    for(int i=0;i<11;++i) CHECK(trace[i]==10+i);
    used=0;intro=1;func_800A5C28();int expected[]={10,11,12,13,16,17,18,19};
    CHECK(used==ARRLEN(expected));for(int i=0;i<used;++i) CHECK(trace[i]==expected[i]);
    used=0;func_800A5CF0(0);func_800A5C94();CHECK(!used);func_800A5CF0(1);func_800A5C94();CHECK(used==1 && trace[0]==21);
    func_800A5CFC();CHECK(used==2 && trace[1]==25);used=0;func_800A5D1C();CHECK(used==1 && trace[0]==19);
    used=0;func_800A5CC4();CHECK(used==3 && trace[0]==22 && trace[1]==23 && trace[2]==24 && !queue()->callbacks);
    func_800A5D6C();func_800A5CC4();CHECK(!queue()->callbacks && !queue()->count);
}
static void test_spawn_wrappers(void) {
    union { f32 f;s32 bits; } x={.f=1.25f},y={.f=-2.5f},z={.f=3.75f},yaw={.f=90.5f};
    used=0;chbaddiesetup_entrypoint_7(42,x.bits,y.bits,z.bits);CHECK(trace[0]==30 && spawned.position[0]==1.25f && spawned.position[1]==-2.5f);
    chbaddiesetup_entrypoint_8(42,-12,23,34);CHECK(trace[1]==31 && spawned.position[0]==-12 && spawned.position[2]==34);
    chbaddiesetup_entrypoint_9(42,x.bits,y.bits,z.bits);CHECK(trace[2]==32 && spawned.position[2]==3.75f);
    CHECK(chbaddiesetup_entrypoint_10(42,x.bits,y.bits,z.bits,yaw.bits)==&spawned);
    CHECK(trace[3]==33 && trace[4]==32 && spawned.rotation[1]==90.5f);
}
int main(void) {
    marker_world_reset();
    *func_800E9A24(marker_world[1])=(Prop){.flags6=6<<1,.ItemID=42};
    token=~(uintptr_t)0-42;func_800A5BE0();CHECK(queue()->enabled && !queue()->count && !queue()->callbacks);
    _chbaddiesetup_entrypoint_0(c0);CHECK(!queue()->count);func_800A5C04();CHECK(queue()->callbacks);
    test_dispatch();test_lifecycle();test_spawn_wrappers();
    marker_world_cleanup();
    puts("Native deferred spawn queue: full-width payloads, all arities, lifecycle, nested enqueue and capacity passed");return 0;
}
