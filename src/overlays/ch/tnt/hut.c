#include "common.h"

OSThread *chtnthut_entrypoint_0(void)
{
    extern u8 D_80800220_chtnthut[];

    return (OSThread *) D_80800220_chtnthut;
}

void func_8080000C_chtnthut(s32 arg0) 
{
}
/* extern */

void func_80800014_chtnthut(Actor *arg0) {
    void func_800C4104(s32, f32, s32, s32, f32, f32);
    f32 func_800D8FF8(void);
    void func_800FFAB0(Actor *);
    if (arg0->unk70_10 == 2) {
        arg0->unk58 += func_800D8FF8();
        if (arg0->unk58 > 0.5f) {
            func_800C4104(0x43F, 0.9f, 0x6D60, arg0->position, 1250.0f, 2500.0f);
            func_800FFAB0(arg0);
        }
    }
}

s32 func_808000B0_chtnthut(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _chtntdetonator_entrypoint_1(Actor *, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80800170_chtnthut(Actor *);
    f32 sp1C[3];

    switch (arg1) {
    case 5:
        func_800EE7F8(sp1C, arg0->position);
        func_800EF1B8(sp1C, arg0->rotation[1], -100.0f);
        sp1C[1] += 75.0f;
        _chexploder_entrypoint_3(arg0, sp1C, 0);
        break;
    case 0x90:
        func_80800170_chtnthut(arg0);
        break;
    case 0x95:
        _chtntdetonator_entrypoint_1(arg0, 0x84);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800170_chtnthut(Actor *arg0) {
    void _chexploder_entrypoint_10(Actor *, s32 *);
    s32 _chexploder_entrypoint_12(s32, s32);
    void _chexploder_entrypoint_13(s32, u32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800DA544(GameFlag);
    Unk80132ED0 *func_80101080(void);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80800268_chtnthut;
    extern s32 D_808002D8_chtnthut;
    Actor *sp24;
    Actor *temp_v0;

    temp_v0 = func_80106790(func_80101080());
    sp24 = temp_v0;
    _chexploder_entrypoint_12(temp_v0, 0x3C);
    _chexploder_entrypoint_13(sp24, 4);
    _chexploder_entrypoint_10(sp24, &D_808002D8_chtnthut);
    func_800BABB8(0, arg0->position, (f32 *)sp24->actorData, arg0->scale, &D_80800268_chtnthut);
    func_80101FDC(arg0, 2);
    func_80103110(arg0, 1);
    func_800DA544(0x84);
}
