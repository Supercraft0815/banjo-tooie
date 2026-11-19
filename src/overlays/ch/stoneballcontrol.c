#include "common.h"
extern u16 D_80804FC0_chstoneballcontrol[10];
typedef struct { f32 v[3]; } StoneballVector;
void func_80801BE0_chstoneballcontrol(Actor *);
void func_80105834(Actor *);
void _sukickball_entrypoint_0(Actor *arg0, s32 arg1);
void _sukickball_entrypoint_1(Actor *, void *);
void func_8080367C_chstoneballcontrol(BtIntPtr);
void func_80801B44_chstoneballcontrol(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
void func_80803724_chstoneballcontrol(Actor *);
void func_808047E8_chstoneballcontrol(Actor *);
void func_808046C4_chstoneballcontrol(Actor *);
s32 func_808036C0_chstoneballcontrol(Actor *, s32, s32);

typedef struct { f32 v[4]; } StoneballDistances;
struct Counts { s32 values[4]; };
struct ActorIds { u8 ids[8]; };
void func_8080079C_chstoneballcontrol(Actor *);
void func_8080120C_chstoneballcontrol(Actor *);
void func_80800F9C_chstoneballcontrol(Actor *);
void func_8010A730(s32, s32);
u8 func_80800360_chstoneballcontrol(u8 *, s32, s32);

StoneballVector D_808050B0_chstoneballcontrol = {{
    0.0f, 0.0f, 0.0f,
}};

struct Counts D_808050BC_chstoneballcontrol = {{
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
}};

struct ActorIds D_808050CC_chstoneballcontrol = {{
    0x01, 0x55, 0x01, 0xB8,
    0x02, 0x9E, 0xFF, 0xFF,
}};

BtFnWord D_808050D4_chstoneballcontrol[] = {
    0x023901B7, 0x06370001, 0x00000000, (BtFnWord)func_8080079C_chstoneballcontrol,
    (BtFnWord)func_80105834, (BtFnWord)func_8010A730, 0x00000000, 0x00000000,
    0x00000000, 0x00080004, (BtFnWord)func_8080120C_chstoneballcontrol, 0x00000000,
    0x00400000, (BtFnWord)func_80800F9C_chstoneballcontrol, (BtFnWord)func_80107C2C, 0x80000202,
    (BtFnWord)func_80800360_chstoneballcontrol, 0x00000000,
};

u8 D_8080511C_chstoneballcontrol[] = {
    0xFF, 0xFF, 0xFF, 0xC8,
};

u32 D_80805120_chstoneballcontrol[] = {
    0xFFFFFFC8, 0x000000FF, 0x000000FF, 0x000000FF,
    0x000000C8,
};

s32 D_80805134_chstoneballcontrol[] = {
    0x0A10000A, 0xFFCE0000, 0xFFCE0032, 0x00320032,
    0x002CFF83, 0x004BFF83, 0x007D0096, 0x007D001B,
    0xFF06FEA2, 0x0027FD30, 0xFD3002D0, 0x02D00022,
    0x01000180, 0x00800100, 0x002A0080, 0x01000300,
    0x04000000,
};

s32 D_80805178_chstoneballcontrol[] = {
    0x001D09E2, 0x001BFF06, 0xFF060015, 0x006600CC,
    0x00220040, 0x004C0007, 0x00070027, 0x000000C8,
    0x000000F0, 0x00161000, 0x000C000F, 0x002C0000,
    0x00640000, 0x000000FA, 0x0000002A, 0x00800100,
    0x03000400, 0x00000000,
};

s32 D_808051C0_chstoneballcontrol[] = {
    0x001D0678, 0x00150066, 0x00CC000A, 0xFFFB0000,
    0xFFFB0005, 0x00000005, 0x002CFF06, 0x0064FF06,
    0x012C00FA, 0x012C001B, 0xFF6AFED4, 0x00220080,
    0x00800100, 0x03000027, 0xFD30FD30, 0x02D002D0,
    0x00161000, 0x002A0080, 0x01000300, 0x04000000,
};

s32 D_80805210_chstoneballcontrol[] = {
    0x001D09DC, 0x00190001, 0x00062302, 0x000AFFFB,
    0x0019FFF1, 0x00050032, 0x000F002C, 0x00000060,
    0x00000000, 0x00D80000, 0x0022010A, 0x03000200,
    0x0500002A, 0x00000002, 0x04000700, 0x0015004C,
    0x00B30016, 0x00040000,
};

f32 D_80805258_chstoneballcontrol[6][3] = {
    -1150.0f, -300.0f, -1000.0f, -1550.0f,
    -300.0f, -400.0f, -2100.0f, -300.0f,
    -400.0f, -2650.0f, -300.0f, -400.0f,
    -1550.0f, -300.0f, -1600.0f, -2650.0f,
    -300.0f, -1600.0f,
};

s32 D_808052A0_chstoneballcontrol[] = {
    0x00000000, 0x00000002, 0x00000001, 0x00000003,
};

StoneballDistances D_808052B0_chstoneballcontrol = {{
    10000000.0f, 10000000.0f, 10000000.0f, 10000000.0f,
}};

StoneballVector D_808052C0_chstoneballcontrol = {{0.0f, 0.0f, 0.0f}};

BtFnWord D_808052CC_chstoneballcontrol[] = {
    0x02670155, 0x06700005, 0x00000000, (BtFnWord)func_80801BE0_chstoneballcontrol,
    (BtFnWord)func_80105834, (BtFnWord)_sukickball_entrypoint_0, 0x00000000, 0x00000000,
    0x00000000, 0x00800004, (BtFnWord)func_8080367C_chstoneballcontrol, 0x00000000,
    0x00240000, (BtFnWord)func_80801B44_chstoneballcontrol, (BtFnWord)func_80107C2C, 0x80000002,
    0x00000000, 0x00000000,
};

BtFnWord D_80805314_chstoneballcontrol[] = {
    0x025301B8, 0x06770005, 0x00000000, (BtFnWord)func_80801BE0_chstoneballcontrol,
    (BtFnWord)func_80105834, (BtFnWord)_sukickball_entrypoint_0, 0x00000000, 0x00000000,
    0x00000000, 0x00800006, (BtFnWord)func_8080367C_chstoneballcontrol, 0x00000000,
    0x00240000, (BtFnWord)func_80801B44_chstoneballcontrol, (BtFnWord)func_80107C2C, 0x80000002,
    0x00000000, 0x00000000,
};

BtFnWord D_8080535C_chstoneballcontrol[] = {
    0x0254029E, 0x06720005, 0x00000000, (BtFnWord)func_80801BE0_chstoneballcontrol,
    (BtFnWord)func_80105834, (BtFnWord)_sukickball_entrypoint_0, 0x00000000, 0x00000000,
    0x00000000, 0x00800004, (BtFnWord)func_8080367C_chstoneballcontrol, 0x00000000,
    0x00240000, (BtFnWord)func_80801B44_chstoneballcontrol, (BtFnWord)func_80107C2C, 0x80000002,
    0x00000000, 0x00000000,
};

u32 D_808053A4_chstoneballcontrol[] = {
    0x00000000, 0x00000000, 0x3F800000, 0x01D70001,
    0x3F800000, 0x01D70001, 0x3F99999A, 0x01D70001,
    0x3F800000, 0x01D70001, 0x3F800000, 0x01D70001,
    0x3F800000, 0x01D70001, 0x3F800000, 0x01D70001,
    0x3F800000, 0x01EB0002, 0x4B189680, 0x01D70001,
    0x3F800000, 0x01D70001, 0x40000000, 0x01D70001,
    0x4B189680, 0x01D70001,
};

StoneballVector D_8080540C_chstoneballcontrol = {{0.0f, 0.0f, 0.0f}};

s32 D_80805418_chstoneballcontrol[] = {
    0xFFFFFFC8,
};

StoneballVector D_8080541C_chstoneballcontrol = {{0.0f, 0.0f, 0.0f}};

StoneballVector D_80805428_chstoneballcontrol = {{0.0f, 0.0f, 0.0f}};

BtFnWord D_80805434_chstoneballcontrol[] = {
    0x023701B6, 0x066A000B, (BtFnWord)D_808053A4_chstoneballcontrol, (BtFnWord)func_80803724_chstoneballcontrol,
    (BtFnWord)func_80105834, (BtFnWord)_sukickball_entrypoint_1, 0x00000000, 0x00000000,
    0x00000000, 0x00000004, (BtFnWord)func_808047E8_chstoneballcontrol, 0x00000000,
    0x00180000, (BtFnWord)func_808046C4_chstoneballcontrol, (BtFnWord)func_80107C2C, 0x80000003,
    (BtFnWord)func_808036C0_chstoneballcontrol, 0x00000000, 0x00000000,
};    typedef struct { u8 pad0[0x4]; f32 unk4; } Objstoneballcontrol_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800000_chstoneballcontrol(Unk80132ED0 **arg0, u32 arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    _subaddiedialog_entrypoint_11(*arg0, arg1, arg2 | 0xE, &((Objstoneballcontrol_arg0 *)arg0)->unk4, 0x33);
}

f32 func_80800040_chstoneballcontrol(void *arg0) {
    void *func_80100094(Actor *, u32);
    extern f32 D_80804FFC_chstoneballcontrol[5];
    return D_80804FFC_chstoneballcontrol[*((u8 *)func_80100094(arg0, 0) + 0x14)];
}

/* extern */

f32 func_80800070_chstoneballcontrol(void *arg0) {
    f32 func_80800040_chstoneballcontrol();
    return func_80800040_chstoneballcontrol(arg0) * 0.75f;
}

/* extern */

#ifdef BT_NATIVE
f32 func_8080009C_chstoneballcontrol(BtIntPtr bt_a0) {
#else
f32 func_8080009C_chstoneballcontrol() {
#endif
    f32 func_80800040_chstoneballcontrol();
#ifdef BT_NATIVE
    return ((f32 (*)())func_80800040_chstoneballcontrol)() * 0.33f;
#else
    return func_80800040_chstoneballcontrol() * 0.33f;
#endif
}

/* extern */

f32 func_808000C8_chstoneballcontrol(void *arg0) {
    return func_80800040_chstoneballcontrol(arg0) * 0.05f;
}

f32 func_808000F4_chstoneballcontrol(void *arg0)
{
    return func_808000C8_chstoneballcontrol(arg0);
}

s32 func_80800114_chstoneballcontrol(s32 arg0, s32 arg1) {
    extern s32 D_80805038_chstoneballcontrol[5][4];
    return D_80805038_chstoneballcontrol[arg0][arg1];
}

s32 func_80800130_chstoneballcontrol(s32 arg0) {
    extern s32 D_80805088_chstoneballcontrol[5];
    return D_80805088_chstoneballcontrol[arg0];
}

void func_80800144_chstoneballcontrol(void *arg0) {
    void *func_80100094(Actor *, u32);
    void _sukickball_entrypoint_17(Actor *);
    s32 _capod_entrypoint_14(void);
    void func_800A54F8(s32);
    s32 func_800DA298(s32);
    struct StoneballData {
        u8 pad0[0x39];
        u8 state;
    } *data;
    Actor *actor = arg0;
    u8 state;

    data = func_80100094(arg0, 0);
    _sukickball_entrypoint_17(arg0);
    if (func_800DA298(0x6AD) == 0) {
        if (actor->unk79_4 != 1 && !actor->unk64_20) {
            if (actor->unk79_4 == 2) {
                _capod_entrypoint_14();
            }
            state = data->state;
            if (state == 0 || state == 1 || state == 2) {
                func_800A54F8(0);
            }
            func_80800000_chstoneballcontrol(arg0, 0xF1C, 0);
            actor->unk70_10 = 3;
        }
    }
}

void func_80800210_chstoneballcontrol(Actor *arg0, s32 arg1) {
    f32 func_800DC178(f32, f32);
    s32 func_800EA05C(void);
    Actor *func_801084B0(BtIntPtr, Actor **);
    Actor *actor;

    switch (arg1) {
        case 1:
        case 6:
            actor = func_801084B0(0x155, &arg0);
            goto position_actor;
        case 3:
            actor = func_801084B0(0x1B8, &arg0);
            goto position_actor;
        case 2:
            actor = func_801084B0(0x29E, &arg0);
            goto position_actor;
    }
position_actor:
    if (func_800EA05C() != 0xBB) {
        actor->position[0] = func_800DC178(-470.0f, 470.0f);
        actor->position[2] = func_800DC178(-470.0f, 470.0f);
    } else if (arg1 != 6) {
        actor->position[0] = func_800DC178(-2850.0f, -1350.0f);
        actor->position[2] = func_800DC178(-1350.0f, -650.0f);
    } else {
        actor->position[0] = -2100.0f;
        actor->position[2] = -1000.0f;
    }
    actor->unk3C = arg0->unk0;
}

u8 func_80800360_chstoneballcontrol(u8 *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x65];
        BT_BITFIELD_ORDER(u8 flags65_hi : 3, u8 flags65_lo : 4);
        u8 dialog : 1;
        BT_BITFIELD_ORDER(u8 flags65_lo : 4, u8 flags65_hi : 3);
        u8 pad66[0xC];
        BT_BITFIELD_ORDER(u8 state : 6, u8 flags72_lo : 2);
        BT_BITFIELD_ORDER(u8 flags72_lo : 2, u8 state : 6);
        u8 pad73[6];
        BT_BITFIELD_ORDER(u8 mode : 4, u8 flags79_lo : 4);
        BT_BITFIELD_ORDER(u8 flags79_lo : 4, u8 mode : 4);
    } ControlFlags;
    s32 _capod_entrypoint_13(BtIntPtr, BtIntPtr, s32, s32);
    s32 _capod_entrypoint_17(f32);
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void _gcgoto_entrypoint_1(u32 a0, u32 a1);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void _subaddiemulti_entrypoint_4(s32);
    BtIntPtr _sukickball_entrypoint_8(Actor *arg0, s32 arg1);
    void func_800A54F8(s32);
    s32 func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    s32 func_800D2054(s32, s32, s32);
    BT_IDO_ONLY(u8) BT_NATIVE_ONLY(s16) func_800D211C(s32);
    s32 func_800D395C(void);
    s32 func_800DA9E4(s32, s32);
    s32 func_800EA05C(void);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800000_chstoneballcontrol(Unk80132ED0 **, u32, s32);
    void func_80800210_chstoneballcontrol(Actor *, s32);
    void func_80801734_chstoneballcontrol(Actor *, s32);
    u32 func_800FDC28(u32);
    u8 *data;
    f32 delay;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0xB:
        ((ControlFlags *)arg0)->mode = 2;
        return 3;
    case 0xE:
        switch (data[0x39]) {
        case 0:
            delay = 0.5f;
            break;
        case 1:
            delay = 0.5f;
            break;
        case 2:
            delay = 0.5f;
            break;
        }
        if (_capod_entrypoint_17(delay)) {
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0,
                data[0x39] + 0xF3E, 6,
                &(func_80106790(_sukickball_entrypoint_8(arg0, data[0x39] + 1)))->position[0], 0);
            ((ControlFlags *)arg0)->dialog = 1;
        }
        return 3;
    case 0x2E:
        switch (((s16 *)&arg2)[0]) {
        case 0xF4D:
        case 0xF4E:
            if (func_800D2054(0, data[0x39] + 0x8E, *(s32 *)(data + 0x20)) == 1) {
                func_80800000_chstoneballcontrol(arg0, 0xF57, 0);
            } else {
        case 0xF21:
        case 0xF22:
        case 0xF57:
                func_80800000_chstoneballcontrol(arg0, 0xCEB, 0x40);
            }
            break;
        case 0xF51:
        case 0xF52:
            _gcfrontend_entrypoint_10();
            break;
        case 0xCEB:
            if (func_800D395C()) {
                if (((s16 *)&arg2)[1] == 1) {
                    _gcfrontend_entrypoint_11();
                } else {
                    _gcfrontend_entrypoint_10();
                }
            } else if (((s16 *)&arg2)[1] == 1) {
                _gcgoto_entrypoint_1(func_800EA05C(), 1);
            } else {
                _gcgoto_entrypoint_1(0xBB, 4);
            }
            break;
        case 0xF1C:
            func_800FDC28(0xD);
            func_800CE8D8(0, (f32)func_80800130_chstoneballcontrol(data[0x39]),
                (s32)(f32)func_80800130_chstoneballcontrol(data[0x39]));
            func_800CE88C(0, 1);
            func_80801734_chstoneballcontrol(arg0, 0);
            ((ControlFlags *)arg0)->state = 4;
            break;
        case 0xF3E:
        case 0xF3F:
        case 0xF40:
            ((ControlFlags *)arg0)->dialog = 0;
            break;
        }
        break;
    case 0x30:
        switch (((s16 *)&arg2)[0]) {
        case 0xF51:
            return data[0x3B];
        case 0xF57:
            return func_800D211C(data[0x39] + 0x8E);
        }
        break;
    case 0x3D:
        func_80800210_chstoneballcontrol(arg0, arg2);
        break;
    case 0x49:
        switch (data[0x39]) {
        case 0:
        case 1:
        case 2:
            if (func_800D395C() == 0 && func_800DA9E4(data[0x39] + 0x41C, 1) == 0) {
                _capod_entrypoint_13(*(s32 *)arg0, 0, 1, 0x2020);
                ((ControlFlags *)arg0)->mode = 1;
            } else {
                func_800A54F8(0);
            }
            break;
        case 3:
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

void func_8080079C_chstoneballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_800D8FF8(void);
    void _sukickball_entrypoint_17(Actor *);
    void _sukickball_entrypoint_19(Actor *arg0, s32 arg1, s32 arg2);
    s32 func_800CEB54(s32, f32);
    s32 func_800CEAD0(s32);
    u32 func_800FDC28(u32);
    void _gcgoto_entrypoint_1(u32 a0, u32 a1);
    void func_80800908_chstoneballcontrol(Actor *);
    void func_8080145C_chstoneballcontrol(Actor *);
    struct StoneballUpdateData {
        f32 timer0;
        f32 timer1;
        u8 pad8[0x32];
        u8 mode;
    } *data;
    f32 delta;

    data = func_80100094(arg0, 0);
    delta = func_800D8FF8();
    data->timer0 -= delta;
    data->timer1 -= delta;
    switch (arg0->unk70_10) {
        case 1:
            func_80800144_chstoneballcontrol(arg0);
            break;
        case 3:
            _sukickball_entrypoint_17(arg0);
            break;
        case 6:
            _sukickball_entrypoint_19(arg0, 1, data->mode);
            break;
        case 4:
            _sukickball_entrypoint_19(arg0, 0, data->mode);
            func_8080145C_chstoneballcontrol(arg0);
            if (func_800CEB54(0, 6.0f)) {
                func_800FDC28(0xE);
            } else if (func_800CEAD0(0)) {
                func_80800908_chstoneballcontrol(arg0);
            }
            break;
        case 7:
            func_8080145C_chstoneballcontrol(arg0);
            break;
        case 8:
            _sukickball_entrypoint_19(arg0, 1, data->mode);
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= func_800D8FF8();
            } else {
                _gcgoto_entrypoint_1(0xBB, 4);
            }
            break;
    }
}

