#include "common.h"

s32 func_80800000_chcrackarchwall(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    void func_800FFAB0(Actor *);
    extern s32 D_808000F0_chcrackarchwall[];
    extern s32 D_80800130_chcrackarchwall[];

    switch (arg1) {
        case 0x95:
            if (func_800DA298(arg0->unk74_7)) {
                func_800FFAB0(arg0);
            }
            break;
        case 0x40:
            func_800DA544(arg0->unk74_7);
            _chexploder_entrypoint_3(arg0, arg0->position, 0xC);
            break;
        case 0x90:
            func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_808000F0_chcrackarchwall);
            func_800C4AF0(arg0->position, D_80800130_chcrackarchwall);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chcrackarchwall_entrypoint_0(void)
{
    extern u8 D_80800144_chcrackarchwall[];

    return (OSThread *) D_80800144_chcrackarchwall;
}
