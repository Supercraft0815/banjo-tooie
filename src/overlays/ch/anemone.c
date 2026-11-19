#include "common.h"

OSThread *chanemone_entrypoint_0(void)
{
    extern ActorData D_808008D8_chanemone[];

    return (OSThread *) D_808008D8_chanemone;
}

void func_8080000C_chanemone(Actor *arg0) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void _subaddieaudioloop_entrypoint_5(BtIntPtr, BtIntPtr, s32, s32, s32 *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    s32 func_800D9078(f32 *);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void func_8010A590(Actor *);
    s32 func_8010D23C(void);
    void func_808003A8_chanemone(Actor *);
    extern s16 D_80800920_chanemone[10];
    extern s16 D_80800934_chanemone[8];
    extern s16 D_80800944_chanemone[8];
    s32 flags = 4;
    s32 active = arg0->unk70_10 != 3;

    func_808003A8_chanemone(arg0);
    if (func_8010D23C()) {
        if (arg0->unk70_10 != 1) {
            flags = 0x1E;
        }
        if (func_800F64A4(func_800F54E4(), 0x400)) {
            flags |= 2;
        }
    }
    if (active) {
        _sudeflect_entrypoint_1(arg0->position, arg0->scale * 850.0f, 0.0f, arg0->scale * 600.0f, flags);
        _sudeflect_entrypoint_0(arg0->position, arg0->scale * 800.0f, arg0->scale * 600.0f, flags);
    } else {
        _sudeflect_entrypoint_0(arg0->position, arg0->scale * 250.0f, arg0->scale * 700.0f, flags);
    }
    _subaddieaudioloop_entrypoint_5((BtIntPtr)arg0, (BtIntPtr)arg0->position, arg0->unk70_10 == 1, 2000, (s32 *)D_80800920_chanemone);
    switch (arg0->unk70_10) {
        case 2:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800934_chanemone, 0.2f);
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 3);
                arg0->unk58 = 6.0f;
            }
            break;
        case 3:
            if (func_800D9078(&arg0->unk58)) {
                func_80102424(arg0, 4);
            }
            break;
        case 4:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800944_chanemone, 0.6f);
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 1);
                _subaddieDll_entrypoint_4(arg0, 0);
                func_8010A590(arg0);
            }
            break;
    }
}

/* extern */

void func_80800260_chanemone(Actor *arg0) { s32 _subaddiesect_entrypoint_1(Actor *);
    s32 _subaddiesect_entrypoint_2(void *, s32, s32);
    f32 func_800DC178(f32, f32);
    void func_80102FDC(Actor *, f32);
    s32 temp_v0;

    func_80102FDC(arg0, arg0->scale * 0.5f); arg0->unk54 = 0.0f; ((f32 *)arg0->actorData)[4] = 0.0f; arg0->unk50 = 0.0f; ((f32 *)arg0->actorData)[5] = 0.0f; ((f32 *)arg0->actorData)[7] = func_800DC178(0.5f, 2.0f); temp_v0 = _subaddiesect_entrypoint_1(arg0); arg0->actorData[6] = temp_v0; _subaddiesect_entrypoint_2(arg0, temp_v0, 0);
}

