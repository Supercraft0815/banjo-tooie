#include "common.h"

void func_800ED964(void *);

typedef struct {
    u8 unk0;
    f32 unk4;
    f32 unk8;
    void (*unkC)(void *);
    void (*unk10)(void *);
    s16 unk14[3];
    s16 unk1A[3];
    f32 unk20;
    f32 unk24;
    u8 unk28;
    u8 unk29;
    u8 pad2A[2];
    f32 unk2C[3];
    f32 unk38[3];
    f32 unk44;
    f32 unk48;
    s16 unk4C;
    s16 unk4E;
    f32 unk50[4];
    f32 unk60[4];
    f32 unk70;
    f32 unk74;
    f32 unk78[3];
    f32 unk84;
    f32 unk88[3];
    f32 unk94;
    f32 unk98;
    f32 unk9C;
} MeshEffect;


void func_800EC890(s32 arg0) 
{
}
void func_800EC898(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct { s16 map; s16 id; s16 scale; s16 offset; } Entry;
    void _glidmake_entrypoint_2(s32, s32, u8 *, u8 *);
    s32 func_800EA05C();
    extern Entry D_80123580[];
    Entry *var_t0;
    s16 temp_v0_2;
    s16 var_v1;
    s32 temp_lo;
    s32 temp_v0;

    temp_v0 = func_800EA05C();
    for (var_t0 = D_80123580; var_t0->map != 0; var_t0++) {
        if (temp_v0 == var_t0->map && arg3 == var_t0->id) {
            break;
        }
    }
    (*(f32 *)((s8 *)(arg0) + (0x14))) = (f32) (2048.0f / (f32) (*(s16 *)((s8 *)(var_t0) + (4))));
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) ((*(s16 *)((s8 *)(var_t0) + (6))) << 6);
    _glidmake_entrypoint_2(arg2, arg3, arg0, arg0 + 6);
    temp_v0 = arg1 / 10;
    if (temp_v0 & 1) {
        (*(s8 *)((s8 *)(arg0) + (0x1A))) = 0;
    } else {
        (*(s8 *)((s8 *)(arg0) + (0x1A))) = 1;
    }
    if (temp_v0 & 2) {
        (*(s8 *)((s8 *)(arg0) + (0x1B))) = 0;
    } else {
        (*(s8 *)((s8 *)(arg0) + (0x1B))) = 1;
    }
    if (temp_v0 & 4) {
        (*(s8 *)((s8 *)(arg0) + (0x1C))) = 0;
    } else {
        (*(s8 *)((s8 *)(arg0) + (0x1C))) = 1;
    }
    temp_v0_2 = (*(s16 *)((s8 *)(arg0) + (0x18)));
    if (temp_v0_2 == 0) {
        (*(s8 *)((s8 *)(arg0) + (0x1C))) = 0;
        return;
    }
    (*(f32 *)((s8 *)(arg0) + (0x10))) = (f32) (50.0f / (f32) temp_v0_2);
}

