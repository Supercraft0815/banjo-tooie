#include "common.h"

OSThread *chpoolkids_entrypoint_0(void)
{
    extern ActorData D_808013F0_chpoolkids[];

    return (OSThread *) D_808013F0_chpoolkids;
}

OSThread *chpoolkids_entrypoint_1(void)
{
    extern ActorData D_80801438_chpoolkids[];

    return (OSThread *) D_80801438_chpoolkids;
}

OSThread *chpoolkids_entrypoint_2(void)
{
    extern ActorData D_80801480_chpoolkids[];

    return (OSThread *) D_80801480_chpoolkids;
}    typedef struct { u8 pad0[0x30]; s32 unk30; } Objpoolkids_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

BT_NATIVE_ONLY(struct player_state_s; s32 _subaddiesect_entrypoint_1(Actor *);) void func_80800024_chpoolkids(void *arg0) {
    BT_IDO_ONLY(s32 _subaddiesect_entrypoint_1();)
    s32 _subaddiesect_entrypoint_2(void *, s32, s32);
    s32 temp_v0;

    temp_v0 = _subaddiesect_entrypoint_1(BT_NATIVE_ONLY((Actor *)arg0));
    (((Objpoolkids_arg0 *)arg0)->unk30) = temp_v0;
    _subaddiesect_entrypoint_2(arg0, temp_v0, 1);
}

void func_80800058_chpoolkids(Actor *arg0) {
    void _glcutDll_entrypoint_17(void);
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    f32 func_80013970(f32);
    s32 func_8008FB58(f32 *, f32, f32);
    s32 func_800D9078();
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_80101F24(Actor *);
    s32 func_801022E4(Actor *);
    struct anctrl_s *func_80104248(void *);
    void func_808008DC_chpoolkids(u8 *);
    void func_80800944_chpoolkids(Actor *, f32);
    void func_80800AA0_chpoolkids(Actor *);
    extern s32 D_808012B0_chpoolkids[10];
    extern s32 D_808012D8_chpoolkids[8];
    extern s32 D_808012F8_chpoolkids[8];
    extern s32 D_808014C8_chpoolkids[4];
    typedef struct {
        Unk80132ED0 *unk0;
        f32 position[3];
        u32 *pointerToSyscallEntry;
        u32 unk14;
        struct {
            u32 unk[5];
            f32 amount;
            u32 rest[2];
        } actorData;
        f32 scale;
        Unk80132ED0 *unk3C;
        s32 pad40;
        f32 rotation[3];
        f32 unk50, unk54, unk58;
        u8 pad5C, pad5D, pad5E, unk5F;
        s32 pad60;
        u32 flags64;
        s32 pad68;
        u32 flags6C, flags70;
        BT_BITFIELD_ORDER(u32 flags74 : 28, u32 mode : 4);
        BT_BITFIELD_ORDER(u32 mode : 4, u32 flags74 : 28);
    } PoolKidsActor;
    f32 *position;

    if (func_80104248(arg0) != 0) {
        if (func_801022E4(arg0) == 0x2B9) {
            f32 progress;
            progress = func_80101F24(arg0);
            ((PoolKidsActor *)arg0)->actorData.amount = func_80013970(func_800F10B4(progress, 0.75f, 0.99f, 0.0f, 180.0f));
            if (progress > 0.33f && progress < 0.52f) {
                ((PoolKidsActor *)arg0)->mode = 2;
            } else {
                ((PoolKidsActor *)arg0)->mode = 1;
            }
        } else {
            ((PoolKidsActor *)arg0)->mode = 1;
            ((PoolKidsActor *)arg0)->actorData.amount = 0.0f;
        }
    }
    position = arg0->position;
    func_8008FB58(position, 60.0f, 60.0f);
    switch (arg0->unk70_10) {
    case 1:
        arg0->actorData[4] = arg0->unk70_10;
        _subaddiedialog_entrypoint_8((BtIntPtr)arg0, position, D_808014C8_chpoolkids, D_808012B0_chpoolkids, 5);
        func_80800AA0_chpoolkids(arg0);
        return;
    case 2:
        func_80800AA0_chpoolkids(arg0);
        return;
    case 3:
        func_80800AA0_chpoolkids(arg0);
        if (func_800D9078(&arg0->unk58) != 0) {
            _glcutDll_entrypoint_17();
        }
        return;
    case 4:
        arg0->actorData[4] = arg0->unk70_10;
        _subaddiedialog_entrypoint_8((BtIntPtr)arg0, position, D_808014C8_chpoolkids, D_808012D8_chpoolkids, 4);
        func_80800AA0_chpoolkids(arg0);
        return;
    case 5:
        arg0->actorData[4] = arg0->unk70_10;
        _subaddiedialog_entrypoint_8((BtIntPtr)arg0, position, D_808014C8_chpoolkids, D_808012F8_chpoolkids, 4);
        func_80800AA0_chpoolkids(arg0);
        return;
    case 6:
        func_808008DC_chpoolkids((u8 *)arg0);
        func_80800944_chpoolkids(arg0, 0.55f);
        break;
    }
}

