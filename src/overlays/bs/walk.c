#include "common.h"
#include "overlays/bs/walk.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/func_80800000_bswalk.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/func_8080016C_bswalk.s")

void func_808001D8_bswalk(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 364) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/func_808001E4_bswalk.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/func_80800220_bswalk.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/func_80800248_bswalk.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_0.s")

void bswalk_entrypoint_1()
{
    func_80800000_bswalk();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_4.s")

s32 bswalk_entrypoint_5(s32 arg0) {
    extern s32 D_80801520_bswalk[];
    return ((s32 *)&D_80801520_bswalk)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_8.s")

s32 bswalk_entrypoint_9(s32 arg0) {
    extern s32 D_80801530_bswalk[];
    return ((s32 *)&D_80801530_bswalk)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_11.s")

/* extern */

void bswalk_entrypoint_12(s32 arg0) {
    s32 _bapackctrl_entrypoint_5(s32, s32);
    s32 func_8008E0E8();
    if (func_8008E0E8() != 0) {
        _bapackctrl_entrypoint_5(arg0, 3);
    }
}

s32 bswalk_entrypoint_13(s32 arg0) {
    extern s32 D_80801540_bswalk[];
    return ((s32 *)&D_80801540_bswalk)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_16.s")

s32 bswalk_entrypoint_17(s32 arg0) {
    extern s32 D_80801550_bswalk[];
    return ((s32 *)&D_80801550_bswalk)[arg0];
}

void bswalk_entrypoint_18(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_20.s")

s32 bswalk_entrypoint_21(s32 arg0) {
    extern s32 D_80801560_bswalk[];
    return ((s32 *)&D_80801560_bswalk)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/walk/bswalk_entrypoint_22.s")
