#include "ch/lavaentrancebridgeswitch.h"
#include "core2/switch_animations.h"
/* extern */

s32 func_80800000_chlavaentrancebridgeswitch(s32 *arg0, s32 arg1 BT_PASS2(, s32 bt_a2)) {
    s32 _capod_entrypoint_13(BtIntPtr, BtIntPtr, s32, s32);
    s32 _chswitch_entrypoint_10(s32 *);
    s32 func_80101180(s32, s32, BtIntPtr);
    if (arg1 == 7) {
        func_80101180(0x38E, 0x60, 0);
        _capod_entrypoint_13(*arg0, 0, 5, 0x10);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0);
}

void func_8080005C_chlavaentrancebridgeswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_391_PROGRESS_IoH_HFP_BRIDGE_EXTENDED);
    _chswitch_entrypoint_9(arg0);
}

OSThread *chlavaentrancebridgeswitch_entrypoint_0(void)
{
    extern ActorData D_808000A0_chlavaentrancebridgeswitch[];

    return (OSThread *) D_808000A0_chlavaentrancebridgeswitch;
}
/* data_to_c.py: from asm/data/overlays/ch/lava/entrancebridgeswitch.data.s */

void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_808000A0_chlavaentrancebridgeswitch [1] BT_DATA(4, overlays_ch_lava_entrancebridgeswitch, 0x0) = { { 835, 911, 2395, 1, (void *)D_8011A270, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080005C_chlavaentrancebridgeswitch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_80800000_chlavaentrancebridgeswitch, 0 } };
