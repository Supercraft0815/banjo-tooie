#include "common.h"

s32 func_80800000_chcrackarchwall(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    void func_800FFAB0(Actor *);
    extern s32 D_808000F0_chcrackarchwall[];
    extern s32 D_80800130_chcrackarchwall[];

    switch (arg1) {
        case 0x95:
            if (func_800DA298(arg0->unk74_7)) {
                func_800FFAB0(arg0);
            }
            break;
        case 0x40:
            func_800DA544(arg0->unk74_7);
            _chexploder_entrypoint_3(arg0, arg0->position, 0xC);
            break;
        case 0x90:
            func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_808000F0_chcrackarchwall);
            func_800C4AF0(arg0->position, D_80800130_chcrackarchwall);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chcrackarchwall_entrypoint_0(void)
{
    extern ActorData D_80800144_chcrackarchwall[];

    return (OSThread *) D_80800144_chcrackarchwall;
}
/* data_to_c.py: from asm/data/overlays/ch/crackarwall.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_808000F0_chcrackarchwall [16] BT_DATA(4, overlays_ch_crackarwall, 0x0) = { 152043549, 165478443, 33555200, 2228608, 33555584, 100663317, 38, 1638400, 458797, 3276900, 2154151, 1908408330, -6553575, -6553500, 4915300, 152698880 };
s32 D_80800130_chcrackarchwall [5] BT_DATA(4, overlays_ch_crackarwall, 0x40) = { 1246227, 655590, 1469792, 66786, 163840000 };
ActorData D_80800144_chcrackarchwall [1] BT_DATA(4, overlays_ch_crackarwall, 0x54) = { { 172, 299, 2297, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_80800000_chcrackarchwall, 0 } };
