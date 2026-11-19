#include "common.h"
#ifdef BT_NATIVE
#include "core2/particle_script.h"
#endif

struct DodgemValues { s32 values[4]; };
struct dodgem_vector { f32 v[3]; };
typedef struct { f32 values[4]; } DodgemValues;
typedef struct { f32 values[4][3]; } DodgemPositions;
struct DodgemRGB { u32 rgb[3]; };
struct DodgemPosition { f32 v[3]; };

OSThread *chdodgemcontrol_entrypoint_0(void)
{
    extern BtFnWord D_80804DB4_chdodgemcontrol[];

    return (OSThread *) D_80804DB4_chdodgemcontrol;
}

Actor *func_8080000C_chdodgemcontrol(Actor *arg0,s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    return func_80106790(((Unk80132ED0 **)func_80100094(arg0,0))[arg1]);
}

/* extern */

void func_80800044_chdodgemcontrol(f32 *arg0) {
    void func_800906B0(f32 *);
    void func_800906DC(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp24[3];
    f32 sp18[3];

    func_800EFA4C(sp24, 0.0f, 20.0f, 5.0f);
    func_800EF934(sp24, sp24, arg0[18]);
    func_800EF04C(sp24, arg0 + 1);
    func_800EE7F8(sp18, arg0 + 17);
    func_800906B0(sp24);
    func_800906DC(sp18);
}

s32 func_808000B8_chdodgemcontrol(s32 arg0) {
    extern struct DodgemValues D_80804DFC_chdodgemcontrol;
    struct DodgemValues sp18;
    void func_800904C8(s32);
    sp18 = D_80804DFC_chdodgemcontrol;
    func_800904C8(sp18.values[arg0]); BT_NATIVE_ONLY(return 0;)
}

void func_8080010C_chdodgemcontrol(Actor *arg0) {
    struct DodgemData {
        u8 pad0[0x34];
        f32 positions[10][3];
        u8 states[10];
        u8 scores[10];
        u8 padC0[2];
        u8 carCount;
        u8 padC3[2];
        u8 pointCount;
    };
    void _chscorepoints_entrypoint_2(s32, BtIntPtr, f32 *, s32);
    s32 func_800CEAD0(s32);
    s32 func_800CEB54(s32, f32);
    f32 func_800EEB40(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_80800CA0_chdodgemcontrol(Actor *);
    void func_80800FC4_chdodgemcontrol(Actor *, s32, s32);
    void func_8080160C_chdodgemcontrol(Actor *);
    void func_80801A8C_chdodgemcontrol(Actor *, s32);
    struct DodgemData *data;
    s32 i;
    s32 missing;
    s32 car;
    int mode;
    s32 kind;
    s32 count;
    u8 state;
    f32 *position;

    data = func_80100094(arg0, 0);
    mode = arg0->unk70_10;
    switch (mode) {
    case 1:
        func_8080160C_chdodgemcontrol(arg0);
        break;
    case 3:
        func_80801A8C_chdodgemcontrol(arg0, 0);
        if (!func_800CEB54(0, 6.0f) && func_800CEAD0(0)) {
            func_80800CA0_chdodgemcontrol(arg0);
        }
        missing = 0;
        for (i = 0; i < data->pointCount; i++) {
            mode = data->states[i];
            switch (mode) {
                case 1:
                    count = data->carCount;
                    position = data->positions[i];
                    for (car = 0; car < count; car++) {
                        if (func_800EEB40(func_8080000C_chdodgemcontrol(arg0, car)->position, position) < 22500.0f) {
                            mode = arg0->unk79_4;
                            switch (mode) {
                            case 3:
                                goto score;
                            case 0:
                            case 1:
                            case 2:
                                if (car != 0) {
                                    data->states[i] = 3U;
                                    break;
                                }
                            score:
                                _chscorepoints_entrypoint_2(data->scores[i] + 1, 0, position, 1);
                                func_80800FC4_chdodgemcontrol(arg0, car, data->scores[i] + 1);
                                data->states[i] = 2U;
                                break;
                            }
                        }
                    }
                    break;
                case 0:
                    missing = 1;
                    break;
            }
        }
        if (missing) {
            func_80108B04(arg0, -1);
        }
        break;
    case 4:
        func_80801A8C_chdodgemcontrol(arg0, 1);
        break;
    case 2:
        break;
    }
}

/* extern */

int func_80800350_chdodgemcontrol(void) {
    f32 func_800DC0C0(void);
    f32 temp_f0;

    temp_f0 = func_800DC0C0();
    if (temp_f0 < 0.5f) {
        return 0;
    }
    if (temp_f0 < 0.8333333f) {
        return 1;
    }
    return 2;
}

/* extern */

void func_808003B0_chdodgemcontrol(void *arg0) {
    f32 func_800DC178(f32, f32);
    (((Vec3f *)arg0)->pos.x) = func_800DC178(-645.0f, 645.0f);
    (((Vec3f *)arg0)->pos.y) = 0.0f;
    (((Vec3f *)arg0)->pos.z) = func_800DC178(-645.0f, 645.0f);
}

/* extern */

s32 func_8080040C_chdodgemcontrol(Actor *arg0, f32 *arg1, s32 arg2) {
    f32 func_800EEB40(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    typedef struct {
        u8 pad[0x34];
        f32 positions[10][3];
        u8 flags[0x19];
        u8 count;
    } DodgemData;
    s32 var_s0;
    DodgemData *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    for (var_s0 = 0; var_s0 < temp_v0->count; var_s0++) {
        if ((var_s0 != arg2) && (temp_v0->flags[var_s0] == 1) && (func_800EEB40(temp_v0->positions[var_s0], arg1) < 40000.0f)) {
            return 0;
        }
    }
    return 1;
}

void func_808004E4_chdodgemcontrol(Actor *arg0, s32 arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_801084B0(BtIntPtr, Actor **);
    typedef struct {
        u8 pad[0x34];
        f32 positions[10][3];
        u8 flags[10];
        u8 choices[10];
    } DodgemData;
    DodgemData *data;
    f32 position[3];
    f32 *destination;
    Actor *actor;

    actor = func_801084B0(0x37F, &arg0);
    data = func_80100094(arg0, 0);
    actor->unk3C = arg0->unk0;
    data->flags[arg1] = 1;
    data->choices[arg1] = func_80800350_chdodgemcontrol();
    actor->unk6C_0 = arg1;
    /* Preserve these address expressions for IDO's stack slots and scheduling. */
    destination = actor->position;
    do {
        func_808003B0_chdodgemcontrol((f32 *)((BtUIntPtr)position | 0));
    } while (!func_8080040C_chdodgemcontrol(arg0, (f32 *)((BtUIntPtr)position | 0), arg1));
    if (position && destination) {}
    destination = actor->position;
    func_800EE7F8(destination, position);
    if (((f32 *)((BtUIntPtr)position | 0))) {}
    func_800EE7F8(data->positions[arg1], destination);
}

s32 func_808005CC_chdodgemcontrol(s32 arg0) { switch (arg0) { case 0: return 0x2D; case 1: return 0x2D; case 2: return 0x2D; case 3: return 0x3C; default: return 0; } }

/* extern */

void func_8080061C_chdodgemcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    arg2 |= 6;
    switch (arg1) {
    case 0x10D9:
    case 0x10DA:
        func_800FC6B0(0x10);
        func_800FDC28(0);
        break;
    case 0x10D4:
    case 0x10D5:
    case 0x10D6:
    case 0x10EC:
    case 0x10EE:
    case 0x10F0:
        func_800FC6B0(0x16);
        func_800FDC28(0);
        break;
    case 0x10D7:
    case 0x10ED:
    case 0x10EF:
    case 0x10F1:
        func_800FC6B0(0x17);
        func_800FDC28(0);
        break;
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x22);
}

void func_808006CC_chdodgemcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void _gcgoto_entrypoint_1(u32 a0, u32 a1);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    s32 func_800D395C(void);
    void func_800DA3B8(s32, s32);
    s32 func_800EA05C(void);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void func_808019C4_chdodgemcontrol(Actor *, s32);
    typedef struct {
        u8 pad0[0xC2];
        u8 count;
        u8 unkC3;
        u8 unkC4;
        u8 unkC5;
    } DodgemData;
    s32 pad[2];
    s32 sp1C;
    DodgemData *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x10D9:
    case 0x10DA:
        _gcfrontend_entrypoint_10();
        break;
    case 0x10FC:
        func_8080061C_chdodgemcontrol(arg0, 0x10D3, 0);
        break;
    case 0x10D3:
    case 0x10EB:
        sp1C = func_808005CC_chdodgemcontrol(arg0->unk79_4);
        func_800CE8D8(0, (f32)sp1C, func_808005CC_chdodgemcontrol(arg0->unk79_4));
        func_800CE88C(0, 1);
        func_808019C4_chdodgemcontrol(arg0, 0);
        arg0->unk70_10 = 3;
        func_800FDC28(0xC);
        break;
    case 0x10D4:
        func_800DA3B8(0xA9, 1);
        _gcgoto_entrypoint_1(0xDD, 5);
        break;
    case 0x10D5:
        func_800DA3B8(0xAA, 1);
        _gcgoto_entrypoint_1(0xDD, 5);
        break;
    case 0x10D6:
        func_800DA3B8(0xB0, 1);
        _gcgoto_entrypoint_1(0xDD, 5);
        break;
    case 0xCEB:
        if (func_800D395C()) {
            if (arg2 == 1) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
        } else {
            if (arg2 == 1) {
                _gcgoto_entrypoint_1(func_800EA05C(), 1);
            } else {
                _gcgoto_entrypoint_1(0xDD, 5);
            }
        }
        break;
    case 0x10D7:
    case 0x10EC:
    case 0x10ED:
    case 0x10EE:
    case 0x10EF:
    case 0x10F0:
    case 0x10F1:
        func_8080061C_chdodgemcontrol(arg0, 0xCEB, 0x40);
        break;
    case 0x10BB:
    case 0x10BC:
    case 0x10BD:
        data->unkC4 = 1;
        break;
    }
}

s32 func_808008EC_chdodgemcontrol(Actor *arg0) { switch (arg0->unk79_4) { case 0: return 0x3C; case 1: return 0x32; case 2: return 0x28; default: return 0; } }

