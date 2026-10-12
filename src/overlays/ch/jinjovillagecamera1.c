#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjovillagecamera1/func_80800000_chjinjovillagecamera1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjovillagecamera1/func_80800078_chjinjovillagecamera1.s")

void func_808002BC_chjinjovillagecamera1(s32 arg0) {
    s32 _chjinjo_entrypoint_2(s32);
    void func_800BF744(s32, s32);
    extern u8 D_80800488_chjinjovillagecamera1;
    s32 temp_v0;

    temp_v0 = _chjinjo_entrypoint_2(-1);
    if (temp_v0 != -1) {
        func_800BF744(9U, 0);
        func_800BF744(*((u8 *) &D_80800488_chjinjovillagecamera1 + temp_v0), 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjovillagecamera1/func_80800310_chjinjovillagecamera1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjovillagecamera1/func_808003C0_chjinjovillagecamera1.s")

OSThread *chjinjovillagecamera1_entrypoint_0(void)
{
    extern u8 D_80800494_chjinjovillagecamera1[];

    return (OSThread *) D_80800494_chjinjovillagecamera1;
}
