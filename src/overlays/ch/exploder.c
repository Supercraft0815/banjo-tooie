#include "common.h"
#ifdef BT_NATIVE
#include "core2/1EDFED0.h"
#endif

OSThread *chexploder_entrypoint_0(void)
{
    extern ActorData D_80801AE0_chexploder[];

    return (OSThread *) D_80801AE0_chexploder;
}

void func_8080000C_chexploder(s32 arg0) 
{
}
/* extern */

void func_80800014_chexploder(Actor *arg0)
{
    void _subaddiefade_entrypoint_3(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_8010A800(Actor *, s32);
    s32 func_808002FC_chexploder(Actor *);
    if (arg0->unk70_10 == 1 && func_808002FC_chexploder(arg0) == 0) {
        func_80101FDC(arg0, 2);
        _subaddiefade_entrypoint_3(arg0);
        func_8010A800(arg0, 2);
    }
}

/* extern */

void func_80800078_chexploder(void **arg0) {
    void func_800ADFE0(s16 handle);
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(*arg0) + (0x10)));
    if (temp_a1 != 0) {
        func_800ADFE0(temp_a1);
        (*(s16 *)((s8 *)(*arg0) + (0x10))) = 0;
    }
}

s32 func_808000C0_chexploder(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void *func_80100094(Actor *, u32);
    void *func_80101080(void);
    void func_801018A4(Actor *, BtIntPtr);
    s32 func_80103140(Actor *, u32, u16);
    void func_80800154_chexploder(Actor *, BtIntPtr);
    struct {
        u8 pad0[0x14];
        u16 unk14, unk16;
    } *data;

    switch (arg1) {
        case 0xAB:
            func_801018A4(arg0, func_80101080());
            break;
        case 0x1F:
            func_80800154_chexploder(arg0, arg2);
            break;
        case 0x95:
            data = func_80100094(arg0, 0);
            func_80103140(arg0, data->unk14, data->unk16);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800154_chexploder(Actor *arg0, BtIntPtr arg1) {
    void * func_80019CD4(void);
    void func_800ADD80(s16, u8 *);
    void func_800ADEC4(u8 *, u8 *, s32, f32 [4][4]);
    void *func_800AE080(s16);
    u8 *func_800B27E0(u8 *);
    void func_800DF72C(BtIntPtr);
    void func_800DF744(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    void mlMtxGet(void *);
    void mlMtxRotatePYR(f32, f32, f32);
    void mlMtxTranslate(f32, f32, f32);
    f32 inverseScale;
    f32 matrix[4][4];
    u8 *model;
    u8 *animation;
    s32 i;
    struct Part {
        f32 position[3];
        f32 pivot[3];
        f32 unk18[3];
        f32 rotation[3];
        u8 pad30[9];
        u8 index;
        u8 pad3A[2];
    } *part;
    struct Data {
        u8 pad0[0xE];
        s16 count;
        u8 pad10[8];
        u8 visibility[256];
    } *data;
    u8 *visibility;

    animation = func_800B27E0((u8 *)arg1);
    part = func_80100094(arg0, 1);
    data = func_80100094(arg0, 0);
    func_801015D0(arg0);
    func_800ADD80(*(s16 *)&arg0->unk0->unk10, animation);
    model = func_800AE080(*(s16 *)&arg0->unk0->unk10);
    inverseScale = 1.0f / arg0->scale;
    for (i = 0; i < data->count; i++, part++) {
        func_80019CD4();
        mlMtxTranslate(part->pivot[0], part->pivot[1], part->pivot[2]);
        mlMtxTranslate(part->position[0] * inverseScale, part->position[1] * inverseScale, part->position[2] * inverseScale);
        mlMtxRotatePYR(part->rotation[0], part->rotation[1], part->rotation[2]);
        mlMtxTranslate(-part->pivot[0], -part->pivot[1], -part->pivot[2]);
        mlMtxGet(matrix);
        func_800ADEC4(model, animation, part->index, matrix);
    }
    func_800DF72C((BtIntPtr)model);
    for (i = 1, visibility = (u8 *)data + 1; i <= data->visibility[0]; i++, visibility++) {
        func_800DF744(i, visibility[0x18]);
    }
}

s32 func_808002FC_chexploder(Actor *arg0) {
    s32 func_8001210C(s32);
    s32 *func_800BF340(f32 *, f32 *, f32 *, s32, f32);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFA20(void *, void *, f32);
    void func_800EFDE8(f32 *, u8 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_8080067C_chexploder(Actor *, void *, f32 *);
    void func_80800834_chexploder(Actor *, void *, f32 *);
    struct Part {
        f32 position[3], pivot[3], velocity[3], rotation[3];
        s16 spinX, spinZ, gravity;
        BT_BITFIELD_ORDER(u32 noCollision:1, u32 unused : 13);
        BT_BITFIELD_ORDER(u32 active:1, u32 bounce : 1);
        BT_BITFIELD_ORDER(u32 bounce:1, u32 active : 1);
        BT_BITFIELD_ORDER(u32 unused:13, u32 noCollision : 1);
        u8 hits, index;
        u8 pad3A[2];
    };
    struct Data {
        u8 pad0[0xC];
        s16 radius, count, maxHits;
        u8 pad12[0x4A];
        f32 time;
    };
    struct Data *data;
    struct Part *part;
    s32 *hit;
    s32 count;
    f32 normal[3];
    f32 speed;
    f32 dt;
    s32 parity;
    f32 position[3];
    f32 motion[3];
    f32 step[3];
    f32 start[3];
    f32 end[3];
    s32 i;

    data = func_80100094(arg0, 0);
    part = func_80100094(arg0, 1);
    count = 0;
    dt = func_800D8FF8();
    parity = func_8001210C(1);
    data->time += dt;
    for (i = 0; i < data->count; i++, part++) {
        if (part->active) {
            part->rotation[0] += part->spinX * dt;
            part->rotation[2] += part->spinZ * dt;
            part->velocity[1] += dt * part->gravity;
            func_800EFA20(motion, part->velocity, 2.0f * dt);
            func_800EFA20(step, part->velocity, dt);
            func_800EFA20(position, part->pivot, arg0->scale);
            func_800EF04C(position, part->position);
            func_800EF04C(position, arg0->position);
            func_800EE7F8(start, position);
            func_800EE7F8(end, position);
            func_800EF04C(end, motion);
            if (func_800EEB40(end, arg0->position) > 12250000.0f) {
                part->active = 0;
            } else {
                if (!part->noCollision) {
                    hit = parity == (i & 1) ? func_800BF340(start, end, normal, arg0->unk14, data->radius) : NULL;
                    if (hit != NULL) {
                        if (part->bounce) {
                            speed = func_800EEF94(part->velocity);
                            func_800EFDE8(part->velocity, (u8 *)part->velocity, normal);
                            func_800EF368(part->velocity, speed * 0.35f);
                            part->spinX *= 0.35f;
                            part->spinZ *= 0.35f;
                            part->hits++;
                            if (data->maxHits < part->hits || 2.0f * (dt * speed) < 10.0f) {
                                part->active = 0;
                                continue;
                            }
                            func_8080067C_chexploder(arg0, part, end);
                        }
                    } else {
                        if (!part->bounce) {
                            part->bounce = 1;
                        }
                    }
                }
                func_800EF04C(part->position, step);
                func_80800834_chexploder(arg0, part, end);
                count++;
            }
        }
    }
    return count;
}
struct SoundEntry { s16 unk0, unk2, unk4, unk6, unk8; };
void func_8080067C_chexploder(Actor *arg0, void *arg1, f32 *arg2) {
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);



    extern struct SoundEntry D_80801B28_chexploder[];
    extern s32 D_80801BA0_chexploder[4];
    struct {
        u8 pad0[0x12];
        u8 unk12;
        u8 pad13[0x41];
        s16 unk54;
        u8 unk56;
        u8 pad57[5];
        f32 unk5C;
    } *data;
    struct HitData {
        u8 pad0[0x38];
        u8 unk38;
    };
    s32 index;
    s32 sp34;
    s32 sp30;
    f32 sp2C;
    f32 sp28;

    data = func_80100094(arg0, 0);
    if (!(data->unk5C < 0.1f)) {
        if (data->unk12 != 0 && data->unk56 == 0) {
            index = data->unk12 - 1;
            sp34 = D_80801B28_chexploder[index].unk0;
            sp30 = D_80801B28_chexploder[index].unk2;
            sp2C = func_800DC178(D_80801B28_chexploder[index].unk4 * 0.00390625f, D_80801B28_chexploder[index].unk6 * 0.00390625f);
            sp28 = D_80801B28_chexploder[index].unk8 * 0.00390625f;
            func_800C4B7C(sp34);
            func_800C4B64(sp2C - ((f32)((struct HitData *)arg1)->unk38 - 1.0f) * sp28);
            func_800C4B70(sp30 - ((struct HitData *)arg1)->unk38 * 4000 + 4000);
            func_8010D930(7, arg0->unk70_0, arg2, D_80801BA0_chexploder);
            if (data->unk54 & 0x100) {
                data->unk56 = 1;
            }
        }
        data->unk5C = 0.0f;
    }
}

void func_80800834_chexploder(Actor *arg0, void *arg1, f32 arg2[3]) {
    void *func_80100094(Actor *, u32);
    f32 func_800EEFD4(f32 *);
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80801BB0_chexploder[], D_80801BD8_chexploder[];
    extern s32 D_80801BE4_chexploder[], D_80801BF0_chexploder[];
    extern s32 D_80801C00_chexploder[];
    struct {
        u8 pad0[0x13];
        u8 unk13;
        u8 pad14[0x44];
        f32 unk58;
    } *data;
    struct HitData {
        u8 pad0[0x18];
        f32 unk18[3];
        u8 pad24[0x14];
        u8 unk38;
    };
    BtIntPtr sp38;
    BtIntPtr sp34;
    BtIntPtr sp30;
    BtIntPtr sp2C;

    data = func_80100094(arg0, 0);
    if (((struct HitData *)arg1)->unk38 < 3 &&
        !(func_800EEFD4(((struct HitData *)arg1)->unk18) < 90000.0f)) {
        switch (data->unk13) {
        case 1:
            sp38 = func_800B5BE4(0x18);
            func_800BABB8(sp38, arg2, 0, data->unk58, D_80801BB0_chexploder);
            func_800BABB8(sp38, arg2, 0, data->unk58, D_80801BD8_chexploder);
            break;
        case 2:
            sp34 = func_800B5BE4(0x18);
            func_800BABB8(sp34, arg2, 0, data->unk58, D_80801BB0_chexploder);
            func_800BABB8(sp34, arg2, 0, data->unk58, D_80801BE4_chexploder);
            break;
        case 3:
            sp30 = func_800B5BE4(0x18);
            func_800BABB8(sp30, arg2, 0, data->unk58, D_80801BB0_chexploder);
            func_800BABB8(sp30, arg2, 0, data->unk58, D_80801BF0_chexploder);
            break;
        case 4:
            sp2C = func_800B5BE4(0x18);
            func_800BABB8(sp2C, arg2, 0, data->unk58, D_80801BB0_chexploder);
            func_800BABB8(sp2C, arg2, 0, data->unk58, D_80801C00_chexploder);
            break;
        }
    }
}

void func_80800A18_chexploder(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void chexploder_entrypoint_9(Actor *, s32, s32);
    struct {
        s16 unk0, unk2, unk4, unk6, unk8, unkA, unkC, unkE, unk10;
        s8 unk12, unk13, pad14[4], unk18, pad19[0x3F];
        f32 unk58;
    } *data;

    data = func_80100094(arg0, 0);
    data->unk0 = 800;
    data->unk2 = 1000;
    data->unk4 = 200;
    data->unk6 = 300;
    data->unk8 = -1050;
    data->unkA = -950;
    data->unkC = (s32)(arg0->scale * 30.0f);
    data->unk10 = 4;
    data->unk18 = 0;
    data->unk12 = 0;
    data->unk13 = 0;
    data->unk58 = 1.0f;
    chexploder_entrypoint_9(arg0, 1, 0);
    chexploder_entrypoint_9(arg0, 2, 1);
}

BtIntPtr func_80800AC8_chexploder(u8 *arg0, void *arg1, u8 *arg2, s32 arg3) {
    typedef struct { f32 m[4][4]; } MtxF;
    typedef struct { u8 pad0[0x10]; s16 anim; } ExploderMarker;
    void *func_80100094(Actor *, u32);
    u32 *func_80100074(Actor *, u32, u32);
    u8 *func_801039E4(Unk80132ED0 *);
    u8 *func_800B27E0(u8 *);
    void * func_80104248(void *data);
    void *func_8008AEDC(void *);
    void func_8008C238(s16, BtIntPtr, BtIntPtr);
    void func_8008C200(s16, BtIntPtr, BtIntPtr);
    s32 func_800AE124(s16);
    void *func_800AE080(s16);
    s16 _dbskeleton_entrypoint_4(s16 arg0[][8], s32 arg1);
    BtUIntPtr func_800ADE50(u8 *, u8 *, s32);
    s32 func_800AE630(u8 *, u8 *, s32, f32 *);
    void func_800F2C1C(MtxF *, f32 *);
    void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
    void func_800EF334(f32 *, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void func_800EFD24(f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    struct {
        s16 unk0[7], count;
        u8 pad10[0x4C];
        f32 unk5C;
    } *data;
    struct {
        f32 unk0[3], unkC[3], unk18[3], unk24[3];
        s16 unk30, unk32;
        BT_BITFIELD_ORDER(u32 pad34 : 16, u32 rest : 14);
        BT_BITFIELD_ORDER(u32 flag80 : 1, u32 flag40 : 1);
        BT_BITFIELD_ORDER(u32 flag40 : 1, u32 flag80 : 1);
        BT_BITFIELD_ORDER(u32 rest : 14, u32 pad34 : 16);
        u8 unk38, bone, unk3A, unk3B;
    } *part;
    u8 *skeleton;
    u8 *matrices;
    BtIntPtr ctrl;
    s32 i;
    f32 sp6C[3];
    f32 sp60[3];

    data = func_80100094((Actor *)arg0, 0);
    skeleton = func_800B27E0(func_801039E4(((Actor *)arg0)->unk0));
    ctrl = func_80104248(arg1);
    func_8008C238(((ExploderMarker *)((Actor *)arg0)->unk0)->anim, (BtIntPtr)skeleton, (BtIntPtr)func_8008AEDC(ctrl));
    data->count = func_800AE124(((ExploderMarker *)((Actor *)arg0)->unk0)->anim);
    part = (void *)func_80100074((Actor *)arg0, 1, data->count * 0x3C);
    matrices = func_800AE080(((ExploderMarker *)((Actor *)arg0)->unk0)->anim);
    for (i = 0; i < data->count; i++, part++) {
        part->bone = _dbskeleton_entrypoint_4(skeleton, i);
        func_800F2C1C((MtxF *)func_800ADE50(matrices, skeleton, part->bone), part->unk24);
    }
    part = func_80100094((Actor *)arg0, 1);
    func_8008C200(((ExploderMarker *)((Actor *)arg0)->unk0)->anim, (BtIntPtr)skeleton, (BtIntPtr)func_8008AEDC(ctrl));
    matrices = func_800AE080(((ExploderMarker *)((Actor *)arg0)->unk0)->anim);
    for (i = 0; i < data->count; i++, part++) {
        func_800AE630(matrices, skeleton, part->bone, part->unkC);
        func_800EF5A0(sp60, ((Actor *)arg0)->rotation, part->unkC[0], part->unkC[1], part->unkC[2]);
        func_800EF334(sp60, ((Actor *)arg0)->scale);
        func_800EF04C(sp60, ((Actor *)arg0)->position);
        func_800F18FC((f32 *)arg2, sp60, sp6C);
        func_800EFD24(part->unk0);
        func_800EEBF0(part->unk18, sp6C, 1000.0f);
        if (arg3 & 0x10) {
            part->flag80 = 1;
        }
        switch (part->bone) {
        case 3:
            if (arg3 & 0x20) {
                part->flag40 = 1;
            } else {
                part->flag40 = 0;
            }
            break;
        default:
            part->flag40 = 1;
            break;
        }
    }
    data->unk5C = 1e10f;
    func_800EFD24(((Actor *)arg0)->rotation);
    BT_NATIVE_ONLY(return) func_80100094((Actor *)arg0, 1);
}

void func_80800D7C_chexploder(Actor *arg0, BtIntPtr arg1, f32 *arg2, s32 arg3) {
    void *func_80100094(Actor *, u32);
    u32 *func_80100074(Actor *, u32, u32);
    u8 *func_801039E4(Unk80132ED0 *);
    u8 *func_800B27E0(u8 *);
    s32 _dbskeleton_entrypoint_0(u8 *);
    s32 _dbskeleton_entrypoint_2(u8 *, s32, f32 *);
    s16 _dbskeleton_entrypoint_4(s16 arg0[][8], s32 arg1);
    void func_800EFD24(f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    struct {
        s16 unk0[7], count;
        u8 pad10[0x4C];
        f32 unk5C;
    } *data;
    struct {
        f32 unk0[3], unkC[3], unk18[3], unk24[3];
        s16 unk30, unk32;
        BT_BITFIELD_ORDER(u32 pad34 : 16, u32 rest : 14);
        BT_BITFIELD_ORDER(u32 flag80 : 1, u32 flag40 : 1);
        BT_BITFIELD_ORDER(u32 flag40 : 1, u32 flag80 : 1);
        BT_BITFIELD_ORDER(u32 rest : 14, u32 pad34 : 16);
        u8 unk38, bone, unk3A, unk3B;
    } *part;
    u8 *skeleton;
    s32 i;
    f32 sp6C[3];
    f32 sp60[3];

    data = func_80100094(arg0, 0);
    skeleton = func_800B27E0(func_801039E4(arg0->unk0));
    data->count = _dbskeleton_entrypoint_0(skeleton);
    part = (void *)func_80100074(arg0, 1, data->count * 0x3C);
    for (i = 0; i < data->count; i++, part++) {
        part->bone = _dbskeleton_entrypoint_4(skeleton, i);
        _dbskeleton_entrypoint_2(skeleton, part->bone, part->unkC);
        func_800EFD24(part->unk0);
        func_800EE780(sp60, part->unkC, arg0->position);
        func_800F18FC(arg2, sp60, sp6C);
        func_800EEBF0(part->unk18, sp6C, 1000.0f);
        part->unk24[0] = 0.0f;
        part->unk24[1] = arg0->rotation[1];
        part->unk24[2] = 0.0f;
        if (arg3 & 0x10) {
            part->flag80 = 1;
        }
        switch (part->bone) {
        case 3:
            if (arg3 & 0x20) {
                part->flag40 = 1;
            } else {
                part->flag40 = 0;
            }
            break;
        default:
            part->flag40 = 1;
            break;
        }
    }
    data->unk5C = 1e10f;
    func_800EFD24(arg0->rotation);
}

void func_80800F74_chexploder(Actor *arg0, BtIntPtr arg1) {
    void *func_80100094(Actor *, u32);
    f32 func_800DC178(f32, f32);
    void func_800EF368(f32 *, f32);
    struct {
        s16 unk0, unk2, unk4, unk6, unk8, unkA, unkC, unkE;
    } *data;
    struct {
        f32 unk0[6];
        f32 unk18[6];
        s16 unk30, unk32;
        union {
            s16 unk34;
            struct {
                BT_BITFIELD_ORDER(u32 pad : 17, u32 rest : 14);
                u32 active : 1;
                BT_BITFIELD_ORDER(u32 rest : 14, u32 pad : 17);
            } bits;
        } flags;
        s32 unk38;
    } *part;
    f32 *vector;
    s32 i;
    f32 speed, vertical, x, z;

    data = func_80100094(arg0, 0);
    part = func_80100094(arg0, 1);
    for (i = 0; i < data->unkE; i++, part++) {
        if (part->flags.bits.active) {
            speed = func_800DC178(data->unk0, data->unk2);
            vertical = func_800DC178(data->unk8, data->unkA);
            x = func_800DC178(data->unk4, data->unk6);
            z = func_800DC178(data->unk4, data->unk6);
            vector = part->unk18;
            func_800EF368(vector, speed);
            func_800EF368(vector, speed);
            part->flags.unk34 = (s16)vertical;
            part->unk30 = (s16)x;
            part->unk32 = (s16)z;
        }
    }
}

/* extern */

void func_808010E0_chexploder(u8 *arg0, BtIntPtr arg1, s32 arg2) {
    s32 func_80018820(s32, s32, s32);
    s32 func_800E1610(s32, s32, s32, BtIntPtr);
    s32 func_800FFAB0(BtIntPtr);
    if (arg2 & 2) {
        func_800E1610(0, 0x41F00000, 0x3F666666, arg0 + 4);
    }
    if (arg2 & 1) {
        func_80018820(0, 0x40400000, 0x3E800000);
    }
    if ((arg1 != 0) && (arg2 & 8)) {
        func_800FFAB0(arg1);
    }
    if (arg2 & 0x40) {
        (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFFE);
    }
}

void func_80801188_chexploder(u8 *arg0, u8 *arg1, BtIntPtr arg2) {
    u8 * func_800B26F0(u8 *arg0);
    if (func_800B26F0(arg1) != NULL) {
        arg0[0x70] = (u8)((arg0[0x70] & ~1) | 1);
        (*(u8 *)((s8 *)(arg0) + (0x71))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x71))) & 0xFFDF);
    }
}    typedef struct { u8 pad0[0x14]; u16 unk14; u16 unk16; u8 pad18[0x3C]; s16 unk54; } Objexploder_chexploder_entrypoint_1_temp_s1; /* offsets.py genstruct: fields from raw offsets on temp_s1; rename once understood */ typedef struct { void * unk0; u8 pad4[0x34]; f32 unk38; u8 pad3C[0x29]; u8 unk65; } Objexploder_chexploder_entrypoint_1_sp30; /* offsets.py genstruct: fields from raw offsets on sp30; rename once understood */ typedef struct { void * unk0; u8 pad4[0x14]; f32 unk18; f32 unk1C; f32 unk20; u8 pad24[0x14]; f32 unk38; u8 pad3C[0x38]; u8 unk74; } Objexploder_chexploder_entrypoint_1_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void chexploder_entrypoint_1(BT_NATIVE_ONLY(Unk80132ED0 *) BT_IDO_ONLY(s32) arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    s32 pad;
    void func_80800A18_chexploder(Actor *arg0);
    void func_80800D7C_chexploder(Actor *arg0, BtIntPtr arg1, f32 *arg2, s32 arg3);
    void func_80800F74_chexploder(Actor *arg0, BtIntPtr arg1);
    void func_808010E0_chexploder(u8 *arg0, BtIntPtr arg1, s32 arg2);
    void func_80801188_chexploder(u8 *arg0, u8 *arg1, BtIntPtr arg2);
    s16 func_800AE020();
    void func_800EE7F8(f32 *, f32 *);
    void * func_80100094(Actor *, u32);
    s32 func_80101074(void *);
    s32 func_8010108C(void *, s32, BtIntPtr);
    s32 func_80103140(Actor *, u32, u16);
    u8 * func_801039E4(Unk80132ED0 *);
    void * func_80104248(void *data);
    BT_IDO_ONLY(void *func_80106790();)
    u8 *func_801084B0(BtIntPtr, void **);
    s32 func_80108944(u8 *, void *);
    BtIntPtr func_80800AC8_chexploder(u8 *, void *, u8 *, s32);
    void *sp30;
    u8 *temp_v0;
    void *temp_s1;

    sp30 = func_80106790(BT_NATIVE_ONLY(arg0));
    temp_v0 = func_801084B0(0x1FF, &sp30);
    temp_s1 = func_80100094(temp_v0, 0);
    (((Objexploder_chexploder_entrypoint_1_temp_v0 *)temp_v0)->unk18) = arg1;
    (((Objexploder_chexploder_entrypoint_1_temp_v0 *)temp_v0)->unk1C) = arg2;
    (((Objexploder_chexploder_entrypoint_1_temp_v0 *)temp_v0)->unk20) = arg3;
    func_800EE7F8(temp_v0 + 0x44, (u8 *)(u8 *)sp30 + 0x44);
    (((Objexploder_chexploder_entrypoint_1_temp_v0 *)temp_v0)->unk38) = (f32) (((Objexploder_chexploder_entrypoint_1_sp30 *)sp30)->unk38);
    if ((*(s16 *)((s8 *)((((Objexploder_chexploder_entrypoint_1_temp_v0 *)temp_v0)->unk0)) + (0x10))) == 0) {
        (*(s16 *)((s8 *)((((Objexploder_chexploder_entrypoint_1_temp_v0 *)temp_v0)->unk0)) + (0x10))) = func_800AE020();
    }
    (((Objexploder_chexploder_entrypoint_1_temp_s1 *)temp_s1)->unk14) = (u16) (*(u16 *)((s8 *)((((Objexploder_chexploder_entrypoint_1_sp30 *)sp30)->unk0)) + (0x14)));
    (((Objexploder_chexploder_entrypoint_1_temp_s1 *)temp_s1)->unk16) = (u16) (*(u16 *)((s8 *)((((Objexploder_chexploder_entrypoint_1_sp30 *)sp30)->unk0)) + (0x16)));
    (((Objexploder_chexploder_entrypoint_1_temp_s1 *)temp_s1)->unk54) = (s16) arg4;
    (((Objexploder_chexploder_entrypoint_1_sp30 *)sp30)->unk65) = (u8) ((((Objexploder_chexploder_entrypoint_1_sp30 *)sp30)->unk65) & 0xFFFE);
    func_80108944(temp_v0, sp30);
    func_80801188_chexploder(temp_v0, func_801039E4((((Objexploder_chexploder_entrypoint_1_sp30 *)sp30)->unk0)), (BtIntPtr) sp30);
    (((Objexploder_chexploder_entrypoint_1_temp_v0 *)temp_v0)->unk74) = (u8) ((((Objexploder_chexploder_entrypoint_1_temp_v0 *)temp_v0)->unk74) & 0xFFFD);
    func_80103140(temp_v0, (((Objexploder_chexploder_entrypoint_1_temp_s1 *)temp_s1)->unk14), (((Objexploder_chexploder_entrypoint_1_temp_s1 *)temp_s1)->unk16));
    func_80800A18_chexploder((Actor *) temp_v0);
    if (func_80104248(sp30) != 0) {
        func_80800AC8_chexploder(temp_v0, sp30, temp_v0 + 0x18, arg4);
    } else {
        func_80800D7C_chexploder((Actor *) temp_v0, (BtIntPtr) sp30, (f32 *) (temp_v0 + 0x18), arg4);
    }
    func_80101074((((Objexploder_chexploder_entrypoint_1_temp_v0 *)temp_v0)->unk0));
    func_8010108C(sp30, 0x90, (((Objexploder_chexploder_entrypoint_1_temp_s1 *)temp_s1)->unk14));
    func_80800F74_chexploder((Actor *) temp_v0, (BtIntPtr) sp30);
    func_808010E0_chexploder(temp_v0, (BtIntPtr) sp30, arg4);
}

void chexploder_entrypoint_2(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    struct ExploderFlags {
        u8 pad0[0x74];
        BT_BITFIELD_ORDER(u8 pad74_7 : 6, u8 pad74_0 : 1);
        u8 flag74_1 : 1;
        BT_BITFIELD_ORDER(u8 pad74_0 : 1, u8 pad74_7 : 6);
    };
    s32 func_8010108C(void *, s32, BtIntPtr);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101038(f32 *);
    s32 func_80101074(void *);
    s32 func_80103140(Actor *, u32, u16);
    u8 *func_801039E4(Unk80132ED0 *);
    void * func_80104248(void *data);
    BT_IDO_ONLY(void *func_80106790();)
    Actor *func_80108474(u32, f32 *, s32);
    s32 func_80108944(u8 *, void *);
    f32 position[3];
    f32 rotation;
    Actor *parent;
    Actor *actor;
    f32 *origin;
    s32 id;
    f32 scale;
    struct {
        u8 pad0[0x14];
        u16 unk14, unk16;
        u8 pad18[0x3C];
        s16 unk54;
    } *data;

    id = ((s16 *)&arg1)[0];
    position[0] = ((s16 *)&arg1)[1];
    position[1] = ((s16 *)&arg2)[0];
    position[2] = ((s16 *)&arg2)[1];
    rotation = *(f32 *)&arg3;
    scale = *(f32 *)&arg4;
    parent = *(Actor **)&arg0;
    actor = func_80108474(0x1FF, position, (s32)rotation);
    data = func_80100094(actor, 0);
    if (parent != NULL) {
        parent = func_80106790(BT_NATIVE_ONLY((Unk80132ED0 *))parent);
    } else {
        parent = NULL;
    }
    actor->scale = scale;
    origin = (f32 *)actor->actorData;
    func_800EE7F8(origin, actor->position);
    if (parent != NULL) {
        func_80101074(actor->unk0);
        if (func_8010108C(parent, 0x8D, id) > 0) {
            func_80101038(origin);
        }
    }
    data->unk14 = id;
    data->unk16 = 0;
    data->unk54 = arg5;
    if (parent != NULL) {
        func_80108944((u8 *)actor, parent);
        ((struct ExploderFlags *)actor)->flag74_1 = 0;
    }
    func_80103140(actor, data->unk14, data->unk16);
    func_80801188_chexploder((u8 *)actor, func_801039E4(actor->unk0), (BtIntPtr)parent);
    func_80800A18_chexploder(actor);
    if (parent != NULL && (arg5 & 0x80) && func_80104248(parent) != 0) {
        func_80800AC8_chexploder((u8 *)actor, parent, (u8 *)origin, arg5);
    } else {
        func_80800D7C_chexploder(actor, 0, origin, arg5);
    }
    if (parent != NULL) {
        func_80101074(actor->unk0);
        func_8010108C(parent, 0x90, data->unk14);
    }
    func_80800F74_chexploder(actor, (BtIntPtr)parent);
    func_808010E0_chexploder((u8 *)actor, (BtIntPtr)parent, arg5);
}

void chexploder_entrypoint_3(Actor *arg0, f32 *arg1, s32 arg2) {
    void func_800EE7F8(f32 *, f32 *);
    void func_80103DFC(Actor *, f32 *);
    void func_8010A570(Actor *);
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
#ifndef BT_NATIVE
    extern s32 _chexploder_entrypoint_1;
#endif
    union {
        f32 vec[3];
        s32 words[3];
    } sp24;

    if (arg1 != NULL) {
        func_800EE7F8(sp24.vec, arg1);
    } else {
        func_80103DFC(arg0, sp24.vec);
    }
    if (arg2 & 4) {
        func_8010A570(arg0);
    }
    _chbaddiesetup_entrypoint_5(&_chexploder_entrypoint_1, (BtIntPtr)arg0->unk0,
        sp24.words[0], sp24.words[1], sp24.words[2], arg2);
}

/* extern */

void chexploder_entrypoint_4(Actor *arg0, s16 *arg1, s32 arg2) {
    void func_800EE88C(f32 dst[3], s16 src[3]);
    void chexploder_entrypoint_3(Actor *, f32 *, s32);
    f32 sp1C[3];

    func_800EE88C(sp1C, arg1);
    chexploder_entrypoint_3(arg0, sp1C, arg2);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) chexploder_entrypoint_5(Actor *arg0, s32 arg1, f32 *arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, BtIntPtr, BtIntPtr, s32, s32, s32, BtIntPtr);
    void func_8010A570(Actor *);
#ifndef BT_NATIVE
    extern s32 _chexploder_entrypoint_2;
#endif
    union {
        struct { s16 first, second; } half;
        s32 word;
    } sp34, sp30;
    volatile BtIntPtr sp2C;

    if (arg0 != NULL) {
        sp2C = (BtIntPtr)arg0->unk0;
    } else {
        sp2C = 0;
    }
    sp34.half.first = arg1;
    sp34.half.second = (s32)arg2[0];
    sp30.half.first = (s32)arg2[1];
    sp30.half.second = (s32)arg2[2];
    if (arg5 & 4) {
        func_8010A570(arg0);
    }
    BT_NATIVE_ONLY(return) _chbaddiesetup_entrypoint_6(&_chexploder_entrypoint_2, sp2C, sp34.word, sp30.word, arg3, arg4, arg5);
}    typedef struct { s16 unk0; s16 unk2; } Objexploder_chexploder_entrypoint_6_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void chexploder_entrypoint_6(Actor *arg0, f32 arg1, f32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (((Objexploder_chexploder_entrypoint_6_temp_v0 *)temp_v0)->unk0) = (s16) (s32) arg1;
    (((Objexploder_chexploder_entrypoint_6_temp_v0 *)temp_v0)->unk2) = (s16) (s32) arg2;
}    typedef struct { u8 pad0[0x8]; s16 unk8; s16 unkA; } Objexploder_chexploder_entrypoint_7_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void chexploder_entrypoint_7(Actor *arg0, f32 arg1, f32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (((Objexploder_chexploder_entrypoint_7_temp_v0 *)temp_v0)->unk8) = (s16) (s32) arg1;
    (((Objexploder_chexploder_entrypoint_7_temp_v0 *)temp_v0)->unkA) = (s16) (s32) arg2;
}    typedef struct { u8 pad0[0x4]; s16 unk4; s16 unk6; } Objexploder_chexploder_entrypoint_8_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void chexploder_entrypoint_8(Actor *arg0, f32 arg1, f32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (((Objexploder_chexploder_entrypoint_8_temp_v0 *)temp_v0)->unk4) = (s16) (s32) arg1;
    (((Objexploder_chexploder_entrypoint_8_temp_v0 *)temp_v0)->unk6) = (s16) (s32) arg2;
}    typedef struct { u8 pad0[0x18]; u8 unk18; } Objexploder_chexploder_entrypoint_9_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void chexploder_entrypoint_9(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s8 *)((s8 *)((temp_v0 + arg1)) + (0x18))) = (s8) arg2;
    if ((s32) (((Objexploder_chexploder_entrypoint_9_temp_v0 *)temp_v0)->unk18) < arg1) {
        (((Objexploder_chexploder_entrypoint_9_temp_v0 *)temp_v0)->unk18) = (u8) arg1;
    }
}

