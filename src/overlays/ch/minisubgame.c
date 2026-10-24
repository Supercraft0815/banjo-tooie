#include "common.h"

OSThread *chminisubgame_entrypoint_0(void)
{
    extern u8 D_80801424_chminisubgame[];

    return (OSThread *) D_80801424_chminisubgame;
}

OSThread *chminisubgame_entrypoint_1(void)
{
    extern u8 D_8080146C_chminisubgame[];

    return (OSThread *) D_8080146C_chminisubgame;
}

void func_80800018_chminisubgame(Actor *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 _susubgame_entrypoint_11(s32);
    void *func_80100094(Actor *, u32);
    extern Prop *B_80801590_chminisubgame[];
    u32 *data;
    Prop **prop;
    s32 count;
    s32 i;
    f32 *position;

    data = func_80100094(arg0, 0U);
    count = _gccubesearch_entrypoint_9(0x1C0, B_80801590_chminisubgame, 0x3C);
    arg0->actorData[6] = count;
    i = 0;
    if (count > 0) {
        prop = B_80801590_chminisubgame;
        position = (f32 *)data;
        do {
            _gspropctrl_entrypoint_11(*prop, position);
            i++;
            prop++;
            position += 3;
        } while (i < (s32)arg0->actorData[6]);
    }
    _susubgame_entrypoint_0(arg0, data + 0xC3, 0);
    _susubgame_entrypoint_11(0);
}

void func_808000C8_chminisubgame(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void func_80090708(s32);
    void func_800BF99C(s32, s32, s32);
    s32 func_800CEAD0(s32);
    s32 func_800D0A9C(u32, u32);
    s32 func_800D0B68(u32, u32);
    s32 func_800D2054(s32, s32, s32);
    s32 func_800D24E8(s32, s32, u32);
    s32 func_800D395C(void);
    s32 func_800D90A4(f32 *);
    f32 func_800DC0C0(void);
    int func_800DC298(f32);
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, s32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    s32 func_80800AAC_chminisubgame(Actor *);
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    u8 *sp34;
    s32 sp30;
    s32 sp2C;
    f32 sp28;
    s16 sp24[2];
    u8 *sp20;

    switch (arg0->unk70_10) {
    case 2:
        func_800D24E8(0xFC, arg0->actorData[4], 0);
        if (func_800CEAD0(0)) {
            sp40 = 4;
            sp38 = func_800D2054(0, 0x88, arg0->actorData[4]);
            sp34 = func_80100094(arg0, 0);
            func_800BF99C(0, 0x5AA, 1);
            func_80090708(2);
            _susubgame_entrypoint_5(arg0, sp34 + 0x30C, 5, 1, 0);
            func_80101180(0x4AE, 0x3E, 0);
            if (func_800D395C()) {
                if (sp38 == 1) {
                    sp44 = 0x104A;
                    sp3C = 0x16;
                } else if (sp38 == 0) {
                    sp44 = 0x104B;
                    sp3C = 0x17;
                } else {
                    sp44 = 0x104C;
                    sp3C = 0x17;
                }
            } else if (!func_800D0A9C(0x1F, 1) && (s32)arg0->actorData[4] >= 0x3C) {
                sp44 = 0x1030;
                sp40 = 0x44;
                sp3C = 0x16;
            } else {
                sp40 = 6;
                if (!func_800D0A9C(0x1F, 1)) {
                    switch (arg0->actorData[4]) {
                    default:
                        sp44 = 0x1032;
                        sp3C = 0x17;
                        break;
                    case 0:
                        sp44 = 0x1034;
                        sp3C = 0x17;
                        break;
                    case 1:
                        sp44 = 0x1046;
                        sp3C = 0x17;
                        break;
                    }
                } else if (sp38 == 1) {
                    sp44 = 0x1031;
                    sp3C = 0x16;
                } else {
                    sp44 = arg0->actorData[4] ? 0x1033 : 0x1034;
                    sp3C = 0x17;
                }
            }
            func_800FDC28(0);
            func_800FC6B0(sp3C);
            _subaddiedialog_entrypoint_11(arg0->unk0, sp44, sp40, NULL, 0x22);
            func_80101FDC(arg0, 3);
            break;
        }
    case 1:
        if ((s32)arg0->actorData[5] < 0xF && func_800DC298(0.2f)) {
            sp30 = func_80800AAC_chminisubgame(arg0);
            sp2C = 0;
            sp28 = func_800DC0C0();
            if (sp28 < 0.1666666f) {
                sp2C = 2;
            } else if (sp28 < 0.5f) {
                sp2C = 1;
            }
            if (sp30 != -1) {
                sp24[0] = sp2C;
                sp24[1] = sp30;
                func_80108B04(arg0, *(u32 *)sp24);
            }
        }
        break;
    case 5:
        if (func_800D0B68(0x1F, 1) && func_800D90A4((f32 *)arg0->actorData)) {
            sp20 = func_80100094(arg0, 0);
            func_80090708(2);
            _susubgame_entrypoint_5(arg0, sp20 + 0x30C, 5, 1, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x46, NULL, 0x22);
            func_80101FDC(arg0, 3);
        }
        break;
    }
}

