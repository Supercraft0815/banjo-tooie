#include "common.h"
#include "core2/actor_animation_entry.h"
OSThread *choctopus_entrypoint_0(void)
{
    extern ActorData D_808008F4_choctopus[];

    return (OSThread *) D_808008F4_choctopus;
}

void func_8080000C_choctopus(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor*);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.8f);
    arg0->actorData[6] = _subaddiesect_entrypoint_1(arg0);
}

void func_80800054_choctopus(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _subaddiesect_entrypoint_0(Actor *, s32, s32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void _subaddieaudioloop_entrypoint_5(Actor *, f32 *, s32, s32, s32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800D9078(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101CDC(Actor *, f32);
    void func_80102424(Actor *, s32);
    extern s16 D_808008C0_choctopus[6];
    extern ActorAnimationEntry D_808008CC_choctopus[5];
    extern s16 D_8080093C_choctopus[10];
    void *expression;
    f32 *position;

    expression = func_80100094(arg0, 1);
    _subaddiesect_entrypoint_0(arg0, arg0->actorData[6], 2);
    if (expression != NULL) {
        _suexpression_entrypoint_10(expression, arg0->unk0, 0);
    }
    position = arg0->position;
    _subaddieaudioloop_entrypoint_5(arg0, position, arg0->unk70_10 == 1, 0x1194, (s32 *)D_8080093C_choctopus);
    switch (arg0->unk70_10) {
        case 1:
            break;
        case 2:
            func_80101CDC(arg0, func_800F10B4(arg0->unk58, 0.0f, 1.25f, 30.0f, D_808008CC_choctopus[1].duration));
            if (func_800D9078(&arg0->unk58)) {
                func_80102424(arg0, 3);
                arg0->unk58 = 8.0f;
            }
            break;
        case 3:
            if (func_800D9078(&arg0->unk58)) {
                _subaddieaudioquick_entrypoint_2(arg0, position, D_808008C0_choctopus);
                func_80102424(arg0, 4);
                func_80101CDC(arg0, 30.0f);
                arg0->unk58 = 3.75f;
            }
            break;
        case 4:
            func_80101CDC(arg0, func_800F10B4(arg0->unk58, 0.0f, 3.75f, D_808008CC_choctopus[1].duration, 30.0f));
            if (func_800D9078(&arg0->unk58)) {
                func_80102424(arg0, 1);
                if (expression != NULL) {
                    _suexpression_entrypoint_18(expression, 0);
                }
                _subaddieDll_entrypoint_4(arg0, 0);
            }
            break;
    }
}

void func_808007E4_choctopus(BT_NATIVE_ONLY(Actor *bt_a0));

void func_80800210_choctopus(BT_NATIVE_ONLY(Actor *bt_a0))
{
    func_808007E4_choctopus(BT_NATIVE_ONLY(bt_a0));
}

void func_80800230_choctopus(Actor *arg0, s32 arg1) {
    s32 func_801015D0(Actor *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    int func_800F3214(void *, void *, void *, f32);
    void func_800DF5D8(u32, u32, u32, s32);
    extern s32 D_80800950_choctopus[][3];
    extern s32 D_80800980_choctopus[3];
    s32 value;
    s32 color[3];

    func_801015D0(arg0);
    switch (arg0->unk70_10) {
        case 2:
            value = func_800F10B4(arg0->unk58, 0.0, 1.25f, 255.0f, 0.0f);
            break;
        case 3:
            value = 255;
            break;
        case 4:
            value = func_800F10B4(arg0->unk58, 0.0, 3.75f, 0.0f, 255.0f);
            break;
        default:
            value = 0;
            break;
    }
    func_800F3214(color, D_80800950_choctopus[arg0->unk74_7 - 50], D_80800980_choctopus, (f32) value / 255.0f);
    func_800DF5D8(color[0], color[1], color[2], 255);
}

s32 func_80800348_choctopus(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_80800428_choctopus(Actor *, s32);
    void func_80800790_choctopus(Actor *);
    void _subaddiecustomhits_entrypoint_0(Actor *, void *);
#ifdef BT_NATIVE
    OSThread *choctopus_entrypoint_1(void);
#else
    extern s32 _choctopus_entrypoint_1;
#endif

    switch (arg1) {
        case 0x40:
            func_80800428_choctopus(arg0, arg2);
            break;
        case 0x1F:
            func_80800230_choctopus(arg0, arg2);
            break;
        case 0x29:
            func_80800790_choctopus(arg0);
            break;
        case 0x2A:
            func_808007E4_choctopus(arg0);
            break;
        case 0x1C:
            if (arg0->unk70_10 == 1) {
                return 2;
            }
            return 1;
        case 0x95:
            _subaddiecustomhits_entrypoint_0(arg0, &_choctopus_entrypoint_1);
            break;
        default:
            return 0;
    }
    return 1;
}

void *func_80100094(Actor *, u32);

void func_80800428_choctopus(Actor *arg0, s32 arg1) {
    s16 func_800CB854(s32 *);
    void func_80102424(Actor *, s32);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern s16 D_808008C0_choctopus[6];
    extern s16 D_8080098C_choctopus[6];
    s32 sp34;
    s32 sp30;
    void *sp2C;

    sp34 = arg0->unk6C_0 == 1;
    sp30 = func_800CB854(NULL) == 5;
    if (sp34 || sp30) {
        sp2C = func_80100094(arg0, 1);
        switch (arg0->unk70_10) {
            case 1:
                func_80102424(arg0, 2);
                _subaddieDll_entrypoint_4(arg0, 1);
                arg0->unk58 = 1.25f;
                if (sp2C != NULL) {
                    _suexpression_entrypoint_18(sp2C, 2);
                }
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808008C0_choctopus);
                if (!sp30) {
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080098C_choctopus);
                }
                break;
            case 3:
                arg0->unk58 = 8.0f;
                break;
        }
    }
}

s32 func_80800540_choctopus(Unk80132ED0 *arg0, f32 *arg1, f32 arg2, BtIntPtr arg3, s32 arg4) {
    s32 _subaddiecustomhits_entrypoint_3(Actor *, f32 *, f32);
    s32 func_800B1F8C(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, BtIntPtr arg5, f32 *arg6, f32 arg7, f32 *arg8, s32 arg9);
    s16 func_800CB854(s32 *);
    f32 func_800EFC7C(void *, void *);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    u8 *func_80103D98(Unk80132ED0 *);
    f32 func_80103F38(Actor *, f32 *);
    void *func_801040A8(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 mlAbsF(f32);
    Actor *actor;
    s32 sp78;
    f32 radius2;
    f32 sp68[3];
    f32 radius5;
    f32 sp58[3];
    f32 magnitude;
    f32 angle;
    s32 result;
    u8 *model;

    actor = func_80106790(arg0);
    if (_subaddiecustomhits_entrypoint_3(actor, arg1, arg2)) {
        return 0;
    }
    switch (func_800CB854(&sp78)) {
        case 2:
            radius2 = func_80103F38(actor, sp68);
            magnitude = arg2;
            magnitude += radius2 * 0.8f;
            return func_800EFFB4(sp68, magnitude, arg1);
        case 5:
            radius5 = func_80103F38(actor, sp58);
            magnitude = arg2;
            magnitude += radius5 * 0.8f;
            result = func_800EFFB4(sp58, magnitude, arg1);
            break;
        default:
            model = func_80103D98(arg0);
            if (!model) {
                return 0;
            }
            angle = func_800F1DCC(actor->rotation[1], func_800F1DF4(actor->position, arg1));
            magnitude = mlAbsF(angle);
            arg4 = 0;
            if (magnitude < 90.0f) arg4 = 8;
            if (magnitude > 35.0f) arg4 |= 2;
            if (angle < 35.0f) arg4 |= 0x10;
            if (angle > -35.0f) arg4 |= 4;
            angle = func_800EFC7C(actor->position, arg1);
            magnitude = actor->scale * 800.0f;
            if (magnitude * magnitude < angle) arg4 |= 0x201;
            result = func_800B1F8C(model, actor->position, actor->rotation, actor->scale, 0, func_801040A8(actor), arg1, arg2, arg3, arg4);
            break;
    }
    if (result) {
        actor->unk6C_0 = result;
    }
    return result;
}

OSThread *choctopus_entrypoint_1(void)
{
    extern BtFnWord D_80800998_choctopus[4];

    return (OSThread *) D_80800998_choctopus;
}

void func_80800790_choctopus(Actor *arg0) {
    void _suexpression_entrypoint_12(void*, f32, f32);
    void *_suexpression_entrypoint_7(Actor *arg0, s32 arg1, s16 arg2);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1U, 0xB6U);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 80.0f, 30.0f);
    }
}
void func_808007E4_choctopus(Actor *arg0) {
    void _suexpression_entrypoint_8(Actor *, s32);
    if (func_80100094(arg0, 1U) != 0) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#include "octopus_data.inc"
