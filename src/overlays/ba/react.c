#include "common.h"

s32 bareact_entrypoint_0() 
{
    return 0x4;
}
struct Entry { u8 id; u8 data[15]; }; typedef struct { u8 pad0[0xEC]; union { void ** unkEC; void * unkEC_voidp; }; } Objreact_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
void bareact_entrypoint_1(void *arg0, s32 arg1) { extern struct Entry D_808000B0_bareact[]; s32 i; for (i = 0; D_808000B0_bareact[i].id != 0; i++) { if (arg1 == D_808000B0_bareact[i].id) { *(void **)(((Objreact_arg0 *)arg0)->unkEC_voidp) = &D_808000B0_bareact[i]; return; } } }

u8 bareact_entrypoint_2(void *arg0) {
    return (*(u8 *)((s8 *)(*(((Objreact_arg0 *)arg0)->unkEC)) + (1)));
}

f32 bareact_entrypoint_3(void *arg0) {
    return (*(f32 *)((s8 *)(*(((Objreact_arg0 *)arg0)->unkEC)) + (4)));
}

f32 bareact_entrypoint_4(void *arg0) {
    return (*(f32 *)((s8 *)(*(((Objreact_arg0 *)arg0)->unkEC)) + (0xC)));
}

f32 bareact_entrypoint_5(void *arg0) {
    return (*(f32 *)((s8 *)(*(((Objreact_arg0 *)arg0)->unkEC)) + (8)));
}
/* data_to_c.py: from asm/data/overlays/ba/react.data.s */
struct Entry D_808000B0_bareact [17] BT_DATA(4, overlays_ba_react, 0x0) = { { 1, { 1, 0, 0, 0x43, 0xFF, 0, 0, 0xC4, 0x96, 0, 0, 0x43, 0x48, 0, 0 } }, { 2, { 1, 0, 0, 0x44, 0x16, 0, 0, 0xC4, 0xBB, 0x80, 0, 0x43, 0x96, 0, 0 } }, { 3, { 1, 0, 0, 0x43, 0xFF, 0, 0, 0xC4, 0x96, 0, 0, 0x42, 0xC8, 0, 0 } }, { 4, { 1, 0, 0, 0x43, 0xFF, 0, 0, 0xC4, 0x96, 0, 0, 0x43, 0x48, 0, 0 } }, { 5, { 1, 0, 0, 0x43, 0xFF, 0, 0, 0xC4, 0x96, 0, 0, 0x43, 0x96, 0, 0 } }, { 6, { 1, 0, 0, 0x43, 0xFF, 0, 0, 0xC4, 0x96, 0, 0, 0x43, 0xC8, 0, 0 } }, { 7, { 1, 0, 0, 0x43, 0xFF, 0, 0, 0xC4, 0x96, 0, 0, 0x43, 0xFA, 0, 0 } }, { 8, { 1, 0, 0, 0x44, 0x16, 0, 0, 0xC4, 0xBB, 0x80, 0, 0x42, 0xC8, 0, 0 } }, { 9, { 1, 0, 0, 0x44, 0x16, 0, 0, 0xC4, 0xBB, 0x80, 0, 0x43, 0x48, 0, 0 } }, { 0xA, { 1, 0, 0, 0x44, 0x16, 0, 0, 0xC4, 0xBB, 0x80, 0, 0x43, 0x96, 0, 0 } }, { 0xB, { 1, 0, 0, 0x44, 0x16, 0, 0, 0xC4, 0xBB, 0x80, 0, 0x43, 0xC8, 0, 0 } }, { 0xC, { 1, 0, 0, 0x44, 0x16, 0, 0, 0xC4, 0xBB, 0x80, 0, 0x43, 0xFA, 0, 0 } }, { 0xD, { 2, 0, 0, 0x43, 0x96, 0, 0, 0xC4, 0x96, 0, 0, 0, 0, 0, 0 } }, { 0xF, { 1, 0, 0, 0x43, 0x96, 0, 0, 0xC4, 0x96, 0, 0, 0, 0, 0, 0 } }, { 0xE, { 3, 0, 0, 0x43, 0x96, 0, 0, 0xC4, 0x96, 0, 0, 0, 0, 0, 0 } }, { 0x10, { 3, 0, 0, 0x43, 0x96, 0, 0, 0xC4, 0x96, 0, 0, 0, 0, 0, 0 } }, { 0, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } } };
