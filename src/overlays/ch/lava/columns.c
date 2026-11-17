#include "common.h"

void func_80800000_chlavacolumns(u8 *arg0) {
    s32 func_80800200_chlavacolumns(BtIntPtr, f32);
    void func_800EFD24(f32 *);
    void func_80103014(u8 *);
    func_80800200_chlavacolumns((BtIntPtr)arg0, -400.0f);
    func_800EFD24(arg0 + 4);
    (*(f32 *)(arg0 + 8)) = -400.0f;
    func_80103014(arg0);
}

s32 func_80800044_chlavacolumns(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _glcutDll_entrypoint_19(s32);
    void _subaddieDll_entrypoint_0(void *arg0);
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    void func_80102FE8(void *, s32);
    void func_80103014(u8 *);
    void func_80103110(void *, s32);
    s32 func_80800200_chlavacolumns(BtIntPtr, f32);
    if (arg1 == 0x95) {
        if (_glcutDll_entrypoint_19(0x4E)) {
            arg0->unk64_16 = 1;
            arg0->position[1] = -400.0f;
            func_80103110(arg0, 1);
            func_80102FE8(arg0, 0);
            _subaddieDll_entrypoint_0(arg0);
            func_80101FDC(arg0, 2);
            func_80800200_chlavacolumns((BtIntPtr)arg0, -400.0f);
            _capod_entrypoint_13(arg0->unk0, NULL, 0x1A, 0x910);
        } else if (func_800DA298(0x390)) {
            arg0->position[1] = 0.0f;
            func_80101FDC(arg0, 3);
            func_80800200_chlavacolumns((BtIntPtr)arg0, 0.0f);
        } else {
            arg0->position[1] = -400.0f;
            func_80800200_chlavacolumns((BtIntPtr)arg0, -400.0f);
        }
        func_80103014((u8 *)arg0);
        return 1;
    }
    return 0;
}

void func_8080014C_chlavacolumns(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800D8FF8(void);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    extern u32 D_80800250_chlavacolumns[2];
    extern s32 D_80800258_chlavacolumns[2];
    f32 delta;

    if (arg0->unk70_10 == 2) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800250_chlavacolumns);
        delta = func_800D8FF8();
        arg0->position[1] = arg0->position[1] + 100.0f * delta;
        if (arg0->position[1] > 0.0f) {
            arg0->position[1] = 0.0f;
            func_80101FDC(arg0, 3);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800258_chlavacolumns);
            func_80103110(arg0, 0);
        }
    }
}

/* extern */

s32 func_80800200_chlavacolumns(BtIntPtr arg0, f32 arg1) {
    BtIntPtr _idworld_entrypoint_3(s32);
    void func_800EDCB8(void *arg0, f32 arg1);
    BtIntPtr temp_v0;

    temp_v0 = _idworld_entrypoint_3(0x190);
    if (temp_v0 != 0) {
        func_800EDCB8(temp_v0, arg1);
        return 1;
    }
    return 0;
}

OSThread *chlavacolumns_entrypoint_0(void)
{
    extern ActorData D_80800260_chlavacolumns[];

    return (OSThread *) D_80800260_chlavacolumns;
}
/* data_to_c.py: from asm/data/overlays/ch/lava/columns.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
u32 D_80800250_chlavacolumns[2] BT_DATA(4, overlays_ch_lava_columns, 0x0) = { 0x1304AD, 0x20000 };
s32 D_80800258_chlavacolumns[2] BT_DATA(4, overlays_ch_lava_columns, 0x8) = { 1246407, 131072 };
ActorData D_80800260_chlavacolumns [1] BT_DATA(4, overlays_ch_lava_columns, 0x10) = { { 344, 639, 2399, 1, 0, (void (*)(struct Actor *))func_8080014C_chlavacolumns, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chlavacolumns, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11778, (void (*)(struct Actor *, long, long))func_80800044_chlavacolumns, 0 } };
