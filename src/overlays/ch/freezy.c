#include "common.h"

OSThread *chfreezy_entrypoint_0(void)
{
    extern u8 D_80800700_chfreezy[];

    return (OSThread *) D_80800700_chfreezy;
}

/* extern */

void func_8080000C_chfreezy(void *arg0) {
    s32 _sufreezy_entrypoint_1();
    _sufreezy_entrypoint_1();
    (*(f32 *)((s8 *)(arg0) + (0x38))) = 0.2f;
}

/* extern */

void func_8080003C_chfreezy(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u32 func_8010A828(Actor*, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    func_8010A828(_subaddielink_entrypoint_4(func_80100094(arg0, 1U)), (u32) (*(u8 *)((s8 *)(arg0) + (0x79))) >> 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/freezy/func_80800080_chfreezy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/freezy/func_80800190_chfreezy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/freezy/chfreezy_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/freezy/chfreezy_entrypoint_2.s")

/* extern */

void func_8080044C_chfreezy(u8 **arg0, Actor *arg1, s32 arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void func_80103DFC(Actor*, f32*);
    s32 func_808004B8_chfreezy(u8 **, Actor *, s32);
    if (((u32) (*(u32 *)((s8 *)(*arg0) + (0x24))) >> 0x16) == 0x2F6) {
        func_800EE7F8((f32 *)((u8 *)arg0 + 0x44), (f32 *)((u8 *)arg1 + 0x44));
        func_80103DFC(arg1, (f32 *)((u8 *)arg0 + 4));
        func_808004B8_chfreezy(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/freezy/func_808004B8_chfreezy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/freezy/func_80800538_chfreezy.s")

/* extern */

void func_808006C0_chfreezy(s32 arg0) {
    s32 _sufreezy_entrypoint_2();
    s32 func_800FFAB0(s32);
    _sufreezy_entrypoint_2();
    func_800FFAB0(arg0);
}
