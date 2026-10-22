#include "common.h"

OSThread *chdiggergroundgen_entrypoint_0(void)
{
    extern u8 D_80800500_chdiggergroundgen[];

    return (OSThread *) D_80800500_chdiggergroundgen;
}

/* extern */

void func_8080000C_chdiggergroundgen(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _subaddielink_entrypoint_0(u8 *);
    _subaddielink_entrypoint_0(func_80100094(arg0, 0U));
}

void func_80800034_chdiggergroundgen(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_80800118_chdiggergroundgen(Actor *);
    void func_8080035C_chdiggergroundgen(Actor *);
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 1:
            if (_subaddielink_entrypoint_4(data) == NULL) {
                func_80800118_chdiggergroundgen(arg0);
            }
            break;
        case 2:
            func_8080035C_chdiggergroundgen(arg0);
            break;
    }
}

s32 func_808000AC_chdiggergroundgen(Actor *arg0, s32 arg1, s32 arg2) {
    void func_808002C4_chdiggergroundgen(Actor *);
    void *func_80100094(Actor *, u32);
    s32 _subaddielink_entrypoint_3(u8 *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x3D:
            func_808002C4_chdiggergroundgen(arg0);
            break;
        case 0x95:
            _subaddielink_entrypoint_3(func_80100094(arg0, 0));
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800118_chdiggergroundgen(Actor *arg0) {
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    s32 func_800CC338(f32 *, s32, s32);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F2094(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    f32 func_8010CD28(Actor *);
    f32 position[3];
    f32 angle;
    f32 start[3];
    f32 end[3];
    f32 normal[3];
    f32 distance;
    f32 heading;
    f32 *data;

    data = func_80100094(arg0, 0);
    heading = func_8010CD28(arg0);
    while (1) {
        angle = func_800DC0C0() * 360.0f;
        if (func_800F2094(angle, heading) < 30.0f) {
            continue;
        }
        distance = func_800DC178(300.0f, 500.0f);
        func_800EE7F8(position, arg0->position);
        func_800EF1B8(position, angle, distance);
        if (func_800CC338(position, arg0->unk70_25 - 1, 0) == -1) {
            continue;
        }
        break;
    }
    func_800EE7F8(start, position);
    func_800EE7F8(end, position);
    start[1] += 200.0f;
    end[1] -= 200.0f;
    func_800BEF00(start, end, normal, arg0->unk14);
    position[1] = end[1];
    func_800EE7F8(&data[2], position);
    func_80108B04(arg0, 0);
    func_80101FDC(arg0, 2);
    arg0->unk58 = 0.85f;
}

void func_808002C4_chdiggergroundgen(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    f32 func_800DC178(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102FDC(void *, f32);
    Actor *func_801084B0(s32, Actor **);
    extern u8 D_80800548_chdiggergroundgen[];
    f32 *sp1C;
    Actor *sp18;

    sp1C = func_80100094(arg0, 0);
    sp18 = func_801084B0(0x131, &arg0);
    func_80102FDC(sp18, func_800DC178(0.8f, 1.2f));
    sp18->rotation[1] = func_800F1DF4(arg0->position, &sp1C[2]);
    _subaddielink_entrypoint_1(sp1C, sp18->unk0);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800548_chdiggergroundgen);
}

void func_8080035C_chdiggergroundgen(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 func_800D9078(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_8001395C(f32);
    s32 func_8008FB10(f32 *, f32, f32, f32);
    void func_800B4470(f32 *, f32 *, f32 *, s32, f32, f32, s32, s32, s32);
    void func_800C4104(s32, f32, s32, s32, f32, f32);
    void func_80101FDC(Actor *, u32);
    extern f32 D_80800554_chdiggergroundgen[];
    f32 *data;
    Actor *actor;
    s32 finished;
    f32 t;

    data = func_80100094(arg0, 0);
    actor = _subaddielink_entrypoint_4(data);
    finished = func_800D9078(&arg0->unk58);
    t = func_800F10B4(arg0->unk58, 0.0f, 0.85f, 1.0f, 0.0f);
    func_800EFE50(actor->position, arg0->position, &data[2], t);
    actor->position[1] += func_8001395C(t * 3.1415927f) * 250.0f;
    func_8008FB10(actor->position, 90.0f, arg0->position[1] - actor->position[1], actor->scale * 100.0f);
    if (finished) {
        func_800B4470(actor->position, NULL, D_80800554_chdiggergroundgen, 1, 0.8f, 0.0f, 100, 150, 0);
        func_800C4104(0x419, 1.0f, 0x6D60, actor->position, 1250.0f, 2500.0f);
        actor->unk64_20 = 1;
        func_80101FDC(arg0, 1);
    }
}
