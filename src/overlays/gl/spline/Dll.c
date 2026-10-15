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

/* extern */

void glsplineDll_entrypoint_1(void *arg0) {
    void func_8001B754(s16);
    void *func_8001B798(s16);
    void heap_free(void *);
    s16 *temp_v0;
    s16 *sp28;
    s16 *var_s0;
    s16 *var_s2;
    s32 var_s1;

    sp28 = func_8001B798((*(s16 *)((s8 *)(arg0) + (0x184))));
    temp_v0 = func_8001B798((*(s16 *)((s8 *)(arg0) + (0x186))));
    var_s1 = 0;
    var_s0 = sp28;
    var_s2 = temp_v0;
    if ((*(s32 *)((s8 *)(arg0) + (0x188))) > 0) {
        do {
            func_8001B754((*(s16 *)((s8 *)(func_8001B798(*var_s0)) + (0x10))));
            func_8001B754(*var_s0);
            func_8001B754(*var_s2);
            var_s1 += 1;
            var_s0++;
            var_s2++;
        } while (var_s1 < (*(s32 *)((s8 *)(arg0) + (0x188))));
    }
    func_8001B754((*(s16 *)((s8 *)(arg0) + (0x184))));
    func_8001B754((*(s16 *)((s8 *)(arg0) + (0x186))));
    (*(s16 *)((s8 *)(arg0) + (0x184))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x186))) = 0;
    heap_free((*(void **)((s8 *)(arg0) + (0x1A4))));
    (*(s32 *)((s8 *)(arg0) + (0x188))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x1A4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x198))) = 0;
    heap_free((*(void **)((s8 *)(arg0) + (0x19C))));
    (*(s32 *)((s8 *)(arg0) + (0x19C))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x1A0))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/spline/Dll/glsplineDll_entrypoint_2.s")
