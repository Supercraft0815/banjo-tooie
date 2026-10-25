#include "common.h"

s32 func_800D0A9C(u32, u32);

OSThread *chwaspnestgame_entrypoint_0(void)
{
    extern u8 D_80801F80_chwaspnestgame[];

    return (OSThread *) D_80801F80_chwaspnestgame;
}

OSThread *chwaspnestgame_entrypoint_1(void)
{
    extern u8 D_80801FC8_chwaspnestgame[];

    return (OSThread *) D_80801FC8_chwaspnestgame;
}

s32 func_800DA544(s32);
void func_80090708(s32);
s32 func_80101180(s32, s32, s32);
s32 func_800D395C(void);
void func_80101FDC(Actor *, u32);
void func_80800018_chwaspnestgame(Actor *arg0, s32 arg1) {
    s32 _gcfrontend_entrypoint_9(s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _susubgame_entrypoint_4(void *, void *);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    s32 func_800D2054(s32, s32, s32);
    void func_800D2770(s32, s32);
    s32 func_800DA524(s32);
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    u8 *sp3C;
    s32 text;
    s32 pad34;
    s32 music;
    s32 result;
    s32 pad28;
    s32 remaining;

    sp3C = func_80100094(arg0, 0);
    switch (arg1) {
    case 2:
        func_800DA524(0);
        _susubgame_entrypoint_4(arg0, sp3C + 0x24);
        func_800DA544(0x6E6);
        _gcfrontend_entrypoint_9(0x73);
        func_800FDC28(0xC);
        func_80090708(0);
        arg0->actorData[7] = 0;
        arg0->actorData[3] = 0;
        func_800CE8D8(0, 60.0f, 60);
        func_800CE88C(0, 1);
        func_800D2770(0xF5, 0);
        break;
    case 3:
        result = func_800D2054(0, 0x87, arg0->actorData[3]);
        func_80090708(2);
        _susubgame_entrypoint_5(arg0, sp3C + 0x24, 5, 1, 0);
        func_80101180(0x1E4, 0x45, 0);
        if (func_800D395C()) {
            if (result == 1) {
                text = 0x144E;
                music = 0x16;
            } else if (result == 0) {
                text = 0x144F;
                music = 0x17;
            } else {
                text = 0x1450;
                music = 0x17;
            }
        } else if (!func_800D0A9C(0x18, 4) && (s32)arg0->actorData[3] >= 40) {
            text = 0x140A;
            music = 0x16;
        } else if (!func_800D0A9C(0x4B, 1) && (s32)arg0->actorData[3] >= 50) {
            text = 0x140C;
            music = 0x16;
        } else {
            remaining = !func_800D0A9C(0x4B, 1);
            if (!func_800D0A9C(0x18, 4) + remaining) {
                switch (arg0->actorData[3]) {
                default:
                    text = 0x140E;
                    music = 0x17;
                    break;
                case 0:
                    text = 0x1410;
                    music = 0x17;
                    break;
                case 1:
                    text = 0x144C;
                    music = 0x17;
                    break;
                }
            } else if (result == 1) {
                text = 0x140D;
                music = 0x16;
            } else {
                if (arg0->actorData[3] != 0) {
                    text = 0x140F;
                } else {
                    text = 0x1410;
                }
                music = 0x17;
            }
        }
        func_800FDC28(0);
        func_800FC6B0(music);
        _subaddiedialog_entrypoint_11(arg0->unk0, text, 6, NULL, 0x99);
        break;
    case 5:
        func_80090708(0);
        _susubgame_entrypoint_4(arg0, sp3C + 0x24);
        arg0->unk58 = 0.5f;
        break;
    }
    func_80101FDC(arg0, arg1);
}

/* extern */

void func_808002EC_chwaspnestgame(Actor *arg0) {
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, f32 *, s32);
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 _susubgame_entrypoint_11(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    void *func_80100094(Actor *, u32);
    s32 var_s0;
    int var_s1;
    u8 *temp_s6;
    u8 *var_s1_2;
    u8 *var_s2;
    f32 sp58[3];
    u8 *var_s3;

    temp_s6 = func_80100094(arg0, 0);
    _subaddiemarker_entrypoint_0(arg0, 0x201, sp58, 1);
    func_800EE7F8((f32 *)arg0->actorData, sp58);
    for (var_s0 = 0; var_s0 * 12 < 24; var_s0++) {
        func_800EFD24((f32 *)(temp_s6 + var_s0 * 12));
        *(f32 *)(temp_s6 + 0x18 + var_s0 * 4) = -1.0f;
    }
    var_s0 = 0;
    var_s1_2 = temp_s6 + 0x3C;
    do {
        _subaddiemarker_entrypoint_1(arg0, 0x1C0, var_s0 + 0x33, sp58, 1);
        func_800EE7F8((f32 *)var_s1_2, sp58);
        var_s0 += 1;
        var_s1_2 += 12;
    } while (var_s0 != 3);
    _susubgame_entrypoint_0(arg0, (u32 *)(temp_s6 + 0x24), 0);
    _susubgame_entrypoint_11(0);
}

/* extern */

void func_80800400_chwaspnestgame(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    s32 _susubgame_entrypoint_2(void *, void *);
    s32 _susubgame_entrypoint_4(void *, void *);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;
    s32 var_v1;

    temp_v0 = func_80100094(arg0, 0);
    for (var_v1 = 0; var_v1 < 2; var_v1++) {
        temp_v0[0x20 + var_v1] = 0;
    }
    _susubgame_entrypoint_11(0);
    if (_susubgame_entrypoint_2(arg0, temp_v0 + 0x24) != 0) {
        _susubgame_entrypoint_4(arg0, temp_v0 + 0x24);
    }
    func_800FDC28(0xC);
}

s32 func_800D0B68(u32, u32);
void func_80108B04(Actor *, u32);
void func_8080047C_chwaspnestgame(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void func_800C3224(u8, f32, f32, f32);
    u8 func_800C4350(u8, f32 *, s32 *);
    s32 func_800CEAD0(s32);
    s32 func_800D24E8(s32, s32, u32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC0C0(void);
    int func_800DC298(f32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80802010_chwaspnestgame[];
    struct NestData {
        f32 position[2][3];
        f32 timer[2];
        u8 sound[2];
        u8 pad[2];
        u32 game[1];
    } *data, *gameData;
    u32 i;
    s32 choice;
    f32 random;

    data = func_80100094(arg0, 0);
    for (i = 0; i != 2; i++) {
        if (data->timer[i] > 0.0f) {
            if (data->sound[i] == 0) {
                data->sound[i] = func_800C4350(0, data->position[i], D_80802010_chwaspnestgame);
            }
            if (arg0->unk70_10 == 2) {
                func_800C3224(data->sound[i], 1.0f, 1.1f, 0.05f);
            } else {
                func_800C3224(data->sound[i], 0.8f, 0.9f, 0.05f);
            }
            func_800C4350(data->sound[i], data->position[i], NULL);
            data->timer[i] = -1.0f;
        }
    }
    switch (arg0->unk70_10) {
        case 1:
            break;
        case 2:
            func_800D24E8(0xF5, arg0->actorData[3], 0);
            if ((s32)arg0->actorData[7] < 10 && func_800DC298(0.09999084473f)) {
                choice = 1;
                random = func_800DC0C0();
                if (random < 0.1666665971f) {
                    choice = 3;
                } else if (random < 0.5f) {
                    choice = 2;
                }
                func_80108B04(arg0, choice);
            }
            if (func_800CEAD0(0)) {
                func_80800018_chwaspnestgame(arg0, 3);
            }
            break;
        case 5:
            if ((!func_800D0A9C(0x4B, 1) || func_800D0B68(0x4B, 1)) &&
                (!func_800D0A9C(0x18, 4) || func_800D0B68(0x18, 4)) &&
                func_800D90A4(&arg0->unk58)) {
                gameData = func_80100094(arg0, 0);
                func_80090708(2);
                _susubgame_entrypoint_5(arg0, gameData->game, 5, 1, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x46, NULL, 0x99);
                func_80101FDC(arg0, 3);
            }
            break;
    }
}

s32 func_80800724_chwaspnestgame(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    void func_80800018_chwaspnestgame(Actor *, s32);
    void func_80800B80_chwaspnestgame(Actor *);
    void func_80800C7C_chwaspnestgame(Actor *, s32);
    void func_80800D7C_chwaspnestgame(Actor *, s32);
    s32 func_80800DE4_chwaspnestgame(Actor *, s32);
    s32 func_80800EB8_chwaspnestgame(void *, s32, s32);
    void func_80800F98_chwaspnestgame(Actor *, s32, s32);
    extern s16 D_80801F76_chwaspnestgame[];
    u8 *sp34;
    s32 sp30;
    s16 *sp2C;
    s32 sp28;

    sp34 = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x95:
            if ((func_800D0A9C(0x4B, 1) && !func_800D0B68(0x4B, 1)) ||
                (func_800D0A9C(0x18, 4) && !func_800D0B68(0x18, 4))) {
                *(f32 *)((u8 *)arg0 + 0x58) = 0.5f;
                func_80101FDC(arg0, 5);
            } else {
                func_80090708(2);
                if (func_800D395C()) {
                    _susubgame_entrypoint_5(arg0, sp34 + 0x24, 5, 1, 0);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x144D, 6, 0, 0x99);
                } else if (func_800DA298(0x6E6)) {
                    _susubgame_entrypoint_5(arg0, sp34 + 0x24, 5, 1, 0);
                    sp28 = !func_800D0A9C(0x4B, 1);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, -!func_800D0A9C(0x18, 4) - sp28 + 0x144B, 6, 0, 0x99);
                } else {
                    _susubgame_entrypoint_6(arg0, sp34 + 0x24, 8, 0x20, 0);
                    sp28 = !func_800D0A9C(0x4B, 1);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, -!func_800D0A9C(0x18, 4) - sp28 + 0x1407, 6, 0, 0x99);
                    func_800DA544(0);
                    func_80108B04(arg0, 0);
                }
                func_80800018_chwaspnestgame(arg0, 1);
            }
            break;
        case 0x3D:
            if (arg2 > 0) {
                func_80800C7C_chwaspnestgame(arg0, arg2);
            } else if (arg2 < 0) {
                func_80800D7C_chwaspnestgame(arg0, -arg2);
            } else {
                func_80800B80_chwaspnestgame(arg0);
            }
            break;
        case 0x2E:
            sp2C = (s16 *)&arg2;
            func_80800F98_chwaspnestgame(arg0, sp2C[0], sp2C[1]);
            break;
        case 0x30:
            sp2C = (s16 *)&arg2;
            return func_80800EB8_chwaspnestgame(arg0, sp2C[0], sp2C[1]);
        case 0x2F:
            sp2C = (s16 *)&arg2;
            sp30 = sp2C[1];
            func_80101180(0x1E4, 0x45, 0);
            _susubgame_entrypoint_6(arg0, sp34 + 0x24, D_80801F76_chwaspnestgame[sp30], 0x20, 0);
            func_80108B04(arg0, -sp30);
            break;
        case 0xB:
            return func_80800DE4_chwaspnestgame(arg0, arg2);
        case 0x57:
            return _susubgame_entrypoint_3(arg0, sp34 + 0x24, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x96:
            if (!func_800D395C()) {
                return 0;
            }
            func_80101180(0x1E4, 0x45, 0);
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0xCEB, 0x46, 0, 0x99);
            func_80101FDC(arg0, 3);
            break;
        default:
            return 0;
    }
    return 1;
}

