#include "common.h"

OSThread *chballoonburst_entrypoint_0(void)
{
    extern u8 D_80801C40_chballoonburst[];

    return (OSThread *) D_80801C40_chballoonburst;
}

OSThread *chballoonburst_entrypoint_1(void)
{
    extern u8 D_80801C88_chballoonburst[];

    return (OSThread *) D_80801C88_chballoonburst;
}

OSThread *chballoonburst_entrypoint_2(void)
{
    extern u8 D_80801CD0_chballoonburst[];

    return (OSThread *) D_80801CD0_chballoonburst;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800024_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800098_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808001FC_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808003C4_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_8080066C_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800704_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800790_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808008F0_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800970_chballoonburst.s")

s32 func_80800A7C_chballoonburst(void *arg0, s32 *arg1) {
    s32 func_800D0A9C(s32, s32);
    s32 func_800D2054(s32, s32, s32);
    s32 func_800D395C(void);
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    void *func_80100094(void *, u32);
    void *data;
    s32 count;
    s32 result;
    s32 available;
    s32 choice;
    s32 completed;
    s32 flag;
    s32 mode;
    s32 state;

    data = func_80100094(arg0, 0);
    count = ((s32 *)data)[1];
    flag = func_800D0A9C(0x19, 1);
    mode = func_800D395C();
    state = func_800D2054(0, 0x80, count);
    available = (state == 1) && (flag || mode);
    choice = ((count >= 0x32) != 0) && !flag && !mode;
    completed = choice;
    func_800FDC28(0);
    func_800FC6B0((choice || available) ? 0x16 : 0x17);
    *arg1 = 6;
    if (completed) {
        result = 0x10D2;
    } else if (available) {
        result = 0x10C0;
    } else if (func_800D395C() == 0) {
        if (flag != 0) {
            if (state == 0) {
                result = 0x10FA;
            } else {
                result = 0x10F9;
            }
        } else {
            result = 0x10F8;
        }
    } else {
        result = 0xCEB;
        *arg1 = 0x46;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800BE8_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800EDC_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800F4C_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808010D8_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_8080110C_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808011A8_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801254_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801290_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801338_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_8080154C_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808015D4_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808017A4_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801948_chballoonburst.s")

void func_80801A10_chballoonburst(u8 *arg0) {
    s32 func_800BBCB8(u8 *, u8 *, s32, s32, s32 *);
    extern s32 D_80801D28_chballoonburst;
    u8 *temp_a0;

    temp_a0 = arg0 + 4;
    func_800BBCB8(temp_a0, temp_a0, (*(s32 *)((s8 *)(arg0) + (0x38))), 8, &D_80801D28_chballoonburst);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801A50_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801ABC_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801AFC_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801B6C_chballoonburst.s")
