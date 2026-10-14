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

void func_80800EF0_sucoasterfly(Unk80132ED0 *arg0, u8 *arg1)
{
  Actor *func_80106790(Unk80132ED0 *);
  s32 func_808014AC_sucoasterfly(Actor *, s32);
  Actor *temp_a0;
  Actor *temp_v0;
  temp_v0 = func_80106790(arg0);
  temp_a0 = temp_v0;
  if (((((u32) ((*((u32 *) (((s8 *) arg1) + 0x24))) ^ 0)) >> 0x16) == 0) && (((((u16) (*((u16 *) (((s8 *) temp_v0) + 0x72)))) & 0xFFFFFFFF) >> 0xA) == 6))
  {
    func_808014AC_sucoasterfly(temp_a0, 7);
  }
}

/* extern */

void func_80800F44_sucoasterfly(Unk80132ED0 *arg0, s32 arg1) {
    int func_801021BC(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    Actor *temp_v0;
    Actor *sp1C;
    u32 flags;

    temp_v0 = func_80106790(arg0);
    if (temp_v0->unk70_10 != 0xA) {
        flags = temp_v0->pad7A_0;
        if (((s32)(flags << 29) >> 31) == 0) {
        sp1C = temp_v0;
        if (func_801021BC(temp_v0, 0xA) != 0) {
            func_808014AC_sucoasterfly(sp1C, 0xA);
        }
        }
    }
}

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
void func_8080215C_sucoasterfly(Actor *arg0) {
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_18(func_80100094(arg0, 1U), 1);
    }
}

u8 *sucoasterfly_entrypoint_5(Actor *arg0) {
    return (u8 *)func_80100094(arg0, 0U) + 0x1C;
}

void sucoasterfly_entrypoint_6()
{
    func_80101870();
}
