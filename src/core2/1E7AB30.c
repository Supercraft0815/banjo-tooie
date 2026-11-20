#include "core2/1E7AB30.h"

typedef struct {
    u8 check_player;
    u8 show_value;
    u8 section_blocks_loss;
    u8 reset_form;
    u8 refresh_kind;
    u8 suppress_count;
    u8 last_form;
    u8 form_request;
    u8 requested_form;
    u8 item_kind;
    u8 padding[6];
} FormHudState;

BT_IDO_ONLY(extern) FormHudState D_80127090;
#ifndef BT_NATIVE
extern s8 D_80127092;
extern u8 D_80127094, D_80127097, D_80127099;
#endif
BT_NATIVE_ONLY(_Static_assert(sizeof(FormHudState) == 0x10, "form HUD state");)

s32 func_800A1240(u32 arg0) {
    u8 func_800D5210(s32);
    void func_800D2748(s32, s32);
    u32 value = func_800D5210(arg0);
    BT_NATIVE_ONLY(u32 bt_result = value;)
    D_80127090.item_kind = value;
    D_80127090.last_form = arg0;
    /* The block preserves IDO's global-address reuse after the call. */
    do {
        func_800D2748(0xCF, value & 0xFF);
    } while (0);
    value = D_80127090.item_kind;
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
    s32 transformation;
    s32 value;

    if ((BT_DATA_FIELD(D_80127090.refresh_kind, D_80127094) == 0) && (func_800D3948() == 0) &&
        (func_800DA298(0x6B6) == 0) && (func_800D3E40(9) == 0) &&
        (BT_DATA_FIELD(D_80127090.form_request, D_80127097) == 0)) {
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
    u32 func_8009E958(void);
    s32 func_800A1240(u32);
    void func_800D517C(void);
    D_80127090.show_value = 0;
    D_80127090.check_player = 0;
    func_800D517C();
    func_800A1240(func_8009E958());
}

void func_800A13A0(void) {
    D_80127090.check_player = 1;
}

void func_800A13B0(s32 arg0) {
    BtIntPtr _gcsectionDll_entrypoint_2(s32);
    s32 _gcsectionDll_entrypoint_3(BtIntPtr, s32);
    s32 func_800F8B64(void);
    s32 func_800F99E8(void);

    D_80127090.section_blocks_loss = _gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(arg0), 0x1000);
    D_80127090.show_value = 0;
    if (func_800F8B64() != 0) {
        D_80127090.show_value = 1;
        D_80127090.reset_form = 1;
    }
    if (func_800F99E8() != 0) {
        D_80127090.show_value = 1;
    }
    D_80127090.refresh_kind = 1;
    if (_gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(arg0), 0x1000) != 0) {
        D_80127090.suppress_count = 1;
    } else {
        D_80127090.suppress_count = 0;
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
    s32 pending;
    s32 state;
    s32 busy;
    u8 request;

    pending = 0;
    if (D_80127090.reset_form != 0) {
        func_800D5034(0, func_8008FD48());
        D_80127090.reset_form = 0;
    }
    if (D_80127090.check_player != 0) {
        if (func_80090128() != 0 && D_80127090.section_blocks_loss == 0) {
            D_80127090.show_value = 1;
        }
        D_80127090.check_player = 0;
    }
    if (D_80127090.refresh_kind != 0) {
        func_800A1240(func_8008FD48());
        D_80127090.refresh_kind = 0;
    }
    if (D_80127090.show_value != 0) {
        if (func_800C95D4() != 0) {
            pending = 1;
            D_80127090.show_value = 0;
        }
    } else {
        state = func_800D4E7C(func_8008FD48());
        if (state != 0 && state < 3) {
            pending = 1;
        }
    }
    if (D_80127090.form_request != 0) {
        pending = 0;
        func_800A1624(0);
        func_800CE864(1);
        func_800CF7F4(0);
        busy = func_800D2820(0xCF) != 0 || func_800D2820(0xCD) != 0;
        if (D_80127090.requested_form != 0x11) {
            func_800D284C(0xC9);
            busy |= func_800D2820(0xC9);
        }
        if (busy == 0) {
            request = D_80127090.form_request;
            D_80127090.form_request = 0;
            if (request == 1) {
                func_800A1240(D_80127090.requested_form);
                func_800A1294(1);
                D_80127090.requested_form = 0;
            } else {
                D_80127090.last_form = 0;
            }
        }
    }
    if (func_80090128() != 0 && pending != 0 && D_80127090.suppress_count == 0) {
        func_800A1294(0);
    }
}

void func_800A1618(s32 arg0) {
    BT_DATA_FIELD(D_80127090.section_blocks_loss, D_80127092) = arg0;
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
    if ((arg0 != D_80127090.last_form) || ((D_80127090.requested_form != 0) && (arg0 != (D_80127090.requested_form)))) {
        D_80127090.form_request = 1;
        D_80127090.requested_form = (u8) arg0;
    }
}

void func_800A1694(void) {
    BT_DATA_FIELD(D_80127090.form_request, D_80127097) = 2;
}

u32 func_800A16A4(void) {
    return BT_DATA_FIELD(D_80127090.form_request, D_80127097);
}

u32 func_800A16B0(void) {
    return BT_DATA_FIELD(D_80127090.item_kind, D_80127099);
}

void func_800A16BC(s32 arg0) {
    if (arg0 != 0) {
        D_80127090.suppress_count = (u8) (D_80127090.suppress_count + 1);
        return;
    }
    D_80127090.suppress_count = (u8) (D_80127090.suppress_count - 1);
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
    s32 transformation;

    if (arg0->unk158 != 0) {
        func_800F9EC0(arg0->unk184, arg1);
        return;
    }
    transformation = func_800A3274(arg0);
    if (arg1 >= 0 || (u8)BT_DATA_FIELD(D_80127090.section_blocks_loss, D_80127092) == 0) {
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
    BT_NATIVE_ONLY(void) BT_IDO_ONLY(s32) func_800F9F74(s32 BT_PASS2(, s32));
    func_800F9F74((((PlayerState *)arg0)->unk184) BT_PASS2(, bt_a0));
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
