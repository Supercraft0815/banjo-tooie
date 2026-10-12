#include "common.h"

OSThread *chinflatableboss_entrypoint_0(void)
{
    extern u8 D_80802E50_chinflatableboss[];

    return (OSThread *) D_80802E50_chinflatableboss;
}

void func_8080000C_chinflatableboss(Actor *arg0) {
    typedef struct {
        f32 position[3];
        s32 id;
        s32 unk10;
        s32 unk14;
    } BossMarker;
    typedef struct {
        u8 unk0[8];
        u8 unk8[0x14];
        f32 position1[3];
        f32 position2[3];
        f32 position3[3];
        u8 unk40[8];
        f32 positions[3][3];
        s32 count6C;
        BossMarker markers70[20];
        s32 count250;
        BossMarker markers254[20];
        u8 unk434[0x60];
        u8 unk494;
        u8 unk495;
        u8 unk496;
        u8 unk497;
        u8 unk498;
        u8 unk499[3];
        u8 unk49C;
    } BossData;
    s32 _chcredits_entrypoint_1(void);
    s32 _chintrotext_entrypoint_2(s32);
    s32 _glcutDll_entrypoint_20(void);
    void _plcamera_entrypoint_8(s32);
    void _subaddieDll_entrypoint_10(s32, void *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, BossMarker *, s32);
    s32 _subaddiemarker_entrypoint_1(Actor *, s32, s32, BossMarker *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    void func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F497C(s32);
    void func_800F49D4(s32, void *, Unk80132ED0 *);
    void func_800F4A58(s32, f32 *, f32);
    u32 func_800F54E4(void);
    void func_800F608C(s32, s32);
    s32 func_800F64A4(s32, s32);
    void func_800F8294(s32, f32 *);
    void func_800F8300(s32, s32, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102FDC(Actor *, f32);
    void func_80109FE8(Actor *, s32);
    void func_8010A85C(Actor *, s32);
    void func_80800F84_chinflatableboss(Actor *, s32);
    void func_8080183C_chinflatableboss(Actor *);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);
    void func_80802AD8_chinflatableboss(Actor *, s32, s32);
    extern s16 D_80802D8C_chinflatableboss;
    extern s32 func_8010D5DC;
    BossData *data;
    s32 i;
    BossMarker markers[3];
    s32 j;
    s32 k;
    s32 count;
    BossMarker *marker;
    s32 player;
    s32 pad;
    f32 *volatile position;

    data = func_80100094(arg0, 0);
    func_800DA524(1);
    func_800DA524(2);
    func_800DA524(4);
    func_800DA524(3);
    func_800DA524(5);
    if (func_800DA298(0x9C) && !_glcutDll_entrypoint_20()) {
        func_800DA544(3);
        _chintrotext_entrypoint_2(1);
        func_800FFAB0(arg0);
        return;
    }
    func_80102FDC(arg0, 1.4f);
    data->unk494 = 1;
    data->unk495 = D_80802D8C_chinflatableboss;
    ((f32 *)arg0->actorData)[4] = 0.35f;
    func_80109FE8(arg0, 0);
    func_800EE7F8(data->position1, position = arg0->position);
    func_800EE7F8(data->position2, position);
    func_800EE7F8(data->position3, position);
    for (i = 0; i != 12; i++) {
        func_80802AD8_chinflatableboss(arg0, i, 1);
    }
    _subaddieDll_entrypoint_10(0x154, data->unk0);
    _subaddieDll_entrypoint_10(0x320, data->unk8);
    func_8080183C_chinflatableboss(arg0);
    func_8010A85C(arg0, 2);
    _suexpression_entrypoint_7(arg0, 1, 0x3A);
    data->count6C = _subaddiemarker_entrypoint_1(arg0, 0x437, 0x32, data->markers70, 20);
    data->count250 = _subaddiemarker_entrypoint_1(arg0, 0x437, 0x35, data->markers254, 20);
    count = _subaddiemarker_entrypoint_0(arg0, 0x3DA, markers, 20);
    j = 0;
    if (count > 0) {
        do {
            k = 0;
            if (count > 0) {
                marker = markers;
                do {
                    if (j + 0x32 == marker->id) {
                        break;
                    }
                    k++;
                    marker++;
                } while (k != count);
            }
            func_800EE7F8(data->positions[j], markers[k].position);
            j++;
        } while (j < count);
    }
    if (func_800DA298(0x17F)) {
        data->unk498 = 5;
    } else {
        data->unk498 = 1;
    }
    if (!func_800F64A4(func_800F54E4(), 1)) {
        data->unk498 = 0;
    }
    if (_glcutDll_entrypoint_20()) {
        func_8010A85C(arg0, 1);
        func_80800F84_chinflatableboss(arg0, _chcredits_entrypoint_1() == 0x36 ? 0x12 : 0x13);
        return;
    }
    if (data->unk498 == 5) {
        player = func_800F54E4();
        data->unk49C = 1;
        data->unk496 = 1;
        func_800F608C(player, 1);
        func_800F8294(player, data->positions[1]);
        func_800F8300(player, 2, position);
        func_800F497C(player);
        _plcamera_entrypoint_8(player);
        func_800DA544(2);
        func_80802A00_chinflatableboss(arg0, 0x22, 0x20);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1087, 0x107, position, 0x3A);
        func_80800F84_chinflatableboss(arg0, 3);
        func_8010A85C(arg0, 1);
        return;
    }
    if (func_800D395C()) {
        arg0->unk64_16 = 1;
        data->unk498 = 2;
        func_800F497C(func_800F54E4());
        func_800F49D4(func_800F54E4(), &func_8010D5DC, arg0->unk0);
        func_800F4A58(func_800F54E4(), data->positions[0], 300.0f);
        func_80802A00_chinflatableboss(arg0, 0x2F, 0x20);
    } else {
        arg0->unk64_16 = 0;
        _chintrotext_entrypoint_2(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80800408_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_808004A0_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80800A98_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80800F84_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_808010BC_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801164_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_808012EC_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801418_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801554_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_8080183C_chinflatableboss.s")

void func_80801904_chinflatableboss(Actor *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void* func_80100094(Actor*, u32);
    f32 *var_a1;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((arg1 >= 3) && (arg1 < 6)) {
        var_a1 = temp_v0 + 0x34;
    } else {
        var_a1 = temp_v0 + 0x28;
    }
    func_800EE7F8(arg2, var_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801958_chinflatableboss.s")

void func_80801AD8_chinflatableboss(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80108B04(Actor*, u32);
    if (arg1 == 0x1085) {
        func_80108B04(arg0, 0U);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801B04_chinflatableboss.s")

/* extern */

s32 func_80801C7C_chinflatableboss(void) {
    s32 func_80801CB4_chinflatableboss();
    return (s32) (0xC - func_80801CB4_chinflatableboss()) / 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801CB4_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801D38_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801DE0_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801EA0_chinflatableboss.s")

/* extern */

void func_80801F4C_chinflatableboss(Actor *arg0) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    Actor* func_80106790(Unk80132ED0 *);
    s32 func_800D10D4(s32, s32, f32 *, s32, s32);
    void func_80802A2C_chinflatableboss(Actor *, Unk80132ED0 *, u32, u32);
    f32 sp2C[3];
    s32 sp28;
    Unk80132ED0 *sp24;

    sp24 = arg0->unk0;
    func_800EE7F8(sp2C, arg0->position);
    sp2C[1] = 5000.0f;
    sp28 = func_800D10D4(0x17, 1, sp2C, 0, 0);
    func_80802A2C_chinflatableboss(func_80106790(sp24), (Unk80132ED0 *)sp28, 0x14, 0x438);
}

void func_80801FC0_chinflatableboss(u8 *arg0, f32 *arg1, f32 *arg2) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802F90_chinflatableboss;
    func_800BABB8(0, arg1, arg2, (*(f32 *)((s8 *)(arg0) + (0x38))) * 0.75f, &D_80802F90_chinflatableboss);
}

void func_8080200C_chinflatableboss(u8 *arg0, f32 *arg1, f32 *arg2) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802FC4_chinflatableboss;
    func_800BABB8(0, arg1, arg2, (*(f32 *)((s8 *)(arg0) + (0x38))) * 0.75f, &D_80802FC4_chinflatableboss);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802058_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802264_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_808023B0_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802450_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_808024BC_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802590_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_8080267C_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_8080272C_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802910_chinflatableboss.s")

/* extern */

void func_808029AC_chinflatableboss(s32 arg0) {
    s32 func_800D2498(s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_80801CB4_chinflatableboss(s32);
    if ((func_800DA298(1) != 0) && (func_800DA298(3) == 0)) {
        func_800D2498(0xEC, func_80801CB4_chinflatableboss(arg0), 0);
    }
}

void func_80802A00_chinflatableboss(Actor *arg0, u32 arg1, u32 arg2) {
    void func_80802A2C_chinflatableboss(Actor *, Unk80132ED0 *, u32, u32);

    func_80802A2C_chinflatableboss(arg0, arg0->unk0, arg1, arg2);
}

void func_80802A2C_chinflatableboss(Actor *arg0, Unk80132ED0 *arg1, u32 arg2, u32 arg3) {
    void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32);
    void _capod_entrypoint_14(void);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if ((*(u8 *)((s8 *)(temp_v0) + (0x49D))) != 0) {
        arg3 |= 0x2000;
        _capod_entrypoint_14();
    }
    _capod_entrypoint_13(arg1, arg0->unk0, arg2, arg3);
    (*(s8 *)((s8 *)(sp1C) + (0x49D))) = 1;
}

void func_80802A9C_chinflatableboss(Actor *arg0) {
    void _capod_entrypoint_14(void);
    void* func_80100094(Actor*, u32);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x49D))) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_14();
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + (0x49D))) = 0;
    }
}

void func_80802AD8_chinflatableboss(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;
    u8 *temp_v1;
    u8 *temp_v1_2;

    temp_v0 = func_80100094(arg0, 0U);
    temp_v1 = temp_v0 + arg1;
    (*(s8 *)((s8 *)(temp_v1) + (0x487))) = (s8) arg2;
    if (arg1 >= 9) {
        arg1 = arg1 + arg1;
        arg1 -= 9;
        temp_v1_2 = temp_v0 + arg1;
        (*(s8 *)((s8 *)(temp_v1_2) + (0x478))) = (s8) arg2;
        (*(s8 *)((s8 *)(temp_v1_2) + (0x479))) = (s8) arg2;
    } else {
        (*(s8 *)((s8 *)(temp_v1) + (0x478))) = (s8) arg2;
    }
}
