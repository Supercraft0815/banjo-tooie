#include "core2/1EC3810.h"

extern u16 D_80132DC2;
extern s32 D_80132DC0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800E9F20.s")

// Get World Section
MapId func_800EA05C(void) 
{
	return D_80132DC2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA068.s")

s32 func_800EA090(void) {
    extern s16 D_80132DC8;

    return D_80132DC8;
}

s32 func_800EA09C(void) {
    return *(s16 *)((u8 *)&D_80132DC0 + 0);
}

void func_800EA0A8()
{
    _gsworldDll_entrypoint_1(&D_80132DC0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA0CC.s")

void func_800EA124()
{
    _gsworldDll_entrypoint_4(&D_80132DC0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA170.s")

void func_800EA334(s32 arg0) {
    extern s16 D_80132DCA;
    *(s16 *)((u8 *)&D_80132DCA + 0) = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA34C.s")

s32 func_800EA358(void) {
    extern s16 D_80132DCC;

    return D_80132DCC;
}

u32 func_800EA364(void) {
    extern u16 D_80132DCE;
    return *(u16 *)((u8 *)&D_80132DCE + 0);
}

void func_800EA370()
{
    func_800EA3A0();
}

void func_800EA390(void) {
}

void func_800EA398(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA45C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EAA2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EADFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EB15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EB210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EB2DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EB350.s")
