#include "common.h"

OSThread *chiciclebits_entrypoint_0(void)
{
    extern u8 D_808003A0_chiciclebits[];

    return (OSThread *) D_808003A0_chiciclebits;
}

void func_8080000C_chiciclebits(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EF334(f32 *, f32);
    void func_80101FDC(Actor *, u32);
    void func_8010A570(Actor *);
    extern s16 D_808003E8_chiciclebits[][5];
    typedef struct {
        u32 pad[4];
        s32 index;
        f32 height;
        u32 pad18;
        f32 speed;
    } IcicleData;
    register s32 index;
    f32 *volatile position;

    index = arg0->unk74_7 - 0x32; position = arg0->position; func_800EE88C(arg0->position, D_808003E8_chiciclebits[index]);
    func_800EF334(position, 100.0f);
    ((IcicleData *)arg0->actorData)->index = index;
    ((IcicleData *)arg0->actorData)->height = arg0->position[1];
    ((IcicleData *)arg0->actorData)->speed = 600.0f;
    arg0->position[1] += 2500.0f;
    if (func_800DA298((u16)D_808003E8_chiciclebits[index][3]) != 0) {
        arg0->position[1] = ((IcicleData *)arg0->actorData)->height;
        func_8010A570(arg0);
        func_80101FDC(arg0, 4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/iciclebits/func_808000D0_chiciclebits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/iciclebits/func_80800240_chiciclebits.s")
