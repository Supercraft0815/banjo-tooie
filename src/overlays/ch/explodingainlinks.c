#include "common.h"

OSThread *chexplodingchainlinks_entrypoint_0(void)
{
    extern u8 D_80800170_chexplodingchainlinks[];

    return (OSThread *) D_80800170_chexplodingchainlinks;
}

void func_8080000C_chexplodingchainlinks(s32 arg0) 
{
}
void func_80800014_chexplodingchainlinks(s32 arg0)
{
    _subaddieDll_entrypoint_7(arg0,0xB);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/explodingainlinks/func_80800034_chexplodingchainlinks.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/explodingainlinks/func_80800070_chexplodingchainlinks.s")

void func_8080010C_chexplodingchainlinks(s32 arg0, Actor *arg1) {
    void func_800BBCB8(f32[3], f32[3], f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_808001B8_chexplodingchainlinks;
    f32 sp24[3];

    func_800EE7F8(sp24, (f32 *)(arg0 + 4));
    sp24[1] = arg1->position[0];
    func_800BBCB8(sp24, sp24, 0.8f, 4, &D_808001B8_chexplodingchainlinks);
}
