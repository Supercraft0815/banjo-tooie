#include "common.h"

/* extern */

void sumissilehome_entrypoint_0(s32 arg0, u8 *arg1) {
    s32 _subaddielink_entrypoint_0(u8 *);
    (*(s8 *)((s8 *)(arg1) + (8))) = 0;
    (*(s8 *)((s8 *)(arg1) + (9))) = 0;
    (*(s8 *)((s8 *)(arg1) + (0))) = -1;
    (*(s8 *)((s8 *)(arg1) + (1))) = -1;
    (*(f32 *)((s8 *)(arg1) + (4))) = 6000.0f;
    (*(s8 *)((s8 *)(arg1) + (0xA))) = 2;
    _subaddielink_entrypoint_0(arg1 + 0xC);
}

void sumissilehome_entrypoint_1(s32 arg0, void *arg1, s32 arg2) {
    (*(s8 *)((s8 *)(arg1) + (8))) = 1;
    (*(s16 *)((s8 *)(arg1) + (2))) = arg2;
}

void sumissilehome_entrypoint_2(s32 arg0, void *arg1, f32 arg2) {
    (*(s8 *)((s8 *)(arg1) + (0xA))) = 1;
    (*(f32 *)((s8 *)(arg1) + (4))) = arg2;
}

void sumissilehome_entrypoint_3(s32 arg0, s8 *arg1, s32 arg2) {
    *arg1 = arg2;
}

void sumissilehome_entrypoint_4(s32 arg0, s32 *arg1, s32 arg2) {
    (*(s8 *)((s8 *)(arg1) + (9))) = (s8)arg2;
}

/* extern */

void sumissilehome_entrypoint_5(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 func_800EA068(s32);
    Unk80132ED0 *func_8010A01C(s32, s32, s32, s32, s32);
    s32 func_8010D490(s32, s32, s32, s32, s32);
    s32 sp34;
    Unk80132ED0 *temp_v0_2;
    u8 * volatile sp2C;

    sp34 = -1;
    if ((arg1[8] != 0) || ((*(u8 *)((s8 *)(arg1) + (9))) != 0)) {
        if (arg1[8] != 0) {
            temp_v0_2 = func_8010A01C(arg0 + 4, arg0 + 0x28, arg2, arg3, (s32) (*(s16 *)((s8 *)(arg1) + (2))));
            _subaddielink_entrypoint_1(sp2C = arg1 + 0xC, temp_v0_2);
            if (_subaddielink_entrypoint_4(sp2C) == 0) {
                (*(u8 *)((s8 *)(arg1) + (8))) = 0U;
            }
        }
        if ((*(u8 *)((s8 *)(arg1) + (9))) != 0) {
            if (((*(u8 *)((s8 *)(arg1) + (8))) == 0) && (func_800EA068(0x4000) != 0)) {
                sp34 = func_8010D490(arg0 + 4, arg0 + 0x28, arg2, arg3, (s32) (*(s8 *)((s8 *)(arg1) + (0))));
            }
            (*(s8 *)((s8 *)(arg1) + (1))) = (s8) sp34;
        }
    }
}

/* extern */

void func_80800178_sumissilehome(void *arg0, void *arg1) {
    f32 func_800EEF94(f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    volatile struct { f32 *vector; f32 length; } saved;

    saved.length = func_800EEF94(saved.vector = (f32 *)((s8 *)arg0 + 0x28));
    func_800EFB24(saved.vector, arg1, (s8 *)arg0 + 4);
    func_800EF368(saved.vector, saved.length);
}

/* extern */

void func_808001C8_sumissilehome(void *arg0, void *arg1, f32 arg2) {
    f32 func_800D8FF8(void);
    f32 func_800EEF94(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    struct { f32 length; f32 delta[3]; } saved;
    f32 dt;

    saved.length = func_800EEF94((f32 *)((s8 *)arg0 + 0x28));
    func_800EFB24(saved.delta, arg1, (s8 *)arg0 + 4);
    dt = func_800D8FF8();
    func_800EF368(saved.delta, dt * arg2);
    func_800EF04C((f32 *)((s8 *)arg0 + 0x28), saved.delta);
    func_800EF368((f32 *)((s8 *)arg0 + 0x28), saved.length);
}

/* extern */

void sumissilehome_entrypoint_6(Actor *arg0, void *arg1) {
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_800F5A00(s32, f32 *);
    void func_8010A2FC(Actor *, f32 *, f32 *);
    f32 position[3];
    struct MissileHomeData {
        s8 unk0;
        s8 unk1;
        u8 pad2[2];
        f32 speed;
        u8 linked;
        u8 player;
        u8 mode;
        u8 padB;
        u8 link[1];
    } *data = arg1;
    Actor *temp_v0;
    s8 temp_a0;

    if (data->linked != 0) {
        temp_v0 = _subaddielink_entrypoint_4(data->link);
        if (temp_v0 == 0) {
            data->linked = 0;
            return;
        }
        func_8010A2FC(temp_v0, position, arg0->position);
        goto block_7;
    }
    if ((data->player != 0) && (temp_a0 = data->unk1, temp_a0 >= 0)) {
        func_800F5A00(temp_a0, position);
        position[1] += 60.0f;
block_7:
        if (data->mode == 1) {
            func_808001C8_sumissilehome(arg0, position, data->speed);
            return;
        }
        func_80800178_sumissilehome(arg0, position);
    }
}
