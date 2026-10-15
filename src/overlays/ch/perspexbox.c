#include "common.h"

s32 func_80800000_chperspexbox(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800FC6B0(u32);
    void func_800FFAB0(Actor *);
    extern s32 D_80800090_chperspexbox;
    extern s32 D_80800124_chperspexbox;

    if (arg1 == 7) {
        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, &D_80800090_chperspexbox);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800124_chperspexbox);
        func_800FC6B0(0x18);
        func_800FFAB0(arg0);
        return 1;
    }
    return 0;
}

OSThread *chperspexbox_entrypoint_0(void)
{
    extern u8 D_80800138_chperspexbox[];

    return (OSThread *) D_80800138_chperspexbox;
}
