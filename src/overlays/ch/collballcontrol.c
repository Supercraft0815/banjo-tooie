#include "common.h"

void _sukickball_entrypoint_0();
void _sukickball_entrypoint_1();
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
void func_8010A730(s32, s32);
s32 func_808002B8_chcollballcontrol(Unk80132ED0 **arg0, s32 arg1, Unk80132ED0 *arg2);
void func_808006FC_chcollballcontrol(Actor *arg0);
void func_80800DD8_chcollballcontrol(Actor *arg0);
void func_80801038_chcollballcontrol(Actor *arg0);
void func_80801964_chcollballcontrol(Actor *arg0);
void func_80801A20_chcollballcontrol(Actor *arg0);
void func_80803208_chcollballcontrol(s32 arg0);
s32 func_80803420_chcollballcontrol(Actor *arg0, s32 arg1, s32 arg2);
void func_80803484_chcollballcontrol(Actor *arg0);
void func_80804420_chcollballcontrol(Actor *arg0);
void func_808044F4_chcollballcontrol(Actor *arg0);
extern u32 D_80805030_chcollballcontrol[];

u32 D_80804C50_chcollballcontrol[] = {
    0x001304B1, 0x000A00A6, 0x00164E20, 0x000101F4,
    0x13880000,
};

s32 D_80804C64_chcollballcontrol[] = {
    0x00130413, 0x00180001, 0x01F41388, 0x00000000,
};

s32 D_80804C74_chcollballcontrol[] = {
    0x001304F4, 0x00164E20, 0x000101F4, 0x13880000,
};

s32 D_80804C84_chcollballcontrol[] = {
    0x00130482, 0x000A0100, 0x00167D00, 0x000101F4,
    0x13880000,
};

u8 D_80804C98_chcollballcontrol[] = {
    0x00, 0x13, 0x05, 0x3C,
    0x00, 0x0A, 0x01, 0x00,
    0x00, 0x16, 0x7D, 0x00,
    0x00, 0x01, 0x00, 0x00,
    0x00, 0x02, 0x00, 0x01,
    0x01, 0xF4, 0x13, 0x88,
    0x00, 0x00, 0x00, 0x00,
};

f32 D_80804CB4_chcollballcontrol[] = {
    150.0f, 225.0f, 300.0f, 0.0f,
    400.0f,
};

f32 D_80804CC8_chcollballcontrol[][2] = {
    {1.0f, 0.0f},
    {0.75f, 1.0f},
    {0.75f, 0.75f},
    {0.333299994f, 0.666599989f},
    {0.333299994f, 0.666599989f},
};

s32 D_80804CF0_chcollballcontrol[] = {
    0x00000003, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000004, 0x00000000,
    0x00000001, 0x00000000, 0x00000001, 0x00000000,
    0x00000005, 0x00000001, 0x00000001, 0x00000000,
    0x00000001, 0x00000001, 0x00000004, 0x00000000,
    0x00000000, 0x00000002, 0x00000000, 0x00000000,
    0x00000005, 0x00000001, 0x00000000, 0x00000001,
    0x00000000, 0x00000001,
};

s32 D_80804D68_chcollballcontrol[] = {
    0x0000002D, 0x0000002D, 0x0000002D, 0x00000000,
    0x0000003C,
};

s32 D_80804D7C_chcollballcontrol[] = {
    0x00000004, 0x00000004, 0x00000004, 0x00000001,
    0x00000004,
};

u32 D_80804D90_chcollballcontrol[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000,
};

u32 D_80804DA8_chcollballcontrol[] = {
    0x003F019E, 0x06370001, 0x00000000, (u32)func_808006FC_chcollballcontrol,
    (u32)func_80105834, (u32)func_8010A730, 0x00000000, 0x00000000,
    0x00000000, 0x00080004, (u32)func_80801038_chcollballcontrol, 0x00000000,
    0x00400000, (u32)func_80800DD8_chcollballcontrol, (u32)func_80107C2C, 0x80000202,
    (u32)func_808002B8_chcollballcontrol, 0x00000000,
};

u8 D_80804DF0_chcollballcontrol[] = {
    0xFF, 0xFF, 0xFF, 0xC8,
};

s32 D_80804DF4_chcollballcontrol[] = {
    0xFFFFFFC8, 0x000000FF, 0x000000FF, 0x000000FF,
    0x000000C8,
};

s32 D_80804E08_chcollballcontrol[] = {
    0x0A10000A, 0xFFCE0000, 0xFFCE0032, 0x00320032,
    0x002CFF83, 0x004BFF83, 0x007D0096, 0x007D001B,
    0xFF06FEA2, 0x0027FD30, 0xFD3002D0, 0x02D00022,
    0x01000180, 0x00800100, 0x002A0080, 0x01000300,
    0x04000000,
};

s32 D_80804E4C_chcollballcontrol[] = {
    0x001D09E2, 0x001BFF06, 0xFF060015, 0x006600CC,
    0x00220040, 0x004C0007, 0x00070027, 0x000000C8,
    0x000000F0, 0x00161000, 0x000C000F, 0x002C0000,
    0x00640000, 0x000000FA, 0x0000002A, 0x00800100,
    0x03000400, 0x00000000,
};

s32 D_80804E94_chcollballcontrol[] = {
    0x001D0678, 0x00150066, 0x00CC000A, 0xFFFB0000,
    0xFFFB0005, 0x00000005, 0x002CFF06, 0x0064FF06,
    0x012C00FA, 0x012C001B, 0xFF6AFED4, 0x00220080,
    0x00800100, 0x03000027, 0xFD30FD30, 0x02D002D0,
    0x00161000, 0x002A0080, 0x01000300, 0x04000000,
};

s32 D_80804EE4_chcollballcontrol[] = {
    0x001D09DC, 0x00190001, 0x00062302, 0x000AFFFB,
    0x0019FFF1, 0x00050032, 0x000F002C, 0x00000060,
    0x00000000, 0x00D80000, 0x0022010A, 0x03000200,
    0x0500002A, 0x00000002, 0x04000700, 0x0015004C,
    0x00B30016, 0x00040000,
};

s32 D_80804F2C_chcollballcontrol[] = {
    0x00000000, 0x00000002, 0x00000001, 0x00000003,
};

u32 D_80804F3C_chcollballcontrol[] = {
    0x4B189680, 0x4B189680, 0x4B189680, 0x4B189680,
};

u32 D_80804F4C_chcollballcontrol[] = {
    0x00000000, 0x00000000, 0x00000000,
};

u32 D_80804F58_chcollballcontrol[] = {
    0x004401A1, 0x06700005, 0x00000000, (u32)func_80801A20_chcollballcontrol,
    (u32)func_80105834, (u32)_sukickball_entrypoint_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000004, (u32)func_80803208_chcollballcontrol, 0x00000000,
    0x00240000, (u32)func_80801964_chcollballcontrol, (u32)func_80107C2C, 0x80000002,
    0x00000000, 0x00000000,
};

u32 D_80804FA0_chcollballcontrol[] = {
    0x004201A3, 0x06770005, 0x00000000, (u32)func_80801A20_chcollballcontrol,
    (u32)func_80105834, (u32)_sukickball_entrypoint_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000006, (u32)func_80803208_chcollballcontrol, 0x00000000,
    0x00240000, (u32)func_80801964_chcollballcontrol, (u32)func_80107C2C, 0x80000002,
    0x00000000, 0x00000000,
};

u32 D_80804FE8_chcollballcontrol[] = {
    0x004301A2, 0x06720005, 0x00000000, (u32)func_80801A20_chcollballcontrol,
    (u32)func_80105834, (u32)_sukickball_entrypoint_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000004, (u32)func_80803208_chcollballcontrol, 0x00000000,
    0x00240000, (u32)func_80801964_chcollballcontrol, (u32)func_80107C2C, 0x80000002,
    0x00000000, 0x00000000,
};

u32 D_80805030_chcollballcontrol[] = {
    0x00000000, 0x00000000, 0x3F800000, 0x01D70001,
    0x3F800000, 0x01D70001, 0x3F99999A, 0x01D70001,
    0x3F800000, 0x01D70001, 0x3F800000, 0x01D70001,
    0x3F800000, 0x01D70001, 0x3F800000, 0x01D70001,
    0x3F800000, 0x01EB0002, 0x4B189680, 0x01D70001,
    0x3F800000, 0x01D70001, 0x40000000, 0x01D70001,
    0x4B189680, 0x01D70001,
};

u32 D_80805098_chcollballcontrol[] = {
    0x00000000, 0x00000000, 0x00000000,
};

u32 D_808050A4_chcollballcontrol[] = {
    0x00000000, 0x00000000, 0x00000000,
};

s32 D_808050B0_chcollballcontrol[] = {
    0xFFFFFFC8,
};

u32 D_808050B4_chcollballcontrol[] = {
    0x00000000, 0x00000000, 0x00000000,
};

u32 D_808050C0_chcollballcontrol[] = {
    0x00000000, 0x00000000, 0x00000000,
};

u32 D_808050CC_chcollballcontrol[] = {
    0x0040019F, 0x066A000B, (u32)D_80805030_chcollballcontrol, (u32)func_80803484_chcollballcontrol,
    (u32)func_80105834, (u32)_sukickball_entrypoint_1, 0x00000000, 0x00000000,
    0x00000000, 0x00000004, (u32)func_808044F4_chcollballcontrol, 0x00000000,
    0x00180000, (u32)func_80804420_chcollballcontrol, (u32)func_80107C2C, 0x80000003,
    (u32)func_80803420_chcollballcontrol, 0x00000000, 0x00000000, 0x00000000,
    0x00000000,
};

void func_80800000_chcollballcontrol(Unk80132ED0 **arg0, u32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    _subaddiedialog_entrypoint_11(*arg0, arg1, arg2 | 0xE, (f32 *)((s8 *)arg0 + 4), 0x33);
}

f32 func_80800040_chcollballcontrol(void *arg0) {
    void *func_80100094(Actor *, u32);

    return D_80804CB4_chcollballcontrol[*((u8 *)func_80100094(arg0, 0) + 0x14)];
}

/* extern */

f32 func_80800070_chcollballcontrol(void *arg0) {
    f32 func_80800040_chcollballcontrol(void *);
    return func_80800040_chcollballcontrol(arg0) * 0.75f;
}

/* extern */

f32 func_8080009C_chcollballcontrol() {
    f32 func_80800040_chcollballcontrol();
    return func_80800040_chcollballcontrol() * 0.33f;
}

/* extern */

f32 func_808000C8_chcollballcontrol() {
    f32 func_80800040_chcollballcontrol();
    return func_80800040_chcollballcontrol() * 0.05f;
}

f32 func_808000F4_chcollballcontrol()
{
    return func_808000C8_chcollballcontrol();
}

s32 func_80800114_chcollballcontrol(s32 arg0, s32 arg1) {

    return *(s32 *) ((u8 *) D_80804CF0_chcollballcontrol + (arg0 * 24) + (arg1 * 4));
}

s32 func_80800138_chcollballcontrol(s32 arg0) {

    return ((s32 *)&D_80804D68_chcollballcontrol)[arg0];
}

void func_8080014C_chcollballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct {
        u8 pad0[0x20];
        s32 words[6];
        u8 pad38;
        u8 mode;
        u8 count;
    } *data;
    s32 i;

    data = func_80100094(arg0, 0U);
    for (i = 0; i < data->count; i++) {
        if (data->mode == 1) {
            data->words[i] = 50;
        } else {
            data->words[i] = 0;
        }
    }
}

