#include "ch/friesstand.h"

OSThread *chfriesstand_entrypoint_0(void)
{
    extern u8 D_80800EC8_chfriesstand[];

    return (OSThread *) D_80800EC8_chfriesstand;
}

OSThread *chfriesstand_entrypoint_1(void)
{
    extern u8 D_80800F10_chfriesstand[];

    return (OSThread *) D_80800F10_chfriesstand;
}

OSThread *chfriesstand_entrypoint_2(void)
{
    extern u8 D_80800F58_chfriesstand[];

    return (OSThread *) D_80800F58_chfriesstand;
}

OSThread *chfriesstand_entrypoint_3(void)
{
    extern u8 D_80800FA0_chfriesstand[];

    return (OSThread *) D_80800FA0_chfriesstand;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_80800030_chfriesstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_808000C4_chfriesstand.s")

void func_80800398_chfriesstand(Actor* arg0)
{
    func_80800970_chfriesstand(arg0);
}

s32 func_808003B8_chfriesstand(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_80090734(s32, f32 *);
    s32 func_800D1A04(s32);
    s32 func_80101EE4(Actor *, f32);
    s32 func_80102424(Actor *, s32);
    s32 func_80103110(Actor *, s32);
    void *func_80106790(Unk80132ED0 *);
    s32 func_80108B04(Actor *, s32);
    s32 func_80800904_chfriesstand(Actor *);
    s32 func_808009F0_chfriesstand(Actor *, s16, s16);
    void func_80800AEC_chfriesstand(Actor *, s32, s16);
    s32 func_80800BB0_chfriesstand(Actor *);
    extern s32 D_80800FF0_chfriesstand;
    Unk80132ED0 *temp_a0;
    s32 temp_t7;
    void *temp_v0;

    switch (arg1) {
    default:
        return 0;
    case 0x2E:
        func_808009F0_chfriesstand(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x2F:
        func_80800AEC_chfriesstand(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x32:
        func_80090734(2, arg0->position);
        break;
    case 0x3D:
        func_80800BB0_chfriesstand(arg0);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80800FF0_chfriesstand, arg0->scale);
        break;
    case 0xA:
        arg0->unk64_16 = 1;
        func_80102424(arg0, 3);
        func_80101EE4(arg0, 0.0f);
        func_80103110(arg0, 1);
        temp_a0 = arg0->unk3C;
        if (temp_a0 != NULL) {
            temp_v0 = func_80106790(temp_a0);
            ((Actor *)temp_v0)->unk64_16 = arg0->unk64_16;
        }
        _capod_entrypoint_13(arg0->unk0, 0, 0x16, 0x30);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x10E0, 4, arg0->position, 0x51);
        break;
    case 0x29:
        func_80800904_chfriesstand(arg0);
        break;
    case 0x2A:
        func_80800970_chfriesstand(arg0);
        break;
    case 0x95:
        if (func_800D1A04(0x4C) == 0) {
            func_80108B04(arg0, 0);
        }
        break;
    case 0xB8:
        temp_t7 = arg2 & 0xFFFF;
        switch (temp_t7) {
        default:
            return 0;
        case 1:
            return arg0->unk3C != NULL ? 0x10AE : 0x10AF;
        case 2:
            return arg0->unk3C != NULL ? 0x1109 : 0x110A;
        }
    }
    return 1;
}

void func_808005F0_chfriesstand(Actor *arg0) {
    extern u32 D_80801000_chfriesstand;
    extern u32 D_8080100C_chfriesstand;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80801000_chfriesstand, &D_8080100C_chfriesstand);
}

