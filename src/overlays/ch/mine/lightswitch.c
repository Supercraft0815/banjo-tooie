#include "ch/minelightswitch.h"

s32 func_80800000_chminelightswitch(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);

    switch (arg1) {
        case 7:
            if (func_800DA298(0x673) == 0) {
                _glcutDll_entrypoint_6(0xCF, 0x15);
            }
            break;
        case 8:
            if (func_800DA298(0x673) == 0) {
                func_800DA544(0x673);
                _glcutDll_entrypoint_6(0xCF, 0x15);
            }
            break;
        default:
            return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return 1;
}

void func_80800094_chminelightswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_9E0_UNK);
}

OSThread *chminelightswitch_entrypoint_0(void)
{
    extern ActorData D_808000C0_chminelightswitch[];

    return (OSThread *) D_808000C0_chminelightswitch;
}
/* data_to_c.py: from asm/data/overlays/ch/mine/lightswitch.data.s */
extern u8 D_8011A248[];
void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_808000C0_chminelightswitch [1] BT_DATA(4, overlays_ch_mine_lightswitch, 0x0) = { { 711, 770, 1703, 1, (void *)D_8011A248, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800094_chminelightswitch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_80800000_chminelightswitch, 0 } };
