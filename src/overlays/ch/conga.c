#include "ch/conga.h"
#include "su/baddiedialog_descriptor.h"
OSThread *chconga_entrypoint_0(void)
{
    extern ActorData D_808006A0_chconga[];

    return (OSThread *) D_808006A0_chconga;
}

/* extern */

void func_8080000C_chconga(BtIntPtr arg0) {
    s32 _glcutDll_entrypoint_20();
    void _subaddieitem_entrypoint_0(u8 *arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _subaddieitem_entrypoint_1(s8 *arg0, s32 arg1);
    s32 func_800D395C();
    s32 func_800DA298(s32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_800FFAB0(Actor *actor);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80105A9C(Actor *, f32);
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = func_800DA298(0x17F);
    sp20 = func_800F64A4(func_800F54E4(), 1);
    sp1C = func_800D395C();
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 5);
        goto block_10;
    }
    if (func_800DA298(0x9C) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if ((sp1C != 0) && (sp24 == 0)) {
        func_80102424(arg0, 4);
        func_80105A9C(arg0, 400.0f);
        goto block_10;
    }
    if ((sp24 != 0) && (sp20 != 0)) {
        func_800FFAB0(arg0);
        return;
    }
block_10:
    _subaddieitem_entrypoint_0(func_80100094(arg0, 0), 0x4E2, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(arg0, 0), 4);
}

void func_80800118_chconga(Actor *arg0) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddieitem_entrypoint_3(Actor *, f32 *, void *);
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    int func_800C6E38(s32);
    void func_800D1824(s32);
    void func_800DA544(s32 index);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80102424(Actor *, s32);
    void func_80103DFC(Actor *, f32 *);
    void func_80105854(Actor *);
    void func_80800538_chconga(BtIntPtr);
    void func_80800618_chconga(Actor *);
    f32 sp2C[3];

    _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    switch (arg0->unk70_10) {
    case 1:
        func_800D1824(0x4D);
        func_80800538_chconga((BtIntPtr)arg0);
        func_80800618_chconga(arg0);
        break;
    case 2:
        func_800D1824(0x4D);
        func_80800618_chconga(arg0);
        break;
    case 3:
        func_800D1824(0x4D);
        func_80103DFC(arg0, sp2C);
        if (_subaddieitem_entrypoint_3(arg0, sp2C, func_80100094(arg0, 0)) != 0) {
            func_800DA544(0x4A);
            func_80102424(arg0, 2);
            _subaddiedialog_entrypoint_11(arg0->unk0, arg0->actorData[4], 0xE, arg0->position, 0x52);
            if (func_800C6E38(0x1B) && func_800C6E38(0x2D)) {
                func_80101180(0x46E, 7, 0);
            }
        }
        break;
    case 4:
        func_80105854(arg0);
        break;
    case 5:
        func_80800618_chconga(arg0);
        break;
    }
    _sudeflect_entrypoint_0(arg0->position, 150.0f, 175.0f, 0xA);
}

void func_80800280_chconga(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_808002A0_chconga(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80800374_chconga(Actor *, s32, s32);
    s32 func_80800478_chconga(Actor *, s32, s32);
    void _gcdialogcamera_entrypoint_3(f32 *, f32);
    void *_suexpression_entrypoint_7(Actor *arg0, s32 arg1, s16 arg2);
    void _suexpression_entrypoint_12(void *, f32, f32);
    void *func_80100094(Actor *, u32);
    extern f32 D_808006E8_chconga[4];

    switch (arg1) {
    case 0x2E:
        func_80800374_chconga(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x30:
        return func_80800478_chconga(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808006E8_chconga, arg0->scale);
        break;
    case 0x95:
        _suexpression_entrypoint_7(arg0, 1, 0x52);
        _suexpression_entrypoint_12(func_80100094(arg0, 1), 45.0f, 15.0f);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800374_chconga(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_808004BC_chconga(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    void _subaddieitem_entrypoint_2(BtIntPtr);
    void func_80102424(Actor *, s32);
    void func_80105A9C(Actor *, f32);
    s32 func_80101180(s32, s32, BtIntPtr);

    switch (arg1) {
    case 0x10B1:
        arg0->actorData[4] = func_808004BC_chconga(arg0, 0x10F2);
        _subaddieitem_entrypoint_2(func_80100094(arg0, 0));
        func_80102424(arg0, 3);
        break;
    case 0x10B3:
        arg0->actorData[4] = func_808004BC_chconga(arg0, 0x10F3);
        _subaddieitem_entrypoint_2(func_80100094(arg0, 0));
        func_80102424(arg0, 3);
        break;
    case 0x10F2:
    case 0x10F3:
    case 0x1101:
        func_80102424(arg0, 4);
        func_80105A9C(arg0, 400.0f);
        func_80101180(0x13C, 0xA, 0);
        break;
    default:
        func_80102424(arg0, 1);
        break;
    }
}

s32 func_80800478_chconga(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800D1A04(s32 a0);
    if ((arg1 == 0x10B0) || (arg1 == 0x10B1)) {
        return func_800D1A04(0x4D);
    }
    return 0;
}

/* extern */

s32 func_808004BC_chconga(BtIntPtr arg0, s32 arg1) {
    int func_800C6E38(s32);
    s32 var_v1;

    if ((func_800C6E38(0x1B) != 0) && (func_800C6E38(0x2D) != 0)) {
        var_v1 = arg1;
    } else if (func_800C6E38(0x1B) != 0) {
        var_v1 = 0x1112;
    } else if (func_800C6E38(0x2D) != 0) {
        var_v1 = 0x10FF;
    } else {
        var_v1 = 0x1113;
    }
    return var_v1;
}

void func_80800538_chconga(BtIntPtr arg0) {
    s32 _subaddiedialog_entrypoint_7(BtIntPtr, BtIntPtr, subaddiedialog_UnkStruct0 *);
    s32 func_800D1A04(s32);
    s32 func_800DA298(s32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    extern subaddiedialog_UnkStruct0 D_808006F8_chconga;
    BT_IDO_ONLY(extern s16 D_808006FC_chconga;)
    BT_IDO_ONLY(extern s16 D_808006FE_chconga;)
    if ((func_800DA298(0x4A) != 0) && (func_800F64A4(func_800F54E4(), 1) != 0)) {
        BT_DATA_FIELD(D_808006F8_chconga.unk6, D_808006FE_chconga) = func_808004BC_chconga(arg0, 0x1101);
    } else {
        if (func_800D1A04(0x4D) >= 4) {
            BT_DATA_FIELD(D_808006F8_chconga.unk4, D_808006FC_chconga) = 0x10B1;
        } else {
            BT_DATA_FIELD(D_808006F8_chconga.unk4, D_808006FC_chconga) = 0x10B0;
        }
        if (func_800D1A04(0x4D) >= 4) {
            BT_DATA_FIELD(D_808006F8_chconga.unk6, D_808006FE_chconga) = 0x10B3;
        } else {
            BT_DATA_FIELD(D_808006F8_chconga.unk6, D_808006FE_chconga) = 0x10B2;
        }
    }
    if (_subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_808006F8_chconga) == 0x1101) {
        func_80101180(0x46E, 7, 0);
    }
}
void func_80800618_chconga(Actor *arg0) {
    extern s16 D_80800714_chconga[8];
    extern f32 D_80800724_chconga[7];
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80800714_chconga, D_80800724_chconga);
}
#include "conga_data.inc"
