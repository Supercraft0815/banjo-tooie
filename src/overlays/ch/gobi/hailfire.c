#include "common.h"

OSThread *chgobihailfire_entrypoint_0(void)
{
    extern ActorData D_80800788_chgobihailfire[];

    return (OSThread *) D_80800788_chgobihailfire;
}

OSThread *chgobihailfire_entrypoint_1(void)
{
    extern ActorData D_808007D0_chgobihailfire[];

    return (OSThread *) D_808007D0_chgobihailfire;
}

/* extern */

void func_80800018_chgobihailfire(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    void func_8010573C(Actor *, f32);
    void func_80105A9C(Actor *, f32);
    struct {
        BT_BITFIELD_ORDER(u32 unused : 15, u32 unused2 : 16);
        u32 enabled : 1;
        BT_BITFIELD_ORDER(u32 unused2 : 16, u32 unused : 15);
    } *flags;
    if (_glcutDll_entrypoint_20() != 0) {
        if (func_800EA05C() != 0x129) {
            func_800FFAB0(arg0);
        }
        func_80102424(arg0, 4);
        func_8010573C(arg0, 1.0f);
        goto block_6;
    }
    if (func_800DA298(0x97) == 0) {
        func_800FFAB0(arg0);
        return;
    }
block_6:
    func_80105A9C(arg0, 500.0f);
    func_80102FDC(arg0, 0.25f);
    flags = (void *)&arg0->pad94;
    flags->enabled = 1;
}

void func_808000C8_chgobihailfire(Actor *arg0) {
    s32 _chbadshad_entrypoint_2(Actor *arg0, s32 arg1, f32 arg2, f32 *arg3);
    void _chgobicommon_entrypoint_0(Actor *);
    void _glcutDll_entrypoint_24(u32, u32, u32);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 _plsu_entrypoint_3(BtIntPtr arg0);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800D9078(f32 *);
    void func_800DA544(s32 index);
    void func_800FFA88(Unk80132ED0 *);
    void func_800FFAB0(Actor *);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);

    _chgobicommon_entrypoint_0(arg0);
    switch (arg0->unk70_10) {
    case 1:
        if (func_800D9078(&arg0->unk58) != 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x126E, 4, NULL, 0x38);
        }
        if (arg0->unk58 == 0.0f) {
            func_80105834(arg0);
            if (func_80105A5C(arg0) != 0) {
                func_800FFAB0(arg0);
                if (arg0->unk64_20) {
                    _glcutDll_entrypoint_24(0x129, 0xEA, 0x47);
                } else {
                    _glcutDll_entrypoint_6(0x129, 0x47);
                }
            }
        }
        break;
    case 2:
        func_80105834(arg0);
        if (func_80105A5C(arg0) != 0) {
            func_800DA544(0x1C6);
            func_80102424(arg0, 3);
        }
        break;
    case 5:
        if ((_plsu_entrypoint_3(arg0->unk0) != -1) && arg0->unk64_19) {
            if (!arg0->unk74_30) {
                arg0->unk74_30 = 1;
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x12C3, 4, arg0->position, 0x38);
            }
            func_80102424(arg0, 6);
            arg0->unk58 = 0.6f;
        }
        break;
    case 6:
        if ((_plsu_entrypoint_3(arg0->unk0) == -1) || !arg0->unk64_19) {
            if (func_800D9078(&arg0->unk58) != 0) {
                func_80102424(arg0, 5);
            }
        } else {
            arg0->unk58 = 0.6f;
        }
        break;
    case 7:
        if (func_80101DDC(arg0) != 0) {
            func_800FFA88(arg0->unk3C);
            arg0->unk3C = NULL;
            func_80102424(arg0, 5);
        }
        break;
    case 8:
        if (func_80101DDC(arg0) != 0) {
            func_80102424(arg0, 5);
        }
        break;
    }
    _chbadshad_entrypoint_2(arg0, 1, arg0->scale * 2.4f, 0);
    arg0->unk64_19 = 0;
}

s32 func_8080032C_chgobihailfire(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_8008FCC8(Unk80132ED0 *);
    void func_80090658(s32);
    s32 func_800C064C(void);
    s32 func_800C067C(s32);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    Actor *func_801084B0(BtIntPtr, Actor **);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    s32 func_80800538_chgobihailfire(Actor *, s32);
    extern u8 D_80800818_chgobihailfire[];
    Actor *sp24;

    switch (arg1) {
        case 0x49:
            return func_80800538_chgobihailfire(arg0, arg2);
        case 0x3E:
            arg0->unk64_19 = 1;
            if (func_8008FCC8(arg0->unk0) == 1) {
                if (!func_800DA298(0x171) && func_800DA298(0x4F2)) {
                    if (arg0->unk70_10 != 7) {
                        func_80090658(1);
                        _capod_entrypoint_13(arg0->unk0, NULL, 0x11, 0);
                        if (func_800C064C() == 0x12C3) {
                            func_800C067C(0x12C3);
                        }
                        _subaddiedialog_entrypoint_11(arg0->unk0, 0x12C4, 4, arg0->position, 0x38);
                        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800818_chgobihailfire);
                        func_80102424(arg0, 7);
                        func_80108B04(arg0, 0);
                        func_8010A570(arg0);
                        func_800DA544(0x171);
                    }
                } else if (arg0->unk70_10 != 8) {
                    func_80102424(arg0, 8);
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800818_chgobihailfire);
                }
            }
            break;
        case 0xB:
            if (arg2 == 0x11) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x12C6, 0x44, arg0->position, 0x42);
                func_80090658(0);
                func_8010A590(arg0);
            }
            return 3;
        case 0x3D:
            sp24 = func_801084B0(0x500, &arg0);
            func_80102FDC(sp24, arg0->scale);
            arg0->unk3C = sp24->unk0;
            func_80101EE4(arg0, 0.0f);
            break;
    }
    return 0;
}