void func_808001B8_chcollballcontrol(Actor *arg0, s32 arg1) {
    f32 func_800DC178(f32, f32);
    Actor *func_801084B0(s32, Actor **);
    Actor *actor;

    switch (arg1) {
    case 1:
    case 6:
        actor = func_801084B0(0x1A1, &arg0);
        break;
    case 5:
        actor = func_801084B0(0x1A1, &arg0);
        actor->unk64_19 = 1;
        break;
    case 3:
        actor = func_801084B0(0x1A3, &arg0);
        break;
    case 2:
        actor = func_801084B0(0x1A2, &arg0);
        break;
    case 4:
        actor = func_801084B0(0x1A2, &arg0);
        actor->unk64_19 = 1;
        break;
    }
    actor->position[0] = func_800DC178(-470.0f, 470.0f);
    actor->position[2] = func_800DC178(-470.0f, 470.0f);
    actor->unk3C = arg0->unk0;
}

s32 func_808002B8_chcollballcontrol(Unk80132ED0 **arg0, s32 arg1, Unk80132ED0 *arg2) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _capod_entrypoint_17(f32);
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    u32 _gcgoto_entrypoint_1(u32, u32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _subaddiemulti_entrypoint_4(s32);
    void func_800A54F8(s32);
    s32 func_800CE88C(s32, s32);
    s32 func_800CE8D8(s32, f32, s32);
    s32 func_800D2054(s32, s32, s32);
    s16 func_800D211C(s32);
    s32 func_800D395C(void);
    s32 func_800DA9E4(s32, s32);
    s32 func_800EA05C(void);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    u32 func_800FDC28(u32);
    void func_8080014C_chcollballcontrol(Actor *);
    void func_808001B8_chcollballcontrol(Actor *, s32);
    void func_80801500_chcollballcontrol(Actor *, s32);
    struct Flags {
        u8 pad0[0x65];
        u8 unused0 : 3;
        u8 dialog : 1;
        u8 unused1 : 4;
        u8 pad1[0xC];
        u8 state : 6;
        u8 unused2 : 2;
        u8 pad2[6];
        u8 mode : 4;
        u8 unused3 : 4;
    };
    struct DialogEvent {
        s16 id;
        s16 choice;
    };
    struct BallData {
        u8 pad0[0x14];
        s32 markers[3];
        s32 score;
        u8 pad1[0x15];
        u8 level;
        u8 pad2;
        u8 result;
    };
    struct BallData *data;
    f32 duration;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0xB:
        ((u8 *)arg0)[0x79] = (((u8 *)arg0)[0x79] & ~0xF0) | 0x20;
        return 3;
    case 0xE:
        switch (data->level) {
        case 0:
            duration = 0.5f;
            break;
        case 1:
            duration = 0.5f;
            break;
        case 2:
            duration = 0.5f;
            break;
        }
        if (_capod_entrypoint_17(duration)) {
            _subaddiedialog_entrypoint_11(*arg0, data->level + 0x12C7, 6,
                func_80106790((Unk80132ED0 *)data->markers[data->level])->position, 0);
            ((struct Flags *)arg0)->dialog = 1;
        }
        return 3;
    case 0x2E:
        switch (((struct DialogEvent *)&arg2)->id) {
        case 0x12CC:
        case 0x12CD:
            if (func_800D2054(1, data->level + 0x91, data->score + 0x3E80) == 1) {
                func_80800000_chcollballcontrol(arg0, 0x12D4, 0x200);
                break;
            }
        case 0x127F:
        case 0x1280:
        case 0x12D4:
            func_80800000_chcollballcontrol(arg0, 0xCEB, 0x240);
            break;
        case 0xCEB:
            if (func_800D395C()) {
                if (((struct DialogEvent *)&arg2)->choice == 1) {
                    _gcfrontend_entrypoint_11();
                } else {
                    _gcfrontend_entrypoint_10();
                }
            } else if (((struct DialogEvent *)&arg2)->choice == 1) {
                _gcgoto_entrypoint_1(func_800EA05C(), 1);
            } else {
                _gcgoto_entrypoint_1(0x12D, 5);
            }
            break;
        case 0x127A:
            func_800FDC28(0xF);
            func_8080014C_chcollballcontrol(arg0);
            func_800CE8D8(0, (f32)func_80800138_chcollballcontrol(data->level),
                func_80800138_chcollballcontrol(data->level));
            func_800CE88C(0, 1);
            func_80801500_chcollballcontrol(arg0, 0);
            ((struct Flags *)arg0)->state = 4;
            break;
        case 0x12D1:
        case 0x12D2:
            _gcfrontend_entrypoint_10();
            break;
        case 0x12C7:
        case 0x12C8:
        case 0x12C9:
            ((struct Flags *)arg0)->dialog = 0;
            break;
        }
        break;
    case 0x30:
        switch (((struct DialogEvent *)&arg2)->id) {
        case 0x12D1:
            return data->result;
        case 0x12D4:
            return func_800D211C(data->level + 0x91) - 0x3E80;
        }
        break;
    case 0x3D:
        func_808001B8_chcollballcontrol(arg0, arg2);
        break;
    case 0x49:
        switch (data->level) {
        case 0:
        case 1:
        case 2:
            if (!func_800D395C() && !func_800DA9E4(data->level + 0x41F, 1)) {
                _capod_entrypoint_13((s32)*arg0, 0, 1, 0x2020);
                ((u8 *)arg0)[0x79] = (((u8 *)arg0)[0x79] & ~0xF0) | 0x10;
            } else {
                func_800A54F8(0);
            }
            break;
        case 4:
            _subaddiemulti_entrypoint_4(0);
            break;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808006FC_chcollballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_800D8FF8(void);
    void _sukickball_entrypoint_17(Actor *);
    void _sukickball_entrypoint_19(Actor *, s32, u8);
    s32 func_800DA298(s32);
    void _capod_entrypoint_14(void);
    void func_800A54F8(s32);
    s32 func_800CEB54(s32, f32);
    s32 func_800CEAD0(s32);
    u32 func_800FDC28(u32);
    u32 _gcgoto_entrypoint_1(u32, u32);
    void func_808008FC_chcollballcontrol(Actor *);
    void func_808011E8_chcollballcontrol(Actor *);
    struct CollballUpdate {
        f32 timer0;
        f32 timer1;
        u8 pad8[0x31];
        u8 mode;
        u8 count;
    } *data;
    f32 dt;

    data = func_80100094(arg0, 0);
    dt = func_800D8FF8();
    data->timer0 -= dt;
    data->timer1 -= dt;
    switch (arg0->unk70_10) {
    case 1:
        _sukickball_entrypoint_17(arg0);
        if (!func_800DA298(0x6AD)) {
            if (arg0->unk79_4 != 1 && !arg0->unk64_20) {
                if (arg0->unk79_4 == 2) {
                    _capod_entrypoint_14();
                }
                if (data->mode == 0 || data->mode == 1 || data->mode == 2) {
                    func_800A54F8(0);
                }
                func_80800000_chcollballcontrol(&arg0->unk0, 0x127A, 0);
                arg0->unk70_10 = 3;
            }
        }
        break;
    case 3:
        _sukickball_entrypoint_17(arg0);
        break;
    case 6:
        _sukickball_entrypoint_19(arg0, 1, data->count);
        break;
    case 4:
        _sukickball_entrypoint_19(arg0, 0, data->count);
        func_808011E8_chcollballcontrol(arg0);
        if (func_800CEB54(0, 6.0f)) {
            func_800FDC28(0x10);
        } else if (func_800CEAD0(0)) {
            func_808008FC_chcollballcontrol(arg0);
        }
        break;
    case 7:
        func_808011E8_chcollballcontrol(arg0);
        break;
    case 8:
        _sukickball_entrypoint_19(arg0, 1, data->count);
        if (arg0->unk58 > 0.0f) {
            arg0->unk58 -= func_800D8FF8();
        } else {
            _gcgoto_entrypoint_1(0x12D, 5);
        }
        break;
    }
}

void func_808008FC_chcollballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    u32 func_800FDC28(u32);
    void func_80801500_chcollballcontrol(Actor *, s32);
    s32 _sumultiscore_entrypoint_2(s32 *, s32 *, s32 *, s32, s32);
    void func_800FC6B0(u32);
    s32 func_800D2054(s32, s32, s32);
    s32 func_800DA544(s32);
    s32 func_80101FDC();
    void func_800AA200(s32);
    struct CollballScore {
        u8 pad0[0x20];
        s32 scores[4];
        u8 winners[4];
        u8 pad34[5];
        u8 mode;
        u8 count;
        s8 result;
    } *data;
    s32 places[4];
    s32 result;
    s32 ties[4];
    u32 dialog;
    s32 i;

    data = func_80100094(arg0, 0);
    arg0->unk70_10 = 6;
    func_80801500_chcollballcontrol(arg0, 1);
    func_800FDC28(0);
    result = _sumultiscore_entrypoint_2(data->scores, places, ties, 1, data->count);
    if (data->mode < 4) {
        if (arg0->unk64_19) {
            switch (places[0]) {
            case 1:
                if (ties[0] == 0) {
                    func_800FC6B0(0x16);
                    func_80800000_chcollballcontrol(&arg0->unk0, 0x12CC, 0x200);
                    break;
                }
            case 2:
            case 3:
            case 4:
                func_80800000_chcollballcontrol(&arg0->unk0, 0x12CD, 0x200);
                func_800FC6B0(0x17);
                break;
            }
        } else {
            switch (places[0]) {
            case 1:
                if (ties[0] == 0) {
                    func_800D2054(1, data->mode + 0x91, data->scores[0] + 0x3E80);
                    func_800DA544(0xA17);
                    func_800FC6B0(0x16);
                    func_80101FDC(arg0, 8);
                    arg0->unk58 = 2.5f;
                    break;
                }
            case 2:
            case 3:
                func_80800000_chcollballcontrol(&arg0->unk0, 0x127F, 0x200);
                func_800FC6B0(0x17);
                break;
            case 4:
                func_80800000_chcollballcontrol(&arg0->unk0, 0x1280, 0x200);
                func_800FC6B0(0x17);
                break;
            }
        }
    } else {
        func_800AA200(1);
        for (i = 0; i < data->count; i++) {
            if (places[i] == 1) {
                data->winners[i] = 1;
            } else {
                data->winners[i] = 0;
            }
        }
        if (result != 0) {
            dialog = 0x12D1;
            data->result = result;
        } else {
            dialog = 0x12D2;
        }
        func_800FC6B0(0x10);
        func_80800000_chcollballcontrol(&arg0->unk0, dialog, 0);
    }
}

/* extern */

void func_80800B5C_chcollballcontrol(u8 *arg0) {
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_8080324C_chcollballcontrol();
    Actor *actor = (Actor *)arg0;
    ((f32 *)actor->actorData)[3] = func_8080009C_chcollballcontrol();
    ((f32 *)actor->actorData)[7] = func_800DC178(0.9f, 1.1f) * 45.0f;
    if (func_800DC0C0() < 0.5f) {
        ((f32 *)actor->actorData)[7] = -((f32 *)actor->actorData)[7];
    }
    func_8080324C_chcollballcontrol(arg0, 9);
    actor->unk64_20 = 1;
}

