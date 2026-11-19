#include "common.h"
#include "core2/switch_animations.h"
s32 func_80800000_chdinotraindoorswitch(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    if (arg1 == 7) {
        _glcutDll_entrypoint_6(0x114U, 0x3CU);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

/* extern */

void func_8080003C_chdinotraindoorswitch(BtIntPtr arg0) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    void _chswitch_entrypoint_9(void *arg0);
    s32 func_80104E78(Actor *arg0);
    _chswitch_entrypoint_7(arg0, 0x164);
    _chswitch_entrypoint_9(arg0);
    func_80104E78(arg0);
}

OSThread *chdinotraindoorswitch_entrypoint_0(void)
{
    extern ActorData D_80800080_chdinotraindoorswitch[];

    return (OSThread *) D_80800080_chdinotraindoorswitch;
}
/* data_to_c.py: from asm/data/overlays/ch/dino/traindoorswitch.data.s */

void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800080_chdinotraindoorswitch [1] BT_DATA(4, overlays_ch_dino_traindoorswitch, 0x0) = { { 835, 1180, 2157, 1, (void *)D_8011A248, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080003C_chdinotraindoorswitch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_80800000_chdinotraindoorswitch, 0 } };
