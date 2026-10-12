#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800000_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800224_chfactorymagnet.s")

/* extern */

void func_8080083C_chfactorymagnet(s32 arg0) {
    s32 _subaddiefind_entrypoint_2(s32, s32);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 func_800F4EC8(s32, s32 *, f32, f32, f32);
    s32 func_800F54E4();
    s32 sp24[3];

    func_800EE7F8(sp24, _subaddiefind_entrypoint_2(0x3FC, 0) + 4);
    func_800F4EC8(func_800F54E4(), sp24, 500.0f, 0.0f, 200.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800898_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800B20_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800E40_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800EF0_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800FE8_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_808012E4_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80801368_chfactorymagnet.s")

/* extern */

void chfactorymagnet_entrypoint_0(s32 arg0, s32 arg1) {
    s32 _chmrtannoy_entrypoint_0();
    s32 func_800C05B8(s32, s32, s32, s32, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800EA05C();
    func_800DA524(0xA06);
    if (func_800EA05C() != 0x107) {
        func_800DA524(0x9DE);
    }
    if (func_800DA298(0x1B8) == 0) {
        _chmrtannoy_entrypoint_0();
        func_800C05B8(0x1338, 4, 0, 0, 0, 0, 0xA3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80801460_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80801508_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_808016A4_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_808019F4_chfactorymagnet.s")

void func_80801A9C_chfactorymagnet(s32 arg0, f32 *arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    extern f32 D_8080298C_chfactorymagnet;
    extern f32 D_80802998_chfactorymagnet;
    if (arg1 != NULL) {
        func_800EE7F8(arg1, &D_8080298C_chfactorymagnet);
    }
    if (arg2 != NULL) {
        func_800EE7F8(arg2, &D_80802998_chfactorymagnet);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80801AE8_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80801B74_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80801CD8_chfactorymagnet.s")

void func_80801E84_chfactorymagnet(u8 *arg0) {
    s32 _sumumbofx_entrypoint_1(void *, s32);
    if ((*(s16 *)((s8 *)(arg0) + (0x82))) != 0) {
        _sumumbofx_entrypoint_1(arg0, 0);
    }
}

OSThread *chfactorymagnet_entrypoint_1(void)
{
    extern u8 D_80802A04_chfactorymagnet[];

    return (OSThread *) D_80802A04_chfactorymagnet;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80801EBC_chfactorymagnet.s")

OSThread *chfactorymagnet_entrypoint_2(void)
{
    extern u8 D_80802A4C_chfactorymagnet[];

    return (OSThread *) D_80802A4C_chfactorymagnet;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80801FB8_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_808022D8_chfactorymagnet.s")

OSThread *chfactorymagnet_entrypoint_3(void)
{
    extern u8 D_80802AB4_chfactorymagnet[];

    return (OSThread *) D_80802AB4_chfactorymagnet;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80802390_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_808025B4_chfactorymagnet.s")

void func_8080281C_chfactorymagnet(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x24)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
    }
}

OSThread *chfactorymagnet_entrypoint_4(void)
{
    extern u8 D_80802B68_chfactorymagnet[];

    return (OSThread *) D_80802B68_chfactorymagnet;
}
