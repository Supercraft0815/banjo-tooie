#include "common.h"

OSThread *chsabreman_entrypoint_0(void)
{
    extern u8 D_80801BE0_chsabreman[];

    return (OSThread *) D_80801BE0_chsabreman;
}

OSThread *chsabreman_entrypoint_1(void)
{
    extern u8 D_80801D30_chsabreman[];

    return (OSThread *) D_80801D30_chsabreman;
}

OSThread *chsabreman_entrypoint_2(void)
{
    extern u8 D_80801D78_chsabreman[];

    return (OSThread *) D_80801D78_chsabreman;
}

OSThread *chsabreman_entrypoint_3(void)
{
    extern u8 D_80801DC0_chsabreman[];

    return (OSThread *) D_80801DC0_chsabreman;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80800030_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80800218_chsabreman.s")

s32 func_808008C8_chsabreman(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chlifeforcespell_entrypoint_1(Actor **, void *, s32, f32, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    s32 _glcutDll_entrypoint_20();
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    s32 _subaddiepalette_entrypoint_4(void *, void *);
    s32 _subaddietaxi_entrypoint_13(Actor *, s32, void *, s32);
    s32 _subaddietaxi_entrypoint_2(Actor *, s32);
    void func_800C01A8(s16, s32);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    s32 func_800DA564(s32, s32);
    s32 func_800F54E4();
    s32 func_800F8300(s32, s32, s32);
    void func_800FC660(u32);
    void func_800FFAB0(Actor *);
    void *func_80100094(s32, s32);
    void func_80102FDC(Actor *, f32);
    Actor *func_801084B0(s32, Actor **);
    void func_80108B04(Actor *, u32);
    void func_808011F8_chsabreman();
    s32 func_8080167C_chsabreman(s32, s32, s32);
    extern s32 D_80801BE8_chsabreman;
    extern s32 _chsabreman_entrypoint_0;
    struct SabremanFlags {
        u32 pad : 26;
        u32 active : 1;
        u32 rest : 5;
    };
    u8 *data;
    Actor *child;

    switch (arg1) {
        case 0x3E:
            if (func_800DA564(0x1CA, 2) == 2 && _subaddietaxi_entrypoint_2(arg0, 0xB)) {
                func_808011F8_chsabreman(arg0, 0xD);
            }
            break;
        case 0x40:
            if (func_800DA564(0x1CA, 2) == 1 && arg0->unk70_10 == 5) {
                func_800FC660(0xE);
                func_808011F8_chsabreman(arg0, 7);
                _subaddieDll_entrypoint_4(arg0, 1);
                (*(s32 *)((u8 *)arg0 + 0x50))++;
                if (*(s32 *)((u8 *)arg0 + 0x50) == 3) {
                    func_800F8300(func_800F54E4(), 2, (s32)((u8 *)arg0 + 4));
                }
            }
            break;
        case 0x3D:
            data = func_80100094((s32)arg0, 0);
            switch (arg2) {
                case 0:
                    child = func_801084B0(0x1FE, &arg0);
                    _subaddielink_entrypoint_1(data + 0x810, *(Unk80132ED0 **)child);
                    func_80102FDC(child, *(f32 *)((u8 *)arg0 + 0x38));
                    *(s32 *)((u8 *)child + 0x3C) = *(s32 *)arg0;
                    break;
                case 1:
                    *(s32 *)((u8 *)arg0 + 0x3C) = _chlifeforcespell_entrypoint_1(&arg0, (u8 *)arg0 + 4, 0x64, 4.0f, 0x12);
                    func_808017D8_chsabreman(arg0, 0x1B, 0x30);
                    break;
            }
            break;
        case 0x2E:
            switch (arg0->unk70_10) {
                case 6:
                    func_808016E4_chsabreman(arg0);
                    func_808011F8_chsabreman(arg0, 5);
                    _subaddieDll_entrypoint_4(arg0, 0);
                    break;
                case 11:
                    func_808016E4_chsabreman(arg0);
                    func_808011F8_chsabreman(arg0, 0xA);
                    break;
                case 24:
                    func_808011F8_chsabreman(arg0, 0x17);
                    break;
            }
            if (*(s16 *)&arg2 == 0x1275) {
                func_800C01A8(0x64, 0);
                func_808017D8_chsabreman(arg0, 8, 0x2030);
                func_800D1000(0x3F, 1, 0, 1, 0);
            }
            break;
        case 0xB:
            if (arg2 == 8) {
                func_808016E4_chsabreman(arg0);
                func_808011F8_chsabreman(arg0, 0x13);
                return 4;
            }
            return 3;
        case 0x44:
            func_80801010_chsabreman(arg0, arg2);
            break;
        case 0x4B:
            func_80108B04(arg0, 1);
            _subaddieDll_entrypoint_4(arg0, 1);
            func_808011F8_chsabreman(arg0, 2);
            *(f32 *)((u8 *)arg0 + 0x58) = 14.0f;
            break;
        case 0x4C:
            *(s32 *)((u8 *)arg0 + 0x3C) = 0;
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80801BE8_chsabreman, *(f32 *)((u8 *)arg0 + 0x38));
            break;
        case 0x1F:
            func_80800D30_chsabreman(arg0, arg2);
            break;
        case 0x57:
            return func_8080167C_chsabreman((s32)arg0, arg2 & 0xFFFF, ((u32)arg2 & 0xFFFF0000) >> 16);
        case 0x95:
            *(s32 *)((u8 *)arg0 + 0x50) = 0;
            if (_glcutDll_entrypoint_20() || _subaddietaxi_entrypoint_13(arg0, 0xB, &_chsabreman_entrypoint_0, 3)) {
                func_80800030_chsabreman(arg0);
            } else if (((struct SabremanFlags *)((u8 *)arg0 + 0x78))->active) {
                func_800FFAB0(arg0);
            }
            break;
        case 0x29:
            data = func_80100094((s32)arg0, 0);
            _subaddiepalette_entrypoint_4(arg0, data);
            break;
        default:
            return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80800CDC_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80800D30_chsabreman.s")

void func_80800F04_chsabreman(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    s32 func_800DA564(s32, s32);
    extern s32 _subaddietaxi_entrypoint_16;
    if (func_800DA564(0x1CA, 2) != 3) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, (*(s32 *)((s8 *)(arg1) + (0))), (*(s32 *)((s8 *)(arg1) + (4))), (*(s32 *)((s8 *)(arg1) + (8))), arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80800F74_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80801010_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_8080112C_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808011AC_chsabreman.s")

void func_808011F8_chsabreman()
{
    func_80102424();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80801218_chsabreman.s")

void func_8080158C_chsabreman(Actor *arg0) {
    s32 func_800DA564(s32, s32);
    void func_800FFAB0(Actor*);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, 0.45f);
    if (func_800DA564(0x1CA, 2) != 3) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808015D4_chsabreman.s")

/* extern */

void func_80801620_chsabreman(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(5, 1);
    func_800DF744(3, 0);
    func_800DF744(6, 0);
    func_800DF744(4, 0);
    func_80101870(arg0, arg1);
}

/* extern */

s32 func_8080167C_chsabreman(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void *func_80100094(s32, s32);
    s32 func_80801724_chsabreman(s32, s32, s32);
    void *temp_v0;

    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        temp_v0 = func_80100094(arg0, 0);
        if ((temp_v0 != NULL) && ((*(s16 *)((s8 *)(temp_v0) + (0x820))) != 2)) {
            func_80801724_chsabreman(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808016E4_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80801724_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808017D8_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80801864_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808018DC_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_8080193C_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808019A4_chsabreman.s")
