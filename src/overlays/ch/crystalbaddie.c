#include "common.h"

OSThread *chcrystalbaddie_entrypoint_0(void)
{
    extern u8 D_80800664_chcrystalbaddie[];

    return (OSThread *) D_80800664_chcrystalbaddie;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crystalbaddie/func_8080000C_chcrystalbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crystalbaddie/func_80800054_chcrystalbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crystalbaddie/func_808002E0_chcrystalbaddie.s")

void func_80800384_chcrystalbaddie(s32 arg0) 
{
}
/* extern */

void func_8080038C_chcrystalbaddie(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(3, 1);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crystalbaddie/func_808003C4_chcrystalbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crystalbaddie/func_80800424_chcrystalbaddie.s")

void func_808004B4_chcrystalbaddie(s32 arg0)
{
    func_80105230(arg0,0);
}

/* extern */

void func_808004D4_chcrystalbaddie(Actor *arg0, s32 *arg1) {
    void _subaddiejoy_entrypoint_10(void *, f32, f32);
    s32 _chexploder_entrypoint_4(void *, s32, s32);
    _subaddiejoy_entrypoint_10(arg0, 1.0f, 0.3f);
    _chexploder_entrypoint_4(arg0, *arg1 + 4, 4);
    (*(u8 *)((s8 *)(arg0) + 0x64)) = (u8)((*(u8 *)((s8 *)(arg0) + 0x64)) & 0xFFFE);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crystalbaddie/func_8080052C_chcrystalbaddie.s")
