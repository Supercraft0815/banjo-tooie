#include "common.h"

s32 bareact_entrypoint_0() 
{
    return 0x4;
}

void bareact_entrypoint_1(void *arg0, s32 arg1) { struct Entry { u8 id; u8 data[15]; }; extern struct Entry D_808000B0_bareact[]; s32 i; for (i = 0; D_808000B0_bareact[i].id != 0; i++) { if (arg1 == D_808000B0_bareact[i].id) { *(void **)(*(void **)((s8 *)arg0 + 0xEC)) = &D_808000B0_bareact[i]; return; } } }

u8 bareact_entrypoint_2(void *arg0) {
    return (*(u8 *)((s8 *)(*(*(void ***)((s8 *)(arg0) + (0xEC)))) + (1)));
}

f32 bareact_entrypoint_3(void *arg0) {
    return (*(f32 *)((s8 *)(*(*(void ***)((s8 *)(arg0) + (0xEC)))) + (4)));
}

f32 bareact_entrypoint_4(void *arg0) {
    return (*(f32 *)((s8 *)(*(*(void ***)((s8 *)(arg0) + (0xEC)))) + (0xC)));
}

f32 bareact_entrypoint_5(void *arg0) {
    return (*(f32 *)((s8 *)(*(*(void ***)((s8 *)(arg0) + (0xEC)))) + (8)));
}
