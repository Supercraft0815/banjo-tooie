#include "native_actor_model.h"
#include "native_map_runtime.h"
#include "native_world_grid.h"
#include "core2/1EDA900.h"
#include "native_actor_animation.h"
#include "memory.h"
#include <limits.h>

void func_80104350(void),func_80104378(void);
void func_80106A20(void),func_80106A28(void),func_80106DF0(void),func_80106E18(void),func_80107BB0(void);
void func_80104504(Actor *),func_80106EE0(void *);
void _subaddieaudioloop_entrypoint_2(Actor *),func_800D8808(s32);
void func_8010DF98(void),func_8010DF3C(void),func_8010DEFC(void),func_8010D254(f32 *);
s32 func_8010D1E8(void);
int func_800DB9B0(void);
void func_800E3980(f32 *);
void _subaddiefade_entrypoint_7(Actor *),func_80106F70(Actor *),func_80104780(Actor *);
void _chbounce_entrypoint_8(Actor *),_subaddiezone_entrypoint_0(void *);
f32 func_800136E4(f32),func_800EEB40(f32 *,f32 *);
s32 func_800EFFB4(f32 *,f32,f32 *),_suautobaddies_entrypoint_1(void);
extern f32 D_80127194;
s32 D_80135A50; extern s32 D_80124390;

void func_800FF390(void) {
    D_80135A50=0;
    func_801065E0();func_80104170();func_80104350();func_80105410();func_80105C20();
    func_80106A20();func_80106DF0();func_80107BB0();
}
void func_800FF3EC(Actor *actor) {
    if(!actor->unk64_26) {
        ActorData *settings=func_80100368(actor);
        if(settings && settings->unk28_func)settings->unk28_func(actor);
        actor->unk64_26=1;
    }
}
void func_800FF44C(void) {
    s32 index;func_80101238(0x93,0);
    for(Actor *actor=func_801067C4(&index);actor;actor=func_8010682C(&index))func_800FF3EC(actor);
}
void func_800FF4A4(Actor *actor) {
    func_8010381C(actor);func_80103938(actor);
    if(actor->unk7C_0) {
        NativeActorPathState *state=func_80105494(actor);
        func_800D8808((state->flags24>>6)&7);func_80105634(actor);
    }
    actor->unk0->unk24&=0x003FFFFFu;
    func_80104328(actor);_subaddieaudioloop_entrypoint_2(actor);func_80104504(actor);func_80106EE0(actor);
    for(u32 slot=0;slot<3;++slot)func_80100074(actor,slot,0);
}
s32 func_800FF564(void) {
    s32 index;func_80101238(0x93,0);
    for(Actor *actor=func_801067C4(&index);actor;actor=func_8010682C(&index)) {
        func_800FF3EC(actor);func_800FF4A4(actor);
        if(actor->unk0)func_800EBFF4(actor->unk0);
        actor->unk0=NULL;
    }
    D_80135A50=0;D_80127194=0;
    func_801041A0();func_80104378();func_80105438();func_80105C48();func_80106608();
    func_80106A28();func_80106E18();func_8010DF98();
    return 0;
}
void func_800FF62C(void) {
    s32 index;f32 position[3];int update_zone=func_800BEC1C()!=NULL;
    func_8010D1E8();
    if(func_800DB9B0())func_800E3980(position);else func_8010D254(position);
    for(Actor *actor=func_801067C4(&index);actor;actor=func_8010682C(&index)) {
        if(actor->unk64_17)continue;
        Unk80132ED0 *marker=actor->unk0;
        if(actor->flags74&0x10) {
            if(func_8010038C(actor,position)) {
                ActorData *settings=func_80100368(actor);
                if(settings && settings->unk10_func)settings->unk10_func(actor);
            }
        } else {
            func_80100120(actor);
            if(func_8010038C(actor,position)) {
                ActorData *settings=func_80100368(actor);
                if(settings && settings->unkC_func)settings->unkC_func(actor);
            }
        }
        if(actor->animation_handle && (actor->flags74&(1u<<27)))func_8008ADE4(func_80104248(actor));
        if(((s16 *)&actor->pad90)[0])func_801061D8(actor);
        if(actor->flags79&3)_subaddiefade_entrypoint_7(actor);
        if((actor->pad94>>20)&0x3FF)func_80106F70(actor);
        if(actor->expression_handle)func_80104780(actor);
        if(actor->flags7A&8) {
            _chbounce_entrypoint_8(actor);func_80103014((u8 *)actor);
            if(update_zone)_subaddiezone_entrypoint_0(actor);
        } else if(!(actor->flags74&0x20)) {
            func_80103014((u8 *)actor);
            if(update_zone)_subaddiezone_entrypoint_0(actor);
        } else {
            u32 yaw=(u32)func_800136E4(actor->rotation[1])&0x1FF;
            u32 pitch=(u32)func_800136E4(actor->rotation[0])&0x1FF;
            u32 roll=(u32)func_800136E4(actor->rotation[2])&0x1FF;
            marker->unk24=(marker->unk24&~0xFF80u)|(pitch<<7);
            marker->unk28=(marker->unk28&0x3FFFu)|(yaw<<23)|(roll<<14);
        }
        func_80103040(actor);
    }
    func_8010DF3C();
}
void func_800FFA3C(Actor *actor) {
    Unk80132ED0 *marker=actor->unk0;
    func_800FF3EC(actor);func_800FF4A4(actor);
    func_801066C0((marker->unk18>>5)&0x7FF);func_800EBFF4(marker);
}
void func_800FFA88(Unk80132ED0 *marker) {func_800FFAB0(func_80106790(marker));}
void func_800FFAB0(Actor *actor) {
    actor->unk64_17=1;++D_80135A50;
    if(actor->parent_marker && actor->unk6C_9!=0x243) {
        Actor *parent=func_80106790(actor->parent_marker);
        if(parent){parent->unk64_17=1;parent->parent_marker=NULL;++D_80135A50;}
        actor->parent_marker=NULL;
    }
    actor->flags7A&=~4u;actor->flags74&=~(1u<<24);
}
void func_800FFB74(void) {
    if(D_80135A50>0) {
        s32 index;
        for(Actor *actor=func_801067C4(&index);actor;actor=func_8010682C(&index))
            if(actor->unk64_17)func_800FFA3C(actor);
        D_80135A50=0;
    }
}
void func_800FFBE4(void) {}
void func_800FFBEC(void) {func_800FFC3C();func_8010DEFC();}
void func_800FFC14(void) {func_800FFC3C();func_8010DEFC();}
void func_800FFC3C(void) {
    s32 index;
    for(Actor *actor=func_801067C4(&index);actor;actor=func_8010682C(&index))actor->unk7C_12=0;
}
void func_800FFC90(void) {
    s32 index;
    for(Actor *actor=func_801067C4(&index);actor;actor=func_8010682C(&index))
        if(actor->unk7C_12 && (actor->flags70&(1u<<24)))actor->flags70^=1u<<23;
}
void func_800FFD10(s32 mode) {
    s32 remaining=mode==1 ? 10 : func_80106730();
    for(Actor *actor=func_801068A8(&D_80124390);actor && remaining>0;actor=func_80106920(&D_80124390),--remaining)
        if((actor->flags70&8) && !func_80103AC0(actor))func_8010381C(actor);
}
void func_800FFDBC(void) {
    s32 index;
    for(Actor *actor=func_801067C4(&index);actor;actor=func_8010682C(&index))func_8010381C(actor);
}
void func_800FFE08(void) { /* The native heap does not relocate actor resources. */ }

