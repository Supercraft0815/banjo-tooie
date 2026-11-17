#include "common.h"

struct anctrl_s;     

void func_80800000_chskeletonexplode(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    f32 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    arg0->unk58 = 0.0f;
    *temp_v0 = 0.0f;
}

/* extern */

void func_80800034_chskeletonexplode(void **arg0) {
    void func_800ADFE0(s16 handle);
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(*arg0) + (0x10)));
    if (temp_a1 != 0) {
        func_800ADFE0(temp_a1);
        (*(s16 *)((s8 *)(*arg0) + (0x10))) = 0;
    }
}

void func_8080007C_chskeletonexplode(Actor *arg0, f32 arg1[3]) {
    void *func_80100094(Actor *, u32);
    f32 func_800D8FF8(void);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern u8 D_80801090_chskeletonexplode[];
    extern u8 D_808010A8_chskeletonexplode[];
    extern u8 D_808010C0_chskeletonexplode[];
    extern u8 D_808010D8_chskeletonexplode[];
    extern u8 D_808010F0_chskeletonexplode[];
    extern u8 D_80801108_chskeletonexplode[];
    extern u8 D_80801120_chskeletonexplode[];
    struct SkeletonExplodeData {
        f32 timer;
        u8 pad4[0xF0];
        u8 sound;
    } *data;

    data = func_80100094(arg0, 1U);
    if (data->timer > 0.0f) {
        data->timer -= func_800D8FF8();
        return;
    }
    switch (data->sound) {
        case 0:
            break;
        case 1:
            _subaddieaudioquick_entrypoint_2(arg0, arg1, D_80801090_chskeletonexplode);
            break;
        case 2:
            _subaddieaudioquick_entrypoint_2(arg0, arg1, D_808010A8_chskeletonexplode);
            break;
        case 3:
            _subaddieaudioquick_entrypoint_2(arg0, arg1, D_808010C0_chskeletonexplode);
            break;
        case 4:
            _subaddieaudioquick_entrypoint_2(arg0, arg1, D_808010D8_chskeletonexplode);
            break;
        case 5:
            _subaddieaudioquick_entrypoint_2(arg0, arg1, D_808010F0_chskeletonexplode);
            break;
        case 6:
            _subaddieaudioquick_entrypoint_2(arg0, arg1, D_80801108_chskeletonexplode);
            break;
        case 7:
            _subaddieaudioquick_entrypoint_2(arg0, arg1, D_80801120_chskeletonexplode);
            break;
    }
    data->timer = 0.25f;
}

void func_808001BC_chskeletonexplode(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void _subaddiefade_entrypoint_3(Actor *);
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    f32 func_800D8FF8(void);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    void func_800EFA20(void *, void *, f32);
    void func_800EFDE8(f32 *, u8 *, f32 *);
    struct SkeletonExplodePart {
    f32 offset[3];
    f32 position[3];
    f32 rotation[3];
    f32 velocity[3];
    f32 unk30[3];
    u8 active;
    u8 pad3D[3];
    }
    *part;
    f32 spB8[3];
    f32 spAC[3];
    f32 spA0[3];
    u32 i;
    f32 sp90[3];
    f32 sp84[3];
    f32 speed;
    s32 finished;
    f32 delta;
    f32 distance;
    f32 length;
    f32 multiplier;
    part = func_80100094(arg0, 0);
    finished = 1;
    delta = func_800D8FF8();
    if (arg0->unk58 < 5.0f) {
    arg0->unk58 += delta;
    }
    else {
    _subaddiefade_entrypoint_3(arg0);
    }
    for (i = 0; i < arg0->unk6C_0; i++) {
    if (part->active != 1) {
    part++;
    continue;
    }
    func_800EFA20(spAC, part->velocity, delta);
    func_800EE780(spB8, part->position, part->offset);
    func_800EF04C(spB8, arg0->position);
    func_800EE7F8(sp90, spB8);
    func_800EE7F8(sp84, sp90);
    func_800EF04C(sp84, spAC);
    func_800EF04C(sp84, spAC);
    if (arg0->position[1] - sp84[1] > 2000.0f) {
    part->active = 2;
    }
    else if (func_800BEF00(sp90, sp84, spA0, 0x20020)) {
    speed = func_800EEF94(part->velocity);
    multiplier = 2.0f;
    length = func_800EEF94(spAC) * multiplier;
    distance = func_800EEAD4(sp90, sp84);
    if (distance < length) {
    func_800EF334(spAC, (distance / length) * 0.9f);
    }
    func_800EFDE8(part->velocity, (void *)part->velocity, spA0);
    func_800EF368(part->velocity, speed * 0.35f);
    func_800EF334(part->unk30, 0.35f);
    if (speed < 250.0f) {
    part->active = 2;
    }
    func_8080007C_chskeletonexplode(arg0, sp84);
    }
    else {
    part->velocity[0] *= 0.95f;
    part->velocity[2] *= 0.95f;
    part->velocity[1] += ((f32 *)arg0->actorData)[7] * func_800D8FF8();
    func_800EF04C(part->rotation, part->unk30);
    func_800EF334(part->unk30, 0.99f);
    }
    func_800EF04C(part->offset, spAC);
    finished = 0;
    part++;
    }
    if (finished) {
    _subaddiefade_entrypoint_3(arg0);
    }
    }