void func_80800908_chstoneballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    u32 func_800FDC28(u32);
    void func_80801734_chstoneballcontrol(Actor *, s32);
    s32 _sumultiscore_entrypoint_2(s32 *, s32 *, s32 *, s32, s32);
    void func_800FC6B0(u32);
    s32 func_800D2054(s32, s32, s32);
    void func_800DA544(s32 index);
    s32 func_80101FDC();
    struct StoneballScore {
        u8 pad0[0x20];
        s32 scores[4];
        u8 winners[4];
        u8 pad34[5];
        u8 mode;
        u8 count;
        s8 result;
    } *data;
    s32 places[4];
    s32 ties[4];
    s32 result;
    u32 dialog;
    s32 i;

    data = func_80100094(arg0, 0);
    arg0->unk70_10 = 6;
    func_800FDC28(0);
    func_80801734_chstoneballcontrol(arg0, 1);
    result = _sumultiscore_entrypoint_2(data->scores, places, ties, 0, data->count);
    if (data->mode < 3) {
        if (arg0->unk64_19) {
            switch (places[0]) {
                case 1:
                    if (ties[0] == 0) {
                        func_800FC6B0(0x16);
                        func_80800000_chstoneballcontrol(&arg0->unk0, 0xF4D, 0x200);
                        return;
                    }
                case 2:
                case 3:
                case 4:
                    func_80800000_chstoneballcontrol(&arg0->unk0, 0xF4E, 0x200);
                    func_800FC6B0(0x17);
                    return;
            }
        } else {
            switch (places[0]) {
                case 1:
                    if (ties[0] == 0) {
                        func_800D2054(0, data->mode + 0x8E, data->scores[0]);
                        func_800DA544(0x9CB);
                        func_800FC6B0(0x16);
                        func_80101FDC(arg0, 8);
                        arg0->unk58 = 2.5f;
                        return;
                    }
                case 2:
                case 3:
                    func_800FC6B0(0x17);
                    func_80800000_chstoneballcontrol(&arg0->unk0, 0xF21, 0x200);
                    return;
                case 4:
                    func_80800000_chstoneballcontrol(&arg0->unk0, 0xF22, 0x200);
                    func_800FC6B0(0x17);
                    return;
            }
        }
    } else {
        for (i = 0; i < data->count; i++) {
            if (places[i] == 1) {
                data->winners[i] = 1;
            } else {
                data->winners[i] = 0;
            }
        }
        if (result != 0) {
            dialog = 0xF51;
            data->result = result;
        } else {
            dialog = 0xF52;
        }
        func_800FC6B0(0x10);
        func_80800000_chstoneballcontrol(&arg0->unk0, dialog, 0);
    }
}

