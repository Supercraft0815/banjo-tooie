#include "common.h"

OSThread *chtransparencypot_entrypoint_0(void)
{
    extern u8 D_808001B0_chtransparencypot[];

    return (OSThread *) D_808001B0_chtransparencypot;
}

void func_8080000C_chtransparencypot(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x38))) = 0.5f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/transparencypot/func_8080001C_chtransparencypot.s")

/* extern */

void func_808000B8_chtransparencypot(Actor *arg0) {
    s32 func_8080001C_chtransparencypot(Actor *, s32);
    if ((arg0->unk70_10 == 2) && (func_800D9078(&arg0->unk58) != 0)) {
        func_8080001C_chtransparencypot(arg0, 1);
    }
}

/* extern */

s32 func_80800104_chtransparencypot(s32 arg0, s32 arg1, u8 *arg2) {
    void func_80800148_chtransparencypot(Actor *, u32);
    u8 **ptr = &arg2;
    switch (arg1) {
    case 0x3E:
        func_80800148_chtransparencypot((Actor *)arg0, (u32)*(u16 *)(*ptr + 0x1A) >> 5);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800148_chtransparencypot(Actor *arg0, u32 arg1) {
    void _fxsparkle_entrypoint_1(f32 *, u32);
    void func_800C4AF0(f32 *, void *);
    s32 func_800F7C0C(s32, s32, f32);
    s32 func_8080001C_chtransparencypot(Actor *, s32);
    extern s32 D_808001F8_chtransparencypot;
    f32 rotation = arg0->rotation[1];

    func_800F7C0C(arg1, 0x67, rotation);
    _fxsparkle_entrypoint_1(arg0->position, 2U);
    func_800C4AF0(arg0->position, &D_808001F8_chtransparencypot);
    func_8080001C_chtransparencypot(arg0, 2);
}