void chexploder_entrypoint_10(Actor *arg0, s16 *arg1) {
    void *func_80100094(Actor *, u32);
    u8 *sp24;
    s16 *var_v0;
    s32 var_a3;
    s32 var_t0;
    struct {
        u8 pad0[0x36];
        BT_BITFIELD_ORDER(u8 unk36_7 : 1, u8 unk36_0 : 6);
        u8 unk36_6 : 1;
        BT_BITFIELD_ORDER(u8 unk36_0 : 6, u8 unk36_7 : 1);
        u8 pad37[2];
        u8 unk39;
        u8 pad3A[2];
    } *var_a2;

    sp24 = func_80100094(arg0, 0U);
    var_a2 = func_80100094(arg0, 1U);
    var_a3 = 0;
    if (*(s16 *)(sp24 + 0xE) > 0) {
        do {
            var_t0 = 0;
            if (*arg1 != -1) {
                var_v0 = arg1;
                do {
                    if (var_a2->unk39 == *var_v0) {
                        var_t0 = 1;
                        break;
                    }
                    var_v0++;
                } while (*var_v0 != -1);
            }
            var_a2->unk36_6 = var_t0;
            var_a3++;
            var_a2++;
        } while (var_a3 < *(s16 *)(sp24 + 0xE));
    }
}

