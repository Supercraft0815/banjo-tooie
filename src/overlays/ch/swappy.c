#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_80800000_chswappy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_808000B0_chswappy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_80800108_chswappy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_80800234_chswappy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_80800300_chswappy.s")

/* extern */

void func_808003DC_chswappy(Actor *arg0, s32 arg1) {
    union SwappyActorView {
        Actor actor;
        struct {
            u8 padding[0x7C];
            u32 pad7C_15 : 17;
            u32 unk7C_14 : 1;
            u32 pad7C_13 : 1;
            u32 unk7C_12 : 1;
            u32 unk7C_0 : 12;
        } flags;
    };
    void func_800E3980(f32 *);
    s32 func_800E3E8C(f32 *, f32);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800F8B88();
    void func_8010A73C(Actor *, s32);
    s32 sp34;
    f32 sp28[3];
    f32 *sp20[2];

    sp20[1] = arg0->position;
    sp34 = func_800E3E8C(sp20[1], 300.0f);
    func_8010A73C(arg0, arg1);
    if ((sp34 != 0) && (func_800F8B88() == 2)) {
        func_800E3980(sp28);
        if (func_800EEB40(sp20[1], sp28) < 6250000.0f) {
            arg0->unk7C_12 = 1;
        }
        ((union SwappyActorView *)(void *)arg0)->flags.unk7C_14 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/chswappy_entrypoint_0.s")

OSThread *chswappy_entrypoint_1(void)
{
    extern u8 D_808006D4_chswappy[];

    return (OSThread *) D_808006D4_chswappy;
}
