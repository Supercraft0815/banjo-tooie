#include "common.h"
#include "mesh_effect_presets.inc"
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
}               typedef struct { u8 pad0[0x4]; f32 unk4; f32 unk8; f32 unkC; f32 unk10; f32 unk14; s16 unk18; s8 unk1A; s8 unk1B; s8 unk1C; u8 pad1D[0xC]; s8 unk29; u8 pad2A[0x1A]; f32 unk44; f32 unk48; s16 unk4C; s16 unk4E; } Obj1EC6180_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
void func_800EC898(u8 *arg0, s32 arg1, BtIntPtr arg2, s32 arg3) {

    void _glidmake_entrypoint_2(BtIntPtr, s32, u8 *, u8 *);
    s32 func_800EA05C();

    MeshEffectPreset *var_t0;
    s16 temp_v0_2;
    s16 var_v1;
    s32 temp_lo;
    s32 temp_v0;

    temp_v0 = func_800EA05C();
    for (var_t0 = D_80123580; var_t0->map != 0; var_t0++) {
        if (temp_v0 == var_t0->map && arg3 == var_t0->mesh) {
            break;
        }
    }
    (((Obj1EC6180_arg0 *)arg0)->unk14) = (f32) (2048.0f / (f32) (var_t0->scale));
    (((Obj1EC6180_arg0 *)arg0)->unkC) = (f32) ((var_t0->offset) << 6);
    _glidmake_entrypoint_2(arg2, arg3, arg0, arg0 + 6);
    temp_v0 = arg1 / 10;
    if (temp_v0 & 1) {
        (((Obj1EC6180_arg0 *)arg0)->unk1A) = 0;
    } else {
        (((Obj1EC6180_arg0 *)arg0)->unk1A) = 1;
    }
    if (temp_v0 & 2) {
        (((Obj1EC6180_arg0 *)arg0)->unk1B) = 0;
    } else {
        (((Obj1EC6180_arg0 *)arg0)->unk1B) = 1;
    }
    if (temp_v0 & 4) {
        (((Obj1EC6180_arg0 *)arg0)->unk1C) = 0;
    } else {
        (((Obj1EC6180_arg0 *)arg0)->unk1C) = 1;
    }
    temp_v0_2 = (((Obj1EC6180_arg0 *)arg0)->unk18);
    if (temp_v0_2 == 0) {
        (((Obj1EC6180_arg0 *)arg0)->unk1C) = 0;
        return;
    }
    (((Obj1EC6180_arg0 *)arg0)->unk10) = (f32) (50.0f / (f32) temp_v0_2);
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

void func_800ECD60(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, f32 *arg4) {
    void func_800EFE50(f32 dst[3], f32 start[3], f32 end[3], f32 t);
    f32 ratio;
    f32 delta[3];
    Vtx *end;

    ratio = arg4[0x44 / 4] / arg4[0x48 / 4];
    ratio = ratio * ratio * ratio * ratio;
    func_800EFE50(delta, &arg4[0x2C / 4], &arg4[0x38 / 4], ratio);
    end = arg1 + arg3;
    for (; arg1 < end; arg1++, arg2++) {
        arg2->v.ob[0] = (s16)(arg1->v.ob[0] + delta[0]);
        arg2->v.ob[1] = (s16)(arg1->v.ob[1] + delta[1]);
        arg2->v.ob[2] = (s16)(arg1->v.ob[2] + delta[2]);
    }
}

void func_800ECEEC(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, f32 *arg4) {
    void func_800EFE50(f32 dst[3], f32 start[3], f32 end[3], f32 t);
    f32 ratio;
    f32 delta[3];
    Vtx *end;

    ratio = arg4[0x44 / 4] / arg4[0x48 / 4];
    func_800EFE50(delta, &arg4[0x2C / 4], &arg4[0x38 / 4], ratio);
    end = arg1 + arg3;
    for (; arg1 < end; arg1++, arg2++) {
        arg2->v.ob[0] = (s16)(arg1->v.ob[0] + delta[0]);
        arg2->v.ob[1] = (s16)(arg1->v.ob[1] + delta[1]);
        arg2->v.ob[2] = (s16)(arg1->v.ob[2] + delta[2]);
    }
}

void func_800ED064(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, f32 *arg4) {
    s16 delta;
    Vtx *end;

    delta = (s32)((arg4[0x44 / 4] / arg4[0x48 / 4]) * (arg4[0x8 / 4] - arg4[0x4 / 4]) + arg4[0x4 / 4]);
    end = arg1 + arg3;
    for (; arg1 < end; arg1++, arg2++) {
        arg2->v.ob[1] = arg1->v.ob[1] + delta;
    }
}

void func_800ED0D4(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, f32 *arg4) {
    s16 delta;
    Vtx *end;

    delta = (s32)((arg4[0x44 / 4] / arg4[0x48 / 4]) * (arg4[0x8 / 4] - arg4[0x4 / 4]) + arg4[0x4 / 4]);
    end = arg1 + arg3;
    for (; arg1 < end; arg1++, arg2++) {
        arg2->v.ob[2] = arg1->v.ob[2] + delta;
    }
}

void func_800ED144(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, f32 *arg4) {
    f32 ratio;
    f32 delta[4];
    Vtx *end;

    end = arg1 + arg3;
    ratio = arg4[0x98 / 4] / arg4[0x9C / 4];
    delta[0] = (arg4[0x88 / 4] - arg4[0x78 / 4]) * ratio;
    delta[1] = (arg4[0x8C / 4] - arg4[0x7C / 4]) * ratio;
    delta[2] = (arg4[0x90 / 4] - arg4[0x80 / 4]) * ratio;
    delta[3] = (arg4[0x94 / 4] - arg4[0x84 / 4]) * ratio;
    for (; arg1 < end; arg1++, arg2++) {
        arg2->v.cn[0] = (u32)(arg4[0x78 / 4] + delta[0]);
        arg2->v.cn[1] = (u32)(arg4[0x7C / 4] + delta[1]);
        arg2->v.cn[2] = (u32)(arg4[0x80 / 4] + delta[2]);
        arg2->v.cn[3] = (u32)(arg4[0x84 / 4] + delta[3]);
    }
}

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

void func_800ED7F8(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, f32 *arg4) {
    void func_800EF9A8(f32 dst[3], f32 src[3], f32 roll);
    void func_800EFA4C(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
    f32 center[3];
    f32 position[3];
    f32 roll;
    Vtx *end;

    roll = (arg4[0x44 / 4] / arg4[0x48 / 4]) * (arg4[2] - arg4[1]) + arg4[1];
    center[0] = (((s16 *)arg4)[0x14 / 2] + ((s16 *)arg4)[0x1A / 2]) * 0.5f;
    center[1] = (((s16 *)arg4)[0x16 / 2] + ((s16 *)arg4)[0x1C / 2]) * 0.5f;
    center[2] = 0.0f;
    end = arg1 + arg3;
    for (; arg1 < end; arg1++, arg2++) {
        func_800EFA4C(position, arg1->v.ob[0] - center[0], arg1->v.ob[1] - center[1], 0.0f);
        func_800EF9A8(position, position, roll);
        arg2->v.ob[0] = center[0] + position[0];
        arg2->v.ob[1] = center[1] + position[1];
    }
}

void func_800ED964(void *self){
    MeshEffect *arg0 = (MeshEffect *)self;
    if(arg0->unk48 == 0.0f){
        arg0->unk48 = 0.00001f;
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
    BT_IDO_ONLY(s32 func_800C2FDC();) BT_NATIVE_ONLY(s32 func_800C2FDC(u8);)
    s32 temp_a1;

    temp_a1 = *arg0;
    if (temp_a1 != 0) {
        BT_IDO_ONLY(func_800C2FDC(temp_a1 & 0xFF, temp_a1);) BT_NATIVE_ONLY(func_800C2FDC(temp_a1 & 0xFF);)
    }
}

void func_800EDB20(void *self, s32 arg1, void *model, s32 mesh_id) {
    void _glidmake_entrypoint_2(BtIntPtr, s32, u8 *, u8 *);
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
    _glidmake_entrypoint_2((BtIntPtr)model, mesh_id, (u8 *)arg0->unk14, (u8 *)arg0->unk1A);
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
    arg0->unk74 = (arg3 > 0.0f) ? arg3 : 0.001f;
}

void func_800EDDDC(void *self, f32 arg1[4], f32 arg2[4], f32 arg3) {
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
    arg0->unk74 = (arg3 > 0.0f) ? arg3 : 0.001f;
    arg0->unk29 = 6;
}

void func_800EDE54(void *self, s32 arg1[4], s32 arg2[4], f32 arg3) {
    MeshEffect *arg0 = self;
    arg0->unk78[0] = (f32) arg1[0];
    arg0->unk78[1] = (f32) arg1[1];
    arg0->unk78[2] = (f32) arg1[2];
    arg0->unk84 = (f32) arg1[3];
    arg0->unk88[0] = (f32) arg2[0];
    arg0->unk88[1] = (f32) arg2[1];
    arg0->unk88[2] = (f32) arg2[2];
    arg0->unk94 = (f32) arg2[3];
    arg0->unk28 = 0;
    arg0->unk9C = (arg3 > 0.0f) ? arg3 : 0.001f;
    arg0->unk98 = 0.0;
}

void func_800EDF2C(void *self, s32 from, s32 to, f32 time) {
    MeshEffect *arg0 = self;
    arg0->unk29 = 5;
    arg0->unk28 = 0;
    arg0->unk84 = (f32) from;
    arg0->unk78[0] = arg0->unk78[1] = arg0->unk78[2] = 0.0f;
    arg0->unk94 = (f32) to;
    arg0->unk88[0] = arg0->unk88[1] = arg0->unk88[2] = 0.0f;
    arg0->unk9C = (time > 0) ? time : 0.001f;
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
  ((Obj1EC6180_arg0 *)arg0)->unk29 = 4;
  ((Obj1EC6180_arg0 *)arg0)->unk4 = arg1;
  ((Obj1EC6180_arg0 *)arg0)->unk48 = arg3;
  ((Obj1EC6180_arg0 *)arg0)->unk44 = 0.0f;
  ((Obj1EC6180_arg0 *)arg0)->unk8 = arg2;
  ((Obj1EC6180_arg0 *)arg0)->unk4C = 0;
  ((Obj1EC6180_arg0 *)arg0)->unk4E = (s16) arg4;
  func_800ED964(arg0);
}

void func_800EE010(void *self){
    void func_800EE040(void *, s32, f32, f32);
    MeshEffect *arg0 = self;
    func_800EE040(arg0, 0x3EC, 0.7f, 0.9f);
}

void func_800EE040(void *self, s32 sfx_id, f32 arg2, f32 arg3){
    u8 func_800C2E04(void);
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

void func_800EE108(MeshEffect *arg0, BtIntPtr model, s32 mesh_id) {
    f32 func_800D8FF8(void);
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    f32 func_800C395C(u8);
    s16 func_800C3920(u8);
    f32 func_800DC264(f32, f32);
    s32 func_800DC214(s32, s32);
    void func_800C31DC(u8, f32);
    void func_800C3058(u8, s32);
    BT_IDO_ONLY(s32 func_800C2FDC();) BT_NATIVE_ONLY(s32 func_800C2FDC(u8);)
    void func_800ECD60();
    void func_800ECEEC();
    void func_800ED064();
    void func_800ED0D4();
    void func_800ED144();
    void func_800ED79C();
    void func_800ED7F8();
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    s32 sp20;

    sp2C = func_800D8FF8();
    if (arg0->unk74 > 0.0f) {
        arg0->unk70 += sp2C;
        if (arg0->unk74 <= arg0->unk70) {
            arg0->unk70 = arg0->unk74;
            if (arg0->unk28 == 0) {
                arg0->unk28 = 2;
            }
        }
        _glid_entrypoint_0(model, mesh_id, (s32 *)func_800EC9F0, (BtIntPtr)arg0);
        if (arg0->unk28 != 0) {
            arg0->unk28--;
            if (arg0->unk28 == 0) {
                arg0->unk74 = 0.0f;
            }
        }
    }
    if (arg0->unk9C > 0.0f) {
        arg0->unk98 += sp2C;
        if (arg0->unk9C <= arg0->unk98) {
            arg0->unk98 = arg0->unk9C;
            if (arg0->unk28 == 0) {
                arg0->unk28 = 2;
            }
        }
        switch (arg0->unk29) {
            case 5:
                _glid_entrypoint_0(model, mesh_id, (s32 *)func_800ED79C, (BtIntPtr)arg0);
                break;
            case 6:
                _glid_entrypoint_0(model, mesh_id, (s32 *)func_800ED424, (BtIntPtr)arg0);
                break;
            default:
                _glid_entrypoint_0(model, mesh_id, (s32 *)func_800ED144, (BtIntPtr)arg0);
                break;
        }
        if (arg0->unk28 != 0) {
            arg0->unk28--;
            if (arg0->unk28 == 0) {
                arg0->unk9C = 0.0f;
            }
        }
    }
    if ((arg0->unk29 == 0) || (arg0->unk29 == 5)) {
        return;
    }
    arg0->unk44 += sp2C;
    if (arg0->unk48 < arg0->unk44) {
        arg0->unk44 = arg0->unk48;
    }
    if (arg0->unk0 != 0) {
        sp28 = arg0->unk44 / arg0->unk48;
        sp24 = func_800C395C(arg0->unk0);
        sp20 = func_800C3920(arg0->unk0);
        sp24 += func_800DC264(-1.0f, 1.0f) * sp2C;
        sp24 = (arg0->unk20 > sp24) ? arg0->unk20 : sp24;
        sp24 = (arg0->unk24 < sp24) ? arg0->unk24 : sp24;
        sp20 += func_800DC214(-0xF, 0xF);
        sp20 = (0x7FFF < sp20) ? 0x7FFF : sp20;
        sp20 = (31000 > sp20) ? 31000 : sp20;
        if (0.8500000238418579f <= sp28) {
            sp20 = (1.0f - ((sp28 - 0.8500000238418579f) / 0.1499999761581421f)) * sp20;
        }
        func_800C31DC(arg0->unk0, sp24);
        func_800C3058(arg0->unk0, sp20);
    }
    switch (arg0->unk29) {
        case 1:
            _glid_entrypoint_0(model, mesh_id, (s32 *)func_800ECD60, (BtIntPtr)arg0);
            break;
        case 2:
            _glid_entrypoint_0(model, mesh_id, (s32 *)func_800ECEEC, (BtIntPtr)arg0);
            break;
        case 3:
            _glid_entrypoint_0(model, mesh_id, (s32 *)func_800ED064, (BtIntPtr)arg0);
            break;
        case 4:
            _glid_entrypoint_0(model, mesh_id, (s32 *)func_800ED7F8, (BtIntPtr)arg0);
            break;
        case 7:
            _glid_entrypoint_0(model, mesh_id, (s32 *)func_800ED0D4, (BtIntPtr)arg0);
            break;
    }
    if (arg0->unk48 <= arg0->unk44) {
        arg0->unk29 = 0;
        arg0->unk4C = arg0->unk4E;
        if (arg0->unk10 != NULL) {
            arg0->unk10(arg0);
        }
        if (arg0->unk0 != 0) {
            func_800C2FDC(arg0->unk0);
            arg0->unk0 = 0;
        }
    }
}
