#include "ch/crusher.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_80800000_chcrusher.s")

OSThread *chcrusher_entrypoint_0(void)
{
    extern u8 D_80800B98_chcrusher[];

    return (OSThread *) D_80800B98_chcrusher;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_80800068_chcrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_808000D4_chcrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_80800394_chcrusher.s")

void func_808003E4_chcrusher(void *arg0) {
    struct CrusherFlags {
        u8 pad[0x65];
        u8 unused : 3;
        u8 active : 1;
        u8 remaining : 4;
    };
    void func_8008FE94(s32, f32 *);
    s32 func_80090150(void);
    void func_800904C8(s32);
    f32 upper[3];
    f32 lower[3];
    f32 x;
    f32 z;
    f32 position[3];

    x = *(f32 *)((u8 *)arg0 + 4) - *(f32 *)((u8 *)arg0 + 0x18);
    z = *(f32 *)((u8 *)arg0 + 0x20) - *(f32 *)((u8 *)arg0 + 0xC);
    x += 25.0f;
    z += 25.0f;
    func_8008FE94(5, position);
    upper[0] = *(f32 *)((u8 *)arg0 + 4) + x;
    lower[0] = *(f32 *)((u8 *)arg0 + 4) - x;
    upper[1] = *(f32 *)((u8 *)arg0 + 0x1C);
    lower[1] = *(f32 *)((u8 *)arg0 + 0x1C) + 100.0f;
    upper[2] = *(f32 *)((u8 *)arg0 + 0xC) + z;
    lower[2] = *(f32 *)((u8 *)arg0 + 0xC) - z;
    if (position[2] < upper[2] && *(f32 *)((u8 *)arg0 + 0x1C) < position[1] &&
        position[0] < upper[0] && lower[0] < position[0]) {
        ((struct CrusherFlags *)arg0)->active = 1;
        if (func_80090150() != 0) {
            func_800904C8(0x59);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_80800508_chcrusher.s")

void func_808005C0_chcrusher(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_808005C8_chcrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_80800684_chcrusher.s")

OSThread *chcrusher_entrypoint_1(void)
{
    extern u8 D_80800C40_chcrusher[];

    return (OSThread *) D_80800C40_chcrusher;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_80800734_chcrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_80800838_chcrusher.s")

OSThread *chcrusher_entrypoint_2(void)
{
    extern u8 D_80800CC8_chcrusher[];

    return (OSThread *) D_80800CC8_chcrusher;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_808008FC_chcrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_80800A98_chcrusher.s")

void func_80800ACC_chcrusher(s32 arg0) 
{
}
void func_80800AD4_chcrusher(s32 arg0)
{
    _chswitch_entrypoint_14(arg0,FLAG_4FB_UNK);
}

OSThread *chcrusher_entrypoint_3(void)
{
    extern u8 D_80800D20_chcrusher[];

    return (OSThread *) D_80800D20_chcrusher;
}

OSThread *chcrusher_entrypoint_4(void)
{
    extern u8 D_80800D68_chcrusher[];

    return (OSThread *) D_80800D68_chcrusher;
}
