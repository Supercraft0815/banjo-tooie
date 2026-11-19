#include "common.h"
#include "core2/particle_internal.h"

/* extern */

int func_800B46B0(void *arg0, BtIntPtr arg1, f32 arg2[3], f32 arg3[3]) {
    void *func_800BEF00(f32 *a,f32 *b,f32 *out,u32 flags);
    f32 sp2C[3];
    s32 var_a3;
    f32 temp_f0;
    s16 temp_v0;

    if ((((ParticleEmitter *)arg0)->min_y == -0x8000) && (((ParticleEmitter *)arg0)->max_y == 0x7FFF)) {
        if (((ParticleEmitter *)arg0)->flags & 0x100) {
            var_a3 = 0x420021;
        } else {
            var_a3 = 0x400000;
        }
        return func_800BEF00(arg2, arg3, sp2C, var_a3) BT_NATIVE_ONLY(!= NULL);
    } else {
    temp_v0 = ((ParticleEmitter *)arg0)->max_y;
    if (temp_v0 != 0x7FFF) {
        temp_f0 = (f32) temp_v0;
        if (temp_f0 < arg3[1]) {
            arg3[1] = temp_f0;
            return 1;
        }
    }
    if (((ParticleEmitter *)arg0)->min_y != -0x8000) {
        temp_f0 = (f32) ((ParticleEmitter *)arg0)->min_y;
        if (arg3[1] < temp_f0) {
            arg3[1] = temp_f0;
            return 1;
        }
    }
    return 0;
    }
}

