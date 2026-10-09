#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/normal/func_80800000_cheggnormal.s")

void func_80800194_cheggnormal(void *arg0) {
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
    void func_80800000_cheggnormal(void *);
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
                func_80800000_cheggnormal(arg0);
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
                func_80800000_cheggnormal(arg0);
                _suegg_entrypoint_16(arg0);
            }
        }
        break;
    }
    if (data->flag) {
        _suegg_entrypoint_3(arg0);
    }
}

OSThread *cheggnormal_entrypoint_0(void)
{
    extern u8 D_808004D0_cheggnormal[];

    return (OSThread *) D_808004D0_cheggnormal;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/normal/cheggnormal_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/normal/cheggnormal_entrypoint_2.s")