void func_80800B4C_chstoneballcontrol(void *arg0, s32 arg1) {
    void func_80102424(Actor *, s32);
    struct StoneballFlags {
        u8 pad0[0x64];
        BT_BITFIELD_ORDER(u32 pad64_30 : 2, u32 pad64_0 : 29);
        u32 active : 1;
        BT_BITFIELD_ORDER(u32 pad64_0 : 29, u32 pad64_30 : 2);
    } *flags = arg0;
    Actor *actor = arg0;

    func_80102424(arg0, arg1);
    switch (actor->unk70_10) {
        case 2:
            if (flags->active) {
                actor->unk70_10 = 10;
                actor->unk58 = 0.0f;
            }
            break;
        case 8:
            actor->unk50 = 0.0f;
            break;
    }
}

void func_80800BCC_chstoneballcontrol(u8 *arg0, BtIntPtr arg1) {
    typedef StoneballVector Vec3;
    f32 func_800DC178(f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    f32 func_80102D78(u8 *);
    void func_80800B4C_chstoneballcontrol(void *, s32);
    f32 func_8080009C_chstoneballcontrol();

    Vec3 sp2C = D_808050B0_chstoneballcontrol;
    f32 var_f2;
    f32 sp24;

    if (arg1 == 0) {
        var_f2 = (((Actor *)arg0)->rotation[1]) + func_800DC178(110.0f, 250.0f);
    } else {
        sp24 = func_80102D78(arg0);
        var_f2 = func_800DC178(110.0f, 250.0f) + sp24;
    }
    func_800EFCD8((f32 *)&sp2C, var_f2, 500.0f);
    func_800EE780((f32 *)(arg0 + 0x18), (f32 *)(arg0 + 4), (f32 *)&sp2C);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = func_8080009C_chstoneballcontrol(arg0);
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
    func_80800B4C_chstoneballcontrol(arg0, 7);
}

/* extern */

void func_80800D20_chstoneballcontrol(u8 *arg0) {
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_80800B4C_chstoneballcontrol(void *, s32);
    Actor *actor = (Actor *)arg0;
#ifdef BT_NATIVE
    ((f32 *)actor->actorData)[3] = ((f32 (*)())func_8080009C_chstoneballcontrol)();
#else
    ((f32 *)actor->actorData)[3] = func_8080009C_chstoneballcontrol();
#endif
    ((f32 *)actor->actorData)[7] = func_800DC178(0.9f, 1.1f) * 45.0f;
    if (func_800DC0C0() < 0.5f) {
        ((f32 *)actor->actorData)[7] = -((f32 *)actor->actorData)[7];
    }
    func_80800B4C_chstoneballcontrol(arg0, 9);
    actor->unk64_20 = 1;
}

void func_80800DB4_chstoneballcontrol(void *arg0, f32 *arg1) {
    s32 _sukickball_entrypoint_6(u8 *, BtIntPtr);
    BtIntPtr _sukickball_entrypoint_8(Actor *arg0, s32 arg1);
    int func_800F0064(f32 *, f32, f32 *);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800F7B9C(BtIntPtr, u32);
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
                func_80800D20_chstoneballcontrol((u8 *)actor);
            }
        }
    }
}

void func_80800EBC_chstoneballcontrol(s32 arg0, s32 arg1) {
    struct player_state_s;
    struct player_state_s *func_800F53D0(BtIntPtr);
    void func_800F82D4(BtIntPtr, s32);
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

void func_80800F24_chstoneballcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    void _chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    s32 _chintrotext_entrypoint_2(s32);
    s32 func_800D395C(void);
    if ((arg1 != 0) || (func_800D395C() != 0)) {
        arg0->unk64_19 = 1;
        _chintrotext_entrypoint_1(0x18AF, arg2 + 0xF, 0, 0);
        return;
    }
    arg0->unk64_19 = 0;
    _chintrotext_entrypoint_2(1);
}

void func_80800F9C_chstoneballcontrol(Actor *arg0) {
    u8 _gcstatusDll_entrypoint_11(void);
    void _sukickball_entrypoint_18(Actor *);
    s32 _sukickball_entrypoint_3(void);
#ifdef BT_NATIVE
    s32 func_80090178(s32);
#else
    s32 func_80090178(AllowedTransformation);
#endif
    s32 func_800D0A9C(u32, u32);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    s32 func_800EA05C(void);
    void func_800F4CEC(BtIntPtr, u32);
    s32 func_800F6438(BtUIntPtr);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    Actor *func_801084B0(BtIntPtr, Actor **);
    void func_8080128C_chstoneballcontrol(Actor *);
    void func_80801330_chstoneballcontrol(Actor *, s32);
    void func_8080145C_chstoneballcontrol(Actor *);
    extern s32 D_8080509C_chstoneballcontrol[5];
    struct Fields {
        u8 pad0[0xA];
        u8 types[4];
        u8 padE[2];
        Unk80132ED0 *markers[4];
        u8 pad20[0x19];
        u8 state;
        u8 count;
        u8 pad3B;
        u8 active;
    };
    struct Fields *data;
    Actor *actor;
    s32 i;

    data = func_80100094(arg0, 0);
    data->state = _sukickball_entrypoint_3();
    data->active = 0;
    if (func_800DA298(0x667) != 0 || func_80090178(0x80) == 0) {
        func_800FFAB0(arg0);
        return;
    }
    if (func_800EA05C() != 0xBB) {
        func_800DA3B8(0x65A, 1);
    }
    data->count = D_8080509C_chstoneballcontrol[data->state];
    switch (data->state) {
        case 0:
            data->state = 0;
            func_80800F24_chstoneballcontrol(arg0, func_800DA298(0x5E), data->state);
            break;
        case 1:
            func_80800F24_chstoneballcontrol(arg0, func_800DA298(0x5F), data->state);
            break;
        case 2:
            func_80800F24_chstoneballcontrol(arg0, func_800D0A9C(3, 1), data->state);
            break;
        case 3:
            break;
        case 4:
            for (i = 0; i != 8; i++) {
                if (func_800F6438(i) != 0) {
                    func_800F4CEC(i, 0);
                }
            }
            data->count = _gcstatusDll_entrypoint_11();
            break;
    }
    func_8080128C_chstoneballcontrol(arg0);
    if (data->state == 4) {
        data->types[0] = 1;
    } else {
        data->types[0] = 2;
    }
    data->types[1] = 1;
    data->types[2] = 1;
    data->types[3] = 1;
    for (i = 0; i < data->count; i++) {
        switch (data->types[i]) {
            case 1:
                data->markers[i] = (actor = func_801084B0(0x1B6, &arg0))->unk0;
                actor->unk3C = arg0->unk0;
                break;
            case 2:
                break;
        }
        func_80801330_chstoneballcontrol(arg0, i);
    }
    if (func_800EA05C() == 0xBB) {
        func_8080145C_chstoneballcontrol(arg0);
        arg0->unk70_10 = 7;
    }
    _sukickball_entrypoint_18(arg0);
    data->active = 1;
}

void func_8080120C_chstoneballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800DA3B8(s32, s32);
    void func_800F4CC0(BtIntPtr);
    s32 func_800F6438(BtUIntPtr);
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

void func_8080128C_chstoneballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct {
        u8 pad0[0x10];
        s32 words[9];
        u8 bytes[6];
        u8 count;
    } *temp_v0;
    s32 var_v1;

    temp_v0 = func_80100094(arg0, 0U);
    for (var_v1 = 0; var_v1 < temp_v0->count; var_v1++) {
        temp_v0->bytes[var_v1] = 0;
        temp_v0->words[var_v1] = 0;
    }
}

void func_808012E0_chstoneballcontrol(void *arg0, s32 arg1) {
    struct Fields {
        u8 pad0[0x64];
        BT_BITFIELD_ORDER(u8 unused : 7, u8 active : 1);
        BT_BITFIELD_ORDER(u8 active : 1, u8 unused : 7);
        u8 pad1[9];
        BT_BITFIELD_ORDER(u16 high : 7, u16 state : 9);
        BT_BITFIELD_ORDER(u16 state : 9, u16 high : 7);
    };
    struct Fields *p = arg0;
    p->state = arg1;
    if (arg1 == 2) {
        p->active = 1;
    } else {
        p->active = 0;
    }
}

s32 func_80801320_chstoneballcontrol(void *arg0) {
    return (*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF;
}

void func_80801330_chstoneballcontrol(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 _sukickball_entrypoint_15(s32);
    void _sukickball_entrypoint_16(s32, f32 *);
    s32 func_800EA05C(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F82D4(BtIntPtr, s32);
    s32 func_800F832C(BtIntPtr, f32 *);
    void func_800F8294(BtIntPtr, f32 *);
    struct Fields {
        u8 pad0[0xA];
        u8 states[6];
        Unk80132ED0 *markers[9];
        u8 bytes[6];
    } *data;
    Actor *actor;
    struct ChildFields {
        u8 pad0[8];
        f32 position[3];
    } *child;

    data = func_80100094(arg0, 0);
    switch (data->states[arg1]) {
        case 1: {
            actor = func_80106790(data->markers[arg1]);
            child = func_80100094(actor, 0);
            _sukickball_entrypoint_16(arg1, actor->position);
            func_800EE7F8(child->position, actor->position);
            actor->rotation[1] = _sukickball_entrypoint_15(arg1);
            actor->unk54 = actor->rotation[1];
            func_808012E0_chstoneballcontrol(actor, arg1);
            break;
        }
        case 2: {
            f32 vec[3];
            if (func_800EA05C() != 0xBB) {
                func_800F82D4(arg1, 2);
                vec[0] = 0.0f;
                vec[1] = _sukickball_entrypoint_15(arg1);
                vec[2] = 0.0f;
                func_800F832C(arg1, vec);
                _sukickball_entrypoint_16(arg1, vec);
                func_800F8294(arg1, vec);
            }
            break;
        }
    }
    data->bytes[arg1] = 0;
}

void func_8080145C_chstoneballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(s32);
    void func_80108B04(Actor *, u32);
    void func_80801638_chstoneballcontrol(BtIntPtr, s32 *);
    void func_80801884_chstoneballcontrol(Actor *);
    struct StoneballData {
        u8 pad0[0x39];
        u8 state;
    } *data;
    struct Counts counts;

    s32 state;

    data = func_80100094(arg0, 0);
    counts = D_808050BC_chstoneballcontrol;
    state = -1;
    func_80801638_chstoneballcontrol((BtIntPtr)arg0, counts.values);
    if (data->state == 3) {
        if (func_800DA298(0x5F) || func_800DA298(0x9EA)) {
            if (counts.values[0] <= 0) {
                state = 3;
            }
        } else if (func_800DA298(0x5E) || func_800DA298(0x9E9)) {
            if (counts.values[0] <= 0) {
                state = 2;
            }
        } else if (counts.values[0] <= 0) {
            state = 1;
        }
        if (state != -1) {
            func_80108B04(arg0, state);
        }
    } else {
        if (counts.values[1] < func_80800114_chstoneballcontrol(data->state, 1)) {
            state = 1;
        } else if (counts.values[2] < func_80800114_chstoneballcontrol(data->state, 2)) {
            state = 2;
        } else if (counts.values[3] < func_80800114_chstoneballcontrol(data->state, 3)) {
            state = 3;
        }
        if (state >= 0) {
            func_80108B04(arg0, state);
        } else if (counts.values[0] < func_80800114_chstoneballcontrol(data->state, 0)) {
            func_80801884_chstoneballcontrol(arg0);
        }
    }
}

void func_80801638_chstoneballcontrol(BtIntPtr arg0, s32 *arg1) {
    s32 _subaddiefind_entrypoint_6(u8 *, Actor **, s32);

    Actor *actors[20];
    struct ActorIds ids;
    Actor *current;
    s32 count;
    int i;

    ids = D_808050CC_chstoneballcontrol;
    count = _subaddiefind_entrypoint_6(ids.ids, actors, 20);
    arg1[2] = 0;
    arg1[1] = 0;
    arg1[0] = 0;
    for (i = 0; i < count; i++) {
            switch (actors[i]->unk6C_9) {
                case 0x155:
                    arg1[1]++;
                    break;
                case 0x29E:
                    arg1[2]++;
                    break;
                case 0x1B8:
                    arg1[3]++;
                    break;
            }
    }
    arg1[0] = arg1[1] + arg1[2] + arg1[3];
}

void func_80801734_chstoneballcontrol(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80801808_chstoneballcontrol(Actor *, s32, s32);
    s32 var_s0;
    struct {
        u8 pad[0x3A];
        u8 count;
    } *data;

    data = func_80100094(arg0, 0U);
    var_s0 = 0;
    if ((s32) data->count > 0) {
        do {
            func_80801808_chstoneballcontrol(arg0, var_s0, arg1);
            var_s0 += 1;
        } while (var_s0 < (s32) data->count);
    }
}

void func_808017AC_chstoneballcontrol(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800B4C_chstoneballcontrol(void *, s32);
    void *actor;

    actor = func_80106790(arg0);
    switch (arg1) {
        case 0:
            func_80800B4C_chstoneballcontrol(actor, 2);
            return;
        case 1:
            func_80800B4C_chstoneballcontrol(actor, 0xB);
            return;
    }
}

void func_80801808_chstoneballcontrol(Actor *arg0, s32 arg1, s32 arg2) {
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
                func_80800EBC_chstoneballcontrol(arg1, arg2);
            }
        } else {
            func_808017AC_chstoneballcontrol(data->entries[arg1], arg2);
        }
    }
}