s32 func_80800938_chdodgemcontrol(u8 *arg0, s32 arg1, s32 arg2) {
    struct Control {
        u8 padding[0x79];
        BT_BITFIELD_ORDER(u8 state : 4, u8 other : 4);
        BT_BITFIELD_ORDER(u8 other : 4, u8 state : 4);
    };
    s32 _capod_entrypoint_13(BtIntPtr, BtIntPtr, s32, s32);
    s32 _capod_entrypoint_17(f32);
    void _subaddiemulti_entrypoint_4(s32);
    void func_800A54F8(s32);
    s16 func_800D211C(s32);
    s32 func_800D395C(void);
    s32 func_800DA9E4(s32, s32);
    s32 func_800EA05C(void);
    void *func_80100094(Actor *, u32);
    Actor *func_80801844_chdodgemcontrol(Actor *);
    void func_80801A3C_chdodgemcontrol(Actor *, s32, s32);
    u8 *data;
    s32 map;
    s32 i;
    u8 *p;
    volatile s16 *params;
    data = func_80100094((Actor *) arg0, 0);
    switch (arg1) {
    case 0xB:
        data[0xC3] = (0, 1);
        return 3;
    case 0xE:
        switch (((struct Control *) arg0)->state) {
        case 0:
            if (_capod_entrypoint_17(0.5f)) {
                func_80801A3C_chdodgemcontrol(arg0, 1, 2);
            }
            break;
        case 1:
            if (_capod_entrypoint_17(0.5f)) {
                func_80801A3C_chdodgemcontrol(arg0, 2, 2);
            }
            break;
        case 2:
            if (_capod_entrypoint_17(0.5f)) {
                func_80801A3C_chdodgemcontrol(arg0, 3, 2);
            }
            break;
        }
        return 3;
    case 0x49:
        arg0 = (u8 *) func_80801844_chdodgemcontrol((Actor *) arg0);
        map = func_800EA05C();
        switch (map) {
        case 0xDE:
            if (!arg2) {
            }
            break;
        case 0xDF:
            break;
        default:
            break;
        }
        switch (((struct Control *) arg0)->state) {
        case 0:
            goto check_flag;
        case 1:
            goto check_flag;
        case 2:
        check_flag:
            if ((!func_800DA9E4(((struct Control *) arg0)->state + 0x419, 1)) && (!func_800D395C())) {
                _capod_entrypoint_13(*((s32 *) arg0), 0, 1, 0x2020);
                data[0xC6] = 1;
            } else {
                data[0xC4] = 1;
                data[0xC3] = 1;
                func_800A54F8(0);
            }
            break;
        case 3:
            data[0xC4] = 1;
            data[0xC3] = 1;
            _subaddiemulti_entrypoint_4(0);
            break;
        }
        break;
    case 0x2E:
        params = (s16 *) (&arg2);
        func_808006CC_chdodgemcontrol(arg0, params[0], params[1]);
        return 1;
    case 0x30:
        params = (s16 *) (&arg2);
        switch (params[0]) {
        case 0x10FC:
            if (params[1] == 0) {
                return func_808008EC_chdodgemcontrol((Actor *) arg0);
            }
            return func_808005CC_chdodgemcontrol(((struct Control *) arg0)->state);
        case 0x10D9:
            return data[0xC1];
        case 0x10D4:
        case 0x10D5:
        case 0x10D6:
        case 0x10EC:
        case 0x10EE:
        case 0x10F0:
            return *((s32 *) (data + 0x10));
        case 0x10ED:
            return func_800D211C(0x8A);
        case 0x10EF:
            return func_800D211C(0x8B);
        case 0x10F1:
            return func_800D211C(0x8C);
        case 0x10D7:
            return func_808008EC_chdodgemcontrol((Actor *) arg0);
        }
        break;
    case 0x3D:
        if (arg2 == (-1)) {
            for (i = 0, p = data; i < data[0xC5]; i++, p++) {
                if (p[0xAC] == 0) {
                    func_808004E4_chdodgemcontrol(arg0, i);
                    break;
                }
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800CA0_chdodgemcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_808019C4_chdodgemcontrol(Actor *, s32);
    s32 func_800D2054(s32, s32, s32);
    void func_800FC6B0(u32);
    s32 _sumultiscore_entrypoint_2(s32 *, s32 *, s32 *, s32, s32);
    struct DodgemData {
        u8 pad0[0x10];
        s32 scores[4];
        s32 winners[4];
        u8 pad30[0x91];
        u8 winner;
        u8 count;
    } *data;
    s16 text;
    s32 ranks[4];
    s32 results[4];
    s32 winner;
    s32 i;

    data = func_80100094(arg0, 0);
    arg0->unk70_10 = 4;
    func_808019C4_chdodgemcontrol(arg0, 1);
    if (arg0->unk64_19) {
        switch (arg0->unk79_4) {
        case 0:
            text = func_800D2054(0, 0x8A, data->scores[0]) == 1 ? 0x10EC : 0x10ED;
            func_8080061C_chdodgemcontrol(arg0, text, 0);
            break;
        case 1:
            text = func_800D2054(0, 0x8B, data->scores[0]) == 1 ? 0x10EE : 0x10EF;
            func_8080061C_chdodgemcontrol(arg0, text, 0);
            break;
        case 2:
            text = func_800D2054(0, 0x8C, data->scores[0]) == 1 ? 0x10F0 : 0x10F1;
            func_8080061C_chdodgemcontrol(arg0, text, 0);
            break;
        }
    } else {
        switch (arg0->unk79_4) {
        case 0:
            if (data->scores[0] >= func_808008EC_chdodgemcontrol(arg0)) {
                text = 0x10D4;
                func_800D2054(0, 0x8A, data->scores[0]);
            } else {
                text = 0x10D7;
            }
            func_8080061C_chdodgemcontrol(arg0, text, 0);
            break;
        case 1:
            if (data->scores[0] >= func_808008EC_chdodgemcontrol(arg0)) {
                text = 0x10D5;
                func_800D2054(0, 0x8B, data->scores[0]);
            } else {
                text = 0x10D7;
            }
            func_8080061C_chdodgemcontrol(arg0, text, 0);
            break;
        case 2:
            if (data->scores[0] >= func_808008EC_chdodgemcontrol(arg0)) {
                text = 0x10D6;
                func_800D2054(0, 0x8C, data->scores[0]);
            } else {
                text = 0x10D7;
            }
            func_8080061C_chdodgemcontrol(arg0, text, 0);
            break;
        case 3:
            winner = _sumultiscore_entrypoint_2(data->scores, ranks, results, 0, data->count);
            for (i = 0; i < data->count; i++) {
                if (ranks[i] == 1) {
                    data->winners[i] = 1;
                } else {
                    data->winners[i] = 0;
                }
            }
            if (winner != 0) {
                text = 0x10D9;
                data->winner = winner;
                func_800FC6B0(0x16);
            } else {
                text = 0x10DA;
                func_800FC6B0(0x17);
            }
            func_8080061C_chdodgemcontrol(arg0, text, 0);
            break;
        }
    }
}

void func_80800FC4_chdodgemcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80804D20_chdodgemcontrol[];
    extern s32 D_80804D34_chdodgemcontrol[];
    s32 temp_a0;
    s32 *temp_v0;
    s32 *temp_v1;

    temp_v0 = func_80100094(arg0, 0);
    if ((arg0->unk70_10 == 3) && ((arg2 >= 0) || ((temp_v0 + arg1)[4] >= -arg2))) {
        temp_a0 = arg1 * 4;
        temp_v1 = (s32 *)((u8 *)temp_v0 + temp_a0);
        temp_v1[4] += arg2;
        if (arg2 > 0) {
            if (temp_a0 == 0) {
                func_8010D930(4, 0, arg0->position, &D_80804D34_chdodgemcontrol);
            }
        } else if (temp_a0 == 0) {
            func_8010D930(5, 0, arg0->position, &D_80804D20_chdodgemcontrol);
        }
    }
}

s32 func_80801084_chdodgemcontrol(f32 *arg0, f32 *arg1, f32 arg2) {
    f32 func_800DC178(f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    int func_800F0064(f32 *, f32, f32 *);
    extern struct dodgem_vector D_80804E0C_chdodgemcontrol;
    struct dodgem_vector sp4C;
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;
    f32 sp2C;

    if (func_800F0064(arg0, arg2, arg1) != 0) {
        sp4C = D_80804E0C_chdodgemcontrol;
        sp30 = arg1[1];
        sp2C = arg0[1];
        func_800EE7F8(sp40, arg0);
        func_800EE7F8(sp34, arg1);
        if ((arg1[0] == arg0[0]) && (arg1[2] == arg0[2])) {
            arg1[0] = func_800DC178(-5.0f, 5.0f) + arg1[0];
            arg1[2] = func_800DC178(-5.0f, 5.0f) + arg1[2];
        }
        sp4C.v[0] = arg0[0] - arg1[0];
        sp4C.v[1] = arg0[1] - arg1[1];
        sp4C.v[2] = arg0[2] - arg1[2];
        func_800EF368(sp4C.v, func_800EEF94(sp4C.v) + 5.0f);
        func_800EFB24(arg1, sp40, sp4C.v);
        func_800EE780(arg0, sp34, sp4C.v);
        arg1[1] = sp30;
        arg0[1] = sp2C;
        return 1;
    }
    return 0;
}

f32 func_80801214_chdodgemcontrol(s32 arg0) {
    extern DodgemValues D_80804E18_chdodgemcontrol;
    DodgemValues values = D_80804E18_chdodgemcontrol;
    return values.values[arg0];
}

void func_80801258_chdodgemcontrol(s32 arg0, f32 arg1[3]) {
    void func_800EE7F8(f32 *, f32 *);
    extern DodgemPositions D_80804E28_chdodgemcontrol;
    DodgemPositions values = D_80804E28_chdodgemcontrol;
    func_800EE7F8(arg1, values.values[arg0]);
}

/* extern */

void func_808012C8_chdodgemcontrol(Actor *arg0, s32 arg1) {
    void _chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    s32 _chintrotext_entrypoint_2(s32);
    s32 func_800D395C(void);
    if ((arg1 != 0) || (func_800D395C() != 0)) {
        arg0->unk64_19 = 1;
        _chintrotext_entrypoint_1(0x18B1, arg0->unk79_4 + 0x12, 0, 0);
        return;
    }
    arg0->unk64_19 = 0;
    _chintrotext_entrypoint_2(1);
}

void func_80801344_chdodgemcontrol(Actor *arg0) {
    void func_800D2748(s32, s32);

    switch (arg0->unk79_4) {
    case 0:
    case 1:
    case 2:
        func_800D2748(0xC3, 0x5B);
        break;
    case 3:
        func_800D2748(0xC3, 0x23);
        break;
    }
    func_800D2748(0xC4, 0x24);
    func_800D2748(0xC5, 0x25);
    func_800D2748(0xC6, 0x26);
}

void func_808013D0_chdodgemcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s16 func_800D211C(s32);
    s32 func_800D2054(s32, s32, s32);
    s32 func_800EA05C(void);
    s32 func_800DA298(s32);
    s32 func_800D0A9C(u32, u32);
    s32 func_800F6438(BtUIntPtr);
    void func_800F4CEC(BtIntPtr, u32);
    u8 _gcstatusDll_entrypoint_11(void);
    void func_808017F0_chdodgemcontrol(Actor *);
    void func_800BF744(s32, s32);
    extern s32 D_80804D00_chdodgemcontrol[];
    typedef struct {
        u8 pad0[0xC2];
        u8 count;
        u8 unkC3;
        u8 unkC4;
        u8 unkC5;
    } DodgemData;
    DodgemData *data;
    s32 i;

    data = func_80100094(arg0, 0);
    if (func_800D211C(0x8A) == 0) {
        func_800D2054(0, 0x8A, 3);
        func_800D2054(0, 0x8B, 3);
        func_800D2054(0, 0x8C, 3);
    }
    switch (func_800EA05C()) {
    case 0xDE:
        arg0->unk79_4 = 0;
        data->unkC5 = 3;
        func_808012C8_chdodgemcontrol(arg0, func_800DA298(0xAC));
        data->count = D_80804D00_chdodgemcontrol[arg0->unk79_4];
        break;
    case 0xDF:
        arg0->unk79_4 = 1;
        data->unkC5 = 3;
        func_808012C8_chdodgemcontrol(arg0, func_800DA298(0xAD));
        data->count = D_80804D00_chdodgemcontrol[arg0->unk79_4];
        break;
    case 0xE0:
        arg0->unk79_4 = 2;
        data->unkC5 = 3;
        func_808012C8_chdodgemcontrol(arg0, func_800D0A9C(0x16, 1));
        data->count = D_80804D00_chdodgemcontrol[arg0->unk79_4];
        break;
    case 0x186:
        for (i = 0; i != 8; i++) {
            if (func_800F6438(i)) {
                func_800F4CEC(i, 0);
            }
        }
        arg0->unk79_4 = 3;
        data->count = _gcstatusDll_entrypoint_11();
        data->unkC5 = 3;
        break;
    }
    if (data->unkC5 >= 11) {
        data->unkC5 = 10;
    }
    data->unkC3 = 0;
    func_808017F0_chdodgemcontrol(arg0);
    func_800BF744(1, 1);
    func_80801344_chdodgemcontrol(arg0);
}

void func_808015E8_chdodgemcontrol(Actor *arg0) {
    switch (arg0->unk79_4) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

void func_8080160C_chdodgemcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(s32);
    s32 _capod_entrypoint_14(void);
    void func_800A54F8(s32);
    void func_800BF744(s32, s32);
    typedef struct {
        u8 pad0[0x30];
        u8 ready[0x92];
        u8 count;
        u8 unkC3;
        u8 unkC4;
        u8 unkC5;
        u8 unkC6;
    } DodgemData;
    DodgemData *data;
    s32 i;
    s32 text;

    data = func_80100094(arg0, 0);
    if (func_800DA298(0x6AD) == 0) {
        for (i = 0; i < data->count; i++) {
            if (!data->ready[i]) {
                return;
            }
        }
        if (data->unkC3 && data->unkC4) {
            if (data->unkC6) {
                _capod_entrypoint_14();
            }
            switch (arg0->unk79_4) {
            case 0:
            case 1:
            case 2:
                func_800A54F8(0);
                break;
            case 3:
                break;
            }
            func_800BF744(1, 0);
            if (arg0->unk79_4 == 3) {
                text = 0x10EB;
            } else {
                text = !arg0->unk64_19 ? 0x10FC : 0x10D3;
            }
            func_8080061C_chdodgemcontrol(arg0, text, 0);
            arg0->unk70_10 = 2;
        }
    }
}

typedef struct {
    u8 pad0[0x64];
    BT_BITFIELD_ORDER(u32 pad64_30 : 2, u32 pad64_0 : 24);
    BT_BITFIELD_ORDER(u32 unk64_29 : 1, u32 unk64_24 : 1);
    BT_BITFIELD_ORDER(u32 unk64_27 : 2, u32 unk64_25 : 1);
    u32 unk64_26 : 1;
    BT_BITFIELD_ORDER(u32 unk64_25 : 1, u32 unk64_27 : 2);
    BT_BITFIELD_ORDER(u32 unk64_24 : 1, u32 unk64_29 : 1);
    BT_BITFIELD_ORDER(u32 pad64_0 : 24, u32 pad64_30 : 2);
    s32 pad68;
    BT_BITFIELD_ORDER(u32 pad6C_21 : 11, u32 unk6C_0 : 9);
    u32 unk6C_9 : 12;
    BT_BITFIELD_ORDER(u32 unk6C_0 : 9, u32 pad6C_21 : 11);
} DodgemControlActor;

void func_80801744_chdodgemcontrol(Actor *arg0, DodgemControlActor *arg1) {
    switch (arg0->unk79_4) {
    case 0:
    case 1:
    case 2:
        switch (arg1->unk6C_0) {
        case 0:
            arg1->unk64_29 = 1;
            arg1->unk64_27 = 0;
            return;
        case 1:
            arg1->unk64_24 = 1;
            return;
        }
        break;
    case 3:
        arg1->unk64_29 = 0;
        arg1->unk64_27 = arg1->unk6C_0;
        return;
    }
}

void func_808017F0_chdodgemcontrol(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    struct {
        s32 words[12];
        u8 bytes[0x92];
        u8 count;
    } *temp_v0;
    s32 var_v1;

    temp_v0 = func_80100094(arg0, 0U);
    for (var_v1 = 0; var_v1 < temp_v0->count; var_v1++) {
        temp_v0->bytes[var_v1] = 0;
        temp_v0->words[var_v1] = 0;
    }
}

/* extern */

Actor *func_80801844_chdodgemcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_801084B0(BtIntPtr, Actor **);
    void func_80108944(Actor *, Actor *);
    s32 func_80801928_chdodgemcontrol(Actor *, s32);
    struct {
        Unk80132ED0 *words[12];
        u8 bytes[0x92];
        u8 count;
    } *temp_v0;
    Unk80132ED0 **var_s2;
    s32 var_s1;
    u32 temp_s0;
    u8 temp_s4;
    Actor *temp_v0_2;
    void *child;

    temp_s0 = arg0->unk79_4;
    temp_v0 = func_80100094(arg0, 0U);
    temp_s4 = temp_v0->count;
    var_s1 = 0;
    var_s2 = temp_v0->words;
    if ((s32) temp_s4 > 0) {
        do {
            temp_v0_2 = func_801084B0(0x305, &arg0);
            temp_v0_2->unk3C = arg0->unk0;
            *var_s2 = temp_v0_2->unk0;
            temp_v0_2->unk79_4 = temp_s0;
            func_80801928_chdodgemcontrol(arg0, var_s1);
            func_80108944(temp_v0_2, arg0);
            child = temp_v0_2;
            func_80801744_chdodgemcontrol(arg0, child);
            var_s1 += 1;
            var_s2++;
        } while (var_s1 != temp_s4);
    }
    return arg0;
}

s32 func_80801928_chdodgemcontrol(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    struct {
        Unk80132ED0 *markers[4];
        s32 state[8];
        s8 active[4];
    } *data;
    Actor *actor;

    data = func_80100094(arg0, 0U);
    actor = func_80106790(data->markers[arg1]);
    func_80801258_chdodgemcontrol(arg1, actor->position);
    actor->rotation[1] = func_80801214_chdodgemcontrol(arg1);
    actor->unk54 = actor->rotation[1];
    actor->unk6C_0 = arg1;
    data->state[arg1] = 0;
    data->active[arg1] = 1; BT_NATIVE_ONLY(return (BtIntPtr) actor;)
}    typedef struct { u8 pad0[0xC2]; u8 unkC2; } Objdodgemcontrol_func_808019C4_chdodgemcontrol_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_808019C4_chdodgemcontrol(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80801A3C_chdodgemcontrol(Actor *, s32, s32);
    s32 var_s0;
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    var_s0 = 0;
    if ((s32) (((Objdodgemcontrol_func_808019C4_chdodgemcontrol_temp_v0 *)temp_v0)->unkC2) > 0) {
        do {
            func_80801A3C_chdodgemcontrol(arg0, var_s0, arg1);
            var_s0 += 1;
        } while (var_s0 < (s32) (((Objdodgemcontrol_func_808019C4_chdodgemcontrol_temp_v0 *)temp_v0)->unkC2));
    }
}

/* extern */

void func_80801A3C_chdodgemcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    s32 func_808042A4_chdodgemcontrol(BtIntPtr, s32);
    s32 temp_t6;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    temp_t6 = arg1 * 4;
    if (*(s32 *)(temp_v0 + temp_t6) != 0) {
        func_808042A4_chdodgemcontrol(*(s32 *)(temp_v0 + temp_t6), arg2);
    }
}

