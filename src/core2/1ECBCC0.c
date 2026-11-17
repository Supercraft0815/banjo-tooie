#include <ultra64.h>
#include "core1/mlmtx.h"

void func_800F274C(MtxF *);     

void func_800F23D0(MtxF *arg0, f32 *arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    s32 i;
    f32 vec[3];

    func_800EE7F8(vec, arg2);
    i = 0;
    do {
        arg1[i] = (vec[0] * arg0->m[0][i] + vec[1] * arg0->m[1][i] + vec[2] * arg0->m[2][i]) + arg0->m[3][i];
        i++;
    } while (i != 3);
}

void func_800F2454(MtxF *arg0, f32 *arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    s32 i;
    f32 vec[3];

    func_800EE7F8(vec, arg2);
    i = 0;
    do {
        arg1[i] = vec[0] * arg0->m[0][i] + vec[1] * arg0->m[1][i] + vec[2] * arg0->m[2][i];
        i++;
    } while (i != 3);
}

void func_800F24D0(MtxF *arg0, f32 *arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    s32 i;
    f32 vec[3];

    func_800EE7F8(vec, arg2);
    i = 0;
    do {
        arg1[i] = vec[0] * arg0->m[i][0] + vec[1] * arg0->m[i][1] + vec[2] * arg0->m[i][2];
        i++;
    } while (i != 3);
}

/* extern */

void func_800F254C(MtxF *arg0, f32 *arg1, f32 arg2) {
    f32 func_80013788();
    f32 func_800137F4(f32);
    void func_800EF2A0(f32[3]);
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 square;

    func_800EF2A0(arg1);
    sp34 = func_800137F4(arg2);
    sp30 = func_80013788();
    sp2C = arg1[0] * arg1[1] * (1.0f - sp30);
    sp28 = arg1[1] * arg1[2] * (1.0f - sp30);
    sp24 = arg1[2] * arg1[0] * (1.0f - sp30);
    func_800F274C(arg0);
    square = arg1[0] * arg1[0];
    arg0->m[0][0] = ((1.0f - square) * sp30) + square;
    arg0->m[2][1] = sp28 - (arg1[0] * sp34);
    arg0->m[1][2] = (arg1[0] * sp34) + sp28;
    square = arg1[1] * arg1[1];
    arg0->m[1][1] = ((1.0f - square) * sp30) + square;
    arg0->m[2][0] = (arg1[1] * sp34) + sp24;
    arg0->m[0][2] = sp24 - (arg1[1] * sp34);
    square = arg1[2] * arg1[2];
    arg0->m[2][2] = ((1.0f - square) * sp30) + square;
    arg0->m[1][0] = sp2C - (arg1[2] * sp34);
    arg0->m[0][1] = (arg1[2] * sp34) + sp2C;
}

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

void func_800F2984(MtxF *arg0, LookAt *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    void func_800EE97C(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    s32 i;
    f32 forward[3];
    f32 right[3];

    func_800EFB24(forward, arg3, arg2);
    func_800EF368(forward, -1.0f);
    func_800EE97C(right, arg4, forward);
    func_800EF2A0(right);
    func_800EE97C(arg4, forward, right);
    func_800EF2A0(arg4);
    func_800F274C(arg0);
    for (i = 0; i < 3; i++) {
        arg0->m[i][0] = right[i];
        arg0->m[i][1] = arg4[i];
        arg0->m[i][2] = forward[i];
    }
    arg0->m[3][0] = -func_800EEAA4(arg2, right);
    arg0->m[3][1] = -func_800EEAA4(arg2, arg4);
    arg0->m[3][2] = -func_800EEAA4(arg2, forward);
    arg1->l[0].l.dir[0] = (u16)(int)((right[0] * 128.0f) < 127.0f ? (right[0] * 128.0f) : 127.0f);
    arg1->l[0].l.dir[1] = (u16)(int)((right[1] * 128.0f) < 127.0f ? (right[1] * 128.0f) : 127.0f);
    arg1->l[0].l.dir[2] = (u16)(int)((right[2] * 128.0f) < 127.0f ? (right[2] * 128.0f) : 127.0f);
    arg1->l[1].l.dir[0] = (u16)(int)((arg4[0] * 128.0f) < 127.0f ? (arg4[0] * 128.0f) : 127.0f);
    arg1->l[1].l.dir[1] = (u16)(int)((arg4[1] * 128.0f) < 127.0f ? (arg4[1] * 128.0f) : 127.0f);
    arg1->l[1].l.dir[2] = (u16)(int)((arg4[2] * 128.0f) < 127.0f ? (arg4[2] * 128.0f) : 127.0f);
    arg1->l[0].l.col[0] = 0;
    arg1->l[0].l.col[1] = 0;
    arg1->l[0].l.col[2] = 0;
    arg1->l[0].l.pad1 = 0;
    arg1->l[0].l.colc[0] = 0;
    arg1->l[0].l.colc[1] = 0;
    arg1->l[0].l.colc[2] = 0;
    arg1->l[0].l.pad2 = 0;
    arg1->l[1].l.col[0] = 0;
    arg1->l[1].l.col[1] = 128;
    arg1->l[1].l.col[2] = 0;
    arg1->l[1].l.pad1 = 0;
    arg1->l[1].l.colc[0] = 0;
    arg1->l[1].l.colc[1] = 128;
    arg1->l[1].l.colc[2] = 0;
    arg1->l[1].l.pad2 = 0;
}

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
}    typedef struct { s8 unk0; s8 unk1; s8 unk2; s8 unk3; s32 unk4; s32 unk8; s32 unkC; } Obj1ECBCC0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_800F2EE0(void *arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) (*(u8 *)((s8 *)(arg1) + (0)));
    (((Obj1ECBCC0_arg0 *)arg0)->unk4) = (s32) (*(u8 *)((s8 *)(arg1) + (1)));
    (((Obj1ECBCC0_arg0 *)arg0)->unk8) = (s32) (*(u8 *)((s8 *)(arg1) + (2)));
}