void func_80800BF0_chcollballcontrol(Actor *arg0, f32 *arg1) {
    s32 _sukickball_entrypoint_6(u8 *, s32);
    Unk80132ED0 *_sukickball_entrypoint_8(u8 *, s32);
    int func_800F0064(f32 *, f32, f32 *);
    void func_800F5A00(s32, f32 *);
    void func_800F7B9C(s32, u32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    struct {
        u8 pad[0x3A];
        u8 count;
    } *data;
    f32 position[4];
    s32 i;
    Actor *actor;

    data = func_80100094(arg0, 0);
    for (i = 0; i < data->count; i++) {
        if (_sukickball_entrypoint_6(arg0, i)) {
            func_800F5A00(i, position);
            if (func_800F0064(position, 200.0f, arg1)) {
                func_800F7B9C(i, 0x38);
            }
        } else {
            actor = func_80106790(_sukickball_entrypoint_8(arg0, i));
            if (func_800F0064(actor->position, 200.0f, arg1)) {
                func_80800B5C_chcollballcontrol((u8 *)actor);
            }
        }
    }
}

void func_80800CF8_chcollballcontrol(s32 arg0, s32 arg1) {
    struct player_state_s;
    struct player_state_s *func_800F53D0(s32);
    void func_800F82D4(s32, s32);
    void _baattach_entrypoint_6(struct player_state_s *, s32, s32, s32);
    switch (arg1) {
        case 0:
            func_800F82D4(arg0, 0);
            break;
        case 1:
            func_800F82D4(arg0, 2);
            _baattach_entrypoint_6(func_800F53D0(arg0), 3, 0, 0);
            break;
    }
}

/* extern */

void func_80800D60_chcollballcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chintrotext_entrypoint_1(s32, s32, s32, s32);
    s32 _chintrotext_entrypoint_2(s32);
    s32 func_800D395C(void);
    if ((arg1 != 0) || (func_800D395C() != 0)) {
        arg0->unk64_19 = 1;
        _chintrotext_entrypoint_1(0x18B5, arg2 + 0xE, 0, 0);
        return;
    }
    arg0->unk64_19 = 0;
    _chintrotext_entrypoint_2(1);
}

void func_80800DD8_chcollballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_801084B0(s32, Actor **);
    s32 func_80090178(AllowedTransformation);
    void func_800FFAB0(Actor *);
    void func_800DA3B8(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800D0A9C(u32, u32);
    s32 func_800F6438(u32);
    void func_800F4CEC(s32, u32);
    u8 _sukickball_entrypoint_3(void);
    s32 _gcstatusDll_entrypoint_11(void);
    void _sukickball_entrypoint_18(Actor *);
    void func_80801108_chcollballcontrol(Actor *, s32);

    struct Fields {
        u8 pad0[0xA];
        u8 types[4];
        u8 padE[2];
        Unk80132ED0 *actors[4];
        u8 pad20[0x14];
        u8 flags[4];
        u8 pad38;
        u8 mode;
        u8 count;
        u8 pad3B;
        u8 active;
    } *data, *other;
    s32 i;
    s32 j;
    Actor *actor;

    data = func_80100094(arg0, 0);
    data->active = 0;
    if (!func_80090178(0x80)) {
        func_800FFAB0(arg0);
        return;
    }
    func_800DA3B8(0x65A, 1);
    data->mode = _sukickball_entrypoint_3();
    data->count = D_80804D7C_chcollballcontrol[data->mode];
    switch (data->mode) {
        case 0:
            func_80800D60_chcollballcontrol(arg0, func_800DA298(0x368), data->mode);
            break;
        case 1:
            func_80800D60_chcollballcontrol(arg0, func_800DA298(0x369), data->mode);
            break;
        case 2:
            func_80800D60_chcollballcontrol(arg0, func_800D0A9C(0x44, 1), data->mode);
            break;
        case 4:
            for (j = 0; j != 8; j++) {
                if (func_800F6438(j)) {
                    func_800F4CEC(j, 0);
                }
            }
            data->count = _gcstatusDll_entrypoint_11();
            break;
    }
    for (i = 0; i < data->count; i++) {
        other = func_80100094(arg0, 0);
        other->flags[i] = 0;
        other->actors[i] = NULL;
    }
    if (data->mode == 4) {
        data->types[0] = 1;
    } else {
        data->types[0] = 2;
    }
    data->types[1] = 1;
    data->types[2] = 1;
    data->types[3] = 1;
    for (i = 0; i < data->count; i++) {
        switch (data->types[i]) {
            case 2:
                break;
            case 1:
                data->actors[i] = (actor = func_801084B0(0x19F, &arg0))->unk0;
                actor->unk3C = arg0->unk0;
                break;
        }
        func_80801108_chcollballcontrol(arg0, i);
    }
    _sukickball_entrypoint_18(arg0);
    data->active = 1;
}

void func_80801038_chcollballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800DA3B8(s32, s32);
    void func_800F4CC0(s32);
    s32 func_800F6438(u32);
    struct Fields {
        u8 pad0[0x39];
        u8 state;
        u8 pad1[2];
        u8 active;
    };
    struct Fields *data;
    s32 i;

    data = func_80100094(arg0, 0);
    if (data->active != 0) {
        func_800DA3B8(0x65A, 0);
        if (data->state == 4) {
            i = 0;
            do {
                if (func_800F6438(i) != 0) {
                    func_800F4CC0(i);
                }
                i++;
            } while (i != 8);
        }
    }
}

void func_808010B8_chcollballcontrol(void *arg0, s32 arg1) {
    struct Fields {
        u8 pad0[0x64];
        u8 unused : 7;
        u8 active : 1;
        u8 pad1[9];
        u16 high : 7;
        u16 state : 9;
    };
    struct Fields *p = arg0;
    p->state = arg1;
    if (arg1 == 2) {
        p->active = 1;
    } else {
        p->active = 0;
    }
}

s32 func_808010F8_chcollballcontrol(void *arg0) {
    return (*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF;
}

void func_80801108_chcollballcontrol(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 _sukickball_entrypoint_15(s32);
    void _sukickball_entrypoint_16(s32, f32 *);
    void func_800F82D4(s32, s32);
    s32 func_800F832C(s32, f32 *);
    void func_800F8294(s32, f32 *);
    struct Data {
        u8 pad[0xA];
        u8 state[6];
        Unk80132ED0 *markers[6];
    } *data;
    Actor *actor;
    f32 position[3];

    data = func_80100094(arg0, 0);
    switch (data->state[arg1]) {
    case 1:
        actor = func_80106790(data->markers[arg1]);
        _sukickball_entrypoint_16(arg1, actor->position);
        actor->rotation[1] = _sukickball_entrypoint_15(arg1);
        actor->unk54 = actor->rotation[1];
        func_808010B8_chcollballcontrol(actor, arg1);
        break;
    case 2:
        func_800F82D4(arg1, 2);
        position[0] = 0.0f;
        position[1] = _sukickball_entrypoint_15(arg1);
        position[2] = 0.0f;
        func_800F832C(arg1, position);
        _sukickball_entrypoint_16(arg1, position);
        func_800F8294(arg1, position);
        break;
    }
}

void func_808011E8_chcollballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_80801350_chcollballcontrol(Actor *, s32 *);
    void func_80801650_chcollballcontrol(Actor *);
    s32 state;
    struct Counts {
        s32 values[6];
    } counts;

    struct {
        u8 pad[0x39];
        u8 mode;
    } *data;
    data = func_80100094(arg0, 0);
    counts = (*(struct Counts *)D_80804D90_chcollballcontrol);
    state = -1;
    func_80801350_chcollballcontrol(arg0, counts.values);
    if (counts.values[1] < func_80800114_chcollballcontrol(data->mode, 1)) {
        state = 1;
    } else if (counts.values[2] < func_80800114_chcollballcontrol(data->mode, 2)) {
        state = 2;
    } else if (counts.values[3] < func_80800114_chcollballcontrol(data->mode, 3)) {
        state = 3;
    } else if (counts.values[4] < func_80800114_chcollballcontrol(data->mode, 4)) {
        state = 4;
    } else if (counts.values[5] < func_80800114_chcollballcontrol(data->mode, 5)) {
        state = 5;
    }
    if (state >= 0) {
        func_80108B04(arg0, state);
    } else if (counts.values[0] < func_80800114_chcollballcontrol(data->mode, 0)) {
        func_80801650_chcollballcontrol(arg0);
    }
}

void func_80801350_chcollballcontrol(Actor *arg0, s32 *arg1) {
    typedef struct { u8 pad[0x1A]; u16 index; u8 pad1[8]; u32 id:10; u32 flags:22; } Marker;
    typedef struct { Marker *marker; s32 unk4; u32 flags; } Entry;
    s32 *func_800BE444(f32 *);
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    Actor *func_80106790(Unk80132ED0 *);
    Entry *entry, *end;
    s32 *list;
    s32 i;
    for (i = 0; i < 6; i++) {
        arg1[i] = 0;
    }
    list = func_800BE444(arg0->position);
    while (*list != 0) {
        entry = (Entry *)func_800E9E88(*list);
        end = (Entry *)func_800E9EB4((s16 *)*list);
        for (; entry < end; entry++) {
            if (entry->flags & 1) {
                switch (entry->marker->id) {
                case 0x44:
                    if (func_80106790(entry->marker)->unk64_19) {
                        arg1[5]++;
                    } else {
                        arg1[1]++;
                    }
                    break;
                case 0x43:
                    if (func_80106790(entry->marker)->unk64_19) {
                        arg1[4]++;
                    } else {
                        arg1[2]++;
                    }
                    break;
                case 0x42:
                    arg1[3]++;
                    break;
                }
            }
        }
        list++;
    }
    arg1[0] = arg1[1] + arg1[2] + arg1[3] + arg1[4] + arg1[5];
}

void func_80801500_chcollballcontrol(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_808015D4_chcollballcontrol(Actor *, s32, s32);
    s32 var_s0;
    struct {
        u8 pad[0x3A];
        u8 count;
    } *data;

    data = func_80100094(arg0, 0U);
    var_s0 = 0;
    if ((s32) data->count > 0) {
        do {
            func_808015D4_chcollballcontrol(arg0, var_s0, arg1);
            var_s0 += 1;
        } while (var_s0 < (s32) data->count);
    }
}

void func_80801578_chcollballcontrol(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    void func_8080324C_chcollballcontrol();
    void *actor;

    actor = func_80106790(arg0);
    switch (arg1) {
        case 0:
            func_8080324C_chcollballcontrol(actor, 2);
            return;
        case 1:
            func_8080324C_chcollballcontrol(actor, 0xB);
            return;
    }
}

void func_808015D4_chcollballcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    struct {
        u8 unk0[0xA];
        u8 kind[6];
        Unk80132ED0 *entries[6];
    } *data;
    u8 kind;

    data = func_80100094(arg0, 0);
    kind = data->kind[arg1];
    if (kind != 0) {
        if (kind != 1) {
            if (kind == 2) {
                func_80800CF8_chcollballcontrol(arg1, arg2);
            }
        } else {
            func_80801578_chcollballcontrol(data->entries[arg1], arg2);
        }
    }
}

void func_80801650_chcollballcontrol(Actor *arg0) {
    f32 func_800DC0C0(void);
    int func_800DC298(f32);
    s32 func_800EA05C(void);
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);

    struct {
        u8 pad[0x39];
        u8 kind;
    } *data;
    f32 random;
    s32 state;
    u8 kind;
    f32 *thresholds;

    data = func_80100094(arg0, 0);
    random = func_800DC0C0();
    if (func_800EA05C() != 0x12D || arg0->unk70_10 != 1) {
        kind = data->kind;
        thresholds = D_80804CC8_chcollballcontrol[kind];
        if (random < thresholds[0] && kind != 1) {
            if (func_800DC298(0.5f) || data->kind == 0) {
                state = 1;
            } else {
                state = 5;
            }
        } else if (random < thresholds[1]) {
            if (func_800DC298(0.5f)) {
                state = 2;
            } else {
                state = 4;
            }
        } else {
            state = 3;
        }
        func_80108B04(arg0, state);
    }
}

