#include "common.h"

void func_80800000_chperspexboxswitch(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _chswitch_entrypoint_10(Actor *, s32, s32);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x4C0, 7, 0);
        _capod_entrypoint_13(arg0->unk0, NULL, 0xE, 0x10);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

/* extern */

void func_80800080_chperspexboxswitch(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    s32 func_80104E78(s32);
    _chswitch_entrypoint_7(arg0, 0x43A);
    _chswitch_entrypoint_8(arg0, 0x201);
    _chswitch_entrypoint_9(arg0);
    func_80104E78(arg0);
}

OSThread *chperspexboxswitch_entrypoint_0(void)
{
    extern u8 D_808000D0_chperspexboxswitch[];

    return (OSThread *) D_808000D0_chperspexboxswitch;
}
