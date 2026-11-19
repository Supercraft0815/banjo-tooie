#ifndef CH_ACTOR_FACTORY_DECL_H
#define CH_ACTOR_FACTORY_DECL_H
#include "common.h"
#ifdef BT_NATIVE
extern __typeof__(*(((ActorData *)0)->unk38_func)) func_80107C2C;
#else
void *func_80107C2C(s32 *, s32, void *, s32, void *);
#endif
#endif