/* extern */

void func_808004DC_chskeletonexplode(Actor *arg0, Actor *arg1, u32 arg2, s32 arg3) {
    s32 func_80103140(Actor *, u32, u16);
    struct SkeletonExplodeFlags {
        u8 pad[0x74];
        u32 pad74_4 : 28;
        u32 unk74_0 : 4;
        u32 pad78_14 : 18;
        u32 unk7A_13 : 2;
        u32 unk7A_11 : 3;
        u32 pad7A_8 : 9;
    };
    struct SkeletonExplodeFlags *dst = (void *)arg0;
    struct SkeletonExplodeFlags *src = (void *)arg1;

    arg0->rotation[0] = arg1->rotation[0];
    arg0->rotation[2] = arg1->rotation[2];
    arg0->rotation[1] = arg1->rotation[1];
    arg0->scale = arg1->scale;
    func_80103140(arg0, (u16)arg2, arg3);
    dst->unk74_0 = src->unk74_0;
    dst->unk7A_11 = src->unk7A_11;
    dst->unk7A_13 = src->unk7A_13;
}

void func_80800594_chskeletonexplode(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x30))) = 15.0f;
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 15.0f;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = 800.0f;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 1000.0f;
    (*(f32 *)((s8 *)(arg0) + (0x34))) = -2000.0f;
}

