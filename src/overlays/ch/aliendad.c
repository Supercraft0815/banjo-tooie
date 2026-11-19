#include "core2/actor_animation_entry.h"
#include "su/baddiedialog_descriptor.h"
extern ActorAnimationEntry D_808025F4_chaliendad[15];
void func_80105834(Actor *);
#include "actor_factory_decl.h"
void func_80800024_chaliendad(Actor *arg0);
void func_808000AC_chaliendad(Actor *arg0);
void func_808008C8_chaliendad(Actor *arg0);
void func_80800918_chaliendad(Actor *arg0, void *arg1);
s32 func_80800A54_chaliendad(Actor *arg0, s32 arg1, s32 arg2);

u32 D_80802670_chaliendad[] = {
    0x00000000,
};

BtFnWord D_80802674_chaliendad[] = {
    0x0158045A, 0x08070009,
    (BtFnWord)D_808025F4_chaliendad, (BtFnWord)func_808000AC_chaliendad,
    (BtFnWord)func_80105834, (BtFnWord)func_80800918_chaliendad,
    0x0BB80000, 0x00000000,
    0x00000000, 0x00040060,
    (BtFnWord)func_808008C8_chaliendad, 0x00000000,
    0x003C0000, (BtFnWord)func_80800024_chaliendad,
    (BtFnWord)func_80107C2C, 0x84400412,
    (BtFnWord)func_80800A54_chaliendad, 0x00000000,
};

extern ActorData D_808026BC_chaliendad[1];
/* The complete descriptor is defined with the other actors below. */


OSThread *chaliendad_entrypoint_0(void)
{


    return (OSThread *) D_80802674_chaliendad;
}

OSThread *chaliendad_entrypoint_1(void)
{


    return (OSThread *) D_808026BC_chaliendad;
}

OSThread *chaliendad_entrypoint_2(void)
{
    extern ActorData D_80802704_chaliendad[1];

    return (OSThread *) D_80802704_chaliendad;
}

