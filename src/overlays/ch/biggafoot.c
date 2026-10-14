#include "ch/biggafoot.h"

OSThread *chbiggafoot_entrypoint_0(void)
{
    extern u8 D_80801094_chbiggafoot[];

    return (OSThread *) D_80801094_chbiggafoot;
}

OSThread *chbiggafoot_entrypoint_1(void)
{
    extern u8 D_808010DC_chbiggafoot[];

    return (OSThread *) D_808010DC_chbiggafoot;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800018_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800100_chbiggafoot.s")

void func_808004B0_chbiggafoot(s32 arg0)
{
    func_800DA524(FLAG2_6CD_UNK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_808004D4_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800840_chbiggafoot.s")

void func_808008D4_chbiggafoot(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    extern s32 D_80801198_chbiggafoot;
    _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80801198_chbiggafoot);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_808008FC_chbiggafoot.s")

/* extern */

void func_80800980_chbiggafoot(void *arg0) {
    s32 func_800F54E4();
    s32 func_800F5A00(s32, s32 *);
    s32 func_800F6438(s32);
    s32 func_80102BF8(void *, s32, s32, s32);
    f32 func_80102D78(void *, s32 *);
    s32 sp1C[3];

    if (func_800F6438(func_800F54E4()) != 0) {
        func_800F5A00(func_800F54E4(), sp1C);
        (*(f32 *)((s8 *)(arg0) + (0x54))) = func_80102D78(arg0, sp1C);
        func_80102BF8(arg0, 0x3E19999A, 0x40A00000, 0x42F00000);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_808009EC_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800A9C_chbiggafoot.s")

void func_80800BA4_chbiggafoot(Actor *arg0) { void func_80102424(Actor *, s32); void func_80800CDC_chbiggafoot(Actor *); extern s16 D_80801030_chbiggafoot; func_80102424(arg0, 6); arg0->unk3C = NULL; arg0->unk6C_0 = 0; ((f32 *)arg0->actorData)[3] = 1.0f; _capod_entrypoint_20(arg0->unk0, D_80801030_chbiggafoot, 0x10); func_80800CDC_chbiggafoot(arg0); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800C04_chbiggafoot.s")

void func_80800CDC_chbiggafoot(Actor *arg0) {
    void func_800C3BDC(u8 id);
    u8 func_800C4350(s32, f32[3], s32 *);
    void func_800C32C4(u8, s32);
    extern u8 D_80801038_chbiggafoot[];
    extern s32 D_80801224_chbiggafoot;
    u8 sp1F;

    sp1F = func_800C4350(0, NULL, &D_80801224_chbiggafoot);
    func_800C32C4(sp1F, D_80801038_chbiggafoot[arg0->unk6C_0]);
    func_800C3BDC(sp1F);
}

void func_80800D38_chbiggafoot(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, 1.4f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800D5C_chbiggafoot.s")

/* extern */

s32 func_80800E2C_chbiggafoot(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chexploder_entrypoint_6(s32, s32, s32);
    s32 _chexploder_entrypoint_9(s32, s32, s32);
    s32 func_80101080();
    s32 func_80106790(s32);
    s32 sp1C;
    s32 temp_v0;

    if (arg1 == 0x90) {
        temp_v0 = func_80106790(func_80101080());
        sp1C = temp_v0;
        _chexploder_entrypoint_9(temp_v0, 1, 2);
        _chexploder_entrypoint_6(sp1C, 0x43C80000, 0x43FA0000);
    } else {
        return 0;
    }
    return 1;
}

void func_80800E98_chbiggafoot(u8 *arg0) {
    s32 func_800BBCB8(u8 *, s32, s32, s32, s32 *);
    extern s32 D_80801244_chbiggafoot;
    func_800BBCB8(arg0 + 4, 0, (*(s32 *)((s8 *)(arg0) + (0x38))), 1, &D_80801244_chbiggafoot);
}
