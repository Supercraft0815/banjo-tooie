#include "common.h"

s32 func_80800000_bsdronebubbled(u8 *arg0) {
    s32 func_8010114C(s32, s32, s32);
    s32 temp_v0;

    temp_v0 = func_8010114C((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (0x48))), 0x2C, (*(s32 *)((s8 *)(arg0) + (0x184))));
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (0x48))) = 0;
    return temp_v0;
}

/* extern */

void bsdronebubbled_entrypoint_0(void *arg0) {
    s32 func_80800000_bsdronebubbled();
    if ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (0x48))) != 0) {
        func_80800000_bsdronebubbled();
    }
}

/* extern */

void bsdronebubbled_entrypoint_1(s32 arg0) {
    void _badata_entrypoint_0(s32, s32 *, f32 *);
    s32 baanim_playForDuration_loopSmooth(s32, s32, f32);
    void func_8009D9D4(s32);
    void func_8009FFD8(s32, s32, s32, s32, s32);
    f32 sp2C;
    s32 sp28;

    _badata_entrypoint_0(arg0, &sp28, &sp2C);
    baanim_playForDuration_loopSmooth(arg0, sp28, sp2C);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (0x44))) = sp2C;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (0x40))) = 0.0f;
    func_8009FFD8(arg0, 1, 1, 3, 7);
    func_8009D9D4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bubbled/bsdronebubbled_entrypoint_2.s")

/* extern */

struct player_state_s;
struct anctrl_s;

void bsdronebubbled_entrypoint_3(struct player_state_s *arg0) {
    void anctrl_setDuration(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    f32 func_800D8FF8(void);
    f32 func_800F1214(f32, f32, f32);
    s32 func_800F1574(f32 *, f32);
    f32 sp24;
    s32 pad;
    struct anctrl_s *sp1C;

    sp24 = (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (0x44)));
    func_800F1574((f32 *)(*(u8 **)((s8 *)arg0 + 0x54) + 0x40), func_800D8FF8() * 0.8333333f);
    sp1C = baanim_getAnimCtrlPtr(arg0); anctrl_setDuration(sp1C, func_800F1214((*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (0x40))), sp24, sp24 * 0.33333334f));
}

void bsdronebubbled_entrypoint_4(s32 arg0) 
{
}
/* extern */

void bsdronebubbled_entrypoint_5(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, f32);
    void _badata_entrypoint_0(s32, s32 *, f32 *);
    void func_8009FFD8(s32, s32, s32, s32, s32);
    f32 sp24;
    s32 sp20;

    _badata_entrypoint_0(arg0, &sp20, &sp24);
    sp24 = sp24 + sp24;
    baanim_playForDuration_loopSmooth(arg0, sp20, sp24);
    func_8009FFD8(arg0, 1, 1, 3, 7);
}

void bsdronebubbled_entrypoint_6()
{
    func_80099B94();
}

void bsdronebubbled_entrypoint_7(void *arg0)
{
}