void func_80800290_chpoolkids(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    s32 func_8008FB58(f32 *, f32, f32);
    void func_80800884_chpoolkids(void *);
    void func_808008DC_chpoolkids(u8 *);
    void func_80800944_chpoolkids(Actor *, f32);
    void func_80800B38_chpoolkids(Actor *);
    extern s32 D_80801318_chpoolkids[10];
    extern s32 D_80801340_chpoolkids[8];
    extern s32 D_80801360_chpoolkids[8];
    extern s32 D_808014D8_chpoolkids[4];
    f32 *position;
    u32 state;

    position = arg0->position;
    func_8008FB58(position, 60.0f, 60.0f);
    state = arg0->unk70_10;
    switch (state) {
    case 1:
        arg0->actorData[4] = state;
        _subaddiedialog_entrypoint_8((BtIntPtr)arg0, position, D_808014D8_chpoolkids, D_80801318_chpoolkids, 5);
        func_80800B38_chpoolkids(arg0);
        return;
    case 2:
        func_80800B38_chpoolkids(arg0);
        return;
    case 4:
        arg0->actorData[4] = state;
        _subaddiedialog_entrypoint_8((BtIntPtr)arg0, position, D_808014D8_chpoolkids, D_80801340_chpoolkids, 4);
        func_80800B38_chpoolkids(arg0);
        return;
    case 5:
        arg0->actorData[4] = state;
        _subaddiedialog_entrypoint_8((BtIntPtr)arg0, position, D_808014D8_chpoolkids, D_80801360_chpoolkids, 4);
        func_80800B38_chpoolkids(arg0);
        return;
    case 6:
        func_80800884_chpoolkids(arg0);
        func_808008DC_chpoolkids((u8 *)arg0);
        func_80800944_chpoolkids(arg0, 0.9f);
        return;
    }
}

typedef union { s32 word; struct { s16 first, second; } halves; } PoolKidsMessage;

