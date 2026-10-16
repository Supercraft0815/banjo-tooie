#include "common.h"

OSThread *chdiggergroundgen_entrypoint_0(void)
{
    extern u8 D_80800500_chdiggergroundgen[];

    return (OSThread *) D_80800500_chdiggergroundgen;
}

/* extern */

void func_8080000C_chdiggergroundgen(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _subaddielink_entrypoint_0(u8 *);
    _subaddielink_entrypoint_0(func_80100094(arg0, 0U));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/groundgen/func_80800034_chdiggergroundgen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/groundgen/func_808000AC_chdiggergroundgen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/groundgen/func_80800118_chdiggergroundgen.s")

void func_808002C4_chdiggergroundgen(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    f32 func_800DC178(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102FDC(void *, f32);
    Actor *func_801084B0(s32, Actor **);
    extern u8 D_80800548_chdiggergroundgen[];
    f32 *sp1C;
    Actor *sp18;

    sp1C = func_80100094(arg0, 0);
    sp18 = func_801084B0(0x131, &arg0);
    func_80102FDC(sp18, func_800DC178(0.8f, 1.2f));
    sp18->rotation[1] = func_800F1DF4(arg0->position, &sp1C[2]);
    _subaddielink_entrypoint_1(sp1C, sp18->unk0);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800548_chdiggergroundgen);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/groundgen/func_8080035C_chdiggergroundgen.s")
