#include "common.h"

s32 func_80800000_chfiregen(Actor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    u8 value;
    Unk80132ED0 **param = &arg2;
    u8 func_800D731C(s32);
    s32 func_800DBE60(u8, s32, s32);
    s32 func_801015D0(Actor *);
    void func_80800978_chfiregen(Actor *, Unk80132ED0 *);

    switch (arg1) {
        case 0x1F:
            value = func_800D731C(arg0->unk0->unk14);
            func_801015D0(arg0);
            if (value) {
                func_800DBE60(value, 0, arg0->unk79_4);
            }
            break;
        case 0x40:
            func_80800978_chfiregen(arg0, *param);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chfiregen_entrypoint_0(void)
{
    extern u8 D_808015B4_chfiregen[];

    return (OSThread *) D_808015B4_chfiregen;
}

OSThread *chfiregen_entrypoint_1(void)
{
    extern u8 D_808015FC_chfiregen[];

    return (OSThread *) D_808015FC_chfiregen;
}

OSThread *chfiregen_entrypoint_2(void)
{
    extern u8 D_80801644_chfiregen[];

    return (OSThread *) D_80801644_chfiregen;
}

OSThread *chfiregen_entrypoint_3(void)
{
    extern u8 D_8080168C_chfiregen[];

    return (OSThread *) D_8080168C_chfiregen;
}

OSThread *chfiregen_entrypoint_4(void)
{
    extern u8 D_808016D4_chfiregen[];

    return (OSThread *) D_808016D4_chfiregen;
}

OSThread *chfiregen_entrypoint_5(void)
{
    extern u8 D_8080171C_chfiregen[];

    return (OSThread *) D_8080171C_chfiregen;
}

void func_808000EC_chfiregen(Actor *arg0) {
    typedef struct {
        u8 prefix[0x18];
        f32 phase;
        f32 unused1;
        f32 unused2;
        f32 cooldown;
        f32 unused4;
        f32 extinguish;
        f32 strength;
        f32 morph;
    } FireData;
    extern f32 func_800D9004(void);
    extern s32 _sudeflect_entrypoint_1(u8 *, f32, f32, f32, s32);
    extern s32 _subaddieaudioloop_entrypoint_2(u8 *);
    extern s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    extern void func_800C31DC(u8, f32);
    extern u8 func_800C4350(s32, f32 *, s32 *);
    extern f32 func_800DC0C0(void);
    extern f32 func_800DC178(f32, f32);
    extern f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern void func_80101CDC(Actor *, f32);
    extern f32 func_80101D0C(Actor *);
    extern s32 func_80101E14(Actor *, f32);
    extern s32 func_801039E4(s32);
    extern s32 func_80103CB8(Actor *, u32);
    extern u8 *func_800B2768(u8 *);
    extern s32 func_800B2840(s32);
    extern void _dbmorph_entrypoint_3(u8 *, s32, s32, s32, f32 *);
    extern void func_808008F4_chfiregen(Actor *, s32);
    extern void func_80800B4C_chfiregen(Actor *, s32);
    extern s32 D_80801570_chfiregen[];
    extern s32 D_80801580_chfiregen[];
    f32 timer;
    f32 dt;
    u32 model;
    s32 mesh;
    dt = func_800D9004();
    _sudeflect_entrypoint_1((u8 *) arg0->position, 80.0f, 0.0, 75.0f, 10);
    if (arg0->unk64_19) {
        ((FireData *) arg0)->phase = ((FireData *) arg0)->phase - dt;
        if (((FireData *) arg0)->phase < 0.0f) {
            ((FireData *) arg0)->phase = 0.0;
            arg0->unk64_19 = 0;
        }
    } else {
        ((FireData *) arg0)->phase = ((FireData *) arg0)->phase + dt;
        if (((FireData *) arg0)->phase > 0.3f) {
            ((FireData *) arg0)->phase = 0.3f;
            arg0->unk64_19 = 1;
        }
    }
    arg0->unk79_4 = (s32) func_800F10B4(((FireData *) arg0)->phase, 0.0, 0.3f, 0.0f, 4.49f);
    if (dt < arg0->unk58) {
        arg0->unk58 = arg0->unk58 - dt;
    } else {
        ((FireData *) arg0)->extinguish = (arg0->unk58 = 0.0f);
    }
    arg0->unk6C_0 += 1;
    switch (arg0->unk70_10) {
        case 2:
        if (((FireData *) arg0)->strength <= 0.95f) {
            ((FireData *) arg0)->strength = ((FireData *) arg0)->strength + 0.05f;
        }
        if (((FireData *) arg0)->morph <= 0.84000003f) {
            ((FireData *) arg0)->morph = ((FireData *) arg0)->morph + 0.16f;
        }
        arg0->unk54 = arg0->unk54 + 0.0075f;
        if (arg0->unk54 > 1.0f) {
            arg0->unk54 = 1.0f;
        }
        if (arg0->unk54 < 0.6f) {
            arg0->unk54 = 0.6f;
        }
        if (arg0->unk5F == 0) {
            arg0->unk5F = func_800C4350(0, arg0->position, D_80801580_chfiregen);
        }
        func_800C31DC(arg0->unk5F, arg0->unk54);
        func_800C4350(arg0->unk5F, 0, 0);
        if (arg0->unk58 <= 0.0f) {
            _subaddieaudioloop_entrypoint_2((u8 *) arg0);
            func_808008F4_chfiregen(arg0, 0);
            arg0->unk70_10 = 1;
        }
        if (func_800DC0C0() < 0.005f) {
            arg0->unk70_10 = 3;
            arg0->rotation[0] = 1;
            func_808008F4_chfiregen(arg0, 0);
            func_80101CDC(arg0, 0.7f);
        }
        if ((func_800DC0C0() < 0.08f) && func_80101E14(arg0, 0.1f)) {
            func_80800B4C_chfiregen(arg0, 3);
            _subaddieaudioquick_entrypoint_2((s32) arg0, (s32) arg0->position, D_80801570_chfiregen);
        }
        if (func_800DC0C0() < 0.25f) {
            func_80800B4C_chfiregen(arg0, 1);
        }
        break;
        case 1:
        if (((FireData *) arg0)->strength > 0.02f) {
            ((FireData *) arg0)->strength = ((FireData *) arg0)->strength - 0.02f;
        }
        if (((FireData *) arg0)->morph >= 0.16f) {
            ((FireData *) arg0)->morph = ((FireData *) arg0)->morph - 0.16f;
        }
        if (arg0->unk58 != 0.0f) {
            func_808008F4_chfiregen(arg0, 1);
            arg0->unk70_10 = 2;
            func_80101CDC(arg0, 0.4f);
            arg0->unk54 = 0.6f;
        }
        timer = func_80101D0C(arg0);
        if (timer != 10000000.0f) {
            arg0->unk54 = arg0->unk54 - 0.02f;
            if (arg0->unk54 < 0.6f) {
                arg0->unk54 = 0.6f;
            }
            if (arg0->unk5F == 0) {
                arg0->unk5F = func_800C4350(0, arg0->position, D_80801580_chfiregen);
            }
            func_800C31DC(arg0->unk5F, arg0->unk54);
            func_800C4350(arg0->unk5F, 0, 0);
            timer += func_800DC178(0.05f, 0.15f);
            if (timer > 4.0f) {
                func_80800B4C_chfiregen(arg0, 3);
                _subaddieaudioquick_entrypoint_2((s32) arg0, (s32) arg0->position, D_80801570_chfiregen);
                timer = 10000000.0f;
                _subaddieaudioloop_entrypoint_2((u8 *) arg0);
            }
            func_80101CDC(arg0, timer);
        }
        break;
        case 3:
        if (((FireData *) arg0)->strength > 0.02f) {
            ((FireData *) arg0)->strength = ((FireData *) arg0)->strength - 0.02f;
        }
        if (((FireData *) arg0)->morph >= 0.16f) {
            ((FireData *) arg0)->morph = ((FireData *) arg0)->morph - 0.16f;
        }
        if ((func_800DC0C0() < 0.03f) && func_80101E14(arg0, 0.1f)) {
            _subaddieaudioquick_entrypoint_2((s32) arg0, (s32) arg0->position, D_80801570_chfiregen);
        }
        if (arg0->unk54 < 0.6f) {
            arg0->unk54 = 0.6f;
        }
        if (arg0->unk5F == 0) {
            arg0->unk5F = func_800C4350(0, arg0->position, D_80801580_chfiregen);
        } else {
            func_800C31DC(arg0->unk5F, arg0->unk54 - 0.2f);
            func_800C4350(arg0->unk5F, 0, 0);
        }
        arg0->unk70_10 = 2;
        func_808008F4_chfiregen(arg0, 1);
        break;
    }
    if ((arg0->rotation[2] != (*((FireData *) arg0)).strength) && (((s32) arg0->unk50) != (-1))) {
        if (((FireData *) arg0)->cooldown < 0.0f) {
            arg0->rotation[2] = ((FireData *) arg0)->strength;
            ((FireData *) arg0)->cooldown = 0.25f;
        } else {
            ((FireData *) arg0)->cooldown = ((FireData *) arg0)->cooldown - dt;
        }
    }
    if (((FireData *) arg0)->morph > 0.02f) {
        model = func_801039E4((s32) arg0->unk0);
        mesh = func_80103CB8(arg0, model);
        _dbmorph_entrypoint_3(func_800B2768((u8 *) model), mesh, func_800B2840(model), 1, &((FireData *) arg0)->morph);
    }
}

s32 func_80800824_chfiregen(Actor *arg0) {
    switch (arg0->unk6C_9) {
    case 0x1AA:
        return 0;
    case 0x1AC:
        return 1;
    case 0x1AE:
        return 2;
    case 0x1B0:
        return 3;
    case 0x1B2:
        return 4;
    case 0x1B4:
        return 5;
    default:
        return 0;
    }
}

s32 func_80800890_chfiregen(Actor *arg0) {
    switch (arg0->unk6C_9) {
    case 0x1AA:
        return 0;
    case 0x1AC:
        return 5;
    case 0x1AE:
        return 8;
    case 0x1B0:
        return 0xB;
    case 0x1B2:
        return 0xF;
    default:
        return -1;
    }
}

/* extern */

void func_808008F4_chfiregen(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    s32 sp1C;

    func_800DA3B8(func_80800824_chfiregen(arg0), arg1);
    if ((arg1 != 0) && (func_800DA298(0x678) == 0)) {
        sp1C = func_80800890_chfiregen(arg0);
        if (sp1C != -1) {
            func_800DA3B8(0x678, 1);
            _capod_entrypoint_13(arg0->unk0, NULL, sp1C, 0x10);
        }
    }
}

/* extern */

void func_80800978_chfiregen(Actor *arg0, Unk80132ED0 *arg1) {
    void func_800FC63C(u32, u32);

    if ((arg1->unk24 >> 22) == 0x26D) {
        if ((s32)((f32 *)arg0->actorData)[5] == 0) {
            arg0->unk6C_0 = 0;
            }
        if ((s32)((f32 *)arg0->actorData)[5] < 2) {
            ((f32 *)arg0->actorData)[5] += 1.0f;
            arg0->unk58 = (s32)arg0->unk74_7 - 50;
        } else if ((s32)((f32 *)arg0->actorData)[5] == 2) {
            ((f32 *)arg0->actorData)[5] += 1.0f;
            if (arg0->unk6C_0 < 40) {
                func_800FC63C(0xE, 0x7FBC);
                arg0->unk58 = ((s32)arg0->unk74_7 - 50) * 1.5f;
            }
        }
    }
}

/* extern */

void func_80800A78_chfiregen(Actor *arg0) {
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    arg0->unk64_20 = 0;
    arg0->scale = 3.0f;
    arg0->unk50 = -1.0f;
    ((f32 *)arg0->actorData)[3] = func_800DC178(0.0f, 0.25f);
    ((f32 *)arg0->actorData)[0] = func_800DC178(0.0f, 1.0f);
    arg0->unk64_19 = func_800DC298(0.5f);
    if (func_800DA298(func_80800824_chfiregen(arg0)) != 0) {
        arg0->unk58 = (s32)arg0->unk74_7 - 50;
        arg0->unk70_10 = 2;
    }
}

void func_80800B4C_chfiregen(Actor *arg0, s32 arg1) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800DBEFC(void *, s32, f32[3]);
    int func_800DC298(f32);
    extern s32 D_80801784_chfiregen[];
    s32 sp34;
    f32 sp28[3];
    s32 var_a1;

    if (arg0->unk7C_12) {
        func_800DBEFC(arg0->unk0->unk4, 4, sp28);
        sp28[1] -= 100.0f;
        sp34 = func_800B53A4(arg1);
        var_a1 = func_800DC298(0.7f) ? 0x9DC : 0x9CA;
        func_800BA3FC(sp34, var_a1);
        func_800BABB8(sp34, sp28, 0, 1.0f, D_80801784_chfiregen);
        func_800BA22C(sp34, arg1);
    }
}

OSThread *chfiregen_entrypoint_6(void)
{
    extern u8 D_808017BC_chfiregen[];

    return (OSThread *) D_808017BC_chfiregen;
}

OSThread *chfiregen_entrypoint_7(void)
{
    extern u8 D_80801804_chfiregen[];

    return (OSThread *) D_80801804_chfiregen;
}

OSThread *chfiregen_entrypoint_8(void)
{
    extern u8 D_8080184C_chfiregen[];

    return (OSThread *) D_8080184C_chfiregen;
}

OSThread *chfiregen_entrypoint_9(void)
{
    extern u8 D_80801894_chfiregen[];

    return (OSThread *) D_80801894_chfiregen;
}

OSThread *chfiregen_entrypoint_10(void)
{
    extern u8 D_808018DC_chfiregen[];

    return (OSThread *) D_808018DC_chfiregen;
}

OSThread *chfiregen_entrypoint_11(void)
{
    extern u8 D_80801924_chfiregen[];

    return (OSThread *) D_80801924_chfiregen;
}

void func_80800C44_chfiregen(Actor *arg0) {
    f32 delta;
    s32 i;
    s32 color[3];
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    s32 func_800C8E84();

    delta = func_800D8FF8();
    if (((f32 *)arg0->actorData)[3] > 0.0f) {
        ((f32 *)arg0->actorData)[3] -= delta;
        return;
    }
    if (func_800DA298(arg0->unk6C_0)) {
        if (arg0->unk70_10 != 3) {
            arg0->unk70_10 = 2;
        }
    } else {
        if (arg0->unk70_10 != 1) {
            arg0->unk70_10 = 4;
        }
    }
    switch (arg0->unk70_10) {
    case 2:
        if (((f32 *)arg0->actorData)[6] <= 0.85f) {
            ((f32 *)arg0->actorData)[6] += 0.15f;
        } else {
            arg0->unk70_10 = 3;
        }
        break;
    case 4:
        if (((f32 *)arg0->actorData)[6] >= 0.08f) {
            ((f32 *)arg0->actorData)[6] -= 0.08f;
        } else {
            arg0->unk70_10 = 1;
        }
        break;
    }
    if (arg0->rotation[2] != ((f32 *)arg0->actorData)[6]) {
        for (i = 0; i < 3; i++) {
            color[i] = ((f32 *)arg0->actorData)[i] * ((f32 *)arg0->actorData)[6];
        }
        func_800C8E84((s32)arg0->unk50, (u32 *)color);
        arg0->rotation[2] = ((f32 *)arg0->actorData)[6];
        ((f32 *)arg0->actorData)[3] = 0.15f;
    }
}

/* extern */

void func_80800E54_chfiregen(u8 *arg0) {
    s32 func_800C8E84(s32, s32 *, u8 *);
    s32 func_800EE904(s32 *, u8 *, u8 *);
    s32 sp1C[3];

    if ((s32) (*(f32 *)((s8 *)(arg0) + (0x50))) != -1) {
        func_800EE904(sp1C, arg0 + 0x18, arg0);
        func_800C8E84((s32) (*(f32 *)((s8 *)(arg0) + (0x50))), sp1C, arg0);
    }
}

void func_80800EB8_chfiregen(Actor *arg0) {
    s32 func_800C8E84();
    void func_800C8800(s32, f32 *);
    void func_800C8900(s32, s32 *);
    s32 func_800C9128(f32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE84C(f32 *, s32 *);
    void func_800EFA88(void *, s32, s32, s32);
    s32 light;
    f32 position[3];
    s32 color[3];

    ((f32 *)arg0->actorData)[3] = func_800DC178(0.0f, 0.15f);
    arg0->unk50 = -1.0f;
    switch (arg0->unk6C_9) {
        case 0x1AB: arg0->unk6C_0 = 0; break;
        case 0x1AD: arg0->unk6C_0 = 1; break;
        case 0x1AF: arg0->unk6C_0 = 2; break;
        case 0x1B1: arg0->unk6C_0 = 3; break;
        case 0x1B3: arg0->unk6C_0 = 4; break;
        case 0x1B5: arg0->unk6C_0 = 5; break;
    }
    light = func_800C9128(arg0->position);
    arg0->unk50 = light;
    func_800C8800(light, position);
    func_800EE7F8((f32 *)arg0->actorData, position);
    func_800C8900(light, color);
    func_800EE84C((f32 *)arg0->actorData, color);
    func_800EFA88(color, 0, 0, 0);
    func_800C8E84((s32)arg0->unk50, color);
}

OSThread *chfiregen_entrypoint_12(void)
{
    extern u8 D_8080196C_chfiregen[];

    return (OSThread *) D_8080196C_chfiregen;
}

OSThread *chfiregen_entrypoint_13(void)
{
    extern u8 D_808019B4_chfiregen[];

    return (OSThread *) D_808019B4_chfiregen;
}

OSThread *chfiregen_entrypoint_14(void)
{
    extern u8 D_808019FC_chfiregen[];

    return (OSThread *) D_808019FC_chfiregen;
}

OSThread *chfiregen_entrypoint_15(void)
{
    extern u8 D_80801A44_chfiregen[];

    return (OSThread *) D_80801A44_chfiregen;
}

OSThread *chfiregen_entrypoint_16(void)
{
    extern u8 D_80801A8C_chfiregen[];

    return (OSThread *) D_80801A8C_chfiregen;
}

OSThread *chfiregen_entrypoint_17(void)
{
    extern u8 D_80801AD4_chfiregen[];

    return (OSThread *) D_80801AD4_chfiregen;
}

void *func_8080105C_chfiregen(Actor *arg0) {
    s32 sp1C;
    s32 _idworld_entrypoint_3(s32);

    switch (arg0->unk6C_9) {
    case 0x2AA:
        sp1C = 0x1AD;
        break;
    case 0x2AB:
        sp1C = 0x1AE;
        break;
    }
    _idworld_entrypoint_3(sp1C);
}

void *func_808010B4_chfiregen(Actor *arg0) {
    s32 sp1C;
    s32 _idworld_entrypoint_3(s32);

    switch (arg0->unk6C_9) {
    case 0x2AA:
        sp1C = 0x1B0;
        break;
    case 0x2AB:
        sp1C = 0x1B1;
        break;
    }
    _idworld_entrypoint_3(sp1C);
}

void func_8080110C_chfiregen(Actor *arg0) {
    f32 delta;
    void *effect;
    f32 color[4];
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    void func_800EDDDC(void *, f32[4], f32[4], f32);

    delta = func_800D8FF8();
    if (((f32 *)arg0->actorData)[3] > 0.0f) {
        ((f32 *)arg0->actorData)[3] -= delta;
        return;
    }
    if (func_800DA298(arg0->unk6C_0)) {
        if (arg0->unk70_10 != 3) {
            arg0->unk70_10 = 2;
        }
    } else {
        if (arg0->unk70_10 != 1) {
            arg0->unk70_10 = 4;
        }
    }
    switch (arg0->unk70_10) {
    case 2:
        if (((f32 *)arg0->actorData)[6] <= 0.85f) {
            ((f32 *)arg0->actorData)[6] += 0.15f;
        } else {
            arg0->unk70_10 = 3;
        }
        break;
    case 4:
        if (((f32 *)arg0->actorData)[6] >= 0.08f) {
            ((f32 *)arg0->actorData)[6] -= 0.08f;
        } else {
            arg0->unk70_10 = 1;
        }
        break;
    }
    if (arg0->rotation[2] != ((f32 *)arg0->actorData)[6]) {
        color[0] = ((f32 *)arg0->actorData)[6];
        color[1] = ((f32 *)arg0->actorData)[6];
        color[2] = ((f32 *)arg0->actorData)[6];
        color[3] = ((f32 *)arg0->actorData)[6];
        effect = func_8080105C_chfiregen(arg0);
        if (effect != NULL) {
            func_800EDDDC(effect, color, color, 5.0f);
        }
        effect = func_808010B4_chfiregen(arg0);
        if (effect != NULL) {
            func_800EDDDC(effect, color, color, 5.0f);
        }
        arg0->rotation[2] = ((f32 *)arg0->actorData)[6];
        ((f32 *)arg0->actorData)[3] = 0.15f;
    }
}

void func_808012F8_chfiregen(s32 arg0) 
{
}
void func_80801300_chfiregen(Actor *arg0) {
    void *effect;
    f32 sp24[4];
    f32 func_800DC178(f32, f32);
    void func_800EDDDC(void *, f32[4], f32[4], f32);

    sp24[0] = ((f32 *)arg0->actorData)[6];
    sp24[1] = ((f32 *)arg0->actorData)[6];
    sp24[2] = ((f32 *)arg0->actorData)[6];
    sp24[3] = ((f32 *)arg0->actorData)[6];
    ((f32 *)arg0->actorData)[3] = func_800DC178(0.0f, 0.15f);
    switch (arg0->unk6C_9) {
    case 0x2A7:
        arg0->unk6C_0 = 0;
        break;
    case 0x2A8:
        arg0->unk6C_0 = 1;
        break;
    case 0x2A9:
        arg0->unk6C_0 = 2;
        break;
    case 0x2AA:
        arg0->unk6C_0 = 3;
        break;
    case 0x2AB:
        arg0->unk6C_0 = 4;
        break;
    case 0x2AC:
        arg0->unk6C_0 = 5;
        break;
    }
    effect = func_8080105C_chfiregen(arg0);
    if (effect != NULL) {
        func_800EDDDC(effect, sp24, sp24, 5.0f);
    }
    effect = func_808010B4_chfiregen(arg0);
    if (effect != NULL) {
        func_800EDDDC(effect, sp24, sp24, 5.0f);
    }
}
