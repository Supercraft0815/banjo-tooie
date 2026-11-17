#include "common.h"

OSThread *chklungoforcefield_entrypoint_0(void)
{
    extern ActorData D_80800400_chklungoforcefield[];

    return (OSThread *) D_80800400_chklungoforcefield;
}

void func_8080000C_chklungoforcefield(Actor *arg0) {
    typedef struct {
        s32 sound;
        f32 timer;
        f32 speed;
        u8 handle;
    } ForcefieldData;
    void _subaddiefade_entrypoint_2(void *arg0);
    s32 func_800C8A98();
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E84(s32 id,u32 *color);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    u8 func_800E8B74(u32);
    void func_800E8D28(u8, f32);
    void func_800E8D5C(u8, void *, s16);
    void func_800E8DB0(u8, s32);
    void func_8010A828(void **arg0, s32 arg1);
    extern s32 D_80800448_chklungoforcefield[6];
    extern s32 D_80800460_chklungoforcefield[3];
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
    func_800C8E84(((ForcefieldData *)arg0->actorData)->sound, D_80800460_chklungoforcefield);
    temp_v0_2 = func_800E8B74(0);
    ((ForcefieldData *)arg0->actorData)->handle = temp_v0_2;
    func_800E8DB0(temp_v0_2, 0xFF);
    func_800E8D28(((ForcefieldData *)arg0->actorData)->handle, 1.0f);
    func_800E8D5C(((ForcefieldData *)arg0->actorData)->handle, D_80800448_chklungoforcefield, 3);
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
    extern u32 D_8080046C_chklungoforcefield[5];
    f32 temp_f0;

    ((ForcefieldData *)arg0->actorData)->timer += ((ForcefieldData *)arg0->actorData)->speed * func_800D8FF8();
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_8080046C_chklungoforcefield);
    _subaddieaudioloop_entrypoint_1((u8 *)arg0, (s32) func_800F12D4((f32) _subaddiefade_entrypoint_0(arg0), 0.0f, 255.0f, 8000.0f, 32767.0f));
    if (((ForcefieldData *)arg0->actorData)->sound != 0) {
        temp_f0 = func_800F12D4((f32) _subaddiefade_entrypoint_0(arg0), 0.0f, 255.0f, 300.0f, 800.0f);
        func_800C8E54(((ForcefieldData *)arg0->actorData)->sound, temp_f0, 2.0f * temp_f0);
    }
}                typedef struct { u8 pad0[0x18]; s32 unk18; u8 pad1C[0x8]; u8 unk24; } Objforcefield_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_808001D4_chklungoforcefield(u8 *arg0) {
    void func_800C8B84(s32);
    void func_800E8C08(u8 a0);
    s32 temp_a1;
    u8 temp_a0;

    temp_a1 = (((Objforcefield_arg0 *)arg0)->unk18);
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (((Objforcefield_arg0 *)arg0)->unk18) = 0;
    }
    temp_a0 = (((Objforcefield_arg0 *)arg0)->unk24);
    if (temp_a0 != 0) {
        func_800E8C08(temp_a0);
        (((Objforcefield_arg0 *)arg0)->unk24) = 0U;
    }
}

/* extern */

s32 func_80800228_chklungoforcefield(void *arg0, s32 arg1, s32 arg2) {
    s32 _chlightfader_entrypoint_1(s32, s32, s32, void *);
    void _subaddiefade_entrypoint_3(void *arg0);
    s32 temp_a0;

    if (arg1 == 0x2C) {
        temp_a0 = (((Objforcefield_arg0 *)arg0)->unk18);
        if (temp_a0 != 0) {
            (((Objforcefield_arg0 *)arg0)->unk18) = _chlightfader_entrypoint_1(temp_a0, 0x4019999A, 2, arg0);
        }
        _subaddiefade_entrypoint_3(arg0);
        return 1;
    }
    return 0;
}

void func_80800288_chklungoforcefield(Actor *arg0, s32 arg1) {
    typedef struct {
        s32 sound;
        f32 timer;
        f32 speed;
        u8 handle;
    } ForcefieldData;
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF47C(s32 (*)(Actor *), Actor *);
    void func_800E3A58(f32 *);
    s32 func_800E8C58(u8);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 *func_801018D8(Actor *);
    int func_80101970(Actor *);
    BtIntPtr func_8010347C(Unk80132ED0 *);
    s32 func_801015D0(Actor *);
    f32 sp3C[3];
    f32 sp38;
    s32 sp34;
    ForcefieldData *data;
    f32 *sp2C;

    data = (ForcefieldData *)arg0->actorData;
    sp34 = arg0->alpha;
    sp38 = func_800F10B4((f32)func_800E8C58(data->handle), 0.0f, 255.0f, 0.6f, 1.0f);
    func_800E3A58(sp3C);
    func_80101970(arg0);
    sp3C[2] += data->timer;
    arg0->alpha = (u32)((f32)sp34 * sp38);
    func_800DF47C(func_801015D0, arg0);
    sp2C = func_801018D8(arg0);
    func_800DE448(arg0->position, sp3C, arg0->scale, sp2C, func_8010347C(arg0->unk0));
    arg0->alpha = sp34;
}
/* data_to_c.py: from asm/data/overlays/ch/klungo/forcefield.data.s */
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800400_chklungoforcefield [1] BT_DATA(4, overlays_ch_klungo_forcefield, 0x0) = { { 180, 1057, 2082, 1, 0, (void (*)(struct Actor *))func_808000F0_chklungoforcefield, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800288_chklungoforcefield, 0, 0, 0, 0, 16, 1028, (void (*)(struct Actor *))func_808001D4_chklungoforcefield, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chklungoforcefield, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8192, (void (*)(struct Actor *, long, long))func_80800228_chklungoforcefield, 0 } };
s32 D_80800448_chklungoforcefield[6] BT_DATA(4, overlays_ch_klungo_forcefield, 0x48) = { 0, 0, 1056964608, 1065353216, 1065353216, 0 };
s32 D_80800460_chklungoforcefield[3] BT_DATA(4, overlays_ch_klungo_forcefield, 0x60) = { 32, 224, 255 };
u32 D_8080046C_chklungoforcefield[5] BT_DATA(4, overlays_ch_klungo_forcefield, 0x6C) = { 0x1305B7, 0xE00F3, 0x10C0019, 0x161F40, 0 };
