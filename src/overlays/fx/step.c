#include "common.h"

/* extern */

typedef struct { s32 unk0; u8 pad4[0x4]; f32 unk8; u8 padC[0x4]; f32 unk10; s32 (*unk14)(u8 *, s32, s32); s32 unk18; s32 (*unk1C)(void *, s32, s32); s32 unk20; u8 unk24; u8 unk25; u8 unk26; } Objstep_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ s32 func_80800000_fxstep(void *arg0) {
    s32 func_800C84B0(s32);
    f32 temp_f0;
    s32 temp_a1;

    temp_f0 = (((Objstep_arg0 *)arg0)->unk10) - (((Objstep_arg0 *)arg0)->unk8);
    if ((temp_f0 > 0.0f) && (temp_f0 < 60.0f)) {
        return 4;
    }
    temp_a1 = (((Objstep_arg0 *)arg0)->unk0);
    if (temp_a1 == 0) {
        return 0;
    }
    return func_800C84B0(temp_a1);
}

/* extern */

void func_80800078_fxstep(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C35E8(u8, f32[3]);
    void func_800C3BDC(u8);
    f32 func_800DC178(f32, f32);
    f32 temp_f0;
    f32 sp20;
    u8 var_s0;

    temp_f0 = arg3 * 0.5f;
    sp20 = func_800DC178(arg2 - temp_f0, arg2 + temp_f0);
    if ((((Objstep_arg0 *)arg0)->unk26) != 0) {
        var_s0 = (((Objstep_arg0 *)arg0)->unk24);
    } else {
        var_s0 = (((Objstep_arg0 *)arg0)->unk25);
    }
    func_800C35E8(var_s0, (f32 *)(arg0 + 4));
    func_800C301C(var_s0, arg1);
    func_800C31DC(var_s0, sp20);
    func_800C3058(var_s0, arg4);
    func_800C3BDC(var_s0);
    (((Objstep_arg0 *)arg0)->unk26) = (u8) ((((Objstep_arg0 *)arg0)->unk26) ^ 1);
}

/* extern */

void func_8080012C_fxstep(u8 *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6) {
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C35E8(u8, f32[3]);
    void func_800C3BDC(u8);
    f32 func_800DC178(f32, f32);
    f32 var_f2;
    f32 temp_f0;
    s32 var_a2;
    u8 var_s0;

    if ((((Objstep_arg0 *)arg0)->unk26) != 0) {
        var_f2 = arg3;
    } else {
        var_f2 = arg4;
    }
    temp_f0 = arg5 * 0.5f;
    var_f2 = func_800DC178(var_f2 - temp_f0, var_f2 + temp_f0);
    if (arg0[0x26] != 0) {
        var_a2 = arg1;
    } else {
        var_a2 = arg2;
    }
    if (arg0[0x26] != 0) {
        var_s0 = (((Objstep_arg0 *)arg0)->unk24);
    } else {
        var_s0 = (((Objstep_arg0 *)arg0)->unk25);
    }
    func_800C35E8(var_s0, (f32 *)(arg0 + 4));
    func_800C301C(var_s0, var_a2);
    func_800C31DC(var_s0, var_f2);
    func_800C3058(var_s0, arg6);
    func_800C3BDC(var_s0);
    (((Objstep_arg0 *)arg0)->unk26) = (u8) ((((Objstep_arg0 *)arg0)->unk26) ^ 1);
}

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
} FxStepEntry;

