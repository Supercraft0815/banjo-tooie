#include "common.h"

OSThread *chcoderoomdoor_entrypoint_0(void)
{
    extern u8 D_808000E0_chcoderoomdoor[];

    return (OSThread *) D_808000E0_chcoderoomdoor;
}

s32 func_8080000C_chcoderoomdoor(Actor *arg0, s32 arg1, s32 arg2) {
    f32 sp34[3];
    f32 *sp2C[2];
    extern s32 D_80800128_chcoderoomdoor[];
    extern u8 D_80800170_chcoderoomdoor[];
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);

    switch (arg1) {
        case 0x40: {
            func_800EE7F8(sp34, arg0->position);
            func_800EF1B8(sp34, arg0->rotation[1], -100.0f);
            _chexploder_entrypoint_3(arg0, sp34, 15);
            break;
        }
        case 0x90: {
            sp2C[0] = arg0->position; func_800BABB8(0, sp2C[0], sp2C[0], 1.0f, D_80800128_chcoderoomdoor);
            _subaddieaudioquick_entrypoint_2(arg0, sp2C[0], D_80800170_chcoderoomdoor);
            func_800DA544(0x366);
            break;
        }
        default:
            return 0;
    }
    return 1;
}
