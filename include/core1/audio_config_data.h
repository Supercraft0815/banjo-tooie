#ifndef CORE1_AUDIO_CONFIG_DATA_H
#define CORE1_AUDIO_CONFIG_DATA_H

#include <ultra64.h>

typedef struct {
    s32 dma_initialized;
    s32 effect_params[134];
    OSMesg completed_task;
    s32 last_task;
    s32 ai_buffer[3];
    s32 dma_pending;
    s32 padding[7];
} Core1AudioConfigData;

extern Core1AudioConfigData core1_audio_config;
#endif