void func_80800024_chaliendad(Actor *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE940(s16 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80801324_chaliendad(Actor *, s32);
    s32 func_80801DD0_chaliendad(void);
    s16 *sp24;

    sp24 = func_80100094(arg0, 0U);
    func_800EE940(sp24, arg0->position);
    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    sp24[3] = (s32)arg0->rotation[1];
    func_80801324_chaliendad(arg0, 0);
    if (func_80801DD0_chaliendad() == 3) {
        func_800FFAB0(arg0);
    }
}

void func_808000AC_chaliendad(Actor *arg0) {
    s32 _chbadshad_entrypoint_2(Actor *arg0, s32 arg1, f32 arg2, f32 *arg3);
    void _subaddieDll_entrypoint_4(Actor *, u32);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    void func_80018820(s32, f32, f32);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    void func_800DA544(s32 index);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(Unk80132ED0 *, s32, BtIntPtr);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_801022E4(Actor *);
    s32 func_80102320(Actor *, f32, f32);
    void func_80102424(Actor *, s32);
    void func_80108B04(Actor *, s32);
    void func_808012AC_chaliendad(Actor *);
    void func_80801324_chaliendad(Actor *, s32);
    void func_80801B9C_chaliendad(BtIntPtr);
    void func_80801C60_chaliendad(void *);
    void func_80801C9C_chaliendad(Actor *, s32, s32);
    void func_80801D40_chaliendad(Actor *, s32, s32, Unk80132ED0 *);
    void func_808022CC_chaliendad(Actor *);
    extern s16 D_8080274C_chaliendad[11], D_80802764_chaliendad[8];
    extern s16 D_80802774_chaliendad[7], D_80802784_chaliendad[7];
    extern s16 D_80802794_chaliendad[7], D_808027A4_chaliendad[7];
    extern s16 D_808027B4_chaliendad[6];
    extern s16 D_808027C0_chaliendad[5];
    extern s16 D_808027CC_chaliendad[4];
    extern s16 D_808027D4_chaliendad[19];
    extern s16 D_808027FC_chaliendad[6], D_80802808_chaliendad[6];
    extern s16 D_80802814_chaliendad[4];
    typedef struct {
        s16 position[3];
        s16 yaw;
        u8 active[3];
        u8 loopActive;
        f32 timers[3];
        u8 pad18[0x10];
        Unk80132ED0 *children[3];
        u32 unk34;
        u8 loop1;
        u8 loop2;
    } AlienData;
    typedef struct {
        f32 timer;
        f32 unk4[2];
        f32 velocity;
        f32 position[3];
        f32 unk1C;
    } AlienMotion;
    AlienData *sp74;
    void *sp70;
    Actor *sp6C;
    f32 sp60[3];
    s32 i;
    s32 count;
    f32 dy;
    s32 done;
    Actor *sp4C;
    f32 sp40[3];

    sp74 = func_80100094(arg0, 0);
    sp70 = func_80100094(arg0, 1);
    if (sp70 != NULL) {
        if (func_801022E4(arg0) != 0x367) {
            _suexpression_entrypoint_18(sp70, 1);
        }
        _suexpression_entrypoint_10(sp70, arg0->unk0, 0);
    }
    switch (arg0->unk70_10) {
        case 2:
            func_800EE7F8(((AlienMotion *)arg0->actorData)->position, arg0->position);
            if (_subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802764_chaliendad, 0.55f)) {
                func_80018820(0, 0.7f, 0.3f);
            }
            if (_subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802774_chaliendad, 0.71f)) {
                func_80018820(0, 1.0f, 0.3f);
            }
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802784_chaliendad, 0.92f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802794_chaliendad, 0.56f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_808027A4_chaliendad, 0.75f);
            sp74->loop2 = _subaddieaudioloop_entrypoint_7(sp74->loop2, arg0->position, func_80102320(arg0, 0.25f, 0.9f), D_808027B4_chaliendad, arg0->unk70_0);
            if (func_80101DDC(arg0)) {
                func_800EE88C(arg0->position, sp74->position);
                arg0->position[1] += 6500.0f;
                arg0->rotation[1] = sp74->yaw;
                func_80102424(arg0, 3);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1288, 0x44, arg0->position, 0x62);
                func_80801D40_chaliendad(arg0, 7, 0x31, NULL);
                ((AlienMotion *)arg0->actorData)->velocity = 800.0f;
                sp6C = _subaddiefind_entrypoint_2(0x45B, NULL);
                func_80102424(sp6C, 4);
                sp6C->unk64_16 = 1;
            }
            break;
        case 3:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_8080274C_chaliendad, 0.4f);
            ((AlienMotion *)arg0->actorData)->velocity += func_800D8FF8() * 600.0f;
            arg0->position[1] -= func_800D8FF8() * ((AlienMotion *)arg0->actorData)->velocity;
            break;
        case 4:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_8080274C_chaliendad, 0.4f);
            ((AlienMotion *)arg0->actorData)->velocity += func_800D8FF8() * 400.0f;
            arg0->position[1] -= func_800D8FF8() * ((AlienMotion *)arg0->actorData)->velocity;
            break;
        case 5:
            if (_subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_808027C0_chaliendad, 0.155f)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808027CC_chaliendad);
                func_80018820(0, 2.0f, 0.3f);
                func_800EE7F8(sp60, arg0->position);
                func_800EF1B8(sp60, arg0->rotation[1], -100.0f);
                func_800BBCB8(sp60, NULL, 1.2f, 1, (s32 *)D_808027D4_chaliendad);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1289, 0x44, arg0->position, 0x62);
            }
            if (func_80101E14(arg0, 0.9f)) {
                func_80801324_chaliendad(arg0, 1);
            }
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 6);
                _subaddieDll_entrypoint_4(arg0, 0);
            }
            break;
        case 7:
            if (func_800D9078(&arg0->unk58)) {
                func_80102424(arg0, 8);
            }
            break;
        case 8:
            if (func_80101E14(arg0, 0.1f)) {
                func_80801324_chaliendad(arg0, 3);
            }
            if (func_80101DDC(arg0)) {
                func_800DA544(0x376);
                func_80801C9C_chaliendad(arg0, 3, 1);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1287, 0xE, arg0->position, 0x62);
                func_80102424(arg0, 10);
            }
            break;
        case 11:
            if (func_80101E14(arg0, 0.2f)) {
                func_80108B04(arg0, 3);
            }
            if (func_80101DDC(arg0) && func_800D9078(&arg0->unk58)) {
                func_80801C60_chaliendad(arg0);
                func_8010114C(sp74->children[0], 0x4A, 0);
                func_80102424(arg0, 9);
            }
            break;
        case 9:
            func_80801B9C_chaliendad(arg0);
            break;
        case 12:
            count = 0;
            for (i = 0; i < 3; i++) {
                if (func_800D9078(&sp74->timers[i])) {
                    func_8010114C(sp74->children[i], 0x4E, 0);
                    sp74->active[i] = 1;
                    sp74->loopActive = 1;
                }
                if (sp74->active[i]) {
                    count++;
                }
            }
            if (count == 3) {
                func_80801D40_chaliendad(arg0, 0x41, 0x30, NULL);
                func_80102424(arg0, 13);
                func_80108B04(arg0, 2);
                arg0->unk58 = 2.0f;
            }
            break;
        case 13:
            if (func_80101DDC(arg0) && func_800D9078(&arg0->unk58)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808027FC_chaliendad);
                func_80102424(arg0, 14);
                arg0->unk58 = 4.0f;
                ((AlienMotion *)arg0->actorData)->velocity = 50.0f;
                ((AlienMotion *)arg0->actorData)->timer = 0.5f;
            }
            break;
        case 14:
            done = func_800D9078(&arg0->unk58);
            ((AlienMotion *)arg0->actorData)->velocity += func_800D8FF8() * 100.0f;
            dy = func_800D8FF8() * ((AlienMotion *)arg0->actorData)->velocity;
            arg0->position[1] += dy;
            if (func_800D9078(&((AlienMotion *)arg0->actorData)->timer)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80802808_chaliendad);
            }
            if (done) {
                sp4C = _subaddiefind_entrypoint_2(0x45B, NULL);
                func_8010114C(arg0->unk3C, 0x4F, 0);
                arg0->unk3C = NULL;
                func_800D1000(0x45, 1, arg0->position, 0, NULL);
                func_80801D40_chaliendad(arg0, 0x47, 0x31, sp4C->unk0);
                func_808022CC_chaliendad(sp4C);
                arg0->unk64_16 = 0;
                func_80102424(arg0, 15);
            }
            break;
    }
    sp74->loop1 = _subaddieaudioloop_entrypoint_7(sp74->loop1, arg0->position, sp74->loopActive, D_80802814_chaliendad, arg0->unk70_0);
    if (_subaddieskeleton_entrypoint_0(arg0, 0x2C, sp40)) {
        _sudeflect_entrypoint_0(sp40, 0.0f, 125.0f, 2);
    }
    if (_subaddieskeleton_entrypoint_0(arg0, 1, sp40)) {
        _sudeflect_entrypoint_0(sp40, 0.0f, 125.0f, 2);
    }
    func_808012AC_chaliendad(arg0);
    if (arg0->unk7C_12) {
        _chbadshad_entrypoint_2(arg0, 3, arg0->scale + arg0->scale, 0);
    }
}

