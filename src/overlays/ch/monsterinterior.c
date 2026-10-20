#include "common.h"

OSThread *chmonsterinterior_entrypoint_0(void)
{
    extern u8 D_80801E80_chmonsterinterior[];

    return (OSThread *) D_80801E80_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_1(void)
{
    extern u8 D_80801EC8_chmonsterinterior[];

    return (OSThread *) D_80801EC8_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_2(void)
{
    extern u8 D_80801F10_chmonsterinterior[];

    return (OSThread *) D_80801F10_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_3(void)
{
    extern u8 D_80801F58_chmonsterinterior[];

    return (OSThread *) D_80801F58_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_4(void)
{
    extern u8 D_80801FA0_chmonsterinterior[];

    return (OSThread *) D_80801FA0_chmonsterinterior;
}

void func_8080003C_chmonsterinterior(Actor *arg0) {
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 _susubgame_entrypoint_11(s32);
    u32 func_800F54E4(void);
    s32 func_800F6438(u32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    u32 *data;

    data = func_80100094(arg0, 0);
    if (func_800F6438(func_800F54E4()) == 0) {
        func_800FFAB0(arg0);
        return;
    }
    *data = 0;
    _susubgame_entrypoint_0(arg0, data + 4, 0);
    _susubgame_entrypoint_11(0);
    arg0->unk6C_0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808000BC_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808002D4_chmonsterinterior.s")

void func_8080060C_chmonsterinterior(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800CEAA8(s32);
    void func_800CE88C(s32, s32);
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    s32 data[2];

    data[1] = func_80100094(arg0, 0);
    if (func_800CEAA8(arg0->unk6C_0) != 0) {
        func_800CE88C(arg0->unk6C_0, 0);
    }
    data[0] = data[1] + 0x10;
    if (_susubgame_entrypoint_2(arg0, data[0]) != 0) {
        _susubgame_entrypoint_4(arg0, data[0]);
    }
}

/* extern */

void func_8080068C_chmonsterinterior(Actor *arg0) {
    s32 _gcstatusDll_entrypoint_11();
    s32 _subaddiemulti_entrypoint_2();
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    s32 func_800D3948(void);
    void func_800F7B9C(s32, u32);
    void func_800F7C0C(s32, s32, f32);
    u32 func_800FDC28(u32);
    void func_80101FDC(Actor *, u32);
    s32 var_s0;
    s32 duration = 60;

    _subaddiemulti_entrypoint_2();
    func_80101FDC(arg0, 3);
    var_s0 = 0;
    if (_gcstatusDll_entrypoint_11() > 0) {
        do {
            if (func_800D3948() == 0) {
                func_800F7B9C(var_s0, 0x73);
                func_800F7C0C(var_s0, 0x5F, -1.0f);
            } else {
                func_800F7C0C(var_s0, 0x5F, -1.0f);
            }
            var_s0 += 1;
        } while (var_s0 < _gcstatusDll_entrypoint_11());
    }
    func_800CE8D8(arg0->unk6C_0, duration, 60);
    func_800CE88C(arg0->unk6C_0, 1);
    arg0->unk58 = 0.01f;
    func_800FDC28(0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_8080078C_chmonsterinterior.s")

s32 func_808009C0_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s16 func_800D211C(s32);
    s32 *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x17F7:
            return *data;
        case 0x17F3:
            return 0x4B;
        case 0x1808:
        case 0x181A:
            return func_800D211C(0x85);
        default:
            return 0;
    }
}

void func_80800A44_chmonsterinterior(Actor *arg0, s32 arg1) {
    s32 _susubgame_entrypoint_2(void *, s32);
    void func_800CD08C(s32, f32 *);
    s32 func_800D3948(void);
    s32 func_800DC128(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80105138(u8 *, s32, f32, f32, s32);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_80800BC8_chmonsterinterior(u8 **, s32);
    struct SpawnFlags {
        u8 pad[0x70];
        u8 pad70 : 7;
        u8 flag : 1;
    };
    Actor *spawned;
    f32 position[3];
    f32 height;
    s32 pad;
    s32 mode;
    void *data;

    if (arg1 == 0 || arg1 == 1 || arg1 == 2) {
        mode = func_800D3948();
        data = func_80100094(arg0, 0);
        if (_susubgame_entrypoint_2(arg0, (s32)data + 0x10)) {
            func_800EE7F8(position, arg0->position);
        } else {
            func_800CD08C(arg0->unk70_25 - 1, position);
        }
        position[1] = arg0->position[1];
        func_80105138((u8 *)arg0, (s32)position, 200.0f, -200.0f, (s32)&height);
        position[1] = height;
        spawned = func_80108528(arg1 + 0x452, position, func_800DC128(0, 0x167), &arg0);
        spawned->unk3C = arg0->unk0;
        spawned->unk64_20 = mode;
        spawned->actorData[5] = arg1;
        spawned->unk6C_0 = arg0->unk6C_0;
        spawned->unk64_19 = _susubgame_entrypoint_2(arg0, (s32)data + 0x10);
        ((struct SpawnFlags *)spawned)->flag = mode == 0;
        func_80800BC8_chmonsterinterior((u8 **)spawned, arg1);
    }
}

void func_80800BC8_chmonsterinterior(u8 **arg0, s32 arg1) {
    s32 func_800D3948(void);
    void func_801032B0(void *, u16, u16);
    extern u16 D_80801FE8_chmonsterinterior[];
    extern u16 D_80801FF0_chmonsterinterior[];
    if (func_800D3948() != 0) {
        func_801032B0(arg0, D_80801FF0_chmonsterinterior[arg1], *(u16 *)(*arg0 + 0x16));
        return;
    }
    func_801032B0(arg0, D_80801FE8_chmonsterinterior[arg1], *(u16 *)(*arg0 + 0x16));
}

s32 func_80800C38_chmonsterinterior(Actor *arg0, s32 *arg1) {
    s32 func_800D0A9C(u32, u32);
    s32 func_800D2054(s32, s32, s32);
    s32 func_800D395C(void);
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
    count = *(s32 *)data;
    flag = func_800D0A9C(0x2E, 1);
    mode = func_800D395C();
    state = func_800D2054(0, 0x85, count);
    available = (state == 1) && (flag || mode);
    choice = ((count >= 0x4B) != 0) && !flag && !mode;
    completed = choice;
    func_800FDC28(0);
    func_800FC6B0(choice || available ? 0x16 : 0x17);
    *arg1 = 6;
    if (completed) {
        result = 0x17FA;
    } else if (available) {
        result = 0x17F7;
    } else if (!func_800D395C()) {
        if (flag) {
            if (state == 0) {
                result = 0x1809;
            } else {
                result = 0x1808;
            }
        } else {
            result = 0x1807;
        }
    } else {
        result = 0xCEB;
        *arg1 = 0x46;
    }
    return result;
}

/* extern */

void func_80800DA4_chmonsterinterior(Actor *arg0) {
    void _subaddiemulti_entrypoint_3(s32);
    void* func_80100094(Actor*, u32);
    s32 _sumultiscore_entrypoint_3(u8 *);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    _subaddiemulti_entrypoint_3(0xA);
    arg0->unk6C_0 = 5;
    _sumultiscore_entrypoint_3(sp1C + 0x28);
    _sumultiscore_entrypoint_4(sp1C + 0x28, 8, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_80800E0C_chmonsterinterior.s")

void func_8080101C_chmonsterinterior(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 _sumultiscore_entrypoint_12(s32, s32, s32);
    _sumultiscore_entrypoint_12((s32)func_80100094(arg0, 0U) + 0x28, arg1, 1);
}

s32 func_80801050_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80801114_chmonsterinterior(Actor *, s32, s32);
    s32 func_80801180_chmonsterinterior(Actor *, s32, s32);
    void func_80800A44_chmonsterinterior(Actor *, s32);
    s32 _subaddiemulti_entrypoint_1(s32, s32);
    void func_800BF544(s32, s32, s32);

    switch (arg1) {
    case 0x2E:
        func_80801114_chmonsterinterior(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x30:
        return func_80801180_chmonsterinterior(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
    case 0x3D:
        func_80800A44_chmonsterinterior(arg0, arg2);
        break;
    case 0x95:
        _subaddiemulti_entrypoint_1(0, 0);
        func_800BF544(0, 0, 0);
        func_800BF544(1, 0, 0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80801114_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    s32 _subaddiemulti_entrypoint_2();
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
    case 0xCEC:
        func_8080068C_chmonsterinterior(arg0);
        return;
    case 0x17F8:
    case 0x17F9:
        _subaddiemulti_entrypoint_2();
        func_80101FDC(arg0, 6);
        _gcfrontend_entrypoint_10();
        return;
    }
}

s32 func_80801180_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    if (arg1 == 0x17F8) {
        return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (4))) + 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808011BC_chmonsterinterior.s")

void func_808013D0_chmonsterinterior(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_8010A3E8(void *, f32);
    f32 func_80801ADC_chmonsterinterior(s32, f32 *);
    f32 func_80801B7C_chmonsterinterior(s32);
    f32 func_800DC178(f32, f32);
    void func_80102FDC(void *, f32);
    s32 _subaddieDll_entrypoint_1(Actor *);
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_8080201C_chmonsterinterior;
    typedef struct {
        s32 pad[10];
        f32 unk28;
        s32 kind;
        f32 unk30;
        s32 pad34[15];
        u32 flags;
    } MonsterInteriorData;
    register s32 *data;
    register s32 kind;

    data = func_80100094(arg0, 0);
    kind = arg0->actorData[5];
    func_8010A3E8(arg0, 0.3f);
    data[3] = 0;
    arg0->position[1] -= 250.0f;
    ((MonsterInteriorData *)arg0)->unk28 = 0.6f;
    ((MonsterInteriorData *)arg0)->unk30 = func_80801ADC_chmonsterinterior(kind, (f32 *)&data[10]);
    arg0->unk58 = func_80801B7C_chmonsterinterior(kind);
    func_80102FDC(arg0, func_800DC178(0.6f, 0.8f));
    _subaddieDll_entrypoint_1(arg0);
    _subaddierouteDll_entrypoint_3(arg0, data, arg0->position);
    _subaddierouteDll_entrypoint_1(arg0);
    if (arg0->unk64_19) {
        arg0->unk64_24 = 0;
        arg0->unk58 = 5.5f;
    }
    func_8010D930(4, ((MonsterInteriorData *)arg0)->flags & 1, arg0->position, &D_8080201C_chmonsterinterior);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808014E8_chmonsterinterior.s")

void func_808017E8_chmonsterinterior(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808017F0_chmonsterinterior.s")

void func_80801930_chmonsterinterior(Actor *arg0, Unk80132ED0 *arg1) {
    void _chscorepoints_entrypoint_2(s32, s32, f32 *, s32);
    s32 _subaddiemulti_entrypoint_5(Unk80132ED0 *);
    void _sumultiscore_entrypoint_7(u8 *, s32, s32, s32);
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800D3948(void);
    s32 func_800DC128(s32, s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(s32, s32, s32);
    void func_80103DFC(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s16 D_80801E50_chmonsterinterior[];
    extern s32 D_80802044_chmonsterinterior[];
    extern s32 D_8080207C_chmonsterinterior[];
    extern s16 D_8080208C_chmonsterinterior[];
    s32 pad;
    s32 *data;
    s32 count;
    s32 emitter;
    s32 player;
    f32 position[3];
    f32 scorePosition[3];

    data = func_80100094(func_80106790(arg0->unk3C), 0);
    if (func_800D3948() != 0) {
        count = 2;
    } else {
        count = func_800DC128(6, 8);
    }
    emitter = func_800B53A4(count);
    player = _subaddiemulti_entrypoint_5(arg1);
    func_80103DFC(arg0, position);
    func_800BABB8(emitter, position, position, 1.0f, D_80802044_chmonsterinterior);
    func_800BA670(emitter, D_8080208C_chmonsterinterior[arg0->actorData[5]]);
    func_800BA22C(emitter, count);
    if (func_800D3948() != 0) {
        _sumultiscore_entrypoint_7((u8 *)&data[10], player, 8, D_80801E50_chmonsterinterior[arg0->actorData[5]]);
    } else {
        *data += D_80801E50_chmonsterinterior[arg0->actorData[5]];
    }
    func_8010D930(1, arg0->unk70_0, position, D_8080207C_chmonsterinterior);
    func_80103DFC(arg0, scorePosition);
    _chscorepoints_entrypoint_2(D_80801E50_chmonsterinterior[arg0->actorData[5]], player, scorePosition, 1);
    func_800FFAB0(arg0);
    if (*(u16 *)&arg1->unk18 & 1) {
        func_8010114C((s32)arg1, 0x98, 0);
    }
}

f32 func_80801ADC_chmonsterinterior(s32 arg0, f32 *arg1) {
    f32 func_800DC178(f32, f32);
    switch (arg0) {
    case 0:
        *arg1 = 600.0f;
        return func_800DC178(500.0f, 600.0f);
    case 1:
        *arg1 = 450.0f;
        return func_800DC178(350.0f, 450.0f);
    case 2:
        *arg1 = 300.0f;
        return func_800DC178(200.0f, 300.0f);
    default:
        return -1.0f;
    }
}

f32 func_80801B7C_chmonsterinterior(s32 arg0) {
    f32 func_800DC178(f32, f32);
    switch (arg0) {
    case 0:
        return func_800DC178(2.5f, 3.0f);
    case 1:
        return func_800DC178(3.0f, 3.5f);
    case 2:
        return func_800DC178(3.5f, 4.5f);
    default:
        return -1.0f;
    }
}

/* extern */
s32 func_80801C1C_chmonsterinterior(u8 *arg0) {
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

s32 func_80801C78_chmonsterinterior(u8 *arg0) {
    u8 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp28;

    sp28 = func_800D9078((f32 *) (arg0 + 0x28));
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x28))), 0.0f, 0.6f, -250.0f, 0.0f);
    return sp28;
}
