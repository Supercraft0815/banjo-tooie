#include "common.h"

OSThread *chcastleshockpadswitch_entrypoint_0(void)
{
    extern u8 D_80800170_chcastleshockpadswitch[];

    return (OSThread *) D_80800170_chcastleshockpadswitch;
}

void func_8080000C_chcastleshockpadswitch(Actor *arg0)
{
    s32 _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    s32 _chswitch_entrypoint_7(Actor *, s32);
    s32 _chswitch_entrypoint_9(Actor *);
    void func_800EE7F8(f32 *, f32 *);
    f32 marker[6];

    if (!_subaddiemarker_entrypoint_1(arg0, 0x4E8, 0x32, marker, 1)) {
        func_800FFAB0(arg0);
    } else {
        func_800EE7F8((f32 *)arg0->actorData, marker);
        ((f32 *)arg0->actorData)[3] = marker[4];
        if (_chswitch_entrypoint_7(arg0, 0xA2)) {
            func_80108B04(arg0, 0);
        }
        _chswitch_entrypoint_9(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/castleshockpadswit/func_80800094_chcastleshockpadswitch.s")