s32 func_808003DC_chpoolkids(Actor *arg0, s32 arg1, PoolKidsMessage arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _dbmorph_entrypoint_3(void *arg0, void *arg1, void *arg2, s32 arg3, f32 *weights);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    s32 _glcutDll_entrypoint_19(s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    u8 *func_800B2768(u8 *);
    BtIntPtr func_800B2840(BtIntPtr);
    s32 func_800DA298(s32);
    s32 func_801015D0(Actor *);
    BtIntPtr func_80103CB8(Actor *, BtUIntPtr);
    void func_808006F8_chpoolkids(BtIntPtr);
    void func_808007F0_chpoolkids(Actor *, s32, s32);
    extern s32 D_808014E8_chpoolkids[], D_808014F8_chpoolkids[];
    s32 flag1, flag2;
    f32 values[2];
    BtIntPtr object;

    switch (arg1) {
    case 0x2E:
        func_808007F0_chpoolkids(arg0, arg2.halves.first, arg2.halves.second);
        break;
    case 0xC:
        flag1 = func_800DA298(0x166);
        flag2 = func_800DA298(0x167);
        if (flag1 && flag2) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1022, 6, arg0->position, 0xA0);
            return 3;
        }
        if (flag1) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1021, 6, arg0->position, 0xA0);
            return 3;
        }
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1020, 6, arg0->position, 0xA0);
        return 3;
    case 0x1F:
        object = arg2.word;
        values[0] = values[1] = ((f32 *)arg0->actorData)[5];
        _dbmorph_entrypoint_3(func_800B2768((u8 *)object), (u8 *)func_80103CB8(arg0, object), func_800B2840(object), 1, (u8 *)values);
        func_801015D0(arg0);
        break;
    case 0x49:
        if (arg0->unk6C_9 != 0x3A3) return 0;
        if (_glcutDll_entrypoint_19(0x2A)) {
            _capod_entrypoint_13(arg0->unk0, 0, 0x1F, 0x2830);
            break;
        }
        if (_glcutDll_entrypoint_19(0x29)) {
            _capod_entrypoint_13(arg0->unk0, 0, 0x2A, 0x2830);
            break;
        }
        return 0;
    case 0x95:
        func_808006F8_chpoolkids((BtIntPtr)arg0);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(arg0->unk6C_9 == 0x3A3 ? D_808014E8_chpoolkids : D_808014F8_chpoolkids, arg0->scale);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800618_chpoolkids(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80101DAC(Actor *, s32);
    void func_801020DC(void *, s32);
    void func_80102424(Actor *, s32);
    void func_80103014(u8 *);
    extern f32 D_80801508_chpoolkids[];
    extern f32 D_80801514_chpoolkids[];

    func_80102424(arg0, 6);
    switch (arg0->unk6C_9) {
        case 0x3A3:
            func_800EE7F8(arg0->position, D_80801508_chpoolkids);
            break;
        case 0x3A4:
            func_800EE7F8(arg0->position, D_80801514_chpoolkids);
            func_801020DC(arg0, 0);
            func_80101DAC(arg0, 0);
            break;
    }
    if (_glcutDll_entrypoint_20() == 0) {
        func_800EF1B8(arg0->position, func_800DC178(0.0f, 359.0f), func_800DC178(0.0f, 200.0f));
    }
    func_80103014(arg0);
}

/* extern */

void func_808006F8_chpoolkids(BtIntPtr arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_800DA524(s32 index);
    void func_80102424(Actor *, s32);
    void func_80800618_chpoolkids(Actor *);
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp1C = 0;
    sp24 = func_800DA298(0x166);
    sp20 = func_800DA298(0x167);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800618_chpoolkids(arg0);
    } else if ((_glcutDll_entrypoint_19(0x2A) != 0) || (_glcutDll_entrypoint_19(0x29) != 0)) {
        sp1C = 1;
    } else if ((sp24 != 0) && (sp20 == 0)) {
        func_80102424(arg0, 4);
    } else if ((sp24 == 0) && (sp20 != 0)) {
        func_80102424(arg0, 5);
    } else if ((sp24 != 0) && (sp20 != 0)) {
        func_80800618_chpoolkids(arg0);
    }
    if (sp1C != 0) {
        func_800DA524(0x168);
        func_800DA524(0x1CE);
    }
}

void func_808007F0_chpoolkids(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_17(void);
    void func_800D0C78(u32, u32, u32);
    void func_80102424(Actor *, s32);

    switch (arg1) {
        case 0x1020:
        case 0x1021:
            _capod_entrypoint_14();
            _glcutDll_entrypoint_17();
            break;
        case 0x1022:
            func_800D0C78(0x22, 1, 0);
            arg0->unk58 = 4.5f;
            func_80102424(arg0, 3);
            break;
        default:
            func_80102424(arg0, arg0->actorData[4]);
            break;
    }
}

/* extern */

void func_80800884_chpoolkids(void *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_80102BF8(void *, s32, s32, s32);
    f32 func_80102D78(void *, s32 *);
    s32 func_8010D600(s32 *);
    s32 sp1C[3];

    if (_glcutDll_entrypoint_20() == 0) {
        func_8010D600(sp1C);
        (((Actor *)arg0)->unk54) = func_80102D78(arg0, sp1C);
        func_80102BF8(arg0, 0x3E19999A, 0x40800000, 0x42F00000);
    }
}

/* extern */

void func_808008DC_chpoolkids(u8 *arg0) {
    void _fxripple_entrypoint_0(s32 arg0, BtIntPtr arg1);
    s32 func_800D9078(BtIntPtr);
    f32 func_800DC178(f32, f32);
    func_800D9078(arg0 + 0x58);
    if ((((Actor *)arg0)->unk58) <= 0.0f) {
        _fxripple_entrypoint_0(3, (f32 *)(arg0 + 4));
        (((Actor *)arg0)->unk58) = func_800DC178(0.6f, 1.2f);
    }
}

