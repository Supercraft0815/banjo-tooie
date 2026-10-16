#include "common.h"

void func_80800000_chjinjovillagecamera1(Actor *arg0, s32 arg1, s32 arg2) {
    void _glcutDll_entrypoint_17();
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
    case 0x1522:
        _glcutDll_entrypoint_17();
        return;
    case 0x1523:
    case 0x1524:
    case 0x1565:
        func_80101FDC(arg0, 2);
        arg0->unk58 = 1.5f;
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjovillagecamera1/func_80800078_chjinjovillagecamera1.s")

void func_808002BC_chjinjovillagecamera1(s32 arg0) {
    s32 _chjinjo_entrypoint_2(s32);
    void func_800BF744(s32, s32);
    extern u8 D_80800488_chjinjovillagecamera1;
    s32 temp_v0;

    temp_v0 = _chjinjo_entrypoint_2(-1);
    if (temp_v0 != -1) {
        func_800BF744(9U, 0);
        func_800BF744(*((u8 *) &D_80800488_chjinjovillagecamera1 + temp_v0), 1);
    }
}

/* extern */

void func_80800310_chjinjovillagecamera1(s32 arg0) {
    s32 _chjinjo_entrypoint_2(s32);
    s32 _glcutDll_entrypoint_19(u32);
    s32 func_800D129C(u32);
    u32 func_800D1338(u32);
    s32 func_800EA05C();
    u32 func_800FDC28(u32);
    s32 func_80101180(s32, s32, s32);
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    func_808002BC_chjinjovillagecamera1(arg0);
    if (func_800EA05C() != 0x142) {
        sp24 = _chjinjo_entrypoint_2(-1);
        sp20 = func_800D1338(sp24);
        sp1C = func_800D129C(sp24);
        sp18 = sp20 == sp1C;
        if (_glcutDll_entrypoint_19(0x84) != 0) {
            if ((sp18 == 0) || (sp1C == 1)) {
                func_80101180(0x48F, 0x7E, 0);
            }
        } else if (sp18 != 0) {
            func_800FDC28(0x12);
        }
    }
}

void func_808003C0_chjinjovillagecamera1(Actor *arg0) {
    s32 _chjinjo_entrypoint_2(s32);
    void _chjinjo_entrypoint_1(s32, s32);
    s32 func_800D9078(f32 *);
    void func_80101FDC(Actor *, u32);
    void _glcutDll_entrypoint_17(void);

    switch (arg0->unk70_10) {
        case 2:
            if (func_800D9078(&arg0->unk58) != 0) {
                _chjinjo_entrypoint_1(_chjinjo_entrypoint_2(-1), 0);
                func_80101FDC(arg0, 3);
                arg0->unk58 = 2.5f;
            }
            break;
        case 3:
            if (func_800D9078(&arg0->unk58) != 0) {
                _glcutDll_entrypoint_17();
            }
            break;
    }
}

OSThread *chjinjovillagecamera1_entrypoint_0(void)
{
    extern u8 D_80800494_chjinjovillagecamera1[];

    return (OSThread *) D_80800494_chjinjovillagecamera1;
}
