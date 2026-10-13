#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/fire/func_80800000_cheggfire.s")

void func_808000B8_cheggfire(void *arg0) {
    void *func_80100094(void *, u32);
    s32 func_800EEEA8(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 _suegg_entrypoint_8(void *);
    s32 _suegg_entrypoint_12(void *);
    s32 _suegg_entrypoint_13(void *);
    s32 _suegg_entrypoint_14(void *);
    void _suegg_entrypoint_16(void *);
    void _suegg_entrypoint_23(void *);
    void _suegg_entrypoint_3(void *);
    void _sueggmisc_entrypoint_1(void *);
    s32 _sueggmove_entrypoint_3(void *);
    void func_80800000_cheggfire(void *);
    struct FireData {
        u8 pad[0x39];
        u8 flag : 1;
        u8 rest : 7;
    } *data;

    data = func_80100094(arg0, 0);
    switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
    case 1:
        if (_suegg_entrypoint_8(arg0) == 0) {
            if (func_800EEEA8((s32)((u8 *)arg0 + 0x28)) != 0) {
                data->flag = 1;
            } else {
                func_80800000_cheggfire(arg0);
                _suegg_entrypoint_16(arg0);
                if (_suegg_entrypoint_14(arg0) != 0) {
                    data->flag = 1;
                }
            }
        }
        break;
    case 2:
        if (_suegg_entrypoint_8(arg0) == 0) {
            *(f32 *)((u8 *)arg0 + 0x38) = func_800F10B4(*(f32 *)((u8 *)data + 0x30), 0.0f, 0.134f, 0.1f, 0.25f);
            if (_sueggmove_entrypoint_3(arg0) != 0) {
                _suegg_entrypoint_23(arg0);
            }
            if (_suegg_entrypoint_13(arg0) != 0) {
                data->flag = 1;
            } else if (_suegg_entrypoint_12(arg0) != 0) {
                _sueggmisc_entrypoint_1(arg0);
            } else {
                func_80800000_cheggfire(arg0);
                _suegg_entrypoint_16(arg0);
            }
        }
        break;
    }
    if (data->flag) {
        _suegg_entrypoint_3(arg0);
    }
}

void func_80800228_cheggfire(s32 arg0) {
    s32 _suegg_entrypoint_21(s32, s32 *);
    s32 _suegg_entrypoint_5();
    extern s32 D_808003B0_cheggfire;
    _suegg_entrypoint_5();
    _suegg_entrypoint_21(arg0, &D_808003B0_cheggfire);
}

OSThread *cheggfire_entrypoint_0(void)
{
    extern u8 D_808003BC_cheggfire[];

    return (OSThread *) D_808003BC_cheggfire;
}

/* extern */

void *cheggfire_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _suegg_entrypoint_1(void *, f32);
    void *_suegg_entrypoint_11(s32, s32, s32);
    s32 _sueggmove_entrypoint_10(s32);
    s32 _sueggmove_entrypoint_5(void *, s32);
    s32 _sueggmove_entrypoint_6(void *, f32, f32);
    s32 _sueggmove_entrypoint_7(void *, s32);
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15B, arg1, arg3);
    temp_v0->scale = 0.134f;
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_5(temp_v0, 1);
    _sueggmove_entrypoint_6(temp_v0, -2200.0f, -22000.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 2;
    return temp_v0;
}

/* extern */

void *cheggfire_entrypoint_2(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _suegg_entrypoint_1(void *, f32);
    void *_suegg_entrypoint_11(s32, s32, s32);
    s32 _sueggmove_entrypoint_10(s32);
    s32 _sueggmove_entrypoint_5(void *, s32);
    s32 _sueggmove_entrypoint_6(void *, f32, f32);
    s32 _sueggmove_entrypoint_7(void *, s32);
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15B, arg1, arg3);
    temp_v0->scale = 0.25f;
    _sueggmove_entrypoint_5(temp_v0, 0);
    _sueggmove_entrypoint_6(temp_v0, 0.0f, -100000.0f);
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 1;
    return temp_v0;
}