void func_80800944_chpoolkids(Actor *arg0, f32 arg1) { BT_NATIVE_ONLY(void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);)
    BtIntPtr _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
    void _fxripple_entrypoint_0(s32 arg0, BtIntPtr arg1);
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) _fxsplash25d_entrypoint_0(f32 *);
    BtIntPtr _fxsplash_entrypoint_2(f32 *, f32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_80101E14(Actor *, f32);
    extern u32 D_80801520_chpoolkids[3];
    f32 position[3];
    BtIntPtr emitter;

    if (func_80101E14(arg0, arg1)) {
        func_800EE7F8(position, arg0->position);
        _subaddieaudioquick_entrypoint_2(arg0, position, D_80801520_chpoolkids);
        _fxripple_entrypoint_0(3, position);
        _fxsplash25d_entrypoint_0(position);
        emitter = _fxsplash_entrypoint_2(position, 35.0f);
        func_800BA930(emitter, -350, 300, -350, 350, 500, 350);
        func_800BA22C(emitter, 6);
        func_800BA930(emitter, -150, 500, -150, 150, 800, 150);
        func_800BA22C(emitter, 6);
        position[1] -= 30.0f;
        emitter = _fxairbub_entrypoint_1(position, 20.0f, arg0->position[1], 1.0f);
        func_800BA930(emitter, -60, -250, -60, 60, -150, 60);
        func_800BA22C(emitter, 4);
    }
}

void func_80800AA0_chpoolkids(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    extern u32 D_8080152C_chpoolkids[4];
    extern u32 D_8080153C_chpoolkids[4];
    extern u32 D_8080154C_chpoolkids[4];
    extern u32 D_8080155C_chpoolkids[4];
    f32 *temp_s1;

    temp_s1 = &arg0->position[0];
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_8080152C_chpoolkids, 0.4f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_8080153C_chpoolkids, 0.18f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_8080154C_chpoolkids, 0.73f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_8080155C_chpoolkids, 0.77f);
}

void func_80800B38_chpoolkids(Actor *arg0) {
    extern u32 D_8080156C_chpoolkids[4];
    extern u32 D_8080157C_chpoolkids[6];
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_8080156C_chpoolkids, D_8080157C_chpoolkids);
}

