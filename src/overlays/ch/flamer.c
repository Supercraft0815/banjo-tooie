#include "common.h"

void *func_80100094(Actor *, u32);
s8 func_800BF8E4(void);

OSThread *chflamer_entrypoint_0(void)
{
    extern u8 D_80800B20_chflamer[];

    return (OSThread *) D_80800B20_chflamer;
}

/* extern */

void func_8080000C_chflamer(Actor *arg0) {
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    (*(s16 *)((s8 *)(temp_v0) + (0x16))) = 0;
    (*(s16 *)((s8 *)(temp_v0) + (0x18))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x1AC))) = 0;
    if (func_800BF8E4() > 0) {
        (*(s16 *)((s8 *)(sp1C) + (4))) = 0x190;
    }
}

void func_80800050_chflamer(Actor *arg0) {
    struct FlamerActorFlags {
        u8 pad0[0x74];
        u32 pad74_25 : 7;
        u32 active : 1;
        u32 pad74_0 : 24;
    };
    struct FlamerParticle {
        f32 age;
        s16 velocity;
        s16 pad6;
        s16 position[3];
        u8 padE[6];
    };
    struct FlamerData {
        s32 light;
        u8 pad4[0x12];
        s16 count;
        s16 intensity;
        s16 pad1A;
        struct FlamerParticle particles[20];
        s32 unk1AC;
        f32 unk1B0;
        u8 link[1];
    };
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800EFC7C(void *, void *);
    void func_800FFA88(Unk80132ED0 *);
    f32 func_80103F38(Actor *, f32 *);
    s32 func_801072A8(void *);
    Actor *func_80800738_chflamer(Actor *);
    s32 func_808007A8_chflamer(Actor *, Actor *);
    void func_8080098C_chflamer(s32);
    void func_808009C0_chflamer(Actor *, Actor *);
    void rare_memcpy(void *, void *, int);
    struct FlamerData *data;
    Actor *linked;
    struct FlamerParticle *particle;
    f32 dt;
    f32 speed;
    f32 acceleration;
    s32 i;
    f32 world[3];
    f32 delta[3];

    data = func_80100094(arg0, 0U);
    linked = _subaddielink_entrypoint_4(data->link);
    if (linked != NULL && func_801072A8(linked) == 0) {
        data->unk1B0 = func_80103F38(linked, NULL);
        func_800EE7F8(arg0->position, linked->position);
        func_800EE7F8(arg0->rotation, linked->rotation);
        arg0->scale = linked->scale;
    }
    func_8080098C_chflamer((s32)arg0);
    switch (arg0->unk70_10) {
        case 1:
            if (linked == NULL || !((struct FlamerActorFlags *)linked)->active) {
                func_80800738_chflamer(arg0);
                linked = NULL;
            }
            data->intensity += 2;
            if (data->intensity >= 20) {
                data->intensity = 20;
                arg0->unk70_10 = 2;
            }
            break;
        case 2:
            if (func_800D9078(&arg0->unk58) != 0 || linked == NULL || !((struct FlamerActorFlags *)linked)->active) {
                func_80800738_chflamer(arg0);
                linked = NULL;
            }
            break;
        case 3:
            data->intensity--;
            if (data->intensity <= 0) {
                data->intensity = 0;
                if (data->count == 0) {
                    if (func_800BF8E4() > 0) {
                        data->light = _chlightfader_entrypoint_1(data->light, 1.0f, 2);
                    }
                    func_800FFA88(arg0->unk0);
                    return;
                }
            }
            break;
    }
    if (func_808007A8_chflamer(arg0, linked) != 0) {
        dt = func_800D8FF8();
        speed = dt * 50.0f;
        acceleration = dt * 300.0f;
        particle = data->particles;
        for (i = 0; i < data->count; ) {
            particle->age += dt * 15.0f;
            if ((s32)particle->age >= 9) {
                data->count--;
                if (data->count > 0) {
                    rare_memcpy(particle, &data->particles[data->count], sizeof(struct FlamerParticle));
                }
                continue;
            }
            {
                particle->velocity = (s32)(particle->velocity + acceleration);
                particle->position[1] = (s32)(particle->position[1] + dt * particle->velocity);
                func_800EE88C(world, particle->position);
                func_800EF04C(world, arg0->position);
                if (func_800EFC7C(world, arg0->position) > 1600.0f) {
                    func_800EFB24(delta, arg0->position, world);
                    delta[1] = 0.0f;
                    func_800EF368(delta, speed);
                    particle->position[0] += delta[0];
                    particle->position[2] += delta[2];
                }
                particle++;
                i++;
            }
        }
    }
    if (func_800BF8E4() > 0) {
        func_808009C0_chflamer(arg0, linked);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_80800434_chflamer.s")

/* extern */

s32 func_80800594_chflamer(Actor *arg0, s32 arg1, s32 arg2) {
    struct FlamerData {
        s32 unk0;
        u8 pad4[0x10];
        s8 unk14;
        u8 pad15[0x19F];
        u8 link[1];
    };
    s32 _subaddielink_entrypoint_3(u8 *);
    s32 func_800C8A98(void);
    struct FlamerData *sp1C;
    struct FlamerData *temp_v0;

    if (arg1 == 0x95) {
        temp_v0 = func_80100094(arg0, 0U);
        sp1C = temp_v0;
        _subaddielink_entrypoint_3(temp_v0->link);
        if (func_800BF8E4() > 0) {
            sp1C->unk0 = func_800C8A98();
            sp1C->unk14 = 0;
        }
    } else {
        return 0;
    }
    return 1;
}

s32 func_8010108C();
s32 func_8010114C(s32, s32, s32);

void chflamer_entrypoint_1(Actor *arg0, Unk80132ED0 *arg1) {
    struct LinkedActorFlags {
        u8 pad[0x74];
        u8 pad74_1 : 7;
        u8 unk74_0 : 1;
    };
    struct LinkFlags {
        u8 pad[0x18];
        u16 flags;
    };
    void _chbaddiesetup_entrypoint_2(s32 *, Unk80132ED0 *, s32);
    extern s32 _chflamer_entrypoint_2;

    if (!arg0->unk64_17) {
        if (!((struct LinkedActorFlags *)arg0)->unk74_0) {
            if ((arg1 != NULL) && (((struct LinkFlags *)arg1)->flags & 1)) {
                func_8010114C(arg1, 0x92, 0);
            }
            ((struct LinkedActorFlags *)arg0)->unk74_0 = 1;
            func_8010108C(arg0, 0x2B, 1);
            _chbaddiesetup_entrypoint_2(&_chflamer_entrypoint_2, arg0->unk0, 0);
        }
    }
}

void chflamer_entrypoint_2(Unk80132ED0 *arg0, s32 arg1) {
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    f32 func_800DC178(f32, f32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_801084B0(s32, Actor **);
    Actor *sp24;
    Actor *sp20;
    u8 *data;

    sp24 = func_80106790(arg0);
    if (!sp24->unk64_17) {
        sp20 = func_801084B0(0x3A2, &sp24);
        if (sp20 != NULL) {
            data = func_80100094(sp20, 0U);
            _subaddielink_entrypoint_1(data + 0x1B4, arg0);
            sp20->unk58 = func_800DC178(4.0f, 6.0f);
            sp20->unk70_10 = 1;
        }
    }
}

Actor *func_80800738_chflamer(Actor *arg0) {
    struct LinkedActorFlags {
        u8 pad[0x74];
        u8 pad74_1 : 7;
        u8 unk74_0 : 1;
    };
    s32 _subaddielink_entrypoint_0(u8 *);
    Actor *_subaddielink_entrypoint_4(u8 *);
    u8 *sp1C;
    Actor *data;

    sp1C = func_80100094(arg0, 0U);
    data = _subaddielink_entrypoint_4(sp1C + 0x1B4);
    if (data != NULL) {
        ((struct LinkedActorFlags *)data)->unk74_0 = 0;
        func_8010108C(data, 0x2B, 0);
    }
    _subaddielink_entrypoint_0(sp1C + 0x1B4);
    arg0->unk70_10 = 3;
    return arg0;
}

s32 func_808007A8_chflamer(Actor *arg0, Actor *arg1) {
    struct FlamerVolumeData {
        u8 pad0[0x16];
        s16 count;
        s16 capacity;
        u8 pad1A[0x192];
        s32 volume;
    };
    s32 _subaddievolume_entrypoint_0(Actor *, f32 *, s32, s32, s32 *);
    s32 func_800F1418(s32, s32);
    void func_808008C0_chflamer(Actor *, f32 *);
    f32 positions[20][3];
    s32 count;
    s32 limit;
    s32 i;
    s32 result;
    struct FlamerVolumeData *data;

    data = func_80100094(arg0, 0U);
    result = 0;
    if (data->count >= data->capacity) {
        return 1;
    }
    while (data->count < data->capacity) {
        limit = func_800F1418(20, data->capacity - data->count);
        count = _subaddievolume_entrypoint_0(arg1, positions[0], 2,
            limit, &data->volume);
        if (count >= 0) {
            result++;
        }
        if (count > 0) {
            for (i = 0; i < count; i++) {
                func_808008C0_chflamer(arg0, positions[i]);
            }
        } else {
            break;
        }
    }
    return result;
}

/* extern */

void func_808008C0_chflamer(Actor *arg0, f32 *arg1) {
    struct FlamerParticle {
        f32 time;
        s16 lifetime;
        s16 variant;
        s16 position[3];
        s16 padE;
        f32 scale;
    };
    struct FlamerParticles {
        u8 pad0[0x16];
        s16 count;
        s16 capacity;
        s16 pad1A;
        struct FlamerParticle particles[1];
    };
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800EE940(s16 *, f32 *);
    void func_800EF3DC(f32 *, f32 *);
    struct FlamerParticle *particle;
    struct FlamerParticles *data;

    data = func_80100094(arg0, 0U);
    if (data->count < data->capacity) {
        particle = &data->particles[data->count];
        particle->time = 0.0f;
        particle->lifetime = func_800DC128(0x1E, 0x28);
        particle->scale = func_800DC178(0.8f, 1.2f);
        particle->variant = func_800DC298(0.5f);
        func_800EF3DC(arg1, arg0->position);
        func_800EE940(particle->position, arg1);
        data->count++;
    }
}

void func_8080098C_chflamer(s32 arg0) {
    s32 _subaddieaudioloop_entrypoint_5(s32, s32, s32, s32, s32 *);
    extern s32 D_80800B68_chflamer;
    _subaddieaudioloop_entrypoint_5(arg0, arg0 + 4, 1, -1, &D_80800B68_chflamer);
}

struct FlamerLight {
    s32 light;
    s16 radius;
    f32 position[3];
    u8 initialized;
};

void func_808009C0_chflamer(Actor *arg0, Actor *arg1) {
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    f32 func_800DC178(f32, f32);
    s32 func_800E3E8C(f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F2F60(void *, void *, f32);
    f32 func_80103F38(Actor *, f32 *);
    extern u32 D_80800B7C_chflamer;
    f32 temp_f2;
    f32 sp40[3];
    f32 sp3C;
    struct FlamerLight *data;

    data = func_80100094(arg0, 0U);
    if (arg1 != 0) {
        temp_f2 = func_80103F38(arg1, sp40) * 0.75f;
        sp3C = temp_f2;
        data->radius = (s32) temp_f2;
    } else {
        sp3C = data->radius;
        func_800EE7F8(sp40, data->position);
    }
    if (data->initialized == 0 ||
        func_800E3E8C(arg0->position, 3.0f * sp3C) ||
        func_800E3E8C(data->position, 3.0f * sp3C)) {
        u32 sp2C[3];
        func_800F2F60(sp2C, &D_80800B7C_chflamer, func_800DC178(0.8f, 1.0f));
        func_800EE7F8(data->position, sp40);
        func_800C8CB8(data->light, sp40);
        func_800C8E84(data->light, sp2C);
        func_800C8E54(data->light, sp3C, 3.0f * sp3C);
    }
    data->initialized = 1;
}
