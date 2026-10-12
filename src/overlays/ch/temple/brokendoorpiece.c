#include "common.h"

void func_80800000_chtemplebrokendoorpiece(s32 arg0) 
{
}
void func_80800008_chtemplebrokendoorpiece(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800DA544(GameFlag);
    extern s32 D_80800100_chtemplebrokendoorpiece;
    extern s32 D_80800114_chtemplebrokendoorpiece;
    func_800BABB8(0, arg0->position, arg0->position, arg0->scale, &D_80800114_chtemplebrokendoorpiece);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800100_chtemplebrokendoorpiece);
    func_800DA544(0xC9);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/temple/brokendoorpiece/func_80800068_chtemplebrokendoorpiece.s")

OSThread *chtemplebrokendoorpiece_entrypoint_0(void)
{
    extern u8 D_8080015C_chtemplebrokendoorpiece[];

    return (OSThread *) D_8080015C_chtemplebrokendoorpiece;
}