void func_800F2EFC(void *arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) (*(u8 *)((s8 *)(arg1) + (0)));
    (((Obj1ECBCC0_arg0 *)arg0)->unk4) = (s32) (*(u8 *)((s8 *)(arg1) + (1)));
    (((Obj1ECBCC0_arg0 *)arg0)->unk8) = (s32) (*(u8 *)((s8 *)(arg1) + (2)));
    (((Obj1ECBCC0_arg0 *)arg0)->unkC) = (s32) (*(u8 *)((s8 *)(arg1) + (3)));
}    typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; } Obj1ECBCC0_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

void func_800F2F20(void *arg0, void *arg1) {
    (((Obj1ECBCC0_arg0 *)arg0)->unk0) = (s8) (((Obj1ECBCC0_arg1 *)arg1)->unk0);
    (((Obj1ECBCC0_arg0 *)arg0)->unk1) = (s8) (((Obj1ECBCC0_arg1 *)arg1)->unk4);
    (((Obj1ECBCC0_arg0 *)arg0)->unk2) = (s8) (((Obj1ECBCC0_arg1 *)arg1)->unk8);
}

void func_800F2F3C(void *arg0, void *arg1) {
    (((Obj1ECBCC0_arg0 *)arg0)->unk0) = (s8) (((Obj1ECBCC0_arg1 *)arg1)->unk0);
    (((Obj1ECBCC0_arg0 *)arg0)->unk1) = (s8) (((Obj1ECBCC0_arg1 *)arg1)->unk4);
    (((Obj1ECBCC0_arg0 *)arg0)->unk2) = (s8) (((Obj1ECBCC0_arg1 *)arg1)->unk8);
    (((Obj1ECBCC0_arg0 *)arg0)->unk3) = (s8) (((Obj1ECBCC0_arg1 *)arg1)->unkC);
}

void func_800F2F60(void *arg0, void *arg1, f32 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) ((f32) (((Obj1ECBCC0_arg1 *)arg1)->unk0) * arg2);
    (((Obj1ECBCC0_arg0 *)arg0)->unk4) = (s32) ((f32) (((Obj1ECBCC0_arg1 *)arg1)->unk4) * arg2);
    (((Obj1ECBCC0_arg0 *)arg0)->unk8) = (s32) ((f32) (((Obj1ECBCC0_arg1 *)arg1)->unk8) * arg2);
}

void func_800F2FD0(u8 *arg0, u8 *arg1, f32 scale) {
    arg0[0] = (u32)((f32)(u32)arg1[0] * scale);
    arg0[1] = (u32)((f32)(u32)arg1[1] * scale);
    arg0[2] = (u32)((f32)(u32)arg1[2] * scale);
}

void func_800F31DC(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(s32 *)((s8 *)(arg0) + (0))) = arg1;
    (((Obj1ECBCC0_arg0 *)arg0)->unk4) = arg2;
    (((Obj1ECBCC0_arg0 *)arg0)->unk8) = arg3;
}

void func_800F31EC(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (((Obj1ECBCC0_arg0 *)arg0)->unk0) = arg1;
    (((Obj1ECBCC0_arg0 *)arg0)->unk1) = arg2;
    (((Obj1ECBCC0_arg0 *)arg0)->unk2) = arg3;
}

void func_800F31FC(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    (((Obj1ECBCC0_arg0 *)arg0)->unk0) = arg1;
    (((Obj1ECBCC0_arg0 *)arg0)->unk1) = arg2;
    (((Obj1ECBCC0_arg0 *)arg0)->unk2) = arg3;
    (((Obj1ECBCC0_arg0 *)arg0)->unk3) = arg4;
}                

