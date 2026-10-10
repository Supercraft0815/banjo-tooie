#include "common.h"

OSThread *chbouncycastle_entrypoint_0(void)
{
    extern u8 D_80800930_chbouncycastle[];

    return (OSThread *) D_80800930_chbouncycastle;
}

OSThread *chbouncycastle_entrypoint_1(void)
{
    extern u8 D_80800978_chbouncycastle[];

    return (OSThread *) D_80800978_chbouncycastle;
}

OSThread *chbouncycastle_entrypoint_2(void)
{
    extern u8 D_808009C0_chbouncycastle[];

    return (OSThread *) D_808009C0_chbouncycastle;
}

OSThread *chbouncycastle_entrypoint_3(void)
{
    extern u8 D_80800A08_chbouncycastle[];

    return (OSThread *) D_80800A08_chbouncycastle;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/chbouncycastle_entrypoint_4.s")

/* extern */

void func_80800148_chbouncycastle(void **arg0) {
    s32 _glidmake_entrypoint_4(s32);
    s32 _glidmake_entrypoint_5(u16, s32);
    s32 func_8010647C(void **, s32);
    s32 func_801065A4();
    s32 temp_v0;

    temp_v0 = func_801065A4();
    if (temp_v0 != 0) {
        _glidmake_entrypoint_4(temp_v0);
    }
    func_8010647C(arg0, _glidmake_entrypoint_5((*(u16 *)((s8 *)(*arg0) + (0x14))), 0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_80800198_chbouncycastle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_80800254_chbouncycastle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_80800308_chbouncycastle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_8080045C_chbouncycastle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_8080051C_chbouncycastle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_80800670_chbouncycastle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_808006C4_chbouncycastle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_80800774_chbouncycastle.s")

void func_80800828_chbouncycastle(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_80800830_chbouncycastle.s")
