#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/timetable/func_80800000_chtimetable.s")

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
