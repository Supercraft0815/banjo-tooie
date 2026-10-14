#include "common.h"

void func_80800000_chlavacolumns(u8 *arg0) {
    s32 func_80800200_chlavacolumns(s32, s32);
    void func_800EFD24(f32 *);
    void func_80103014(u8 *);
    func_80800200_chlavacolumns((s32)arg0, (s32)0xC3C80000);
    func_800EFD24(arg0 + 4);
    (*(f32 *)(arg0 + 8)) = -400.0f;
    func_80103014(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/columns/func_80800044_chlavacolumns.s")

void func_8080014C_chlavacolumns(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800D8FF8(void);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    extern u32 D_80800250_chlavacolumns;
    extern s32 D_80800258_chlavacolumns;
    f32 delta;

    if (arg0->unk70_10 == 2) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_80800250_chlavacolumns);
        delta = func_800D8FF8();
        arg0->position[1] = arg0->position[1] + 100.0f * delta;
        if (arg0->position[1] > 0.0f) {
            arg0->position[1] = 0.0f;
            func_80101FDC(arg0, 3);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800258_chlavacolumns);
            func_80103110(arg0, 0);
        }
    }
}

/* extern */

s32 func_80800200_chlavacolumns(s32 arg0, s32 arg1) {
    s32 _idworld_entrypoint_3(s32);
    s32 func_800EDCB8(s32, s32);
    s32 temp_v0;

    temp_v0 = _idworld_entrypoint_3(0x190);
    if (temp_v0 != 0) {
        func_800EDCB8(temp_v0, arg1);
        return 1;
    }
    return 0;
}

OSThread *chlavacolumns_entrypoint_0(void)
{
    extern u8 D_80800260_chlavacolumns[];

    return (OSThread *) D_80800260_chlavacolumns;
}
