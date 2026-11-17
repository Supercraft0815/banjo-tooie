#include "ch/lavatraindoorswitch.h"

s32 func_80800000_chlavatraindoorswitch(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    if (arg1 == 7) {
        _glcutDll_entrypoint_6(0x129U, 0x4DU);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_8080003C_chlavatraindoorswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_1D0_STATION_UNLOCKED_HFPL);
    _chswitch_entrypoint_9(arg0);
}

OSThread *chlavatraindoorswitch_entrypoint_0(void)
{
    extern ActorData D_80800080_chlavatraindoorswitch[];

    return (OSThread *) D_80800080_chlavatraindoorswitch;
}
/* data_to_c.py: from asm/data/overlays/ch/lava/traindoorswitch.data.s */
extern u8 D_8011A248[];
void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800080_chlavatraindoorswitch [1] BT_DATA(4, overlays_ch_lava_traindoorswitch, 0x0) = { { 835, 645, 2157, 1, (void *)D_8011A248, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080003C_chlavatraindoorswitch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32767, 11266, (void (*)(struct Actor *, long, long))func_80800000_chlavatraindoorswitch, 0 } };