void func_80800B68_chpoolkids(Actor *arg0) {
    s32 _gcmapsects_entrypoint_5(s32);
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    void _subaddieaudioloop_entrypoint_5(Actor *arg0, f32 *arg1, u32 arg2, s32 arg3, u32 *arg4);
    BtIntPtr func_800BEA88(s32);
    void func_800BF744(s32, s32);
    s32 func_800D9078();
    s32 func_800E3DC0(s16 *, s16 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_808011A8_chpoolkids(Actor *);
    extern s32 D_80801594_chpoolkids[3];
#ifdef BT_NATIVE
    void chpoolkids_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    extern s32 _chpoolkids_entrypoint_3;
#endif
    struct PoolKidsData {
        s16 section;
        s16 state;
        f32 timer;
        f32 unk8;
        f32 valueC;
        s16 done10;
        s16 unk12;
        s16 min14[3];
        s16 max1A[3];
        f32 value20;
        s16 done24;
        s16 unk26;
        s16 min28[3];
        s16 max2E[3];
    } *data;
    s32 pad;
    s32 sp34;
    s32 sp30;
    BtIntPtr sp2C;
    s32 active;

    data = func_80100094(arg0, 0);
    if (_gcmapsects_entrypoint_5(data->section)) {
        active = data->done10 == 0;
        if (active || (!active && arg0->unk5F)) {
            _subaddieaudioloop_entrypoint_5((BtIntPtr)arg0, (BtIntPtr)arg0->position, active, -1, D_80801594_chpoolkids);
        }
        switch (data->state) {
        case 1:
            sp34 = func_800D9078(&data->timer);
            data->valueC = func_800F12D4(data->timer, 0.0f, 4.0f, 1.0f, 0.0f);
            if (sp34) {
                data->done10 = 1;
                data->state = 0;
            }
            break;
        case 2:
            sp30 = func_800D9078(&data->timer);
            func_808011A8_chpoolkids(arg0);
            func_800BF744(3, 1);
            data->value20 = func_800F12D4(data->timer, 0.0f, 2.1f, 1.0f, 0.0f);
            if (sp30) {
                data->done24 = 1;
                data->state = 0;
            }
            break;
        }
        if (!data->done10 || !data->done24) {
            sp2C = func_800BEA88(1);
            if (sp2C) {
                if (!data->done24 && func_800E3DC0(data->min28, data->max2E)) {
                    _glid_entrypoint_0(sp2C, 1, &_chpoolkids_entrypoint_3, (BtIntPtr)arg0->unk0);
                }
                if (!data->done10 && func_800E3DC0(data->min14, data->max1A)) {
                    _glid_entrypoint_0(sp2C, 2, &_chpoolkids_entrypoint_3, (BtIntPtr)arg0->unk0);
                }
            }
        }
    }
}

u32 func_80800D3C_chpoolkids(BtIntPtr unused, s32 arg1, s32 arg2) {
    void func_80800D74_chpoolkids(Actor *);

    if (arg1 == 0x95) {
        func_80800D74_chpoolkids((Actor *) unused);
        return 1;
    }
    return 0;
}

void func_80800D74_chpoolkids(Actor *arg0) {
    s32 _gcmapsects_entrypoint_4(f32 *);
    s32 _glcutDll_entrypoint_19(s32);
    s32 _glcutDll_entrypoint_20(void);
    void _glidmake_entrypoint_2(BtIntPtr, s32, s16 *, s16 *);
    void _idworldmake_entrypoint_1(BtIntPtr arg0, s32 arg1, volatile unsigned int arg2, s32 arg3);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    BtIntPtr func_800BEA88(s32);
    void func_800BF744(s32, s32);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    struct PoolKidsData {
        s16 section;
        s16 state;
        f32 timer;
        f32 unk8;
        f32 valueC;
        s16 done10;
        s16 unk12;
        s16 min14[3];
        s16 max1A[3];
        f32 value20;
        s16 done24;
        s16 unk26;
        s16 min28[3];
        s16 max2E[3];
    } *data;
    s32 sp28;
    s32 sp24;
    BtIntPtr sp20;
    s32 active;

    data = func_80100094(arg0, 0);
    sp28 = func_800DA298(0x166);
    sp24 = func_800DA298(0x167);
    data->section = _gcmapsects_entrypoint_4(arg0->position);
    data->state = 0;
    data->timer = 0.0f;
    data->unk8 = 0.0f;
    data->value20 = 0.0f;
    data->valueC = 0.0f;
    if (_glcutDll_entrypoint_20()) {
        sp28 = 1;
        sp24 = 1;
    }
    if (sp28) {
        data->valueC = 1.0f;
    }
    if (sp24) {
        data->value20 = 1.0f;
    }
    if (_glcutDll_entrypoint_19(0x2A)) {
        data->state = 1;
        data->valueC = 0.0f;
        data->timer = 4.0f;
        data->unk8 = 4.0f;
        _subaddieDll_entrypoint_4(arg0, 1);
    } else if (_glcutDll_entrypoint_19(0x29)) {
        data->state = 2;
        data->value20 = 0.0f;
        data->timer = 6.0f;
        data->unk8 = 6.0f;
        _subaddieDll_entrypoint_4(arg0, 1);
    }
    if (data->valueC == 1.0f) {
        data->done10 = 1;
    } else {
        data->done10 = 0;
    }
    if (data->value20 == 1.0f) {
        data->done24 = 1;
    } else {
        data->done24 = 0;
    }
    func_800BF744(3, 0);
    active = data->done10 ? 0 : 1;
    func_800BF744(2, active);
    sp20 = func_800BEA88(1);
    _glidmake_entrypoint_2(sp20, 1, data->min28, data->max2E);
    _glidmake_entrypoint_2(sp20, 2, data->min14, data->max1A);
    _idworldmake_entrypoint_1(sp20, 0x8D, 1, 1);
    _idworldmake_entrypoint_1(sp20, 0x8D, 2, 1);
}

void chpoolkids_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    u8 *data;
    Vtx *end;
    f32 scale;
    data = func_80100094(func_80106790(arg4), 0);
    switch (arg0) {
    case 1:
        scale = 1.0f - *(f32 *)(data + 0x20);
        for (end = arg1 + arg3; arg1 < end; arg1++, arg2++) {
            arg2->v.cn[3] = (u32)((f32)(u32)arg1->v.cn[3] * scale);
        }
        break;
    case 2:
        scale = 1.0f - *(f32 *)(data + 0xC);
        for (end = arg1 + arg3; arg1 < end; arg1++, arg2++) {
            arg2->v.cn[3] = (u32)((f32)(u32)arg1->v.cn[3] * scale);
        }
        break;
    }
}

