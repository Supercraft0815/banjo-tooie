#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80800000_chquiz.s")

f32 func_80800070_chquiz(s32 arg0) {
    extern f32 D_80807004_chquiz[];
    return *(f32 *)((s32)&D_80807004_chquiz + (arg0 * 24));
}

s32 func_8080008C_chquiz(s32 arg0) {
    extern s32 D_80807008_chquiz;
    return *(s32 *)((s32)&D_80807008_chquiz + arg0 * 24);
}

f32 func_808000A8_chquiz(s32 arg0) {
    extern f32 D_8080700C_chquiz[];
    return *(f32 *)((s32)&D_8080700C_chquiz + (arg0 * 24));
}

s32 func_808000C4_chquiz(s32 arg0) {
    extern s32 D_80807010_chquiz;
    return *(s32 *)((s32)&D_80807010_chquiz + arg0 * 24);
}

f32 func_808000E0_chquiz(s32 arg0) {
    extern f32 D_80807014_chquiz[];
    return *(f32 *)((s32)&D_80807014_chquiz + (arg0 * 24));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_808000FC_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80800218_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80800298_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_808002F0_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_8080034C_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_808005C0_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80800728_chquiz.s")

/* extern */

void func_8080085C_chquiz(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _gcnewoption_entrypoint_45(s32);
    s32 func_808005C0_chquiz(Actor *, s32, s32);
    if ((*(u8 *)((s8 *)(func_80100094(arg0, 0U)) + (0x98))) != 0) {
        func_808005C0_chquiz(arg0, _gcnewoption_entrypoint_45((*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (0x94)))), 4);
    }
}

s32 func_808008B0_chquiz(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s8 *)((s8 *)(temp_v0) + (0x99))) = 0;
    return (s32) temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_808008D4_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80800944_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_808009D8_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80800A70_chquiz.s")

s32 func_80800B6C_chquiz(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (0xCC)));
}

s32 func_80800B90_chquiz(s32 arg0) {
    if ((arg0 >= 0x1910) && (arg0 < 0x1A00)) {
        return 0;
    }
    if ((arg0 >= 0x1A00) && (arg0 < 0x1A89)) {
        return 1;
    }
    return 2;
}

void func_80800BD4_chquiz(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (0xD0))) = arg1;
}

