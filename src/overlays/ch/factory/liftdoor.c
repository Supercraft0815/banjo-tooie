#include "common.h"
#include "core2/switch_animations.h"
OSThread *chfactoryliftdoor_entrypoint_0(void)
{
    extern ActorData D_80800140_chfactoryliftdoor[];

    return (OSThread *) D_80800140_chfactoryliftdoor;
}

OSThread *chfactoryliftdoor_entrypoint_1(void)
{
    extern ActorData D_80800188_chfactoryliftdoor[];

    return (OSThread *) D_80800188_chfactoryliftdoor;
}

/* extern */

void func_80800018_chfactoryliftdoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    void func_8010A800(Actor *, s32);
    s32 switch_id;
    switch_id = arg0->unk74_7 + 0xC;
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 300.0f, 1, switch_id) != 0) {
        _chdoormake_entrypoint_5(arg0, 1.5f);
        _chdoormake_entrypoint_8(arg0, 4);
    }
    func_8010A800(arg0, 0);
}

/* extern */

void func_8080008C_chfactoryliftdoor(Actor *arg0) {
    s32 _chswitch_entrypoint_14(BtIntPtr, s32);
    s32 func_800DA298(s32);
    s32 func_80105010();
    void func_80109EEC(s16 *, s32);
    s32 sp24[2];
    s32 temp_a1;

    temp_a1 = arg0->unk74_7 + 0xC;
    sp24[1] = temp_a1;
    _chswitch_entrypoint_14((BtIntPtr)arg0, temp_a1);
    func_80109EEC((s16 *)arg0, 0x40);
    func_80105010(arg0);
    if (func_800DA298(sp24[1]) != 0) {
        func_8010A570(arg0);
    }
}

s32 func_808000F0_chfactoryliftdoor(Actor *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 7) {
        func_80101180(0x3B8, arg1, 0);
        func_8010A570(arg0);
    } else {
        return 0;
    }
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/factory/liftdoor.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);

void _chswitch_entrypoint_13();
OSThread *_chswitch_entrypoint_0(void);
ActorData D_80800140_chfactoryliftdoor [1] BT_DATA(4, overlays_ch_factory_liftdoor, 0x0) = { { 172, 952, 1864, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800018_chfactoryliftdoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11346, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
ActorData D_80800188_chfactoryliftdoor [1] BT_DATA(4, overlays_ch_factory_liftdoor, 0x48) = { { 169, 953, 1865, 1, (void *)BT_DATA_FIELD(D_8011A298, (u8 *)D_8011A270 + 0x28), (void (*)(struct Actor *))_chswitch_entrypoint_13, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, (BtIntPtr)_chswitch_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_8080008C_chfactoryliftdoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11280, (void (*)(struct Actor *, long, long))func_808000F0_chfactoryliftdoor, 0 } };
