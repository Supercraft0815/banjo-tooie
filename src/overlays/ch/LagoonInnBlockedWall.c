#include "common.h"
BT_NATIVE_ONLY(void func_8010A63C(Actor *);)
/* extern */

void func_80800000_chLagoonInnBlockedWall(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 func_800D9078(f32 *arg0);
    void func_800DA544(s32 index);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    u32 func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    void func_800FFAB0(Actor *);

    switch (arg0->unk70_10) {
    case 3:
        if (func_800D9078(&arg0->unk58) != 0) {
            f32 sp24[3];
            func_800EE7F8(sp24, arg0->position);
            func_800EF1B8(sp24, arg0->rotation[1], -100);
            _chexploder_entrypoint_3(arg0, sp24, 3);
            func_800DA544(0x3A9);
        }
        break;
    case 2:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800F82D4(func_800F54E4(), 0);
            _glcutDll_entrypoint_6(0x1A7, 0x32);
            func_800FFAB0(arg0);
        }
        break;
    }
}

void func_808000C0_chLagoonInnBlockedWall(BT_NATIVE_ONLY(Actor *actor))
{
    func_8010A63C(BT_NATIVE_ONLY(actor));
}

s32 func_808000E0_chLagoonInnBlockedWall(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _glcutDll_entrypoint_19(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    s32 func_800EA05C();
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    u32 func_800F54E4(void);
    void func_800F8300();
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_8010A570(Actor *);
    extern s32 D_80800400_chLagoonInnBlockedWall[];
    extern s32 D_8080046C_chLagoonInnBlockedWall[];
    f32 sp34[3];

    switch (arg1) {
    case 0x49:
        if (_glcutDll_entrypoint_19(0x32)) {
            arg0->unk58 = 0.4f;
            func_80103110(arg0, 1);
            func_80101FDC(arg0, 3);
            _capod_entrypoint_13(arg0->unk0, NULL, 0x1C, 0x910);
            return 1;
        }
        break;
    case 5:
        func_8010A570(arg0);
        func_800EE7F8(sp34, arg0->position);
        func_800EF1B8(sp34, arg0->rotation[1], 100.0f);
        _chexploder_entrypoint_3(arg0, sp34, 3);
        func_800F8300(func_800F54E4(), 2, arg0->position);
        return 1;
    case 0x90:
        if (func_800EA05C() == 0xED) {
            func_80101FDC(arg0, 2);
            func_80103110(arg0, 1);
            arg0->unk58 = 0.8f;
        } else {
            func_800FFAB0(arg0);
        }
        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_80800400_chLagoonInnBlockedWall);
        func_800C4AF0(arg0->position, D_8080046C_chLagoonInnBlockedWall);
        return 1;
    }
    return 0;
}

OSThread *chLagoonInnBlockedWall_entrypoint_0(void)
{
    extern ActorData D_80800480_chLagoonInnBlockedWall[];

    return (OSThread *) D_80800480_chLagoonInnBlockedWall;
}

void func_8080025C_chLagoonInnBlockedWall(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80109704(BtIntPtr, s32, s32, s32, f32, s32, s32, s32);
    extern s32 D_808004C8_chLagoonInnBlockedWall[19];
    extern s32 D_80800514_chLagoonInnBlockedWall[5];
    extern s32 D_80800528_chLagoonInnBlockedWall[9];
    extern s32 D_8080054C_chLagoonInnBlockedWall[9];
    f32 sp34[3];

    func_800EE7F8(sp34, arg0->position);
    sp34[1] += 80.0f;
    func_800BBCB8(sp34, NULL, arg0->scale * 1.2f, 8, D_80800528_chLagoonInnBlockedWall);
    func_800BBCB8(sp34, NULL, arg0->scale * 1.2f, 0x10, D_808004C8_chLagoonInnBlockedWall);
    func_800BBCB8(sp34, sp34, arg0->scale, 0xF, D_8080054C_chLagoonInnBlockedWall);
    func_80109704((BtIntPtr)arg0, 8, -0x28, 0xC8, 1.85f, 0xB4, 0x3C, 0x50);
    _subaddieaudioquick_entrypoint_2(arg0, sp34, D_80800514_chLagoonInnBlockedWall);
    func_800FFAB0(arg0);
    func_80101180(0x488, 5, 0);
}

s32 func_80800398_chLagoonInnBlockedWall(BtIntPtr arg0, s32 arg1, volatile s32 arg2) {
    if (arg1 == 0x40) {
        func_8080025C_chLagoonInnBlockedWall(arg0, *(s32 *)&arg2);
        return 1;
    }
    return 0;
}

OSThread *chLagoonInnBlockedWall_entrypoint_1(void)
{
    extern ActorData D_80800570_chLagoonInnBlockedWall[];

    return (OSThread *) D_80800570_chLagoonInnBlockedWall;
}
/* data_to_c.py: from asm/data/overlays/ch/LagoonInnBlockedWall.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
void func_80102EC0();
s32 D_80800400_chLagoonInnBlockedWall [27] BT_DATA(4, overlays_ch_LagoonInnBlockedWall, 0x0) = { 101711901, 165478443, 33555200, 2228608, 33555584, 100663317, 38, 1638400, 458797, 3276900, 2154151, 1908408330, -6553575, -6553500, 4915300, 102373648, 1902240, 1310765, 26215000, 1834208, -39321566, 11731148, 11731123, 1966130, 3276813, 4921626, 0 };
s32 D_8080046C_chLagoonInnBlockedWall [5] BT_DATA(4, overlays_ch_LagoonInnBlockedWall, 0x6C) = { 1246227, 655590, 1469792, 72036, 425984000 };
ActorData D_80800480_chLagoonInnBlockedWall [1] BT_DATA(4, overlays_ch_LagoonInnBlockedWall, 0x80) = { { 172, 1160, 2287, 1, 0, (void (*)(struct Actor *))func_80800000_chLagoonInnBlockedWall, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 937, 0, 0, 1024, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808000C0_chLagoonInnBlockedWall, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11266, (void (*)(struct Actor *, long, long))func_808000E0_chLagoonInnBlockedWall, 0 } };
s32 D_808004C8_chLagoonInnBlockedWall[19] BT_DATA(4, overlays_ch_LagoonInnBlockedWall, 0xC8) = { 2948700, 26934876, 31458140, 31457307, -78578664, 2031596, 1310756, 3473507, 2752512, 131276, 20119573, 89, 1441796, 1903082, 1638401, 393255, -19595564, 19661100, 0 };
s32 D_80800514_chLagoonInnBlockedWall[5] BT_DATA(4, overlays_ch_LagoonInnBlockedWall, 0x114) = { 1246227, 852198, 16777217, 65542500, 0 };
s32 D_80800528_chLagoonInnBlockedWall[9] BT_DATA(4, overlays_ch_LagoonInnBlockedWall, 0x128) = { 786512, 2294528, 2818432, 27656213, 11731148, 1903035, 1572864, 592896, 201326592 };
s32 D_8080054C_chLagoonInnBlockedWall[9] BT_DATA(4, overlays_ch_LagoonInnBlockedWall, 0x14C) = { 1902243, 1310765, 39322400, 2228326, 8388659, 4980766, 1310740, 852028, 0 };
ActorData D_80800570_chLagoonInnBlockedWall [1] BT_DATA(4, overlays_ch_LagoonInnBlockedWall, 0x170) = { { 886, 1169, 1706, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 937, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11264, (void (*)(struct Actor *, long, long))func_80800398_chLagoonInnBlockedWall, 0 } };
