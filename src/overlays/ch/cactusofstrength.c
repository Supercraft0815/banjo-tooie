#include "common.h"

OSThread *chcactusofstrength_entrypoint_0(void)
{
    extern u8 D_80800D00_chcactusofstrength[];

    return (OSThread *) D_80800D00_chcactusofstrength;
}

OSThread *chcactusofstrength_entrypoint_1(void)
{
    extern u8 D_80800D48_chcactusofstrength[];

    return (OSThread *) D_80800D48_chcactusofstrength;
}

OSThread *chcactusofstrength_entrypoint_2(void)
{
    extern u8 D_80800D90_chcactusofstrength[];

    return (OSThread *) D_80800D90_chcactusofstrength;
}

void func_80800024_chcactusofstrength(Actor *arg0) {
    int _gcaudiolist_entrypoint_0();
    s32 func_800D9058(f32);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);

    switch (arg0->unk70_10) {
        case 2:
            if (func_80101DDC(arg0)) {
                if (arg0->unk6C_0) {
                    arg0->unk6C_0--;
                } else {
                    func_80102424(arg0, 3);
                    arg0->unk6C_0 = func_800D9058(0.5f);
                }
            }
            break;
        case 3:
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 1);
                _gcaudiolist_entrypoint_0(0);
                func_80103110(arg0, 0);
            }
            break;
    }
}

void func_80800108_chcactusofstrength(s32 arg0) 
{
}
/* extern */

void func_80800110_chcactusofstrength(Actor *arg0, s32 arg1) {
    int _gcaudiolist_entrypoint_0();
    s32 func_8008FCC8(Unk80132ED0 *);
    s32 func_80101180(s32, s32, s32);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    s32 var_a2;
    s32 temp_v0;

    if (arg0->unk70_10 == 1) {
        temp_v0 = func_8008FCC8(arg0->unk0);
        switch (temp_v0) {
        case 1:
            var_a2 = 1;
            break;
        case 0xB:
            var_a2 = 2;
            break;
        default:
            var_a2 = 4;
            break;
        }
        if (var_a2 != -1) {
            func_80102424(arg0, 2);
            _gcaudiolist_entrypoint_0(0);
            func_80103110(arg0, 1);
            arg0->unk6C_0 = 8;
            func_80101180(0x13B, 0xA, var_a2);
        }
    }
}

/* extern */

