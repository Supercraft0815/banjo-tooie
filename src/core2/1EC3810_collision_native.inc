#include "native_world_collision.h"
#include "native_collision_geometry.h"
#include "native_actor_model.h"
#include "core2/1EAF950.h"

s16 _gsproplookup_entrypoint_0(NativeMarkerProp *);
void func_800EA400(s32,Unk80132ED0 *,f32 *,void *);
f32 func_800EEAD4(f32 *,f32 *);
static void (*world_hit_callback)(uintptr_t,uintptr_t);
static uintptr_t world_hit_userdata;
void func_800EA600(void (*callback)(uintptr_t,uintptr_t),uintptr_t userdata) {
    world_hit_callback=callback;world_hit_userdata=userdata;
}
void func_800EA614(void) { world_hit_callback=NULL;world_hit_userdata=0; }

void *func_800EA628(NativeWorldCell *cell,f32 *start,f32 *end,f32 *normal,u32 flags) {
    void *result=NULL;
    NativeMarkerProp *prop=func_800E9E88(cell),*limit=func_800E9EB4(cell);
    for(;prop<limit;++prop) {
        if(!(prop->flags&0x10)) continue;
        if(!(prop->flags&1)) {
            if(!(prop->flags&2)) continue;
            s32 id=_gsproplookup_entrypoint_0(prop);
            u8 *model=func_800D6B0C(id);
            if(!model && func_800CB854(NULL)==1) model=(void *)func_800D674C(id);
            if(!model) continue;
            void *mesh=func_800B2720(model);
            if(mesh) {
                prop->flags|=8;
                f32 position[3]={prop->position[0],prop->position[1],prop->position[2]};
                f32 rotation[3]={0,(f32)((prop->sprite>>8)&255)*2,(f32)(prop->sprite&255)*2};
                f32 scale=(f32)(prop->flags>>8)*0.009999999776f;
                if(func_800AAEF4(position,func_800B2354(func_800B2840(model))*scale,start,end)) {
                    void *hit=func_800AB868(mesh,func_800B2840(model),position,rotation,scale,start,end,normal,flags);
                    if(hit) result=hit;
                }
            }
            func_800D62E4(id);
        } else {
            Unk80132ED0 *marker=prop->marker;
            if(!(prop->flags&8) || !(marker->unk18&0x10000)) continue;
            NativeMarkerCollision *custom=marker->collision ? marker->collision() : NULL;
            if(custom && custom->line) {
                void *hit=custom->line(marker,start,end,normal,flags);
                if(hit) result=hit;
                continue;
            }
            Actor *actor=func_80106790(marker);
            if(actor->unk64_17) continue;
            func_80103328(actor);
            if(!func_800AAEF4(actor->position,(f32)(u16)actor->pad68*actor->scale*1.100000024f,start,end)) continue;
            if(func_800CB854(NULL)==1) func_80103508(actor);
            u8 *model=func_80103AA0(marker);
            if(!model) continue;
            void *mesh=func_800B2720(model);
            if(mesh) {
                void *hit=func_800AB868(mesh,func_80103CDC(actor,model),actor->position,actor->rotation,actor->scale,start,end,normal,flags);
                if(hit && world_hit_callback) world_hit_callback((uintptr_t)marker,world_hit_userdata);
                s32 context;
                if(hit && func_800CB854(&context)==1) {
                    func_801039E4(marker);
                    if((u32)actor->pad80>>16) func_800EA400(context,marker,end,hit);
                }
                if(hit) result=hit;
            }
            func_800D62E4(marker->unk14);
        }
    }
    return result;
}

