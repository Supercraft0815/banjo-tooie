#include "common.h"

void func_80800000_chlavacolumns(u8 *arg0) {
    s32 func_80800200_chlavacolumns(s32, s32);
    void func_800EFD24(f32 *);
    void func_80103014(u8 *);
    func_80800200_chlavacolumns((s32)arg0, (s32)0xC3C80000);
    func_800EFD24(arg0 + 4);
    (*(f32 *)(arg0 + 8)) = -400.0f;
    func_80103014(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/columns/func_80800044_chlavacolumns.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/columns/func_8080014C_chlavacolumns.s")

/* extern */

s32 func_80800200_chlavacolumns(s32 arg0, s32 arg1) {
    s32 _idworld_entrypoint_3(s32);
    s32 func_800EDCB8(s32, s32);
    s32 temp_v0;

    temp_v0 = _idworld_entrypoint_3(0x190);
    if (temp_v0 != 0) {
        func_800EDCB8(temp_v0, arg1);
        return 1;
    }
    return 0;
}

OSThread *chlavacolumns_entrypoint_0(void)
{
    extern u8 D_80800260_chlavacolumns[];

    return (OSThread *) D_80800260_chlavacolumns;
}
