#include "gc/sectionskip.h"

s32 func_80800000_gcsectionskip(f32 *arg0, f32 *arg1, f32 arg2, s32 arg3) {
    void func_800EE7F8(f32 *, f32 *);
    int func_800EECE0(f32 *, f32 *);
    f32 mlAbsF(f32);
    f32 sqrtf(f32);
    f32 original[3];
    f32 dx;
    f32 dz;
    f32 root;
    f32 scale;
    f32 sum;
    f32 x;
    f32 z;
    f32 absolute;

    func_800EE7F8(original, arg0);
    if (arg3 == 0) {
        dx = (arg1[0] + arg2) - arg0[0];
        if (arg2 < dx) {
            dx -= 2.0f * arg2;
        }
        dz = (arg1[2] + arg2) - arg0[2];
        if (arg2 < dz) {
            dz -= 2.0f * arg2;
        }
        absolute = mlAbsF(dx);
        if (absolute < mlAbsF(dz)) {
            arg0[0] += dx;
        } else {
            arg0[2] += dz;
        }
    } else {
        root = sqrtf(2.0f);
        scale = (2.0f * arg2) / root;
        x = arg0[0] - arg1[0];
        z = arg0[2] - arg1[2];
        absolute = mlAbsF(x);
        sum = mlAbsF(z) + absolute;
        x = (x * scale) / sum;
        z = (z * scale) / sum;
        arg0[0] = arg1[0] + x;
        arg0[2] = arg1[2] + z;
    }
    if (func_800EECE0(original, arg0) != 0) {
        return 0;
    }
    return 1;
}

void func_8080019C_gcsectionskip(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    s32 func_80800000_gcsectionskip(f32 *, f32 *, f32, s32);
    f32 sp64[3];
    f32 sp58[3];
    s32 i;
    s32 flag;
    f32 divisor;

    func_800EE7F8(sp64, arg1);
    divisor = 4.0f;
    flag = (s32)arg4;
    for (i = 0; i < 4; i++) {
        func_800EFE50(sp58, arg1, arg0, (f32)i / divisor);
        if (func_80800000_gcsectionskip(sp58, arg2, arg3, flag)) {
            func_800EE7F8(sp64, sp58);
        } else {
            break;
        }
    }
    func_800EE7F8(arg1, sp64);
}    typedef struct { u8 pad0[0x6]; u16 unk6; } Objsectionskip_func_808002A0_gcsectionskip_node; /* offsets.py genstruct: fields from raw offsets on node; rename once understood */

/* extern */

void func_808002A0_gcsectionskip(BtIntPtr arg0, s16 *arg1) {
    void func_800EFB24(void *, void *, void *);
    void func_800F5D70(BtIntPtr, f32 *);
    void func_800F5D9C(BtIntPtr, f32 *);
    s32 func_800F8418(BtIntPtr, f32 *);
    void func_8080019C_gcsectionskip(f32 *, f32 *, f32 *, f32, f32);
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    s32 sp2C;
    f32 sp28;

    register s16 *node = arg1;

    if (node != NULL) {
        sp2C = (u32)*((u8 *)node + 0x13) >> 7;
        sp28 = (f32)((u32)*&((Objsectionskip_func_808002A0_gcsectionskip_node *)node)->unk6 >> 7);
        func_800F5D9C(arg0, sp30);
        func_800F5D70(arg0, sp3C);
        func_800EF334(sp3C, func_800D8FF8());
        func_800EFB24(sp48, sp30, sp3C);
        func_800EE88C(sp54, arg1);
        func_8080019C_gcsectionskip(sp48, sp30, sp54, sp28, (f32)sp2C);
        func_800F8418(arg0, sp30);
    }
}

void func_80800374_gcsectionskip(BtIntPtr arg0, BtIntPtr arg1) {
    func_800F7E3C(arg0, 0);
    func_808002A0_gcsectionskip(arg0, arg1);
}

void gcsectionskip_entrypoint_0(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0xDAA) {
        func_800DA524(FLAG2_6C9_UNK);
    }
}

