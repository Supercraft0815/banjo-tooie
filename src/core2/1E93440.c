#include "core2/1E93440.h"
#include "core2/particle_internal.h"

/* extern */

void func_800B9B50(ParticleEmitter *emitter, Particle *particle) {
    f32 func_800DC0C0();
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EE940(s16 *, f32 *);
    s32 func_800EEDA0(s16 *, s16 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_800EF368(f32 *, f32);
    void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    s32 func_800F0E44(s32);
    s32 i;
    f32 spB0[3];
    f32 spA4[3];
    f32 sp98[3];
    f32 sp8C[3];
    f32 sp80[3];
    f32 sp74[3];
    f32 sp68[3];
    f32 zero;
    f32 sp60;
    f32 sp5C;
    s16 temp_a0;
    s32 temp_s0;
    s32 temp_s1;

    for (i = 0; i < 3; i++) {
        particle->acceleration[i] = func_800DC128(emitter->acceleration_min[i], emitter->acceleration_max[i]);
    }
    particle->unk38 = (s8) (*(u16 *)&emitter->unkA8);
    if (emitter->fade_in == 0.0f) {
        particle->fade = 1.0f;
    } else {
        particle->fade = 0.0;
    }
    particle->frame = (s16) (s32) (func_800DC178((f32) emitter->start_frame[0], (f32) emitter->start_frame[1]) * 256.0f);
    particle->framerate = (s16) (s32) (func_800DC178(emitter->framerate[0], emitter->framerate[1]) * 256.0f);
    switch (emitter->spawn_mode) {
    case 0:
        if (emitter->flags & 0x40) {
            func_800EE88C(spB0, emitter->spawn.box.min);
            func_800EE88C(spA4, emitter->spawn.box.max);
            func_800EFE50(sp98, spB0, spA4, func_800DC0C0());
            func_800EE940(particle->position, sp98);
        } else {
            for (i = 0; i < 3; i++) {
                particle->position[i] = emitter->position[i] + func_800DC128(emitter->spawn.box.min[i], emitter->spawn.box.max[i]);
            }
        }
        break;
    case 1:
        func_800EE88C(sp8C, emitter->position);
        sp60 = (sp5C = func_800DC178(0.0f, 359.0f), func_800DC178(0.0f, 359.0f));
        func_800EF214(sp8C, sp5C, sp60, (f32) func_800DC128(emitter->spawn.sphere.radius[0], emitter->spawn.sphere.radius[1]));
        func_800EE940(particle->position, sp8C);
        break;
    case 2:
        func_800EE88C(sp80, emitter->position);
        sp60 = func_800DC178(0.0f, 359.9f);
        func_800EF1B8(sp80, sp60, (f32) func_800DC128(emitter->spawn.ring.radius[0], emitter->spawn.ring.radius[1]));
        func_800EE940(particle->position, sp80);
        particle->position[1] += func_800DC128(emitter->spawn.ring.height[1], emitter->spawn.ring.height[0]);
        break;
    }
    particle->scale = func_800DC128(emitter->start_scale[0], emitter->start_scale[1]);
    particle->start_scale = (s16) particle->scale;
    temp_a0 = emitter->final_scale[0];
    if ((temp_a0 == 0) && (emitter->final_scale[1] == 0)) {
        particle->scale_delta = 0;
    } else {
        particle->scale_delta = (s16) (func_800DC128(temp_a0, emitter->final_scale[1]) - particle->start_scale);
    }
    if (emitter->flags & 0x400) {
        for (i = 0; i < 3; i++) {
            particle->rotation[i] = func_800DC178(0.0f, 360.0f);
        }
    } else {
        func_800EFA4C(particle->rotation, (f32) emitter->rotation[0], (f32) emitter->rotation[1], (f32) emitter->rotation[2]);
    }
    for (i = 0; i < 3; i++) {
        particle->angular_velocity[i] = func_800DC128(emitter->angular_velocity_min[i], emitter->angular_velocity_max[i]);
    }
    particle->age = 0.0f;
    particle->lifetime = (s16) (func_800DC128(emitter->lifetime[0], emitter->lifetime[1]) + 1);
    switch (emitter->velocity_mode) {
    case 0:
        for (i = 0; i < 3; i++) {
            particle->velocity[i] = func_800DC128(emitter->velocity.box.min[i], emitter->velocity.box.max[i]);
        }
        break;
    case 1:
        temp_s0 = func_800F0E44(emitter->velocity.sphere.yaw[0] + func_800DC128(0, func_800F0E44(emitter->velocity.sphere.yaw[1] - emitter->velocity.sphere.yaw[0])));
        temp_s1 = func_800F0E44(emitter->velocity.sphere.pitch[0] + func_800DC128(0, func_800F0E44(emitter->velocity.sphere.pitch[1] - emitter->velocity.sphere.pitch[0])));
        zero = 0.0;
        func_800EF4E4(sp74, (f32) temp_s0, (f32) temp_s1, zero, zero, (f32) func_800DC128(emitter->velocity.sphere.speed[0], emitter->velocity.sphere.speed[1]));
        func_800EE940(particle->velocity, sp74);
        break;
    case 2:
        if (func_800EEDA0(particle->position, emitter->velocity.toward.point) == 0) {
            if (emitter->flags & 0x8000) {
                sp68[0] = (f32) (emitter->velocity.toward.point[0] - particle->position[0]);
                sp68[1] = (f32) (emitter->velocity.toward.point[1] - particle->position[1]);
                sp68[2] = (f32) (emitter->velocity.toward.point[2] - particle->position[2]);
            } else {
                sp68[0] = (f32) (particle->position[0] - emitter->velocity.toward.point[0]);
                sp68[1] = (f32) (particle->position[1] - emitter->velocity.toward.point[1]);
                sp68[2] = (f32) (particle->position[2] - emitter->velocity.toward.point[2]);
            }
            func_800EF368(sp68, func_800DC178((f32) emitter->velocity.toward.speed[0], (f32) emitter->velocity.toward.speed[1]));
            func_800EE940(particle->velocity, sp68);
        } else {
            particle->velocity[2] = 0;
            particle->velocity[0] = (s16) particle->velocity[2];
            particle->velocity[1] = func_800DC128(emitter->velocity.toward.speed[0], emitter->velocity.toward.speed[1]);
        }
        break;
    }
    particle->active = 1;
    if (emitter->flags & 8) {
        emitter->unk52 = 0;
    }
    if (emitter->flags & 0x10) {
        emitter->unk53 = 0;
    }
}

s32 func_800BA198(ParticleEmitter *emitter) {
    BtIntPtr temp_v1;

    if (emitter != NULL) {
        temp_v1 = (BtIntPtr)emitter->end;
        if (temp_v1 != 0) {
            return (s32) (temp_v1 - (BtIntPtr)emitter->begin) / (s32)sizeof(Particle);
        }
    }
    return 0;
}

void func_800BA1D0(ParticleEmitter *emitter, f32 position[3], f32 velocity[3], s32 count) {
    void func_800EE940(s16 *, f32 *);
    emitter->flags |= 0x40;
    func_800EE940(emitter->spawn.box.min, position);
    func_800EE940(emitter->spawn.box.max, velocity);
    emitter->spawn_mode = 0;
    func_800BA22C((BtIntPtr)emitter, count);
}

void func_800BA22C(BtIntPtr arg0, s32 n) {
    void func_800B9B50(ParticleEmitter *, Particle *);
    ParticleEmitter *emitter = (ParticleEmitter *)arg0;
    for (; n > 0; n--) {
        if (emitter->end < emitter->capacity) func_800B9B50(emitter, emitter->end++);
    }
}

int func_800BA28C(ParticleEmitter *emitter) {
    return (((BtIntPtr)emitter->end -
             (BtIntPtr)emitter->begin) / (s32)sizeof(Particle) == 0) &&
           (emitter->state == 2);
}

/* extern */

s32 func_800BA2C4(void *arg0) {
    void heap_free(void *memory);
    heap_free(arg0);
    return 0;
}

void *heap_alloc(s32);
void rare_memset(void *, u8, int);
void func_800BA4C4(ParticleEmitter *, f32);
void func_800BA4D0(ParticleEmitter *, s16);
void func_800BA554(ParticleEmitter *, f32, f32);
void func_800BA568(ParticleEmitter *, s16);
void func_800BA7C4(ParticleEmitter *, f32, f32);
void func_800BA894(ParticleEmitter *, f32, f32);
void func_800BA8F8(ParticleEmitter *, f32, f32);

s16 *func_800BA2E8(s32 arg0) {
    ParticleEmitter *emitter;

    emitter = heap_alloc(arg0 * sizeof(Particle) + offsetof(ParticleEmitter, particles));
    rare_memset(emitter, 0, arg0 * sizeof(Particle) + offsetof(ParticleEmitter, particles));
    emitter->state = 2;
    emitter->color[0] = emitter->color[1] = emitter->color[2] = emitter->color[3] = 0xFF;
    emitter->fade_out = 1.0f;
    func_800BA4D0(emitter, -0x8000);
    func_800BA568(emitter, 0x7FFF);
    func_800BA894(emitter, 0.0f, 5.0f);
    func_800BA8F8(emitter, 0.0f, 5.0f);
    func_800BA4C4(emitter, 0.9f);
    func_800BA554(emitter, 1.0f, 1.0f);
    func_800BA7C4(emitter, 1.0f, 1.0f);
    emitter->begin = emitter->particles;
    emitter->end = emitter->begin;
    emitter->capacity = emitter->end + arg0;
    emitter->unk52 = 1;
    emitter->unk53 = 1;
    return (s16 *)emitter;
}

/* extern */

void func_800BA3FC(BtIntPtr arg0, s32 asset_id) {
    ParticleEmitter *emitter = (ParticleEmitter *)arg0;
    s32 func_800AF5A0(s16 *arg0);
    void * func_800D674C(s32 a0);
    s32 func_800D738C(BtIntPtr);
    if (asset_id != emitter->asset_id) {
        emitter->asset_id = (u16) asset_id;
        emitter->asset_kind = func_800D738C(asset_id & 0xFFFF);
        emitter->unkB = func_800AF5A0(func_800D674C(emitter->asset_id));
    }
}

void func_800BA450(BtIntPtr arg0, s16 min_x, s16 min_y, s16 min_z, s16 max_x, s16 max_y, s16 max_z) {
    ParticleEmitter *emitter = (ParticleEmitter *)arg0;
    void func_800EFA6C(void *, s16, s16, s16);
    func_800EFA6C(emitter->acceleration_min, min_x, min_y, min_z);
    func_800EFA6C(emitter->acceleration_max, max_x, max_y, max_z);
}

void func_800BA4B0(ParticleEmitter *emitter, s32 alpha) {
    emitter->color[3] = alpha;
}

void func_800BA4B8(ParticleEmitter *emitter, s32 arg1, s32 arg2) {
    emitter->unkAA = arg1;
    emitter->unkBC = arg2;
}

void func_800BA4C4(ParticleEmitter *emitter, f32 arg1) {
    emitter->unkB0 = arg1;
}

void func_800BA4D0(ParticleEmitter *emitter, s16 min_y) {
    s32 func_800B5698(s16 *);
    void func_800BA54C(ParticleEmitter *, s32);
    s16 sp1E;
    if (func_800B5698(&sp1E) != 0) {
        if (min_y < sp1E) {
            min_y = sp1E;
        }
        if (emitter->unkA8 == 0) {
            func_800BA54C(emitter, 2);
        }
    }
    emitter->min_y = min_y;
}

void func_800BA544(ParticleEmitter *emitter, BtIntPtr arg1) {
    emitter->on_bounce = (void (*)(ParticleEmitter *, f32 *))arg1;
}

void func_800BA54C(ParticleEmitter *emitter, s32 arg1) {
    emitter->unkA8 = arg1;
}

void func_800BA554(ParticleEmitter *emitter, f32 arg1, f32 arg2) {
    emitter->unkB4 = arg1;
    emitter->unkB8 = arg2;
}

void func_800BA568(ParticleEmitter *emitter, s16 max_y) {
    emitter->max_y = max_y;
}

/* extern */

void func_800BA574(ParticleEmitter *emitter BT_PASS2(, s16 *bt_a0)) {
    BT_IDO_ONLY(s32 func_800EE814(s32);) BT_NATIVE_ONLY(void func_800EE814(s16 *, s16 *);)
    func_800EE814(emitter->unkC BT_PASS2(, bt_a0));
}

void func_800BA594(ParticleEmitter *emitter, f32 fade_in, f32 fade_out) {
    emitter->fade_in = fade_in;
    emitter->fade_out = fade_out;
}

void func_800BA5A8(ParticleEmitter *emitter, s32 flags) {
    emitter->flags = flags;
}

void func_800BA5B0(ParticleEmitter *emitter, s32 min, s32 max) {
    emitter->start_frame[0] = min;
    emitter->start_frame[1] = max;
}

void func_800BA5BC(ParticleEmitter *emitter, f32 min, f32 max) {
    emitter->framerate[0] = min;
    emitter->framerate[1] = max;
}

void func_800BA5D0(ParticleEmitter *emitter, s16 y) {
    Particle *particle;

    emitter->position[1] = y;
    if (emitter->end > (particle = emitter->begin)) {
        do {
            particle->position[1] = y;
            particle++;
        } while (particle < emitter->end);
    }
}

/* extern */

void func_800BA610(ParticleEmitter *emitter, s16 min_y, s16 max_y) {
    void func_800EFA6C(void *, s16, s16, s16);
    func_800EFA6C(emitter->acceleration_min, 0, min_y, 0);
    func_800EFA6C(emitter->acceleration_max, 0, max_y, 0);
}

void func_800BA660(ParticleEmitter *emitter, s32 arg1, s16 arg2) {
    emitter->unk88 = arg1;
    emitter->unk98 = arg2;
}

void func_800BA670(BtIntPtr arg0, s32 asset_id) {
    ParticleEmitter *emitter = (ParticleEmitter *)arg0;
    s32 func_800D738C(BtIntPtr);
    if (asset_id != emitter->asset_id) {
        emitter->asset_id = (u16) asset_id;
        emitter->asset_kind = func_800D738C(asset_id & 0xFFFF);
    }
}

void func_800BA6B0(ParticleEmitter *emitter, s16 min_x, s16 min_y, s16 min_z, s16 max_x, s16 max_y, s16 max_z) {
    void func_800EFA6C(void *, s16, s16, s16);
    emitter->spawn_mode = 0;
    func_800EFA6C(emitter->spawn.box.min, min_x, min_y, min_z);
    func_800EFA6C(emitter->spawn.box.max, max_x, max_y, max_z);
}

void func_800BA714(ParticleEmitter *emitter, s16 min, s16 max) {
    emitter->spawn_mode = 1;
    emitter->spawn.sphere.radius[0] = min;
    emitter->spawn.sphere.radius[1] = max;
}

void func_800BA730(ParticleEmitter *emitter, s16 radius_min, s16 radius_max, s16 height_min, s16 height_max) {
    emitter->spawn_mode = 2;
    emitter->spawn.ring.radius[0] = radius_min;
    emitter->spawn.ring.radius[1] = radius_max;
    emitter->spawn.ring.height[0] = height_min;
    emitter->spawn.ring.height[1] = height_max;
}

/* extern */

void func_800BA75C(BtIntPtr arg0, f32 position[3]) {
    ParticleEmitter *emitter = (ParticleEmitter *)arg0;
    void func_800EE940(s16 *, f32 *);
    func_800EE940(emitter->position, position);
}

void func_800BA77C(BtIntPtr arg0, s16 x, s16 y, s16 z) {
    ParticleEmitter *emitter = (ParticleEmitter *)arg0;
    void func_800EFA6C(void *, s16, s16, s16);
    func_800EFA6C(emitter->rotation, x, y, z);
}

void func_800BA7C4(ParticleEmitter *emitter, f32 min, f32 max) {
    emitter->start_scale[0] = (s16) (s32) (min * 256.0f);
    emitter->start_scale[1] = (s16) (s32) (max * 256.0f);
}

void func_800BA7FC(ParticleEmitter *emitter, f32 min, f32 max) {
    emitter->final_scale[0] = (s16) (s32) (min * 256.0f);
    emitter->final_scale[1] = (s16) (s32) (max * 256.0f);
}

void func_800BA834(ParticleEmitter *emitter, s16 min_x, s16 min_y, s16 min_z, s16 max_x, s16 max_y, s16 max_z) {
    void func_800EFA6C(void *, s16, s16, s16);
    func_800EFA6C(emitter->angular_velocity_min, min_x, min_y, min_z);
    func_800EFA6C(emitter->angular_velocity_max, max_x, max_y, max_z);
}

void func_800BA894(ParticleEmitter *emitter, f32 min, f32 max) {
    f32 func_800DC178(f32, f32);
    f32 timer = emitter->spawn_timer;
    emitter->spawn_interval[0] = min;
    emitter->spawn_interval[1] = max;
    if ((emitter->spawn_timer == 0.0f) || (max < timer)) {
        emitter->spawn_timer = func_800DC178(emitter->spawn_interval[0], emitter->spawn_interval[1]);
    }
}

void func_800BA8F8(ParticleEmitter *emitter, f32 min, f32 max) {
    emitter->lifetime[0] = (s16) (s32) (min * 256.0f);
    emitter->lifetime[1] = (s16) (s32) (max * 256.0f);
}

void func_800BA930(BtIntPtr arg0, s16 min_x, s16 min_y, s16 min_z, s16 max_x, s16 max_y, s16 max_z) {
    ParticleEmitter *emitter = (ParticleEmitter *)arg0;
    void func_800EFA6C(void *, s16, s16, s16);
    emitter->velocity_mode = 0;
    func_800EFA6C(emitter->velocity.box.min, min_x, min_y, min_z);
    func_800EFA6C(emitter->velocity.box.max, max_x, max_y, max_z);
}

void func_800BA994(ParticleEmitter *emitter, s16 yaw_min, s16 pitch_min, s16 speed_min, s16 yaw_max, s16 pitch_max, s16 speed_max) {
    f32 func_800136E4(f32);
    emitter->velocity_mode = 1;
    emitter->velocity.sphere.pitch[0] = (s32)func_800136E4((f32)pitch_min);
    emitter->velocity.sphere.pitch[1] = (s32)func_800136E4((f32)pitch_max);
    emitter->velocity.sphere.yaw[0] = (s32)func_800136E4((f32)yaw_min);
    emitter->velocity.sphere.yaw[1] = (s32)func_800136E4((f32)yaw_max);
    emitter->velocity.sphere.speed[0] = speed_min;
    emitter->velocity.sphere.speed[1] = speed_max;
}

void func_800BAA60(ParticleEmitter *emitter, f32 *point, s16 speed_min, s16 speed_max) {
    void func_800EE940(s16 *, f32 *);
    emitter->velocity_mode = 2;
    emitter->velocity.toward.speed[0] = speed_min;
    emitter->velocity.toward.speed[1] = speed_max;
    func_800EE940(emitter->velocity.toward.point, point);
}

void func_800BAA9C(ParticleEmitter *emitter, f32 scale) {
    func_800BA7C4(emitter, scale, scale);
    func_800BA7FC(emitter, scale, scale);
}

void func_800BAAE4(ParticleEmitter *emitter, f32 arg1, f32 arg2, f32 arg3) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(emitter->unk6C, arg1, arg2, arg3);
}

