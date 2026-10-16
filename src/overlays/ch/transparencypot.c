#include "common.h"

OSThread *chtransparencypot_entrypoint_0(void)
{
    extern u8 D_808001B0_chtransparencypot[];

    return (OSThread *) D_808001B0_chtransparencypot;
}

void func_8080000C_chtransparencypot(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x38))) = 0.5f;
}

void func_8080001C_chtransparencypot(Actor *arg0, s32 arg1) {
    s32 _subaddiefade_entrypoint_2();
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    f32 temp;

    if (arg1 != 1) {
        if (arg1 == 2) {
            arg0->unk64_16 = 0;
            func_8010A570(arg0);
            temp = arg0->rotation[1] * func_800DC178(0.5f, 1.0f);
            arg0->unk58 = temp;
        }
    } else {
        arg0->unk64_16 = 1;
        func_8010A590(arg0);
        _subaddiefade_entrypoint_2(arg0);
    }
    func_80101FDC(arg0, arg1);
}

/* extern */

void func_808000B8_chtransparencypot(Actor *arg0) {
    void func_8080001C_chtransparencypot(Actor *, s32);
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
    void func_8080001C_chtransparencypot(Actor *, s32);
    extern s32 D_808001F8_chtransparencypot;
    f32 rotation = arg0->rotation[1];

    func_800F7C0C(arg1, 0x67, rotation);
    _fxsparkle_entrypoint_1(arg0->position, 2U);
    func_800C4AF0(arg0->position, &D_808001F8_chtransparencypot);
    func_8080001C_chtransparencypot(arg0, 2);
}
