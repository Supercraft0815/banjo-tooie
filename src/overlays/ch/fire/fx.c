#include "common.h"

OSThread *chfirefx_entrypoint_0(void)
{
    extern u8 D_80801200_chfirefx[];

    return (OSThread *) D_80801200_chfirefx;
}

OSThread *chfirefx_entrypoint_1(void)
{
    extern u8 D_80801248_chfirefx[];

    return (OSThread *) D_80801248_chfirefx;
}

/* extern */

typedef union {
    Actor actor;
    struct {
        u8 pad0[0x74];
        u32 pad74_7 : 25;
        u32 unk74_6 : 1;
        u32 pad74_0 : 6;
    } flags;
} ChFireFxActor;

void func_80800018_chfirefx(ChFireFxActor *arg0) {
    void chfirefx_entrypoint_2(Actor *, f32, f32, s32, s32);
    s32 var_v0;

    var_v0 = 0xD;
    if (arg0->flags.unk74_6) {
        var_v0 = 0x2D;
    }
    arg0->flags.unk74_6 = 0;
    chfirefx_entrypoint_2(&arg0->actor, arg0->actor.scale, (f32)arg0->actor.unk74_7, (s32)arg0->actor.rotation[1], var_v0);
}

void chfirefx_entrypoint_2(Actor *arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    struct FireData {
        s32 unk0;
        f32 scale;
        s16 unk8, unkA, count, active;
        u16 flags;
        s16 value;
        u16 radius, range;
        u8 link[8];
    } *data;
    u32 *func_80100074(Actor *, u32, u32);
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    s32 func_800EA05C(void);
    Actor *other;
    data = (struct FireData *)func_80100074(arg0, 0, arg3 * 20 + 32);
    data->count = arg3;
    data->unk8 = 0;
    data->unkA = data->unk8;
    data->active = 0;
    data->scale = arg1;
    data->flags = arg4;
    data->value = (s32)arg2;
    data->radius = (u32)(arg1 * 150.0f);
    data->range = (u32)(arg1 * 850.0f);
    if ((arg4 & 8) && arg2 <= 70.0f) { data->active = 1; }
    if (arg4 & 16) { data->active = 1; }
    other = _subaddiefind_entrypoint_2(0x289, NULL);
    _subaddielink_entrypoint_1(data->link, other ? other->unk0 : NULL);
    arg0->unk64_20 = func_800EA05C() == 0xED;
}

