#include "common.h"
#include "core2/switch_animations.h"
#ifdef BT_NATIVE
void func_80800000_chlavaarchgrill3switches(BtIntPtr bt_a0, s32 bt_a1)
#else
void func_80800000_chlavaarchgrill3switches()
#endif
{
    _chswitch_entrypoint_7();
}

void func_80800020_chlavaarchgrill3switches(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    switch (arg1) {
    case 7:
        func_80101180(0x288, arg3, 0);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    case 8:
        func_80101180(0x288, arg4, 0);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    default:
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    }
}

/* extern */

void func_808000C0_chlavaarchgrill3switches(BtIntPtr arg0) {
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    func_80800000_chlavaarchgrill3switches(arg0, 0xA1D);
    _chswitch_entrypoint_8(arg0, 0x200);
}

void func_808000F0_chlavaarchgrill3switches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800020_chlavaarchgrill3switches();
    func_80800020_chlavaarchgrill3switches(arg0, arg1, arg2, 0x63, 0x64);
}

OSThread *chlavaarchgrill3switches_entrypoint_0(void)
{
    extern ActorData D_808001F0_chlavaarchgrill3switches[];

    return (OSThread *) D_808001F0_chlavaarchgrill3switches;
}

/* extern */

void func_80800124_chlavaarchgrill3switches(BtIntPtr arg0) {
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    func_80800000_chlavaarchgrill3switches(arg0, 0xA1E);
    _chswitch_entrypoint_8(arg0, 0x400);
}

void func_80800154_chlavaarchgrill3switches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800020_chlavaarchgrill3switches();
    func_80800020_chlavaarchgrill3switches(arg0, arg1, arg2, 0x61, 0x62);
}

OSThread *chlavaarchgrill3switches_entrypoint_1(void)
{
    extern ActorData D_80800238_chlavaarchgrill3switches[];

    return (OSThread *) D_80800238_chlavaarchgrill3switches;
}

/* extern */

void func_80800188_chlavaarchgrill3switches(BtIntPtr arg0) {
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    func_80800000_chlavaarchgrill3switches(arg0, 0xA1F);
    _chswitch_entrypoint_8(arg0, 0x200);
}

void func_808001B8_chlavaarchgrill3switches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800020_chlavaarchgrill3switches();
    func_80800020_chlavaarchgrill3switches(arg0, arg1, arg2, 0x5D, 0x5E);
}

OSThread *chlavaarchgrill3switches_entrypoint_2(void)
{
    extern ActorData D_80800280_chlavaarchgrill3switches[];

    return (OSThread *) D_80800280_chlavaarchgrill3switches;
}
/* data_to_c.py: from asm/data/overlays/ch/lava/archgrill3switches.data.s */

void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_808001F0_chlavaarchgrill3switches [1] BT_DATA(4, overlays_ch_lava_archgrill3switches, 0x0) = { { 835, 1170, 1976, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_808000C0_chlavaarchgrill3switches, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 10258, (void (*)(struct Actor *, long, long))func_808000F0_chlavaarchgrill3switches, 0 } };
ActorData D_80800238_chlavaarchgrill3switches [1] BT_DATA(4, overlays_ch_lava_archgrill3switches, 0x48) = { { 835, 1171, 1977, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800124_chlavaarchgrill3switches, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 10258, (void (*)(struct Actor *, long, long))func_80800154_chlavaarchgrill3switches, 0 } };
ActorData D_80800280_chlavaarchgrill3switches [1] BT_DATA(4, overlays_ch_lava_archgrill3switches, 0x90) = { { 835, 1172, 1976, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800188_chlavaarchgrill3switches, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 10258, (void (*)(struct Actor *, long, long))func_808001B8_chlavaarchgrill3switches, 0 } };
