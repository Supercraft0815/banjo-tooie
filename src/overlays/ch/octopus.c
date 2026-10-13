#include "common.h"

OSThread *choctopus_entrypoint_0(void)
{
    extern u8 D_808008F4_choctopus[];

    return (OSThread *) D_808008F4_choctopus;
}

void func_8080000C_choctopus(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor*);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.8f);
    arg0->actorData[6] = _subaddiesect_entrypoint_1(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800054_choctopus.s")

void func_808007E4_choctopus();

void func_80800210_choctopus()
{
    func_808007E4_choctopus();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800230_choctopus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800348_choctopus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800428_choctopus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800540_choctopus.s")

OSThread *choctopus_entrypoint_1(void)
{
    extern u8 D_80800998_choctopus[];

    return (OSThread *) D_80800998_choctopus;
}

void func_80800790_choctopus(Actor *arg0) {
    void _suexpression_entrypoint_12(void*, f32, f32);
    void _suexpression_entrypoint_7(Actor*, u32, u32);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1U, 0xB6U);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 80.0f, 30.0f);
    }
}

void func_808007E4_choctopus(Actor *arg0) {
    void _suexpression_entrypoint_8(Actor *, s32);
    if (func_80100094(arg0, 1U) != 0) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