void func_80801A8C_chdodgemcontrol(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_800D24E8(s32, s32, u32);
    void func_800D2770(s32, s32);
    s32 func_800D28A0(s32);
    struct DodgemData {
        s32 actors[4];
        s32 values[4];
        s32 flags[4];
        u8 pad30[0x90];
        u8 initialized;
        u8 unkC1;
        u8 count;
    } *data;
    s32 count;
    s32 i;
    s32 id;

    data = func_80100094(arg0, 0U);
    switch (arg0->unk79_4) {
        case 0:
        case 1:
        case 2:
            count = 1;
            break;
        case 3:
            count = data->count;
            break;
    }
    i = 0;
    if (count > 0) {
        do {
            id = i + 0xC3;
            if (data->initialized == 0) {
                id = i + 0xC3;
                func_800D2770(id, 0);
            } else {
                func_800D24E8(id, data->values[i], 0U);
            }
            if (arg1 && data->flags[i]) {
                func_800D28A0(id);
            }
            i++;
        } while (i != count);
    }
    data->initialized = 1;
}

void func_80801B94_chdodgemcontrol(BtIntPtr arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    BtIntPtr func_800B53A4(s32);
    s32 func_800BA22C(BtIntPtr, s32);
    BT_IDO_ONLY(s32 func_800BA3FC(BtIntPtr, s32);) BT_NATIVE_ONLY(void func_800BA3FC(BtIntPtr, s32);)
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, s32 *, s32 *, s32, s32 *);)
    s32 func_80103DFC(BtIntPtr, s32 *);
    extern s32 D_80804E78_chdodgemcontrol[];
    extern s32 D_80804EA4_chdodgemcontrol[];
    BtIntPtr sp2C;
    s32 sp20[3];

    sp2C = func_800B53A4(0xC);
    func_80103DFC(arg0, sp20);
    func_800BABB8(sp2C, BT_NATIVE_ONLY((f32 *))(sp20), BT_NATIVE_ONLY((f32 *))(sp20), BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))&D_80804E78_chdodgemcontrol);
    func_800BA3FC(sp2C, arg1);
    func_800BA22C(sp2C, 0xC);
    _subaddieaudioquick_entrypoint_2(arg0, sp20, &D_80804EA4_chdodgemcontrol);
}

