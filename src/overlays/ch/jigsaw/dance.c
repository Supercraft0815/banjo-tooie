#include "common.h"

/* extern */

void func_80800000_chjigsawdance(Actor *arg0) {
    s32 func_800C8A98();
    void func_800C8CB8(s32, f32[3]);
    s32 func_800CF9E4(s32, s32, s32);
    s32 func_800CFA70(s32, s32);
    if (func_800CFA70((s32)arg0->unk50, 1) != -1) {
        arg0->unk6C_0 = func_800C8A98();
        func_800CF9E4((s32)arg0->unk50, 1, arg0->unk6C_0);
        func_800C8CB8(arg0->unk6C_0, arg0->position);
        return;
    }
    arg0->unk6C_0 = 0;
}

void func_808000AC_chjigsawdance(Actor *arg0) {
    void func_800C8B84(s32);
    if (arg0->unk6C_0 != 0) {
        func_800C8B84(arg0->unk6C_0);
        arg0->unk6C_0 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/dance/func_808000F0_chjigsawdance.s")

void chjigsawdance_entrypoint_0(void *arg0, s32 arg1) {
    (*(f32 *)((s8 *)(arg0) + (0x50))) = (f32) arg1;
}

void chjigsawdance_entrypoint_1(Actor *arg0, s32 arg1) {
    struct anctrl_s;
    f32 anctrl_getAnimTimer(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *func_8008FD20(void);
    f32 func_80090010(void);
    void func_800C8B84(s32);
    void func_800FFA88(Unk80132ED0 *);
    void func_80101FDC(Actor *, u32);
    struct anctrl_s *func_80104248(void *);
    void func_8010D254(f32 *);
    struct anctrl_s *control;

    switch (arg1) {
    case 3:
        if (arg0->unk70_10 == 1) {
            func_80101FDC(arg0, 2);
            anctrl_setPlaybackType(func_80104248(arg0), 1);
        }
        break;
    case 2:
        func_80101FDC(arg0, 3);
        break;
    case 1:
        func_80101FDC(arg0, 4);
        break;
    case 4:
        func_8010D254(arg0->position);
        arg0->rotation[1] = func_80090010();
        control = func_80104248(arg0);
        anctrl_setSmoothTransition(control, 0);
        anctrl_setStart(control, anctrl_getAnimTimer(func_8008FD20()));
        anctrl_setDuration(control, 1000.0f);
        anctrl_start(control);
        break;
    case 5:
        if (arg0->unk6C_0 != 0) {
            func_800C8B84(arg0->unk6C_0);
            arg0->unk6C_0 = 0;
        }
        func_800FFA88(arg0->unk0);
        break;
    }
}

OSThread *chjigsawdance_entrypoint_2(void)
{
    extern u8 D_80800488_chjigsawdance[];

    return (OSThread *) D_80800488_chjigsawdance;
}
