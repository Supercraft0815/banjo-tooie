#include "native_actor.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if(!(x)) { fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x); exit(1); } } while(0)
static void test_registry(void) {
    Unk80132ED0 markers[80]={0}; s32 index;
    CHECK(!func_80106730() && !func_80106768(0) && !func_80106790(NULL));
    func_801065E0(); CHECK(!func_801067C4(&index));
    for(int i=0;i<80;++i) {
        Actor *actor=func_80106668(&index);
        CHECK(index==i && actor->unk0==NULL && actor->alpha==0);
        actor->unk0=&markers[i]; actor->position[0]=i; actor->unk14=0x1000+i;
        markers[i].unk18=0xA5010013 | ((u32)i<<5);
    }
    CHECK(func_80106730()==80); func_80106630();
    for(int i=0;i<80;++i) {
        Actor *actor=func_80106790(&markers[i]);
        CHECK(actor && actor==func_80106768(i) && actor->position[0]==i && actor->unk14==0x1000u+i);
        CHECK(func_801069A4(&markers[i]));
    }
    Actor *actor=func_801067C4(&index); CHECK(actor && index==79);
    for(int i=79;i>=0;--i) { CHECK(actor && actor->unk0==&markers[i] && index==i); actor=func_8010682C(&index); }
    CHECK(!actor);
    index=500; CHECK(func_8010682C(&index)==func_80106768(79) && index==79);
    index=-1; CHECK(func_801068A8(&index)==func_80106768(0) && index==0);
    index=80; CHECK(func_801068A8(&index)==func_80106768(0));
    CHECK(func_80106920(&index)==func_80106768(79) && index==79);
    u32 flags=markers[79].unk18 & ~0xFFE0u;
    func_801066C0(5);
    CHECK(func_80106730()==79 && !func_801069A4(&markers[5]) && !func_80106790(&markers[5]));
    CHECK(func_80106790(&markers[79])==func_80106768(5));
    CHECK((markers[79].unk18 & ~0xFFE0u)==flags && ((markers[79].unk18>>5)&0x7FF)==5);
    func_801066C0(-1); func_801066C0(79); CHECK(func_80106730()==79);
    CHECK(!func_80106768(-1) && !func_80106768(79));
    markers[0].unk18 &= ~0x10000u; CHECK(!func_80106790(&markers[0])); markers[0].unk18 |= 0x10000;
    while(func_80106730()) func_801066C0(0);
    index=0; CHECK(!func_801068A8(&index) && !func_80106920(&index));
    func_80106608(); func_80106630(); CHECK(!func_80106730());
    CHECK(!func_80106790(&markers[79]));
}
/* Metadata selection, collision and rendering remain test boundaries. */
static ActorData metadata;
static Actor *observed_actor;
static int marker_updates, shadows, collision_calls, collision_result;
static f32 positions[2][3];
static ActorData *factory(void) { return &metadata; }
s32 func_800CC338(f32 (*input)[3], s32 index, s32 value) {
    CHECK(input==positions && index==126 && value==62);
    ++collision_calls;
    return collision_result;
}
void func_800EC124(f32 *position,void *marker,f32 *rotation) {
    CHECK(position==observed_actor->position && marker==observed_actor->unk0 && rotation==observed_actor->rotation);
    ++marker_updates;
}
s32 _chbadshad_entrypoint_1(Actor *actor,f32 *position,f32 scale) {
    CHECK(actor==observed_actor && position==actor->position && scale==6);
    ++shadows;
    return 1;
}
static void test_properties(void) {
    Actor actor={0};
    Unk80132ED0 marker={0};
    observed_actor=&actor; actor.unk0=&marker;actor.factory=factory;
    actor.unk14=0x12345678; actor.position[0]=12; actor.rotation[1]=45;
    func_80102FDC(&actor,4); CHECK(actor.scale==4 && actor.position[0]==12 && actor.unk14==0x12345678);
    actor.pad74_18=0x7FE; CHECK(!func_80102F14(&actor)); CHECK(func_80102F14(&actor)==1 && actor.pad74_18==0x7FF);
    actor.unk79_0=actor.unk79_1=actor.unk79_3=1; actor.unk79_4=15;
    CHECK(!func_80102F44(&actor)); CHECK(func_80102F44(&actor)==1);
    CHECK(actor.unk79_0 && actor.unk79_1 && actor.unk79_3 && actor.unk79_4==15);
    actor.pad74_0=0x7F; func_80102FE8(&actor,0); CHECK(actor.pad74_0==0x5F);
    func_80102FE8(&actor,-1); CHECK(actor.pad74_0==0x7F);
    actor.pad7C_13=0x7FFF; func_80103110(&actor,0); CHECK(actor.pad7C_13==0x7FFD);
    func_80103110(&actor,8); CHECK(actor.pad7C_13==0x7FFF);
    CHECK(func_80102EC8(&actor,positions) && collision_calls==0);
    actor.unk70_25=127; actor.pad70_1=0x1FF;
    collision_result=-1; CHECK(!func_80102EC8(&actor,positions));
    collision_result=0; CHECK(func_80102EC8(&actor,positions) && collision_calls==2);
    func_80103014((u8 *)&actor); CHECK(marker_updates==1);
    for(unsigned bank=0;bank<2;++bank) {
        for(unsigned bit=0;bit<31;++bit) {
            u32 value=1u<<bit;
            metadata.unk24=bank ? 0 : value>>16; metadata.unk26=bank ? 0 : value;
            metadata.unk3C=bank ? value>>16 : 0; metadata.unk3E=bank ? value : 0;
            u32 selector=bank ? 0x80000000u : 0;
            CHECK(func_80102FA0(&metadata,selector|value));
            CHECK(func_80102F74(&actor,selector|value));
            CHECK(!func_80102FA0(&metadata,selector|(1u<<((bit+1)%31))));
            CHECK(!func_80102FA0(&metadata,selector));
        }
    }
    metadata.unk24=metadata.unk3C=(s16)0x8000; metadata.unk26=metadata.unk3E=0;
    CHECK(!func_80102FA0(&metadata,0x7FFFFFFF) && !func_80102FA0(&metadata,-1));
    metadata.shadow_scale=1.5f; actor.pad74_18=0;
    actor.unk7C_12=1; func_80103040(&actor); CHECK(shadows==0);
    actor.pad74_18=4; func_80103040(&actor); CHECK(shadows==1);
    actor.unk7C_12=0; func_80103040(&actor); CHECK(shadows==1);
    func_801065E0(); s32 index; Unk80132ED0 parent_marker={.unk18=0x10000};
    Actor *parent=func_80106668(&index); CHECK(index==0); parent->unk0=&parent_marker;
    actor.parent_marker=&parent_marker;
    parent->unk64_16=1; func_80103040(&actor); CHECK(shadows==1);
    parent->unk7C_12=1; func_80103040(&actor); CHECK(shadows==2);
    parent->unk7C_12=0; parent->unk64_16=0; func_80103040(&actor); CHECK(shadows==3);
    func_801066C0(0); func_80103040(&actor); CHECK(shadows==3);
    func_80106608(); CHECK(actor.parent_marker==&parent_marker && actor.rotation[1]==45);
}
static void test_capacity(void) {
    s32 index;
    CHECK(!func_80106668(&index) && index==-1);
    func_801065E0();
    for(int i=0;i<2048;++i) CHECK(func_80106668(&index) && index==i);
    CHECK(!func_80106668(&index) && index==-1 && func_80106730()==2048);
    func_801066C0(2047);CHECK(func_80106668(&index) && index==2047);
    func_80106608();
}
int main(void) {
    for(int i=0;i<40;++i) test_registry();
    test_properties();test_capacity();
    puts("Native actor registry, marker lookup, properties, flags and shadow dispatch passed");
    return 0;
}
