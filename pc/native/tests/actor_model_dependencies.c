#include "actor_model_dependencies.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
/* External animation, skeleton, effects and actor-message consumers are observed boundaries. */
ActorData model_test_settings;
int model_test_loads,model_test_unloads,model_test_created,model_test_destroyed;
uintptr_t model_test_message;
s32 model_test_color[3]={255,255,255};
static int skeleton;
static intptr_t model_test_event(Actor *,s32,uintptr_t);
ActorData *model_test_factory(void) {return &model_test_settings;}
void model_test_reset(void) {
    model_test_settings=(ActorData){.unk40_func=model_test_event};model_test_loads=model_test_unloads=model_test_created=model_test_destroyed=0;model_test_message=0;
    for(int i=0;i<3;++i)model_test_color[i]=255;
}
static intptr_t model_test_event(Actor *actor,s32 message,uintptr_t data) {
    CHECK(actor && (message==0x29 || message==0x2A));
    if(message==0x29){CHECK(data && (actor->flags70&8));++model_test_loads;model_test_message=data;}
    else {CHECK(!data && !(actor->flags70&8));++model_test_unloads;}
    return 1;
}
void _subaddiefade_entrypoint_9(Actor *actor,s32 *out) {CHECK(actor);for(int i=0;i<3;++i)out[i]=model_test_color[i];}
#ifndef BT_TEST_REAL_SKELETON
s16 func_800AE020(void) {++model_test_created;return 3;}
void func_800ADFE0(s16 id) {CHECK(id==3);++model_test_destroyed;}
void *func_800AE080(s16 id) {CHECK(id==0 || id==3);return &skeleton;}
s32 func_800AE0E8(s16 id) {return id==3;}
#endif
s16 func_800D88F8(void) {++model_test_created;return 4;}
void func_800D8954(s16 id) {CHECK(id==4);++model_test_destroyed;}
void *func_800DBFF8(void) {++model_test_created;return heap_alloc(16);}
void func_800DBFD8(void *data) {CHECK(data);heap_free(data);++model_test_destroyed;}
#ifndef BT_TEST_REAL_ITEMS
void func_80105DFC(Actor *actor) {((s16 *)&actor->pad90)[0]=5;++model_test_created;}
void func_80106138(void *data) {Actor *actor=data;CHECK(((s16 *)&actor->pad90)[0]==5);((s16 *)&actor->pad90)[0]=0;++model_test_destroyed;}
#endif
#ifndef BT_TEST_REAL_ACTOR_ANIMATION
void func_80102424(Actor *actor,s32 type) {CHECK(type==actor->unk70_10);actor->animation_handle=6;++model_test_created;}
void func_80104328(Actor *actor) {if(!actor->animation_handle)return;CHECK(actor->animation_handle==6);actor->animation_handle=0;++model_test_destroyed;}
#endif
void func_80104460(Actor *actor) {actor->expression_handle=7;++model_test_created;}
void func_80104504(Actor *actor) {if(!actor->expression_handle)return;CHECK(actor->expression_handle==7);actor->expression_handle=0;++model_test_destroyed;}
#ifndef BT_TEST_REAL_RENDER_STATE
void func_800DF7F8(s32 id,f32 center_radius,f32 radius) {CHECK(id && center_radius>=0 && radius>=0);}

#endif
