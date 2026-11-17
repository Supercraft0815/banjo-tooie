#include "core2/1E7AB30.h"

typedef struct { s8 unk0; s8 unk1; u8 pad2[0x3]; u8 unk5; s8 unk6; s8 unk7; u8 unk8; u8 unk9; } Obj1E7AB30_D_80127090; /* offsets.py genstruct: fields from raw offsets on &D_80127090; rename once understood */ s32 func_800A1240(u32 arg0) {
    extern s8 D_80127090;
    u8 func_800D5210(s32);
    void func_800D2748(s32, s32);
    u32 value = func_800D5210(arg0);
    BT_NATIVE_ONLY(u32 bt_result = value;)
    ((Obj1E7AB30_D_80127090 *)&D_80127090)->unk9 = value;
    ((Obj1E7AB30_D_80127090 *)&D_80127090)->unk6 = arg0;
    /* The block preserves IDO's global-address reuse after the call. */
    do {
        func_800D2748(0xCF, value & 0xFF);
    } while (0);
    value = ((Obj1E7AB30_D_80127090 *)&D_80127090)->unk9;
    func_800D2748(0xCD, value); BT_NATIVE_ONLY(return (s8)bt_result;)
}

void func_800A1294(s32 arg0) {
    s32 func_8008FD48();
    s32 func_800D2498(u32, s32, u32);
    s32 func_800D24E8(s32, s32, u32);
    s32 func_800D3948(void);
    s32 func_800D3E40(s32);
    s32 func_800D4E7C(s32);
    u8 func_800D4EB8(s32);
    s32 func_800DA298(s32);
    extern u8 D_80127094;
    extern u8 D_80127097;
    s32 transformation;
    s32 value;

    if ((D_80127094 == 0) && (func_800D3948() == 0) &&
        (func_800DA298(0x6B6) == 0) && (func_800D3E40(9) == 0) &&
        (D_80127097 == 0)) {
        transformation = func_8008FD48();
        value = func_800D4EB8(transformation);
        if (value != 0) {
            if (arg0 != 0) {
                func_800D2498(0xCF, func_800D4E7C(transformation), value);
            } else {
                func_800D24E8(0xCF, func_800D4E7C(transformation), value);
            }
        }
    }
}

/* extern */

void func_800A1364(void) {
    extern s8 D_80127090;
    u32 func_8009E958(void);
    s32 func_800A1240(u32);
    void func_800D517C(void);
    (((Obj1E7AB30_D_80127090 *)&D_80127090)->unk1) = 0;
    (((Obj1E7AB30_D_80127090 *)&D_80127090)->unk0) = 0;
    func_800D517C();
    func_800A1240(func_8009E958());
}

void func_800A13A0(void) {
    extern s8 D_80127090;
    D_80127090 = 1;
}

void func_800A13B0(s32 arg0) {
    extern s8 D_80127090;
    BtIntPtr _gcsectionDll_entrypoint_2(s32);
    s32 _gcsectionDll_entrypoint_3(BtIntPtr, s32);
    s32 func_800F8B64(void);
    s32 func_800F99E8(void);

    *((s8 *)&D_80127090 + 2) = _gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(arg0), 0x1000);
    *((s8 *)&D_80127090 + 1) = 0;
    if (func_800F8B64() != 0) {
        *((s8 *)&D_80127090 + 1) = 1;
        *((s8 *)&D_80127090 + 3) = 1;
    }
    if (func_800F99E8() != 0) {
        *((s8 *)&D_80127090 + 1) = 1;
    }
    *((s8 *)&D_80127090 + 4) = 1;
    if (_gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(arg0), 0x1000) != 0) {
        *((s8 *)&D_80127090 + 5) = 1;
    } else {
        *((s8 *)&D_80127090 + 5) = 0;
    }
}

