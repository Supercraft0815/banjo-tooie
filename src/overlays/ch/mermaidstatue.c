#include "common.h"

OSThread *chmermaidstatue_entrypoint_0(void)
{
    extern u8 D_80800354_chmermaidstatue[];

    return (OSThread *) D_80800354_chmermaidstatue;
}

OSThread *chmermaidstatue_entrypoint_1(void)
{
    extern u8 D_8080039C_chmermaidstatue[];

    return (OSThread *) D_8080039C_chmermaidstatue;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mermaidstatue/func_80800018_chmermaidstatue.s")

void func_80800094_chmermaidstatue(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mermaidstatue/func_8080009C_chmermaidstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mermaidstatue/func_808000E0_chmermaidstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mermaidstatue/func_80800150_chmermaidstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mermaidstatue/func_808001B0_chmermaidstatue.s")

void func_808002C8_chmermaidstatue(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor*, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor*, f32);
    void _chdoormake_entrypoint_6(Actor*, s32);
    void _chdoormake_entrypoint_8(void*, u32);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 400.0f, 1, 0x18D) != 0) {
        _chdoormake_entrypoint_8(arg0, 0xDU);
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_6(arg0, 0x40400000);
    }
}
