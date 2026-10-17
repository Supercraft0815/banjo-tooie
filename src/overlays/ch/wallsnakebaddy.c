#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wallsnakebaddy/func_80800000_chwallsnakebaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wallsnakebaddy/func_8080027C_chwallsnakebaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wallsnakebaddy/func_808004FC_chwallsnakebaddy.s")

s32 func_808005D8_chwallsnakebaddy(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_808004FC_chwallsnakebaddy(Actor *, s32);
    void func_800EEB9C(f32[3], f32, f32);
    void func_80101010(f32 *);
    f32 sp1C[3];
    switch (arg1) {
        case 0x40:
            func_808004FC_chwallsnakebaddy(arg0, arg2);
            break;
        case 0x97:
            func_800EEB9C(sp1C, arg0->rotation[1], 150.0f);
            func_80101010(sp1C);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800650_chwallsnakebaddy()
{
    func_80105010();
}

OSThread *chwallsnakebaddy_entrypoint_0(void)
{
    extern u8 D_808007B4_chwallsnakebaddy[];

    return (OSThread *) D_808007B4_chwallsnakebaddy;
}
