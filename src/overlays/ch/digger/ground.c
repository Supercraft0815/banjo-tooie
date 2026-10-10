#include "common.h"

OSThread *chdiggerground_entrypoint_0(void)
{
    extern u8 D_80800408_chdiggerground[];

    return (OSThread *) D_80800408_chdiggerground;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/ground/func_8080000C_chdiggerground.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/ground/func_80800070_chdiggerground.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/ground/func_808000C4_chdiggerground.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/ground/func_80800168_chdiggerground.s")

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
