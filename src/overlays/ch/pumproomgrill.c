#include "common.h"

OSThread *chpumproomgrill_entrypoint_0(void)
{
    extern u8 D_808000E0_chpumproomgrill[];

    return (OSThread *) D_808000E0_chpumproomgrill;
}

void func_8080000C_chpumproomgrill(s32 arg0) 
{
}
s32 func_80800014_chpumproomgrill(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_808000AC_chpumproomgrill(Actor *);
    f32 sp1C[3];

    switch (arg1) {
    case 0x40:
        func_800EE7F8(sp1C, arg0->position);
        func_800EF1B8(sp1C, arg0->rotation[1], -400.0f);
        _chexploder_entrypoint_3(arg0, sp1C, 0xF);
        break;
    case 0x90:
        func_808000AC_chpumproomgrill(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808000AC_chpumproomgrill(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor*, f32[3], void*);
    s32 func_800DA544(s32);
    extern s32 D_80800128_chpumproomgrill;
    _subaddieaudioquick_entrypoint_2(arg0, (f32 *)((u8 *)arg0 + 4), &D_80800128_chpumproomgrill);
    func_800DA544(0x162);
}
