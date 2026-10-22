#include "common.h"

OSThread *chhillbilly_entrypoint_0(void)
{
    extern u8 D_80800C60_chhillbilly[];

    return (OSThread *) D_80800C60_chhillbilly;
}

/* extern */

void func_8080000C_chhillbilly(void *arg0) {
    s32 _sucoaster_entrypoint_0(void *, s32);
    u8 *_sucoaster_entrypoint_3();
    void func_800EE940(s16 *dst, f32 *src);
    u8 *sp1C;
    f32 *volatile sp18;
    f32 *position;

    if (_sucoaster_entrypoint_0(arg0, 0xC) != 0) {
        sp1C = _sucoaster_entrypoint_3(arg0);
        func_800EE940((s16 *)(sp1C + 6), sp18 = (f32 *)((u8 *)arg0 + 4));
        position = sp18;
        func_800EE940((s16 *)sp1C, position);
    }
}

void func_80800064_chhillbilly(Actor *arg0) {
    struct HillbillyFlags {
        u8 pad0[0x74];
        u8 flags74;
        u8 pad75[3];
        u32 pad78_3 : 29;
        u32 unk78_2 : 1;
        u32 pad78_0 : 2;
    };
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 _sucoaster_entrypoint_13();
    s32 _sucoaster_entrypoint_19(void *);
    s32 _sucoaster_entrypoint_2();
    u8 *_sucoaster_entrypoint_3();
    void _sucoaster_entrypoint_7(Actor *, s32, f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EE940(s16 *, f32 *);
    s32 func_80101DDC(Actor *);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    f32 func_8010CD28(Actor *);
    s32 func_808002F0_chhillbilly(f32 *);
    s32 func_808003C8_chhillbilly(u8 *);
    s32 func_8080042C_chhillbilly(u8 *);
    void func_80800944_chhillbilly(Actor *);
    void func_808009D8_chhillbilly(Actor *, s32, s32);
    extern u32 D_80800CA8_chhillbilly;
    f32 sp34[3];
    f32 sp28[3];

    _sucoaster_entrypoint_2(arg0);
    if (!((struct HillbillyFlags *)arg0)->unk78_2) {
        _subaddieskeleton_entrypoint_3(arg0->unk0, 4, sp34);
        func_800EE940((s16 *)_sucoaster_entrypoint_3(arg0), sp34);
        switch (arg0->unk70_10) {
        case 2:
        case 3:
        case 8:
            if (func_8080042C_chhillbilly((u8 *)arg0)) {
                _sucoaster_entrypoint_10(arg0, 20);
                ((f32 *)arg0->actorData)[3] = 0.0f;
            }
            break;
        case 19:
            func_80800944_chhillbilly(arg0);
            arg0->unk54 = func_8010CD28(arg0);
            func_80102BF8(arg0, 0.2f, 60.0f, 300.0f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800CA8_chhillbilly, 0.2f);
            if (func_80101DDC(arg0)) {
                _sucoaster_entrypoint_10(arg0, (((struct HillbillyFlags *)arg0)->flags74 & 1) ? 18 : (arg0->unk64_29 ? 2 : 8));
            }
            break;
        case 20:
            _sucoaster_entrypoint_19(arg0);
            if (func_80101DDC(arg0)) {
                func_808009D8_chhillbilly(arg0, 0x78A, 0);
                _sucoaster_entrypoint_10(arg0, 22);
            }
            break;
        case 21:
            _sucoaster_entrypoint_19(arg0);
            if (!_sucoaster_entrypoint_13(arg0)) {
                if (func_808002F0_chhillbilly((f32 *)arg0)) {
                    _sucoaster_entrypoint_10(arg0, 20);
                    ((f32 *)arg0->actorData)[3] = 0.0f;
                    return;
                }
                if (_subaddierouteDll_entrypoint_4(arg0)) {
                    func_800EE88C(sp28, (s16 *)(_sucoaster_entrypoint_3(arg0) + 6));
                    arg0->unk54 = func_80102D78(arg0, sp28);
                }
            }
            _sucoaster_entrypoint_7(arg0, 0x5802, 30.0f);
            break;
        case 22:
            if (func_808003C8_chhillbilly((u8 *)arg0)) {
                func_808009D8_chhillbilly(arg0, 0x789, 0);
                _sucoaster_entrypoint_10(arg0, 19);
            }
            break;
        }
    }
}

/* extern */

void func_80800298_chhillbilly(Actor *arg0, u8 *arg1) { s32 _sucoaster_entrypoint_20(Actor *, u8 *); s32 var_a1; if ((u32)(arg0->unk0->unk28 << 18) >> 31) { var_a1 = 0; } else { var_a1 = 1; } func_800DF744(3, var_a1); _sucoaster_entrypoint_20(arg0, arg1); }

/* extern */

s32 func_808002F0_chhillbilly(f32 *arg0) {
    u8 *_sucoaster_entrypoint_3();
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EFC7C(f32 *, f32 *);
    f32 sp1C[3];

    func_800EE88C(sp1C, (s16 *)(_sucoaster_entrypoint_3() + 6));
    return func_800EFC7C(arg0 + 1, sp1C) < 10000.0f;
}

void func_80800348_chhillbilly(Actor *arg0) {
    u8 *_sucoaster_entrypoint_3();
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE88C(f32 *, s16 *);
    extern s32 D_80800CB4_chhillbilly;
    f32 sp24[3];

    if (arg0->unk70_10 == 0x16) {
        func_800EE7F8(sp24, arg0->position);
    } else {
        func_800EE88C(sp24, (s16 *)_sucoaster_entrypoint_3(arg0));
    }
    func_800BBCB8(sp24, NULL, arg0->scale, 1, &D_80800CB4_chhillbilly);
}

/* extern */

s32 func_808003C8_chhillbilly(u8 *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    s32 _sucoaster_entrypoint_13();
    struct Flags {
        u8 pad[0x64];
        u32 : 2;
        u32 flag : 1;
        u32 : 29;
        u8 pad68[0xC];
        u8 : 7;
        u8 flag74 : 1;
    };
    if (((struct Flags *)arg0)->flag) {
        return _subaddiejoy_entrypoint_6(arg0, 0) == 1;
    }
    if (((struct Flags *)arg0)->flag74) {
        return 1;
    }
    return _sucoaster_entrypoint_13() == 1;
}

/* extern */

s32 func_8080042C_chhillbilly(u8 *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    struct Flags {
        u8 pad[0x64];
        u32 : 2;
        u32 flag : 1;
        u32 : 29;
    };

    if (((struct Flags *)arg0)->flag) {
        return _subaddiejoy_entrypoint_6(arg0, 0) == 1;
    } else {
        return 0;
    }
}

void func_8080046C_chhillbilly(Actor *arg0) {
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    void func_808009D8_chhillbilly(Actor *, s32, s32);

    switch (arg0->unk70_10) {
    case 21:
        _sucoaster_entrypoint_10(arg0, 3);
        return;
    case 22:
        func_808009D8_chhillbilly(arg0, 0x789, 0);
        _sucoaster_entrypoint_10(arg0, 0x13);
        return;
    }
}

/* extern */

void func_808004D0_chhillbilly(Actor *arg0) { s32 _subaddieDll_entrypoint_3(Actor *); s32 _sucoaster_entrypoint_10(Actor *, s32); s32 _sucoaster_entrypoint_6(Actor *, f32, ...); s32 var_a2; if ((arg0->unk70_10 == 2) || (arg0->unk70_10 == 3) || (arg0->unk70_10 == 8)) { if (_subaddieDll_entrypoint_3(arg0) != 0) { var_a2 = 0x15; } else { var_a2 = 0xE; } _sucoaster_entrypoint_6(arg0, 200.0f, var_a2); _sucoaster_entrypoint_10(arg0, var_a2); } }

s32 func_80800540_chhillbilly(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _sucoaster_entrypoint_21(Actor *, s32, s32);
    void func_80101074(void *);
    s32 func_808006B4_chhillbilly(Actor *, s32, u32);
    void func_808009D8_chhillbilly(Actor *, s32, s32);
    extern u8 D_80800B54_chhillbilly[];
    struct ActorFlags { u8 pad[0x78]; u32 upper : 29; u32 flag : 1; u32 lower : 2; };
    struct Flags { u8 pad[0x2A]; u8 upper : 2; u8 enabled : 1; u8 lower : 5; };
    struct Event { s16 value; u8 type; u8 pad; };
    s32 result;
    s32 animation;
    s32 event;

    switch (arg1) {
    case 1:
    case 2:
        result = _sucoaster_entrypoint_21(arg0, arg1, arg2);
        if (!((struct ActorFlags *)arg0)->flag) {
            if (arg0->unk64_29) {
                func_8080046C_chhillbilly(arg0);
                return 1;
            }
            func_808004D0_chhillbilly(arg0);
            return 1;
        }
        break;
    case 0x42:
        result = func_808006B4_chhillbilly(arg0, ((struct Event *)&arg2)->value, ((struct Event *)&arg2)->type);
        break;
    case 0x8F:
        event = arg2;
        if (event == 0 || event == 4) {
            func_808009D8_chhillbilly(arg0, 0x78A, 0);
            ((struct Flags *)arg0->unk0)->enabled = 0;
        }
        result = 1;
        break;
    case 0x95:
        animation = (arg0->unk70_10 == 22 || arg0->unk70_10 == 16) ? 0x78A : 0x789;
        func_808009D8_chhillbilly(arg0, animation, 1);
        result = _sucoaster_entrypoint_21(arg0, arg1, arg2);
        break;
    case 0x38:
        func_80101074(D_80800B54_chhillbilly);
        return 7;
    default:
        result = _sucoaster_entrypoint_21(arg0, arg1, arg2);
        break;
    }
    return result;
}

s32 func_808006B4_chhillbilly(Actor *arg0, s32 arg1, u32 arg2) {
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 func_800D9058(f32);
    void func_801020DC(void *, s32);
    void func_8010297C(void *, f32, f32, f32);
    void func_80800894_chhillbilly(Actor *, s32);
    void func_808009D8_chhillbilly(Actor *, s32, s32);
    struct Flags { u8 pad[0x2A]; u8 upper : 2; u8 enabled : 1; u8 lower : 5; };
    s32 state;

    switch (arg2) {
    case 0:
        if (arg0->unk70_10 == 22) {
            return 0;
        }
        switch (arg1) {
        case 2:
        case 3:
            state = arg0->unk0->unk14 == 0x78A ? 22 : 21;
            func_80800894_chhillbilly(arg0, state);
            break;
        case 4:
            func_80800894_chhillbilly(arg0, 21);
            break;
        case 5:
        case 8:
        case 9:
        case 18:
            return 1;
        case 7:
            _sucoaster_entrypoint_10(arg0, 8);
            break;
        }
        break;
    case 2:
    case 7:
        func_80800894_chhillbilly(arg0, 21);
        break;
    case 3:
        arg0->unk6C_0 = func_800D9058(2.0f);
        func_8010297C(arg0, arg0->unk54, 70.0f, 120.0f);
        if (arg0->unk70_10 == 8) {
            func_80800894_chhillbilly(arg0, 21);
        }
        return 0;
    case 4:
        if (arg0->unk0->unk14 == 0x789) {
            return 1;
        }
        break;
    case 1:
    case 6:
        return 1;
    case 5:
        func_80800894_chhillbilly(arg0, 12);
        break;
    case 8:
        if (arg1 == 17) {
            func_808009D8_chhillbilly(arg0, 0x78A, 0);
            func_801020DC(arg0, 0);
        }
        ((struct Flags *)arg0->unk0)->enabled = 0;
        return 1;
    case 9:
        if (arg0->unk64_29) {
            _sucoaster_entrypoint_10(arg0, 2);
            break;
        }
        return 1;
    }
    return 0;
}

void func_80800894_chhillbilly(Actor *arg0, s32 arg1) {
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 _sucoaster_entrypoint_6(Actor *, f32, ...);
    void func_8010A570(Actor *);
    void func_808009D8_chhillbilly(Actor *, s32, s32);
    struct Flags { u8 pad[0x2A]; u8 upper : 2; u8 enabled : 1; u8 lower : 5; };

    switch (arg1) {
    case 12:
        func_80800348_chhillbilly(arg0);
        func_808009D8_chhillbilly(arg0, 0x789, 0);
        func_8010A570(arg0);
        _sucoaster_entrypoint_10(arg0, 12);
        ((struct Flags *)arg0->unk0)->enabled = 1;
        return;
    case 21:
        _sucoaster_entrypoint_10(arg0, 21);
        _sucoaster_entrypoint_6(arg0, 200.0f);
        return;
    case 22:
        _sucoaster_entrypoint_10(arg0, 22);
        return;
    }
}

void func_80800944_chhillbilly(Actor *arg0) {
    u8 *_sucoaster_entrypoint_3();
    s32 func_8001210C(s32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE88C(f32 *, s16 *);
    extern s32 D_80800CF0_chhillbilly;
    f32 sp34[3];
    f32 sp28[3];

    if (arg0->unk7C_12 && (func_8001210C(1) == 0)) {
        func_800EE88C(sp28, (s16 *)_sucoaster_entrypoint_3(arg0));
        func_800EE7F8(sp34, sp28);
        sp34[1] -= 20.0f;
        func_800BBCB8(sp28, sp34, 1.0f, 3, &D_80800CF0_chhillbilly);
    }
}

void func_808009D8_chhillbilly(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_80103140(Actor *, u32, u16);
    s32 func_801032B0(Actor *, u16, u16);
    void func_8010A3E8(void *, f32);

    if (arg2 != 0) {
        func_801032B0(arg0, arg1, arg0->unk0->unk16);
    } else {
        func_80103140(arg0, (u16)arg1, arg0->unk0->unk16);
    }
    switch (arg1) {
        case 0x789:
            func_8010A3E8(arg0, 0.75f);
            break;
        case 0x78A:
            func_8010A3E8(arg0, 1.0f);
            break;
    }
}
