#include "common.h"

OSThread *chhoneyb_entrypoint_0(void)
{
    extern u8 D_80801020_chhoneyb[];

    return (OSThread *) D_80801020_chhoneyb;
}

OSThread *chhoneyb_entrypoint_1(void)
{
    extern u8 D_80801068_chhoneyb[];

    return (OSThread *) D_80801068_chhoneyb;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800018_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800058_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_8080011C_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800194_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800240_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_808002AC_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_8080062C_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800680_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800744_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800920_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800968_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800B2C_chhoneyb.s")

void func_80800B58_chhoneyb()
{
    func_800D1A04(0x49);
}

void func_80800B78_chhoneyb()
{
    _gcextra_entrypoint_0();
}

/* extern */

s32 func_80800B98_chhoneyb(s32 arg0) {
    s32 _gcextra_entrypoint_1();
    if ((arg0 <= 0) || (_gcextra_entrypoint_1() < arg0)) {
        return -1;
    }
    return (arg0 * 2) - 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800BD8_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800C0C_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800C34_chhoneyb.s")

void func_80800C58_chhoneyb()
{
    func_8010C964();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800C78_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/chhoneyb_entrypoint_2.s")