OSThread *chcollballcontrol_entrypoint_0(void)
{


    return (OSThread *) D_80804DA8_chcollballcontrol;
}

void func_80801764_chcollballcontrol(u8 *arg0, s32 arg1) {
    void _subaddiefade_entrypoint_3(Actor *);
    void _sukickball_entrypoint_11(u8 *, s32);
    s32 _sukickball_entrypoint_6(u8 *, s32);
    void func_800B4470(u8 *, s32, void *, s32, f32, f32, s32, s32, s32);
    void func_800F4F98(s32, void *);
    void *func_80100094(Actor *, u32);
    s32 func_80101FDC(u8 *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_808021D4_chcollballcontrol(Actor *);
    void func_80802264_chcollballcontrol(Actor *volatile, volatile s32);

    u8 *data;
    s32 linked;
    u32 kind;
    u32 state;

    data = func_80100094(arg0, 0);
    state = (u32)*(u16 *)(arg0 + 0x72) >> 10;
    if (state == 2 && arg1 != state) {
        linked = *(s32 *)(arg0 + 0x3C);
        if (linked != 0) {
            if (_sukickball_entrypoint_6(func_80106790(linked), data[0x20])) {
                func_800F4F98(data[0x20], *(void **)arg0);
            }
            _sukickball_entrypoint_11(func_80106790(*(s32 *)(arg0 + 0x3C)), data[0x20]);
            state = (u32)*(u16 *)(arg0 + 0x72) >> 10;
        }
    }
    if (state == 3 && arg1 == 2 && (*(u32 *)(*(u8 **)arg0 + 0x24) >> 22) == 0x42) {
        *(f32 *)(data + 0x14) = 20.0f;
        *(f32 *)(data + 0x18) = 2.0f;
        _subaddiefade_entrypoint_3(arg0);
        func_808021D4_chcollballcontrol(arg0);
        arg1 = 4;
    }
    func_80101FDC(arg0, arg1);
    if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 6) {
        func_808021D4_chcollballcontrol(arg0);
        _subaddiefade_entrypoint_3(arg0);
        func_800B4470(arg0 + 4, 0, D_80804DF0_chcollballcontrol, 1, 0.75f, 0.0f, 0x7D, 0xFA, 0);
        kind = *(u32 *)(*(u8 **)arg0 + 0x24) >> 22;
        if (kind != 0x43) {
            if (kind == 0x44) {
                func_80802264_chcollballcontrol(arg0, 1);
            }
        } else {
            func_80802264_chcollballcontrol(arg0, 2);
        }
    }
}

void func_80801920_chcollballcontrol(u8 *arg0) {
    void *func_80100094(Actor *, u32);
    u8 *data;

    data = func_80100094(arg0, 0);
    *(s8 *)(data + 0x20) = 0x7F;
    *(f32 *)(data + 4) = 0.0f;
    *(f32 *)data = 0.0;
    *(f32 *)(arg0 + 0x24) = 0.0f;
}

void func_80801964_chcollballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_800DC178(f32, f32);
    void func_8010A590(Actor *);
    f32 *data;

    data = func_80100094(arg0, 0);
    arg0->unk74_17 = 0;
    func_8010A590(arg0);
    arg0->scale = 1.5f;
    arg0->rotation[0] = func_800DC178(0.0f, 45.0f);
    arg0->rotation[2] = func_800DC178(0.0f, 45.0f);
    func_80801920_chcollballcontrol((u8 *)arg0);
    if (arg0->unk64_19) {
        data[5] = 20.0f;
        data[6] = 8.0f;
    }
    arg0->alpha = 0;
    arg0->position[1] = -75.0f;
}

void func_80801A20_chcollballcontrol(Actor *arg0) {
    s32 _sukickball_entrypoint_6(u8 *, s32);
    s32 _sukickball_entrypoint_7(u8 *, s32);
    Unk80132ED0 *_sukickball_entrypoint_8(u8 *, s32);
    f32 func_800137AC(f32);
    f32 func_800137C4(void);
    void func_800B4470(u8 *, s32, void *, s32, f32, f32, s32, s32, s32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    f32 func_800DC0C0(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800EFBFC(void *, void *);
    void func_800EFCD8(f32 *, f32, f32);
    void func_800F5A00(s32, f32 *);
    void func_800F5D70(s32, f32 *);
    f32 func_800F5F24(u32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_808020B0_chcollballcontrol(void *);
    void func_808020F4_chcollballcontrol(Actor *);
    void func_808021D4_chcollballcontrol(Actor *);
    void func_808022F0_chcollballcontrol(f32 *);
    void func_80802764_chcollballcontrol(s32 *);
    void func_80802CE0_chcollballcontrol(u8 *);
    void func_808030D0_chcollballcontrol(Actor *);

    f32 *data;
    u8 *linked;
    f32 position[3];
    f32 previous[3];
    f32 velocity[3];
    Actor *carrier;
    Actor *kicker;
    f32 sine;
    f32 cosine;

    data = func_80100094(arg0, 0);
    linked = (u8 *)func_80106790(arg0->unk3C);
    switch (arg0->unk70_10) {
        case 5:
            if (arg0->position[1] < 25.0f) {
                arg0->position[1] += 5.0f;
            }
            if ((u32)arg0->alpha < 240.0f) {
                arg0->alpha = (u32)arg0->alpha + 15.0f;
            } else if (arg0->position[1] >= 25.0f) {
                arg0->unk70_10 = 1;
                arg0->alpha = 255;
            }
            break;
        case 1:
            func_80802CE0_chcollballcontrol((u8 *)arg0);
            func_80802764_chcollballcontrol((s32 *)arg0);
            func_808020B0_chcollballcontrol(arg0);
            break;
        case 2:
            func_800EE7F8(previous, arg0->position);
            func_80802764_chcollballcontrol((s32 *)arg0);
            if (_sukickball_entrypoint_6(linked, ((u8 *)data)[0x20])) {
                func_800F5A00(((u8 *)data)[0x20], position);
                arg0->unk54 = func_800F5F24(((u8 *)data)[0x20]);
                arg0->position[1] = 0.0f;
                func_800EFCD8(arg0->position, arg0->unk54, 60.0f);
                func_800EF04C(arg0->position, position);
                func_800F5D70(((u8 *)data)[0x20], velocity);
                arg0->unk50 = velocity[0] * velocity[0] + velocity[2] * velocity[2];
                func_800EE7F8((f32 *)arg0->actorData, position);
            } else {
                carrier = func_80106790(_sukickball_entrypoint_8(linked, ((u8 *)data)[0x20]));
                arg0->position[1] = 0.0f;
                func_800EFCD8(arg0->position, carrier->rotation[1], 60.0f);
                func_800EF04C(arg0->position, carrier->position);
                arg0->unk54 = carrier->rotation[1];
                arg0->unk50 = ((f32 *)carrier->actorData)[3] * ((f32 *)carrier->actorData)[3];
                func_800EE7F8((f32 *)arg0->actorData, carrier->position);
            }
            if (func_800EFBFC(previous, arg0->position) > 25.0f && func_800DC0C0() < 0.1f) {
                func_800B4470((u8 *)previous, 0, D_80804DF4_chcollballcontrol, 1, 0.75f, 0.0f, 75, 150, 0);
            }
            func_800D9078(data);
            func_80802CE0_chcollballcontrol((u8 *)arg0);
            if (_sukickball_entrypoint_7(linked, ((u8 *)data)[0x20])) {
                kicker = func_80106790(_sukickball_entrypoint_8(linked, ((u8 *)data)[0x20]));
                if (kicker->unk64_20 == 1) {
                    func_808030D0_chcollballcontrol(arg0);
                    kicker->unk58 = 0.0f;
                    kicker->unk64_20 = 0;
                }
            }
            func_808020B0_chcollballcontrol(arg0);
            break;
        case 3:
            func_80802764_chcollballcontrol((s32 *)arg0);
            func_800EF1B8(arg0->position, arg0->rotation[1], ((f32 *)arg0->actorData)[3] * func_800D8FF8());
            ((f32 *)arg0->actorData)[3] -= 6.0f;
            if ((arg0->unk0->unk24 >> 22) == 0x42 && ((f32 *)arg0->actorData)[3] < 600.0f) {
                data[5] += data[6];
                data[6] += 0.5f;
            }
            if (((f32 *)arg0->actorData)[3] <= 0.0f) {
                func_80801764_chcollballcontrol((u8 *)arg0, 1);
                func_808021D4_chcollballcontrol(arg0);
            }
            func_80802CE0_chcollballcontrol((u8 *)arg0);
            if (func_800DC0C0() < 0.15f && ((f32 *)arg0->actorData)[3] > 120.0f) {
                func_800B4470((u8 *)arg0->position, 0, D_80804DF4_chcollballcontrol, 1, 0.75f, 0.0f, 50, 100, 0);
            }
            func_808020B0_chcollballcontrol(arg0);
            break;
        case 4:
            func_80802764_chcollballcontrol((s32 *)arg0);
            func_808020F4_chcollballcontrol(arg0);
            break;
        case 6:
            ((f32 *)arg0->actorData)[3] -= 15.0f;
            func_808020F4_chcollballcontrol(arg0);
            break;
    }
    if (((f32 *)arg0->actorData)[3] > 30.0f) {
        sine = func_800137AC(arg0->rotation[1]);
        cosine = func_800137C4();
        arg0->rotation[0] += 2.0f * (sine * ((f32 *)arg0->actorData)[3]) / 30.0f;
        arg0->rotation[2] -= 2.0f * (cosine * ((f32 *)arg0->actorData)[3]) / 30.0f;
    }
    if ((arg0->unk0->unk24 >> 22) == 0x42 && arg0->unk70_10 != 4 && arg0->unk70_10 != 6 && arg0->unk7C_12 && func_800DC0C0() < 0.1f) {
        func_808022F0_chcollballcontrol(data + 2);
    }
    if (arg0->unk64_19) {
        data[5] += data[6];
    }
    if (data[7] > 0.0f) {
        data[7] -= func_800D8FF8();
    }
}

/* extern */

void func_808020B0_chcollballcontrol(void *arg0) {
    s32 func_8080237C_chcollballcontrol();
    s32 func_808023FC_chcollballcontrol(void *, s32);
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = func_8080237C_chcollballcontrol();
    temp_a1 = temp_v0;
    (*(f32 *)((s8 *)(arg0) + (8))) = 30.0f;
    if (temp_v0 != -1) {
        func_808023FC_chcollballcontrol(arg0, temp_a1);
    }
}

void func_808020F4_chcollballcontrol(Actor *arg0) {
    arg0->position[1] -= 5.0f;
    arg0->alpha = (u32)arg0->alpha * 0.7f;
    arg0->scale *= 0.95f;
}

void func_808021D4_chcollballcontrol(Actor *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    void func_80802324_chcollballcontrol(f32 *);
    void func_80802A50_chcollballcontrol(Actor *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefade_entrypoint_3(Actor *);
    void func_80800BF0_chcollballcontrol(Actor *, f32 *);

    Actor *sp24;

    sp24 = func_80106790(arg0->unk3C);
    if ((arg0->unk0->unk24 >> 22) == 0x42) {
        func_80802324_chcollballcontrol(arg0->position);
        func_80802A50_chcollballcontrol(arg0);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804C64_chcollballcontrol);
        _subaddiefade_entrypoint_3(arg0);
        func_80801764_chcollballcontrol((u8 *)arg0, 4);
        func_80800BF0_chcollballcontrol(sp24, arg0->position);
    }
}

void func_80802264_chcollballcontrol(Actor *volatile arg0, volatile s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800BA22C(s32, s32);
    void func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);


    s32 emitter;
    s32 model;
    f32 *position;

    position = arg0->position;
    emitter = func_800BABB8(0, position, NULL, 1.0f, D_80804E08_chcollballcontrol);
    model = (arg1 == 1) ? 0x679 : 0x67A;
    func_800BA670(emitter, model);
    func_800BA22C(emitter, 0xA);
    _subaddieaudioquick_entrypoint_2(arg0, position, D_80804C74_chcollballcontrol);
}

void func_808022F0_chcollballcontrol(f32 *arg0) {
    void func_800BBCB8(f32[3], s32, f32, s32, s32 *);

    func_800BBCB8(arg0, 0, 1.0f, 2, D_80804E4C_chcollballcontrol);
}

void func_80802324_chcollballcontrol(f32 *arg0) {
    void func_800BBCB8(f32[3], s32, f32, s32, s32 *);


    func_800BBCB8(arg0, 0, 1.0f, 0xA, D_80804E94_chcollballcontrol);
    func_800BBCB8(arg0, 0, 1.0f, 5, D_80804EE4_chcollballcontrol);
}

s32 func_8080237C_chcollballcontrol(void *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;

    temp_f0 = (*(f32 *)((s8 *)(arg0) + (4)));
    if (temp_f0 < -675.0f) {
        return 2;
    }
    if (temp_f0 > 675.0f) {
        return 0;
    }
    temp_f0_2 = (*(f32 *)((s8 *)(arg0) + (0xC)));
    if (temp_f0_2 < -675.0f) {
        return 3;
    }
    if (temp_f0_2 > 675.0f) {
        return 1;
    }
    return -1;
}

s32 func_808023FC_chcollballcontrol(void *ptr, s32 arg1) {
    void func_80802AF8_chcollballcontrol(Actor *, s32);
    u8 *arg0 = ptr;

    switch (arg1) {
        case 0:
            if (*(f32 *)(arg0 + 0xC) > -183.0f && *(f32 *)(arg0 + 0xC) < 183.0f) {
                if (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4 && *(f32 *)(arg0 + 4) > 720.0f) {
                    func_80802AF8_chcollballcontrol(arg0, 0);
                }
                if (*(f32 *)(arg0 + 4) > 801.0f) {
                    *(f32 *)(arg0 + 4) = 846.0f;
                    *(f32 *)(arg0 + 0x24) = 0.0f;
                }
            } else {
                *(f32 *)(arg0 + 4) = 720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801764_chcollballcontrol(arg0, 6);
            }
            break;
        case 1:
            if (*(f32 *)(arg0 + 4) < 183.0f && *(f32 *)(arg0 + 4) > -183.0f) {
                if (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4 && *(f32 *)(arg0 + 0xC) > 720.0f) {
                    func_80802AF8_chcollballcontrol(arg0, 1);
                }
                if (*(f32 *)(arg0 + 0xC) > 801.0f) {
                    *(f32 *)(arg0 + 0xC) = 846.0f;
                    *(f32 *)(arg0 + 0x24) = 0.0f;
                }
            } else {
                *(f32 *)(arg0 + 0xC) = 720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801764_chcollballcontrol(arg0, 6);
            }
            break;
        case 2:
            if (*(f32 *)(arg0 + 0xC) < 183.0f && *(f32 *)(arg0 + 0xC) > -183.0f) {
                if (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4 && *(f32 *)(arg0 + 4) < -720.0f) {
                    func_80802AF8_chcollballcontrol(arg0, 2);
                }
                if (*(f32 *)(arg0 + 4) < -801.0f) {
                    *(f32 *)(arg0 + 4) = -846.0f;
                    *(f32 *)(arg0 + 0x24) = 0.0f;
                }
            } else {
                *(f32 *)(arg0 + 4) = -720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801764_chcollballcontrol(arg0, 6);
            }
            break;
        case 3:
            if (*(f32 *)(arg0 + 4) > -183.0f && *(f32 *)(arg0 + 4) < 183.0f) {
                if (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4 && *(f32 *)(arg0 + 0xC) < -720.0f) {
                    func_80802AF8_chcollballcontrol(arg0, 3);
                }
                if (*(f32 *)(arg0 + 0xC) < -801.0f) {
                    *(f32 *)(arg0 + 0xC) = -846.0f;
                    *(f32 *)(arg0 + 0x24) = 0.0f;
                }
            } else {
                *(f32 *)(arg0 + 0xC) = -720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801764_chcollballcontrol(arg0, 6);
            }
            break;
    }
}

void func_80802764_chcollballcontrol(s32 *arg0) {
    typedef struct { u8 pad[0x1A]; u16 index; u8 pad1[8]; u32 id:10; u32 flags:22; } Marker;
    typedef struct { Marker *marker; s32 unk4; u32 flags; } Entry;
    s32 *func_800BE3F8(void *);
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_808028D0_chcollballcontrol(Actor *, Actor *);
    void func_80802964_chcollballcontrol(Actor *, u32);
    void func_808029D8_chcollballcontrol(Actor *, Actor *);
    s32 *list;
    Entry *entry;
    Entry *end;
    Marker *marker;

    list = func_800BE3F8(arg0 + 1);
    while (*list != 0) {
        entry = (Entry *)func_800E9E88(*list);
        end = (Entry *)func_800E9EB4((s16 *)*list);
        for (; entry < end; entry++) {
            if (entry->flags & 1) {
                marker = entry->marker;
                if (marker != (Marker *)*arg0) {
                    if (marker->id == 0x44 || marker->id == 0x42 || marker->id == 0x43) {
                        func_808028D0_chcollballcontrol(arg0, func_80106790((s32)marker));
                    }
                    if (marker->id == 0) {
                        func_80802964_chcollballcontrol(arg0, (u32)marker->index >> 5);
                    }
                    if (marker->id == 0x40) {
                        func_808029D8_chcollballcontrol(arg0, func_80106790((s32)marker));
                    }
                }
            }
        }
        list++;
    }
}

void func_808028D0_chcollballcontrol(Actor *arg0, Actor *arg1) {
    void *func_80100094(Actor *, u32);
    s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);

    f32 *sp1C;

    sp1C = func_80100094(arg0, 0);
    if (_sukickball_entrypoint_13(arg0->position, arg1->position, 60.0f) && sp1C[7] <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804C84_chcollballcontrol);
        sp1C[7] = 0.75f;
    }
}

