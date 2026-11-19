#include "common.h"
#include "core2/switch_animations.h"
s32 func_80800000_chlavaarchgrillswitch(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
void func_80800014_chlavaarchgrillswitch(s32 arg0) 
{
}
OSThread *chlavaarchgrillswitch_entrypoint_0(void)
{
    extern ActorData D_80800030_chlavaarchgrillswitch[];

    return (OSThread *) D_80800030_chlavaarchgrillswitch;
}
/* data_to_c.py: from asm/data/overlays/ch/lava/archgrillswitch.data.s */

void _chswitch_entrypoint_11();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *_chswitch_entrypoint_2(void);
void func_80107C2C();
ActorData D_80800030_chlavaarchgrillswitch [1] BT_DATA(4, overlays_ch_lava_archgrillswitch, 0x0) = { { 835, 647, 2265, 1, (void *)BT_DATA_FIELD(D_8011A2C0, (u8 *)D_8011A270 + 0x50), (void (*)(struct Actor *))_chswitch_entrypoint_11, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2184, 0, (BtIntPtr)_chswitch_entrypoint_2, 0, 0, (void (*)(struct Actor *))func_80800014_chlavaarchgrillswitch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8192, (void (*)(struct Actor *, long, long))func_80800000_chlavaarchgrillswitch, 0 } };
