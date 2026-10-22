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

void func_80800018_chklungodoors(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    s32 _chdoormake_entrypoint_4(Actor *, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 func_800EA05C();
    void func_80102FDC(void *, f32);
    void func_80103110(void *, s32);
    u32 func_8010A5B0(Actor *, s32);
    void func_8010A800(Actor *, s32);
    typedef struct {
        s16 map;
        s16 angle;
        f32 scale;
        s32 unk8;
        u16 flag;
        u8 animated;
        u8 sound;
    } DoorConfig;
    extern DoorConfig D_80800490_chklungodoors[];
    s32 result;
    s32 i;
    DoorConfig *entry;
    DoorConfig *config;

    config = NULL;
    for (i = 0; i != 3; i++) {
        entry = &D_80800490_chklungodoors[i];
        if (func_800EA05C() == entry->map) {
            config = entry;
            arg0->actorData[4] = i;
            break;
        }
    }
    func_80102FDC(arg0, config->scale);
    func_8010A800(arg0, 0);
    if (arg0->unk6C_9 == 0x420) {
        if (config->animated) {
            func_80103110(arg0, 1);
            result = _chdoormake_entrypoint_4(arg0, 0xA82A, config->flag);
        } else {
            result = _chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, config->angle, 0x122, config->flag);
        }
        if (result != 0) {
            _chdoormake_entrypoint_5(arg0, 0.7f);
            _chdoormake_entrypoint_6(arg0, 2.0f);
            _chdoormake_entrypoint_8(arg0, config->sound);
        }
    } else {
        if (config->animated) {
            func_80103110(arg0, 1);
            result = _chdoormake_entrypoint_4(arg0, 0xA82A, -1);
        } else {
            result = _chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, config->angle, 0x122, -1);
        }
        if (result != 0) {
            _chdoormake_entrypoint_5(arg0, 0.7f);
            _chdoormake_entrypoint_6(arg0, 0.25f);
            _chdoormake_entrypoint_8(arg0, config->sound);
        }
    }
    if (config->animated) {
        *(u16 *)&arg0->unk0->unk24 = (*(u16 *)&arg0->unk0->unk24 & 0x3F) | 0xCC40;
        func_80103110(arg0, 1);
        func_8010A5B0(arg0, result == 1);
    }
}

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
