#include "common.h"
#include "core2/weather_effects.h"
#ifdef BT_NATIVE
#include "vector.h"
#endif
struct LeafEmitter {
    f32 position[3], displacement[3];
    s32 cursor;
    struct Vector *particles;
    s16 capacity;
    u8 mode;
    s32 models[4];
    u8 model_index;
    f32 timer;
};
#ifdef BT_ILP32
_Static_assert(sizeof(LeafEmitter) == 0x3C, "leaf emitter layout");
#endif


void func_80800000_fxleaves(LeafEmitter *arg0) {
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
    BT_IDO_ONLY(void *vector_push_back(struct Vector **);)
    BT_IDO_ONLY(s32 vector_size(void *vec);)
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 distance;
    f32 x;
    f32 *sp50;
    f32 sp44[3];
    f32 y;
    s32 i;

    if (vector_size(arg0->particles) < arg0->capacity) {
        func_8008FE68(sp74);
        func_800E3958(sp68);
        func_800E3A58(sp5C);
        sp50 = vector_push_back(&arg0->particles);
        distance = func_800DC178(50.0f, 1200.0f);
        func_800EFA4C(sp44, 0.0f, func_800DC178(200.0f, 500.0f), -distance);
        if (func_800EEFD4(arg0->displacement) < 25.0f) {
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
        if (++arg0->model_index >= 4) {
            arg0->model_index = 0;
        }
        *(s32 *)sp50 = arg0->models[arg0->model_index];
    }
}

void func_80800288_fxleaves(LeafEmitter *arg0, s32 arg1) {
    arg0->mode = arg1;
}

/* extern */

void fxleaves_entrypoint_0(LeafEmitter *arg0) {
    BT_IDO_ONLY(void vector_clear(void *vec);)
    vector_clear((arg0->particles));
}

void fxleaves_entrypoint_1(LeafEmitter *arg0) {
    struct ImageStruct *func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, u8 *);
    s32 func_800DF350(void);
    void func_800DF830(s32);
    BT_IDO_ONLY(void * vector_begin(void *vec);)
    BT_IDO_ONLY(void * vector_end(void *vec);)
    u8 *sp34;
    u8 *temp_v0;
    u8 *var_s0;

    sp34 = vector_begin(arg0->particles);
    temp_v0 = vector_end(arg0->particles);
    var_s0 = sp34;
    if (var_s0 < temp_v0) {
        do {
            func_800DF830(2);
            func_800DE448((f32 *)(var_s0 + 4), (f32 *)(var_s0 + 0x1C), 1.0f, NULL, (u8 *)func_800D674C(*(s32 *)var_s0));
            *(s8 *)(var_s0 + 0x34) = func_800DF350();
            var_s0 += 0x38;
        } while (var_s0 < temp_v0);
    }
}

/* extern */

int fxleaves_entrypoint_2(LeafEmitter *arg0) {
    BT_IDO_ONLY(s32 vector_size(void *vec);)
    return arg0->mode != 1 &&
        vector_size(arg0->particles) == 0;
}

/* extern */

void fxleaves_entrypoint_3(LeafEmitter *arg0) {
    void heap_free(void *memory);
    BT_IDO_ONLY(void vector_free(void *vec);)
    vector_free((arg0->particles));
    heap_free(arg0);
}

/* extern */

LeafEmitter *fxleaves_entrypoint_4(s32 arg0) {
    void *heap_alloc(s32);
    BT_IDO_ONLY(void * vector_new(u32 element_size, u32 count);)
    LeafEmitter *sp1C;
    LeafEmitter *temp_v0;

    temp_v0 = heap_alloc(sizeof(LeafEmitter));
    (temp_v0->cursor) = 0;
    (temp_v0->position[2]) = 0.0f;
    (temp_v0->position[1]) = 0.0f;
    (temp_v0->position[0]) = 0.0f;
    (temp_v0->displacement[2]) = 0.0f;
    (temp_v0->displacement[1]) = 0.0f;
    (temp_v0->displacement[0]) = 0.0f;
    sp1C = temp_v0;
    (sp1C->particles) = vector_new(0x38, arg0);
    (sp1C->capacity) = (s16) arg0;
    (sp1C->mode) = 0;
    (sp1C->models[0]) = 0x9ED;
    (sp1C->models[1]) = 0x9EE;
    (sp1C->models[2]) = 0x9EF;
    (sp1C->models[3]) = 0x9F0;
    (sp1C->model_index) = 0;
    (sp1C->timer) = 0.1f;
    return sp1C;
}

void fxleaves_entrypoint_5(LeafEmitter *arg0)
{
    func_80800288_fxleaves(arg0,1);
}

void fxleaves_entrypoint_6(LeafEmitter *arg0)
{
    func_80800288_fxleaves(arg0,0x2);
}

void fxleaves_entrypoint_7(LeafEmitter *arg0) {
    void func_8008FE68(f32 *);
    s32 func_800A5490(void);
    f32 func_800D8FF8(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    s32 func_800F1574(f32 *, f32);
    BT_IDO_ONLY(void * vector_at(void *vec, s32 index);)
    BT_IDO_ONLY(void vector_clear(void *vec);)
    BT_IDO_ONLY(void vector_erase(void *vec, u32 index);)
    BT_IDO_ONLY(s32 vector_size(void *vec);)
    f32 player_pos[3];
    f32 delta = func_800D8FF8();
    int i;
    f32 *leaf;

    func_8008FE68(player_pos);
    func_800EFB24(arg0->displacement, player_pos, arg0->position);
    func_800EE7F8(arg0->position, player_pos);
    if (func_800A5490()) {
        vector_clear(arg0->particles);
    }
    for (i = 0; i < vector_size(arg0->particles); i++) {
        leaf = vector_at(arg0->particles, i);
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
            vector_erase(arg0->particles, i);
            i--;
        }
    }
    (arg0->cursor)++;
    if (arg0->cursor < vector_size(arg0->particles)) {
        leaf = vector_at(arg0->particles, arg0->cursor);
        if (1320.0f < func_800EEAD4(leaf + 1, player_pos)) {
            vector_erase(arg0->particles, arg0->cursor);
        }
    } else {
        arg0->cursor = 0;
    }
    if (func_800F1574(&arg0->timer, delta)) {
        if (arg0->mode == 1 && !func_800A5490()) {
            func_80800000_fxleaves(arg0);
        }
        arg0->timer = 0.1f;
    }
}