Actor *func_80800AF8_chwaspnestgame(Actor *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    void func_800EE7F8(f32 *, f32 *);
    Actor *sp1C;
    Actor *temp_v0;
    extern u16 D_80801F70_chwaspnestgame[];

    temp_v0 = func_80108528(0x1E4, arg1, 0, &arg0);
    temp_v0->unk3C = arg0->unk0;
    sp1C = temp_v0;
    func_800EE7F8((f32 *)temp_v0->actorData, arg2);
    sp1C->unk6C_0 = arg3;
    func_80103140(sp1C, D_80801F70_chwaspnestgame[arg3], 0U);
    return sp1C;
}

/* extern */

void func_80800B80_chwaspnestgame(Actor *arg0) {
    void func_8008FE68(f32 *);
    f32 func_80090010();
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 sp2C[3];
    f32 sp20[3];
    Actor *temp_v0;

    func_8008FE68(sp2C);
    func_800EEB9C(sp20, func_80090010(), 300.0f);
    sp20[1] = 100.0f;
    func_800EF04C(sp2C, sp20);
    temp_v0 = func_80800AF8_chwaspnestgame(arg0, arg0->position, arg0->position, 0);
    arg0->unk3C = temp_v0->unk0;
    *((u8 *)temp_v0 + 0x75) &= ~0x10;
}

