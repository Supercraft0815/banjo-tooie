#include "ch/hagstraindoorswit.h"

s32 func_80800000_chhagstraindoorswitch(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    if (arg1 == 7) {
        func_80101180(0x38C, 7, 0);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_80800040_chhagstraindoorswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_403_STATION_UNLOCKED_IoH);
    _chswitch_entrypoint_9(arg0);
}

OSThread *chhagstraindoorswitch_entrypoint_0(void)
{
    extern ActorData D_80800080_chhagstraindoorswitch[];

    return (OSThread *) D_80800080_chhagstraindoorswitch;
}
/* data_to_c.py: from asm/data/overlays/ch/hagstraindoorswit.data.s */
extern u8 D_8011A270[];
void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800080_chhagstraindoorswitch [1] BT_DATA(4, overlays_ch_hagstraindoorswit, 0x0) = { { 835, 909, 2157, 1, (void *)((u8 *)D_8011A270 + 0x50), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800040_chhagstraindoorswitch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32767, 11266, (void (*)(struct Actor *, long, long))func_80800000_chhagstraindoorswitch, 0 } };
