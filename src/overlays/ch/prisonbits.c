#include "common.h"

OSThread *chprisonbits_entrypoint_0(void)
{
    extern u8 D_80800F78_chprisonbits[];

    return (OSThread *) D_80800F78_chprisonbits;
}

OSThread *chprisonbits_entrypoint_1(void)
{
    extern u8 D_80800FC0_chprisonbits[];

    return (OSThread *) D_80800FC0_chprisonbits;
}

OSThread *chprisonbits_entrypoint_2(void)
{
    extern u8 D_80801008_chprisonbits[];

    return (OSThread *) D_80801008_chprisonbits;
}

OSThread *chprisonbits_entrypoint_3(void)
{
    extern u8 D_80801050_chprisonbits[];

    return (OSThread *) D_80801050_chprisonbits;
}

OSThread *chprisonbits_entrypoint_4(void)
{
    extern u8 D_808010A8_chprisonbits[];

    return (OSThread *) D_808010A8_chprisonbits;
}

void func_8080003C_chprisonbits()
{
    _chswitch_entrypoint_7();
}

void func_8080005C_chprisonbits(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *temp_v0;

    temp_v0 = (Actor *) _subaddiefind_entrypoint_2(0x120, 0);
    arg0->position[0] = temp_v0->position[0] + (f32) arg2;
    arg0->position[2] = temp_v0->position[2];
    func_8080003C_chprisonbits(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_808000C0_chprisonbits.s")

void func_808001E0_chprisonbits(s32 arg0)
{
    func_8080003C_chprisonbits(arg0,1);
}

void func_80800200_chprisonbits(s32 arg0) {
    func_8080005C_chprisonbits(arg0, 0x2, 175);
}

/* extern */

void func_80800224_chprisonbits(Actor *arg0) {
    s32 _chdoormake_entrypoint_0(void*, f32, u32, s32);
    void _chdoormake_entrypoint_5(Actor*, f32);
    void _chdoormake_entrypoint_8(void*, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    if (_chdoormake_entrypoint_0(arg0, 90.0f, 0x60U, 0xD5) != 0) {
        _chdoormake_entrypoint_8(arg0, 5);
        _chdoormake_entrypoint_5(arg0, 3.0f);
        _chdoormake_entrypoint_9(arg0, 0, 0, 0x10);
    }
}

void func_80800280_chprisonbits()
{
    func_800DA298();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_808002A0_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800344_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_8080044C_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800518_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_8080090C_chprisonbits.s")

void func_80800970_chprisonbits(Actor *arg0) {
    void _suexpression_entrypoint_8(Actor*, u32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_8(arg0, 1U);
    }
    _susubgame_entrypoint_4(arg0, (s32) (sp1C + 0x1C));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_808009C4_chprisonbits.s")

int func_80800BB4_chprisonbits(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80801100_chprisonbits;
    s32 result;

    result = _subaddiedialog_entrypoint_7((s32)arg0, (s32)arg0 + 4, &D_80801100_chprisonbits);
    if ((result != 0) && (result != 0x1208)) {
        _susubgame_entrypoint_5(arg0, (u8 *)func_80100094(arg0, 0U) + 0x1C, 4, 0, 0);
    }
    return result;
}

void func_80800C18_chprisonbits(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor*, f32*, u32*, u32*);
    extern u32 D_8080111C_chprisonbits;
    extern u32 D_8080112C_chprisonbits;
    extern u32 D_80801138_chprisonbits;
    extern u32 D_80801144_chprisonbits;

    f32 * volatile temp_a1;

    _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = (f32 *) ((s8 *) arg0 + 4), &D_8080111C_chprisonbits, &D_80801144_chprisonbits);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_8080112C_chprisonbits, 0.75f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_80801138_chprisonbits, 0.6f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800C84_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800CC4_chprisonbits.s")

/* extern */

void func_80800DAC_chprisonbits(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_800CD08C(s32, u8 *);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    func_800CD08C(((u32) (*(u32 *)((s8 *)(arg0) + (0x70))) >> 0x19) - 1, temp_v0);
    (*(f32 *)((s8 *)(sp1C) + (4))) = (f32) arg0->position[1];
}

int func_80800DFC_chprisonbits(Actor *arg0) {
    return !func_800DA298(0x5B) && func_80090128() && func_8010C500(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/chprisonbits_entrypoint_5.s")