void func_808005CC_chskeletonexplode(Actor *arg0, void *arg1, f32 *arg2) {
    f32 _dbskeleton_entrypoint_1(void *);
    s32 _dbskeleton_entrypoint_2(u8 *, s32, f32 *);
    s16 _dbskeleton_entrypoint_4(s16 arg0[][8], s32 arg1);
    void *func_8008AEDC(void *);
    void func_8008C200(s16, BtIntPtr, BtIntPtr);
    BtIntPtr func_8008C27C();
    BtUIntPtr func_800ADE50(u8 *, u8 *, s32);
    void *func_800AE080(s16);
    s32 func_800AE124(s16);
    s32 func_800AE630(u8 *, u8 *, s32, f32 *);
    u8 *func_800B27E0(u8 *);
    f32 func_800DC178(f32, f32);
    void func_800DFC20(s32 *, s32, f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF334(f32 *, f32);
    void func_800EF3DC(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800F2C1C();
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    u8 *func_801039E4(Unk80132ED0 *);
    struct anctrl_s *func_80104248(void *);
    struct SkeletonExplodeMarker {
        u8 pad0[0x10];
        s16 animation;
    };
    struct SkeletonExplodePart {
        f32 offset[3];
        f32 position[3];
        f32 rotation[3];
        f32 velocity[3];
        f32 unk30[3];
        u8 active;
        u8 pad3D[3];
    };
    f32 angle;
    f32 pitch;
    u8 *skeleton;
    s32 *animation;
    u32 i;
    s32 bone;
    u8 *matrices;
    struct anctrl_s *control;
    struct SkeletonExplodePart *part;
    f32 sp80[3];
    f32 *position;
    void *anim;
    BtUIntPtr matrix;

    skeleton = func_800B27E0(func_801039E4(arg0->unk0));
    control = func_80104248(arg1);
    anim = func_8008AEDC(control);
    func_8008C200(((struct SkeletonExplodeMarker *)arg0->unk0)->animation, skeleton, anim);
    animation = func_8008C27C(func_8008AEDC(control));
    arg0->unk6C_0 = func_800AE124(((struct SkeletonExplodeMarker *)arg0->unk0)->animation);
    matrices = func_800AE080(((struct SkeletonExplodeMarker *)arg0->unk0)->animation);
    func_80100074(arg0, 0, arg0->unk6C_0 * sizeof(struct SkeletonExplodePart));
    part = func_80100094(arg0, 0);
    for (i = 0; i < arg0->unk6C_0; i++, part++) {
        bone = _dbskeleton_entrypoint_4(skeleton, i);
        matrix = func_800ADE50(matrices, skeleton, bone);
        func_800F2C1C(matrix, part->rotation);
        func_800AE630(matrices, skeleton, bone, part->offset);
        func_800EE780(sp80, arg0->position, part->offset);
        angle = func_800F1DF4(sp80, arg2) - arg0->rotation[1];
        position = part->position;
        _dbskeleton_entrypoint_2(skeleton, bone, position);
        func_800EF3DC(part->offset, position);
        pitch = func_800DC178(-20.0f, 20.0f);
        func_800EEC30(part->velocity, pitch + 130.0f, func_800DC178(-65.0f, 65.0f) + angle, 1000.0f);
        part->active = 1;
    }
    for (i = 0; i < arg0->unk6C_0; i++) {
        part = (struct SkeletonExplodePart *)func_80100094(arg0, 0) + i;
        if (part->active == 4) {
            func_800DFC20(animation, _dbskeleton_entrypoint_4(skeleton, i), part->offset);
            func_800EF334(part->offset, _dbskeleton_entrypoint_1(skeleton));
        }
    }
}

void func_80800894_chskeletonexplode(Actor *arg0, BtIntPtr arg1, f32 *arg2) {
    s32 _dbskeleton_entrypoint_0(u8 *);
    s32 _dbskeleton_entrypoint_2(u8 *, s32, f32 *);
    s16 _dbskeleton_entrypoint_4(s16 arg0[][8], s32 arg1);
    u8 *func_800B27E0(u8 *);
    f32 func_800DC178(f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    u8 *func_801039E4(Unk80132ED0 *);
    struct SkeletonExplodePart {
        f32 offset[3];
        f32 position[3];
        f32 rotation[3];
        f32 velocity[3];
        f32 unk30[3];
        s8 active;
        u8 pad3D[3];
    };
    f32 angle;
    f32 pitch;
    u8 *skeleton;
    u32 i;
    f32 *position;
    struct SkeletonExplodePart *part;
    f32 sp84[3];

    skeleton = func_800B27E0(func_801039E4(arg0->unk0));
    arg0->unk6C_0 = _dbskeleton_entrypoint_0(skeleton);
    func_80100074(arg0, 0, arg0->unk6C_0 * sizeof(struct SkeletonExplodePart));
    part = func_80100094(arg0, 0);
    for (i = 0; i < arg0->unk6C_0; i++, part++) {
        position = part->position;
        _dbskeleton_entrypoint_2(skeleton, _dbskeleton_entrypoint_4(skeleton, i), position);
        func_800EFD24(part->offset);
        func_800EE780(sp84, position, arg0->position);
        angle = func_800F1DF4(sp84, arg2);
        part->rotation[0] = 0.0f;
        part->rotation[1] = arg0->rotation[1];
        part->rotation[2] = 0.0f;
        pitch = func_800DC178(-20.0f, 20.0f);
        func_800EEC30(part->velocity, pitch + 130.0f, func_800DC178(-65.0f, 65.0f) + angle, 1000.0f);
        part->active = 1;
    }
    arg0->rotation[1] = 0.0f;
    arg0->rotation[0] = 0.0f;
    arg0->rotation[2] = 0.0f;
}

void chskeletonexplode_entrypoint_0(Unk80132ED0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s16 func_800AE020(void);
    f32 func_800DC178(f32, f32);
    void func_800EF334(f32 *, f32);
    void *func_80100094(Actor *, u32);
    void func_80101074(void *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    struct anctrl_s *func_80104248(void *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_801084B0(BtIntPtr, Actor **);
    struct SkeletonExplodeMarker {
        u8 pad0[0x10];
        s16 animation;
        u8 pad12[6];
        u16 flags;
    };
    struct SkeletonExplodeData {
        f32 timer;
        s32 count;
        u8 pad8[0xEC];
        u8 sound;
        u8 state;
    };
    struct SkeletonExplodePart {
        f32 offset[3];
        f32 position[3];
        f32 rotation[3];
        f32 velocity[3];
        f32 unk30[3];
        u8 active;
        u8 pad3D[3];
    };
    Actor *actor;
    Actor *source;
    union {
        u32 i;
        Unk80132ED0 *marker;
    } state;
    struct SkeletonExplodeData *data;
    struct SkeletonExplodePart *part;
    f32 position[3];
    Unk80132ED0 **markerRef = &arg0;
    state.marker = *markerRef;

    position[0] = arg1;
    position[1] = arg2;
    position[2] = arg3;
    source = func_80106790(state.marker);
    actor = func_801084B0(0x304, &source);
    source = func_80106790(state.marker);
    data = func_80100094(actor, 1);
    func_808004DC_chskeletonexplode(actor, source, arg4, arg5);
    if (((struct SkeletonExplodeMarker *)actor->unk0)->animation == 0) {
        ((struct SkeletonExplodeMarker *)actor->unk0)->animation = func_800AE020();
    }
    source->unk64_16 = 0;
    func_80800594_chskeletonexplode(actor);
    if (func_80104248(source)) {
        func_808005CC_chskeletonexplode(actor, source, position);
    } else {
        func_80800894_chskeletonexplode(actor, (BtIntPtr)source, position);
    }
    data->count = 0;
    data->sound = 0;
    data->state = 0;
    if (((struct SkeletonExplodeMarker *)state.marker)->flags & 1) {
        func_80101074(actor->unk0);
        func_8010114C((BtIntPtr)state.marker, 0xF, 0);
    }
    part = func_80100094(actor, 0);
    for (state.i = 0; state.i < actor->unk6C_0; state.i++, part++) {
        func_800EF334(part->velocity, func_800DC178(((f32 *)actor->actorData)[4], ((f32 *)actor->actorData)[5]) / 1000.0f);
        part->unk30[0] = func_800DC178(((f32 *)actor->actorData)[6], ((f32 *)actor->actorData)[0]);
        part->unk30[1] = func_800DC178(((f32 *)actor->actorData)[6], ((f32 *)actor->actorData)[0]);
        part->unk30[2] = func_800DC178(((f32 *)actor->actorData)[6], ((f32 *)actor->actorData)[0]);
    }
}                  typedef struct { u8 pad0[0x18]; f32 unk18; u8 pad1C[0xC]; f32 unk28; f32 unk2C; f32 unk30; } Objskeletonexplode_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void chskeletonexplode_entrypoint_1(void *arg0, f32 arg1, f32 arg2) {
    (((Objskeletonexplode_arg0 *)arg0)->unk28) = arg1;
    (((Objskeletonexplode_arg0 *)arg0)->unk2C) = arg2;
}

void chskeletonexplode_entrypoint_2(void *arg0, f32 arg1, f32 arg2) {
    (((Objskeletonexplode_arg0 *)arg0)->unk30) = arg1;
    (((Objskeletonexplode_arg0 *)arg0)->unk18) = arg2;
}    typedef struct { u8 pad0[0x4]; s32 unk4; } Objskeletonexplode_chskeletonexplode_entrypoint_3_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void chskeletonexplode_entrypoint_3(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    (*(s32 *)((s8 *)((temp_v0 + (arg1 * 4))) + (4))) = arg2;
    if ((((Objskeletonexplode_chskeletonexplode_entrypoint_3_temp_v0 *)temp_v0)->unk4) < arg1) {
        (((Objskeletonexplode_chskeletonexplode_entrypoint_3_temp_v0 *)temp_v0)->unk4) = arg1;
    }
}

void chskeletonexplode_entrypoint_4(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 1U)) + (0xF4))) = (s8) arg1;
}

void chskeletonexplode_entrypoint_5(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 1U)) + (0xF5))) = (s8) arg1;
}

