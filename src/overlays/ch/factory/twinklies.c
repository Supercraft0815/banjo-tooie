#include "common.h"

OSThread *chfactorytwinklies_entrypoint_0(void)
{
    extern u8 D_80802218_chfactorytwinklies[];

    return (OSThread *) D_80802218_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_1(void)
{
    extern u8 D_80802260_chfactorytwinklies[];

    return (OSThread *) D_80802260_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_2(void)
{
    extern u8 D_808022A8_chfactorytwinklies[];

    return (OSThread *) D_808022A8_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_3(void)
{
    extern u8 D_808022F0_chfactorytwinklies[];

    return (OSThread *) D_808022F0_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_4(void)
{
    extern u8 D_80802338_chfactorytwinklies[];

    return (OSThread *) D_80802338_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_5(void)
{
    extern u8 D_80802380_chfactorytwinklies[];

    return (OSThread *) D_80802380_chfactorytwinklies;
}

struct player_state_s;

void func_80800048_chfactorytwinklies(Actor *arg0) {
    typedef struct player_state_s PlayerState;
    s32 _gcstatusDll_entrypoint_11(void);
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 _susubgame_entrypoint_11(s32);
    void func_800946C4(PlayerState *, s32);
    void func_800A16BC(s32);
    void func_800D2748(s32, s32);
    PlayerState *func_800F53D0(s32);
    s32 func_800F5410(s32);
    u32 func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    struct {
        s32 counts[16];
        s32 values[9][3];
        u32 game;
    } *data;
    s32 i;
    s32 player;

    data = func_80100094(arg0, 0);
    player = func_800F54E4();
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        data->counts[i] = 0;
        data->values[i][0] = 0;
        data->values[i][1] = 0;
        data->values[i][2] = 0;
    }
    func_800946C4(func_800F53D0(player), 1);
    _susubgame_entrypoint_0(arg0, &data->game, 0);
    _susubgame_entrypoint_11(0);
    func_800A16BC(1);
    switch (func_800F5410(player)) {
        case 10:
            func_800D2748(0xEF, 0x57);
            break;
        case 11:
            func_800D2748(0xEF, 0x58);
            break;
        case 13:
            func_800D2748(0xEF, 0x59);
            break;
        case 7:
            func_800D2748(0xEF, 0x5A);
            break;
        default:
            func_800D2748(0xEF, 0x5B);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808001A0_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_8080040C_chfactorytwinklies.s")

void func_8080064C_chfactorytwinklies(Actor *arg0) {
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void func_800A16BC(s32);
    void func_800CE88C(s32, s32);
    s32 func_800CEAA8(s32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    s32 data[2];

    data[1] = func_80100094(arg0, 0);
    func_800A16BC(0);
    if (func_800CEAA8(0) != 0) {
        func_800CE88C(0, 0);
    }
    data[0] = data[1] + 0xAC;
    if (_susubgame_entrypoint_2(arg0, data[0]) != 0) {
        _susubgame_entrypoint_4(arg0, data[0]);
    }
    func_800FDC28(0);
}

/* extern */

void func_808006C0_chfactorytwinklies(Actor *arg0) {
    s32 _subaddiemulti_entrypoint_2();
    s32 _subaddiemulti_entrypoint_4(s32);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    s32 func_800DA298(s32);
    u32 func_800FDC28(u32);
    void func_80101FDC(Actor *, u32);
    f32 duration;
    _subaddiemulti_entrypoint_2();
    func_80101FDC(arg0, 3);
    duration = 60.0f;
    func_800CE8D8(0, duration, (s32) duration);
    func_800CE88C(0, 1);
    arg0->unk58 = 0.01f;
    if (func_800DA298(0x6A7) != 0) {
        _subaddiemulti_entrypoint_4(0x17);
    }
    func_800FDC28(0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800748_chfactorytwinklies.s")

s32 func_808009EC_chfactorytwinklies(Actor *arg0, s32 arg1, s32 arg2) { void *func_80100094(Actor *, u32); s16 func_800D211C(s32); u32 func_800F54E4(void); s32 *data; data = func_80100094(arg0, 0); switch (arg1) { case 0x1347: return data[func_800F54E4()]; case 0x1345: return 0x28; case 0x1375: case 0x1385: return func_800D211C(0x83); default: return 0; } }

void func_80800A84_chfactorytwinklies(Actor *arg0, s32 arg1) { 
    s32 _susubgame_entrypoint_2(void *, s32);
    void func_800CD08C(s32, f32 *);
    s32 func_800DC128(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    u8 *data;
    Actor *child;
    f32 position[3];
    s32 flag;
    typedef struct {
        u8 pad[0x70];
        u32 flags70;
    } ActorFlags;
    struct {
        u8 pad[0x2A];
        u8 pad2A_6 : 2;
        u8 flag : 1;
        u8 pad2A_0 : 5;
    } *marker;

    if (arg1 == 0 || arg1 == 1 || arg1 == 2) {
        data = func_80100094(arg0, 0);
        if (_susubgame_entrypoint_2(arg0, (s32)(data + 0xAC))) {
            func_800EE7F8(position, arg0->position);
        } else {
            func_800CD08C((((ActorFlags *)arg0)->flags70 >> 25) - 1, position);
        }
        position[1] = 0.0f;
        child = func_80108528(arg1 + 0x443, position, func_800DC128(0, 0x167), &arg0);
        child->unk3C = arg0->unk0;
        child->actorData[5] = arg1;
        flag = _susubgame_entrypoint_2(arg0, (s32)(data + 0xAC));
        marker = (void *)child->unk0;
        marker->flag = flag;
    }
}

s32 func_80800B80_chfactorytwinklies(Actor *arg0, s32 *arg1) {
    s32 func_800D0A9C(u32, u32);
    s32 func_800D2054(s32, s32, s32);
    s32 func_800D395C(void);
    u32 func_800F54E4(void);
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void *data;
    s32 count;
    s32 result;
    s32 available;
    s32 choice;
    s32 completed;
    s32 flag;
    s32 mode;
    s32 state;

    data = func_80100094(arg0, 0);
    count = ((s32 *)data)[func_800F54E4()];
    flag = func_800D0A9C(0x3B, 1);
    mode = func_800D395C();
    state = func_800D2054(0, 0x83, count);
    available = (state == 1) && (flag || mode);
    choice = ((count >= 0x28) != 0) && !flag && !mode;
    completed = choice;
    func_800FDC28(0);
    func_800FC6B0((choice || available) ? 0x16 : 0x17);
    *arg1 = 6;
    if (completed) {
        result = 0x1346;
    } else if (available) {
        result = 0x1347;
    } else if (!func_800D395C()) {
        if (flag) {
            if (state == 0) {
                result = 0x1376;
            } else {
                result = 0x1375;
            }
        } else {
            result = 0x1374;
        }
    } else {
        result = 0xCEB;
        *arg1 = 0x46;
    }
    return result;
}

void func_80800D00_chfactorytwinklies(Actor *arg0) {
    s32 _gcstatusDll_entrypoint_11(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F849C(s32, f32);
    void *func_80100094(Actor *, u32);
    struct {
        s32 unk0[16];
        s32 unk40[4][3];
    } *data;
    s32 i;
    s32 sum;

    data = func_80100094(arg0, 0);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        sum = data->unk40[i][0] + data->unk40[i][1] + data->unk40[i][2];
        func_800F849C(i, func_800F10B4((f32)sum, 0.0f, 10.0f, 1.0f, 0.6f));
    }
}

void func_80800DE0_chfactorytwinklies(Actor *arg0) {
    typedef struct player_state_s PlayerState;
    s32 _gcstatusDll_entrypoint_11(void);
    s32 _subaddiemulti_entrypoint_3(s32);
    void func_800946C4(PlayerState *, s32);
    void func_800A16BC(s32);
    void func_800D2748(s32, s32);
    PlayerState *func_800F53D0(s32);
    void *func_80100094(Actor *, u32);
    struct {
        s32 unk0[16];
        s32 unk40[4][3];
    } *data;
    s32 i;

    data = func_80100094(arg0, 0);
    func_800A16BC(1);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        data->unk0[i] = 0;
        data->unk40[i][0] = 0;
        data->unk40[i][1] = 0;
        data->unk40[i][2] = 0;
        func_800946C4(func_800F53D0(i), 1);
        func_800D2748(i + 0xC3, i + 0x5B);
    }
    _subaddiemulti_entrypoint_3(0xA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800E9C_chfactorytwinklies.s")

s32 func_8080105C_chfactorytwinklies(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80801108_chfactorytwinklies(Actor *, s32, s32);
    s32 func_80801174_chfactorytwinklies(Actor *, s32, s32);
    void func_80800A84_chfactorytwinklies(Actor *, s32);
    s32 _subaddiemulti_entrypoint_1(s32, s32);
    s32 _subaddiemulti_entrypoint_4(s32);

    switch (arg1) {
    case 0x2E:
        func_80801108_chfactorytwinklies(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x30:
        return func_80801174_chfactorytwinklies(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
    case 0x3D:
        func_80800A84_chfactorytwinklies(arg0, arg2);
        break;
    case 0x95:
        _subaddiemulti_entrypoint_1(0, 0);
        _subaddiemulti_entrypoint_4(0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80801108_chfactorytwinklies(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    s32 _subaddiemulti_entrypoint_2();
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
    case 0xCEC:
        func_808006C0_chfactorytwinklies(arg0);
        return;
    case 0x1348:
    case 0x1349:
        _subaddiemulti_entrypoint_2();
        func_80101FDC(arg0, 6);
        _gcfrontend_entrypoint_10();
        return;
    }
}

s32 func_80801174_chfactorytwinklies(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    if (arg1 == 0x1348) {
        return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (0xA0))) + 1;
    }
    return 0;
}

void func_808011B0_chfactorytwinklies(Actor *arg0) {
    s32 _gcstatusDll_entrypoint_11();
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiemulti_entrypoint_1(s32, s32);
    void func_800AA20C(s32, s32);
    void func_800FC6B0(u32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s32 temp;
    s32 scores[8];
    s32 *data;
    s32 max;
    s32 i;
    s32 j;
    s32 k;
    s32 dialog;

    data = func_80100094(arg0, 0);
    max = -1;
    for (j = 0; j < _gcstatusDll_entrypoint_11(); j++) {
        scores[j] = data[j];
        if (max < scores[j]) {
            max = scores[j];
        }
        func_800AA20C(j, scores[j]);
    }
    for (j = 0; j < _gcstatusDll_entrypoint_11(); j++) {
        if (max == scores[j]) {
            data[j + 8] = 1;
        }
    }
    for (i = 1; i < _gcstatusDll_entrypoint_11(); i++) {
        for (k = i; k > 0 && scores[k - 1] < scores[k]; k--) {
            temp = scores[k];
            scores[k] = scores[k - 1];
            scores[k - 1] = temp;
        }
    }
    func_800FC6B0(0x16);
    if (scores[0] != scores[1]) {
        for (k = 0; data[k] != scores[0]; k++) {}
        data[40] = k;
        dialog = 0x1348;
    } else {
        dialog = 0x1349;
    }
    _subaddiemulti_entrypoint_1(0, 0);
    func_80101FDC(arg0, 5);
    _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 6, NULL, 0xA3);
}

void func_808013BC_chfactorytwinklies(Actor *arg0, s32 arg1) {
    s32 _gcstatusDll_entrypoint_11();
    s32 func_800D24E8(s32, s32, u32);
    s32 func_800D28A0(s32);
    void *func_80100094(Actor *, u32);
    s32 *data;
    s32 id;
    s32 i;
    s32 *entry;

    data = func_80100094(arg0, 0);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        id = i + 0xC3;
        func_800D24E8(id, data[i], 0);
        if (arg1 && data[i + 8]) {
            func_800D28A0(id);
        }
    }
}

void func_8080145C_chfactorytwinklies(Actor *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk74_7 - 0x32;
    arg0->actorData[5] = temp_v0;
    switch (temp_v0) {
    case 0:
        arg0->actorData[4] = 0x20000000;
        break;
    case 1:
        arg0->actorData[4] = 0x10000000;
        break;
    case 2:
        arg0->actorData[4] = 0x08000000;
        break;
    }
}

void func_808014B0_chfactorytwinklies(Actor *arg0) {
    void _chscorepoints_entrypoint_2(s32, s32, f32 *, s32);
    s32 _gcstatusDll_entrypoint_11(void);
    s32 func_800CEAA8(s32);
    s32 func_800CEAD0(s32);
    s32 func_800F55FC(s32);
    void func_800F5A2C(s32, s32, f32 *);
    s32 func_800F6C5C(s32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80108B04(Actor *, u32);
    struct {
        s32 counts[16];
        s32 values[9][3];
        u32 game;
    } *data;
    s32 i;
    s32 points;
    s32 count;
    f32 position[3];
    u32 kind;
    s32 *total;

    data = func_80100094(func_80106790(arg0->unk3C), 0);
    if (func_800CEAA8(0) && !func_800CEAD0(0)) {
        for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
            if (func_800F6C5C(i) && (func_800F55FC(i) & arg0->actorData[4])) {
                count = data->values[i][arg0->actorData[5]];
                if (count > 0) {
                    points = (3 - arg0->actorData[5]) * count;
                    total = &data->counts[i];
                    *total += points;
                    data->values[i][arg0->actorData[5]] = 0;
                    func_800F5A2C(i, 5, position);
                    _chscorepoints_entrypoint_2(points, i, position, 1);
                    func_80108B04(arg0, i);
                }
            }
        }
    }
}

s32 func_80801608_chfactorytwinklies(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800F5A2C(s32, s32, f32 *);
    s32 func_800DC128(s32, s32);
    s32 func_800EA05C();
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80102FDC(Actor *, f32);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    f32 *sp34;
    Actor *sp30;
    f32 sp24[3];
    Actor *found;

    switch (arg1) {
    case 0x3D:
        func_800F5A2C(arg2, 5, sp24);
        sp30 = func_80108528(arg0->actorData[5] + 0x443, sp24, func_800DC128(0, 0x167), &arg0);
        sp34 = func_80100094(sp30, 0);
        func_800EE7F8(sp34 + 7, arg0->position);
        func_800EE7F8(sp34 + 4, sp24);
        func_80101FDC(sp30, 5);
        func_80102FDC(sp30, 0.2f);
        break;
    case 0x95:
        if (func_800EA05C(arg2) == 0x17D) {
            found = _subaddiefind_entrypoint_2(0x44D, 0);
        } else {
            found = _subaddiefind_entrypoint_2(0x442, 0);
        }
        arg0->unk3C = found->unk0;
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080171C_chfactorytwinklies(Actor *arg0) {
    s32 _subaddieDll_entrypoint_1(Actor *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    s32 func_800C8A98(void);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    void *func_80100094(Actor *, u32);
    void func_8010A3E8(void *, f32);
    void func_8010A570(Actor *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    f32 func_80801ED0_chfactorytwinklies(void *);
    f32 func_80801FAC_chfactorytwinklies(void *);
    extern u32 D_808023C8_chfactorytwinklies[][3];
    extern s32 D_808023EC_chfactorytwinklies[];
    extern s32 D_80802400_chfactorytwinklies[];
    typedef struct {
        Unk80132ED0 *marker;
        f32 position[3];
        u32 pad10[6];
        f32 speed;
        s32 color;
        f32 value;
        u32 pad34[7];
        s32 light;
    } Twinklie;
    typedef struct {
        u32 unused : 18;
        u32 active : 1;
        u32 rest : 13;
    } MarkerFlags;
    s32 *sp24;

    sp24 = func_80100094(arg0, 0);
    func_8010A3E8(arg0, 0.3f);
    if (arg0->unk70_10 == 1) {
        arg0->position[1] -= 250.0f;
        ((Twinklie *)arg0)->speed = 0.6f;
        ((Twinklie *)arg0)->value = func_80801ED0_chfactorytwinklies(arg0);
        arg0->unk58 = func_80801FAC_chfactorytwinklies(arg0);
        _subaddieDll_entrypoint_1(arg0);
        _subaddierouteDll_entrypoint_3(arg0, sp24, arg0->position);
        _subaddierouteDll_entrypoint_1(arg0);
        sp24[3] = 0;
        ((Twinklie *)arg0)->light = func_800C8A98();
        func_800C8E54(((Twinklie *)arg0)->light, 500.0f, 800.0f);
        func_800C8E84(((Twinklie *)arg0)->light, D_808023C8_chfactorytwinklies[arg0->actorData[5]]);
        if (((MarkerFlags *)&arg0->unk0->unk28)->active) {
            arg0->unk64_24 = 0;
            arg0->unk58 = 5.5f;
        }
        func_8010D930(4, arg0->unk70_0, arg0->position, D_808023EC_chfactorytwinklies);
    } else {
        func_8010D930(4, arg0->unk70_0, arg0->position, D_80802400_chfactorytwinklies);
        func_8010A570(arg0);
        arg0->unk58 = 1.2f;
        arg0->unk64_24 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808018A0_chfactorytwinklies.s")

void func_80801D58_chfactorytwinklies(u8 *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 temp_a3;

    temp_a3 = (*(s32 *)((s8 *)(arg0) + (0x50)));
    if (temp_a3 != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x50))) = _chlightfader_entrypoint_1(temp_a3, 1.0f, 2);
    }
}

/* extern */

s32 func_80801D94_chfactorytwinklies(Actor *arg0, s32 arg1, u8 *arg2) {
    void func_80801DD8_chfactorytwinklies(Actor *, s32);
    u8 **ptr = &arg2;
    switch (arg1) {
    case 0x3E:
        func_80801DD8_chfactorytwinklies(arg0, (u32)*(u16 *)(*ptr + 0x1A) >> 5);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80801DD8_chfactorytwinklies(Actor *arg0, s32 arg1) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80103DFC(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_8080243C_chfactorytwinklies[];
    extern s32 D_80802468_chfactorytwinklies[];
    extern s16 D_80802478_chfactorytwinklies[];
    struct TwinklieFlags {
        u8 pad[0x70];
        u32 reserved : 31;
        u32 flag : 1;
    };
    struct CounterData {
        s32 pad[16];
        s32 count[1][3];
    };
    Actor *parent;
    struct CounterData *data;
    s32 emitter;
    f32 position[3];

    parent = func_80106790(arg0->unk3C);
    data = func_80100094(parent, 0);
    emitter = func_800B53A4(12);
    func_80103DFC(arg0, position);
    func_800BABB8(emitter, position, position, 1.0f, D_8080243C_chfactorytwinklies);
    func_800BA3FC(emitter, D_80802478_chfactorytwinklies[arg0->actorData[5]]);
    func_800BA22C(emitter, 12);
    data->count[arg1][arg0->actorData[5]] += 1;
    func_8010D930(1, ((struct TwinklieFlags *)arg0)->flag, arg0->position, D_80802468_chfactorytwinklies);
    func_800FFAB0(arg0);
}

f32 func_80801ED0_chfactorytwinklies(void *arg0) {
    f32 func_800DC178(f32, f32);
    switch (*(s32 *)((u8 *)arg0 + 0x2C)) {
    case 0:
        return func_800DC178(800.0f, 900.0f);
    case 1:
        return func_800DC178(600.0f, 700.0f);
    default:
        return func_800DC178(400.0f, 500.0f);
    }
}

f32 func_80801F5C_chfactorytwinklies(void *arg0) { switch (*(s32 *)((u8 *)arg0 + 0x2C)) { case 0: return 900.0f; case 1: return 700.0f; default: return 500.0f; } }

f32 func_80801FAC_chfactorytwinklies(void *arg0) {
    f32 func_800DC178(f32, f32);
    switch (*(s32 *)((u8 *)arg0 + 0x2C)) {
    case 0:
        return func_800DC178(4.0f, 4.0f);
    case 1:
        return func_800DC178(4.0f, 4.0f);
    default:
        return func_800DC178(4.0f, 4.0f);
    }
}

/* extern */
s32 func_80802020_chfactorytwinklies(u8 *arg0) {
    u8 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800D9078((f32 *) (arg0 + 0x28));
    sp24 = temp_v0;
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x28))), 0.0f, 0.6f, 0.0f, -250.0f);
    return sp24;
}

/* extern */

s32 func_8080207C_chfactorytwinklies(u8 *arg0) {
    u8 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp28;

    sp28 = func_800D9078((f32 *) (arg0 + 0x28));
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x28))), 0.0f, 0.6f, -250.0f, 0.0f);
    return sp28;
}
