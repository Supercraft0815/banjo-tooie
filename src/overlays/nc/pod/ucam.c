#include "common.h"

/* extern */

typedef struct { s16 unk0; s16 unk2; u8 pad4[0xC]; f32 unk10; u8 pad14[0x4]; f32 unk18; void * unk1C; u32 unk20; u8 pad24[0x18]; f32 unk3C; u8 pad40[0x8]; s16 unk48; u8 pad4A[0x6]; f32 unk50; f32 unk54; s16 unk58; u8 pad5A[0x6]; u8 unk60; u8 pad61[0x2]; s8 unk63; } Objucam_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_ncpoducam(u8 *arg0) {
    void func_800EFD24(f32 *);
    func_800EFD24((f32 *)(arg0 + 4));
    func_800EFD24((f32 *)(arg0 + 0x10));
    func_800EFD24((f32 *)(arg0 + 0x24));
    func_800EFD24((f32 *)(arg0 + 0x30));
    (((Objucam_arg0 *)arg0)->unk63) = 0;
    (((Objucam_arg0 *)arg0)->unk50) = 40.0f;
    (((Objucam_arg0 *)arg0)->unk54) = 1.0f;
}

s16 ncpoducam_entrypoint_0(void) {
    s16 func_8001B668(s32, s32);
    u32 func_800E6A00(void);
    void func_800EFD24(f32 *);
    void *ncpoducam_entrypoint_1(s16);
    s16 handle;
    u8 *data;

    handle = func_8001B668(0, 0x68);
    data = ncpoducam_entrypoint_1(handle);
    *(s32 *)(data + 0x5C) = 0;
    *(s32 *)(data + 0x1C) = 0;
    *(s16 *)(data + 0) = 0;
    *(s16 *)(data + 2) = 0;
    func_800EFD24((f32 *)(data + 0x3C));
    func_800EFD24((f32 *)(data + 4));
    func_800EFD24((f32 *)(data + 0x10));
    *(s16 *)(data + 0x48) = 0;
    *(s32 *)(data + 0x4C) = 0;
    *(s16 *)(data + 0x58) = -1;
    data[0x60] = 0xFF;
    data[0x62] = 0;
    data[0x65] = func_800E6A00();
    return handle;
}

/* extern */

 void *ncpoducam_entrypoint_1(s16 arg0) {
    void *func_8001B798(s16);
    return func_8001B798(arg0);
}

/* extern */

void ncpoducam_entrypoint_2(u8 *arg0, s16 *arg1, s32 arg2) {
    void func_8080145C_ncpoducam(u8 *, s16 *, s32);
    (((Objucam_arg0 *)arg0)->unk58) = arg2;
    func_8080145C_ncpoducam(arg0, arg1, 1);
}    typedef struct { u8 pad0[0x12]; u16 unk12; } Objucam_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

void ncpoducam_entrypoint_3(void *arg0, void *arg1) {
    (((Objucam_arg0 *)arg0)->unk1C) = arg1;
    (((Objucam_arg0 *)arg0)->unk20) = ((u32) (((Objucam_arg1 *)arg1)->unk12)) >> 1;
}

void ncpoducam_entrypoint_4(s16 *arg0, s32 arg1) {
    arg0[36] = arg1;
}

s32 ncpoducam_entrypoint_5(s16 *arg0) {
    return arg0[36];
}

void func_80800160_ncpoducam(u8 *arg0) {
    void func_8001B754(s16 handle);
    s16 temp_a0;
    s16 temp_a1;

    temp_a1 = (((Objucam_arg0 *)arg0)->unk0);
    if (temp_a1 != 0) {
        func_8001B754(temp_a1);
        (((Objucam_arg0 *)arg0)->unk0) = 0;
    }
    temp_a0 = (((Objucam_arg0 *)arg0)->unk2);
    if (temp_a0 != 0) {
        func_8001B754(temp_a0);
        (((Objucam_arg0 *)arg0)->unk2) = 0;
    }
}

void ncpoducam_entrypoint_6(s16 arg0) {
    void func_8001B754(s16 handle);
    func_80800160_ncpoducam(ncpoducam_entrypoint_1(arg0));
    func_8001B754(arg0);
}

s32 func_808001F0_ncpoducam(void *arg0, s32 arg1) {
    return arg1 == -1 ? 0 : ((u32)arg1 == ((u32)*(u16 *)((u8 *)arg0 + 0x12) >> 1));
}

