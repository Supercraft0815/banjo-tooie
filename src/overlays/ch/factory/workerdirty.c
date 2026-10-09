#include "ch/factory/workerdirty.h"

OSThread *chfactoryworkerdirty_entrypoint_0(void)
{
    extern u8 D_80800EF8_chfactoryworkerdirty[];

    return (OSThread *) D_80800EF8_chfactoryworkerdirty;
}

void func_8080000C_chfactoryworkerdirty(Actor* arg0)
{
    func_80108B04(arg0,1);
}

/* extern */

void func_8080002C_chfactoryworkerdirty(Actor *arg0) {
    s32 func_8010114C(s32, s32, s32);
    s32 *sp1C;
    s32 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    func_8010114C(*temp_v0, 0x2C, 0);
    *sp1C = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800068_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_808000AC_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_8080025C_chfactoryworkerdirty.s")

void func_80800340_chfactoryworkerdirty(Actor* arg0)
{
    func_80100094(arg0,0);
    func_80800DB4_chfactoryworkerdirty(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_8080036C_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800394_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_8080061C_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800700_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800788_chfactoryworkerdirty.s")

/* extern */

s32 func_80800828_chfactoryworkerdirty(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80800A54_chfactoryworkerdirty();
    if (arg1 == 0x134E) {
        return func_80800A54_chfactoryworkerdirty();
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800864_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_808008A4_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800994_chfactoryworkerdirty.s")

void func_808009C0_chfactoryworkerdirty(void) {
    func_800DA564(FLAG_42D_PROGRESS_GI_SKIVVY_WASHED_OUTSIDE, 6);
}

s32 func_808009E4_chfactoryworkerdirty()
{
    return func_800DA298(FLAG_433_UNK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800A04_chfactoryworkerdirty.s")

/* extern */

s32 func_80800A14_chfactoryworkerdirty(s32 arg0) {
    s32 func_80800A04_chfactoryworkerdirty(s32);
    s32 sp1C;

    sp1C = func_800DA564(FLAG_42D_PROGRESS_GI_SKIVVY_WASHED_OUTSIDE, 6);
    return (func_80800A04_chfactoryworkerdirty(arg0) + 1) == sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800A54_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800AB4_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800AF8_chfactoryworkerdirty.s")

/* extern */

void func_80800B40_chfactoryworkerdirty(void) {
    s32 func_80800A04_chfactoryworkerdirty();
    func_800DA7A8(FLAG_42D_PROGRESS_GI_SKIVVY_WASHED_OUTSIDE, func_80800A04_chfactoryworkerdirty() + 1, 6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/chfactoryworkerdirty_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/chfactoryworkerdirty_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/chfactoryworkerdirty_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800C98_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800D48_chfactoryworkerdirty.s")

/* extern */

void func_80800DB4_chfactoryworkerdirty(Actor *arg0) {
    s32 _suexpression_entrypoint_8(Actor *, s32);
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
