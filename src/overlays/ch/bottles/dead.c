#include "common.h"

void func_80800000_chbottlesdead(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.15f);
}

void func_80800034_chbottlesdead(BT_NATIVE_ONLY(Actor *bt_a0))
{
    BT_ILP32_ONLY(void func_8010C964(u8 *);)
    func_8010C964(BT_ILP32_ONLY((u8 *)bt_a0));
}

/* extern */

void func_80800054_chbottlesdead(BtIntPtr arg0, BtIntPtr arg1) {
    void func_800DF744(s32 index,s32 value);
    void func_80101870(Actor* arg0, void* arg1);
    func_800DF744(3, 0);
    func_80101870(arg0, arg1);
}

OSThread *chbottlesdead_entrypoint_0(void)
{
    extern ActorData D_808000C0_chbottlesdead[];

    return (OSThread *) D_808000C0_chbottlesdead;
}
/* data_to_c.py: from asm/data/overlays/ch/bottles/dead.data.s */
extern u8 D_808000B0_chbottlesdead[];
void func_80105834(Actor*);
void func_80107C2C();
u8 D_808000B0_chbottlesdead[16] BT_DATA(4, overlays_ch_bottles_dead, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x04, 0x60, 0x00, 0x84 };
ActorData D_808000C0_chbottlesdead [1] BT_DATA(4, overlays_ch_bottles_dead, 0x10) = { { 344, 1212, 2243, 1, (void *)D_808000B0_chbottlesdead, (void (*)(struct Actor *))func_80800034_chbottlesdead, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800054_chbottlesdead, 19660800, 1091917141, 59, 0, 0, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chbottlesdead, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 13318, 0, 0 } };
