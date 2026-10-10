#include "common.h"

void func_80800000_chbottlesdead(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.15f);
}

void func_80800034_chbottlesdead()
{
    func_8010C964();
}

/* extern */

void func_80800054_chbottlesdead(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(3, 0);
    func_80101870(arg0, arg1);
}

OSThread *chbottlesdead_entrypoint_0(void)
{
    extern u8 D_808000C0_chbottlesdead[];

    return (OSThread *) D_808000C0_chbottlesdead;
}
