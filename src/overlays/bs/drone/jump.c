#include "common.h"

/* extern */

typedef struct { u8 pad0[0x54]; s8 * unk54; u8 pad58[0x138]; f32 unk190; f32 unk194; } Objjump_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ typedef struct { u8 pad0[0x4]; f32 unk4; } Objjump_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */ void bsdronejump_entrypoint_0(void *arg0, void *arg1, f32 arg2) {
    f32 _bamovegoto_entrypoint_3();
    f32 func_80013970(f32);
    void func_8008C990(void *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 pad[1];
    f32 sp20;
    f32 new_var;

    func_8008C990(arg0, func_800F10B4(arg2, 0.0f, 1.0f, ((Objjump_arg0 *)arg0)->unk190, ((Objjump_arg0 *)arg0)->unk194));
    sp20 = _bamovegoto_entrypoint_3(arg0);
    new_var = func_80013970(arg2 * 180.0f) * sp20 * 0.5f;
    (((Objjump_arg1 *)arg1)->unk4) += new_var;
}

void bsdronejump_entrypoint_1(s32 arg0)
{
    func_800961A0(arg0,0);
}

void bsdronejump_entrypoint_2(void *arg0) {
    void _badata_entrypoint_8(void *, s32 *, f32 *, f32 *);
    void baanim_playForDuration_loopStartingAt(void *, s32, f32, f32);
    void func_8009FFD8();
    void func_8009C128(void *, f32[3]);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void yaw_setIdeal(void *, f32);
    void _bamovegoto_entrypoint_0(void *);
    void _bamovegoto_entrypoint_7(void *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void _bamovegoto_entrypoint_12(void *, f32 *);
    void _bamovegoto_entrypoint_11(void *arg0, BtIntPtr arg1, BtIntPtr arg2);
    void _bamovegoto_entrypoint_13(void *);
    extern void _bsdronejump_entrypoint_0(void *, void *, f32);
    f32 sp44;
    s32 pad;
    f32 sp34[3];
    s32 sp30;

    _badata_entrypoint_8(arg0, &sp30, &((Objjump_arg0 *)arg0)->unk190, &((Objjump_arg0 *)arg0)->unk194);
    baanim_playForDuration_loopStartingAt(arg0, sp30, 1000.0f, ((Objjump_arg0 *)arg0)->unk190);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    func_8009C128(arg0, sp34);
    sp44 = func_800EEAD4(sp34, (f32 *)(((Objjump_arg0 *)arg0)->unk54 + 0x34));
    yaw_setIdeal(arg0, func_800F1DF4(sp34, (f32 *)(((Objjump_arg0 *)arg0)->unk54 + 0x34)));
    _bamovegoto_entrypoint_0(arg0);
    _bamovegoto_entrypoint_7(arg0, func_800F10B4(sp44, 100.0f, 5000.0f, 0.4f, 4.5f));
    _bamovegoto_entrypoint_12(arg0, (f32 *)(((Objjump_arg0 *)arg0)->unk54 + 0x34));
    _bamovegoto_entrypoint_11(arg0, 0, _bsdronejump_entrypoint_0);
    _bamovegoto_entrypoint_13(arg0);
    func_800961A0(arg0, 1);
}

void bsdronejump_entrypoint_3(BT_NATIVE_ONLY(s32 bt_a0))
{
    func_80099AA8(BT_NATIVE_ONLY(bt_a0));
}

/* extern */

void bsdronejump_entrypoint_4(BtIntPtr arg0) {
    s32 _badata_entrypoint_34(BtIntPtr);
    void bs_setState(void *self, s32 nextState);
    s32 _bamovegoto_entrypoint_4();
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_bamovegoto_entrypoint_4() != 0) {
        var_a1 = _badata_entrypoint_34(arg0);
    }
    bs_setState(arg0, var_a1);
}
