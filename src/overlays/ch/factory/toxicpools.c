#include "common.h"

OSThread *chfactorytoxicpools_entrypoint_0(void)
{
    extern u8 D_80800940_chfactorytoxicpools[];

    return (OSThread *) D_80800940_chfactorytoxicpools;
}

OSThread *chfactorytoxicpools_entrypoint_1(void)
{
    extern u8 D_80800988_chfactorytoxicpools[];

    return (OSThread *) D_80800988_chfactorytoxicpools;
}

OSThread *chfactorytoxicpools_entrypoint_2(void)
{
    extern u8 D_808009D0_chfactorytoxicpools[];

    return (OSThread *) D_808009D0_chfactorytoxicpools;
}

void func_80800024_chfactorytoxicpools(Actor *arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_8010A570(Actor *);
    struct ToxicPoolData {
        s16 unk0;
        s16 state;
        f32 timer;
    } *sp1C;
    s32 sp18;

    sp1C = func_80100094(arg0, 1);
    sp18 = func_800DA298(0x18E);
    if (_chswitch_entrypoint_7(arg0, 0x18E) != 0) {
        func_80103110(arg0, 0);
    }
    sp1C->timer = 8.0f;
    if (sp18 != 0) {
        sp1C->unk0 = 0x384;
    } else {
        sp1C->unk0 = 0;
    }
    if (sp18 != 0) {
        sp1C->state = 2;
    } else {
        sp1C->state = 0;
    }
    if (sp18 != 0) {
        func_8010A570(arg0);
    }
}

void func_808000D0_chfactorytoxicpools(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void _chswitch_entrypoint_6(Actor *);
    s32 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_80103110(Actor *, u32);
    void func_80800270_chfactorytoxicpools(Actor *);
    struct ToxicPoolData {
        s16 unk0;
        s16 state;
        f32 timer;
    } *sp24;
    s32 sp20;

    sp24 = func_80100094(arg0, 1);
    switch (sp24->state) {
        case 0:
            _chswitch_entrypoint_6(arg0);
            break;
        case 1:
            sp20 = func_800D9078(&sp24->timer);
            sp24->unk0 = (s32)func_800F12D4(sp24->timer, 0.0f, 8.0f, 900.0f, 0.0f);
            if (sp20 != 0) {
                sp24->state = 2;
                func_80103110(arg0, 0);
            }
            break;
    }
    func_80800270_chfactorytoxicpools(arg0);
}

