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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/dance/chjigsawdance_entrypoint_1.s")

OSThread *chjigsawdance_entrypoint_2(void)
{
    extern u8 D_80800488_chjigsawdance[];

    return (OSThread *) D_80800488_chjigsawdance;
}