s32 func_80800538_chgobihailfire(Actor *arg0, s32 arg1) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _glcutDll_entrypoint_19(u32);
    s32 _glcutDll_entrypoint_20(void);
    s32 func_800DA298(s32);
    int func_800DB9B0(void);
    s32 func_800EA05C(void);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_80104E78(Actor *);
    void func_801056EC(Actor *, f32);
    s32 cutscene;
    s32 complete;
    s32 active;
    u32 flags;

    complete = func_800DA298(0x1C6);
    cutscene = _glcutDll_entrypoint_19(0x47);
    switch (func_800EA05C()) {
        case 0x127:
            active = func_800DA298(0x97) && !complete && !func_800DB9B0();
            if (_glcutDll_entrypoint_20()) {
                func_800FFAB0(arg0);
                return 0;
            }
            func_80102424(arg0, 1);
            if (cutscene) {
                arg0->unk64_20 = 1;
            } else {
                arg0->unk64_20 = 0;
            }
            if (cutscene || active) {
                flags = 0x830;
                if (cutscene) {
                    flags = 0x2830;
                }
                arg0->unk58 = 5.0f;
                _capod_entrypoint_13(arg0->unk0, NULL, 0, flags);
                return 1;
            }
            func_800FFAB0(arg0);
            return 0;
        case 0x129:
            if (_glcutDll_entrypoint_20()) {
                return 0;
            }
            if (cutscene) {
                func_80102424(arg0, 2);
                func_801056EC(arg0, 0.0f);
                _capod_entrypoint_13(arg0->unk0, NULL, 1, 0x2900);
                return 1;
            }
            if (complete) {
                func_80102424(arg0, 5);
                func_801056EC(arg0, 1.0f);
                func_80104E78(arg0);
            } else {
                func_800FFAB0(arg0);
            }
            break;
    }
    return 0;
}
/* data_to_c.py: from asm/data/overlays/ch/gobi/hailfire.data.s */
extern u8 D_80800730_chgobihailfire[];
void func_80102EC0();
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
extern u8 D_80800778_chgobihailfire[];
u8 D_80800730_chgobihailfire[72] BT_DATA(4, overlays_ch_gobi_hailfire, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x07, 0xAE, 0x14, 0x02, 0x23, 0x00, 0x01, 0x3F, 0x07, 0xAE, 0x14, 0x02, 0x23, 0x00, 0x01, 0x40, 0x90, 0x00, 0x00, 0x02, 0x22, 0x00, 0x01, 0x40, 0x90, 0x00, 0x00, 0x02, 0x22, 0x00, 0x01, 0x40, 0xA3, 0xD7, 0x0A, 0x04, 0x9A, 0x00, 0x01, 0x3F, 0x19, 0x99, 0x9A, 0x04, 0x9C, 0x00, 0x02, 0x40, 0x57, 0xAE, 0x14, 0x04, 0x9D, 0x00, 0x02, 0x3F, 0x19, 0x99, 0x9A, 0x04, 0x9C, 0x00, 0x02 };
u8 D_80800778_chgobihailfire[16] BT_DATA(4, overlays_ch_gobi_hailfire, 0x48) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x57, 0xAE, 0x14, 0x04, 0xA0, 0x00, 0x02 };
ActorData D_80800788_chgobihailfire [1] BT_DATA(4, overlays_ch_gobi_hailfire, 0x58) = { { 392, 995, 1928, 1, (void *)D_80800730_chgobihailfire, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_808000C8_chgobihailfire, (void (*)(long, long))func_80101870, 0, 1092196762, 0, 0, 16388, 2348, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800018_chgobihailfire, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1040, (void (*)(struct Actor *, long, long))func_8080032C_chgobihailfire, 0 } };
ActorData D_808007D0_chgobihailfire [1] BT_DATA(4, overlays_ch_gobi_hailfire, 0xA0) = { { 344, 1280, 2322, 1, (void *)D_80800778_chgobihailfire, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 12, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2050, 0, 0 } };
u8 D_80800818_chgobihailfire [24] BT_DATA(4, overlays_ch_gobi_hailfire, 0xE8) = { 0, 0x13, 4, 0xCA, 0, 0xD, 0, 0xD9, 0, 0xF3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