s32 func_800B4790(BtIntPtr arg0) {
    typedef struct {
        s16 acceleration[3];
        s16 position[3];
        f32 alpha;
        f32 rotation[3];
        f32 age;
        s16 angularVelocity[3];
        s16 velocity[3];
        s16 frame;
        s16 frameRate;
        s16 scale;
        s16 initialScale;
        s16 scaleChange;
        s16 lifetime;
        BT_BITFIELD_ORDER(unsigned int bounces : 8, unsigned int  : 16);
        BT_BITFIELD_ORDER(unsigned int touched : 1, unsigned int flags : 7);
        BT_BITFIELD_ORDER(unsigned int flags : 7, unsigned int touched : 1);
        BT_BITFIELD_ORDER(unsigned int : 16, unsigned int bounces : 8);
    } UpdateParticle;
    typedef struct UpdateEmitter {
        u16 flags;
        u8 pad02[5];
        u8 state;
        u8 pad08[2];
        u8 type;
        u8 frameCount;
        u8 pad0C[12];
        f32 fadeIn;
        f32 fadeOut;
        f32 spawnTimer;
        f32 duration;
        u8 pad28[42];
        u8 animation;
        u8 pad53;
        f32 spawnMin;
        f32 spawnMax;
        u8 pad5C[44];
        s32 water;
        UpdateParticle *start;
        UpdateParticle *end;
        UpdateParticle *limit;
        s16 waterOffset;
        u8 pad9A[16];
        s16 sound;
        u8 padAC[4];
        f32 restitution;
        f32 pitchMin;
        f32 pitchMax;
        s32 volume;
        void (*callback)(struct UpdateEmitter *, f32 *);
        u8 padC4[12];
        f32 damping;
    } UpdateEmitter;
    s32 _idwater_entrypoint_1(s32);
    void func_800B9B50(void *, void *);
    void func_800C3FC0(s32, f32, s32);
    f32 func_800D8FF8(void);
    f32 func_800DC178(f32, f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EE940(s16 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 mlAbsF(f32);
    void rare_memcpy(void *, void *, int);
    extern f32 D_80127F14;
    extern s8 D_80127F1C;
    UpdateParticle *p;
    f32 dt;
    f32 lifetime;
    f32 fraction;
    f32 position[3];
    f32 probe[3];
    s32 hit;
    f32 volume;
    int i;

    dt = func_800D8FF8();
    if ((u8)D_80127F1C) {
        p = ((UpdateEmitter *)arg0)->start;
        while (p < ((UpdateEmitter *)arg0)->end) {
            p->age += dt;
            lifetime = p->lifetime * (1.0f / 256.0f);
            if (p->age >= lifetime) {
                rare_memcpy((u8 *)p, (u8 *)--((UpdateEmitter *)arg0)->end, sizeof(UpdateParticle));
                if (((UpdateEmitter *)arg0)->state == 1) {
                    ((UpdateEmitter *)arg0)->limit--;
                }
            } else {
                fraction = p->age / lifetime;
                if (fraction < ((UpdateEmitter *)arg0)->fadeIn) {
                    p->alpha = fraction / ((UpdateEmitter *)arg0)->fadeIn;
                } else if (fraction <= ((UpdateEmitter *)arg0)->fadeOut) {
                    p->alpha = 1.0f;
                } else {
                    p->alpha = 1.0f - (fraction - ((UpdateEmitter *)arg0)->fadeOut) / (1.0f - ((UpdateEmitter *)arg0)->fadeOut);
                }
                p->scale = p->initialScale + (s32)(fraction * p->scaleChange * (1.0f / 256.0f) * 256.0f);
                if (((UpdateEmitter *)arg0)->type == 7) {
                    switch (((UpdateEmitter *)arg0)->animation) {
                    case 0:
                        break;
                    case 1:
                        p->frame += (s32)(p->frameRate * dt);
                        if ((p->frame >> 8) >= ((UpdateEmitter *)arg0)->frameCount) {
                            p->frame = 0;
                        }
                        break;
                    case 2:
                        p->frame += (s32)(p->frameRate * dt);
                        if ((p->frame >> 8) >= ((UpdateEmitter *)arg0)->frameCount) {
                            p->frame = (((UpdateEmitter *)arg0)->frameCount << 8) - 256;
                        }
                        break;
                    }
                }
                for (i = 0; i < 3; i++) {
                    p->position[i] += p->velocity[i] * dt;
                    p->rotation[i] += p->angularVelocity[i] * dt;
                    p->velocity[i] += p->acceleration[i] * dt;
                }
                if (((UpdateEmitter *)arg0)->flags & 0x2000) {
                    for (i = 0; i < 3; i++) {
                        p->velocity[i] *= ((UpdateEmitter *)arg0)->damping;
                    }
                }
                if (((UpdateEmitter *)arg0)->flags & 0x4000) {
                    for (i = 0; i < 3; i++) {
                        p->rotation[i] *= ((UpdateEmitter *)arg0)->damping;
                    }
                }
                if (((UpdateEmitter *)arg0)->water) {
                    p->position[1] = _idwater_entrypoint_1(((UpdateEmitter *)arg0)->water) + ((UpdateEmitter *)arg0)->waterOffset;
                }
                func_800EE88C(position, p->position);
                if ((((UpdateEmitter *)arg0)->flags & 0x1000) && !p->touched) {
                    rare_memcpy((u8 *)p, (u8 *)--((UpdateEmitter *)arg0)->end, sizeof(UpdateParticle));
                    if (((UpdateEmitter *)arg0)->state == 1) {
                        ((UpdateEmitter *)arg0)->limit--;
                    }
                } else {
                    p->touched = 0;
                    if ((s32)p->bounces > 0) {
                        func_800EFA4C(probe, p->position[0], p->position[1] + 50.0f, p->position[2]);
                        hit = func_800B46B0((UpdateEmitter *)arg0, (BtIntPtr)p, probe, position);
                        func_800EE940(p->position, position);
                        if (hit) {
                            if (((UpdateEmitter *)arg0)->sound) {
                                volume = mlAbsF(p->velocity[1]) * 0.1f;
                                if (volume > 1) {
                                    volume = 1;
                                }
                                if (D_80127F14 == 0.0f) {
                                    func_800C3FC0(((UpdateEmitter *)arg0)->sound, func_800DC178(((UpdateEmitter *)arg0)->pitchMin, ((UpdateEmitter *)arg0)->pitchMax), (s32)(((UpdateEmitter *)arg0)->volume * volume));
                                    D_80127F14 = 0.25f;
                                }
                            }
                            p->position[1] += 2;
                            position[1] += 2.0f;
                            p->velocity[1] = mlAbsF(p->velocity[1]) * ((UpdateEmitter *)arg0)->restitution;
                            if (((UpdateEmitter *)arg0)->flags & 0x80) {
                                p->velocity[0] *= ((UpdateEmitter *)arg0)->restitution;
                                p->velocity[2] *= ((UpdateEmitter *)arg0)->restitution;
                            }
                            if (!(((UpdateEmitter *)arg0)->flags & 2)) {
                                p->initialScale *= ((UpdateEmitter *)arg0)->restitution;
                                p->scaleChange *= ((UpdateEmitter *)arg0)->restitution;
                            }
                            p->angularVelocity[0] *= ((UpdateEmitter *)arg0)->restitution;
                            p->angularVelocity[1] *= ((UpdateEmitter *)arg0)->restitution;
                            p->angularVelocity[2] *= ((UpdateEmitter *)arg0)->restitution;
                            if (--p->bounces == 0) {
                                if (((UpdateEmitter *)arg0)->callback) {
                                    ((UpdateEmitter *)arg0)->callback((UpdateEmitter *)arg0, position);
                                }
                                rare_memcpy((u8 *)p, (u8 *)--((UpdateEmitter *)arg0)->end, sizeof(UpdateParticle));
                                if (((UpdateEmitter *)arg0)->state == 1) {
                                    ((UpdateEmitter *)arg0)->limit--;
                                }
                                continue;
                            }
                        }
                    }
                    p++;
                }
            }
        }
        if (((UpdateEmitter *)arg0)->duration > 0.0f) {
            ((UpdateEmitter *)arg0)->duration -= dt;
            if (((UpdateEmitter *)arg0)->duration <= 0.0f) {
                ((UpdateEmitter *)arg0)->state = 2;
            }
        }
        switch (((UpdateEmitter *)arg0)->state) {
        case 0:
            ((UpdateEmitter *)arg0)->spawnTimer -= dt;
            if (((UpdateEmitter *)arg0)->spawnTimer <= 0.0f) {
                ((UpdateEmitter *)arg0)->spawnTimer = func_800DC178(((UpdateEmitter *)arg0)->spawnMin, ((UpdateEmitter *)arg0)->spawnMax);
                if (((UpdateEmitter *)arg0)->end < ((UpdateEmitter *)arg0)->limit) {
                    func_800B9B50((UpdateEmitter *)arg0, ((UpdateEmitter *)arg0)->end++);
                }
            }
            break;
        case 1:
            ((UpdateEmitter *)arg0)->spawnTimer -= dt;
            if (((UpdateEmitter *)arg0)->spawnTimer <= 0.0f) {
                ((UpdateEmitter *)arg0)->spawnTimer = func_800DC178(((UpdateEmitter *)arg0)->spawnMin, ((UpdateEmitter *)arg0)->spawnMax);
                if (((UpdateEmitter *)arg0)->limit - ((UpdateEmitter *)arg0)->end > 0) {
                    func_800B9B50((UpdateEmitter *)arg0, ((UpdateEmitter *)arg0)->end++);
                } else {
                    ((UpdateEmitter *)arg0)->state = 2;
                }
            }
            break;
        }
    }
    BT_NATIVE_ONLY(return 0;) }

void func_800B5028(void) {
    BtIntPtr heap_alloc(s32);
    extern ParticleEmitter **D_80127F10;
    extern s16 D_80127F18;
    D_80127F10 = (ParticleEmitter **)heap_alloc(0);
    D_80127F18 = 0;
}

void func_800B5054(void) {
    s32 func_800BA2C4(void *);
    void heap_free(void *);
    extern ParticleEmitter **D_80127F10;
    extern s16 D_80127F18;
    extern u8 D_80127F1D;
    s32 i;
    for (i = 0; i < D_80127F18; i++) {
        func_800BA2C4(D_80127F10[i]);
    }
    heap_free((void *)D_80127F10);
    D_80127F10 = 0;
    D_80127F18 = 0;
    D_80127F1D = 0;
}

void func_800B50F0(void) {
    s32 func_800B4790(BtIntPtr);
    void func_800B5450(void *);
    f32 func_800D8FF8(void);
    extern ParticleEmitter **D_80127F10;
    extern f32 D_80127F14;
    extern s16 D_80127F18;
    ParticleEmitter *emitter;
    s32 i;
    BtIntPtr offset;
    ParticleEmitter *entry;

    if (D_80127F14 < func_800D8FF8()) {
        D_80127F14 = 0.0f;
    } else {
        D_80127F14 -= func_800D8FF8();
    }
    if (D_80127F10 != 0) {
        for (i = 0, offset = 0; i < D_80127F18; i++, offset += sizeof(*D_80127F10)) {
            emitter = *(ParticleEmitter **)((u8 *)D_80127F10 + offset);
            func_800B4790((BtIntPtr)emitter);
            if (emitter->managed != 0 &&
                emitter->state == 2 &&
                emitter->end == emitter->begin) {
                emitter->remove_when_empty = 1;
            } else {
                emitter->remove_when_empty = 0;
            }
        }
        if (D_80127F18 > 0) {
            offset = 0;
            do {
                entry = *(ParticleEmitter **)((u8 *)D_80127F10 + offset);
                if (entry->remove_when_empty != 0) {
                    func_800B5450(entry);
                } else {
                    offset += sizeof(*D_80127F10);
                }
            } while (offset < D_80127F18 * (s32)sizeof(*D_80127F10));
        }
    }
}

void func_800B525C(BtIntPtr arg0) {
    void func_800BC358(void *, BtIntPtr, s32);
    extern ParticleEmitter **D_80127F10;
    extern s16 D_80127F18;
    s32 i;
    for (i = 0; i < D_80127F18; i++) {
        func_800BC358(D_80127F10[i], arg0, 4);
    }
}

void func_800B52EC(BtIntPtr arg0) {
    void func_800BC358(void *, BtIntPtr, s32);
    extern ParticleEmitter **D_80127F10;
    extern s16 D_80127F18;
    s32 i;
    for (i = 0; i < D_80127F18; i++) {
        func_800BC358(D_80127F10[i], arg0, 0);
    }
}

void func_800B537C(s32 arg0)
{
    func_800B525C(arg0);
    func_800B52EC(arg0);
}
BtIntPtr func_800B53A4(s32 arg0) {
    s16 *func_800BA2E8(s32 arg0);
    void *heap_realloc(void *, BtIntPtr);
    extern ParticleEmitter **D_80127F10;
    extern s16 D_80127F18;
    D_80127F10 = heap_realloc(D_80127F10, ++D_80127F18 * (s32)sizeof(*D_80127F10));
    D_80127F10[D_80127F18 - 1] = (ParticleEmitter *)func_800BA2E8(arg0);
    D_80127F10[D_80127F18 - 1]->managed = 1;
    return (BtIntPtr)D_80127F10[D_80127F18 - 1];
}

void func_800B5450(void *arg0) {
    s32 func_800BA2C4(void *);
    void *heap_realloc(void *, BtIntPtr);
    extern ParticleEmitter **D_80127F10;
    extern s16 D_80127F18;
    s32 i = 0;

    while (BT_DATA_FIELD(i < D_80127F18 && arg0 != D_80127F10[i], arg0 != D_80127F10[i] && i < D_80127F18)) { i++; }
    if (i == D_80127F18)
        return;
    func_800BA2C4(arg0);
    D_80127F10[i] = D_80127F10[D_80127F18 - 1];
    D_80127F18--;
    D_80127F10 = heap_realloc(D_80127F10, D_80127F18 * (s32)sizeof(*D_80127F10));
}

void func_800B5534(s8 *arg0)
{
    arg0[9] = 0;
}

void func_800B553C(s8 *arg0)
{
    arg0[9] = 1;
}

void *func_800B5548(void *arg0) {
    BtIntPtr defrag(BtIntPtr);
    extern ParticleEmitter **D_80127F10;
    extern s16 D_80127F18;
    int i;
    BtIntPtr old;
    if (arg0) {
        old = (BtIntPtr)arg0;
        i = 0;
        while (BT_DATA_FIELD(i < D_80127F18 && D_80127F10[i] != arg0, D_80127F10[i] != arg0 && i < D_80127F18)) {
            i++;
        }
        arg0 = (void *)defrag((BtIntPtr)arg0);
        ((ParticleEmitter *)arg0)->begin = (void *)((BtIntPtr)arg0 + (BtUIntPtr)((BtIntPtr)((ParticleEmitter *)arg0)->begin - old));
        ((ParticleEmitter *)arg0)->end = (void *)((BtIntPtr)arg0 + (BtUIntPtr)((BtIntPtr)((ParticleEmitter *)arg0)->end - old));
        ((ParticleEmitter *)arg0)->capacity = (void *)((BtIntPtr)arg0 + (BtUIntPtr)((BtIntPtr)((ParticleEmitter *)arg0)->capacity - old));
        if (i < D_80127F18) {
            D_80127F10[i] = arg0;
        }
    }
    return arg0;
}

void func_800B562C(void) {
    BtIntPtr defrag(BtIntPtr);
    extern ParticleEmitter **D_80127F10;
    D_80127F10 = (ParticleEmitter **)defrag((BtIntPtr)D_80127F10);
}

void func_800B5654(s32 arg0, s32 arg1) {
    extern s8 D_80127F1C;
    if (arg1 == 2) {
        D_80127F1C = 1;
        return;
    }
    D_80127F1C = 0;
}

#include "1E8DFA0_reflection_height.inc"

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
ParticleEmitter **D_80127F10 BT_DATA(4, bss_core2bss1_0_2, 0x770);
f32 D_80127F14 BT_DATA(4, bss_core2bss1_0_2, 0x774);
s16 D_80127F18 BT_DATA(4, bss_core2bss1_0_2, 0x778);
s8 D_80127F1C BT_DATA(4, bss_core2bss1_0_2, 0x77C);
#endif
