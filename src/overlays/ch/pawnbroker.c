#include "common.h"

OSThread *chpawnbroker_entrypoint_0(void)
{
    extern ActorData D_80800FD0_chpawnbroker[];

    return (OSThread *) D_80800FD0_chpawnbroker;
}

OSThread *chpawnbroker_entrypoint_1(void)
{
    extern ActorData D_80801018_chpawnbroker[];

    return (OSThread *) D_80801018_chpawnbroker;
}

OSThread *chpawnbroker_entrypoint_2(void)
{
    extern ActorData D_80801060_chpawnbroker[];

    return (OSThread *) D_80801060_chpawnbroker;
}

void func_80800024_chpawnbroker(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddieitem_entrypoint_3(Actor *, f32 *, void *);
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    void func_800D1824(s32);
    void func_800DA544(s32 index);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 func_80101DDC(Actor *);
    s32 func_801022E4(Actor *);
    s32 func_80102320(Actor *, f32, f32);
    void func_80102424(Actor *, s32);
    void func_80103DFC(Actor *, f32 *);
    void func_80800664_chpawnbroker(Actor *);
    void func_80800694_chpawnbroker(Actor *);
    s32 func_808007BC_chpawnbroker(Actor *, void *, s32 *, s32, s32);
    void func_80800AE4_chpawnbroker(Actor *, s32, s32);
    extern s32 D_80800ED0_chpawnbroker[];
    extern s32 D_80800F08_chpawnbroker[];
    extern s32 D_80800F40_chpawnbroker[];
    extern f32 D_808010A8_chpawnbroker[];
    extern f32 D_808010B8_chpawnbroker[];
    void *expression;
    f32 position[3];

    expression = func_80100094(arg0, 1);
    func_800D1824(0x4E);
    _sudeflect_entrypoint_1(D_808010B8_chpawnbroker, 60.0f, 0.0f, 60.0f, 2);
    _sudeflect_entrypoint_1(arg0->position, 250.0f, 0.0f, 100.0f, 10);
    _suexpression_entrypoint_10(expression, arg0->unk0, 0);
    if (func_801022E4(arg0) != 0x115 || !func_80102320(arg0, 0.55f, 0.99f)) {
        _suexpression_entrypoint_18(expression, 1);
    }
    switch (arg0->unk70_10) {
    case 2:
        func_80800694_chpawnbroker(arg0);
        if (func_808007BC_chpawnbroker(arg0, D_808010A8_chpawnbroker, D_80800ED0_chpawnbroker, 7, 0x6A5)) {
            func_80800AE4_chpawnbroker(arg0, 3, 0);
        }
        break;
    case 6:
        func_80800694_chpawnbroker(arg0);
        if (func_808007BC_chpawnbroker(arg0, D_808010A8_chpawnbroker, D_80800F08_chpawnbroker, 7, 0x6A6)) {
            func_80800AE4_chpawnbroker(arg0, 3, 0);
        }
        break;
    case 5:
        func_80800694_chpawnbroker(arg0);
        if (func_808007BC_chpawnbroker(arg0, D_808010A8_chpawnbroker, D_80800F40_chpawnbroker, 4, 0)) {
            func_80800AE4_chpawnbroker(arg0, 5, 1);
        }
        break;
    case 8:
        func_80800694_chpawnbroker(arg0);
        if (func_808007BC_chpawnbroker(arg0, D_808010A8_chpawnbroker, D_80800F40_chpawnbroker, 4, 0)) {
            func_80800AE4_chpawnbroker(arg0, 5, 1);
        }
        break;
    case 4:
        func_80800664_chpawnbroker(arg0);
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 5);
            func_80101180(0x353, 5, 0);
            func_800DA544(0xB4);
        }
        break;
    case 3:
        func_80800694_chpawnbroker(arg0);
        func_80103DFC(arg0, position);
        if (_subaddieitem_entrypoint_3(arg0, position, func_80100094(arg0, 0))) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xFE8, 0xE, arg0->position, 0x53);
            func_80102424(arg0, 1);
        }
        break;
    case 7:
        func_80800664_chpawnbroker(arg0);
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 8);
            func_80101180(0x353, 5, 0);
            func_800DA544(0xB5);
        }
        break;
    default:
        func_80800694_chpawnbroker(arg0);
        break;
    }
}

