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

s32 func_80800240_chiciclebits(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    s32 func_80101180(s32, s32, s32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    s32 func_80103140(Actor *, u32, u16);
    void func_8010A570(Actor *);
    extern u16 D_808003F0_chiciclebits[][5];
    extern u8 D_808004B8_chiciclebits[];
    extern u8 D_808004C8_chiciclebits[];
    s32 sp24;

    switch (arg1) {
        case 0x40:
            sp24 = func_80101180(0x41C, 0x43, 0) == 0;
            _subaddieaudioquick_entrypoint_2(arg0, NULL, D_808004B8_chiciclebits);
            _subaddieaudioquick_entrypoint_2(arg0, NULL, D_808004C8_chiciclebits);
            func_8010A570(arg0);
            func_80101FDC(arg0, 2);
            func_80103110(arg0, 1);
            func_80018820(0, 3.0f, 0.5f);
            arg0->unk58 = 1.4f;
            if (sp24) {
                _capod_entrypoint_13(arg0->unk0, NULL, 0, 0x11);
            }
            break;
        case 0x43:
            if (arg0->unk70_10 == 1) {
                return 0;
            }
            break;
        case 0x95:
            func_80103140(arg0, D_808003F0_chiciclebits[arg0->actorData[4]][0], arg0->unk0->unk16);
            break;
        default:
            return 0;
    }
    return 1;
}
