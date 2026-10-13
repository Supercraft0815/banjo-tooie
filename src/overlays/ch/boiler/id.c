#include "common.h"

OSThread *chboilerid_entrypoint_0(void)
{
    extern u8 D_80800D5C_chboilerid[];

    return (OSThread *) D_80800D5C_chboilerid;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_8080000C_chboilerid.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_80800128_chboilerid.s")

/* extern */
s32 func_808003AC_chboilerid(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 _subaddielink_entrypoint_3(u8 *);
    if (arg1 == 0x95) {
        _subaddielink_entrypoint_3((u8 *)func_80100094(arg0, 0U) + 0x60);
        return 1;
    }
    return 0;
}

/* extern */

void func_808003EC_chboilerid(s32 arg0) {
    s32 func_800CF494();
    s32 func_800DA524(s32);
    func_800DA524(0x66F);
    func_800CF494();
}

/* extern */

void func_80800418_chboilerid(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _mlwave_entrypoint_1(u8 *);
    _mlwave_entrypoint_1(func_80100094(arg0, 0U));
}

void func_80800440_chboilerid(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _mlwave_entrypoint_1(u8 *);
    _mlwave_entrypoint_1((u8 *)func_80100094(arg0, 0U) + 0x20);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_80800468_chboilerid.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_80800700_chboilerid.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_8080079C_chboilerid.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_8080084C_chboilerid.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_80800918_chboilerid.s")

void func_80800998_chboilerid(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_80800C48_chboilerid.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_80800CB0_chboilerid.s")
