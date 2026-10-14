#include "ch/doubloon.h"

void func_80800000_chdoubloon(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x44))) = 0.0f;
}

/* extern */

void func_8080000C_chdoubloon(s32 arg0) {
    s32 func_80103110(s32, s32);
    s32 chdoubloon_entrypoint_1();
    chdoubloon_entrypoint_1();
    func_80103110(arg0, 0);
}

void chdoubloon_entrypoint_0(Actor *arg0, u8 *arg1) {
    struct Flags { u32 pad : 19; u32 active : 1; u32 rest : 12; };
    void func_80101870(Actor* arg0, void* arg1);
    s32 func_80103110(s32, s32);
    func_80101870(arg0, arg1);
    if (((struct Flags *)((s8 *)arg0 + 0x7C))->active) {
        func_80103110((s32) arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doubloon/chdoubloon_entrypoint_1.s")

s32 func_808001D4_chdoubloon(Actor *arg0, s32 arg1, s32 arg2) {
    void _fxsparkle_entrypoint_1(f32 *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _sudialog_entrypoint_0(s32, s32);
    void func_800D0BD4(s32, u32);
    void func_800D1844(s32);
    void func_800FFAB0(Actor *);
    extern s32 D_80800290_chdoubloon;

    switch (arg1) {
        case 0x3E: {
            _sudialog_entrypoint_0(0x165, 4);
            func_800D0BD4(*(s32 *)&arg0->unk54, 7);
            func_800D1844(0x4E);
            _subaddieaudioquick_entrypoint_2(arg0, &arg0->position[0], &D_80800290_chdoubloon);
            _fxsparkle_entrypoint_1(arg0->position, 0x13);
            func_800FFAB0(arg0);
            return 1;
        }
        case 0x13:
            *(s32 *)&arg0->unk54 = arg2;
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chdoubloon_entrypoint_2(void)
{
    extern u8 D_808002A0_chdoubloon[];

    return (OSThread *) D_808002A0_chdoubloon;
}
