#include "common.h"

OSThread *chdingpot_entrypoint_0(void)
{
    extern u8 D_80800500_chdingpot[];

    return (OSThread *) D_80800500_chdingpot;
}

void func_8080000C_chdingpot(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.5f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dingpot/func_80800040_chdingpot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dingpot/func_8080021C_chdingpot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dingpot/func_808002B4_chdingpot.s")

void func_80800350_chdingpot(s32 arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    extern s32 D_808004B0_chdingpot;
    extern s32 D_808005C8_chdingpot;
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, &D_808005C8_chdingpot, &D_808004B0_chdingpot, 5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dingpot/func_80800388_chdingpot.s")
