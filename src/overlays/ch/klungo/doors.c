#include "common.h"

OSThread *chklungodoors_entrypoint_0(void)
{
    extern u8 D_808004C0_chklungodoors[];

    return (OSThread *) D_808004C0_chklungodoors;
}

OSThread *chklungodoors_entrypoint_1(void)
{
    extern u8 D_80800508_chklungodoors[];

    return (OSThread *) D_80800508_chklungodoors;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/doors/func_80800018_chklungodoors.s")

void func_80800234_chklungodoors(Actor *arg0) {
    s32 _chdoor_entrypoint_0();
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddiefade_entrypoint_0(Actor *);
    u8 func_800D9078(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_8010A590(Actor *);
    extern u8 D_8080049E_chklungodoors[];
    extern u32 D_80800550_chklungodoors;
    s32 sp2C;
    s32 temp_v0;

    _chdoor_entrypoint_0();
    if (D_8080049E_chklungodoors[arg0->actorData[4] * 0x10] != 0) {
        temp_v0 = _subaddiefade_entrypoint_0(arg0);
        sp2C = temp_v0;
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, temp_v0 > 0, &D_80800550_chklungodoors);
        _subaddieaudioloop_entrypoint_0(arg0, func_800F10B4((f32) sp2C, 0.0f, 255.0f, 0.7f, 1.4f));
        if (arg0->unk70_10 == 1 && func_800D9078((f32 *)&arg0->actorData[5]) != 0) {
            func_8010A590(arg0);
        }
    }
}

s32 func_80800300_chklungodoors(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    void _chelectricfence_entrypoint_1(Actor *, f32 *);
    f32 func_800EC75C(void *, f32 *);
    s32 func_80103140(Actor *, u32, u16);
    void func_8010A570(Actor *);
    extern u16 D_80800498_chklungodoors[][8];
    extern u16 D_8080049A_chklungodoors[][8];
    extern u8 D_8080049E_chklungodoors[];
    f32 sp2C[3];
    void *volatile sp28;

    switch (arg1) {
        case 0x95:
            switch (arg0->unk6C_9) {
                case 0x41F:
                    func_80103140(arg0, D_80800498_chklungodoors[arg0->actorData[4]][0], arg0->unk0->unk16);
                    break;
                case 0x420:
                    func_80103140(arg0, D_8080049A_chklungodoors[arg0->actorData[4]][0], arg0->unk0->unk16);
                    break;
            }
            break;
        case 7:
            if (D_8080049E_chklungodoors[arg0->actorData[4] * 0x10] != 0) {
                func_8010A570(arg0);
            }
            break;
        case 8:
            if (D_8080049E_chklungodoors[arg0->actorData[4] * 0x10] != 0) {
                func_8010A570(arg0);
            }
            break;
        case 0x3F:
            sp28 = (void *)arg2;
            func_800EC75C((void *)arg2, sp2C);
            _chelectricfence_entrypoint_1(arg0, sp2C);
            *(f32 *)&arg0->actorData[5] = 0.2f;
            func_8010A570(arg0);
            return 1;
    }
    return _chdoor_entrypoint_1((s32)arg0, arg1, arg2);
}
