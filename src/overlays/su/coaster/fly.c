#include "su/coasterfly.h"

OSThread *sucoasterfly_entrypoint_0(void)
{
    extern u8 D_80802280_sucoasterfly[];

    return (OSThread *) D_80802280_sucoasterfly;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/sucoasterfly_entrypoint_1.s")

void sucoasterfly_entrypoint_2(Actor* arg0)
{
    func_80802128_sucoasterfly(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/sucoasterfly_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/sucoasterfly_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80800EF0_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80800F44_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80800FA8_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801108_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_808014AC_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_8080181C_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_808018BC_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_808019A0_sucoasterfly.s")

/* extern */

void func_80801A80_sucoasterfly(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F5BF0(s32, s32);
    func_800F5BF0(func_800F54E4(), arg0 + 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801AB0_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801B90_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801C44_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801CD0_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801DD0_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801E5C_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801FE4_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80802080_sucoasterfly.s")

void func_80802128_sucoasterfly(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_8080215C_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/sucoasterfly_entrypoint_5.s")

void sucoasterfly_entrypoint_6()
{
    func_80101870();
}