void *func_80100094(Actor *, u32);    typedef struct { u8 pad0[0x38]; u8 unk38; u8 unk39; } Objaliendad_func_808008C8_chaliendad_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

void func_808008C8_chaliendad(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void func_80801E80_chaliendad(Actor *);
    void *sp1C;

    sp1C = func_80100094(arg0, 0U);
    (((Objaliendad_func_808008C8_chaliendad_sp1C *)sp1C)->unk38) = _subaddieaudioloop_entrypoint_3((((Objaliendad_func_808008C8_chaliendad_sp1C *)sp1C)->unk38));
    (((Objaliendad_func_808008C8_chaliendad_sp1C *)sp1C)->unk39) = _subaddieaudioloop_entrypoint_3((((Objaliendad_func_808008C8_chaliendad_sp1C *)sp1C)->unk39));
    func_80801E80_chaliendad(arg0);
}

void func_80800918_chaliendad(Actor *arg0, void *arg1) {
    s32 _chlifeforcespell_entrypoint_2(Actor *arg0, Unk80132ED0 *arg1, s32 *arg2);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void func_800DF744(s32, s32);
    void func_800E39A8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80101870(Actor *, void *);
    s32 *sp4C;
    f32 sp40[3];
    s32 sp34[3];
    s32 sp28[3];

    sp4C = func_80100094(arg0, 0U);
    if (arg0->unk70_10 == 2) {
        func_800E39A8(arg0->position, sp40);
        func_800EF214(arg0->position, sp40[0], sp40[1], -1000.0f);
        arg0->rotation[1] = sp40[1];
        arg0->rotation[0] = sp40[0] + 15.0f;
        func_800DF744(3, 1);
    } else {
        func_800DF744(3, 0);
    }
    func_800DF744(1, arg0->unk7A_11 + 1);
    func_800DF744(2, arg0->unk7A_11 + 1);
    if (sp4C[13] != 0) {
        _subaddiefade_entrypoint_9(arg0, sp28);
        _chlifeforcespell_entrypoint_2(arg0, sp4C[13], sp34);
        _subaddiefade_entrypoint_11(arg0, sp34);
        func_80101870(arg0, arg1);
        _subaddiefade_entrypoint_11(arg0, sp28);
        return;
    }
    func_80101870(arg0, arg1);
}

