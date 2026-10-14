#include "common.h"

OSThread *chpowerhutwitchy_entrypoint_0(void)
{
    extern u8 D_80800B28_chpowerhutwitchy[];

    return (OSThread *) D_80800B28_chpowerhutwitchy;
}

OSThread *chpowerhutwitchy_entrypoint_1(void)
{
    extern u8 D_80800B70_chpowerhutwitchy[];

    return (OSThread *) D_80800B70_chpowerhutwitchy;
}

OSThread *chpowerhutwitchy_entrypoint_2(void)
{
    extern u8 D_80800BB8_chpowerhutwitchy[];

    return (OSThread *) D_80800BB8_chpowerhutwitchy;
}

OSThread *chpowerhutwitchy_entrypoint_3(void)
{
    extern u8 D_80800C00_chpowerhutwitchy[];

    return (OSThread *) D_80800C00_chpowerhutwitchy;
}

void func_80800030_chpowerhutwitchy(Actor *arg0) {
    s32 _chpowerhut_entrypoint_0(Actor *, s32 *);
    extern s32 D_80800B00_chpowerhutwitchy;
    _chpowerhut_entrypoint_0(arg0, &D_80800B00_chpowerhutwitchy);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x18))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/func_80800068_chpowerhutwitchy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/func_80800168_chpowerhutwitchy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/func_8080024C_chpowerhutwitchy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/chpowerhutwitchy_entrypoint_4.s")

void func_808005C8_chpowerhutwitchy(Actor *arg0) {
    s32 _chpowerhut_entrypoint_0(Actor *, s32 *);
    extern s32 D_80800B14_chpowerhutwitchy;
    _chpowerhut_entrypoint_0(arg0, &D_80800B14_chpowerhutwitchy);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x18))) = 0;
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x19))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/func_80800610_chpowerhutwitchy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/func_8080073C_chpowerhutwitchy.s")

void func_80800890_chpowerhutwitchy(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, void (*)(void), s32);
    s32 func_800BEA88(s32);
    void _chpowerhutwitchy_entrypoint_5(void);
    s32 sp24;
    s32 temp_v0;
    s32 temp_v0_2;
    void (*callback)(void) = _chpowerhutwitchy_entrypoint_5;

    temp_v0 = func_800BEA88(0);
    sp24 = temp_v0;
    _glid_entrypoint_0(temp_v0, 4, callback, *arg0);
    _glid_entrypoint_0(sp24, 5, callback, *arg0);
    temp_v0_2 = func_800BEA88(1);
    sp24 = temp_v0_2;
    _glid_entrypoint_0(temp_v0_2, 4, callback, *arg0);
    _glid_entrypoint_0(sp24, 5, callback, *arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/chpowerhutwitchy_entrypoint_5.s")

/* extern */

void func_808009FC_chpowerhutwitchy(s32 arg0) {
    s32 _idworldmake_entrypoint_1(s32, s32, s32, s32);
    s32 func_800BEA88(s32);
    s32 func_800EA05C();
    if (func_800EA05C() == 0xD6) {
        _idworldmake_entrypoint_1(func_800BEA88(0), 0x89D, 4, 1);
    }
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x19))) = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/func_80800A58_chpowerhutwitchy.s")
