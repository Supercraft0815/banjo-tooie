#include "common.h"

void func_80800000_chmumbopadstatue(s32 arg0) 
{
}
s32 func_80800008_chmumbopadstatue(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    extern s32 D_808000A0_chmumbopadstatue[27];
    extern s32 D_8080010C_chmumbopadstatue[5];
    f32 *temp_s0;

    if (arg1 == 0x40) {
        temp_s0 = arg0->position;
        _chexploder_entrypoint_3(arg0, temp_s0, 0xC);
        func_800BABB8(0, temp_s0, temp_s0, arg0->scale, D_808000A0_chmumbopadstatue);
        func_800C4AF0(temp_s0, D_8080010C_chmumbopadstatue);
        return 1;
    }
    return 0;
}

OSThread *chmumbopadstatue_entrypoint_0(void)
{
    extern ActorData D_80800120_chmumbopadstatue[];

    return (OSThread *) D_80800120_chmumbopadstatue;
}
/* data_to_c.py: from asm/data/overlays/ch/mumbo/padstatue.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_808000A0_chmumbopadstatue[27] BT_DATA(4, overlays_ch_mumbo_padstatue, 0x0) = { 101711901, 165478443, 33555200, 2228608, 33555584, 100663317, 38, 1638400, 458797, 3276900, 2154151, 1908408330, -6553575, -6553500, 4915300, 102373648, 1902240, 1310765, 26215000, 1834208, -39321566, 11731148, 11731123, 1966130, 3276813, 4921626, 0 };
s32 D_8080010C_chmumbopadstatue[5] BT_DATA(4, overlays_ch_mumbo_padstatue, 0x6C) = { 1246227, 655590, 1469792, 72036, 425984000 };
ActorData D_80800120_chmumbopadstatue [1] BT_DATA(4, overlays_ch_mumbo_padstatue, 0x80) = { { 172, 514, 1666, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chmumbopadstatue, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 10240, (void (*)(struct Actor *, long, long))func_80800008_chmumbopadstatue, 0 } };
