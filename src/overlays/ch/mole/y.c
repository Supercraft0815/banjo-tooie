#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_80800000_chmoley.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_808000AC_chmoley.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_80800190_chmoley.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_80800274_chmoley.s")

void func_8080088C_chmoley(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_808008C0_chmoley(Actor *arg0) { void _suexpression_entrypoint_12(void *, f32, f32); f32 zero = 0.0f; arg0->scale = 0.5f; _suexpression_entrypoint_7(arg0, 1, 0x6F); _suexpression_entrypoint_12(func_80100094(arg0, 1), zero, zero); }

void chmoley_entrypoint_0(void *arg0, s32 arg1) {
    struct Fields {
        u8 pad[0x79];
        u8 upper : 4;
        u8 lower : 4;
    };
    ((struct Fields *)arg0)->upper = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/chmoley_entrypoint_1.s")

OSThread *chmoley_entrypoint_2(void)
{
    extern u8 D_80800C10_chmoley[];

    return (OSThread *) D_80800C10_chmoley;
}
