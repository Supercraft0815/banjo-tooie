#include "ch/conga.h"

OSThread *chconga_entrypoint_0(void)
{
    extern u8 D_808006A0_chconga[];

    return (OSThread *) D_808006A0_chconga;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_8080000C_chconga.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_80800118_chconga.s")

void func_80800280_chconga(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_808002A0_chconga.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_80800374_chconga.s")

s32 func_80800478_chconga(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800D1A04(s32 a0);
    if ((arg1 == 0x10B0) || (arg1 == 0x10B1)) {
        return func_800D1A04(0x4D);
    }
    return 0;
}

/* extern */

s32 func_808004BC_chconga(s32 arg0, s32 arg1) {
    int func_800C6E38(s32);
    s32 var_v1;

    if ((func_800C6E38(0x1B) != 0) && (func_800C6E38(0x2D) != 0)) {
        var_v1 = arg1;
    } else if (func_800C6E38(0x1B) != 0) {
        var_v1 = 0x1112;
    } else if (func_800C6E38(0x2D) != 0) {
        var_v1 = 0x10FF;
    } else {
        var_v1 = 0x1113;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_80800538_chconga.s")

void func_80800618_chconga(Actor *arg0) {
    extern u32 D_80800714_chconga;
    extern u32 D_80800724_chconga;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80800714_chconga, &D_80800724_chconga);
}
