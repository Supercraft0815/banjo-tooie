#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/egg/gcegg_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/egg/gcegg_entrypoint_1.s")

s16 gcegg_entrypoint_2(s32 arg0) {
    extern s16 D_80800202_gcegg[][7];
    return D_80800202_gcegg[arg0][0];
}

s16 gcegg_entrypoint_3(s32 arg0) {
    extern s16 D_80800206_gcegg[][7];
    return D_80800206_gcegg[arg0][0];
}

u8 gcegg_entrypoint_4(s32 arg0) {
    extern u8 D_8080020C_gcegg[];
    return D_8080020C_gcegg[arg0 * 14];
}

u8 gcegg_entrypoint_5(s32 arg0) {
    extern u8 D_80800209_gcegg[];
    return D_80800209_gcegg[arg0 * 14];
}

int gcegg_entrypoint_6(s32 arg0) {
    int func_800C6E38(s32);
    extern u8 D_8080020A_gcegg[][14];
    s32 ability = D_8080020A_gcegg[arg0][0];
    return ability == 0x3C || func_800C6E38(ability);
}

int gcegg_entrypoint_7(s32 arg0) {
    s32 func_800D3948(void);
    extern u8 D_8080020B_gcegg[];
    if (func_800D3948() == 0) {
        return 1;
    }
    {
        u8 result = D_8080020B_gcegg[arg0 * 14];
        return result;
    }
}
