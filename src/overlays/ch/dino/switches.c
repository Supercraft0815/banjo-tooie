#include "common.h"

OSThread *chdinoswitches_entrypoint_0(void)
{
    extern u8 D_80800C30_chdinoswitches[];

    return (OSThread *) D_80800C30_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_1(void)
{
    extern u8 D_80800C78_chdinoswitches[];

    return (OSThread *) D_80800C78_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_2(void)
{
    extern u8 D_80800CC0_chdinoswitches[];

    return (OSThread *) D_80800CC0_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_3(void)
{
    extern u8 D_80800D08_chdinoswitches[];

    return (OSThread *) D_80800D08_chdinoswitches;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800030_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800108_chdinoswitches.s")

void func_80800270_chdinoswitches(void *arg0) {
    void func_801032B0(void *, u16, u16);
    extern u8 D_80800B28_chdinoswitches[];
    s32 index = *(s32 *)((u8 *)arg0 + 0x18);

    func_801032B0(arg0, *(u16 *)(D_80800B28_chdinoswitches + index * 0x14),
                  *(u16 *)((u8 *)*(void **)arg0 + 0x16));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_808002B0_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_808003E8_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/chdinoswitches_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800714_chdinoswitches.s")

void func_808007A0_chdinoswitches(Actor *arg0) {
    void func_800DA544(GameFlag);
    s32 func_8010114C(s32, s32, s32);
    s32 func_80101E14(Actor *, f32);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    extern u16 D_80800B22_chdinoswitches[][10];
    s32 temp_a0;

    if (arg0->unk70_10 == 2 && func_80101E14(arg0, 0.3f) != 0) {
        func_800DA544(D_80800B22_chdinoswitches[arg0->actorData[0]][0]);
        func_80102424(arg0, 3);
        func_80101EE4(arg0, 0.3f);
        func_80103110(arg0, 0);
        temp_a0 = (s32)arg0->unk3C;
        if (temp_a0 != 0) {
            func_8010114C(temp_a0, 7, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800848_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_808008F0_chdinoswitches.s")

void func_80800A48_chdinoswitches(void *arg0) {
    void func_80103140(void *, u16, u16);
    extern u8 D_80800B2C_chdinoswitches[];
    s32 index = *(s32 *)((u8 *)arg0 + 0x18);

    func_80103140(arg0, *(u16 *)(D_80800B2C_chdinoswitches + index * 0x14),
                  *(u16 *)((u8 *)*(void **)arg0 + 0x16));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800A88_chdinoswitches.s")
