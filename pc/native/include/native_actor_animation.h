#ifndef BT_NATIVE_ACTOR_ANIMATION_H
#define BT_NATIVE_ACTOR_ANIMATION_H
#include "core2/1EDB4D0.h"
#include "core2/anctrl.h"
#include "core2/actor_animation_entry.h"
typedef ActorAnimationEntry NativeActorAnimation;
void func_80104170(void),func_801041A0(void),func_801041C8(void);
AnimCtrl *func_80104200(s16),*func_80104248(void *),*func_80104268(s16 *),*func_801042B8(Actor *);
void func_801042D8(s16 *),func_80104328(Actor *);
s32 func_80101BE0(Actor *,u32),func_80101F64(Actor *,s32);
f32 func_80101D0C(Actor *),func_8010203C(Actor *,u32);
void func_80101D4C(Actor *),func_80101D7C(Actor *),func_80101DAC(Actor *,s32),func_80101EE4(Actor *,f32);
void func_80102078(void *,s32),func_801020A8(Actor *),func_801020DC(void *,s32),func_80102190(void *,s32);
s32 func_80102128(Actor *,s32,s32,f32,s32),func_801021BC(Actor *,s32),func_80102320(Actor *,f32,f32);
void func_80102204(Actor *);
NativeActorAnimation *func_80102394(Actor *);
u16 func_801023E4(Actor *,s32);
#endif