void func_80800320_chpawnbroker(Actor *arg0) {
    Prop *_gccubesearch_entrypoint_0(u32, Actor *);
    s32 _plsu_entrypoint_0(f32 *, f32 *);
    void _subaddieitem_entrypoint_0(void *, BtUIntPtr, s32, s32);
    void _subaddieitem_entrypoint_1(s8 *arg0, s32 arg1);
    s32 func_800D0A9C(u32, u32);
    s32 func_800D0B68(u32, u32);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    s32 func_800DA298(s32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_8010A3E8(void *, f32);
    s32 state;
    s32 pad40;
    f32 position[3];
    s32 distant;

    func_800EE88C((f32 *)arg0->actorData, _gccubesearch_entrypoint_0(0x154, arg0)->position);
    if (func_800D0B68(0x27, 1) && func_800D0B68(0xA, 4)) {
        state = 8;
    } else if (func_800D0B68(0x27, 1)) {
        distant = 1;
        if (_plsu_entrypoint_0(position, (f32 *)arg0->actorData) != -1 &&
            func_800EEAD4(position, (f32 *)arg0->actorData) < 250.0f) {
            distant = 0;
        }
        if (func_800DA298(0xB5)) {
            if (!func_800D0A9C(0xA, 4)) {
                func_800D1000(0xA, 4, (f32 *)arg0->actorData, 3, 0);
            }
            state = 8;
        } else if (distant) {
            if (!func_800D0A9C(0xA, 4)) {
                func_800D1000(0xA, 4, (f32 *)arg0->actorData, 3, 0);
            }
            state = 6;
        } else {
            state = 5;
        }
    } else if (func_800DA298(0xB4)) {
        state = 5;
    } else {
        state = 2;
    }
    if (state != 5 && state != 8) {
        func_80108B04(arg0, 0x353);
    }
    _subaddieitem_entrypoint_0(func_80100094(arg0, 0), 0x4E4, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(arg0, 0), func_800DA298(0xB4) ? 5 : 20);
    func_80101FDC(arg0, state);
    func_8010A3E8(arg0, 0.8f);
}

void func_80800514_chpawnbroker(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_80800534_chpawnbroker(Actor *arg0, s32 arg1, s32 arg2) {
    extern u32 D_80800F60_chpawnbroker[4];
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    void func_80108B04(Actor *, u32);
    void func_808006FC_chpawnbroker(Actor *, s32);
    void func_8080083C_chpawnbroker(Actor *, s32, s32);
    s32 func_80800A50_chpawnbroker(void *, s32, s32);
    void func_80800AA8_chpawnbroker(void *);
    BtIntPtr expression;

    switch (arg1) {
        case 0x2E:
            func_8080083C_chpawnbroker(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x3D:
            func_808006FC_chpawnbroker(arg0, arg2);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800F60_chpawnbroker, arg0->scale);
            break;
        case 0x57:
            return func_80800A50_chpawnbroker(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0xB:
            func_80800AA8_chpawnbroker(arg0);
            return 4;
        case 0x95:
            expression = _suexpression_entrypoint_7(arg0, 1, 0x53);
            _suexpression_entrypoint_12(expression, 0x428C0000, 0x41F00000);
            _suexpression_entrypoint_17(expression, 0x3E8);
            func_80108B04(arg0, 0x354);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800664_chpawnbroker(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_808010C4_chpawnbroker;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808010C4_chpawnbroker, 0.52f);
}

void func_80800694_chpawnbroker(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    extern u32 D_808010CC_chpawnbroker[3];
    extern u32 D_808010D8_chpawnbroker[3];
    extern u32 D_808010E4_chpawnbroker[3];
    extern u32 D_808010F0_chpawnbroker[4];
    f32 * volatile temp_a1;

    _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = &arg0->position[0], D_808010D8_chpawnbroker, D_808010F0_chpawnbroker);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, D_808010CC_chpawnbroker, 0.0f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, D_808010E4_chpawnbroker, 0.0f);
}

void func_808006FC_chpawnbroker(Actor *arg0, s32 arg1) {
    void func_80102FDC(Actor *, f32);
    Actor *func_801084B0(BtIntPtr, Actor **);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    s32 func_80108944(void *, void *);
    Actor *temp_v0;

    switch (arg1) {
        case 0x136:
            func_80108528(arg1, (f32 *)arg0->actorData, 0xA, &arg0);
            return;
        case 0x353:
            func_80108528(arg1, (f32 *)arg0->actorData, 0, &arg0);
            return;
        case 0x354:
            temp_v0 = func_801084B0(arg1, &arg0);
            func_80102FDC(temp_v0, arg0->scale);
            func_80108944(temp_v0, arg0);
            arg0->unk3C = temp_v0->unk0;
            return;
    }
}

/* extern */

s32 func_808007BC_chpawnbroker(Actor *arg0, void *arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    s32 _subaddiedialog_entrypoint_9(BtIntPtr, s32, s32 *, s32);
    s32 temp_v0;

    *(s16 *)arg1 = arg4;
    temp_v0 = _subaddiedialog_entrypoint_8((BtIntPtr)arg0, arg0->position, arg1, arg2, arg3);
    if (temp_v0 == 0) {
        return 0;
    }
    if (_subaddiedialog_entrypoint_9((BtIntPtr)arg0, temp_v0, arg2, arg3) != 3) {
        return 1;
    }
    return 0;
}

void func_8080083C_chpawnbroker(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _subaddieitem_entrypoint_2(BtIntPtr);
    s32 func_800D0A9C(u32, u32);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800AA8_chpawnbroker(void *);
    void func_80800B88_chpawnbroker(Actor *, s32, s32);
    s32 func_80800C00_chpawnbroker(s32, s32);
    s32 sp34;
    s32 sp30;
    s32 state;

    switch (arg1) {
        case 0xFE4:
        case 0xFE6:
        case 0x105B:
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xFEA, 0x4E, arg0->position, 0x53);
            break;
        case 0xFEA:
            if (func_800DA298(0xB4)) {
                sp34 = func_80800C00_chpawnbroker(5, arg2);
                _subaddiedialog_entrypoint_11(arg0->unk0, sp34, 0xE, arg0->position, 0x53);
                if (sp34 == 0x1040) {
                    arg0->unk64_20 = 0;
                }
            } else {
                sp30 = func_80800C00_chpawnbroker(0x14, arg2);
                _subaddiedialog_entrypoint_11(arg0->unk0, sp30, 0xE, arg0->position, 0x53);
                if (sp30 == 0x1040) {
                    arg0->unk64_20 = 1;
                }
            }
            break;
        case 0x1040:
            _subaddieitem_entrypoint_2(func_80100094(arg0, 0));
            func_80102424(arg0, 3);
            break;
        case 0xFE8:
            func_80102424(arg0, arg0->unk64_20 ? 4 : 7);
            func_80102424(func_80106790(arg0->unk3C), 2);
            func_80800B88_chpawnbroker(arg0, 3, 0x30);
            break;
        default:
            if (func_800DA298(0xB5)) {
                state = 8;
            } else if (func_800DA298(0xB4)) {
                if (func_800D0B68(0x27, 1) && func_800D0A9C(0xA, 4)) {
                    state = 6;
                } else {
                    state = 5;
                }
            } else {
                state = 2;
            }
            func_80800AA8_chpawnbroker(arg0);
            func_80102424(arg0, state);
            break;
    }
}

/* extern */

s32 func_80800A50_chpawnbroker(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_80800AE4_chpawnbroker(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 2) {
            func_80800AE4_chpawnbroker(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80800AA8_chpawnbroker(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x28))) = 0;
    }
}

