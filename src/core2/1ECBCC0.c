#include <ultra64.h>
#include "core1/mlmtx.h"

void func_800F274C(MtxF *);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F23D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F24D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F254C.s")

void func_800F26B0(MtxF* arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_800F274C(arg0);
    arg0->m[0][0] = arg1;
    arg0->m[1][1] = arg2;
    arg0->m[2][2] = arg3;
    arg0->m[3][3] = 1.0f;
}

void func_800F2704(MtxF *mf, float arg1, float arg2, float arg3){
    void func_800F274C(MtxF *mf);

    func_800F274C(mf);
    mf->m[3][0] = arg1;
    mf->m[3][1] = arg2;
    mf->m[3][2] = arg3;
}

void func_800F274C(MtxF *mf)
{
    int i, j;

    for (i=0; i<4; i++)
    for (j=0; j<4; j++)
        if (i == j) mf->m[i][j] = 1.0;
        else mf->m[i][j] = 0.0;
}

void func_800F27D4(float lmf[4][4], float rmf[4][4], float dst[4][4]) {
    s32 i, j, k;
    float sp1C[4][4];

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            sp1C[i][j] = 0.0f;
            for(k = 0; k < 4; k++){
                sp1C[i][j] += lmf[i][k]*rmf[k][j];
            }
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            dst[i][j] = sp1C[i][j];
        }
    }
}

void func_800F293C(f32 arg0[4][4], f32 arg1[4][4]) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arg0[i][j] = arg1[i][j];
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2984.s")

void func_800F2C1C(MtxF *arg0, f32 *arg1) {
    f32 func_800138D0(f32);
    f32 func_80013A7C(f32, f32);
    f32 func_80013AAC(f32);
    f32 mlAbsF(f32);
    extern f32 D_80125EF0;
    f32 cosine;
    s32 pad;

    if (D_80125EF0 < 1.0f - mlAbsF(arg0->m[2][1])) {
        arg1[0] = func_80013AAC(-arg0->m[2][1]);
        cosine = func_800138D0(arg1[0]);
    } else {
        cosine = 0.0f;
        if (arg0->m[2][1] < 0.0f) {
            arg1[0] = 90.0f;
        } else {
            arg1[0] = -90.0f;
        }
    }
    if (cosine != 0.0f) {
        cosine = 1.0f / cosine;
        arg1[1] = func_80013AAC(arg0->m[2][0] * cosine);
        arg1[2] = func_80013AAC(arg0->m[0][1] * cosine);
    } else {
        arg1[1] = func_80013A7C(arg0->m[0][0], 0.0f);
        arg1[2] = 0.0f;
    }
}

// Transforms a Vec4f by a MtxF.
void func_800F2D34(MtxF* mat, f32 out[4], f32 in[4]) {
    s32 pad;
    f32 in_copy[4];

    in_copy[0] = in[0];
    in_copy[1] = in[1];
    in_copy[2] = in[2];
    in_copy[3] = in[3];
    out[0] = in_copy[0] * mat->m[0][0] + in_copy[1] * mat->m[1][0] + in_copy[2] * mat->m[2][0] + in_copy[3] * mat->m[3][0];
    out[1] = in_copy[0] * mat->m[0][1] + in_copy[1] * mat->m[1][1] + in_copy[2] * mat->m[2][1] + in_copy[3] * mat->m[3][1];
    out[2] = in_copy[0] * mat->m[0][2] + in_copy[1] * mat->m[1][2] + in_copy[2] * mat->m[2][2] + in_copy[3] * mat->m[3][2];
    out[3] = in_copy[0] * mat->m[0][3] + in_copy[1] * mat->m[1][3] + in_copy[2] * mat->m[2][3] + in_copy[3] * mat->m[3][3];
}

void func_800F2E60(s32 arg0[3], s32 arg1[3]) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
}

void func_800F2E7C(s32 arg0[4], s32 arg1[4]) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[3] = arg1[3];
}

void func_800F2EA0(void *arg0, void *arg1) {
    (*(u8 *)((s8 *)(arg0) + (0))) = (u8) (*(u8 *)((s8 *)(arg1) + (0)));
    (*(u8 *)((s8 *)(arg0) + (1))) = (u8) (*(u8 *)((s8 *)(arg1) + (1)));
    (*(u8 *)((s8 *)(arg0) + (2))) = (u8) (*(u8 *)((s8 *)(arg1) + (2)));
}

