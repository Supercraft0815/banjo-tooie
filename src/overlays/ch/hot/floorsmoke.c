#include "common.h"

OSThread *chhotfloorsmoke_entrypoint_0(void)
{
    extern u8 D_808002D0_chhotfloorsmoke[];

    return (OSThread *) D_808002D0_chhotfloorsmoke;
}

/* extern */

void func_8080000C_chhotfloorsmoke(Actor *arg0) {
    s32 func_800EA05C();
    s32 temp_v0;

    arg0->unk64_20 = 1;
    temp_v0 = func_800EA05C();
    if (temp_v0 != 0xD1) {
        if (temp_v0 != 0x12B) {
            arg0->unk6C_0 = 0;
            return;
        }
        arg0->unk64_20 = 0;
        arg0->unk6C_0 = 2;
        return;
    }
    arg0->unk6C_0 = 1;
}

void func_80800090_chhotfloorsmoke(Actor *arg0) {
    s32 func_800D9078(f32 *);
    void func_80101FDC(Actor *, u32);
    void func_808000FC_chhotfloorsmoke(Actor *);

    switch (arg0->unk70_10) {
    case 1:
        func_808000FC_chhotfloorsmoke(arg0);
        return;
    case 2:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_80101FDC(arg0, 1);
        }
        return;
    }
}

void func_808000FC_chhotfloorsmoke(Actor *arg0) {
    void func_800CD08C(s32, f32 *);
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);
    void func_808001E8_chhotfloorsmoke(Actor *, f32[3]);
    f32 sp34;
    f32 sp28[3];

    switch (arg0->unk6C_0) {
    case 1:
        if (func_800DA298(0x66F) == 0) {
            return;
        }
        sp34 = func_800DC178(1.0f, 1.5f);
        break;
    case 2:
        sp34 = func_800DC178(1.0f, 1.5f);
        break;
    default:
        sp34 = func_800DC178(2.0f, 3.0f);
        break;
    }
    func_800CD08C(arg0->unk70_25 - 1, sp28);
    sp28[1] = arg0->position[1];
    func_808001E8_chhotfloorsmoke(arg0, sp28);
    func_80101FDC(arg0, 2);
    arg0->unk58 = sp34;
}

void func_808001E8_chhotfloorsmoke(Actor *arg0, f32 arg1[3]) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800DA298(s32);
    s32 func_800E3E8C(f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_80800318_chhotfloorsmoke[];
    extern s32 D_80800350_chhotfloorsmoke[];
    extern s32 D_80800388_chhotfloorsmoke[];
    f32 sp34[3];
    f32 sp28[3];
    s32 *var_v0;

    if (func_800E3E8C(arg1, 500.0f) != 0) {
        func_800EE7F8(sp34, arg1);
        sp34[1] -= 400.0f;
        func_800EE7F8(sp28, arg1);
        sp28[1] -= 20.0f;
        if (arg0->unk6C_0 == 2) {
            var_v0 = D_80800350_chhotfloorsmoke;
        } else {
            var_v0 = D_80800318_chhotfloorsmoke;
        }
        func_800BABB8(0, sp28, sp34, 1.0f, var_v0);
    }
    if (arg0->unk64_20 && (func_800DA298(0x66F) == 0)) {
        _subaddieaudioquick_entrypoint_2(arg0, arg1, D_80800388_chhotfloorsmoke);
    }
}
