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

/* extern */

s32 func_808002FC_chtntbox(Actor *arg0, s32 arg1, s32 arg2) {
    void func_8080015C_chtntbox(Actor *, s32);
    void func_808004F8_chtntbox(Actor *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x40:
            func_8080015C_chtntbox(arg0, *data);
            break;
        case 0x3D:
            func_808004F8_chtntbox(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_80800358_chtntbox(Actor *arg0) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    s32 func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF410(s32);
    void func_800DF830(s32);
    s32 func_80101870();
    s32 func_80101970();
    f32 *func_801027F4(Actor *);
    s32 pad;
    f32 *sp28;

    func_80101870();
    if (arg0->unk7C_12) {
        func_80101970(arg0);
        func_800DF830(3);
        func_800DF410(_subaddiefade_entrypoint_0(arg0));
        sp28 = func_801027F4(arg0);
        func_800DE448(arg0->position, sp28, arg0->scale * 0.25f, NULL, func_800D674C(0x6AC));
    }
}

void func_808003F0_chtntbox(s32 arg0, f32 arg1[3]) {
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    extern s32 D_80800A3C_chtntbox;
    s32 temp_s5;
    f32 sp60[3];
    s32 var_s1;

    temp_s5 = func_800B53A4(8);
    for (var_s1 = 0; var_s1 != 8; var_s1++) {
        func_800EEB9C(sp60, (f32) var_s1 * 45.0f, func_800DC178(60.0f, 80.0f));
        func_800EF04C(sp60, arg1);
        func_800BABB8(temp_s5, sp60, arg1, 0.6f, &D_80800A3C_chtntbox);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/box/func_808004F8_chtntbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/box/func_80800624_chtntbox.s")

void func_808007B0_chtntbox(f32 *arg0) {
    s32 func_8001211C();
    void func_800BA22C(s32, s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800A80_chtntbox;
    s32 sp24;

    sp24 = func_800BABB8(0, arg0 + 1, 0, 1.4f, &D_80800A80_chtntbox);
    func_800BA3FC(sp24, (func_8001211C() & 1) ? 0x9E3 : 0x9E2);
    func_800BA22C(sp24, 1);
}

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