/* extern */

void func_80800C00_chwaspnestgame(void *arg0, s32 arg1) {
    f32 func_800DC178(f32, f32);
    s32 func_800EF368(void *, s32);
    (*(f32 *)((s8 *)(arg0) + (0))) = func_800DC178(-100.0f, 100.0f);
    (*(f32 *)((s8 *)(arg0) + (4))) = func_800DC178(-100.0f, 100.0f);
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800DC178(-100.0f, 100.0f);
    func_800EF368(arg0, arg1);
}

/* extern */

void func_80800C7C_chwaspnestgame(Actor *arg0, s32 arg1) {
    void func_800EE7B4(f32[3], f32[3], f32[3], f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF3DC(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
    s32 sp7C;
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    func_80800C00_chwaspnestgame(sp40, 0x43FA0000);
    sp40[1] += 1950.0f;
    func_80800C00_chwaspnestgame(sp34, 0x42C80000);
    func_800EE7B4(sp64, sp40, sp34, 100.0f);
    func_800EE7B4(sp70, sp40, sp34, -100.0f);
    func_800EFA4C(sp28, 0.0f, -600.0f, 0.0f);
    if (func_800F0734(sp70, sp64, sp28, 4000.0f, 5100.0f, sp58, sp4C) != 0) {
        func_800EF3DC(sp58, sp34);
        func_800EF04C(sp4C, sp34);
        func_80800AF8_chwaspnestgame(arg0, sp58, sp4C, arg1);
        arg0->actorData[7]++;
    }
}

/* extern */

void func_80800D7C_chwaspnestgame(Actor *arg0, s32 arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    s32 sp34;
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp28, (f32 *)((u8 *)func_80100094(arg0, 0U) + arg1 * 0xC + 0x30));
    func_800EE7F8(sp1C, sp28);
    func_80800AF8_chwaspnestgame(arg0, sp28, sp1C, arg1);
}

s32 func_80800DE4_chwaspnestgame(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void func_80800018_chwaspnestgame(Actor *, s32);
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0:
            if (func_800D0A9C(0x4B, 1) == 0 && (s32)arg0->actorData[3] >= 0x32) {
                _susubgame_entrypoint_5(arg0, data + 0x24, 5, 1, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x140B, 4, NULL, 0x99);
                return 4;
            }
            func_80800018_chwaspnestgame(arg0, 5);
            return 4;
        case 4:
            func_80800018_chwaspnestgame(arg0, 5);
            return 4;
        default:
            return 3;
    }
}

