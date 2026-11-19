#include "common.h"
#include "core2/switch_animations.h"
s32 func_80800000_chdrawbridgeswitches(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32); BT_NATIVE_ONLY(s32 native_ret;)
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    BT_NATIVE_ONLY(native_ret = ) _chswitch_entrypoint_7(arg0, arg1);
    _chswitch_entrypoint_8(arg0, arg2); BT_NATIVE_ONLY(return native_ret;)
}

void func_80800030_chdrawbridgeswitches(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    switch (arg1) {
    case 7:
        func_80101180(0x49F, arg3, 0);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    case 8:
        func_80101180(0x49F, arg4, 0);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    default:
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    }
}

void func_808000D0_chdrawbridgeswitches(s32 arg0) {
    s32 func_80800000_chdrawbridgeswitches(BtIntPtr, s32, s32);
    func_80800000_chdrawbridgeswitches(arg0, 0xA20, 512);
}

void func_808000F4_chdrawbridgeswitches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800030_chdrawbridgeswitches();
    func_80800030_chdrawbridgeswitches(arg0, arg1, arg2, 0x69, 0x68);
}

OSThread *chdrawbridgeswitches_entrypoint_0(void)
{
    extern ActorData D_80800210_chdrawbridgeswitches[];

    return (OSThread *) D_80800210_chdrawbridgeswitches;
}

void func_80800128_chdrawbridgeswitches(s32 arg0) {
    s32 func_80800000_chdrawbridgeswitches(BtIntPtr, s32, s32);
    func_80800000_chdrawbridgeswitches(arg0, 0xA21, 1024);
}

void func_8080014C_chdrawbridgeswitches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800030_chdrawbridgeswitches();
    func_80800030_chdrawbridgeswitches(arg0, arg1, arg2, 0x6B, 0x6A);
}

OSThread *chdrawbridgeswitches_entrypoint_1(void)
{
    extern ActorData D_80800258_chdrawbridgeswitches[];

    return (OSThread *) D_80800258_chdrawbridgeswitches;
}

/* extern */

void func_80800180_chdrawbridgeswitches(BtIntPtr arg0) {
    void _chswitch_entrypoint_9(void *arg0);
    func_80800000_chdrawbridgeswitches(arg0, 0x58E, 1);
    _chswitch_entrypoint_9(arg0);
}

void func_808001B0_chdrawbridgeswitches(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    if (arg1 == 7) {
        func_80101180(0x395, 7, 0);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

OSThread *chdrawbridgeswitches_entrypoint_2(void)
{
    extern ActorData D_808002A0_chdrawbridgeswitches[];

    return (OSThread *) D_808002A0_chdrawbridgeswitches;
}
/* data_to_c.py: from asm/data/overlays/ch/drawbridgeswites.data.s */

void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *_chswitch_entrypoint_2(void);
void func_80107C2C();
ActorData D_80800210_chdrawbridgeswitches [1] BT_DATA(4, overlays_ch_drawbridgeswites, 0x0) = { { 835, 1184, 1976, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, (BtIntPtr)_chswitch_entrypoint_2, 0, 0, (void (*)(struct Actor *))func_808000D0_chdrawbridgeswitches, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_808000F4_chdrawbridgeswitches, 0 } };
ActorData D_80800258_chdrawbridgeswitches [1] BT_DATA(4, overlays_ch_drawbridgeswites, 0x48) = { { 835, 1185, 1977, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, (BtIntPtr)_chswitch_entrypoint_2, 0, 0, (void (*)(struct Actor *))func_80800128_chdrawbridgeswitches, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_8080014C_chdrawbridgeswitches, 0 } };
ActorData D_808002A0_chdrawbridgeswitches [1] BT_DATA(4, overlays_ch_drawbridgeswites, 0x90) = { { 835, 1341, 2370, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800180_chdrawbridgeswitches, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_808001B0_chdrawbridgeswitches, 0 } };
