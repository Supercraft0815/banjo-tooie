#include "common.h"

OSThread *chswitch_entrypoint_0(void)
{
    extern u8 D_80800DB0_chswitch[];

    return (OSThread *) D_80800DB0_chswitch;
}

OSThread *chswitch_entrypoint_1(void)
{
    extern u8 D_80800DC4_chswitch[];

    return (OSThread *) D_80800DC4_chswitch;
}

OSThread *chswitch_entrypoint_2(void)
{
    extern u8 D_80800DD8_chswitch[];

    return (OSThread *) D_80800DD8_chswitch;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_80800024_chswitch.s")

/* extern */

void func_808000B8_chswitch(Unk80132ED0 *arg0, s32 arg1) {
    void func_80103110(void *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;

    actor = func_80106790(arg0);
    if (!(actor->unk58 > 0.0f)) {
        actor->unk64_20 = (s32)actor->unk64_20 ^ 1;
        actor->unk58 = 2.0f;
        func_80103110(actor, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_8080012C_chswitch.s")

/* extern */

s32 chswitch_entrypoint_3(void *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    s32 func_80102E08(void *);
    void func_80103110(void *, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800DA298(arg1);
    sp1C = temp_v0;
    (*(s32 *)((s8 *)(arg0) + (0x34))) = arg1;
    func_80103110(arg0, 0);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = 0.75f;
    func_80102E08(arg0);
    return sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_808002B4_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_6.s")

/* extern */

s32 chswitch_entrypoint_7(void *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    s32 func_80102424(void *, s32);
    s32 func_80102E08(void *);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800DA298(arg1);
    sp24 = temp_v0;
    (*(s32 *)((s8 *)(arg0) + (0x34))) = arg1;
    if (temp_v0 != 0) {
        (*(f32 *)((s8 *)(arg0) + (0x54))) = 0.0f;
        func_80102424(arg0, 3);
    } else {
        (*(f32 *)((s8 *)(arg0) + (0x54))) = 0.375f;
        func_80102424(arg0, 1);
    }
    (*(s32 *)((s8 *)(arg0) + (0x2C))) = -1;
    (*(s32 *)((s8 *)(arg0) + (0x50))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x30))) = 0;
    func_80102E08(arg0);
    return sp24;
}

void chswitch_entrypoint_8(s32 *arg0, s32 arg1) {
    arg0[11] = arg1;
}

void chswitch_entrypoint_9(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0x30))) = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_80800694_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_8080093C_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_14.s")
