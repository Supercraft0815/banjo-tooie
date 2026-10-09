#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80800000_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80800060_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80800314_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_8080094C_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80801114_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_808011E4_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_808015D8_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80801654_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80801718_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_808018B8_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80801974_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80802730_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80802950_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_8080298C_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80802C18_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80802C94_chfantasyathlete.s")

/* extern */

void func_80802D38_chfantasyathlete(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80802D74_chfantasyathlete.s")

/* extern */

void func_80802DA8_chfantasyathlete(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_80800314_chfantasyathlete(s32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800314_chfantasyathlete(arg0);
    }
}

OSThread *chfantasyathlete_entrypoint_0(void)
{
    extern u8 D_808031B4_chfantasyathlete[];

    return (OSThread *) D_808031B4_chfantasyathlete;
}
