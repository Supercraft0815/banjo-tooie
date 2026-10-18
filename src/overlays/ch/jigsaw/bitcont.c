#include "common.h"

void func_80800000_chjigsawbitcont(Actor *arg0, u32 arg1) {
    s32 func_800DA298(GameFlag);
    void func_800DA544(GameFlag);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    extern s16 D_808009B4_chjigsawbitcont[][8];
    func_80101FDC(arg0, arg1);
    if ((arg1 == 2) && (func_800DA298(D_808009B4_chjigsawbitcont[arg0->unk74_7][0]) == 0)) {
        func_800DA544(D_808009B4_chjigsawbitcont[arg0->unk74_7][0]);
        func_80108B04(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/bitcont/func_80800084_chjigsawbitcont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/bitcont/func_80800214_chjigsawbitcont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/bitcont/func_808002E4_chjigsawbitcont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/bitcont/func_8080040C_chjigsawbitcont.s")

OSThread *chjigsawbitcont_entrypoint_0(void)
{
    extern u8 D_808009B8_chjigsawbitcont[];

    return (OSThread *) D_808009B8_chjigsawbitcont;
}

void func_80800570_chjigsawbitcont(Actor *arg0, u32 arg1) {
    void func_80101FDC(Actor *, u32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void _subaddiebounce_entrypoint_0(Actor *);
    s32 _subaddieDll_entrypoint_4(void *, s32);

    func_80101FDC(arg0, arg1);
    switch (arg0->unk70_10) {
        case 2:
            arg0->unk79_4 = 3;
            ((f32 *)arg0->actorData)[3] = func_800DC178(0.0f, 250.0f);
            _subaddiebounce_entrypoint_0(arg0);
            arg0->unk64_16 = 1;
            break;
        case 3:
            func_800EE7F8(arg0->position, (f32 *)arg0->actorData);
            _subaddieDll_entrypoint_4(arg0, 0);
            break;
        case 4:
            func_800EE7F8(arg0->position, (f32 *)arg0->actorData);
            arg0->unk64_16 = 1;
            break;
    }
}

void func_80800634_chjigsawbitcont(s32 arg0) {
    s32 func_8001211C();
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    f32 func_800DC0C0();
    s32 func_800E3E8C(s32, s32);
    s32 func_800FFAB0(s32);
    s32 func_8010C9B0(s32, s32);
    s32 func_8080040C_chjigsawbitcont(s32);
    extern s32 D_80800A00_chjigsawbitcont;
    s32 sp24;
    s32 temp_a0;

    temp_a0 = arg0 + 4;
    sp24 = temp_a0;
    if ((func_800E3E8C(temp_a0, 0x42480000) != 0) && !(func_8001211C() & 3) && (func_800DC0C0() < 0.1f)) {
        func_800BBCB8(sp24, 0, 0x3F800000, 2, &D_80800A00_chjigsawbitcont);
    }
    if (func_8010C9B0(sp24, 0x32) != 0) {
        func_8080040C_chjigsawbitcont(arg0);
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/bitcont/func_808006D8_chjigsawbitcont.s")

void func_80800868_chjigsawbitcont(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x38))) = 0.2f;
    (*(f32 *)((s8 *)(arg0) + (0x34))) = -1500.0f;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 840.0f;
}

void func_80800890_chjigsawbitcont(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *actor;
    f32 (*positions)[3];
    f32 *range;
    Actor *func_801084B0(s32, Actor **);
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800DC178(f32, f32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void func_80800570_chjigsawbitcont(Actor *, u32);
    extern f32 D_808009A8_chjigsawbitcont[][4];

    actor = func_801084B0(0x17F, &arg0);
    positions = func_80100094(arg0, 0);
    actor->unk6C_0 = arg1;
    func_800EE7F8((f32 *)actor->actorData, positions[actor->unk6C_0]);
    actor->unk3C = arg0->unk0;
    range = D_808009A8_chjigsawbitcont[arg0->unk74_7];
    actor->unk58 = func_800DC178(range[1], range[2]);
    switch (arg2) {
        case 0:
            _subaddieDll_entrypoint_4(actor, 1);
            break;
        case 1:
            func_80800570_chjigsawbitcont(actor, 4);
            break;
    }
}

OSThread *chjigsawbitcont_entrypoint_1(void)
{
    extern u8 D_80800A28_chjigsawbitcont[];

    return (OSThread *) D_80800A28_chjigsawbitcont;
}
