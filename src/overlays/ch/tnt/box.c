#include "common.h"

OSThread *chtntbox_entrypoint_0(void)
{
    extern u8 D_80800988_chtntbox[];

    return (OSThread *) D_80800988_chtntbox;
}

OSThread *chtntbox_entrypoint_1(void)
{
    extern u8 D_808009D0_chtntbox[];

    return (OSThread *) D_808009D0_chtntbox;
}

void func_80800018_chtntbox(u8 *arg0) {
    struct TntBoxData { u8 pad[0x76]; unsigned short index : 9; unsigned short rest : 7; };

    *(s16 *)(arg0 + 0x7C) = (((struct TntBoxData *)arg0)->index * 10) + 0x320;
    (*(u8 *)((s8 *)(arg0) + (0x95))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x95))) & 0xFFFE) | 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/box/func_80800044_chtntbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/box/func_8080015C_chtntbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/box/func_808002FC_chtntbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/box/func_80800358_chtntbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/box/func_808003F0_chtntbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/box/func_808004F8_chtntbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/box/func_80800624_chtntbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/box/func_808007B0_chtntbox.s")

void func_80800824_chtntbox(s32 arg0, f32 arg1) {
    s32 _chlightfader_entrypoint_1(s32, s32, s32);
    s32 func_800C8A98();
    s32 func_800C8CB8(s32, s32);
    s32 func_800C8E54(s32, f32, f32);
    s32 func_800C8E84(s32, s32 *);
    extern s32 D_80800AC8_chtntbox;
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800C8A98();
    sp1C = temp_v0;
    func_800C8CB8(temp_v0, arg0);
    func_800C8E84(sp1C, &D_80800AC8_chtntbox);
    func_800C8E54(sp1C, arg1 * 400.0f, arg1 * 800.0f);
    _chlightfader_entrypoint_1(sp1C, 0x3FB33333, 5);
}
