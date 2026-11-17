#include "common.h"

s32 func_80800000_suexpressmorph(s32 arg0) {
    extern s16 D_80801324_suexpressmorph;
    extern s32 D_8080132C_suexpressmorph;
    s32 *var_v0;
    s32 var_v1;

    var_v0 = &D_8080132C_suexpressmorph;
    var_v1 = 1;
    if (arg0 == D_80801324_suexpressmorph) {
        return 0;
    }
    for (;;) {
        if (arg0 == *(s16 *)(var_v0 + 1)) return var_v1;
        if (arg0 == *(s16 *)(var_v0 + 4)) return var_v1 + 1;
        if (arg0 == *(s16 *)(var_v0 + 7)) return var_v1 + 2;
        if (arg0 == *(s16 *)(var_v0 + 10)) return var_v1 + 3;
        var_v1 += 4;
        var_v0 += 12;
        if (var_v1 == 0x11) return -1;
    }
}

s32 suexpressmorph_entrypoint_0(s16 arg0) {
    extern u8 D_80801327_suexpressmorph[][12];
    s32 i = func_80800000_suexpressmorph(arg0);
    s32 t;

    if (i == -1) {
        return 0;
    }
    t = D_80801327_suexpressmorph[i][0] * 4 + 8;
    t += D_80801327_suexpressmorph[i][0] * 4;
    return t;
}                typedef struct { u8 pad0[0x2]; s16 unk2; u8 pad4[0x4]; f32 unk8; } Objexpressmorph_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

#ifdef BT_NATIVE // defined below on the N64; the arrays before it need the complete type
struct MorphEntry {
    f32 (*data)[9];
    s16 id;
    u8 unk6;
    u8 count;
    s32 unk8;
};
#else
struct MorphEntry;
#endif

s32 func_808000EC_suexpressmorph(f32 *arg0, void *arg1) {
    f32 func_800D8FF8(void); extern struct MorphEntry D_80801320_suexpressmorph[]; BT_IDO_ONLY(f32 *var_s0; f32 *var_s2; u8 *var_v0;) BT_NATIVE_ONLY(u8 *var_v0; f32 *var_s0; f32 *var_s2;) BtIntPtr var_s3; s32 var_s4; s32 temp_v1;  var_s0 = &((Objexpressmorph_arg1 *)arg1)->unk8; var_s3 = 0; var_s4 = 0; var_v0 = ((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2]; temp_v1 = var_v0[7]; var_s2 = (f32 *)(temp_v1 * 4 + (u8 *)arg1 + 8); if ((s32)temp_v1 > 0) { do { if (*var_s2 <= 0) { *(f32 *)((u8 *)arg0 + var_s3) = *(f32 *)((BtIntPtr)(*(f32 (**)[9])var_v0)[((u8 *)arg1)[5]] + var_s3 + 4); } else { *var_s2 -= func_800D8FF8(); } if (*(f32 *)((u8 *)arg0 + var_s3) < *var_s0) { *var_s0 += (*(f32 *)((u8 *)arg0 + var_s3) - *var_s0) * 0.2f; if (*var_s0 < 0.0f) { *var_s0 = 0.0f; } } else if (*var_s0 < *(f32 *)((u8 *)arg0 + var_s3)) { *var_s0 += (*(f32 *)((u8 *)arg0 + var_s3) - *var_s0) * 0.2f; if (*var_s0 > 1.0f) { *var_s0 = 1.0f; } } var_s4++; var_s3 += 4; var_s0++; var_s2++; var_v0 = ((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2]; } while (var_s4 < (s32)var_v0[7]); } BT_NATIVE_ONLY(return 0;) }

s32 func_808002BC_suexpressmorph(f32 *arg0, void *arg1) {
    u32 func_800D5298(void);
    u32 func_800D52A4(void);
    s32 func_800D52F4(void);
    extern struct MorphEntry D_80801320_suexpressmorph[];
    s32 pad;
    BT_IDO_ONLY(f32 *timer;) BT_NATIVE_ONLY(BtIntPtr offset;)
    s32 state;
    BT_IDO_ONLY(BtIntPtr offset;) BT_NATIVE_ONLY(f32 *timer;)
    s32 i;
    s32 selected;
    s16 *row;
    u8 count;
    f32 *values;

    selected = -1;
    timer = (f32 *)(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2][7] * 4 + (u8 *)arg1 + 8);
    if (func_800D52F4() == *(s16 *)arg1) {
        state = func_800D52A4() + 1;
        i = 0;
        if ((s32)(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2])[6] > 0) {
            row = *(s16 **)(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2]);
            do {
                if (state == *row) {
                    selected = i;
                }
                i++;
                row += 18;
            } while (i < (s32)(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2])[6]);
        }
        i = 0;
        if (func_800D5298()) {
            if ((s32)(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2])[7] > 0) {
                offset = 0;
                do {
                i++;
                if (*(f32 *)((BtIntPtr)(*(f32 (**)[9])(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2]))[selected] + offset + 4) != -1.0f) {
                    if (*timer < *(f32 *)((BtIntPtr)(*(f32 (**)[9])(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2]))[selected] + offset + 20)) {
                        *timer = *(f32 *)((BtIntPtr)(*(f32 (**)[9])(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2]))[selected] + offset + 20);
                        *(f32 *)((u8 *)arg0 + offset) = *(f32 *)((BtIntPtr)(*(f32 (**)[9])(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2]))[selected] + offset + 4);
                                }
                }
                offset += 4;
                timer++;
                } while (i < (s32)(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2])[7]);
            }
        } else {
            if ((s32)(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2])[7] > 0) {
                offset = 0;
                do {
                i++;
                if (*(f32 *)((BtIntPtr)(*(f32 (**)[9])(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2]))[selected] + offset + 4) != -1.0f) {
                    *(f32 *)((u8 *)arg0 + offset) = *(f32 *)((BtIntPtr)(*(f32 (**)[9])(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2]))[selected] + offset + 4);
                        }
                offset += 4;
                } while (i < (s32)(((u8 (*)[12])D_80801320_suexpressmorph)[((Objexpressmorph_arg1 *)arg1)->unk2])[7]);
            }
        }
    }
    BT_NATIVE_ONLY(return 0;) }

