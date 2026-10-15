#include "common.h"

OSThread *chattract_entrypoint_0(void)
{
    extern u8 D_808004F4_chattract[];

    return (OSThread *) D_808004F4_chattract;
}

void func_8080000C_chattract(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/attract/func_80800014_chattract.s")

void func_80800204_chattract(Actor *arg0, s32 arg1) {
    void func_800DF410(s32);
    void func_800DF47C(s32 (*)(Actor *), Actor *);
    void func_800DF4CC(f32 *);
    void func_800DF944(u32, f32 *, f32, f32, u8, u8, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_8010347C(Unk80132ED0 *);
    s32 func_801015D0(Actor *);
    f32 sp3C[3];
    if (arg0->rotation[1]) {
        func_800EFA4C(sp3C, 0.0f, arg0->rotation[1], 0.0f);
        func_800DF4CC(sp3C);
    }
    func_800DF410(arg0->alpha);
    func_800DF47C(&func_801015D0, arg0);
    func_800DF944(arg1, arg0->position, 0.0f, arg0->scale, 0, 1, func_8010347C(arg0->unk0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/attract/func_808002AC_chattract.s")

void chattract_entrypoint_1(s32 arg0) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, s32);
    extern s32 _chattract_entrypoint_2;
    _chbaddiesetup_entrypoint_1(&_chattract_entrypoint_2, arg0);
}

void chattract_entrypoint_2(s32 arg0) {
    void func_800EC828(void);
    Actor *func_80108454(s32, s32 *, u32);
    extern s32 B_80800540_chattract;
    Actor *temp_v0;
    Unk80132ED0 *temp_v0_2;

    temp_v0 = func_80108454(0x4B5, &B_80800540_chattract, 0);
    if (temp_v0 != NULL) {
        temp_v0->unk74_7 = arg0 + 1;
        temp_v0_2 = temp_v0->unk0;
        (*(u16 *)((s8 *)(temp_v0_2) + (0x12))) = (u16) (((*(u16 *)((s8 *)(temp_v0_2) + (0x12))) & 1) | 2);
        func_800EC828();
    }
}
