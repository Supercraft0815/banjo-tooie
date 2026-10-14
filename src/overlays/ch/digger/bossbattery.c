#include "common.h"

OSThread *chdiggerbossbattery_entrypoint_0(void)
{
    extern u8 D_808002F0_chdiggerbossbattery[];

    return (OSThread *) D_808002F0_chdiggerbossbattery;
}

/* extern */

void func_8080000C_chdiggerbossbattery(Actor *arg0) {
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    func_800EFD24(arg0->position);
    func_80102FDC(arg0, 0.25f);
    arg0->unk58 = func_800DC178(1.5f, 3.0f);
    if (func_800DA298(arg0->unk74_7 + 0xA1D) != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossbattery/func_80800090_chdiggerbossbattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossbattery/func_80800170_chdiggerbossbattery.s")
