#include "ch/crusher.h"

s32 func_80800000_chcrusher(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *func_80108474(u32, f32 *, s32);
    f32 position[3];
    s32 result;

    if (arg1 == 0x49) {
        position[0] = arg0->position[0];
        position[2] = arg0->position[2];
        position[1] = 0.0f;
        func_80108474(0x386, position, -0x5A);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

OSThread *chcrusher_entrypoint_0(void)
{
    extern u8 D_80800B98_chcrusher[];

    return (OSThread *) D_80800B98_chcrusher;
}

void func_80800068_chcrusher(Actor *arg0, u8 *arg1) {
    s32 func_800DBEFC(s32, s32, s32);
    void func_80101870(Actor* arg0, void* arg1);
    OSThread * func_80104130(void);
    func_80101870(arg0, arg1);
    if (((struct { u32 unused : 19; u32 active : 1; u32 rest : 12; } *)((u8 *)arg0 + 0x7C))->active) {
        func_800DBEFC(func_80104130(), 6, (s32) arg0->actorData);
        func_800DBEFC(func_80104130(), 4, (s32) &arg0->actorData[4]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_808000D4_chcrusher.s")

void func_80800394_chcrusher(u8 *arg0) {
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80800BF0_chcrusher;
    func_800BABB8(0, arg0 + 0x28, 0, 0x3F800000, &D_80800BF0_chcrusher);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.3f;
}

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

/* extern */

void func_80800508_chcrusher(Actor *arg0) {
    void func_8008FA94(f32 *, f32 *);
    void func_8010D254(f32 *);
    f32 upper[3];
    f32 lower[3];
    f32 x;
    f32 z;
    f32 position[3];

    z = ((f32 *)arg0->actorData)[2] - arg0->position[2];
    x = arg0->position[0] - ((f32 *)arg0->actorData)[0];
    z += 25.0f;
    func_8010D254(position);
    upper[0] = arg0->position[0] - x;
    lower[0] = arg0->position[0] + x;
    upper[1] = ((f32 *)arg0->actorData)[1];
    lower[1] = ((f32 *)arg0->actorData)[1] + 1000.0f;
    upper[2] = arg0->position[2] - z;
    lower[2] = arg0->position[2] + z;
    func_8008FA94(upper, lower);
}

void func_808005C0_chcrusher(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusher/func_808005C8_chcrusher.s")

/* extern */

s32 func_80800684_chcrusher(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80090494(s32, f32 *);
    void func_8010D254(f32 *);

    if (arg1 == 0x3E) {
        if (arg0->unk70_10 == 2) {
            func_8010D254((f32 *)arg0->actorData);
            if (((f32 *)arg0->actorData)[2] < -50.0f) {
                ((f32 *)arg0->actorData)[0] =
                    ((f32 *)arg0->actorData)[0] - 50.0f;
                func_80090494(6, (f32 *)arg0->actorData);
            }
        }
        arg1 = 1;
    } else {
        return 0;
    }
    return arg1;
}

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

void func_80800A98_chcrusher(s32 arg0) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg0 + 4, 0.0f, -10.0f, 0.0f);
}

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
