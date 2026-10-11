#include "common.h"

s16 gsproplookup_entrypoint_0(u16 *arg0) {
    extern s32 D_80800040_gsproplookup;
    return *((s16 *)&D_80800040_gsproplookup + ((u32)*arg0 >> 4));
}

s16 gsproplookup_entrypoint_1(u16 *arg0) {
    extern s32 D_808000F4_gsproplookup;
    return *((s16 *)&D_808000F4_gsproplookup + ((u32)*arg0 >> 4));
}