void func_800A1450(void) {
    s32 func_8008FD48();
    s32 func_80090128();
    void func_800A1294(s32);
    void func_800A1624(s32);
    s32 func_800C95D4(void);
    void func_800CE864();
    void func_800CF7F4(u32);
    s32 func_800D2820(s32);
    s32 func_800D284C(s32);
    s32 func_800D4E7C(s32);
    void func_800D5034(s32 arg0, s32 arg1);
    extern s8 D_80127090;
    s32 pending;
    s32 state;
    s32 busy;
    u8 request;

    pending = 0;
    if (((u8 *)&D_80127090)[3] != 0) {
        func_800D5034(0, func_8008FD48());
        ((u8 *)&D_80127090)[3] = 0;
    }
    if (((u8 *)&D_80127090)[0] != 0) {
        if (func_80090128() != 0 && ((u8 *)&D_80127090)[2] == 0) {
            ((u8 *)&D_80127090)[1] = 1;
        }
        ((u8 *)&D_80127090)[0] = 0;
    }
    if (((u8 *)&D_80127090)[4] != 0) {
        func_800A1240(func_8008FD48());
        ((u8 *)&D_80127090)[4] = 0;
    }
    if (((u8 *)&D_80127090)[1] != 0) {
        if (func_800C95D4() != 0) {
            pending = 1;
            ((u8 *)&D_80127090)[1] = 0;
        }
    } else {
        state = func_800D4E7C(func_8008FD48());
        if (state != 0 && state < 3) {
            pending = 1;
        }
    }
    if (((u8 *)&D_80127090)[7] != 0) {
        pending = 0;
        func_800A1624(0);
        func_800CE864(1);
        func_800CF7F4(0);
        busy = func_800D2820(0xCF) != 0 || func_800D2820(0xCD) != 0;
        if (((u8 *)&D_80127090)[8] != 0x11) {
            func_800D284C(0xC9);
            busy |= func_800D2820(0xC9);
        }
        if (busy == 0) {
            request = ((u8 *)&D_80127090)[7];
            ((u8 *)&D_80127090)[7] = 0;
            if (request == 1) {
                func_800A1240(((u8 *)&D_80127090)[8]);
                func_800A1294(1);
                ((u8 *)&D_80127090)[8] = 0;
            } else {
                ((u8 *)&D_80127090)[6] = 0;
            }
        }
    }
    if (func_80090128() != 0 && pending != 0 && ((u8 *)&D_80127090)[5] == 0) {
        func_800A1294(0);
    }
}    typedef struct { s8 unk0; } Obj1E7AB30_D_80127092; /* offsets.py genstruct: fields from raw offsets on &D_80127092; rename once understood */

void func_800A1618(s32 arg0) {
    extern s8 D_80127092;
    ((Obj1E7AB30_D_80127092 *)&D_80127092)->unk0 = arg0;
}

/* extern */

void func_800A1624(s32 arg0) {
    void func_800A1294(s32);
    s32 func_800D284C(s32);
    if (arg0 != 0) {
        func_800A1294(0);
        return;
    }
    func_800D284C(0xCF);
}

void func_800A1658(s32 arg0) {
    extern s8 D_80127090;
    if ((arg0 != (*(u8 *)((s8 *)(&D_80127090) + (6)))) || (((((Obj1E7AB30_D_80127090 *)&D_80127090)->unk8) != 0) && (arg0 != (((Obj1E7AB30_D_80127090 *)&D_80127090)->unk8)))) {
        (((Obj1E7AB30_D_80127090 *)&D_80127090)->unk7) = 1;
        (((Obj1E7AB30_D_80127090 *)&D_80127090)->unk8) = (u8) arg0;
    }
}

void func_800A1694(void) {
    extern u8 D_80127097;
    D_80127097 = 2;
}    typedef struct { u8 unk0; } Obj1E7AB30_D_80127097; /* offsets.py genstruct: fields from raw offsets on &D_80127097; rename once understood */

u32 func_800A16A4(void) {
    extern u8 D_80127097;
    return *&((Obj1E7AB30_D_80127097 *)&D_80127097)->unk0;
}    typedef struct { u8 unk0; } Obj1E7AB30_D_80127099; /* offsets.py genstruct: fields from raw offsets on &D_80127099; rename once understood */

u32 func_800A16B0(void) {
    extern u8 D_80127099;
    return *&((Obj1E7AB30_D_80127099 *)&D_80127099)->unk0;
}

