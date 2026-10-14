#include "common.h"

struct player_state_s;

void bsbkflamethrower_entrypoint_0(struct player_state_s *arg0, f32 arg1[3], f32 arg2[3]) {
    f32 func_8009BFCC(struct player_state_s *);
    void func_8009C128(struct player_state_s *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA98(f32 *, f32 *, f32);
    f32 yaw_get(struct player_state_s *);
    f32 sp24[3];
    f32 sp20;
    f32 sp1C;

    sp1C = func_8009BFCC(arg0);
    func_800EEC30(arg2, -sp1C, yaw_get(arg0), 1.0f);
    func_8009C128(arg0, arg1);
    func_800EFA98(sp24, arg2, 40.0f);
    func_800EF04C(arg1, sp24);
    arg1[1] += 94.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bkflamethrower/func_80800094_bsbkflamethrower.s")

void bsbkflamethrower_entrypoint_1(s32 arg0)
{
    func_80800094_bsbkflamethrower(arg0,0);
}

void bsbkflamethrower_entrypoint_2(s32 *arg0) { arg0[87] = 0; func_80800094_bsbkflamethrower(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bkflamethrower/bsbkflamethrower_entrypoint_3.s")

s32 bsbkflamethrower_entrypoint_4(s32 arg0) {
    extern s32 D_80800450_bsbkflamethrower[];
    return ((s32 *)&D_80800450_bsbkflamethrower)[arg0];
}
