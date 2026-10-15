#include "common.h"

OSThread *chdiggerground_entrypoint_0(void)
{
    extern u8 D_80800408_chdiggerground[];

    return (OSThread *) D_80800408_chdiggerground;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/ground/func_8080000C_chdiggerground.s")

/* extern */

void func_80800070_chdiggerground(Actor *arg0) {
    void func_80101FDC(Actor*, u32);
    void func_8010A3E8(void *arg0, f32 arg1);
    void func_808000C4_chdiggerground(Actor *);
    if (((u32) (*(u32 *)((s8 *)(arg0) + (0x6C))) >> 0x15) != 0) {
        func_80101FDC(arg0, 1U);
        func_808000C4_chdiggerground(arg0);
        arg0->unk64_20 = 1;
    }
    func_8010A3E8(arg0, 0.75f);
}

/* extern */

void func_808000C4_chdiggerground(Actor *arg0) {
    s32 _subaddieDll_entrypoint_1(Actor *);
    s32 _sucoaster_entrypoint_0(void *, s32);
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 func_800D9058(f32);
    int func_800DC298(f32);
    void func_8010A590(Actor *);

    _subaddieDll_entrypoint_1(arg0);
    if (_sucoaster_entrypoint_0(arg0, 0) != 0) {
        _sucoaster_entrypoint_10(arg0, func_800DC298(0.65f) ? 3 : 2);
        if (arg0->pad6C_21 == 0) {
            arg0->unk6C_0 = func_800D9058(1.5f);
        }
        arg0->unk64_24 = 1;
        func_8010A590(arg0);
    }
}

/* extern */

s32 func_80800168_chdiggerground(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _sucoaster_entrypoint_21(Actor *, s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80800214_chdiggerground(Actor *);
    if (func_80100094(arg0, 0U) == NULL) {
        return 0;
    }
    if (arg1 == 0xB6) {
        func_80800214_chdiggerground(arg0);
    }
    return _sucoaster_entrypoint_21(arg0, arg1, arg2);
}

/* extern */

void func_808001C8_chdiggerground(Actor *arg0, u8 *arg1) {
    void* func_80100094(Actor*, u32);
    void func_80101870(Actor* arg0, void* arg1);
    s32 _sucoaster_entrypoint_20(Actor *, u8 *);
    if (func_80100094(arg0, 0U) == NULL) {
        func_80101870(arg0, arg1);
        return;
    }
    _sucoaster_entrypoint_20(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/ground/func_80800214_chdiggerground.s")
