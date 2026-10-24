#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/func_80800000_fxrain.s")

void func_808001E8_fxrain(s32 *arg0, s32 arg1) {
    arg0[10] = arg1;
}

/* extern */

void fxrain_entrypoint_0(void *arg0) {
    s32 vector_clear(s32);
    vector_clear((*(s32 *)((s8 *)(arg0) + (0x20))));
}

/* extern */

void fxrain_entrypoint_1(void *arg0) {
    s32 func_800D674C(s32);
    s32 func_800DE448(u32, s32, f32, s32, s32);
    s32 func_800DF350(void);
    void func_800DF830(s32);
    u32 vector_begin(s32);
    u32 vector_end(s32);
    u32 sp3C;
    s32 temp_s1;
    u32 temp_v0;
    u32 var_s0;

    temp_s1 = func_800D674C(0x9EC);
    sp3C = vector_begin((*(s32 *)((s8 *)(arg0) + (0x20))));
    temp_v0 = vector_end((*(s32 *)((s8 *)(arg0) + (0x20))));
    var_s0 = sp3C;
    if (var_s0 < temp_v0) {
        do {
            func_800DF830(2);
            func_800DE448(var_s0, 0, 1.0f, 0, temp_s1);
            (*(s8 *)((s8 *)(var_s0) + (0x18))) = func_800DF350();
            var_s0 += 0x1C;
        } while (var_s0 < temp_v0);
    }
}

int fxrain_entrypoint_2(void *arg0) {
    s32 vector_size(s32);
    return ((*(s32 *)((s8 *)(arg0) + (0x28))) != 1) && (vector_size((*(s32 *)((s8 *)(arg0) + (0x20)))) == 0);
}

int fxrain_entrypoint_3(void *arg0) {
    s32 state;

    if ((*(s32 *)((s8 *)arg0 + 0x28)) != 1) {
        return 0;
    }
    state = (*(u8 *)((s8 *)arg0 + 0x30));
    switch (state) {
    case 1:
    case 2:
        return 1;
    case 3:
        return ((*(f32 *)((s8 *)arg0 + 0x44)) * 0.9f) > (*(f32 *)((s8 *)arg0 + 0x34));
    default:
        return 0;
    }
}

/* extern */

void fxrain_entrypoint_4(u8 *arg0) {
    s32 func_800C2FDC();
    s32 heap_free(u8 *);
    s32 vector_free(s32, u8 *);
    u8 temp_a2;

    temp_a2 = (*(u8 *)((s8 *)(arg0) + (0)));
    if (temp_a2 != 0) {
        func_800C2FDC(temp_a2 & 0xFF, arg0, (u32)temp_a2);
        (*(u8 *)((s8 *)(arg0) + (0))) = 0;
    }
    vector_free((*(s32 *)((s8 *)(arg0) + (0x20))), arg0);
    heap_free(arg0);
}

/* extern */

u8 *fxrain_entrypoint_5(s32 arg0) {
    s32 func_800EFD24(u8 *);
    u8 *heap_alloc(s32);
    s32 vector_new(s32, s32);
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x4C);
    func_800EFD24(temp_v0 + 4);
    func_800EFD24(temp_v0 + 0x10);
    (*(s8 *)((s8 *)(temp_v0) + (0))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0x1C))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0x30))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x20))) = vector_new(0x1C, arg0);
    (*(s32 *)((s8 *)(temp_v0) + (0x24))) = arg0;
    (*(s32 *)((s8 *)(temp_v0) + (0x28))) = 0;
    (*(f32 *)((s8 *)(temp_v0) + (0x2C))) = 0.1f;
    return temp_v0;
}

void fxrain_entrypoint_6(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    typedef struct {
        u8 pad0[0x30];
        u8 enabled;
        f32 elapsed;
        f32 rate;
        f32 values[4];
    } RainFade;
    RainFade *this = arg0;
    this->enabled = 1;
    this->elapsed = 0.0f;
    this->rate = 0.1f;
    this->values[0] = arg1;
    this->values[1] = arg2;
    this->values[2] = arg3;
    this->values[3] = arg4;
}

void fxrain_entrypoint_7(s32 arg0)
{
    func_808001E8_fxrain(arg0,1);
}

/* extern */

void fxrain_entrypoint_8(u8 *arg0) {
    s32 func_800C3A40(u8, f32, f32, f32);
    u8 temp_a0;

    func_808001E8_fxrain(arg0, 2);
    temp_a0 = *arg0;
    if (temp_a0 != 0) {
        func_800C3A40(temp_a0, 0.0f, 0.0f, 3.0f);
        *arg0 = 0U;
    }
}

