#include "common.h"

OSThread *chdrips_entrypoint_0(void)
{
    extern u8 D_80800610_chdrips[];

    return (OSThread *) D_80800610_chdrips;
}

void chdrips_entrypoint_1(s32 arg0, s32 arg1)
{
  s32 _fxripple_entrypoint_0(s32, s32);
  s32 func_800C4140(s32, s32, s32);
  f32 func_800DC178(f32, f32);
  func_800C4140(((((u32) (func_800DC178(1.0f, 1.4f) * 1023.0f)) << 13) << 8) + 0xBBD53, arg1, 0x05DC012C);
  _fxripple_entrypoint_0(0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/chdrips_entrypoint_2.s")

void func_80800260_chdrips(Actor *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    s32 func_800BA4D0(s32, s16);
    void func_800BA544(s32 *, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    int func_800DC298(f32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80800698_chdrips[];
    extern s32 _chdrips_entrypoint_1;
    extern s32 _chdrips_entrypoint_2;
    s32 temp_v0;
    struct {
        f32 position[3];
        f32 size;
        u8 flag;
        u8 pad[3];
    } *temp_s0;

    if (func_800DC298(arg0->rotation[1] * 0.333f * 0.0027777778f) != 0) {
        temp_s0 = func_80100094(arg0, 0);
        temp_v0 = func_800B53A4(1);
        temp_s0 += arg0->unk6C_0;
        if (temp_s0->flag != 0) {
            func_800BA544(temp_v0, &_chdrips_entrypoint_1);
        } else {
            func_800BA544(temp_v0, &_chdrips_entrypoint_2);
        }
        func_800BA4D0(temp_v0, (s16) (s32) temp_s0->size);
        func_800BABB8(temp_v0, temp_s0->position, NULL, 1.0f, D_80800698_chdrips);
        func_800BA22C(temp_v0, 1);
        arg0->unk6C_0 = func_800DC128(0, arg0->unk74_7);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/func_80800394_chdrips.s")

void func_808005CC_chdrips(Actor *arg0) {
    u32* func_80100074(Actor*, u32, u32);
    func_80100074(arg0, 0U, 0U);
}