void func_80801884_chstoneballcontrol(Actor *arg0) {
    f32 func_800DC0C0(void);
    s32 func_800EA05C(void);
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);
    extern f32 D_80805010_chstoneballcontrol[5][2];
    struct {
        u8 pad0[0x39];
        u8 kind;
    } *sp1C;
    f32 sp18;
    u32 state;
    f32 *thresholds;

    sp1C = func_80100094(arg0, 0);
    sp18 = func_800DC0C0();
    if (func_800EA05C() != 0xBB || arg0->unk70_10 != 1) {
        thresholds = D_80805010_chstoneballcontrol[sp1C->kind];
        if (sp18 < thresholds[0]) {
            state = 1;
        } else if (sp18 < thresholds[1]) {
            state = 2;
        } else {
            state = 3;
        }
        func_80108B04(arg0, state);
    }
}

OSThread *chstoneballcontrol_entrypoint_0(void)
{


    return (OSThread *) D_808050D4_chstoneballcontrol;
}

void func_80801944_chstoneballcontrol(u8 *arg0, s32 arg1) {
    void _subaddiefade_entrypoint_3(Actor *);
    void _sukickball_entrypoint_11(u8 *, s32);
    s32 _sukickball_entrypoint_6(u8 *, BtIntPtr);
    void func_800B4470(u8 *, s32, void *, s32, f32, f32, s32, s32, s32);
    void func_800F4F98(s32, void *);
    void *func_80100094(Actor *, u32);
    s32 func_80101FDC(u8 *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_808024F8_chstoneballcontrol(Actor *);
    void func_80802588_chstoneballcontrol(Actor *volatile, volatile s32);

    u8 *data;
    BtIntPtr linked;
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
    if (state == 3 && arg1 == 2 && (*(u32 *)(*(u8 **)arg0 + 0x24) >> 22) == 0x253) {
        *(f32 *)(data + 0x14) = 20.0f;
        *(f32 *)(data + 0x18) = 2.0f;
        _subaddiefade_entrypoint_3(arg0);
        func_808024F8_chstoneballcontrol(arg0);
        arg1 = 4;
    }
    func_80101FDC(arg0, arg1);
    if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 6) {
        func_808024F8_chstoneballcontrol(arg0);
        _subaddiefade_entrypoint_3(arg0);
        func_800B4470(arg0 + 4, 0, D_8080511C_chstoneballcontrol, 1, 0.75f, 0.0f, 0x7D, 0xFA, 0);
        kind = *(u32 *)(*(u8 **)arg0 + 0x24) >> 22;
        if (kind != 0x254) {
            if (kind == 0x267) {
                func_80802588_chstoneballcontrol(arg0, 1);
            }
        } else {
            func_80802588_chstoneballcontrol(arg0, 2);
        }
    }
}

void func_80801B00_chstoneballcontrol(u8 *arg0) {
    void *func_80100094(Actor *, u32);
    u8 *data;

    data = func_80100094(arg0, 0);
    *(s8 *)(data + 0x20) = 0x7F;
    *(f32 *)(data + 4) = 0.0f;
    *(f32 *)data = 0.0;
    *(f32 *)(arg0 + 0x24) = 0.0f;
}

void func_80801B44_chstoneballcontrol(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    s32 func_800EA05C();
    void func_8010A590(Actor *);

    arg0->unk74_17 = 0;
    func_8010A590(arg0);
    arg0->scale = 1.5f;
    arg0->rotation[0] = func_800DC178(0.0f, 45.0f);
    arg0->rotation[2] = func_800DC178(0.0f, 45.0f);
    func_80801B00_chstoneballcontrol(arg0);
    if (func_800EA05C() != 0xBB) {
        arg0->position[1] = -75.0f;
    } else {
        arg0->position[1] = -425.0f;
    }
}

