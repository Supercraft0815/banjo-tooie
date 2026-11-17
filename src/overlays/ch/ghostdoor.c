#include "ch/ghostdoor.h"

OSThread *chghostdoor_entrypoint_0(void)
{
    extern ActorData D_80800220_chghostdoor[];

    return (OSThread *) D_80800220_chghostdoor;
}

OSThread *chghostdoor_entrypoint_1(void)
{
    extern ActorData D_80800268_chghostdoor[];

    return (OSThread *) D_80800268_chghostdoor;
}

/* extern */

void func_80800018_chghostdoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    void func_800EFD24(f32 *);
    void func_800FFAB0(Actor *);
    void func_80103014(Actor *);
    f32 var_f0;
    s32 var_v0;

    var_f0 = arg0->rotation[1];
    var_v0 = 0;
    if (arg0->unk74_7 == 0x32) {
        var_v0 = 1;
        var_f0 += 180.0f;
    }
    func_800EFD24(arg0->position);
    func_80103014(arg0);
    if (_chdoormake_entrypoint_3(arg0, var_f0, 0.0f, 650.0f, 0x20, 0x96) != 0) {
        _chdoormake_entrypoint_5(arg0, 3.5f);
        _chdoormake_entrypoint_6(arg0, 2.0f);
        if (var_v0 != 0) {
            _chdoormake_entrypoint_8(arg0, 0xF);
        }
    }
    if (func_800DA298(FLAG_096_STATION_UNLOCKED_WW) != 0) {
        func_800FFAB0(arg0);
    }
}

s32 func_808000F4_chghostdoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(BtIntPtr, s32, BtIntPtr);
    void func_800FFAB0(Actor *);
    s32 func_80103140(Actor *, u32, u16);
    s32 id;

    switch (arg1) {
        case 0x95:
            id = arg0->unk74_7 == 0x32 ? 0x782 : 0x783;
            func_80103140(arg0, (u16)id, arg0->unk0->unk16);
            break;
        case 0x9D:
            func_800FFAB0(arg0);
            return 1;
    }
    return _chdoor_entrypoint_1((BtIntPtr)arg0, arg1, arg2);
}

void func_80800190_chghostdoor(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_096_STATION_UNLOCKED_WW);
    _chswitch_entrypoint_9(arg0);
}

/* extern */

s32 func_808001BC_chghostdoor(Actor *arg0, s32 arg1 BT_PASS2(, s32 bt_a2)) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _chswitch_entrypoint_10(Actor * BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2));
    s32 func_80101180(s32, s32, BtIntPtr);
    int result;
    if (arg1 == 7) {
        _capod_entrypoint_13(arg0->unk0, 0, 5, 0x10);
        func_80101180(0x344, 7, 0);
        result = 1;
    } else {
        return _chswitch_entrypoint_10(arg0 BT_PASS2(, arg1) BT_PASS2(, bt_a2));
    }
    return result;
}
/* data_to_c.py: from asm/data/overlays/ch/ghostdoor.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
extern u8 D_8011A248[];
void _chswitch_entrypoint_6();
ActorData D_80800220_chghostdoor [1] BT_DATA(4, overlays_ch_ghostdoor, 0x0) = { { 172, 836, -1, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800018_chghostdoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11266, (void (*)(struct Actor *, long, long))func_808000F4_chghostdoor, 0 } };
ActorData D_80800268_chghostdoor [1] BT_DATA(4, overlays_ch_ghostdoor, 0x48) = { { 835, 840, 2157, 1, (void *)D_8011A248, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2060, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800190_chghostdoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_808001BC_chghostdoor, 0 } };
