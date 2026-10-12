#include "common.h"

void func_80800000_chworlddoors(u8 *arg0) {
    void func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    extern s32 D_80800990_chworlddoors;
    f32 *sp20;
    f32 sp24[2];

    sp20 = (f32 *)(arg0 + 0x28);
    func_800EE7F8(sp24, sp20);
    func_800EF214(sp24, *(f32 *)(arg0 + 0x44), *(f32 *)(arg0 + 0x48), -50.0f);
    func_800BBCB8(sp20, sp24, 1.0f, 6, &D_80800990_chworlddoors);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800068_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800214_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800388_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_808006A8_chworlddoors.s")

void func_80800750_chworlddoors(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_2(Actor*);
    s32 func_800E1720(s32);
    u32 temp_v0;

    temp_v0 = arg0->actorData[3];
    if (temp_v0 != 0) {
        func_800E1720(temp_v0 - 1);
    }
    if (arg0->unk5F != 0) {
        _subaddieaudioloop_entrypoint_2(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800798_chworlddoors.s")

OSThread *chworlddoors_entrypoint_0(void)
{
    extern u8 D_80800A04_chworlddoors[];

    return (OSThread *) D_80800A04_chworlddoors;
}