void func_800BAB1C(ParticleEmitter *emitter, f32 arg1, f32 arg2, f32 arg3) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(emitter->unk60, arg1, arg2, arg3);
}

void func_800BAB54(ParticleEmitter *emitter, f32 arg1) {
    emitter->unk5C = arg1;
}

/* extern */

void func_800BAB60(ParticleEmitter *emitter BT_PASS2(, void *bt_a0)) {
    BT_IDO_ONLY(s32 func_800F2EA0(BtIntPtr);) BT_NATIVE_ONLY(void func_800F2EA0(void *, void *);)
    func_800F2EA0(emitter->color BT_PASS2(, bt_a0));
}

/* extern */

void func_800BAB80(BtIntPtr arg0, f32 *arg1) {
    ParticleEmitter *emitter = (ParticleEmitter *)arg0;
    void func_800F2EBC(void *arg0, void *arg1);
    func_800F2EBC(emitter->color, arg1);
}

void func_800BABA0(ParticleEmitter *emitter, f32 arg1) {
    emitter->state = 0;
    emitter->unk24 = arg1;
}

void func_800BABB0(s32 arg0) 
{
}
/* extern */

BtIntPtr func_800BABB8(BtIntPtr arg0, f32 *position, f32 *target, f32 scale, s16 *cmd) {

    s32 func_800AF5A0(s16 *arg0);
    BtIntPtr func_800B53A4(s32);
    void func_800B5534(s8 *);
    void * func_800D674C(s32 a0);
    s32 func_800D738C(BtIntPtr);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    s32 func_800DC298(f32);
    void func_800EE940(s16 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFA6C(void *, s16, s16, s16);
    void func_800F31EC(u8 *, s32, s32, s32);
    void func_800F31FC(u8 *, s32, s32, s32, s32);
    f32 var_f22;
    s16 command;
    s32 sp17C;

    var_f22 = 1.0f;
    sp17C = 0;
    if ((arg0 != 0) && (position != NULL)) {
        func_800EE940(((ParticleEmitter *)arg0)->position, position);
    }
    if (cmd == NULL) return arg0;
    {
        command = *cmd;
        cmd++;
        if (command != 0) {
            do {
                switch (command & 0xFF) {
                case 0x1: {
                    s32 i;
                    for (i = 0; i < 3; i++, cmd += 1) {
                        ((ParticleEmitter *)arg0)->acceleration_min[i] = (f32)*cmd * var_f22;
                        ((ParticleEmitter *)arg0)->acceleration_max[i] = (f32)cmd[3] * var_f22;
                    }
                    cmd += 3;
                    break;
                }
                case 0x2:
                    ((ParticleEmitter *)arg0)->color[3] = (u8) ((s32) (command & 0xFF00) >> 8);
                    break;
                case 0x3:
                    ((ParticleEmitter *)arg0)->unkAA = cmd[0];
                    ((ParticleEmitter *)arg0)->unkBC = (s32) cmd[1];
                    cmd += 2;
                    break;
                case 0x4: {
                    f32 x;
                    x = (f32)cmd[0] * 0.00390625f;
                    cmd += 1;
                    ((ParticleEmitter *)arg0)->unkB0 = x;
                    break;
                }
                case 0x5: {
                    s32 temp_v0_2;
                    temp_v0_2 = cmd[0];
                    cmd += 1;
                    ((ParticleEmitter *)arg0)->min_y = temp_v0_2;
                    break;
                }
                case 0x6: {
                    s32 temp_v0_3;
                    temp_v0_3 = cmd[0];
                    cmd += 1;
                    ((ParticleEmitter *)arg0)->min_y = (s16) (s32) (position[1] + (f32) temp_v0_3);
                    break;
                }
                case 0x7:
                    ((ParticleEmitter *)arg0)->unkA8 = cmd[0];
                    cmd += 1;
                    break;
                case 0x8: {
                    f32 x, y;
                    x = (f32)cmd[0] * 0.00390625f;
                    y = (f32)cmd[1] * 0.00390625f;
                    cmd += 2;
                    ((ParticleEmitter *)arg0)->unkB4 = x;
                    ((ParticleEmitter *)arg0)->unkB8 = y;
                    break;
                }
                case 0x9: {
                    s32 temp_v0_4;
                    temp_v0_4 = cmd[0];
                    cmd += 1;
                    ((ParticleEmitter *)arg0)->max_y = temp_v0_4;
                    break;
                }
                case 0xA: {
                    s32 i;
                    for (i = 0; i < 3; i++, cmd += 1) {
                        ((ParticleEmitter *)arg0)->spawn.box.min[i] = (f32)*cmd * scale;
                        ((ParticleEmitter *)arg0)->spawn.box.max[i] = (f32)cmd[3] * scale;
                    }
                    ((ParticleEmitter *)arg0)->spawn_mode = 0;
                    cmd += 3;
                    break;
                }
                case 0xB:
                    ((ParticleEmitter *)arg0)->spawn_mode = 2;
                    ((ParticleEmitter *)arg0)->spawn.ring.radius[0] = (s16) (s32) ((f32) cmd[0] * scale);
                    ((ParticleEmitter *)arg0)->spawn.ring.radius[1] = (s16) (s32) ((f32) cmd[1] * scale);
                    ((ParticleEmitter *)arg0)->spawn.ring.height[0] = (s16) (s32) ((f32) cmd[2] * scale);
                    ((ParticleEmitter *)arg0)->spawn.ring.height[1] = (s16) (s32) ((f32) cmd[3] * scale);
                    cmd += 4;
                    break;
                case 0xC: {
                    f32 x;
                    s16 low, high;
                    x = (f32)cmd[0];
                    ((ParticleEmitter *)arg0)->spawn_mode = 0;
                    cmd++;
                    x *= scale;
                    low = -x;
                    func_800EFA6C(((ParticleEmitter *)arg0)->spawn.box.min, low, low, low);
                    high = x;
                    func_800EFA6C(((ParticleEmitter *)arg0)->spawn.box.max, high, high, high);
                    break;
                }
                case 0xD: {
                    /* Preserve the original frame slots whose accesses were optimized out. */
                    s32 stackPadding[8];
                    s16 x, low;
                    x = cmd[0];
                    cmd++;
                    ((ParticleEmitter *)arg0)->spawn_mode = 0;
                    x = (s32)((f32)x * scale);
                    low = -x;
                    func_800EFA6C(((ParticleEmitter *)arg0)->spawn.box.min, low, 0, low);
                    func_800EFA6C(((ParticleEmitter *)arg0)->spawn.box.max, x, x, x);
                    break;
                }
                case 0xE:
                    ((ParticleEmitter *)arg0)->spawn_mode = 1;
                    ((ParticleEmitter *)arg0)->spawn.sphere.radius[0] = (s16) (s32) ((f32) cmd[0] * scale);
                    ((ParticleEmitter *)arg0)->spawn.sphere.radius[1] = (s16) (s32) ((f32) cmd[1] * scale);
                    cmd += 2;
                    break;
                case 0xF:
                    ((ParticleEmitter *)arg0)->state = 1;
                    ((ParticleEmitter *)arg0)->spawn_timer = func_800DC178(((ParticleEmitter *)arg0)->spawn_interval[0], ((ParticleEmitter *)arg0)->spawn_interval[1]);
                    break;
                case 0x10: {
                    BtIntPtr temp_v0_6;
                    temp_v0_6 = func_800B53A4((s32) (command & 0xFF00) >> 8);
                    arg0 = temp_v0_6;
                    if (position != NULL) {
                        func_800EE940(((ParticleEmitter *)temp_v0_6)->position, position);
                    }
                    break;
                }
                case 0x11: {
                    s32 temp_t0;
                    BtIntPtr temp_v0_7;
                    temp_t0 = (s32) (command & 0xFF00) >> 8;
                    sp17C = temp_t0;
                    temp_v0_7 = func_800B53A4(temp_t0);
                    arg0 = temp_v0_7;
                    if (position != NULL) {
                        func_800EE940(((ParticleEmitter *)temp_v0_7)->position, position);
                    }
                    break;
                }
                case 0x12: {
                    s16 x, y, z;
                    x = cmd[0];
                    y = cmd[1];
                    z = cmd[2];
                    cmd += 3;
                    func_800EFA6C(((ParticleEmitter *)arg0)->unkC, x, y, z);
                    cmd += 3;
                    break;
                }
                case 0x13:
                    if (((s32) (command & 0xFF00) >> 8) != 0) {
                        var_f22 = scale;
                    } else {
                        var_f22 = 1.0f;
                    }
                    break;
                case 0x14: {
                    ((ParticleEmitter *)arg0)->flags = 0x586;
                    ((ParticleEmitter *)arg0)->unkB0 = 0.4f;
                    ((ParticleEmitter *)arg0)->fade_in = 0.0f;
                    ((ParticleEmitter *)arg0)->unkA8 = 4;
                    ((ParticleEmitter *)arg0)->lifetime[0] = 0x300;
                    ((ParticleEmitter *)arg0)->lifetime[1] = 0x400;
                    ((ParticleEmitter *)arg0)->fade_out = 0.8f;
                    func_800EFA6C(((ParticleEmitter *)arg0)->angular_velocity_min, 0xC8, 0, 0xC8);
                    func_800EFA6C(((ParticleEmitter *)arg0)->angular_velocity_max, 0x190, 0, 0x190);
                    func_800EFA6C(((ParticleEmitter *)arg0)->acceleration_min, 0, -0x3E8, 0);
                    func_800EFA6C(((ParticleEmitter *)arg0)->acceleration_max, 0, -0x320, 0);
                    break;
                }
                case 0x15: {
                    f32 x, y;
                    x = (f32)cmd[0] * 0.00390625f;
                    y = (f32)cmd[1] * 0.00390625f;
                    cmd += 2;
                    ((ParticleEmitter *)arg0)->fade_in = x;
                    ((ParticleEmitter *)arg0)->fade_out = y;
                    break;
                }
                case 0x16:
                    ((ParticleEmitter *)arg0)->flags = cmd[0];
                    cmd += 1;
                    break;
                case 0x17: {
                    f32 probability;
                    probability = (f32)*cmd++ * 0.00390625f;
                    if (func_800DC298(probability) != 0) {
                        ((ParticleEmitter *)arg0)->flags = (u16)*(s16 *)&((ParticleEmitter *)arg0)->flags | 0x800;
                    }
                    break;
                }
                case 0x18: {
                    s16 x, y;
                    f32 z, w;
                    x = cmd[0];
                    y = cmd[1];
                    z = (f32)cmd[2] * 0.00390625f;
                    w = (f32)cmd[3] * 0.00390625f;
                    cmd += 4;
                    ((ParticleEmitter *)arg0)->start_frame[1] = y;
                    ((ParticleEmitter *)arg0)->start_frame[0] = x;
                    ((ParticleEmitter *)arg0)->framerate[0] = z;
                    ((ParticleEmitter *)arg0)->framerate[1] = w;
                    break;
                }
                case 0x19: {
                    s16 temp_v0_9;
                    s16 temp_v1;
                    temp_v0_9 = cmd[0];
                    temp_v1 = cmd[1];
                    cmd += 2;
                    ((ParticleEmitter *)arg0)->start_frame[1] = temp_v1;
                    ((ParticleEmitter *)arg0)->start_frame[0] = temp_v0_9;
                    break;
                }
                case 0x1A:
                    func_800BA22C(arg0, (s32) (command & 0xFF00) >> 8);
                    break;
                case 0x1B:
                    func_800EFA6C(((ParticleEmitter *)arg0)->acceleration_min, 0, (s16) (s32) ((f32) cmd[0] * var_f22), 0);
                    func_800EFA6C(((ParticleEmitter *)arg0)->acceleration_max, 0, (s16) (s32) ((f32) cmd[1] * var_f22), 0);
                    cmd += 2;
                    break;
                case 0x1C: {
                    BtIntPtr temp_v0_10;
                    temp_v0_10 = (BtIntPtr)func_800BA2E8((s32) (command & 0xFF00) >> 8);
                    arg0 = temp_v0_10;
                    if (position != NULL) {
                        func_800EE940(((ParticleEmitter *)temp_v0_10)->position, position);
                    }
                    break;
                }
                case 0x1D: {
                    s32 model, kind;
                    model = *cmd++;
                    if (model == ((ParticleEmitter *)arg0)->asset_id) break;
                    ((ParticleEmitter *)arg0)->asset_id = model;
                    kind = func_800D738C(model & 0xFFFF);
                    ((ParticleEmitter *)arg0)->asset_kind = kind;
                    if ((kind & 0xFF) == 7) {
                        ((ParticleEmitter *)arg0)->unkB = func_800AF5A0(func_800D674C(((ParticleEmitter *)arg0)->asset_id));
                    }
                    break;
                }
                case 0x1E: {
                    f32 random;
                    random = func_800DC178((f32)cmd[0], (f32)cmd[1]);
                    random = scale * random;
                    cmd += 2;
                    ((ParticleEmitter *)arg0)->position[1] += (s16)random;
                    break;
                }
                case 0x1F: {
                    s16 temp_v0_13;
                    s16 temp_v1_2;
                    temp_v0_13 = cmd[0];
                    temp_v1_2 = cmd[1];
                    cmd += 2;
                    func_800F31EC(((ParticleEmitter *)arg0)->color, (u32) (temp_v0_13 & 0xFF00) >> 8, temp_v0_13 & 0xFF, (u32) (temp_v1_2 & 0xFF00) >> 8);
                    break;
                }
                case 0x20: {
                    s16 temp_v0_14;
                    s16 temp_v1_3;
                    temp_v0_14 = cmd[0];
                    temp_v1_3 = cmd[1];
                    cmd += 2;
                    func_800F31FC(((ParticleEmitter *)arg0)->color, (u32) (temp_v0_14 & 0xFF00) >> 8, temp_v0_14 & 0xFF, (u32) (temp_v1_3 & 0xFF00) >> 8, temp_v1_3 & 0xFF);
                    break;
                }
                case 0x21: {
                    s16 temp_a1_2;
                    s16 temp_a2;
                    s16 temp_a3;
                    temp_a1_2 = cmd[0];
                    temp_a2 = cmd[1];
                    temp_a3 = cmd[2];
                    cmd += 3;
                    func_800EFA6C(((ParticleEmitter *)arg0)->rotation, temp_a1_2, temp_a2, temp_a3);
                    break;
                }
                case 0x22: {
                    f32 x, y, z, w;
                    x = (f32)cmd[0] * 0.00390625f;
                    y = (f32)cmd[1] * 0.00390625f;
                    z = (f32)cmd[2] * 0.00390625f;
                    w = (f32)cmd[3] * 0.00390625f;
                    cmd += 4;
                    ((ParticleEmitter *)arg0)->start_scale[0] = x * scale * 256.0f;
                    ((ParticleEmitter *)arg0)->start_scale[1] = y * scale * 256.0f;
                    ((ParticleEmitter *)arg0)->final_scale[0] = z * scale * 256.0f;
                    ((ParticleEmitter *)arg0)->final_scale[1] = w * scale * 256.0f;
                    break;
                }
                case 0x23: {
                    f32 x;
                    x = (f32)cmd[0] * 0.00390625f;
                    cmd++;
                    x = x * scale * 256.0f;
                    ((ParticleEmitter *)arg0)->start_scale[0] = (s32)x;
                    ((ParticleEmitter *)arg0)->start_scale[1] = (s32)x;
                    ((ParticleEmitter *)arg0)->final_scale[0] = (s32)x;
                    ((ParticleEmitter *)arg0)->final_scale[1] = (s32)x;
                    break;
                }
                case 0x24: {
                    f32 x, y;
                    x = (f32)cmd[0] * 0.00390625f;
                    y = (f32)cmd[1] * 0.00390625f;
                    cmd += 2;
                    ((ParticleEmitter *)arg0)->start_scale[0] = x * scale * 256.0f;
                    ((ParticleEmitter *)arg0)->start_scale[1] = y * scale * 256.0f;
                    break;
                }
                case 0x25: {
                    f32 x, y;
                    x = (f32)cmd[0] * 0.00390625f;
                    y = (f32)cmd[1] * 0.00390625f;
                    cmd += 2;
                    ((ParticleEmitter *)arg0)->final_scale[0] = x * scale * 256.0f;
                    ((ParticleEmitter *)arg0)->final_scale[1] = y * scale * 256.0f;
                    break;
                }
                case 0x26:
                    func_800EFA6C(((ParticleEmitter *)arg0)->angular_velocity_min, cmd[0], cmd[1], cmd[2]);
                    func_800EFA6C(((ParticleEmitter *)arg0)->angular_velocity_max, cmd[3], cmd[4], cmd[5]);
                    cmd += 6;
                    break;
                case 0x27:
                    func_800EFA6C(((ParticleEmitter *)arg0)->angular_velocity_min, cmd[0], 0, cmd[1]);
                    func_800EFA6C(((ParticleEmitter *)arg0)->angular_velocity_max, cmd[2], 0, cmd[3]);
                    cmd += 4;
                    break;
                case 0x28: {
                    f32 x;
                    x = (f32)cmd[0] * 0.00390625f;
                    cmd++;
                    func_800BABA0((void *)arg0, x);
                    break;
                }
                case 0x29:
                    func_800B5534((s8 *)arg0);
                    break;
                case 0x2A: {
                    f32 x, y, z, w;
                    x = (f32)cmd[0] * 0.00390625f;
                    y = (f32)cmd[1] * 0.00390625f;
                    z = (f32)cmd[2] * 0.00390625f;
                    w = (f32)cmd[3] * 0.00390625f;
                    cmd += 4;
                    ((ParticleEmitter *)arg0)->spawn_interval[0] = x;
                    ((ParticleEmitter *)arg0)->spawn_interval[1] = y;
                    if ((((ParticleEmitter *)arg0)->spawn_timer == 0.0f) || (y < ((ParticleEmitter *)arg0)->spawn_timer)) {
                        ((ParticleEmitter *)arg0)->spawn_timer = func_800DC178(x, y);
                    }
                    ((ParticleEmitter *)arg0)->lifetime[0] = z * 256.0f;
                    ((ParticleEmitter *)arg0)->lifetime[1] = w * 256.0f;
                    break;
                }
                case 0x2B: {
                    f32 x, y;
                    x = (f32)cmd[0] * 0.00390625f;
                    y = (f32)cmd[1] * 0.00390625f;
                    cmd += 2;
                    ((ParticleEmitter *)arg0)->lifetime[0] = x * 256.0f;
                    ((ParticleEmitter *)arg0)->lifetime[1] = y * 256.0f;
                    break;
                }
                case 0x2C:
                    ((ParticleEmitter *)arg0)->velocity_mode = 0;
                    ((ParticleEmitter *)arg0)->velocity.box.min[0] = (s16) (s32) ((f32) cmd[0] * var_f22);
                    ((ParticleEmitter *)arg0)->velocity.box.min[1] = (s16) (s32) ((f32) cmd[1] * var_f22);
                    ((ParticleEmitter *)arg0)->velocity.box.min[2] = (s16) (s32) ((f32) cmd[2] * var_f22);
                    ((ParticleEmitter *)arg0)->velocity.box.max[0] = (s16) (s32) ((f32) cmd[3] * var_f22);
                    ((ParticleEmitter *)arg0)->velocity.box.max[1] = (s16) (s32) ((f32) cmd[4] * var_f22);
                    ((ParticleEmitter *)arg0)->velocity.box.max[2] = (s16) (s32) ((f32) cmd[5] * var_f22);
                    cmd += 6;
                    break;
                case 0x2D:
                    ((ParticleEmitter *)arg0)->velocity_mode = 2;
                    ((ParticleEmitter *)arg0)->velocity.toward.speed[0] = (s16) (s32) ((f32) cmd[0] * var_f22);
                    ((ParticleEmitter *)arg0)->velocity.toward.speed[1] = (s16) (s32) ((f32) cmd[1] * var_f22);
                    cmd += 2;
                    func_800EE940(((ParticleEmitter *)arg0)->velocity.toward.point, target);
                    break;
                case 0x2E:
                    ((ParticleEmitter *)arg0)->velocity_mode = 1;
                    ((ParticleEmitter *)arg0)->velocity.sphere.yaw[0] = cmd[0];
                    ((ParticleEmitter *)arg0)->velocity.sphere.pitch[0] = (s16) cmd[1];
                    ((ParticleEmitter *)arg0)->velocity.sphere.speed[0] = (s16) (s32) ((f32) cmd[2] * var_f22);
                    ((ParticleEmitter *)arg0)->velocity.sphere.yaw[1] = (s16) cmd[3];
                    ((ParticleEmitter *)arg0)->velocity.sphere.pitch[1] = (s16) cmd[4];
                    ((ParticleEmitter *)arg0)->velocity.sphere.speed[1] = (s16) (s32) ((f32) cmd[5] * var_f22);
                    cmd += 6;
                    break;
                case 0x2F: {
                    f32 x, y, z, a, b, c, d;
                    x = (f32)cmd[0] * 0.00390625f;
                    y = (f32)cmd[1] * 0.00390625f;
                    z = (f32)cmd[2] * 0.00390625f;
                    a = (f32)cmd[3] * 0.00390625f;
                    b = (f32)cmd[4] * 0.00390625f;
                    c = (f32)cmd[5] * 0.00390625f;
                    d = (f32)cmd[6] * 0.00390625f;
                    cmd += 7;
                    func_800EFA4C(((ParticleEmitter *)arg0)->unk6C, x * scale, y * scale, z * scale);
                    func_800EFA4C(((ParticleEmitter *)arg0)->unk60, a * scale, b * scale, c * scale);
                    ((ParticleEmitter *)arg0)->unk5C = d;
                    break;
                }
                case 0x30: {
                    f32 x;
                    x = (f32)cmd[0] * 0.00390625f;
                    cmd += 1;
                    ((ParticleEmitter *)arg0)->unkD0 = x;
                    break;
                }
                case 0x31: {
                    s32 temp_f4_4;
                    temp_f4_4 = func_800DC128(cmd[0], cmd[1]);
                    cmd += 2;
                    ((ParticleEmitter *)arg0)->velocity.box.max[0] = (s16) (((ParticleEmitter *)arg0)->velocity.box.max[0] + (s16) (scale * (f32) temp_f4_4));
                    break;
                }
                case 0x32:
                    ((ParticleEmitter *)arg0)->unk52 = (u8) cmd[0];
                    cmd += 1;
                    break;
                case 0x33:
                    ((ParticleEmitter *)arg0)->unk53 = (u8) cmd[0];
                    cmd += 1;
                    break;
                case 0x34: {
                    s32 i;
                    for (i = 0; i < 4; i++) {
                        ((ParticleEmitter *)arg0)->color[i] = 0xFF;
                    }
                    func_800BA930(arg0, 0, 0, 0, 0, 0, 0);
                    func_800BA450(arg0, 0, 0, 0, 0, 0, 0);
                    func_800BA834((ParticleEmitter *)arg0, 0, 0, 0, 0, 0, 0);
                    break;
                }
                }
                command = *cmd;
                cmd += 1;
            } while (command != 0);
        }
        if (sp17C != 0) {
            func_800BA22C(arg0, sp17C);
        }
    }
    return arg0;
}

BtIntPtr func_800BBCB8(f32 *arg0, f32 *arg1, f32 arg2, s32 arg3, s32 *arg4) {
    BtIntPtr func_800B53A4(s32);
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(arg3);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg0, arg1, arg2, (s16 *)arg4);
    func_800BA22C(sp24, arg3);
    return sp24;
}

/* extern */

void func_800BBD18(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, s32 *arg4) {
    s32 func_800B4790(BtIntPtr);
    if (arg0 != 0) {
        func_800BABB8(arg0, arg1, arg2, arg3, (s16 *)arg4);
        func_800B4790(arg0);
    }
}