s32 func_80800EB8_chwaspnestgame(void *arg0, s32 arg1, s32 arg2) {
    s32 func_800D211C(s32);

    switch (arg1) {
        case 0x1405:
        case 0x1449:
            return arg2 ? 0x32 : 0x28;
        case 0x1406:
        case 0x144A:
            return 0x32;
        case 0x1409:
            return 0x3C;
        case 0x140E:
        case 0x144C:
            return *(s32 *)((u8 *)arg0 + 0x24);
        case 0x140F:
        case 0x1450:
            if (arg2 == 0) {
                return *(s32 *)((u8 *)arg0 + 0x24);
            }
        default:
            return func_800D211C(0x87);
    }
}

void func_80800F98_chwaspnestgame(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    u32 _gcgoto_entrypoint_1(u32, u32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    void *data;
    s32 dialog;
    s32 flags;
    s32 map;
    s32 exit;

    data = func_80100094(arg0, 0);
    flags = 4;
    dialog = 0;
    switch (arg1) {
        case 0x1405:
        case 0x1406:
        case 0x1407:
            _susubgame_entrypoint_5(arg0, (u8 *)data + 0x24, 5, 1, 0);
            dialog = 0x1408;
            flags = 0x46;
            break;
        case 0x1408:
            if (arg2 == 1) {
                dialog = 0x1409;
                _susubgame_entrypoint_6(arg0, (u8 *)data + 0x24, 0xC, 0x20, 0);
            } else {
                dialog = 0xCEC;
                func_80101180(0x1E4, 0x45, 0);
            }
            break;
        case 0x1409:
            func_80101180(0x1E4, 0x45, 0);
            _susubgame_entrypoint_5(arg0, (u8 *)data + 0x24, 5, 1, 0);
        case 0x1449:
        case 0x144A:
        case 0x144B:
        case 0x144D:
            dialog = 0xCEC;
            break;
        case 0xCEC:
            func_80800018_chwaspnestgame(arg0, 2);
            break;
        case 0xCEB:
            if (func_800D395C() != 0) {
                if (arg2 == 1) {
                    _gcfrontend_entrypoint_11();
                } else {
                    _gcfrontend_entrypoint_10();
                }
            } else {
                if (arg2 == 1) {
                    map = 0x139;
                    exit = 1;
                } else {
                    map = 0x136;
                    exit = 0x13;
                }
                func_80090708(0);
                func_80800018_chwaspnestgame(arg0, 4);
                _gcgoto_entrypoint_1(map, exit);
            }
            break;
        case 0x140A:
            func_800D1000(0x18, 4, arg0->actorData, 1, 0);
            _susubgame_entrypoint_6(arg0, (u8 *)data + 0x24, 0, 0x20, 0);
            break;
        case 0x140B:
        case 0x140C:
            func_800D1000(0x4B, 1, NULL, 1, 0);
            _susubgame_entrypoint_6(arg0, (u8 *)data + 0x24, 4, 0x20, 0);
            break;
        case 0x140D:
        case 0x140E:
        case 0x140F:
        case 0x1410:
        case 0x144C:
        case 0x144E:
        case 0x144F:
        case 0x1450:
            dialog = 0xCEB;
            flags = 0x46;
            break;
    }
    if (dialog != 0) {
        _subaddiedialog_entrypoint_11(arg0->unk0, dialog, flags, NULL, 0x99);
    }
}

/* extern */

void func_80801260_chwaspnestgame(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790();
    void *temp_v0;

    temp_v0 = func_80106790(arg0);
    (*(s32 *)((s8 *)(temp_v0) + (0x24))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (0x24))) + arg1);
    (*(s32 *)((s8 *)(temp_v0) + (0x34))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (0x34))) - 1);
}

