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

void func_8080005C_chfireimp(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _sucoasterfly_entrypoint_3(Actor *);
    f32 *_sucoasterfly_entrypoint_5(s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    s32 func_800EFFB4(f32[3], f32, f32[3]);
    void func_8010D640(s32);
    extern s32 D_80800240_chfireimp;
    f32 *sp2C;
    s32 var_v1;
    f32 sp1C[3];

    sp2C = _sucoasterfly_entrypoint_5(arg0);
    var_v1 = 1;
    _sucoasterfly_entrypoint_3(arg0);
    switch (arg0->unk70_10) {
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        var_v1 = 0;
        break;
    }
    if ((var_v1 != 0) && (func_800D90A4(sp2C) != 0)) {
        func_8010D640(sp1C);
        if (func_800EFFB4(arg0->position, 1800.0f, sp1C) != 0) {
            *sp2C = func_800DC178(2.4f, 3.4f);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800240_chfireimp);
        }
    }
}
