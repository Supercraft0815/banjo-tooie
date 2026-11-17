#include "common.h"
struct Vector;
struct Vector *vector_new(u32 element_size, u32 count);
void *vector_push_back(struct Vector **vec_ptr);
void *vector_begin(struct Vector *vec);
void *vector_end(struct Vector *vec);
void vector_clear(struct Vector *vec);
void vector_free(struct Vector *vec);

extern struct Vector *D_80127EF4;

void sufade_entrypoint_0(s32 arg0, s32 *arg1) {
    u8 *temp_v0;

    if (D_80127EF4 == 0) {
        struct Vector *volatile *handle = &D_80127EF4;
        *handle = vector_new(4, 1);
    }
    temp_v0 = vector_push_back(&D_80127EF4);
    temp_v0[0] = arg1[0];
    temp_v0[1] = arg1[1];
    temp_v0[2] = arg1[2];
    temp_v0[3] = arg0;
}    typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 unk3; } Objfade_sufade_entrypoint_1_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */

void sufade_entrypoint_1(BtIntPtr arg0) {
    void func_800B99CC(Gfx **arg0, s32 arg1, s32 *arg2);
    extern s32 B_80800160_sufade;
    u8 *temp_v0;
    u8 *var_s0;

    var_s0 = vector_begin(D_80127EF4);
    temp_v0 = vector_end(D_80127EF4);
    if (var_s0 < temp_v0) {
        do {
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (0))) = (s32) (((Objfade_sufade_entrypoint_1_var_s0 *)var_s0)->unk0);
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (4))) = (s32) (((Objfade_sufade_entrypoint_1_var_s0 *)var_s0)->unk1);
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (8))) = (s32) (((Objfade_sufade_entrypoint_1_var_s0 *)var_s0)->unk2);
            func_800B99CC(arg0, (((Objfade_sufade_entrypoint_1_var_s0 *)var_s0)->unk3), &B_80800160_sufade);
            var_s0 += 4;
        } while (var_s0 < temp_v0);
    }
    vector_clear(D_80127EF4);
}

void sufade_entrypoint_2(void) {
    if (D_80127EF4 != 0) {
        vector_free(D_80127EF4);
        D_80127EF4 = 0;
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 B_80800160_sufade BT_DATA(16, bss_su_fade, 0x0);
#endif