void func_80802964_chcollballcontrol(Actor *arg0, u32 arg1) {
    s32 _sukickball_entrypoint_12(u8 *, s32);
    s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
    void func_800F5A00(s32, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *parent;
    f32 sp18[3];

    parent = func_80106790(arg0->unk3C);
    if (arg0->unk70_10 != 2 && _sukickball_entrypoint_12((u8 *)parent, arg1)) {
        func_800F5A00(arg1, sp18);
        _sukickball_entrypoint_13(sp18, arg0->position, 62.999996185302734375f);
    }
}

void func_808029D8_chcollballcontrol(Actor *arg0, Actor *arg1) {
    s32 _sukickball_entrypoint_12(u8 *, s32);
    s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *parent;

    parent = func_80106790(arg0->unk3C);
    if (arg0->unk70_10 != 2) {
        if (_sukickball_entrypoint_12((u8 *)parent, func_808010F8_chcollballcontrol(arg1))) {
            _sukickball_entrypoint_13(arg1->position, arg0->position, 62.999996185302734375f);
        }
    }
}

void func_80802A50_chcollballcontrol(Actor *arg0) {
    typedef struct { f32 timer; u8 pad[0x1C]; u8 owner; } BallData;
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _sukickball_entrypoint_6(u8 *, s32);
    void _sukickball_entrypoint_11(u8 *, s32);
    void func_800F4F98(s32, void *);
    BallData *data;
    Actor *parent;

    data = func_80100094(arg0, 0);
    parent = func_80106790(arg0->unk3C);
    if (data->owner != 0x7F) {
        if (_sukickball_entrypoint_6(parent, data->owner)) {
            func_800F4F98(data->owner, arg0->unk0);
            _sukickball_entrypoint_11(parent, data->owner);
        } else {
            _sukickball_entrypoint_11(parent, data->owner);
        }
        data->owner = 0x7F;
        data->timer = 10000000.0f;
    }
}

void func_80802AF8_chcollballcontrol(Actor *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    void _subaddiefade_entrypoint_3(Actor *);
    void _sukickball_entrypoint_9(Actor *, s32, s32);

    Actor *parent;
    u32 id;

    parent = func_80106790(arg0->unk3C);
    func_80802A50_chcollballcontrol(arg0);
    id = arg0->unk0->unk24 >> 22;
    switch (id) {
    case 0x44:
        if (arg0->unk64_19) {
            _sukickball_entrypoint_9(parent, D_80804F2C_chcollballcontrol[arg1], 5);
        } else {
            _sukickball_entrypoint_9(parent, D_80804F2C_chcollballcontrol[arg1], 1);
        }
        break;
    case 0x42:
        _sukickball_entrypoint_9(parent, D_80804F2C_chcollballcontrol[arg1], 3);
        break;
    case 0x43:
        if (arg0->unk64_19) {
            _sukickball_entrypoint_9(parent, D_80804F2C_chcollballcontrol[arg1], 4);
        } else {
            _sukickball_entrypoint_9(parent, D_80804F2C_chcollballcontrol[arg1], 2);
        }
        break;
    }
    arg0->unk70_10 = 4;
    _subaddiefade_entrypoint_3(arg0);
}

void chcollballcontrol_entrypoint_1(Unk80132ED0 *arg0, s32 arg1, u32 arg2, s32 arg3) {
    typedef struct { f32 unknown; f32 timer; } ControlData;
    f32 func_800D8FF8(void);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_808030D0_chcollballcontrol(Actor *);
    void *actor;
    ControlData *data;

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0);
    if (arg1 != 1) {
        if (arg1 == 3) {
            func_80801764_chcollballcontrol(actor, 1);
        }
    } else {
        data->timer = func_800D8FF8() * arg2;
        func_808030D0_chcollballcontrol(actor);
    }
}