void fxrain_entrypoint_9(void *arg0) {
    typedef struct {
        u8 sound;
        f32 position[3];
        f32 displacement[3];
        u8 cursor;
        s32 particles;
        s32 unk24;
        s32 active;
        f32 timer;
        u8 phase;
        f32 elapsed;
        f32 periods[5];
    } Rain;
    typedef struct {
        f32 position[3];
        f32 velocity[3];
        u8 persistent;
    } RainParticle;
    s32 func_800A5490(void);
    s32 func_800C2E04(void);
    s32 func_800C2FDC();
    void func_800C301C(u8, s32);
    void func_800C316C(u8, s32, s32, f32);
    void func_800C330C(u8, s32);
    void func_800C3418(u8, s32);
    void func_800C37E0(u8, f32, f32, f32);
    s32 func_800C3A40(u8, f32, f32, f32);
    void func_800C3BDC(u8);
    f32 func_800D8FF8(void);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    s32 func_800F1574(f32 *, f32);
    void *vector_at(s32, s32);
    s32 vector_clear(s32);
    s32 vector_erase(s32, s32);
    s32 vector_size(s32);
    f32 position[3];
    f32 delta;

    delta = func_800D8FF8();
    func_800E3980(position);
    func_800EFB24(((Rain *)arg0)->displacement, position, ((Rain *)arg0)->position);
    func_800EE7F8(((Rain *)arg0)->position, position);
    if (func_800A5490()) {
        vector_clear(((Rain *)arg0)->particles);
    }
    if (vector_size(((Rain *)arg0)->particles) > 0) {
        if (((Rain *)arg0)->sound == 0) {
            ((Rain *)arg0)->sound = func_800C2E04();
            func_800C330C(((Rain *)arg0)->sound, 3);
            func_800C301C(((Rain *)arg0)->sound, 0x465);
            func_800C37E0(((Rain *)arg0)->sound, 0.95f, 1.05f, 0.01f);
            func_800C3A40(((Rain *)arg0)->sound, 3.0f, 12960000.0f, 0.0f);
            func_800C3418(((Rain *)arg0)->sound, 2);
            func_800C316C(((Rain *)arg0)->sound, 5000, 6000, 5.0f);
            func_800C3BDC(((Rain *)arg0)->sound);
        }
    } else if (((Rain *)arg0)->sound != 0) {
        func_800C2FDC(((Rain *)arg0)->sound);
        ((Rain *)arg0)->sound = 0;
    }
    {
        s32 i;
        RainParticle *particle;
        for (i = 0; i < vector_size(((Rain *)arg0)->particles); i++) {
            particle = vector_at(((Rain *)arg0)->particles, i);
            particle->position[0] += particle->velocity[0] * delta;
            particle->position[1] += particle->velocity[1] * delta;
            particle->position[2] += particle->velocity[2] * delta;
            if (particle->position[1] < position[1] - 500.0f && particle->persistent == 0) {
                vector_erase(((Rain *)arg0)->particles, i);
                i--;
            }
        }
    }
    ((Rain *)arg0)->cursor++;
    if (((Rain *)arg0)->cursor < vector_size(((Rain *)arg0)->particles)) {
        f32 distance;
        distance = 2200.0f;
        if (func_800EEB40(vector_at(((Rain *)arg0)->particles, ((Rain *)arg0)->cursor), position) >
            distance * distance) {
            vector_erase(((Rain *)arg0)->particles, ((Rain *)arg0)->cursor);
        }
    } else {
        ((Rain *)arg0)->cursor = 0;
    }
    if (((Rain *)arg0)->phase != 0) {
        ((Rain *)arg0)->elapsed += delta;
        if (((Rain *)arg0)->elapsed >= ((Rain *)arg0)->periods[((Rain *)arg0)->phase]) {
            ((Rain *)arg0)->phase++;
            ((Rain *)arg0)->elapsed = 0.0f;
            if (((Rain *)arg0)->phase >= 5) {
                ((Rain *)arg0)->phase = 1;
            }
        }
        if (((Rain *)arg0)->phase == 1) {
            ((Rain *)arg0)->periods[0] = (1.0f - ((Rain *)arg0)->elapsed / ((Rain *)arg0)->periods[1]) * 0.1f;
        } else if (((Rain *)arg0)->phase == 2) {
            ((Rain *)arg0)->periods[0] = 0.01f;
        } else if (((Rain *)arg0)->phase == 3) {
            ((Rain *)arg0)->periods[0] = ((Rain *)arg0)->elapsed / ((Rain *)arg0)->periods[3] * 0.1f;
        } else {
            ((Rain *)arg0)->periods[0] = 0.01f;
        }
        if (((Rain *)arg0)->periods[0] <= 0.01f) {
            ((Rain *)arg0)->periods[0] = 0.01f;
        }
    }
    if (func_800F1574(&((Rain *)arg0)->timer, delta)) {
        if (((Rain *)arg0)->active == 1 && !func_800A5490() && ((Rain *)arg0)->phase != 4) {
            func_80800000_fxrain(arg0);
        }
        if (((Rain *)arg0)->phase != 0) {
            ((Rain *)arg0)->timer = ((Rain *)arg0)->periods[0];
        } else {
            ((Rain *)arg0)->timer = 0.01f;
        }
    }
}
