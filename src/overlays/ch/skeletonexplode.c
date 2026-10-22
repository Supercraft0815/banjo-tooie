#include "common.h"

void func_80800000_chskeletonexplode(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    f32 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    arg0->unk58 = 0.0f;
    *temp_v0 = 0.0f;
}

/* extern */

void func_80800034_chskeletonexplode(void **arg0) {
    s32 func_800ADFE0(s16);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_808001BC_chskeletonexplode.s")

/* extern */

void func_808004DC_chskeletonexplode(Actor *arg0, Actor *arg1, u16 arg2, s32 arg3) {
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
    func_80103140(arg0, arg2, arg3);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/func_808005CC_chskeletonexplode.s")

void func_80800894_chskeletonexplode(Actor *arg0, s32 arg1, f32 *arg2) {
    s32 _dbskeleton_entrypoint_0(u8 *);
    s32 _dbskeleton_entrypoint_2(u8 *, s32, f32 *);
    s32 _dbskeleton_entrypoint_4(u8 *, u32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/skeletonexplode/chskeletonexplode_entrypoint_0.s")

void chskeletonexplode_entrypoint_1(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x28))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = arg2;
}

void chskeletonexplode_entrypoint_2(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x30))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x18))) = arg2;
}

void chskeletonexplode_entrypoint_3(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    (*(s32 *)((s8 *)((temp_v0 + (arg1 * 4))) + (4))) = arg2;
    if ((*(s32 *)((s8 *)(temp_v0) + (4))) < arg1) {
        (*(s32 *)((s8 *)(temp_v0) + (4))) = arg1;
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
    extern s32 _chskeletonexplode_entrypoint_0;
    s32 sp[3];
    func_800EE904(sp, arg1);
    _chbaddiesetup_entrypoint_6(&_chskeletonexplode_entrypoint_0, *arg0, sp[0], sp[1], sp[2], arg2, arg3);
}

void chskeletonexplode_entrypoint_7(Actor *arg0, f32 *arg1) {
    extern s32 _chskeletonexplode_entrypoint_0;
    s32 sp[5];

    sp[1] = arg0->unk0->unk14;
    sp[0] = arg0->unk0->unk16;
    func_800EE904(&sp[2], arg1);
    _chbaddiesetup_entrypoint_6(&_chskeletonexplode_entrypoint_0, (s32) arg0->unk0, sp[2], sp[3], sp[4], sp[1], sp[0]);
}

void chskeletonexplode_entrypoint_8(Actor **arg0, s16 *arg1) {
    extern s32 _chskeletonexplode_entrypoint_0;
    s32 sp[5];

    sp[1] = ((u16 *)&(*arg0)->unk14)[0];
    sp[0] = ((u16 *)&(*arg0)->unk14)[1];
    sp[2] = arg1[0];
    sp[3] = arg1[1];
    sp[4] = arg1[2];
    _chbaddiesetup_entrypoint_6(&_chskeletonexplode_entrypoint_0, (s32) *arg0, sp[2], sp[3], sp[4], sp[1], sp[0]);
}

s32 func_80800E88_chskeletonexplode(Actor *arg0) {
    s32 _dbskeleton_entrypoint_4(u8 *, u32);
    s32 func_80019CD4(void);
    void func_800ADD80(s16, u8 *);
    void func_800ADEC4(u8 *, u8 *, s32, f32 [4][4]);
    void *func_800AE080(s16);
    u8 *func_800B27E0(u8 *);
    void func_800DF6BC(s32, s32);
    void func_800DF72C(s32);
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
    func_800DF72C((s32)transforms);
    func_800DF758(data->values);
    flags.mode = data->mode;
    if (flags.mode != 0) {
        func_800DF6BC(flags.mode, arg0->alpha);
    }
}

/* extern */

s32 func_8080100C_chskeletonexplode(s32 arg0, s32 arg1, s32 arg2) {
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
    extern u8 D_80801138_chskeletonexplode[];

    return (OSThread *) D_80801138_chskeletonexplode;
}
