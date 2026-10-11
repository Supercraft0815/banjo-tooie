#include "common.h"

OSThread *chpumproomgrill_entrypoint_0(void)
{
    extern u8 D_808000E0_chpumproomgrill[];

    return (OSThread *) D_808000E0_chpumproomgrill;
}

void func_8080000C_chpumproomgrill(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pumproomgrill/func_80800014_chpumproomgrill.s")

void func_808000AC_chpumproomgrill(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor*, f32[3], void*);
    s32 func_800DA544(s32);
    extern s32 D_80800128_chpumproomgrill;
    _subaddieaudioquick_entrypoint_2(arg0, (f32 *)((u8 *)arg0 + 4), &D_80800128_chpumproomgrill);
    func_800DA544(0x162);
}