/* extern */

void func_8080129C_chwaspnestgame(void) {
    Actor *func_80106790();
    void *temp_v0;

    temp_v0 = func_80106790();
    (*(s32 *)((s8 *)(temp_v0) + (0x34))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (0x34))) - 1);
}

void func_808012C8_chwaspnestgame(s32 arg0) 
{
}
/* extern */

void func_808012D0_chwaspnestgame(void *arg0) {
    s32 func_80102BF8(void *, s32, s32, s32);
    f32 func_80102D78(void *, s32 *);
    s32 func_8010D600(s32 *);
    s32 sp1C[3];

    func_8010D600(sp1C);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = func_80102D78(arg0, sp1C);
    func_80102BF8(arg0, 0x3DCCCCCD, 0x40800000, 0x43340000);
    func_808012C8_chwaspnestgame((s32) arg0);
}

void func_80801324_chwaspnestgame(f32 *arg0, f32 arg1, f32 arg2) {
    void func_800EF334(f32 vec[3], f32 scale);
    if (arg1 != 0.0f) {
        func_800EF334(arg0, arg2 / arg1);
    }
}

s32 func_80801364_chwaspnestgame(s32 actor, s32 arg1)
{
  void _subaddiefade_entrypoint_3(Actor *);
  void func_8008FE68(f32 *);
  void func_800C4AF0(f32 *, void *);
  void func_800EE7F8(f32 *, f32 *);
  void func_800EF2A0(f32 *);
  void func_800EFD24(f32 *);
  void func_80102424(Actor *, s32);
  s32 func_8010A570(s32);
  void func_8010DC50(s32);
  s32 func_8010DCB4(s32);
  extern u8 D_80802024_chwaspnestgame[];
  extern u8 D_80802038_chwaspnestgame[];
  f32 pos[3];
  Actor *arg0 = (Actor *) actor;
  struct Motion
  {
    f32 origin[3];
    f32 phase;
    f32 velocity[3];
    f32 angle;
  };
  if ((arg0->unk70_10 == 2) && (arg1 != 5))
  {
    func_8010DCB4(10);
  }
  switch (arg1)
  {
    case 2:
      func_8010DC50(10);
      break;

    case 1:
      func_8008FE68(pos);
      ((struct Motion *) arg0->actorData)->velocity[0] = pos[2] - arg0->position[2];
      ((struct Motion *) arg0->actorData)->velocity[1] = 0 * 0.0f;
      ((struct Motion *) arg0->actorData)->velocity[2] = pos[0] - arg0->position[0];
      func_800EF2A0(((struct Motion *) arg0->actorData)->velocity);
      ((struct Motion *) arg0->actorData)->phase = 0.0f;
      ((struct Motion *) arg0->actorData)->angle = 0.0f;
      ((struct Motion *) arg0->actorData)->velocity[1] = 1.0f;
      func_800EE7F8(((struct Motion *) arg0->actorData)->origin, arg0->position);
      break;

    case 5:
      func_8010A570(actor);
      break;

    case 3:
      func_800C4AF0(arg0->position, D_80802024_chwaspnestgame);
      func_8010A570(actor);
      break;

    case 4:
      func_800C4AF0(arg0->position, D_80802038_chwaspnestgame);
      arg0->rotation[0] = 0.0f;
      break;

    case 6:
      func_800EFD24(((struct Motion *) arg0->actorData)->velocity);
      break;

    case 7:
      _subaddiefade_entrypoint_3(arg0);
      break;

  }

  func_80102424(arg0, arg1);
}

