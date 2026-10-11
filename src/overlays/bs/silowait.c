#include "common.h"

/* extern */

void func_80800000_bssilowait(u8 *arg0) {
    void func_80091E6C(void *arg0);
    void baphysics_reset_gravity(u8 *);
    void baphysics_reset_terminal_velocity(u8 *);
    void func_80092880(void *, s32);
    func_80092880(arg0, 1);
    func_80091E6C(arg0);
    baphysics_reset_gravity(arg0);
    baphysics_reset_terminal_velocity(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/silowait/func_8080003C_bssilowait.s")

/* extern */

void func_808000D0_bssilowait(s32 arg0) {
    s32 bs_setState(s32, s32);
    s32 func_80099AA8(s32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    if (func_8009E6EC() == 0x90) {
        bs_setState(arg0, 1);
        func_8009E830(arg0, 2);
        return;
    }
    func_80099AA8(arg0);
}

void func_80800120_bssilowait(s32 arg0) 
{
}
s32 bssilowait_entrypoint_0(s32 arg0) {
    extern s32 D_80800140_bssilowait[];
    return ((s32 *)&D_80800140_bssilowait)[arg0];
}
