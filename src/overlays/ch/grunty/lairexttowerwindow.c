#include "common.h"

void func_80800000_chgruntylairexttowerwindow(s32 arg0) 
{
}
s32 func_80800008_chgruntylairexttowerwindow(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void func_80800070_chgruntylairexttowerwindow(Actor *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x40:
            _chexploder_entrypoint_3(arg0, arg0->position, 0xC);
            break;
        case 0x90:
            func_80800070_chgruntylairexttowerwindow(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800070_chgruntylairexttowerwindow(Actor *arg0) {
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    extern s32 D_808000D0_chgruntylairexttowerwindow[27];
    extern s32 D_8080013C_chgruntylairexttowerwindow[5];
    (void)&arg0;
    func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_808000D0_chgruntylairexttowerwindow);
    func_800C4AF0(arg0->position, D_8080013C_chgruntylairexttowerwindow);
}

OSThread *chgruntylairexttowerwindow_entrypoint_0(void)
{
    extern ActorData D_80800150_chgruntylairexttowerwindow[];

    return (OSThread *) D_80800150_chgruntylairexttowerwindow;
}
/* data_to_c.py: from asm/data/overlays/ch/grunty/lairexttowerwindow.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_808000D0_chgruntylairexttowerwindow[27] BT_DATA(4, overlays_ch_grunty_lairexttowerwindow, 0x0) = { 101711901, 165478443, 33555200, 2228608, 33555584, 100663317, 38, 1638400, 458797, 3276900, 2154151, 1908408330, -6553575, -6553500, 4915300, 102373648, 1902240, 1310765, 26215000, 1834208, -39321566, 11731148, 11731123, 1966130, 3276813, 4921626, 0 };
s32 D_8080013C_chgruntylairexttowerwindow[5] BT_DATA(4, overlays_ch_grunty_lairexttowerwindow, 0x6C) = { 1246227, 655590, 1469792, 66786, 163840000 };
ActorData D_80800150_chgruntylairexttowerwindow [1] BT_DATA(4, overlays_ch_grunty_lairexttowerwindow, 0x80) = { { 172, 907, 1666, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chgruntylairexttowerwindow, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 10240, (void (*)(struct Actor *, long, long))func_80800008_chgruntylairexttowerwindow, 0 } };
