#include "common.h"

OSThread *chjiggytemple_entrypoint_0(void)
{
    extern u8 D_808008C8_chjiggytemple[];

    return (OSThread *) D_808008C8_chjiggytemple;
}

void func_8080000C_chjiggytemple(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    extern s32 D_80800910_chjiggytemple;
    _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80800910_chjiggytemple);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/temple/func_80800034_chjiggytemple.s")

void func_808000A8_chjiggytemple(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/temple/func_808000B0_chjiggytemple.s")

OSThread *chjiggytemple_entrypoint_1(void)
{
    extern u8 D_8080092C_chjiggytemple[];

    return (OSThread *) D_8080092C_chjiggytemple;
}

/* extern */

void func_80800320_chjiggytemple(s32 arg0) {
    s32 _chdoormake_entrypoint_3(s32, f32, f32, f32, s32, s32);
    s32 _chdoormake_entrypoint_5(s32, f32);
    s32 _chdoormake_entrypoint_6(s32, f32);
    s32 _chdoormake_entrypoint_7(s32, f32);
    s32 _chdoormake_entrypoint_8(s32, s32);
    s32 _chdoormake_entrypoint_9(s32, s32, s32, s32);
    s32 _glcutDll_entrypoint_18();
    s32 _sujiggy_entrypoint_17();
    s32 func_800DA298(s32);
    s32 func_800EA090();
    s32 func_8010108C(s32, s32, s32);
    void func_80101FDC(Actor *, u32);
    f32 func_80103EF4(s32);
    s32 sp2C;
    s32 sp28;

    sp2C = func_800EA090();
    if ((func_800DA298(0x532) != 0) && ((sp2C == 1) || (_sujiggy_entrypoint_17() != 0))) {
        func_80101FDC(arg0, 4);
    }
    _chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, func_80103EF4(arg0), 2, -1);
    _chdoormake_entrypoint_5(arg0, 1.0f);
    _chdoormake_entrypoint_6(arg0, 0.5f);
    _chdoormake_entrypoint_7(arg0, 0.5f);
    _chdoormake_entrypoint_8(arg0, 5);
    _chdoormake_entrypoint_9(arg0, 1, 0x12, 0x10);
    if (func_800DA298(0x532) != 0) {
        sp28 = _glcutDll_entrypoint_18();
        if ((_sujiggy_entrypoint_17() == 0) && (sp28 != 0x67) && (sp28 != 0x7A)) {
            func_8010108C(arg0, 8, 0);
        }
    }
}

void func_80800438_chjiggytemple(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    if (arg1 == 7) {
        _chdoor_entrypoint_1(arg0, arg1, arg2);
        return;
    }
    _chdoor_entrypoint_1(arg0, arg1, arg2);
}

OSThread *chjiggytemple_entrypoint_2(void)
{
    extern u8 D_80800974_chjiggytemple[];

    return (OSThread *) D_80800974_chjiggytemple;
}

void func_8080047C_chjiggytemple(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, u8, s32 *, s32);
    extern u32 D_808009BC_chjiggytemple;
    extern s32 D_808009D0_chjiggytemple;
    f32 *sp24[2];
    f32 *position;
    sp24[1] = (f32 *)((u8 *)arg0 + 4);
    _subaddieaudioloop_entrypoint_4(arg0, sp24[1], 1U, &D_808009BC_chjiggytemple);
    position = sp24[1];
    (*(u8 *)((s8 *)(arg0) + (0x24))) = _subaddieaudioloop_entrypoint_7((*(u8 *)((s8 *)(arg0) + (0x24))), position, 1, &D_808009D0_chjiggytemple, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/temple/func_808004D8_chjiggytemple.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/temple/func_80800688_chjiggytemple.s")

/* extern */

void func_80800784_chjiggytemple(void *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void func_800B5450(void *);
    s32 func_800E1720(s32);
    void *temp_a2;
    s32 temp_v0;
    u8 temp_a0;

    temp_a2 = (*(void **)((s8 *)(arg0) + (0x2C)));
    if (temp_a2 != NULL) {
        func_800B5450(temp_a2);
        (*(void **)((s8 *)(arg0) + (0x2C))) = NULL;
    }
    temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x30)));
    if (temp_v0 != 0) {
        func_800E1720(temp_v0 - 1);
        (*(s32 *)((s8 *)(arg0) + (0x30))) = 0;
    }
    temp_a0 = (*(u8 *)((s8 *)(arg0) + (0x24)));
    if (temp_a0 != 0) {
        (*(u8 *)((s8 *)(arg0) + (0x24))) = _subaddieaudioloop_entrypoint_3(temp_a0);
    }
}

s32 func_808007F4_chjiggytemple(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _glcutDll_entrypoint_19(u32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
        case 0x95:
            if (!_glcutDll_entrypoint_19(0x67) && !_glcutDll_entrypoint_19(0x7A)) {
                func_800FFAB0(arg0);
            } else {
                _capod_entrypoint_13(arg0->unk0, NULL, 0x14, 0x2820);
            }
            break;
        case 0xB:
            func_80101FDC(arg0, 2);
            ((f32 *)arg0->actorData)[2] = 0.0f;
            ((f32 *)arg0->actorData)[4] = 2.0f;
            return 3;
        default:
            return 0;
    }
    return 1;
}
