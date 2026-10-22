#include "su/coasterfly.h"

OSThread *sucoasterfly_entrypoint_0(void)
{
    extern u8 D_80802280_sucoasterfly[];

    return (OSThread *) D_80802280_sucoasterfly;
}

s32 sucoasterfly_entrypoint_1(Actor *arg0, s32 arg1) {
    u32 *func_80100074(Actor *, u32, u32);
    s32 _sucoasterflydata_entrypoint_0(Actor *);
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    s32 func_80801FE4_sucoasterfly(Actor *, f32 *, f32, f32);
    struct CoasterFlyData {
        f32 position[3];
        f32 unkC;
        u8 unk10;
        u8 variant : 4;
        u8 flags : 4;
        s16 unk12;
        s32 unk14;
        s16 height;
        s16 unk1A;
    } *data;
    f32 groundY;

    data = (struct CoasterFlyData *)func_80100074(arg0, 0, arg1 + 0x1C);
    data->variant = _sucoasterflydata_entrypoint_0(arg0);
    _subaddierouteDll_entrypoint_3(arg0, data, arg0->position);
    data->unkC = 0.0f;
    groundY = arg0->position[1] - 400.0f;
    func_80801FE4_sucoasterfly(arg0, &groundY, 50.0f, -1500.0f);
    data->height = (s32)(arg0->position[1] - groundY);
    return 1;
}

