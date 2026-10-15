#include "ch/burgerstand.h"

OSThread *chburgerstand_entrypoint_0(void)
{
    extern u8 D_80800C28_chburgerstand[];

    return (OSThread *) D_80800C28_chburgerstand;
}

OSThread *chburgerstand_entrypoint_1(void)
{
    extern u8 D_80800C70_chburgerstand[];

    return (OSThread *) D_80800C70_chburgerstand;
}

OSThread *chburgerstand_entrypoint_2(void)
{
    extern u8 D_80800CB8_chburgerstand[];

    return (OSThread *) D_80800CB8_chburgerstand;
}

OSThread *chburgerstand_entrypoint_3(void)
{
    extern u8 D_80800D00_chburgerstand[];

    return (OSThread *) D_80800D00_chburgerstand;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_80800030_chburgerstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_808000C4_chburgerstand.s")

void func_80800284_chburgerstand(Actor* arg0)
{
    func_80800720_chburgerstand(arg0);
}

s32 func_808002A4_chburgerstand(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_80090734(s32, f32 *);
    s32 func_800D1A04(s32);
    s32 func_80101EE4(Actor *, f32);
    s32 func_80102424(Actor *, s32);
    s32 func_80103110(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80108B04(Actor *, s32);
    s32 func_808006B4_chburgerstand(Actor *);
    s32 func_808007A0_chburgerstand(Actor *, s16, s16);
    s32 func_8080087C_chburgerstand(Actor *, s16, s16);
    s32 func_80800940_chburgerstand(Actor *);
    extern s32 D_80800D50_chburgerstand;
    Unk80132ED0 *temp_a0;
    s32 temp_t7;
    s32 result;
    Actor *temp_v0;

    switch (arg1) {
        default:                                    /* switch 2 */
            return 0;
        case 0x2E:                                  /* switch 2 */
            func_808007A0_chburgerstand(arg0, (*(s16 *)((s8 *)(&arg2) + (0))), (*(s16 *)((s8 *)(&arg2) + (2))));
            break;
        case 0x2F:                                  /* switch 2 */
            func_8080087C_chburgerstand(arg0, (*(s16 *)((s8 *)(&arg2) + (0))), (*(s16 *)((s8 *)(&arg2) + (2))));
            break;
        case 0x32:                                  /* switch 2 */
            func_80090734(2, arg0->position);
            break;
        case 0x3D:                                  /* switch 2 */
            func_80800940_chburgerstand(arg0);
            break;
        case 0x52:                                  /* switch 2 */
            _gcdialogcamera_entrypoint_3(&D_80800D50_chburgerstand, arg0->scale);
            break;
        case 0xA:                                   /* switch 2 */
            arg0->unk64_16 = 1;
            func_80102424(arg0, 2);
            func_80101EE4(arg0, 0.0f);
            func_80103110(arg0, 1);
            temp_a0 = arg0->unk3C;
            if (temp_a0 != NULL) {
                temp_v0 = func_80106790(temp_a0);
                temp_v0->unk64_16 = arg0->unk64_16;
            }
            _capod_entrypoint_13(arg0->unk0, 0, 0x11, 0x30);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x10DF, 4, arg0->position, 0x50);
            break;
        case 0x29:                                  /* switch 2 */
            func_808006B4_chburgerstand(arg0);
            break;
        case 0x2A:                                  /* switch 2 */
            func_80800720_chburgerstand(arg0);
            break;
        case 0x95:
            if (func_800D1A04(0x4B) == 0) {
                func_80108B04(arg0, 0);
            }
            break;
        case 0xB8:
            temp_t7 = arg2 & 0xFFFF;
            switch (temp_t7) {
            default:
                return 0;
            case 1:
                return arg0->unk3C != NULL ? 0x10AB : 0x10AC;
            case 2:
                return arg0->unk3C != NULL ? 0x1106 : 0x1107;
            }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_808004DC_chburgerstand.s")

void func_808005AC_chburgerstand(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_3(s32, s32, s32 *);
    void func_800BA22C(s32, s32);
    s32 func_800BA994(s32, s32, s16, s32, s32, s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_80101E4C(Actor *, f32 *);
    extern f32 D_80800DDC_chburgerstand[];
    extern s32 D_80800DEC_chburgerstand[];
    f32 position[3];
    s32 emitter;

    if (func_80101E4C(arg0, D_80800DDC_chburgerstand) &&
        _subaddieskeleton_entrypoint_3(arg0->unk0, 4, position)) {
        position[1] -= 30.0f;
        emitter = func_800BABB8(0, position, NULL, arg0->scale, D_80800DEC_chburgerstand);
        func_800BA994(emitter, 0x2D, (s16)(s32)(arg0->rotation[1] - 50.0f),
            (s16)(s32)(arg0->scale * 10.0f), 0x3C, (s32)(arg0->rotation[1] + 50.0f), (s32)(arg0->scale * 20.0f));
        func_800BA22C(emitter, 3);
    }
}

s32 func_808006B4_chburgerstand(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x50);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42480000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x3E8);
    }
}

void func_80800720_chburgerstand(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_80800754_chburgerstand(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    s32 func_80090734(s32, f32 *);
    extern s32 D_80800E14_chburgerstand;
    extern s32 D_80800BC0_chburgerstand;
    f32 *position[2];

    position[1] = arg0->position;
    if (_subaddiedialog_entrypoint_8((s32)arg0, position[1], &D_80800E14_chburgerstand, &D_80800BC0_chburgerstand, 5) != 0) {
        func_80090734(1, position[1]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_808007A0_chburgerstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/burgerstand/func_8080087C_chburgerstand.s")

s32 func_80800940_chburgerstand(Actor *arg0) {
    Actor *func_801084B0(s32, Actor **);
    void func_80102FDC(void *, f32);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    Actor *temp_v0;
    s32 sp20[3];

    temp_v0 = func_801084B0(0x32C, &arg0);
    func_80102FDC(temp_v0, arg0->scale);
    _subaddiefade_entrypoint_9(arg0, sp20);
    _subaddiefade_entrypoint_11(temp_v0, sp20);
    arg0->unk3C = temp_v0->unk0;
    temp_v0->unk64_16 = arg0->unk64_16;
}

void func_808009C4_chburgerstand(s32 arg0) 
{
}
/* extern */

void func_808009CC_chburgerstand(void *arg0) {
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
        var_v0 = 0x9F;
    }
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 225.0f, 0x20, var_v0) != 0) {
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_8(arg0, 3);
    }
}

void func_80800A8C_chburgerstand(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_09F_UNK);
    _chswitch_entrypoint_9(arg0);
}

s32 func_80800AB8_chburgerstand(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 ret;

    if (arg1 == 7) {
        func_80101180(0x32F, 7, 0);
        func_80101180(0x32B, 0xA, 0);
        ret = 1;
    } else {
        return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return ret;
}
