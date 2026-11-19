#include "common.h"
#include "core2/switch_animations.h"
OSThread *chfactorycrusher_entrypoint_0(void)
{
    extern ActorData D_80800A50_chfactorycrusher[];

    return (OSThread *) D_80800A50_chfactorycrusher;
}

OSThread *chfactorycrusher_entrypoint_1(void)
{
    extern ActorData D_80800A98_chfactorycrusher[];

    return (OSThread *) D_80800A98_chfactorycrusher;
}

/* extern */

void func_80800018_chfactorycrusher(Actor *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EF934(f32 *, f32 *, f32);
    f32 func_800F0E00(f32, f32);
    f32 func_800F13F0(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    s32 func_80104004(Actor *, f32 *, f32 *);
    void func_8010A63C(void *);
    f32 *temp_s3;
    f32 sp50[3];
    f32 sp44[3];
    s32 i;

    func_800EE7F8((f32 *)&arg0->actorData[0], arg0->position);
    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    func_800EF1B8((f32 *)&arg0->actorData[4], arg0->rotation[1], 500.0f);
    arg0->unk58 = 0.0f;
    func_8010A63C(arg0);
    temp_s3 = func_80100094(arg0, 0);
    if (func_80104004(arg0, sp50, sp44) != 0) {
        func_800EF934(sp50, sp50, arg0->rotation[1]);
        func_800EF934(sp44, sp44, arg0->rotation[1]);
        for (i = 0; i < 3; i++) {
            temp_s3[i] = func_800F13F0(sp50[i], sp44[i]);
            temp_s3[i + 3] = func_800F0E00(sp50[i], sp44[i]);
        }
    }
    if (arg0->unk74_7 != 0x32) {
        func_80101FDC(arg0, 6);
        func_80103110(arg0, 0);
    }
}

void func_80800150_chfactorycrusher(Actor *arg0) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    s32 func_800DA298(s32);
    void func_800E148C(s32, f32, f32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    f32 func_800F0E00(f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F5578(BtIntPtr);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F7F98(BtIntPtr, u32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80101FDC(Actor *, u32);
    void func_8010A624(Actor *);
    u32 func_8010A654(void ***, s32);
    void func_8010D640(BtIntPtr);
    f32 mlAbsF(f32);
    void func_808006CC_chfactorycrusher(Actor *);
    int func_80800738_chfactorycrusher(BtIntPtr, f32 *);
    int func_80800800_chfactorycrusher(Actor *);
    Actor *func_80800898_chfactorycrusher(Actor *);
    void func_808008B8_chfactorycrusher(BtIntPtr, f32);
    void func_808008F0_chfactorycrusher(Actor *);
    extern u8 D_80800AE0_chfactorycrusher[];
    struct {
        f32 bounds[6];
        s32 unk18;
    } *data;
    Actor *other;

    data = func_80100094(arg0, 0);
    other = func_80800898_chfactorycrusher(arg0);
    switch (arg0->unk70_10) {
        case 1: {
            f32 position[3];
            u32 animation;

            if (func_800DA298(0x329) == 0 && !arg0->unk64_19 && data->unk18 == 0
                && func_800D90A4(&arg0->unk58) != 0) {
                arg0->unk64_20 = 0;
                if (func_80800738_chfactorycrusher((BtIntPtr)arg0, position) != 0) {
                    if (func_800F64A4(func_800F54E4(), 0x10000) != 0
                        || func_800F5578(func_800F54E4()) >= 2) {
                        animation = ((f32 *)arg0->actorData)[0] < position[0] ? 0x22 : 0x1E;
                        _capod_entrypoint_13(arg0->unk0, NULL, animation, 0);
                        arg0->unk64_19 = 1;
                    }
                    func_800F7F98(func_800F54E4(), 1);
                    arg0->unk64_20 = 1;
                    func_80101180(0x3EE, 0xB9, 0);
                    func_8010A624(arg0);
                    func_8010A624(other);
                }
                func_80101FDC(arg0, 2);
                arg0->unk58 = 0.25f;
            }
            ((f32 *)arg0->actorData)[7] = 0.0f;
            break;
        }
        case 2: {
            s32 finished;
            f32 position[3];
            f32 shake;
            f32 progress;

            finished = func_800D9078(&arg0->unk58);
            progress = func_800F12D4(arg0->unk58, 0.0f, 0.25f, 1.0f, 0.0f);
            ((f32 *)arg0->actorData)[7] = progress;
            func_808008B8_chfactorycrusher((BtIntPtr)arg0, ((f32 *)arg0->actorData)[7]);
            func_808008B8_chfactorycrusher((BtIntPtr)other, ((f32 *)arg0->actorData)[7]);
            if (arg0->unk64_20) {
                func_808008F0_chfactorycrusher(arg0);
            }
            if (finished != 0) {
                if (arg0->unk74_7 == 0x32) {
                    func_800E148C(func_800E1610(2, 80.0f, 0.85f, (f32 *)&arg0->actorData[4]), 2000.0f, 8000.0f);
                    func_8010D640((BtIntPtr)position);
                    shake = (800.0f / func_800F0E00(800.0f, mlAbsF(position[2] - 4000.0f))) * 2.75f;
                    if (shake > 0.25f) {
                        func_80018820(0, shake, 0.35f);
                    }
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800AE0_chfactorycrusher);
                }
                func_80800800_chfactorycrusher(arg0);
                func_80101FDC(arg0, 3);
                arg0->unk58 = 0.35f;
            }
            break;
        }
        case 3:
            if (func_800D90A4(&arg0->unk58) != 0) {
                func_80101FDC(arg0, 4);
                arg0->unk58 = 1.5f;
            }
            ((f32 *)arg0->actorData)[7] = 1.0f;
            break;
        case 4: {
            f32 progress;
            s32 finished;

            finished = func_800D9078(&arg0->unk58);
            progress = func_800F12D4(arg0->unk58, 0.0f, 1.5f, 0.0f, 1.0f);
            ((f32 *)arg0->actorData)[7] = progress;
            func_808008B8_chfactorycrusher((BtIntPtr)arg0, ((f32 *)arg0->actorData)[7]);
            func_808008B8_chfactorycrusher((BtIntPtr)other, ((f32 *)arg0->actorData)[7]);
            if (finished != 0) {
                func_80101FDC(arg0, 1);
                if (arg0->unk64_20) {
                    arg0->unk58 = 2.0f;
                } else {
                    arg0->unk58 = 0.0f;
                }
                arg0->unk64_20 = 0;
            }
            break;
        }
        case 5:
            func_808008B8_chfactorycrusher((BtIntPtr)arg0, ((f32 *)arg0->actorData)[7]);
            func_808008B8_chfactorycrusher((BtIntPtr)other, ((f32 *)arg0->actorData)[7]);
            break;
    }
    if (!arg0->unk64_19) {
        func_808006CC_chfactorycrusher(arg0);
        func_808006CC_chfactorycrusher(other);
        if (!arg0->unk64_20) {
            func_8010A654((void ***)arg0, arg0->unk7C_12);
            func_8010A654((void ***)other, other->unk7C_12);
        }
    }
}

s32 func_80800580_chfactorycrusher(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *_subaddiefind_entrypoint_1(Actor *arg0, s32 arg1, s32 arg2, f32 *arg3);
    u32 func_800F54E4(void);
    s32 func_800F7F98(BtIntPtr, u32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    Actor *func_80800898_chfactorycrusher(Actor *);
    struct {
        f32 bounds[6];
        s32 unk18;
    } *data;
    Actor *other;
    Unk80132ED0 **found;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x95:
            found = _subaddiefind_entrypoint_1(arg0, 0x3BA, -1, 0);
            if (found != NULL) {
                arg0->unk3C = *found;
            }
            data->unk18 = 0;
            break;
        case 0xB:
        if ((arg2 == 0x1E) || (arg2 == 0x22)) {
            other = func_80800898_chfactorycrusher(arg0);
            arg0->unk64_19 = 0;
            other->unk64_19 = arg0->unk64_19;
            func_800F7F98(func_800F54E4(), 0);
            func_80101180(0x3EE, 0xBA, 0);
        }
        return 3;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_8080067C_chfactorycrusher(s32 arg0, s32 arg1) {
    f32 sp1C[3];

    func_800E3980(sp1C);
    if (sp1C[2] > 2500.0f) {
        func_80101870(arg0, arg1);
    }
}

/* extern */

void func_808006CC_chfactorycrusher(Actor *arg0) {
    void func_800EE780(f32 dst[3], f32 a[3], f32 b[3]);
    u32 func_800F54E4(void);
    void* func_80100094(Actor*, u32);
    s32 func_800F4D18(BtUIntPtr, f32 *, f32 *);
    f32 *sp3C;
    f32 sp30[3];
    f32 sp24[3];

    sp3C = func_80100094(arg0, 0U);
    func_800EE780(sp30, sp3C, arg0->position);
    func_800EE780(sp24, sp3C + 3, arg0->position);
    func_800F4D18(func_800F54E4(), sp30, sp24);
}

/* extern */

int func_80800738_chfactorycrusher(BtIntPtr arg0, f32 *arg1) {
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6478(BtIntPtr);
    f32 temp_f0;
    f32 temp_f0_2;

    if (func_800F6478(func_800F54E4()) == 0) {
        return 0;
    }
    func_800F5A00(func_800F54E4(), arg1);
    if (arg1[0] > -2350.0f && arg1[0] < 3550.0f
        && arg1[2] > 3400.0f && arg1[2] < 4600.0f) {
        return 1;
    }
    return 0;
}

/* extern */

int func_80800800_chfactorycrusher(Actor *arg0) {
    u32 func_800F54E4(void);
    s32 func_800F5578(BtIntPtr);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_800F7B9C(BtIntPtr arg0,u32 a1);
    s32 func_800F7F98(BtIntPtr, u32);
    void *func_80100094(Actor *, u32);
    struct {
        f32 position[3];
        f32 position2[3];
        s32 unk18;
    } *sp1C;
    BtIntPtr sp18;
    BtIntPtr temp_v0;
    int var_v0;

    sp1C = func_80100094(arg0, 0);
    var_v0 = 0;
    if (arg0->unk64_20) {
        temp_v0 = func_800F54E4();
        sp18 = temp_v0;
        if ((func_800F5578(temp_v0) == 1) && (func_800F64A4(sp18, 0x10000) == 0)) {
            func_800F7F98(sp18, 0);
            sp1C->unk18 = 1;
        }
        func_800F7B9C(sp18, 0x5C);
        return 1;
    }
    return var_v0;
}

/* extern */

Actor *func_80800898_chfactorycrusher(Actor *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    return func_80106790(arg0->unk3C);
}

void func_808008B8_chfactorycrusher(BtIntPtr arg0, f32 arg1) {
    void func_800EFE50(f32*, void*, void*, f32);
    func_800EFE50(arg0 + 4, arg0 + 0x18, arg0 + 0x28, arg1);
}

void func_808008F0_chfactorycrusher(Actor *arg0) {
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_800F8418(BtIntPtr, f32 *);
    f32 lower;
    f32 upper;
    f32 position[3];
    BtIntPtr player;
    Actor *crusher;

    player = func_800F54E4();
    crusher = func_80800898_chfactorycrusher(arg0);
    upper = arg0->position[2];
    lower = crusher->position[2];
    func_800F5A00(player, position);
    if (position[2] < lower) {
        position[2] = lower;
        func_800F8418(player, position);
    } else if (upper < position[2]) {
        position[2] = upper;
        func_800F8418(player, position);
    }
}

/* extern */

void func_80800984_chfactorycrusher(BtIntPtr arg0) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    void _chswitch_entrypoint_9(void *arg0);
    _chswitch_entrypoint_7(arg0, 0x329);
    _chswitch_entrypoint_8(arg0, 1);
    _chswitch_entrypoint_9(arg0);
}

/* extern */

s32 func_808009BC_chfactorycrusher(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void _chmrtannoy_entrypoint_0(void);
    if (arg1 == 7) {
        _chmrtannoy_entrypoint_0();
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1340U, 4U, arg0->position, 0xA3U);
        return 1;
    }
    return _chswitch_entrypoint_10((BtIntPtr) arg0, arg1, arg2);
}
/* data_to_c.py: from asm/data/overlays/ch/factory/crusher.data.s */
void func_80105834();
void func_80107C2C();

void _chswitch_entrypoint_6();
int func_80101870();
ActorData D_80800A50_chfactorycrusher [1] BT_DATA(4, overlays_ch_factory_crusher, 0x0) = { { 799, 954, 1866, 1, 0, (void (*)(struct Actor *))func_80800150_chfactorycrusher, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8080067C_chfactorycrusher, 0, 0, 0, 0, 8192, 1024, 0, 0, 28, 0, (void (*)(struct Actor *))func_80800018_chfactorycrusher, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 1026, (void (*)(struct Actor *, long, long))func_80800580_chfactorycrusher, 0 } };
ActorData D_80800A98_chfactorycrusher [1] BT_DATA(4, overlays_ch_factory_crusher, 0x48) = { { 835, 955, 2370, 1, (void *)D_8011A270, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800984_chfactorycrusher, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_808009BC_chfactorycrusher, 0 } };
u8 D_80800AE0_chfactorycrusher [32] BT_DATA(4, overlays_ch_factory_crusher, 0x90) = { 0, 0x13, 4, 0xCE, 0, 0xD, 0, 0xC0, 0, 0xD9, 0, 0x18, 0, 1, 7, 0xD0, 0x1F, 0x40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
