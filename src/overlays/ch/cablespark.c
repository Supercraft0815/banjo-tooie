#include "common.h"

OSThread *chcablespark_entrypoint_0(void)
{
    extern ActorData D_80800B88_chcablespark[];

    return (OSThread *) D_80800B88_chcablespark;
}

void func_8080000C_chcablespark(Actor *arg0) {
    extern s32 D_80800B70_chcablespark[6];
    extern u32 D_80800BD0_chcablespark[3];
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    void func_800C8E84(s32 id,u32 *color);
    void func_800C8FE0(s32, s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_80101FDC(Actor *, u32);
    void func_80800668_chcablespark(Actor *);
    int func_808007B8_chcablespark(Actor *);
    s32 func_80800828_chcablespark(void *);
    s32 func_80800970_chcablespark(Actor *);
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    arg0->unk64_24 = 0;
    if (func_80800828_chcablespark(arg0)) {
        arg0->unk64_24 = 1;
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, arg0->unk70_10 == 3, D_80800BD0_chcablespark);
        sp2C = func_800D90A4(&arg0->unk58);
        switch (arg0->unk70_10) {
        case 1:
            if (arg0->unk64_29) {
                if (sp2C && _subaddiejoy_entrypoint_6((u8 *)arg0, 1) == 1) {
                    func_80101FDC(arg0, 2);
                    arg0->unk58 = 0.25f;
                }
            } else if (sp2C && !func_808007B8_chcablespark(arg0)) {
                func_80101FDC(arg0, 3);
                arg0->unk58 = func_800DC178(0.8f, 1.2f);
                func_80800668_chcablespark(arg0);
                func_800C8FE0(arg0->actorData[6], 1);
            }
            break;
        case 2:
            if (sp2C) {
                func_80101FDC(arg0, 3);
                arg0->unk58 = 1.0f;
                func_80800668_chcablespark(arg0);
                func_800C8FE0(arg0->actorData[6], 1);
            }
            break;
        case 3:
            if (arg0->unk64_29) {
                sp28 = 0;
            } else {
                sp28 = func_808007B8_chcablespark(arg0);
            }
            sp24 = func_80800970_chcablespark(arg0);
            func_800C8E84(arg0->actorData[6], (s32 *)((u8 *)D_80800B70_chcablespark + func_800DC298(0.35f) * 12));
            if (sp2C || sp28 || sp24) {
                func_80101FDC(arg0, 1);
                if (arg0->unk64_29) {
                    arg0->unk58 = func_800DC178(1.2f, 1.4f);
                } else {
                    arg0->unk58 = 2.0f;
                }
                func_800C8FE0(arg0->actorData[6], 0);
            }
            break;
        }
    }
}

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
}    typedef struct { u8 pad0[0x18]; u8 unk18; } Objcablespark_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_808002BC_chcablespark(void *arg0) {
    BT_IDO_ONLY(s32 func_800E87E0(s32, u8);) BT_NATIVE_ONLY(void func_800E87E0(u8);)
    u8 temp_a1;

    temp_a1 = (((Objcablespark_arg0 *)arg0)->unk18);
    if (temp_a1 != 0) {
        BT_IDO_ONLY(func_800E87E0(temp_a1 & 0xFF, temp_a1);) BT_NATIVE_ONLY(func_800E87E0((u8)temp_a1);)
    }
}