void chexploder_entrypoint_11(Actor *arg0, s16 *arg1) {
    void *func_80100094(Actor *, u32);
    u8 *sp24;
    s16 *var_v0;
    s32 var_a3;
    u8 *var_a2;

    sp24 = func_80100094(arg0, 0U);
    var_a2 = func_80100094(arg0, 1U);
    var_a3 = 0;
    if (*(s16 *)(sp24 + 0xE) > 0) {
        do {
            var_a3 += 1;
            if (*arg1 != -1) {
                var_v0 = arg1;
                do {
                    if (var_a2[0x39] == *var_v0) {
                        var_a2[0x36] &= 0xFFBF;
                        break;
                    }
                    var_v0++;
                } while (*var_v0 != -1);
            }
            var_a2 += 0x3C;
        } while (var_a3 < *(s16 *)(sp24 + 0xE));
    }
}

void chexploder_entrypoint_12(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0xC))) = (s16) (s32) (arg0->scale * (f32) arg1);
}

void chexploder_entrypoint_13(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0U)) + (0x12))) = (s8) arg1;
}

void chexploder_entrypoint_14(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0x10))) = (s16) arg1;
}    typedef struct { u8 pad0[0x13]; s8 unk13; u8 pad14[0x44]; f32 unk58; } Objexploder_chexploder_entrypoint_15_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void chexploder_entrypoint_15(Actor *arg0, s32 arg1, f32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (((Objexploder_chexploder_entrypoint_15_temp_v0 *)temp_v0)->unk13) = (s8) arg1;
    (((Objexploder_chexploder_entrypoint_15_temp_v0 *)temp_v0)->unk58) = arg2;
}

