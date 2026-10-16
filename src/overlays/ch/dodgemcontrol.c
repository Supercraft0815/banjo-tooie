#include "common.h"

OSThread *chdodgemcontrol_entrypoint_0(void)
{
    extern u8 D_80804DB4_chdodgemcontrol[];

    return (OSThread *) D_80804DB4_chdodgemcontrol;
}

Actor *func_8080000C_chdodgemcontrol(Actor *arg0,s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    return func_80106790(((Unk80132ED0 **)func_80100094(arg0,0))[arg1]);
}

/* extern */

void func_80800044_chdodgemcontrol(f32 *arg0) {
    void func_800906B0(f32 *);
    void func_800906DC(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp24[3];
    f32 sp18[3];

    func_800EFA4C(sp24, 0.0f, 20.0f, 5.0f);
    func_800EF934(sp24, sp24, arg0[18]);
    func_800EF04C(sp24, arg0 + 1);
    func_800EE7F8(sp18, arg0 + 17);
    func_800906B0(sp24);
    func_800906DC(sp18);
}

s32 func_808000B8_chdodgemcontrol(s32 arg0) {
    struct DodgemValues { s32 values[4]; };
    extern struct DodgemValues D_80804DFC_chdodgemcontrol;
    struct DodgemValues sp18;
    void func_800904C8(s32);
    sp18 = D_80804DFC_chdodgemcontrol;
    func_800904C8(sp18.values[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080010C_chdodgemcontrol.s")

/* extern */

int func_80800350_chdodgemcontrol(void) {
    f32 func_800DC0C0(void);
    f32 temp_f0;

    temp_f0 = func_800DC0C0();
    if (temp_f0 < 0.5f) {
        return 0;
    }
    if (temp_f0 < 0.8333333f) {
        return 1;
    }
    return 2;
}

/* extern */

void func_808003B0_chdodgemcontrol(void *arg0) {
    f32 func_800DC178(f32, f32);
    (*(f32 *)((s8 *)(arg0) + (0))) = func_800DC178(-645.0f, 645.0f);
    (*(f32 *)((s8 *)(arg0) + (4))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800DC178(-645.0f, 645.0f);
}

/* extern */

s32 func_8080040C_chdodgemcontrol(Actor *arg0, f32 *arg1, s32 arg2) {
    f32 func_800EEB40(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    typedef struct {
        u8 pad[0x34];
        f32 positions[10][3];
        u8 flags[0x19];
        u8 count;
    } DodgemData;
    s32 var_s0;
    DodgemData *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    for (var_s0 = 0; var_s0 < temp_v0->count; var_s0++) {
        if ((var_s0 != arg2) && (temp_v0->flags[var_s0] == 1) && (func_800EEB40(temp_v0->positions[var_s0], arg1) < 40000.0f)) {
            return 0;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808004E4_chdodgemcontrol.s")

s32 func_808005CC_chdodgemcontrol(s32 arg0) { switch (arg0) { case 0: return 0x2D; case 1: return 0x2D; case 2: return 0x2D; case 3: return 0x3C; default: return 0; } }

/* extern */

void func_8080061C_chdodgemcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    arg2 |= 6;
    switch (arg1) {
    case 0x10D9:
    case 0x10DA:
        func_800FC6B0(0x10);
        func_800FDC28(0);
        break;
    case 0x10D4:
    case 0x10D5:
    case 0x10D6:
    case 0x10EC:
    case 0x10EE:
    case 0x10F0:
        func_800FC6B0(0x16);
        func_800FDC28(0);
        break;
    case 0x10D7:
    case 0x10ED:
    case 0x10EF:
    case 0x10F1:
        func_800FC6B0(0x17);
        func_800FDC28(0);
        break;
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x22);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808006CC_chdodgemcontrol.s")

s32 func_808008EC_chdodgemcontrol(Actor *arg0) { switch (arg0->unk79_4) { case 0: return 0x3C; case 1: return 0x32; case 2: return 0x28; default: return 0; } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80800938_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80800CA0_chdodgemcontrol.s")

void func_80800FC4_chdodgemcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80804D20_chdodgemcontrol;
    extern s32 D_80804D34_chdodgemcontrol;
    s32 temp_a0;
    s32 *temp_v0;
    s32 *temp_v1;

    temp_v0 = func_80100094(arg0, 0);
    if ((arg0->unk70_10 == 3) && ((arg2 >= 0) || ((temp_v0 + arg1)[4] >= -arg2))) {
        temp_a0 = arg1 * 4;
        temp_v1 = (s32 *)((u8 *)temp_v0 + temp_a0);
        temp_v1[4] += arg2;
        if (arg2 > 0) {
            if (temp_a0 == 0) {
                func_8010D930(4, 0, arg0->position, &D_80804D34_chdodgemcontrol);
            }
        } else if (temp_a0 == 0) {
            func_8010D930(5, 0, arg0->position, &D_80804D20_chdodgemcontrol);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801084_chdodgemcontrol.s")

f32 func_80801214_chdodgemcontrol(s32 arg0) {
    typedef struct { f32 values[4]; } DodgemValues;
    extern DodgemValues D_80804E18_chdodgemcontrol;
    DodgemValues values = D_80804E18_chdodgemcontrol;
    return values.values[arg0];
}

void func_80801258_chdodgemcontrol(s32 arg0, f32 arg1[3]) {
    void func_800EE7F8(f32 *, f32 *);
    typedef struct { f32 values[4][3]; } DodgemPositions;
    extern DodgemPositions D_80804E28_chdodgemcontrol;
    DodgemPositions values = D_80804E28_chdodgemcontrol;
    func_800EE7F8(arg1, values.values[arg0]);
}

/* extern */

void func_808012C8_chdodgemcontrol(Actor *arg0, s32 arg1) {
    s32 _chintrotext_entrypoint_1(s32, s32, s32, s32);
    s32 _chintrotext_entrypoint_2(s32);
    s32 func_800D395C(void);
    if ((arg1 != 0) || (func_800D395C() != 0)) {
        arg0->unk64_19 = 1;
        _chintrotext_entrypoint_1(0x18B1, arg0->unk79_4 + 0x12, 0, 0);
        return;
    }
    arg0->unk64_19 = 0;
    _chintrotext_entrypoint_2(1);
}

void func_80801344_chdodgemcontrol(Actor *arg0) {
    void func_800D2748(s32, s32);

    switch (arg0->unk79_4) {
    case 0:
    case 1:
    case 2:
        func_800D2748(0xC3, 0x5B);
        break;
    case 3:
        func_800D2748(0xC3, 0x23);
        break;
    }
    func_800D2748(0xC4, 0x24);
    func_800D2748(0xC5, 0x25);
    func_800D2748(0xC6, 0x26);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808013D0_chdodgemcontrol.s")

void func_808015E8_chdodgemcontrol(Actor *arg0) {
    switch (arg0->unk79_4) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080160C_chdodgemcontrol.s")

typedef struct {
    u8 pad0[0x64];
    u32 pad64_30 : 2;
    u32 unk64_29 : 1;
    u32 unk64_27 : 2;
    u32 unk64_26 : 1;
    u32 unk64_25 : 1;
    u32 unk64_24 : 1;
    u32 pad64_0 : 24;
    s32 pad68;
    u32 pad6C_21 : 11;
    u32 unk6C_9 : 12;
    u32 unk6C_0 : 9;
} DodgemControlActor;

void func_80801744_chdodgemcontrol(Actor *arg0, DodgemControlActor *arg1) {
    switch (arg0->unk79_4) {
    case 0:
    case 1:
    case 2:
        switch (arg1->unk6C_0) {
        case 0:
            arg1->unk64_29 = 1;
            arg1->unk64_27 = 0;
            return;
        case 1:
            arg1->unk64_24 = 1;
            return;
        }
        break;
    case 3:
        arg1->unk64_29 = 0;
        arg1->unk64_27 = arg1->unk6C_0;
        return;
    }
}

void func_808017F0_chdodgemcontrol(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    struct {
        s32 words[12];
        u8 bytes[0x92];
        u8 count;
    } *temp_v0;
    s32 var_v1;

    temp_v0 = func_80100094(arg0, 0U);
    for (var_v1 = 0; var_v1 < temp_v0->count; var_v1++) {
        temp_v0->bytes[var_v1] = 0;
        temp_v0->words[var_v1] = 0;
    }
}

/* extern */

Actor *func_80801844_chdodgemcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_801084B0(s32, Actor **);
    void func_80108944(Actor *, Actor *);
    s32 func_80801928_chdodgemcontrol(Actor *, s32);
    struct {
        Unk80132ED0 *words[12];
        u8 bytes[0x92];
        u8 count;
    } *temp_v0;
    Unk80132ED0 **var_s2;
    s32 var_s1;
    u32 temp_s0;
    u8 temp_s4;
    Actor *temp_v0_2;
    void *child;

    temp_s0 = arg0->unk79_4;
    temp_v0 = func_80100094(arg0, 0U);
    temp_s4 = temp_v0->count;
    var_s1 = 0;
    var_s2 = temp_v0->words;
    if ((s32) temp_s4 > 0) {
        do {
            temp_v0_2 = func_801084B0(0x305, &arg0);
            temp_v0_2->unk3C = arg0->unk0;
            *var_s2 = temp_v0_2->unk0;
            temp_v0_2->unk79_4 = temp_s0;
            func_80801928_chdodgemcontrol(arg0, var_s1);
            func_80108944(temp_v0_2, arg0);
            child = temp_v0_2;
            func_80801744_chdodgemcontrol(arg0, child);
            var_s1 += 1;
            var_s2++;
        } while (var_s1 != temp_s4);
    }
    return arg0;
}

s32 func_80801928_chdodgemcontrol(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    struct {
        Unk80132ED0 *markers[4];
        s32 state[8];
        s8 active[4];
    } *data;
    Actor *actor;

    data = func_80100094(arg0, 0U);
    actor = func_80106790(data->markers[arg1]);
    func_80801258_chdodgemcontrol(arg1, actor->position);
    actor->rotation[1] = func_80801214_chdodgemcontrol(arg1);
    actor->unk54 = actor->rotation[1];
    actor->unk6C_0 = arg1;
    data->state[arg1] = 0;
    data->active[arg1] = 1;
}

/* extern */

void func_808019C4_chdodgemcontrol(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80801A3C_chdodgemcontrol(Actor *, s32, s32);
    s32 var_s0;
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    var_s0 = 0;
    if ((s32) (*(u8 *)((s8 *)(temp_v0) + (0xC2))) > 0) {
        do {
            func_80801A3C_chdodgemcontrol(arg0, var_s0, arg1);
            var_s0 += 1;
        } while (var_s0 < (s32) (*(u8 *)((s8 *)(temp_v0) + (0xC2))));
    }
}

/* extern */

void func_80801A3C_chdodgemcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    s32 func_808042A4_chdodgemcontrol(s32, s32);
    s32 temp_t6;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    temp_t6 = arg1 * 4;
    if (*(s32 *)(temp_v0 + temp_t6) != 0) {
        func_808042A4_chdodgemcontrol(*(s32 *)(temp_v0 + temp_t6), arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801A8C_chdodgemcontrol.s")

void func_80801B94_chdodgemcontrol(s32 arg0, s32 arg1) {
    s32 _subaddieaudioquick_entrypoint_2(s32, s32 *, s32 *);
    s32 func_800B53A4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, s32 *, s32 *, s32, s32 *);
    s32 func_80103DFC(s32, s32 *);
    extern s32 D_80804E78_chdodgemcontrol;
    extern s32 D_80804EA4_chdodgemcontrol;
    s32 sp2C;
    s32 sp20[3];

    sp2C = func_800B53A4(0xC);
    func_80103DFC(arg0, sp20);
    func_800BABB8(sp2C, sp20, sp20, 0x3F800000, &D_80804E78_chdodgemcontrol);
    func_800BA3FC(sp2C, arg1);
    func_800BA22C(sp2C, 0xC);
    _subaddieaudioquick_entrypoint_2(arg0, sp20, &D_80804EA4_chdodgemcontrol);
}

void func_80801C18_chdodgemcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiefade_entrypoint_5();
    func_80102424(arg0, arg2);
    if ((arg0->unk70_10) == 3) {
        _subaddiefade_entrypoint_5(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801C60_chdodgemcontrol.s")

void func_80801F00_chdodgemcontrol(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x50)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80801F2C_chdodgemcontrol.s")

OSThread *chdodgemcontrol_entrypoint_1(void)
{
    extern u8 D_80804EDC_chdodgemcontrol[];

    return (OSThread *) D_80804EDC_chdodgemcontrol;
}

s32 func_8080207C_chdodgemcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    extern s32 D_80804F64_chdodgemcontrol[];
    s32 result;
    if (arg1 == 0x1F) {
        func_801015D0(arg0);
        func_800DF744(3, D_80804F64_chdodgemcontrol[arg0->unk6C_0]);
        func_800DF744(4, D_80804F64_chdodgemcontrol[arg0->unk6C_0]);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80802104_chdodgemcontrol.s")

void func_80802180_chdodgemcontrol(Actor *arg0) {
    f32 func_800138D0(f32);
    f32 func_800D8FF8(void);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    f32 func_800F1DCC(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, f32);
    void func_80802104_chdodgemcontrol(Actor *);
    void func_808039B8_chdodgemcontrol(Actor *);
    f32 func_808046EC_chdodgemcontrol(Actor *);
    f32 mlAbsF(f32);
    f32 *sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    sp8C = func_80100094(arg0, 0);
    sp88 = func_800D8FF8();
    sp84 = func_800F1DCC(*(f32 *)((u8 *)arg0 + 0x48), *(f32 *)((u8 *)arg0 + 0x54));
    *(f32 *)((u8 *)arg0 + 0x24) *= 0.95f;
    sp84 = mlAbsF(func_800138D0(sp84));
    sp80 = func_808046EC_chdodgemcontrol(arg0) * (1.1f - sp84) * sp88;
    sp8C[3] *= 0.8f;
    func_800EEB9C(sp74, *(f32 *)((u8 *)arg0 + 0x48), -40.0f);
    func_800EF04C((f32 *)((u8 *)arg0 + 4), sp74);
    if (func_80102CF4(arg0, sp80) == 0) {
        func_80102B2C(arg0, sp80);
    }
    *(f32 *)((u8 *)arg0 + 0x48) += sp8C[3];
    func_800EEB9C(sp74, *(f32 *)((u8 *)arg0 + 0x48), 40.0f);
    func_800EF04C((f32 *)((u8 *)arg0 + 4), sp74);
    func_800EEB9C(sp5C, *(f32 *)((u8 *)arg0 + 0x48), 48.75f);
    func_800EF04C(sp5C, (f32 *)((u8 *)arg0 + 4));
    func_800EEB9C(sp68, *(f32 *)((u8 *)arg0 + 0x48), *(f32 *)((u8 *)arg0 + 0x24));
    func_800EF04C(sp68, sp8C);
    if (sp68[0] < 0.0f) {
        sp68[0] = -sp68[0];
    }
    if (sp68[2] < 0.0f) {
        sp68[2] = -sp68[2];
    }
    if (*(f32 *)((u8 *)arg0 + 4) < -629.0f) {
        *(f32 *)((u8 *)arg0 + 4) = -629.0f;
        func_800EEB9C(sp8C, 90.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[0] < -655.0f) {
        sp5C[0] = -655.0f;
        func_800EEB9C(sp50, *(f32 *)((u8 *)arg0 + 0x48), 48.75f);
        *(f32 *)((u8 *)arg0 + 4) = sp5C[0] - sp50[0];
        func_800EEB9C(sp8C, 90.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (*(f32 *)((u8 *)arg0 + 4) > 629.0f) {
        *(f32 *)((u8 *)arg0 + 4) = 629.0f;
        func_800EEB9C(sp8C, 270.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[0] > 655.0f) {
        sp5C[0] = 655.0f;
        func_800EEB9C(sp44, *(f32 *)((u8 *)arg0 + 0x48), 48.75f);
        *(f32 *)((u8 *)arg0 + 4) = sp5C[0] - sp44[0];
        func_800EEB9C(sp8C, 270.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (*(f32 *)((u8 *)arg0 + 0xC) > 629.0f) {
        *(f32 *)((u8 *)arg0 + 0xC) = 629.0f;
        func_800EEB9C(sp8C, 180.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[2] > 655.0f) {
        sp5C[2] = 655.0f;
        func_800EEB9C(sp38, *(f32 *)((u8 *)arg0 + 0x48), 75.0f);
        *(f32 *)((u8 *)arg0 + 0xC) = sp5C[2] - sp38[2];
        func_800EEB9C(sp8C, 180.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (*(f32 *)((u8 *)arg0 + 0xC) < -629.0f) {
        *(f32 *)((u8 *)arg0 + 0xC) = -629.0f;
        func_800EEB9C(sp8C, 0.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[2] < -655.0f) {
        sp5C[2] = -655.0f;
        func_800EEB9C(sp2C, *(f32 *)((u8 *)arg0 + 0x48), 48.75f);
        *(f32 *)((u8 *)arg0 + 0xC) = sp5C[2] - sp2C[2];
        func_800EEB9C(sp8C, 0.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    func_800EEB9C((f32 *)((u8 *)arg0 + 0x28), *(f32 *)((u8 *)arg0 + 0x48), *(f32 *)((u8 *)arg0 + 0x24));
    func_800EF04C((f32 *)((u8 *)arg0 + 0x28), sp8C);
    func_800EF334((f32 *)((u8 *)arg0 + 0x28), sp88);
    func_800EF04C((f32 *)((u8 *)arg0 + 4), (f32 *)((u8 *)arg0 + 0x28));
    func_800EF334(sp8C, 0.7f);
    if (sp8C[6] != 0.0f) {
        sp8C[6] = sp8C[6] - sp88;
    }
    func_808039B8_chdodgemcontrol(arg0);
}

s32 func_808026D0_chdodgemcontrol(s32 arg0) {
    s32 func_80104248();
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_start(s32);
    s32 func_8008B188(s32, s32);
    anctrl_setPlaybackType(func_80104248(), 1);
    func_8008B188(func_80104248(arg0), 1);
    return anctrl_start(func_80104248(arg0));
}

/* extern */

void func_80802720_chdodgemcontrol(s32 arg0) {
    s32 anctrl_setIndex(s32, s32);
    s32 func_80101CDC(s32, s32);
    s32 func_80104248();
    s32 func_808026D0_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x105);
    func_80101CDC(arg0, 0x4B189680);
    func_808026D0_chdodgemcontrol(arg0);
}

/* extern */

void func_80802764_chdodgemcontrol(Actor *arg0) {
    s32 anctrl_setIndex(s32, s32);
    s32 func_80101CDC(s32, s32);
    s32 func_80104248();
    s32 func_808026D0_chdodgemcontrol(s32);
    s32 func_808000B8_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x10B);
    func_80101CDC((s32)arg0, 0x3F666666);
    func_808026D0_chdodgemcontrol((s32)arg0);
    if (arg0->unk64_20) {
        func_808000B8_chdodgemcontrol(0);
    }
}

/* extern */

void func_808027C4_chdodgemcontrol(s32 arg0) {
    struct Flags {
        u8 pad[0x64];
        u32 : 11;
        u32 active : 1;
        u32 : 20;
    };
    s32 anctrl_setIndex(s32, s32);
    s32 func_80101CDC(s32, s32);
    s32 func_80104248();
    s32 func_808000B8_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x108);
    func_80101CDC(arg0, 0x3F666666);
    func_808026D0_chdodgemcontrol(arg0);
    if (((struct Flags *)arg0)->active) {
        func_808000B8_chdodgemcontrol(1);
    }
}

/* extern */

void func_80802824_chdodgemcontrol(Actor *arg0) {
    s32 anctrl_setIndex(s32, s32);
    s32 func_80101CDC(s32, s32);
    s32 func_80104248();
    s32 func_808026D0_chdodgemcontrol(s32);
    s32 func_808000B8_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x109);
    func_80101CDC((s32)arg0, 0x3F666666);
    func_808026D0_chdodgemcontrol((s32)arg0);
    if (arg0->unk64_20) {
        func_808000B8_chdodgemcontrol(2);
    }
}

/* extern */

void func_80802884_chdodgemcontrol(Actor *arg0) {
    s32 anctrl_setIndex(s32, s32);
    s32 func_80101CDC(s32, s32);
    s32 func_80104248();
    s32 func_808026D0_chdodgemcontrol(s32);
    s32 func_808000B8_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x10A);
    func_80101CDC((s32)arg0, 0x3F666666);
    func_808026D0_chdodgemcontrol((s32)arg0);
    if (arg0->unk64_20) {
        func_808000B8_chdodgemcontrol(3);
    }
}

void func_808028E4_chdodgemcontrol(s32 arg0) {
    struct Flags {
        u8 pad[0x64];
        u32 : 11;
        u32 active : 1;
        u32 : 20;
    };
    s32 anctrl_isStopped(s32);
    s32 anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_start(s32);
    s32 func_8008B188(s32, s32);
    s32 func_8008B28C(s32);
    void func_800904C8(s32);
    f32 func_800F1DCC(f32, f32);
    s32 func_80101CDC(s32, s32);
    s32 func_801022E4(s32);
    s32 func_80104248();
    f32 difference;

    difference = func_800F1DCC(*(f32 *)(arg0 + 0x48), *(f32 *)(arg0 + 0x54));
    if (((struct Flags *)arg0)->active) {
        if (difference > 10.0f) {
            func_800904C8(0x75);
        } else if (difference < -10.0f) {
            func_800904C8(0x76);
        } else {
            func_800904C8(0x74);
        }
    } else if (difference > 10.0f) {
        switch (func_801022E4(arg0)) {
        case 0x105:
            anctrl_setIndex(func_80104248(arg0), 0x106);
            func_80101CDC(arg0, 0x3F000000);
            anctrl_setPlaybackType(func_80104248(arg0), 1);
            func_8008B188(func_80104248(arg0), 1);
            anctrl_start(func_80104248(arg0));
            break;
        case 0x107:
            if (func_8008B28C(func_80104248(arg0))) {
                func_8008B188(func_80104248(arg0), 0);
                func_80101CDC(arg0, 0x40400000);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x108:
        case 0x109:
        case 0x10A:
        case 0x10B:
            if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        }
    } else if (difference < -10.0f) {
        switch (func_801022E4(arg0)) {
        case 0x105:
            anctrl_setIndex(func_80104248(arg0), 0x107);
            func_80101CDC(arg0, 0x3F000000);
            anctrl_setPlaybackType(func_80104248(arg0), 1);
            func_8008B188(func_80104248(arg0), 1);
            anctrl_start(func_80104248(arg0));
            break;
        case 0x106:
            if (func_8008B28C(func_80104248(arg0))) {
                func_80101CDC(arg0, 0x40400000);
                func_8008B188(func_80104248(arg0), 0);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x108:
        case 0x109:
        case 0x10A:
        case 0x10B:
            if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        }
    } else {
        switch (func_801022E4(arg0)) {
        case 0x105:
            break;
        case 0x106:
            if (func_8008B28C(func_80104248(arg0))) {
                func_80101CDC(arg0, 0x40400000);
                func_8008B188(func_80104248(arg0), 0);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x107:
            if (func_8008B28C(func_80104248(arg0))) {
                func_80101CDC(arg0, 0x40400000);
                func_8008B188(func_80104248(arg0), 0);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x108:
        case 0x109:
        case 0x10A:
        case 0x10B:
            if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80802D04_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_80803200_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080349C_chdodgemcontrol.s")

/* extern */

void func_8080372C_chdodgemcontrol(Actor *arg0, f32 arg1, f32 arg2) {
    f32 func_800F1DCC(f32, f32);
    f32 sp1C;
    f32 temp_f0;
    f32 var_f12;

    sp1C = func_800F1DCC(arg0->rotation[1], arg1);
    temp_f0 = func_800F1DCC(arg0->rotation[1], arg2);
    var_f12 = temp_f0;
    if (sp1C < 0.0f) {
        sp1C = -sp1C;
    }
    if (temp_f0 < 0.0f) {
        var_f12 = -temp_f0;
    }
    if (sp1C < var_f12) {
        arg0->unk54 = arg1;
        return;
    }
    arg0->unk54 = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808037C8_chdodgemcontrol.s")

void func_808039B8_chdodgemcontrol(Actor *arg0) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    f32 func_800EEF94(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    Actor *func_8080000C_chdodgemcontrol(Actor *, s32);
    void func_80801084_chdodgemcontrol(f32 *, f32 *, f32);
    void func_80802104_chdodgemcontrol(Actor *);
    void func_80802764_chdodgemcontrol(Actor *);
    void func_80802824_chdodgemcontrol(Actor *);
    void func_80802884_chdodgemcontrol(Actor *);
    extern s32 D_80804D5C_chdodgemcontrol;
    s32 i;
    Actor *controller;
    u8 *control_data;
    Actor *other;
    f32 *data;
    f32 *other_data;
    f32 other_pos[3];
    f32 front[3];
    f32 other_front[3];
    f32 speed;
    f32 difference;
    s32 angle;
    f32 anglef;
    f32 point[3];
    f32 other_point[3];
    f32 offset[3];
    f32 other_offset[3];

    data = func_80100094(arg0, 0);
    controller = func_80106790(*(Unk80132ED0 **)((u8 *)arg0 + 0x3C));
    control_data = func_80100094(controller, 0);
    for (i = 0; i < control_data[0xC2]; i++) {
        if (i != (*(u32 *)((u8 *)arg0 + 0x6C) & 0x1FF)) {
            other = func_8080000C_chdodgemcontrol(controller, i);
            other_data = func_80100094(other, 0);
            other_pos[0] = ((f32 *)other)[1];
            other_pos[1] = ((f32 *)other)[2];
            other_pos[2] = ((f32 *)other)[3];
            func_800EEB9C(front, ((f32 *)arg0)[0x12], 75.0f);
            func_800EF04C(front, ((f32 *)arg0 + 1));
            func_800EEB9C(other_front, ((f32 *)other)[0x12], 48.75f);
            func_800EF04C(other_front, ((f32 *)other + 1));
            if (func_800EFFB4(((f32 *)arg0 + 1), 182.0f, other_pos) ||
                func_800EFFB4(front, 156.0f, other_pos) ||
                func_800EFFB4(((f32 *)arg0 + 1), 156.0f, other_front) ||
                func_800EFFB4(front, 130.0f, other_front)) {
                speed = func_800EEF94((f32 *)arg0 + 10);
                if (i == (s32)((f32 *)arg0)[13]) {
                    ((f32 *)arg0)[20] = 0.0f;
                }
                if (func_800EEF94((f32 *)other + 10) <= speed) {
                    angle = (s32)func_800F1DF4(((f32 *)other + 1), ((f32 *)arg0 + 1));
                    difference = func_800F1DCC(((f32 *)other)[18], (f32)angle);
                    if (data[6] <= 0.0f) {
                        func_8010D930(1, 0, ((f32 *)arg0 + 1), &D_80804D5C_chdodgemcontrol);
                        data[6] = 1.0f;
                    }
                    if (difference > -45.0f && difference < 45.0f) {
                        func_80802764_chdodgemcontrol(other);
                    }
                    if (difference < -45.0f && difference > -135.0f) {
                        func_80802824_chdodgemcontrol(other);
                    }
                    if (difference > 45.0f && difference < 135.0f) {
                        func_80802884_chdodgemcontrol(other);
                    }
                    if (difference < -135.0f || difference > 135.0f) {
                        func_808027C4_chdodgemcontrol((s32)other);
                    }
                    if (((f32 *)arg0)[9] < 150.0f) {
                        ((f32 *)arg0)[9] = 150.0f;
                    }
                    if (!(*(u32 *)((u8 *)arg0 + 0x6C) & 0x1FF) &&
                        ((u32)((u8 *)controller)[0x79] >> 4) != 3) {
                        ((f32 *)arg0)[9] *= 0.8999938965f;
                        anglef = (f32)angle;
                        func_800EEB9C(data, anglef, ((f32 *)arg0)[9] * 0.5f);
                    } else {
                        ((f32 *)arg0)[9] *= 0.6999969482f;
                        anglef = (f32)angle;
                        func_800EEB9C(data, anglef, ((f32 *)arg0)[9] / 1.0f);
                    }
                    if (i == 0 && ((u32)((u8 *)controller)[0x79] >> 4) != 3) {
                        ((f32 *)other)[9] *= 0.5f;
                        func_800EEB9C(other_data, anglef, -((f32 *)arg0)[9] * 3.0f);
                    } else {
                        ((f32 *)other)[9] *= 0.6999969482f;
                        func_800EEB9C(other_data, anglef, -((f32 *)arg0)[9] / 1.0f);
                    }
                    func_800EEB9C(offset, ((f32 *)arg0)[18], 48.75f);
                    func_800EEB9C(other_offset, ((f32 *)other)[18], 48.75f);
                    func_80801084_chdodgemcontrol(((f32 *)arg0 + 1), ((f32 *)other + 1), 170.625f);
                    func_800EE780(point, offset, ((f32 *)arg0 + 1));
                    func_80801084_chdodgemcontrol(point, ((f32 *)other + 1), 170.625f);
                    func_800EFB24(((f32 *)arg0 + 1), point, offset);
                    func_800EE780(other_point, other_offset, ((f32 *)other + 1));
                    func_80801084_chdodgemcontrol(((f32 *)arg0 + 1), other_point, 136.5f);
                    func_800EFB24(((f32 *)other + 1), other_point, other_offset);
                    func_800EE780(point, offset, ((f32 *)arg0 + 1));
                    func_800EE780(other_point, other_offset, ((f32 *)other + 1));
                    func_80801084_chdodgemcontrol(point, other_point, 136.5f);
                    func_800EFB24(((f32 *)other + 1), other_point, other_offset);
                    func_800EFB24(((f32 *)arg0 + 1), point, offset);
                    difference = func_800F1DCC(((f32 *)arg0)[18], (f32)(angle + 180));
                    if (difference > -45.0f && difference < 45.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    if (difference < -45.0f && difference > -135.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    if (difference > 45.0f && difference < 135.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    if (difference < -135.0f || difference > 135.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    difference = func_800F1DCC(((f32 *)arg0)[18], anglef);
                    if (difference > -80.0f && difference < 10.0f) {
                        data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    if (difference < 80.0f && difference > 10.0f) {
                        data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                    if (difference > -170.0f && difference < -100.0f) {
                        data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                    if (difference < 170.0f && difference > 80.0f) {
                        data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    difference = func_800F1DCC(((f32 *)other)[18], anglef);
                    if (difference > -80.0f && difference < 10.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                    if (difference < 80.0f && difference > 10.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    if (difference > -170.0f && difference < -100.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    if (difference < 170.0f && difference > 80.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                }
            }
        }
    }
}

/* extern */

void func_8080422C_chdodgemcontrol(s32 arg0, s32 arg1) {
    s32 anctrl_setPlaybackType(s32, s32);
    s32 func_80101FDC();
    s32 func_80104248(s32, s32);
    func_80101FDC();
    if ((arg1 == 5) || (arg1 == 6) || (arg1 == 7)) {
        anctrl_setPlaybackType(func_80104248(arg0, arg1), 2);
        return;
    }
    anctrl_setPlaybackType(func_80104248(arg0, arg1), 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_808042A4_chdodgemcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080440C_chdodgemcontrol.s")

void func_8080455C_chdodgemcontrol(void *arg0) {
    struct Flags {
        u8 pad[0x64];
        u32 : 11;
        u32 active : 1;
        u32 : 20;
    };
    void func_800904C8(s32);
    if (((struct Flags *)arg0)->active) {
        func_800904C8(0x28);
    }
}

f32 func_8080458C_chdodgemcontrol(Actor *arg0) {
    switch (arg0->unk79_4) {
        case 0:
        case 1:
        case 2:
            if (!arg0->unk6C_0) {
                return 60.0f;
            }
            return 50.0f;
        case 3:
            return 60.0f;
        default:
            return 0.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080460C_chdodgemcontrol.s")

f32 func_808046EC_chdodgemcontrol(Actor *arg0) {
    switch (arg0->unk79_4) {
        case 0:
        case 1:
        case 2:
            if (!arg0->unk6C_0) {
                return 800.0f;
            }
            return 600.0f;
        case 3:
            return 600.0f;
        default:
            return 0.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemcontrol/func_8080476C_chdodgemcontrol.s")

OSThread *chdodgemcontrol_entrypoint_2(void)
{
    extern u8 D_80804FAC_chdodgemcontrol[];

    return (OSThread *) D_80804FAC_chdodgemcontrol;
}