s32 func_80800210_fxstep(u8 *arg0, f32 arg1, f32 arg2, s32 arg3) {
    void func_8080012C_fxstep(u8 *, s32, s32, f32, f32, f32, s32);
    extern FxStepEntry D_80800830_fxstep[];
    s32 i;

    for (i = 0; D_80800830_fxstep[i].id != 0; i++) {
        if (arg3 == D_80800830_fxstep[i].id) {
            func_8080012C_fxstep(arg0, D_80800830_fxstep[i].value1, D_80800830_fxstep[i].value2, D_80800830_fxstep[i].value8 + arg1, D_80800830_fxstep[i].valueC + arg1, D_80800830_fxstep[i].value10, (s32) ((f32) D_80800830_fxstep[i].value14 * arg2));
            return 1;
        }
    }
    return 0;
}
typedef struct { s16 id; s16 sound; f32 offset; f32 flags; s16 scale; s16 pad; } StepEntry;
s32 func_808002B4_fxstep(BtIntPtr arg0, f32 arg1, f32 arg2, s32 arg3) {
    void func_80800078_fxstep(u8 *, s32, f32, f32, s32);








    extern StepEntry D_80800AA0_fxstep[];
    s32 i;
    for (i = 0; D_80800AA0_fxstep[i].id != 0; i++) {
        if (arg3 == D_80800AA0_fxstep[i].id) {
            func_80800078_fxstep(arg0, D_80800AA0_fxstep[i].sound, D_80800AA0_fxstep[i].offset + arg1, D_80800AA0_fxstep[i].flags, (s32) ((f32) D_80800AA0_fxstep[i].scale * arg2));
            return 1;
        }
    }
    return 0;
}

/* extern */

void func_80800344_fxstep(u8 *arg0, f32 arg1, f32 arg2, s32 arg3) {
    s32 func_80800210_fxstep(u8 *, f32, f32, s32);
    s32 var_a3;
    s32 (*temp_v0_2)(u8 *, s32, s32);

    var_a3 = func_80800000_fxstep(arg0);
    if (arg3 != 0) {
        func_80800210_fxstep(arg0, arg1, arg2, var_a3);
    }
    temp_v0_2 = (((Objstep_arg0 *)arg0)->unk14);
    if (temp_v0_2 != NULL) {
        temp_v0_2(arg0, var_a3, (((Objstep_arg0 *)arg0)->unk18));
    }
}

/* extern */

void func_808003B4_fxstep(void *arg0, f32 arg1, f32 arg2, s32 arg3) {
    s32 func_808002B4_fxstep(BtIntPtr, f32, f32, s32);
    s32 var_a3;
    s32 (*temp_v0_2)(void *, s32, s32);

    var_a3 = func_80800000_fxstep(arg0);
    if (arg3 != 0) {
        func_808002B4_fxstep(arg0, arg1, arg2, var_a3);
    }
    temp_v0_2 = (((Objstep_arg0 *)arg0)->unk1C);
    if (temp_v0_2 != NULL) {
        temp_v0_2(arg0, var_a3, (((Objstep_arg0 *)arg0)->unk20));
    }
}

/* extern */

void fxstep_entrypoint_0(void *arg0) {
    s32 func_800C2FDC(u8);
    void heap_free(void *memory);
    func_800C2FDC((((Objstep_arg0 *)arg0)->unk24));
    func_800C2FDC((((Objstep_arg0 *)arg0)->unk25));
    heap_free(arg0);
}

void *fxstep_entrypoint_1(void) {
    u8 func_800C2E04(void);
    void func_800C330C(u8, s32);
    void func_800C3418(u8, s32);
    void func_800EFD24(f32 *);
    void *heap_alloc(s32);
    void fxstep_entrypoint_4(void *, BtIntPtr, s32);
    void fxstep_entrypoint_5(void *, s32, f32);
    void fxstep_entrypoint_7(void *, BtIntPtr, s32);
    struct {
        s32 unk0;
        f32 position[3];
        s32 unk10[5];
        u8 sound0;
        u8 sound1;
        u8 flag0;
        u8 flag1;
    } *this = heap_alloc(sizeof(*this));

    this->flag0 = 0;
    this->flag1 = 1;
    this->sound0 = func_800C2E04();
    func_800C330C(this->sound0, 3);
    func_800C3418(this->sound0, 0);
    this->sound1 = func_800C2E04();
    func_800C330C(this->sound1, 3);
    func_800C3418(this->sound1, 0);
    func_800EFD24(this->position);
    fxstep_entrypoint_4(this, 0, 0);
    fxstep_entrypoint_5(this, 0, 0.0f);
    fxstep_entrypoint_7(this, 0, 0);
    return this;
}

void fxstep_entrypoint_2(s8 *arg0, s32 arg1) {
    arg0[38] = arg1;
}