s32 func_80800A54_chaliendad(Actor *arg0, s32 arg1, s32 arg2) {
    extern f32 D_808025E4_chaliendad[4];
    Unk80132ED0 *_chlifeforcespell_entrypoint_1(Actor **arg0, f32 arg1[3], s32 arg2, f32 arg3, s32 arg4);
    void _gcdialogcamera_entrypoint_3(f32 *, f32);
    void _glcutDll_entrypoint_17(void);
    s32 _glcutDll_entrypoint_19(s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_800DA544(s32 index);
    void func_800E39A8(f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_80108B04(Actor *, s32);
    void func_80800F28_chaliendad(Actor *);
    void func_80801110_chaliendad(Actor *, s32, s32);
    void func_80801220_chaliendad(void *, s32, s32);
    s32 func_80801254_chaliendad(void *, s32, s32);
    void func_80801C60_chaliendad(void *);
    void func_80801D40_chaliendad(Actor *, s32, s32, Unk80132ED0 *);
    s32 func_80801DD0_chaliendad(void);
    void func_80801E28_chaliendad(Actor *);
    void func_80801E80_chaliendad(Actor *);
    s32 *data;
    f32 sp50[3];
    f32 sp44[3];
    Actor *child;
    f32 sp34[3];
    Actor *other;
    f32 sp24[3];

    data = func_80100094(arg0, 0U);
    switch (arg1) {
    default:
        return 0;
    case 0x95:
        func_80800F28_chaliendad(arg0);
        break;
    case 0x2E:
        func_80801110_chaliendad(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x2F:
        func_80801220_chaliendad(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x3D:
        switch (arg2) {
        case 0:
            func_800EE7F8(sp50, arg0->position);
            sp50[1] += 60.0f;
            data[13] = _chlifeforcespell_entrypoint_1(&arg0, sp50, 0x96, 3.2f, 0x12);
            break;
        case 1:
            func_800EE7F8(sp44, arg0->position);
            sp44[1] += 2000.0f;
            func_80108528(0x45B, sp44, 0, &arg0);
            break;
        case 2:
            child = func_80108528(0x466, arg0->position, 0, &arg0);
            arg0->unk3C = child->unk0;
            break;
        case 3:
            if (_subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp34)) {
                other = func_80108528(0x467, sp34, 0, &arg0);
                other->unk3C = arg0->unk0;
            }
            break;
        }
        break;
    case 0x4B:
        func_80108B04(arg0, 0);
        func_80801D40_chaliendad(arg0, 0x15, 0x30, NULL);
        func_80102424(arg0, 7);
        arg0->unk58 = 6.0f;
        break;
    case 0x4C:
        data[13] = 0;
        break;
    case 0xB:
        switch (arg2) {
        case 7:
            func_800EE88C(arg0->position, (s16 *)data);
            arg0->position[1] += 6500.0f;
            func_80102424(arg0, 4);
            func_80801D40_chaliendad(arg0, 0x2D, 0x31, NULL);
            *(f32 *)&arg0->actorData[3] = 800.0f;
            return 4;
        case 45:
            func_800EE88C(arg0->position, (s16 *)data);
            func_80801D40_chaliendad(arg0, 0x27, 0x30, NULL);
            func_80102424(arg0, 5);
            return 4;
        case 39:
            func_80801C60_chaliendad(arg0);
            if (_glcutDll_entrypoint_19(0x4A)) {
                _glcutDll_entrypoint_17();
            }
            func_800DA544(0x375);
            return 4;
        }
        return 3;
    case 0xE:
        if (arg0->unk70_10 == 2) {
            func_800E39A8(arg0->position, sp24);
            func_800EF214(arg0->position, sp24[0], sp24[1], -1000.0f);
            arg0->rotation[1] = sp24[1];
            arg0->rotation[0] = sp24[0] + 15.0f;
        }
        return 3;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808025E4_chaliendad, arg0->scale);
        break;
    case 0x57:
        return func_80801254_chaliendad(arg0, arg2 & 0xFFFF, (arg2 & 0xFFFF0000) >> 16);
    case 0x31:
        if (arg2 == 0x45B) {
            func_80801D40_chaliendad(arg0, 0x1A, 0x30, NULL);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x12AA, 7, arg0->position, 0x62);
            func_80102424(arg0, 10);
        } else if (func_80801DD0_chaliendad() == 3) {
            func_80108B04(arg0, 1);
            func_80801D40_chaliendad(arg0, 0x45, 0x2030, NULL);
        }
        break;
    case 0x29:
        func_80801E28_chaliendad(arg0);
        break;
    case 0x2A:
        func_80801E80_chaliendad(arg0);
        break;
    case 0x2C:
        func_80801C60_chaliendad(arg0);
        func_800FFAB0(arg0);
        break;
    case 0xB8:
        return 0x12A9 - func_80801DD0_chaliendad();
    }
    return 1;
}

void func_80800F28_chaliendad(Actor *arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 func_800DA298(s32);
    int func_800DB9B0(void);
    s32 func_800EA090(void);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80801324_chaliendad(Actor *, s32);
    void func_80801D40_chaliendad(Actor *, s32, s32, Unk80132ED0 *);
    Unk80132ED0 **data;
    Actor *other;
    Actor *child;
    s32 pad48;
    s32 cutscene;
    s32 active;
    s32 flags;
    s32 entrance;
    s32 allowed;
    s32 i;
    Unk80132ED0 **cursor;
    s32 pad28;

    data = func_80100094(arg0, 0U);
    other = _subaddiefind_entrypoint_2(0x45B, 0);
    arg0->unk64_20 = 0;
    if (func_800DA298(0x375) == 0) {
        cutscene = _glcutDll_entrypoint_19(0x4A);
        active = 0;
        flags = 0x30;
        if (cutscene == 0 && func_800DB9B0() == 0) {
            if (func_800DA298(0xB6) != 0) {
                entrance = func_800EA090();
                allowed = entrance != 0xA && entrance != 6;
                if (allowed) {
                    active = 1;
                }
            }
        } else {
            flags = 0x2830;
        }
        if (cutscene != 0 || active != 0) {
            arg0->unk64_20 = 1;
            func_80102424(arg0, 1);
            func_80101FDC(other, 2);
            arg0->unk64_16 = 0;
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x12A0, 0x44, arg0->position, 0x62);
            func_80801D40_chaliendad(arg0, 0x2A, flags, other->unk0);
        }
    }
    i = 0;
    cursor = data;
    do {
        child = _subaddiefind_entrypoint_2(i + 0x456, 0);
        if (child != NULL) {
            cursor[10] = child->unk0;
        } else {
            cursor[10] = NULL;
        }
        i++;
        cursor++;
    } while (i != 3);
    if (!arg0->unk64_20) {
        func_800FFAB0(other);
        if (func_800DA298(0x375) == 0) {
            func_800FFAB0(arg0);
            return;
        }
        if (func_800DA298(0x376) == 0) {
            func_80801324_chaliendad(arg0, 2);
            func_80102424(arg0, 6);
        }
    }
}

