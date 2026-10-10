#include "common.h"

s32 func_80800000_chdinotraindoorswitch(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    if (arg1 == 7) {
        _glcutDll_entrypoint_6(0x114U, 0x3CU);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

/* extern */

void func_8080003C_chdinotraindoorswitch(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    s32 func_80104E78(s32);
    _chswitch_entrypoint_7(arg0, 0x164);
    _chswitch_entrypoint_9(arg0);
    func_80104E78(arg0);
}

OSThread *chdinotraindoorswitch_entrypoint_0(void)
{
    extern u8 D_80800080_chdinotraindoorswitch[];

    return (OSThread *) D_80800080_chdinotraindoorswitch;
}
