#include "common.h"

OSThread *chklungoleave_entrypoint_0(void)
{
    extern u8 D_80800130_chklungoleave[];

    return (OSThread *) D_80800130_chklungoleave;
}

/* extern */

void func_8080000C_chklungoleave(Actor *arg0) {
    void func_80105A9C(Actor*, f32);
    s32 func_80105BAC(Actor *);
    func_80105A9C(arg0, 300.0f);
    func_80105BAC(arg0);
}

void func_80800038_chklungoleave(s32 arg0)
{
    func_80105834();
    func_808000F0_chklungoleave(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/leave/func_80800060_chklungoleave.s")

int func_808000F0_chklungoleave(s32 arg0) { s32 func_80105230(); extern s32 D_80800178_chklungoleave; func_80105230(arg0, &D_80800178_chklungoleave); }