void func_80800620_chfriesstand(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_8080101C_chfriesstand;
    extern u32 D_8080102C_chfriesstand;
    extern u32 D_80801038_chfriesstand;
    extern u32 D_80801044_chfriesstand;
    extern u32 D_80801050_chfriesstand;
    extern u32 D_8080105C_chfriesstand;
    f32 *temp_s1;

    temp_s1 = (f32 *)((s8 *)arg0 + 4);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_8080102C_chfriesstand, 0.08f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_80801038_chfriesstand, 0.23f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_80801044_chfriesstand, 0.34f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_80801050_chfriesstand, 0.42f);
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, &D_8080101C_chfriesstand, &D_8080105C_chfriesstand);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_808006D4_chfriesstand.s")

s32 func_80800904_chfriesstand(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x51);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42480000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x3E8);
    }
}

void func_80800970_chfriesstand(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_808009A4_chfriesstand(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    s32 func_80090734(s32, f32 *);
    extern s32 D_80801088_chfriesstand;
    extern s32 D_80800E50_chfriesstand;
    f32 *position[2];

    position[1] = arg0->position;
    if (_subaddiedialog_entrypoint_8((s32)arg0, position[1], &D_80801088_chfriesstand, &D_80800E50_chfriesstand, 5) != 0) {
        func_80090734(1, position[1]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friesstand/func_808009F0_chfriesstand.s")

void func_80800AEC_chfriesstand(Actor *arg0, s32 arg1, s16 arg2) {
    s32 _subaddiedialog_entrypoint_9(Actor *, s32, s32 *, s32);
    void func_8010D254(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_80090708(s32);
    void func_8008F8B0(void);
    void func_8008F904(void *, Unk80132ED0 *);
    void func_8008F990(f32 *, f32);
    extern s32 D_80800E50_chfriesstand;
    extern s32 func_8010D5DC;
    f32 sp34[3];
    f32 sp28[3];
    s32 pad[2];

    if (arg0->unk3C != NULL && _subaddiedialog_entrypoint_9(arg0, arg1, &D_80800E50_chfriesstand, 5) == 2) {
        func_8010D254(sp28);
        func_800EE7F8(sp34, arg0->position);
        func_800EF1B8(sp34, arg0->rotation[1], 255.0f);
        if (func_800EEAD4(sp28, sp34) > 50.0f) {
            func_80090708(0);
            func_8008F8B0();
            func_8008F904(&func_8010D5DC, arg0->unk0);
            func_8008F990(sp34, 170.0f);
        }
    }
}

s32 func_80800BB0_chfriesstand(Actor *arg0) {
    Actor *func_801084B0(s32, Actor **);
    void func_80102FDC(void *, f32);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    Actor *temp_v0;
    s32 sp20[3];

    temp_v0 = func_801084B0(0x32E, &arg0);
    func_80102FDC(temp_v0, arg0->scale);
    _subaddiefade_entrypoint_9(arg0, sp20);
    _subaddiefade_entrypoint_11(temp_v0, sp20);
    arg0->unk3C = temp_v0->unk0;
    temp_v0->unk64_16 = arg0->unk64_16;
}

void func_80800C34_chfriesstand(s32 arg0) 
{
}
/* extern */

void func_80800C3C_chfriesstand(void *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800EA05C();
    void func_80101FDC(Actor *, u32);
    void func_8010A624(void ***);
    s32 var_v0;

    if (func_800EA05C() == 0x124) {
        func_8010A624(arg0);
    }
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) ((*(f32 *)((s8 *)(arg0) + (8))) - 225.0f);
    if (_glcutDll_entrypoint_20() != 0) {
        var_v0 = -1;
        func_80101FDC(arg0, 4);
    } else {
        var_v0 = 0xA0;
    }
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 225.0f, 0x20, var_v0) != 0) {
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_8(arg0, 3);
    }
}

void func_80800CF0_chfriesstand(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_0A0_UNK);
    _chswitch_entrypoint_9(arg0);
}

s32 func_80800D1C_chfriesstand(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    int result;
    if (arg1 == 7) {
        func_80101180(0x331, 7, 0);
        func_80101180(0x32D, 0xA, 0);
        result = 1;
    } else {
        return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return result;
}