s32 func_80800190_chfactorytoxicpools(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_8010A570(Actor *);
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void func_800C4AF0(f32 *, void *);
    s32 func_800BEA88(s32);
    s32 _idworldmake_entrypoint_1(s32, s32, s32, s32);
    void func_80800270_chfactorytoxicpools(Actor *);
    s32 _chswitch_entrypoint_10(Actor *, s32, s32);
    extern f32 D_80800A18_chfactorytoxicpools[3];
    struct ToxicPoolData {
        s16 unk0;
        s16 state;
        f32 timer;
    } *sp24;

    switch (arg1) {
        case 7:
            sp24 = func_80100094(arg0, 1);
            func_80103110(arg0, 1);
            func_8010A570(arg0);
            sp24->state = 1;
            _capod_entrypoint_13(arg0->unk0, NULL, 0, 0x10);
            func_800C4AF0(arg0->position, D_80800A18_chfactorytoxicpools);
            break;
        case 0x95:
            _idworldmake_entrypoint_1(func_800BEA88(1), 0x659, 1, 1);
            func_80800270_chfactorytoxicpools(arg0);
        default:
            return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return 1;
}

void func_80800270_chfactorytoxicpools(Actor *arg0) {
    s32 _idwibble_entrypoint_5(s32, s16);
    s32 _idworld_entrypoint_4(s32, s32);
    s32 func_800BEA88(s32);
    void* func_80100094(Actor*, u32);
    s16 *sp1C;

    sp1C = func_80100094(arg0, 1U);
    _idwibble_entrypoint_5(_idworld_entrypoint_4(func_800BEA88(1), 1), *sp1C);
}

void func_808002B8_chfactorytoxicpools(Actor *arg0) {
    s32 _chswitch_entrypoint_14(Actor *, s32);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    s32 func_80105010(Actor *);
    void func_8010A570(Actor *);
    struct ToxicPoolData {
        s16 unk0;
        s16 state;
        f32 timer;
    } *sp1C;
    s32 sp18;

    sp1C = func_80100094(arg0, 1);
    sp18 = func_800DA298(0x166);
    _chswitch_entrypoint_14(arg0, 0x166);
    sp1C->timer = 1.0f;
    if (sp18 != 0) {
        sp1C->state = 2;
    } else {
        sp1C->state = 0;
    }
    if (sp18 != 0) {
        func_8010A570(arg0);
    }
    func_80105010(arg0);
}

void func_80800338_chfactorytoxicpools(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void _chswitch_entrypoint_13(Actor *);
    s32 func_800D9078(f32 *);
    void func_80103110(Actor *, u32);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    struct ToxicPoolData {
        s16 unk0;
        s16 state;
        f32 timer;
    } *data, *sp1C;

    data = func_80100094(arg0, 1);
    switch (data->state) {
        case 0:
            _chswitch_entrypoint_13(arg0);
            break;
        case 1:
            sp1C = data;
            if (func_800D9078(&data->timer)) {
                func_80103110(arg0, 0);
                sp1C->state = 2;
                func_800F82D4(func_800F54E4(), 0);
                _capod_entrypoint_13(arg0->unk0, NULL, 0x12, 0x2030);
            }
            break;
    }
}

s32 func_808003DC_chfactorytoxicpools(Actor *arg0, s32 arg1, void * volatile arg2) {
    void _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_6(u32, u32);
    u32 func_800F54E4(void);
    void func_800F8300();
    void *func_80100094(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_8010A570(Actor *);
    void func_808004A4_chfactorytoxicpools(s32 *);
    struct ToxicPoolData {
        s16 unk0;
        s16 state;
        f32 timer;
    } *data;
    void *actor = arg0;

    switch (arg1) {
        case 0x95:
            func_808004A4_chfactorytoxicpools(actor);
            break;
        case 7:
            data = func_80100094(arg0, 1);
            func_80103110(arg0, 1);
            func_8010A570(arg0);
            data->state = 1;
            func_800F8300(func_800F54E4(), 2, arg0->position);
            break;
        case 0xB:
            _capod_entrypoint_14();
            _glcutDll_entrypoint_6(0x1A7, 0x2A);
            return 4;
        default:
            return 0;
    }
    return 1;
}

void func_808004A4_chfactorytoxicpools(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 _idworldmake_entrypoint_1(s32, s32, s32, s32);
    s32 func_800BEA88(s32);
    extern s32 _chfactorytoxicpools_entrypoint_3;
    s32 temp_v0;
    s32 sp1C;

    temp_v0 = func_800BEA88(1);
    if (temp_v0 != 0) {
        sp1C = temp_v0;
        _idworldmake_entrypoint_1(temp_v0, 0x7D, 2, 1);
        _glid_entrypoint_0(sp1C, 2, &_chfactorytoxicpools_entrypoint_3, *arg0);
    }
}

/* extern */

void chfactorytoxicpools_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3) {
    s32 func_800DA298(s32);
    s32 var_v0;
    Vtx *end;

    if (func_800DA298(0x166) != 0) {
        var_v0 = -0x12C;
    } else {
        var_v0 = 0;
    }
    end = arg1 + arg3;
    if (arg1 < end) {
        do {
            arg1++;
            arg2++;
            arg2[-1].v.ob[1] = arg1[-1].v.ob[1] + var_v0;
        } while (arg1 < end);
    }
}

void func_8080057C_chfactorytoxicpools(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 func_800CBC3C();
    void func_800EE88C(f32 *, s16 *);
    void func_800EFD24(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    struct PoolData {
        s16 unk0;
        s16 count;
        struct {
            s16 room;
            s16 pad;
            f32 position[3];
            f32 velocity[3];
        } entries[8];
    } *data;
    Prop *props[8];
    f32 position[4];
    s32 i;

    data = func_80100094(arg0, 0);
    data->count = _gccubesearch_entrypoint_9(0x154, props, 8);
    for (i = 0; i < data->count; i++) {
        func_800EE88C(position, props[i]->position);
        data->entries[i].room = func_800CBC3C(position);
        func_800EFD24(data->entries[i].velocity);
        func_800EE7F8(data->entries[i].position, position);
    }
    data->unk0 = -1;
    arg0->unk58 = 1.2f;
}

void func_80800670_chfactorytoxicpools(Actor *arg0) {
    s32 func_800CC338(f32 *, s32, s32);
    s32 func_800D9078(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    s32 func_800F5578(s32);
    f32 func_800F5628(s32);
    void func_800F5A00(s32, f32 *);
    s32 func_800F5C94(s32);
    s32 func_800F5D18(s32);
    s32 func_800F6A38(s32);
    void func_800F7D90(s32, s32, void *, s32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80800898_chfactorytoxicpools(Actor *);
    struct PoolData {
        s16 unk0;
        s16 count;
        struct {
            s16 room;
            s16 pad;
            f32 position[3];
            f32 velocity[3];
        } entries[8];
    } *data;
    s32 player;
    s32 state;
    s32 active;
    f32 position[3];
    s32 i;
    f32 height;
    s32 valid;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 1:
            player = func_800F54E4();
            if (func_800F6A38(player)) {
                state = func_800F5C94(player);
                active = func_800F5D18(player);
                if (state != 12 && state != 14 && active && func_800D9078(&arg0->unk58)) {
                    func_800F7D90(player, 0x52, data->entries[data->unk0].velocity, 1);
                    func_80101FDC(arg0, 2);
                    func_80800898_chfactorytoxicpools(arg0);
                    arg0->unk58 = 2.5f;
                }
            } else {
                func_800F5A00(player, position);
                for (i = 0; i < data->count; i++) {
                    height = func_800F5628(player);
                    valid = height != -18000.0f;
                    if (valid) {
                        position[1] = height;
                    } else {
                        position[1] = data->entries[i].velocity[1];
                    }
                    if (func_800CC338(position, data->entries[i].room, 0) != -1) {
                        if (!valid) {
                            func_800EE7F8(data->entries[i].velocity, data->entries[i].position);
                        } else {
                            func_800EE7F8(data->entries[i].velocity, position);
                        }
                        data->unk0 = i;
                    }
                }
                arg0->unk58 = 1.2f;
            }
            break;
        case 2:
            if (func_800D9078(&arg0->unk58) && func_800F5578(func_800F54E4()) > 0) {
                func_80101FDC(arg0, 1);
                arg0->unk58 = 1.2f;
            }
            break;
    }
}

void func_80800898_chfactorytoxicpools(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    extern s32 D_80800A38_chfactorytoxicpools;
    extern s32 D_80800A74_chfactorytoxicpools;
    extern s32 D_80800AB0_chfactorytoxicpools;
    extern f32 D_80800AC8_chfactorytoxicpools[3];
    f32 sp34[3];
    f32 sp28[3];

    func_800F5A00(func_800F54E4(), sp28);
    func_800BBCB8(sp28, NULL, 1.0f, 8, &D_80800A38_chfactorytoxicpools);
    func_800EE780(sp34, sp28, D_80800AC8_chfactorytoxicpools);
    func_800BBCB8(sp28, sp34, 1.0f, 4, &D_80800A74_chfactorytoxicpools);
    _subaddieaudioquick_entrypoint_2(arg0, sp28, &D_80800AB0_chfactorytoxicpools);
}