s32 func_808001C4_chcactusofstrength(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_80800110_chcactusofstrength(Actor *, s32);
    s32 result;
    if (arg1 == 0x40) {
        func_80800110_chcactusofstrength(arg0, *(s32 *)&arg2);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

void func_80800200_chcactusofstrength(Actor *arg0) {
    u8 func_800D9078(f32 *);
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80101FDC(Actor *, u32);
    void func_808006BC_chcactusofstrength(void *);
    void func_80800718_chcactusofstrength(void *);
    void func_80800780_chcactusofstrength(Actor *);
    void func_80800824_chcactusofstrength(Actor *, f32);
    void func_8080094C_chcactusofstrength(Actor *);
    f32 position[3];

    func_800EE7F8(position, arg0->position);
    func_800EF1B8(position, 135.0f, -55.0f);
    _sudeflect_entrypoint_0(position, 60.0f, 75.0f, 2);
    func_8080094C_chcactusofstrength(arg0);
    switch (arg0->unk70_10) {
        case 1:
            func_808006BC_chcactusofstrength(arg0);
            break;
        case 2:
            func_80800824_chcactusofstrength(arg0, 20.0f);
            if (arg0->unk58 > 0.0f) {
                if (func_800D9078(&arg0->unk58)) {
                    return;
                }
            } else {
                arg0->position[1] += *(f32 *)&arg0->actorData[3];
                if (arg0->position[1] >= *(f32 *)&arg0->actorData[5]) {
                    arg0->position[1] = *(f32 *)&arg0->actorData[5];
                    func_80800718_chcactusofstrength(arg0);
                    arg0->unk64_16 = 0;
                    func_80101FDC(arg0, 4);
                    return;
                }
                *(f32 *)&arg0->actorData[3] -= 5.0f;
                if (*(f32 *)&arg0->actorData[3] <= 0.0f) {
                    func_80101FDC(arg0, 1);
                    return;
                }
            }
            break;
        case 3:
            func_80800824_chcactusofstrength(arg0, -20.0f);
            arg0->position[1] += *(f32 *)&arg0->actorData[3];
            *(f32 *)&arg0->actorData[3] -= (*(f32 *)&arg0->actorData[3] > 0) ? 10.0f : 5.0f;
            if (*(f32 *)&arg0->actorData[3] < -50.0f) {
                *(f32 *)&arg0->actorData[3] = -50.0f;
            }
            if (arg0->position[1] <= *(f32 *)&arg0->actorData[4]) {
                arg0->position[1] = *(f32 *)&arg0->actorData[4];
                func_80800780_chcactusofstrength(arg0);
            }
            break;
    }
}

/* extern */

void func_808003EC_chcactusofstrength(void *arg0) {
    s32 func_800D0A9C(u32, u32);
    void func_800FFAB0(Actor *);
    (*(s32 *)((s8 *)(arg0) + (0x50))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 1200.0f;
    if (func_800D0A9C(0x1E, 1) != 0) {
        func_800FFAB0(arg0);
    }
}

s32 func_80800440_chcactusofstrength(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
    u32 func_800F54E4(void);
    s32 func_800F7F98(s32, u32);
    void func_800FFAB0(Actor *);
    void func_808004F8_chcactusofstrength(Actor *, s32);
    Actor *actor;

    switch (arg1) {
        case 0xA:
            func_808004F8_chcactusofstrength(arg0, arg2);
            return 1;
        case 0xB:
            if (arg2 == 2) {
                func_800FFAB0(arg0);
            }
            func_800F7F98(func_800F54E4(), 0);
            return 3;
        case 0x95:
            actor = _subaddiefind_entrypoint_0(arg0->position, 0x13A, -1, 0);
            if (actor != NULL) {
                arg0->unk3C = actor->unk0;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808004F8_chcactusofstrength(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _subaddieDll_entrypoint_4(Actor *, u32);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    s32 func_800CEAA8(s32);
    u32 func_800F54E4(void);
    s32 func_800F7F98(s32, u32);
    void func_800FC618(s32, s32);
    void func_80101FDC(Actor *, u32);
    f32 sqrtf(f32);
    f32 height = 0.0f;
    f32 delta;
    s32 oldFlags;
    s32 flags;

    oldFlags = *(s32 *)&arg0->unk50;
    delta = ((f32 *)arg0->actorData)[5] - ((f32 *)arg0->actorData)[4];
    if (oldFlags == 0 || func_800CEAA8(0) != 0) {
        flags = *(volatile s32 *)&arg0->unk50;
        if ((flags & arg1) != 0) {
            return;
        }
        switch (arg1) {
            case 1:
                *(s32 *)&arg0->unk50 = flags | 1;
                height = delta * 0.25f;
                break;
            case 2:
                *(s32 *)&arg0->unk50 = flags | 2;
                height = delta * 0.25f;
                break;
            case 4:
                *(s32 *)&arg0->unk50 = flags | 4;
                height = delta * 0.50001f;
                break;
        }
        if (oldFlags == 0) {
            func_800CE8D8(0, 20.0f, 20);
            func_800CE88C(0, 1);
            _subaddieDll_entrypoint_4(arg0, 1);
        }
        func_80101FDC(arg0, 2);
        ((f32 *)arg0->actorData)[3] = sqrtf(10.0f * height);
        if ((*(s32 *)&arg0->unk50 & 7) != 7) {
            func_800FC618(0xE, -1);
            arg0->unk58 = 0.2f;
            _capod_entrypoint_13(arg0->unk0, NULL, 0xAA, 0x800);
            func_800F7F98(func_800F54E4(), 1);
            return;
        }
        func_800FC618(0x10, -1);
        _capod_entrypoint_13(arg0->unk0, NULL, 2, 0x800);
        func_800F7F98(func_800F54E4(), 1);
    }
}

/* extern */

void func_808006BC_chcactusofstrength(void *arg0) {
    void func_800CE88C(s32, s32);
    s32 func_800CEAA8(s32);
    s32 func_800CEAD0(s32);
    void func_80101FDC(Actor *, u32);
    if (((*(s32 *)((s8 *)(arg0) + (0x50))) != 0) && (func_800CEAD0(0) != 0)) {
        if (func_800CEAA8(0) != 0) {
            func_800CE88C(0, 0);
        }
        func_80101FDC(arg0, 3);
    }
}

/* extern */

void func_80800718_chcactusofstrength(void *arg0) {
    s32 _mlwave_entrypoint_0(s32, s32, s32);
    s32 func_80100074(void *, s32, s32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void *sp1C;
    void *temp_v0;

    temp_v0 = func_80106790(((Actor *)arg0)->unk3C);
    sp1C = temp_v0;
    func_80101FDC(temp_v0, 2);
    func_80103110(sp1C, 1);
    (*(f32 *)((s8 *)(sp1C) + (0x58))) = 2.5f;
    _mlwave_entrypoint_0(func_80100074(sp1C, 1, 0x1C), 0x42C80000, 0x42A00000);
}

void func_80800780_chcactusofstrength(Actor *arg0) {
    void func_800B4470(u8 *, s32, void *, s32, f32, f32, s32, s32, s32);
    void func_800C4104(s32, f32, s32, s32, f32, f32);
    void func_80101FDC(Actor *, u32);
    void _subaddieDll_entrypoint_4(Actor *, u32);

    func_800B4470(arg0->position, 0, NULL, 1, 0.5f, 0.0f, 125, 250, 0);
    func_800C4104(0x417, 1.0f, 0x7D00, arg0->position, 1250.0f, 2500.0f);
    func_80101FDC(arg0, 1);
    *(s32 *)&arg0->unk50 = 0;
    _subaddieDll_entrypoint_4(arg0, 1);
}

void func_80800824_chcactusofstrength(Actor *arg0, f32 arg1) {
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    extern s32 D_80800DD8_chcactusofstrength;
    s32 temp_s4;
    f32 sp80[3];
    f32 sp74[3];
    f32 sp68[3];
    s32 var_s1;

    func_800EE7F8(sp74, arg0->position);
    func_800EE7F8(sp68, sp74);
    sp68[1] += arg1;
    temp_s4 = func_800B53A4(2);
    for (var_s1 = 0; var_s1 != 2; var_s1++) {
        func_800EEB9C(sp80, func_800DC178(0.0f, 270.0f), 20.0f);
        func_800EF04C(sp80, sp74);
        func_800BABB8(temp_s4, sp80, sp68, 1.0f, &D_80800DD8_chcactusofstrength);
    }
}

void func_8080094C_chcactusofstrength(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    f32 func_800F0E00(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13F0(f32, f32);
    f32 mlAbsF(f32);
    extern s32 D_80800E08_chcactusofstrength;
    f32 *sp28;
    f32 sp30;
    u32 temp_t6;

    temp_t6 = arg0->unk70_10;
    if ((temp_t6 == 2) || (temp_t6 == 3)) {
        if (arg0->unk5F == 0) {
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_80800E08_chcactusofstrength);
        }
        if (arg0->unk5F != 0) {
            sp28 = arg0->position;
            sp30 = mlAbsF(((f32 *)arg0->actorData)[3]);
            sp30 = func_800F13F0(sp30, 20.0f);
            sp30 = func_800F0E00(5.0f, sp30);
            sp30 = func_800F10B4(sp30, 5.0f, 20.0f, 1.1f, 1.4f);
            func_800C4350(arg0->unk5F, sp28, 0);
            func_800C31DC(arg0->unk5F, sp30);
            func_800C3BDC(arg0->unk5F);
        }
    } else {
        _subaddieaudioloop_entrypoint_2(arg0);
    }
}

void func_80800A44_chcactusofstrength(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _mlwave_entrypoint_1(u8 *);
    f32 _mlwave_entrypoint_5(u8 *, f32, f32);
    s32 _mlwave_entrypoint_8(u8 *, f32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    u8 func_800D9078(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80800E18_chcactusofstrength;
    f32 sp28;
    u8 *sp30;
    f32 sp24[3];
    u8 *temp_v0;

    if (arg0->unk70_10 == 2) {
        temp_v0 = func_80100094(arg0, 1);
        sp30 = temp_v0;
        _mlwave_entrypoint_1(temp_v0);
        arg0->rotation[2] = _mlwave_entrypoint_5(sp30, -20.0f, 20.0f);
        if ((_mlwave_entrypoint_8(sp30, 0.75f) != 0) || (_mlwave_entrypoint_8(sp30, 0.25f) != 0)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800E18_chcactusofstrength);
        }
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800EE7F8(sp24, (f32 *)arg0->actorData);
            func_800EF1B8(sp24, arg0->rotation[1], -60.0f);
            sp24[1] -= 40.0f;
            _chexploder_entrypoint_3(arg0, sp24, 3);
        }
    }
}

void func_80800B24_chcactusofstrength(Actor *arg0) {
    s32 func_800D0A9C(u32, u32);
    void func_800FFAB0(Actor *);
    void func_800EE7F8(f32 *, f32 *);
    if (func_800D0A9C(0x1E, 1) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    arg0->position[1] += 225.0f;
}

s32 func_80800B90_chcactusofstrength(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
    void func_800FFAB0(Actor *);
    void func_80800C18_chcactusofstrength(Actor *);
    Actor *temp_v0;

    switch (arg1) {
        case 0x90:
            func_80800C18_chcactusofstrength(arg0);
            func_800FFAB0(arg0);
            return 1;
        case 0x95:
            temp_v0 = _subaddiefind_entrypoint_0(arg0->position, 0x13B, -1, 0);
            if (temp_v0 != NULL) {
                arg0->unk3C = temp_v0->unk0;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800C18_chcactusofstrength(Actor *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    s32 func_800CEAA8(s32);
    void func_800CE88C(s32, s32);
    extern s32 D_80800E24_chcactusofstrength;
    extern s32 D_80800E64_chcactusofstrength;
    Actor *sp24;

    sp24 = func_80106790(arg0->unk3C);
    func_800BABB8(0, arg0->position, arg0->position, arg0->scale, &D_80800E24_chcactusofstrength);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800E64_chcactusofstrength);
    func_800D1000(0x1E, 1, NULL, 1, 0);
    *(s32 *)&sp24->unk50 = 0;
    if (func_800CEAA8(0) != 0) {
        func_800CE88C(0, 0);
    }
}
