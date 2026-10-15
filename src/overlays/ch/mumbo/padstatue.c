#include "common.h"

void func_80800000_chmumbopadstatue(s32 arg0) 
{
}
s32 func_80800008_chmumbopadstatue(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    extern s32 D_808000A0_chmumbopadstatue;
    extern s32 D_8080010C_chmumbopadstatue;
    f32 *temp_s0;

    if (arg1 == 0x40) {
        temp_s0 = arg0->position;
        _chexploder_entrypoint_3(arg0, temp_s0, 0xC);
        func_800BABB8(0, temp_s0, temp_s0, arg0->scale, &D_808000A0_chmumbopadstatue);
        func_800C4AF0(temp_s0, &D_8080010C_chmumbopadstatue);
        return 1;
    }
    return 0;
}

OSThread *chmumbopadstatue_entrypoint_0(void)
{
    extern u8 D_80800120_chmumbopadstatue[];

    return (OSThread *) D_80800120_chmumbopadstatue;
}
