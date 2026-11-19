#include "native_actor.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

#define CHECK(x) do { if (!(x)) { fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x); exit(1); } } while(0)
/* Mesh loading, model rendering and item-specific effects are controlled fixtures. */
static Actor *owner;
static void *current_model;
static int created, updated, destroyed, compacted, released, model_missing, rebuilt;
static int update_model, update_secondary;
static s16 meshes[] = {12,101,0,200,0,300,0,400,0,500,0,600,0,700,0,800,0,900,0,1200,0,1700,0,1900,0};
typedef struct { Unk80132ED0 *marker; s32 id; u32 magic; } Payload;
static Payload *payload(void *data) {
    CHECK((uintptr_t)data % _Alignof(Payload)==0);
    return data;
}
static void create(void *data,s32 index,void *model,s32 id,s32 mode) {
    CHECK(model==current_model && index>=0 && mode==4);
    CHECK(func_80106314()==owner->unk0);
    *payload(data)=(Payload){owner->unk0,id,0xA1C70F5}; ++created;
}
static void update(void *data,void *model,s32 id) {
    Payload *p=payload(data);
    CHECK(p->marker==owner->unk0 && p->id==id && p->magic==0xA1C70F5);
    CHECK(model==current_model);
    CHECK(func_80106520(900)!=NULL && func_80106520(-1)==NULL);
    if(id==400 || id==600) CHECK(func_8010649C(owner,id)==data);
    ++updated;
}
static void destroy(void *data) { CHECK(payload(data)->magic==0xA1C70F5); ++destroyed; }
static void compact(void *data) { CHECK(payload(data)->magic==0xA1C70F5); ++compacted; }
#define ITEM_CALLBACKS {create,update,destroy,NULL}
ActorItemType D_80124440[] = {
    ITEM_CALLBACKS,ITEM_CALLBACKS,ITEM_CALLBACKS,ITEM_CALLBACKS,ITEM_CALLBACKS,
    ITEM_CALLBACKS,ITEM_CALLBACKS,ITEM_CALLBACKS,ITEM_CALLBACKS,ITEM_CALLBACKS,
    {create,update,destroy,compact}
};
void *_glidmake_entrypoint_5(u16 asset,void *scale) {
    CHECK(scale==NULL);
    if(asset==999) return NULL;
    current_model=heap_alloc(32); return current_model;
}
s16 *_glidmake_entrypoint_1(void *model) { CHECK(model==current_model); return meshes; }
void _glidmake_entrypoint_4(void *model) { CHECK(model); heap_free(model); ++released; }
void *func_80103AA0(Unk80132ED0 *marker) { CHECK(marker==owner->unk0); return model_missing ? NULL : (u8 *)current_model; }
void *func_80103CDC(Actor *a,void *model) { CHECK(a==owner && model==current_model); return &owner->position; }
void *func_80103D00(Actor *a,void *model) { CHECK(a==owner && model==current_model); return &owner->rotation; }
void _glid_entrypoint_5(void *model,void *value) { CHECK(model==current_model && value==&owner->position); ++update_model; }
void _glid_entrypoint_6(void *model,void *value) { CHECK(model==current_model && value==&owner->rotation); ++update_secondary; }
void func_8010381C(Actor *a) { CHECK(a==owner); ++rebuilt; }
s32 func_8001211C(void) { return 0; }
s32 func_800A9F14(s32 mode) { (void)mode; return 0; }
s32 func_800A9F30(void) { return 1; }

int main(void) {
    Actor actors[32]={0}; Unk80132ED0 markers[32]={0};
    func_80105C20();
    for(int i=0;i<32;++i) {
        owner=&actors[i]; owner->unk0=&markers[i]; markers[i].unk14=123;
        ((u16 *)&owner->pad90)[1]=0x55AA;
        func_80105DFC(owner);
        NativeActorItems *entry=func_801063C0(owner);
        CHECK((uintptr_t)entry % _Alignof(NativeActorItems)==0);
        CHECK(vector_size(entry->items)==12 && func_801065A4(owner)==current_model);
        CHECK(created==(i+1)*12);
        func_80105DFC(owner); CHECK(created==(i+1)*12);
        CHECK(((u16 *)&owner->pad90)[1]==0x55AA);
        CHECK(func_8010649C(owner,-1)==NULL);
    }
    func_80105CD0(); CHECK(compacted==32);
    for(int i=0;i<32;++i) {
        owner=&actors[i]; NativeActorItems *entry=func_801063C0(owner);
        void *old=entry->model; current_model=heap_alloc(32);
        func_8010647C(owner,current_model); heap_free(old);
        CHECK(func_801065A4(owner)==current_model);
        for(int j=0;j<vector_size(entry->items);++j) {
            NativeActorItem *item=vector_at(entry->items,j);
            CHECK(item->model==current_model && item->type>=0 && item->type<11);
        }
        owner->unk7C_12=1; owner->pad70_16=0x100;
        func_801061D8(owner); CHECK(updated==(i+1)*12);
        owner->pad74_18=16; func_801061D8(owner); CHECK(updated==(i+1)*12);
        CHECK(update_model==(i+1)*2 && update_secondary==(i+1)*2);
        owner->pad70_1=4; model_missing=1; func_801061D8(owner); model_missing=0;
        CHECK(rebuilt==i+1);
        func_80106138(owner); CHECK(!func_801065A4(owner));
        CHECK(((u16 *)&owner->pad90)[1]==0x55AA && destroyed==(i+1)*12);
    }
    CHECK(released==32);
    owner=&actors[0]; markers[0].unk14=999;
    func_80105DFC(owner); CHECK(!func_801065A4(owner));
    markers[0].unk14=123; func_80105DFC(owner); CHECK(func_801065A4(owner));
    func_80105C48(); CHECK(released==33);
    puts("Native actor item allocation, callbacks, rebinding, lookup and cleanup passed");
    return 0;
}
