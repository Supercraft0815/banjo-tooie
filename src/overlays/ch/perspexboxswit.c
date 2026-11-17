#include "common.h"

void func_80800000_chperspexboxswitch(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _chswitch_entrypoint_10(Actor *, s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    if (arg1 == 7) {
        func_80101180(0x4C0, 7, 0);
        _capod_entrypoint_13(arg0->unk0, NULL, 0xE, 0x10);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

/* extern */

void func_80800080_chperspexboxswitch(BtIntPtr arg0) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    void _chswitch_entrypoint_9(void *arg0);
    s32 func_80104E78(Actor *arg0);
    _chswitch_entrypoint_7(arg0, 0x43A);
    _chswitch_entrypoint_8(arg0, 0x201);
    _chswitch_entrypoint_9(arg0);
    func_80104E78(arg0);
}

OSThread *chperspexboxswitch_entrypoint_0(void)
{
    extern ActorData D_808000D0_chperspexboxswitch[];

    return (OSThread *) D_808000D0_chperspexboxswitch;
}
/* data_to_c.py: from asm/data/overlays/ch/perspexboxswit.data.s */
extern u8 D_8011A1BC[];
void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *_chswitch_entrypoint_2(void);
void func_80107C2C();
ActorData D_808000D0_chperspexboxswitch [1] BT_DATA(4, overlays_ch_perspexboxswit, 0x0) = { { 835, 1217, 1976, 1, (void *)((u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2056, 0, (BtIntPtr)_chswitch_entrypoint_2, 0, 0, (void (*)(struct Actor *))func_80800080_chperspexboxswitch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_80800000_chperspexboxswitch, 0 } };
