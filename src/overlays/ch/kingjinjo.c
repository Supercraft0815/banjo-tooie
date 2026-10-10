#include "common.h"

OSThread *chkingjinjo_entrypoint_0(void)
{
    extern u8 D_808011A8_chkingjinjo[];

    return (OSThread *) D_808011A8_chkingjinjo;
}

OSThread *chkingjinjo_entrypoint_1(void)
{
    extern u8 D_808011F0_chkingjinjo[];

    return (OSThread *) D_808011F0_chkingjinjo;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800018_chkingjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800194_chkingjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800634_chkingjinjo.s")

/* extern */

void func_808009D0_chkingjinjo(s32 arg0) {
    s32 _suexpression_entrypoint_8(s32, s32);
    s32 func_80800C18_chkingjinjo();
    func_80800C18_chkingjinjo();
    _suexpression_entrypoint_8(arg0, 0x1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_808009FC_chkingjinjo.s")

void func_80800AE4_chkingjinjo(s32 arg0, s32 *arg1) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 func_80800C60_chkingjinjo(void *, s32, s32);
    s32 temp_v0;

    temp_v0 = _subaddiedialog_entrypoint_7(arg0, arg0 + 4, arg1);
    if ((temp_v0 != 0) && (temp_v0 != 0x1208)) {
        func_80800C60_chkingjinjo((u8 *) arg0, 3, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800B28_chkingjinjo.s")

/* extern */

s32 func_80800BBC_chkingjinjo(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 func_80800C60_chkingjinjo(void *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if (((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) != 2) {
            func_80800C60_chkingjinjo(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800C18_chkingjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800C60_chkingjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800CFC_chkingjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800D80_chkingjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800E58_chkingjinjo.s")

s32 func_80800F60_chkingjinjo(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
/* extern */

void func_80800F74_chkingjinjo(void *arg0, s32 arg1) {
    s32 func_800DF744(s32, u32);
    s32 func_80101870(void *, s32);
    func_800DF744(3, (*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF);
    func_800DF744(4, (u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) << 0xC) >> 0x1F);
    func_80101870(arg0, arg1);
}
