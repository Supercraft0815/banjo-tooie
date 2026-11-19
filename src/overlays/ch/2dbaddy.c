#include "common.h"

OSThread *ch2dbaddy_entrypoint_0(void)
{
    extern ActorData D_80800A9C_ch2dbaddy[];

    return (OSThread *) D_80800A9C_ch2dbaddy;
}

/* extern */

void func_8080000C_ch2dbaddy(Actor *arg0) {
    s32 _sucoaster_entrypoint_0(void *, s32);
    u8 *_sucoaster_entrypoint_3();
    void func_800EE940(s16 dst[3], f32 src[3]);
    void func_80102FDC(Actor *, f32);
    void func_8010A3E8(void *, f32);
    void func_8010A570(Actor *);
    void func_80800850_ch2dbaddy();
    u8 *sp24;

    if (_sucoaster_entrypoint_0(arg0, 0xA) != 0) {
        func_8010A3E8(arg0, 0.55f);
        func_80102FDC(arg0, arg0->scale * 0.6f);
        sp24 = _sucoaster_entrypoint_3(arg0);
        func_80800850_ch2dbaddy(arg0);
        func_800EE940(sp24, arg0->position);
        arg0->unk64_16 = 0;
        func_8010A570(arg0);
    }
}

void func_808000A0_ch2dbaddy(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 _sucoaster_entrypoint_13();
    void _sucoaster_entrypoint_19(Actor *arg0);
    void _sucoaster_entrypoint_2(Actor *arg0);
    u8 *_sucoaster_entrypoint_3();
    s32 _sucoaster_entrypoint_7(Actor *arg0, s32 arg1, f32 arg2);
    void func_800EE88C(f32 *, s16 *);
    s32 func_80101DDC(Actor *);
    f32 func_80101F24(Actor *);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    void func_8010A570(Actor *);
    u32 func_8010A5B0(Actor *, s32);
    f32 func_8010CD28(Actor *);
    s32 func_808003C4_ch2dbaddy(f32 *);
    s32 func_8080041C_ch2dbaddy(u8 *);
    s32 func_80800468_ch2dbaddy(u8 *);
    s32 func_80800700_ch2dbaddy(Actor *, s32);
    void func_80800820_ch2dbaddy(Actor *);
    struct ActorFlags {
        u8 pad[0x78];
        BT_BITFIELD_ORDER(u32 : 29, u32  : 2);
        u32 flag : 1;
        BT_BITFIELD_ORDER(u32 : 2, u32  : 29);
    };
    f32 sp24[3];

    _sucoaster_entrypoint_2(arg0);
    if (!((struct ActorFlags *)arg0)->flag) {
        switch (arg0->unk70_10) {
        case 2:
        case 3:
        case 8:
            if (func_80800468_ch2dbaddy((u8 *)arg0)) {
                _sucoaster_entrypoint_10(arg0, 0x16);
                ((f32 *)arg0->actorData)[3] = 0.0f;
            }
            break;
        case 19:
            _sucoaster_entrypoint_19(arg0);
            if (func_8080041C_ch2dbaddy((u8 *)arg0)) {
                func_80800700_ch2dbaddy(arg0, 0x14);
            }
            break;
        case 20:
            func_80800820_ch2dbaddy(arg0);
            arg0->unk54 = func_8010CD28(arg0);
            func_80102BF8(arg0, 0.2f, 60.0f, 300.0f);
            func_8010A5B0(arg0, arg0->unk64_20);
            arg0->unk64_20 = 1;
            if (func_80101DDC(arg0)) {
                _sucoaster_entrypoint_10(arg0, arg0->unk64_29 ? 2 : 8);
            }
            break;
        case 22:
            _sucoaster_entrypoint_19(arg0);
            if (func_80101F24(arg0) > 0.6f) {
                func_8010A570(arg0);
            }
            if (func_80101DDC(arg0)) {
                func_80800700_ch2dbaddy(arg0, 0x13);
            }
            break;
        case 21:
            _sucoaster_entrypoint_19(arg0);
            if (!_sucoaster_entrypoint_13(arg0)) {
                if (func_808003C4_ch2dbaddy((f32 *)arg0)) {
                    _sucoaster_entrypoint_10(arg0, 0x16);
                    ((f32 *)arg0->actorData)[3] = 0.0f;
                    break;
                }
                if (_subaddierouteDll_entrypoint_4(arg0)) {
                    func_800EE88C(sp24, (s16 *)_sucoaster_entrypoint_3(arg0));
                    arg0->unk54 = func_80102D78(arg0, sp24);
                }
            }
            _sucoaster_entrypoint_7(arg0, 0x5802, 30.0f);
            break;
        }
    }
}