void chskeletonexplode_entrypoint_6(s32 *arg0, f32 *arg1, s32 arg2, s32 arg3) {
#ifndef BT_NATIVE
    extern s32 _chskeletonexplode_entrypoint_0;
#endif
    s32 sp[3];
    func_800EE904(sp, arg1);
    _chbaddiesetup_entrypoint_6(&_chskeletonexplode_entrypoint_0, *arg0, sp[0], sp[1], sp[2], arg2, arg3);
}

void chskeletonexplode_entrypoint_7(Actor *arg0, f32 *arg1) {
#ifndef BT_NATIVE
    extern s32 _chskeletonexplode_entrypoint_0;
#endif
    s32 sp[5];

    sp[1] = arg0->unk0->unk14;
    sp[0] = arg0->unk0->unk16;
    func_800EE904(&sp[2], arg1);
    _chbaddiesetup_entrypoint_6(&_chskeletonexplode_entrypoint_0, (BtIntPtr) arg0->unk0, sp[2], sp[3], sp[4], sp[1], sp[0]);
}

void chskeletonexplode_entrypoint_8(Actor **arg0, s16 *arg1) {
#ifndef BT_NATIVE
    extern s32 _chskeletonexplode_entrypoint_0;
#endif
    s32 sp[5];

    sp[1] = ((u16 *)&(*arg0)->unk14)[0];
    sp[0] = ((u16 *)&(*arg0)->unk14)[1];
    sp[2] = arg1[0];
    sp[3] = arg1[1];
    sp[4] = arg1[2];
    _chbaddiesetup_entrypoint_6(&_chskeletonexplode_entrypoint_0, (BtIntPtr) *arg0, sp[2], sp[3], sp[4], sp[1], sp[0]);
}

