#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_0.s")

/* extern */

void sucoaster_entrypoint_1(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_80802728_sucoaster(Actor *, u8 *);
    func_80802728_sucoaster(arg0, func_80100094(arg0, 0U));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_8080027C_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80800C68_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_808015F8_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_17.s")

void sucoaster_entrypoint_18(s32 arg0)
{
    func_80105230(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_19.s")

void sucoaster_entrypoint_20()
{
    func_80101870();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_21.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_22.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_8080202C_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_808020B8_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802130_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_808021A8_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802260_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_8080230C_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802384_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802400_sucoaster.s")

/* extern */

s32 func_80802550_sucoaster(s32 arg0, s32 arg1) {
    s32 func_8080202C_sucoaster();
    s32 func_80802594_sucoaster(s32, s32);
    if (func_8080202C_sucoaster() != 0) {
        return func_80802594_sucoaster(arg0, arg1) == 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802594_sucoaster.s")

/* extern */

f32 func_8080264C_sucoaster(void *arg0, s32 arg1) {
    f32 func_8010CD50(void *, s32);
    s32 func_80802760_sucoaster(s32);
    s32 temp_v0;

    temp_v0 = func_80802760_sucoaster(arg1);
    if (temp_v0 == -1) {
        return (*(f32 *)((s8 *)(arg0) + (0x48)));
    }
    return func_8010CD50(arg0, temp_v0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802690_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802728_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802760_sucoaster.s")