/* extern */

void func_808014BC_chwaspnestgame(Actor *arg0, f32 *arg1) {
    f32 func_800D8FF8(void);
    f32 dt;
    struct {
        u32 unk0[4];
        f32 x;
        f32 y;
        f32 z;
    } *velocity;

    dt = func_800D8FF8();
    velocity = (void *)arg0->actorData;
    arg0->position[0] += velocity->x * dt + arg1[0] * dt * dt;
    arg0->position[1] += velocity->y * dt + arg1[1] * dt * dt;
    arg0->position[2] += velocity->z * dt + arg1[2] * dt * dt;
    velocity->x += arg1[0] * dt;
    velocity->y += arg1[1] * dt;
    velocity->z += arg1[2] * dt;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801590_chwaspnestgame.s")

/* extern */

s32 func_808017DC_chwaspnestgame(Actor *arg0, f32 arg1, s32 arg2) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    struct {
        f32 sp24[3];
        f32 sp30[3];
        f32 sp3C[3];
    } vectors;

    func_800EFA4C(vectors.sp3C, 0.0f, -arg1, 0.0f);
    func_800EE7F8(vectors.sp30, arg0->position);
    func_808014BC_chwaspnestgame(arg0, vectors.sp3C);
    return arg2 ? (func_800BEF00(vectors.sp30, arg0->position, vectors.sp24, 0x20020) ? 1 : 0) : 0;
}

