#include "ch/cauldronentrydoor.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cauldronentrydoor/func_80800000_chcauldronentrydoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cauldronentrydoor/func_808000C8_chcauldronentrydoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cauldronentrydoor/func_80800168_chcauldronentrydoor.s")

/* extern */

void func_808001FC_chcauldronentrydoor(void *arg0) {
    s32 func_800DA298(s32, void *);
    (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 0.0f;
    if (func_800DA298(0x436, arg0) != 0) {
        (*(f32 *)((s8 *)(arg0) + (0x1C))) = 360.0f;
    } else {
        (*(f32 *)((s8 *)(arg0) + (0x1C))) = 270.0f;
    }
    (*(f32 *)((s8 *)(arg0) + (0x20))) = 0.5f;
    (*(f32 *)((s8 *)(arg0) + (0x44))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x1C)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cauldronentrydoor/func_80800274_chcauldronentrydoor.s")

void func_80800370_chcauldronentrydoor(s32 arg0) 
{
}
void chcauldronentrydoor_entrypoint_0()
{
    func_800E1720();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cauldronentrydoor/func_80800398_chcauldronentrydoor.s")

OSThread *chcauldronentrydoor_entrypoint_1(void)
{
    extern u8 D_80800550_chcauldronentrydoor[];

    return (OSThread *) D_80800550_chcauldronentrydoor;
}

OSThread *chcauldronentrydoor_entrypoint_2(void)
{
    extern u8 D_80800598_chcauldronentrydoor[];

    return (OSThread *) D_80800598_chcauldronentrydoor;
}
