#include "common.h"

OSThread *chtnthut_entrypoint_0(void)
{
    extern u8 D_80800220_chtnthut[];

    return (OSThread *) D_80800220_chtnthut;
}

void func_8080000C_chtnthut(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/hut/func_80800014_chtnthut.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/hut/func_808000B0_chtnthut.s")

void func_80800170_chtnthut(Actor *arg0) {
    void _chexploder_entrypoint_10(Actor *, s32 *);
    s32 _chexploder_entrypoint_12(s32, s32);
    void _chexploder_entrypoint_13(s32, u32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800DA544(GameFlag);
    Unk80132ED0 *func_80101080(void);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80800268_chtnthut;
    extern s32 D_808002D8_chtnthut;
    Actor *sp24;
    Actor *temp_v0;

    temp_v0 = func_80106790(func_80101080());
    sp24 = temp_v0;
    _chexploder_entrypoint_12(temp_v0, 0x3C);
    _chexploder_entrypoint_13(sp24, 4);
    _chexploder_entrypoint_10(sp24, &D_808002D8_chtnthut);
    func_800BABB8(0, arg0->position, (f32 *)sp24->actorData, arg0->scale, &D_80800268_chtnthut);
    func_80101FDC(arg0, 2);
    func_80103110(arg0, 1);
    func_800DA544(0x84);
}
