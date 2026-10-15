#include "common.h"

OSThread *chminelobbydoor_entrypoint_0(void)
{
    extern u8 D_808001F0_chminelobbydoor[];

    return (OSThread *) D_808001F0_chminelobbydoor;
}

/* extern */

void func_8080000C_chminelobbydoor(s32 arg0) {
    s32 _chdoormake_entrypoint_3(s32, f32, f32, f32, s32, s32);
    s32 _chdoormake_entrypoint_5(s32, f32);
    s32 _chdoormake_entrypoint_8(s32, s32);
    s32 func_8009E958();
    s32 func_800D0A9C(s32, s32);
    s32 func_800EA090();
    s32 func_80101FDC(s32, s32);
    if ((func_800EA090() == 1) && ((func_800D0A9C(0xF, 1) == 0) || (func_8009E958() != 1))) {
        func_80101FDC(arg0, 1);
    }
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 200.0f, 8, -1) != 0) {
        _chdoormake_entrypoint_5(arg0, 1.5f);
        _chdoormake_entrypoint_8(arg0, 14);
    }
}

void func_808000A8_chminelobbydoor(s32 arg0)
{
    func_808000D0_chminelobbydoor();
    _chdoor_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/lobbydoor/func_808000D0_chminelobbydoor.s")

/* extern */

s32 func_8080018C_chminelobbydoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    s32 func_8010108C(Actor *, s32, s32);
    if (arg1 == 0x2E) {
        if (*(s16 *) &arg2 == 0xFA1) {
            func_8010108C(arg0, 7, 0);
            return 1;
        }
        return 1;
    }
    return _chdoor_entrypoint_1((s32) arg0, arg1, arg2);
}
