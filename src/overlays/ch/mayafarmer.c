#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800000_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_808000B0_chmayafarmer.s")

/* extern */

void func_80800138_chmayafarmer(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800180_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_808001CC_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800228_chmayafarmer.s")

void func_80800520_chmayafarmer(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800540_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_8080085C_chmayafarmer.s")

OSThread *chmayafarmer_entrypoint_0(void)
{
    extern u8 D_80801278_chmayafarmer[];

    return (OSThread *) D_80801278_chmayafarmer;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_808008F8_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_808009A0_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800B9C_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800C58_chmayafarmer.s")

/* extern */

void func_80800D18_chmayafarmer(u8 *arg0) {
    s32 func_800CC63C(s32, s32);
    s32 func_800EE7F8(u8 *, s32);
    u32 temp_v0;

    temp_v0 = (*(u32 *)((s8 *)(arg0) + (0x70)));
    func_800EE7F8(arg0 + 0x18, func_800CC63C((temp_v0 >> 0x19) - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800D60_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80801040_chmayafarmer.s")

void func_808010DC_chmayafarmer(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_808012E8_chmayafarmer;
    _subaddieaudioloop_entrypoint_4(arg0, (f32 *) ((u8 *) arg0 + 4), 1U, &D_808012E8_chmayafarmer);
}

OSThread *chmayafarmer_entrypoint_1(void)
{
    extern u8 D_808012FC_chmayafarmer[];

    return (OSThread *) D_808012FC_chmayafarmer;
}
