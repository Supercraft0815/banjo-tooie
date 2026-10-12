#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/statusDll/gcstatusDll_entrypoint_0.s")

void gcstatusDll_entrypoint_1(s32 arg0) {
    extern s32 D_8012B3FC;
    *(s32 *)((u8 *)&D_8012B3FC + 4) = arg0;
}

void gcstatusDll_entrypoint_2(s32 arg0) {
    extern s32 D_8012B3FC;
    *(s8 *)((u8 *)&D_8012B3FC + 8) = arg0;
}

void gcstatusDll_entrypoint_3(s32 arg0, s32 arg1) {
    extern s32 D_8012B3FC;
    *(s8 *)((u8 *)&D_8012B3FC + 9 + arg0) = arg1;
}

void gcstatusDll_entrypoint_4(s32 arg0) {
    extern s32 D_8012B3FC;
    *(s8 *)((u8 *)&D_8012B3FC + 13) = arg0;
}

void gcstatusDll_entrypoint_5(s32 arg0) {
    extern s32 D_8012B3FC;
    *(s8 *)((u8 *)&D_8012B3FC + 18) = arg0;
}

void gcstatusDll_entrypoint_6(s32 arg0, s32 arg1) {
    extern s32 D_8012B3FC;
    *(s8 *)((u8 *)&D_8012B3FC + 14 + arg0) = arg1;
}

void gcstatusDll_entrypoint_7(s32 arg0) {
    extern s32 D_8012B3FC;
    *(s8 *)((u8 *)&D_8012B3FC + 19) = arg0;
}

void gcstatusDll_entrypoint_8(s32 arg0) {
    extern s32 D_8012B3FC;
    *(s8 *)((u8 *)&D_8012B3FC + 20) = arg0;
}

void gcstatusDll_entrypoint_9(s32 arg0) {
    extern s32 D_8012B3FC;
    *(s8 *)((u8 *)&D_8012B3FC + 21) = arg0;
}

u8 gcstatusDll_entrypoint_10(void) {
    extern s32 D_8012B3FC;
    return (*(u8 *)((s8 *)(&D_8012B3FC) + (8)));
}

u8 gcstatusDll_entrypoint_11(void) {
    extern u8 D_8012762C;
    extern s32 D_8012B3FC;
    u8 value = *((u8 *)&D_8012B3FC + 8);
    if (D_8012762C != 0x1B) {
        return 1U;
    }
    return value;
}

s32 gcstatusDll_entrypoint_12(void) {
    extern s32 D_8012B3FC;
    return *(s32 *)((u8 *)&D_8012B3FC + 4);
}

u8 gcstatusDll_entrypoint_13(s32 arg0) {
    extern s32 D_8012B3FC;
    return *((u8 *)&D_8012B3FC + 9 + arg0);
}

u8 gcstatusDll_entrypoint_14(void) {
    extern s32 D_8012B3FC;
    u8 result;
    result = *((u8 *)&D_8012B3FC + 13);
    return result;
}

u8 gcstatusDll_entrypoint_15(void) {
    extern s32 D_8012B3FC;
    return (*(u8 *)((s8 *)(&D_8012B3FC) + (18)));
}

u8 gcstatusDll_entrypoint_16(s32 arg0) {
    extern s32 D_8012B3FC;
    return *((u8 *)&D_8012B3FC + 14 + arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/statusDll/gcstatusDll_entrypoint_17.s")

u8 gcstatusDll_entrypoint_18(void) {
    extern s32 D_8012B3FC;
    u8 result;
    result = *((u8 *)&D_8012B3FC + 20);
    return result;
}

u8 gcstatusDll_entrypoint_19(void) {
    extern s32 D_8012B3FC;
    u8 result;
    result = *((u8 *)&D_8012B3FC + 21);
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/statusDll/gcstatusDll_entrypoint_20.s")
