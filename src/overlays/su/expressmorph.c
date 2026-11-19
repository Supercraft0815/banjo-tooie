#include "common.h"
#include "expressmorph_tables.h"
s32 func_80800000_suexpressmorph(s32 arg0) {

    struct MorphEntry *var_v0;
    s32 var_v1;

    var_v0 = &D_80801320_suexpressmorph[1];
    var_v1 = 1;
    if (arg0 == D_80801320_suexpressmorph[0].id) {
        return 0;
    }
    for (;;) {
        if (arg0 == var_v0[0].id) {
            return var_v1;
        }
        if (arg0 == var_v0[1].id) {
            return var_v1 + 1;
        }
        if (arg0 == var_v0[2].id) {
            return var_v1 + 2;
        }
        if (arg0 == var_v0[3].id) {
            return var_v1 + 3;
        }
        var_v1 += 4;
        var_v0 += 4;
        if (var_v1 == 0x11) {
            return -1;
        }
    }
}

s32 suexpressmorph_entrypoint_0(s16 arg0) {
    s32 i = func_80800000_suexpressmorph(arg0);
    s32 t;

    if (i == -1) {
        return 0;
    }
    t = D_80801320_suexpressmorph[i].count * 4 + 8;
    t += D_80801320_suexpressmorph[i].count * 4;
    return t;
}

typedef struct {
    u8 pad0[0x2];
    s16 unk2;
    u8 pad4[0x4];
    f32 unk8;
} Objexpressmorph_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

s32 func_808000EC_suexpressmorph(f32 *arg0, void *arg1) {
    f32 func_800D8FF8(void); extern struct MorphEntry D_80801320_suexpressmorph[]; BT_IDO_ONLY(f32 *var_s0; f32 *var_s2; u8 *var_v0;) BT_NATIVE_ONLY(u8 *var_v0; f32 *var_s0; f32 *var_s2;) BtIntPtr var_s3; s32 var_s4; s32 temp_v1;  var_s0 = &((Objexpressmorph_arg1 *)arg1)->unk8; var_s3 = 0; var_s4 = 0; var_v0 = MORPH_RECORD(((Objexpressmorph_arg1 *)arg1)->unk2); temp_v1 = MORPH_FIELD(var_v0, count); var_s2 = (f32 *)(temp_v1 * 4 + (u8 *)arg1 + 8); if ((s32)temp_v1 > 0) { do { if (*var_s2 <= 0) { *(f32 *)((u8 *)arg0 + var_s3) = MORPH_CHANNEL(var_v0, ((u8 *)arg1)[5], var_s3, weights); } else { *var_s2 -= func_800D8FF8(); } if (*(f32 *)((u8 *)arg0 + var_s3) < *var_s0) { *var_s0 += (*(f32 *)((u8 *)arg0 + var_s3) - *var_s0) * 0.2f; if (*var_s0 < 0.0f) { *var_s0 = 0.0f; } } else if (*var_s0 < *(f32 *)((u8 *)arg0 + var_s3)) { *var_s0 += (*(f32 *)((u8 *)arg0 + var_s3) - *var_s0) * 0.2f; if (*var_s0 > 1.0f) { *var_s0 = 1.0f; } } var_s4++; var_s3 += 4; var_s0++; var_s2++; var_v0 = MORPH_RECORD(((Objexpressmorph_arg1 *)arg1)->unk2); } while (var_s4 < (s32)MORPH_FIELD(var_v0, count)); } BT_NATIVE_ONLY(return 0;) }

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
    MorphFrameCursor row;
    u8 count;
    f32 *values;

    selected = -1;

    timer = (f32 *)(MORPH_FIELD(MORPH_FOR_WORK(arg1), count) * 4 + (u8 *)arg1 + 8);

    if (func_800D52F4() == *(s16 *)arg1) {
        state = func_800D52A4() + 1;
        i = 0;

        if ((s32)MORPH_FIELD(MORPH_FOR_WORK(arg1), frameCount) > 0) {
            row = MORPH_FRAMES(MORPH_FOR_WORK(arg1));
            do {
                if (state == MORPH_STATE(row)) {
                    selected = i;
                }
                i++;
                row += MORPH_FRAME_STEP;
            } while (i < (s32)MORPH_FIELD(MORPH_FOR_WORK(arg1), frameCount));
        }
        i = 0;

        if (func_800D5298()) {
            if ((s32)MORPH_FIELD(MORPH_FOR_WORK(arg1), count) > 0) {
                offset = 0;
                do {
                    i++;
                    if (MORPH_CHANNEL(MORPH_FOR_WORK(arg1), selected, offset, weights) != -1.0f) {
                        if (*timer < MORPH_CHANNEL(MORPH_FOR_WORK(arg1), selected, offset, timers)) {
                            *timer = MORPH_CHANNEL(MORPH_FOR_WORK(arg1), selected, offset, timers);
                            *(f32 *)((u8 *)arg0 + offset) = MORPH_CHANNEL(MORPH_FOR_WORK(arg1), selected, offset, weights);
                        }
                    }
                    offset += 4;
                    timer++;
                } while (i < (s32)MORPH_FIELD(MORPH_FOR_WORK(arg1), count));
            }
        } else {
            if ((s32)MORPH_FIELD(MORPH_FOR_WORK(arg1), count) > 0) {
                offset = 0;
                do {
                    i++;
                    if (MORPH_CHANNEL(MORPH_FOR_WORK(arg1), selected, offset, weights) != -1.0f) {
                    *(f32 *)((u8 *)arg0 + offset) = MORPH_CHANNEL(MORPH_FOR_WORK(arg1), selected, offset, weights);
                    }
                    offset += 4;
                } while (i < (s32)MORPH_FIELD(MORPH_FOR_WORK(arg1), count));
            }
        }
    }
    BT_NATIVE_ONLY(return 0;)
}

