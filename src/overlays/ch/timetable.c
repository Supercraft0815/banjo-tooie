#include "common.h"

void func_80800000_chtimetable(s32 arg0, s32 arg1, f32 *arg2) {
    Prop* _gccubesearch_entrypoint_1(u32, f32[3]);
    void _gspropctrl_entrypoint_11(Prop*, f32[3]);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(arg1 + 0x51F, arg0 + 4), arg2);
    arg2[2] = -1100.0f;
    arg2[1] = -50.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_80800058_chtimetable.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_808000B0_chtimetable.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_8080016C_chtimetable.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_8080025C_chtimetable.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_808002D4_chtimetable.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_80800308_chtimetable.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_80800364_chtimetable.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_80800404_chtimetable.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_808005B8_chtimetable.s")

OSThread *chtimetable_entrypoint_0(void)
{
    extern u8 D_808007CC_chtimetable[];

    return (OSThread *) D_808007CC_chtimetable;
}
