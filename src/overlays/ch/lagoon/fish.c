#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_80800000_chlagoonfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_808001A0_chlagoonfish.s")

void func_80800240_chlagoonfish(Actor *arg0) { func_80100074(arg0, 0U, 0U); }

void func_80800264_chlagoonfish(Actor *arg0)
{
    func_80800240_chlagoonfish(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_80800284_chlagoonfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_808002F8_chlagoonfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_8080038C_chlagoonfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_80800908_chlagoonfish.s")

/* extern */

void func_808009FC_chlagoonfish(u8 *arg0) {
    s32 func_800CC63C(s32, s32);
    s32 func_800EE7F8(u8 *, s32);
    u32 temp_v0;

    temp_v0 = (*(u32 *)((s8 *)(arg0) + (0x70)));
    func_800EE7F8(arg0 + 0x18, func_800CC63C((temp_v0 >> 0x19) - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_80800A44_chlagoonfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_80800AE0_chlagoonfish.s")

OSThread *chlagoonfish_entrypoint_0(void)
{
    extern u8 D_80800B70_chlagoonfish[];

    return (OSThread *) D_80800B70_chlagoonfish;
}