s32 func_80800E88_chskeletonexplode(Actor *arg0) {
    s16 _dbskeleton_entrypoint_4(s16 arg0[][8], s32 arg1);
    void * func_80019CD4(void);
    void func_800ADD80(s16, u8 *);
    void func_800ADEC4(u8 *, u8 *, s32, f32 [4][4]);
    void *func_800AE080(s16);
    u8 *func_800B27E0(u8 *);
    void func_800DF6BC(s32, s32);
    void func_800DF72C(BtIntPtr);
    void func_800DF758(s32 *);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    u8 *func_801039E4(Unk80132ED0 *);
    void mlMtxGet(void *);
    void mlMtxRotatePYR(f32, f32, f32);
    void mlMtxTranslate(f32, f32, f32);
    struct SkeletonExplodeData {
        f32 timer;
        s32 values[60];
        u8 sound;
        u8 mode;
    } *data;
    struct SkeletonExplodePart {
        f32 offset[3];
        f32 position[3];
        f32 rotation[3];
        f32 velocity[3];
        f32 unk30[3];
        s8 active;
        u8 pad3D[3];
    } *part;
    s32 bone;
    f32 matrix[4][4];
    u8 *skeleton;
    u8 *transforms;
    u32 i;
    struct {
        u32 mode : 8;
    } flags;

    data = func_80100094(arg0, 1);
    skeleton = func_800B27E0(func_801039E4(arg0->unk0));
    part = func_80100094(arg0, 0);
    func_801015D0(arg0);
    func_800ADD80(((s16 *)&arg0->unk0->unk10)[0], skeleton);
    transforms = func_800AE080(((s16 *)&arg0->unk0->unk10)[0]);
    for (i = 0; i < arg0->unk6C_0; i++, part++) {
        bone = _dbskeleton_entrypoint_4(skeleton, i);
        func_80019CD4();
        mlMtxTranslate(part->position[0], part->position[1], part->position[2]);
        mlMtxTranslate(part->offset[0], part->offset[1], part->offset[2]);
        mlMtxRotatePYR(part->rotation[0], part->rotation[1], part->rotation[2]);
        mlMtxTranslate(-part->position[0], -part->position[1], -part->position[2]);
        mlMtxGet(matrix);
        func_800ADEC4(transforms, skeleton, bone, matrix);
    }
    func_800DF72C((BtIntPtr)transforms);
    func_800DF758(data->values);
    flags.mode = data->mode;
    if (flags.mode != 0) {
        func_800DF6BC(flags.mode, arg0->alpha);
    }
    BT_NATIVE_ONLY(return 0;) }

