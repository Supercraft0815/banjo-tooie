#include "common.h"

OSThread *chdingpot_entrypoint_0(void)
{
    extern ActorData D_80800500_chdingpot[];

    return (OSThread *) D_80800500_chdingpot;
}

void func_8080000C_chdingpot(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.5f);
}

void func_80800040_chdingpot(Actor *arg0) {
    void _subaddieDll_entrypoint_4(Actor *, s32);
    void func_800C3F48(s32);
    void func_800D175C(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800F4CC0(BtIntPtr);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F7844(BtUIntPtr, f32 *, f32, f32);
    void func_800F82D4(BtIntPtr arg0,s32 arg1);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_808002B4_chdingpot(Actor *, f32 *);
    s32 func_80800350_chdingpot(BtIntPtr);
    void func_80800388_chdingpot(Actor *);
    extern f32 D_80800548_chdingpot[8];
    extern f32 D_80800568_chdingpot[15];
    f32 sp24[3];

    switch (arg0->unk70_10) {
    case 1:
        func_808002B4_chdingpot(arg0, D_80800548_chdingpot);
        if (func_80800350_chdingpot((BtIntPtr)arg0) == 0) {
            func_80800388_chdingpot(arg0);
            return;
        }
        return;
    case 2:
        func_808002B4_chdingpot(arg0, D_80800548_chdingpot);
        return;
    case 3:
        func_808002B4_chdingpot(arg0, D_80800568_chdingpot);
        if (func_80101DDC(arg0) != 0) {
            func_80102424(arg0, 4);
            return;
        }
        break;
    case 4:
        if (func_80101E14(arg0, 0.596f) != 0) {
            func_800C3F48(0x6CBF441E);
        }
        if (func_80101E14(arg0, 0.63f) != 0) {
            func_800EE7F8(sp24, arg0->position);
            func_800EF1B8(sp24, arg0->rotation[1], 400.0f);
            func_800F4CC0(func_800F54E4());
            func_800F82D4(func_800F54E4(), 0);
            func_800F7844(func_800F54E4(), sp24, 1620.0f, -4100.0f);
            func_800D175C(0x40, 0x270F);
            func_800D175C(0x41, 0x270F);
            func_800D175C(0x42, 0x270F);
            func_800D175C(0x43, 0x270F);
            func_800D175C(0x44, 0x270F);
            func_800D175C(0x46, 0x270F);
            func_800D175C(0x47, 0x270F);
        }
        if (func_80101DDC(arg0) != 0) {
            func_80102424(arg0, 1);
            _subaddieDll_entrypoint_4(arg0, 0);
        }
        break;
    }
}

s32 func_8080021C_chdingpot(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_80102424(Actor *, s32);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F7F98(BtIntPtr, u32);
    extern s32 D_808005A4_chdingpot[4];

    switch (arg1) {
    case 0x2E:
        func_80102424(arg0, 1);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808005A4_chdingpot, arg0->scale);
        break;
    case 0xB:
        func_800F7F98(func_800F54E4(), 0);
        return 3;
    default:
        return 0;
    }
    return 1;
}
union SoundPair { s32 word; s16 sound[2]; };
void func_808002B4_chdingpot(Actor *arg0, f32 *arg1) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C301C(u8, s32);
    void func_800C3BDC(u8);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    s32 func_800DC128(s32, s32);
    s32 func_80101E4C(Actor *, f32 *);
    extern s32 D_808005B8_chdingpot[4];
    union SoundPair


sp2C;
    extern union SoundPair D_808005B4_chdingpot;
    s32 pad28;
    f32 *volatile sp24;

    sp2C = D_808005B4_chdingpot;
    if (func_80101E4C(arg0, arg1) != 0) {
        if (arg0->unk5F == 0) {
            arg0->unk5F = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
        }
        sp24 = arg0->position;
        func_800C301C(arg0->unk5F, sp2C.sound[func_800DC128(0, 2)]);
        func_800C4350(arg0->unk5F, sp24, D_808005B8_chdingpot);
        func_800C3BDC(arg0->unk5F);
    }
}

s32 func_80800350_chdingpot(BtIntPtr arg0) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    extern s32 D_808004B0_chdingpot[10];
    extern s32 D_808005C8_chdingpot[4];
    return _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, D_808005C8_chdingpot, D_808004B0_chdingpot, 5);
}

