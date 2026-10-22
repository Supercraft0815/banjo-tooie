#include "common.h"

OSThread *chweldarhead_entrypoint_0(void)
{
    extern u8 D_808004F0_chweldarhead[];

    return (OSThread *) D_808004F0_chweldarhead;
}

void func_8080000C_chweldarhead(Actor *arg0) {
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 _susubgame_entrypoint_12(u32 *, s32 *);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    void func_800F497C(s32);
    void func_800F49D4(s32, void *, s32);
    void func_800F4A58(s32, s32, f32);
    u32 func_800F54E4(void);
    void func_800F8294(s32, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80108B04(Actor *, u32);
    extern s32 D_808004E0_chweldarhead[];
    extern s32 func_8010D5DC;
    f32 *data;
    f32 position[6];
    f32 target[6];
    s32 player;

    data = func_80100094(arg0, 0);
    _susubgame_entrypoint_0(arg0, (u32 *)(data + 6), 0);
    _susubgame_entrypoint_12((u32 *)(data + 6), D_808004E0_chweldarhead);
    if (func_800DA298(0x18C) == 0) {
        func_800FFAB0(arg0);
        return;
    }
    _subaddiemarker_entrypoint_1(arg0, 0x320, 0x32, data, 1);
    if (func_800DA9E4(0x9C9, 0) != 0) {
        player = func_800F54E4();
        _subaddiemarker_entrypoint_1(arg0, 0x320, 0x33, position, 1);
        _subaddiemarker_entrypoint_1(arg0, 0x320, 0x34, target, 1);
        func_800F8294(player, position);
        func_800F497C(player);
        func_800F49D4(player, &func_8010D5DC, arg0->unk0);
        func_800F4A58(player, target, 250.0f);
        _susubgame_entrypoint_6(arg0, data + 6, 0x44, 0x2030, 0);
        func_80102424(arg0, 2);
        return;
    }
    arg0->unk64_20 = 0;
    func_80108B04(arg0, 0);
}

void func_80800170_chweldarhead(u8 *arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    s32 func_800DC128(s32, s32);
    extern s32 D_80800538_chweldarhead;
    extern s16 D_8080053E_chweldarhead;
    if (((Actor *) arg0)->unk70_10 == 1) {
        D_8080053E_chweldarhead = func_800DC128(0, 4) + 0x1361;
        _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80800538_chweldarhead);
    }
    _sudeflect_entrypoint_0((f32 *) (arg0 + 4), 20.0f, 120.0f, 0xA);
}

s32 func_808001E4_chweldarhead(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_8080038C_chweldarhead(Actor *, s32, s32);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_80102FDC(void *, f32);
    void _chappearfx_entrypoint_1(Actor *, u32, u32, f32);
    extern s32 D_808004E0_chweldarhead[];
    f32 *data;
    Actor *spawned;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        default:
            return 0;
        case 0x2E:
            func_8080038C_chweldarhead(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(arg0, data + 6, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808004E0_chweldarhead, arg0->scale);
            break;
        case 0x32:
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1360, 0xE, arg0->position, 0xB5);
            break;
        case 0xB:
            if (arg2 == 0x48) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1384, 0xE, arg0->position, 0xB5);
                return 4;
            }
            return 3;
        case 0x3D:
            spawned = func_80108528(0x210, data, (s32)data[4], &arg0);
            func_80102FDC(spawned, data[5]);
            if (arg0->unk64_20) {
                _chappearfx_entrypoint_1(spawned, 0x22, 1, 1.0f);
            }
            break;
    }
    return 1;
}

void func_8080038C_chweldarhead(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void func_80108B04(Actor *, u32);
    void func_80102424(Actor *, s32);
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x1360:
            _susubgame_entrypoint_6(arg0, data + 0x18, 0x48, 0x30, 0);
            func_80108B04(arg0, 0);
            arg0->unk64_20 = 1;
            break;
        case 0x1384:
            _susubgame_entrypoint_4(arg0, data + 0x18);
        default:
            func_80102424(arg0, 1);
            break;
    }
}
