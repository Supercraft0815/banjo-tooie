#include "core2/1EDA900.h"
#include "native_actor.h"
#include "marker_world.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
static ActorData metadata;
static intptr_t replies[32];
static int calls,order[64],factory_calls,add_once;
static uintptr_t expected_data;
static Unk80132ED0 *spawn(int,int,int,int);
static intptr_t event(Actor *actor,s32 message,uintptr_t data) {
    int id=actor->actorData[0];CHECK(data==expected_data && calls<64);order[calls++]=id;
    if(message==99) {
        s32 index=(actor->unk0->unk18>>5)&0x7FF;
        func_800EBFF4(actor->unk0);func_801066C0(index);
    } else if(message==100 && !add_once) {add_once=1;spawn(12,100,1,0);}
    return replies[id];
}
static ActorData *factory(void) {++factory_calls;return &metadata;}
static Unk80132ED0 *spawn(int id,int x,int type,int fallback) {
    s32 position[3]={x,100,100},index;
    Unk80132ED0 *marker=func_800EBED4(position,1,5,fallback);CHECK(marker);
    Actor *actor=func_80106668(&index);rare_memset(actor,0,sizeof(*actor));actor->unk0=marker;actor->factory=factory;
    actor->actorData[0]=id;actor->position[0]=x;actor->position[1]=actor->position[2]=100;
    actor->unk6C_9=type;actor->flags74=1u<<28;func_800EC340(marker,index);marker->unk18|=0x10000;
    return marker;
}
static void reset(void) {
    marker_world_reset();func_800EBB5C();func_800EBB94();func_801065E0();
    metadata=(ActorData){.unk40_func=event};calls=factory_calls=add_once=0;
    for(int i=0;i<32;++i)replies[i]=0;
}
static void cleanup(void) {marker_world_cleanup();func_80106608();}
static void test_context(void) {
    f32 input[3]={1,-2,3},output[3]={0};int token;
    func_80101010(input);input[0]=99;func_80101038(output);CHECK(output[0]==1 && output[1]==-2 && output[2]==3);
    func_8010105C(1.25f);CHECK(func_80101068()==1.25f);
    func_80101074(&token);CHECK(func_80101080()==&token);func_80101074(NULL);CHECK(!func_80101080());
}
static void test_direct(void) {
    reset();Unk80132ED0 *marker=spawn(0,100,1,0);Actor *actor=func_80106790(marker);
    expected_data=(uintptr_t)&metadata;replies[0]=(intptr_t)&replies;
    CHECK(func_80100368(actor)==&metadata && func_8010108C(actor,7,expected_data)==replies[0]);
    CHECK(func_8010114C(marker,7,expected_data)==replies[0] && calls==2 && order[0]==0);
    actor->flags74=0;int before=factory_calls;CHECK(func_8010108C(actor,7,expected_data)==-1 && factory_calls==before);
    actor->flags74=1u<<28;metadata.unk40_func=NULL;CHECK(func_8010108C(actor,7,expected_data)==-1 && calls==2);
    metadata.unk40_func=event;actor->factory=NULL;CHECK(!func_80100368(actor) && func_8010108C(actor,7,expected_data)==-1);
    CHECK(!func_80100368(NULL) && func_8010108C(NULL,7,expected_data)==-1 && func_8010114C(NULL,7,expected_data)==-1);
    actor->factory=factory;actor->unk64_17=1;CHECK(func_8010108C(actor,7,expected_data)==replies[0] && calls==3);
    replies[0]=-17;expected_data=UINTPTR_MAX;CHECK(func_8010114C(marker,7,expected_data)==-17);
    cleanup();
}
static void test_broadcast(void) {
    reset();Unk80132ED0 *markers[6];
    for(int i=0;i<6;++i){markers[i]=spawn(i,100+i*10,i%2,0);replies[i]=i==5 ? -1 : i+100;}
    func_80106790(markers[4])->unk64_17=1;
    expected_data=(uintptr_t)markers;
    CHECK(func_80101180(1,4,expected_data)==103 && calls==3 && order[0]==5 && order[1]==3 && order[2]==1);
    calls=0;CHECK(func_80101238(4,expected_data)==103 && calls==5 && order[4]==0);
    f32 center[3]={100,100,100};calls=0;
    CHECK(func_801012D0(center,20,4,expected_data)==101 && calls==2 && order[0]==1 && order[1]==0);
    calls=0;CHECK(!func_801012D0(center,0,4,expected_data) && !calls);
    CHECK(func_801012D0(center,-20,4,expected_data)==101 && calls==2);
    calls=0;CHECK(!func_80101180(999,4,expected_data) && !calls);
    for(int i=0;i<6;++i)replies[i]=0;calls=0;CHECK(!func_80101238(4,expected_data) && calls==5);
    cleanup();
}
static void test_nearby(void) {
    reset();f32 point[3]={100,100,100};expected_data=(uintptr_t)point;
    Unk80132ED0 *fallback=spawn(8,1100,1,1);replies[8]=(intptr_t)&metadata;
    CHECK(func_801013A8(point,2,expected_data)==replies[8] && calls==1 && order[0]==8);
    Actor *actor=func_80106790(fallback);actor->position[0]=1600;calls=0;CHECK(!func_801013A8(point,2,expected_data) && !calls);
    actor->position[0]=1599;CHECK(func_801013A8(point,2,expected_data)==replies[8]);
    Unk80132ED0 *first=spawn(0,100,1,0),*second=spawn(1,1100,1,0);replies[0]=7;replies[1]=8;
    calls=0;CHECK(func_801013A8(point,2,expected_data)==7 && calls==3 && order[0]==0 && order[1]==1 && order[2]==8);
    func_80106790(first)->unk64_17=1;calls=0;CHECK(func_801013A8(point,2,expected_data)==7 && calls==3);
    ((NativeMarkerProp *)first->unk0)->flags&=~1u;calls=0;CHECK(func_801013A8(point,2,expected_data)==8 && calls==2);((NativeMarkerProp *)first->unk0)->flags|=1;
    first->unk18&=~0x10000;second->unk18&=~0x10000;calls=0;CHECK(func_801013A8(point,2,expected_data)==replies[8] && calls==1);
    first->unk18|=0x10000;second->unk18|=0x10000;cleanup();
}
static void test_registry_mutation(void) {
    reset();expected_data=(uintptr_t)&add_once;
    for(int i=0;i<8;++i)spawn(i,100,1,0);
    CHECK(!func_80101238(100,expected_data) && calls==8 && func_80106730()==9);
    for(int i=0;i<8;++i)CHECK(order[i]==7-i);
    calls=0;CHECK(!func_80101238(99,expected_data) && calls==9 && !func_80106730());
    CHECK(order[0]==12);cleanup();
}
int main(void) {
    test_context();test_direct();test_broadcast();test_nearby();test_registry_mutation();
    puts("native actor events: full-width payload/results, broadcasts, cell/fallback results and registry mutation passed");return 0;
}
