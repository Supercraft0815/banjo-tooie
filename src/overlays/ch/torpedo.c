#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_80800000_chtorpedo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_808000B8_chtorpedo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_808001E0_chtorpedo.s")

void func_80800350_chtorpedo(Actor *arg0) {
    void func_800F1A88(f32 *, f32 *);
    f32 sp18[2];

    func_800F1A88((f32 *)((s8 *)arg0 + 0x28), sp18);
    arg0->rotation[0] = -sp18[0];
    arg0->rotation[1] = sp18[1];
}

/* extern */

void func_80800394_chtorpedo(s32 *arg0) {
    void *func_80100094(s32 *, s32);
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if ((*(s32 (**)(s32, s32, s32))((s8 *)(temp_v0) + (0x2C))) != NULL) {
        (*(s32 (**)(s32, s32, s32))((s8 *)(temp_v0) + (0x2C)))(*arg0, 5, (*(s32 *)((s8 *)(temp_v0) + (0x30))));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_808003DC_chtorpedo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/chtorpedo_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_80800720_chtorpedo.s")

OSThread *chtorpedo_entrypoint_1(void)
{
    extern u8 D_8080095C_chtorpedo[];

    return (OSThread *) D_8080095C_chtorpedo;
}
