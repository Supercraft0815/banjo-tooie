#include "common.h"

/* extern */

void func_80800000_chdinoroargrill(void *arg0) {
    s32 func_8010A800(void *, s32);
    (*(f32 *)((s8 *)(arg0) + (0x28))) = 0.0f;
    func_8010A800(arg0, 0);
}

void func_80800028_chdinoroargrill(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _chdoor_entrypoint_0();
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    void func_80101FDC(Actor *, u32);
    s32 func_80102F44(void *);
    s32 func_8010C710(Actor *);
    extern u8 D_80800250_chdinoroargrill[];
    Unk80132ED0 *temp_a0;

    if (D_80800250_chdinoroargrill[(s32) *(f32 *)&arg0->actorData[4]] == 0) {
        if (func_80102F44(arg0) == 0) {
            func_80101FDC(arg0, 3);
            arg0->unk58 = 1.9f;
            temp_a0 = arg0->unk0;
            _capod_entrypoint_13(temp_a0, temp_a0, 0x4C, 0x810);
            if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, arg0->scale * 170.0f, 0, -1) != 0) {
                _chdoormake_entrypoint_8(arg0, 0xE);
            }
        }
        _chdoor_entrypoint_0(arg0);
        return;
    }
    if (func_8010C710(arg0) >= 0xC5C11) {
        *(f32 *)&arg0->actorData[4] = 0.0f;
    }
}

s32 func_80800124_chdinoroargrill(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800DA544(GameFlag);
    void func_800FC63C(u32, u32);
    void func_800FFAB0(Actor *);
    extern u8 D_80800250_chdinoroargrill[];

    switch (arg1) {
        case 0xB:
            if (arg2 == 0x4C) {
                func_800DA544(0xA22);
                func_800FFAB0(arg0);
            }
            return 3;
        case 0x1D:
        case 0x1E:
            if (D_80800250_chdinoroargrill[(s32)*(f32 *)&arg0->actorData[4]] != 0) {
                if (arg1 == D_80800250_chdinoroargrill[(s32)*(f32 *)&arg0->actorData[4]]) {
                    *(f32 *)&arg0->actorData[4] += 1.0f;
                    if (D_80800250_chdinoroargrill[(s32)*(f32 *)&arg0->actorData[4]] == 0) {
                        func_800FC63C(0x10, -1);
                        return 1;
                    }
                } else {
                    *(f32 *)&arg0->actorData[4] = 0.0f;
                }
            }
            return 1;
        case 0x95:
            arg0->unk79_2 = 0;
            return 1;
        default:
            return 0;
    }
}

OSThread *chdinoroargrill_entrypoint_0(void)
{
    extern u8 D_80800258_chdinoroargrill[];

    return (OSThread *) D_80800258_chdinoroargrill;
}
