#include "common.h"

OSThread *chbabydino_entrypoint_0(void)
{
    extern ActorData D_80800770_chbabydino[];

    return (OSThread *) D_80800770_chbabydino;
}

void func_8080000C_chbabydino(Actor *arg0) {
    s32 func_800EA05C();
    s32 func_800DA298(s32);
    s32 _glcutDll_entrypoint_19(s32);
    void *func_80105494(Actor *);
    void func_80105A9C(Actor *, f32);
    s32 func_800FFAB0();
    void func_80102424(Actor *, s32);
    s32 map;

    map = func_800EA05C();
    if (func_80105494(arg0) != NULL) {
        func_80105A9C(arg0, 500.0f);
    }
    switch (map) {
        case 0xEA:
            if (func_800DA298(0x98)) {
                arg0->unk64_20 = 1;
            }
            if (func_800DA298(0x8A) || func_800DA298(0x588)) {
                func_800FFAB0(arg0);
                return;
            }
            func_80102424(arg0, 2);
            return;
        case 0xEC:
            if (!_glcutDll_entrypoint_19(0x1F)) {
                func_800FFAB0(arg0);
            }
            return;
        case 0x121:
            if (func_800DA298(0x588)) {
                func_80102424(arg0, 5);
                return;
            }
            func_800FFAB0(arg0);
            break;
    }
}

void func_8080011C_chbabydino(Actor *arg0) { s32 _capod_entrypoint_14(void); void _chdinofamilyfx_entrypoint_0(Actor *arg0); void _glcutDll_entrypoint_15(s32); void _glcutDll_entrypoint_17(void); s32 _glcutDll_entrypoint_19(s32); void _glcutDll_entrypoint_24(u32, u32, u32); void _glcutDll_entrypoint_6(u32, u32); s32 _subaddiedialog_entrypoint_7(BtIntPtr, BtIntPtr, s32 *); s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3); void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr); BtIntPtr _suexpression_entrypoint_20(); void func_800DA544(); s32 func_800FFAB0(); void func_80102424(Actor *, s32); void func_80800448_chbabydino(Actor *); s32 func_808005A0_chbabydino(BtIntPtr, s32); extern s32 D_808007B8_chbabydino[7];  _sudeflect_entrypoint_0(arg0->position, arg0->scale * 100.0f, arg0->scale * 150.0f, 10); _suexpression_entrypoint_10((u32 *)_suexpression_entrypoint_20(arg0), arg0->unk0, 0); switch (arg0->unk70_10) { case 1: break; case 2: func_80800448_chbabydino(arg0); break; case 3: if (!func_808005A0_chbabydino((BtIntPtr)arg0, 1)) { _capod_entrypoint_14(); if (_glcutDll_entrypoint_19(0x1F)) { _glcutDll_entrypoint_24(0xEC, -1, 0x1F); } else { _glcutDll_entrypoint_6(0xEC, 0x1F); } } break; case 4: if (!func_808005A0_chbabydino((BtIntPtr)arg0, 0)) { func_800DA544(0x588); func_80102424(arg0, 5); func_800FFAB0(arg0); _glcutDll_entrypoint_15(1); _glcutDll_entrypoint_17(); _capod_entrypoint_14(); } break; case 5: _subaddiedialog_entrypoint_7((BtIntPtr)arg0, (BtIntPtr)arg0->position, D_808007B8_chbabydino); break; } _chdinofamilyfx_entrypoint_0((u8 *)arg0); }

