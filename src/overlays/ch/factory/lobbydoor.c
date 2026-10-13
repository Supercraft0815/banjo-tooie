#include "common.h"

OSThread *chfactorylobbydoor_entrypoint_0(void)
{
    extern u8 D_80800160_chfactorylobbydoor[];

    return (OSThread *) D_80800160_chfactorylobbydoor;
}

/* extern */

void func_8080000C_chfactorylobbydoor(s32 arg0) {
    s32 _chdoormake_entrypoint_3(s32, f32, f32, f32, s32, s32);
    s32 _chdoormake_entrypoint_5(s32, f32);
    s32 _chdoormake_entrypoint_8(s32, s32);
    s32 func_8009E958();
    s32 func_800D0A9C(s32, s32);
    s32 func_800EA090();
    s32 func_80101FDC(s32, s32);
    if ((func_800EA090() == 1) && ((func_800D0A9C(0x35, 1) == 0) || (func_8009E958() != 1))) {
        func_80101FDC(arg0, 1);
    }
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 200.0f, 8, -1) != 0) {
        _chdoormake_entrypoint_5(arg0, 1.5f);
        _chdoormake_entrypoint_8(arg0, 5);
    }
}

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
