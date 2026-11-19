#include "common.h"

typedef struct { u8 pad0[0xC]; s16 unkC; s16 unkE; u8 pad10[0x8]; u32 unk18; } Objplayer_sucoasterplayer_entrypoint_0_sp24; /* offsets.py genstruct: fields from raw offsets on sp24; rename once understood */ typedef struct { u8 pad0[0x24]; f32 unk24; u8 pad28[0x3C]; s32 unk64; u8 pad68[0xA]; u16 unk72; } Objplayer_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void sucoasterplayer_entrypoint_0(void *arg0) {
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    void _sucoaster_entrypoint_11(Actor *arg0, f32 arg1);
    s32 _sucoaster_entrypoint_16(void *, s32);
    void _sucoaster_entrypoint_19(Actor *arg0);
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    s32 _sucoasterdata_entrypoint_2(u32);
    s32 _sucoasterdata_entrypoint_3(u32);
    s32 _sucoasterhit_entrypoint_1(void *);
    void _sucoasterhit_entrypoint_2(Actor *arg0);
    s32 func_80016B54(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_801021BC(void *, s32);
    void func_80102BF8(void *, f32, f32, f32);
    s32 func_8080076C_sucoasterplayer(void *, void *);
    s32 sucoasterplayer_entrypoint_2(void *, f32);
    int sucoasterplayer_entrypoint_3(void *);
    struct CoasterFlags {
        u8 pad[0x18];
        BT_BITFIELD_ORDER(u32 : 10, u32 : 21);
        BT_BITFIELD_ORDER(u32 hit : 1, u32 hit : 1; u32  : 10);
    };
    void *sp24;

    sp24 = func_80100094(arg0, 0);
    switch ((u32)*&((Objplayer_arg0 *)arg0)->unk72 >> 10) {
    case 2:
        if (func_8080076C_sucoasterplayer(arg0, sp24) == 0) {
            if (sucoasterplayer_entrypoint_3(arg0) != 0) {
                if ((f32)*&((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unkE >=
                    ((f32)*&((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unkC * 0.00390625f) *
                    (f32)_sucoasterdata_entrypoint_2(((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unk18 >> 28)) {
                    _sucoaster_entrypoint_9(arg0, 3, 6);
                }
            } else if (func_801021BC(arg0, 7) != 0 &&
                       func_80016B54((u32)(((Objplayer_arg0 *)arg0)->unk64 * 8) >> 30, 1) == 1) {
                _sucoaster_entrypoint_9(arg0, 7, 6);
            }
        }
        sucoasterplayer_entrypoint_2(arg0, 30.0f);
        break;
    case 3:
        _sucoaster_entrypoint_11(arg0, (f32)_sucoasterdata_entrypoint_2(((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unk18 >> 28));
        if (func_8080076C_sucoasterplayer(arg0, sp24) == 0) {
            if (sucoasterplayer_entrypoint_3(arg0) != 0) {
                if ((f32)_sucoasterdata_entrypoint_3(((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unk18 >> 28) *
                    ((f32)*&((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unkC / 256.0f) <
                    (f32)*&((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unkE) {
                    _sucoaster_entrypoint_9(arg0, 8, 6);
                }
                if ((f32)*&((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unkE <
                    ((f32)*&((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unkC * 0.00390625f) *
                    (f32)_sucoasterdata_entrypoint_2(((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unk18 >> 28)) {
                    _sucoaster_entrypoint_9(arg0, 2, 6);
                }
            } else {
                _sucoaster_entrypoint_9(arg0, 2, 6);
            }
        }
        sucoasterplayer_entrypoint_2(arg0, 30.0f);
        break;
    case 8:
        _sucoaster_entrypoint_11(arg0, (f32)_sucoasterdata_entrypoint_3(((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unk18 >> 28));
        if (func_8080076C_sucoasterplayer(arg0, sp24) == 0) {
            if (sucoasterplayer_entrypoint_3(arg0) != 0) {
                if ((f32)_sucoasterdata_entrypoint_3(((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unk18 >> 28) *
                    ((f32)*&((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unkC / 256.0f) >=
                    (f32)*&((Objplayer_sucoasterplayer_entrypoint_0_sp24 *)sp24)->unkE) {
                    _sucoaster_entrypoint_9(arg0, 3, 6);
                }
            } else {
                _sucoaster_entrypoint_9(arg0, 3, 6);
            }
        }
        sucoasterplayer_entrypoint_2(arg0, 30.0f);
        break;
    case 9:
        _sucoaster_entrypoint_19(arg0);
        _subaddiejoy_entrypoint_9(arg0, (s8 *)arg0 + 0x54, 1);
        func_80102BF8(arg0, 0.3f, 1.0f, 1000.0f);
        sucoasterplayer_entrypoint_2(arg0, 30.0f);
        _sucoaster_entrypoint_16(arg0, 1);
        _sucoaster_entrypoint_16(arg0, 6);
        if (!((struct CoasterFlags *)sp24)->hit &&
            _sucoaster_entrypoint_16(arg0, 5) != 0) {
            _sucoasterhit_entrypoint_2(arg0);
        }
        if (func_80101DDC(arg0) != 0) {
            _sucoaster_entrypoint_9(arg0, 3, 6);
        }
        break;
    case 11:
        _sucoaster_entrypoint_16(arg0, 2);
        if (func_80101DDC(arg0) != 0) {
            _sucoaster_entrypoint_9(arg0, 3, 6);
        }
        break;
    case 12:
    case 13:
    case 18:
        *(u8 *)((s8 *)arg0 + 0x64) &= ~1;
        break;
    case 15:
        _sucoasterhit_entrypoint_1(arg0);
        break;
    case 7:
        _sucoaster_entrypoint_19(arg0);
        sucoasterplayer_entrypoint_3(arg0);
        _sucoaster_entrypoint_16(arg0, 0);
        func_80102BF8(arg0, 0.3f, 1.0f, 1000.0f);
        if (func_80101DDC(arg0) != 0) {
            _sucoaster_entrypoint_9(arg0, 2, 6);
        }
        break;
    }
}

/* extern */

void sucoasterplayer_entrypoint_1(Actor *arg0) {
    s32 _subaddieDll_entrypoint_3(Actor *);
    void _subaddiefade_entrypoint_3(Actor *);
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    int func_800DC298(f32);
    s32 func_80107070(Actor *, s32);
    struct CoasterFlags {
        u8 pad0[0x70];
        BT_BITFIELD_ORDER(u32 unk70_25 : 7, u32 pad70_0 : 4);
        BT_BITFIELD_ORDER(u32 pad70_10 : 15, u32 unk70_4 : 6);
        BT_BITFIELD_ORDER(u32 unk70_4 : 6, u32 pad70_10 : 15);
        BT_BITFIELD_ORDER(u32 pad70_0 : 4, u32 unk70_25 : 7);
    } *flags = (void *)arg0;
    s32 var_a1;

    if (!arg0->unk64_29) {
        if (arg0->unk70_10 != 12) {
            if (flags->unk70_25 && flags->unk70_4) {
                if (_subaddieDll_entrypoint_3(arg0)) {
                    if (arg0->unk70_10 == 2) {
                        if (func_800DC298(0.5f)) {
                            var_a1 = 2;
                        } else {
                            var_a1 = 3;
                        }
                        _sucoaster_entrypoint_9(arg0, var_a1, 7);
                    }
                } else if (func_80107070(arg0, 1) == 0) {
                    _subaddiefade_entrypoint_3(arg0);
                    _sucoaster_entrypoint_10(arg0, 14);
                }
                arg0->unk14 |= 0x80000;
                goto block_17;
            }
        }
    } else {
        arg0->unk14 &= ~0x80000;
        switch (arg0->unk70_10) {
        case 5:
        case 6:
        case 7:
        case 10:
            _sucoaster_entrypoint_9(arg0, 2, 6);
            break;
        case 4:
            _sucoaster_entrypoint_9(arg0, 3, 6);
            break;
        }
block_17:
        arg0->unk54 = arg0->rotation[1];
    }
}    typedef struct { u8 pad0[0xE]; s16 unkE; } Objplayer_sucoasterplayer_entrypoint_2_sp24; /* offsets.py genstruct: fields from raw offsets on sp24; rename once understood */

/* extern */

s32 sucoasterplayer_entrypoint_2(void *arg0, f32 arg1) {
    void _sucoaster_entrypoint_18(BtIntPtr arg0);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F2094(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80107C00(void);
    s32 func_8010B990(Actor *, s32);
    void *sp24;
    f32 sp20;

    sp24 = func_80100094(arg0, 0);
    (((Objplayer_arg0 *)arg0)->unk24) = func_800F15F8((((Objplayer_arg0 *)arg0)->unk24), (f32) (((Objplayer_sucoasterplayer_entrypoint_2_sp24 *)sp24)->unkE), func_80107C00() * arg1);
    _sucoaster_entrypoint_18(arg0);
    sp20 = func_800F2094(((Actor *)arg0)->unk54, ((Actor *)arg0)->rotation[1]);
    func_80102BF8(arg0, 0.3f, 1.0f, 1000.0f);
    if (sp20 >= 100.0f) {
        return 1;
    } else {
        func_8010B990(arg0, 0x205025);
    }
    return 1;
}

/* extern */

int sucoasterplayer_entrypoint_3(void *arg0) {
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    void _sucoaster_entrypoint_6(Actor *arg0, f32 arg1);
    s32 _sucoasterdata_entrypoint_4(u32);
    void *func_80100094(Actor *, u32);
    Actor *sp1C;
    f32 sp18;

    sp1C = func_80100094(arg0, 0);
    sp18 = _subaddiejoy_entrypoint_9(arg0, &((Actor *)arg0)->unk54, 1);
    _sucoaster_entrypoint_6(arg0, (f32) _sucoasterdata_entrypoint_4(sp1C->actorData[0] >> 28) * sp18);
    return sp18 != 0.0f;
}    typedef struct { u8 pad0[0x18]; u32 unk18; } Objplayer_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

/* extern */

s32 func_8080076C_sucoasterplayer(void *arg0, void *arg1) {
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    void *_sucoasterdata_entrypoint_1(u32);
    s32 func_80016B30(u32, s32);
    if (((*(u16 *)((s8 *)(_sucoasterdata_entrypoint_1((u32) (((Objplayer_arg1 *)arg1)->unk18) >> 0x1C)) + (0x4A))) != 0) && (func_80016B30((u32) ((((Objplayer_arg0 *)arg0)->unk64) * 8) >> 0x1E, 1) == 1)) {
        return _sucoaster_entrypoint_9(arg0, 9, 6);
    }
    return 0;
}
