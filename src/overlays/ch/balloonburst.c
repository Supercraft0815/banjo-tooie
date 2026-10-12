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
    void *func_80100094(Actor *, u32);
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

/* extern */

void func_80800EDC_chballoonburst(Actor *arg0) {
    s32 _subaddiemulti_entrypoint_3(s32);
    void *func_80100094(Actor *, u32);
    s32 _sumultiscore_entrypoint_3(u8 *);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    u8 *data;

    data = func_80100094(arg0, 0U);
    arg0->unk6C_0 = 5;
    ((s32 *)data)[3] = 1;
    _subaddiemulti_entrypoint_3(0xA);
    _sumultiscore_entrypoint_3(data + 0x30);
    _sumultiscore_entrypoint_4(data + 0x30, 6, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800F4C_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808010D8_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_8080110C_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808011A8_chballoonburst.s")

s32 func_80801254_chballoonburst(u8 *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    if (arg1 == 0x10CF) {
        return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (8))) + 1;
    }
    return 0;
}

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

void func_80801A50_chballoonburst(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80801D5C_chballoonburst;
    s32 sp24;
    f32 *temp_a1;
    s32 temp_v0;

    temp_v0 = func_800B53A4(arg2);
    sp24 = temp_v0;
    func_800BA670(temp_v0, arg1);
    temp_a1 = arg0 + 4;
    func_800BABB8(sp24, temp_a1, temp_a1, (*(f32 *)((s8 *)(arg0) + (0x38))), &D_80801D5C_chballoonburst);
    func_800BA22C(sp24, arg2);
}

void func_80801ABC_chballoonburst(u8 *arg0) {
    s32 func_800BBCB8(u8 *, u8 *, s32, s32, s32 *);
    extern s32 D_80801D98_chballoonburst;
    func_800BBCB8(arg0 + 4, 0, (*(s32 *)((s8 *)(arg0) + (0x38))), 1, &D_80801D98_chballoonburst);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801AFC_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801B6C_chballoonburst.s")
