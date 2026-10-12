#include "common.h"

OSThread *chweldarbossfireball_entrypoint_0(void)
{
    extern u8 D_80800410_chweldarbossfireball[];

    return (OSThread *) D_80800410_chweldarbossfireball;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fireball/func_8080000C_chweldarbossfireball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fireball/func_808000C4_chweldarbossfireball.s")

void func_8080017C_chweldarbossfireball(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x34)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (*(s32 *)((s8 *)(arg0) + (0x34))) = 0;
    }
}

/* extern */

void func_808001B4_chweldarbossfireball(Actor *arg0, s32 arg1) {
    void* func_800DE448(f32* position, f32* arg1, f32 scale, f32* arg3, s32 arg4);
    void func_800DF830(s32 arg0);
    void func_801018A4(Actor *, s32);
    s32 func_800D674C(s32);
    s32 func_80101970();
    Actor *actor;
    s32 asset;
    actor = arg0;
    func_80101970(actor);
    func_800DF830(2);
    asset = func_800D674C(0x89D);
    func_800DE448(actor->position, actor->rotation, actor->scale, NULL, asset);
    func_801018A4(actor, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fireball/func_80800214_chweldarbossfireball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fireball/func_80800284_chweldarbossfireball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fireball/func_808002E0_chweldarbossfireball.s")

void func_80800404_chweldarbossfireball(s32 arg0) {
}
