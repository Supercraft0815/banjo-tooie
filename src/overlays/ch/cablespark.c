#include "common.h"

OSThread *chcablespark_entrypoint_0(void)
{
    extern u8 D_80800B88_chcablespark[];

    return (OSThread *) D_80800B88_chcablespark;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_8080000C_chcablespark.s")

/* extern */

void func_8080024C_chcablespark(Actor *arg0) {
    void _subaddieDll_entrypoint_4(Actor *, u32);
    f32 func_800DC178(f32, f32);
    s32 func_80800828_chcablespark(void *);
    void func_808008BC_chcablespark(void *);
    ((s8 *)arg0->actorData)[0] = 0;
    arg0->unk58 = func_800DC178(0.0f, 2.0f);
    if ((arg0->unk74_7 == 0x35) && (func_80800828_chcablespark(arg0) != 0)) {
        _subaddieDll_entrypoint_4(arg0, 1);
    }
    func_808008BC_chcablespark(arg0);
}

/* extern */

void func_808002BC_chcablespark(void *arg0) {
    s32 func_800E87E0(s32, u8);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x18)));
    if (temp_a1 != 0) {
        func_800E87E0(temp_a1 & 0xFF, temp_a1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_808002E8_chcablespark.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_8080040C_chcablespark.s")

void func_80800590_chcablespark(Actor *arg0, f32 *arg1) {
    f32 func_800136E4(f32);
    void func_800E3980(f32 *);
    void func_800EE97C(f32 *, f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    s32 func_800F1884(f32 *, f32 *);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;

    sp24 = 0.0f;
    func_800E3980(sp4C);
    func_800EFB24(sp40, arg0->position, sp4C);
    func_800EEC30(sp34, ((f32 *)arg0->actorData)[5], ((f32 *)arg0->actorData)[4], 100.0f);
    if (arg0->position[1] < sp4C[1]) {
        func_800EE97C(sp28, sp34, sp40);
    } else {
        func_800EE97C(sp28, sp40, sp34);
    }
    func_800F1884(sp28, &sp24);
    arg1[0] = ((f32 *)arg0->actorData)[5];
    arg1[1] = ((f32 *)arg0->actorData)[4];
    arg1[2] = func_800136E4(sp24 - 90.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablespark/func_80800668_chcablespark.s")

/* extern */

int func_808007B8_chcablespark(Actor *arg0) {
    f32 func_800EEB40(f32 *, f32 *);
    void func_8010D254(s32 *);
    union {
        s32 words[3];
        f32 floats[3];
    } sp1C;

    if (arg0->unk74_7 == 0x35) {
        return 0;
    }
    func_8010D254(sp1C.words);
    return func_800EEB40(arg0->position, sp1C.floats) > 1000000.0f;
}

s32 func_80800828_chcablespark(void *arg0) {
    s32 func_800DA298(s32);

    switch (((Actor *)arg0)->unk74_7 - 0x32) {
        case 1:
            if (func_800DA298(0xEB) == 0) {
                return 0;
            }
            break;
        case 2:
            if (func_800DA298(0xEC) == 0) {
                return 0;
            }
            break;
        case 3:
            if (func_800DA298(0x18C) == 0) {
                return 0;
            }
            break;
    }
    return 1;
}

/* extern */

void func_808008BC_chcablespark(void *arg0) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80103014(u8 *);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_800EE7F8(sp3C, ((Actor *)arg0)->position);
    func_800EF1B8(sp3C, ((Actor *)arg0)->rotation[1], 100.0f);
    func_800EE7F8(sp30, ((Actor *)arg0)->position);
    func_800EF1B8(sp30, ((Actor *)arg0)->rotation[1], -50.0f);
    if (func_800BEF00(sp3C, sp30, sp24, ((Actor *)arg0)->unk14) != 0) {
        func_800EE7F8(((Actor *)arg0)->position, sp30);
        func_800EF1B8(((Actor *)arg0)->position, ((Actor *)arg0)->rotation[1], ((Actor *)arg0)->scale * 5.0f);
        func_80103014(arg0);
    }
}

/* extern */

s32 func_80800970_chcablespark(Actor *arg0) {
    void _chelectricfence_entrypoint_1(Actor *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    s32 func_800F0008(f32[3], f32, f32[3], f32);
    u32 func_800F54E4(void);
    f32 func_800F57F0(s32, f32 *);
    s32 func_800F6478(s32);
    s32 func_800F7B9C(s32, s32);
    f32 sp3C[3];
    f32 temp_f0;
    f32 sp2C[3];
    f32 sp28;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp24 = temp_v0;
    if (func_800F6478(temp_v0) == 0) {
        return 0;
    }
    sp28 = func_800F57F0(sp24, sp2C);
    func_800EE7F8(sp3C, arg0->position);
    func_800EF1B8(sp3C, arg0->rotation[1], arg0->scale * 40.0f);
    temp_f0 = arg0->scale * 50.0f;
    if ((func_800F0008(sp3C, temp_f0, sp2C, sp28) != 0) && (func_800F7B9C(sp24, 0x51) == 2)) {
        _chelectricfence_entrypoint_1(arg0, sp2C);
        return 1;
    }
    return 0;
}

void func_80800A48_chcablespark(Actor *arg0) {
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32[3]);
    void func_800C8D4C(s32, f32 *);
    s32 func_800C8E84(s32, s32 *);
    void func_800C8F64(s32, s32);
    void func_800C8FE0(s32, s32);
    s8 func_800E8714(s32);
    void func_800E8830(u8, f32[3]);
    s32 func_80800828_chcablespark(void *);
    extern s32 D_80800B70_chcablespark;
    struct SparkRange { f32 values[2]; };
    extern struct SparkRange D_80800BDC_chcablespark;
    f32 sp28[2];

    *(struct SparkRange *)sp28 = D_80800BDC_chcablespark;
    sp28[0] *= arg0->scale;
    sp28[1] *= arg0->scale;
    arg0->actorData[6] = func_800C8A98();
    func_800C8E84(arg0->actorData[6], &D_80800B70_chcablespark);
    func_800C8CB8(arg0->actorData[6], arg0->position);
    func_800C8F64(arg0->actorData[6], 0xB);
    func_800C8D4C(arg0->actorData[6], sp28);
    func_800C8FE0(arg0->actorData[6], arg0->unk70_10 == 3);
    ((u8 *)arg0->actorData)[0] = func_800E8714(1);
    func_800E8830(((u8 *)arg0->actorData)[0], arg0->position);
    arg0->unk64_24 = func_80800828_chcablespark(arg0);
    if (arg0->unk74_7 == 0x35) {
        arg0->unk64_24 = 0;
    }
}
