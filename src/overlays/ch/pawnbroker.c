#include "common.h"

OSThread *chpawnbroker_entrypoint_0(void)
{
    extern u8 D_80800FD0_chpawnbroker[];

    return (OSThread *) D_80800FD0_chpawnbroker;
}

OSThread *chpawnbroker_entrypoint_1(void)
{
    extern u8 D_80801018_chpawnbroker[];

    return (OSThread *) D_80801018_chpawnbroker;
}

OSThread *chpawnbroker_entrypoint_2(void)
{
    extern u8 D_80801060_chpawnbroker[];

    return (OSThread *) D_80801060_chpawnbroker;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pawnbroker/func_80800024_chpawnbroker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pawnbroker/func_80800320_chpawnbroker.s")

void func_80800514_chpawnbroker(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pawnbroker/func_80800534_chpawnbroker.s")

void func_80800664_chpawnbroker(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_808010C4_chpawnbroker;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808010C4_chpawnbroker, 0.52f);
}

void func_80800694_chpawnbroker(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    extern u32 D_808010CC_chpawnbroker;
    extern u32 D_808010D8_chpawnbroker;
    extern u32 D_808010E4_chpawnbroker;
    extern u32 D_808010F0_chpawnbroker;
    f32 * volatile temp_a1;

    _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = (f32 *) ((s8 *) arg0 + 4), &D_808010D8_chpawnbroker, &D_808010F0_chpawnbroker);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_808010CC_chpawnbroker, 0.0f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_808010E4_chpawnbroker, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pawnbroker/func_808006FC_chpawnbroker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pawnbroker/func_808007BC_chpawnbroker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pawnbroker/func_8080083C_chpawnbroker.s")

/* extern */

s32 func_80800A50_chpawnbroker(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 func_80800AE4_chpawnbroker(void *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 2) {
            func_80800AE4_chpawnbroker(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80800AA8_chpawnbroker(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x28))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pawnbroker/func_80800AE4_chpawnbroker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pawnbroker/func_80800B88_chpawnbroker.s")

/* extern */

s32 func_80800C00_chpawnbroker(s32 arg0, s32 arg1) {
    s32 func_800D1A04(s32);
    s32 func_800F54E4();
    s32 func_800F64A4(s32, s32);
    if (arg1 > 0) {
        if (func_800D1A04(0x4E) >= arg0) {
            if (func_800F64A4(func_800F54E4(), 0x201) != 0) {
                return 0x1040;
            }
            return 0x1225;
        }
        return 0xFE9;
    }
    return 0xFE7;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pawnbroker/func_80800C70_chpawnbroker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pawnbroker/func_80800CB4_chpawnbroker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pawnbroker/func_80800D5C_chpawnbroker.s")

/* extern */

void func_80800DE8_chpawnbroker(Actor *arg0) {
    s32 func_80101DDC(Actor*);
    void func_80102424(Actor*, s32);
    void func_80800E3C_chpawnbroker(Actor *);
    if (arg0->unk70_10 == 2) {
        func_80800E3C_chpawnbroker(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80102424(arg0, 1);
        }
    }
}

void func_80800E34_chpawnbroker(s32 arg0) 
{
}
void func_80800E3C_chpawnbroker(Actor *arg0) { void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32); void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *); extern u32 D_80801144_chpawnbroker; extern u32 D_8080114C_chpawnbroker; extern u32 D_80801154_chpawnbroker; f32 * volatile temp_a1; _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = (f32 *) ((s8 *) arg0 + 4), &D_80801144_chpawnbroker, &D_80801154_chpawnbroker); _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_8080114C_chpawnbroker, 0.5f); _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_8080114C_chpawnbroker, 0.87f); }
