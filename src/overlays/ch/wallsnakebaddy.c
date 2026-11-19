#include "common.h"

void func_80800000_chwallsnakebaddy(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    f32 func_800D8FF8(void);
    u32 func_800F54E4(void);
    f32 func_800F5F7C(BtUIntPtr);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_80107070(Actor *, u32);
    s32 func_8010CA74(f32 *, s32);
    extern s32 D_808006F4_chwallsnakebaddy[3];
    extern s32 D_80800700_chwallsnakebaddy[4];
    extern s32 D_80800710_chwallsnakebaddy[4];
    f32 y;

    switch (arg0->unk70_10) {
    case 1:
        if (arg0->unk58 > 0.0f) {
            arg0->unk58 -= func_800D8FF8();
            break;
        }
        y = func_800F5F7C(func_800F54E4());
        if ((arg0->unk64_29 && _subaddiejoy_entrypoint_6((u8 *)arg0, 1) == 1) ||
            (!arg0->unk64_29 && func_8010CA74(arg0->position, arg0->unk74_7))) {
            if (y <= arg0->position[1]
                ? arg0->position[1] - 500.0f <= y
                : y <= arg0->position[1] + 360.0f) {
                func_80102424(arg0, y <= arg0->position[1] ? 2 : 3);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808006F4_chwallsnakebaddy);
            }
        }
        break;
    case 2:
    case 3:
        if (func_80101E14(arg0, 0.18f) || func_80101E14(arg0, 0.31f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800700_chwallsnakebaddy);
        }
        if (func_80101E14(arg0, 0.6f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800710_chwallsnakebaddy);
        }
        if (func_80101E14(arg0, 0.999f)) {
            func_80102424(arg0, 1);
            arg0->unk58 = 0.4f;
        }
        break;
    case 4:
    case 5:
        if (func_80101DDC(arg0)) {
            func_80107070(arg0, 3);
        }
        if (func_80101F24(arg0) > 0.7f) {
            arg0->unk64_19 = 0;
        }
        break;
    }
}

void func_8080027C_chwallsnakebaddy(Actor *arg0, void *arg1) {
    s32 func_8001211C(void);
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA670(BtIntPtr, s32);
    void func_800BAB80(BtIntPtr, f32 *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800DBEFC(s32 *, s32, f32 *);
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);
    OSThread *func_80104130(void);
    s32 func_801072A8(void *);
    extern s32 D_80800720_chwallsnakebaddy[];
    extern s16 D_80800750_chwallsnakebaddy[6];

    extern u8 D_8080075C_chwallsnakebaddy[];
    extern s32 D_80800764_chwallsnakebaddy[];
    extern s32 D_8080078C_chwallsnakebaddy[];
    extern f32 D_80800798_chwallsnakebaddy[];
    BtIntPtr smokeEmitter;
    s32 active;
    f32 position[3];
    u8 *count;
    s16 *model;
    BtIntPtr emitter;
    s32 state;
    s32 visible;

    state = arg0->unk70_10;
    active = (state == 4 || state == 5) ? 1 : 0;
    visible = (state == 1 || func_801072A8(arg0)) ? 0 : 1;
    func_800DF744(3, visible);
    func_800DF744(4, active ^ 1);
    func_800DF744(5, active);
    func_80101870(arg0, arg1);
    if (arg0->unk7C_12) {
        if (arg0->unk64_20) {
            arg0->unk64_20 = 0;
            arg0->unk64_19 = 1;
            func_800DBEFC(func_80104130(), 4, position);
            count = D_8080075C_chwallsnakebaddy; model = D_80800750_chwallsnakebaddy;
            do {
                emitter = func_800B53A4(*count);
                func_800BA670(emitter, *model);
                func_800BABB8(emitter, position, position, arg0->scale, D_80800764_chwallsnakebaddy);
                func_800BA22C(emitter, *count);
                count++;
            } while (++model != &D_80800750_chwallsnakebaddy[5]);
            emitter = func_800B53A4(5);
            func_800BABB8(emitter, position, NULL, arg0->scale, D_80800720_chwallsnakebaddy);
            func_800BABB8(emitter, position, NULL, arg0->scale, D_8080078C_chwallsnakebaddy);
            func_800BA22C(emitter, 5);
        }
        if (arg0->unk64_19) {
            if (func_801072A8(arg0)) {
                arg0->unk64_19 = 0;
            }
            func_800DBEFC(func_80104130(), 4, position);
            if ((func_8001211C() & 1) == 1) {
                smokeEmitter = func_800B53A4(1);
                func_800BABB8(smokeEmitter, position, NULL, arg0->scale * 0.35f, D_80800720_chwallsnakebaddy);
                func_800BAB80(smokeEmitter, D_80800798_chwallsnakebaddy);
                func_800BA22C(smokeEmitter, 1);
            }
        }
    }
}

void func_808004FC_chwallsnakebaddy(Actor *arg0, s32 arg1) {
    extern Actor *_chbaddiesetup_entrypoint_10(s32 id, s32 x, s32 y, s32 z, s32 yaw);
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80102424(Actor *, s32);
    s32 func_8010A430(void *);
    void func_8010A570(Actor *);
    extern s32 D_8080079C_chwallsnakebaddy[3];
    extern s32 D_808007A8_chwallsnakebaddy[3];
    f32 position[3];

    arg0->unk64_20 = 1;
    func_8010A570(arg0);
    func_80102424(arg0, arg0->unk70_10 == 2 ? 4 : 5);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080079C_chwallsnakebaddy);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808007A8_chwallsnakebaddy);
    if (func_8010A430(arg0)) {
        func_800EE7F8(position, arg0->position);
        func_800EF1B8(position, arg0->rotation[1], 60.0f);
        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 3,
            ((s32 *)position)[0], ((s32 *)position)[1], ((s32 *)position)[2], ((s32 *)arg0->rotation)[1]);
    }
}

s32 func_808005D8_chwallsnakebaddy(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_808004FC_chwallsnakebaddy(Actor *, s32);
    void func_800EEB9C(f32[3], f32, f32);
    void func_80101010(f32 *);
    f32 sp1C[3];
    switch (arg1) {
        case 0x40:
            func_808004FC_chwallsnakebaddy(arg0, arg2);
            break;
        case 0x97:
            func_800EEB9C(sp1C, arg0->rotation[1], 150.0f);
            func_80101010(sp1C);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800650_chwallsnakebaddy(BT_NATIVE_ONLY(s32 bt_a0))
{
    func_80105010(BT_NATIVE_ONLY(bt_a0));
}

OSThread *chwallsnakebaddy_entrypoint_0(void)
{
    extern ActorData D_808007B4_chwallsnakebaddy[];
    return (OSThread *) D_808007B4_chwallsnakebaddy;
}
#include "wallsnakebaddy_data.inc"
