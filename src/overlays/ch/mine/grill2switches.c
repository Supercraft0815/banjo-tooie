#include "common.h"
#include "core2/switch_animations.h"
s32 func_80800000_chminegrill2switches(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    BT_NATIVE_ONLY(s32 result =) _chswitch_entrypoint_7(arg0, arg1);
    _chswitch_entrypoint_8(arg0, arg2); BT_NATIVE_ONLY(return result;)
}

/* extern */

void func_80800030_chminegrill2switches(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    if (arg1 == 7) {
        func_80101180(0x4C2, arg3, 0);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_80800094_chminegrill2switches(s32 arg0) {
    s32 func_80800000_chminegrill2switches(BtIntPtr, s32, s32);
    func_80800000_chminegrill2switches(arg0, 0xA26, 512);
}

void func_808000B8_chminegrill2switches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800030_chminegrill2switches();
#ifdef BT_NATIVE
    ((void (*)())func_80800030_chminegrill2switches)(arg0, arg1, arg2, 0x7A, 0x79);
#else
    func_80800030_chminegrill2switches(arg0, arg1, arg2, 0x7A, 0x79);
#endif
}

OSThread *chminegrill2switches_entrypoint_0(void)
{
    extern ActorData D_80800150_chminegrill2switches[];

    return (OSThread *) D_80800150_chminegrill2switches;
}

void func_808000EC_chminegrill2switches(s32 arg0) {
    s32 func_80800000_chminegrill2switches(BtIntPtr, s32, s32);
    func_80800000_chminegrill2switches(arg0, 0xA28, 1024);
}

void func_80800110_chminegrill2switches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800030_chminegrill2switches();
#ifdef BT_NATIVE
    ((void (*)())func_80800030_chminegrill2switches)(arg0, arg1, arg2, 0x7C, 0x7B);
#else
    func_80800030_chminegrill2switches(arg0, arg1, arg2, 0x7C, 0x7B);
#endif
}

OSThread *chminegrill2switches_entrypoint_1(void)
{
    extern ActorData D_80800198_chminegrill2switches[];

    return (OSThread *) D_80800198_chminegrill2switches;
}
/* data_to_c.py: from asm/data/overlays/ch/mine/grill2switches.data.s */

void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *_chswitch_entrypoint_2(void);
void func_80107C2C();
ActorData D_80800150_chminegrill2switches [1] BT_DATA(4, overlays_ch_mine_grill2switches, 0x0) = { { 835, 1181, 1976, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, (BtIntPtr)_chswitch_entrypoint_2, 0, 0, (void (*)(struct Actor *))func_80800094_chminegrill2switches, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11266, (void (*)(struct Actor *, long, long))func_808000B8_chminegrill2switches, 0 } };
ActorData D_80800198_chminegrill2switches [1] BT_DATA(4, overlays_ch_mine_grill2switches, 0x48) = { { 835, 1182, 1977, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, (BtIntPtr)_chswitch_entrypoint_2, 0, 0, (void (*)(struct Actor *))func_808000EC_chminegrill2switches, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11266, (void (*)(struct Actor *, long, long))func_80800110_chminegrill2switches, 0 } };
