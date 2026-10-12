#include "common.h"

void gsattract_entrypoint_0(void) {
    extern s32 D_8013546C;
    (*(f32 *)((s8 *)(&D_8013546C) + (8))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/attract/gsattract_entrypoint_1.s")

void gsattract_entrypoint_2(s32 arg0) 
{
}
void gsattract_entrypoint_3(void) {
    int func_800A8264(void);
    s32 func_808002A4_gsattract(s32);
    extern s32 D_8013546C;
    extern s32 D_80800493_gsattract;
    s32 var_a0;
    u8 *state;

    if (func_800A8264() == 0) {
        state = (u8 *)(u32)(&D_8013546C + 1);
        var_a0 = state[1] + 1;
        if (var_a0 >= *((u8 *)&D_80800493_gsattract + state[0] * 12)) {
            var_a0 = 0;
        }
        func_808002A4_gsattract(var_a0);
    }
}

void gsattract_entrypoint_4(void) {
    extern s32 D_8013546C;
    (*(s8 *)((s8 *)(&D_8013546C) + (4))) = 2;
}

void func_80800274_gsattract(s32 arg0) {
    extern s32 D_8013546C;
    extern s32 D_80800493_gsattract;
    s8 *state;
    s32 index;

    index = arg0 & 0xFF;
    state = (s8 *)&D_8013546C;
    state += 4;
    *state = arg0;
    *(u8 *)(state + 1) = *(u8 *)((s8 *)&D_80800493_gsattract + index * 12);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/attract/func_808002A4_gsattract.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/attract/gsattract_entrypoint_5.s")