void chfirefx_entrypoint_3(Actor *arg0) {
    struct FireParticle {
        f32 frame;
        s16 velocity, unk6;
        s16 position[3];
        s16 unkE[3];
    };
    struct FireData {
        s32 unk0;
        f32 scale;
        s16 used, amount, count, active;
        u16 flags;
        s16 value;
        u16 radius, range;
        u8 link[8];
        struct FireParticle particles[1];
    };
    s32 _chhotwaterpoolbits_entrypoint_5(s32, s32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800EFC7C(void *, void *);
    u32 func_800F54E4(void);
    s32 func_800F6438(u32);
    s32 func_800F6478(s32);
    int func_800F6AA4(s32);
    s32 func_800F7B9C(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_8010CEF8(f32 *, s32);
    s32 func_80800884_chfirefx(Actor *);
    void func_80800C18_chfirefx(Actor *);
    void func_80800E9C_chfirefx(Actor *);
    void rare_memcpy(void *, void *, int);
    register struct FireData *data;
    register struct FireParticle *particle;
    register u32 player;
    f32 delta;
    f32 speed;
    f32 acceleration;
    struct FireParticle *start;
    int i;
    f32 position[3];
    f32 direction[3];

    data = func_80100094(arg0, 0);
    player = func_800F54E4();
    func_800D9078(&arg0->unk58);
    switch ((s32)arg0->unk70_10) {
        case 2:
            data->amount += 2;
            if (data->amount >= data->count) {
                data->amount = data->count;
            }
            if ((data->flags & 4) && func_800F6438(player) &&
                !func_800F6AA4(player) && func_800F6478(player) &&
                func_8010CEF8(arg0, data->value) &&
                func_800F7B9C(player, 0x51) == 2) {
                _chhotwaterpoolbits_entrypoint_5(arg0, 0x3F400000);
            }
            break;
        case 1:
            data->amount -= 2;
            if (data->amount < 0) {
                data->amount = 0;
            }
            break;
    }
    if (func_80800884_chfirefx(arg0)) {
        delta = func_800D8FF8();
        speed = (data->scale * delta) * 50.0f;
        acceleration = (data->scale * delta) * 400.0f;
        start = data->particles;
        particle = start;
        for (i = 0; i < data->used;) {
            particle->frame += delta * 15.0f;
            if ((s32)particle->frame >= 9) {
                data->used--;
                if (data->used > 0) {
                    rare_memcpy(particle, &start[data->used], sizeof(*particle));
                }
                continue;
            }
            {
                particle->velocity = (s32)(particle->velocity + acceleration);
                particle->position[1] = (s32)(particle->position[1] + delta * particle->velocity);
                func_800EE88C(position, particle->position);
                func_800EF04C(position, arg0->position);
                if (func_800EFC7C(position, arg0->position) >
                    (0.4f * data->value) * (0.4f * data->value)) {
                    func_800EFB24(direction, arg0->position, position);
                    direction[1] = 0.0f;
                    func_800EF368(direction, speed);
                    particle->position[0] += direction[0];
                    particle->position[2] += direction[2];
                }
                particle++;
                i++;
            }
        }
    }
    if (data->flags & 1) {
        func_80800C18_chfirefx(arg0);
    }
    func_80800E9C_chfirefx(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/chfirefx_entrypoint_4.s")

s32 chfirefx_entrypoint_5(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 _subaddielink_entrypoint_3(u8 *);
    void func_80800C18_chfirefx(Actor *);
    u8 *sp1C;
    s32 *value = &arg2;

    if (arg1 == 0x95) {
        sp1C = func_80100094(arg0, 0);
        _subaddielink_entrypoint_3(sp1C + 0x18);
        *(s32 *)sp1C = 0;
        if (*(u16 *)(sp1C + 0x10) & 1) {
            func_80800C18_chfirefx(arg0);
        }
    } else {
        return 0;
    }
    return 1;
}

void chfirefx_entrypoint_6(Actor *arg0, s16 arg1, s16 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s16 *)((s8 *)(temp_v0) + (0x14))) = arg1;
    (*(s16 *)((s8 *)(temp_v0) + (0x16))) = arg2;
}

s32 func_80800884_chfirefx(Actor *arg0) {
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800E3980(f32 *);
    void func_800EE940(s16 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    struct Particle {
        f32 time;
        s16 lifetime;
        s16 flag;
        s16 velocity[3];
        s16 pad;
        f32 scale;
    };
    struct FireData {
        s32 unk0;
        f32 scale;
        s16 count;
        s16 limit;
        s16 unkC;
        s16 mode;
        s16 unk10;
        s16 distance;
        s16 unk14[6];
        struct Particle particles[1];
    };
    f32 angle;
    f32 offset;
    f32 camera[3];
    f32 velocity[3];
    s32 count;
    struct Particle *particle;
    struct FireData *data;

    data = func_80100094(arg0, 0);
    count = 0;
    if (data->count >= data->limit) {
        return 1;
    }
    if (data->mode == 1) {
        if (arg0->unk58 != 0.0f) {
            return 1;
        }
        arg0->unk58 = 0.06f;
    }
    func_800E3980(camera);
    while (data->count < data->limit && count < 2) {
        particle = &data->particles[data->count];
        particle->time = 0.0f;
        particle->lifetime = (s32)((f32)func_800DC128(30, 40) * data->scale);
        particle->scale = func_800DC178(0.8f, 1.2f);
        particle->flag = func_800DC298(0.5f);
        angle = func_800F1DF4(arg0->position, camera);
        offset = func_800DC178(-90.0f, 90.0f);
        func_800EEB9C(velocity, offset + angle, func_800DC178(data->distance * 0.25f, data->distance));
        func_800EE940(particle->velocity, velocity);
        count++;
        (data->count)++;
    }
    return 1;
}

void func_80800AA8_chfirefx(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(s32);
    void func_8010D640(s32);
    f32 func_800EEB40(f32 *, f32 *);
    u8 func_800C4350(s32, f32[3], s32 *);
    void func_800C3584(u8, f32, f32);
    void func_800C3BDC(u8);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    extern s32 D_80801290_chfirefx;
    u16 *data;
    f32 position[3];
    s32 active;

    data = func_80100094(arg0, 0);
    active = arg0->unk70_10 == 2;
    if (arg0->unk64_20) {
        active &= func_800DA298(0) == 0;
    }
    func_8010D640(position);
    if (active) {
        if (func_800EEB40(position, arg0->position) > (f32)(data[11] * data[11])) {
            active = 0;
        }
    }
    if (active) {
        if (arg0->unk5F == 0) {
            arg0->unk5F = func_800C4350(arg0->unk5F, arg0->position, &D_80801290_chfirefx);
        }
        if (arg0->unk5F != 0) {
            func_800C4350(arg0->unk5F, arg0->position, NULL);
            func_800C3584(arg0->unk5F, (f32)(u32)data[10], (f32)(u32)data[11]);
            func_800C3BDC(arg0->unk5F);
        }
    } else {
        _subaddieaudioloop_entrypoint_2(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800C18_chfirefx.s")

/* extern */

void func_80800E9C_chfirefx(Actor *arg0) {
    Actor *_subaddielink_entrypoint_4(u8 *);
    void *func_80100094(Actor *, u32);
    void func_80800AA8_chfirefx(Actor *);
    void func_8080116C_chfirefx(Actor *, Unk80132ED0 **);
    Actor *temp_v0;

    temp_v0 = _subaddielink_entrypoint_4((u8 *)func_80100094(arg0, 0U) + 0x18);
    if ((temp_v0 == NULL) || (arg0->unk70_10 != 2)) {
        func_80800AA8_chfirefx(arg0);
        return;
    }
    func_8080116C_chfirefx(temp_v0, &arg0->unk0);
}

void func_80800F00_chfirefx(Actor *arg0) {
    s32 _subaddielink_entrypoint_0(u8 *);
    void *func_80100094(Actor *, u32);
    s32 *sp2C;
    s32 var_s0;
    u8 *var_s1;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    var_s0 = 0;
    var_s1 = temp_v0 + 8;
    sp2C = (s32 *)temp_v0;
    do {
        _subaddielink_entrypoint_0(var_s1);
        var_s0 += 8;
        var_s1 += 8;
    } while (var_s0 != 0x80);
    sp2C[1] = 0;
    sp2C[0] = (s32)arg0->rotation[1];
}

void func_80800F7C_chfirefx(Actor *arg0)
{
  Actor *_subaddielink_entrypoint_4(u8 *);
  void *func_80100094(Actor *, u32);
  void func_80103110(Actor *, u32);
  void func_8010D254(f32 *);
  f32 func_800EEB40(f32 *, f32 *);
  Actor *actors[16];
  s32 i;
  s32 count;
  s32 j;
  f32 distances[16];
  f32 position[3];
  struct 
  {
    s32 limit;
    s32 count;
    u8 links[16][8];
  } *data;
  Actor *tmpActor;
  f32 tmpDistance;
  data = func_80100094(arg0, 0);
  for (i = 0, count = 0; i < data->count; i++)
  {
    actors[count] = _subaddielink_entrypoint_4(data->links[i]);
    if (actors[count] != NULL)
    {
      count++;
    }
  }

  func_80103110(arg0, 0);
  data->count = 0;
  if (count == 0)
  {
    return;
  }
  if (data->limit >= count)
  {
    for (i = 0; i < count; i++)
    {
      func_80800AA8_chfirefx(actors[i]);
    }

    return;
  }
  {
    func_8010D254(position);
    for (i = 0; i < count; i++)
    {
      distances[i] = func_800EEB40(position, actors[i]->position);
    }

    for (j = 1; j < count; j++)
    {
 do { for (i = j; (i > 0) && (distances[i] < distances[i - 1]); i--) { tmpDistance = distances[i]; distances[i] = distances[i - 1]; distances[i - 1] = tmpDistance; tmpActor = actors[i]; actors[i] = actors[i - 1]; actors[i - 1] = tmpActor; } } while (0);
    }

    for (i = 0; i < data->limit; i++)
    {
      func_80800AA8_chfirefx(actors[i]);
    }

  }
}

void func_8080116C_chfirefx(Actor *arg0, Unk80132ED0 **arg1)
{
  s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
  void *func_80100094(Actor *, u32);
  void func_80103110(Actor *, u32);
  s32 *temp_v0;
  temp_v0 = func_80100094(arg0, 0U);
  _subaddielink_entrypoint_1((((u8 *) temp_v0) + ((temp_v0[1]++) * 8)) + ((0, 8)), *arg1);
  func_80103110(arg0, 1U);
}
