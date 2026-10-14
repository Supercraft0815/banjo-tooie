#include "common.h"

/* extern */

s32 func_80800000_fxstep(void *arg0) {
    s32 func_800C84B0(s32);
    f32 temp_f0;
    s32 temp_a1;

    temp_f0 = (*(f32 *)((s8 *)(arg0) + (0x10))) - (*(f32 *)((s8 *)(arg0) + (8)));
    if ((temp_f0 > 0.0f) && (temp_f0 < 60.0f)) {
        return 4;
    }
    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0)));
    if (temp_a1 == 0) {
        return 0;
    }
    return func_800C84B0(temp_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_80800078_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_8080012C_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_80800210_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_808002B4_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_80800344_fxstep.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/func_808003B4_fxstep.s")

/* extern */

void fxstep_entrypoint_0(void *arg0) {
    s32 func_800C2FDC(u8);
    s32 heap_free(void *);
    func_800C2FDC((*(u8 *)((s8 *)(arg0) + (0x24))));
    func_800C2FDC((*(u8 *)((s8 *)(arg0) + (0x25))));
    heap_free(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_1.s")

void fxstep_entrypoint_2(s8 *arg0, s32 arg1) {
    arg0[38] = arg1;
}

void fxstep_entrypoint_3(s8 *arg0, s32 arg1) {
    arg0[39] = arg1;
}

void fxstep_entrypoint_4(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0x1C))) = arg1;
    (*(s32 *)((s8 *)(arg0) + (0x20))) = arg2;
}

void fxstep_entrypoint_5(void *arg0, s32 arg1, f32 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x10))) = arg2;
}

/* extern */

void fxstep_entrypoint_6(s32 arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8(arg0 + 0x4);
}

void fxstep_entrypoint_7(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0x14))) = arg1;
    (*(s32 *)((s8 *)(arg0) + (0x18))) = arg2;
}

/* extern */

void fxstep_entrypoint_8(u8 *arg0, f32 arg1, f32 arg2) {
    s32 func_808003B4_fxstep(s32, f32, f32, s32);
    func_808003B4_fxstep(arg0, arg1, arg2, arg0[0x27]);
}

/* extern */

void fxstep_entrypoint_9(s32 arg0) {
    s32 func_808003B4_fxstep(s32, f32, f32, s32);
    func_808003B4_fxstep(arg0, 0.0f, 1.0f, 0);
}

/* extern */

void fxstep_entrypoint_10(s32 arg0, s32 arg1) {
    s32 func_808002B4_fxstep(s32, f32, f32, s32);
    func_808002B4_fxstep(arg0, 0.0f, 1.0f, arg1);
}

void fxstep_entrypoint_11(u8 *arg0, f32 arg1, f32 arg2) {
    void func_80800344_fxstep(u8 *, f32, f32, u8);
    func_80800344_fxstep(arg0, arg1, arg2, arg0[0x27]);
}

void fxstep_entrypoint_12(u8 *arg0) {
    void func_80800344_fxstep(u8 *, f32, f32, u8);
    func_80800344_fxstep(arg0, 0.0f, 1.0f, 0);
}

/* extern */

void fxstep_entrypoint_13(u8 *arg0, s32 arg1) {
    s32 func_80800210_fxstep(u8 *, f32, f32, s32);
    if (arg0[0x27] != 0) {
        func_80800210_fxstep(arg0, 0.0f, 1.0f, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/step/fxstep_entrypoint_14.s")

s32 fxstep_entrypoint_15(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, f32 *arg4) {
    typedef struct {
        s16 id;
        s16 value1;
        s16 value2;
        s16 pad6;
        f32 value8;
        f32 valueC;
        f32 value10;
        s16 value14;
        s16 pad16;
    } StepEntry;
    f32 func_800DC178(f32, f32);
    extern StepEntry D_80800830_fxstep[];
    s32 var_v0;

    for (var_v0 = 0; D_80800830_fxstep[var_v0].id != 0; var_v0++) {
        if (arg0 == D_80800830_fxstep[var_v0].id) {
            if (arg1 != 0) {
                *arg4 = D_80800830_fxstep[var_v0].value8;
                *arg2 = D_80800830_fxstep[var_v0].value1;
            } else {
                *arg4 = D_80800830_fxstep[var_v0].valueC;
                *arg2 = D_80800830_fxstep[var_v0].value2;
            }
            *arg4 += func_800DC178(-0.05f, 0.05f);
            *arg3 = D_80800830_fxstep[var_v0].value14;
            return 1;
        }
    }
    return 0;
}