s32 func_808002E8_chanemone(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_808005A0_chanemone(Actor *, s32);
    void _subaddiecustomhits_entrypoint_0(Actor *, void *);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    BtIntPtr func_8010262C(Unk80132ED0 *, u32);
#ifdef BT_NATIVE
    OSThread *chanemone_entrypoint_1(void);
#else
    extern s32 _chanemone_entrypoint_1;
#endif
    BtIntPtr model;

    switch (arg1) {
        case 0x3F:
            func_808005A0_chanemone(arg0, arg2);
            return 1;
        case 0x95:
            _subaddiecustomhits_entrypoint_0(arg0, &_chanemone_entrypoint_1);
            return 1;
        case 0x9C:
            model = func_8010262C(arg0->unk0, 1);
            if (model != 0) {
                func_800E0AFC((void *)model, 0x64, 1.0f,
                    ((f32 *)arg0->actorData)[5], ((f32 *)arg0->actorData)[4], 0.0f);
                return 1;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808003A8_chanemone(Actor *arg0) {
    f32 func_80013728(f32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F0D50(f32, f32, f32);
    void func_800F18FC(f32 *, f32 *, f32 *);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    s32 func_8010D23C(void);
    void func_8010D254(f32 *);
    f32 dt;
    f32 player[3];
    f32 position[3];
    f32 angles[2];

    dt = func_800D8FF8();
    if (func_8010D23C() != 0) {
        func_8010D254(player);
        func_800EE7F8(position, arg0->position);
        position[1] += arg0->scale + 200.0f;
        func_800EF1B8(position, arg0->rotation[1], arg0->scale * 300.0f);
        if (func_800EEB40(player, position) < 2250000.0f) {
            func_800F18FC(position, player, angles);
            arg0->unk54 = angles[1] - arg0->rotation[1];
            arg0->unk50 = -angles[0];
        } else if (func_800D9078(&((f32 *)arg0->actorData)[7]) != 0) {
            arg0->unk54 = func_800DC178(-60.0f, 60.0f);
            arg0->unk50 = func_800DC178(-50.0f, 50.0f);
            ((f32 *)arg0->actorData)[7] = func_800DC178(0.5f, 2.0f);
        }
    } else {
        arg0->unk54 = 0.0f;
        arg0->unk50 = 0.0f;
    }
    arg0->unk54 = func_800F0D50(func_80013728(arg0->unk54), -60.0f, 60.0f);
    arg0->unk50 = func_800F0D50(func_80013728(arg0->unk50), -50.0f, 50.0f);
    ((f32 *)arg0->actorData)[4] = func_800F1FF0(((f32 *)arg0->actorData)[4], arg0->unk54, 0.1f, 4.0f * dt, 60.0f * dt);
    ((f32 *)arg0->actorData)[5] = func_800F1FF0(((f32 *)arg0->actorData)[5], arg0->unk50, 0.1f, 4.0f * dt, 60.0f * dt);
}

void func_808005A0_chanemone(Actor *arg0, s32 arg1) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    extern s16 D_80800954_chanemone[8];
    u32 state;

    if ((s32)arg0->unk6C_0 == 1) {
        state = arg0->unk70_10;
        if (state == 1) {
            goto activate;
        }
        if (state == 3) {
            goto extend;
        }
        if (state == 4) {
activate:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800954_chanemone);
            func_80102424(arg0, 2);
            _subaddieDll_entrypoint_4(arg0, 1);
            func_8010A570(arg0);
            goto done;
        }
        goto done;
extend:
        arg0->unk58 = 6.0f;
    }
done:;
}

s32 func_80800648_chanemone(Unk80132ED0 *arg0, BtIntPtr arg1, f32 arg2, BtIntPtr arg3, s32 arg4)
{
    f32 func_800136E4(f32);
    s32 func_800B1F8C(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, BtIntPtr arg5, f32 *arg6, f32 arg7, f32 *arg8, s32 arg9);
    s16 func_800CB854(BtIntPtr *);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF04C(f32 *, f32 *);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    u8 *func_80103D98(Unk80132ED0 *);
    void *func_801040A8(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    s32 result;
    BtIntPtr sp64;
    f32 sp58[3];
    u8 *sp54;
    f32 angle;
    u8 *sp4C;

    actor = func_80106790(arg0);
    switch (func_800CB854(&sp64)) {
    case 2:
        func_800EE88C(sp58, (s16 *)&arg0->unk1C + 1);
        func_800EF04C(sp58, actor->position);
        return func_800EFFB4(sp58, (u32)*(u16 *)&actor->pad68 * 0.8f * actor->scale + arg2, (f32 *)arg1);
    case 5:
        sp54 = func_80103D98(arg0);
        if (sp54 == NULL) {
            return 0;
        }
        result = func_800B1F8C(sp54, actor->position, actor->rotation, actor->scale, 0, func_801040A8(actor), arg1, arg2, arg3, 30);
        break;
    default:
        sp4C = func_80103D98(arg0);
        if (sp4C == NULL) {
            return 0;
        }
        angle = func_800136E4(func_800F1DCC(func_800F1DF4(actor->position, (f32 *)arg1), actor->rotation[1]));
        if (angle < 90.0f) {
            arg4 = 12;
        } else if (angle < 180.0f) {
            arg4 = 24;
        } else if (angle < 270.0f) {
            arg4 = 18;
        } else {
            arg4 = 6;
        }
        result = func_800B1F8C(sp4C, actor->position, actor->rotation, actor->scale, 0, func_801040A8(actor), arg1, arg2, arg3, arg4);
        break;
    }
    if (result != 0) {
        actor->unk6C_0 = result;
    }
    return result;
}

OSThread *chanemone_entrypoint_1(void)
{
    extern BtFnWord D_80800964_chanemone[4];
    return (OSThread *) D_80800964_chanemone;
}
#include "anemone_data.inc"