void func_80801C18_chdodgemcontrol(Actor *arg0, BtIntPtr arg1, s32 arg2) {
    void _subaddiefade_entrypoint_5(void *arg0);
    func_80102424(arg0, arg2);
    if ((arg0->unk70_10) == 3) {
        _subaddiefade_entrypoint_5(arg0);
    }
}

void func_80801C60_chdodgemcontrol(Actor *arg0) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    void _subaddiefade_entrypoint_6(Actor *, s32);
    void func_800C8E84(s32, u32 *);
    f32 func_800D8FF8(void);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s16 D_80804ECC_chdodgemcontrol[];
    extern struct DodgemRGB D_80804EB4_chdodgemcontrol;
    extern struct DodgemRGB D_80804EC0_chdodgemcontrol;
    struct DodgemData {
        u8 pad0[0xAC];
        u8 states[10];
        u8 types[14];
    };
    Actor *sp4C;
    struct DodgemData *sp48;

    sp4C = func_80106790(arg0->unk3C);
    sp48 = func_80100094(sp4C, 0);
    switch (arg0->unk70_10) {
        case 1:
            _subaddiefade_entrypoint_6(arg0, 7);
            if (_subaddiefade_entrypoint_0(arg0) == 255) {
                func_80801C18_chdodgemcontrol(arg0, (BtIntPtr)sp4C, 2);
            }
            break;
        case 2:
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= func_800D8FF8();
            } else {
                func_80801C18_chdodgemcontrol(arg0, (BtIntPtr)sp4C, 3);
            }
            break;
        case 3:
            _subaddiefade_entrypoint_6(arg0, -7);
            break;
    }
    switch (arg0->unk70_10) {
        case 3: {
            struct DodgemRGB color = D_80804EB4_chdodgemcontrol;
            color.rgb[sp48->types[arg0->unk6C_0]] = _subaddiefade_entrypoint_0(arg0);
            func_800C8E84(*(s32 *)&arg0->unk50, color.rgb);
            if (_subaddiefade_entrypoint_0(arg0) == 0) {
                sp48->states[arg0->unk6C_0] = 0;
                func_800FFAB0(arg0);
            }
            break;
        }
        case 1: {
            struct DodgemRGB color = D_80804EC0_chdodgemcontrol;
            color.rgb[sp48->types[arg0->unk6C_0]] = _subaddiefade_entrypoint_0(arg0);
            func_800C8E84(*(s32 *)&arg0->unk50, color.rgb);
            break;
        }
    }
    if ((s32)arg0->unk70_10 < 3) {
        switch (sp48->states[arg0->unk6C_0]) {
            case 2:
                func_80801B94_chdodgemcontrol((BtIntPtr)arg0, D_80804ECC_chdodgemcontrol[sp48->types[arg0->unk6C_0]]);
                sp48->states[arg0->unk6C_0] = 0;
                func_800FFAB0(arg0);
                break;
            case 3:
                sp48->states[arg0->unk6C_0] = 0;
                func_800FFAB0(arg0);
                break;
        }
    }
}    typedef struct { u8 pad0[0x50]; s32 unk50; } Objdodgemcontrol_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80801F00_chdodgemcontrol(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (((Objdodgemcontrol_arg0 *)arg0)->unk50);
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
    }
}

void func_80801F2C_chdodgemcontrol(Actor *arg0)
{
  void _subaddiefade_entrypoint_2(void *arg0);
  s32 func_800C8A98(void);
  void func_800C8CB8(s32, f32 *);
  void func_800C8E54(s32, f32, f32);
  void func_800C8FB0(s32, u32, u32, u32);
  void *func_80100094(Actor *, u32);
  s32 func_801032B0(Actor *, u16, u16);
  Actor *func_80106790(Unk80132ED0 *);
  extern u16 D_80804ED4_chdodgemcontrol[];
  struct DodgemData
  {
    u8 pad0[0xB6];
    u8 types[0xE];
    u8 unkC4;
    u8 unkC5;
    u8 unkC6;
  };
  s32 pad;
  struct DodgemData *data;
  s32 handle;
  data = func_80100094(func_80106790(arg0->unk3C), 0);
  arg0->scale = 0.8f;
  func_801032B0(arg0, D_80804ED4_chdodgemcontrol[data->types[arg0->unk6C_0]], arg0->unk0->unk16);
  handle = func_800C8A98();
  *((s32 *) (&arg0->unk50)) = handle;
  func_800C8E54(handle, arg0->scale * 500.0f, arg0->scale * 800.0f);
  func_800C8FB0(*((s32 *) (&arg0->unk50)), 0, 0, 0);
 do { func_800C8CB8(*((s32 *) (&arg0->unk50)), arg0->position); _subaddiefade_entrypoint_2(arg0); } while (0);
  switch ((s32) arg0->unk6C_0)
  {
    case 0:
      arg0->unk58 = 6.0f;
      break;

    case 1:
      arg0->unk58 = 5.0f;
      break;

    case 2:
      arg0->unk58 = 4.0f;
      break;

  }

  data->unkC4 = 0;
  data->unkC6 = 0;
}

OSThread *chdodgemcontrol_entrypoint_1(void)
{
    extern BtFnWord D_80804EDC_chdodgemcontrol[];

    return (OSThread *) D_80804EDC_chdodgemcontrol;
}

