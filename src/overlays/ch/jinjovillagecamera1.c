#include "common.h"

void func_80800000_chjinjovillagecamera1(Actor *arg0, s32 arg1, s32 arg2) {
    void _glcutDll_entrypoint_17();
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
    case 0x1522:
        _glcutDll_entrypoint_17();
        return;
    case 0x1523:
    case 0x1524:
    case 0x1565:
        func_80101FDC(arg0, 2);
        arg0->unk58 = 1.5f;
        return;
    }
}

s32 func_80800078_chjinjovillagecamera1(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _chjinjo_entrypoint_0(s32);
    s16 _chjinjo_entrypoint_3(s32 arg0);
    s16 _glcutDll_entrypoint_9(void);
    s32 _glcutDll_entrypoint_19(u32);
    void _glcutDll_entrypoint_24(u32, u32, u32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800D129C(u32);
    u32 func_800D1338(u32);
    void func_800DA544(s32 index);
    s32 func_800DA564(s32, s32);
    s32 func_800DA9E4(s32, s32);
    s32 func_800EA05C(void);
    extern u8 D_80800470_chjinjovillagecamera1[];
    extern u8 D_8080047C_chjinjovillagecamera1[];
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    switch (arg1) {
    case 0xB:
        sp34 = func_800DA564(0x6D0, 4);
        if (func_800EA05C() == 0x142) {
            sp30 = _chjinjo_entrypoint_3(sp34);
            _glcutDll_entrypoint_24(sp30, _glcutDll_entrypoint_9(), 0x84);
            return 3;
        }
        if (arg2 == D_8080047C_chjinjovillagecamera1[sp34]) {
            func_800DA544(0x39E);
        }
        return 3;
    case 0x49:
        sp2C = func_800DA564(0x6D0, 4);
        if (_glcutDll_entrypoint_19(0x84) == 0) {
            return 0;
        }
        if (func_800EA05C() == 0x142) {
            _capod_entrypoint_13(arg0->unk0, NULL, D_80800470_chjinjovillagecamera1[sp2C], 0x810);
        } else {
            _capod_entrypoint_13(arg0->unk0, NULL, D_8080047C_chjinjovillagecamera1[sp2C], 0x2830);
            if (func_800DA9E4(0x43C, 1) == 0) {
                sp20 = func_800D1338(sp2C);
                if (func_800D129C(sp2C) == sp20) {
                    func_800DA544(0x43D);
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1524, 4, NULL, _chjinjo_entrypoint_0(sp2C));
                } else {
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1522, 4, NULL, _chjinjo_entrypoint_0(sp2C));
                }
            } else if (func_800DA9E4(0x43D, 1) == 0) {
                sp24 = sp2C == 0 ? 0x1565 : 0x1523;
                _subaddiedialog_entrypoint_11(arg0->unk0, sp24, 4, NULL, _chjinjo_entrypoint_0(sp2C));
            }
        }
        break;
    case 0x2E:
        func_80800000_chjinjovillagecamera1(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        return 1;
    default:
        return 0;
    }
    return 1;
}

void func_808002BC_chjinjovillagecamera1(s32 arg0) {
    s16 _chjinjo_entrypoint_2(s32 arg0);
    void func_800BF744(s32, s32);
    extern u8 D_80800488_chjinjovillagecamera1[12];
    s32 temp_v0;

    temp_v0 = _chjinjo_entrypoint_2(-1);
    if (temp_v0 != -1) {
        func_800BF744(9U, 0);
        func_800BF744(*((u8 *) D_80800488_chjinjovillagecamera1 + temp_v0), 1);
    }
}

/* extern */

void func_80800310_chjinjovillagecamera1(s32 arg0) {
    s16 _chjinjo_entrypoint_2(s32 arg0);
    s32 _glcutDll_entrypoint_19(u32);
    s32 func_800D129C(u32);
    u32 func_800D1338(u32);
    s32 func_800EA05C();
    u32 func_800FDC28(u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    func_808002BC_chjinjovillagecamera1(arg0);
    if (func_800EA05C() != 0x142) {
        sp24 = _chjinjo_entrypoint_2(-1);
        sp20 = func_800D1338(sp24);
        sp1C = func_800D129C(sp24);
        sp18 = sp20 == sp1C;
        if (_glcutDll_entrypoint_19(0x84) != 0) {
            if ((sp18 == 0) || (sp1C == 1)) {
                func_80101180(0x48F, 0x7E, 0);
            }
        } else if (sp18 != 0) {
            func_800FDC28(0x12);
        }
    }
}

void func_808003C0_chjinjovillagecamera1(Actor *arg0) {
    s16 _chjinjo_entrypoint_2(s32 arg0);
    void _chjinjo_entrypoint_1(s32, s32);
    s32 func_800D9078(f32 *);
    void func_80101FDC(Actor *, u32);
    void _glcutDll_entrypoint_17(void);

    switch (arg0->unk70_10) {
        case 2:
            if (func_800D9078(&arg0->unk58) != 0) {
                _chjinjo_entrypoint_1(_chjinjo_entrypoint_2(-1), 0);
                func_80101FDC(arg0, 3);
                arg0->unk58 = 2.5f;
            }
            break;
        case 3:
            if (func_800D9078(&arg0->unk58) != 0) {
                _glcutDll_entrypoint_17();
            }
            break;
    }
}

OSThread *chjinjovillagecamera1_entrypoint_0(void)
{
    extern ActorData D_80800494_chjinjovillagecamera1[];

    return (OSThread *) D_80800494_chjinjovillagecamera1;
}
/* data_to_c.py: from asm/data/overlays/ch/jinjovillagecamera1.data.s */
void func_80105834(Actor*);
void func_8010A730();
void func_80107C2C();
u8 D_80800470_chjinjovillagecamera1 [12] BT_DATA(4, overlays_ch_jinjovillagecamera1, 0x0) = { 0x10, 0x18, 0, 0x16, 0xD, 6, 3, 0xA, 0x13, 0, 0, 0 };
u8 D_8080047C_chjinjovillagecamera1 [12] BT_DATA(4, overlays_ch_jinjovillagecamera1, 0xC) = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
u8 D_80800488_chjinjovillagecamera1[12] BT_DATA(4, overlays_ch_jinjovillagecamera1, 0x18) = { 4, 5, 1, 9, 6, 8, 3, 7, 2, 0, 0, 0 };
ActorData D_80800494_chjinjovillagecamera1 [1] BT_DATA(4, overlays_ch_jinjovillagecamera1, 0x24) = { { 344, 1166, 0, 1, 0, (void (*)(struct Actor *))func_808003C0_chjinjovillagecamera1, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 8, 1028, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800310_chjinjovillagecamera1, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8194, (void (*)(struct Actor *, long, long))func_80800078_chjinjovillagecamera1, 0 } };