int func_800F3214(void *arg0, void *arg1, void *arg2, f32 arg3) {
    (*(s32 *)((s8 *)arg0 + 0)) = (s32) ((f32) (*(s32 *)((s8 *)arg1 + 0)) + (f32) (*(s32 *)((s8 *)arg2 + 0) - *(s32 *)((s8 *)arg1 + 0)) * arg3);
    (*(s32 *)((s8 *)arg0 + 4)) = (s32) ((f32) (*(s32 *)((s8 *)arg1 + 4)) + (f32) (*(s32 *)((s8 *)arg2 + 4) - *(s32 *)((s8 *)arg1 + 4)) * arg3);
    (*(s32 *)((s8 *)arg0 + 8)) = (s32) ((f32) (*(s32 *)((s8 *)arg1 + 8)) + (f32) (*(s32 *)((s8 *)arg2 + 8) - *(s32 *)((s8 *)arg1 + 8)) * arg3);
    return arg3 == 1.0f;
}

void func_800F32D4(void *arg0, void *arg1, void *arg2, f32 arg3, f32 arg4) {
    f32 ratio;

    ratio = arg3 / arg4;
    if (ratio > 1.0f) {
        ratio = 1.0f;
    }
    func_800F3214(arg0, arg1, arg2, ratio);
}

int func_800F3320(u8 *arg0, u8 *arg1, u8 *arg2, f32 amount) {
    if (amount > 1.0f) amount = 1.0f;
    arg0[0] = (u32)((f32)(u32)arg1[0] + (f32)(arg2[0] - arg1[0]) * amount);
    arg0[1] = (u32)((f32)(u32)arg1[1] + (f32)(arg2[1] - arg1[1]) * amount);
    arg0[2] = (u32)((f32)(u32)arg1[2] + (f32)(arg2[2] - arg1[2]) * amount);
    return amount == 1.0f;
}

void func_800F35AC(void *arg0, void *arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;

    temp_v0 = (*(s32 *)((s8 *)(arg1) + (0)));
    if (temp_v0 < 0) {
        (*(s8 *)((s8 *)(arg0) + (0))) = 0;
    } else {
        var_v1 = temp_v0 >= 0x100 ? 0xFF : temp_v0;
        (*(s8 *)((s8 *)(arg0) + (0))) = (s8) var_v1;
    }
    temp_v0_2 = (*(s32 *)((s8 *)(arg1) + (4)));
    if (temp_v0_2 < 0) {
        (*(s8 *)((s8 *)(arg0) + (1))) = 0;
    } else {
        var_v1_2 = temp_v0_2 >= 0x100 ? 0xFF : temp_v0_2;
        (*(s8 *)((s8 *)(arg0) + (1))) = (s8) var_v1_2;
    }
    temp_v0_3 = (*(s32 *)((s8 *)(arg1) + (8)));
    if (temp_v0_3 < 0) {
        (*(s8 *)((s8 *)(arg0) + (2))) = 0;
        return;
    }
    var_v1_3 = temp_v0_3 >= 0x100 ? 0xFF : temp_v0_3;
    (*(s8 *)((s8 *)(arg0) + (2))) = (s8) var_v1_3;
}

void func_800F362C(void *arg0, void *arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;

    temp_v0 = (*(s32 *)((s8 *)(arg1) + (0)));
    if (temp_v0 < 0) {
        (*(s8 *)((s8 *)(arg0) + (0))) = 0;
    } else {
        var_v1 = temp_v0 >= 0x100 ? 0xFF : temp_v0;
        (*(s8 *)((s8 *)(arg0) + (0))) = (s8) var_v1;
    }
    temp_v0_2 = (*(s32 *)((s8 *)(arg1) + (4)));
    if (temp_v0_2 < 0) {
        (*(s8 *)((s8 *)(arg0) + (1))) = 0;
    } else {
        var_v1_2 = temp_v0_2 >= 0x100 ? 0xFF : temp_v0_2;
        (*(s8 *)((s8 *)(arg0) + (1))) = (s8) var_v1_2;
    }
    temp_v0_3 = (*(s32 *)((s8 *)(arg1) + (8)));
    if (temp_v0_3 < 0) {
        (*(s8 *)((s8 *)(arg0) + (2))) = 0;
    } else {
        var_v1_3 = temp_v0_3 >= 0x100 ? 0xFF : temp_v0_3;
        (*(s8 *)((s8 *)(arg0) + (2))) = (s8) var_v1_3;
    }
    temp_v0_4 = (*(s32 *)((s8 *)(arg1) + (0xC)));
    if (temp_v0_4 < 0) {
        (*(s8 *)((s8 *)(arg0) + (3))) = 0;
        return;
    }
    var_v1_4 = temp_v0_4 >= 0x100 ? 0xFF : temp_v0_4;
    (*(s8 *)((s8 *)(arg0) + (3))) = (s8) var_v1_4;
}

int func_800F36D4(s32 *arg0, s32 *arg1) {
    return (arg0[0] == arg1[0]) && (arg0[1] == arg1[1]) && (arg0[2] == arg1[2]);
}

int func_800F371C(u32 arg0[4], u32 arg1[4]) {
    return arg0[0] == arg1[0] && arg0[1] == arg1[1] && arg0[2] == arg1[2] && arg0[3] == arg1[3];
}
