#include "common.h"

OSThread *chweldarhead_entrypoint_0(void)
{
    extern u8 D_808004F0_chweldarhead[];

    return (OSThread *) D_808004F0_chweldarhead;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarhead/func_8080000C_chweldarhead.s")

void func_80800170_chweldarhead(u8 *arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    s32 func_800DC128(s32, s32);
    extern s32 D_80800538_chweldarhead;
    extern s16 D_8080053E_chweldarhead;
    if (((Actor *) arg0)->unk70_10 == 1) {
        D_8080053E_chweldarhead = func_800DC128(0, 4) + 0x1361;
        _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80800538_chweldarhead);
    }
    _sudeflect_entrypoint_0((f32 *) (arg0 + 4), 20.0f, 120.0f, 0xA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarhead/func_808001E4_chweldarhead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarhead/func_8080038C_chweldarhead.s")
