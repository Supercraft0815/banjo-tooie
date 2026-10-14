#include "common.h"

/* extern */

s32 func_80800000_glsplineDll(u32 *arg0, s32 *arg1, u32 *arg2, u32 *arg3, u32 *arg4, u32 *arg5, s32 *arg6, void *arg7) {
    s32 _gspropctrl_entrypoint_6(void *);
    s32 temp_v0;

    temp_v0 = (*(s32 *)((s8 *)(arg7) + (4)));
    if (!(temp_v0 & 1) && (((u32) (temp_v0 << 0x19) >> 0x1A) == 0xB)) {
        *arg0 = (u32) ((*(s32 *)((s8 *)(arg7) + (8))) << 0x16) >> 0x1F;
        *arg1 = (*(u8 *)((s8 *)(arg7) + (0xA))) & 1;
        *arg2 = (u32) ((*(u32 *)((s8 *)(arg7) + (0xC))) << 0x12) >> 0x16;
        *arg3 = (u32) ((*(s32 *)((s8 *)(arg7) + (8))) << 0x12) >> 0x1F;
        *arg4 = (u32) (*(u32 *)((s8 *)(arg7) + (0xC))) >> 0x17;
        *arg5 = (u32) ((*(u32 *)((s8 *)(arg7) + (0xC))) << 9) >> 0x17;
        *arg6 = _gspropctrl_entrypoint_6(arg7);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/spline/Dll/glsplineDll_entrypoint_0.s")

s16 func_80800C70_glsplineDll(void) {
    extern u8 D_8012762C;
    extern struct { s16 level; s16 result; } D_80800FC8_glsplineDll[];
    s32 i = 0;
    while (D_8012762C != D_80800FC8_glsplineDll[i].level && D_80800FC8_glsplineDll[i].level != -1) {
        i++;
    }
    return D_80800FC8_glsplineDll[i].result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/spline/Dll/glsplineDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/spline/Dll/glsplineDll_entrypoint_2.s")
