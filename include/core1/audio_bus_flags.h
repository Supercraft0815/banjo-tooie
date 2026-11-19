#ifndef CORE1_AUDIO_BUS_FLAGS_H
#define CORE1_AUDIO_BUS_FLAGS_H

#include "types.h"

#ifdef BT_NATIVE
/* The original mixer indexes three overlapping byte ranges by effect bus. */
extern u8 D_8007EA33[13];
#define BUS_ROUTING(bus) D_8007EA33[(bus)]
#define BUS_PHASE(bus) D_8007EA33[1 + (bus)]
#define BUS_MODE(bus) D_8007EA33[2 + (bus)]
#endif
#endif