void func_80801110_chaliendad(Actor *arg0, s32 arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    u8 _subaddiedialog_entrypoint_9(void *arg0, s32 arg1, void *arg2, s32 arg3);
    void func_80102424(Actor *, s32);
    void func_80801D40_chaliendad(Actor *, s32, s32, Unk80132ED0 *);
    extern subaddiedialog_UnkStruct1 D_808025C0_chaliendad[3];
    extern f32 D_808025D8_chaliendad[3];
    extern f32 D_808025E4_chaliendad[4];
    f32 *sp2C;
    s32 i;

    sp2C = func_80100094(arg0, 0U);
    switch (arg1) {
    case 0x1287:
        func_80102424(arg0, 0xB);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x12B4, 0x144, arg0->position, 0x62);
        func_80801D40_chaliendad(arg0, 0x37, 0x30, NULL);
        arg0->unk58 = 1.5f;
        break;
    case 0x12AA:
        func_80801D40_chaliendad(arg0, 0x49, 0x30, NULL);
        func_80102424(arg0, 0xC);
        for (i = 0; i < 3; i++) {
            sp2C[i + 3] = D_808025D8_chaliendad[i];
        }
        break;
    default:
        if (_subaddiedialog_entrypoint_9(arg0, arg1, D_808025C0_chaliendad, 3) != 0) {
            func_80102424(arg0, 9);
        }
        break;
    }
}

void func_80801220_chaliendad(void *arg0, s32 arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    extern s16 D_8080281C_chaliendad[4];
    if (arg1 == 0x12A0) {
        _subaddieaudioquick_entrypoint_2(arg0, (u8 *)arg0 + 4, D_8080281C_chaliendad);
    }
}

/* extern */