/* extern */

void func_80801880_chwaspnestgame(Actor *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
    f32 temp_f0;
    struct Motion {
        f32 origin[3];
        f32 angle;
        f32 scale[3];
        f32 phase;
    };

    temp_f0 = func_800D8FF8();
    ((struct Motion *)arg0->actorData)->phase += arg2 * temp_f0;
    ((struct Motion *)arg0->actorData)->angle += arg3 * temp_f0;
    arg0->position[0] = ((struct Motion *)arg0->actorData)->origin[0] + (((struct Motion *)arg0->actorData)->scale[0] * arg1) * func_800138D0(((struct Motion *)arg0->actorData)->phase);
    arg0->position[2] = ((struct Motion *)arg0->actorData)->origin[2] + (((struct Motion *)arg0->actorData)->scale[2] * arg1) * func_800138D0(((struct Motion *)arg0->actorData)->phase);
    arg0->position[1] = ((struct Motion *)arg0->actorData)->origin[1] + (((struct Motion *)arg0->actorData)->scale[1] * arg1) * func_80013970(((struct Motion *)arg0->actorData)->angle);
}

/* extern */

void func_80801954_chwaspnestgame(s32 arg0) {
    s32 func_800DA298(s32);
    f32 func_800EEB40(s32, s32);
    s32 func_8010A570(s32);
    s32 func_80801364_chwaspnestgame(s32, s32);
    if (func_800EEB40(arg0 + 0x18, arg0 + 4) > 1.0f) {
        func_80801364_chwaspnestgame(arg0, 2);
    } else {
        func_80801364_chwaspnestgame(arg0, 1);
    }
    if (func_800DA298(0) != 0) {
        func_8010A570(arg0);
    }
}

/* extern */

void func_808019D4_chwaspnestgame(Actor *arg0) {
    s32 func_8010DCB4(s32);
    u32 temp_t6;

    temp_t6 = (u32) arg0->unk70_10;
    if ((temp_t6 == 2) || (temp_t6 == 5)) {
        func_8010DCB4(0xA);
    }
}

/* extern */

void func_80801A10_chwaspnestgame(Actor *arg0) {
    void func_8080129C_chwaspnestgame();
    void func_808012C8_chwaspnestgame(s32 arg0);
    void func_808012D0_chwaspnestgame(void *arg0);
    s32 func_80801364_chwaspnestgame(s32 actor, s32 arg1);
    s32 func_808017DC_chwaspnestgame(Actor *arg0, f32 arg1, s32 arg2);
    void func_80801880_chwaspnestgame(Actor *arg0, f32 arg1, f32 arg2, f32 arg3);
    void func_80801CE4_chwaspnestgame(Actor *arg0);
    void func_80801D28_chwaspnestgame(Actor *arg0);
    s32 func_800DA298(s32);
    s32 func_800FFA88(Unk80132ED0 *);
    s32 func_80101DDC(Actor *);
    s32 func_80801590_chwaspnestgame(Actor *, s32, s32);

    switch (((Actor *)arg0)->unk70_10) {
    case 1:
        func_80801D28_chwaspnestgame(arg0);
        func_808012D0_chwaspnestgame(arg0);
        func_80801880_chwaspnestgame(arg0, 50.0f, 240.0f, 190.0f);
        return;
    case 2:
        func_80801D28_chwaspnestgame(arg0);
        func_80801CE4_chwaspnestgame(arg0);
        if (func_80801590_chwaspnestgame(arg0, 0x42C80000, 0x43FA0000) != 0) {
            if (func_800DA298(0) == 0) {
                func_8080129C_chwaspnestgame(arg0->unk3C);
                func_800FFA88((u8 *)arg0 ->unk0);
                return;
            }
            func_80801364_chwaspnestgame((s32) arg0, 1);
            return;
        }
    default:
        return;
    case 5:
        func_80801D28_chwaspnestgame(arg0);
        func_80801CE4_chwaspnestgame(arg0);
        if (func_80801590_chwaspnestgame(arg0, 0x43480000, 0x44FA0000) != 0) {
            func_800FFA88((u8 *)arg0 ->unk0);
            return;
        }
        break;
    case 3:
        func_808012C8_chwaspnestgame((s32) arg0);
        if (func_808017DC_chwaspnestgame(arg0, 1000.0f, 1) != 0) {
            func_80801364_chwaspnestgame((s32) arg0, 4);
            return;
        }
        break;
    case 4:
        if (func_80101DDC(arg0) != 0) {
            func_80801364_chwaspnestgame((s32) arg0, 7);
            return;
        }
        break;
    case 6:
        func_80801D28_chwaspnestgame(arg0);
        if (func_808017DC_chwaspnestgame(arg0, 500.0f, 1) != 0) {
            func_80801364_chwaspnestgame((s32) arg0, 7);
        }
        break;
    }
}