void suexpressmorph_entrypoint_1(u8 *arg0) {
    s32 func_808000EC_suexpressmorph(f32 *, void *);
    s32 func_808002BC_suexpressmorph(f32 *, void *);
    struct MorphEntry *var_v0;
    f32 sp28[3];
    s32 var_v1;

    var_v0 = &D_80801320_suexpressmorph[*(s16 *)(arg0 + 2)];
    for (var_v1 = 0; var_v1 < (s32)var_v0->count; var_v1++) {
        sp28[var_v1] = var_v0->frames[arg0[5]].weights[var_v1];
        var_v0 = &D_80801320_suexpressmorph[*(s16 *)(arg0 + 2)];
    }
    func_808002BC_suexpressmorph(sp28, arg0);
    func_808000EC_suexpressmorph(sp28, arg0);
}

void suexpressmorph_entrypoint_2(u8 *arg0, void *arg1) {
    struct MorphFlags {
        u8 pad[0x17];
        BT_BITFIELD_ORDER(u8 other : 7, u8 active : 1);
        BT_BITFIELD_ORDER(u8 active : 1, u8 other : 7);
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

    sp38 = func_80103AA0(*(u8 **)arg1);
    if (sp38 != NULL) {
        morph = (u8 *)func_80103CDC(arg1, sp38);
        if (morph != NULL) {
            sp34 = func_800B2840((BtIntPtr)sp38);
            sp2C = func_800B2768(sp38);
            _dbmorph_entrypoint_3(sp2C, morph, sp34, arg0[6], arg0 + 8);
            if (D_80801320_suexpressmorph[*(s16 *)(arg0 + 2)].flags & 1) {
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
}    typedef struct {
    u8 pad0[0x8];
    f32 unk8;
} Objexpressmorph_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void suexpressmorph_entrypoint_5(s16 *arg0, s16 arg1) {
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

#include "expressmorph_data.inc"