void func_80800388_chdingpot(Actor *arg0) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _plsu_entrypoint_3(BtIntPtr arg0);
    void _subaddieDll_entrypoint_4(Actor *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C9C04(f32, u32, u32);
    s32 func_800DA298(s32);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800F4CEC(BtIntPtr, u32);
    BtUIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F7F98(BtIntPtr, u32);
    void func_800F82D4(BtIntPtr arg0,s32 arg1);
    void func_80102424(Actor *, s32);
    extern s32 D_808005D8_chdingpot[6];
    s32 temp_s0;
    f32 sp28[3];
    f32 *sp24;

    if (func_800DA298(0x1AC) != 0) {
        temp_s0 = _plsu_entrypoint_3((&arg0)[0]->unk0);
        if ((func_800F54E4() == temp_s0) && (temp_s0 != -1) && (func_800F64A4(temp_s0, 0xB) != 0)) {
            func_800F5A00(temp_s0, sp28);
            if (func_800EEB40(sp24 = (&arg0)[0]->position, sp28) < 10000.0f) {
                _subaddieaudioquick_entrypoint_2(arg0, sp24, D_808005D8_chdingpot);
                _subaddieDll_entrypoint_4(arg0, 1);
                func_80102424(arg0, 3);
                func_800F82D4(temp_s0, 2);
                func_800F7F98(temp_s0, 1);
                _capod_entrypoint_13(arg0->unk0, 0, 2, 0x10);
                func_800F4CEC(temp_s0, 0x60);
                func_800C9C04(0.5f, 0x15, 0x55F0);
            }
        }
    }
}
/* data_to_c.py: from asm/data/overlays/ch/dingpot.data.s */
extern u8 D_808004D8_chdingpot[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 D_808004B0_chdingpot[10] BT_DATA(4, overlays_ch_dingpot, 0x0) = { 1, 216596736, 1537, 216662528, 512, 218628352, 1024, 218693888, -73729, 302973696 };
u8 D_808004D8_chdingpot[40] BT_DATA(4, overlays_ch_dingpot, 0x28) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xCC, 0xCC, 0xCD, 0x02, 0xB0, 0x00, 0x01, 0x40, 0xCC, 0xCC, 0xCD, 0x02, 0xB0, 0x00, 0x01, 0x40, 0x59, 0x99, 0x9A, 0x02, 0xB1, 0x00, 0x02, 0x3F, 0x80, 0x00, 0x00, 0x02, 0xB2, 0x00, 0x02 };
ActorData D_80800500_chdingpot [1] BT_DATA(4, overlays_ch_dingpot, 0x50) = { { 815, 977, 1959, 1, (void *)D_808004D8_chdingpot, (void (*)(struct Actor *))func_80800040_chdingpot, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 163840000, 1082130432, 0, 0, 0, 2312, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chdingpot, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_8080021C_chdingpot, 0 } };
f32 D_80800548_chdingpot[8] BT_DATA(4, overlays_ch_dingpot, 0x98) = { 0.571f, 0.608f, 0.645f, 0.685f, 0.716f, 0.75f, 0.791f, -1.0f };
f32 D_80800568_chdingpot[15] BT_DATA(4, overlays_ch_dingpot, 0xB8) = { 0.293f, 0.376f, 0.42f, 0.453f, 0.488f, 0.522f, 0.556f, 0.59f, 0.626f, 0.661f, 0.693f, 0.729f, 0.764f, 0.863f, -1.0f };
s32 D_808005A4_chdingpot[4] BT_DATA(4, overlays_ch_dingpot, 0xF4) = { 1137180672, 1137180672, 1137180672, 1127481344 };
union SoundPair D_808005B4_chdingpot BT_DATA(4, overlays_ch_dingpot, 0x104) = { 89458006 };
s32 D_808005B8_chdingpot[4] BT_DATA(4, overlays_ch_dingpot, 0x108) = { 50724877, 16777497, 1452792, 196608 };
s32 D_808005C8_chdingpot[4] BT_DATA(4, overlays_ch_dingpot, 0x118) = { 28049408, 22937764, 12, 104595968 };
s32 D_808005D8_chdingpot[6] BT_DATA(4, overlays_ch_dingpot, 0x128) = { 1246239, 852160, 14221312, 0, 0, 0 };