void sucoasterfly_entrypoint_2(Actor* arg0)
{
    func_80802128_sucoasterfly(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/sucoasterfly_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/sucoasterfly_entrypoint_4.s")

void func_80800EF0_sucoasterfly(Unk80132ED0 *arg0, u8 *arg1)
{
  Actor *func_80106790(Unk80132ED0 *);
  s32 func_808014AC_sucoasterfly(Actor *, s32);
  Actor *temp_a0;
  Actor *temp_v0;
  temp_v0 = func_80106790(arg0);
  temp_a0 = temp_v0;
  if (((((u32) ((*((u32 *) (((s8 *) arg1) + 0x24))) ^ 0)) >> 0x16) == 0) && (((((u16) (*((u16 *) (((s8 *) temp_v0) + 0x72)))) & 0xFFFFFFFF) >> 0xA) == 6))
  {
    func_808014AC_sucoasterfly(temp_a0, 7);
  }
}

/* extern */

void func_80800F44_sucoasterfly(Unk80132ED0 *arg0, s32 arg1) {
    int func_801021BC(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    Actor *temp_v0;
    Actor *sp1C;
    u32 flags;

    temp_v0 = func_80106790(arg0);
    if (temp_v0->unk70_10 != 0xA) {
        flags = temp_v0->pad7A_0;
        if (((s32)(flags << 29) >> 31) == 0) {
        sp1C = temp_v0;
        if (func_801021BC(temp_v0, 0xA) != 0) {
            func_808014AC_sucoasterfly(sp1C, 0xA);
        }
        }
    }
}

void func_80800FA8_sucoasterfly(Unk80132ED0 *arg0, Unk80132ED0 *arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    s32 _sueggmisc_entrypoint_0();
    void _suegg_entrypoint_19(Actor *, f32 *);
    f32 func_800D8FF8(void);
    f32 func_800EEF94(f32 *);
    f32 func_800EEFD4(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFD24(f32 *);
    void func_800F5A00(s32, f32 *);
    void func_800F5D70(s32, f32 *);
    Actor *actor;
    f32 velocity[3];
    f32 position[4];

    actor = func_80106790(arg0);
    if (_sueggmisc_entrypoint_0(arg1) != 0) {
        _suegg_entrypoint_19(func_80106790(arg1), velocity);
        func_800EF334(velocity, 1.0f / func_800D8FF8());
        if (func_800EEF94(velocity) > 400.0f) {
            func_800EF368(velocity, 400.0f);
        }
    } else if ((arg1->unk24 >> 22) == 0) {
        func_800F5D70((u32)((u16 *)&arg1->unk18)[1] >> 5, velocity);
        if (func_800EEFD4(velocity) < 100.0f) {
            func_800F5A00((u32)((u16 *)&arg1->unk18)[1] >> 5, position);
            func_800EFB24(velocity, actor->position, position);
            func_800EF368(velocity, 200.0f);
            velocity[1] += 150.0f;
        }
    } else {
        func_800EFD24(velocity);
    }
    func_808014AC_sucoasterfly(actor, 0xB);
    func_800EF04C(&((f32 *)actor->actorData)[4], velocity);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801108_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_808014AC_sucoasterfly.s")

void *func_80100094(Actor *, u32);

void func_8080181C_sucoasterfly(Actor *arg0) {
    f32 func_800F0E00(f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_80107C00(void);
    f32 *sp1C;
    volatile f32 sp18;
    f32 speed;
    f32 current;
    f32 initial;

    sp1C = func_80100094(arg0, 0);
    initial = sp1C[3];
    current = ((f32 *)arg0->actorData)[3];
    if (initial < current) {
        speed = func_800F0E00(current, 10.0f);
    } else {
        speed = initial;
    }
    sp18 = speed * 0.1f;
    ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], sp1C[3], func_80107C00() * sp18);
}

void func_808018BC_sucoasterfly(Actor *arg0) {
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    f32 func_800F0E00(f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_80107C00(void);
    struct CoasterFlyActorFlags {
        u8 pad0[0x64];
        u32 pad64 : 2;
        u32 disabled : 1;
        u32 remaining64 : 29;
    };
    f32 *sp2C;
    volatile f32 sp28;
    f32 scale;
    f32 speed;
    f32 current;
    f32 initial;

    sp2C = func_80100094(arg0, 0);
    if (((struct CoasterFlyActorFlags *)arg0)->disabled) {
        scale = _subaddiejoy_entrypoint_9(arg0, NULL, 0);
    } else {
        scale = 1.0f;
    }
    initial = sp2C[3];
    current = ((f32 *)arg0->actorData)[3];
    if (initial < current) {
        speed = func_800F0E00(current, 10.0f);
    } else {
        speed = initial;
    }
    sp28 = speed * 0.1f;
    ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], sp2C[3] * scale, func_80107C00() * sp28);
}

/* extern */

void func_808019A0_sucoasterfly(Actor *arg0) {
    void func_800EEB9C(f32[3], f32, f32);
    f32 func_800F0D50(f32, f32, f32);
    void func_80102924(void *, f32);
    s32 func_8010B990(Actor *, s32);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    void func_808018BC_sucoasterfly(Actor *);
    f32 func_80801E5C_sucoasterfly();
    f32 sp24;
    s32 sp20;

    sp24 = func_80801E5C_sucoasterfly();
    sp20 = (arg0->unk64_29) ? 0x404027 : 0x504327;
    func_808018BC_sucoasterfly(arg0);
    func_800EEB9C(&((f32 *)arg0->actorData)[4], arg0->rotation[1], ((f32 *)arg0->actorData)[3]);
    ((f32 *)arg0->actorData)[5] = func_800F0D50(sp24 - arg0->position[1], -300.0f, 300.0f);
    if ((func_8010B990(arg0, sp20) & 0x24) && !(arg0->unk64_29)) {
        func_80102924(arg0, arg0->rotation[1] + 180.0f);
        func_808014AC_sucoasterfly(arg0, 2);
    }
}

/* extern */

void func_80801A80_sucoasterfly(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F5BF0(s32, s32);
    func_800F5BF0(func_800F54E4(), arg0 + 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801AB0_sucoasterfly.s")

/* extern */

s32 func_80801B90_sucoasterfly(Actor *arg0) {
    s32 _suchase_entrypoint_1(Actor *);
    s32 func_8010C500(Actor *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    struct CoasterFlyActorFlags {
        u8 pad0[0x64];
        u32 pad64 : 2;
        u32 disabled : 1;
        u32 remaining64 : 29;
    };
    s32 var_v1 = 0;
    struct {
        u32 unk0[4];
        u32 pad10 : 12;
        u32 unk10_19 : 1;
        u32 unk10_0 : 19;
    } *data;

    if (((struct CoasterFlyActorFlags *)arg0)->disabled) {
        return 0;
    }
    if (func_8010C500(arg0) == 0) {
        var_v1 = 1;
    }
    if (var_v1 == 0) {
        if (_suchase_entrypoint_1(arg0) == 0) {
            var_v1 += 1;
        }
    }
    if (var_v1 != 0) {
        data = func_80100094(arg0, 0U);
        func_808014AC_sucoasterfly(arg0, data->unk10_19 ? 7 : 1);
    }
    return var_v1;
}

void func_80801C44_sucoasterfly(Actor *arg0, s32 arg1) {
    void *_sucoasterflydata_entrypoint_1(u32);
    s32 func_80101E14(Actor *, f32);
    void func_80801CD0_sucoasterfly(Actor *, s32);
    struct CoasterFlyData {
        u8 pad0[0x11];
        u8 track;
    } *data;
    struct CoasterFlyParameters {
        s16 pad0[2];
        struct {
            s16 enabled;
            s16 pad2[2];
            s16 fraction;
        } entries[1];
    } *parameters;

    data = func_80100094(arg0, 0U);
    parameters = _sucoasterflydata_entrypoint_1((u32)data->track >> 4);
    if (parameters->entries[arg1].enabled != 0 &&
        func_80101E14(arg0, (f32)parameters->entries[arg1].fraction * 0.00390625f) != 0) {
        func_80801CD0_sucoasterfly(arg0, arg1);
    }
}

void func_80801CD0_sucoasterfly(Actor *arg0, s32 arg1) {
    void *_sucoasterflydata_entrypoint_1(u32);
    void func_8010D640(f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800DC178(f32, f32);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern u8 D_808022BC_sucoasterfly[];
    struct CoasterFlyData {
        u8 pad0[0x11];
        u8 track;
    };
    struct SoundParameters {
        s16 id;
        s16 volume;
        s16 pitch;
        s16 pad;
    };
    f32 pitch;
    u8 *sp38;
    struct CoasterFlyData *data;
    f32 sp28[3];

    data = func_80100094(arg0, 0U);
    sp38 = _sucoasterflydata_entrypoint_1((u32)data->track >> 4);
    if (((struct SoundParameters *)(sp38 + 4))[arg1].id != 0) {
        func_8010D640(sp28);
        if (!(func_800EEB40(sp28, arg0->position) >= 9000000.0f)) {
            pitch = func_800DC178(-0.05f, 0.05f);
            pitch += (f32)((struct SoundParameters *)(sp38 + 4))[arg1].pitch * 0.00390625f;
            func_800C4B64(pitch);
            func_800C4B7C(((struct SoundParameters *)(sp38 + 4))[arg1].id);
            func_800C4B70(((struct SoundParameters *)(sp38 + 4))[arg1].volume);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808022BC_sucoasterfly);
        }
    }
}

s32 func_80801DD0_sucoasterfly(Actor *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    int func_800F20BC(f32, f32, f32);
    int func_801021BC(Actor *, s32);
    f32 func_8010CD28(Actor *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);

    if (func_800F20BC(arg0->rotation[1], func_8010CD28(arg0), 20.0f) != 0 &&
        _subaddiejoy_entrypoint_6((u8 *)arg0, 1) == 1) {
        if (func_801021BC(arg0, 5) != 0) {
            func_808014AC_sucoasterfly(arg0, 5);
            return 1;
        }
        func_808014AC_sucoasterfly(arg0, 6);
        return 1;
    }
    return 0;
}

f32 func_80801E5C_sucoasterfly(Actor *arg0) {
    void func_8008FE94(s32, f32 *);
    s32 func_800CC338(f32 *, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    int func_80104544();
    f32 func_8010473C(Actor *, f32 *);
    s32 func_80801FE4_sucoasterfly(Actor *, f32 *, f32, f32);
    struct CoasterFlyActorFlags {
        u8 pad0[0x70];
        u32 section : 7;
        u32 pad70 : 15;
        u32 track : 6;
        u32 pad74 : 4;
    };
    struct CoasterFlyData {
        f32 position[3];
        f32 unkC;
        u8 unk10;
        u8 variant : 4;
        u8 flags : 4;
        s16 unk12;
        s32 unk14;
        s16 height;
        s16 unk1A;
    } *data;
    f32 position[3];
    f32 height;
    f32 ground;

    data = func_80100094(arg0, 0);
    if (arg0->unk64_29) {
        func_8008FE94(5, position);
        return position[1] + 100.0f;
    }
    if (func_80104544(arg0)) {
        height = func_8010473C(arg0, NULL) + (f32)data->height;
        func_800EE7F8(position, arg0->position);
        position[1] = height;
        if (func_800CC338(position, arg0->unk70_25 - 1, ((struct CoasterFlyActorFlags *)arg0)->track - 1) != -1) {
            return height;
        }
    } else if (func_80801FE4_sucoasterfly(arg0, &ground, 50.0f, -((f32)data->height + 400.0f))) {
        func_800EE7F8(position, arg0->position);
        position[1] = (f32)data->height + ground;
        if (func_800CC338(position, arg0->unk70_25 - 1, ((struct CoasterFlyActorFlags *)arg0)->track - 1) != -1) {
            return (f32)data->height + ground;
        }
    }
    return arg0->position[1];
}

s32 func_80801FE4_sucoasterfly(Actor *arg0, f32 *arg1, f32 arg2, f32 arg3) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp34, arg0->position);
    func_800EE7F8(sp28, arg0->position);
    sp34[1] += arg2;
    sp28[1] += arg3;
    if (func_800BEF00(sp34, sp28, sp1C, arg0->unk14) != 0) {
        *arg1 = sp28[1];
        return 1;
    }
    return 0;
}

/* extern */

void func_80802080_sucoasterfly(Actor *arg0) {
    typedef struct {
        u8 pad0[0x11];
        u8 track;
    } CoasterFlyData;
    typedef struct {
        u8 pad0[2];
        union {
            s16 id;
            u8 bytes[2];
        } expression;
    } TrackData;
    void *_sucoasterflydata_entrypoint_1(u32);
    s32 _suexpression_entrypoint_1(u8);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 pad;
    TrackData *sp20;

    sp20 = _sucoasterflydata_entrypoint_1((u32)((CoasterFlyData *)func_80100094(arg0, 0U))->track >> 4);
    if ((func_80100094(arg0, 1U) == NULL) && (_suexpression_entrypoint_1(sp20->expression.bytes[1]) != 0)) {
        _suexpression_entrypoint_7(arg0, 1, sp20->expression.id);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42480000, 0x42200000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x7D0);
    }
}

void func_80802128_sucoasterfly(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_8080215C_sucoasterfly(Actor *arg0) {
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_18(func_80100094(arg0, 1U), 1);
    }
}

u8 *sucoasterfly_entrypoint_5(Actor *arg0) {
    return (u8 *)func_80100094(arg0, 0U) + 0x1C;
}

void sucoasterfly_entrypoint_6()
{
    func_80101870();
}