void chexploder_entrypoint_16(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 func_80103140(Actor*, u32, u16);
    struct { u8 pad[0x14]; u16 id; u16 next; } *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    temp_v0->id = arg1;
    func_80103140(arg0, temp_v0->id, temp_v0->next);
}
/* data_to_c.py: from asm/data/overlays/ch/exploder.data.s */
void func_80102EC0();
void func_801018A4 ( Actor * , BtIntPtr );
void func_80107C2C();
ActorData D_80801AE0_chexploder [1] BT_DATA(4, overlays_ch_exploder, 0x0) = { { 344, 511, -1, 1, 0, (void (*)(struct Actor *))func_80800014_chexploder, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_801018A4, 29999, 0, 0, 0, 0, 1056, (void (*)(struct Actor *))func_80800078_chexploder, 0, 96, 0, (void (*)(struct Actor *))func_8080000C_chexploder, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32640, 9218, (void (*)(struct Actor *, long, long))func_808000C0_chexploder, 0 } };
struct SoundEntry D_80801B28_chexploder [12] BT_DATA(4, overlays_ch_exploder, 0x48) = { { 1184, 25000, 256, 256, 6 }, { 1045, 25000, 256, 256, 6 }, { 1046, 25000, 256, 256, 6 }, { 1047, 25000, 256, 256, 6 }, { 1577, 18000, 179, 179, 6 }, { 1047, 18000, 256, 256, 25 }, { 1473, 18000, 256, 256, 6 }, { 1473, 12000, 256, 256, 25 }, { 1113, 25000, 256, 256, 25 }, { 1688, 25000, 243, 268, 0 }, { 1300, 28000, 179, 179, 0 }, { 0, 0, 0, 0, 0 } };
s32 D_80801BA0_chexploder[4] BT_DATA(4, overlays_ch_exploder, 0xC0) = { 2162689, 81922500, 1900574, 0 };
s32 D_80801BB0_chexploder [10] BT_DATA(4, overlays_ch_exploder, 0xD0) = { 1903069, 1442304, 917514, 1310754, 15925516, 7536780, 1376281, 11730987, 8388761, 0 };
s32 D_80801BD8_chexploder [3] BT_DATA(4, overlays_ch_exploder, 0xF8) = { 2088615, 1895825690, 0 };
s32 D_80801BE4_chexploder [3] BT_DATA(4, overlays_ch_exploder, 0x104) = { 2146496, -1061158630, 0 };
s32 D_80801BF0_chexploder [4] BT_DATA(4, overlays_ch_exploder, 0x110) = { 2113791, 1086325018, 1376281, 8388608 };
s32 D_80801C00_chexploder [4] BT_DATA(4, overlays_ch_exploder, 0x120) = { 2113600, 1086325018, 0, 0 };
