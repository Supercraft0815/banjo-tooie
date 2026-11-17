#include "common.h"

typedef struct { u8 pad0[0xC]; f32 unkC; u8 pad10[0x8]; s32 unk18; BtIntPtr unk1C; s16 unk20; u8 unk22; u8 pad23[0x1]; s32 unk24; u8 pad28[0x10]; f32 unk38; } Objleaves_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_fxleaves(void *arg0) {
    void func_8008FE68(f32 *);
    void func_800E3958(f32 *);
    void func_800E3A58(f32 *);
    s32 func_800E3F8C(f32, f32, f32);
    f32 func_800DC178(f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEFD4(f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);
    void *vector_push_back(void **);
    s32 vector_size(void *vec);
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 distance;
    f32 x;
    f32 *sp50;
    f32 sp44[3];
    f32 y;
    s32 i;

    if (vector_size(((Objleaves_arg0 *)arg0)->unk1C) < ((Objleaves_arg0 *)arg0)->unk20) {
        func_8008FE68(sp74);
        func_800E3958(sp68);
        func_800E3A58(sp5C);
        sp50 = vector_push_back((void **)((u8 *)arg0 + 0x1C));
        distance = func_800DC178(50.0f, 1200.0f);
        func_800EFA4C(sp44, 0.0f, func_800DC178(200.0f, 500.0f), -distance);
        if (func_800EEFD4(&((Objleaves_arg0 *)arg0)->unkC) < 25.0f) {
            func_800EF934(sp44, sp44, func_800DC178(0.0f, 360.0f));
        } else {
            func_800EF934(sp44, sp44, sp5C[1] + func_800DC178(-70.0f, 70.0f));
        }
        func_800EE780(sp44, sp74, sp44);
        if (distance < 600.0f) {
            for (i = 0; i < 10 && func_800E3F8C(sp44[0], sp44[1] - 10.0f, sp44[2]); i++) {
                sp44[1] += 100.0f;
            }
        }
        func_800EE7F8(sp50 + 1, sp44);
        func_800EFA4C(sp50 + 4, 0.0f, -100.0f, 0.0f);
        func_800EFD24(sp50 + 7);
        x = func_800DC178(-300.0f, 300.0f);
        y = func_800DC178(-300.0f, 300.0f);
        func_800EFA4C(sp50 + 10, x, y, func_800DC178(-300.0f, 300.0f));
        if (++*((u8 *)arg0 + 0x34) >= 4) {
            *((u8 *)arg0 + 0x34) = 0;
        }
        *(s32 *)sp50 = (&((Objleaves_arg0 *)arg0)->unk24)[*((u8 *)arg0 + 0x34)];
    }
}

void func_80800288_fxleaves(s8 *arg0, s32 arg1) {
    arg0[34] = arg1;
}

/* extern */

void fxleaves_entrypoint_0(void *arg0) {
    void vector_clear(void *vec);
    vector_clear((((Objleaves_arg0 *)arg0)->unk1C));
}

void fxleaves_entrypoint_1(void *arg0) {
    BtIntPtr func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    s32 func_800DF350(void);
    void func_800DF830(s32);
    void * vector_begin(void *vec);
    void * vector_end(void *vec);
    BtUIntPtr sp34;
    BtUIntPtr temp_v0;
    BtUIntPtr var_s0;

    sp34 = vector_begin(((Objleaves_arg0 *)arg0)->unk1C);
    temp_v0 = vector_end(((Objleaves_arg0 *)arg0)->unk1C);
    var_s0 = sp34;
    if (var_s0 < temp_v0) {
        do {
            func_800DF830(2);
            func_800DE448((f32 *)(var_s0 + 4), (f32 *)(var_s0 + 0x1C), 1.0f, NULL, func_800D674C(*(s32 *)var_s0));
            *(s8 *)(var_s0 + 0x34) = func_800DF350();
            var_s0 += 0x38;
        } while (var_s0 < temp_v0);
    }
}

/* extern */

int fxleaves_entrypoint_2(void *arg0) {
    s32 vector_size(void *vec);
    return *&((Objleaves_arg0 *)arg0)->unk22 != 1 &&
        vector_size(((Objleaves_arg0 *)arg0)->unk1C) == 0;
}

/* extern */

void fxleaves_entrypoint_3(void *arg0) {
    void heap_free(void *memory);
    void vector_free(void *vec);
    vector_free((((Objleaves_arg0 *)arg0)->unk1C));
    heap_free(arg0);
}    typedef struct { u8 pad0[0x1C]; BtIntPtr unk1C; s16 unk20; s8 unk22; u8 pad23[0x1]; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s8 unk34; u8 pad35[0x3]; f32 unk38; } Objleaves_fxleaves_entrypoint_4_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */ typedef struct { f32 unk0; f32 unk4; f32 unk8; f32 unkC; f32 unk10; f32 unk14; s32 unk18; } Objleaves_fxleaves_entrypoint_4_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void *fxleaves_entrypoint_4(s32 arg0) {
    void *heap_alloc(s32);
    void * vector_new(u32 element_size, u32 count);
    void *sp1C;
    void *temp_v0;

    temp_v0 = heap_alloc(0x3C);
    (((Objleaves_fxleaves_entrypoint_4_temp_v0 *)temp_v0)->unk18) = 0;
    (((Objleaves_fxleaves_entrypoint_4_temp_v0 *)temp_v0)->unk8) = 0.0f;
    (((Objleaves_fxleaves_entrypoint_4_temp_v0 *)temp_v0)->unk4) = 0.0f;
    (((Objleaves_fxleaves_entrypoint_4_temp_v0 *)temp_v0)->unk0) = 0.0f;
    (((Objleaves_fxleaves_entrypoint_4_temp_v0 *)temp_v0)->unk14) = 0.0f;
    (((Objleaves_fxleaves_entrypoint_4_temp_v0 *)temp_v0)->unk10) = 0.0f;
    (((Objleaves_fxleaves_entrypoint_4_temp_v0 *)temp_v0)->unkC) = 0.0f;
    sp1C = temp_v0;
    (((Objleaves_fxleaves_entrypoint_4_sp1C *)sp1C)->unk1C) = vector_new(0x38, arg0);
    (((Objleaves_fxleaves_entrypoint_4_sp1C *)sp1C)->unk20) = (s16) arg0;
    (((Objleaves_fxleaves_entrypoint_4_sp1C *)sp1C)->unk22) = 0;
    (((Objleaves_fxleaves_entrypoint_4_sp1C *)sp1C)->unk24) = 0x9ED;
    (((Objleaves_fxleaves_entrypoint_4_sp1C *)sp1C)->unk28) = 0x9EE;
    (((Objleaves_fxleaves_entrypoint_4_sp1C *)sp1C)->unk2C) = 0x9EF;
    (((Objleaves_fxleaves_entrypoint_4_sp1C *)sp1C)->unk30) = 0x9F0;
    (((Objleaves_fxleaves_entrypoint_4_sp1C *)sp1C)->unk34) = 0;
    (((Objleaves_fxleaves_entrypoint_4_sp1C *)sp1C)->unk38) = 0.1f;
    return sp1C;
}

void fxleaves_entrypoint_5(BtIntPtr arg0)
{
    func_80800288_fxleaves(arg0,1);
}

void fxleaves_entrypoint_6(BtIntPtr arg0)
{
    func_80800288_fxleaves(arg0,0x2);
}

void fxleaves_entrypoint_7(void *arg0) {
    void func_8008FE68(f32 *);
    s32 func_800A5490(void);
    f32 func_800D8FF8(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    s32 func_800F1574(f32 *, f32);
    void * vector_at(void *vec, s32 index);
    void vector_clear(void *vec);
    void vector_erase(void *vec, u32 index);
    s32 vector_size(void *vec);
    f32 player_pos[3];
    f32 delta = func_800D8FF8();
    int i;
    f32 *leaf;

    func_8008FE68(player_pos);
    func_800EFB24((s8 *)arg0 + 0xC, player_pos, arg0);
    func_800EE7F8(arg0, player_pos);
    if (func_800A5490()) {
        vector_clear(((Objleaves_arg0 *)arg0)->unk1C);
    }
    for (i = 0; i < vector_size(((Objleaves_arg0 *)arg0)->unk1C); i++) {
        leaf = vector_at(((Objleaves_arg0 *)arg0)->unk1C, i);
        leaf[1] += leaf[4] * delta;
        leaf[2] += leaf[5] * delta;
        leaf[3] += leaf[6] * delta;
        leaf[4] += func_800DC178(-400.0f, 400.0f) * delta;
        leaf[6] += func_800DC178(-400.0f, 400.0f) * delta;
        leaf[7] += leaf[10] * delta;
        leaf[8] += leaf[11] * delta;
        leaf[9] += leaf[12] * delta;
        leaf[10] += func_800DC178(-300.0f, 300.0f) * delta;
        leaf[11] += func_800DC178(-300.0f, 300.0f) * delta;
        leaf[12] += func_800DC178(-300.0f, 300.0f) * delta;
        if (leaf[2] < player_pos[1] - 500.0f && !*((u8 *)leaf + 0x34)) {
            vector_erase(((Objleaves_arg0 *)arg0)->unk1C, i);
            i--;
        }
    }
    (((Objleaves_arg0 *)arg0)->unk18)++;
    if (((Objleaves_arg0 *)arg0)->unk18 < vector_size(((Objleaves_arg0 *)arg0)->unk1C)) {
        leaf = vector_at(((Objleaves_arg0 *)arg0)->unk1C, ((Objleaves_arg0 *)arg0)->unk18);
        if (1320.0f < func_800EEAD4(leaf + 1, player_pos)) {
            vector_erase(((Objleaves_arg0 *)arg0)->unk1C, ((Objleaves_arg0 *)arg0)->unk18);
        }
    } else {
        ((Objleaves_arg0 *)arg0)->unk18 = 0;
    }
    if (func_800F1574(&((Objleaves_arg0 *)arg0)->unk38, delta)) {
        if (*((u8 *)arg0 + 0x22) == 1 && !func_800A5490()) {
            func_80800000_fxleaves(arg0);
        }
        ((Objleaves_arg0 *)arg0)->unk38 = 0.1f;
    }
}