void *func_800EAA2C(NativeWorldCell *cell,f32 *start,f32 *end,f32 radius,f32 *normal,s32 iterations,u32 flags) {
    void *result=NULL;
    NativeMarkerProp *prop=func_800E9E88(cell),*limit=func_800E9EB4(cell);
    for(;prop<limit;++prop) {
        if(!(prop->flags&0x10)) continue;
        if(!(prop->flags&1)) {
            if(!(prop->flags&2)) continue;
            s32 id=_gsproplookup_entrypoint_0(prop);
            u8 *model=func_800D6B0C(id);
            void *mesh=func_800B2720(model);
            if(mesh) {
                f32 position[3]={prop->position[0],prop->position[1],prop->position[2]};
                f32 rotation[3]={0,(f32)((prop->sprite>>8)&255)*2,(f32)(prop->sprite&255)*2};
                void *hit=func_800AC848(mesh,func_800B2840(model),position,rotation,(f32)(prop->flags>>8)*0.009999999776f,start,end,radius,normal,iterations,flags);
                /* Static props pass their packed first word, not an actor marker. */
                if(hit && world_hit_callback) world_hit_callback(prop->sprite,world_hit_userdata);
                if(hit) result=hit;
            }
            if(model) func_800D62E4(id);
        } else {
            Unk80132ED0 *marker=prop->marker;
            if(!(prop->flags&8) || !(marker->unk18&0x10000)) continue;
            Actor *actor=func_80106790(marker);
            if(actor->unk64_17) continue;
            NativeMarkerCollision *custom=marker->collision ? marker->collision() : NULL;
            if(custom && custom->sweep) {
                void *hit=custom->sweep(marker,start,end,radius,normal,iterations,flags);
                if(hit) result=hit;
                continue;
            }
            func_80103328(actor);
            if(func_800EEAD4(end,actor->position)-radius>=actor->scale*(f32)(u16)actor->pad68) continue;
            if(func_800CB854(NULL)==1) func_80103508(actor);
            u8 *model=func_80103AA0(marker);void *mesh=func_800B2720(model);
            if(mesh) {
                void *hit=func_800AC848(mesh,func_80103CDC(actor,model),actor->position,actor->rotation,actor->scale,start,end,radius,normal,iterations,flags);
                if(hit) result=hit;
            }
            if(model) func_800D62E4(marker->unk14);
        }
    }
    return result;
}

void *func_800EADFC(NativeWorldCell *cell,f32 *point,f32 radius,f32 *normal,u32 flags) {
    void *result=NULL;
    NativeMarkerProp *prop=func_800E9E88(cell),*limit=func_800E9EB4(cell);
    for(;prop<limit;++prop) {
        if(!(prop->flags&0x10)) continue;
        if(!(prop->flags&1)) {
            if(!(prop->flags&2)) continue;
            u8 *model=func_800D6B0C(_gsproplookup_entrypoint_0(prop));
            void *mesh=func_800B2720(model);
            if(mesh) {
                f32 position[3]={prop->position[0],prop->position[1],prop->position[2]};
                f32 rotation[3]={0,(f32)((prop->sprite>>8)&255)*2,(f32)(prop->sprite&255)*2};
                void *hit=func_800AD1AC(mesh,func_800B2840(model),position,rotation,(f32)(prop->flags>>8)*0.009999999776f,point,radius,normal,flags);
                if(hit) result=hit;
            }
        } else {
            Unk80132ED0 *marker=prop->marker;
            if(!(prop->flags&8) || !(marker->unk18&0x10000)) continue;
            Actor *actor=func_80106790(marker);
            if(actor->unk64_17) continue;
            NativeMarkerCollision *custom=marker->collision ? marker->collision() : NULL;
            if(custom && custom->sphere) {
                void *hit=custom->sphere(marker,point,radius,normal,flags);
                if(hit) result=hit;
                continue;
            }
            func_80103328(actor);
            if(func_800EEAD4(point,actor->position)-radius>=actor->scale*(f32)(u16)actor->pad68) continue;
            if(func_800CB854(NULL)==1) func_80103508(actor);
            u8 *model=func_80103AA0(marker);void *mesh=func_800B2720(model);
            if(mesh) {
                void *hit=func_800AD1AC(mesh,func_80103CDC(actor,model),actor->position,actor->rotation,actor->scale,point,radius,normal,flags);
                if(hit) result=hit;
            }
            if(model) func_800D62E4(marker->unk14);
        }
    }
    return result;
}
