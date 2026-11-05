#include "marker_world.h"
#include "native_block_pool.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x); exit(1); } } while(0)
static int update_mode,update_order,reset_calls;
void func_800EA370(void) { ++reset_calls; }
s32 func_800EA3A0(void) { ++reset_calls;return 0; }
s32 func_800EA09C(void) { return update_mode; }
void func_800EA45C(void) { CHECK(update_order==0);++update_order; }
void func_800FF62C(void) { CHECK(update_order==1);++update_order; }
void func_800EA51C(void) { CHECK(update_order==2);++update_order; }
void *_gccubesearch_entrypoint_17(s32 id,void *out) {
    CHECK(out);
    if(id!=999) return NULL;
    *(NativeWorldCell **)out=marker_world[1];return func_800E9BF4(marker_world[1],1);
}
static void test_models(void) {
    NativeWorldCell *cube=marker_world[1];
    CHECK(!func_800E9D68(cube) && !func_800E9D90(cube) && !func_800E9BF4(cube,0));
    for(int i=0;i<25;++i) {
        Prop *prop=func_800E9A24(cube);
        CHECK(prop->flags6==0x1900 && prop->unk6_7==50 && !prop->unk6_1 && !prop->unk6_0);
        CHECK(!prop->ItemID && !prop->unkA && !prop->flagsC && (prop->unk12&0x3FF)==0x100);
        prop->position[0]=i;prop->position[1]=prop->position[2]=0;
    }
    CHECK(func_800E9DC4(cube)==25 && func_800E9D90(cube)-func_800E9D68(cube)==25);
    CHECK(!func_800E9BF4(cube,-1) && !func_800E9BF4(cube,25));
    Prop *props=func_800E9D68(cube);props[0].flagsC=0xA55A1234;
    CHECK(props[0].FlagOrRotation==(0xA55A1234u>>23) && props[0].unkC_0==(0xA55A1234u&0x7FFFFF));
    *func_800BE5C4(marker_world[1])=3;
    func_800E9B74(cube,&props[1]);CHECK(func_800E9DD4(cube)==2 && func_800E9DC4(cube)==24);
    props=func_800E9D68(cube);CHECK(props[1].position[0]==2 && props[23].position[0]==24);
    func_800E9B74(cube,&props[23]);CHECK(func_800E9DD4(cube)==2 && func_800E9DC4(cube)==23);
    func_800E9EE8(998);CHECK(func_800E9DC4(cube)==23);
    func_800E9EE8(999);CHECK(func_800E9DC4(cube)==22 && func_800E9DD4(cube)==1);
    CHECK(func_800E9BF4(cube,1)->position[0]==3);
    func_800E9B74(cube,(Prop *)((u8 *)func_800E9D68(cube)+1));CHECK(func_800E9DC4(cube)==22);
    func_800E9DF8();CHECK(func_800E9BF4(cube,1)->position[0]==3);
    func_800E9C44(cube);CHECK(!func_800E9DC4(cube) && !func_800E9DD4(cube));
    func_800E9E4C(cube,0);CHECK(!cube->models[0] && !cube->dynamic[0]);
}
static void test_sprites(void) {
    NativeWorldCell *cube=marker_world[0];
    NativeMarkerProp *prop=func_800E98C0(cube);
    CHECK(!(prop->sprite&2) && (prop->flags&~0x20u)==0x210);
    prop->position[0]=77;
    CHECK(func_800E9DCC(cube)==1 && func_800E9EB4(cube)==prop+1);
    CHECK(!func_800E9AC0(cube,(void *)((u8 *)prop+1)) && func_800E9DCC(cube)==1);
    CHECK(!func_800E9AC0(cube,prop) && !func_800E9DCC(cube));
    CHECK(!func_800E9E88(cube) && !func_800E9EB4(cube));func_800E9CF4(cube);
}
static void check_marker(Unk80132ED0 *marker,int value) {
    NativeMarkerProp *prop=(void *)marker->unk0;
    NativeWorldCell *cube=func_800BDB9C(marker->cube_index);
    NativeMarkerProp *begin=func_800E9E88(cube), *end=func_800E9EB4(cube);
    CHECK(prop>=begin && prop<end && (uintptr_t)prop%_Alignof(NativeMarkerProp)==0);
    CHECK(prop->marker==marker && prop->position[1]==value && (prop->flags&1));
}
static void test_shared_pool(void) {
    Unk80132ED0 *markers[180];
    marker_world_reset();func_800EBB5C();func_800EBB94();
    for(int i=0;i<180;++i) {
        s32 pos[3]={i%3==2 ? 1000 : 0,i,i};
        markers[i]=func_800EBED4(pos,i&1,i,i%3==0);
        CHECK(markers[i]);
        for(int j=0;j<=i;++j) check_marker(markers[j],j);
    }
    for(int i=0;i<180;i+=4) {
        s32 pos[3]={i%2 ? 1001 : 1,i,0};
        func_800EC058(pos,markers[i]);
        for(int j=0;j<180;++j) check_marker(markers[j],j);
    }
    for(int i=1;i<180;i+=2) {
        func_800EBFF4(markers[i]);markers[i]=NULL;
        for(int j=0;j<180;++j) if(markers[j]) check_marker(markers[j],j);
    }
    for(int cell=0;cell<3;++cell) {
        func_800E9C44(marker_world[cell]);
        for(int j=0;j<180;++j) if(markers[j]) {
            if(markers[j]->cube_index==cell-1) { CHECK(!markers[j]->unk0 && !(markers[j]->unk10&0xFFFE));markers[j]=NULL; }
            else check_marker(markers[j],j);
        }
    }
    for(int i=0;i<200;++i) CHECK(func_800EBD78());CHECK(!func_800EBD78());func_800EBB94();
}
int main(void) {
    _Static_assert(sizeof(NativeWorldCell)==8,"cube handle layout");
    marker_world_reset();func_800EBB5C();func_800EBB94();
    func_800E96E0();func_800E9708();CHECK(reset_calls==2);
    update_mode=1;func_800E97C0();CHECK(!update_order);
    update_mode=0;func_800E97C0();CHECK(update_order==3);
    test_models();test_sprites();test_shared_pool();marker_world_cleanup();
    CHECK(!D_80132DB0 && !D_80132DB4);
    puts("Native world props: real shared pools, relocation repair, model removal and cell cleanup passed");return 0;
}
