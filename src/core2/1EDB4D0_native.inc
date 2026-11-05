#include "native_actor_animation.h"
#include "native_actor_model.h"
#include "native_render.h"
#include "core2/1EDA900.h"
void func_8008B2DC(void *,f32);
s32 func_8001210C(s32),func_800DC298(f32),func_800D3E40(s32);
f32 func_800DC0C0(void);

s32 func_80101BE0(Actor *actor,u32 state) {
    NativeActorAnimation *table=func_80102394(actor);actor->unk70_10=state;
    if(!table)return 0;
    if(table[state].index) {
        AnimCtrl *control=func_80104248(actor);
        if(!control){control=func_801042B8(actor);anctrl_reset(control);}
        if(anctrl_getPlaybackType((u8 *)control)==3)anctrl_setPlaybackType(control,2);
        anctrl_setIndex(control,table[state].index);anctrl_setDuration(control,table[state].duration);func_8008B188(control,1);
    } else func_80104328(actor);
    return 1;
}
void func_80101CDC(Actor *actor,f32 duration) {AnimCtrl *c=func_80104248(actor);if(c)anctrl_setDuration(c,duration);}
f32 func_80101D0C(Actor *actor) {AnimCtrl *c=func_80104248(actor);return c ? func_8008B2AC((f32 *)c) : 0;}
void func_80101D4C(Actor *actor) {AnimCtrl *c=func_80104248(actor);if(c)anctrl_setPlaybackType(c,1);}
void func_80101D7C(Actor *actor) {AnimCtrl *c=func_80104248(actor);if(c)anctrl_setPlaybackType(c,2);}
void func_80101DAC(Actor *actor,s32 value) {AnimCtrl *c=func_80104248(actor);if(c)func_8008B4A8(c,value);}
s32 func_80101DDC(Actor *actor) {AnimCtrl *c=func_80104248(actor);return c ? anctrl_isStopped(c) : 0;}
s32 func_80101E14(Actor *actor,f32 time) {AnimCtrl *c=func_80104248(actor);return c ? anctrl_isAt(c,time) : 0;}
s32 func_80101E4C(Actor *actor,f32 *times) {
    for(s32 i=0;times[i]!=-1.0f;++i)if(func_80101E14(actor,times[i]))return i+1;
    return 0;
}
void func_80101EE4(Actor *actor,f32 time) {AnimCtrl *c=func_80104248(actor);if(c){func_8008B10C(c,time);func_8008B2DC(c,time);}}
f32 func_80101F24(Actor *actor) {AnimCtrl *c=func_80104248(actor);return c ? anctrl_getAnimTimer(c) : 0;}
s32 func_80101F64(Actor *actor,s32 state) {
    NativeActorAnimation *table=func_80102394(actor);AnimCtrl *c=func_80104248(actor);
    return !c || !table || anctrl_getIndex(c)!=table[state].index;
}
void func_80101FDC(Actor *actor,u32 state) {
    /* MIPS forwarded the caller's argument registers despite the empty C call. */
    s32 changed=func_80101F64(actor,state);
    if(func_80101BE0(actor,state)) {AnimCtrl *c=func_80104248(actor);if(c && changed)anctrl_start(c);}
}
f32 func_8010203C(Actor *actor,u32 state) {NativeActorAnimation *table=func_80102394(actor);return table ? table[state].duration : 0;}
void func_80102078(void *actor,s32 bits) {
    /* Existing callers pass the IEEE-754 bits through the original integer ABI. */
    union {s32 bits;f32 value;} duration={.bits=bits};
    AnimCtrl *c=func_80104248(actor);if(c)func_8008B1C8(c,duration.value);
}
void func_801020A8(Actor *actor) {AnimCtrl *c=func_80104248(actor);if(c)func_8008B1C8(c,0.2f);}
void func_801020DC(void *actor,s32 enabled) {AnimCtrl *c=func_80104248(actor);if(c)anctrl_setSmoothTransition(c,enabled==1);}
s32 func_80102128(Actor *actor,s32 period,s32 phase,f32 chance,s32 state) {
    if(func_8001210C(period)!=phase || !func_800DC298(chance))return 0;
    if(state!=-1)func_80102424(actor,state);return 1;
}
void func_80102190(void *data,s32 disabled) {
    Actor *actor=data;if(disabled)actor->flags74&=~(1u<<27);else actor->flags74|=1u<<27;
}
s32 func_801021BC(Actor *actor,s32 state) {NativeActorAnimation *table=func_80102394(actor);return table && table[state].index;}
void func_80102204(Actor *actor) {
    AnimCtrl *c=func_80104248(actor);if(!c)return;
    void *model=func_801039E4(actor->unk0);if(!model)return;
    func_8008B304(c);BoneTransformList *pose=func_8008B4D4(c);NativeBoneMatrices **matrices=func_800DF330();
    void *vertices=func_80103CDC(actor,model),*binding=func_800B26F0(model);
    func_800AE160(matrices,(NativeSkeleton *)func_800B27E0(model),pose);_dbanim_entrypoint_0(binding,vertices,*matrices);
    if(actor->flags70&(1u<<24))_dbanim_entrypoint_0(binding,func_80103D00(actor,model),*matrices);
    func_800DF41C(0);func_800DF72C(0);
}
s32 func_801022E4(Actor *actor) {AnimCtrl *c=func_80104248(actor);return c ? anctrl_getIndex(c) : 0;}
s32 func_80102320(Actor *actor,f32 start,f32 end) {
    AnimCtrl *c=func_80104248(actor);if(!c)return 0;
    f32 time=anctrl_getAnimTimer(c);return start<=time && time<=end;
}
NativeActorAnimation *func_80102394(Actor *actor) {
    if(actor->unk79_3){func_8010108C(actor,0x99,0);return func_80101080();}
    ActorData *settings=func_80100368(actor);return settings ? settings->unk8 : NULL;
}
u16 func_801023E4(Actor *actor,s32 state) {NativeActorAnimation *table=func_80102394(actor);return table ? table[state].flags : 0;}
void func_80102424(Actor *actor,s32 state) {
    NativeActorAnimation *table=func_80102394(actor);AnimCtrl *c=func_80104248(actor);
    if(c && table)anctrl_setSmoothTransition(c,!(table[state].flags&0x200));
    func_80101FDC(actor,state);c=func_80104248(actor);
    if(!c || !table)return;
    u16 flags=table[state].flags;
    if(flags&1){anctrl_setPlaybackType(c,2);func_8008B4A8(c,!(flags&0x100));}
    if(flags&2)anctrl_setPlaybackType(c,1);
    if(flags&4)anctrl_setPlaybackType(c,3);
    if(flags&8)func_8008B188(c,1);
    if(flags&0x10)func_8008B188(c,0);
    if(flags&0x800)func_8008B188(c,func_800DC298(0.5f)!=0);
    if(flags&0x40)func_8008B10C(c,0);
    if(flags&0x80)func_8008B10C(c,0.999f);
    if(flags&0x400)func_8008B10C(c,func_800DC0C0());
    func_80102190(actor,(flags&0x20)!=0);
}
void *func_8010262C(Unk80132ED0 *marker,u32 type) {
    s16 index=marker->unk10>>16;if(!index || !type)return NULL;
    void *entry=func_800AE080(index),*model=func_800AE6BC(entry);
    if(!model){s16 handle=func_800E09B8(type);if(!handle)return NULL;func_800AE6FC(entry,handle);model=func_800E0A28(handle);}
    func_800E0ACC(model);func_800E0AF0(model,1);return model;
}
void func_801026CC(Actor *actor,Vec3s32 range,f32 speed) {
    if(func_800D3E40(8))speed*=1.5f;
    f32 duration=speed<100 ? range.x : (speed-100)*range.y+range.x;
    if(duration<range.z)duration=range.z;func_80101CDC(actor,duration);
}
