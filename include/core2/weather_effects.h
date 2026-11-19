#ifndef BT_CORE2_WEATHER_EFFECTS_H
#define BT_CORE2_WEATHER_EFFECTS_H
#include "common.h"

typedef struct LeafEmitter LeafEmitter;
typedef struct RainEmitter RainEmitter;
LeafEmitter *func_800B7C10(void);
RainEmitter *func_800B7C54(void);
RainEmitter *func_800B7C98(void);

void _fxleaves_entrypoint_0(LeafEmitter *effect);
void _fxleaves_entrypoint_1(LeafEmitter *effect);
int _fxleaves_entrypoint_2(LeafEmitter *effect);
void _fxleaves_entrypoint_3(LeafEmitter *effect);
LeafEmitter *_fxleaves_entrypoint_4(s32 capacity);
void _fxleaves_entrypoint_5(LeafEmitter *effect);
void _fxleaves_entrypoint_6(LeafEmitter *effect);
void _fxleaves_entrypoint_7(LeafEmitter *effect);

void _fxrain_entrypoint_0(RainEmitter *effect);
void _fxrain_entrypoint_1(RainEmitter *effect);
int _fxrain_entrypoint_2(RainEmitter *effect);
int _fxrain_entrypoint_3(RainEmitter *effect);
void _fxrain_entrypoint_4(RainEmitter *effect);
RainEmitter *_fxrain_entrypoint_5(s32 capacity);
void _fxrain_entrypoint_6(RainEmitter *effect, f32 rise, f32 steady, f32 fall, f32 pause);
void _fxrain_entrypoint_7(RainEmitter *effect);
void _fxrain_entrypoint_8(RainEmitter *effect);
void _fxrain_entrypoint_9(RainEmitter *effect);

#endif
