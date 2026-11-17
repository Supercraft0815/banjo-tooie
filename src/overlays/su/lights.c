#include "common.h"

struct Vector;
struct Vector *vector_new(u32 element_size, u32 count);
void *vector_begin(struct Vector *vec);
void *vector_end(struct Vector *vec);
void *vector_push_back(struct Vector **vec_ptr);
void vector_free(struct Vector *vec);     
u8 *func_80800000_sulights(s32 arg0, s32 arg1) {
    extern struct Vector *D_80127EF0;
    u8 *begin;
    u8 *end;
    u8 *p;

    if (D_80127EF0 == NULL) {
        D_80127EF0 = vector_new(0x3C, 1);
    }
    end = vector_end(D_80127EF0);
    begin = vector_begin(D_80127EF0);
    p = begin;
    while (p < end && *p != 0) {
        p += 0x3C;
    }
    if (p == end) {
        p = vector_push_back(&D_80127EF0);
    }
    p[0] = arg0;
    p[1] = arg1;
    *(f32 *)(p + 0x34) = 0.0f;
    return p;
}

void func_808000D0_sulights(s8 *arg0) {
    arg0[0] = 0;
}

void func_808000D8_sulights(u8 *arg0) {
    void func_800C8E84(s32, u32 *);
    f32 fraction;
    u32 rgb[3];
    s32 i;

    fraction = *(f32 *)(arg0 + 0x34) / *(f32 *)(arg0 + 0x38);
    for (i = 0; i < 3; i++) {
        rgb[i] = (s32)((f32)((s32 *)arg0)[i + 1] + (f32)((s32 *)arg0)[i + 4] * fraction);
    }
    func_800C8E84(arg0[1], rgb);
}

void func_80800194_sulights(u8 *arg0) {
    void func_800C8D4C(s32, f32 *);
    f32 fraction;
    f32 position[2];
    s32 i;

    fraction = *(f32 *)(arg0 + 0x34) / *(f32 *)(arg0 + 0x38);
    for (i = 0; i < 2; i++) {
        position[i] = ((f32 *)arg0)[i + 7] + ((f32 *)arg0)[i + 10] * fraction;
    }
    func_800C8D4C(arg0[1], position);
}

/* extern */

void func_8080021C_sulights(u8 *arg0) {
    void func_800C8900(s32, u8 *);
    void func_800C8E84(s32, u32 *);
    f32 func_800DC0C0(void);
    s32 sp4C;
    s32 sp40[3];
    f32 sp3C;
    s32 *var_v0;
    s32 var_a0;
    u8 *var_v1;

    if (func_800DC0C0() > 0.5f) {
        sp3C = 1.0f;
    } else {
        sp3C = -1.0f;
    }
    func_800C8900(arg0[1], (u8 *)sp40);
    var_v0 = sp40;
    var_v1 = arg0;
    do {
        *var_v0 += sp3C * (*(f32 *)(arg0 + 0x38) * (f32)*(s32 *)(var_v1 + 0x10) * *(f32 *)(arg0 + 0x34));
        if (*var_v0 > *(s32 *)(var_v1 + 4) + *(s32 *)(var_v1 + 0x10)) {
            *var_v0 = *(s32 *)(var_v1 + 4) + *(s32 *)(var_v1 + 0x10);
        }
        if (*var_v0 < *(s32 *)(var_v1 + 4) - *(s32 *)(var_v1 + 0x10)) {
            *var_v0 = *(s32 *)(var_v1 + 4) - *(s32 *)(var_v1 + 0x10);
        }
        var_v0++;
        var_v1 += 4;
    } while (var_v0 != BT_NATIVE_ONLY(sp40 + 3) BT_IDO_ONLY(&sp4C)); // IDO keeps sp4C right after sp40[3]
    func_800C8E84(arg0[1], sp40);
    *(f32 *)(arg0 + 0x34) = 0.0f;
}

void func_80800340_sulights(u8 *arg0) {
    s32 i;
    s32 *p;
    s32 value;
    i = 0;
    p = (s32 *)arg0;
    *(f32 *)(arg0 + 0x34) = 0.0f;
    do {
        value = p[4];
        i++;
        p++;
        p[0] += value;
        p[3] = value * -1;
    } while (i != 3);
}

void func_8080038C_sulights(u8 *arg0) { s32 i; f32 *p; f32 value; i = 0; p = (f32 *)arg0; *(f32 *)(arg0 + 0x34) = 0.0f; do { value = p[10]; i++; p++; p[6] += value; p[9] = value * -1.0f; } while (i != 2); }    typedef struct { u8 pad0[0x38]; f32 unk38; } Objlights_sulights_entrypoint_0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void sulights_entrypoint_0(s32 arg0, s32 *arg1, s32 *arg2, f32 arg3) {
    void func_800C8E84(s32, u32 *);
    void func_800EE830(s32 dst[3], s32 src[3]);
    u8 *func_80800000_sulights(s32, s32);
    s32 i;
    u8 *temp_v0;

    temp_v0 = func_80800000_sulights(1, arg0);
    if (arg3 < 0.001f) {
        (((Objlights_sulights_entrypoint_0_temp_v0 *)temp_v0)->unk38) = 0.001f;
    } else {
        (((Objlights_sulights_entrypoint_0_temp_v0 *)temp_v0)->unk38) = arg3;
    }
    func_800EE830((s32 *)(temp_v0 + 4), arg1);
    for (i = 0; i < 3; i++) {
        ((s32 *)temp_v0)[i + 4] = arg2[i] - arg1[i];
    }
    func_800C8E84(arg0, arg1);
}

