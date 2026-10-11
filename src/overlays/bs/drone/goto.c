#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/func_80800000_bsdronegoto.s")

/* extern */

s32 func_8080009C_bsdronegoto(void) {
    s32 func_800A3274();
    return func_800A3274() != 0x12;
}

void func_808000C0_bsdronegoto()
{
    func_8009B7C0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/func_808000E0_bsdronegoto.s")

void func_80800148_bsdronegoto(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/func_80800150_bsdronegoto.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/func_8080026C_bsdronegoto.s")

/* extern */

void func_8080032C_bsdronegoto(void *arg0) {
    s32 func_800961A0(s32 *, s32);
    func_800961A0(arg0, (*(s32 *)((s8 *)(arg0) + (0x198))));
}

/* extern */

void bsdronegoto_entrypoint_0(void *arg0) {
    s32 _badata_entrypoint_14(void *);
    s32 _gcgoto_entrypoint_14(s32);
    s32 func_80091E48(void *, s32);
    s32 func_80800000_bsdronegoto(void *, s32);
    int player_isStable(void *);
    (*(s32 *)((s8 *)(arg0) + (0x190))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x194))) = 0;
    _gcgoto_entrypoint_14(1);
    func_80091E48(arg0, 0x3F);
    if ((player_isStable(arg0) == 0) && (_badata_entrypoint_14(arg0) != 0)) {
        func_80800000_bsdronegoto(arg0, 1);
        return;
    }
    func_80800000_bsdronegoto(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/bsdronegoto_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/bsdronegoto_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/goto/bsdronegoto_entrypoint_3.s")