void func_80802CE0_chcollballcontrol(u8 *arg0) {
    typedef struct { f32 v[4]; } Distances;
    typedef struct { f32 v[3]; } Position;
    typedef struct { f32 timer; u8 pad[0x1C]; u8 owner; } BallData;
    typedef struct { u8 pad[0x3A]; u8 count; } ParentData;
    typedef struct { u8 pad[0x24]; u32 id:10; u32 flags:22; } MarkerState;
    typedef struct { u8 pad[0x70]; u32 upper:16; u32 state:6; u32 flags:10; } ActorState;


    extern void _chcollballcontrol_entrypoint_1(void);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _sukickball_entrypoint_6(u8 *, s32);
    s32 _sukickball_entrypoint_7(u8 *, s32);
    Unk80132ED0 *_sukickball_entrypoint_8(u8 *, s32);
    void _sukickball_entrypoint_10(u8 *, s32, s32);
    void _sukickball_entrypoint_11(u8 *, s32);
    s32 _sukickball_entrypoint_12(u8 *, s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    void func_800F4950(s32, void *, void (*)(void));
    void func_800F4F98(s32, void *);
    s32 func_800F5410(s32);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6C5C(s32);
    BallData *data = func_80100094(arg0, 0);
    f32 distances[4];
    u8 *parent;
    ParentData *parentData;
    f32 closest;
    s32 selected;
    s32 i;

    *(Distances *)distances = (*(Distances *)D_80804F3C_chcollballcontrol);
    parent = func_80106790(*(s32 *)(arg0 + 0x3C));
    parentData = func_80100094(parent, 0);
    if ((((ActorState *)parent)->state == 4 ||
         ((ActorState *)parent)->state == 7) &&
        (0.0f == data->timer || ((ActorState *)arg0)->state == 1)) {
        selected = 0x7F;
        closest = 10000000.0f;
        for (i = 0; i < parentData->count; i++) {
            if ((((ActorState *)arg0)->state != 2 || i != data->owner) &&
                !_sukickball_entrypoint_12(parent, i)) {
                f32 position[3];
                *(Position *)position = (*(Position *)D_80804F4C_chcollballcontrol);
                if (_sukickball_entrypoint_6(parent, i)) {
                    if (func_800F6C5C(i) && func_800F5410(i) == 8) {
                        func_800F5A00(i, position);
                        if (func_800EFFB4((f32 *)(arg0 + 4), 65.0f, position)) {
                            distances[i] = func_800EEB40((f32 *)(arg0 + 4), position);
                        }
                    }
                } else {
                    func_800EE7F8(position, (f32 *)func_80106790(_sukickball_entrypoint_8(parent, i)) + 1);
                    if (func_800EFFB4((f32 *)(arg0 + 4), 65.0f, position)) {
                        distances[i] = func_800EEB40((f32 *)(arg0 + 4), position);
                    }
                }
            }
        }
        for (i = 0; i < parentData->count; i++) {
            if (((ActorState *)arg0)->state == 2 && i == data->owner) {
                continue;
            }
            if (distances[i] < closest) {
                closest = distances[i];
                selected = i;
            }
        }
        if (selected != 0x7F) {
            if (data->owner != 0x7F) {
                if (_sukickball_entrypoint_7(parent, data->owner)) {
                    _sukickball_entrypoint_11(parent, data->owner);
                } else {
                    func_800F4F98(data->owner, *(void **)arg0);
                    _sukickball_entrypoint_11(parent, data->owner);
                }
            }
            data->owner = selected;
            data->timer = 1.5f;
            if (_sukickball_entrypoint_6(parent, data->owner)) {
                func_800F4950(data->owner, *(void **)arg0, _chcollballcontrol_entrypoint_1);
            } else {
                u8 *player = func_80106790(_sukickball_entrypoint_8(parent, data->owner));
                player[0x65] &= ~0x10;
            }
            switch ((*(MarkerState **)arg0)->id) {
                case 0x44:
                    _sukickball_entrypoint_10(parent, data->owner, 1);
                    break;
                case 0x42:
                    _sukickball_entrypoint_10(parent, data->owner, 3);
                    break;
                case 0x43:
                    _sukickball_entrypoint_10(parent, data->owner, 2);
                    break;
            }
            func_80801764_chcollballcontrol(arg0, 2);
            *(f32 *)(arg0 + 0x24) = 0.0f;
        }
    }
}

void func_808030D0_chcollballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _sukickball_entrypoint_6(u8 *, s32);
    Unk80132ED0 *_sukickball_entrypoint_8(u8 *, s32);
    void _sukickball_entrypoint_11(u8 *, s32);
    f32 func_800F5F24(u32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F4F98(s32, void *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);

    s32 pad;
    u8 *parent;
    Actor *player;
    struct {
        f32 timer;
        f32 charge;
        u8 pad8[0x18];
        u8 owner;
    } *data;

    data = func_80100094(arg0, 0);
    parent = (u8 *)func_80106790(arg0->unk3C);
    if (_sukickball_entrypoint_6(parent, data->owner)) {
        arg0->rotation[1] = func_800F5F24(data->owner);
        ((f32 *)arg0->actorData)[3] = func_800F10B4(data->charge, 0.0f, 1.0f, 450.0f, 900.0f);
        func_800F4F98(data->owner, arg0->unk0);
        _sukickball_entrypoint_11(parent, data->owner);
    } else {
        player = func_80106790(_sukickball_entrypoint_8(parent, data->owner));
        arg0->rotation[1] = player->rotation[1];
        ((f32 *)arg0->actorData)[3] = func_800F10B4(player->unk58, 8.0f, 16.0f, 450.0f, 900.0f);
        player->unk58 = 0.0f;
        _sukickball_entrypoint_11(parent, data->owner);
    }
    arg0->unk70_10 = 3;
    data->owner = 0x7F;
    data->timer = 0.0f;
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804C98_chcollballcontrol);
}

void func_80803208_chcollballcontrol(s32 arg0)
{
    func_80801764_chcollballcontrol(arg0,0);
}

OSThread *chcollballcontrol_entrypoint_2(void)
{


    return (OSThread *) D_80804F58_chcollballcontrol;
}

OSThread *chcollballcontrol_entrypoint_3(void)
{


    return (OSThread *) D_80804FA0_chcollballcontrol;
}

OSThread *chcollballcontrol_entrypoint_4(void)
{


    return (OSThread *) D_80804FE8_chcollballcontrol;
}

void func_8080324C_chcollballcontrol(Actor *arg0, s32 arg1) {
    void func_80102424(Actor *, s32);

    func_80102424(arg0, arg1);
    switch (arg0->unk70_10) {
        case 2:
            if (arg0->unk64_29) {
                arg0->unk70_10 = 10;
                arg0->unk58 = 0.0f;
            }
            break;
        case 8:
            arg0->unk50 = 0.0f;
            break;
    }
}

void func_808032CC_chcollballcontrol(u8 *arg0, s32 arg1) {
    typedef struct { f32 v[3]; } Vec3;
    f32 func_800DC178(f32, f32);
    s32 func_800EE780(u8 *, u8 *, s32 *);
    void func_800EFCD8(f32 *, f32, f32);
    f32 func_80102D78(u8 *);
    void func_8080324C_chcollballcontrol();
    f32 func_8080009C_chcollballcontrol();

    Vec3 sp2C = (*(Vec3 *)D_80805098_chcollballcontrol);
    f32 var_f2;
    f32 sp24;

    if (arg1 == 0) {
        var_f2 = (*(f32 *)((s8 *)(arg0) + (0x48))) + func_800DC178(110.0f, 250.0f);
    } else {
        sp24 = func_80102D78(arg0);
        var_f2 = func_800DC178(110.0f, 250.0f) + sp24;
    }
    func_800EFCD8((f32 *)&sp2C, var_f2, 500.0f);
    func_800EE780(arg0 + 0x18, arg0 + 4, (s32 *)&sp2C);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = func_8080009C_chcollballcontrol(arg0);
    if ((*(f32 *)((s8 *)(arg0) + (0x18))) > 720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x18))) = 720.0f;
    }
    if ((*(f32 *)((s8 *)(arg0) + (0x20))) > 720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x20))) = 720.0f;
    }
    if ((*(f32 *)((s8 *)(arg0) + (0x18))) < -720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x18))) = -720.0f;
    }
    if ((*(f32 *)((s8 *)(arg0) + (0x20))) < -720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x20))) = -720.0f;
    }
    (*(f32 *)((s8 *)(arg0) + (0x34))) = func_800DC178(0.25f, 1.0f);
    func_8080324C_chcollballcontrol(arg0, 7);
}