s32 func_808002E8_chcablespark(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddieDll_entrypoint_4(Actor *, u32);
    s32 func_80800828_chcablespark(void *);
    void func_80800A48_chcablespark(Actor *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_80101010(f32 *);
    f32 offset[3];
    f32 inverseScale;

    switch (arg1) {
        case 0xA:
            arg0->unk64_24 = func_80800828_chcablespark(arg0);
            if (arg0->unk74_7 == 0x35) {
                arg0->unk64_24 = 0;
                if (func_80800828_chcablespark(arg0)) {
                    _subaddieDll_entrypoint_4(arg0, 1);
                }
            }
            break;
        case 0x95:
            func_80800A48_chcablespark(arg0);
            break;
        case 0x97:
            inverseScale = 1.0f / arg0->scale;
            func_800EEB9C(offset, arg0->rotation[1], 150.0f * inverseScale);
            offset[1] += 175.0f * inverseScale;
            func_80101010(offset);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080040C_chcablespark(Actor *arg0, s32 arg1) {
    void *func_800D674C(s32);
    s32 func_800DC128(s32, s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    s32 func_800DF350(void);
    void func_800DF47C(s32, BtIntPtr);
    void func_800DF744(s32, s32);
    void func_800DF830(s32);
    void func_800E3A58(f32 *);
    s32 func_800E88E4(u8);
    s32 func_801015D0(Actor *);
    BtIntPtr func_8010347C(Unk80132ED0 *);
    void func_80800590_chcablespark(Actor *, f32 *);
    s32 func_80800828_chcablespark(void *);
    f32 sp34[3];

    arg0->unk64_20 = (s32)arg0->unk64_20 ^ 1;
    func_800DF830(1);
    func_800DF744(4, func_80800828_chcablespark(arg0) ? 1 : 2);
    func_800DE448(arg0->position, arg0->rotation, arg0->scale, 0, func_800D674C(0x6BC));
    arg0->unk7C_12 = func_800DF350();
    if (arg0->unk70_10 == 3) {
        func_80800590_chcablespark(arg0, sp34);
        func_800DF744(1, func_800DC128(0, 4));
        func_800DF47C(func_801015D0, arg0);
        func_800DE448(arg0->position, sp34, arg0->scale, 0, func_8010347C(arg0->unk0));
        if (func_800E88E4(((u8 *)arg0->actorData)[0]) == 1 && arg0->unk64_20 && arg0->unk7C_12) {
            func_800E3A58(sp34);
            func_800DF830(0);
            func_800DE448(arg0->position, sp34, arg0->scale, 0, func_800D674C(0x6BB));
        }
    }
}

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

void func_80800668_chcablespark(Actor *arg0) {
    f32 func_800136E4(f32);
    void func_800E3980(f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 mlAbsF(f32);
    f32 sp2C[3];
    f32 sp24[2];
    f32 sp20;
    f32 sp1C;
    func_800E3980(sp2C);
    func_800F18FC(arg0->position, sp2C, &sp24[0]);
    sp24[1] = func_800F1DCC(arg0->rotation[1], sp24[1]);
    sp24[0] = -sp24[0];
    sp1C = mlAbsF(sp24[1]) > 45.0f ? 0 : (sp24[1] > 0.0f ? 15.0f : -15.0f);
    sp20 = mlAbsF(sp24[0]) > 45.0f ? 0 : (sp24[0] < 0.0f ? 15.0f : -15.0f);
    ((f32 *)arg0->actorData)[4] = func_800136E4(arg0->rotation[1] + sp1C);
    ((f32 *)arg0->actorData)[5] = func_800136E4(sp20);
}

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
    void *func_800BEF00(f32 *a,f32 *b,f32 *out,u32 flags);
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
    BtUIntPtr func_800F54E4(void);
    BT_IDO_ONLY(f32) BT_NATIVE_ONLY(s32) func_800F57F0(BtIntPtr, f32 *);
    s32 func_800F6478(BtIntPtr);
    s32 func_800F7B9C(BtIntPtr, s32);
    f32 sp3C[3];
    f32 temp_f0;
    f32 sp2C[3];
    f32 sp28;
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    temp_v0 = func_800F54E4();
    sp24 = temp_v0;
    if (func_800F6478(temp_v0) == 0) {
        return 0;
    }
    sp28 = BT_IDO_ONLY(func_800F57F0(sp24, sp2C)) BT_NATIVE_ONLY(((union { s32 i; f32 f; }){ .i = func_800F57F0(sp24, sp2C) }).f);
    func_800EE7F8(sp3C, arg0->position);
    func_800EF1B8(sp3C, arg0->rotation[1], arg0->scale * 40.0f);
    temp_f0 = arg0->scale * 50.0f;
    if ((func_800F0008(sp3C, temp_f0, sp2C, sp28) != 0) && (func_800F7B9C(sp24, 0x51) == 2)) {
        _chelectricfence_entrypoint_1(arg0, sp2C);
        return 1;
    }
    return 0;
}
struct SparkRange { f32 values[2]; };
void func_80800A48_chcablespark(Actor *arg0) {
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32[3]);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32 id,u32 *color);
    void func_800C8F64(s32, s32);
    void func_800C8FE0(s32, s32);
    s8 func_800E8714(s32);
    void func_800E8830(u8, f32[3]);
    s32 func_80800828_chcablespark(void *);
    extern s32 D_80800B70_chcablespark[6];

    extern struct SparkRange D_80800BDC_chcablespark;
    f32 sp28[2];

    *(struct SparkRange *)sp28 = D_80800BDC_chcablespark;
    sp28[0] *= arg0->scale;
    sp28[1] *= arg0->scale;
    arg0->actorData[6] = func_800C8A98();
    func_800C8E84(arg0->actorData[6], D_80800B70_chcablespark);
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
/* data_to_c.py: from asm/data/overlays/ch/cablespark.data.s */
void func_80105834(Actor*);
void func_80107C2C();
s32 D_80800B70_chcablespark[6] BT_DATA(4, overlays_ch_cablespark, 0x0) = { 192, 192, 255, 128, 128, 160 };
ActorData D_80800B88_chcablespark [1] BT_DATA(4, overlays_ch_cablespark, 0x18) = { { 676, 829, 1721, 1, 0, (void (*)(struct Actor *))func_8080000C_chcablespark, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8080040C_chcablespark, 117964800, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_808002BC_chcablespark, 0, 0, 0, (void (*)(struct Actor *))func_8080024C_chcablespark, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 25603, (void (*)(struct Actor *, long, long))func_808002E8_chcablespark, 0 } };
u32 D_80800BD0_chcablespark[3] BT_DATA(4, overlays_ch_cablespark, 0x60) = { 0x13050C, 0xD010C, 0x1190000 };
struct SparkRange D_80800BDC_chcablespark BT_DATA(4, overlays_ch_cablespark, 0x6C) = { { 250.0f, 400.0f } };
