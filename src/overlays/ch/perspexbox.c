#include "common.h"

s32 func_80800000_chperspexbox(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800FC6B0(u32);
    void func_800FFAB0(Actor *);
    extern s32 D_80800090_chperspexbox[37];
    extern s32 D_80800124_chperspexbox[5];

    if (arg1 == 7) {
        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_80800090_chperspexbox);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800124_chperspexbox);
        func_800FC6B0(0x18);
        func_800FFAB0(arg0);
        return 1;
    }
    return 0;
}

OSThread *chperspexbox_entrypoint_0(void)
{
    extern ActorData D_80800138_chperspexbox[];

    return (OSThread *) D_80800138_chperspexbox;
}
/* data_to_c.py: from asm/data/overlays/ch/perspexbox.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_80800090_chperspexbox[37] BT_DATA(4, overlays_ch_perspexbox, 0x0) = { 68157469, 165478443, 33555200, 2228608, 33555584, 100663317, 38, 1638400, 458797, 3276900, 2126302, -1480589302, -6553575, -6553500, 4915300, 68814608, 1902835, 1310765, 26215000, 1834208, -39321566, 15073536, 15073510, 1966130, 3276813, 4917018, 118489117, 150405140, 2949520, 39321627, -52363864, 2228454, 16777446, 15073310, 3276850, 852043, 119144448 };
s32 D_80800124_chperspexbox[5] BT_DATA(4, overlays_ch_perspexbox, 0x94) = { 1246349, 655590, 1469792, 66786, 163840000 };
ActorData D_80800138_chperspexbox [1] BT_DATA(4, overlays_ch_perspexbox, 0xA8) = { { 344, 1216, 2290, 1, 0, 0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 1082, 0, 2, 3072, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9218, (void (*)(struct Actor *, long, long))func_80800000_chperspexbox, 0 } };
