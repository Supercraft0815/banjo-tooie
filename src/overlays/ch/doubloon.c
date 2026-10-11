#include "ch/doubloon.h"

void func_80800000_chdoubloon(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x44))) = 0.0f;
}

/* extern */

void func_8080000C_chdoubloon(s32 arg0) {
    s32 func_80103110(s32, s32);
    s32 chdoubloon_entrypoint_1();
    chdoubloon_entrypoint_1();
    func_80103110(arg0, 0);
}

void chdoubloon_entrypoint_0(Actor *arg0, u8 *arg1) {
    struct Flags { u32 pad : 19; u32 active : 1; u32 rest : 12; };
    void func_80101870(Actor* arg0, void* arg1);
    s32 func_80103110(s32, s32);
    func_80101870(arg0, arg1);
    if (((struct Flags *)((s8 *)arg0 + 0x7C))->active) {
        func_80103110((s32) arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doubloon/chdoubloon_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doubloon/func_808001D4_chdoubloon.s")

OSThread *chdoubloon_entrypoint_2(void)
{
    extern u8 D_808002A0_chdoubloon[];

    return (OSThread *) D_808002A0_chdoubloon;
}
