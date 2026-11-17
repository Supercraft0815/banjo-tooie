#include "common.h"

void func_80800000_chwaterfallgrillswitch(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    if (arg1 == 7) {
        func_80101180(0x11B, 7, 0);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_80800054_chwaterfallgrillswitch(Actor *arg0) {
    void _chswitch_entrypoint_8(s16 *arg0, s32 arg1);
    s32 _chswitch_entrypoint_7(void *arg0, s32 arg1);
    _chswitch_entrypoint_7(arg0, 0);
    _chswitch_entrypoint_8((s16 *) arg0, 0x201);
}

OSThread *chwaterfallgrillswitch_entrypoint_0(void)
{
    extern ActorData D_80800090_chwaterfallgrillswitch[];

    return (OSThread *) D_80800090_chwaterfallgrillswitch;
}
/* data_to_c.py: from asm/data/overlays/ch/waterfall/grillswitch.data.s */
extern u8 D_8011A248[];
void _chswitch_entrypoint_6();
void func_80102EC0();
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800090_chwaterfallgrillswitch [1] BT_DATA(4, overlays_ch_waterfall_grillswitch, 0x0) = { { 12, 284, 1664, 1, (void *)D_8011A248, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800054_chwaterfallgrillswitch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_80800000_chwaterfallgrillswitch, 0 } };