void func_8080028C_chbabydino(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_808002AC_chbabydino(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    BtIntPtr _suexpression_entrypoint_20();
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 func_800DA298(s32);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    void func_808003BC_chbabydino(Actor *, s32, s32);
    s32 func_808005F0_chbabydino(Actor *, s32);
    void *expression;
    s32 value;

    switch (arg1) {
        case 0x2E:
            func_808003BC_chbabydino(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x49:
            return func_808005F0_chbabydino(arg0, arg2);
        case 0x95:
            _suexpression_entrypoint_7(arg0, 1, 0x39);
            expression = (void *)_suexpression_entrypoint_20(arg0);
            _suexpression_entrypoint_12(expression, 0x42480000, 0x41A00000);
            _suexpression_entrypoint_17(expression, 1000);
            break;
        case 0x1F:
            func_801015D0(arg0);
            func_800DF744(3, 1);
            break;
        case 0xB8:
            value = arg2;
            if ((value & 0xFFFF) == 1) {
                return func_800DA298(0x98) ? 0x107F : 0x107D;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_808003BC_chbabydino(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_22();
    s32 func_800DA298(s32);
    void func_80102424(Actor *, s32);
    s32 var_a1;

    if (arg0->unk64_19) {
        _capod_entrypoint_22();
        arg0->unk64_19 = 0;
    }
    if ((arg1 != 0x107E) && (arg1 != 0x1080)) {
        if (func_800DA298(0x588) != 0) {
            var_a1 = 5;
        } else {
            var_a1 = 2;
        }
        func_80102424(arg0, var_a1);
    }
}

void func_80800448_chbabydino(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _capod_entrypoint_21(Unk80132ED0 *, BtIntPtr, s32, s32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s16);)
    s32 _subaddiedialog_entrypoint_8(Actor *, void *, s32 *, s32 *, s32);
    s32 func_800DA298(s32);
    void func_800DA544(GameFlag);
    int func_800DB9B0(void);
    BtUIntPtr func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    void func_80102424(Actor *, s32);
    extern s32 D_80800700_chbabydino[10];
    extern s32 D_808007D4_chbabydino[7];
    s32 sp2C;

    sp2C = 0;
    if (func_800DA298(0x98) && !arg0->unk64_20) {
        if (!func_800DB9B0()) {
            func_800DA544(0x89);
            arg0->unk64_20 = 1;
            func_800F82D4(func_800F54E4(), 0);
            if (func_800DA298(0x4EE)) {
                func_80102424(arg0, 3);
                _subaddieDll_entrypoint_4(arg0, 1);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x107E, 0xC, NULL, 0x39);
                _capod_entrypoint_13(arg0->unk0, NULL, 3, 0x31);
            } else {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x107F, 0xE, NULL, 0x39);
                func_80102424(arg0, 1);
                sp2C = 1;
            }
        }
    } else {
        sp2C = _subaddiedialog_entrypoint_8(arg0, arg0->position, D_808007D4_chbabydino, D_80800700_chbabydino, 5);
    }
    if (sp2C) {
        _capod_entrypoint_21(arg0->unk0, 0, 0xB, 0);
        arg0->unk64_19 = 1;
    }
}

/* extern */

s32 func_808005A0_chbabydino(BtIntPtr arg0, s32 arg1) {
    s32 func_800FFAB0(BtIntPtr);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_80105834();
    s32 func_80105A5C(BtIntPtr);
    func_80105834();
    if (func_80105A5C(arg0) != 0) {
        if (arg1 != 0) {
            func_800FFAB0(arg0);
        }
        return 0;
    }
    return 1;
}

s32 func_808005F0_chbabydino(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _glcutDll_entrypoint_19(s32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s16);)
    s32 func_800EA05C();
    void func_80102424(Actor *, s32);

    switch (func_800EA05C()) {
        case 0xEA:
            if (_glcutDll_entrypoint_19(0x1F)) {
                func_80102424(arg0, 3);
                _subaddieDll_entrypoint_4(arg0, 1);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1080, 0xC, NULL, 0x39);
                _capod_entrypoint_13(arg0->unk0, NULL, 3, 0x2821);
                return 1;
            }
            break;
        case 0xEC:
            if (_glcutDll_entrypoint_19(0x1F)) {
                func_80102424(arg0, 4);
                _subaddieDll_entrypoint_4(arg0, 1);
                _capod_entrypoint_13(arg0->unk0, NULL, 7, 0x2821);
                return 1;
            }
            break;
    }
    return 0;
}
/* data_to_c.py: from asm/data/overlays/ch/babydino.data.s */
extern u8 D_80800728_chbabydino[];
void func_801018A4();
void func_80107C2C();
s32 D_80800700_chbabydino[10] BT_DATA(4, overlays_ch_babydino, 0x0) = { 1, 276562176, 1537, -65024, 512, 286523648, 1024, 286589184, -73729, 302711552 };
u8 D_80800728_chbabydino[72] BT_DATA(4, overlays_ch_babydino, 0x28) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xD0, 0x00, 0x00, 0x01, 0x4D, 0x00, 0x00, 0x40, 0xD0, 0x00, 0x00, 0x01, 0x4D, 0x00, 0x00, 0x3E, 0xE6, 0x66, 0x66, 0x01, 0x4C, 0x00, 0x00, 0x3E, 0xE6, 0x66, 0x66, 0x01, 0x4C, 0x00, 0x00, 0x40, 0xD0, 0x00, 0x00, 0x01, 0x4D, 0x00, 0x00, 0x3E, 0xE6, 0x66, 0x66, 0x01, 0x4C, 0x00, 0x00, 0x3E, 0xE6, 0x66, 0x66, 0x01, 0x4C, 0x00, 0x00, 0x40, 0xD0, 0x00, 0x00, 0x01, 0x4D, 0x00, 0x00 };
ActorData D_80800770_chbabydino [1] BT_DATA(4, overlays_ch_babydino, 0x70) = { { 393, 312, 1740, 1, (void *)D_80800728_chbabydino, (void (*)(struct Actor *))func_8080011C_chbabydino, (void (*)(struct Actor *))func_8080011C_chbabydino, (void (*)(long, long))func_801018A4, 0, 1075838976, 0, 0, 16388, 288, (void (*)(struct Actor *))func_8080028C_chbabydino, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chbabydino, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1106, (void (*)(struct Actor *, long, long))func_808002AC_chbabydino, 0 } };
s32 D_808007B8_chbabydino[7] BT_DATA(4, overlays_ch_babydino, 0xB8) = { 700, 4225, 1537, 302710784, 3735552, 786432, 16777216 };
s32 D_808007D4_chbabydino[7] BT_DATA(4, overlays_ch_babydino, 0xD4) = { 8978432, 45875257, 12, 256, 0, 0, 0 };
