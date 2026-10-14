#include "common.h"

OSThread *chdiggerbossinterior_entrypoint_0(void)
{
    extern u8 D_80800230_chdiggerbossinterior[];

    return (OSThread *) D_80800230_chdiggerbossinterior;
}

/* extern */

void func_8080000C_chdiggerbossinterior(s32 arg0) {
    s32 func_800FE850();
    func_800FE850();
}

void func_8080002C_chdiggerbossinterior(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    void _sucoaster_entrypoint_5(Actor *);
    void func_800D2498(u32, s32, u32);
    s32 func_800DA980(s32, s32);
    extern u32 D_80800278_chdiggerbossinterior;
    s32 sp30[2];
    Actor *actor;

    func_800D2498(0x10B, 2 - func_800DA980(0xA4F, 2), 0);
    _subaddieaudioloop_entrypoint_4(arg0, NULL, 1, &D_80800278_chdiggerbossinterior);
    if (arg0->unk70_10 == 2) {
        if (arg0->unk79_4-- == 0) {
            actor = _subaddiefind_entrypoint_2(0x131, sp30);
            if (actor != NULL) {
                do {
                    _sucoaster_entrypoint_5(actor);
                    actor = _subaddiefind_entrypoint_3(0x131, sp30);
                } while (actor != NULL);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossinterior/func_808000F4_chdiggerbossinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossinterior/func_80800178_chdiggerbossinterior.s")