void func_80800AE4_chpawnbroker(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void _gcdialogcamera_entrypoint_8(void);
    extern u32 D_80800F60_chpawnbroker[4];

    switch (arg0->actorData[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x11, 0);
        case 1:
            _capod_entrypoint_8(1);
            arg0->actorData[4] = 2;
            _gcdialogcamera_entrypoint_3(D_80800F60_chpawnbroker, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80800B88_chpawnbroker(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    switch (arg0->actorData[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x11, arg2);
        case 2:
            arg0->actorData[4] = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

/* extern */

s32 func_80800C00_chpawnbroker(s32 arg0, s32 arg1) {
    s32 func_800D1A04(s32);
    BtIntPtr func_800F54E4();
    s32 func_800F64A4(BtIntPtr, s32);
    if (arg1 > 0) {
        if (func_800D1A04(0x4E) >= arg0) {
            if (func_800F64A4(func_800F54E4(), 0x201) != 0) {
                return 0x1040;
            }
            return 0x1225;
        }
        return 0xFE9;
    }
    return 0xFE7;
}

/* extern */
void func_80800CB4_chpawnbroker(Actor *arg0);

void func_80800C70_chpawnbroker(Actor *arg0) {
    u32 temp_t6;

    temp_t6 = (u32) arg0->unk70_10;
    switch (temp_t6) {
    case 1:
        func_80800CB4_chpawnbroker(arg0);
        break;
    case 2:
        return;
    }
}

void func_80800CB4_chpawnbroker(Actor *arg0) {
    Unk80132ED0 *func_800D0634(u32, u32);
    s32 func_800D0B68(u32, u32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
    void func_8010A570(Actor *);
    void func_80102424(Actor *, s32);
    Actor *sp24;

    arg0->position[1] -= 40.0f;
    if (func_800D0B68(0x27, 1) == 0) {
        sp24 = func_80106790(func_800D0634(0x27, 1));
    } else if (func_800D0B68(0xA, 4) == 0) {
        sp24 = _subaddiefind_entrypoint_0(arg0->position, 0x136, -1, 0);
    }
    arg0->unk3C = sp24->unk0;
    func_8010A570(sp24);
    func_80102424(arg0, 2);
}

s32 func_80800D5C_chpawnbroker(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800FFAB0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A590(Actor *);
    extern s32 D_80801100_chpawnbroker[13];
    extern s32 D_80801134_chpawnbroker[4];

    if (arg1 == 5) {
        func_800BBCB8(arg0->position, arg0->position, arg0->scale, 0x28, D_80801100_chpawnbroker);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801134_chpawnbroker);
        func_8010A590(func_80106790(arg0->unk3C));
        func_800FFAB0(arg0);
        return 1;
    }
    return 0;
}

/* extern */

void func_80800DE8_chpawnbroker(Actor *arg0) {
    s32 func_80101DDC(Actor*);
    void func_80102424(Actor*, s32);
    void func_80800E3C_chpawnbroker(Actor *);
    if (arg0->unk70_10 == 2) {
        func_80800E3C_chpawnbroker(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80102424(arg0, 1);
        }
    }
}

void func_80800E34_chpawnbroker(s32 arg0) 
{
}
void func_80800E3C_chpawnbroker(Actor *arg0) { void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32); void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *); extern u32 D_80801144_chpawnbroker; extern u32 D_8080114C_chpawnbroker; extern u32 D_80801154_chpawnbroker[3]; f32 * volatile temp_a1; _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = &arg0->position[0], &D_80801144_chpawnbroker, D_80801154_chpawnbroker); _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_8080114C_chpawnbroker, 0.5f); _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_8080114C_chpawnbroker, 0.87f); }
/* data_to_c.py: from asm/data/overlays/ch/pawnbroker.data.s */
extern u8 D_80800F70_chpawnbroker[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
extern u8 D_80800FB8_chpawnbroker[];
s32 D_80800ED0_chpawnbroker [14] BT_DATA(4, overlays_ch_pawnbroker, 0x0) = { 1, 266535168, 1, 266600960, 512, 274137344, 512, 266600960, 1024, 274202880, 1024, 266600960, -73729, 302711552 };
s32 D_80800F08_chpawnbroker [14] BT_DATA(4, overlays_ch_pawnbroker, 0x38) = { 1, 266666240, 1, 266732032, 512, 274268416, 512, 274399744, 1024, 274333952, 1024, 266732032, -73729, 302711552 };
s32 D_80800F40_chpawnbroker [8] BT_DATA(4, overlays_ch_pawnbroker, 0x70) = { 1, 267059712, 512, 274465280, 1024, 274530816, -73729, 302711552 };
u32 D_80800F60_chpawnbroker[4] BT_DATA(4, overlays_ch_pawnbroker, 0x90) = { 0x437A0000, 0x43160000, 0x43160000, 0x43160000 };
u8 D_80800F70_chpawnbroker[72] BT_DATA(4, overlays_ch_pawnbroker, 0xA0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xFB, 0x33, 0x33, 0x01, 0x15, 0x00, 0x01, 0x40, 0xFB, 0x33, 0x33, 0x01, 0x15, 0x00, 0x01, 0x40, 0xFB, 0x33, 0x33, 0x01, 0x15, 0x00, 0x01, 0x41, 0x0D, 0x47, 0xAE, 0x01, 0x17, 0x00, 0x02, 0x40, 0xFB, 0x33, 0x33, 0x01, 0x15, 0x00, 0x01, 0x40, 0xFB, 0x33, 0x33, 0x01, 0x15, 0x00, 0x01, 0x41, 0x0D, 0x47, 0xAE, 0x01, 0x17, 0x00, 0x02, 0x40, 0xFB, 0x33, 0x33, 0x01, 0x15, 0x00, 0x01 };
u8 D_80800FB8_chpawnbroker[24] BT_DATA(4, overlays_ch_pawnbroker, 0xE8) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x0D, 0x47, 0xAE, 0x01, 0x18, 0x00, 0x44, 0x41, 0x0D, 0x47, 0xAE, 0x01, 0x18, 0x00, 0x02 };
ActorData D_80800FD0_chpawnbroker [1] BT_DATA(4, overlays_ch_pawnbroker, 0x100) = { { 692, 850, 1731, 2, (void *)D_80800F70_chpawnbroker, (void (*)(struct Actor *))func_80800024_chpawnbroker, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 1068708659, 0, 0, 0, 288, (void (*)(struct Actor *))func_80800514_chpawnbroker, 0, 20, 0, (void (*)(struct Actor *))func_80800320_chpawnbroker, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32256, 9346, (void (*)(struct Actor *, long, long))func_80800534_chpawnbroker, 0 } };
ActorData D_80801018_chpawnbroker [1] BT_DATA(4, overlays_ch_pawnbroker, 0x148) = { { 693, 851, 1879, 1, 0, (void (*)(struct Actor *))func_80800C70_chpawnbroker, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 2, 2052, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800CB4_chpawnbroker, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9346, (void (*)(struct Actor *, long, long))func_80800D5C_chpawnbroker, 0 } };
ActorData D_80801060_chpawnbroker [1] BT_DATA(4, overlays_ch_pawnbroker, 0x190) = { { 694, 852, 1732, 1, (void *)D_80800FB8_chpawnbroker, (void (*)(struct Actor *))func_80800DE8_chpawnbroker, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2052, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800E34_chpawnbroker, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8194, 0, 0 } };
f32 D_808010A8_chpawnbroker [4] BT_DATA(4, overlays_ch_pawnbroker, 0x1D8) = { 0.0f, 8.228507e-38f, 1.68156e-44f, 6.175751e-16f };
f32 D_808010B8_chpawnbroker [3] BT_DATA(4, overlays_ch_pawnbroker, 0x1E8) = { 461.0f, 95.0f, -100.0f };
u32 D_808010C4_chpawnbroker BT_DATA(4, overlays_ch_pawnbroker, 0x1F4) = 0x130532;
u8 D_808010C4_chpawnbroker__gap[4] BT_DATA(4, overlays_ch_pawnbroker, 0x1F8) = { 0 };
u32 D_808010CC_chpawnbroker[3] BT_DATA(4, overlays_ch_pawnbroker, 0x1FC) = { 0x130533, 0xD0140, 0x1590000 };
u32 D_808010D8_chpawnbroker[3] BT_DATA(4, overlays_ch_pawnbroker, 0x208) = { 0x130564, 0xD00F3, 0x10C0000 };
u32 D_808010E4_chpawnbroker[3] BT_DATA(4, overlays_ch_pawnbroker, 0x214) = { 0x130565, 0xD00F3, 0x10C0000 };
u32 D_808010F0_chpawnbroker[4] BT_DATA(4, overlays_ch_pawnbroker, 0x220) = { 0x3E3851EC, 0x3E8F5C29, 0x3EB851EC, 0xBF800000 };
s32 D_80801100_chpawnbroker[13] BT_DATA(4, overlays_ch_pawnbroker, 0x230) = { 1902424, 1310763, 13369651, 2949620, 39321627, -65471264, 2228531, 23462041, 13369374, 1966120, 917554, 3932165, 0 };
s32 D_80801134_chpawnbroker[4] BT_DATA(4, overlays_ch_pawnbroker, 0x264) = { 1246349, 1572865, 81922500, 0 };
u32 D_80801144_chpawnbroker BT_DATA(4, overlays_ch_pawnbroker, 0x274) = 0x130520;
u8 D_80801144_chpawnbroker__gap[4] BT_DATA(4, overlays_ch_pawnbroker, 0x278) = { 0 };
u32 D_8080114C_chpawnbroker BT_DATA(4, overlays_ch_pawnbroker, 0x27C) = 0x130521;
u8 D_8080114C_chpawnbroker__gap[4] BT_DATA(4, overlays_ch_pawnbroker, 0x280) = { 0 };
u32 D_80801154_chpawnbroker[3] BT_DATA(4, overlays_ch_pawnbroker, 0x284) = { 0x3E6B851F, 0x3EA3D70A, 0xBF800000 };
