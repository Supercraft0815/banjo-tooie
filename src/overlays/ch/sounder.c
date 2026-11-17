#include "common.h"

void func_80800000_chsounder(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_5(Actor *arg0, f32 *arg1, u32 arg2, s32 arg3, u32 *arg4);
    extern s32 D_808000A0_chsounder[3];
    extern s32 D_808000AC_chsounder[4];

    switch (arg0->unk74_7) {
    case 0x32:
        _subaddieaudioloop_entrypoint_5((BtIntPtr)arg0, (BtIntPtr)arg0->position, 1, -1, D_808000A0_chsounder);
        return;
    case 0x33:
        _subaddieaudioloop_entrypoint_5((BtIntPtr)arg0, (BtIntPtr)arg0->position, 1, -1, D_808000AC_chsounder);
        return;
    }
}

void func_80800078_chsounder(s32 arg0) 
{
}
void func_80800080_chsounder(s32 arg0) 
{
}
OSThread *chsounder_entrypoint_0(void)
{
    extern ActorData D_808000BC_chsounder[];

    return (OSThread *) D_808000BC_chsounder;
}
/* data_to_c.py: from asm/data/overlays/ch/sounder.data.s */
void func_80105834(Actor*);
void func_8010A730();
void func_80107C2C();
s32 D_808000A0_chsounder[3] BT_DATA(4, overlays_ch_sounder, 0x0) = { 1246764, 1459792, 0 };
s32 D_808000AC_chsounder[4] BT_DATA(4, overlays_ch_sounder, 0xC) = { 1246764, 1450792, 65686, 98304000 };
ActorData D_808000BC_chsounder [1] BT_DATA(4, overlays_ch_sounder, 0x1C) = { { 344, 373, 0, 1, 0, (void (*)(struct Actor *))func_80800000_chsounder, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 196608000, 0, 0, 0, 8, 4, (void (*)(struct Actor *))func_80800078_chsounder, 0, 0, 0, (void (*)(struct Actor *))func_80800080_chsounder, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 514, 0, 0 } };
