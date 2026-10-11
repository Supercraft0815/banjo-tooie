#include "common.h"

OSThread *chstarspinnerstar_entrypoint_0(void)
{
    extern u8 D_808006B0_chstarspinnerstar[];

    return (OSThread *) D_808006B0_chstarspinnerstar;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/star/func_8080000C_chstarspinnerstar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/star/func_80800320_chstarspinnerstar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/star/func_808003F8_chstarspinnerstar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/star/func_80800454_chstarspinnerstar.s")

/* extern */

void func_808005F8_chstarspinnerstar(void **arg0, s32 arg1) {
    s32 _glcutDll_entrypoint_20();
    u8 func_800D731C(u16);
    s32 func_800DA298(s32);
    s32 func_800DBE60(u8, s32, s32);
    s32 func_801015D0();
    u8 sp1F;
    u8 temp_v0;

    func_801015D0();
    temp_v0 = func_800D731C((*(u16 *)((s8 *)(*arg0) + (0x14))));
    sp1F = temp_v0;
    if ((temp_v0 != 0) && (func_800DA298(0xEA) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800DBE60(sp1F, 0, 0);
    }
}

f32 *func_80800660_chstarspinnerstar(s32 arg0) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    extern f32 B_80800710_chstarspinnerstar;
    f32 *position;
    func_800EE7F8(&B_80800710_chstarspinnerstar, arg0 + 4);
    position = &B_80800710_chstarspinnerstar;
    position[1] = position[1];
    return position;
}
