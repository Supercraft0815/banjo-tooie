#include "common.h"

s32 func_80800000_baeggcursor(s32 arg0) {
    extern s32 D_80800690_baeggcursor[];
    return ((s32 *)&D_80800690_baeggcursor)[arg0];
}

s32 baeggcursor_entrypoint_0() 
{
    return 0x1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/cursor/baeggcursor_entrypoint_1.s")

u32 baeggcursor_entrypoint_2(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 104) + 9);
}

void baeggcursor_entrypoint_3(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (0)));
    *arg2 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (4)));
}

void baeggcursor_entrypoint_4(s32 arg0)
{
    baeggcursor_entrypoint_7(arg0,0);
}

void baeggcursor_entrypoint_5(void *arg0) { *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 0x68) + 9) = 0; baeggcursor_entrypoint_7(arg0, 1); }

void baeggcursor_entrypoint_6(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 104) + 10) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/cursor/baeggcursor_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/cursor/baeggcursor_entrypoint_8.s")

s32 baeggcursor_entrypoint_9(void *arg0) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (9)));
    if ((temp_v0 != 0) && (temp_v0 != 1) && (temp_v0 != 4)) {
        return 1;
    }
    return 0;
}

void baeggcursor_entrypoint_10(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (0))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x68)))) + (4))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/cursor/baeggcursor_entrypoint_11.s")