void func_800A16BC(s32 arg0) {
    extern s8 D_80127090;
    if (arg0 != 0) {
        (((Obj1E7AB30_D_80127090 *)&D_80127090)->unk5) = (u8) ((((Obj1E7AB30_D_80127090 *)&D_80127090)->unk5) + 1);
        return;
    }
    (((Obj1E7AB30_D_80127090 *)&D_80127090)->unk5) = (u8) ((((Obj1E7AB30_D_80127090 *)&D_80127090)->unk5) - 1);
}

void func_800A16F4(PlayerState *arg0) {
    void _batimer_set(PlayerState *, s32, f32);
    _batimer_set(arg0, 0xE, 3.0f);
}

/* extern */

s32 func_800A1718(PlayerState *arg0) {
    s32 func_800F9F04(s32);
    s32 func_800A3274(PlayerState *);
    s32 func_800D4E7C(s32);
    if ((arg0->unk158) != 0) {
        return func_800F9F04(arg0->unk184);
    }
    return func_800D4E7C(func_800A3274(arg0));
}

/* extern */

s32 func_800A1760(PlayerState *arg0) {
    s32 func_800F9F18(s32);
    s32 func_800A3274(PlayerState *);
    u8 func_800D4EB8(s32);
    if ((arg0->unk158) != 0) {
        return func_800F9F18(arg0->unk184);
    }
    return func_800D4EB8(func_800A3274(arg0));
}

void func_800A17A8(PlayerState *arg0, s32 arg1) {
    void _batimer_set(PlayerState *, s32, f32);
    void func_800A1294(s32);
    s32 func_800A3274(PlayerState *);
    s32 func_800D3E40(s32);
    void func_800D4E18(s32, s32);
    u8 func_800D4EB8(s32);
    void func_800F9EC0(s32, s32);
    extern s8 D_80127092;
    s32 transformation;

    if (arg0->unk158 != 0) {
        func_800F9EC0(arg0->unk184, arg1);
        return;
    }
    transformation = func_800A3274(arg0);
    if (arg1 >= 0 || (u8)D_80127092 == 0) {
        if (func_800D4EB8(transformation) != 0) {
            if (func_800D3E40(9) != 0) {
                arg1 = func_800D4EB8(transformation);
            }
            func_800D4E18(transformation, arg1);
            func_800A1294(0);
            if (func_800D3E40(4) != 0) {
                _batimer_set(arg0, 0xE, 3.0f);
            }
        }
    }
}

/* extern */

void func_800A1870(PlayerState *arg0, s32 arg1) {
    void func_800A1294(s32);
    void func_800F9F2C(s32, s32);
    s32 func_800A3274(PlayerState *);
    void func_800D4FB8(s32 arg0, s32 arg1);
    if ((arg0->unk158) != 0) {
        func_800F9F2C(arg0->unk184, arg1);
        return;
    }
    func_800D4FB8(func_800A3274(arg0), arg1);
    func_800A1294(1);
}

/* extern */

void func_800A18C8(void *arg0 BT_PASS2(, s32 bt_a0)) {
    s32 func_800F9F74(s32);
    func_800F9F74((((PlayerState *)arg0)->unk184));
}

/* extern */

void func_800A18E8(PlayerState *arg0) {
    s32 _batimer_decrement(void *, s32);
    s32 func_800A3274(PlayerState *);
    s32 func_800D4E7C(s32);
    u8 func_800D4EB8(s32);
    void func_800FC660(u32);
    s32 sp1C;
    s32 sp18;

    if (_batimer_decrement(arg0, 0xE) != 0) {
        sp1C = func_800A3274(arg0);
        if ((sp18 = func_800D4E7C(sp1C)) != 0 && sp18 < func_800D4EB8(sp1C)) {
            func_800FC660(8);
            func_800A17A8(arg0, 1);
        }
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s8 D_80127090 BT_DATA(4, bss_core2bss1_0_1, 0x30);
s8 D_80127092 BT_DATA(4, bss_core2bss1_0_1, 0x32);
u8 D_80127094 BT_DATA(4, bss_core2bss1_0_1, 0x34);
u8 D_80127097 BT_DATA(4, bss_core2bss1_0_1, 0x37);
u8 D_80127099 BT_DATA(4, bss_core2bss1_0_1, 0x39);
#endif