static u16 *actor_buffer_handle(Actor *actor,s32 slot) {
    if(!actor)return NULL;
    switch(slot) {
        case 0:return &actor->buffer_handle0;
        case 1:return &actor->buffer_handle1;
        case 2:return &actor->buffer_handle2;
        default:return NULL;
    }
}
u32 *func_800FFECC(Actor *actor,s32 slot,s32 requested) {
    u16 *handle=actor_buffer_handle(actor,slot);
    if(!handle || requested<0 || requested>INT32_MAX-3)return NULL;
    s32 size=(requested+3)&~3;
    if(!size) {
        func_8001B754(*handle);*handle=0;return NULL;
    }
    s32 old_size=*handle ? func_8001B7B8(*handle) : 0;
    u32 *buffer;
    if(*handle)buffer=func_8001B710(*handle,size);
    else {
        *handle=func_8001B668(4,size);
        if(!*handle)return NULL;
        buffer=func_8001B798(*handle);
    }
    if(size>old_size)rare_memset((u8 *)buffer+old_size,0,size-old_size);
    return buffer;
}
u32 *func_80100074(Actor *actor,u32 slot,u32 size) {
    if(slot>=3 || size>INT32_MAX-3)return NULL;
    return func_800FFECC(actor,(s32)slot,(s32)size);
}
void *func_80100094(Actor *actor,u32 slot) {
    if(slot>=3)return NULL;
    u16 *handle=actor_buffer_handle(actor,(s32)slot);
    return handle && *handle ? func_8001B798(*handle) : NULL;
}
void *func_801000D8(Actor *actor,s32 slot,s32 size) {
    void *buffer=func_80100094(actor,(u32)slot);
    return buffer ? buffer : func_800FFECC(actor,slot,size);
}
void func_80100120(Actor *actor) {
    if(!(actor->flags74&(1u<<21))) {
        ActorData *settings=func_80100368(actor);
        if(settings && settings->unk34_func) {
            if((actor->flags70&8) && func_80102F74(actor,0x80080000))func_8010381C(actor);
            settings->unk34_func(actor);
            if(actor->unk64_17)actor->flags7C=(actor->flags7C|0x8000)&~0x4000u;
        }
        actor->flags74|=1u<<21;
    }
}
void func_801001D8(void) {
    s32 index;func_8010D1E8();
    for(Actor *actor=func_801067C4(&index);actor;actor=func_8010682C(&index))func_80100120(actor);
    func_800FFB74();
}
s32 func_80100230(Actor *actor,f32 *position) {
    if(!(actor->flags7C&0x4000))return 0;
    u32 radius=actor->flags7C>>16;
    if(!radius)return 1;
    return (f32)(s32)(radius*radius)<func_800EEB40(position,actor->position);
}
void func_801002C0(void) {
    func_801001D8();_suautobaddies_entrypoint_1();func_800FFB74();
    /* Native callbacks remain linked; the N64 overlay-unload pass is unnecessary. */
}
s32 func_8010038C(Actor *actor,f32 *position) {
    if(!(actor->flags7C&0x8000)) {
        actor->flags7C|=0x8000;
        func_8010108C(actor,0x95,0);
        if(actor->unk64_17)return 0;
    }
    if(!(actor->flags7C&0x4000))return 0;
    u32 radius=actor->flags7C>>16;
    if(!radius || (actor->flags7C&0x3000)==0x3000)return 1;
    return func_800EFFB4(actor->position,(f32)radius,position);
}