s32 func_808002A8_ch2dbaddy(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _sucoaster_entrypoint_21(Actor *, s32, s32);
    u8 *_sucoaster_entrypoint_3();
    void func_80101074(void *);
    s32 func_801032B0(Actor *, u16, u16);
    void func_808004A8_ch2dbaddy(Actor *);
    void func_808004F4_ch2dbaddy(Actor *);
    s32 func_80800564_ch2dbaddy(Actor *, s32, u32);
    extern u8 D_80800A3C_ch2dbaddy[];
    struct ActorFlags {
        u8 pad[0x78];
        BT_BITFIELD_ORDER(u32 : 29, u32  : 2);
        u32 flag : 1;
        BT_BITFIELD_ORDER(u32 : 2, u32  : 29);
    };
    s32 result;

    switch (arg1) {
    case 1:
    case 2:
        result = _sucoaster_entrypoint_21(arg0, arg1, arg2);
        if (!((struct ActorFlags *)arg0)->flag) {
            if (arg0->unk64_29) {
                func_808004A8_ch2dbaddy(arg0);
                return 1;
            }
            func_808004F4_ch2dbaddy(arg0);
            return 1;
        }
        break;
    case 0x42:
        result = func_80800564_ch2dbaddy(arg0, *(s16 *)&arg2, ((u8 *)&arg2)[2]);
        break;
    case 0x95:
        func_801032B0(arg0, ((u16 *)_sucoaster_entrypoint_3(arg0))[3], 0);
        result = _sucoaster_entrypoint_21(arg0, arg1, arg2);
        break;
    case 0x38:
        func_80101074(D_80800A3C_ch2dbaddy);
        return 8;
    default:
        result = _sucoaster_entrypoint_21(arg0, arg1, arg2);
        break;
    }
    return result;
}

/* extern */

s32 func_808003C4_ch2dbaddy(f32 *arg0) {
    void func_800EE88C(f32 dst[3], s16 src[3]);
    f32 func_800EFC7C(f32 *, f32 *);
    u8 *_sucoaster_entrypoint_3();
    f32 sp1C[3];

    func_800EE88C(sp1C, (s16 *)_sucoaster_entrypoint_3());
    return func_800EFC7C(arg0 + 1, sp1C) < 10000.0f;
}

/* extern */

s32 func_8080041C_ch2dbaddy(u8 *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    s32 _sucoaster_entrypoint_13();
    struct Flags {
        u8 pad[0x64];
        BT_BITFIELD_ORDER(u32 : 2, u32  : 29);
        u32 flag : 1;
        BT_BITFIELD_ORDER(u32 : 29, u32  : 2);
    };
    if (((struct Flags *)arg0)->flag) {
        return _subaddiejoy_entrypoint_6(arg0, 0) == 1;
    }
    return _sucoaster_entrypoint_13() == 1;
}

/* extern */

s32 func_80800468_ch2dbaddy(u8 *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    struct Flags {
        u8 pad[0x64];
        BT_BITFIELD_ORDER(u32 : 2, u32  : 29);
        u32 flag : 1;
        BT_BITFIELD_ORDER(u32 : 29, u32  : 2);
    };

    if (((struct Flags *)arg0)->flag) {
        return _subaddiejoy_entrypoint_6(arg0, 0) == 1;
    } else {
        return 0;
    }
}

/* extern */

void func_808004A8_ch2dbaddy(Actor *arg0) {
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 func_80800700_ch2dbaddy(Actor *, s32);
    u32 temp_t6;

    temp_t6 = (u32) arg0->unk70_10;
    if (temp_t6 != 0x13) {
        if (temp_t6 == 0x15) {
            _sucoaster_entrypoint_10(arg0, 3);
        }
    } else {
        func_80800700_ch2dbaddy(arg0, 0x14);
    }
}

/* extern */

