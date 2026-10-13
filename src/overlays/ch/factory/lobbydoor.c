#include "common.h"

OSThread *chfactorylobbydoor_entrypoint_0(void)
{
    extern u8 D_80800160_chfactorylobbydoor[];

    return (OSThread *) D_80800160_chfactorylobbydoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/lobbydoor/func_8080000C_chfactorylobbydoor.s")

void func_808000A8_chfactorylobbydoor(s32 arg0)
{
    func_808000D0_chfactorylobbydoor();
    _chdoor_entrypoint_0(arg0);
}
int func_808000D0_chfactorylobbydoor(s32 arg0) { s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *); s32 _chmrtannoy_entrypoint_0(void); extern s32 D_808001A8_chfactorylobbydoor; if (_subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_808001A8_chfactorylobbydoor) != 0) { _chmrtannoy_entrypoint_0(); } }

s32 func_80800108_chfactorylobbydoor(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    s32 func_8010108C(Actor*, s32, s32, s32);
    if (arg1 == 0x2E) {
        if (*(s16 *) &arg2 == 0x1370) {
            func_8010108C(arg0, 7, 0, arg3);
        }
        return 1;
    }
    return _chdoor_entrypoint_1((s32) arg0, arg1, (s32) arg2);
}
