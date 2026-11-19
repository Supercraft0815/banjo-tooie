/* The custom-hit collision channel records the latest successful hit here. */
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_custom_hits.h"
typedef NativeActorHit ActorHitData;
#else
typedef struct { f32 position[3], radius; s32 id, frame; } ActorHitData;
#endif
ActorHitData D_80124400 BT_DATA(4, actor_last_hit, 0) = {{0.0f, 0.0f, 0.0f}, 0.0f, -1, 0};
