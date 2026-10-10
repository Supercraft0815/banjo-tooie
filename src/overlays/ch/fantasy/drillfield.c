#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/drillfield/func_80800000_chfantasydrillfield.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/drillfield/func_808000C4_chfantasydrillfield.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/drillfield/func_80800360_chfantasydrillfield.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/drillfield/func_808003C8_chfantasydrillfield.s")

/* extern */

void func_8080048C_chfantasydrillfield(void *arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_80800000_chfantasydrillfield();
    s32 func_808000C4_chfantasydrillfield(void *);
    s32 func_808003C8_chfantasydrillfield(u32);
    func_80800000_chfantasydrillfield();
    if (func_800DA298(0xA0F) == 0) {
        func_800DA544(0xA0F);
        func_808000C4_chfantasydrillfield(arg0);
    }
    (*(s32 *)((s8 *)(arg0) + (0x34))) = func_808003C8_chfantasydrillfield((u32) (*(u32 *)((s8 *)(arg0) + (0x6C))) >> 0x15);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/drillfield/func_808004E8_chfantasydrillfield.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/drillfield/func_8080054C_chfantasydrillfield.s")

OSThread *chfantasydrillfield_entrypoint_0(void)
{
    extern u8 D_808009C4_chfantasydrillfield[];

    return (OSThread *) D_808009C4_chfantasydrillfield;
}
