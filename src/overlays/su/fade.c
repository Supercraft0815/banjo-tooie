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
}

void sufade_entrypoint_1(s32 arg0) {
    s32 func_800B99CC(s32, u8, s32 *);
    extern s32 B_80800160_sufade;
    u8 *temp_v0;
    u8 *var_s0;

    var_s0 = vector_begin(D_80127EF4);
    temp_v0 = vector_end(D_80127EF4);
    if (var_s0 < temp_v0) {
        do {
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (0))) = (s32) (*(u8 *)((s8 *)(var_s0) + (0)));
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (4))) = (s32) (*(u8 *)((s8 *)(var_s0) + (1)));
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (8))) = (s32) (*(u8 *)((s8 *)(var_s0) + (2)));
            func_800B99CC(arg0, (*(u8 *)((s8 *)(var_s0) + (3))), &B_80800160_sufade);
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
