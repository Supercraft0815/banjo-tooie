#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_9.s")

/* extern */

s32 subaddiefind_entrypoint_10(Actor *arg0, s32 arg1, u32 arg2) {
    Actor *subaddiefind_entrypoint_11(s32, u32);
    Actor *temp_v0;

    temp_v0 = subaddiefind_entrypoint_11(arg1, arg2);
    if (temp_v0 != NULL) {
        arg0->unk3C = temp_v0->unk0;
    } else {
        arg0->unk3C = NULL;
    }
    return arg0->unk3C ? 1 : 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_13.s")
