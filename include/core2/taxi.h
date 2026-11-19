#ifndef CORE2_TAXI_H
#define CORE2_TAXI_H

#include "common.h"

#ifdef BT_NATIVE
typedef s32 (*TaxiInteractMethod)(s32 slot, f32 *position, f32 *output);
typedef void (*TaxiSpawnMethod)(s32 slot, void *args, s32 yaw_bits, s32 flags);
typedef struct TaxiMethods { TaxiInteractMethod interact; TaxiSpawnMethod spawn; } TaxiMethods;
typedef OSThread *(*TaxiProviderGetter)(void);
typedef struct TaxiSlot {
    u8 index; u8 state; s16 registration_flags; TaxiProviderGetter provider;
    f32 spawn_position[3]; f32 spawn_yaw; s16 spawn_map; s16 spawn_flags;
    f32 return_position[3]; f32 return_yaw; s16 return_map; s16 return_flags;
} TaxiSlot;
extern TaxiSlot D_8012AB70[16];
#else
typedef BtIntPtr TaxiProviderGetter;
#endif

#endif