s32 func_8080021C_ncpoducam(void *arg0) {
    s32 func_800EE7F8();
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800F5BC4(BtIntPtr arg0, f32 *arg1);
    void func_80103DFC(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 sp54[3];
    f32 *sp24;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    if (((Objucam_arg0 *)arg0)->unk48 & 1) {
        if (func_808001F0_ncpoducam(((Objucam_arg0 *)arg0)->unk1C, *(s32 *)((u8 *)arg0 + 0x20))) {
            func_80103DFC(func_80106790(*(Unk80132ED0 **)((u8 *)arg0 + 0x1C)), sp54);
            if ((((Objucam_arg0 *)arg0)->unk48 & 0x400) && *((u8 *)arg0 + 0x63)) {
                sp24 = &((Objucam_arg0 *)arg0)->unk3C;
                func_800EFB24(sp44, sp54, sp24);
                func_800EF334(sp44, 0.3f);
                func_800EF04C(sp24, sp44);
                return 1;
            }
            func_800EE7F8(&((Objucam_arg0 *)arg0)->unk3C, sp54);
            *((u8 *)arg0 + 0x63) = 1;
        }
        return 1;
    }
    if (((Objucam_arg0 *)arg0)->unk48 & 0x40) {
        func_800F5BC4(func_800F54E4(), sp38);
        func_800F5A00(func_800F54E4(), sp54);
        func_800EF04C(sp54, sp38);
        if ((((Objucam_arg0 *)arg0)->unk48 & 0x400) && *((u8 *)arg0 + 0x63)) {
            sp24 = &((Objucam_arg0 *)arg0)->unk3C;
            func_800EFB24(sp2C, sp54, sp24);
            func_800EF334(sp2C, 0.3f);
            func_800EF04C(sp24, sp2C);
            return 1;
        }
        *((u8 *)arg0 + 0x63) = 1;
        func_800EE7F8(&((Objucam_arg0 *)arg0)->unk3C, sp54);
        return 1;
    }
    if (((Objucam_arg0 *)arg0)->unk48 & 0x80) {
        return 1;
    }
    return 0;
}

void func_808003A8_ncpoducam(u8 *arg0, s32 arg1) {
    void _cadbfunc_entrypoint_24(s32 *);
    Unk80132ED0 *_subaddiefind_entrypoint_12(s32);
    void _suspline_entrypoint_3(f32 arg0[][3], s32 arg1, f32 *arg2);
    f32 _suspline_entrypoint_4(BtIntPtr, s32);
    void _suspline_entrypoint_5(BtIntPtr, f32 *);
    f32 func_800136E4(f32);
    void *func_8001B798(s16);
    BT_IDO_ONLY(s32 func_800A5800(s16);) BT_NATIVE_ONLY(u8 *func_800A5800(s32);)
    s32 func_800EE7F8();
    void func_800EF04C(f32 *, f32 *);
    void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
    void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
    f32 func_800F1828(f32 *, f32 *);
    void func_800F18FC(f32 *arg0, f32 *arg1, f32 *arg2);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8080021C_ncpoducam(void *);
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    u8 *actor;
    BtIntPtr spline;
    s32 id;

    spline = func_8001B798(*(s16 *)arg0);
    _suspline_entrypoint_3(spline, 0, sp60);
    _suspline_entrypoint_3(spline, 2, sp54);
    _suspline_entrypoint_3(spline, 1, sp48);
    if (*(s16 *)(arg0 + 0x48) & 8) {
        if (func_808001F0_ncpoducam(*(void **)(arg0 + 0x1C), *(s32 *)(arg0 + 0x20))) {
            actor = (u8 *)func_80106790(*(Unk80132ED0 **)(arg0 + 0x1C));
        } else {
            actor = NULL;
        }
    } else {
        func_800A5800(*(s16 *)(arg0 + 0x58));
        _cadbfunc_entrypoint_24(&id);
        actor = (u8 *)_subaddiefind_entrypoint_12(id);
    }
    if (actor != NULL) {
        if (!(*(s16 *)(arg0 + 0x48) & 0x400) || arg0[0x63] == 0) {
            func_800EE7F8((f32 *)(arg0 + 0x30), (f32 *)(actor + 0x44));
            func_800EE7F8((f32 *)(arg0 + 0x24), (f32 *)(actor + 4));
            arg0[0x63] = 1;
        } else {
            *(f32 *)(arg0 + 0x30) += func_800F1DCC(*(f32 *)(actor + 0x44), *(f32 *)(arg0 + 0x30)) * 0.1f;
            *(f32 *)(arg0 + 0x34) += func_800F1DCC(*(f32 *)(actor + 0x48), *(f32 *)(arg0 + 0x34)) * 0.1f;
            *(f32 *)(arg0 + 0x38) += func_800F1DCC(*(f32 *)(actor + 0x4C), *(f32 *)(arg0 + 0x38)) * 0.1f;
            *(f32 *)(arg0 + 0x24) += (*(f32 *)(actor + 4) - *(f32 *)(arg0 + 0x24)) * 0.1f;
            *(f32 *)(arg0 + 0x28) += (*(f32 *)(actor + 8) - *(f32 *)(arg0 + 0x28)) * 0.1f;
            *(f32 *)(arg0 + 0x2C) += (*(f32 *)(actor + 0xC) - *(f32 *)(arg0 + 0x2C)) * 0.1f;
        }
    }
    func_800EE7F8((f32 *)(arg0 + 4), sp54);
    func_800EF6A8((f32 *)(arg0 + 4), (f32 *)(arg0 + 0x30), *(f32 *)(arg0 + 4), *(f32 *)(arg0 + 8), *(f32 *)(arg0 + 0xC));
    func_800EF04C((f32 *)(arg0 + 4), (f32 *)(arg0 + 0x24));
    if (!(*(s16 *)(arg0 + 0x48) & 1)) {
        func_800EE7F8(sp84, sp60);
        func_800EF6A8(sp84, (f32 *)(arg0 + 0x30), sp84[0], sp84[1], sp84[2]);
        func_800EF04C(sp84, (f32 *)(arg0 + 0x24));
        func_800EE7F8(sp78, sp60);
        func_800EF5A0(sp6C, sp48, 100.0f, 0.0f, 0.0f);
        func_800EF04C(sp78, sp6C);
        func_800EF6A8(sp78, (f32 *)(arg0 + 0x30), sp78[0], sp78[1], sp78[2]);
        func_800EF04C(sp78, (f32 *)(arg0 + 0x24));
        *(f32 *)(arg0 + 0x18) = func_800136E4(-func_800F1828(sp84, sp78));
        *(f32 *)(arg0 + 0x10) = -func_800136E4(func_800F1828(sp84, (f32 *)(arg0 + 4)));
        *(f32 *)(arg0 + 0x14) = func_800136E4(func_800F1DF4(sp84, (f32 *)(arg0 + 4)));
    }
    if (func_8080021C_ncpoducam(arg0)) {
        func_800F18FC((f32 *)(arg0 + 0x3C), (f32 *)(arg0 + 4), (f32 *)(arg0 + 0x10));
        *(f32 *)(arg0 + 0x10) = -*(f32 *)(arg0 + 0x10);
        *(f32 *)(arg0 + 0x18) = 0.0f;
    }
    *(f32 *)(arg0 + 0x50) = _suspline_entrypoint_4(spline, 0);
    if (arg1 == 0) {
        _suspline_entrypoint_5(spline, sp54);
    }
}

/* extern */

void func_80800704_ncpoducam(u8 *arg0, s32 arg1) {
    void _suspline_entrypoint_3(f32 arg0[][3], s32 arg1, f32 *arg2);
    f32 _suspline_entrypoint_4(BtIntPtr, s32);
    void _suspline_entrypoint_5(BtIntPtr, f32 *);
    void *func_8001B798(s16);
    void func_800F18FC(f32 *arg0, f32 *arg1, f32 *arg2);
    s32 func_8080021C_ncpoducam(void *);
    register BtIntPtr temp_s1;

    temp_s1 = func_8001B798(*(s16 *)arg0);
    _suspline_entrypoint_3(temp_s1, 0, (f32 *)(arg0 + 4));
    if (func_8080021C_ncpoducam(arg0) == 0) {
        _suspline_entrypoint_3(temp_s1, 1, (f32 *)(arg0 + 0x10));
    } else {
        func_800F18FC((f32 *)(arg0 + 0x3C), (f32 *)(arg0 + 4), (f32 *)(arg0 + 0x10));
        (((Objucam_arg0 *)arg0)->unk10) = (f32) -(((Objucam_arg0 *)arg0)->unk10);
        (((Objucam_arg0 *)arg0)->unk18) = 0.0f;
    }
    (((Objucam_arg0 *)arg0)->unk50) = _suspline_entrypoint_4(temp_s1, 0);
    (((Objucam_arg0 *)arg0)->unk54) = _suspline_entrypoint_4(temp_s1, 1);
    if (arg1 == 0) {
        _suspline_entrypoint_5(temp_s1, (f32 *)(arg0 + 4));
    }
}

void func_808007D0_ncpoducam(u8 *arg0) {
    void *func_8001B798(s16);
    void _suspline_entrypoint_13(void *);
    f32 _suspline_entrypoint_6(void *);
    void _suspline_entrypoint_9(void *, f32);
    void _suspline_entrypoint_14(void *);
    void _suspline_entrypoint_17(void *);
    void *spline;

    switch (arg0[0x60]) {
        case 5:
        case 6:
            spline = func_8001B798(*(s16 *)arg0);
            _suspline_entrypoint_13(spline);
            _suspline_entrypoint_9(spline, _suspline_entrypoint_6(spline));
            _suspline_entrypoint_14(spline);
            _suspline_entrypoint_17(spline);
        case 8:
            return;
    }
}

s32 func_80800854_ncpoducam(u8 *arg0, s16 *arg1) {
    s32 _ncpod_entrypoint_5(s16 *, void *, s32, s16, BtIntPtr);
    s32 _suspline_entrypoint_7(void *);
    void *func_8001B798(s16);
    void *func_80110024(s16 *);
    s32 finished;
    s32 result;

    finished = 0;
    result = _ncpod_entrypoint_5(arg1, func_80110024(arg1), 0xE, *(s16 *)(arg0 + 0x58), 0);
    if (result == 4) {
        return result;
    }
    *(s32 *)(arg0 + 0x4C) = result;
    switch (arg0[0x60]) {
        case 8:
            break;
        case 5:
        case 6:
            finished = _suspline_entrypoint_7(func_8001B798(*(s16 *)arg0));
            break;
    }
    if (finished != 0) {
        result = _ncpod_entrypoint_5(arg1, func_80110024(arg1), 0xC, *(s16 *)(arg0 + 0x58), 0);
        if (result == 4) {
            return result;
        }
        *(s32 *)(arg0 + 0x4C) = result;
    }
    return result;
}

void func_80800944_ncpoducam(u8 *arg0) {
    f32 _glintrosyncDll_entrypoint_5(void);
    f32 func_800D8FF8(void);
    void *func_8001B798(s16);
    void _suspline_entrypoint_16(void *);
    f32 _susplinet_entrypoint_9(void *);
    void _susplinet_entrypoint_11(void *, f32);
    void _susplinet_entrypoint_16(void *, f32, f32);
    f32 delta;
    void *spline;
    f32 position;
    u8 mode;

    if (arg0[0x65]) {
        delta = _glintrosyncDll_entrypoint_5();
    } else {
        delta = func_800D8FF8();
    }
    mode = arg0[0x60];
    if (mode != 5 && mode != 6) {
        if (mode == 8) {
            spline = func_8001B798(*(s16 *)(arg0 + 2));
            position = _susplinet_entrypoint_9(spline);
            _susplinet_entrypoint_11(spline, position);
            _susplinet_entrypoint_16(spline, position, 100.0f * delta + position);
        }
    } else {
        _suspline_entrypoint_16(func_8001B798(*(s16 *)arg0));
    }
}

/* extern */

void func_80800A18_ncpoducam(u8 *arg0) {
    void _susplinet_entrypoint_17(u8 *spline);
    void _susplinet_entrypoint_7(f32 arg0[][3], s32 arg1, f32 *arg2);
    f32 _susplinet_entrypoint_8(BtIntPtr, s32);
    void *func_8001B798(s16);
    BtIntPtr temp_v0;

    temp_v0 = func_8001B798((((Objucam_arg0 *)arg0)->unk2));
    _susplinet_entrypoint_17(temp_v0);
    _susplinet_entrypoint_7(temp_v0, 0, arg0 + 4);
    _susplinet_entrypoint_7(temp_v0, 1, arg0 + 0x10);
    (((Objucam_arg0 *)arg0)->unk50) = _susplinet_entrypoint_8(temp_v0, 0);
    (((Objucam_arg0 *)arg0)->unk54) = _susplinet_entrypoint_8(temp_v0, 1);
}

/* extern */

void func_80800A94_ncpoducam(u8 *arg0, s16 *arg1) {
    s32 _ncpod_entrypoint_11(BtIntPtr, s32);
    s32 _ncpod_entrypoint_8(BtIntPtr, BtIntPtr, BtIntPtr);
    s32 _ncpod_entrypoint_9(BtIntPtr, f32);
    void *func_80110024(s16 *);
    void func_80800704_ncpoducam(u8 *, s32);
    BtIntPtr sp24;
    BtIntPtr temp_v0_2;
    u8 temp_v0_3;

    switch (*(u8 *)(arg0 + 0x60)) {
        case 8:
            func_80800A18_ncpoducam(arg0);
            break;
        case 5:
            func_80800704_ncpoducam(arg0, 0);
            break;
        case 6:
            func_808003A8_ncpoducam(arg0, 0);
            break;
    }
    temp_v0_2 = func_80110024(arg1);
    sp24 = temp_v0_2;
    _ncpod_entrypoint_8(temp_v0_2, arg0 + 4, arg0 + 0x10);
    _ncpod_entrypoint_9(sp24, *(f32 *)(arg0 + 0x50));
    if ((*(f32 *)(arg0 + 0x50) == 40.0f) && ((temp_v0_3 = *(u8 *)(arg0 + 0x60), temp_v0_3 == 5) || (temp_v0_3 == 8))) {
        _ncpod_entrypoint_11(sp24, *(s32 *)(arg0 + 0x54));
    }
}

s32 func_80800B74_ncpoducam(u8 *arg0, s16 *arg1) {
    s32 _ncpod_entrypoint_5(s16 *, void *, s32, s16, BtIntPtr);
    s32 _suspline_entrypoint_1(void *);
    s32 _susplinet_entrypoint_2(void *);
    void *func_8001B798(s16);
    void *func_80110024(s16 *);
    void func_8080145C_ncpoducam(u8 *, s16 *, s32);
    s32 active;
    s32 result;
    s32 type;

    type = arg0[0x60];
    active = 0;
    result = 3;
    if (type != 5 && type != 6) {
        if (type == 8) {
            active = _susplinet_entrypoint_2(func_8001B798(*(s16 *)(arg0 + 2)));
        }
    } else {
        active = _suspline_entrypoint_1(func_8001B798(*(s16 *)arg0));
    }
    if (active != 0) {
        if (*(s16 *)(arg0 + 0x48) & 0x20) {
            func_8080145C_ncpoducam(arg0, arg1, 2);
            result = _ncpod_entrypoint_5(arg1, func_80110024(arg1), 0xB, *(s16 *)(arg0 + 0x58), 0);
            if (result == 4) {
                return result;
            } else {
                *(s32 *)(arg0 + 0x4C) = result;
            }
        } else {
            result = _ncpod_entrypoint_5(arg1, func_80110024(arg1), 0xB, *(s16 *)(arg0 + 0x58), 0);
            if (result == 4) {
                return result;
            }
            *(s32 *)(arg0 + 0x4C) = result;
            func_8080145C_ncpoducam(arg0, arg1, 3);
        }
    }
    return result;
}

/* extern */

s32 func_80800CB8_ncpoducam(s16 arg0, s32 arg1) {
    BT_IDO_ONLY(s32 func_800A5800(s16);) BT_NATIVE_ONLY(u8 *func_800A5800(s32);)
    s32 _cadbfunc_entrypoint_16(s16 *);
    s32 var_s0;

    var_s0 = 0;
    if (arg0 != -1) {
        do {
            func_800A5800(arg0);
            _cadbfunc_entrypoint_16(&arg0);
            var_s0 += 1;
        } while (arg0 != -1);
    }
    return var_s0;
}

void func_80800D28_ncpoducam(u8 *arg0) {
    s32 _cadbfunc_entrypoint_0(u8 *);
    s32 _cadbfunc_entrypoint_2(s32);
    s32 _cadbfunc_entrypoint_12(f32 *);
    s32 _cadbfunc_entrypoint_14(f32 *);
    s32 _cadbfunc_entrypoint_16(s16 *);
    void _cadbfunc_entrypoint_24(s32 *);
    s32 _cadbfunc_entrypoint_29(s32, s32 *);
    void _susplinet_entrypoint_0(void *, s32, u32, u32);
    void _susplinet_entrypoint_1(void *, s32, s32);
    s16 *_susplinet_entrypoint_12(void *);
    s16 *_susplinet_entrypoint_13(void *);
    void *_susplinet_entrypoint_14(void *, s32);
    f32 *_susplinet_entrypoint_15(void *, s32);
    u32 _susplinet_entrypoint_18(s32, u32, u32);
    void _susplinet_entrypoint_19(void *, s32, u32, u32);
    s16 func_8001B668(s32, s32);
    void *func_8001B798(s16);
    BT_IDO_ONLY(s32 func_800A5800(s16);) BT_NATIVE_ONLY(u8 *func_800A5800(s32);)
    u8 *vectors[2];
    f32 *values[2];
    s32 count;
    void *spline;
    s16 *indices;
    s16 handle;
    s16 i;
    s16 *links;
    s32 data;
    s32 j;
    s32 size;
    s32 flag;

    count = func_80800CB8_ncpoducam(*(s16 *)(arg0 + 0x58), arg0[0x60]);
    size = _susplinet_entrypoint_18(count, 2, 2);
    *(s16 *)(arg0 + 2) = func_8001B668(0, size);
    spline = func_8001B798(*(s16 *)(arg0 + 2));
    _susplinet_entrypoint_19(spline, count, 2, 2);
    _susplinet_entrypoint_1(spline, 1, 1);
    for (j = 0; j < 2; j++) {
        vectors[j] = _susplinet_entrypoint_14(spline, j);
    }
    for (j = 0; j != 2; j++) {
        values[j] = _susplinet_entrypoint_15(spline, j);
    }
    indices = _susplinet_entrypoint_12(spline);
    links = _susplinet_entrypoint_13(spline);
    handle = *(s16 *)(arg0 + 0x58);
    i = 0;
    while (handle != -1) {
        func_800A5800(handle);
        _cadbfunc_entrypoint_0(vectors[0]);
        _cadbfunc_entrypoint_2((BtIntPtr)vectors[1]);
        *links = -1;
        _cadbfunc_entrypoint_12(values[0]);
        _cadbfunc_entrypoint_24(&data);
        *indices = data;
        _cadbfunc_entrypoint_14(values[1]);
        _cadbfunc_entrypoint_29(0x100, &flag);
        _susplinet_entrypoint_0(spline, i, 2, flag);
        _cadbfunc_entrypoint_29(0x200, &flag);
        _susplinet_entrypoint_0(spline, i, 4, flag);
        _cadbfunc_entrypoint_29(0x400, &flag);
        _susplinet_entrypoint_0(spline, i, 1, flag);
        indices++;
        links++;
        vectors[0] += 12;
        vectors[1] += 12;
        values[0]++;
        values[1]++;
        i++;
        _cadbfunc_entrypoint_16(&handle);
    }
}

void func_80800F64_ncpoducam(u8 *arg0) {
    s32 _cadbfunc_entrypoint_0(u8 *);
    s32 _cadbfunc_entrypoint_2(s32);
    s32 _cadbfunc_entrypoint_10(f32 *);
    s32 _cadbfunc_entrypoint_12(f32 *);
    s32 _cadbfunc_entrypoint_16(s16 *);
    s32 _cadbfunc_entrypoint_18(u8 *);
    s32 _cadbfunc_entrypoint_29(s32, s32 *);
    void _suspline_entrypoint_0(void *, s32, s32);
    void *_suspline_entrypoint_10(void *, s32);
    f32 *_suspline_entrypoint_11(void *, s32);
    s32 _suspline_entrypoint_18(s32, s32, s32);
    void _suspline_entrypoint_19(void *, s32, s32, s32, s32, s32);
    s16 func_8001B668(s32, s32);
    void *func_8001B798(s16);
    BT_IDO_ONLY(s32 func_800A5800(s16);) BT_NATIVE_ONLY(u8 *func_800A5800(s32);)
    s32 func_800EE7F8();
    void func_800EF04C(f32 *, f32 *);
    void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
    void func_800F0EF0(s32, f32 *);
    u8 *vectors[3];
    f32 *values[4];
    s32 count;
    s16 handle;
    void *spline;
    s16 i;
    s32 data;
    f32 angle;

    count = func_80800CB8_ncpoducam(*(s16 *)(arg0 + 0x58), arg0[0x60]);
    *(s16 *)arg0 = func_8001B668(0, _suspline_entrypoint_18(count, 3, 4));
    spline = func_8001B798(*(s16 *)arg0);
    _suspline_entrypoint_19(spline, count, 3, 4, 2, 2);
    for (i = 0; i < 3; i++) {
        vectors[i] = _suspline_entrypoint_10(spline, i);
    }
    for (i = 0; i < 4; i++) {
        values[i] = _suspline_entrypoint_11(spline, i);
    }
    handle = *(s16 *)(arg0 + 0x58);
    i = 0;
    while (handle != -1) {
        func_800A5800(handle);
        _cadbfunc_entrypoint_0(vectors[0]);
        _cadbfunc_entrypoint_2((BtIntPtr)vectors[1]);
        _cadbfunc_entrypoint_10(values[2]);
        _cadbfunc_entrypoint_12(values[0]);
        *values[1] = 1.0f;
        _cadbfunc_entrypoint_18((u8 *)values[3]);
        _cadbfunc_entrypoint_29(8, &data);
        _suspline_entrypoint_0(spline, i, data);
        vectors[0] += 12;
        vectors[1] += 12;
        values[2]++;
        values[0]++;
        values[1]++;
        values[3]++;
        i++;
        _cadbfunc_entrypoint_16(&handle);
    }
    for (i = 0; i < 3; i++) {
        vectors[i] = _suspline_entrypoint_10(spline, i);
    }
    for (i = 0; i < 4; i++) {
        values[i] = _suspline_entrypoint_11(spline, i);
    }
    func_800F0EF0(count, (f32 *)vectors[1]);
    for (i = 0; i < count; i++) {
        angle = *values[3];
        *values[3] = ((f32 *)vectors[1])[2];
        func_800EE7F8((f32 *)vectors[2], (f32 *)vectors[1]);
        func_800EF4E4((f32 *)vectors[2], ((f32 *)vectors[2])[0], ((f32 *)vectors[2])[1], 0.0f, 0.0f, -angle);
        func_800EF04C((f32 *)vectors[2], (f32 *)vectors[0]);
        vectors[0] += 12;
        vectors[1] += 12;
        vectors[2] += 12;
        values[3]++;
    }
}

void func_80801274_ncpoducam(u8 *arg0) {
    s32 _cadbfunc_entrypoint_0(u8 *);
    s32 _cadbfunc_entrypoint_2(s32);
    s32 _cadbfunc_entrypoint_10(f32 *);
    s32 _cadbfunc_entrypoint_12(f32 *);
    s32 _cadbfunc_entrypoint_14(f32 *);
    s32 _cadbfunc_entrypoint_16(s16 *);
    s32 _cadbfunc_entrypoint_29(s32, s32 *);
    void _suspline_entrypoint_0(void *, s32, s32);
    void *_suspline_entrypoint_10(void *, s32);
    f32 *_suspline_entrypoint_11(void *, s32);
    s32 _suspline_entrypoint_18(s32, s32, s32);
    void _suspline_entrypoint_19(void *, s32, s32, s32, s32, s32);
    s16 func_8001B668(s32, s32);
    void *func_8001B798(s16);
    BT_IDO_ONLY(s32 func_800A5800(s16);) BT_NATIVE_ONLY(u8 *func_800A5800(s32);)
    void func_800F0EF0(s32, f32 *);
    u8 *vectors[2];
    f32 *values[3];
    s32 count;
    s16 handle;
    void *spline;
    s16 i;
    s32 data;

    count = func_80800CB8_ncpoducam(*(s16 *)(arg0 + 0x58), arg0[0x60]);
    *(s16 *)arg0 = func_8001B668(0, _suspline_entrypoint_18(count, 2, 3));
    spline = func_8001B798(*(s16 *)arg0);
    _suspline_entrypoint_19(spline, count, 2, 3, 0, 2);
    for (i = 0; i < 2; i++) {
        vectors[i] = _suspline_entrypoint_10(spline, i);
    }
    for (i = 0; i < 3; i++) {
        values[i] = _suspline_entrypoint_11(spline, i);
    }
    i = 0;
    handle = *(s16 *)(arg0 + 0x58);
    while (handle != -1) {
        func_800A5800(handle);
        _cadbfunc_entrypoint_0(vectors[0]);
        _cadbfunc_entrypoint_2(vectors[1]);
        _cadbfunc_entrypoint_10(values[2]);
        _cadbfunc_entrypoint_12(values[0]);
        _cadbfunc_entrypoint_14(values[1]);
        _cadbfunc_entrypoint_29(8, &data);
        _suspline_entrypoint_0(spline, i, data);
        vectors[0] += 12;
        vectors[1] += 12;
        values[2]++;
        values[0]++;
        values[1]++;
        i++;
        _cadbfunc_entrypoint_16(&handle);
    }
    func_800F0EF0(count, _suspline_entrypoint_10(spline, 1));
}

void func_8080145C_ncpoducam(u8 *arg0, s16 *arg1, s32 arg2) {
    s32 func_800A5854(s32);
    void *func_80110024(s16 *);
    s32 _ncpod_entrypoint_12(BtIntPtr, s32);
    void func_80800D28_ncpoducam(u8 *);
    void func_80800F64_ncpoducam(u8 *);
    void func_80801274_ncpoducam(u8 *);
    u8 temp_v0;

    *(s32 *)(arg0 + 0x5C) = arg2;
    switch (arg2) {
        case 1:
            func_80800160_ncpoducam(arg0);
            func_80800000_ncpoducam(arg0);
            temp_v0 = func_800A5854(*(s16 *)(arg0 + 0x58));
            *(u8 *)(arg0 + 0x60) = temp_v0;
            switch (temp_v0) {
                case 8:
                    func_80800D28_ncpoducam(arg0);
                    break;
                case 5:
                    func_80801274_ncpoducam(arg0);
                    break;
                case 6:
                    func_80800F64_ncpoducam(arg0);
                    break;
            }
            break;
        case 3:
            _ncpod_entrypoint_12(func_80110024(arg1), 0);
            break;
    }
}

s32 ncpoducam_entrypoint_7(s16 arg0, s16 *arg1) {
    u8 *data;
    s32 result;

    data = ncpoducam_entrypoint_1(arg0);
    result = 3;
    switch (*(s32 *)(data + 0x5C)) {
        case 0:
            break;
        case 1:
            func_808007D0_ncpoducam(data);
            result = func_80800854_ncpoducam(data, arg1);
            if (result == 4) {
                return result;
            }
            if (*(s16 *)(data + 0x48) & 2) {
                if (*(u8 *)(data + 0x64) != 0) {
                    func_80800944_ncpoducam(data);
                } else {
                    *(u8 *)(data + 0x64) = 1;
                }
            }
            func_80800A94_ncpoducam(data, arg1);
            if (!(*(s16 *)(data + 0x48) & 2)) {
                func_80800944_ncpoducam(data);
            }
            result = func_80800B74_ncpoducam(data, arg1);
            break;
        case 2:
            result = func_80800854_ncpoducam(data, arg1);
            if (result == 4) {
                return result;
            }
            func_80800A94_ncpoducam(data, arg1);
            break;
        case 3:
            break;
    }
    return result;
}

/* extern */

s32 ncpoducam_entrypoint_8(void *arg0, s32 arg1) {
    s32 _susplinet_entrypoint_4(void *, s32);
    void *func_8001B798(s16);
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)(*(void **)&arg0) + (0x60)));
    if ((temp_v0 != 5) && (temp_v0 != 6) && (temp_v0 == 8)) {
        return _susplinet_entrypoint_4(func_8001B798((((Objucam_arg0 *)arg0)->unk2)), arg1);
    }
    return 0;
}

