#include "ch/lavacolumnswitch.h"
#include "core2/switch_animations.h"
s32 func_80800000_chlavacolumnswitch(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    if (arg1 == 7) {
        _glcutDll_entrypoint_6(0x127U, 0x4EU);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_8080003C_chlavacolumnswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_390_UNK);
    _chswitch_entrypoint_9(arg0);
}

OSThread *chlavacolumnswitch_entrypoint_0(void)
{
    extern ActorData D_80800080_chlavacolumnswitch[];

    return (OSThread *) D_80800080_chlavacolumnswitch;
}
/* data_to_c.py: from asm/data/overlays/ch/lava/columnswitch.data.s */

void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800080_chlavacolumnswitch [1] BT_DATA(4, overlays_ch_lava_columnswitch, 0x0) = { { 835, 638, 2262, 1, (void *)D_8011A270, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080003C_chlavacolumnswitch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11266, (void (*)(struct Actor *, long, long))func_80800000_chlavacolumnswitch, 0 } };