s32 func_80801254_chaliendad(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_80801C9C_chaliendad(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x1C))) != 2) {
            func_80801C9C_chaliendad(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_808012AC_chaliendad(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_8080142C_chaliendad(void *);
    void func_8080152C_chaliendad(Actor *);
    void func_80801868_chaliendad(Actor *);
    struct {
        u8 pad0[0x18];
        s16 state;
    } *data;
    s16 state;

    data = func_80100094(arg0, 0U);
    state = data->state;
    switch (state) {
        case 0:
            func_8080142C_chaliendad(arg0);
            return;
        case 1:
            func_8080152C_chaliendad(arg0);
            return;
        case 3:
            func_80801868_chaliendad(arg0);
            return;
    }
}

void func_80801324_chaliendad(Actor *arg0, s32 arg1) {
    struct {
        u8 pad0[0x18];
        s16 state;
        s16 pad1A;
        f32 duration;
        f32 scale;
        f32 targetScale;
    } *data;
    struct {
        u8 pad0[0x78];
        BT_BITFIELD_ORDER(u32 pad78 : 18, u32 pad7B : 9);
        BT_BITFIELD_ORDER(u32 blinkState : 2, u32 blinkFrame : 3);
        BT_BITFIELD_ORDER(u32 blinkFrame : 3, u32 blinkState : 2);
        BT_BITFIELD_ORDER(u32 pad7B : 9, u32 pad78 : 18);
    } *actor = (void *)arg0;

    data = func_80100094(arg0, 0U);
    data->state = arg1;
    switch (arg1) {
        case 0:
            actor->blinkState = 0;
            actor->blinkFrame = 0;
            break;
        case 1:
            actor->blinkState = 0;
            actor->blinkFrame = 0;
            data->scale = 0.8f;
            data->targetScale = 0.8f;
            data->duration = 6.0f;
            break;
        case 2:
            actor->blinkFrame = 3;
            data->scale = 0.4f;
            data->targetScale = 0.4f;
            break;
        case 3:
            actor->blinkState = 2;
            actor->blinkFrame = 3;
            data->scale = 0.3f;
            data->targetScale = 0.3f;
            data->duration = 5.0f;
            break;
    }
}

void func_8080142C_chaliendad(void *arg0) {
    f32 func_800DC0C0(void);
    struct {
        u8 pad0[0x78];
        BT_BITFIELD_ORDER(u32 pad78 : 18, u32 pad7B : 9);
        BT_BITFIELD_ORDER(u32 blinkState : 2, u32 blinkFrame : 3);
        BT_BITFIELD_ORDER(u32 blinkFrame : 3, u32 blinkState : 2);
        BT_BITFIELD_ORDER(u32 pad7B : 9, u32 pad78 : 18);
    } *actor = arg0;

    switch (actor->blinkState) {
        case 0:
            if (func_800DC0C0() < 0.03f) {
                actor->blinkState = 1;
            }
            break;
        case 1:
            if (actor->blinkFrame == 3) {
                actor->blinkState = 3;
            } else {
                actor->blinkFrame++;
            }
            break;
        case 3:
            actor->blinkFrame--;
            if (actor->blinkFrame == 0) {
                actor->blinkState = 0;
            }
            break;
    }
}

void func_8080152C_chaliendad(Actor *arg0) {
    s32 func_800D90A4(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 pad;
    f32 progress;
    f32 blinkProgress;
    s32 expired;
    struct {
        u8 pad0[0x18];
        s16 state;
        s16 pad1A;
        f32 duration;
        f32 scale;
        f32 targetScale;
    } *data;
    struct {
        u8 pad0[0x78];
        BT_BITFIELD_ORDER(u32 pad78 : 18, u32 pad7B : 9);
        BT_BITFIELD_ORDER(u32 blinkState : 2, u32 blinkFrame : 3);
        BT_BITFIELD_ORDER(u32 blinkFrame : 3, u32 blinkState : 2);
        BT_BITFIELD_ORDER(u32 pad7B : 9, u32 pad78 : 18);
    } *actor = (void *)arg0;
    f32 duration;
    s32 frame;
    s32 padEnd;

    data = func_80100094(arg0, 0U);
    func_800D90A4(&data->duration);
    expired = func_800D90A4(&data->scale);
    progress = func_800F10B4(data->duration, 0.0f, 6.0f, 1.0f, 0.0f);
    blinkProgress = func_800F10B4(data->scale, 0.0f, data->targetScale, 1.0f, 0.0f);
    switch (actor->blinkState) {
        case 0:
            if (func_800D90A4(&data->scale)) {
                actor->blinkState = 1;
                duration = func_800F10B4(progress, 0.0f, 1.0f, 0.1f, 0.8f);
                data->targetScale = duration;
                data->scale = duration;
            }
            return;
        case 1:
            if (actor->blinkFrame == 3) {
                if (func_800D90A4(&data->scale)) {
                    actor->blinkState = 2;
                    duration = func_800F10B4(progress, 0.0f, 1.0f, 0.0f, 0.8f);
                    data->targetScale = duration;
                data->scale = duration;
                }
            } else {
                actor->blinkFrame++;
            }
            return;
        case 2:
            if (func_800D90A4(&data->scale)) {
                actor->blinkState = 3;
                duration = func_800F10B4(progress, 0.0f, 1.0f, 0.1f, 0.8f);
                data->targetScale = duration;
                data->scale = duration;
            }
            return;
        case 3:
            frame = func_800F10B4(progress, 0.0f, 1.0f, 0, 2.0f);
            actor->blinkFrame = func_800F10B4(blinkProgress, 0.0f, 1.0f, frame, 3.0f);
            if (expired) {
                actor->blinkFrame = frame;
                actor->blinkState = 0;
                duration = func_800F10B4(progress, 0.0f, 1.0f, 0.8f, 0.01f);
                data->targetScale = duration;
                data->scale = duration;
                if (progress == 1.0f) {
                    func_80801324_chaliendad(arg0, 2);
                }
            }
            return;
    }
}

void func_80801868_chaliendad(Actor *arg0) {
    s32 func_800D90A4(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 pad;
    f32 progress;
    f32 blinkProgress;
    s32 expired;
    struct {
        u8 pad0[0x18];
        s16 state;
        s16 pad1A;
        f32 duration;
        f32 scale;
        f32 targetScale;
    } *data;
    struct {
        u8 pad0[0x78];
        BT_BITFIELD_ORDER(u32 pad78 : 18, u32 pad7B : 9);
        BT_BITFIELD_ORDER(u32 blinkState : 2, u32 blinkFrame : 3);
        BT_BITFIELD_ORDER(u32 blinkFrame : 3, u32 blinkState : 2);
        BT_BITFIELD_ORDER(u32 pad7B : 9, u32 pad78 : 18);
    } *actor = (void *)arg0;
    f32 duration;
    s32 frame;
    s32 padEnd;

    data = func_80100094(arg0, 0U);
    func_800D90A4(&data->duration);
    expired = func_800D90A4(&data->scale);
    progress = func_800F10B4(data->duration, 0.0f, 6.0f, 1.0f, 0.0f);
    blinkProgress = func_800F10B4(data->scale, 0.0f, data->targetScale, 1.0f, 0.0f);
    switch (actor->blinkState) {
        case 0:
            if (func_800D90A4(&data->scale)) {
                actor->blinkState = 1;
                duration = func_800F10B4(progress, 0.0f, 1.0f, 0.8f, 0.1f);
                data->targetScale = duration;
                data->scale = duration;
            }
            return;
        case 1:
            if (actor->blinkFrame == 3) {
                if (func_800D90A4(&data->scale)) {
                    actor->blinkState = 2;
                    duration = func_800F10B4(progress, 0.0f, 1.0f, 0.8f, 0.0f);
                data->targetScale = duration;
                data->scale = duration;
                }
            } else {
                actor->blinkFrame++;
            }
            return;
        case 2:
            if (func_800D90A4(&data->scale)) {
                actor->blinkState = 3;
                duration = func_800F10B4(progress, 0.0f, 1.0f, 0.8f, 0.1f);
                data->targetScale = duration;
                data->scale = duration;
            }
            return;
        case 3:
            frame = func_800F10B4(progress, 0.0f, 1.0f, 2.0f, 0);
            actor->blinkFrame = func_800F10B4(blinkProgress, 0.0f, 1.0f, frame, 3.0f);
            if (expired) {
                actor->blinkFrame = frame;
                actor->blinkState = 0;
                duration = func_800F10B4(progress, 0.0f, 1.0f, 0.01f, 0.08f);
                data->targetScale = duration;
                data->scale = duration;
                if (progress == 1.0f) {
                    func_80801324_chaliendad(arg0, 0.0f);
                }
            }
            return;
    }
}

void func_80801B9C_chaliendad(BtIntPtr arg0) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, subaddiedialog_UnkStruct2 *, subaddiedialog_UnkStruct1 *, s32);
    extern subaddiedialog_UnkStruct1 D_808025C0_chaliendad[3];
    extern subaddiedialog_UnkStruct2 D_80802824_chaliendad;
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, &D_80802824_chaliendad, D_808025C0_chaliendad, 3);
}

/* extern */

void func_80801BD4_chaliendad(Actor *arg0) {
    void _subaddieDll_entrypoint_4(Actor *, u32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void func_80102424(Actor *, s32);
    void func_80801D40_chaliendad(Actor *, s32, s32, Unk80132ED0 *);
    Actor *temp_v0;

    arg0->unk64_16 = 1;
    _subaddieDll_entrypoint_4(arg0, 1);
    func_80102424(arg0, 2);
    _subaddiedialog_entrypoint_11(arg0->unk0, 0x12B3, 0x44, arg0->position, 0x62);
    func_80801D40_chaliendad(arg0, 0x22, 0x30, 0);
    temp_v0 = _subaddiefind_entrypoint_2(0x45B, 0);
    temp_v0->unk64_16 = 0;
}

/* extern */

void func_80801C60_chaliendad(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x1C))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x1C))) = 0;
    }
}

