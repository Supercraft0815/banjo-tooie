#include "common.h"

OSThread *chdinofoot_entrypoint_0(void)
{
    extern u8 D_80800818_chdinofoot[];

    return (OSThread *) D_80800818_chdinofoot;
}

/* extern */

void func_8080000C_chdinofoot(void *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddiefade_entrypoint_12(void *, s32, s32, s32);
    s32 func_80102424(void *, s32);
    s32 func_80102FDC(void *, f32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 5);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = 1.4f;
    }
    _subaddiefade_entrypoint_12(arg0, 0x60, 0x80, 0x60);
    func_80102FDC(arg0, (*(f32 *)((s8 *)(arg0) + (0x38))) * 4.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_80800084_chdinofoot.s")

/* extern */

s32 func_808002A8_chdinofoot(Actor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    u32 func_800FDC28(u32);
    void func_8080035C_chdinofoot(Actor *, Unk80132ED0 *);
    Unk80132ED0 **data = &arg2;
    s32 result;
    switch (arg1) {
        case 0x3F:
            func_8080035C_chdinofoot(arg0, *data);
            return 1;
        case 0xB:
            arg0->unk64_20 = 0;
            func_800FDC28(0);
            result = 3;
            break;
        default:
            return 0;
    }
    return result;
}

/* extern */

void func_80800310_chdinofoot(s32 arg0, s32 arg1) {
    s32 _subaddiefade_entrypoint_0();
    s32 _subaddiefade_entrypoint_1(s32, s32);
    s32 func_80101870(s32, s32);
    s32 sp1C;

    sp1C = _subaddiefade_entrypoint_0();
    _subaddiefade_entrypoint_1(arg0, 0xFF);
    func_80101870(arg0, arg1);
    _subaddiefade_entrypoint_1(arg0, sp1C);
}

/* extern */

void func_8080035C_chdinofoot(Actor *arg0, Unk80132ED0 *arg1) {
    s32 func_800F54E4();
    s32 func_800F79DC(s32, s32, s32);
    s32 func_800F7B9C(s32, s32);
    f32 func_80101F24(Actor *);
    void func_8010A570(Actor *);
    if ((arg1->unk24 >> 22) == 0) {
        if ((arg0->unk70_10 == 4) && (func_80101F24(arg0) < 0.4f)) {
            func_800F7B9C(func_800F54E4(), 0x5A);
            func_8010A570(arg0);
            return;
        }
        func_800F79DC(func_800F54E4(), 0xA, arg0->unk0);
        func_8010A570(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_80800408_chdinofoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_80800480_chdinofoot.s")

/* extern */

s32 func_8080055C_chdinofoot(void *arg0) {
    f32 func_800136E4(f32);
    f32 func_8010CD28(void *);
    s32 func_80800408_chdinofoot();
    if (func_80800408_chdinofoot() != 0) {
        (*(f32 *)((s8 *)(arg0) + (4))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x18)));
        (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x20)));
        (*(f32 *)((s8 *)(arg0) + (0x48))) = func_800136E4(func_8010CD28(arg0) + 180.0f);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_808005C4_chdinofoot.s")

s32 func_808006BC_chdinofoot(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800E15CC(s32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    s32 func_808005C4_chdinofoot(Actor *);
    extern u32 D_80800880_chdinofoot;
    extern s32 D_80800890_chdinofoot;
    extern s32 D_808008A0_chdinofoot;
    f32 *temp_s1;

    temp_s1 = arg0->position;
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_80800880_chdinofoot, 0.0f);
    if (func_80101F24(arg0) < 0.4f) {
        func_808005C4_chdinofoot(arg0);
    }
    if (func_80101E14(arg0, 0.4f) != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, temp_s1, &D_80800890_chdinofoot);
        func_800BBCB8(temp_s1, temp_s1, 1.0f, 6, &D_808008A0_chdinofoot);
        func_800E15CC(0, 40.0f, 0.8f);
        func_80018820(0, 3.0f, 0.25f);
        return 1;
    }
    return 0;
}
