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

/* extern */

void func_80800018_chmermaidstatue(void *arg0) {
    s32 _subaddiesect_entrypoint_1();
    s32 _subaddiesect_entrypoint_2(void *, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA7A8(s32, s32, s32);
    s32 func_80101FDC(void *, s32);
    s32 func_80109EEC(void *, s32);
    s32 func_8010A570(void *);
    s32 temp_v0;

    temp_v0 = _subaddiesect_entrypoint_1();
    (*(s32 *)((s8 *)(arg0) + (0x30))) = temp_v0;
    _subaddiesect_entrypoint_2(arg0, temp_v0, 0);
    func_800DA7A8(0x6B1, 0, 3);
    func_80109EEC(arg0, 0x40);
    if (func_800DA298(0x18D) != 0) {
        func_8010A570(arg0);
        func_80101FDC(arg0, 2);
    }
}

void func_80800094_chmermaidstatue(s32 arg0) 
{
}
/* extern */

void func_8080009C_chmermaidstatue(void *arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(void *, s32);
    func_800DF744(3, ((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) - 0x31);
    func_80101870(arg0, arg1);
}

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
