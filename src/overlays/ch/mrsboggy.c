#include "ch/mrsboggy.h"

OSThread *chmrsboggy_entrypoint_0(void)
{
    extern u8 D_80800AD8_chmrsboggy[];

    return (OSThread *) D_80800AD8_chmrsboggy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_8080000C_chmrsboggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_80800088_chmrsboggy.s")

void func_80800290_chmrsboggy(Actor* arg0)
{
    func_80800548_chmrsboggy(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_808002B0_chmrsboggy.s")

/* extern */

void func_808004F4_chmrsboggy(s32 arg0) {
    s32 _suexpression_entrypoint_12(s32, s32, s32);
    s32 _suexpression_entrypoint_17(s32, s32);
    s32 _suexpression_entrypoint_20();
    s32 _suexpression_entrypoint_7(s32, s32, s32);
    s32 sp1C;
    s32 temp_v0;

    if (_suexpression_entrypoint_20() == 0) {
        temp_v0 = _suexpression_entrypoint_7(arg0, 1, 0x3E);
        sp1C = temp_v0;
        _suexpression_entrypoint_12(temp_v0, 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(sp1C, 0x3E8);
    }
}

void func_80800548_chmrsboggy(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_80800568_chmrsboggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_808005D8_chmrsboggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_8080070C_chmrsboggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_80800738_chmrsboggy.s")

/* extern */

void func_80800790_chmrsboggy(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x28))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_808007CC_chmrsboggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_80800878_chmrsboggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_80800910_chmrsboggy.s")

/* extern */

void func_80800990_chmrsboggy(void) {
    s32 func_800DA980(s32, s32);
    func_800DA980(0x8C, 3);
}