void func_808004F4_ch2dbaddy(Actor *arg0) { s32 _subaddieDll_entrypoint_3(Actor *); s32 _sucoaster_entrypoint_10(Actor *, s32); s32 _sucoaster_entrypoint_6(Actor *, f32, ...); s32 var_a2; if ((arg0->unk70_10 == 2) || (arg0->unk70_10 == 3) || (arg0->unk70_10 == 8)) { if (_subaddieDll_entrypoint_3(arg0) != 0) { var_a2 = 0x15; } else { var_a2 = 0xE; } _sucoaster_entrypoint_6(arg0, 200.0f, var_a2); _sucoaster_entrypoint_10(arg0, var_a2); } }

s32 func_80800564_ch2dbaddy(Actor *arg0, s32 arg1, u32 arg2) {
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 func_800D9058(f32);
    void func_801020DC(void *, s32);
    void func_8010297C(void *, f32, f32, f32);
    s32 func_80800700_ch2dbaddy(Actor *, s32);

    switch (arg2) {
    case 0:
        if (arg0->unk70_10 == 19) {
            return 0;
        }
        switch (arg1) {
        case 2:
        case 3:
            func_80800700_ch2dbaddy(arg0, 21);
            break;
        case 4:
            func_80800700_ch2dbaddy(arg0, 21);
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
        func_80800700_ch2dbaddy(arg0, 21);
        break;
    case 3:
        arg0->unk6C_0 = func_800D9058(2.0f);
        func_8010297C(arg0, arg0->unk54, 70.0f, 120.0f);
        if (arg0->unk70_10 == 8) {
            func_80800700_ch2dbaddy(arg0, 21);
        }
        return 0;
    case 4:
        if (arg0->unk70_10 == 19) {
            break;
        }
        return 1;
    case 1:
    case 6:
        return 1;
    case 5:
        func_80800700_ch2dbaddy(arg0, 12);
        break;
    case 8:
        if (arg1 == 17) {
            func_801020DC(arg0, 0);
        }
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

s32 func_80800700_ch2dbaddy(Actor *arg0, s32 arg1) {
    u8 *_sucoaster_entrypoint_3();
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 _sucoaster_entrypoint_6(Actor *, f32, ...);
    void func_8010A570(Actor *);
    void func_80800850_ch2dbaddy();
    s32 func_801032B0(Actor *, u16, u16);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern u32 D_80800AE4_ch2dbaddy[4];
    u8 *sp24;

    sp24 = _sucoaster_entrypoint_3();
    switch (arg1) {
        case 12:
            func_8010A570(arg0);
            _sucoaster_entrypoint_10(arg0, arg1);
            break;
        case 21:
            _sucoaster_entrypoint_10(arg0, arg1);
            _sucoaster_entrypoint_6(arg0, 200.0f);
            break;
        case 19:
            _sucoaster_entrypoint_10(arg0, arg1);
            func_8010A570(arg0);
            if (!arg0->unk64_29) {
                func_80800850_ch2dbaddy(arg0);
                func_801032B0(arg0, *(u16 *)(sp24 + 6), 0);
            }
            arg0->unk64_16 = 0;
            break;
        case 20:
            _sucoaster_entrypoint_10(arg0, arg1);
            arg0->unk64_16 = 1;
            arg0->unk64_20 = 0;
            func_8010A570(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800AE4_ch2dbaddy);
            BT_NATIVE_ONLY(return 0;) break;
    }
}

void func_80800820_ch2dbaddy(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    extern u32 D_80800AF4_ch2dbaddy[3];
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800AF4_ch2dbaddy, 0.1f);
}    typedef struct { u8 pad0[0x6]; s16 unk6; } Obj2dbaddy_func_80800850_ch2dbaddy_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

#ifdef BT_NATIVE
void func_80800850_ch2dbaddy(s32 bt_a0) {
#else
void func_80800850_ch2dbaddy(void) {
#endif
    s32 func_800DC128(s32, s32);
    u8 *_sucoaster_entrypoint_3();
    extern s16 D_80800B00_ch2dbaddy[];
    u8 *sp1C;

    sp1C = _sucoaster_entrypoint_3();
    (((Obj2dbaddy_func_80800850_ch2dbaddy_sp1C *)sp1C)->unk6) = D_80800B00_ch2dbaddy[func_800DC128(0, 3)];
}
/* data_to_c.py: from asm/data/overlays/ch/2dbaddy.data.s */
extern u8 D_80800984_ch2dbaddy[];
void func_80105834(Actor*);
void _sucoaster_entrypoint_20();
void _sucoaster_entrypoint_1();
OSThread *_sucoasterhit_entrypoint_0(void);
void func_80107C2C();
extern u8 D_80800970_ch2dbaddy[];
u8 D_80800970_ch2dbaddy[20] BT_DATA(4, overlays_ch_2dbaddy, 0x0) = { 0x00, 0x13, 0x00, 0x01, 0x00, 0x0E, 0x00, 0x01, 0x00, 0x0D, 0x00, 0x01, 0x00, 0x10, 0x00, 0x01, 0x00, 0x13, 0x00, 0x03 };
u8 D_80800984_ch2dbaddy[184] BT_DATA(4, overlays_ch_2dbaddy, 0x14) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xA6, 0x66, 0x66, 0x03, 0x80, 0x00, 0x01, 0x40, 0xA6, 0x66, 0x66, 0x03, 0x80, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x7C, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x7C, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x7C, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x7C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x7C, 0x00, 0x01, 0x3F, 0x35, 0xC2, 0x8F, 0x03, 0x7D, 0x00, 0x02, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x7C, 0x00, 0x01, 0x3F, 0x00, 0x00, 0x00, 0x03, 0x7F, 0x00, 0x02, 0x3F, 0xB3, 0x33, 0x33, 0x01, 0xEA, 0x00, 0x02, 0x3F, 0xB3, 0x33, 0x33, 0x01, 0xEA, 0x00, 0x84, 0x40, 0xA6, 0x66, 0x66, 0x03, 0x80, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x7C, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xA0, 0x00, 0x00, 0x03, 0x7B, 0x00, 0x44, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x7C, 0x00, 0x01, 0x3F, 0xA0, 0x00, 0x00, 0x03, 0x7B, 0x00, 0x44, 0x3F, 0xA0, 0x00, 0x00, 0x03, 0x7B, 0x00, 0x02, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x7C, 0x00, 0x01, 0x3F, 0x8F, 0x5C, 0x29, 0x03, 0x7E, 0x00, 0x02 };
u8 D_80800A3C_ch2dbaddy [96] BT_DATA(4, overlays_ch_2dbaddy, 0xCC) = { 0, 0, 0, 0x12, 0x40, 0x66, 0x66, 0x66, 0, 0x13, 0, 0, 0, 0, 0, 0x1C, 0x3F, 0xE6, 0x66, 0x66, 0, 0x1E, 0, 0, 0, 0, 0, 0xE, 0x3F, 0xE6, 0x66, 0x66, 0, 0x10, 0, 0, 0, 0, 0, 0x2B, 0x40, 0xC, 0xCC, 0xCD, 0, 0x1E, 0, 0, 0, 0, 0, 0x2A, 0x40, 0xC, 0xCC, 0xCD, 0, 0x10, 0, 0, 0, 0, 0, 0x1A, 0x40, 0xC, 0xCC, 0xCD, 2, 0x18, 0, 0, 0, 0, 0, 0xC, 0x40, 0xC, 0xCC, 0xCD, 2, 0xA, 0, 0, 0, 0, 0, 0x46, 0x40, 0x73, 0x33, 0x33, 2, 0x44, 0, 0 };
ActorData D_80800A9C_ch2dbaddy [1] BT_DATA(4, overlays_ch_2dbaddy, 0x12C) = { { 759, 1124, 0, 19, (void *)D_80800984_ch2dbaddy, (void (*)(struct Actor *))func_808000A0_ch2dbaddy, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_sucoaster_entrypoint_20, 196608000, 0, 0, 0, 17159, 809, (void (*)(struct Actor *))_sucoaster_entrypoint_1, (BtIntPtr)_sucoasterhit_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_8080000C_ch2dbaddy, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31694, 21533, (void (*)(struct Actor *, long, long))func_808002A8_ch2dbaddy, (BtIntPtr)D_80800970_ch2dbaddy } };
u32 D_80800AE4_ch2dbaddy[4] BT_DATA(4, overlays_ch_2dbaddy, 0x174) = { 0x130520, 0xD00F3, 0x10C0018, 0 };
u32 D_80800AF4_ch2dbaddy[3] BT_DATA(4, overlays_ch_2dbaddy, 0x184) = { 0x1305EC, 0xD00F3, 0x10C0000 };
s16 D_80800B00_ch2dbaddy [8] BT_DATA(4, overlays_ch_2dbaddy, 0x190) = { 2072, 2073, 2074, 0, 0, 0, 0, 0 };
