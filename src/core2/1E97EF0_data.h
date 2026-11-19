#ifndef BT_CORE2_1E97EF0_DATA_H
#define BT_CORE2_1E97EF0_DATA_H
#include "common.h"
#if defined(BT_NATIVE) && defined(BT_ILP32)
#define native_map D_801285B0
#include "native_map.h"
_Static_assert(sizeof(void *) == 4, "map N64 data overlay requires ILP32 pointers");
_Static_assert(sizeof(NativeMapLayer) == 0x2C, "map layer N64 stride");
_Static_assert(offsetof(NativeMap, config) == 0x58, "map config N64 offset");
_Static_assert(offsetof(NativeMap, section_count) == 0x77, "map section count N64 offset");
_Static_assert(offsetof(NativeMap, lighting_type) == 0x84, "map lighting type N64 offset");
_Static_assert(offsetof(NativeMap, vectors) == 0x178, "map vector table N64 offset");
_Static_assert(offsetof(NativeMap, zone_state) == 0x17C, "map zone state N64 offset");
_Static_assert(offsetof(NativeMap, collision_model) == 0x1B0, "map collision owner N64 offset");
NativeMap D_801285B0;
#define MAP_COLLISION_BITS native_map.layers[0].collision_bits
#define D_80128627 BT_DATA_FIELD(native_map.section_count, D_80128627)
#define D_80128634 BT_DATA_FIELD(native_map.lighting_type, D_80128634)
#define D_80128728 BT_DATA_FIELD((s32 *)native_map.vectors, D_80128728)
#define D_8012872C BT_DATA_FIELD(native_map.zone_state_bits, D_8012872C)
#define D_80128730 BT_DATA_FIELD(native_map.minimum[0], D_80128730)
#define D_80128734 BT_DATA_FIELD(native_map.minimum[1], D_80128734)
#define D_8012873C BT_DATA_FIELD(native_map.maximum[0], D_8012873C)
#define D_80128748 BT_DATA_FIELD(native_map.combined_minimum[0], D_80128748)
#define D_80128754 BT_DATA_FIELD(native_map.combined_maximum[0], D_80128754)
#define D_80128760 BT_DATA_FIELD(native_map.collision_model_bits, D_80128760)
#else
#define MAP_COLLISION_BITS D_801285B0
#endif
#endif
