#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_80800000_chjadesnake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_80800048_chjadesnake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_8080009C_chjadesnake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_80800150_chjadesnake.s")

void func_80800728_chjadesnake(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor*, s32);
    if (arg1 != 0xF3C) {
        if (arg1 == 0xF3D) {
            func_80102424(arg0, 8);
        }
    } else {
        func_80102424(arg0, 6);
    }
}

void func_80800770_chjadesnake(Actor *arg0, u8 *arg1) {
    s32 func_800DBEFC(s32, s32, s32);
    void func_80101870(Actor* arg0, void* arg1);
    OSThread * func_80104130(void);
    func_80101870(arg0, arg1);
    if (((struct { u32 unused : 19; u32 active : 1; u32 rest : 12; } *)((u8 *)arg0 + 0x7C))->active) {
        func_800DBEFC(func_80104130(), 4, (s32) arg0->actorData);
        func_800DBEFC(func_80104130(), 5, (s32) &arg0->actorData[4]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_808007DC_chjadesnake.s")

OSThread *chjadesnake_entrypoint_0(void)
{
    extern u8 D_808009F4_chjadesnake[];

    return (OSThread *) D_808009F4_chjadesnake;
}