s32 func_80803420_chcollballcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad[0x64];
        u32 : 3;
        u32 controller_index : 2;
    } BallFlags;
    void *func_80100094(Actor *, u32);
    void func_800BD268();
    void **data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 1:
        func_800BD268(*data, ((BallFlags *)arg0)->controller_index);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80803484_chcollballcontrol(Actor *arg0) {
    struct anctrl_s;
    typedef struct { f32 v[3]; } BallVector;
    typedef struct {
        void *controller;
        f32 timer;
        f32 position[3];
    } BallControl;
    f32 func_80800070_chcollballcontrol();
    f32 _subaddiejoy_entrypoint_3();
    s32 _sukickball_entrypoint_12(u8 *, s32);
    void _sukickball_entrypoint_14(Actor *);
    f32 _sukickball_entrypoint_15(s32);
    void _sukickball_entrypoint_16(s32, f32 *);
    void _sukickball_entrypoint_2(Actor *, f32, f32);
    s32 _sukickball_entrypoint_5(Actor *, f32 *);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void func_800B4470(u8 *, s32, void *, s32, f32, f32, s32, s32, s32);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    int func_800F0064(f32 *, f32, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, s32);
    struct anctrl_s *func_80104248(void *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80803E18_chcollballcontrol(Actor *);
    void func_80803F70_chcollballcontrol(Actor *);
    void func_8080405C_chcollballcontrol(u8 *);
    s32 func_8080451C_chcollballcontrol(Actor *);
    void func_8080486C_chcollballcontrol(Actor *);


    BallControl *sp64;
    Actor *sp60;
    f32 sp5C;
    BallVector sp50;
    s32 pad4C;

    sp64 = func_80100094(arg0, 0);
    sp5C = func_800D8FF8();
    sp60 = func_80106790(arg0->unk3C);
    func_800BD2D0(sp64->controller);
    sp64->timer -= sp5C;
    switch (arg0->unk70_10) {
    case 10:
        ((f32 *)arg0->actorData)[5] = 0.0f;
        ((f32 *)arg0->actorData)[3] = _subaddiejoy_entrypoint_3(arg0);
        if (_sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0)) {
            ((f32 *)arg0->actorData)[3] = func_800F10B4(((f32 *)arg0->actorData)[3], 0.0f, 1.0f, 0.0f, func_80800070_chcollballcontrol(arg0));
        } else {
            ((f32 *)arg0->actorData)[3] = func_800F10B4(((f32 *)arg0->actorData)[3], 0.0f, 1.0f, 0, func_80800040_chcollballcontrol(arg0));
        }
        if (_sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0) && func_800BCFC4(sp64->controller, 1)) {
            arg0->unk58 = func_800F10B4((s32)func_800BCD78(sp64->controller, 1, 1) * func_800D8FF8(), 0.0f, 1.0f, 450.0f, 900.0f);
            arg0->unk64_20 = 1;
        }
        func_8080486C_chcollballcontrol(arg0);
        _sukickball_entrypoint_2(arg0, func_8080009C_chcollballcontrol(arg0), func_80800040_chcollballcontrol(arg0));
        if (func_800BD030(sp64->controller, 9)) {
            func_8080324C_chcollballcontrol(arg0, 8);
        }
        break;
    case 8:
        if (arg0->unk50 == 0) {
            if (func_80101E14(arg0, 0.3077f)) {
                anctrl_setPlaybackType(func_80104248(arg0), 3);
                arg0->unk50 = 1.0f;
                ((f32 *)arg0->actorData)[3] = 1050.0f;
                func_800B4470((u8 *)arg0->position, 0, D_808050B0_chcollballcontrol, 1, 0.75f, 0.0f, 125, 250, 0);
            }
        } else if (arg0->unk50 != 0) {
            arg0->unk50 += sp5C;
            if (arg0->unk50 > 2.5f || ((f32 *)arg0->actorData)[3] < 150.0f) {
                func_8080324C_chcollballcontrol(arg0, 2);
                ((f32 *)arg0->actorData)[3] = func_8080009C_chcollballcontrol(arg0);
            } else {
                ((f32 *)arg0->actorData)[3] *= 0.9f;
            }
        }
        ((f32 *)arg0->actorData)[5] = 0;
        func_800EEB9C(&((f32 *)arg0->actorData)[4], arg0->rotation[1], ((f32 *)arg0->actorData)[3] * sp5C);
        func_800EF04C(arg0->position, &((f32 *)arg0->actorData)[4]);
        if (arg0->unk64_29) {
            _subaddiejoy_entrypoint_3(arg0);
            if (!func_80102CF4(arg0, 0x41000000)) {
                func_80102B2C(arg0, 8.0f);
            }
        }
        func_8080405C_chcollballcontrol((u8 *)arg0);
        break;
    case 12:
        if (((f32 *)arg0->actorData)[3] < 150.0f) {
            func_8080324C_chcollballcontrol(arg0, 2);
            ((f32 *)arg0->actorData)[3] = func_8080009C_chcollballcontrol(arg0);
        } else {
            ((f32 *)arg0->actorData)[3] *= 0.9f;
        }
        ((f32 *)arg0->actorData)[5] = 0.0f;
        func_800EEB9C(&((f32 *)arg0->actorData)[4], arg0->unk54, ((f32 *)arg0->actorData)[3] * sp5C);
        func_800EF04C(arg0->position, &((f32 *)arg0->actorData)[4]);
        break;
    case 2:
        if (arg0->unk64_29) {
            func_8080324C_chcollballcontrol(arg0, 10);
            arg0->unk58 = 0.0f;
        }
        if (!func_8080451C_chcollballcontrol(arg0)) {
            func_8080324C_chcollballcontrol(arg0, 1);
        }
        if (_sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0)) {
            if (func_800DC0C0() < 0.95f) {
                func_8080324C_chcollballcontrol(arg0, 5);
            } else {
                ((f32 *)arg0->actorData)[7] = func_800DC178(0.0f, 2.5f);
                func_8080324C_chcollballcontrol(arg0, 4);
            }
        }
        func_8080486C_chcollballcontrol(arg0);
        _sukickball_entrypoint_2(arg0, func_8080009C_chcollballcontrol(arg0), func_80800040_chcollballcontrol(arg0));
        break;
    case 1:
        _sukickball_entrypoint_16(arg0->unk6C_0, (f32 *)arg0->actorData);
        func_8080486C_chcollballcontrol(arg0);
        _sukickball_entrypoint_2(arg0, func_8080009C_chcollballcontrol(arg0), func_80800040_chcollballcontrol(arg0));
        if (func_8080451C_chcollballcontrol(arg0)) {
            func_8080324C_chcollballcontrol(arg0, 2);
        }
        if (func_800EFFB4(arg0->position, 50.0f, (f32 *)arg0->actorData)) {
            func_8080324C_chcollballcontrol(arg0, 3);
        }
        break;
    case 3:
        if (func_8080451C_chcollballcontrol(arg0)) {
            func_8080324C_chcollballcontrol(arg0, 2);
        }
        _sukickball_entrypoint_14(arg0);
        _sukickball_entrypoint_2(arg0, func_8080009C_chcollballcontrol(arg0), func_80800040_chcollballcontrol(arg0));
        break;
    case 4:
        sp50 = (*(BallVector *)D_808050A4_chcollballcontrol);
        if (((f32 *)arg0->actorData)[7] > 0.0f) {
            ((f32 *)arg0->actorData)[7] -= sp5C;
        } else {
            func_8080324C_chcollballcontrol(arg0, 5);
        }
        if (!_sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0)) {
            func_8080324C_chcollballcontrol(arg0, 1);
        }
        _sukickball_entrypoint_16(arg0->unk6C_0, (f32 *)arg0->actorData);
        func_800EFCD8(sp50.v, _sukickball_entrypoint_15(arg0->unk6C_0), 250.0f);
        func_800EF04C((f32 *)arg0->actorData, sp50.v);
        if (func_800F0064(arg0->position, 100.0f, (f32 *)arg0->actorData) || _sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0) == 3) {
            func_8080324C_chcollballcontrol(arg0, 5);
        }
        func_8080486C_chcollballcontrol(arg0);
        _sukickball_entrypoint_2(arg0, func_8080009C_chcollballcontrol(arg0), func_80800040_chcollballcontrol(arg0));
        break;
    case 5:
        func_80803E18_chcollballcontrol(arg0);
        func_80803F70_chcollballcontrol(arg0);
        func_8080324C_chcollballcontrol(arg0, 6);
        break;
    case 6:
        if (_sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0)) {
            func_80803F70_chcollballcontrol(arg0);
        } else {
            func_8080324C_chcollballcontrol(arg0, 2);
        }
        break;
    case 7:
        if (((f32 *)arg0->actorData)[7] > 0.0f) {
            ((f32 *)arg0->actorData)[7] -= sp5C;
        } else {
            func_8080324C_chcollballcontrol(arg0, 2);
        }
        func_8080486C_chcollballcontrol(arg0);
        _sukickball_entrypoint_2(arg0, func_8080009C_chcollballcontrol(arg0), func_80800040_chcollballcontrol(arg0));
        break;
    case 9:
        arg0->unk58 = 0.0f;
        arg0->unk64_20 = 0;
        arg0->rotation[1] += ((f32 *)arg0->actorData)[7];
        if (((f32 *)arg0->actorData)[7] > 1.0f) {
            ((f32 *)arg0->actorData)[7] *= 0.95f;
        } else if (((f32 *)arg0->actorData)[7] < -1.0f) {
            ((f32 *)arg0->actorData)[7] *= 0.95f;
        } else {
            func_8080324C_chcollballcontrol(arg0, 2);
            ((f32 *)arg0->actorData)[7] = 0.0f;
        }
        break;
    }
    if (_sukickball_entrypoint_5(arg0, sp64->position)) {
        if (arg0->unk70_10 == 8) {
            func_8080324C_chcollballcontrol(arg0, 2);
        } else if (!arg0->unk64_29) {
            func_808032CC_chcollballcontrol((u8 *)arg0, 0);
        }
    } else {
        func_800EE7F8(sp64->position, arg0->position);
    }
}

s32 func_80803D54_chcollballcontrol(s32 arg0, s32 arg1) {
    s32 func_800DC128(s32, s32);
    int func_800DC298(f32);
    s32 choice = arg0;

    switch (arg1) {
        case 0:
            if (func_800DC298(0.1999969482f)) {
                return 0;
            }
            break;
        case 1:
            if (func_800DC298(0.2249908447f)) {
                return 0;
            }
            break;
        case 2:
            if (func_800DC298(0.3299865723f)) {
                return 0;
            }
            break;
    }
    while (choice == arg0) {
        choice = func_800DC128(1, 4);
    }
    return choice;
}

void func_80803E18_chcollballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _sukickball_entrypoint_12(u8 *, s32);
    void _sukickball_entrypoint_4(s32, void *);
    void func_80803EF4_chcollballcontrol(Actor *, s32);
    struct {
        u8 pad0[0x14];
        u8 mode;
    } *data;
    s32 state;

    data = func_80100094(arg0, 0);
    state = _sukickball_entrypoint_12((u8 *)func_80106790(arg0->unk3C), arg0->unk6C_0);
    switch (state) {
        case 2:
            _sukickball_entrypoint_4(arg0->unk6C_0, arg0->actorData);
            return;
        case 3:
            func_80803EF4_chcollballcontrol(arg0, func_80803D54_chcollballcontrol(arg0->unk6C_0, data->mode));
            return;
        case 1:
            _sukickball_entrypoint_4(func_80803D54_chcollballcontrol(arg0->unk6C_0, data->mode), arg0->actorData);
        case 0:
            return;
    }
}

void func_80803EF4_chcollballcontrol(Actor *arg0, s32 arg1) {
    s32 _sukickball_entrypoint_6(u8 *, s32);
    Unk80132ED0 *_sukickball_entrypoint_8(u8 *, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    u8 *parent;

    parent = (u8 *)func_80106790(arg0->unk3C);
    if (_sukickball_entrypoint_6(parent, arg1)) {
        func_800F5A00(arg1, (f32 *)arg0->actorData);
        return;
    }
    func_800EE7F8((f32 *)arg0->actorData,
                 func_80106790(_sukickball_entrypoint_8(parent, arg1))->position);
}

void func_80803F70_chcollballcontrol(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    s32 _sukickball_entrypoint_12(u8 *, s32);
    void _sukickball_entrypoint_4(s32, void *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 func_80102D78();
    s32 func_80102CF4(Actor *, s32);
    void func_80102B2C(Actor *, f32);
    void func_8080324C_chcollballcontrol();

    if (_sukickball_entrypoint_12((u8 *)func_80106790(arg0->unk3C), arg0->unk6C_0) == 2) {
        _sukickball_entrypoint_4(arg0->unk6C_0, arg0->actorData);
    }
    arg0->unk54 = func_80102D78(arg0, arg0->actorData);
    if (!func_80102CF4(arg0, 0x41800000)) {
        func_80102B2C(arg0, 16.0f);
        return;
    }
    if (!func_80102CF4(arg0, 0x40800000)) {
        func_80102B2C(arg0, 4.0f);
        return;
    }
    arg0->unk58 = func_800DC178(10.0f, 16.0f);
    arg0->unk64_20 = 1;
    func_8080324C_chcollballcontrol((u8 *)arg0, 2);
}

void func_8080405C_chcollballcontrol(u8 *arg0) {
    typedef struct { f32 v[3]; } Vec3;
    typedef struct {
        u8 pad[0x65];
        u8 : 3;
        u8 hit : 1;
        u8 : 4;
    } BallFlags;

    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 _sukickball_entrypoint_6(u8 *, s32);
    s32 _sukickball_entrypoint_7(u8 *, s32);
    Unk80132ED0 *_sukickball_entrypoint_8(u8 *, s32);
    s32 _sukickball_entrypoint_12(u8 *, s32);
    s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    void func_800EEB9C(f32 *, f32, f32);
    f32 func_800EEF94(f32 *);
    void func_800EF04C(f32 *, f32 *);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    s32 func_800F52B8(s32, Unk80132ED0 *);
    void func_800F5A00(s32, f32 *);
    void func_800F5D70(s32, f32 *);
    void func_800F7700(s32, s32, f32 *);
    void func_800F8294(s32, f32 *);
    f32 func_80102D78();
    void func_8080324C_chcollballcontrol();
    u8 *parent;
    u8 *other;
    s32 i;
    u8 *data;
    f32 pos[3];
    f32 selfSpeed;
    f32 speed;
    f32 velocity[3];
    Vec3 impulse;
    f32 playerPos[3];
    f32 *selfPos;
    f32 hitPos[3];

    other = NULL;
    parent = func_80106790(*(s32 *)(arg0 + 0x3C));
    data = func_80100094(parent, 0);
    for (i = 0; i < data[0x3A]; i++) {
        if (i != (*(s32 *)(arg0 + 0x6C) & 0x1FF)) {
            selfPos = (f32 *)(arg0 + 4);
            if (_sukickball_entrypoint_7(parent, i)) {
                other = func_80106790(_sukickball_entrypoint_8(parent, i));
                pos[0] = *(f32 *)(other + 4);
                pos[1] = *(f32 *)(other + 8);
                pos[2] = *(f32 *)(other + 0xC);
            } else {
                func_800F5A00(i, pos);
            }
            if (func_800EFFB4(selfPos, 90.0f, pos)) {
                selfSpeed = func_800EEF94((f32 *)(arg0 + 0x28));
                if (_sukickball_entrypoint_6(parent, i)) {
                    func_800F5D70(i, velocity);
                    speed = func_800EEF94(velocity) * func_800D8FF8();
                } else {
                    speed = func_800EEF94((f32 *)(other + 0x28)) * func_800D8FF8();
                }
                if (speed <= selfSpeed) {
                    if (_sukickball_entrypoint_6(parent, i)) {
                        _sukickball_entrypoint_13(selfPos, pos, 60.0f);
                        func_800F8294(i, pos);
                        if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 8) {
                            impulse = (*(Vec3 *)D_808050B4_chcollballcontrol);
                            func_800F5A00(i, playerPos);
                            func_800EEB9C(impulse.v, func_80102D78(arg0, playerPos), 150.0f);
                            func_800EF04C(impulse.v, playerPos);
                            func_800F7700(i, 3, selfPos);
                        }
                    } else {
                        _sukickball_entrypoint_13(selfPos, (f32 *)(other + 4), 60.0f);
                        if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 8) {
                            *(f32 *)(other + 0x58) = 1.5f;
                            ((BallFlags *)other)->hit = 1;
                            func_8080324C_chcollballcontrol(other, 12);
                            *(f32 *)(other + 0x24) = *(f32 *)(arg0 + 0x24) * 0.75f;
                            *(f32 *)(other + 0x54) = func_80102D78(arg0, (f32 *)(other + 4));
                            *(f32 *)(arg0 + 0x24) *= 0.5f;
                        }
                    }
                } else {
                    _sukickball_entrypoint_13(pos, selfPos, 60.0f);
                    if ((func_800DC0C0() < 0.5f) &&
                        !_sukickball_entrypoint_12(parent, *(s32 *)(arg0 + 0x6C) & 0x1FF)) {
                        func_808032CC_chcollballcontrol(arg0, (s32)pos);
                    }
                    if (_sukickball_entrypoint_6(parent, i) &&
                        func_800F52B8(i, *(Unk80132ED0 **)arg0) == 2) {
                        func_800F5A00(i, hitPos);
                        *(f32 *)(arg0 + 0x54) = func_800F1DF4(hitPos, selfPos);
                        func_8080324C_chcollballcontrol(arg0, 12);
                        *(f32 *)(arg0 + 0x24) = speed * 0.75f / func_800D8FF8();
                    }
                    *(f32 *)(arg0 + 0x58) = 1.5f;
                    ((BallFlags *)arg0)->hit = 1;
                }
            }
        }
    }
}