#ifndef BT_NATIVE
struct MorphEntry {
    f32 (*data)[9];
    s16 id;
    u8 unk6;
    u8 count;
    s32 unk8;
};
#endif

void suexpressmorph_entrypoint_1(u8 *arg0) {
    s32 func_808000EC_suexpressmorph(f32 *, void *);
    s32 func_808002BC_suexpressmorph(f32 *, void *);
    extern struct MorphEntry D_80801320_suexpressmorph[];
    struct MorphEntry *var_v0;
    f32 sp28[3];
    s32 var_v1;

    var_v0 = &D_80801320_suexpressmorph[*(s16 *)(arg0 + 2)];
    for (var_v1 = 0; var_v1 < (s32)var_v0->count; var_v1++) {
        sp28[var_v1] = var_v0->data[arg0[5]][var_v1 + 1];
        var_v0 = &D_80801320_suexpressmorph[*(s16 *)(arg0 + 2)];
    }
    func_808002BC_suexpressmorph(sp28, arg0);
    func_808000EC_suexpressmorph(sp28, arg0);
}

void suexpressmorph_entrypoint_2(u8 *arg0, void *arg1) {
    struct MorphFlags {
        u8 pad[0x17];
        u8 other : 7;
        u8 active : 1;
    };
    s32 pad0;
    u8 *sp38;
    BtIntPtr sp34;
    s32 pad;
    u8 *sp2C;
    u8 *morph;
    void _dbmorph_entrypoint_3(void *arg0, void *arg1, void *arg2, s32 arg3, f32 *weights);
    void _dbmorph_entrypoint_4(s16 *arg0, u8 *arg1, u8 *arg2, s32 arg3, BtIntPtr arg4);
    void * func_800AE080(s16 handle);
    u8 *func_800B2768(u8 *);
    BtIntPtr func_800B2840(BtIntPtr);
    u8 *func_80103AA0(u8 *);
    BtIntPtr func_80103CDC(u8 *, u8 *);
    extern u8 D_80801328_suexpressmorph[];

    sp38 = func_80103AA0(*(u8 **)arg1);
    if (sp38 != NULL) {
        morph = (u8 *)func_80103CDC(arg1, sp38);
        if (morph != NULL) {
            sp34 = func_800B2840((BtIntPtr)sp38);
            sp2C = func_800B2768(sp38);
            _dbmorph_entrypoint_3(sp2C, morph, sp34, arg0[6], arg0 + 8);
            if (D_80801328_suexpressmorph[*(s16 *)(arg0 + 2) * 12] & 1) {
                ((struct MorphFlags *)morph)->active = 1;
                _dbmorph_entrypoint_4(sp2C, morph, sp34, arg0[6], func_800AE080(*(s16 *)(*(u8 **)arg1 + 0x10)));
            }
        }
    }
}

/* extern */

void suexpressmorph_entrypoint_3(s16 *arg0, s16 arg1) {
    s32 func_80800000_suexpressmorph(s32);
    *arg0 = arg1;
    arg0[1] = func_80800000_suexpressmorph(*arg0);
}

void suexpressmorph_entrypoint_4(s8 *arg0, s32 arg1) {
    arg0[6] = arg1;
}    typedef struct { u8 pad0[0x8]; f32 unk8; } Objexpressmorph_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void suexpressmorph_entrypoint_5(s16 *arg0, s16 arg1) {
    extern struct MorphEntry D_80801320_suexpressmorph[];
    s32 var_a0;
    f32 *var_v0;
    f32 *var_v1;
    s32 count;

    suexpressmorph_entrypoint_3(arg0, arg1);
    ((s8 *)arg0)[5] = 0;
    ((s8 *)arg0)[6] = 1;
    var_v0 = &((Objexpressmorph_arg0 *)arg0)->unk8;
    count = D_80801320_suexpressmorph[arg0[1]].count;
    var_v1 = (f32 *)(count * 4 + (u8 *)arg0 + 8);
    var_a0 = 0;
    if ((s32)count > 0) {
        do {
            *var_v0 = 0.0f;
            *var_v1 = 0.0f;
            var_a0++;
            var_v0++;
            var_v1++;
        } while (var_a0 < (s32)D_80801320_suexpressmorph[arg0[1]].count);
    }
}