s32 func_80800C00_chquiz(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (0xD0)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80800C24_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80800C8C_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80800CE8_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80800DA8_chquiz.s")

s8 func_80800E38_chquiz(s32 arg0, s32 arg1) {
    return (*(s8 *)((s8 *)((arg0 + arg1)) + (0x60)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80800E44_chquiz.s")

/* extern */

void func_80800EF4_chquiz(s16 arg0, s32 arg1, s32 arg2) {
    s32 _cadbfunc_entrypoint_0(s32);
    s32 _cadbfunc_entrypoint_2(s32);
    s32 func_800A5800(s16);
    func_800A5800(arg0);
    _cadbfunc_entrypoint_0(arg1);
    _cadbfunc_entrypoint_2(arg2);
}

/* extern */

void func_80800F34_chquiz(s32 *arg0, void *arg1) {
    s32 _ncpod_entrypoint_12(s32, s32);
    s32 _ncpod_entrypoint_16(s32, s32, s32, s32);
    s32 func_800A89F8();
    s32 func_800A9478(s32);
    s32 func_800F5EF8(s32);
    s32 func_8010FD88(s32);
    s32 func_80110024(s32);
    s32 func_80801170_chquiz(s32 *, void *);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F5EF8(func_800A9478(func_800A89F8()));
    sp1C = temp_v0;
    (*(s8 *)((s8 *)(arg1) + (0x5C))) = 3;
    (*(s16 *)((s8 *)(arg1) + (0x50))) = 0;
    _ncpod_entrypoint_16(temp_v0, *arg0, 0x2C, 0x804);
    _ncpod_entrypoint_12(func_80110024(sp1C), 0);
    func_80801170_chquiz(arg0, arg1);
    func_8010FD88(sp1C);
}

/* extern */

void func_80800FBC_chquiz(s32 arg0) {
    s32 _ncpod_entrypoint_17(s32, s32);
    s32 _ncpod_entrypoint_18(s32);
    s32 func_800A89F8();
    s32 func_800A9478(s32);
    s32 func_800F5EF8(s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F5EF8(func_800A9478(func_800A89F8()));
    sp1C = temp_v0;
    if (_ncpod_entrypoint_18(temp_v0) == 0x2C) {
        _ncpod_entrypoint_17(sp1C, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_8080100C_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801058_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801170_chquiz.s")

int func_808013E0_chquiz(s32 arg0, void *arg1) {
    return *((u8 *)arg1 + 0x5C) == 3 || *((u8 *)arg1 + 0x5C) == 4;
}

s32 func_80801408_chquiz(Actor *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _ncpod_entrypoint_20(s32, s32, s32, s32);
    s32 func_800A89F8();
    s32 func_800A9478(s32);
    s32 func_800F5EF8(s32);
    s32 temp_v0;

    temp_v0 = _ncpod_entrypoint_20(func_800F5EF8(func_800A9478(func_800A89F8())), (s32) arg0->unk0, arg2, arg3 | 0x20);
    (*(s8 *)((s8 *)(arg1) + (0x5C))) = 4;
    return temp_v0;
}

/* extern */

void func_80801470_chquiz(s32 arg0, u8 *arg1) {
    s32 _ncpod_entrypoint_12(s32, s32);
    s32 func_800A89F8();
    s32 func_800A9478(s32);
    s32 func_800F54E4();
    s32 func_800F5EF8(s32);
    s32 func_8010FFB0(s32, u8 *, u8 *);
    s32 func_80110024(s32);
    if ((*(u8 *)((s8 *)(arg1) + (0x5C))) == 4) {
        func_8010FFB0(func_800F5EF8(func_800F54E4()), arg1 + 0x38, arg1 + 0x44);
        (*(u8 *)((s8 *)(arg1) + (0x5C))) = 3U;
        _ncpod_entrypoint_12(func_80110024(func_800F5EF8(func_800A9478(func_800A89F8()))), 0);
    }
}

s32 func_808014F8_chquiz(s32 arg0, s32 arg1) {
    s32 func_800A89F8();
    s32 func_800A9478(s32);
    s32 func_800F5EF8(s32);
    s32 func_80110024(s32);
    s32 _ncpod_entrypoint_15(s32, s32, s32);
    return _ncpod_entrypoint_15(func_80110024(func_800F5EF8(func_800A9478(func_800A89F8()))), arg0, arg1);
}

s32 func_80801544_chquiz(s32 arg0) {
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_8080154C_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801600_chquiz.s")

s32 func_808016F8_chquiz(void *arg0, s32 arg1, f32 arg2) {
    (*(s8 *)((s8 *)(arg0) + (0x90))) = (s8) arg1;
    (*(f32 *)((s8 *)(arg0) + (0x8C))) = arg2;
    (*(f32 *)((s8 *)(arg0) + (0x88))) = arg2;
    (*(f32 *)((s8 *)(arg0) + (0x84))) = arg2;
}

void func_80801710_chquiz(void *arg0) {
    (*(s8 *)((s8 *)(arg0) + (0x90))) = 1;
}

u32 func_8080171C_chquiz(u8 *arg0) {
    return arg0[144];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801724_chquiz.s")

void func_80801758_chquiz(s32 *arg0, s32 arg1) {
    arg0[32] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801760_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801784_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801794_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801930_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801A54_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801B7C_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801C08_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801C7C_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80801CC4_chquiz.s")

OSThread *chquiz_entrypoint_0(void)
{
    extern u8 D_808072CC_chquiz[];

    return (OSThread *) D_808072CC_chquiz;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80802004_chquiz.s")

/* extern */

void func_80802108_chquiz(u8 *arg0, s32 arg1) {
    s32 func_800C8FE0(s32, s32);
    s32 temp_a0;
    s32 var_s0;
    u8 *var_s1;

    var_s0 = 0;
    var_s1 = arg0;
    do {
        temp_a0 = (*(s32 *)((s8 *)(var_s1) + (0x28)));
        if (temp_a0 != 0) {
            func_800C8FE0(temp_a0, arg1);
        }
        var_s0 += 4;
        var_s1 += 4;
    } while (var_s0 != 8);
}

/* extern */

void func_8080216C_chquiz(u8 *arg0) {
    s32 func_800C8B84(s32);
    s32 temp_a0;
    s32 var_s1;
    u8 *var_s0;

    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a0 = (*(s32 *)((s8 *)(var_s0) + (0x28)));
        if (temp_a0 != 0) {
            func_800C8B84(temp_a0);
            (*(s32 *)((s8 *)(var_s0) + (0x28))) = 0;
        }
        var_s1 += 4;
        var_s0 += 4;
    } while (var_s1 != 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_808021C8_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80802250_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80802434_chquiz.s")

void func_80802628_chquiz(Actor *arg0) {
    void func_80108B04(Actor *, u32);
    struct QuizField {
        u16 upper : 9;
        u16 lower : 7;
    };

    ((struct QuizField *)((u8 *)arg0 + 0x76))->upper -= 50;
    func_80108B04(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80802664_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_808029A4_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80802A2C_chquiz.s")

OSThread *chquiz_entrypoint_1(void)
{
    extern u8 D_80807334_chquiz[];

    return (OSThread *) D_80807334_chquiz;
}

/* extern */

void func_80803320_chquiz(s32 arg0, Unk80132ED0 *arg1) {
    s32 func_80102424(Actor *, s32);
    Actor *_subaddiefind_entrypoint_11(s32, s32);
    Actor *sp1C;
    Actor *temp_v0;

    temp_v0 = _subaddiefind_entrypoint_11(0x52B, arg0);
    sp1C = temp_v0;
    func_80102424(temp_v0, 4);
    sp1C->unk3C = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80803368_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80803470_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80803588_chquiz.s")

void func_80803910_chquiz(u8 *arg0) {
    s32 func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x24)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (*(s32 *)((s8 *)(arg0) + (0x24))) = 0;
    }
}

OSThread *chquiz_entrypoint_2(void)
{
    extern u8 D_80807480_chquiz[];

    return (OSThread *) D_80807480_chquiz;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80803954_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_808039D4_chquiz.s")

OSThread *chquiz_entrypoint_3(void)
{
    extern u8 D_808074DC_chquiz[];

    return (OSThread *) D_808074DC_chquiz;
}

s32 func_80803B54_chquiz(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    return _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x4D);
}

void func_80803B88_chquiz(s32 arg0) {
    s32 _chlightfader_entrypoint_1(s32, s32, s32);
    s32 func_800C8A98();
    s32 func_800C8CB8(s32, s32);
    s32 func_800C8D4C(s32, s32 *);
    s32 func_800C8E84(s32, s32 *);
    s32 func_800C8F64(s32, s32);
    extern s32 D_8080755C_chquiz;
    extern s32 D_80807564_chquiz;
    s32 temp_v0;

    temp_v0 = func_800C8A98();
    func_800C8CB8(temp_v0, arg0);
    func_800C8F64(temp_v0, 0xF);
    func_800C8D4C(temp_v0, &D_8080755C_chquiz);
    func_800C8E84(temp_v0, &D_80807564_chquiz);
    _chlightfader_entrypoint_1(temp_v0, 0x40000000, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80803BFC_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_808040D4_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80804110_chquiz.s")

int func_8080414C_chquiz(void *arg0) {
    s32 value = *(s32 *)((s8 *)arg0 + 0x34);
    return value == 0xF || value == 0x10;
}

void func_80804170_chquiz(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    f32 func_800DC178(f32, f32);
    void func_8080100C_chquiz(Actor *, void *, u8);
    void func_80801058_chquiz(Actor *, void *, f32, s8, s8, s8);
    void func_8008F990(void *, f32);
    s32 _chintrotext_entrypoint_1(s32, s32, s32, s32);
    s32 _gcgoto_entrypoint_2(s32, s32, s32);
    s32 _gcnewoption_entrypoint_47(s32);
    s32 _gcstatusDll_entrypoint_17();
    s32 _gcstatusDll_entrypoint_18(void);
    s32 _glglobalsettings_entrypoint_3();
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _suquiz_entrypoint_11(s32);
    s32 _suquiz_entrypoint_18(s32);
    s32 _suquiz_entrypoint_19(s32);
    s32 _suquiz_entrypoint_2();
    s32 _suquiz_entrypoint_20(s32);
    s32 _suquiz_entrypoint_4();
    s32 _suquiz_entrypoint_6();
    f32 _suquiz_entrypoint_8(s32);
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, Unk80132ED0 *);
    s32 func_800D3948();
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800DC128(s32, s32);
    s32 func_800FC660(s32);
    s32 func_80101180(s32, s32, s32);
    s32 func_80102424(Actor *, s32);
    s32 func_8080034C_chquiz(Actor *, s32);
    s32 func_808008B0_chquiz(Actor *);
    s32 func_808008D4_chquiz(Actor *);
    s32 func_80800A70_chquiz(Actor *);
    s32 func_80800B6C_chquiz(Actor *);
    s32 func_80800B90_chquiz(s32);
    s32 func_80801408_chquiz(Actor *, void *, s32, s32);
    s32 func_808014F8_chquiz(s32, s32);
    s32 func_80801544_chquiz(s32);
    s32 func_8080154C_chquiz(void *);
    s32 func_808016F8_chquiz(void *, s32, f32);
    s32 func_80801724_chquiz(void *);
    s32 func_80801760_chquiz(void *, s32, s32);
    s32 func_80801784_chquiz(void *, s32);
    s32 func_80801930_chquiz(void *, s32 *);
    s32 func_80801A54_chquiz(void *, s32 *);
    s32 func_80801C08_chquiz(void *, s32);
    s32 func_80803B54_chquiz(Actor *, s32, s32);
    extern s32 D_80807678_chquiz;
    extern s32 func_8010D5DC;
    void *temp_s1;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    volatile s32 sp5C;
    s32 sp50[3];
    s32 count1;
    s32 sp48;
    s32 sp38[4];
    s32 count2;

    temp_s1 = func_80100094(arg0, 0U);
    switch (arg1) {
    case 0x1:
        func_80801408_chquiz(arg0, temp_s1, 9, 0);
        func_80102424(arg0, 1);
        func_808014F8_chquiz(1, 1);
        goto block_128;
    case 0x2:
        func_80803B54_chquiz(arg0, 0x1460, 4);
        goto block_128;
    case 0x3:
        func_80803B54_chquiz(arg0, 0x1461, 4);
        goto block_128;
    case 0x4:
        func_80803B54_chquiz(arg0, 0x1463, 4);
        func_8080100C_chquiz(arg0, temp_s1, 0U);
        goto block_128;
    case 0x5:
        func_80803B54_chquiz(arg0, 0x1465, 4);
        func_8080100C_chquiz(arg0, temp_s1, 1U);
        goto block_128;
    case 0x6:
        func_80803B54_chquiz(arg0, 0x1464, 4);
        func_8080100C_chquiz(arg0, temp_s1, 2U);
        goto block_128;
    case 0x7:
        if (func_800DA298(0x584) != 0) {
            func_80803B54_chquiz(arg0, 0x146A, 0x46);
        } else {
            func_800DA544(0x584);
            func_80803B54_chquiz(arg0, 0x1466, 4);
        }
        func_80801724_chquiz(temp_s1);
        func_8080100C_chquiz(arg0, temp_s1, 3U);
        func_80102424(arg0, 1);
        _suquiz_entrypoint_18(1);
        _chintrotext_entrypoint_1(0x1A89, 0, 0, 2);
        goto block_128;
    case 0x8:
        if (func_800DA298(0x585) != 0) {
            func_80803B54_chquiz(arg0, 0x146B, 0x46);
        } else {
            func_800DA544(0x585);
            func_80803B54_chquiz(arg0, 0x1467, 4);
        }
        func_80801724_chquiz(temp_s1);
        func_80102424(arg0, 1);
        func_8080100C_chquiz(arg0, temp_s1, 4U);
        _suquiz_entrypoint_18(2);
        _chintrotext_entrypoint_1(0x1A89, 1, 0, 2);
        goto block_128;
    case 0x9:
        func_80102424(arg0, 1);
        func_80803B54_chquiz(arg0, 0x1462, 4);
        func_8080100C_chquiz(arg0, temp_s1, 6U);
        _suquiz_entrypoint_18(3);
        goto block_128;
    case 0xA:
        if (func_800DA298(0x586) != 0) {
            func_80803B54_chquiz(arg0, 0x146C, 0x46);
        } else {
            func_800DA544(0x586);
            func_80803B54_chquiz(arg0, 0x1468, 4);
        }
        func_80801724_chquiz(temp_s1);
        func_80102424(arg0, 1);
        func_8080100C_chquiz(arg0, temp_s1, arg0->actorData[7] == 9 ? 5 : 6);
        _suquiz_entrypoint_18(3);
        _chintrotext_entrypoint_1(0x1A89, 2, 0, 2);
        goto block_128;
    case 0xB:
        if (func_8080154C_chquiz(temp_s1) != 0) {
            if (func_800D3948() != 0) {
                func_80804170_chquiz(arg0, 0x35);
                return;
            }
            func_80804170_chquiz(arg0, 0x1A);
            return;
        }
        func_808008D4_chquiz(arg0);
        func_80800A70_chquiz(arg0);
        func_80102424(arg0, 1);
        switch (func_80800B90_chquiz(func_80800B6C_chquiz(arg0))) {
        case 0:
            func_80804170_chquiz(arg0, 0xD);
            return;
        case 1:
            func_8080100C_chquiz(arg0, temp_s1, 8U);
            func_80803B54_chquiz(arg0, func_800DC128(0x14A1, 0x14A4), 0x46);
            goto block_128;
        }
        break;
    case 0xD:
        if (arg0->unk70_10 != 0xC) {
            sp68 = 2;
        } else {
            sp68 = 1;
        }
        func_8080100C_chquiz(arg0, temp_s1, 9U);
        func_8080034C_chquiz(arg0, 1);
        _suquiz_entrypoint_19(sp68);
        func_808016F8_chquiz(temp_s1, 0, _suquiz_entrypoint_8(sp68));
        func_80101180(0x529, 0x82, 0);
        goto block_128;
    case 0xF:
        sp64 = _suquiz_entrypoint_6();
        func_8080034C_chquiz(arg0, 2);
        func_80801058_chquiz(arg0, temp_s1, 0.5f, 0, (s8) func_80801544_chquiz(sp64), 1);
        if (_suquiz_entrypoint_11(sp64) == 0) {
            *(f32 *)&arg0->actorData[0] = func_800DC178(1.0f, 2.0f);
            arg0->unk64_20 = 0;
            *(f32 *)&arg0->actorData[1] = 1.0f;
        }
        _suquiz_entrypoint_19(3);
        func_808016F8_chquiz(temp_s1, 1, _suquiz_entrypoint_8(3));
        goto block_128;
    case 0x11:
        func_80102424(arg0, 2);
        func_800FC660(0xF);
        func_8080100C_chquiz(arg0, temp_s1, 0xDU);
        if (_suquiz_entrypoint_4() == 2) {
            func_80803B54_chquiz(arg0, func_800DC128(0x1485, 0x148B), 0x46);
            func_8080034C_chquiz(arg0, 0);
        } else {
            func_80803B54_chquiz(arg0, func_800DC128(0x1479, 0x147F), 0x46);
        }
        func_808008B0_chquiz(arg0);
        func_80801760_chquiz(temp_s1, 0x63, _suquiz_entrypoint_6());
        goto block_128;
    case 0x13:
        func_8080100C_chquiz(arg0, temp_s1, 0xBU);
        if (_suquiz_entrypoint_4() == 2) {
            func_80803B54_chquiz(arg0, func_800DC128(0x14B0, 0x14B6), 0x46);
        } else {
            func_80803B54_chquiz(arg0, func_800DC128(0x14AA, 0x14B0), 0x46);
        }
        func_808008B0_chquiz(arg0);
        func_80801760_chquiz(temp_s1, 0x67, _suquiz_entrypoint_6());
        goto block_128;
    case 0xE:
        func_8080100C_chquiz(arg0, temp_s1, 0xAU);
        func_80101180(0x529, 0x85, _suquiz_entrypoint_6());
        _suquiz_entrypoint_19(4);
        func_80101180(0x529, 0x86, 0);
        func_8080034C_chquiz(arg0, 3);
        func_808016F8_chquiz(temp_s1, _gcnewoption_entrypoint_47((*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (0x94)))), _suquiz_entrypoint_8(4));
        goto block_128;
    case 0x10:
        sp60 = _suquiz_entrypoint_6();
        func_8080034C_chquiz(arg0, 4);
        func_80801058_chquiz(arg0, temp_s1, 0.5f, 0, (s8) func_80801544_chquiz(sp60), 1);
        if (_suquiz_entrypoint_11(sp60) == 0) {
            *(f32 *)&arg0->actorData[0] = func_800DC178(1.0f, 2.0f);
            arg0->unk64_20 = 0;
            *(f32 *)&arg0->actorData[1] = 2.0f;
        }
        _suquiz_entrypoint_19(5);
        func_808016F8_chquiz(temp_s1, 1, _suquiz_entrypoint_8(5));
        goto block_128;
    case 0x12:
        func_80102424(arg0, 2);
        func_8080100C_chquiz(arg0, temp_s1, 0xAU);
        func_800FC660(0xF);
        if (_suquiz_entrypoint_4() == 2) {
            func_80803B54_chquiz(arg0, func_800DC128(0x14B6, 0x14BC), 0x46);
        } else {
            func_80803B54_chquiz(arg0, func_800DC128(0x147F, 0x1485), 0x46);
        }
        func_808008B0_chquiz(arg0);
        func_8080034C_chquiz(arg0, 0);
        func_80801760_chquiz(temp_s1, 0x64, _suquiz_entrypoint_6());
        goto block_128;
    case 0x14:
        func_8080100C_chquiz(arg0, temp_s1, 0xBU);
        func_80803B54_chquiz(arg0, func_800DC128(0x14DA, 0x14E0), 0x46);
        func_808008B0_chquiz(arg0);
        func_80801760_chquiz(temp_s1, 0x68, _suquiz_entrypoint_6());
        func_8080034C_chquiz(arg0, 0);
        goto block_128;
    case 0x16:
        func_8080100C_chquiz(arg0, temp_s1, 0xCU);
        if (_suquiz_entrypoint_4() == 2) {
            func_80803B54_chquiz(arg0, func_800DC128(0x14BC, 0x14C2), 0x46);
        } else {
            func_80803B54_chquiz(arg0, func_800DC128(0x146D, 0x1473), 0x46);
        }
        func_8080034C_chquiz(arg0, 0);
        goto block_128;
    case 0x15:
        func_8080100C_chquiz(arg0, temp_s1, 0x11U);
        func_80803B54_chquiz(arg0, func_800DC128(0x149A, 0x14A0), 0x46);
        func_8080034C_chquiz(arg0, 0);
        goto block_128;
    case 0x17:
        func_80102424(arg0, 3);
        func_800FC660(0xE);
        func_808008B0_chquiz(arg0);
        func_8080100C_chquiz(arg0, temp_s1, 0xFU);
        func_80803B54_chquiz(arg0, func_800DC128(0x1473, 0x1479), 0x46);
        func_8080034C_chquiz(arg0, 0);
        func_80801760_chquiz(temp_s1, 0x65, _suquiz_entrypoint_6());
        goto block_128;
    case 0x18:
        func_80102424(arg0, 3);
        func_800FC660(0xE);
        func_808008B0_chquiz(arg0);
        func_8080100C_chquiz(arg0, temp_s1, 0x10U);
        func_80803B54_chquiz(arg0, func_800DC128(0x14A4, 0x14AA), 0x46);
        func_8080034C_chquiz(arg0, 0);
        func_80801760_chquiz(temp_s1, 0x66, _suquiz_entrypoint_6());
        goto block_128;
    case 0x19:
        func_80102424(arg0, 1);
        func_80101180(0x529, 0x84, _suquiz_entrypoint_6());
        func_80101180(0x52E, 0x8C, _suquiz_entrypoint_6());
        func_80801058_chquiz(arg0, temp_s1, 1.0f, 0, (s8) func_80801544_chquiz(_suquiz_entrypoint_6()), 0);
        *(f32 *)&arg0->actorData[0] = 2.0f;
        goto block_128;
    case 0x1A:
        sp5C = 0;
        func_80101180(0x529, 0x3B, 0);
        func_8080100C_chquiz(arg0, temp_s1, 0x12U);
        if (_suquiz_entrypoint_4() == 2) {
            func_80804170_chquiz(arg0, 0x1F);
            if (func_80801784_chquiz(temp_s1, 2) < 0xF) {
                sp5C = 0x1491;
            } else {
                func_808014F8_chquiz(1, 1);
                sp5C = 0x1492;
            }
            func_80803B54_chquiz(arg0, sp5C, 0x4E);
            arg0->unk6C_0 = 2;
            return;
        }
        count1 = func_80801930_chquiz(temp_s1, &sp50[0]);
        if (count1 == 1) {
            arg0->unk6C_0 = sp50[0];
            switch (arg0->unk6C_0) {
            case 1:
                if (_suquiz_entrypoint_4() == 0) {
                    sp5C = 0x148D;
                } else {
                    sp5C = 0x1490;
                }
                break;
            case 0:
                if (_suquiz_entrypoint_4() == 0) {
                    sp5C = 0x148B;
                } else {
                    sp5C = 0x148E;
                }
                break;
            case 2:
                if (_suquiz_entrypoint_4() == 0) {
                    sp5C = 0x148C;
                } else {
                    sp5C = 0x148F;
                }
                break;
            }
        } else {
            if (_suquiz_entrypoint_4() == 0) {
                sp5C = 0x14C7;
            } else {
                sp5C = 0x14C8;
            }
            arg0->unk6C_0 = sp50[func_800DC128(0, count1)];
        }
        func_80803B54_chquiz(arg0, sp5C, 0x46);
        goto block_128;
    case 0x1B:
        func_8080100C_chquiz(arg0, temp_s1, 0x13U);
        goto block_128;
    case 0x1C:
        func_80101180(0x529, 0x87, arg0->unk6C_0);
        _suquiz_entrypoint_20(arg0->unk6C_0);
        goto block_128;
    case 0x1D:
        *(f32 *)&arg0->actorData[0] = 2.0f;
        goto block_128;
    case 0x1E:
        func_8080100C_chquiz(arg0, temp_s1, 0x14U);
        func_80102424(arg0, 4);
        goto block_128;
    case 0x20:
        func_80102424(arg0, 6);
        func_8080100C_chquiz(arg0, temp_s1, 0x19U);
        goto block_128;
    case 0x21:
        _suquiz_entrypoint_18(4);
        _suquiz_entrypoint_2();
        func_80101180(0x4CD, 7, 0);
        func_80801408_chquiz(arg0, func_80100094(arg0, 0U), 0x13, 0x10);
        arg0->unk64_16 = 0;
        goto block_128;
    case 0x22:
        func_80101180(0x529, 0x8A, 2);
        func_80801058_chquiz(arg0, temp_s1, 1.5f, 0, 9, 1);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x14A0, 0xC, arg0->position, 0xC);
        goto block_128;
    case 0x23:
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F990(&D_80807678_chquiz, 500.0f);
        func_8008F904(&func_8010D5DC, arg0->unk0);
        func_80801408_chquiz(arg0, temp_s1, 0x15, 0x40);
        *(f32 *)&arg0->actorData[0] = 0.3f;
        goto block_128;
    case 0x24:
        func_80801058_chquiz(arg0, temp_s1, 2.5f, _glglobalsettings_entrypoint_3() != 0 ? 2 : 0, 7, 1);
        func_808014F8_chquiz(0, 1);
        goto block_128;
    case 0x25:
        _gcgoto_entrypoint_2(0x19C, 0, 0);
        goto block_128;
    case 0x26:
        _suquiz_entrypoint_18(1);
        func_8080100C_chquiz(arg0, temp_s1, 0x21U);
        func_80803B54_chquiz(arg0, 0x14CC, 0x46);
        goto block_128;
    case 0x27:
        _suquiz_entrypoint_18(2);
        func_8080100C_chquiz(arg0, temp_s1, 0x22U);
        func_80803B54_chquiz(arg0, 0x14CD, 0x46);
        goto block_128;
    case 0x28:
        _suquiz_entrypoint_18(3);
        func_8080100C_chquiz(arg0, temp_s1, 0x23U);
        func_80803B54_chquiz(arg0, 0x14CE, 0x46);
        goto block_128;
    case 0x29:
        func_80801724_chquiz(temp_s1);
        func_8080100C_chquiz(arg0, temp_s1, 3U);
        func_80803B54_chquiz(arg0, 0x14D3, 0x46);
        goto block_128;
    case 0x2A:
        func_80801724_chquiz(temp_s1);
        func_8080100C_chquiz(arg0, temp_s1, 3U);
        func_80803B54_chquiz(arg0, 0x14D4, 0x46);
        goto block_128;
    case 0x2B:
        func_80801724_chquiz(temp_s1);
        func_8080100C_chquiz(arg0, temp_s1, 3U);
        func_80803B54_chquiz(arg0, 0x14D5, 0x46);
        goto block_128;
    case 0x2C:
        func_8080100C_chquiz(arg0, temp_s1, 0x24U);
        func_80803B54_chquiz(arg0, 0x14CF, 0x46);
        goto block_128;
    case 0x2D:
        func_8080100C_chquiz(arg0, temp_s1, 0x25U);
        func_80803B54_chquiz(arg0, 0x14D0, 0x46);
        goto block_128;
    case 0x2E:
        func_8080100C_chquiz(arg0, temp_s1, 0x1AU);
        func_80803B54_chquiz(arg0, 0x1469, 0x46);
        goto block_128;
    case 0x2F:
        func_8080100C_chquiz(arg0, temp_s1, 0x1BU);
        func_80803B54_chquiz(arg0, 0x14D6, 0x46);
        goto block_128;
    case 0x30:
        func_8080100C_chquiz(arg0, temp_s1, 0x1CU);
        func_80803B54_chquiz(arg0, 0x14C2, 0x46);
        goto block_128;
    case 0x31:
        func_8080100C_chquiz(arg0, temp_s1, 0x1DU);
        func_80803B54_chquiz(arg0, 0x14C3, 0x46);
        goto block_128;
    case 0x32:
        func_8080100C_chquiz(arg0, temp_s1, 0x1EU);
        func_80803B54_chquiz(arg0, 0x14C4, 0x46);
        goto block_128;
    case 0x33:
        func_8080100C_chquiz(arg0, temp_s1, 0x1FU);
        func_80803B54_chquiz(arg0, 0x14C5, 0x46);
        goto block_128;
    case 0x34:
        func_8080100C_chquiz(arg0, temp_s1, 0x1BU);
        func_80803B54_chquiz(arg0, (f32) _gcstatusDll_entrypoint_17() == 0.0f ? 0x14C6 : 0x14D9, 0x46);
        goto block_128;
    case 0x35:
        func_8080100C_chquiz(arg0, temp_s1, 0x1AU);
        if ((f32) _gcstatusDll_entrypoint_17() != 0.0f) {
            count2 = func_80801A54_chquiz(temp_s1, &sp38[0]);
            if (count2 == 1) {
                arg0->unk6C_0 = sp38[0];
                sp48 = 0x1493;
            } else {
                sp48 = 0x1495;
                arg0->unk6C_0 = sp38[func_800DC128(0, count2)];
            }
        } else {
            arg0->unk6C_0 = func_80801C08_chquiz(temp_s1, _gcstatusDll_entrypoint_18());
            sp48 = 0x1494;
        }
        func_80801758_chquiz(temp_s1, arg0->unk6C_0);
        func_80803B54_chquiz(arg0, sp48, 0x46);
        func_800FC660(0x10);
        goto block_128;
    case 0x36:
        func_8080100C_chquiz(arg0, temp_s1, 0x13U);
        goto block_128;
    case 0x37:
        func_80101180(0x529, 0x87, arg0->unk6C_0);
        goto block_128;
    }
block_128:
    arg0->actorData[7] = arg1;
}

/* extern */

void func_808053BC_chquiz(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    u32 func_8010A828(Actor*, u32);
    s32 _suquiz_entrypoint_0();
    s32 func_80800C24_chquiz(Actor *);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    func_8010A828(arg0, 9U);
    (*(s8 *)((s8 *)(sp1C) + (0x98))) = 0;
    _suquiz_entrypoint_0();
    func_80800C24_chquiz(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80805404_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_80805878_chquiz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quiz/func_808058F0_chquiz.s")

/* extern */

void func_808064F4_chquiz(s32 arg0, s32 arg1) {
    s32 func_800EB854();
    s32 func_801018A4(s32, s32);
    s32 func_808002F0_chquiz(s32, s32);
    if (func_800EB854() == 0) {
        func_801018A4(arg0, arg1);
        return;
    }
    func_808002F0_chquiz(arg0, arg1);
}

OSThread *chquiz_entrypoint_4(void)
{
    extern u8 D_80807684_chquiz[];

    return (OSThread *) D_80807684_chquiz;
}