void func_80804420_chcollballcontrol(Actor *arg0) {
    typedef struct {
        void *controller;
        u8 pad4[0x10];
        u8 mode;
    } BallData;
    typedef struct {
        u8 pad[0x64];
        u32 active : 1;
        u32 : 1;
        u32 controlled : 1;
        u32 controller_index : 2;
    } BallFlags;
    void *func_80100094(Actor *, u32);
    void func_8010A590(Actor *);
    void *func_800BD0DC(s32);
    void func_800BD268();
    void func_800BD28C();
    s32 _gcstatusDll_entrypoint_11();
    u8 _sukickball_entrypoint_3();
    BallData *data;

    data = func_80100094(arg0, 0);
    ((BallFlags *)arg0)->active = 1;
    arg0->scale = 0.5f;
    func_8010A590(arg0);
    data->mode = _sukickball_entrypoint_3();
    if (data->mode == 4) {
        if (arg0->unk6C_0 < _gcstatusDll_entrypoint_11()) {
            ((BallFlags *)arg0)->controlled = 1;
            ((BallFlags *)arg0)->controller_index = arg0->unk6C_0;
        }
    }
    data->controller = func_800BD0DC(2);
    func_800BD268(data->controller, arg0->unk6C_0);
    func_800BD28C(data->controller, 2);
}

void func_808044F4_chcollballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800BD09C();
    void **data = func_80100094(arg0, 0);
    func_800BD09C(*data);
}

s32 func_8080451C_chcollballcontrol(Actor *arg0)
{
    s32 *_subaddiefind_entrypoint_0();
    f32 func_800136E4(f32);
    f32 func_800DC0C0(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    int func_800F0064(f32 *, f32, f32 *);
    s32 func_80102CF4(Actor *, s32);
    f32 func_80102D78();
    void func_8080324C_chcollballcontrol(Actor *, s32);
    u8 *selected;
    union { f32 f; s32 i; } distance;
    u8 *other;
    f32 angle;
    f32 speed;

    selected = (u8 *)_subaddiefind_entrypoint_0((f32 *)((u8 *)arg0 + 4), 0x1A1, -1, &distance.f);
    if (selected == NULL) {
        selected = (u8 *)_subaddiefind_entrypoint_0((f32 *)((u8 *)arg0 + 4), 0x1A2, -1, &distance.f);
        if (selected == NULL) {
            selected = (u8 *)_subaddiefind_entrypoint_0((f32 *)((u8 *)arg0 + 4), 0x1A3, -1, &distance.f);
            if (selected == NULL) {
                return NULL;
            }
        }
    } else if ((((u32)*(u16 *)(selected + 0x72) >> 10) == 2 &&
                !func_800F0064((f32 *)((u8 *)arg0 + 4), 100.0f, (f32 *)(selected + 4))) ||
               ((u32)*(u16 *)(selected + 0x72) >> 10) == 6 ||
               ((u32)*(u16 *)(selected + 0x72) >> 10) == 4 ||
               ((u32)*(u16 *)(selected + 0x72) >> 10) == 3) {
        switch ((u32)*(u16 *)(selected + 0x72) >> 10) {
            case 2:
                other = (u8 *)_subaddiefind_entrypoint_0((f32 *)((u8 *)arg0 + 4), 0x1A1, 2, &distance.f);
                break;
            case 3:
                other = (u8 *)_subaddiefind_entrypoint_0((f32 *)((u8 *)arg0 + 4), 0x1A1, 3, &distance.f);
                break;
            case 6:
                other = (u8 *)_subaddiefind_entrypoint_0((f32 *)((u8 *)arg0 + 4), 0x1A1, 6, &distance.f);
                break;
            case 4:
                other = (u8 *)_subaddiefind_entrypoint_0((f32 *)((u8 *)arg0 + 4), 0x1A1, 4, &distance.f);
                break;
        }
        if (other != NULL && (((u32)*(u16 *)(other + 0x72) >> 10) == 1 ||
                              ((u32)*(u16 *)(other + 0x72) >> 10) == 3)) {
            selected = other;
        }
    }
    if (((u32)*(u16 *)(selected + 0x72) >> 10) == 2) {
        angle = *(f32 *)(selected + 0x54) - func_80102D78(arg0, (f32 *)(selected + 0x18));
        speed = 0.0f;
        angle = func_800136E4(angle);
        if (angle < 90.0f) {
            angle = *(f32 *)(selected + 0x54) + 65.0f;
            speed = *(f32 *)(selected + 0x50) * 0.006666666828f;
        } else if (angle > 270.0f) {
            angle = *(f32 *)(selected + 0x54) - 65.0f;
            speed = *(f32 *)(selected + 0x50) * 0.006666666828f;
        } else if (*(f32 *)(selected + 0x50) > 10.0f) {
            speed = *(f32 *)(selected + 0x50) * 0.002857142827f;
        }
        if (speed < 25.0f) {
            speed = 25.0f;
        }
        if (speed < 30.0f) {
            *(f32 *)((u8 *)arg0 + 0x54) = func_80102D78(arg0, (f32 *)(selected + 0x18));
            if (!func_80102CF4(arg0, 0x42340000) && func_80102CF4(arg0, 0x42B40000) &&
                func_800DC0C0() < 0.8f) {
                func_8080324C_chcollballcontrol(arg0, 8);
            }
        }
        func_800EFCD8((f32 *)((u8 *)arg0 + 0x18), angle, speed);
        func_800EF04C((f32 *)((u8 *)arg0 + 0x18), (f32 *)(selected + 4));
    } else {
        func_800EE7F8((f32 *)((u8 *)arg0 + 0x18), (f32 *)(selected + 4));
    }
    return (s32)selected;
}

void func_8080486C_chcollballcontrol(Actor *arg0) {
    typedef struct {
        f32 v[3];
    } Vec3;
    typedef struct {
        f32 position[3];
        f32 speed;
        f32 velocity[3];
    } Motion;
    s32 _sukickball_entrypoint_12(u8 *, s32);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, s32);
    f32 func_80102D78();
    Actor *func_80106790(Unk80132ED0 *);
    f32 func_80800070_chcollballcontrol(void *);
    void func_80804A48_chcollballcontrol(void *);
    void func_80804AA8_chcollballcontrol(void *);
    extern u32 D_808050C0_chcollballcontrol[];
    Vec3 sp2C = *(Vec3 *)D_808050C0_chcollballcontrol;
    Actor *parent;

    parent = func_80106790(arg0->unk3C);
    if (arg0->unk70_10 != 10) {
        arg0->unk54 = func_80102D78(arg0, ((Motion *) arg0->actorData)->position);
        if (!func_80102CF4(arg0, 0x43700000)) {
            func_80804AA8_chcollballcontrol(arg0);
        } else {
            func_80804A48_chcollballcontrol(arg0);
        }
        if (!func_80102CF4(arg0, 0x41800000)) {
            func_80102B2C(arg0, 16.0f);
        } else if (!func_80102CF4(arg0, 0x40800000)) {
            func_80102B2C(arg0, 4.0f);
        }
    } else if (!func_80102CF4(arg0, 0x42000000)) {
        func_80102B2C(arg0, 32.0f);
    } else if (!func_80102CF4(arg0, 0x41800000)) {
        func_80102B2C(arg0, 16.0f);
    } else if (!func_80102CF4(arg0, 0x40800000)) {
        func_80102B2C(arg0, 4.0f);
    }
    if (_sukickball_entrypoint_12((u8 *) parent, arg0->unk6C_0) && (func_80800070_chcollballcontrol(arg0) < ((Motion *) arg0->actorData)->speed)) {
        ((Motion *) arg0->actorData)->speed = func_80800070_chcollballcontrol(arg0);
    }
    func_800EFCD8(((Motion *) arg0->actorData)->velocity, arg0->rotation[1], func_800D8FF8() * ((Motion *) arg0->actorData)->speed);
    func_800EF04C(arg0->position, ((Motion *) arg0->actorData)->velocity);
    func_8080405C_chcollballcontrol((u8 *) arg0);
    arg0->rotation[1] = func_800136E4(arg0->rotation[1]);
}

void func_80804A48_chcollballcontrol(void *arg0) {
    if ((*(f32 *)((s8 *)(arg0) + (0x24))) < func_80800040_chcollballcontrol(arg0)) {
        *(f32 *)((s8 *)arg0 + 0x24) += func_808000C8_chcollballcontrol(arg0);
        return;
    }
    (*(f32 *)((s8 *)(arg0) + (0x24))) = func_80800040_chcollballcontrol(arg0);
}

void func_80804AA8_chcollballcontrol(void *arg0) {
    f32 func_8080009C_chcollballcontrol();
    f32 func_808000F4_chcollballcontrol();
    if (func_8080009C_chcollballcontrol(arg0) < *(f32 *)((s8 *)arg0 + 0x24)) {
        *(f32 *)((s8 *)arg0 + 0x24) -= func_808000F4_chcollballcontrol(arg0);
    }
}

OSThread *chcollballcontrol_entrypoint_5(void)
{


    return (OSThread *) D_808050CC_chcollballcontrol;
}