void func_80801C9C_chaliendad(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    void _capod_entrypoint_7(s32, s32);
    void _capod_entrypoint_8(s32 arg0);
    void _gcdialogcamera_entrypoint_3(f32 *, f32);
    void _gcdialogcamera_entrypoint_4(BtIntPtr arg0);
    void _gcdialogcamera_entrypoint_5(BtIntPtr arg0);
    void _gcdialogcamera_entrypoint_8(void);
    extern f32 D_808025E4_chaliendad[4];

    switch (arg0->actorData[1]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xD, 0);
        case 1:
            _capod_entrypoint_8(1);
            arg0->actorData[1] = 2;
            _gcdialogcamera_entrypoint_3(D_808025E4_chaliendad, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80801D40_chaliendad(Actor *arg0, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    s32 _capod_entrypoint_6(BtIntPtr arg0, s32 arg1, s32 arg2);

    if (arg3 == NULL) {
        arg3 = arg0->unk0;
    }
    switch (arg0->actorData[1]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xD, arg2);
        case 2:
            arg0->actorData[1] = 1;
        case 1:
            _capod_entrypoint_6(arg3, arg1, arg2);
            break;
    }
}

s32 func_80801DD0_chaliendad(void) {
    s32 func_800DA298(s32);
    s32 i;
    s32 count = 0;
    for (i = 0; i < 3; i++) {
        if (func_800DA298(i + 0x372)) {
            count++;
        }
    }
    return count;
}

/* extern */

void func_80801E28_chaliendad(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    BtIntPtr temp_v0;

    if (func_80100094(arg0, 1U) == NULL) {
        temp_v0 = _suexpression_entrypoint_7(arg0, 1, 0x62);
        _suexpression_entrypoint_12(temp_v0, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(temp_v0, 0x3E8);
    }
}

void func_80801E80_chaliendad(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_80801EB4_chaliendad(Actor *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void *func_80105494(Actor *);
    void func_80105A9C(Actor *, f32);
    f32 *data;

    data = func_80100094(arg0, 0U);
    data[2] = arg0->rotation[1];
    if (func_80105494(arg0) != NULL) {
        data[0] = 100.0f;
        data[1] = 100.0f;
        func_80105A9C(arg0, 1200.0f);
        if (func_80801DD0_chaliendad() == 3) {
            func_800FFAB0(arg0);
        }
    } else {
        data[1] = 100.0f;
        data[0] = 10.0f;
        func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
        func_800EE7F8((f32 *)arg0->actorData, arg0->position);
        ((f32 *)arg0->actorData)[1] = 1000.0f;
        func_80101FDC(arg0, 5);
        arg0->unk58 = 6.0f;
    }
}

void func_80801F98_chaliendad(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void func_80105834(Actor *);
    s32 func_80105998(Actor *, f32);
    s32 func_80105A5C(Actor *);
    void func_80802218_chaliendad(Actor *);
    void func_80802284_chaliendad(Actor *);

    func_80802218_chaliendad(arg0);
    switch (arg0->unk70_10) {
        case 3:
            break;
        case 2:
            func_80105834(arg0);
            if (func_80105998(arg0, 0.8f)) {
                func_80102424(arg0, 3);
                func_80801BD4_chaliendad(_subaddiefind_entrypoint_2(0x45A, 0));
            }
            break;
        case 4:
            func_80105834(arg0);
            if (func_80105A5C(arg0)) {
                func_800FFAB0(arg0);
            }
            break;
    }
    func_80802284_chaliendad(arg0);
}

void func_80802058_chaliendad(Actor *arg0) {
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80102424(Actor *, s32);
    void func_80802218_chaliendad(Actor *);
    void func_80802284_chaliendad(Actor *);
    s32 sp34;
    s32 pad30;
    s32 sp2C;
    s32 pad28;

    func_80802218_chaliendad(arg0);
    switch (arg0->unk70_10) {
        case 6:
            break;
        case 5:
            sp34 = func_800D9078(&arg0->unk58);
            func_800EFE50(arg0->position, (f32 *)&arg0->actorData[4],
                (f32 *)arg0->actorData,
                func_800F12D4(arg0->unk58, 0.0f, 6.0f, 1.0f, 0.0f));
            if (sp34) {
                func_80101180(0x45A, 0x31, arg0->unk6C_9);
                func_80102424(arg0, 6);
            }
            break;
        case 7:
            sp2C = func_800D9078(&arg0->unk58);
            ((f32 *)arg0->actorData)[3] += func_800D8FF8() * 300.0f;
            arg0->position[1] += ((f32 *)arg0->actorData)[3] * func_800D8FF8();
            if (sp2C) {
                func_80101180(0x45A, 0x2C, 0);
                func_800FFAB0(arg0);
            }
            break;
    }
    func_80802284_chaliendad(arg0);
}

void func_80802188_chaliendad(Actor *arg0, s32 arg1) {
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF47C(s32, BtIntPtr);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 *func_801018D8(Actor *);
    int func_80101970(Actor *);
    BtIntPtr func_8010347C(Unk80132ED0 *);
    s32 func_801015D0(Actor *);
    f32 sp34[3];
    f32 *sp30;

    sp30 = func_80100094(arg0, 0U);
    func_80101970(arg0);
    func_800EFA4C(sp34, arg0->rotation[0], sp30[2], arg0->rotation[2]);
    func_800DF47C(&func_801015D0, arg0);
    func_800DE448(arg0->position, sp34, arg0->scale, func_801018D8(arg0), func_8010347C(arg0->unk0));
}    typedef struct { f32 unk0; f32 unk4; f32 unk8; } Objaliendad_func_80802218_chaliendad_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

void func_80802218_chaliendad(Actor *arg0) {
    f32 func_800D8FF8();
    f32 func_800F15F8(f32, f32, f32);
    void *sp1C;
    f32 sp18;
    f32 temp_f0;
    f32 temp_f0_2;

    sp1C = func_80100094(arg0, 0U);
    temp_f0 = func_800D8FF8();
    sp18 = temp_f0;
    temp_f0_2 = func_800F15F8((((Objaliendad_func_80802218_chaliendad_sp1C *)sp1C)->unk4), (((Objaliendad_func_80802218_chaliendad_sp1C *)sp1C)->unk0), temp_f0 * 15.0f);
    (((Objaliendad_func_80802218_chaliendad_sp1C *)sp1C)->unk4) = temp_f0_2;
    (((Objaliendad_func_80802218_chaliendad_sp1C *)sp1C)->unk8) = (f32) ((((Objaliendad_func_80802218_chaliendad_sp1C *)sp1C)->unk8) + (temp_f0_2 * sp18));
}

void func_80802284_chaliendad(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    void func_80103DFC(Actor*, f32*);
    extern s16 D_80802834_chaliendad[9];
    f32 sp1C[3];

    func_80103DFC(arg0, sp1C);
    _subaddieaudioloop_entrypoint_4(arg0, sp1C, (arg0->unk70_10 ^ 1) != 0, D_80802834_chaliendad);
}

void func_808022CC_chaliendad(Actor *arg0) {
    void func_80102424(Actor *, s32);
    f32 *sp1C;
    sp1C = func_80100094(arg0, 0);
    func_80102424(arg0, 7);
    *(f32 *)&arg0->actorData[3] = 100.0f;
    arg0->unk58 = 5.0f;
    sp1C[0] = 100.0f;
    sp1C[1] = 10.0f;
}    typedef struct { u8 pad0[0x58]; f32 unk58; } Objaliendad_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80802330_chaliendad(Actor *arg0) {
    (((Objaliendad_arg0 *)arg0)->unk58) = 0.85f;
}
#include "aliendad_tail_data.inc"
void func_80802340_chaliendad(Actor *arg0) {
    void _subaddiefade_entrypoint_3(Actor *);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    f32 func_800138D0(f32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_80102424(Actor *, s32);
    void func_80102FDC(void *, f32);
    s32 sp2C;

    _subaddieskeleton_entrypoint_2(arg0->unk3C, 4, arg0->position);
    switch (arg0->unk70_10) {
        case 1:
            sp2C = func_800D9078(&arg0->unk58);
            func_80102FDC(arg0, func_800F12D4(arg0->unk58, 0.0f, 0.85f, 0.2f, 0.08f));
            if (sp2C != 0) {
                func_80102424(arg0, 2);
                arg0->unk58 = 2.5f;
            }
            break;
        case 2:
            *(f32 *)&arg0->actorData[3] += func_800D8FF8() * 800.0f;
            func_80102FDC(arg0, func_800138D0(*(f32 *)&arg0->actorData[3]) * 0.080000006f + 0.2f);
            if (func_800D9078(&arg0->unk58) != 0) {
                func_80102424(arg0, 3);
                _subaddiefade_entrypoint_3(arg0);
            }
            break;
        case 3:
            break;
    }
}
