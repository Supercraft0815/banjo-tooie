#include "native_actor.h"
#include "native_world_grid.h"
f32 func_800EEB40(f32 *,f32 *);

intptr_t func_8010108C(Actor *actor,s32 message,uintptr_t data) {
    if(!actor || !(actor->flags74&(1u<<28)))return -1;
    ActorData *settings=func_80100368(actor);
    if(!settings || !settings->unk40_func)return -1;
    /* Native callbacks are linked permanently; N64 overlay unloading does not apply. */
    return settings->unk40_func(actor,message,data);
}
intptr_t func_8010114C(Unk80132ED0 *marker,s32 message,uintptr_t data) {
    return func_8010108C(func_80106790(marker),message,data);
}
intptr_t func_80101180(s32 type,s32 message,uintptr_t data) {
    s32 index;intptr_t result=0;
    for(Actor *actor=func_801067C4(&index);actor;actor=func_8010682C(&index)) {
        if(!actor->unk64_17 && type==actor->unk6C_9) {
            intptr_t value=func_8010108C(actor,message,data);
            if(value>0 && !result)result=value;
        }
    }
    return result;
}
intptr_t func_80101238(s32 message,uintptr_t data) {
    s32 index;intptr_t result=0;
    for(Actor *actor=func_801067C4(&index);actor;actor=func_8010682C(&index)) {
        if(!actor->unk64_17) {
            intptr_t value=func_8010108C(actor,message,data);
            if(value>0 && !result)result=value;
        }
    }
    return result;
}
intptr_t func_801012D0(f32 *center,f32 radius,s32 message,uintptr_t data) {
    s32 index;intptr_t result=0;radius*=radius;
    for(Actor *actor=func_801067C4(&index);actor;actor=func_8010682C(&index)) {
        if(!actor->unk64_17 && func_800EEB40(actor->position,center)<radius) {
            intptr_t value=func_8010108C(actor,message,data);
            if(value>0 && !result)result=value;
        }
    }
    return result;
}
intptr_t func_801013A8(f32 *position,s32 message,uintptr_t data) {
    intptr_t result=0;
    for(NativeWorldCell **cells=func_800BE3F8(position);*cells;++cells) {
        NativeMarkerProp *prop=func_800E9E88(*cells),*end=func_800E9EB4(*cells);
        for(;prop<end;++prop) {
            if(!(prop->flags&1) || !(prop->marker->unk18&0x10000))continue;
            intptr_t value=func_8010114C(prop->marker,message,data);
            if(value>0 && !result)result=value;
        }
    }
    NativeWorldCell *fallback=func_800BDC44();
    NativeMarkerProp *prop=func_800E9E88(fallback),*end=func_800E9EB4(fallback);
    for(;prop<end;++prop) {
        if(!(prop->flags&1) || !(prop->marker->unk18&0x10000))continue;
        Actor *actor=func_80106790(prop->marker);
        if(!actor)continue;
        f32 distance=func_800EEB40(actor->position,position);
        s32 radius=func_800BDC5C();
        if(distance<(f32)func_800BDC5C()*1.5f*(1.5f*(f32)radius)) {
            /* The original tests a stale/uninitialized local instead of this result. */
            intptr_t value=func_8010108C(actor,message,data);
            if(value>0 && !result)result=value;
        }
    }
    return result;
}
