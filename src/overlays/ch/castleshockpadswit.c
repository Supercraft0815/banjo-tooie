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

s32 func_80800094_chcastleshockpadswitch(Actor *arg0, s32 arg1, s32 arg2)
{
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _chappearfx_entrypoint_1(Actor *, u32, u32, f32);
    s32 _chswitch_entrypoint_10(Actor *, s32, s32);
    s32 _subaddiefade_entrypoint_2();
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    Actor *spawned;

    switch (arg1) {
        case 7:
            func_80108B04(arg0, 1);
            _capod_entrypoint_13(arg0->unk0, NULL, 6, 0x10);
            break;
        case 0x3D:
            spawned = func_80108528(0x210, (f32 *)arg0->actorData,
                                  (s32)((f32 *)arg0->actorData)[3], &arg0);
            if (arg2 != 0) {
                _subaddiefade_entrypoint_2(spawned);
                _chappearfx_entrypoint_1(spawned, 0x22, 1, 1.0f);
            }
            break;
        default:
            return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return 1;
}