void fxstep_entrypoint_3(s8 *arg0, s32 arg1) {
    arg0[39] = arg1;
}

void fxstep_entrypoint_4(void *arg0, BtIntPtr arg1, s32 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0x1C))) = arg1;
    (*(s32 *)((s8 *)(arg0) + (0x20))) = arg2;
}

void fxstep_entrypoint_5(void *arg0, s32 arg1, f32 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x10))) = arg2;
}

/* extern */

void fxstep_entrypoint_6(BtIntPtr effect, f32 position[3]) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8((f32 *)(effect + 4), position);
}

void fxstep_entrypoint_7(void *arg0, BtIntPtr arg1, s32 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0x14))) = arg1;
    (*(s32 *)((s8 *)(arg0) + (0x18))) = arg2;
}

/* extern */

void fxstep_entrypoint_8(u8 *arg0, f32 arg1, f32 arg2) {
    void func_808003B4_fxstep(void *, f32, f32, s32);
    func_808003B4_fxstep(arg0, arg1, arg2, arg0[0x27]);
}

/* extern */

void fxstep_entrypoint_9(void *arg0) {
    void func_808003B4_fxstep(void *, f32, f32, s32);
    func_808003B4_fxstep(arg0, 0.0f, 1.0f, 0);
}

/* extern */

void fxstep_entrypoint_10(BtIntPtr arg0, s32 arg1) {
    s32 func_808002B4_fxstep(BtIntPtr, f32, f32, s32);
    func_808002B4_fxstep(arg0, 0.0f, 1.0f, arg1);
}

void fxstep_entrypoint_11(u8 *arg0, f32 arg1, f32 arg2) {
    void func_80800344_fxstep(u8 *, f32, f32, s32);
    func_80800344_fxstep(arg0, arg1, arg2, arg0[0x27]);
}

void fxstep_entrypoint_12(u8 *arg0) {
    void func_80800344_fxstep(u8 *, f32, f32, s32);
    func_80800344_fxstep(arg0, 0.0f, 1.0f, 0);
}

/* extern */

void fxstep_entrypoint_13(u8 *arg0, s32 arg1) {
    s32 func_80800210_fxstep(u8 *, f32, f32, s32);
    if (arg0[0x27] != 0) {
        func_80800210_fxstep(arg0, 0.0f, 1.0f, arg1);
    }
}

/* extern */

void fxstep_entrypoint_14(s32 arg0, s32 arg1, f32 *arg2, s32 arg3, s32 arg4) {
    u8 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C3584(u8, f32, f32);
    void func_800C35E8(u8, f32[3]);
    void func_800C3BDC(u8);
    f32 func_800DC178(f32, f32);
    s32 fxstep_entrypoint_15(s32, s32, s32 *, s32 *, f32 *);
    s32 sp3C;
    s32 sp38;
    f32 sp34;
    u8 temp_s0;

    if (fxstep_entrypoint_15(arg0, arg1, &sp3C, &sp38, &sp34) != 0) {
        temp_s0 = func_800C2E04();
        func_800C330C(temp_s0, 1);
        func_800C35E8(temp_s0, arg2);
        func_800C301C(temp_s0, sp3C);
        func_800C31DC(temp_s0, func_800DC178(-0.05f, 0.05f) + sp34);
        func_800C3058(temp_s0, sp38);
        func_800C3584(temp_s0, (f32) arg3, (f32) arg4);
        func_800C3BDC(temp_s0);
    }
}

