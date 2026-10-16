#include "common.h"

OSThread *chtntblockage_entrypoint_0(void)
{
    extern u8 D_80800240_chtntblockage[];

    return (OSThread *) D_80800240_chtntblockage;
}

void func_8080000C_chtntblockage(Actor *arg0) {
    void func_800C4AF0(f32 *, void *);
    f32 func_800D8FF8(void);
    void func_800FFAB0(Actor *);
    extern s32 D_80800288_chtntblockage;
    if (arg0->unk70_10 == 2) {
        arg0->unk58 += func_800D8FF8();
        if (arg0->unk58 > 0.5f) {
            func_800C4AF0(arg0->position, &D_80800288_chtntblockage);
            func_800FFAB0(arg0);
        }
    }
}

void func_80800088_chtntblockage()
{
    _subaddiefade_entrypoint_14();
}

s32 func_808000A8_chtntblockage(s32 arg0) {
    return ((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) + 0x4C;
}

s32 func_808000B8_chtntblockage(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _chtntdetonator_entrypoint_1(Actor *, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80800184_chtntblockage(Actor *);
    f32 position[3];

    switch (arg1) {
    case 5:
        func_800EE7F8(position, arg0->position);
        func_800EF1B8(position, arg0->rotation[1], -300.0f);
        position[1] -= 110.0f;
        _chexploder_entrypoint_3(arg0, position, 0);
        break;
    case 0x90:
        func_80800184_chtntblockage(arg0);
        break;
    case 0x95:
        _chtntdetonator_entrypoint_1(arg0, func_808000A8_chtntblockage((s32)arg0));
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800184_chtntblockage(Actor *arg0) {
    s32 _chexploder_entrypoint_12(s32, s32);
    void _chexploder_entrypoint_13(s32, u32);
    void _chexploder_entrypoint_15(s32, u32, f32);
    s32 _chexploder_entrypoint_6(s32, f32, f32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800DA544(GameFlag);
    Unk80132ED0 *func_80101080(void);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_8080029C_chtntblockage[];
    Actor *temp_v0;

    temp_v0 = func_80106790(func_80101080());
    _chexploder_entrypoint_12((s32)temp_v0, 0x32);
    _chexploder_entrypoint_6((s32)temp_v0, 1200.0f, 1400.0f);
    _chexploder_entrypoint_13((s32)temp_v0, 4);
    _chexploder_entrypoint_15((s32)temp_v0, 1, 1.2f);
    func_800BABB8(0, arg0->position, (f32 *)temp_v0->actorData, arg0->scale, D_8080029C_chtntblockage);
    func_800DA544(func_808000A8_chtntblockage((s32)arg0));
    func_80101FDC(arg0, 2);
    func_80103110(arg0, 1);
}
