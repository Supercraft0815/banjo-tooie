#include "common.h"

OSThread *chtntblockage_entrypoint_0(void)
{
    extern u8 D_80800240_chtntblockage[];

    return (OSThread *) D_80800240_chtntblockage;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/blockage/func_8080000C_chtntblockage.s")

void func_80800088_chtntblockage()
{
    _subaddiefade_entrypoint_14();
}

s32 func_808000A8_chtntblockage(s32 arg0) {
    return ((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) + 0x4C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/blockage/func_808000B8_chtntblockage.s")

void func_80800184_chtntblockage(Actor *arg0) {
    s32 _chexploder_entrypoint_12(s32, s32);
    void _chexploder_entrypoint_13(s32, u32);
    void _chexploder_entrypoint_15(s32, u32, f32);
    s32 _chexploder_entrypoint_6(s32, f32, f32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800DA544(GameFlag);
    Unk80132ED0 *func_80101080(void);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_8080029C_chtntblockage[];
    Actor *temp_v0;

    temp_v0 = func_80106790(func_80101080());
    _chexploder_entrypoint_12((s32)temp_v0, 0x32);
    _chexploder_entrypoint_6((s32)temp_v0, 1200.0f, 1400.0f);
    _chexploder_entrypoint_13((s32)temp_v0, 4);
    _chexploder_entrypoint_15((s32)temp_v0, 1, 1.2f);
    func_800BABB8(0, arg0->position, (f32 *)temp_v0->actorData, arg0->scale, D_8080029C_chtntblockage);
    func_800DA544(func_808000A8_chtntblockage((s32)arg0));
    func_80101FDC(arg0, 2);
    func_80103110(arg0, 1);
}