/* extern */

s32 func_8080100C_chskeletonexplode(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 func_80800E88_chskeletonexplode();
    switch (arg1) {
    case 0x1F:
        func_80800E88_chskeletonexplode(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

OSThread *chskeletonexplode_entrypoint_9(void)
{
    extern ActorData D_80801138_chskeletonexplode[];

    return (OSThread *) D_80801138_chskeletonexplode;
}
/* data_to_c.py: from asm/data/overlays/ch/skeletonexplode.data.s */
void func_80105834(Actor*);
void func_801018A4();
void func_80107C2C();
u8 D_80801090_chskeletonexplode [24] BT_DATA(4, overlays_ch_skeletonexplode, 0x0) = { 0, 0x13, 4, 0x15, 0, 0xD, 0, 0xE6, 1, 0, 0, 0x16, 0x1F, 0x40, 0, 1, 5, 0xDC, 9, 0xC4, 0, 0, 0, 0 };
u8 D_808010A8_chskeletonexplode [24] BT_DATA(4, overlays_ch_skeletonexplode, 0x18) = { 0, 0x13, 4, 0x16, 0, 0xD, 0, 0xE6, 1, 0, 0, 0x16, 0x1F, 0x40, 0, 1, 5, 0xDC, 9, 0xC4, 0, 0, 0, 0 };
u8 D_808010C0_chskeletonexplode [24] BT_DATA(4, overlays_ch_skeletonexplode, 0x30) = { 0, 0x13, 4, 0x17, 0, 0xD, 0, 0xE6, 1, 0, 0, 0x16, 0x1F, 0x40, 0, 1, 5, 0xDC, 9, 0xC4, 0, 0, 0, 0 };
u8 D_808010D8_chskeletonexplode [24] BT_DATA(4, overlays_ch_skeletonexplode, 0x48) = { 0, 0x13, 4, 0x5A, 0, 0xD, 0, 0xE6, 1, 0, 0, 0x16, 0x1F, 0x40, 0, 1, 5, 0xDC, 9, 0xC4, 0, 0, 0, 0 };
u8 D_808010F0_chskeletonexplode [24] BT_DATA(4, overlays_ch_skeletonexplode, 0x60) = { 0, 0x13, 4, 0xB, 0, 0xD, 0, 0xF3, 1, 0xC, 0, 0x16, 0x1F, 0x40, 0, 1, 5, 0xDC, 9, 0xC4, 0, 0, 0, 0 };
u8 D_80801108_chskeletonexplode [24] BT_DATA(4, overlays_ch_skeletonexplode, 0x78) = { 0, 0x13, 4, 0x1F, 0, 0xD, 0, 0xF3, 1, 0xC, 0, 0x16, 0x1F, 0x40, 0, 1, 5, 0xDC, 9, 0xC4, 0, 0, 0, 0 };
u8 D_80801120_chskeletonexplode [24] BT_DATA(4, overlays_ch_skeletonexplode, 0x90) = { 0, 0x13, 4, 0xA0, 0, 0xD, 0, 0xF3, 1, 0xC, 0, 0x16, 0x1F, 0x40, 0, 1, 5, 0xDC, 9, 0xC4, 0, 0, 0, 0 };
ActorData D_80801138_chskeletonexplode [1] BT_DATA(4, overlays_ch_skeletonexplode, 0xA8) = { { 708, 772, -1, 1, 0, (void (*)(struct Actor *))func_808001BC_chskeletonexplode, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 0, 0, 0, 128, 1060, (void (*)(struct Actor *))func_80800034_chskeletonexplode, 0, 0, 248, (void (*)(struct Actor *))func_80800000_chskeletonexplode, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32640, 2, (void (*)(struct Actor *, long, long))func_8080100C_chskeletonexplode, 0 } };