s32 func_80801B9C_chwaspnestgame(Actor *arg0, s32 arg1, Unk80132ED0 *volatile arg2) {
    void _chscorepoints_entrypoint_2(s32, s32, f32 *, s32);
    s32 _subaddiemulti_entrypoint_5(Unk80132ED0 *);
    void func_800C4AF0(f32 *, void *);
    s32 func_801015D0(Actor *);
    void func_8010DD20(Actor *, s32, Unk80132ED0 *);
    extern u8 D_8080207C_chwaspnestgame[];
    s32 player;
    s32 score;
    u32 state;

    switch (arg1) {
        case 0x3E:
            func_800C4AF0(arg0->position, D_8080207C_chwaspnestgame);
            break;
        case 0x40:
            player = _subaddiemulti_entrypoint_5(arg2);
            score = arg0->unk6C_0;
            _chscorepoints_entrypoint_2(score, player, arg0->position, 1);
            func_80801260_chwaspnestgame(arg0->unk3C, score);
            func_80801364_chwaspnestgame((s32)arg0, 3);
            break;
        case 0x45:
            state = arg0->unk70_10;
            if (state == 2) {
                func_80801364_chwaspnestgame((s32)arg0, 5);
            } else if (state == 1) {
                func_80801364_chwaspnestgame((s32)arg0, 6);
            }
            break;
        case 0x1F:
            state = arg0->unk70_10;
            if (state == 2 || state == 5) {
                func_8010DD20(arg0, 0xA, arg2);
            } else {
                func_801015D0(arg0);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80801CE4_chwaspnestgame(Actor *arg0) {
    void func_800F1A88(f32 *, f32 *);
    f32 sp18[2];

    func_800F1A88((f32 *)((s8 *)arg0 + 0x28), sp18);
    arg0->rotation[0] = -sp18[0];
    arg0->rotation[1] = sp18[1];
}

void func_80801D28_chwaspnestgame(Actor *arg0) {
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 i;
    struct {
        f32 positions[2][3];
        f32 distances[2];
    } *data;
    s32 j;
    f32 pos[3];
    f32 distance;

    data = func_80100094(func_80106790(arg0->unk3C), 0);
    func_800E3980(pos);
    distance = func_800EEAD4(arg0->position, pos);
    for (i = 0; i < 2; i++) {
        if (data->distances[i] < 0.0f || distance < data->distances[i]) {
            break;
        }
    }
    if (i < 2) {
        for (j = 1; j > i; j--) {
            func_800EE7F8(data->positions[j], data->positions[j - 1]);
            data->distances[j] = data->distances[j - 1];
        }
        func_800EE7F8(data->positions[i], arg0->position);
        data->distances[i] = distance;
    }
}