s32 func_8080207C_chdodgemcontrol(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    extern s32 D_80804F64_chdodgemcontrol[];
    s32 result;
    if (arg1 == 0x1F) {
        func_801015D0(arg0);
        func_800DF744(3, D_80804F64_chdodgemcontrol[arg0->unk6C_0]);
        func_800DF744(4, D_80804F64_chdodgemcontrol[arg0->unk6C_0]);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

void func_80802104_chdodgemcontrol(Actor *arg0) {
    void func_80018820(s32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 *data;

    data = func_80100094(arg0, 0);
    if (!(data[7] > 0.0f)) {
        data[7] = 1.5f;
        if (arg0->unk6C_0 == 0 || arg0->unk64_29) {
            func_80018820(arg0->unk6C_0, 0.5f, 1.0f);
        }
    }
}

void func_80802180_chdodgemcontrol(Actor *arg0) {
    f32 func_800138D0(f32);
    f32 func_800D8FF8(void);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    f32 func_800F1DCC(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, f32);
    void func_80802104_chdodgemcontrol(Actor *);
    void func_808039B8_chdodgemcontrol(Actor *);
    f32 func_808046EC_chdodgemcontrol(Actor *);
    f32 mlAbsF(f32);
    f32 *sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    sp8C = func_80100094(arg0, 0);
    sp88 = func_800D8FF8();
    sp84 = func_800F1DCC(arg0->rotation[1], arg0->unk54);
    *(f32 *)((u8 *)arg0 + 0x24) *= 0.95f;
    sp84 = mlAbsF(func_800138D0(sp84));
    sp80 = func_808046EC_chdodgemcontrol(arg0) * (1.1f - sp84) * sp88;
    sp8C[3] *= 0.8f;
    func_800EEB9C(sp74, arg0->rotation[1], -40.0f);
    func_800EF04C(&arg0->position[0], sp74);
    if (func_80102CF4(arg0, sp80) == 0) {
        func_80102B2C(arg0, sp80);
    }
    arg0->rotation[1] += sp8C[3];
    func_800EEB9C(sp74, arg0->rotation[1], 40.0f);
    func_800EF04C(&arg0->position[0], sp74);
    func_800EEB9C(sp5C, arg0->rotation[1], 48.75f);
    func_800EF04C(sp5C, &arg0->position[0]);
    func_800EEB9C(sp68, arg0->rotation[1], *(f32 *)((u8 *)arg0 + 0x24));
    func_800EF04C(sp68, sp8C);
    if (sp68[0] < 0.0f) {
        sp68[0] = -sp68[0];
    }
    if (sp68[2] < 0.0f) {
        sp68[2] = -sp68[2];
    }
    if (arg0->position[0] < -629.0f) {
        arg0->position[0] = -629.0f;
        func_800EEB9C(sp8C, 90.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[0] < -655.0f) {
        sp5C[0] = -655.0f;
        func_800EEB9C(sp50, arg0->rotation[1], 48.75f);
        arg0->position[0] = sp5C[0] - sp50[0];
        func_800EEB9C(sp8C, 90.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (arg0->position[0] > 629.0f) {
        arg0->position[0] = 629.0f;
        func_800EEB9C(sp8C, 270.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[0] > 655.0f) {
        sp5C[0] = 655.0f;
        func_800EEB9C(sp44, arg0->rotation[1], 48.75f);
        arg0->position[0] = sp5C[0] - sp44[0];
        func_800EEB9C(sp8C, 270.0f, sp68[0] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (arg0->position[2] > 629.0f) {
        arg0->position[2] = 629.0f;
        func_800EEB9C(sp8C, 180.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[2] > 655.0f) {
        sp5C[2] = 655.0f;
        func_800EEB9C(sp38, arg0->rotation[1], 75.0f);
        arg0->position[2] = sp5C[2] - sp38[2];
        func_800EEB9C(sp8C, 180.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (arg0->position[2] < -629.0f) {
        arg0->position[2] = -629.0f;
        func_800EEB9C(sp8C, 0.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    if (sp5C[2] < -655.0f) {
        sp5C[2] = -655.0f;
        func_800EEB9C(sp2C, arg0->rotation[1], 48.75f);
        arg0->position[2] = sp5C[2] - sp2C[2];
        func_800EEB9C(sp8C, 0.0f, sp68[2] * 1.25f);
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        func_80802104_chdodgemcontrol(arg0);
    }
    func_800EEB9C((f32 *)((u8 *)arg0 + 0x28), arg0->rotation[1], *(f32 *)((u8 *)arg0 + 0x24));
    func_800EF04C((f32 *)((u8 *)arg0 + 0x28), sp8C);
    func_800EF334((f32 *)((u8 *)arg0 + 0x28), sp88);
    func_800EF04C(&arg0->position[0], (f32 *)((u8 *)arg0 + 0x28));
    func_800EF334(sp8C, 0.7f);
    if (sp8C[6] != 0.0f) {
        sp8C[6] = sp8C[6] - sp88;
    }
    func_808039B8_chdodgemcontrol(arg0);
}

s32 func_808026D0_chdodgemcontrol(BtIntPtr arg0) {
    BtIntPtr func_80104248();
    s32 anctrl_setPlaybackType(BtIntPtr, s32);
    s32 anctrl_start(BtIntPtr);
    void func_8008B188(void *arg0, s32 arg1);
    anctrl_setPlaybackType(func_80104248(), 1);
    func_8008B188(func_80104248(arg0), 1);
    return anctrl_start(func_80104248(arg0));
}

/* extern */

void func_80802720_chdodgemcontrol(BtIntPtr arg0) {
    s32 anctrl_setIndex(BtIntPtr, s32);
    s32 func_80101CDC(BtIntPtr, s32);
    BtIntPtr func_80104248();
    s32 func_808026D0_chdodgemcontrol(BtIntPtr);
    anctrl_setIndex(func_80104248(), 0x105);
    func_80101CDC(arg0, 0x4B189680);
    func_808026D0_chdodgemcontrol(arg0);
}

/* extern */

void func_80802764_chdodgemcontrol(Actor *arg0) {
    s32 anctrl_setIndex(BtIntPtr, s32);
    s32 func_80101CDC(BtIntPtr, s32);
    BtIntPtr func_80104248();
    s32 func_808026D0_chdodgemcontrol(BtIntPtr);
    s32 func_808000B8_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x10B);
    func_80101CDC((BtIntPtr)arg0, 0x3F666666);
    func_808026D0_chdodgemcontrol((BtIntPtr)arg0);
    if (arg0->unk64_20) {
        func_808000B8_chdodgemcontrol(0);
    }
}

/* extern */

void func_808027C4_chdodgemcontrol(BtIntPtr arg0) {
    struct Flags {
        u8 pad[0x64];
        BT_BITFIELD_ORDER(u32 : 11, u32  : 20);
        u32 active : 1;
        BT_BITFIELD_ORDER(u32 : 20, u32  : 11);
    };
    s32 anctrl_setIndex(BtIntPtr, s32);
    s32 func_80101CDC(BtIntPtr, s32);
    BtIntPtr func_80104248();
    s32 func_808000B8_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x108);
    func_80101CDC(arg0, 0x3F666666);
    func_808026D0_chdodgemcontrol(arg0);
    if (((struct Flags *)arg0)->active) {
        func_808000B8_chdodgemcontrol(1);
    }
}

/* extern */

void func_80802824_chdodgemcontrol(Actor *arg0) {
    s32 anctrl_setIndex(BtIntPtr, s32);
    s32 func_80101CDC(BtIntPtr, s32);
    BtIntPtr func_80104248();
    s32 func_808026D0_chdodgemcontrol(BtIntPtr);
    s32 func_808000B8_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x109);
    func_80101CDC((BtIntPtr)arg0, 0x3F666666);
    func_808026D0_chdodgemcontrol((BtIntPtr)arg0);
    if (arg0->unk64_20) {
        func_808000B8_chdodgemcontrol(2);
    }
}

/* extern */

void func_80802884_chdodgemcontrol(Actor *arg0) {
    s32 anctrl_setIndex(BtIntPtr, s32);
    s32 func_80101CDC(BtIntPtr, s32);
    BtIntPtr func_80104248();
    s32 func_808026D0_chdodgemcontrol(BtIntPtr);
    s32 func_808000B8_chdodgemcontrol(s32);
    anctrl_setIndex(func_80104248(), 0x10A);
    func_80101CDC((BtIntPtr)arg0, 0x3F666666);
    func_808026D0_chdodgemcontrol((BtIntPtr)arg0);
    if (arg0->unk64_20) {
        func_808000B8_chdodgemcontrol(3);
    }
}

void func_808028E4_chdodgemcontrol(BtIntPtr arg0) {
    struct Flags {
        u8 pad[0x64];
        BT_BITFIELD_ORDER(u32 : 11, u32  : 20);
        u32 active : 1;
        BT_BITFIELD_ORDER(u32 : 20, u32  : 11);
    };
    s32 anctrl_isStopped(BtIntPtr);
    s32 anctrl_setIndex(BtIntPtr, s32);
    s32 anctrl_setPlaybackType(BtIntPtr, s32);
    s32 anctrl_start(BtIntPtr);
    void func_8008B188(void *arg0, s32 arg1);
    s32 func_8008B28C(void *arg0);
    void func_800904C8(s32);
    f32 func_800F1DCC(f32, f32);
    s32 func_80101CDC(BtIntPtr, s32);
    s32 func_801022E4(BtIntPtr);
    BtIntPtr func_80104248();
    f32 difference;

    difference = func_800F1DCC(*(f32 *)(arg0 + 0x48), *(f32 *)(arg0 + 0x54));
    if (((struct Flags *)arg0)->active) {
        if (difference > 10.0f) {
            func_800904C8(0x75);
        } else if (difference < -10.0f) {
            func_800904C8(0x76);
        } else {
            func_800904C8(0x74);
        }
    } else if (difference > 10.0f) {
        switch (func_801022E4(arg0)) {
        case 0x105:
            anctrl_setIndex(func_80104248(arg0), 0x106);
            func_80101CDC(arg0, 0x3F000000);
            anctrl_setPlaybackType(func_80104248(arg0), 1);
            func_8008B188(func_80104248(arg0), 1);
            anctrl_start(func_80104248(arg0));
            break;
        case 0x107:
            if (func_8008B28C(func_80104248(arg0))) {
                func_8008B188(func_80104248(arg0), 0);
                func_80101CDC(arg0, 0x40400000);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x108:
        case 0x109:
        case 0x10A:
        case 0x10B:
            if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        }
    } else if (difference < -10.0f) {
        switch (func_801022E4(arg0)) {
        case 0x105:
            anctrl_setIndex(func_80104248(arg0), 0x107);
            func_80101CDC(arg0, 0x3F000000);
            anctrl_setPlaybackType(func_80104248(arg0), 1);
            func_8008B188(func_80104248(arg0), 1);
            anctrl_start(func_80104248(arg0));
            break;
        case 0x106:
            if (func_8008B28C(func_80104248(arg0))) {
                func_80101CDC(arg0, 0x40400000);
                func_8008B188(func_80104248(arg0), 0);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x108:
        case 0x109:
        case 0x10A:
        case 0x10B:
            if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        }
    } else {
        switch (func_801022E4(arg0)) {
        case 0x105:
            break;
        case 0x106:
            if (func_8008B28C(func_80104248(arg0))) {
                func_80101CDC(arg0, 0x40400000);
                func_8008B188(func_80104248(arg0), 0);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x107:
            if (func_8008B28C(func_80104248(arg0))) {
                func_80101CDC(arg0, 0x40400000);
                func_8008B188(func_80104248(arg0), 0);
            } else if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        case 0x108:
        case 0x109:
        case 0x10A:
        case 0x10B:
            if (anctrl_isStopped(func_80104248(arg0))) {
                func_80802720_chdodgemcontrol(arg0);
            }
            break;
        }
    }
}

void func_80802D04_chdodgemcontrol(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    s32 _subaddiejoy_entrypoint_2(void *arg0, s32 arg1, BtIntPtr arg2);
    s32 anctrl_isStopped(BtIntPtr);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C4B70(s32);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800F11E4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    BtIntPtr func_80104248();
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    void func_80803200_chdodgemcontrol(Actor *);
    void func_8080349C_chdodgemcontrol(Actor *);
    void func_808037C8_chdodgemcontrol(Actor *);
    void func_8080422C_chdodgemcontrol(BtIntPtr, s32);
    f32 func_8080458C_chdodgemcontrol(Actor *);
    f32 func_8080460C_chdodgemcontrol(Actor *);
    void func_8080476C_chdodgemcontrol(Actor *);
    extern u32 D_80804D10_chdodgemcontrol[];
    extern s32 D_80804D48_chdodgemcontrol[];
    extern s32 D_80804D5C_chdodgemcontrol[];
    extern s32 D_80804D74_chdodgemcontrol[];
    extern s32 D_80804D8C_chdodgemcontrol[];
    extern s32 D_80804DA4_chdodgemcontrol[];
    extern f32 D_80804F74_chdodgemcontrol[];
    extern f32 D_80804F84_chdodgemcontrol[];
    extern f32 D_80804F94_chdodgemcontrol[];
    f32 *data;
    f32 dt;
    f32 sampleRate;
    f32 joy;

    data = func_80100094(arg0, 0);
    dt = func_800D8FF8();
    if (data[7] >= 0.0f) {
        data[7] -= dt;
    }
    if (((f32 *)arg0->actorData)[3] > 10.0f) {
        sampleRate = func_800F11E4(((f32 *)arg0->actorData)[3],
            func_8080460C_chdodgemcontrol(arg0) * 0.1f,
            func_8080460C_chdodgemcontrol(arg0), 2000.0f, 15000.0f);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_80804D10_chdodgemcontrol);
        func_800C31DC(arg0->unk5F, func_800F11E4(((f32 *)arg0->actorData)[3],
            func_8080460C_chdodgemcontrol(arg0) * 0.5f,
            func_8080460C_chdodgemcontrol(arg0), 0.85f, 1.1f));
        func_800C3058(arg0->unk5F, (s32)sampleRate);
        if (func_800DC0C0() < 0.01f) {
            func_800C4B70((s32)sampleRate);
            func_8010D930(8, 0, arg0->position, &D_80804DA4_chdodgemcontrol);
        }
    }
    if (arg0->unk64_20) {
        func_80800044_chdodgemcontrol((f32 *)arg0);
    }
    switch (arg0->unk70_10) {
    case 4:
        ((f32 *)arg0->actorData)[3] *= 0.8f;
        break;
    case 3:
        arg0->unk54 = _subaddiejoy_entrypoint_2(arg0, (s32)arg0->rotation[1], &joy);
        if (((f32 *)arg0->actorData)[3] < func_8080460C_chdodgemcontrol(arg0)) {
            ((f32 *)arg0->actorData)[3] += joy * func_8080458C_chdodgemcontrol(arg0);
        }
        func_80802180_chdodgemcontrol(arg0);
        if (!arg0->unk64_29) {
            arg0->unk70_10 = 2;
        }
        func_808028E4_chdodgemcontrol((BtIntPtr)arg0);
        break;
    case 2:
        if (arg0->unk64_29) {
            arg0->unk70_10 = 3;
        }
        if (data[4] <= 0.0f) {
            func_8080476C_chdodgemcontrol(arg0);
            if (((f32 *)arg0->actorData)[3] < func_8080460C_chdodgemcontrol(arg0)) {
                ((f32 *)arg0->actorData)[3] += func_8080458C_chdodgemcontrol(arg0);
            }
            if (data[5] > 0.0f) {
                data[5] -= dt;
            } else {
                arg0->unk50 -= dt;
            }
        } else {
            data[4] -= dt;
            if (data[5] > 0.0f) {
                data[5] -= dt;
                if (((f32 *)arg0->actorData)[3] < func_8080460C_chdodgemcontrol(arg0) * 0.5f) {
                    ((f32 *)arg0->actorData)[3] += func_8080458C_chdodgemcontrol(arg0);
                }
            } else {
                func_8080349C_chdodgemcontrol(arg0);
                func_808037C8_chdodgemcontrol(arg0);
                func_80803200_chdodgemcontrol(arg0);
            }
        }
        func_80802180_chdodgemcontrol(arg0);
        func_808028E4_chdodgemcontrol((BtIntPtr)arg0);
        break;
    case 5:
        if (func_80101E14(arg0, 0.7283f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804D48_chdodgemcontrol);
        }
        if (func_80101E4C(arg0, &D_80804F74_chdodgemcontrol)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804D5C_chdodgemcontrol);
        }
        if (anctrl_isStopped(func_80104248(arg0))) {
            func_8080422C_chdodgemcontrol((BtIntPtr)arg0, 4);
        }
        break;
    case 6:
        if (func_80101E4C(arg0, &D_80804F84_chdodgemcontrol)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804D74_chdodgemcontrol);
        }
        if (anctrl_isStopped(func_80104248(arg0))) {
            func_8080422C_chdodgemcontrol((BtIntPtr)arg0, 4);
        }
        break;
    case 7:
        if (func_80101E4C(arg0, &D_80804F94_chdodgemcontrol)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804D8C_chdodgemcontrol);
        }
        if (func_80101E14(arg0, 0.39f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804D48_chdodgemcontrol);
        }
        if (anctrl_isStopped(func_80104248(arg0))) {
            func_8080422C_chdodgemcontrol((BtIntPtr)arg0, 4);
        }
        break;
    }
}

void func_80803200_chdodgemcontrol(Actor *arg0) {
    f32 func_800DC0C0(void);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    int func_800F0064(f32 *, f32, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 func_8080458C_chdodgemcontrol(Actor *);
    f32 func_8080460C_chdodgemcontrol(Actor *);
    struct DodgemActorData { f32 pad[3]; f32 speed; };
    struct DodgemState { u8 pad[0x10]; f32 collision; f32 timer; };
    struct DodgemData { u8 pad[0xC2]; u8 count; };
    Actor *other;
    Actor *controller;
    s32 i;
    struct DodgemState *state;
    struct DodgemData *data;
    f32 sp80[3];

    state = func_80100094(arg0, 0);
    controller = func_80106790(arg0->unk3C);
    data = func_80100094(controller, 0);
    for (i = 0; i < data->count; i++) {
        if (i != arg0->unk6C_0) {
            other = func_8080000C_chdodgemcontrol(controller, i);
            func_800EEB9C(sp80, arg0->rotation[1] - 145.0f, 325.0f);
            func_800EF04C(sp80, arg0->position);
            if (func_800F0064(sp80, 110.0f, other->position)) {
                state->collision = 1.0f;
                if (func_800DC0C0() < 0.5f) {
                    arg0->unk54 = arg0->rotation[1] - 65.0f;
                } else {
                    arg0->unk54 = arg0->rotation[1] + 65.0f;
                }
                if (((struct DodgemActorData *)arg0->actorData)->speed < func_8080460C_chdodgemcontrol(arg0)) {
                    ((struct DodgemActorData *)arg0->actorData)->speed += func_8080458C_chdodgemcontrol(arg0);
                }
                state->timer = 0.25f;
            }
            func_800EEB9C(sp80, arg0->rotation[1] + 145.0f, 325.0f);
            func_800EF04C(sp80, arg0->position);
            if (func_800F0064(sp80, 110.0f, other->position)) {
                state->collision = 1.0f;
                if (func_800DC0C0() < 0.5f) {
                    arg0->unk54 = arg0->rotation[1] - 65.0f;
                } else {
                    arg0->unk54 = arg0->rotation[1] + 65.0f;
                }
                if (((struct DodgemActorData *)arg0->actorData)->speed < func_8080460C_chdodgemcontrol(arg0)) {
                    ((struct DodgemActorData *)arg0->actorData)->speed += func_8080458C_chdodgemcontrol(arg0);
                }
                state->timer = 0.25f;
            }
        }
    }
}

void func_8080349C_chdodgemcontrol(Actor *arg0) {
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    int func_800F0064(f32 *, f32, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 func_8080458C_chdodgemcontrol(Actor *);
    f32 func_8080460C_chdodgemcontrol(Actor *);
    struct DodgemActorData { f32 pad[3]; f32 speed; f32 pad10[3]; f32 target; };
    struct DodgemState { u8 pad[0x10]; f32 collision; f32 timer; };
    struct DodgemData { u8 pad[0xC2]; u8 count; };
    Actor *other;
    Actor *controller;
    s32 i;
    struct DodgemState *state;
    struct DodgemData *data;
    f32 sp80[3];
    f32 value;

    state = func_80100094(arg0, 0);
    controller = func_80106790(arg0->unk3C);
    data = func_80100094(controller, 0);
    for (i = 0; i < data->count; i++) {
        if (i != arg0->unk6C_0 && (state->collision > 0.0f || (f32)i != ((struct DodgemActorData *)arg0->actorData)->target)) {
            other = func_8080000C_chdodgemcontrol(controller, i);
            func_800EEB9C(sp80, arg0->rotation[1] + 20.0f, 325.0f);
            func_800EF04C(sp80, arg0->position);
            if (func_800F0064(sp80, 150.0f, other->position)) {
                state->collision = 1.0f;
                arg0->unk54 = arg0->rotation[1] - 65.0f;
                if (func_8080460C_chdodgemcontrol(arg0) * 0.25f < ((struct DodgemActorData *)arg0->actorData)->speed) {
                    value = 2.0f;
                    ((struct DodgemActorData *)arg0->actorData)->speed = ((struct DodgemActorData *)arg0->actorData)->speed - (func_8080458C_chdodgemcontrol(arg0) * value);
                }
                state->timer = 0.25f;
            }
            func_800EEB9C(sp80, arg0->rotation[1] - 20.0f, 325.0f);
            func_800EF04C(sp80, arg0->position);
            if (func_800F0064(sp80, 150.0f, other->position)) {
                state->collision = 1.0f;
                arg0->unk54 = arg0->rotation[1] + 65.0f;
                if (func_8080460C_chdodgemcontrol(arg0) * 0.25f < ((struct DodgemActorData *)arg0->actorData)->speed) {
                    value = 2.0f;
                    ((struct DodgemActorData *)arg0->actorData)->speed = ((struct DodgemActorData *)arg0->actorData)->speed - (func_8080458C_chdodgemcontrol(arg0) * value);
                }
                state->timer = 0.25f;
            }
        }
    }
}

/* extern */

void func_8080372C_chdodgemcontrol(Actor *arg0, f32 arg1, f32 arg2) {
    f32 func_800F1DCC(f32, f32);
    f32 sp1C;
    f32 temp_f0;
    f32 var_f12;

    sp1C = func_800F1DCC(arg0->rotation[1], arg1);
    temp_f0 = func_800F1DCC(arg0->rotation[1], arg2);
    var_f12 = temp_f0;
    if (sp1C < 0.0f) {
        sp1C = -sp1C;
    }
    if (temp_f0 < 0.0f) {
        var_f12 = -temp_f0;
    }
    if (sp1C < var_f12) {
        arg0->unk54 = arg1;
        return;
    }
    arg0->unk54 = arg2;
}

void func_808037C8_chdodgemcontrol(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    f32 func_80102D78(Actor *, f32 *);
    f32 func_8080458C_chdodgemcontrol(Actor *);
    f32 func_8080460C_chdodgemcontrol(Actor *);
    extern struct DodgemPosition D_80804FA0_chdodgemcontrol;
    f32 *sp4C;
    f32 scale;
    struct DodgemPosition sp3C;
    f32 sp38;
    s32 pad34;
    f32 sp30;

    sp4C = func_80100094(arg0, 0);
    scale = func_800DC178(0.6f, 0.75f);
    if (720.0f * scale < arg0->position[0] ||
        arg0->position[0] < -720.0f * scale ||
        720.0f * scale < arg0->position[2] ||
        arg0->position[2] < -720.0f * scale) {
        sp3C = D_80804FA0_chdodgemcontrol;
        sp38 = func_80102D78(arg0, sp3C.v);
        sp30 = func_800DC178(15.0f, 70.0f);
        func_8080372C_chdodgemcontrol(arg0, sp30 + sp38, sp38 - func_800DC178(15.0f, 70.0f));
        if (func_8080460C_chdodgemcontrol(arg0) * 0.5f < ((f32 *)arg0->actorData)[3]) {
            ((f32 *)arg0->actorData)[3] -= func_8080458C_chdodgemcontrol(arg0);
        }
        if (((f32 *)arg0->actorData)[3] < func_8080460C_chdodgemcontrol(arg0) * 0.5f) {
            ((f32 *)arg0->actorData)[3] += func_8080458C_chdodgemcontrol(arg0);
        }
        sp4C[5] = 0.25f;
        return;
    }
    if (((f32 *)arg0->actorData)[3] < func_8080460C_chdodgemcontrol(arg0) * 0.75f) {
        ((f32 *)arg0->actorData)[3] += func_8080458C_chdodgemcontrol(arg0);
    }
}

void func_808039B8_chdodgemcontrol(Actor *arg0) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    f32 func_800EEF94(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    Actor *func_8080000C_chdodgemcontrol(Actor *, s32);
    s32 func_80801084_chdodgemcontrol(f32 *, f32 *, f32);
    void func_80802104_chdodgemcontrol(Actor *);
    void func_80802764_chdodgemcontrol(Actor *);
    void func_80802824_chdodgemcontrol(Actor *);
    void func_80802884_chdodgemcontrol(Actor *);
    extern s32 D_80804D5C_chdodgemcontrol[];
    s32 i;
    Actor *controller;
    u8 *control_data;
    Actor *other;
    f32 *data;
    f32 *other_data;
    f32 other_pos[3];
    f32 front[3];
    f32 other_front[3];
    f32 speed;
    f32 difference;
    s32 angle;
    f32 anglef;
    f32 point[3];
    f32 other_point[3];
    f32 offset[3];
    f32 other_offset[3];

    data = func_80100094(arg0, 0);
    controller = func_80106790(arg0->unk3C);
    control_data = func_80100094(controller, 0);
    for (i = 0; i < control_data[0xC2]; i++) {
        if (i != (*(u32 *)((u8 *)arg0 + 0x6C) & 0x1FF)) {
            other = func_8080000C_chdodgemcontrol(controller, i);
            other_data = func_80100094(other, 0);
            other_pos[0] = ((f32 *)other)[1];
            other_pos[1] = ((f32 *)other)[2];
            other_pos[2] = ((f32 *)other)[3];
            func_800EEB9C(front, ((f32 *)arg0)[0x12], 75.0f);
            func_800EF04C(front, ((f32 *)arg0 + 1));
            func_800EEB9C(other_front, ((f32 *)other)[0x12], 48.75f);
            func_800EF04C(other_front, ((f32 *)other + 1));
            if (func_800EFFB4(((f32 *)arg0 + 1), 182.0f, other_pos) ||
                func_800EFFB4(front, 156.0f, other_pos) ||
                func_800EFFB4(((f32 *)arg0 + 1), 156.0f, other_front) ||
                func_800EFFB4(front, 130.0f, other_front)) {
                speed = func_800EEF94((f32 *)arg0 + 10);
                if (i == (s32)((f32 *)arg0)[13]) {
                    ((f32 *)arg0)[20] = 0.0f;
                }
                if (func_800EEF94((f32 *)other + 10) <= speed) {
                    angle = (s32)func_800F1DF4(((f32 *)other + 1), ((f32 *)arg0 + 1));
                    difference = func_800F1DCC(((f32 *)other)[18], (f32)angle);
                    if (data[6] <= 0.0f) {
                        func_8010D930(1, 0, ((f32 *)arg0 + 1), &D_80804D5C_chdodgemcontrol);
                        data[6] = 1.0f;
                    }
                    if (difference > -45.0f && difference < 45.0f) {
                        func_80802764_chdodgemcontrol(other);
                    }
                    if (difference < -45.0f && difference > -135.0f) {
                        func_80802824_chdodgemcontrol(other);
                    }
                    if (difference > 45.0f && difference < 135.0f) {
                        func_80802884_chdodgemcontrol(other);
                    }
                    if (difference < -135.0f || difference > 135.0f) {
                        func_808027C4_chdodgemcontrol((BtIntPtr)other);
                    }
                    if (((f32 *)arg0)[9] < 150.0f) {
                        ((f32 *)arg0)[9] = 150.0f;
                    }
                    if (!(*(u32 *)((u8 *)arg0 + 0x6C) & 0x1FF) &&
                        ((u32)((u8 *)controller)[0x79] >> 4) != 3) {
                        ((f32 *)arg0)[9] *= 0.8999938965f;
                        anglef = (f32)angle;
                        func_800EEB9C(data, anglef, ((f32 *)arg0)[9] * 0.5f);
                    } else {
                        ((f32 *)arg0)[9] *= 0.6999969482f;
                        anglef = (f32)angle;
                        func_800EEB9C(data, anglef, ((f32 *)arg0)[9] / 1.0f);
                    }
                    if (i == 0 && ((u32)((u8 *)controller)[0x79] >> 4) != 3) {
                        ((f32 *)other)[9] *= 0.5f;
                        func_800EEB9C(other_data, anglef, -((f32 *)arg0)[9] * 3.0f);
                    } else {
                        ((f32 *)other)[9] *= 0.6999969482f;
                        func_800EEB9C(other_data, anglef, -((f32 *)arg0)[9] / 1.0f);
                    }
                    func_800EEB9C(offset, ((f32 *)arg0)[18], 48.75f);
                    func_800EEB9C(other_offset, ((f32 *)other)[18], 48.75f);
                    func_80801084_chdodgemcontrol(((f32 *)arg0 + 1), ((f32 *)other + 1), 170.625f);
                    func_800EE780(point, offset, ((f32 *)arg0 + 1));
                    func_80801084_chdodgemcontrol(point, ((f32 *)other + 1), 170.625f);
                    func_800EFB24(((f32 *)arg0 + 1), point, offset);
                    func_800EE780(other_point, other_offset, ((f32 *)other + 1));
                    func_80801084_chdodgemcontrol(((f32 *)arg0 + 1), other_point, 136.5f);
                    func_800EFB24(((f32 *)other + 1), other_point, other_offset);
                    func_800EE780(point, offset, ((f32 *)arg0 + 1));
                    func_800EE780(other_point, other_offset, ((f32 *)other + 1));
                    func_80801084_chdodgemcontrol(point, other_point, 136.5f);
                    func_800EFB24(((f32 *)other + 1), other_point, other_offset);
                    func_800EFB24(((f32 *)arg0 + 1), point, offset);
                    difference = func_800F1DCC(((f32 *)arg0)[18], (f32)(angle + 180));
                    if (difference > -45.0f && difference < 45.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    if (difference < -45.0f && difference > -135.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    if (difference > 45.0f && difference < 135.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    if (difference < -135.0f || difference > 135.0f) {
                        func_80802104_chdodgemcontrol(arg0);
                    }
                    difference = func_800F1DCC(((f32 *)arg0)[18], anglef);
                    if (difference > -80.0f && difference < 10.0f) {
                        data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    if (difference < 80.0f && difference > 10.0f) {
                        data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                    if (difference > -170.0f && difference < -100.0f) {
                        data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                    if (difference < 170.0f && difference > 80.0f) {
                        data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    difference = func_800F1DCC(((f32 *)other)[18], anglef);
                    if (difference > -80.0f && difference < 10.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                    if (difference < 80.0f && difference > 10.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    if (difference > -170.0f && difference < -100.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * 0.01f;
                    }
                    if (difference < 170.0f && difference > 80.0f) {
                        other_data[3] = ((f32 *)arg0)[9] * -0.01f;
                    }
                }
            }
        }
    }
}

/* extern */

void func_8080422C_chdodgemcontrol(BtIntPtr arg0, s32 arg1) {
    s32 anctrl_setPlaybackType(BtIntPtr, s32);
    s32 func_80101FDC();
    BtIntPtr func_80104248(BtIntPtr, s32);
    func_80101FDC();
    if ((arg1 == 5) || (arg1 == 6) || (arg1 == 7)) {
        anctrl_setPlaybackType(func_80104248(arg0, arg1), 2);
        return;
    }
    anctrl_setPlaybackType(func_80104248(arg0, arg1), 1);
}

s32 func_808042A4_chdodgemcontrol(BtIntPtr arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    Actor *actor = func_80106790((Unk80132ED0 *)arg0);

    switch (arg1) {
        case 2:
            switch (actor->unk6C_0) {
                case 1:
                    _subaddiedialog_entrypoint_11(actor->unk3C, 0x10BB, 4, actor->position, 0x78);
                    break;
                case 2:
                    _subaddiedialog_entrypoint_11(actor->unk3C, 0x10BD, 4, actor->position, 0x78);
                    break;
                case 3:
                    _subaddiedialog_entrypoint_11(actor->unk3C, 0x10BC, 4, actor->position, 0x78);
                    break;
            }
        case 3:
            switch (actor->unk6C_0) {
                case 1:
                    func_8080422C_chdodgemcontrol((BtIntPtr)actor, 5);
                    break;
                case 2:
                    func_8080422C_chdodgemcontrol((BtIntPtr)actor, 7);
                    break;
                case 3:
                    func_8080422C_chdodgemcontrol((BtIntPtr)actor, 6);
                    break;
            }
            break;
        case 0:
            func_8080422C_chdodgemcontrol((BtIntPtr)actor, 2);
            break;
        case 1:
            func_8080422C_chdodgemcontrol((BtIntPtr)actor, 4);
            break;
    } BT_NATIVE_ONLY(return 0;)
}

void func_8080440C_chdodgemcontrol(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800EFD24(f32 *);
    s32 func_80103140(Actor *, u32, u16);
    void func_800904F4(s32, Unk80132ED0 *);
    void func_800904C8(s32);
    u8 _gcstatusDll_entrypoint_11(void);
    f32 *sp24;

    sp24 = func_80100094(arg0, 0);
    arg0->scale = 0.65f;
    func_800EFD24(sp24);
    sp24[3] = 0.0f;
    switch (arg0->unk79_4) {
        case 0:
        case 1:
        case 2:
            switch (arg0->unk6C_0) {
                case 0:
                    func_80103140(arg0, 0x828, arg0->unk0->unk16);
                    func_800904F4(0x27, arg0->unk0);
                    func_800904C8(0x74);
                    arg0->unk64_20 = 1;
                    break;
                case 1:
                    func_8080422C_chdodgemcontrol((BtIntPtr)arg0, 5);
                    break;
                case 2:
                    func_8080422C_chdodgemcontrol((BtIntPtr)arg0, 7);
                    break;
                case 3:
                    func_8080422C_chdodgemcontrol((BtIntPtr)arg0, 6);
                    break;
            }
            break;
        case 3:
            if (arg0->unk6C_0 < (u32)_gcstatusDll_entrypoint_11()) {
                arg0->unk64_29 = 1;
            }
            break;
    }
}

void func_8080455C_chdodgemcontrol(void *arg0) {
    struct Flags {
        u8 pad[0x64];
        BT_BITFIELD_ORDER(u32 : 11, u32  : 20);
        u32 active : 1;
        BT_BITFIELD_ORDER(u32 : 20, u32  : 11);
    };
    void func_800904C8(s32);
    if (((struct Flags *)arg0)->active) {
        func_800904C8(0x28);
    }
}

f32 func_8080458C_chdodgemcontrol(Actor *arg0) {
    switch (arg0->unk79_4) {
        case 0:
        case 1:
        case 2:
            if (!arg0->unk6C_0) {
                return 60.0f;
            }
            return 50.0f;
        case 3:
            return 60.0f;
        default:
            return 0.0f;
    }
}

f32 func_8080460C_chdodgemcontrol(Actor *arg0) {
    switch (arg0->unk79_4) {
        case 0:
            if (!arg0->unk6C_0) {
                return 600.0f;
            }
            return 400.0f;
        case 1:
            if (!arg0->unk6C_0) {
                return 600.0f;
            }
            return 500.0f;
        case 2:
            if (!arg0->unk6C_0) {
                return 600.0f;
            }
            return 600.0f;
        case 3:
            return 600.0f;
        default:
            return 0.0f;
    }
}

f32 func_808046EC_chdodgemcontrol(Actor *arg0) {
    switch (arg0->unk79_4) {
        case 0:
        case 1:
        case 2:
            if (!arg0->unk6C_0) {
                return 800.0f;
            }
            return 600.0f;
        case 3:
            return 600.0f;
        default:
            return 0.0f;
    }
}

void func_8080476C_chdodgemcontrol(Actor *arg0) {
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    struct DodgemData {
        u8 pad0[0x34];
        f32 positions[10][3];
        u8 flags[0x16];
        u8 count;
        u8 padC3[2];
        u8 positionCount;
    };
    Actor *player;
    Actor *controller;
    struct DodgemData *data;
    s32 index;
    s32 i;
    s32 count;
    Actor *other;
    f32 position[3];

    controller = func_80106790(arg0->unk3C);
    data = func_80100094(controller, 0);
    if (controller->unk79_4 == 3) {
        if (arg0->unk50 <= 0.0f) {
            index = func_800DC128(0, data->positionCount);
            if (data->flags[index] == 1) {
                ((f32 *)arg0->actorData)[7] = index;
            }
            arg0->unk50 = func_800DC178(3.0f, 5.0f);
        }
        arg0->unk54 = func_800F1DF4(arg0->position, data->positions[(s32)((f32 *)arg0->actorData)[7]]);
    } else {
        player = func_8080000C_chdodgemcontrol(controller, 0);
        count = 0;
        for (i = 1; i < data->count; i++) {
            if (i != arg0->unk6C_0) {
                other = func_8080000C_chdodgemcontrol(controller, i);
                if (func_800EEB40(other->position, player->position) < 90000.0f) {
                    count++;
                }
            }
        }
        if (count >= 2) {
            if (arg0->unk50 <= 0.0f) {
                position[1] = 0.0f;
                position[0] = func_800DC178(-600.0f, 600.0f);
                position[2] = func_800DC178(-600.0f, 600.0f);
                arg0->unk54 = func_800F1DF4(arg0->position, position);
                arg0->unk50 = func_800DC178(0.5f, 1.5f);
            }
        } else {
            arg0->unk54 = func_800F1DF4(arg0->position, player->position);
        }
    }
}

OSThread *chdodgemcontrol_entrypoint_2(void)
{
    extern BtFnWord D_80804FAC_chdodgemcontrol[];

    return (OSThread *) D_80804FAC_chdodgemcontrol;
}

void func_80105834();
void func_80101870();
void func_80107C2C();
void func_801018A4();
s32 D_80804D00_chdodgemcontrol[] = {
    0x00000002, 0x00000003, 0x00000004, 0x00000004,
};
u32 D_80804D10_chdodgemcontrol[] = {
    0x00130516, 0x001601F4, 0x00010DAC, 0x13880000,
};
s32 D_80804D20_chdodgemcontrol[] = {
    0x0013054C, 0x000D00F3, 0x010C0018, 0x00010DAC,
    0x13880000,
};
s32 D_80804D34_chdodgemcontrol[] = {
    0x0013054B, 0x000D00F3, 0x010C0018, 0x00010DAC,
    0x13880000,
};
s32 D_80804D48_chdodgemcontrol[] = {
    0x00130661, 0x000A00B8, 0x00164650, 0x00010DAC,
    0x13880000,
};
s32 D_80804D5C_chdodgemcontrol[] = {
    0x00130519, 0x000D00F3, 0x010C0016, 0x46500001,
    0x0DAC1388, 0x00000000,
};
s32 D_80804D74_chdodgemcontrol[] = {
    0x0013062B, 0x000D00CC, 0x00E60016, 0x46500001,
    0x0DAC1388, 0x00000000,
};
s32 D_80804D8C_chdodgemcontrol[] = {
    0x001304B6, 0x000D00CC, 0x00E60016, 0x46500001,
    0x0DAC1388, 0x00000000,
};
s32 D_80804DA4_chdodgemcontrol[] = {
    0x00130515, 0x001E0001, 0x0DAC1388, 0x00000000,
};
BtFnWord D_80804DB4_chdodgemcontrol[] = {
    0x02CB0306, 0x00000001, 0x00000000, (BtFnWord)func_8080010C_chdodgemcontrol,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000004, (BtFnWord)func_808015E8_chdodgemcontrol, 0x00000000,
    0x00C80000, (BtFnWord)func_808013D0_chdodgemcontrol, (BtFnWord)func_80107C2C, 0x80000602,
    (BtFnWord)func_80800938_chdodgemcontrol, 0x00000000,
};
struct DodgemValues D_80804DFC_chdodgemcontrol = {
    0x00000077, 0x00000078, 0x0000007A, 0x00000079,
};
struct dodgem_vector D_80804E0C_chdodgemcontrol = {
    0.0f, 0.0f, 0.0f,
};
DodgemValues D_80804E18_chdodgemcontrol = {
    270.0f, 90.0f, 180.0f, 0.0f,
};
DodgemPositions D_80804E28_chdodgemcontrol = {
    615.0f, 0.0f, 0.0f, -615.0f, 0.0f, 0.0f, 0.0f, 0.0f, 615.0f, 0.0f, 0.0f, -615.0f,
};
u32 D_80804E58_chdodgemcontrol[] = {
    0x00000000, 0x00000000, 0x3F0A3D71, 0x03600000,
    0x3F0A3D71, 0x03600000, 0x3F0A3D71, 0x03600000,
};
s32 D_80804E78_chdodgemcontrol[] = {
    0x00161200, 0x00150000, 0x00CC002B, 0x00C00100,
    0x0022004C, 0x00590026, 0x0033002D, 0x01900258,
    0x000D0014, 0x001BFCE0, 0xFDA80000,
};
s32 D_80804EA4_chdodgemcontrol[] = {
    0x001304FC, 0x0018000D, 0x00F3010C, 0x00000000,
};
struct DodgemRGB D_80804EB4_chdodgemcontrol = {
    0x00000000, 0x00000000, 0x00000000,
};
struct DodgemRGB D_80804EC0_chdodgemcontrol = {
    0x00000000, 0x00000000, 0x00000000,
};
s16 D_80804ECC_chdodgemcontrol[] = {
    0x09E4, 0x09E8, 0x09E0, 0x0000,
};
u16 D_80804ED4_chdodgemcontrol[] = {
    0x07C7, 0x07C6, 0x07C5, 0x0000,
};
BtFnWord D_80804EDC_chdodgemcontrol[] = {
    0x01FC037F, 0x07C50001, (BtFnWord)D_80804E58_chdodgemcontrol, (BtFnWord)func_80801C60_chdodgemcontrol,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00020004, (BtFnWord)func_80801F00_chdodgemcontrol, 0x00000000,
    0x00000000, (BtFnWord)func_80801F2C_chdodgemcontrol, (BtFnWord)func_80107C2C, 0x80000002,
    0x00000000, 0x00000000,
};
u32 D_80804F24_chdodgemcontrol[] = {
    0x00000000, 0x00000000, 0x4B189680, 0x01050000,
    0x4B189680, 0x01050000, 0x4B189680, 0x01050000,
    0x4B189680, 0x01050000, 0x40551EB8, 0x010E0001,
    0x40800000, 0x010F0001, 0x40800000, 0x01100001,
};
s32 D_80804F64_chdodgemcontrol[] = {
    0x00000004, 0x00000001, 0x00000003, 0x00000002,
};
f32 D_80804F74_chdodgemcontrol[] = {
    0.148300007f, 0.300000012f, 0.467999995f, -1.0f,
};
f32 D_80804F84_chdodgemcontrol[] = {
    0.0700000003f, 0.239999995f, 0.400000006f, -1.0f,
};
f32 D_80804F94_chdodgemcontrol[] = {
    0.0799999982f, 0.879999995f, -1.0f,
};
struct DodgemPosition D_80804FA0_chdodgemcontrol = {
    0.0f, 0.0f, 0.0f,
};
BtFnWord D_80804FAC_chdodgemcontrol[] = {
    0x02CA0305, 0x06BA0004, (BtFnWord)D_80804F24_chdodgemcontrol, (BtFnWord)func_80802D04_chdodgemcontrol,
    (BtFnWord)func_80105834, (BtFnWord)func_801018A4, 0x00000000, 0x3F800000,
    0x00000000, 0x00000004, (BtFnWord)func_8080455C_chdodgemcontrol, 0x00000000,
    0x00200000, (BtFnWord)func_8080440C_chdodgemcontrol, (BtFnWord)func_80107C2C, 0x80000002,
    (BtFnWord)func_8080207C_chdodgemcontrol, 0x00000000, 0x00000000, 0x00000000,
    0x00000000,
};