void func_80801BE0_chstoneballcontrol(Actor *arg0) {
    typedef struct { f32 timer; f32 unk4; f32 position[3]; f32 unk14; f32 unk18; f32 unk1C; u8 owner; } BallData;
    typedef struct { u8 pad[0x24]; BT_BITFIELD_ORDER(u32 id:10, u32 flags : 22); BT_BITFIELD_ORDER(u32 flags:22, u32 id : 10); } MarkerState;
    s32 _sukickball_entrypoint_6(u8 *, BtIntPtr);
    s32 _sukickball_entrypoint_7(u8 *, BtIntPtr);
    BtIntPtr _sukickball_entrypoint_8(Actor *arg0, s32 arg1);
    f32 func_800137AC(f32);
    f32 func_800137C4(void);
    void func_8008FB58(f32 *, f32, f32);
    s32 func_80090178(s32);
    void func_800B4470(u8 *, s32, void *, s32, f32, f32, s32, s32, s32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    f32 func_800DC0C0(void);
    s32 func_800EA05C();
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    s32 func_800EF1B8(f32 *, f32, f32);
    f32 func_800EFBFC(void *, void *);
    void func_800EFCD8(f32 *, f32, f32);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800F5D70(BtIntPtr, f32 *);
    f32 func_800F5F24(BtUIntPtr);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_808023AC_chstoneballcontrol(u8 *volatile);
    void func_80802418_chstoneballcontrol(Actor *);
    void func_808024F8_chstoneballcontrol(Actor *);
    void func_80802614_chstoneballcontrol(f32 *);
    void func_80802C30_chstoneballcontrol(s32 *);
    void func_80803148_chstoneballcontrol(u8 *);
    void func_80803538_chstoneballcontrol(u8 *);

    BallData *data;
    u8 *parent;
    f32 position[3];
    f32 oldPosition[3];
    f32 velocity[3];
    Actor *carrier;
    Actor *kicker;
    f32 sine;
    f32 cosine;

    data = func_80100094(arg0, 0);
    parent = (u8 *)func_80106790(arg0->unk3C);
    if (!func_80090178(0x80)) {
        func_8008FB58(arg0->position, 0.0f, 25.0f);
    }
    switch (arg0->unk70_10) {
        case 5:
            if (func_800EA05C() != 0xBB) {
                if (arg0->position[1] < 25.0f) {
                    arg0->position[1] += 5.0f;
                }
                if (arg0->alpha < 240.0f) {
                    arg0->alpha += 15.0f;
                } else if (arg0->position[1] >= 25.0f) {
                    arg0->unk70_10 = 1;
                    arg0->alpha = 255;
                }
            } else {
                if (arg0->position[1] < -325.0f) {
                    arg0->position[1] += 5.0f;
                }
                if (arg0->alpha < 240.0f) {
                    arg0->alpha += 15.0f;
                } else if (arg0->position[1] >= -325.0f) {
                    arg0->unk70_10 = 1;
                    arg0->alpha = 255;
                }
            }
            break;
        case 1:
            func_80803148_chstoneballcontrol((u8 *)arg0);
            func_80802C30_chstoneballcontrol((s32 *)arg0);
            func_808023AC_chstoneballcontrol((u8 *)arg0);
            break;
        case 2:
            func_800EE7F8(oldPosition, arg0->position);
            func_80802C30_chstoneballcontrol((s32 *)arg0);
            if (_sukickball_entrypoint_6(parent, data->owner)) {
                func_800F5A00(data->owner, position);
                arg0->unk54 = func_800F5F24(data->owner);
                arg0->position[1] = 0.0f;
                func_800EFCD8(arg0->position, arg0->unk54, 60.0f);
                func_800EF04C(arg0->position, position);
                func_800F5D70(data->owner, velocity);
                arg0->unk50 = velocity[0] * velocity[0] + velocity[2] * velocity[2];
                func_800EE7F8((f32 *)arg0->actorData, position);
            } else {
                carrier = func_80106790(_sukickball_entrypoint_8(parent, data->owner));
                arg0->position[1] = 0.0f;
                func_800EFCD8(arg0->position, carrier->rotation[1], 60.0f);
                func_800EF04C(arg0->position, carrier->position);
                arg0->unk54 = carrier->rotation[1];
                arg0->unk50 = ((f32 *)carrier->actorData)[3] * ((f32 *)carrier->actorData)[3];
                func_800EE7F8((f32 *)arg0->actorData, carrier->position);
            }
            if (func_800EFBFC(oldPosition, arg0->position) > 25.0f && func_800DC0C0() < 0.1f) {
                func_800B4470((u8 *)oldPosition, 0, D_80805120_chstoneballcontrol, 1, 0.75f, 0.0f, 75, 150, 0);
            }
            func_800D9078((f32 *)data);
            func_80803148_chstoneballcontrol((u8 *)arg0);
            if (_sukickball_entrypoint_7(parent, data->owner)) {
                kicker = func_80106790(_sukickball_entrypoint_8(parent, data->owner));
                if (kicker->unk64_20 == 1) {
                    func_80803538_chstoneballcontrol((u8 *)arg0);
                    kicker->unk58 = 0.0f;
                    kicker->unk64_20 = 0;
                }
            }
            func_808023AC_chstoneballcontrol((u8 *)arg0);
            break;
        case 3:
            func_80802C30_chstoneballcontrol((s32 *)arg0);
            func_800EF1B8(arg0->position, arg0->rotation[1], ((f32 *)arg0->actorData)[3] * func_800D8FF8());
            ((f32 *)arg0->actorData)[3] -= 6.0f;
            if (((MarkerState *)arg0->unk0)->id == 0x253 && ((f32 *)arg0->actorData)[3] < 600.0f) {
                data->unk14 += data->unk18;
                data->unk18 += 0.5f;
            }
            if (((f32 *)arg0->actorData)[3] <= 0.0f) {
                func_80801944_chstoneballcontrol((u8 *)arg0, 1);
                func_808024F8_chstoneballcontrol(arg0);
            }
            func_80803148_chstoneballcontrol((u8 *)arg0);
            if (func_800DC0C0() < 0.15f && ((f32 *)arg0->actorData)[3] > 120.0f) {
                func_800B4470((u8 *)arg0->position, 0, D_80805120_chstoneballcontrol, 1, 0.75f, 0.0f, 50, 100, 0);
            }
            func_808023AC_chstoneballcontrol((u8 *)arg0);
            break;
        case 4:
            func_80802C30_chstoneballcontrol((s32 *)arg0);
            func_80802418_chstoneballcontrol(arg0);
            break;
        case 6:
            ((f32 *)arg0->actorData)[3] -= 15.0f;
            func_80802418_chstoneballcontrol(arg0);
            break;
    }
    if (((f32 *)arg0->actorData)[3] > 30.0f) {
        sine = func_800137AC(arg0->rotation[1]);
        cosine = func_800137C4();
        arg0->rotation[0] += (sine * ((f32 *)arg0->actorData)[3] * 2.0f) / 30.0f;
        arg0->rotation[2] -= (cosine * ((f32 *)arg0->actorData)[3] * 2.0f) / 30.0f;
    }
    if (((MarkerState *)arg0->unk0)->id == 0x253 && arg0->unk70_10 != 4 && arg0->unk70_10 != 6 && arg0->unk7C_12 && func_800DC0C0() < 0.1f) {
        func_80802614_chstoneballcontrol(data->position);
    }
    if (data->unk1C > 0.0f) {
        data->unk1C -= func_800D8FF8();
    }
}

/* extern */

void func_808023AC_chstoneballcontrol(u8 *volatile arg0) {
    s32 func_800EA05C();
    s32 func_808026A0_chstoneballcontrol();
    void func_8080282C_chstoneballcontrol(u8 *, s32);
    s32 sp1C[1];
    s32 map;
    s32 kind;
    u8 *data;

    sp1C[0] = func_808026A0_chstoneballcontrol();
    map = func_800EA05C();
    data = arg0;
    kind = sp1C[0];
    if (map != 0xBB) {
        *(f32 *)(data + 8) = 30.0f;
    } else {
        *(f32 *)(data + 8) = -320.0f;
    }
    if (kind != -1) {
        func_8080282C_chstoneballcontrol(data, kind);
    }
}

void func_80802418_chstoneballcontrol(Actor *arg0) {
    arg0->position[1] -= 5.0f;
    arg0->alpha = (u32)arg0->alpha * 0.7f;
    arg0->scale *= 0.95f;
}

void func_808024F8_chstoneballcontrol(Actor *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    void func_80802648_chstoneballcontrol(f32 *);
    void func_80802F14_chstoneballcontrol(Actor *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefade_entrypoint_3(Actor *);
    extern u16 D_80804FD4_chstoneballcontrol[10];
    Actor *sp24;

    sp24 = func_80106790(arg0->unk3C);
    if ((arg0->unk0->unk24 >> 22) == 0x253) {
        func_80802648_chstoneballcontrol(arg0->position);
        func_80802F14_chstoneballcontrol(arg0);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804FD4_chstoneballcontrol);
        _subaddiefade_entrypoint_3(arg0);
        func_80801944_chstoneballcontrol(arg0, 4);
        func_80800DB4_chstoneballcontrol(sp24, arg0->position);
    }
}

void func_80802588_chstoneballcontrol(Actor *volatile arg0, volatile s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA670(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);

    extern u16 D_80804FE8_chstoneballcontrol[10];
    BtIntPtr emitter;
    s32 model;
    f32 *position;

    position = arg0->position;
    emitter = func_800BABB8(0, position, NULL, 1.0f, D_80805134_chstoneballcontrol);
    model = (arg1 == 1) ? 0x679 : 0x67A;
    func_800BA670(emitter, model);
    func_800BA22C(emitter, 0xA);
    _subaddieaudioquick_entrypoint_2(arg0, position, D_80804FE8_chstoneballcontrol);
}

void func_80802614_chstoneballcontrol(f32 *arg0) {
    BtIntPtr func_800BBCB8(f32 *arg0, f32 *arg1, f32 arg2, s32 arg3, s32 *arg4);

    func_800BBCB8(arg0, 0, 1.0f, 2, D_80805178_chstoneballcontrol);
}

void func_80802648_chstoneballcontrol(f32 *arg0) {
    BtIntPtr func_800BBCB8(f32 *arg0, f32 *arg1, f32 arg2, s32 arg3, s32 *arg4);

    func_800BBCB8(arg0, 0, 1.0f, 0xA, D_808051C0_chstoneballcontrol);
    func_800BBCB8(arg0, 0, 1.0f, 5, D_80805210_chstoneballcontrol);
}

s32 func_808026A0_chstoneballcontrol(Actor *arg0) {
    s32 func_800EA05C();
    int func_800F0064(f32 *, f32, f32 *);

    s32 i;

    if (func_800EA05C() == 0xBB) {
        if (arg0->position[0] < -3055.0f) {
            return 2;
        }
        if (arg0->position[0] > -1145.0f) {
            return 0;
        }
        if (arg0->position[2] < -1555.0f) {
            return 3;
        }
        if (arg0->position[2] > -445.0f) {
            return 1;
        }
        for (i = 0; i < 6; i++) {
            if (func_800F0064(arg0->position, 100.0f, D_80805258_chstoneballcontrol[i])) {
                return 1;
            }
        }
        return -1;
    }
        if (arg0->position[0] < -675.0f) {
            return 2;
        }
        if (arg0->position[0] > 675.0f) {
            return 0;
        }
        if (arg0->position[2] < -675.0f) {
            return 3;
        }
        if (arg0->position[2] > 675.0f) {
            return 1;
        }
    return -1;
}

void func_8080282C_chstoneballcontrol(u8 *arg0, s32 arg1) {
    s32 func_800EA05C();
    void func_80802FBC_chstoneballcontrol(Actor *, s32);

    if (func_800EA05C() != 0xBB) {
        switch (arg1) {
        case 0:
            if ((*(f32 *)(arg0 + 0xC) > -183.0f) && (*(f32 *)(arg0 + 0xC) < 183.0f)) {
                if ((((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4) && (*(f32 *)(arg0 + 4) > 720.0f)) {
                    func_80802FBC_chstoneballcontrol(arg0, 0);
                }
                if (*(f32 *)(arg0 + 4) > 801.0f) {
                    *(f32 *)(arg0 + 4) = 846.0;
                    *(f32 *)(arg0 + 0x24) = 0.0;
                }
            } else {
                *(f32 *)(arg0 + 4) = 720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801944_chstoneballcontrol(arg0, 6);
            }
            break;
        case 1:
            if ((*(f32 *)(arg0 + 4) < 183.0f) && (*(f32 *)(arg0 + 4) > -183.0f)) {
                if ((((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4) && (*(f32 *)(arg0 + 0xC) > 720.0f)) {
                    func_80802FBC_chstoneballcontrol(arg0, 1);
                }
                if (*(f32 *)(arg0 + 0xC) > 801.0f) {
                    *(f32 *)(arg0 + 0xC) = 846.0;
                    *(f32 *)(arg0 + 0x24) = 0.0;
                }
            } else {
                *(f32 *)(arg0 + 0xC) = 720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801944_chstoneballcontrol(arg0, 6);
            }
            break;
        case 2:
            if ((*(f32 *)(arg0 + 0xC) < 183.0f) && (*(f32 *)(arg0 + 0xC) > -183.0f)) {
                if ((((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4) && (*(f32 *)(arg0 + 4) < -720.0f)) {
                    func_80802FBC_chstoneballcontrol(arg0, 2);
                }
                if (*(f32 *)(arg0 + 4) < -801.0f) {
                    *(f32 *)(arg0 + 4) = -846.0;
                    *(f32 *)(arg0 + 0x24) = 0.0;
                }
            } else {
                *(f32 *)(arg0 + 4) = -720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801944_chstoneballcontrol(arg0, 6);
            }
            break;
        case 3:
            if ((*(f32 *)(arg0 + 4) > -183.0f) && (*(f32 *)(arg0 + 4) < 183.0f)) {
                if ((((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4) && (*(f32 *)(arg0 + 0xC) < -720.0f)) {
                    func_80802FBC_chstoneballcontrol(arg0, 3);
                }
                if (*(f32 *)(arg0 + 0xC) < -801.0f) {
                    *(f32 *)(arg0 + 0xC) = -846.0;
                    *(f32 *)(arg0 + 0x24) = 0.0;
                }
            } else {
                *(f32 *)(arg0 + 0xC) = -720.0f;
                *(f32 *)(arg0 + 0x24) = 0.0f;
                func_80801944_chstoneballcontrol(arg0, 6);
            }
            break;
        }
    } else {
        if ((*(f32 *)(arg0 + 4) > -1145.0f) || (*(f32 *)(arg0 + 4) < -3255.0f) ||
            (*(f32 *)(arg0 + 0xC) > -745.0f) || (*(f32 *)(arg0 + 0xC) < -1255.0f)) {
            *(f32 *)(arg0 + 0x24) = 0.0f;
            func_80801944_chstoneballcontrol(arg0, 6);
        }
    }
}

void func_80802C30_chstoneballcontrol(s32 *arg0) {
    typedef struct { u8 pad[0x1A]; u16 index; u8 pad1[8]; BT_BITFIELD_ORDER(u32 id:10, u32 flags : 22); BT_BITFIELD_ORDER(u32 flags:22, u32 id : 10); } Marker;
    typedef struct { Marker *marker; s32 unk4; u32 flags; } Entry;
    s32 *func_800BE3F8(void *);
    Entry *func_800E9E88(BtIntPtr);
    void * func_800E9EB4(void *cube);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80802D9C_chstoneballcontrol(Actor *, Actor *);
    void func_80802E30_chstoneballcontrol(Actor *, u32);
    void func_80802EA0_chstoneballcontrol(Actor *, Actor *);
    s32 *list;
    Entry *entry;
    Entry *end;
    Marker *marker;

    list = func_800BE3F8(arg0 + 1);
    while (*list != 0) {
        entry = func_800E9E88(*list);
        end = func_800E9EB4(*list);
        for (; entry < end; entry++) {
            if (entry->flags & 1) {
                marker = entry->marker;
                if (marker != (Marker *)*arg0) {
                    if (marker->id == 0x267 || marker->id == 0x253 || marker->id == 0x254) {
                        func_80802D9C_chstoneballcontrol(arg0, func_80106790((BtIntPtr)marker));
                    }
                    if (marker->id == 0) {
                        func_80802E30_chstoneballcontrol(arg0, (u32)marker->index >> 5);
                    }
                    if (marker->id == 0x237) {
                        func_80802EA0_chstoneballcontrol(arg0, func_80106790((BtIntPtr)marker));
                    }
                }
            }
        }
        list++;
    }
}

void func_80802D9C_chstoneballcontrol(Actor *arg0, Actor *arg1) {
    s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
    void func_800C4140(u32, f32 *, u32);
    void *func_80100094(Actor *, u32);
    f32 *sp1C;

    sp1C = func_80100094(arg0, 0);
    if (_sukickball_entrypoint_13(arg0->position, arg1->position, 60.0f) && sp1C[7] <= 0.0f) {
        func_800C4140(0x7FFF4482, arg0->position, 0x138801F4);
        sp1C[7] = 0.75f;
    }
}

void func_80802E30_chstoneballcontrol(Actor *arg0, u32 arg1) {
    s32 _sukickball_entrypoint_12(u8 *, s32);
    s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
    void func_800F5A00(BtIntPtr, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *parent;
    f32 sp18[3];

    parent = func_80106790(arg0->unk3C);
    if (arg0->unk70_10 != 2 && _sukickball_entrypoint_12((u8 *)parent, arg1)) {
        func_800F5A00(arg1, sp18);
        _sukickball_entrypoint_13(sp18, arg0->position, 60.0f);
    }
}

void func_80802EA0_chstoneballcontrol(Actor *arg0, Actor *arg1) {
    s32 _sukickball_entrypoint_12(u8 *, s32);
    s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *parent;

    parent = func_80106790(arg0->unk3C);
    if (arg0->unk70_10 != 2) {
        if (_sukickball_entrypoint_12((u8 *)parent, func_80801320_chstoneballcontrol(arg1))) {
            _sukickball_entrypoint_13(arg1->position, arg0->position, 60.0f);
        }
    }
}

void func_80802F14_chstoneballcontrol(Actor *arg0) {
    typedef struct { f32 timer; u8 pad[0x1C]; u8 owner; } BallData;
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _sukickball_entrypoint_6(u8 *, BtIntPtr);
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

void func_80802FBC_chstoneballcontrol(Actor *arg0, s32 arg1) { Actor *parent;
    u32 kind;
    void _sukickball_entrypoint_9(Actor *, s32, s32);
    void _subaddiefade_entrypoint_3(Actor *);
    Actor *func_80106790(Unk80132ED0 *);


    parent = func_80106790(arg0->unk3C);
    func_80802F14_chstoneballcontrol(arg0);
    kind = arg0->unk0->unk24 >> 22;
    switch (kind) {
    case 0x267:
        _sukickball_entrypoint_9(parent, D_808052A0_chstoneballcontrol[arg1], 1);
        break;
    case 0x253:
        _sukickball_entrypoint_9(parent, D_808052A0_chstoneballcontrol[arg1], 3);
        break;
    case 0x254:
        _sukickball_entrypoint_9(parent, D_808052A0_chstoneballcontrol[arg1], 2);
        break;
    }
    arg0->unk70_10 = 4;
    _subaddiefade_entrypoint_3(arg0);
}

void chstoneballcontrol_entrypoint_1(Unk80132ED0 *arg0, s32 arg1, u32 arg2, s32 arg3) {
    typedef struct { f32 unknown; f32 timer; } ControlData;
    f32 func_800D8FF8(void);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80803538_chstoneballcontrol(u8 *);
    void *actor;
    ControlData *data;

    actor = func_80106790(arg0);
    data = func_80100094(actor, 0);
    if (arg1 != 1) {
        if (arg1 == 3) {
            func_80801944_chstoneballcontrol(actor, 1);
        }
    } else {
        data->timer = func_800D8FF8() * arg2;
        func_80803538_chstoneballcontrol(actor);
    }
}

void func_80803148_chstoneballcontrol(u8 *arg0) {
    typedef StoneballDistances Distances;
    typedef StoneballVector Position;
    typedef struct { f32 timer; u8 pad[0x1C]; u8 owner; } BallData;
    typedef struct { u8 pad[0x3A]; u8 count; } ParentData;
    typedef struct { u8 pad[0x24]; BT_BITFIELD_ORDER(u32 id:10, u32 flags : 22); BT_BITFIELD_ORDER(u32 flags:22, u32 id : 10); } MarkerState;
    typedef struct { u8 pad[0x70]; BT_BITFIELD_ORDER(u32 upper:16, u32 flags : 10); u32 state:6; BT_BITFIELD_ORDER(u32 flags:10, u32 upper : 16); } ActorState;


#ifndef BT_NATIVE
    extern void _chstoneballcontrol_entrypoint_1(void);
#endif
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _sukickball_entrypoint_6(u8 *, BtIntPtr);
    s32 _sukickball_entrypoint_7(u8 *, BtIntPtr);
    BtIntPtr _sukickball_entrypoint_8(Actor *arg0, s32 arg1);
    void _sukickball_entrypoint_10(u8 *, s32, s32);
    void _sukickball_entrypoint_11(u8 *, s32);
    s32 _sukickball_entrypoint_12(u8 *, s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    void func_800F4950(s32, void *, void (*)(void));
    void func_800F4F98(s32, void *);
    s32 func_800F5410(BtIntPtr);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6C5C(BtIntPtr);
    BallData *data = func_80100094(arg0, 0);
    f32 distances[4];
    u8 *parent;
    ParentData *parentData;
    f32 closest;
    s32 selected;
    s32 i;

    *(Distances *)distances = D_808052B0_chstoneballcontrol;
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
                *(Position *)position = D_808052C0_chstoneballcontrol;
                if (_sukickball_entrypoint_6(parent, i)) {
                    if (func_800F6C5C(i) && func_800F5410(i) == 8) {
                        func_800F5A00(i, position);
                        if (func_800EFFB4((f32 *)(arg0 + 4), 65.0f, position)) {
                            distances[i] = func_800EEB40((f32 *)(arg0 + 4), position);
                        }
                    }
                } else {
                    func_800EE7F8(position, func_80106790(_sukickball_entrypoint_8(parent, i))->position);
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
                func_800F4950(data->owner, *(void **)arg0, _chstoneballcontrol_entrypoint_1);
            } else {
                u8 *player = func_80106790(_sukickball_entrypoint_8(parent, data->owner));
                player[0x65] &= ~0x10;
            }
            switch ((*(MarkerState **)arg0)->id) {
                case 0x267:
                    _sukickball_entrypoint_10(parent, data->owner, 1);
                    break;
                case 0x253:
                    _sukickball_entrypoint_10(parent, data->owner, 3);
                    break;
                case 0x254:
                    _sukickball_entrypoint_10(parent, data->owner, 2);
                    break;
            }
            func_80801944_chstoneballcontrol(arg0, 2);
            *(f32 *)(arg0 + 0x24) = 0.0f;
        }
    }
}

void func_80803538_chstoneballcontrol(u8 *actorPtr) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _sukickball_entrypoint_6(u8 *, BtIntPtr);
    BtIntPtr _sukickball_entrypoint_8(Actor *arg0, s32 arg1);
    void _sukickball_entrypoint_11(u8 *, s32);
    f32 func_800F5F24(BtUIntPtr);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F4F98(s32, void *);
    void func_800C4140(u32, f32 *, u32);
    Actor *arg0 = (Actor *)actorPtr;
    s32 pad;
    Actor *player;
    void *parent;
    struct {
        f32 timer;
        f32 charge;
        u8 pad8[0x18];
        u8 owner;
    } *data;

    parent = func_80106790(arg0->unk3C);
    data = func_80100094(arg0, 0);
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
    func_800C4140(0x7FFF453C, arg0->position, 0x3E800640);
}

void func_8080367C_chstoneballcontrol(BtIntPtr arg0)
{
    func_80801944_chstoneballcontrol(arg0,0);
}

OSThread *chstoneballcontrol_entrypoint_2(void)
{


    return (OSThread *) D_808052CC_chstoneballcontrol;
}

OSThread *chstoneballcontrol_entrypoint_3(void)
{


    return (OSThread *) D_80805314_chstoneballcontrol;
}

OSThread *chstoneballcontrol_entrypoint_4(void)
{


    return (OSThread *) D_8080535C_chstoneballcontrol;
}

s32 func_808036C0_chstoneballcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad[0x64];
        BT_BITFIELD_ORDER(u32 : 3, u32 : 27);
        BT_BITFIELD_ORDER(u32 controller_index : 2, u32 controller_index : 2; u32  : 3);
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

void func_80803724_chstoneballcontrol(Actor *arg0) {
    typedef StoneballVector Vec3;
    typedef struct {
        f32 position[3];
        f32 speed;
        f32 velocity[3];
        f32 timer;
    } BallMotion;
    typedef struct {
        void *controller;
        f32 timer;
        f32 position[3];
    } BallControl;

    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    f32 _subaddiejoy_entrypoint_3();
    s32 _sukickball_entrypoint_12(u8 *, s32);
    void _sukickball_entrypoint_14(Actor *);
    f32 _sukickball_entrypoint_15(s32);
    void _sukickball_entrypoint_16(s32, f32 *);
    void _sukickball_entrypoint_2(Actor *, f32, f32);
    s32 _sukickball_entrypoint_5(Actor *, f32 *);
    void func_800B4470(u8 *, s32, void *, s32, f32, f32, s32, s32, s32);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    int func_800F0064(f32 *, f32, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, s32);
    struct anctrl_s *func_80104248(void *);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void func_808040B8_chstoneballcontrol(Actor *);
    void func_80804218_chstoneballcontrol(Actor *);
    void func_80804304_chstoneballcontrol(u8 *);
    BtIntPtr func_80804810_chstoneballcontrol(Actor *);
    void func_80804B60_chstoneballcontrol(Actor *);
    BallControl *sp64;
    Actor *sp60;
    f32 sp5C;
    Vec3 sp50;
    f32 speedLimit;

    sp64 = func_80100094(arg0, 0);
    sp5C = func_800D8FF8();
    sp60 = func_80106790(arg0->unk3C);
    func_800BD2D0(sp64->controller);
    sp64->timer -= sp5C;
    switch (arg0->unk70_10) {
    case 10:
        ((BallMotion *)arg0->actorData)->velocity[1] = 0.0f;
        ((BallMotion *)arg0->actorData)->speed = _subaddiejoy_entrypoint_3(arg0);
        if (_sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0)) {
            ((BallMotion *)arg0->actorData)->speed = func_800F10B4(((BallMotion *)arg0->actorData)->speed, 0.0f, 1.0f, 0.0f, func_80800070_chstoneballcontrol(arg0));
        } else {
            speedLimit = func_80800040_chstoneballcontrol(arg0);
            ((BallMotion *)arg0->actorData)->speed = func_800F10B4(((BallMotion *)arg0->actorData)->speed,
                0.0f,
                1.0f,
                0,
                speedLimit);
        }
        if (_sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0) && func_800BCFC4(sp64->controller, 1)) {
            arg0->unk58 = func_800F10B4((s32)func_800BCD78(sp64->controller, 1, 1) * func_800D8FF8(), 0.0f, 1.0f, 450.0f, 900.0f);
            arg0->unk64_20 = 1;
        }
        func_80804B60_chstoneballcontrol(arg0);
        _sukickball_entrypoint_2(arg0, func_8080009C_chstoneballcontrol(arg0), func_80800040_chstoneballcontrol(arg0));
        if (func_800BD030(sp64->controller, 9)) {
            func_80800B4C_chstoneballcontrol(arg0, 8);
        }
        break;
    case 8:
        if (0 == arg0->unk50) {
            if (func_80101E14(arg0, 0.3077f)) {
                anctrl_setPlaybackType(func_80104248(arg0), 3);
                arg0->unk50 = 1.0f;
                ((BallMotion *)arg0->actorData)->speed = 1050.0f;
                func_800B4470((u8 *)arg0->position, 0, D_80805418_chstoneballcontrol, 1, 0.75f, 0, 125, 250, 0);
            }
        } else if (0 != arg0->unk50) {
            arg0->unk50 += sp5C;
            if (arg0->unk50 > 2.5f || ((BallMotion *)arg0->actorData)->speed < 150.0f) {
                func_80800B4C_chstoneballcontrol(arg0, 2);
                ((BallMotion *)arg0->actorData)->speed = func_8080009C_chstoneballcontrol(arg0);
            } else {
                ((BallMotion *)arg0->actorData)->speed *= 0.9f;
            }
        }
        ((BallMotion *)arg0->actorData)->velocity[1] = 0;
        func_800EEB9C(((BallMotion *)arg0->actorData)->velocity, arg0->rotation[1], ((BallMotion *)arg0->actorData)->speed * sp5C);
        func_800EF04C(arg0->position, ((BallMotion *)arg0->actorData)->velocity);
        if (arg0->unk64_29) {
            _subaddiejoy_entrypoint_3(arg0);
            if (!func_80102CF4(arg0, 0x41000000)) {
                func_80102B2C(arg0, 8.0f);
            }
        }
        func_80804304_chstoneballcontrol((u8 *)arg0);
        break;
    case 12:
        if (((BallMotion *)arg0->actorData)->speed < 150.0f) {
            func_80800B4C_chstoneballcontrol(arg0, 2);
            ((BallMotion *)arg0->actorData)->speed = func_8080009C_chstoneballcontrol(arg0);
        } else {
            ((BallMotion *)arg0->actorData)->speed *= 0.9f;
        }
        ((BallMotion *)arg0->actorData)->velocity[1] = 0.0f;
        func_800EEB9C(((BallMotion *)arg0->actorData)->velocity, arg0->unk54, ((BallMotion *)arg0->actorData)->speed * sp5C);
        func_800EF04C(arg0->position, ((BallMotion *)arg0->actorData)->velocity);
        break;
    case 2:
        if (arg0->unk64_29) {
            arg0->unk70_10 = 10;
            arg0->unk58 = 0.0f;
        }
        if (!func_80804810_chstoneballcontrol(arg0)) {
            func_80800B4C_chstoneballcontrol(arg0, 1);
        }
        if (_sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0)) {
            if (func_800DC0C0() < 0.95f) {
                func_80800B4C_chstoneballcontrol(arg0, 5);
            } else {
                ((BallMotion *)arg0->actorData)->timer = func_800DC178(0.0f, 2.5f);
                func_80800B4C_chstoneballcontrol(arg0, 4);
            }
        }
        func_80804B60_chstoneballcontrol(arg0);
        _sukickball_entrypoint_2(arg0, func_8080009C_chstoneballcontrol(arg0), func_80800040_chstoneballcontrol(arg0));
        break;
    case 1:
        _sukickball_entrypoint_16(arg0->unk6C_0, ((BallMotion *)arg0->actorData)->position);
        func_80804B60_chstoneballcontrol(arg0);
        _sukickball_entrypoint_2(arg0, func_8080009C_chstoneballcontrol(arg0), func_80800040_chstoneballcontrol(arg0));
        if (func_80804810_chstoneballcontrol(arg0)) {
            func_80800B4C_chstoneballcontrol(arg0, 2);
        }
        if (func_800EFFB4(arg0->position, 50.0f, ((BallMotion *)arg0->actorData)->position)) {
            func_80800B4C_chstoneballcontrol(arg0, 3);
        }
        break;
    case 3:
        if (func_80804810_chstoneballcontrol(arg0)) {
            func_80800B4C_chstoneballcontrol(arg0, 2);
        }
        _sukickball_entrypoint_14(arg0);
        _sukickball_entrypoint_2(arg0, func_8080009C_chstoneballcontrol(arg0), func_80800040_chstoneballcontrol(arg0));
        break;
    case 4:
        {
            sp50 = D_8080540C_chstoneballcontrol;
            if (((BallMotion *)arg0->actorData)->timer > 0.0f) {
                ((BallMotion *)arg0->actorData)->timer -= sp5C;
            } else {
                func_80800B4C_chstoneballcontrol(arg0, 5);
            }
            if (!_sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0)) {
                func_80800B4C_chstoneballcontrol(arg0, 1);
            }
            _sukickball_entrypoint_16(arg0->unk6C_0, ((BallMotion *)arg0->actorData)->position);
            func_800EFCD8(sp50.v, _sukickball_entrypoint_15(arg0->unk6C_0), 250.0f);
            func_800EF04C(((BallMotion *)arg0->actorData)->position, sp50.v);
            if (func_800F0064(arg0->position, 100.0f, ((BallMotion *)arg0->actorData)->position) || _sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0) == 3) {
                func_80800B4C_chstoneballcontrol(arg0, 5);
            }
            func_80804B60_chstoneballcontrol(arg0);
            _sukickball_entrypoint_2(arg0, func_8080009C_chstoneballcontrol(arg0), func_80800040_chstoneballcontrol(arg0));
        }
        break;
    case 5:
        func_808040B8_chstoneballcontrol(arg0);
        func_80804218_chstoneballcontrol(arg0);
        func_80800B4C_chstoneballcontrol(arg0, 6);
        break;
    case 6:
        if (_sukickball_entrypoint_12((u8 *)sp60, arg0->unk6C_0)) {
            func_80804218_chstoneballcontrol(arg0);
        } else {
            func_80800B4C_chstoneballcontrol(arg0, 2);
        }
        break;
    case 7:
        if (((BallMotion *)arg0->actorData)->timer > 0.0f) {
            ((BallMotion *)arg0->actorData)->timer -= sp5C;
        } else {
            func_80800B4C_chstoneballcontrol(arg0, 2);
        }
        func_80804B60_chstoneballcontrol(arg0);
        _sukickball_entrypoint_2(arg0, func_8080009C_chstoneballcontrol(arg0), func_80800040_chstoneballcontrol(arg0));
        break;
    case 9:
        arg0->unk64_20 = 0;
        arg0->unk58 = 0.0f;
        arg0->rotation[1] += ((BallMotion *)arg0->actorData)->timer;
        if (((BallMotion *)arg0->actorData)->timer > 1.0f) {
            ((BallMotion *)arg0->actorData)->timer *= 0.95f;
        } else if (((BallMotion *)arg0->actorData)->timer < -1.0f) {
            ((BallMotion *)arg0->actorData)->timer *= 0.95f;
        } else {
            func_80800B4C_chstoneballcontrol(arg0, 2);
            ((BallMotion *)arg0->actorData)->timer = 0.0f;
        }
        break;
    }
    if (_sukickball_entrypoint_5(arg0, sp64->position)) {
        if (arg0->unk70_10 == 8) {
            func_80800B4C_chstoneballcontrol(arg0, 2);
        } else if (!arg0->unk64_29) {
            func_80800BCC_chstoneballcontrol((u8 *)arg0, 0);
        }
    } else {
        func_800EE7F8(sp64->position, arg0->position);
    }
}

s32 func_80803FF4_chstoneballcontrol(s32 arg0, s32 arg1) {
    s32 func_800DC128(s32, s32);
    int func_800DC298(f32);
    s32 choice = arg0;

    switch (arg1) {
        case 0:
            if (func_800DC298(0.1499938965f)) {
                return 0;
            }
            break;
        case 1:
            if (func_800DC298(0.2249908447f)) {
                return 0;
            }
            break;
        case 2:
            if (func_800DC298(0.299987793f)) {
                return 0;
            }
            break;
    }
    while (choice == arg0) {
        choice = func_800DC128(1, 4);
    }
    return choice;
}

void func_808040B8_chstoneballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _sukickball_entrypoint_12(u8 *, s32);
    void _sukickball_entrypoint_4(s32, void *);
    void func_8080419C_chstoneballcontrol(Actor *, s32);
    Actor *parent;
    struct {
        u8 pad0[0x39];
        u8 mode;
    } *data;
    s32 state;

    parent = func_80106790(arg0->unk3C);
    data = func_80100094(parent, 0);
    state = _sukickball_entrypoint_12((u8 *)parent, arg0->unk6C_0);
    switch (state) {
        case 1:
            _sukickball_entrypoint_4(arg0->unk6C_0, arg0->actorData);
            return;
        case 3:
            func_8080419C_chstoneballcontrol(arg0, func_80803FF4_chstoneballcontrol(arg0->unk6C_0, data->mode));
            return;
        case 2:
            _sukickball_entrypoint_4(func_80803FF4_chstoneballcontrol(arg0->unk6C_0, data->mode), arg0->actorData);
        case 0:
            return;
    }
}

void func_8080419C_chstoneballcontrol(Actor *arg0, s32 arg1) {
    s32 _sukickball_entrypoint_6(u8 *, BtIntPtr);
    BtIntPtr _sukickball_entrypoint_8(Actor *arg0, s32 arg1);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F5A00(BtIntPtr, f32 *);
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

void func_80804218_chstoneballcontrol(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    s32 _sukickball_entrypoint_12(u8 *, s32);
    void _sukickball_entrypoint_4(s32, void *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 func_80102D78();
    s32 func_80102CF4(Actor *, s32);
    void func_80102B2C(Actor *, f32);

    if (_sukickball_entrypoint_12((u8 *)func_80106790(arg0->unk3C), arg0->unk6C_0) == 1) {
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
    func_80800B4C_chstoneballcontrol(arg0, 2);
}

void func_80804304_chstoneballcontrol(u8 *arg0) {
    typedef StoneballVector Vec3;
    typedef struct { BT_BITFIELD_ORDER(u8 high:3, u8 low : 4); u8 active:1; BT_BITFIELD_ORDER(u8 low:4, u8 high : 3); } BallFlags;

    s32 _sukickball_entrypoint_12(u8 *, s32);
    s32 _sukickball_entrypoint_13(f32 *, f32 *, f32);
    s32 _sukickball_entrypoint_6(u8 *, BtIntPtr);
    s32 _sukickball_entrypoint_7(u8 *, BtIntPtr);
    BtIntPtr _sukickball_entrypoint_8(Actor *arg0, s32 arg1);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800EEF94(f32 *);
    s32 func_800EF1B8(f32 *, f32, f32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    s32 func_800F52B8(BtIntPtr, Unk80132ED0 *);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800F5D70(BtIntPtr, f32 *);
    void func_800F7700(BtIntPtr, s32, f32 *);
    void func_800F8294(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    f32 func_80102D78();
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800B4C_chstoneballcontrol(void *, s32);
    s32 i;
    u8 *parent;
    u8 *other;
    u8 *parentData;
    f32 *selfPosition;
    f32 position[3];
    f32 selfSpeed;
    f32 speed;
    f32 velocity[3];

    other = NULL;
    parentData = func_80100094(func_80106790(*(s32 *)(arg0 + 0x3C)), 0);
    for (i = 0; i < parentData[0x3A]; i++) {
        selfPosition = (f32 *)(arg0 + 4);
        if (i != (*(s32 *)(arg0 + 0x6C) & 0x1FF)) {
            parent = func_80106790(*(s32 *)(arg0 + 0x3C));
            if (_sukickball_entrypoint_7(parent, i)) {
                other = func_80106790(_sukickball_entrypoint_8(parent, i));
                position[0] = *(f32 *)(other + 4);
                position[1] = *(f32 *)(other + 8);
                position[2] = *(f32 *)(other + 0xC);
            } else {
                func_800F5A00(i, position);
            }
            if (func_800EFFB4(selfPosition, 90.0f, position)) {
                selfSpeed = func_800EEF94((f32 *)(arg0 + 0x28));
                if (_sukickball_entrypoint_6(parent, i)) {
                    func_800F5D70(i, velocity);
                    speed = func_800EEF94(velocity) * func_800D8FF8();
                } else {
                    speed = func_800EEF94((f32 *)(other + 0x28)) * func_800D8FF8();
                }
                if (speed < selfSpeed) {
                    if (_sukickball_entrypoint_6(parent, i)) {
                        _sukickball_entrypoint_13(selfPosition, position, 60.0f);
                        func_800F8294(i, position);
                        if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 8) {
                            Vec3 impulse = D_8080541C_chstoneballcontrol;
                            f32 playerPosition[3];
                            func_800F5A00(i, playerPosition);
                            func_800EF1B8((f32 *)&impulse, func_80102D78(arg0, playerPosition), 150.0f);
                            func_800F7700(i, 3, selfPosition);
                        }
                    } else {
                        f32 *otherPosition = (f32 *)(other + 4);
                        _sukickball_entrypoint_13(selfPosition, otherPosition, 60.0f);
                        if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 8) {
                            *(f32 *)(other + 0x58) = 1.5f;
                            ((BallFlags *)(other + 0x65))->active = 1;
                            func_80800B4C_chstoneballcontrol(other, 12);
                            *(f32 *)(other + 0x24) = *(f32 *)(arg0 + 0x24) * 0.75f;
                            *(f32 *)(other + 0x54) = func_80102D78(arg0, otherPosition);
                            *(f32 *)(arg0 + 0x24) *= 0.5f;
                        }
                    }
                } else {
                    _sukickball_entrypoint_13(position, selfPosition, 60.0f);
                    if (func_800DC0C0() < 0.5f && !_sukickball_entrypoint_12(parent, *(s32 *)(arg0 + 0x6C) & 0x1FF)) {
                        func_80800BCC_chstoneballcontrol(arg0, (BtIntPtr)position);
                    }
                    if (_sukickball_entrypoint_6(parent, i) && func_800F52B8(i, *(Unk80132ED0 **)arg0) == 2) {
                        f32 secondPosition[3];
                        func_800F5A00(i, secondPosition);
                        *(f32 *)(arg0 + 0x54) = func_800F1DF4(secondPosition, selfPosition);
                        func_80800B4C_chstoneballcontrol(arg0, 12);
                        *(f32 *)(arg0 + 0x24) = (speed * 0.75f) / func_800D8FF8();
                    }
                    *(f32 *)(arg0 + 0x58) = 1.5f;
                    ((BallFlags *)(arg0 + 0x65))->active = 1;
                }
            }
        }
    }
}

void func_808046C4_chstoneballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_8010A590(Actor *);
    s32 func_800EA05C();
    u8 _gcstatusDll_entrypoint_11(void);
    void *func_800BD0DC(s32);
    void func_800BD268();
    void func_800BD28C();
    typedef struct {
        u8 pad[0x64];
        BT_BITFIELD_ORDER(u32 enabled : 1, u32 : 27);
        BT_BITFIELD_ORDER(u32 : 1, u32 controller_index : 2);
        u32 active : 1;
        BT_BITFIELD_ORDER(u32 controller_index : 2, u32  : 1; u32 enabled : 1);
    } BallFlags;
    struct {
        void *handle;
        u8 pad[0x10];
        u8 map;
    } *data;

    data = func_80100094(arg0, 0);
    ((BallFlags *)arg0)->enabled = 1;
    arg0->scale = 0.5f;
    func_8010A590(arg0);
    switch (func_800EA05C()) {
    case 0xC6:
        data->map = 0;
        break;
    case 0xC8:
        data->map = 1;
        break;
    case 0xC9:
        data->map = 2;
        break;
    case 0xBB:
        data->map = 3;
        break;
    case 0x17F:
        data->map = 4;
        if (arg0->unk6C_0 < (u32)_gcstatusDll_entrypoint_11()) {
            ((BallFlags *)arg0)->active = 1;
            ((BallFlags *)arg0)->controller_index = arg0->unk6C_0;
        }
        break;
    }
    data->handle = func_800BD0DC(2);
    func_800BD268(data->handle, arg0->unk6C_0);
    func_800BD28C(data->handle, 2);
}

void func_808047E8_chstoneballcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800BD09C();
    void **data = func_80100094(arg0, 0);
    func_800BD09C(*data);
}

BtIntPtr func_80804810_chstoneballcontrol(Actor *arg0)
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
    void func_80800B4C_chstoneballcontrol(void *, s32);
    u8 *selected;
    union { f32 f; s32 i; } distance;
    u8 *other;
    f32 angle;
    f32 speed;

    selected = (u8 *)_subaddiefind_entrypoint_0(&arg0->position[0], 0x155, -1, &distance.f);
    if (selected == NULL) {
        selected = (u8 *)_subaddiefind_entrypoint_0(&arg0->position[0], 0x29E, -1, &distance.f);
        if (selected == NULL) {
            selected = (u8 *)_subaddiefind_entrypoint_0(&arg0->position[0], 0x1B8, -1, &distance.f);
            if (selected == NULL) {
                return NULL;
            }
        }
    } else if ((((u32)*(u16 *)(selected + 0x72) >> 10) == 2 &&
                !func_800F0064(&arg0->position[0], 100.0f, (f32 *)(selected + 4))) ||
               ((u32)*(u16 *)(selected + 0x72) >> 10) == 6 ||
               ((u32)*(u16 *)(selected + 0x72) >> 10) == 4 ||
               ((u32)*(u16 *)(selected + 0x72) >> 10) == 3) {
        switch ((u32)*(u16 *)(selected + 0x72) >> 10) {
            case 2:
                other = (u8 *)_subaddiefind_entrypoint_0(&arg0->position[0], 0x155, 2, &distance.f);
                break;
            case 3:
                other = (u8 *)_subaddiefind_entrypoint_0(&arg0->position[0], 0x155, 3, &distance.f);
                break;
            case 6:
                other = (u8 *)_subaddiefind_entrypoint_0(&arg0->position[0], 0x155, 6, &distance.f);
                break;
            case 4:
                other = (u8 *)_subaddiefind_entrypoint_0(&arg0->position[0], 0x155, 4, &distance.f);
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
            arg0->unk54 = func_80102D78(arg0, (f32 *)(selected + 0x18));
            if (!func_80102CF4(arg0, 0x42340000) && func_80102CF4(arg0, 0x42B40000) &&
                func_800DC0C0() < 0.8f) {
                func_80800B4C_chstoneballcontrol(arg0, 8);
            }
        }
        func_800EFCD8((f32 *)((u8 *)arg0 + 0x18), angle, speed);
        func_800EF04C((f32 *)((u8 *)arg0 + 0x18), (f32 *)(selected + 4));
    } else {
        func_800EE7F8((f32 *)((u8 *)arg0 + 0x18), (f32 *)(selected + 4));
    }
    return (BtIntPtr)selected;
}

void func_80804B60_chstoneballcontrol(Actor *arg0) {
    typedef StoneballVector Vec3;
    typedef struct { f32 position[3]; f32 speed; f32 velocity[3]; } BallMotion;

    s32 _sukickball_entrypoint_12(u8 *, s32);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    f32 func_80102D78();
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80804D40_chstoneballcontrol(void *);
    void func_80804DA0_chstoneballcontrol(void *);
    Vec3 sp2C = D_80805428_chstoneballcontrol;
    Actor *parent;

    parent = func_80106790(arg0->unk3C);
    if (arg0->unk70_10 != 10) {
        arg0->unk54 = func_80102D78(arg0, ((BallMotion *)arg0->actorData)->position);
        if (!func_80102CF4(arg0, 0x43700000)) {
            func_80804DA0_chstoneballcontrol(arg0);
        } else {
            func_80804D40_chstoneballcontrol(arg0);
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
    if (_sukickball_entrypoint_12((u8 *)parent, arg0->unk6C_0) &&
        func_80800070_chstoneballcontrol(arg0) < ((BallMotion *)arg0->actorData)->speed) {
        ((BallMotion *)arg0->actorData)->speed = func_80800070_chstoneballcontrol(arg0);
    }
    func_800EFCD8(((BallMotion *)arg0->actorData)->velocity, arg0->rotation[1], func_800D8FF8() * ((BallMotion *)arg0->actorData)->speed);
    func_800EE780(arg0->position, arg0->position, ((BallMotion *)arg0->actorData)->velocity);
    func_80804304_chstoneballcontrol((u8 *)arg0);
    arg0->rotation[1] = func_800136E4(arg0->rotation[1]);
}

void func_80804D40_chstoneballcontrol(void *arg0) {
    if ((*(f32 *)((s8 *)(arg0) + (0x24))) < func_80800040_chstoneballcontrol(arg0)) {
        *(f32 *)((s8 *)arg0 + 0x24) += func_808000C8_chstoneballcontrol(arg0);
        return;
    }
    (*(f32 *)((s8 *)(arg0) + (0x24))) = func_80800040_chstoneballcontrol(arg0);
}

void func_80804DA0_chstoneballcontrol(void *arg0) {
    if (func_8080009C_chstoneballcontrol(arg0) < *(f32 *)((s8 *)arg0 + 0x24)) {
        *(f32 *)((s8 *)arg0 + 0x24) -= func_808000F4_chstoneballcontrol(arg0);
    }
}

OSThread *chstoneballcontrol_entrypoint_5(void)
{


    return (OSThread *) D_80805434_chstoneballcontrol;
}
