#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/suckunder/func_80800000_bsdronesuckunder.s")

void bsdronesuckunder_entrypoint_0(s32 arg0)
{
    func_800961A0(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/suckunder/bsdronesuckunder_entrypoint_1.s")

/* extern */

void bsdronesuckunder_entrypoint_2(s32 arg0) {
    s32 func_80099AA8(s32);
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    if ((temp_v0 == 0x26) || (temp_v0 == 0x51) || (temp_v0 == 0x52) || (temp_v0 == 0x6A)) {
        func_80099B94(arg0);
        return;
    }
    func_80099AA8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/suckunder/bsdronesuckunder_entrypoint_3.s")
