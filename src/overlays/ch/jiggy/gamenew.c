#include "common.h"

void *func_80100094(Actor *, u32);

OSThread *chjiggygamenew_entrypoint_0(void)
{
    extern u8 D_80803D44_chjiggygamenew[];

    return (OSThread *) D_80803D44_chjiggygamenew;
}

/* extern */

s32 func_8080000C_chjiggygamenew(void) {
    Actor *func_80106790();
    return (*(s32 *)((s8 *)(func_80106790()) + (0x20)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800030_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800158_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_8080020C_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800368_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800424_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_808004E0_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_808006E0_chjiggygamenew.s")

/* extern */

s32 func_808007BC_chjiggygamenew(void) {
    Actor *func_80106790();
    return (*(s32 *)((s8 *)(func_80106790()) + (0x28))) == 5;
}

/* extern */

void func_808007E4_chjiggygamenew(s16 arg0[][12], s32 arg1, s32 arg2) {
    s32 rom_read_word(s32, u32 *);
    u32 sp1C[1];

    rom_read_word(arg1 - 0x50000000, sp1C);
    arg0[arg2][2] = sp1C[0] & 0xFFFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800834_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800AF8_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800B88_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80800CC0_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_808019E0_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80801C20_chjiggygamenew.s")

int func_80801CB0_chjiggygamenew(u8 arg0, s32 arg1, void *arg2) {
    struct Entry { u8 pad0[4]; u16 unk4; u8 pad6[0x12]; };
    u16 temp_v1 = ((struct Entry *)arg2)[arg1].unk4;

    return (temp_v1 == 0x6B54) || (temp_v1 == 0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80801CE8_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80801E4C_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80801EE8_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802030_chjiggygamenew.s")

void func_8080245C_chjiggygamenew(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802464_chjiggygamenew.s")

void func_808024C8_chjiggygamenew(s32 arg0)
{
    func_800E4208();
    func_800E44FC(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_808024F0_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802858_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/chjiggygamenew_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/chjiggygamenew_entrypoint_2.s")

OSThread *chjiggygamenew_entrypoint_3(void)
{
    extern u8 D_80803E50_chjiggygamenew[];

    return (OSThread *) D_80803E50_chjiggygamenew;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802E80_chjiggygamenew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80802F3C_chjiggygamenew.s")

void func_80803564_chjiggygamenew(s32 arg0) 
{
}
/* extern */

void func_8080356C_chjiggygamenew(void) {
    s32 func_80102424(s32, s32);
    Actor *func_80106790();
    func_80102424(func_80106790(), 8);
}

/* extern */

void func_80803598_chjiggygamenew(void) {
    s32 func_80102424(s32, s32);
    Actor *func_80106790();
    func_80102424(func_80106790(), 7);
}

void func_808035C4_chjiggygamenew(Unk80132ED0 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790();
    func_800EE7F8(arg1, (f32 *)((u8 *)func_80100094(func_80106790(arg0), 0U) + 0xC));
}

void func_808035FC_chjiggygamenew(Actor *arg0, f32 *arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    u8 *temp_v0;

    temp_v0 = func_80100094(func_80106790((Unk80132ED0 *)arg0), 0U);
    arg1[0] = *(f32 *)((u8 *)temp_v0 + 0x18);
    arg1[1] = *(f32 *)((u8 *)temp_v0 + 0x1C);
}

s32 func_8080363C_chjiggygamenew(void) {
    Actor *func_80106790();
    return ((u32) (*(u16 *)((s8 *)(func_80106790()) + (0x72))) >> 0xA) == 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_80803668_chjiggygamenew.s")

OSThread *chjiggygamenew_entrypoint_4(void)
{
    extern u8 D_80803EBC_chjiggygamenew[];

    return (OSThread *) D_80803EBC_chjiggygamenew;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/gamenew/func_8080377C_chjiggygamenew.s")

void func_80803928_chjiggygamenew(Unk80132ED0 *arg0, Gfx **arg1) {
    s32 func_800E81D0(void);
    void func_80101870(Actor* arg0, void* arg1);
    Actor *func_80106790(Unk80132ED0 *);
    Gfx *sp18;
    Gfx *temp_v0_2;
    s32 temp_v0;

    temp_v0 = func_800E81D0();
    if (temp_v0 != 0) {
        temp_v0_2 = (*arg1)++;
        temp_v0_2->words.w0 = 0xDB060010;
        sp18 = temp_v0_2;
        sp18->words.w1 = osVirtualToPhysical((u8 *) temp_v0);
        func_80101870(func_80106790(arg0), arg1);
    }
}
