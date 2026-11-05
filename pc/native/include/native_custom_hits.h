#ifndef BT_NATIVE_CUSTOM_HITS_H
#define BT_NATIVE_CUSTOM_HITS_H
#include "native_world_collision.h"
typedef struct { f32 position[3],radius; s32 id,frame; } NativeActorHit;
void subaddiecustomhits_entrypoint_0(Actor *,NativeMarkerCollision *(*)(void));
NativeMarkerCollision *subaddiecustomhits_entrypoint_1(void);
s32 subaddiecustomhits_entrypoint_2(Unk80132ED0 *,f32 *,f32,f32 *,u32);
s32 subaddiecustomhits_entrypoint_3(Actor *,f32 *,f32);
s32 subaddiecustomhits_entrypoint_4(Actor *,f32 *,f32 *);
f32 subaddiecustomhits_entrypoint_5(Actor *,f32 *);
#endif
