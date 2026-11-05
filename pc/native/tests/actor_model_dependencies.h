#ifndef BT_TEST_ACTOR_MODEL_DEPENDENCIES_H
#define BT_TEST_ACTOR_MODEL_DEPENDENCIES_H
#include "native_actor_model.h"
extern ActorData model_test_settings;
extern int model_test_loads,model_test_unloads,model_test_created,model_test_destroyed;
extern uintptr_t model_test_message;
extern s32 model_test_color[3];
ActorData *model_test_factory(void);
void model_test_reset(void);
#endif