s32 gcsectionskip_entrypoint_1(BtIntPtr arg0, s32 arg1, s32 arg2, u32 arg3, u8 *arg4) {
    s32 _chchuffycont_entrypoint_0(s32 *, s32 *);
    s32 _chchuffycont_entrypoint_1(s32 *, s32 *);
    s32 func_800A8264(void);
    int func_800C6E38(s32);
    s32 func_800D3948(void);
    s32 func_800D395C(void);
    s32 func_800DC298(f32);
    s32 func_800F4BE4(BtIntPtr);
    s32 func_800F5410(BtIntPtr);
    s32 func_800F66F0(BtIntPtr);
    s32 func_800F6CC8(BtIntPtr);
    s32 func_800F6D24(BtIntPtr);
    s32 func_800F70BC(BtIntPtr);
    s32 func_800F7C9C(BtIntPtr, s32, s32, s32);
    s32 func_800F8B88(void);
    void func_80800374_gcsectionskip();
    s32 func_80800D3C_gcsectionskip(s32 *, s32 *);
    void func_80800EF8_gcsectionskip(s32, s32);
    extern u8 D_8012762C;
    extern u8 D_80801040_gcsectionskip[];
    s32 sp2C;
    BtUIntPtr sp28;
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
        BtUIntPtr sp20;
        sp20 = func_800F54E4();
        if (sp24 == 0x11) {
            func_80800374_gcsectionskip(sp28, arg0);
            return 0;
        }
        func_800F7C9C(sp20, 0x95, func_800EA05C(), 2);
        goto final_checks;
    }
    case 26: {
        BtUIntPtr sp1C;
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
        section = BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4(arg1);
        sameSection = section == level && sp24 == 0xD;
        if (level != section || (level == 0x1A && !sameSection)) {
#ifdef BT_NATIVE
            ((void (*)())func_80800374_gcsectionskip)(sp28, arg0, level);
#else
            func_80800374_gcsectionskip(sp28, arg0, level);
#endif
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

s32 func_80800D3C_gcsectionskip(s32 *arg0, s32 *arg1) {
    s32 func_800F5410(BtIntPtr);
    enum map_e map;

    if (func_800F5410(func_800F54E4()) != 1) {
        return 0;
    }
    map = func_800EA05C();
    switch (map) {
    case MAP_AF_SM_SPIRAL_MOUNTAIN:
        if (func_800DA298(FLAG_318_PROGRESS_DEFEATED_KLUNGO_1)) {
            *arg0 = 0x142;
            *arg1 = 3;
        }
        break;
    case MAP_142_JV_JINJO_VILLAGE:
        if (func_800DA298(FLAG_318_PROGRESS_DEFEATED_KLUNGO_1)) {
            *arg0 = 0xAF;
            *arg1 = 3;
        } else {
            *arg1 = 1;
        }
        break;
    case MAP_15A_IOH_WASTELAND:
        if (func_800DA298(FLAG_319_PROGRESS_DEFEATED_KLUNGO_2)) {
            *arg0 = 0x154;
            *arg1 = 3;
        } else {
            *arg1 = 1;
        }
        break;
    case MAP_154_IOH_PINE_GROVE:
        if (func_800DA298(FLAG_319_PROGRESS_DEFEATED_KLUNGO_2)) {
            *arg0 = 0x15A;
            *arg1 = 1;
        }
        break;
    case MAP_15D_CK_CAULDRON_KEEP:
        if (func_800DA298(FLAG_31A_PROGRESS_DEFEATED_KLUNGO_3)) {
            *arg0 = 0x15F;
            if (func_800DA298(FLAG_441_UNK)) {
                *arg1 = 3;
            } else {
                *arg1 = 1;
            }
        }
        break;
    case MAP_15F_CK_QUIZ:
        if (func_800DA298(FLAG_31A_PROGRESS_DEFEATED_KLUNGO_3)) {
            *arg0 = 0x15D;
            *arg1 = 2;
        } else {
            *arg1 = 1;
        }
        break;
    }
    return 1;
}

void func_80800EF8_gcsectionskip(s32 arg0, s32 arg1) { func_800C05B8(arg0, 0, NULL, NULL, 0, 0, arg1); }
/* data_to_c.py: from asm/data/overlays/gc/sectionskip.data.s */
u8 D_80801040_gcsectionskip [16] BT_DATA(4, overlays_gc_sectionskip, 0x0) = { 0, 0x16, 0x23, 0x28, 0x17, 0x13, 0x24, 0x25, 0x15, 0x14, 0, 0, 0, 0, 0, 0 };
