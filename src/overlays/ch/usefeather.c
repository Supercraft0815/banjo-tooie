#include "common.h"

void func_80800000_chusefeather(Actor *arg0) {
    s32 _subaddiefade_entrypoint_1(s32, s32);
    void func_800BA3FC(s32, s32);
    void func_800BA75C(s32, f32[3]);
    void func_800BABA0(void *, f32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FFAB0(Actor *);
    extern s32 D_80800340_chusefeather[];
    s32 i;
    s32 emitter;
    f32 position[3];
    s32 alpha;

    func_800EF1B8(arg0->position, arg0->rotation[1], ((f32 *)arg0->actorData)[3]);
    if (((f32 *)arg0->actorData)[1] > -100.0f) {
        ((f32 *)arg0->actorData)[1] -= 3.5f;
    }
    if (arg0->position[1] > -16000.0f) {
        arg0->position[1] += ((f32 *)arg0->actorData)[1];
    }
    if (arg0->unk58 > 0.5f) {
        for (i = 0; i < 3; i++) {
            position[i] = arg0->position[i] + 2.0f * func_800DC0C0() * 25.0f - (i == 1 ? 0 : 25);
        }
        emitter = func_800BABB8(0, position, NULL, 1.0f, D_80800340_chusefeather);
        func_800BA3FC(emitter, arg0->unk6C_9 == 0x26A ? 0x9E4 : 0x9E2);
        func_800BA75C(emitter, position);
        func_800BABA0((void *)emitter, 0.25f);
    }
    arg0->unk58 -= func_800D8FF8();
    if (arg0->unk58 < 0.0f) {
        func_800FFAB0(arg0);
    } else {
        alpha = (s32)func_800F10B4(arg0->unk58, 0.0, 0.3f, 0.0, 255.0f);
        _subaddiefade_entrypoint_1((s32)arg0, alpha);
        if (alpha == 0) {
            func_800FFAB0(arg0);
        }
    }
}

void chusefeather_entrypoint_0(s32 arg0, s32 arg1) {
    f32 func_800DC0C0(void);
    void func_800F5A00(s32, f32 *);
    f32 func_800F5F24(u32);
    void func_80102FDC(Actor *, f32);
    Actor *func_80108474(u32, f32 *, s32);
    Actor *sp2C;
    f32 sp20[3];
    s32 var_v0;
    f32 sp18;

    func_800F5A00(arg0, sp20);
    sp18 = func_800F5F24(arg0);
    var_v0 = (func_800DC0C0() > 0.5f) ? 0x1E : -0x1E;
    sp2C = func_80108474(arg1, sp20, (s32) (var_v0 + sp18));
    func_80102FDC(sp2C, 0.45f);
    ((f32 *)sp2C->actorData)[3] = 22.0f;
    ((f32 *)sp2C->actorData)[1] = 48.0f;
    sp2C->unk58 = 1.2f;
}

void chusefeather_entrypoint_1(s32 arg0, s32 arg1) {
    s32 _chbaddiesetup_entrypoint_2(s32 *, s32, s32);
    s32 func_800D3948();
    extern s32 _chusefeather_entrypoint_0;
    s32 var_a2;

    if (func_800D3948() == 0) {
        if (arg1 == 0) {
            var_a2 = 0x26A;
        } else {
            var_a2 = 0x26B;
        }
        _chbaddiesetup_entrypoint_2(&_chusefeather_entrypoint_0, arg0, var_a2);
    }
}

OSThread *chusefeather_entrypoint_2(void)
{
    extern u8 D_80800364_chusefeather[];

    return (OSThread *) D_80800364_chusefeather;
}

OSThread *chusefeather_entrypoint_3(void)
{
    extern u8 D_808003AC_chusefeather[];

    return (OSThread *) D_808003AC_chusefeather;
}
