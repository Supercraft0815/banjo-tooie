#include "common.h"

s32 baeggaim_entrypoint_0() 
{
    return 0x4;
}

f32 func_80800008_baeggaim(f32 arg0, f32 arg1, f32 arg2) { s32 func_800D8FEC(); f32 func_800F0DC0(f32, f32); f32 temp_f0; f32 var_f20; s32 var_s0; var_f20 = arg0;
    var_s0 = 0;
    if ((func_800D8FEC() * 5) > 0) {
        do {
            temp_f0 = func_800F0DC0((arg1 - var_f20) * 0.04f, arg2);
            var_s0 += 1;
            var_f20 += temp_f0;
        } while (var_s0 < (func_800D8FEC() * 5));
    }
    return var_f20;
}

void func_808000B4_baeggaim(struct player_state_s *arg0, f32 *arg1) { s32 _baeggcursor_entrypoint_10(void *, f32, f32); s32 _baeggcursor_entrypoint_3(void *, f32 *, f32 *); f32 bastick_getX(struct player_state_s *); f32 bastick_getY(struct player_state_s *); f32 func_80800008_baeggaim(f32, f32, f32); f32 sp24; f32 sp20; f32 temp_f0;
    _baeggcursor_entrypoint_3(arg0, arg1, arg1 + 1);
    sp24 = (bastick_getX(arg0) * 114.0f) + 114.0f + 38.0f;
    sp20 = (bastick_getY(arg0) * 85.5f) + 85.5f + 28.5f;
    arg1[0] = func_80800008_baeggaim(arg1[0], sp24, 7.4f);
    temp_f0 = func_80800008_baeggaim(arg1[1], sp20, 5.5f);
    arg1[1] = temp_f0;
    _baeggcursor_entrypoint_10(arg0, arg1[0], temp_f0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/aim/func_80800170_baeggaim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/aim/func_80800264_baeggaim.s")

void baeggaim_entrypoint_1(s32 arg0)
{
    _baeggcursor_entrypoint_7(arg0,0x4);
    _baeggfire_entrypoint_4(arg0);
}

void baeggaim_entrypoint_2(s32 arg0)
{
    _baeggcursor_entrypoint_7(arg0,0x3);
    _baeggfire_entrypoint_5(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/aim/baeggaim_entrypoint_3.s")
