#include "common.h"

void func_80800000_chdodgemdoors(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    s32 func_80103140(Actor *, u32, u16);
    void func_8010A63C(void ***);

    arg0->unk74_7 = arg0->unk74_7 - 0x32;
    arg0->position[2] = -645.0f;
    func_80103140(arg0, (u16)(arg0->unk74_7 + 0x767), arg0->unk0->unk16);
    func_8010A63C(arg0);
    if (func_800DA298(arg0->unk74_7 + 0xAB) != 0) {
        func_80101FDC(arg0, 3);
        arg0->position[1] = 275.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dodgemdoors/func_808000A0_chdodgemdoors.s")

void func_8080026C_chdodgemdoors(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800D8FF8(void);
    s32 func_800DA544(s32);
    void func_80101FDC(Actor *, u32);
    extern u8 D_80800360_chdodgemdoors[];

    switch (arg0->unk70_10) {
        case 2:
            if (!arg0->unk74_30) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800360_chdodgemdoors);
                arg0->unk74_30 = 1;
            }
            if (arg0->position[1] < 275.0f) {
                arg0->position[1] += 175.0f * func_800D8FF8();
            } else {
                func_80101FDC(arg0, 3);
                func_800DA544(arg0->unk74_7 + 0xAB);
            }
            break;
        case 1:
        case 3:
            break;
    }
}

OSThread *chdodgemdoors_entrypoint_0(void)
{
    extern u8 D_80800374_chdodgemdoors[];

    return (OSThread *) D_80800374_chdodgemdoors;
}
