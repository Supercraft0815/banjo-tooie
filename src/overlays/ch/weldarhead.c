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

void func_8080038C_chweldarhead(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void func_80108B04(Actor *, u32);
    void func_80102424(Actor *, s32);
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x1360:
            _susubgame_entrypoint_6(arg0, data + 0x18, 0x48, 0x30, 0);
            func_80108B04(arg0, 0);
            arg0->unk64_20 = 1;
            break;
        case 0x1384:
            _susubgame_entrypoint_4(arg0, data + 0x18);
        default:
            func_80102424(arg0, 1);
            break;
    }
}