void func_80800430_chminisubgame(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    _susubgame_entrypoint_11(0);
    if (_susubgame_entrypoint_2(arg0, (s32) (sp1C + 0x30C)) != 0) {
        _susubgame_entrypoint_4(arg0, (s32) (sp1C + 0x30C));
    }
}

s32 func_80800484_chminisubgame(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_19(f32[3]);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiefade_entrypoint_2();
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    void func_80090708(s32);
    void func_800BF99C(s32, s32, s32);
    s32 func_800D0A9C(u32, u32);
    s32 func_800D0B68(u32, u32);
    s16 func_800D211C(s32);
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    f32 func_800DC178(f32, f32);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    void func_80101FDC(Actor *, u32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_80103140(Actor *, u32, u16);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    void func_80108B04(Actor *, u32);
    void func_80800BA8_chminisubgame(Actor *, s32, s32);
    extern s16 D_80801400_chminisubgame[][6];
    u8 *data;
    Actor *child;
    s32 index;
    s32 type;
    f32 position[3];
    f32 rotation[3];
    s16 packed[2];
    void *entry;

    data = func_80100094(arg0, 0U);
    switch (arg1) {
    case 0x95:
        if (func_800D0A9C(0x1F, 1) && !func_800D0B68(0x1F, 1)) {
            func_80101FDC(arg0, 5);
            ((f32 *)arg0->actorData)[0] = 0.5f;
        } else {
            func_80090708(2);
            func_800DA544(0);
            if (func_800D395C()) {
                _susubgame_entrypoint_5(arg0, data + 0x30C, 5, 1, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1049, 6, NULL, 0x22);
            } else if (func_800DA298(0x6E5)) {
                _susubgame_entrypoint_5(arg0, data + 0x30C, 5, 1, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x102D, 6, NULL, 0x22);
            } else {
                _susubgame_entrypoint_6(arg0, data + 0x30C, 5, 0x20, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, !func_800D0A9C(0x1F, 1) ? 0x102C : 0x102D, 6, NULL, 0x22);
            }
        }
        break;
    case 0x3D:
        index = ((s16 *)&arg2)[1];
        type = ((s16 *)&arg2)[0];
        if (index < 0) {
            func_800EE7F8(position, arg0->position);
        } else {
            func_800EE7F8(position, ((f32 (*)[3])data)[index]);
            data[index + 0x2D0] = 1;
            arg0->actorData[5]++;
        }
        child = func_80108528(0x4AE, position, 0, &arg0);
        child->unk3C = arg0->unk0;
        if (index >= 0) {
            func_800E3980(rotation);
            child->rotation[1] = func_80102D78(arg0, rotation);
        }
        child->unk6C_0 = type;
        child->actorData[7] = index;
        entry = D_80801400_chminisubgame[type];
        func_80103140(child, (u16)((s16 *)entry)[0], 0);
        ((f32 *)child->actorData)[3] = func_800DC178(((s16 *)entry)[1], ((s16 *)entry)[2]);
        child->unk58 = func_800DC178(((s16 *)entry)[3], ((s16 *)entry)[4]);
        ((f32 *)child->actorData)[5] = child->unk58;
        ((f32 *)child->actorData)[6] = child->position[1];
        ((f32 *)child->actorData)[4] = 0.0f;
        child->unk50 = ((s16 *)entry)[5];
        if (index < 0) {
            arg0->unk3C = child->unk0;
        }
        if (index >= 0 || child->unk6C_0 == 2) {
            _subaddiefade_entrypoint_2(child);
        }
        return 1;
    case 0x2E:
        func_80800BA8_chminisubgame(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x30:
        switch (((s16 *)&arg2)[0]) {
        case 0x1032:
            return arg0->actorData[4];
        case 0x102C:
            return 60;
        case 0x1033:
        case 0x104C:
            if (!((s16 *)&arg2)[1]) {
                return arg0->actorData[4];
            }
            break;
        }
        return func_800D211C(0x88);
    case 0x2F:
        packed[0] = ((s16 *)&arg2)[1] - 1;
        packed[1] = -1;
        if (((s16 *)&arg2)[1] == 3) {
            _susubgame_entrypoint_6(arg0, data + 0x30C, 9, 0xA0, 0);
        }
        func_80108B04(arg0, *(u32 *)packed);
        entry = arg0->unk3C;
        if (entry != NULL) {
            func_8010114C((s32)entry, 0x3E, 0);
            arg0->unk3C = NULL;
        }
        break;
    case 0xE:
        if (arg2 == 9) {
            entry = arg0->unk3C;
            if (entry != NULL) {
                _capod_entrypoint_19(func_80106790(entry)->position);
            }
        }
        return 3;
    case 0xB:
        if (arg2 == 1) {
            func_80090708(0);
            _susubgame_entrypoint_4(arg0, (s32)(data + 0x30C));
            func_80101FDC(arg0, 5);
            ((f32 *)arg0->actorData)[0] = 0.5f;
            return 4;
        }
        return 3;
    case 0x57:
        return _susubgame_entrypoint_3(arg0, data + 0x30C, arg2 & 0xFFFF, (arg2 & 0xFFFF0000) >> 16);
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        func_800BF99C(0, 0x5AA, 1);
        func_80101180(0x4AE, 0x3E, 0);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x46, NULL, 0x22);
        func_80101FDC(arg0, 3);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800A64_chminisubgame(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    arg0->actorData[5] -= 1;
    (*(s8 *)((s8 *)((temp_v0 + arg1)) + (0x2D0))) = 2;
}

s32 func_80800AAC_chminisubgame(Actor *arg0) {
    void func_8008FE68(f32 *);
    s32 func_800DC128(s32, s32);
    f32 func_800EEAD4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    f32 (*data)[3];
    f32 position[3];
    s32 index;
    s32 i;

    data = func_80100094(arg0, 0U);
    func_8008FE68(position);
    for (i = 0; i < (s32)arg0->actorData[6]; i++) {
        index = func_800DC128(0, arg0->actorData[6]);
        if (func_800EEAD4(data[index], position) > 1200.0f) {
            if (2 == ((u8 *)data)[index + 0x2D0]) {
                ((u8 *)data)[index + 0x2D0] = 0;
            } else if (((u8 *)data)[index + 0x2D0] == 0) {
                return index;
            }
        }
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800BA8_chminisubgame.s")

/* extern */

void func_80800EC8_chminisubgame(Actor *arg0) {
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    void func_800E3980(f32 *);
    void func_80102424(Actor *, s32);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_8010C9B0(f32 *, s32);
    void func_8010D600(s32);
    s32 func_80801058_chminisubgame(Actor *, s32, s32);
    f32 sp34[3];
    f32 sp28[3];
    u32 state;

    state = arg0->unk70_10;
    if (state != 1) {
        if (state != 2) {
            if (state == 3) {
                if ((s32)arg0->actorData[7] >= 0) {
                    func_800E3980(sp34);
                    arg0->unk54 = func_80102D78(arg0, sp34);
                    func_80102BF8(arg0, 0.1f, 4.0f, 180.0f);
                }
                if (func_800DA298(0) == 0) {
                    func_80102424(arg0, 1);
                }
            }
        } else {
            goto block_9;
        }
    } else {
        if (arg0->unk58 < 5.0f) {
            func_80102424(arg0, 2);
        }
block_9:
        func_8010D600((s32)sp28);
        arg0->unk54 = func_80102D78(arg0, sp28);
        func_80102BF8(arg0, 0.1f, 4.0f, 180.0f);
        ((f32 *)arg0->actorData)[4] += (240.0f + (arg0->unk58 / ((f32 *)arg0->actorData)[5]) * -120.0f) * func_800D8FF8();
        arg0->position[1] = ((f32 *)arg0->actorData)[6] + func_80013970(((f32 *)arg0->actorData)[4]) * arg0->unk50;
        if (func_800D9078(&arg0->unk58) || func_8010C9B0(arg0->position, (s32)((f32 *)arg0->actorData)[3])) {
            func_80801058_chminisubgame(arg0, 0x3E, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80801058_chminisubgame.s")

void func_808011DC_chminisubgame(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808014B4_chminisubgame;
    s32 sp24;
    f32 *temp_a1;
    s32 temp_v0;

    temp_v0 = func_800B53A4(arg2);
    sp24 = temp_v0;
    func_800BA670(temp_v0, arg1);
    temp_a1 = arg0 + 4;
    func_800BABB8(sp24, temp_a1, temp_a1, (*(f32 *)((s8 *)(arg0) + (0x38))), &D_808014B4_chminisubgame);
    func_800BA22C(sp24, arg2);
}

void func_80801248_chminisubgame(Actor *arg0) {
    s32 func_80090270();
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    s32 func_800CEAD0(s32);
    s32 func_800DA298(s32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    extern s32 D_808014F0_chminisubgame;
    extern s32 D_80801534_chminisubgame;
    extern s32 D_80801578_chminisubgame;
    f32 *position;

    if (func_80090270() == 0 && (func_800DA298(0) != 0 || func_800CEAD0(0) == 0)) {
        position = arg0->position;
        func_800E1610(0, 20.0f, 0.6f, position);
        func_800C4AF0(position, &D_80801578_chminisubgame);
    }
    position = arg0->position;
    func_808011DC_chminisubgame((u8 *)arg0, arg0->unk6C_0 * 3 + 0x9A4, 2);
    func_808011DC_chminisubgame((u8 *)arg0, arg0->unk6C_0 * 3 + 0x9A5, 6);
    func_808011DC_chminisubgame((u8 *)arg0, arg0->unk6C_0 * 3 + 0x9A6, 4);
    func_800BABB8(0, position, NULL, 1.0f, &D_808014F0_chminisubgame);
    func_800BABB8(0, position, NULL, 1.0f, &D_80801534_chminisubgame);
}
