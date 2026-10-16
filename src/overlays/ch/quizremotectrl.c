#include "common.h"

void func_80800000_chquizremotectrl(Actor *arg0, s32 arg1) {
    switch (arg1) {
        case 1:
        case 3:
            break;
        case 0:
            arg0->unk54 = 0.0f;
            arg0->unk50 = 0.5f;
            break;
        case 2:
            arg0->unk54 = 1.0f;
            break;
    }
    arg0->unk79_4 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_80800068_chquizremotectrl.s")

/* extern */

void func_8080012C_chquizremotectrl(s32 *arg0) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _capod_entrypoint_21(s32, s32, s32, s32);
    s32 _suquiz_entrypoint_26();
    s32 func_800A5854(s32);
    void func_80800000_chquizremotectrl(Actor *, s32);
    s32 sp1C;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = _suquiz_entrypoint_26();
    sp1C = temp_v0;
    temp_v0_2 = func_800A5854(temp_v0);
    if (temp_v0_2 != 2) {
        if ((temp_v0_2 == 5) || (temp_v0_2 == 6) || (temp_v0_2 == 8)) {
            _capod_entrypoint_13(*arg0, 0, sp1C, 0x834);
        }
    } else {
        _capod_entrypoint_21(*arg0, 0, sp1C, 0x814);
    }
    func_80800000_chquizremotectrl((Actor *)arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_808001BC_chquizremotectrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_808002C8_chquizremotectrl.s")

void func_808003A0_chquizremotectrl(s32 arg0) 
{
}
/* extern */

void func_808003A8_chquizremotectrl(Actor *arg0) {
    void func_800CEA38(s32, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_808001BC_chquizremotectrl(Actor *, s32);
    func_800CEA38(0, 1);
    func_800EFA4C(arg0->position, 0.0f, 0.0f, 0.0f);
    arg0->rotation[2] = 0.0f;
    arg0->rotation[0] = 0.0f;
    arg0->rotation[1] = 0.0f;
    func_808001BC_chquizremotectrl(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_80800410_chquizremotectrl.s")

s32 func_808005E4_chquizremotectrl(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0xB) {
        return 3;
    }
    return 0;
}

OSThread *chquizremotectrl_entrypoint_0(void)
{
    extern u8 D_80800668_chquizremotectrl[];

    return (OSThread *) D_80800668_chquizremotectrl;
}
