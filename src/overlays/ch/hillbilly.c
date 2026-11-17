#include "common.h"

OSThread *chhillbilly_entrypoint_0(void)
{
    extern ActorData D_80800C60_chhillbilly[];

    return (OSThread *) D_80800C60_chhillbilly;
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Objhillbilly_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

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
        func_800EE940((s16 *)(sp1C + 6), sp18 = &((Objhillbilly_arg0 *)arg0)->unk4);
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
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 _sucoaster_entrypoint_13();
    void _sucoaster_entrypoint_19(Actor *arg0);
    void _sucoaster_entrypoint_2(Actor *arg0);
    u8 *_sucoaster_entrypoint_3();
    s32 _sucoaster_entrypoint_7(Actor *arg0, s32 arg1, f32 arg2);
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
    extern u32 D_80800CA8_chhillbilly[3];
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
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800CA8_chhillbilly, 0.2f);
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

void func_80800298_chhillbilly(Actor *arg0, u8 *arg1) { void _sucoaster_entrypoint_20(); s32 var_a1; if ((u32)(arg0->unk0->unk28 << 18) >> 31) { var_a1 = 0; } else { var_a1 = 1; } func_800DF744(3, var_a1); _sucoaster_entrypoint_20(arg0, arg1); }

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
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE88C(f32 *, s16 *);
    extern s32 D_80800CB4_chhillbilly[15];
    f32 sp24[3];

    if (arg0->unk70_10 == 0x16) {
        func_800EE7F8(sp24, arg0->position);
    } else {
        func_800EE88C(sp24, (s16 *)_sucoaster_entrypoint_3(arg0));
    }
    func_800BBCB8(sp24, NULL, arg0->scale, 1, D_80800CB4_chhillbilly);
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
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE88C(f32 *, s16 *);
    extern s32 D_80800CF0_chhillbilly[16];
    f32 sp34[3];
    f32 sp28[3];

    if (arg0->unk7C_12 && (func_8001210C(1) == 0)) {
        func_800EE88C(sp28, (s16 *)_sucoaster_entrypoint_3(arg0));
        func_800EE7F8(sp34, sp28);
        sp34[1] -= 20.0f;
        func_800BBCB8(sp28, sp34, 1.0f, 3, D_80800CF0_chhillbilly);
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
/* data_to_c.py: from asm/data/overlays/ch/hillbilly.data.s */
extern u8 D_80800BA8_chhillbilly[];
void func_80105834(Actor*);
void _sucoaster_entrypoint_1();
OSThread *_sucoasterhit_entrypoint_0(void);
void func_80107C2C();
extern u8 D_80800B40_chhillbilly[];
u8 D_80800B40_chhillbilly[20] BT_DATA(4, overlays_ch_hillbilly, 0x0) = { 0x00, 0x16, 0x00, 0x01, 0x00, 0x0E, 0x00, 0x01, 0x00, 0x0D, 0x00, 0x01, 0x00, 0x10, 0x00, 0x01, 0x00, 0x16, 0x00, 0x01 };
u8 D_80800B54_chhillbilly [84] BT_DATA(4, overlays_ch_hillbilly, 0x14) = { 0, 0, 0, 0x2A, 0x3F, 0xA0, 0, 0, 0, 0x2B, 0, 0, 0, 0, 0, 0x1E, 0x3F, 0xA6, 0x66, 0x66, 2, 0x1C, 0, 0, 0, 0, 0, 0x10, 0x3F, 0xA6, 0x66, 0x66, 2, 0xE, 0, 0, 0, 0, 0, 0x1C, 0x3F, 0xA6, 0x66, 0x66, 1, 0xE, 0, 0, 0, 0, 0, 0x14, 0x3F, 0x99, 0x99, 0x9A, 2, 0x18, 0, 0, 0, 0, 0, 6, 0x3F, 0x99, 0x99, 0x9A, 2, 0xA, 0, 0, 0, 0, 0, 1, 0x3F, 0xC0, 0, 0, 1, 0x12, 0, 0 };
u8 D_80800BA8_chhillbilly[184] BT_DATA(4, overlays_ch_hillbilly, 0x68) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x19, 0x99, 0x9A, 0x02, 0x1D, 0x00, 0x01, 0x3F, 0x19, 0x99, 0x9A, 0x02, 0x1D, 0x00, 0x01, 0x3F, 0xC0, 0x00, 0x00, 0x02, 0x1A, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x02, 0x1A, 0x00, 0x01, 0x3F, 0xC0, 0x00, 0x00, 0x02, 0x1A, 0x00, 0x01, 0x3F, 0xC0, 0x00, 0x00, 0x02, 0x1A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xC0, 0x00, 0x00, 0x02, 0x1A, 0x00, 0x01, 0x3F, 0x99, 0x99, 0x9A, 0x03, 0xE1, 0x00, 0x02, 0x3F, 0xC0, 0x00, 0x00, 0x02, 0x1A, 0x00, 0x01, 0x3F, 0x00, 0x00, 0x00, 0x03, 0xE2, 0x00, 0x02, 0x3F, 0xB3, 0x33, 0x33, 0x02, 0x1B, 0x00, 0x02, 0x3F, 0xB3, 0x33, 0x33, 0x02, 0x1B, 0x00, 0x84, 0x3F, 0x19, 0x99, 0x9A, 0x02, 0x1D, 0x00, 0x01, 0x3F, 0xC0, 0x00, 0x00, 0x02, 0x1A, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x8C, 0xCC, 0xCD, 0x02, 0x1C, 0x00, 0x01, 0x3F, 0xC0, 0x00, 0x00, 0x02, 0x1A, 0x00, 0x01, 0x3F, 0x66, 0x66, 0x66, 0x02, 0x18, 0x00, 0x02, 0x3F, 0x8C, 0xCC, 0xCD, 0x02, 0x19, 0x00, 0x02, 0x3F, 0x4C, 0xCC, 0xCD, 0x02, 0x1A, 0x00, 0x01, 0x3F, 0x8C, 0xCC, 0xCD, 0x02, 0x1C, 0x00, 0x01 };
ActorData D_80800C60_chhillbilly [1] BT_DATA(4, overlays_ch_hillbilly, 0x120) = { { 417, 336, 1930, 22, (void *)D_80800BA8_chhillbilly, (void (*)(struct Actor *))func_80800064_chhillbilly, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800298_chhillbilly, 196608000, 1065353216, 0, 0, 17157, 865, (void (*)(struct Actor *))_sucoaster_entrypoint_1, (BtIntPtr)_sucoasterhit_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_8080000C_chhillbilly, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31694, 21533, (void (*)(struct Actor *, long, long))func_80800540_chhillbilly, (BtIntPtr)D_80800B40_chhillbilly } };
u32 D_80800CA8_chhillbilly[3] BT_DATA(4, overlays_ch_hillbilly, 0x168) = { 0x1304CF, 0xD00F3, 0x10C0000 };
s32 D_80800CB4_chhillbilly[15] BT_DATA(4, overlays_ch_hillbilly, 0x174) = { 1902474, 2556004, 13107400, 26214427, -52363964, 1376256, 6684715, 50332672, 2948970, 19726186, 9830800, 9830407, 196612, 8388630, 25296896 };
s32 D_80800CF0_chhillbilly[16] BT_DATA(4, overlays_ch_hillbilly, 0x1B0) = { 1902244, 1446274, 1834408, -39321561, -39256664, 39322200, 2949270, 13107234, 786457, 0, 2818201, 13369365, 179, 720946, 3997686, -1310720 };
