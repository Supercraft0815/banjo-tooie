#include "common.h"

void func_80800000_bsdronevanish(void *arg0, s32 arg1) {
    void _batimer_set(struct player_state_s *, s32, f32);
    void func_80093370(void *, s32);
    void func_800FC618(s32, s32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);

    switch (arg1) {
        case 1:
            _batimer_set(arg0, 0, 0.3f);
            break;
        case 2:
            func_800FC618(0x1C, -1);
            func_800FCA90(0x1C);
            _batimer_set(arg0, 0, 0.4f);
            break;
        case 3:
            func_80093370(arg0, 0);
            func_800FCAE0(0x1C, 0, 0x7D0);
            _batimer_set(arg0, 0, 2.0f);
            break;
    }
    *(s8 *)((s8 *)*(void **)((s8 *)arg0 + 0x188) + 0x18) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/vanish/func_808000CC_bsdronevanish.s")

void func_8080019C_bsdronevanish(s32 arg0, s32 arg1) {
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800578_bsdronevanish;
    func_800BABB8(arg0, NULL, NULL, 1.0f, &D_80800578_bsdronevanish);
    func_800BA3FC(arg0, arg1);
}

/* extern */

void func_808001E4_bsdronevanish(void *arg0) {
    s32 func_800B5450(s32);
    func_800B5450((*(s32 *)((s8 *)((*(s32 **)((s8 *)(arg0) + (0x188)))) + (4))));
    func_800B5450(*(*(s32 **)((s8 *)(arg0) + (0x188))));
}

/* extern */

void func_8080021C_bsdronevanish(void *arg0) {
    s32 func_800B53A4(s32);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x188)))) + (0x10))) = 0.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x188)))) + (8))) = 0.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x188)))) + (0xC))) = 1.0f;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x188)))) + (0))) = func_800B53A4(0x3C);
    func_8080019C_bsdronevanish((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x188)))) + (0))), 0x9E5);
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x188)))) + (4))) = func_800B53A4(0x3C);
    func_8080019C_bsdronevanish((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x188)))) + (4))), 0x9E2);
}

/* extern */

void func_808002A4_bsdronevanish(void *arg0) {
    f32 func_800D8FF8(void);
    s32 func_808000CC_bsdronevanish(void *);
    f32 delta;
    void *temp_v0;

    delta = func_800D8FF8();
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x188)));
    (*(f32 *)((s8 *)(temp_v0) + (0x10))) = (f32) ((*(f32 *)((s8 *)(temp_v0) + (0x10))) - delta);
    if ((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x188)))) + (0x10))) < 0.0f) {
        do {
            func_808000CC_bsdronevanish(arg0);
            temp_v0 = (*(void **)((s8 *)(arg0) + (0x188)));
            (*(f32 *)((s8 *)(temp_v0) + (8))) += 0.02f * (*(f32 *)((s8 *)(temp_v0) + (0xC)));
            temp_v0 = (*(void **)((s8 *)(arg0) + (0x188)));
            (*(f32 *)((s8 *)(temp_v0) + (0x10))) += 0.02f;
        } while ((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x188)))) + (0x10))) < 0.0f);
    }
}

/* extern */

void bsdronevanish_entrypoint_0(void *arg0) {
    s32 _badata_entrypoint_3(void *, s32 *, s32 *);
    void _bastatemem_entrypoint_0(void *, s32);
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    s32 func_800961AC(void *, s32);
    s32 func_8009FFD8(void *, s32, s32, s32, s32);
    void func_80800000_bsdronevanish(void *, s32);
    s32 sp2C;
    s32 sp28;

    _bastatemem_entrypoint_0(arg0, 0x1C);
    _badata_entrypoint_3(arg0, &sp28, &sp2C);
    baanim_playForDuration_loopSmooth(arg0, sp28, sp2C);
    func_8009FFD8(arg0, 1, 1, 3, 7);
    func_800961AC(arg0, 6);
    func_8080021C_bsdronevanish(arg0);
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x188)))) + (0x18))) = 0;
    func_80800000_bsdronevanish(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/vanish/bsdronevanish_entrypoint_1.s")

/* extern */

void bsdronevanish_entrypoint_2(void *arg0) {
    s32 _bastatemem_entrypoint_1(void *);
    s32 func_80092778(void *);
    s32 func_800961AC(void *, s32);
    func_808001E4_bsdronevanish(arg0);
    func_800961AC(arg0, 1);
    func_80092778(arg0);
    _bastatemem_entrypoint_1(arg0);
}
