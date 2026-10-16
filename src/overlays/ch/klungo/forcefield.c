#include "common.h"

OSThread *chklungoforcefield_entrypoint_0(void)
{
    extern u8 D_80800400_chklungoforcefield[];

    return (OSThread *) D_80800400_chklungoforcefield;
}

void func_8080000C_chklungoforcefield(Actor *arg0) {
    typedef struct {
        s32 sound;
        f32 timer;
        f32 speed;
        u8 handle;
    } ForcefieldData;
    s32 _subaddiefade_entrypoint_2();
    s32 func_800C8A98();
    void func_800C8CB8(s32, f32[3]);
    s32 func_800C8E84(s32, s32 *);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    u8 func_800E8B74(u32);
    void func_800E8D28(u8, f32);
    void func_800E8D5C(u8, void *, s16);
    void func_800E8DB0(u8, s32);
    u32 func_8010A828(Actor *, u32);
    extern s32 D_80800448_chklungoforcefield;
    extern s32 D_80800460_chklungoforcefield;
    f32 var_f2;
    s32 temp_v0;
    u8 temp_v0_2;

    if (func_800DC298(0.5f) != 0) {
        var_f2 = 1.0f;
    } else {
        var_f2 = -1.0f;
    }
    ((ForcefieldData *)arg0->actorData)->speed = func_800DC178(30.0f, 45.0f) * var_f2;
    temp_v0 = func_800C8A98();
    ((ForcefieldData *)arg0->actorData)->sound = temp_v0;
    func_800C8CB8(temp_v0, arg0->position);
    func_800C8E84(((ForcefieldData *)arg0->actorData)->sound, &D_80800460_chklungoforcefield);
    temp_v0_2 = func_800E8B74(0);
    ((ForcefieldData *)arg0->actorData)->handle = temp_v0_2;
    func_800E8DB0(temp_v0_2, 0xFF);
    func_800E8D28(((ForcefieldData *)arg0->actorData)->handle, 1.0f);
    func_800E8D5C(((ForcefieldData *)arg0->actorData)->handle, &D_80800448_chklungoforcefield, 3);
    _subaddiefade_entrypoint_2(arg0);
    func_8010A828(arg0, 0x40);
}

void func_808000F0_chklungoforcefield(Actor *arg0) {
    typedef struct {
        s32 sound;
        f32 timer;
        f32 speed;
    } ForcefieldData;
    void _subaddieaudioloop_entrypoint_1(u8 *, s32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddiefade_entrypoint_0(Actor *);
    void func_800C8E54(s32, f32, f32);
    f32 func_800D8FF8(void);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    extern u32 D_8080046C_chklungoforcefield;
    f32 temp_f0;

    ((ForcefieldData *)arg0->actorData)->timer += ((ForcefieldData *)arg0->actorData)->speed * func_800D8FF8();
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_8080046C_chklungoforcefield);
    _subaddieaudioloop_entrypoint_1((u8 *)arg0, (s32) func_800F12D4((f32) _subaddiefade_entrypoint_0(arg0), 0.0f, 255.0f, 8000.0f, 32767.0f));
    if (((ForcefieldData *)arg0->actorData)->sound != 0) {
        temp_f0 = func_800F12D4((f32) _subaddiefade_entrypoint_0(arg0), 0.0f, 255.0f, 300.0f, 800.0f);
        func_800C8E54(((ForcefieldData *)arg0->actorData)->sound, temp_f0, 2.0f * temp_f0);
    }
}

void func_808001D4_chklungoforcefield(u8 *arg0) {
    void func_800C8B84(s32);
    void func_800E8C08(u8 a0);
    s32 temp_a1;
    u8 temp_a0;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x18)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
    temp_a0 = (*(u8 *)((s8 *)(arg0) + (0x24)));
    if (temp_a0 != 0) {
        func_800E8C08(temp_a0);
        (*(u8 *)((s8 *)(arg0) + (0x24))) = 0U;
    }
}

/* extern */

s32 func_80800228_chklungoforcefield(void *arg0, s32 arg1, s32 arg2) {
    s32 _chlightfader_entrypoint_1(s32, s32, s32, void *);
    s32 _subaddiefade_entrypoint_3(void *);
    s32 temp_a0;

    if (arg1 == 0x2C) {
        temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x18)));
        if (temp_a0 != 0) {
            (*(s32 *)((s8 *)(arg0) + (0x18))) = _chlightfader_entrypoint_1(temp_a0, 0x4019999A, 2, arg0);
        }
        _subaddiefade_entrypoint_3(arg0);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/forcefield/func_80800288_chklungoforcefield.s")