void func_800EC9E0(s32 arg0, s32 arg1, s32 arg2) {
}
void func_800EC9F0(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, f32 *arg4) {
    f32 ratio;
    f32 delta[4];
    Vtx *end;

    end = arg1 + arg3;
    ratio = arg4[0x70 / 4] / arg4[0x74 / 4];
    delta[0] = (arg4[0x60 / 4] - arg4[0x50 / 4]) * ratio;
    delta[1] = (arg4[0x64 / 4] - arg4[0x54 / 4]) * ratio;
    delta[2] = (arg4[0x68 / 4] - arg4[0x58 / 4]) * ratio;
    delta[3] = (arg4[0x6C / 4] - arg4[0x5C / 4]) * ratio;
    for (; arg1 < end; arg1++, arg2++) {
        arg2->v.cn[0] = (arg4[0x50 / 4] + delta[0]) * arg1->v.cn[0];
        arg2->v.cn[1] = (arg4[0x54 / 4] + delta[1]) * arg1->v.cn[1];
        arg2->v.cn[2] = (arg4[0x58 / 4] + delta[2]) * arg1->v.cn[2];
        arg2->v.cn[3] = (arg4[0x5C / 4] + delta[3]) * arg1->v.cn[3];
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ECD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ECEEC.s")

void func_800ED064(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, f32 *arg4) {
    s16 delta;
    Vtx *end;

    delta = (s32)((arg4[0x44 / 4] / arg4[0x48 / 4]) * (arg4[0x8 / 4] - arg4[0x4 / 4]) + arg4[0x4 / 4]);
    end = arg1 + arg3;
    for (; arg1 < end; arg1++, arg2++) {
        arg2->v.ob[1] = arg1->v.ob[1] + delta;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED0D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED144.s")

void func_800ED424(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, f32 *arg4) {
    f32 ratio;
    f32 color[4];
    Vtx *end;

    end = arg1 + arg3;
    ratio = arg4[0x98 / 4] / arg4[0x9C / 4];
    color[0] = (arg4[0x78 / 4] + ((arg4[0x88 / 4] - arg4[0x78 / 4]) * ratio)) / 255.0f;
    color[1] = (arg4[0x7C / 4] + ((arg4[0x8C / 4] - arg4[0x7C / 4]) * ratio)) / 255.0f;
    color[2] = (arg4[0x80 / 4] + ((arg4[0x90 / 4] - arg4[0x80 / 4]) * ratio)) / 255.0f;
    color[3] = (arg4[0x84 / 4] + ((arg4[0x94 / 4] - arg4[0x84 / 4]) * ratio)) / 255.0f;
    for (; arg1 < end; arg1++, arg2++) {
        arg2->v.cn[0] = arg1->v.cn[0] * color[0];
        arg2->v.cn[1] = arg1->v.cn[1] * color[1];
        arg2->v.cn[2] = arg1->v.cn[2] * color[2];
        arg2->v.cn[3] = arg1->v.cn[3] * color[3];
    }
}

void func_800ED79C(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, f32 *arg4) {
    s32 alpha;
    Vtx *end;
    f32 ratio;

    ratio = arg4[0x98 / 4] / arg4[0x9C / 4];
    alpha = arg4[0x84 / 4] + (arg4[0x94 / 4] - arg4[0x84 / 4]) * ratio;
    end = arg1 + arg3;
    for (; arg1 < end; arg1++, arg2++) {
        arg2->v.cn[3] = alpha;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED7F8.s")

void func_800ED964(void *self){
    MeshEffect *arg0 = (MeshEffect *)self;
    extern f32 D_80125E60;
    if(arg0->unk48 == 0.0f){
        arg0->unk48 = D_80125E60;
    }

    if(arg0->unkC != NULL){
        arg0->unkC(arg0);
    }
}

void func_800ED9B4(void *self, f32 arg1[3], f32 arg2[3], f32 arg3, s32 arg4){
    MeshEffect *arg0 = (MeshEffect *)self;
    arg0->unk2C[0] = arg1[0];
    arg0->unk2C[1] = arg1[1];
    arg0->unk2C[2] = arg1[2];
    arg0->unk38[0] = arg2[0];
    arg0->unk38[1] = arg2[1];
    arg0->unk38[2] = arg2[2];
    arg0->unk29 = 1;
    arg0->unk4C = 0;
    arg0->unk48 = arg3;
    arg0->unk44 = 0.0f;
    arg0->unk4E = (s16) arg4;
    func_800ED964(arg0);
}

s32 func_800EDA24(s16 *arg0) {
    return arg0[38];
}

int func_800EDA2C(void *self, f32 arg1[3]) {
    MeshEffect *arg0 = self;
    return (arg0->unk14[0] <= arg1[0]) && (arg1[0] < arg0->unk1A[0])
        && (arg0->unk14[2] <= arg1[2]) && (arg1[2] < arg0->unk1A[2]);
}

/* extern */

void func_800EDAF4(u8 *arg0) {
    s32 func_800C2FDC(s32, u8);
    u8 temp_a1;

    temp_a1 = *arg0;
    if (temp_a1 != 0) {
        func_800C2FDC(temp_a1 & 0xFF, temp_a1);
    }
}

void func_800EDB20(void *self, s32 arg1, void *model, s32 mesh_id) {
    void _glidmake_entrypoint_2(s32, s32, u8 *, u8 *);
    MeshEffect *arg0 = self;
    arg0->unk0 = 0;
    arg0->unkC = NULL;
    arg0->unk10 = NULL;
    arg0->unk29 = 0;
    arg0->unk28 = 0;
    arg0->unk4C = 0;
    arg0->unk4E = 0;
    arg0->unk70 = 0.0f;
    arg0->unk74 = 0.0f;
    arg0->unk9C = 0.0f;
    arg0->unk98 = 0.0f;
    arg0->unk44 = 0;
    arg0->unk48 = 0;
    _glidmake_entrypoint_2((s32)model, mesh_id, (u8 *)arg0->unk14, (u8 *)arg0->unk1A);
}

void func_800EDBA0(void *self, f32 arg1[3], f32 arg2[3], f32 arg3, s32 arg4){
    MeshEffect *arg0 = (MeshEffect *)self;
    arg0->unk2C[0] = arg1[0];
    arg0->unk2C[1] = arg1[1];
    arg0->unk2C[2] = arg1[2];
    arg0->unk38[0] = arg2[0];
    arg0->unk38[1] = arg2[1];
    arg0->unk38[2] = arg2[2];
    arg0->unk29 = 2;
    arg0->unk4C = 0;
    arg0->unk48 = arg3;
    arg0->unk44 = 0.0f;
    arg0->unk4E = arg4;
    func_800ED964(arg0);
}

void func_800EDC10(void *self, f32 arg1, f32 arg2, f32 arg3,s32 arg4){
    MeshEffect *arg0 = (MeshEffect *)self;
    arg0->unk29 = 3;
    arg0->unk4 = arg1;
    arg0->unk44 = 0.0f;
    arg0->unk48 = arg3;
    arg0->unk8 = arg2;
    arg0->unk4C = 0;
    arg0->unk4E = arg4;
    func_800ED964(arg0);
}

void func_800EDC64(void *self, f32 arg1, f32 arg2, f32 arg3,s32 arg4){
    MeshEffect *arg0 = (MeshEffect *)self;
    arg0->unk29 = 7;
    arg0->unk4 = arg1;
    arg0->unk44 = 0.0f;
    arg0->unk48 = arg3;
    arg0->unk8 = arg2;
    arg0->unk4C = 0;
    arg0->unk4E = arg4;
    func_800ED964(arg0);
}

void func_800EDCB8(void *arg0, f32 arg1) {
    void func_800EDC10(void *, f32, f32, f32, s32);
    func_800EDC10(arg0, arg1, arg1, 0.0f, 1);
}

void func_800EDCEC(void *arg0, f32 arg1) {
    void func_800EDC64(void *, f32, f32, f32, s32);
    func_800EDC64(arg0, arg1, arg1, 0.0f, 1);
}

/* extern */

void func_800EDD20(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    void func_800EDC10(void *, f32, f32, f32, s32);
    void func_800EE010();
    func_800EE010();
    func_800EDC10(arg0, arg1, arg2, arg3, arg4);
}

void func_800EDD68(void *self, f32 arg1[4], f32 arg2[4], f32 arg3) {
    extern f32 D_80125E64;
    MeshEffect *arg0 = self;
    arg0->unk50[0] = arg1[0];
    arg0->unk50[1] = arg1[1];
    arg0->unk50[2] = arg1[2];
    arg0->unk50[3] = arg1[3];
    arg0->unk60[0] = arg2[0];
    arg0->unk60[1] = arg2[1];
    arg0->unk60[2] = arg2[2];
    arg0->unk60[3] = arg2[3];
    arg0->unk70 = 0.0f;
    arg0->unk28 = 0;
    arg0->unk74 = (arg3 > 0.0f) ? arg3 : D_80125E64;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDE54.s")

void func_800EDF2C(void *self, s32 from, s32 to, f32 time) {
    extern f32 D_80125E70;
    MeshEffect *arg0 = self;
    arg0->unk29 = 5;
    arg0->unk28 = 0;
    arg0->unk84 = (f32) from;
    arg0->unk78[0] = arg0->unk78[1] = arg0->unk78[2] = 0.0f;
    arg0->unk94 = (f32) to;
    arg0->unk88[0] = arg0->unk88[1] = arg0->unk88[2] = 0.0f;
    arg0->unk9C = (time > 0) ? time : D_80125E70;
    arg0->unk98 = 0.0f;
}

void func_800EDF98(void *self, s32 opacity){
    void func_800EDF2C(void *, s32, s32, f32);
    MeshEffect *arg0 = (MeshEffect *)self;
    func_800EDF2C(arg0, opacity, opacity, 0.0f);
}

void func_800EDFBC(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4)
{
  void func_800ED964(void *);
  *((s8 *) (((s8 *) arg0) + 0x29)) = 4;
  *((f32 *) (((s8 *) arg0) + 4)) = arg1;
  *((f32 *) (((s8 *) arg0) + 0x48)) = arg3;
  *((f32 *) (((s8 *) arg0) + 0x44)) = 0.0f;
  *((f32 *) (((s8 *) arg0) + 8)) = arg2;
  *((s16 *) (((s8 *) arg0) + 0x4C)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x4E)) = (s16) arg4;
  func_800ED964(arg0);
}

void func_800EE010(void *self){
    void func_800EE040(void *, s32, f32, f32);
    MeshEffect *arg0 = self;
    func_800EE040(arg0, 0x3EC, 0.7f, 0.9f);
}

void func_800EE040(void *self, s32 sfx_id, f32 arg2, f32 arg3){
    s32 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C330C(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C3058(u8, s32);
    void func_800C3BDC(u8);
    MeshEffect *arg0 = self;
    if(arg0->unk0 == 0){
        arg0->unk0 = func_800C2E04();
    }
    arg0->unk20 = arg2;
    arg0->unk24 = arg3;
    func_800C301C(arg0->unk0, sfx_id);
    func_800C330C(arg0->unk0, 3);
    func_800C31DC(arg0->unk0, (arg2 + arg3) * 0.5f);
    func_800C3058(arg0->unk0, 32000);
    func_800C3BDC(arg0->unk0);
}

void func_800EE0F0(s32 *arg0, s32 arg1) {
    arg0[3] = arg1;
}

void func_800EE0F8(s32 *arg0, s32 arg1) {
    arg0[4] = arg1;
}

void func_800EE100(s16 *arg0, s32 arg1) {
    arg0[38] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EE108.s")
