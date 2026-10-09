#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_80800000_bstaxi.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_80800064_bstaxi.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_4.s")

s32 bstaxi_entrypoint_5(s32 arg0) {
    extern s32 D_80802130_bstaxi[];
    return ((s32 *)&D_80802130_bstaxi)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_80800420_bstaxi.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_808004A8_bstaxi.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_80800524_bstaxi.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_808005B8_bstaxi.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_808005F0_bstaxi.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_808006F4_bstaxi.s")

s32 bstaxi_entrypoint_6(s32 arg0) {
    extern s32 D_80802188_bstaxi[];
    return ((s32 *)&D_80802188_bstaxi)[arg0];
}

void bstaxi_entrypoint_7()
{
    bstaxi_entrypoint_0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_9.s")

s32 bstaxi_entrypoint_10(s32 arg0) {
    extern s32 D_80802198_bstaxi[];
    return ((s32 *)&D_80802198_bstaxi)[arg0];
}

/* extern */

void func_80800A18_bstaxi(void *arg0, u32 arg1) {
    s32 _bapackctrl_entrypoint_5(void *, s32);
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    s32 baanim_playForDuration_onceSmooth(void *, s32, s32);
    s32 bainput_enable(void *, s32, s32);
    switch (arg1) {
    case 0:
        if ((*(u8 *)((s8 *)(arg0) + (0x15C))) == 3) {
            _bapackctrl_entrypoint_5(arg0, 2);
        }
        break;
    case 1:
        (*(s8 *)((s8 *)(arg0) + (0x15D))) = 0;
        baanim_playForDuration_onceSmooth(arg0, 0x121, 0x3F8CCCCD);
        bainput_enable(arg0, 0, 0);
        break;
    case 2:
        baanim_playForDuration_loopSmooth(arg0, 0x12B, 0x40900000);
        break;
    case 3:
        baanim_playForDuration_onceSmooth(arg0, 0x12D, 0x40333333);
        break;
    case 4:
        baanim_playForDuration_onceSmooth(arg0, 0x12C, 0x3FB33333);
        break;
    }
    (*(u8 *)((s8 *)(arg0) + (0x15C))) = (u8) arg1;
}

void bstaxi_entrypoint_11(s32 arg0)
{
    func_80800A18_bstaxi(arg0,0);
    bstaxi_entrypoint_0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_13.s")

s32 bstaxi_entrypoint_14(s32 arg0) {
    extern s32 D_808021A8_bstaxi[];
    return ((s32 *)&D_808021A8_bstaxi)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_17.s")

s32 bstaxi_entrypoint_18(s32 arg0) {
    extern s32 D_808021B8_bstaxi[];
    return ((s32 *)&D_808021B8_bstaxi)[arg0];
}

void bstaxi_entrypoint_19()
{
    bstaxi_entrypoint_0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_21.s")

s32 bstaxi_entrypoint_22(s32 arg0) {
    extern s32 D_808021C8_bstaxi[];
    return ((s32 *)&D_808021C8_bstaxi)[arg0];
}

void bstaxi_entrypoint_23()
{
    bstaxi_entrypoint_0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_25.s")

s32 bstaxi_entrypoint_26(s32 arg0) {
    extern s32 D_808021D8_bstaxi[];
    return ((s32 *)&D_808021D8_bstaxi)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/func_80801600_bstaxi.s")

void bstaxi_entrypoint_27(s32 arg0)
{
    func_80801600_bstaxi(arg0,0);
    bstaxi_entrypoint_0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_29.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_30.s")

s32 bstaxi_entrypoint_31(s32 arg0) {
    extern s32 D_808021E8_bstaxi[];
    return ((s32 *)&D_808021E8_bstaxi)[arg0];
}

void bstaxi_entrypoint_32(s32 arg0)
{
    func_80090A2C();
    bstaxi_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_33.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/taxi/bstaxi_entrypoint_34.s")

s32 bstaxi_entrypoint_35(s32 arg0) {
    extern s32 D_808021F8_bstaxi[];
    return ((s32 *)&D_808021F8_bstaxi)[arg0];
}