/* extern */

void sulights_entrypoint_1(s32 arg0, s32 *arg1, f32 arg2) {
    void func_800C8900(s32, u8 *);
    void sulights_entrypoint_0(s32, s32 *, s32 *, f32);
    s32 sp1C[3];

    func_800C8900(arg0, (u8 *) sp1C);
    sulights_entrypoint_0(arg0, sp1C, arg1, arg2);
}

/* extern */

void sulights_entrypoint_2(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void func_800C8D4C(s32, f32 *);
    u8 *func_80800000_sulights(s32, s32);
    s32 i;
    u8 *p;
    p = func_80800000_sulights(2, arg0);
    if (arg3 < 0.001f) {
        *(f32 *)(p + 0x38) = 0.001f;
    } else {
        *(f32 *)(p + 0x38) = arg3;
    }
    for (i = 0; i < 2; i++) {
        ((f32 *)p)[i + 7] = arg1[i];
        ((f32 *)p)[i + 10] = arg2[i] - arg1[i];
    }
    func_800C8D4C(arg0, arg1);
}

/* extern */

void sulights_entrypoint_3(s32 arg0, f32 *arg1, f32 arg2) {
    void func_800C883C(s32 arg0, void *arg1);
    f32 sp18[2];

    func_800C883C(arg0, &sp18);
    sulights_entrypoint_2(arg0, sp18, arg1, arg2);
}                        typedef struct { u8 pad0[0x4]; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; s32 unk18; u8 pad1C[0x1C]; f32 unk38; } Objlights_sulights_entrypoint_4_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */ typedef struct { s32 unk0; s32 unk4; s32 unk8; } Objlights_arg2; /* offsets.py genstruct: fields from raw offsets on arg2; rename once understood */ typedef struct { s32 unk0; s32 unk4; s32 unk8; } Objlights_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

/* extern */

void sulights_entrypoint_4(s32 arg0, void *arg1, void *arg2, f32 arg3) {
    void func_800C8E84(s32, u32 *);
    u8 *func_80800000_sulights(s32, s32);
    f32 var_f0;
    void *temp_v1;

    temp_v1 = func_80800000_sulights(3, arg0);
    if (arg3 < 0.001f) {
        var_f0 = 0.001f;
    } else {
        var_f0 = arg3;
    }
    (((Objlights_sulights_entrypoint_4_temp_v1 *)temp_v1)->unk38) = (f32) (4.0f / var_f0);
    (((Objlights_sulights_entrypoint_4_temp_v1 *)temp_v1)->unk4) = (s32) (((Objlights_arg1 *)arg1)->unk0);
    (((Objlights_sulights_entrypoint_4_temp_v1 *)temp_v1)->unk8) = (s32) (((Objlights_arg1 *)arg1)->unk4);
    (((Objlights_sulights_entrypoint_4_temp_v1 *)temp_v1)->unkC) = (s32) (((Objlights_arg1 *)arg1)->unk8);
    (((Objlights_sulights_entrypoint_4_temp_v1 *)temp_v1)->unk10) = (s32) (((Objlights_arg2 *)arg2)->unk0);
    (((Objlights_sulights_entrypoint_4_temp_v1 *)temp_v1)->unk14) = (s32) (((Objlights_arg2 *)arg2)->unk4);
    (((Objlights_sulights_entrypoint_4_temp_v1 *)temp_v1)->unk18) = (s32) (((Objlights_arg2 *)arg2)->unk8);
    func_800C8E84(arg0, arg1);
}    typedef struct { u8 pad0[0x4]; s32 unk4; s32 unk8; s32 unkC; u8 pad10[0x28]; f32 unk38; } Objlights_sulights_entrypoint_5_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void sulights_entrypoint_5(s32 arg0, s32 *arg1, s32 *arg2, f32 arg3) {
    void func_800C8E84(s32, u32 *);
    u8 *func_80800000_sulights(s32, s32);
    s32 i;
    u8 *temp_v0;

    temp_v0 = func_80800000_sulights(4, arg0);
    if (arg3 < 0.001f) {
        (((Objlights_sulights_entrypoint_5_temp_v0 *)temp_v0)->unk38) = 0.001f;
    } else {
        (((Objlights_sulights_entrypoint_5_temp_v0 *)temp_v0)->unk38) = (f32) (arg3 * 0.5f);
    }
    (((Objlights_sulights_entrypoint_5_temp_v0 *)temp_v0)->unk4) = (s32) (((Objlights_arg1 *)arg1)->unk0);
    (((Objlights_sulights_entrypoint_5_temp_v0 *)temp_v0)->unk8) = (s32) (((Objlights_arg1 *)arg1)->unk4);
    (((Objlights_sulights_entrypoint_5_temp_v0 *)temp_v0)->unkC) = (s32) (((Objlights_arg1 *)arg1)->unk8);
    for (i = 0; i < 3; i++) {
        ((s32 *)temp_v0)[i + 4] = arg2[i] - arg1[i];
    }
    func_800C8E84(arg0, arg1);
}

