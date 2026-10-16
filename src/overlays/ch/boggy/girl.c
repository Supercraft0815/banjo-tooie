#include "ch/boggy/girl.h"

OSThread *chboggygirl_entrypoint_0(void)
{
    extern u8 D_80800CF0_chboggygirl[];

    return (OSThread *) D_80800CF0_chboggygirl;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_8080000C_chboggygirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_808000A8_chboggygirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_80800508_chboggygirl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_80800708_chboggygirl.s")

void func_8080091C_chboggygirl(Actor* arg0)
{
    func_80800B28_chboggygirl(arg0);
}

void func_8080093C_chboggygirl(Actor *arg0) {
    s16 _glsplinefind_entrypoint_0(u32, f32 *);
    void func_800EE940(void *, f32 *);
    void *sp24;
    f32 sp18[3];

    sp24 = func_80100094(arg0, 0U);
    ((s16 *)sp24)[3] = _glsplinefind_entrypoint_0(0x3A1U, sp18);
    func_800EE940(sp24, sp18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/girl/func_8080097C_chboggygirl.s")

void func_80800A4C_chboggygirl(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800DA980(s32, s32);
    struct Flags { u8 pad[0x16]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    struct Flags *data;
    s32 dialog;

    dialog = (func_800DA980(0x8C, 3) == 3) ? 0x1099 : 0x1098;
    _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 0xF, arg0->position, 0x3C);
    data = func_80100094(arg0, 0);
    data->flag = 1;
}

/* extern */

void func_80800ABC_chboggygirl(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x3C);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x3E8);
    }
}

void func_80800B28_chboggygirl(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
/* extern */

s32 func_80800B5C_chboggygirl(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F640C(s32, s32);
    s32 func_800F64A4(s32, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F64A4(temp_v0, 0x201) == 0) {
        return 0;
    }
    return func_800F640C(sp1C, arg0) > 0;
}
