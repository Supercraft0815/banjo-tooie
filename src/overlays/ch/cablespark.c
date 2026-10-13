#include "common.h"

OSThread *chcablespark_entrypoint_0(void)
{
    extern u8 D_80800B88_chcablespark[];

    return (OSThread *) D_80800B88_chcablespark;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_8080000C_chcablespark.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_8080024C_chcablespark.s")

/* extern */

void func_808002BC_chcablespark(void *arg0) {
    s32 func_800E87E0(s32, u8);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x18)));
    if (temp_a1 != 0) {
        func_800E87E0(temp_a1 & 0xFF, temp_a1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_808002E8_chcablespark.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_8080040C_chcablespark.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_80800590_chcablespark.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_80800668_chcablespark.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_808007B8_chcablespark.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_80800828_chcablespark.s")

/* extern */

void func_808008BC_chcablespark(void *arg0) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80103014(u8 *);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_800EE7F8(sp3C, ((Actor *)arg0)->position);
    func_800EF1B8(sp3C, ((Actor *)arg0)->rotation[1], 100.0f);
    func_800EE7F8(sp30, ((Actor *)arg0)->position);
    func_800EF1B8(sp30, ((Actor *)arg0)->rotation[1], -50.0f);
    if (func_800BEF00(sp3C, sp30, sp24, ((Actor *)arg0)->unk14) != 0) {
        func_800EE7F8(((Actor *)arg0)->position, sp30);
        func_800EF1B8(((Actor *)arg0)->position, ((Actor *)arg0)->rotation[1], ((Actor *)arg0)->scale * 5.0f);
        func_80103014(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_80800970_chcablespark.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_80800A48_chcablespark.s")
