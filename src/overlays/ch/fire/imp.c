#include "common.h"

OSThread *chfireimp_entrypoint_0(void)
{
    extern u8 D_808001F8_chfireimp[];

    return (OSThread *) D_808001F8_chfireimp;
}

/* extern */

void func_8080000C_chfireimp(s32 arg0) {
    s32 _sucoasterfly_entrypoint_1(s32, s32);
    f32 *_sucoasterfly_entrypoint_5(s32);
    s32 func_8010A3E8(s32, s32);
    if (_sucoasterfly_entrypoint_1(arg0, 4) != 0) {
        *_sucoasterfly_entrypoint_5(arg0) = 3.4f;
    }
    func_8010A3E8(arg0, 0x3F266666);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/imp/func_8080005C_chfireimp.s")
