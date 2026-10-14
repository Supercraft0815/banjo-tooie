#include "core2/1ED8C80.h"

void func_800FF390(void) {
    s32 func_80104170();
    s32 func_80104350();
    s32 func_80105410();
    s32 func_80105C20();
    s32 func_801065E0();
    s32 func_80106A20();
    s32 func_80106DF0();
    s32 func_80107BB0();
    extern s32 D_80135A50;
    D_80135A50 = 0;
    func_801065E0();
    func_80104170();
    func_80104350();
    func_80105410();
    func_80105C20();
    func_80106A20();
    func_80106DF0();
    func_80107BB0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF3EC.s")

/* extern */

void func_800FF44C(void) {
    s32 func_800FF3EC(Actor *);
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    s32 sp24;
    s32 var_a0;

    func_80101238(0x93, 0);
    if ((var_a0 = func_801067C4(&sp24)) != 0) {
        do {
            func_800FF3EC((Actor *)var_a0);
        } while ((var_a0 = func_8010682C(&sp24)) != 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF4A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF62C.s")

/* extern */

void func_800FFA3C(Actor *arg0) {
    void func_800EBFF4(void *arg0);
    s32 func_800FF3EC(Actor *);
    s32 func_800FF4A4(Actor *);
    s32 func_801066C0(u32);
    Unk80132ED0 *sp1C = arg0->unk0;
    func_800FF3EC(arg0);
    func_800FF4A4(arg0);
    func_801066C0((u32) (*(u16 *)((s8 *)(sp1C) + (0x1A))) >> 5);
    func_800EBFF4(sp1C);
}

void func_800FFA88(Unk80132ED0* a0)
{
    func_800FFAB0(func_80106790(a0));
}

void func_800FFAB0(Actor *arg0) {
    extern s32 D_80135A50;
    Actor *temp_v0;
    s32 temp_a2;
    struct ActorFlags {
        u8 prefix[0x74];
        u32 pad74_25 : 7;
        u32 flag74_24 : 1;
        u32 pad74_0 : 24;
        u32 pad78_3 : 29;
        u32 flag78_2 : 1;
        u32 pad78_0 : 2;
    } *flags = (void *)arg0;

    arg0->unk64_17 = 1;
    D_80135A50 += 1;
    temp_a2 = arg0->pad40;
    if ((temp_a2 != 0) && (arg0->unk6C_9 != 0x243)) {
        temp_v0 = func_80106790((Unk80132ED0 *) temp_a2);
        temp_v0->unk64_17 = 1;
        arg0->pad40 = 0;
        temp_v0->pad40 = 0;
        D_80135A50 += 1;
    }
    flags->flag78_2 = 0;
    flags->flag74_24 = flags->flag78_2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFB74.s")

void func_800FFBE4(void) {
}

void func_800FFC3C(void);

void func_800FFBEC()
{
    func_800FFC3C();
    func_8010DEFC();
}

void func_800FFC14()
{
    func_800FFC3C();
    func_8010DEFC();
}

void func_800FFC3C(void) {
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    s32 var_s0;
    s32 sp20[1];

    if ((var_s0 = func_801067C4(sp20)) != 0) {
        do {
            *(u8 *)((s8 *)var_s0 + 0x7E) &= 0xFFEF;
        } while ((var_s0 = func_8010682C(sp20)) != 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFD10.s")

/* extern */

void func_800FFDBC(void) {
    s32 func_8010381C(s32);
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    s32 var_a0;
    s32 sp20;

    if ((var_a0 = func_801067C4(&sp20)) != 0) {
        do {
            func_8010381C(var_a0);
        } while ((var_a0 = func_8010682C(&sp20)) != 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFE08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFECC.s")

u32* func_80100074(Actor* a0, u32 a1, u32 a2)
{
    return func_800FFECC(a0,a1,a2);
}

void *func_80100094(Actor *arg0, u32 arg1) {
    s32 func_8001B798(s16);
    s16 temp;
    s32 result;
    temp = *(s16 *)((u8 *)arg0 + 0x82 + arg1 * 2);
    result = 0;
    if (temp != 0) {
        return (void *) func_8001B798(temp);
    }
    return (void *) result;
}

s32 func_801000D8(Actor *arg0, s32 arg1, s32 arg2) {
    if (func_80100094(arg0, (u32) arg1) == NULL) {
        func_80100074(arg0, (u32) arg1, (u32) arg2);
    }
    return func_80100094(arg0, (u32) arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_80100120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_801001D8.s")

int func_80100230(Actor *arg0, f32 *arg1) {
    f32 func_800EEB40(f32 *, f32 *);
    struct {
        u8 padding[0x7C];
        u32 radius : 16;
        u32 pad7E_15 : 1;
        u32 enabled : 1;
        u32 pad7E_0 : 14;
    } *range;
    void *data;
    f32 distance;

    data = arg0;
    range = data;
    if (!range->enabled) {
        return 0;
    }
    if (range->radius == 0) {
        return 1;
    }
    distance = func_800EEB40(arg1, arg0->position);
    return (f32)(s32)(range->radius * range->radius) < distance;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_801002C0.s")

void *func_80100368(void *arg0) {
    return (*(void *(**)())((s8 *)(arg0) + (0x10)))();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_8010038C.s")
