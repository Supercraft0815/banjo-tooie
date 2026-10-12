#include "gc/sectionskip.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/sectionskip/func_80800000_gcsectionskip.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/sectionskip/func_8080019C_gcsectionskip.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/sectionskip/func_808002A0_gcsectionskip.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/sectionskip/func_80800374_gcsectionskip.s")

void gcsectionskip_entrypoint_0(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0xDAA) {
        func_800DA524(FLAG2_6C9_UNK);
    }
}

s32 gcsectionskip_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, u32 arg3, u8 *arg4) {
    s32 _chchuffycont_entrypoint_0(s32 *, s32 *);
    s32 _chchuffycont_entrypoint_1(s32 *, s32 *);
    s32 func_800A8264(void);
    int func_800C6E38(s32);
    s32 func_800D3948(void);
    s32 func_800D395C(void);
    s32 func_800DC298(f32);
    s32 func_800F4BE4(s32);
    s32 func_800F5410(s32);
    s32 func_800F66F0(s32);
    s32 func_800F6CC8(s32);
    s32 func_800F6D24(s32);
    s32 func_800F70BC(s32);
    s32 func_800F7C9C(s32, s32, s32, s32);
    s32 func_800F7E3C(s32, s32);
    s32 func_800F8B88(void);
    void func_808002A0_gcsectionskip(u32, s32);
    void func_80800374_gcsectionskip();
    s32 func_80800D3C_gcsectionskip(s32 *, s32 *);
    void func_80800EF8_gcsectionskip(s32, s32);
    extern u8 D_8012762C;
    extern u8 D_80801040_gcsectionskip[];
    s32 sp2C;
    u32 sp28;
    s32 sp24;

    sp2C = 1;
    if (_gcgoto_entrypoint_15() != 0) {
        return 0;
    }
    sp28 = func_800F54E4();
    if (arg4 != NULL && sp28 != ((u32)*(u16 *)(arg4 + 0x1A) >> 5)) {
        return 0;
    }
    sp24 = func_800F5410(sp28);
    _gcgoto_entrypoint_0(&arg1, &arg2);
    if (func_800F6D24(sp28) != 0 || func_800F8004(sp28) != 0 ||
        func_800F6CC8(sp28) != 0 || func_800F66F0(sp28) != 0 ||
        func_800F70BC(func_800F54E4()) != 0) {
        func_808002A0_gcsectionskip(sp28, arg0);
        return 0;
    }
    if (func_800F8B88() == 3 && sp24 == 0xB) {
        func_800F7B9C(sp28, 0x88);
        return 0;
    }
    switch (arg3) {
    case 0:
        if (func_800F4BE4(sp28) == 0) {
            func_80800374_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 1:
        if (_chchuffycont_entrypoint_0(&arg1, &arg2) == 0) {
            return 0;
        }
        goto final_checks;
    case 2:
        if (_chchuffycont_entrypoint_1(&arg1, &arg2) == 0) {
            return 0;
        }
        sp2C = 0;
        goto final_checks;
    case 3:
        if (func_800DA298(0xB2) == 0) {
            return 0;
        }
        goto final_checks;
    case 4:
        if (sp24 != 1) {
            func_80800374_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 29:
        if (sp24 != 1) {
            func_808002A0_gcsectionskip(sp28, arg0);
            func_800F7E3C(sp28, 0x1228);
            return 0;
        }
        goto final_checks;
    case 5:
        if (sp24 != 0xB) {
            func_80800374_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 6:
        if (sp24 != 0xA) {
            func_80800374_gcsectionskip(sp28, arg0);
            return 0;
        }
        sp2C = 0;
        goto final_checks;
    case 7:
        if (func_800DA298(0xB6) != 0) {
            return 0;
        }
        goto final_checks;
    case 8:
        if (func_800DA564(0xA34, 3) != 0) {
            return 0;
        }
        goto final_checks;
    case 14:
        arg2 = D_80801040_gcsectionskip[func_800DA564(0x3A4, 4)];
        goto final_checks;
    case 11:
        if (func_800DA298(0x327) != 0) {
            arg2++;
        }
        goto final_checks;
    case 12:
        if (func_800DA9E4(0x409, 1) == 0) {
            func_800DA3B8(0x40A, func_800DC298(0.5f) ? 0 : 1);
        }
        switch (func_800EA05C()) {
        case 0x136:
            switch (arg1) {
            case 0x13E:
                if (func_800DA298(0x40A) == 0) {
                    arg1 = 0x13F;
                }
                break;
            case 0x13F:
                if (func_800DA298(0x40A) == 0) {
                    arg1 = 0x13E;
                }
                break;
            default:
                return 0;
            }
            break;
        case 0x13E:
            if (func_800DA298(0x40A) == 0) {
                arg2 = 9;
            }
            break;
        case 0x13F:
            if (func_800DA298(0x40A) == 0) {
                arg2 = 0x16;
            }
            break;
        }
        goto final_checks;
    case 13:
        if (func_80800D3C_gcsectionskip(&arg1, &arg2) == 0) {
            func_80800374_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 9:
        if (sp24 != 1) {
            func_808002A0_gcsectionskip(sp28, arg0);
            return 0;
        }
        if (func_800C6E38(0x1B) == 0) {
            func_808002A0_gcsectionskip(sp28, arg0);
            func_80800EF8_gcsectionskip(0x10FB, 0x22);
            return 0;
        }
        goto final_checks;
    case 16:
        if (sp24 != 1 && sp24 != 8) {
            func_80800374_gcsectionskip(sp28, arg0);
            return 0;
        }
        sp2C = 0;
        goto final_checks;
    case 17:
        if (sp24 != 0xC) {
            func_80800EF8_gcsectionskip(0x1219, 0x22);
            return 0;
        }
        goto final_checks;
    case 18:
        if (sp24 == 0xA) {
            func_80800EF8_gcsectionskip(0x1545, 0xCB);
            return 0;
        }
        if (sp24 == 0xB) {
            func_80800EF8_gcsectionskip(0x1544, 0xCB);
            return 0;
        }
        goto final_checks;
    case 19:
        if (sp24 != 8) {
            func_80800EF8_gcsectionskip(0xF56, 0xCB);
            func_808002A0_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 20:
        if (sp24 != 1) {
            func_808002A0_gcsectionskip(sp28, arg0);
            func_80800EF8_gcsectionskip(0x1221, 0x22);
            return 0;
        }
        if (func_800C6E38(0x15) == 0) {
            func_808002A0_gcsectionskip(sp28, arg0);
            func_80800EF8_gcsectionskip(0x1227, 0x22);
            return 0;
        }
        if (func_800C6E38(0x2E) == 0) {
            func_808002A0_gcsectionskip(sp28, arg0);
            func_80800EF8_gcsectionskip(0x122A, 0x22);
            return 0;
        }
        if (func_800DA298(0x44) != 0 && func_800DA298(0x43) == 0) {
            arg1 = 0x19A;
            arg2 = 1;
        }
        goto final_checks;
    case 21:
        if (func_800DA298(0x360) != 0) {
            arg1 = 0x19B;
        }
        goto final_checks;
    case 22:
        if (func_800F64A4(sp28, 0x601) == 0) {
            func_80800EF8_gcsectionskip(0x1211, 0x6F);
            func_808002A0_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 23:
        if (func_800F64A4(sp28, 0x801) == 0) {
            func_80800EF8_gcsectionskip(0x1223, 0x6F);
            func_808002A0_gcsectionskip(sp28, arg0);
            return 0;
        }
        if (func_800C6E38(0x1F) == 0 || func_800C6E38(0x2D) == 0) {
            func_80800EF8_gcsectionskip(0x1226, 0x6F);
            func_808002A0_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 24:
        if (sp24 == 0x11) {
            func_80800374_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 25: {
        u32 sp20;
        sp20 = func_800F54E4();
        if (sp24 == 0x11) {
            func_80800374_gcsectionskip(sp28, arg0);
            return 0;
        }
        func_800F7C9C(sp20, 0x95, func_800EA05C(), 2);
        goto final_checks;
    }
    case 26: {
        u32 sp1C;
        sp1C = func_800F54E4();
        if (sp24 == 0x11) {
            func_80800374_gcsectionskip(sp28, arg0);
            return 0;
        }
        func_800F7C9C(sp1C, 0x95, func_800EA05C(), 2);
        func_800F7B9C(sp1C, 0x96);
        goto final_checks;
    }
    case 27:
        if (sp24 == 0x11) {
            func_80800374_gcsectionskip(sp28, arg0);
            return 0;
        }
        if (sp24 != 1) {
            if (func_800F7E3C(sp28, 0x1224) != 0) {
                _chmrtannoy_entrypoint_0();
            }
            func_808002A0_gcsectionskip(sp28, arg0);
            return 0;
        }
        if (func_800C6E38(0x2D) == 0) {
            if (func_800F7E3C(sp28, 0x122B) != 0) {
                _chmrtannoy_entrypoint_0();
            }
            func_808002A0_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 28:
        if (sp24 == 8) {
            func_80800374_gcsectionskip(sp28, arg0);
            func_808002A0_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 30:
        if (sp24 == 0xD) {
            func_800F7E3C(sp28, 0x1215);
            func_808002A0_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 31:
        if (func_800DA298(0x360) == 0 && func_800DA298(0x3B) == 0) {
            func_800F7E3C(sp28, 0x1566);
            func_808002A0_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    case 32:
        if (func_800C6E38(0x2F) == 0) {
            func_800F7E3C(sp28, 0x122C);
            func_808002A0_gcsectionskip(sp28, arg0);
            return 0;
        }
        goto final_checks;
    default:
final_checks:
    if (func_800D395C() != 0 || func_800D3948() != 0) {
        func_808002A0_gcsectionskip(sp28, arg0);
        return 0;
    }
    if (sp2C != 0 && sp24 != 1) {
        s32 level;
        s32 section;
        s32 sameSection;

        level = D_8012762C;
        section = _gcsectionDll_entrypoint_4(arg1);
        sameSection = section == level && sp24 == 0xD;
        if (level != section || (level == 0x1A && !sameSection)) {
            func_80800374_gcsectionskip(sp28, arg0, level);
            return 0;
        }
    }
    if (func_800A8264() != 0) {
        return 0;
    }
    _gcgoto_entrypoint_3(arg0, arg1, arg2);
    return 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/sectionskip/func_80800D3C_gcsectionskip.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/sectionskip/func_80800EF8_gcsectionskip.s")
