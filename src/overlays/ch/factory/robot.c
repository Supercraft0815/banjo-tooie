#include "common.h"

OSThread *chfactoryrobot_entrypoint_0(void)
{
    extern u8 D_80802928_chfactoryrobot[];

    return (OSThread *) D_80802928_chfactoryrobot;
}

OSThread *chfactoryrobot_entrypoint_1(void)
{
    extern u8 D_80802970_chfactoryrobot[];

    return (OSThread *) D_80802970_chfactoryrobot;
}

OSThread *chfactoryrobot_entrypoint_2(void)
{
    extern u8 D_808029B8_chfactoryrobot[];

    return (OSThread *) D_808029B8_chfactoryrobot;
}

/* extern */

void func_80800024_chfactoryrobot(void *arg0) {
    s32 func_80105010();
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x34))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x30))) = 20.0f;
    func_80105010();
}

u32 func_800F54E4(void);

void func_80800058_chfactoryrobot(Actor *arg0) {
    u8 func_800D9078(f32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800F18FC(f32 *, f32 *, f32 *);
    s32 func_800F4F34(u32, f32 *, f32, f32);
    void func_80101FDC(Actor *, u32);
    void func_8010D254(f32 *);
    void func_80800264_chfactoryrobot(Actor *);
    int func_808006DC_chfactoryrobot(Actor *, f32, f32);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp28[2];

    func_800EE7F8(sp3C, arg0->position);
    func_800EF1B8(sp3C, arg0->rotation[1], 40.0f);
    func_800F4F34(func_800F54E4(), sp3C, 30.0f, 100.0f);
    switch (arg0->unk70_10) {
        case 1:
            func_80800264_chfactoryrobot(arg0);
            arg0->unk54 = 50.0f;
            arg0->unk50 = 20.0f;
            if (func_808006DC_chfactoryrobot(arg0, 1.0f, 15.0f)) {
                ((f32 *)arg0->actorData)[0] = func_800DC178(1.0f, 1.2f);
                func_80101FDC(arg0, 2);
            }
            break;
        case 2:
            func_80800264_chfactoryrobot(arg0);
            if (func_800D9078((f32 *)arg0->actorData)) {
                func_80101FDC(arg0, 3);
            }
            break;
        case 3:
            func_80800264_chfactoryrobot(arg0);
            arg0->unk54 = -50.0f;
            arg0->unk50 = 20.0f;
            if (func_808006DC_chfactoryrobot(arg0, 1.0f, 15.0f)) {
                ((f32 *)arg0->actorData)[0] = func_800DC178(1.0f, 1.2f);
                func_80101FDC(arg0, 4);
            }
            break;
        case 4:
            func_80800264_chfactoryrobot(arg0);
            if (func_800D9078((f32 *)arg0->actorData)) {
                func_80101FDC(arg0, 1);
            }
            break;
        case 5:
            func_80800264_chfactoryrobot(arg0);
            func_8010D254(sp30);
            func_800F18FC(arg0->position, sp30, sp28);
            arg0->unk54 = sp28[1] - arg0->rotation[1];
            arg0->unk50 = -sp28[0];
            func_808006DC_chfactoryrobot(arg0, 4.0f, 40.0f);
            if (arg0->unk58 == 0.0f) {
                func_80101FDC(arg0, 3);
            }
            break;
    }
}

void func_80800264_chfactoryrobot(Actor *arg0) {
    u8 func_800D9078(f32 *);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 func_8010D248(void);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    f32 _subaddieaudioloop_entrypoint_8(void *, f32 *, s32, f32);
    void func_80101FDC(Actor *, u32);

    func_800D9078(&arg0->unk58);
    if (_subaddierouteDll_entrypoint_4(arg0) && func_8010D248() && func_8010C500(arg0)) {
        arg0->unk58 = 4.0f;
    }
    _subaddieDll_entrypoint_4(arg0, arg0->unk58 > 0.0f ? 1 : 0);
    ((f32 *)arg0->actorData)[4] = _subaddieaudioloop_entrypoint_8(arg0, arg0->position, arg0->unk58 > 0.0f, ((f32 *)arg0->actorData)[4]);
    if (arg0->unk70_10 != 5 && arg0->unk58 > 0.0f) {
        func_80101FDC(arg0, 5);
    }
}

s32 func_80800360_chfactoryrobot(Actor *arg0, s32 arg1, u8 *arg2) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80107070(Actor *, s32);
    void func_80800424_chfactoryrobot(Actor *, u8 *);
    void func_80800508_chfactoryrobot(Actor *);
    void func_808005D4_chfactoryrobot(Actor *);
    u8 **arg2p = &arg2;

    switch (arg1) {
    case 0x40:
        func_80106790(arg0->unk3C)->unk3C = NULL;
        func_808005D4_chfactoryrobot(arg0);
        func_80107070(arg0, 3);
        break;
    case 0x1F:
        func_80800424_chfactoryrobot(arg0, *arg2p);
        break;
    case 0x8F:
        if (*arg2p == NULL) {
            func_80800508_chfactoryrobot(arg0);
        }
        break;
    case 0x95:
        func_80800508_chfactoryrobot(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_80800424_chfactoryrobot(Actor *arg0, u8 *arg1) {
    s32 func_800AE080(s16);
    s32 func_800AE1E8(s16, s32, s32);
    u8 *func_800B27E0(u8 *);
    void func_800D93A0(f32[4], f32[3]);
    void func_800DF41C(s32);
    void func_800DF72C(s32);
    void func_800DFF2C(u8 **, s32, f32[4]);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_801015D0(Actor *);
    s32 func_801040D0(void);
    f32 sp38[4];
    f32 sp28[4];
    s32 temp_s0;

    temp_s0 = func_801040D0();
    func_801015D0(arg0);
    func_800DF41C(temp_s0);
    func_800EFA4C(sp38, 0.0f, ((f32 *)arg0->actorData)[5], 0.0f);
    func_800D93A0(sp28, sp38);
    func_800DFF2C(temp_s0, 0x12, sp28);
    func_800EFA4C(sp38, ((f32 *)arg0->actorData)[6], 0.0f, 0.0f);
    func_800D93A0(sp28, sp38);
    func_800DFF2C(temp_s0, 0x6C, sp28);
    func_800AE1E8(((s16 *)&arg0->unk0->unk10)[0], func_800B27E0(arg1), temp_s0);
    func_800DF72C(func_800AE080(((s16 *)&arg0->unk0->unk10)[0]));
}

/* extern */

void func_80101FDC(Actor *, u32);

void func_80800508_chfactoryrobot(Actor *arg0) {
    s32 _subaddiefind_entrypoint_10(Actor *, s32, u32);
    void func_80103110(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80107200(Actor *);
    struct RobotFlags {
        u8 pad0[0x70];
        u32 flags25 : 7;
        u32 pad10 : 15;
        u32 flags4 : 6;
        u32 pad0bits : 4;
    };
    Actor *sp24;
    u32 flags;

    _subaddiefind_entrypoint_10(arg0, 0x3BF, arg0->unk74_7);
    sp24 = func_80106790(arg0->unk3C);
    sp24->unk3C = arg0->unk0;
    func_80101FDC(sp24, 1);
    func_80103110(sp24, 1);
    ((struct RobotFlags *)arg0)->flags25 = ((struct RobotFlags *)sp24)->flags25;
    flags = ((struct RobotFlags *)sp24)->flags4;
    if (flags != 0) {
        ((struct RobotFlags *)arg0)->flags4 = flags;
    } else {
        ((struct RobotFlags *)arg0)->flags4 = 1;
    }
    func_80107200(arg0);
}

void func_808005D4_chfactoryrobot(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EF214(f32 *, f32, f32, f32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80802A00_chfactoryrobot;
    extern s32 D_80802A38_chfactoryrobot;
    extern s32 D_80802A6C_chfactoryrobot;
    extern s32 D_80802A7C_chfactoryrobot;
    struct RobotRenderFlags {
        u8 pad0[0x70];
        u32 pad70 : 31;
        u32 enabled : 1;
    };
    f32 sp44[3];
    f32 sp38[3];
    f32 *position;

    position = arg0->position;
    func_800EE7F8(sp44, position);
    func_800EF214(sp44, -arg0->rotation[0], arg0->rotation[1], 20.0f);
    func_800BBCB8(sp44, position, 1.0f, 8, &D_80802A38_chfactoryrobot);
    func_800BBCB8(sp44, position, 1.0f, 12, &D_80802A00_chfactoryrobot);
    func_8010D930(6, ((struct RobotRenderFlags *)arg0)->enabled, sp44, &D_80802A6C_chfactoryrobot);
    _subaddieaudioquick_entrypoint_2(arg0, sp44, &D_80802A7C_chfactoryrobot);
    func_800EE7F8(sp38, position);
    func_800EF1B8(sp38, arg0->rotation[1], -50.0f);
    _chexploder_entrypoint_3(arg0, sp38, 0);
}

/* extern */

int func_808006DC_chfactoryrobot(Actor *arg0, f32 arg1, f32 arg2) {
    f32 func_80013728(f32);
    f32 func_800D8FF8(void);
    f32 func_800F0D50(f32, f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    int func_800F20BC(f32, f32, f32);
    f32 dt;

    dt = func_800D8FF8();
    arg0->unk54 = func_800F0D50(func_80013728(arg0->unk54), -80.0f, 80.0f);
    arg0->unk50 = func_800F0D50(func_80013728(arg0->unk50), -60.0f, 60.0f);
    ((f32 *)arg0->actorData)[5] = func_800F1FF0(((f32 *)arg0->actorData)[5], arg0->unk54, 0.15f, dt * arg1, dt * arg2);
    ((f32 *)arg0->actorData)[6] = func_800F1FF0(((f32 *)arg0->actorData)[6], arg0->unk50, 0.15f, dt * arg1, dt * arg2);
    func_800F20BC(((f32 *)arg0->actorData)[5], arg0->unk54, 4.0f);
}

void func_808007C4_chfactoryrobot(Actor *arg0) {
    s32 _subaddieDll_entrypoint_1(Actor *);
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE940(s16 *, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80105138(Actor *, f32 *, f32, f32, f32 *);
    void func_80107200(Actor *);
    void func_8010A3E8(void *, f32);
    void func_8010A590(Actor *);
    s32 func_80801160_chfactoryrobot(u8 *, s32);
    struct RobotInitData {
        s16 position[3];
        s16 timer;
        u8 pad8[4];
        f32 yaw;
        f32 targetYaw;
        u8 pad14[0x10];
        f32 unk24;
        f32 unk28;
        u8 pad2C[8];
        u8 route[4];
    };
    struct RobotInitData *data;
    f32 height;

    data = func_80100094(arg0, 0);
    func_8010A3E8(arg0, 0.4f);
    func_8010A590(arg0);
    func_800EE940(data->position, arg0->position);
    data->targetYaw = data->yaw = arg0->rotation[1];
    data->unk28 = 1.0f;
    data->unk24 = 0.0f;
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    if (arg0->unk7A_5) {
        if (func_80105138(arg0, arg0->position, 0.0f, -500.0f, &height)) {
            data->position[1] = (s32)height;
        }
        _subaddieDll_entrypoint_1(arg0);
        _subaddierouteDll_entrypoint_3(arg0, data->route, arg0->position);
        func_80107200(arg0);
        func_80801160_chfactoryrobot((u8 *)arg0, 3);
        data->timer = (s32)func_800DC178(100.0f, 200.0f);
    } else {
        func_80801160_chfactoryrobot((u8 *)arg0, 1);
        arg0->unk64_24 = 0;
        ((f32 *)arg0->actorData)[1] += 300.0f;
        arg0->unk58 = 1.0f;
    }
}

void func_80800920_chfactoryrobot(Actor *arg0) {
    void _chelectricfence_entrypoint_1(Actor *, f32 *);
    s32 _subaddieDll_entrypoint_1(Actor *);
    u8 _subaddieaudioloop_entrypoint_6(u8, f32 *, s32, s32, u32 *, s32);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddierouteDll_entrypoint_1(Actor *);
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    void func_800C31DC(u8, f32);
    void func_800C8CB8(s32, f32 *);
    s32 func_800C8E84(s32, s32 *);
    void func_800C8FE0(s32, s32);
    u8 func_800D9078(f32 *);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    f32 func_800F57F0(s32, f32 *);
    s32 func_800F7B9C(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    void func_80107200(Actor *);
    s32 func_8010CFBC(f32 *, s32, s32);
    s32 func_80801160_chfactoryrobot(u8 *, s32);
    s32 func_80801278_chfactoryrobot(Actor *);
    s32 func_80801A80_chfactoryrobot(Actor *);
    s32 func_80801B3C_chfactoryrobot(Actor *);
    s32 func_80801BB0_chfactoryrobot(Actor *);
    void func_80801C7C_chfactoryrobot(Actor *);
    extern s32 D_80802890_chfactoryrobot;
    extern u32 D_80802A8C_chfactoryrobot[];
    extern u32 D_80802A9C_chfactoryrobot[];
    extern u32 D_80802AAC_chfactoryrobot[];
    struct RobotUpdateData {
        s16 position[3];
        s16 timer;
        u8 sound;
        u8 electricSound;
        u8 padA[2];
        f32 yaw;
        f32 targetYaw;
        s32 light;
        s16 activated;
        s16 pad1A;
        f32 cooldown;
        f32 electricTimer;
        f32 unk24;
        f32 volume;
        u8 pad2C[8];
        u8 route[4];
    };
    struct RobotFlags {
        u32 pad : 29;
        u32 disabled : 1;
        u32 pad2 : 2;
    };
    struct RobotUpdateData *data;
    s32 electricFinished;
    f32 playerPosition[3];
    f32 fraction;
    f32 position[3];
    s32 finished;

    data = func_80100094(arg0, 0);
    if (!((struct RobotFlags *)&arg0->unk78)->disabled) {
        data->electricSound = _subaddieaudioloop_entrypoint_6(data->electricSound, arg0->position, data->electricTimer > 0.0f, -1, D_80802AAC_chfactoryrobot, arg0->unk70_0);
        data->sound = _subaddieaudioloop_entrypoint_6(data->sound, arg0->position, 1, -1, D_80802A9C_chfactoryrobot, arg0->unk70_0);
        if (data->sound) {
            func_800C31DC(data->sound, data->volume);
        }
        func_800D9078(&data->cooldown);
        electricFinished = func_800D9078(&data->electricTimer);
        if (data->electricTimer > 0.0f) {
            if (data->cooldown == 0.0f) {
                if (func_8010CFBC(arg0->position, (s32)(arg0->scale * 80.0f), (s32)(arg0->scale * 175.0f)) && func_800F7B9C(func_800F54E4(), 0x51) == 2) {
                    if (arg0->unk64_29) {
                        data->cooldown = 1.5f;
                    } else {
                        data->cooldown = 6.0f;
                    }
                    data->activated = arg0->unk64_29;
                    data->electricTimer = 0.4f;
                    func_800F57F0(func_800F54E4(), playerPosition);
                    _chelectricfence_entrypoint_1(arg0, playerPosition);
                }
            }
            func_800C8CB8(data->light, arg0->position);
            func_800C8E84(data->light, ((s32 (*)[3])&D_80802890_chfactoryrobot)[func_800DC298(0.35f)]);
        } else if (electricFinished) {
            func_800C8FE0(data->light, 0);
        }
        switch (arg0->unk70_10) {
        case 1:
            finished = func_800D9078(&arg0->unk58);
            fraction = func_800F12D4(arg0->unk58, 0.0f, 1.0f, 1.0f, 0.0f);
            func_800EE88C(position, data->position);
            func_800EFE50(arg0->position, position, (f32 *)arg0->actorData, fraction);
            if (finished) {
                _subaddieDll_entrypoint_1(arg0);
                _subaddierouteDll_entrypoint_3(arg0, data->route, arg0->position);
                _subaddierouteDll_entrypoint_1(arg0);
                func_80107200(arg0);
                func_80801160_chfactoryrobot((u8 *)arg0, 2);
                arg0->unk64_24 = 1;
            }
            break;
        case 2:
            if (func_80801278_chfactoryrobot(arg0)) {
                _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802A8C_chfactoryrobot, 0.0f);
                if (func_80101DDC(arg0)) {
                    func_80801160_chfactoryrobot((u8 *)arg0, 3);
                    arg0->unk58 = func_800DC178(2.0f, 4.0f);
                    func_80801C7C_chfactoryrobot(arg0);
                }
            }
            break;
        case 3:
            if (func_80801278_chfactoryrobot(arg0)) {
                func_80801BB0_chfactoryrobot(arg0);
                func_80801A80_chfactoryrobot(arg0);
            }
            break;
        case 4:
            if (func_80801278_chfactoryrobot(arg0)) {
                _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802A8C_chfactoryrobot, 0.0f);
                if (func_80101DDC(arg0)) {
                    func_80801160_chfactoryrobot((u8 *)arg0, 5);
                    if (arg0->unk64_29) {
                        arg0->unk58 = func_800DC178(2.0f, 3.0f);
                    } else {
                        arg0->unk58 = func_800DC178(4.0f, 5.0f);
                    }
                }
            }
            break;
        case 5:
            if (func_80801278_chfactoryrobot(arg0)) {
                func_80801B3C_chfactoryrobot(arg0);
            }
            break;
        case 6:
            break;
        }
        if (!arg0->unk64_29 && data->activated && data->electricTimer == 0.0f) {
            if (func_800EEB40(arg0->position, (f32 *)arg0->actorData) < 62500.0f) {
                func_800C8FE0(data->light, 1);
                data->electricTimer = func_800DC178(1.2f, 1.6f);
            }
        }
    }
}

/* extern */

void func_80800DC4_chfactoryrobot(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void func_800C8B84(volatile s32);
    void *func_80100094(Actor *, u32);
    u8 *sp2C;
    s32 temp_a0;
    s32 var_s1;
    u8 temp_v0_2;
    u8 *temp_v0;
    u8 *var_s0;

    temp_v0 = func_80100094(arg0, 0);
    var_s1 = 0;
    var_s0 = temp_v0;
    sp2C = temp_v0;
    do {
        temp_v0_2 = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(var_s0) + (8))));
        var_s1 += 1;
        var_s0 += 1;
        (*(s8 *)((s8 *)(var_s0) + (7))) = temp_v0_2;
    } while (var_s1 != 2);
    temp_a0 = (*(s32 *)((s8 *)(sp2C) + (0x14)));
    if (temp_a0 != 0) {
        func_800C8B84(temp_a0);
        (*(s32 *)((s8 *)(sp2C) + (0x14))) = 0;
    }
}

s32 func_80800E40_chfactoryrobot(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x18];
        s16 unk18;
        f32 unk1C;
    } RobotData;
    void *func_80100094(Actor *, u32);
    s32 _subaddieDll_entrypoint_3(Actor *);
    s32 func_80107070(Actor *, s32);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _chexploder_entrypoint_9(Actor *, s32, s32);
    void _chexploder_entrypoint_13(s32, u32);
    void func_800FFAB0(Actor *);
    void func_8010A590(Actor *);
    void func_80109FE8(void **, s32);
    s32 func_80801160_chfactoryrobot(u8 *, s32);
    void func_8080183C_chfactoryrobot(Actor *);
    s32 func_80801C50_chfactoryrobot(s32);
    s32 func_80802470_chfactoryrobot(Actor *, s32);
    RobotData *data;
    Actor *sp20;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x40:
        func_80801160_chfactoryrobot((u8 *)arg0, 7);
        break;
    case 2:
        if (_subaddieDll_entrypoint_3(arg0) == 0) {
            func_80107070(arg0, 1);
        }
        break;
    case 0x3E:
        if (arg0->unk64_29) {
            data->unk1C = 1.5f;
        } else {
            data->unk1C = 6.0f;
        }
        data->unk18 = arg0->unk64_29;
        break;
    case 0x90:
        sp20 = func_80106790(func_80101080());
        _chexploder_entrypoint_9(sp20, 3, 0);
        _chexploder_entrypoint_13((s32)sp20, 10);
        if (func_80107070(arg0, 3) == 0) {
            func_800FFAB0(arg0);
        }
        break;
    case 0x93:
        func_80802470_chfactoryrobot(arg0, 0);
        break;
    case 0x95:
        func_8080183C_chfactoryrobot(arg0);
        break;
    case 0x38:
        return func_80801C50_chfactoryrobot((s32)arg0);
    case 0x8F:
        if (arg2 == 0) {
            func_8010A590(arg0);
            func_80109FE8((void **)arg0, 1);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800FFC_chfactoryrobot(Actor *arg0, void *arg1) {
    typedef struct {
        u8 pad0[0xA];
        s16 unkA;
        u8 padC[8];
        s32 unk14;
        u8 pad18[8];
        f32 unk20;
    } RobotData;
    typedef struct {
        u8 pad0[0x74];
        u8 flags74;
        u8 pad75[3];
        u32 pad78_3 : 29;
        u32 flag78_2 : 1;
        u32 pad78_0 : 2;
    } RobotFlags;
    void *func_80100094(Actor *, u32);
    s32 func_800DC128(s32, s32);
    void func_800DF744(s32, s32);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    s32 _subaddiefade_entrypoint_12(s32, s32, s32, s32);
    u8 func_800C9044(s32);
    void func_800C8900(s32, s32 *);
    void func_80101870(Actor *, void *);
    RobotData *sp44;
    register RobotData *data;
    s32 sp34[3];
    s32 sp28[3];
    register s32 active;

    sp44 = func_80100094(arg0, 0);
    if (sp44->unk20 > 0.0f && !((RobotFlags *)arg0)->flag78_2) {
        data = func_80100094(arg0, 0);
        data->unkA = func_800DC128(0, 4);
    }
    active = sp44->unk20 > 0.0f ? ((RobotData *)func_80100094(arg0, 0))->unkA : 0;
    func_800DF744(3, active);
    _subaddiefade_entrypoint_9(arg0, sp34);
    active = sp44->unk14 != 0;
    if (active) {
        active = func_800C9044(sp44->unk14) != 0;
    }
    if (((RobotFlags *)arg0)->flags74 & 1) {
        _subaddiefade_entrypoint_12((s32)arg0, 255, 255, 255);
    } else if (active) {
        func_800C8900(sp44->unk14, sp28);
        _subaddiefade_entrypoint_11(arg0, sp28);
    }
    func_80101870(arg0, arg1);
    if (active || (((RobotFlags *)arg0)->flags74 & 1)) {
        _subaddiefade_entrypoint_11(arg0, sp34);
    }
}

s32 func_80801160_chfactoryrobot(u8 *arg0, s32 arg1) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 *_fxgenlist_entrypoint_2(void);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_80102424(Actor *, s32);
    void func_80103DFC(Actor *, f32 *);
    void func_80109FE8(void **, s32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    s32 func_80802470_chfactoryrobot(Actor *, s32);
    extern s32 D_80802AB8_chfactoryrobot;
    f32 sp2C[3];

    func_80102424((Actor *)arg0, arg1);
    switch (arg1) {
    case 2:
    case 4:
        func_80109FE8(arg0, 1);
        return;
    case 5:
        func_80109FE8(arg0, 0);
        return;
    case 1:
        func_80109FE8(arg0, 0);
        return;
    case 7:
        func_80103DFC((Actor *)arg0, sp2C);
        func_80802470_chfactoryrobot((Actor *)arg0, 1);
        ((Actor *)arg0)->unk64_24 = 0;
        func_800BBCB8(sp2C, sp2C, 0.8f, 1, _fxgenlist_entrypoint_2());
        func_8010D930(6, ((Actor *)arg0)->unk70_0, sp2C, &D_80802AB8_chfactoryrobot);
        _chexploder_entrypoint_3(arg0, ((Actor *)arg0)->position, 0x124);
        return;
    default:
        func_80109FE8(arg0, 1);
        return;
    }
}

s32 func_80801278_chfactoryrobot(Actor *arg0) {
    typedef struct {
        s16 position[3];
        s16 speed;
        u8 pad8[0x10];
        s16 active;
        s16 pad1A;
        f32 timer;
        f32 unk20;
        f32 wait;
        f32 scale;
        f32 yaw;
        f32 targetYaw;
        u8 route[4];
    } RobotData;
    typedef struct {
        f32 position[3];
        f32 speed;
        f32 velocity[3];
    } RobotMotion;
    typedef struct {
        u8 pad0[0x12];
        u16 flags;
    } RobotMarker;
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    Unk80132ED0 *_suchase_entrypoint_0(void);
    void func_8008FE94(s32, f32 *);
    f32 func_800D8FF8(void);
    u8 func_800D9078(f32 *);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EFD24(f32 *);
    f32 func_800F0D50(f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 func_80102D78(Actor *, f32 *);
    void func_80104580(Actor *);
    s32 func_8010B990(Actor *, s32);
    s32 func_8010D248(void);
    void func_80801954_chfactoryrobot(Actor *);
    void func_80801C7C_chfactoryrobot(Actor *);
    RobotData *data;
    f32 dt;
    f32 targetSpeed;
    f32 scale;
    f32 pad4C;
    f32 angle;
    s32 id;
    f32 pad40;
    f32 angle2;

    data = func_80100094(arg0, 0);
    dt = func_800D8FF8();
    scale = 1.0f;
    if (_subaddierouteDll_entrypoint_4(arg0)) {
        if (data->active == 0) {
            if (data->timer == 0.0f && !func_800C0638() &&
                (arg0->unk64_29 || (func_8010D248() && func_8010C500(arg0) && _suchase_entrypoint_0() == arg0->unk0))) {
                data->active = 1;
                data->wait = func_800DC178(2.0f, 4.0f);
                switch (arg0->unk70_10) {
                case 4:
                case 5:
                    func_80801160_chfactoryrobot((u8 *)arg0, 2);
                    data->speed = (s32)func_800DC178(100.0f, 200.0f);
                    break;
                }
            }
        } else if (!arg0->unk64_29 && (!func_8010C500(arg0) || _suchase_entrypoint_0() != arg0->unk0)) {
            data->active = 0;
            func_80801C7C_chfactoryrobot(arg0);
        }
    }
    targetSpeed = data->active ? 420.0f : data->speed;
    ((RobotMotion *)arg0->actorData)->speed = func_800F15F8(((RobotMotion *)arg0->actorData)->speed, targetSpeed, dt * 150.0f);
    if (((RobotMotion *)arg0->actorData)->speed != 0.0f) {
        if (data->active) {
            func_8008FE94(5, ((RobotMotion *)arg0->actorData)->position);
            if (arg0->unk64_29) {
                scale = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 1);
                if (data->timer == 0.0f) {
                    func_800EEB9C(((RobotMotion *)arg0->actorData)->velocity, arg0->unk54, ((RobotMotion *)arg0->actorData)->speed * scale);
                    ((RobotMotion *)arg0->actorData)->velocity[1] = func_800F0D50(((RobotMotion *)arg0->actorData)->position[1] - arg0->position[1], -300.0f, 300.0f);
                } else {
                    func_800EFD24(((RobotMotion *)arg0->actorData)->velocity);
                }
            } else {
                angle = func_80102D78(arg0, ((RobotMotion *)arg0->actorData)->position);
                if (_subaddierouteDll_entrypoint_4(arg0)) {
                    _subaddierouteDll_entrypoint_7(arg0, data->route, angle, angle, 400.0f, 0x5000);
                    data->targetYaw = arg0->unk54;
                }
                data->yaw = func_800F1FF0(data->yaw, data->targetYaw, 0.15f, func_800D8FF8() * 10.0f, func_800D8FF8() * 150.0f);
                arg0->unk54 = angle;
                func_800EEB9C(((RobotMotion *)arg0->actorData)->velocity, data->yaw, ((RobotMotion *)arg0->actorData)->speed);
                ((RobotMotion *)arg0->actorData)->velocity[1] = func_800F0D50(((RobotMotion *)arg0->actorData)->position[1] - arg0->position[1], -300.0f, 300.0f);
            }
            func_80801954_chfactoryrobot(arg0);
            func_8010B990(arg0, arg0->unk64_29 ? 0x204027 : 0x504427);
        } else {
            id = (((u32)((RobotMarker *)arg0->unk0)->flags) >> 1) & 0xF;
            if (func_8001210C(15) == id && func_800DC298(0.6f)) {
                arg0->unk54 = func_800DC178(0.0f, 359.0f);
            }
            func_80801954_chfactoryrobot(arg0);
            func_800D9078(&data->wait);
            if (data->wait == 0.0f) {
                if (func_800EEB40(((RobotMotion *)arg0->actorData)->position, arg0->position) > 6400.0f) {
                    angle2 = func_80102D78(arg0, ((RobotMotion *)arg0->actorData)->position);
                    if (_subaddierouteDll_entrypoint_4(arg0)) {
                        _subaddierouteDll_entrypoint_7(arg0, data->route, angle2, angle2, 400.0f, 0x5000);
                        data->targetYaw = arg0->unk54;
                    }
                        data->yaw = func_800F1FF0(data->yaw, data->targetYaw, 0.15f, func_800D8FF8() * 10.0f, func_800D8FF8() * 120.0f);
                    arg0->unk54 = angle2;
                    func_800EEB9C(((RobotMotion *)arg0->actorData)->velocity, data->yaw, ((RobotMotion *)arg0->actorData)->speed);
                    ((RobotMotion *)arg0->actorData)->velocity[1] = func_800F0D50(((RobotMotion *)arg0->actorData)->position[1] - arg0->position[1], -300.0f, 300.0f);
                    if (func_8010B990(arg0, 0x504427) & 0x26) {
                        func_80801C7C_chfactoryrobot(arg0);
                    }
                } else {
                    func_80801C7C_chfactoryrobot(arg0);
                    data->wait = func_800DC178(2.0f, 4.0f);
                }
            } else {
                scale = 0.0f;
            }
        }
    } else {
        func_80104580(arg0);
    }
    data->scale += 0.7f * (func_800F12D4(((RobotMotion *)arg0->actorData)->speed * scale, 0.0f, 420.0f, 1.0f, 1.1f) - data->scale);
    return 1;
}

void func_8080183C_chfactoryrobot(Actor *arg0) {
    typedef struct {
        u8 pad0[8];
        s8 unk8[2];
        u8 padA[0xA];
        s32 unk14;
        u8 pad18[8];
        f32 unk20;
    } RobotData;
    typedef struct {
        f32 values[2];
    } RobotSize;
    void _subaddierouteDll_entrypoint_1(Actor *);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32[3]);
    void func_800C8D4C(s32, f32 *);
    s32 func_800C8E84(s32, s32 *);
    void func_800C8F64(s32, s32);
    void func_800C8FE0(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80802398_chfactoryrobot(Actor *);
    extern s32 D_80802890_chfactoryrobot;
    extern RobotSize D_80802ACC_chfactoryrobot;
    struct {
        RobotSize size;
        f32 pad;
    } local;
    s32 i;
    RobotData *data;

    data = func_80100094(arg0, 0);
    local.size = D_80802ACC_chfactoryrobot;
    for (i = 0; i != 2; i++) {
        data->unk8[i] = 0;
    }
    func_80802398_chfactoryrobot(arg0);
    local.size.values[0] *= arg0->scale;
    local.size.values[1] *= arg0->scale;
    data->unk14 = func_800C8A98();
    func_800C8E84(data->unk14, &D_80802890_chfactoryrobot);
    func_800C8CB8(data->unk14, arg0->position);
    func_800C8F64(data->unk14, 3);
    func_800C8D4C(data->unk14, local.size.values);
    func_800C8FE0(data->unk14, data->unk20 > 0.0f);
    if (arg0->unk70_10 != 1) {
        _subaddierouteDll_entrypoint_1(arg0);
    }
}

void func_80801954_chfactoryrobot(Actor *arg0) {
    typedef struct {
        u8 pad0[0xC];
        f32 unkC;
        f32 unk10;
    } RobotData;
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_8010262C(Unk80132ED0 *, u32);
    RobotData *data;
    f32 dt;
    s32 model;

    data = func_80100094(arg0, 0);
    dt = func_800D8FF8();
    if (arg0->unk70_10 != 5) {
        data->unk10 = func_800F1FF0(data->unk10, arg0->unk54, 0.1f, dt * 0.5f, dt * 150.0f);
        data->unkC = func_800F1FF0(data->unkC, arg0->unk54, 0.2f, dt * 4.0f, dt * 400.0f);
    }
    model = func_8010262C(arg0->unk0, 2);
    if (model != 0) {
        func_800E0AFC((void *)model, 3, 1.0f, 0.0f, data->unk10, 0.0f);
        func_800E0AFC((void *)model, 0x12, 1.0f, 0.0f, func_800136E4(data->unkC - data->unk10), 0.0f);
    }
}

/* extern */

s32 func_80801A80_chfactoryrobot(Actor *arg0) {
    typedef struct {
        u8 pad0[0x18];
        s16 unk18;
        u8 pad1A[6];
        f32 unk20;
    } RobotData;
    typedef struct {
        u8 pad0[0x64];
        u32 pad64_30 : 2;
        u32 unk64_29 : 1;
        u32 pad64_0 : 29;
    } RobotFlags;
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    u8 func_800D9078(f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80801160_chfactoryrobot(u8 *, s32);
    RobotData *sp24;
    u32 var_v0;
    RobotData *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp24 = temp_v0;
    if (temp_v0->unk20 > 0.0f) {
        return 0;
    }
    if (((RobotFlags *)arg0)->unk64_29) {
        var_v0 = _subaddiejoy_entrypoint_6((u8 *)arg0, 0);
    } else {
        if (temp_v0->unk18 != 0) {
            return 0;
        }
        var_v0 = func_800D9078(&arg0->unk58);
    }
    if (var_v0 != 0) {
        func_80801160_chfactoryrobot((u8 *)arg0, 4);
        sp24->unk20 = 0.0f;
        return 1;
    } else {
        return 0;
    }
}

/* extern */
u8 func_800D9078(f32 *);

s32 func_80801B3C_chfactoryrobot(Actor *arg0) {
    typedef struct {
        u8 pad0[0x64];
        u32 pad64_30 : 2;
        u32 unk64_29 : 1;
        u32 pad64_0 : 29;
    } RobotFlags;
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    s32 func_80801160_chfactoryrobot(u8 *, s32);
    s32 var_v1;

    if (((RobotFlags *)arg0)->unk64_29) {
        var_v1 = _subaddiejoy_entrypoint_6((u8 *)arg0, 0);
    } else {
        var_v1 = 0;
    }
    if ((var_v1 != 0) || (func_800D9078(&arg0->unk58) != 0)) {
        func_80801160_chfactoryrobot((u8 *)arg0, 2);
    }
    return var_v1;
}

/* extern */

s32 func_80801BB0_chfactoryrobot(Actor *arg0) {
    typedef struct {
        u8 pad0[0x64];
        u32 pad64_30 : 2;
        u32 unk64_29 : 1;
        u32 pad64_0 : 29;
    } RobotFlags;
    typedef struct {
        u8 pad0[0x14];
        s32 unk14;
        u8 pad18[8];
        f32 unk20;
    } RobotData;
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    void func_800C8FE0(s32, s32);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    RobotData *sp1C;
    RobotData *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    if (temp_v0->unk20 > 0.0f) {
        return 1;
    }
    if (((RobotFlags *)arg0)->unk64_29 && (_subaddiejoy_entrypoint_6((u8 *)arg0, 1) != 0)) {
        func_800C8FE0(sp1C->unk14, 1);
        sp1C->unk20 = func_800DC178(1.2f, 1.6f);
        return 1;
    }
    return 0;
}

s32 func_80801C50_chfactoryrobot(s32 arg0) {
    s32 func_80101074(s32 *);
    extern s32 D_80802AD4_chfactoryrobot;
    func_80101074(&D_80802AD4_chfactoryrobot);
    return 2;
}

/* extern */

void func_80801C7C_chfactoryrobot(Actor *arg0) {
    typedef struct {
        u8 pad[0x70];
        u32 index : 7;
        u32 trailing : 25;
    } RobotFlags;
    typedef struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
    } RobotData;
    void func_800CD1E0(s32, u8 *, f32);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    RobotData *sp1C;
    RobotData *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    func_800CD1E0(((RobotFlags *)arg0)->index - 1, (u8 *)arg0->actorData, (f32)temp_v0->unk2 + 60.0f);
    sp1C->unk6 = (s16)(s32)func_800DC178(100.0f, 200.0f);
}

/* extern */

void func_80801D08_chfactoryrobot(Actor *arg0) {
    typedef struct {
        u8 pad[0x70];
        u32 leading : 22;
        u32 state : 6;
        u32 trailing : 4;
    } RobotState;
    s32 func_800EA05C(void);
    void *func_80100094(Actor *, u32);
    u8 *data;
    RobotState *flags;

    data = func_80100094(arg0, 0);
    flags = (RobotState *)arg0;
    if (flags->state == 0) {
        flags->state = 1;
    }
    if (func_800EA05C() == 0x101) {
        data[0x12] = 1;
    } else {
        data[0x12] = 0;
    }
}

void func_80801D7C_chfactoryrobot(Actor *arg0) {
    typedef struct {
        u8 pad[0x64];
        u32 leading : 11;
        u32 sounded : 1;
        u32 trailing : 20;
    } RobotFlags;
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _chmrtannoy_entrypoint_0(void);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _sudialog_entrypoint_0(s32, s32);
    s32 func_8008FDC4(void);
    void func_800D1254(s32, s32, f32 *);
    s32 func_800D2498(s32, s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    int func_800F00A4(f32 *, f32, f32, f32, f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 func_800F1418(s32, s32);
    s32 func_800F4F34(u32, f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010D23C(void);
    extern s32 D_80802AEC_chfactoryrobot;
    u8 *data;
    Unk80132ED0 **cursor;
    s32 i;
    s32 nearby;
    f32 *position;
    f32 pos6[3];
    s32 done6;
    f32 height6;
    f32 pos7[3];
    s32 done7;
    f32 height7;

    data = func_80100094(arg0, 0);
    position = (f32 *)((u8 *)arg0 + 4);
    func_800F4F34(func_800F54E4(), position, 100.0f, 80.0f);
    switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
    case 1:
        if (*(Unk80132ED0 **)((u8 *)arg0 + 0x3C) == NULL) {
            func_80101FDC(arg0, 3);
        } else if (*(f32 *)((u8 *)func_80106790(*(Unk80132ED0 **)((u8 *)arg0 + 0x3C)) + 0x58) > 0.0f && data[0x14] == 0) {
            _sudialog_entrypoint_0(0x364, 4);
            i = 0;
            if (data[0x10] < data[0x11]) {
                nearby = 0;
                if (i < data[0x10]) {
                    cursor = (Unk80132ED0 **)data;
                    do {
                        if (func_800F00A4(position, 150.0f, 800.0f, 0.0f,
                                (f32 *)((u8 *)func_80106790(*cursor) + 4))) {
                            nearby = 1;
                            break;
                        }
                        i++;
                        cursor++;
                    } while (i < data[0x10]);
                }
                if (!nearby) {
                    func_80108B04(arg0, 0);
                    func_80101FDC(arg0, 2);
                    *(f32 *)((u8 *)arg0 + 0x58) = func_800DC178(1.5f, 2.5f);
                }
            }
        }
        break;
    case 2:
        if (func_800D9078((f32 *)((u8 *)arg0 + 0x58))) {
            func_80101FDC(arg0, 1);
        }
        break;
    case 4:
        if (func_8010D23C() && func_8010C500(arg0) && (func_8008FDC4() & 0x08000000)) {
            _capod_entrypoint_13(*(s32 *)arg0, 0, 0xC, 0x30);
            func_80101FDC(arg0, 6);
            ((u8 *)arg0)[0x65] &= ~0x10;
            *(f32 *)((u8 *)arg0 + 0x58) = 1.0f;
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x133B, 7, position, 0xA3);
        }
        break;
    case 6:
        done6 = func_800D9078((f32 *)((u8 *)arg0 + 0x58));
        height6 = func_800F12D4(*(f32 *)((u8 *)arg0 + 0x58), 0.0f, 1.0f, -200.0f, 300.0f);
        func_800EE7F8(pos6, position);
        pos6[1] += height6;
        func_800D1254(0x39, 1, pos6);
        if (!((RobotFlags *)arg0)->sounded && *(f32 *)((u8 *)arg0 + 0x58) < 0.7f) {
            _subaddieaudioquick_entrypoint_2(arg0, position, &D_80802AEC_chfactoryrobot);
            ((RobotFlags *)arg0)->sounded = 1;
        }
        if (done6) {
            func_80101FDC(arg0, 9);
        }
        break;
    case 7:
        done7 = func_800D9078((f32 *)((u8 *)arg0 + 0x58));
        height7 = func_800F12D4(*(f32 *)((u8 *)arg0 + 0x58), 0.0f, 1.0f, 300.0f, -200.0f);
        func_800EE7F8(pos7, position);
        pos7[1] += height7;
        func_800D1254(0x39, 1, pos7);
        if (done7) {
            func_80101FDC(arg0, 10);
            func_800DA544(0x1BB);
        }
        break;
    case 8:
        func_800D2498(0x101, data[0x13], 0);
        if (func_800D9078((f32 *)((u8 *)arg0 + 0x58))) {
            func_80101FDC(arg0, 9);
        }
        break;
    case 9:
        func_800D2498(0x101, data[0x13], 0);
        if (data[0x10] < func_800F1418(data[0x11], data[0x13]) && data[0x14] == 0) {
            func_80108B04(arg0, 0);
            func_80101FDC(arg0, 8);
            *(f32 *)((u8 *)arg0 + 0x58) = func_800DC178(1.5f, 2.5f);
        }
        break;
    case 3:
    case 5:
    case 10:
        break;
    }
    data[0x14] = 0;
}

/* extern */

void func_8080219C_chfactoryrobot(void *arg0) {
    s32 func_800E8C08(s32, u8, void *);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x28)));
    if (temp_a1 != 0) {
        func_800E8C08(temp_a1 & 0xFF, temp_a1, arg0);
        (*(u8 *)((s8 *)(arg0) + (0x28))) = 0U;
    }
}

/* extern */

void func_808021D4_chfactoryrobot(void *arg0, s32 arg1) {
    u8 func_800D731C(u16);
    s32 func_800DBE60(u8, s32, s32);
    s32 func_800E8C58(u8);
    s32 func_801015D0();
    u8 sp1F;
    s32 sp18;
    s32 temp_v0_2;
    u8 temp_v0;

    func_801015D0();
    temp_v0 = func_800D731C((*(u16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0)))) + (0x14))));
    sp1F = temp_v0;
    if (temp_v0 != 0) {
        temp_v0_2 = func_800E8C58((*(u8 *)((s8 *)(arg0) + (0x28))));
        sp18 = temp_v0_2;
        func_800DBE60(sp1F, 0, temp_v0_2);
        func_800DBE60(sp1F, 1, sp18);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80802240_chfactoryrobot.s")

/* extern */

s32 func_80802398_chfactoryrobot(Actor *arg0) {
    s32 _subaddiefind_entrypoint_10(Actor *, s32, u32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_808025D4_chfactoryrobot(Actor *);
    struct RobotFlags {
        u8 pad[0x7E];
        u16 initialized : 1;
        u16 remaining : 15;
    };
    struct RobotData {
        Unk80132ED0 *markers[4];
        u8 count;
    };
    Actor *robot;
    struct RobotData *data;

    if (arg0->unk7A_5) {
        return 0;
    }
    if (_subaddiefind_entrypoint_10(arg0, 0x3BF, arg0->unk74_7) == 0) {
        return 0;
    }
    robot = func_80106790(arg0->unk3C);
    data = func_80100094(robot, 0);
    if (!((struct RobotFlags *)robot)->initialized) {
        func_808025D4_chfactoryrobot(robot);
        ((struct RobotFlags *)robot)->initialized = 1;
    }
    data->markers[data->count] = arg0->unk0;
    data->count++;
    return 1;
}

s32 func_80802470_chfactoryrobot(Actor *arg0, s32 arg1) {
    s32 _capod_entrypoint_13();
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void func_800FC660(u32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80101FDC(Actor *, u32);
    struct RobotData {
        Unk80132ED0 *markers[4];
        u8 count;
        u8 pad11;
        u8 active;
        u8 remaining;
    };
    Actor *robot;
    struct RobotData *data;
    s32 i;

    if (arg0->unk7A_5) {
        return 0;
    }
    if (arg0->unk3C == NULL) {
        return 0;
    }
    robot = func_80106790(arg0->unk3C);
    data = func_80100094(robot, 0);
    if (arg1 && data->active) {
        if (--data->remaining == 0) {
            _capod_entrypoint_13(robot->unk0, NULL, 0xF, 0x30);
            func_80101FDC(robot, 7);
            robot->unk64_20 = 0;
            robot->unk58 = 1.0f;
            func_800FC660(0x10);
            _subaddiedialog_entrypoint_11(robot->unk0, 0x137B, 0x44, robot->position, 0xA3);
        }
    }
    arg0->unk3C = NULL;
    for (i = 0; i < data->count; i++) {
        if (arg0->unk0 == data->markers[i]) {
            data->markers[i] = data->markers[--data->count];
            return 1;
        }
    }
    return 0;
}

s32 func_808025D4_chfactoryrobot(Actor *arg0) {
    s32 _capod_entrypoint_13();
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiefind_entrypoint_10(Actor *, s32, u32);
    void func_800D1254(s32, s32, f32 *);
    s32 func_800DA298(s32);
    s32 func_800EA090(void);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F0D90(s32, s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    struct RobotData {
        Unk80132ED0 *markers[4];
        u8 count;
        u8 limit;
        u8 active;
        u8 remaining;
        u8 initialized;
    };
    struct RobotData *data;
    s32 i;
    f32 pos[3];

    data = func_80100094(arg0, 0);
    if (data->active) {
        _subaddieDll_entrypoint_4(arg0, 1);
        data->remaining = 6;
        func_80101FDC(arg0, func_800DA298(0x1BB) ? 10 : 4);
        func_800EE7F8(pos, arg0->position);
        pos[1] += 300.0f;
        func_800D1254(0x39, 1, pos);
    } else if (!_subaddiefind_entrypoint_10(arg0, 0x3BD, arg0->unk74_7)) {
        func_80101FDC(arg0, 3);
        func_80103110(arg0, 0);
    }
    data->limit = func_800F0D90((s32)arg0->rotation[1], 1, 4);
    data->count = 0;
    data->initialized = 1;
    for (i = 0; i < data->limit; i++) {
        data->markers[i] = NULL;
    }
    if (data->active && !func_800DA298(0x6A3) && func_800EA090() == 3) {
        _capod_entrypoint_13(arg0->unk0, NULL, 8, 0x10);
        func_800DA544(0x6A3);
    }
}
