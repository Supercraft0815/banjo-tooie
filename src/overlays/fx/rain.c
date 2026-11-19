#include "common.h"
#include "core2/weather_effects.h"
#ifdef BT_NATIVE
#include "vector.h"
#endif
struct RainEmitter {
    u8 sound;
    f32 position[3];
    f32 displacement[3];
    u8 cursor;
    struct Vector *particles;
    s32 capacity;
    s32 active;
    f32 timer;
    u8 phase;
    f32 elapsed;
    f32 periods[5];
};
#ifdef BT_ILP32
_Static_assert(sizeof(RainEmitter) == 0x4C, "rain emitter layout");
#endif


void func_80800000_fxrain(BT_NATIVE_ONLY(RainEmitter *effect) BT_IDO_ONLY(BtIntPtr arg0)) {
    f32 func_800DC178(f32 arg0, f32 arg1);
    void func_800E3958(f32 *);
    void func_800E3980(f32 *arg0);
    void func_800E3A58(f32 *arg0);
    s32 func_800E3F8C(f32 arg0, f32 arg1, f32 arg2);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    f32 func_800EEFD4(f32 *arg0);
    void func_800EF04C(f32 *arg0, f32 *arg1);
    void func_800EF934(f32 dst[3], f32 src[3], f32 yaw);
    void func_800EFA4C(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
    BT_IDO_ONLY(void *vector_push_back(void **);)
    BT_IDO_ONLY(s32 vector_size(void *vec);)
    BT_NATIVE_ONLY(s32 arg0;)
    f32 sp64[3];
    f32 sp58[3];
    Vec3f angles;
    f32 distance;
    f32 random;
    f32 *sp40;
    f32 sp34[3];

    if (vector_size(BT_DATA_FIELD(effect, ((RainEmitter *)arg0))->particles) < BT_DATA_FIELD(effect, ((RainEmitter *)arg0))->capacity) {
        func_800E3980(sp64);
        func_800E3958(sp58);
        func_800E3A58(angles.f);
        sp40 = vector_push_back(&BT_DATA_FIELD(effect, ((RainEmitter *)arg0))->particles);
        distance = func_800DC178(50.0f, 2000.0f);
        random = func_800DC178(200.0f, 300.0f);
        func_800EFA4C(sp34, 0.0f, random, -distance);
        if (func_800EEFD4(BT_DATA_FIELD(effect, ((RainEmitter *)arg0))->displacement) < 25.0f) {
            random = func_800DC178(0.0f, 360.0f);
            func_800EF934(sp34, sp34, random);
        } else {
            random = func_800DC178(-70.0f, 70.0f);
            func_800EF934(sp34, sp34, random + angles.pos.y);
        }
        func_800EF04C(sp34, sp64);
        arg0 = 0; if ((distance < 1000.0f) && func_800E3F8C(sp34[0], sp34[1] - 10.0f, sp34[2])) {
            do {
                arg0++;
                sp34[1] += 100.0f;
            } while ((arg0 < 10) && func_800E3F8C(sp34[0], sp34[1] - 10.0f, sp34[2]));
        }
        func_800EE7F8(sp40, sp34);
        random = func_800DC178(-1600.0f, -1500.0f);
        func_800EFA4C(sp40 + 3, 0.0f, random, 0.0f);
    }
}

void func_808001E8_fxrain(RainEmitter *arg0, s32 arg1) {
    arg0->active = arg1;
}

/* extern */

void fxrain_entrypoint_0(RainEmitter *arg0) {
    BT_IDO_ONLY(void vector_clear(void *vec);)
    vector_clear((arg0->particles));
}    typedef struct { u8 pad0[0x18]; s8 unk18; } Objrain_fxrain_entrypoint_1_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */

/* extern */

void fxrain_entrypoint_1(RainEmitter *arg0) {
    struct ImageStruct *func_800D674C(s32);
    void* func_800DE448(f32* position, f32* arg1, f32 scale, f32* arg3, u8* arg4);
    s32 func_800DF350(void);
    void func_800DF830(s32);
    BT_IDO_ONLY(void * vector_begin(void *vec);)
    BT_IDO_ONLY(void * vector_end(void *vec);)
    u8 *sp3C;
    u8 *temp_s1;
    u8 *temp_v0;
    u8 *var_s0;

    temp_s1 = (u8 *)func_800D674C(0x9EC);
    sp3C = vector_begin((arg0->particles));
    temp_v0 = vector_end((arg0->particles));
    var_s0 = sp3C;
    if (var_s0 < temp_v0) {
        do {
            func_800DF830(2);
            func_800DE448((f32 *)var_s0, NULL, 1.0f, NULL, temp_s1);
            (((Objrain_fxrain_entrypoint_1_var_s0 *)var_s0)->unk18) = func_800DF350();
            var_s0 += 0x1C;
        } while (var_s0 < temp_v0);
    }
}

int fxrain_entrypoint_2(RainEmitter *arg0) {
    BT_IDO_ONLY(s32 vector_size(void *vec);)
    return ((arg0->active) != 1) && (vector_size((arg0->particles)) == 0);
}

int fxrain_entrypoint_3(RainEmitter *arg0) {
    s32 state;

    if ((arg0->active) != 1) {
        return 0;
    }
    state = (arg0->phase);
    switch (state) {
    case 1:
    case 2:
        return 1;
    case 3:
        return ((arg0->periods[3]) * 0.9f) > (arg0->elapsed);
    default:
        return 0;
    }
}

/* extern */

void fxrain_entrypoint_4(RainEmitter *arg0) {
    BT_IDO_ONLY(s32 func_800C2FDC();) BT_NATIVE_ONLY(s32 func_800C2FDC(u8);)
    void heap_free(void *memory);
    BT_IDO_ONLY(s32 vector_free(s32, u8 *);)
    u8 temp_a2;

    temp_a2 = (arg0->sound);
    if (temp_a2 != 0) {
        BT_IDO_ONLY(func_800C2FDC(temp_a2 & 0xFF, arg0, (u32)temp_a2);) BT_NATIVE_ONLY(func_800C2FDC(temp_a2 & 0xFF);)
        (arg0->sound) = 0;
    }
    BT_NATIVE_ONLY(vector_free(arg0->particles);) BT_IDO_ONLY(vector_free(arg0->particles, arg0);)
    heap_free(arg0);
}

/* extern */

RainEmitter *fxrain_entrypoint_5(s32 arg0) {
    void func_800EFD24(f32 vec[3]);
    void *heap_alloc(s32);
    BT_IDO_ONLY(void * vector_new(u32 element_size, u32 count);)
    RainEmitter *temp_v0;

    temp_v0 = heap_alloc(sizeof(RainEmitter));
    func_800EFD24(temp_v0->position);
    func_800EFD24(temp_v0->displacement);
    (temp_v0->sound) = 0;
    (temp_v0->cursor) = 0;
    (temp_v0->phase) = 0;
    (temp_v0->particles) = vector_new(0x1C, arg0);
    (temp_v0->capacity) = arg0;
    (temp_v0->active) = 0;
    (temp_v0->timer) = 0.1f;
    return temp_v0;
}

void fxrain_entrypoint_6(RainEmitter *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    arg0->phase = 1;
    arg0->elapsed = 0.0f;
    arg0->periods[0] = 0.1f;
    arg0->periods[1] = arg1;
    arg0->periods[2] = arg2;
    arg0->periods[3] = arg3;
    arg0->periods[4] = arg4;
}

void fxrain_entrypoint_7(RainEmitter *arg0)
{
    func_808001E8_fxrain(arg0,1);
}

/* extern */

void fxrain_entrypoint_8(RainEmitter *arg0) {
    void func_800C3A40(u8 arg0, f32 arg1, f32 arg2, f32 arg3);
    u8 temp_a0;

    func_808001E8_fxrain(arg0, 2);
    temp_a0 = arg0->sound;
    if (temp_a0 != 0) {
        func_800C3A40(temp_a0, 0.0f, 0.0f, 3.0f);
        arg0->sound = 0U;
    }
}

void fxrain_entrypoint_9(RainEmitter *arg0) {

    typedef struct {
        f32 position[3];
        f32 velocity[3];
        u8 persistent;
    } RainParticle;
    s32 func_800A5490(void);
    u8 func_800C2E04(void);
    BT_IDO_ONLY(s32 func_800C2FDC();) BT_NATIVE_ONLY(s32 func_800C2FDC(u8);)
    void func_800C301C(u8, s32);
    void func_800C316C(u8, s32, s32, f32);
    void func_800C330C(u8, s32);
    void func_800C3418(u8, s32);
    void func_800C37E0(u8, f32, f32, f32);
    void func_800C3A40(u8 arg0, f32 arg1, f32 arg2, f32 arg3);
    void func_800C3BDC(u8);
    f32 func_800D8FF8(void);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    s32 func_800F1574(f32 *, f32);
    BT_IDO_ONLY(void * vector_at(void *vec, s32 index);)
    BT_IDO_ONLY(void vector_clear(void *vec);)
    BT_IDO_ONLY(void vector_erase(void *vec, u32 index);)
    BT_IDO_ONLY(s32 vector_size(void *vec);)
    f32 position[3];
    f32 delta;

    delta = func_800D8FF8();
    func_800E3980(position);
    func_800EFB24(arg0->displacement, position, arg0->position);
    func_800EE7F8(arg0->position, position);
    if (func_800A5490()) {
        vector_clear(arg0->particles);
    }
    if (vector_size(arg0->particles) > 0) {
        if (arg0->sound == 0) {
            arg0->sound = func_800C2E04();
            func_800C330C(arg0->sound, 3);
            func_800C301C(arg0->sound, 0x465);
            func_800C37E0(arg0->sound, 0.95f, 1.05f, 0.01f);
            func_800C3A40(arg0->sound, 3.0f, 12960000.0f, 0.0f);
            func_800C3418(arg0->sound, 2);
            func_800C316C(arg0->sound, 5000, 6000, 5.0f);
            func_800C3BDC(arg0->sound);
        }
    } else if (arg0->sound != 0) {
        func_800C2FDC(arg0->sound);
        arg0->sound = 0;
    }
    {
        s32 i;
        RainParticle *particle;
        for (i = 0; i < vector_size(arg0->particles); i++) {
            particle = vector_at(arg0->particles, i);
            particle->position[0] += particle->velocity[0] * delta;
            particle->position[1] += particle->velocity[1] * delta;
            particle->position[2] += particle->velocity[2] * delta;
            if (particle->position[1] < position[1] - 500.0f && particle->persistent == 0) {
                vector_erase(arg0->particles, i);
                i--;
            }
        }
    }
    arg0->cursor++;
    if (arg0->cursor < vector_size(arg0->particles)) {
        f32 distance;
        distance = 2200.0f;
        if (func_800EEB40(vector_at(arg0->particles, arg0->cursor), position) >
            distance * distance) {
            vector_erase(arg0->particles, arg0->cursor);
        }
    } else {
        arg0->cursor = 0;
    }
    if (arg0->phase != 0) {
        arg0->elapsed += delta;
        if (arg0->elapsed >= arg0->periods[arg0->phase]) {
            arg0->phase++;
            arg0->elapsed = 0.0f;
            if (arg0->phase >= 5) {
                arg0->phase = 1;
            }
        }
        if (arg0->phase == 1) {
            arg0->periods[0] = (1.0f - arg0->elapsed / arg0->periods[1]) * 0.1f;
        } else if (arg0->phase == 2) {
            arg0->periods[0] = 0.01f;
        } else if (arg0->phase == 3) {
            arg0->periods[0] = arg0->elapsed / arg0->periods[3] * 0.1f;
        } else {
            arg0->periods[0] = 0.01f;
        }
        if (arg0->periods[0] <= 0.01f) {
            arg0->periods[0] = 0.01f;
        }
    }
    if (func_800F1574(&arg0->timer, delta)) {
        if (arg0->active == 1 && !func_800A5490() && arg0->phase != 4) {
            func_80800000_fxrain(arg0);
        }
        if (arg0->phase != 0) {
            arg0->timer = arg0->periods[0];
        } else {
            arg0->timer = 0.01f;
        }
    }
}
