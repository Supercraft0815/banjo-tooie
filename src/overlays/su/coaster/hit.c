#include "common.h"

OSThread *sucoasterhit_entrypoint_0(void)
{
    extern u8 D_80800CB0_sucoasterhit[];

    return (OSThread *) D_80800CB0_sucoasterhit;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/func_8080000C_sucoasterhit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/func_80800114_sucoasterhit.s")

/* extern */

void func_808001C8_sucoasterhit(Unk80132ED0 *arg0, s32 arg1) {
    Actor* func_80106790(Unk80132ED0 *);
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    struct Flags {
        u8 padding[0x78];
        u32 upper : 29;
        u32 flag : 1;
        u32 lower : 2;
    };
    Actor *temp_v0;

    temp_v0 = func_80106790(arg0);
    if (!((struct Flags *)temp_v0)->flag) {
        _sucoaster_entrypoint_9(temp_v0, 0xC, 5);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/func_80800208_sucoasterhit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/func_80800294_sucoasterhit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/func_80800870_sucoasterhit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/sucoasterhit_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/func_80800AEC_sucoasterhit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/hit/sucoasterhit_entrypoint_2.s")