/* extern */

void sulights_entrypoint_6(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void func_800C8D4C(s32, f32 *);
    u8 *func_80800000_sulights(s32, s32);
    s32 i;
    u8 *p;
    p = func_80800000_sulights(5, arg0);
    if (arg3 < 0.001f) {
        *(f32 *)(p + 0x38) = 0.001f;
    } else {
        *(f32 *)(p + 0x38) = arg3 * 0.5f;
    }
    for (i = 0; i < 2; i++) {
        ((f32 *)p)[i + 7] = arg1[i];
        ((f32 *)p)[i + 10] = arg2[i] - arg1[i];
    }
    func_800C8D4C(arg0, arg1);
}

void sulights_entrypoint_7(s32 arg0) {
    extern struct Vector *D_80127EF0;
    BtUIntPtr end;
    BtUIntPtr begin;
    BtUIntPtr ptr;

    if (D_80127EF0 != 0) {
        end = vector_end(D_80127EF0);
        begin = vector_begin(D_80127EF0);
        ptr = begin;
        if (begin < end) {
            do {
                if (*(u8 *)ptr != 0 && arg0 == *(u8 *)(ptr + 1)) {
                    func_808000D0_sulights((s8 *)ptr);
                }
                ptr += 0x3C;
            } while (ptr < end);
        }
    }
}

void sulights_entrypoint_8(void) {
    extern struct Vector *D_80127EF0;
    if (D_80127EF0 != 0) {
        vector_free(D_80127EF0);
        D_80127EF0 = 0;
    }
}    typedef struct { u8 unk0; u8 pad1[0x33]; f32 unk34; f32 unk38; } Objlights_sulights_entrypoint_9_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */
typedef struct { s32 (*update)(u32); s32 (*finish)(u32); } LightCallbacks;
void sulights_entrypoint_9(void) {
    f32 func_800D8FF8();
    extern struct Vector *D_80127EF0;




    extern LightCallbacks D_80800A00_sulights[];
    s32 (*temp_v0_2)(u32);
    f32 temp_f0;
    f32 temp_f20;
    BtUIntPtr temp_s2;
    BtUIntPtr temp_v0;
    BtUIntPtr var_s0;

    temp_f20 = func_800D8FF8();
    temp_s2 = vector_end(D_80127EF0);
    temp_v0 = vector_begin(D_80127EF0);
    var_s0 = temp_v0;
    if (temp_v0 < temp_s2) {
        do {
            if ((((Objlights_sulights_entrypoint_9_var_s0 *)var_s0)->unk0) != 0) {
                temp_f0 = (((Objlights_sulights_entrypoint_9_var_s0 *)var_s0)->unk38);
                (((Objlights_sulights_entrypoint_9_var_s0 *)var_s0)->unk34) = (f32) ((((Objlights_sulights_entrypoint_9_var_s0 *)var_s0)->unk34) + temp_f20);
                if (temp_f0 < (((Objlights_sulights_entrypoint_9_var_s0 *)var_s0)->unk34)) {
                    (((Objlights_sulights_entrypoint_9_var_s0 *)var_s0)->unk34) = temp_f0;
                }
                D_80800A00_sulights[*(u8 *)var_s0 - 1].update(var_s0);
                if ((((Objlights_sulights_entrypoint_9_var_s0 *)var_s0)->unk38) <= (((Objlights_sulights_entrypoint_9_var_s0 *)var_s0)->unk34)) {
                    temp_v0_2 = D_80800A00_sulights[*(u8 *)var_s0 - 1].finish;
                    if (temp_v0_2 != NULL) {
                        temp_v0_2(var_s0);
                    }
                }
            }
            var_s0 += 0x3C;
        } while (var_s0 < temp_s2);
    }
}
/* data_to_c.py: from asm/data/overlays/su/lights.data.s */
LightCallbacks D_80800A00_sulights [6] BT_DATA(4, overlays_su_lights, 0x0) = { { (long (*)(unsigned long))func_808000D8_sulights, (long (*)(unsigned long))func_808000D0_sulights }, { (long (*)(unsigned long))func_80800194_sulights, (long (*)(unsigned long))func_808000D0_sulights }, { (long (*)(unsigned long))func_8080021C_sulights, 0 }, { (long (*)(unsigned long))func_808000D8_sulights, (long (*)(unsigned long))func_80800340_sulights }, { (long (*)(unsigned long))func_80800194_sulights, (long (*)(unsigned long))func_8080038C_sulights }, { 0, 0 } };
