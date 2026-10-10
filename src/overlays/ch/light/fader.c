#include "common.h"

OSThread *chlightfader_entrypoint_0(void)
{
    extern u8 D_808003A0_chlightfader[];

    return (OSThread *) D_808003A0_chlightfader;
}

void func_8080000C_chlightfader(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/fader/func_80800014_chlightfader.s")

s32 chlightfader_entrypoint_1(s32 arg0, s32 arg1, s32 arg2) {
    void _chbaddiesetup_entrypoint_3(s32 *, s32, s32, s32);
    void func_800C8B84(s32);
    s32 func_800C954C(void);
    extern s32 _chlightfader_entrypoint_2;
    if (func_800C954C() == 0) {
        _chbaddiesetup_entrypoint_3(&_chlightfader_entrypoint_2, arg0, arg1, arg2);
    } else {
        func_800C8B84(arg0);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/fader/chlightfader_entrypoint_2.s")