s32 ncpoducam_entrypoint_9(void *arg0, volatile s32 arg1) {
    s32 _suspline_entrypoint_2(void *, s32);
    s32 _susplinet_entrypoint_5(void *, s32);
    void *func_8001B798(s16);
    u8 temp_v0;
    void *ptr = arg0;

    temp_v0 = *(u8 *)((s8 *)*(void **)&arg0 + 0x60);
    if ((temp_v0 != 5) && (temp_v0 != 6)) {
        if (temp_v0 == 8) {
            return _susplinet_entrypoint_5(func_8001B798(((Objucam_arg0 *)arg0)->unk2), arg1);
        }
    } else {
        return _suspline_entrypoint_2(func_8001B798(*(s16 *)ptr), arg1);
    }
    return 0;
}

f32 ncpoducam_entrypoint_10(void *arg0) {
    f32 _suspline_entrypoint_6(void *);
    f32 _susplinet_entrypoint_9(void *);
    void *func_8001B798(s16);
    u8 temp_v0;

    temp_v0 = ((Objucam_arg0 *)arg0)->unk60;
    if ((temp_v0 != 5) && (temp_v0 != 6)) {
        if (temp_v0 == 8) {
            return _susplinet_entrypoint_9(func_8001B798(((Objucam_arg0 *)arg0)->unk2));
        }
    } else {
        return _suspline_entrypoint_6(func_8001B798(*(s16 *)arg0));
    }
    return 0.0f;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) ncpoducam_entrypoint_11(BtIntPtr arg0 BT_PASS2(, s32 bt_a1)) {
    s32 func_800EE7F8(s32);
    BT_NATIVE_ONLY(return) func_800EE7F8(arg0 + 0x3C);
}