void func_800F2EBC(void *arg0, void *arg1) {
    (*(u8 *)((s8 *)(arg0) + (0))) = (u8) (*(u8 *)((s8 *)(arg1) + (0)));
    (*(u8 *)((s8 *)(arg0) + (1))) = (u8) (*(u8 *)((s8 *)(arg1) + (1)));
    (*(u8 *)((s8 *)(arg0) + (2))) = (u8) (*(u8 *)((s8 *)(arg1) + (2)));
    (*(u8 *)((s8 *)(arg0) + (3))) = (u8) (*(u8 *)((s8 *)(arg1) + (3)));
}

void func_800F2EE0(void *arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) (*(u8 *)((s8 *)(arg1) + (0)));
    (*(s32 *)((s8 *)(arg0) + (4))) = (s32) (*(u8 *)((s8 *)(arg1) + (1)));
    (*(s32 *)((s8 *)(arg0) + (8))) = (s32) (*(u8 *)((s8 *)(arg1) + (2)));
}

void func_800F2EFC(void *arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) (*(u8 *)((s8 *)(arg1) + (0)));
    (*(s32 *)((s8 *)(arg0) + (4))) = (s32) (*(u8 *)((s8 *)(arg1) + (1)));
    (*(s32 *)((s8 *)(arg0) + (8))) = (s32) (*(u8 *)((s8 *)(arg1) + (2)));
    (*(s32 *)((s8 *)(arg0) + (0xC))) = (s32) (*(u8 *)((s8 *)(arg1) + (3)));
}

void func_800F2F20(void *arg0, void *arg1) {
    (*(s8 *)((s8 *)(arg0) + (0))) = (s8) (*(s32 *)((s8 *)(arg1) + (0)));
    (*(s8 *)((s8 *)(arg0) + (1))) = (s8) (*(s32 *)((s8 *)(arg1) + (4)));
    (*(s8 *)((s8 *)(arg0) + (2))) = (s8) (*(s32 *)((s8 *)(arg1) + (8)));
}

void func_800F2F3C(void *arg0, void *arg1) {
    (*(s8 *)((s8 *)(arg0) + (0))) = (s8) (*(s32 *)((s8 *)(arg1) + (0)));
    (*(s8 *)((s8 *)(arg0) + (1))) = (s8) (*(s32 *)((s8 *)(arg1) + (4)));
    (*(s8 *)((s8 *)(arg0) + (2))) = (s8) (*(s32 *)((s8 *)(arg1) + (8)));
    (*(s8 *)((s8 *)(arg0) + (3))) = (s8) (*(s32 *)((s8 *)(arg1) + (0xC)));
}

void func_800F2F60(void *arg0, void *arg1, f32 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) ((f32) (*(s32 *)((s8 *)(arg1) + (0))) * arg2);
    (*(s32 *)((s8 *)(arg0) + (4))) = (s32) ((f32) (*(s32 *)((s8 *)(arg1) + (4))) * arg2);
    (*(s32 *)((s8 *)(arg0) + (8))) = (s32) ((f32) (*(s32 *)((s8 *)(arg1) + (8))) * arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F2FD0.s")

void func_800F31DC(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(s32 *)((s8 *)(arg0) + (0))) = arg1;
    (*(s32 *)((s8 *)(arg0) + (4))) = arg2;
    (*(s32 *)((s8 *)(arg0) + (8))) = arg3;
}

void func_800F31EC(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(s8 *)((s8 *)(arg0) + (0))) = arg1;
    (*(s8 *)((s8 *)(arg0) + (1))) = arg2;
    (*(s8 *)((s8 *)(arg0) + (2))) = arg3;
}

void func_800F31FC(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    (*(s8 *)((s8 *)(arg0) + (0))) = arg1;
    (*(s8 *)((s8 *)(arg0) + (1))) = arg2;
    (*(s8 *)((s8 *)(arg0) + (2))) = arg3;
    (*(s8 *)((s8 *)(arg0) + (3))) = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F3214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F32D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F3320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F35AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F362C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECBCC0/func_800F36D4.s")

int func_800F371C(u32 arg0[4], u32 arg1[4]) {
    return arg0[0] == arg1[0] && arg0[1] == arg1[1] && arg0[2] == arg1[2] && arg0[3] == arg1[3];
}