void func_808011A8_chpoolkids(Actor *arg0) {
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_808015A0_chpoolkids[];
    extern f32 D_808015EC_chpoolkids[3];
    BtIntPtr temp_s2;
    s32 count;
    int var_s0;

    temp_s2 = func_800B5BE4(0x23);
    count = 1;
    for (var_s0 = 0; var_s0 < count; var_s0++) {
        func_800BABB8(temp_s2, D_808015EC_chpoolkids, D_808015EC_chpoolkids, arg0->scale * 1.15f, D_808015A0_chpoolkids);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/poolkids.data.s */
extern u8 D_80801380_chpoolkids[];
void func_80105834(Actor*);
void func_801018A4();
void func_80107C2C();
extern u8 D_808013B8_chpoolkids[];
void func_80101870(Actor* arg0, void* arg1);
void func_80102EC0();
void func_8010A730();
s32 D_808012B0_chpoolkids[10] BT_DATA(4, overlays_ch_poolkids, 0x0) = { 1, 269746432, 1537, 269877760, 512, 274792704, 1024, 274858240, -73729, 302711552 };
s32 D_808012D8_chpoolkids[8] BT_DATA(4, overlays_ch_poolkids, 0x28) = { 513, 270008576, 1537, 270139904, 1024, 275054848, -73729, 302711552 };
s32 D_808012F8_chpoolkids[8] BT_DATA(4, overlays_ch_poolkids, 0x48) = { 513, 270270720, 1537, 270402048, 1024, 275185920, -73729, 302711552 };
s32 D_80801318_chpoolkids[10] BT_DATA(4, overlays_ch_poolkids, 0x68) = { 1, 269811968, 1537, 269943296, 512, 274923776, 1024, 274989312, -73729, 302711552 };
s32 D_80801340_chpoolkids[8] BT_DATA(4, overlays_ch_poolkids, 0x90) = { 1025, 270074112, 1537, 270205440, 512, 275120384, -73729, 302711552 };
s32 D_80801360_chpoolkids[8] BT_DATA(4, overlays_ch_poolkids, 0xB0) = { 1025, 270336256, 1537, 270467584, 512, 275251456, -73729, 302711552 };
u8 D_80801380_chpoolkids[56] BT_DATA(4, overlays_ch_poolkids, 0xD0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x35, 0x47, 0xAE, 0x02, 0xB9, 0x00, 0x00, 0x41, 0x35, 0x47, 0xAE, 0x02, 0xB9, 0x00, 0x00, 0x41, 0x35, 0x47, 0xAE, 0x02, 0xB9, 0x00, 0x00, 0x41, 0x35, 0x47, 0xAE, 0x02, 0xB9, 0x00, 0x00, 0x41, 0x35, 0x47, 0xAE, 0x02, 0xB9, 0x00, 0x00, 0x41, 0x2E, 0x66, 0x66, 0x02, 0xC0, 0x00, 0x00 };
u8 D_808013B8_chpoolkids[56] BT_DATA(4, overlays_ch_poolkids, 0x108) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xC0, 0xF5, 0xC3, 0x02, 0xBA, 0x00, 0x00, 0x40, 0xC0, 0xF5, 0xC3, 0x02, 0xBA, 0x00, 0x00, 0x40, 0xC0, 0xF5, 0xC3, 0x02, 0xBA, 0x00, 0x00, 0x40, 0xC0, 0xF5, 0xC3, 0x02, 0xBA, 0x00, 0x00, 0x40, 0xC0, 0xF5, 0xC3, 0x02, 0xBA, 0x00, 0x00, 0x40, 0xA0, 0x00, 0x00, 0x02, 0xB4, 0x00, 0x00 };
ActorData D_808013F0_chpoolkids [1] BT_DATA(4, overlays_ch_poolkids, 0x140) = { { 780, 931, 2004, 1, (void *)D_80801380_chpoolkids, (void (*)(struct Actor *))func_80800058_chpoolkids, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 131072000, 1065353216, 0, 0, 128, 256, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800024_chpoolkids, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31728, 25746, (void (*)(struct Actor *, long, long))func_808003DC_chpoolkids, 0 } };
ActorData D_80801438_chpoolkids [1] BT_DATA(4, overlays_ch_poolkids, 0x188) = { { 781, 932, 2005, 1, (void *)D_808013B8_chpoolkids, (void (*)(struct Actor *))func_80800290_chpoolkids, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 131072000, 1065353216, 0, 0, 0, 256, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800024_chpoolkids, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31728, 25746, (void (*)(struct Actor *, long, long))func_808003DC_chpoolkids, 0 } };
ActorData D_80801480_chpoolkids [1] BT_DATA(4, overlays_ch_poolkids, 0x1D0) = { { 813, 973, 0, 1, 0, (void (*)(struct Actor *))func_80800B68_chpoolkids, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_8010A730, 196608000, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9730, (void (*)(struct Actor *, long, long))func_80800D3C_chpoolkids, 0 } };
s32 D_808014C8_chpoolkids[4] BT_DATA(4, overlays_ch_poolkids, 0x218) = { 23592960, 16384160, 12, 103940608 };
s32 D_808014D8_chpoolkids[4] BT_DATA(4, overlays_ch_poolkids, 0x228) = { 30277632, 16384161, 12, 103940608 };
s32 D_808014E8_chpoolkids [4] BT_DATA(4, overlays_ch_poolkids, 0x238) = { 1124859904, 1120403456, 1120403456, 1109393408 };
s32 D_808014F8_chpoolkids [4] BT_DATA(4, overlays_ch_poolkids, 0x248) = { 1124859904, 1125515264, 1125515264, 1109393408 };
f32 D_80801508_chpoolkids [3] BT_DATA(4, overlays_ch_poolkids, 0x258) = { -15700.0f, 8189.0f, -7000.0f };
f32 D_80801514_chpoolkids [3] BT_DATA(4, overlays_ch_poolkids, 0x264) = { -14800.0f, 8189.0f, -8000.0f };
u32 D_80801520_chpoolkids[3] BT_DATA(4, overlays_ch_poolkids, 0x270) = { 0x130409, 0xD00F3, 0x10C0000 };
u32 D_8080152C_chpoolkids[4] BT_DATA(4, overlays_ch_poolkids, 0x27C) = { 0x130524, 0xD00F3, 0x10C0016, 0x46500000 };
u32 D_8080153C_chpoolkids[4] BT_DATA(4, overlays_ch_poolkids, 0x28C) = { 0x13041D, 0xD00B3, 0xCC0016, 0x46500000 };
u32 D_8080154C_chpoolkids[4] BT_DATA(4, overlays_ch_poolkids, 0x29C) = { 0x13055E, 0xD00F3, 0x10C0016, 0x46500000 };
u32 D_8080155C_chpoolkids[4] BT_DATA(4, overlays_ch_poolkids, 0x2AC) = { 0x1303FF, 0xD00F3, 0x10C0016, 0x46500000 };
u32 D_8080156C_chpoolkids[4] BT_DATA(4, overlays_ch_poolkids, 0x2BC) = { 0x130402, 0xD00F3, 0x10C0016, 0x5DC00000 };
u32 D_8080157C_chpoolkids[6] BT_DATA(4, overlays_ch_poolkids, 0x2CC) = { 0x3E4CCCCD, 0x3EB33333, 0x3F0A3D71, 0x3F47AE14, 0x3F7D70A4, 0xBF800000 };
s32 D_80801594_chpoolkids[3] BT_DATA(4, overlays_ch_poolkids, 0x2E4) = { 1246764, 1459792, 0 };
s32 D_808015A0_chpoolkids [19] BT_DATA(4, overlays_ch_poolkids, 0x2F0) = { 1903069, 1769922, 36044845, 13107450, 720936, 5242890, -655338, 100663346, 51, 131111, -6488164, 6553700, 2228369, 11206904, 17760277, 786598, 2818201, 11763714, 18481152 };
f32 D_808015EC_chpoolkids [ 3 ] BT_DATA(4, overlays_ch_poolkids, 0x33C) = { -15300.0f, 8200.0f, -8200.0f };