s32 fxstep_entrypoint_15(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, f32 *arg4) {
    f32 func_800DC178(f32, f32);
    extern FxStepEntry D_80800830_fxstep[];
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
/* data_to_c.py: from asm/data/overlays/fx/step.data.s */
FxStepEntry D_80800830_fxstep [26] BT_DATA(4, overlays_fx_step, 0x0) = { { 1, 1028, 1028, 0, 1.0f, 1.2f, 0.05f, 9000, 0 }, { 2, 1027, 1027, 0, 1.0f, 1.2f, 0.05f, 3000, 0 }, { 3, 1029, 1029, 0, 1.0f, 1.2f, 0.05f, 11000, 0 }, { 4, 1034, 1034, 0, 1.0f, 1.2f, 0.05f, 13000, 0 }, { 5, 1049, 1049, 0, 1.0f, 1.2f, 0.05f, 9000, 0 }, { 6, 1026, 1026, 0, 1.0f, 1.2f, 0.05f, 7000, 0 }, { 7, 1051, 1051, 0, 1.0f, 1.0f, 0.05f, 10000, 0 }, { 8, 1025, 1025, 0, 0.7f, 0.8f, 0.05f, 17000, 0 }, { 11, 1034, 1034, 0, 0.5f, 0.55f, 0.01f, 16000, 0 }, { 9, 1113, 1113, 0, 1.0f, 1.1f, 0.05f, 21000, 0 }, { 10, 1114, 1114, 0, 1.0f, 1.1f, 0.05f, 21000, 0 }, { 12, 1154, 1154, 0, 0.85f, 0.89f, 0.05f, 21000, 0 }, { 13, 1008, 1008, 0, 0.96f, 1.04f, 0.02f, 10000, 0 }, { 14, 1034, 1034, 0, 1.2f, 1.35f, 0.05f, 13000, 0 }, { 15, 1135, 1135, 0, 0.95f, 1.1f, 0.05f, 16000, 0 }, { 16, 1051, 1051, 0, 1.0f, 1.0f, 0.05f, 9000, 0 }, { 17, 1198, 1198, 0, 1.0f, 1.0f, 0.05f, 9000, 0 }, { 18, 1212, 1212, 0, 1.0f, 1.0f, 0.05f, 9000, 0 }, { 19, 1390, 1390, 0, 1.0f, 1.1f, 0.05f, 11000, 0 }, { 21, 1034, 1034, 0, 1.0f, 1.2f, 0.05f, 13000, 0 }, { 22, 1390, 1390, 0, 1.0f, 1.1f, 0.05f, 13000, 0 }, { 23, 1474, 1474, 0, 1.4f, 1.5f, 0.05f, 25000, 0 }, { 26, 1237, 1237, 0, 1.0f, 1.5f, 0.05f, 25000, 0 }, { 20, 1551, 1551, 0, 1.0f, 1.2f, 0.05f, 11000, 0 }, { 24, 1026, 1026, 0, 1.0f, 1.2f, 0.05f, 7000, 0 }, { 0, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0 } };
StepEntry D_80800AA0_fxstep [23] BT_DATA(4, overlays_fx_step, 0x270) = { { 1, 1098, 1.0f, 0.05f, 12000, 0 }, { 2, 1102, 1.0f, 0.05f, 3000, 0 }, { 3, 1029, 1.0f, 0.05f, 14000, 0 }, { 4, 1034, 1.0f, 0.05f, 13000, 0 }, { 5, 1104, 1.0f, 0.05f, 11000, 0 }, { 6, 1100, 1.0f, 0.05f, 10000, 0 }, { 7, 1051, 1.0f, 0.05f, 17000, 0 }, { 8, 1025, 0.7f, 0.05f, 17000, 0 }, { 11, 1034, 0.5f, 0.03f, 17000, 0 }, { 9, 1113, 1.0f, 0.05f, 22000, 0 }, { 10, 1114, 1.0f, 0.05f, 22000, 0 }, { 12, 1154, 0.9f, 0.05f, 22000, 0 }, { 16, 1051, 1.0f, 0.05f, 22000, 0 }, { 17, 1198, 1.0f, 0.05f, 22000, 0 }, { 18, 1212, 1.0f, 0.05f, 22000, 0 }, { 19, 1390, 1.0f, 0.05f, 32767, 0 }, { 21, 1034, 1.0f, 0.05f, 13000, 0 }, { 22, 1390, 0.85f, 0.05f, 28000, 0 }, { 23, 1474, 1.4f, 0.05f, 32000, 0 }, { 26, 1237, 1.0f, 0.05f, 32000, 0 }, { 20, 1551, 1.0f, 0.05f, 14000, 0 }, { 24, 1100, 1.0f, 0.05f, 10000, 0 }, { 0, 0, 0.0f, 0.0f, 0, 0 } };
