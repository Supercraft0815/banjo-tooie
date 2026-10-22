#include "common.h"

void func_80800000_chbkcart(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    s32 func_800D1A04(s32);
    s32 func_800DA298(s32);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);

    switch (arg0->unk74_7 - 0x32) {
        case 0:
            if (func_800D1A04(0x53) || func_800DA298(0x3E2)) {
                func_800FFA88(arg0->unk0);
                return;
            }
            break;
        case 1:
            if (func_800DA298(0x3E3) || func_800DA298(0x3E4)) {
                func_800FFA88(arg0->unk0);
                return;
            }
            break;
        case 2:
            if (func_800DA298(0x3E5) || func_800DA298(0x3E6)) {
                func_800FFA88(arg0->unk0);
                return;
            }
            break;
    }
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0), arg0->position);
    if (!func_800DA298(0x342)) {
        func_80102424(arg0, 1);
    } else {
        func_80102424(arg0, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bkcart/func_80800130_chbkcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bkcart/func_808004DC_chbkcart.s")

OSThread *chbkcart_entrypoint_0(void)
{
    extern u8 D_80800880_chbkcart[];

    return (OSThread *) D_80800880_chbkcart;
}
