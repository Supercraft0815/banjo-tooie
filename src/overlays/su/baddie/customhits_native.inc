#include "native_custom_hits.h"
#include "native_actor_model.h"
#include "native_model.h"
s32 func_8001211C(void),func_800AE0B8(void *),func_800EFFB4(f32 *,f32,f32 *);
s16 func_800B1F8C(void *,f32 *,f32 *,f32,s32,void *,f32 *,f32,f32 *,u32);
f32 *func_801027F4(Actor *);
NativeActorHit *func_80104124(void);
void func_800EE7F8(f32 *,f32 *),func_80103328(Actor *),func_80103DFC(Actor *,f32 *);
f32 func_80103F38(Actor *,f32 *);
void subaddiecustomhits_entrypoint_0(Actor *actor,NativeMarkerCollision *(*getter)(void)) {
    func_800EC358(actor->unk0,getter);
    actor->flags74|=0x80000000u;
}
NativeMarkerCollision *subaddiecustomhits_entrypoint_1(void) {
    static NativeMarkerCollision methods={.test=subaddiecustomhits_entrypoint_2};
    return &methods;
}
s32 subaddiecustomhits_entrypoint_2(Unk80132ED0 *marker,f32 *point,f32 radius,f32 *normal,u32 kind) {
    Actor *actor=func_80106790(marker);
    u8 *model=func_80103AA0(marker);
    void *skeleton=func_801040A8(actor);
    if(!model || !func_800AE0B8(skeleton) || actor->scale==0) return 0;
    s32 result=func_800B1F8C(func_800B2824(model),actor->position,func_801027F4(actor),actor->scale,0,skeleton,point,radius,normal,kind);
    if(result) {
        NativeActorHit *hit=func_80104124();
        func_800EE7F8(hit->position,point);hit->radius=radius;
        hit->id=(marker->unk10>>1)&0x7FFF;hit->frame=func_8001211C();
    }
    return result;
}
s32 subaddiecustomhits_entrypoint_3(Actor *actor,f32 *point,f32 radius) {
    f32 center[3];func_80103DFC(actor,center);
    return !func_800EFFB4(center,(f32)(u16)actor->pad68*actor->scale+radius,point);
}
s32 subaddiecustomhits_entrypoint_4(Actor *actor,f32 *position,f32 *radius) {
    NativeActorHit *hit=func_80104124();
    if(hit->id==((actor->unk0->unk10>>1)&0x7FFF) && func_8001211C()==hit->frame) {
        func_800EE7F8(position,hit->position);
        if(radius) *radius=hit->radius;
        return 1;
    }
    f32 value=func_80103F38(actor,position);
    if(radius) *radius=value;
    return 0;
}
f32 subaddiecustomhits_entrypoint_5(Actor *actor,f32 *position) {
    NativeMarkerProp *prop=(void *)actor->unk0->unk0;
    if(!(prop->flags&2)) return func_800EC75C(actor->unk0,position);
    func_80103328(actor);func_800EE7F8(position,actor->position);
    return (f32)(u16)actor->pad68*actor->scale*1.15f;
}
