#include "common.h"

OSThread *chklungophial_entrypoint_0(void)
{
    extern ActorData D_80800C30_chklungophial[];

    return (OSThread *) D_80800C30_chklungophial;
}

OSThread *chklungophial_entrypoint_1(void)
{
    extern ActorData D_80800C78_chklungophial[];

    return (OSThread *) D_80800C78_chklungophial;
}

void func_80800018_chklungophial(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    BtUIntPtr func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    void func_80108A30(s32, void *, f32, s32);
    void func_8010D12C(BtIntPtr, f32 *, f32, s32);
    extern u32 D_80800CC0_chklungophial[];
    struct Motion {
        f32 unused[3];
        f32 duration;
        f32 velocity[3];
    };
    struct Phial {
        f32 position[3];
        s32 effect;
        f32 scale;
    };
    s32 i;
    f32 target[3];
    struct Phial *data;
    f32 origin[3];


    data = func_80100094(arg0, 0);
    func_8010D12C(func_800F54E4(), target, arg0->unk58, 5);
    for (i = 0; i < 3; i++) {
        ((struct Motion *)arg0->actorData)->velocity[i] =
            (target[i] - arg0->position[i]) / ((struct Motion *)arg0->actorData)->duration;
    }
    ((struct Motion *)arg0->actorData)->velocity[1] +=
        400.0f * ((struct Motion *)arg0->actorData)->duration;
    arg0->unk50 = (func_800DC298(0.5f) ? -1.0f : 1.0f) * func_800DC178(250.0f, 350.0f);
    arg0->unk54 = (func_800DC298(0.5f) ? -1.0f : 1.0f) * func_800DC178(150.0f, 250.0f);
    func_800EE7F8(data->position, arg0->position);
    data->scale = 0.15f;
    data->effect = func_800C8A98();
    func_800C8E84(data->effect, D_80800CC0_chklungophial);
    func_800C8E54(data->effect, 250.0f, 600.0f);
    func_800C8CB8(data->effect, arg0->position);
    if (_subaddiefind_entrypoint_2(0x423, 0) == NULL) {
        func_800EFD24(origin);
        func_80108A30(0x423, origin, 0.0f, 50);
    }
}

void func_80800204_chklungophial(Actor *arg0 BT_PASS2(, s32 bt_a1)) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    f32 func_800136E4(f32);
    s32 func_800BFA1C();
    void func_800C8B84(volatile s32);
    void func_800C8CB8(s32, f32 *);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    int func_800DC298(f32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_8010B990(Actor *, s32);
    s32 func_808003C8_chklungophial(BtIntPtr, s32);
    s32 func_80800AEC_chklungophial(Actor *, f32 *, f32);
    extern u8 D_80800CCC_chklungophial[];
    struct Phial {
        f32 position[3];
        s32 effect;
        f32 scale;
    };
    struct Motion {
        f32 unused[3];
        f32 duration;
        f32 velocity[3];
    };
    struct Phial *data;
    f32 dt;
    Actor *klungo;
    f32 position[3];

    data = func_80100094(arg0, 0);
    if (func_800D9078(&data->scale)) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800CCC_chklungophial);
    }
    if (arg0->unk70_10 == 1) {
        dt = func_800D8FF8();
        klungo = _subaddiefind_entrypoint_2(0x423, 0);
        arg0->rotation[1] = func_800136E4(arg0->rotation[1] + dt * arg0->unk50);
        arg0->rotation[0] = func_800136E4(arg0->rotation[0] + dt * arg0->unk54);
        ((struct Motion *)arg0->actorData)->velocity[1] -= 800.0f * dt;
        if (func_8010B990(arg0, 0x400007) & 0x20) {
            func_808003C8_chklungophial((BtIntPtr)arg0, 1);
        }
        if (func_800DC298(0.6f) && klungo != NULL) {
            _subaddieskeleton_entrypoint_3(arg0->unk0, 4, position);
            func_80800AEC_chklungophial(klungo, position, 0.0f);
        }
    }
    if (func_800BFA1C(arg0->position) == 0) {
        func_800FFAB0(arg0);
        if (data->effect != 0) {
            func_800C8B84(data->effect);
            data->effect = 0;
        }
    }
    if (data->effect != 0) {
        func_800C8CB8(data->effect, arg0->position);
    }
}

/* extern */

s32 func_8080038C_chklungophial(s32 arg0, s32 arg1, volatile s32 arg2) {
    s32 func_808003C8_chklungophial(BtIntPtr, s32);
    int ret;
    if (arg1 == 0x40) {
        func_808003C8_chklungophial(arg0, 0);
        ret = 1;
    } else {
        return 0;
    }
    return ret;
}

s32 func_808003C8_chklungophial(BtIntPtr arg0, s32 arg1) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA77C(BtIntPtr, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32 *, f32 *, f32, s32 *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80103DFC(Actor *, f32 *);
    void func_8010A570(Actor *);
    s32 func_808006B4_chklungophial(Actor *, f32 *, f32 *);
    s32 func_80800AEC_chklungophial(Actor *, f32 *, f32);
    extern s32 D_80800CDC_chklungophial[], D_80800D18_chklungophial[];
    extern s32 D_80800D28_chklungophial[], D_80800D50_chklungophial[];
    extern s32 D_80800D6C_chklungophial[], D_80800D90_chklungophial[];
    extern s32 D_80800DCC_chklungophial[];
    struct Phial {
        f32 position[3];
        s32 effect;
        f32 scale;
    };
    f32 position[3];
    f32 velocity[3];
    s32 pad;
    struct Phial *data;
    f32 normal[3];
    BtIntPtr emitter;
    Actor *other;
    f32 delay;
    s32 i;
    f32 point[3];
    f32 angle;
    Actor *actor = (Actor *)arg0;

    data = func_80100094(actor, 0);
    func_80103DFC(actor, position);
    func_800EE7F8(velocity, position);
    func_800EF1B8(velocity, func_800F1DF4(actor->position, data->position), actor->scale * 60.0f);
    velocity[1] -= actor->scale * 40.0f;
    func_800BBCB8(position, velocity, actor->scale, 10, D_80800CDC_chklungophial);
    _subaddieaudioquick_entrypoint_2(actor, position, D_80800D18_chklungophial);
    _subaddieaudioquick_entrypoint_2(actor, position, D_80800D50_chklungophial);
    if (arg1 == 1) {
        other = _subaddiefind_entrypoint_2(0x423, 0);
        if (func_808006B4_chklungophial(actor, position, normal)) {
            emitter = func_800BABB8(0, position, NULL, actor->scale * 0.25f, D_80800D6C_chklungophial);
            func_800BA77C(emitter, (s16)(s32)normal[0], (s16)(s32)normal[1], (s16)(s32)normal[2]);
            func_800BA22C(emitter, 1);
        }
        func_800BABB8(0, position, NULL, actor->scale, D_80800D90_chklungophial);
        _subaddieaudioquick_entrypoint_2(actor, position, D_80800DCC_chklungophial);
        if (other != NULL) {
            delay = 0.35f;
            for (i = 0; i != 6; i++) {
                angle = func_800DC178(0.0f, 359.0f);
                func_800EEB9C(point, angle, func_800DC178(5.0f, 80.0f));
                func_800EF04C(point, position);
                func_80800AEC_chklungophial(other, point, delay);
                delay += func_800DC178(0.1f, 0.2f);
            }
        }
    } else {
        func_800BBCB8(position, position, 1.0f, 2, D_80800D28_chklungophial);
    }
    if (data->effect != 0) {
        data->effect = _chlightfader_entrypoint_1(data->effect, 1.5f, 2);
    }
    func_800FFAB0(actor);
    func_8010A570(actor); BT_NATIVE_ONLY(return 0;)
}

s32 func_808006B4_chklungophial(Actor *arg0, f32 *arg1, f32 *arg2) {
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF174(f32 *, f32 *, f32);
    void func_800EFD24(f32 *);
    s32 func_800F1988(f32 *, f32 *, f32 *);
    f32 mlAbsF(f32);
    f32 start[3];
    f32 end[3];
    f32 normal[3];
    f32 scale;

    func_800EE7F8(start, arg0->position);
    scale = func_800D8FF8() * -6.0f;
    func_800EF174(start, (f32 *)&arg0->actorData[4], scale);
    func_800EE7F8(end, arg0->position);
    func_800EF174(end, (f32 *)&arg0->actorData[4], func_800D8FF8() * 3.0f);
    if (func_800C6A7C(start, end, normal, arg0->unk14)) {
        if (func_800F1988(normal, arg2, arg2 + 1)) {
            arg2[2] = 0.0f;
            func_800EE7F8(arg1, end);
            return 1;
        }
        if (mlAbsF(normal[0]) < 0.0001f &&
            mlAbsF(normal[2]) < 0.0001f &&
            mlAbsF(normal[1]) > 0.9999f) {
            func_800EFD24(arg2);
            func_800EE7F8(arg1, end);
            return 1;
        }
    }
    return 0;
}

void func_80800820_chklungophial(s32 arg0) 
{
}
void func_80800828_chklungophial(Actor *arg0) {
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void rare_memcpy(void *, void *, int);
    struct PhialEntry {
        f32 position[3];
        f32 scale;
        f32 elapsed;
        f32 duration;
        f32 speed;
        f32 height;
        f32 angle;
    };
    struct PhialData {
        s32 count;
        struct PhialEntry entries[50];
    } *data;
    f32 delta;
    struct PhialEntry *entry;
    s32 i;
    s32 count;

    delta = func_800D8FF8();
    data = func_80100094(arg0, 0);
    entry = data->entries;
    i = 0;
    while (i < data->count) {
        if (func_800D90A4(&entry->duration)) {
            if (func_800D90A4(&entry->scale)) {
                entry->elapsed += delta * 15.0f;
            }
            if (entry->elapsed > 11.0f) {
                rare_memcpy(entry, &data->entries[data->count] - 1, sizeof(*entry));
                data->count--;
                continue;
            } else {
                entry->position[1] += delta * entry->height;
            }
        }
        entry++;
        i++;
    }
    if (arg0->unk70_10 == 2) {
        count = data->count;
        if (count == 0) {
            func_800FFAB0(arg0);
        }
    }
}

s32 func_80800980_chklungophial(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80101FDC(Actor*, u32);
    switch (arg1) {
        case 0x4F:
            func_80101FDC(arg0, 2U);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_808009BC_chklungophial(Actor *arg0, s32 arg1) {
    BtIntPtr func_800D674C(s32);
    void func_800E24D8(s32);
    void func_800E2530(f32);
    void func_800E2588(u32);
    void func_800E2594(BtUIntPtr arg0, void *arg1);
    s32 func_800E2720(BtIntPtr, s32, s32, f32 *, f32 *, s32);
    void func_800E2A14(BtIntPtr);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    struct PhialEntry {
        f32 position[3];
        f32 scale;
        f32 elapsed;
        f32 duration;
        f32 speed;
        f32 height;
        f32 angle;
    };
    struct PhialData {
        s32 count;
        struct PhialEntry entries[50];
    } *temp_v0;
    f32 temp_f0;
    BtIntPtr temp_s1;
    s32 var_s1;
    f32 sp4C[3];
    struct PhialEntry *var_s0;

    temp_v0 = func_80100094(arg0, 0);
    var_s0 = temp_v0->entries;
    arg0->unk7C_12 = 1;
    if (temp_v0->count != 0) {
        temp_s1 = func_800D674C(0x9CF);
        func_800E2588(1);
        func_800E2594(arg1, temp_s1);
        func_800E24D8(1);
        var_s1 = 0;
        if (temp_v0->count > 0) {
            do {
                if (var_s0->duration == 0.0f) {
                    temp_f0 = var_s0->speed;
                    func_800EFA4C(sp4C, temp_f0, temp_f0, temp_f0);
                    func_800E2530(var_s0->angle);
                    func_800E2720(arg1, (s32) var_s0->elapsed, 0, var_s0->position, sp4C, 0xFF);
                }
                var_s1 += 1;
                var_s0++;
            } while (var_s1 < temp_v0->count);
        }
        func_800E2A14(arg1);
    }
}

/* extern */

s32 func_80800AEC_chklungophial(Actor *arg0, f32 *arg1, f32 arg2) {
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    struct PhialEntry {
        f32 position[3];
        f32 scale;
        f32 elapsed;
        f32 duration;
        f32 speed;
        f32 height;
        f32 angle;
    };
    struct PhialData {
        s32 count;
        struct PhialEntry entries[50];
    } *temp_v0;
    struct PhialEntry *temp_s0;

    temp_v0 = func_80100094(arg0, 0);
    if (temp_v0->count == 0x32) {
        return 0;
    }
    temp_s0 = &temp_v0->entries[temp_v0->count];
    bzero(temp_s0, 0x24);
    func_800EE7F8(temp_s0->position, arg1);
    temp_s0->scale = func_800DC178(0.55f, 1.25f);
    temp_s0->elapsed = 0.0f;
    temp_s0->duration = arg2;
    temp_s0->speed = func_800DC178(0.85f, 1.15f);
    temp_s0->height = func_800DC178(40.0f, 80.0f);
    temp_s0->angle = func_800DC178(0.0f, 359.0f);
    temp_v0->count += 1;
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/klungo/phial.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800C30_chklungophial [1] BT_DATA(4, overlays_ch_klungo_phial, 0x0) = { { 818, 1058, 1800, 1, 0, (void (*)(struct Actor *))func_80800204_chklungophial, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 1065353216, 0, 0, 0, 68, 0, (BtIntPtr)func_80108ED0, 20, 0, (void (*)(struct Actor *))func_80800018_chklungophial, (void (*)(void *, long, void *, long, void *))func_80107C2C, 0, 0, (void (*)(struct Actor *, long, long))func_8080038C_chklungophial, 0 } };
ActorData D_80800C78_chklungophial [1] BT_DATA(4, overlays_ch_klungo_phial, 0x48) = { { 819, 1059, -1, 1, 0, (void (*)(struct Actor *))func_80800828_chklungophial, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808009BC_chklungophial, 0, 0, 0, 0, 2, 1028, 0, 0, 1804, 0, (void (*)(struct Actor *))func_80800820_chklungophial, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8194, (void (*)(struct Actor *, long, long))func_80800980_chklungophial, 0 } };
u32 D_80800CC0_chklungophial [3] BT_DATA(4, overlays_ch_klungo_phial, 0x90) = { 0xFF, 0xFF, 0x80 };
u8 D_80800CCC_chklungophial [16] BT_DATA(4, overlays_ch_klungo_phial, 0x9C) = { 0, 0x13, 6, 1, 0, 0xD, 0, 0xF3, 1, 0xC, 0, 2, 0, 0, 0, 0 };
s32 D_80800CDC_chklungophial [15] BT_DATA(4, overlays_ch_klungo_phial, 0xAC) = { 1902512, 1443206, 2818355, 26804263, 13107400, 26214800, 2949620, 39321627, -65471264, 2228480, 20119680, 10027029, 204, 917534, 3276800 };
s32 D_80800D18_chklungophial [4] BT_DATA(4, overlays_ch_klungo_phial, 0xE8) = { 1246349, 1572877, 22610291, 0 };
s32 D_80800D28_chklungophial [10] BT_DATA(4, overlays_ch_klungo_phial, 0xF8) = { 1903069, 2228608, 33554944, 41943061, 153, 1638400, 458795, 20119910, 2162687, 1088421888 };
s32 D_80800D50_chklungophial [7] BT_DATA(4, overlays_ch_klungo_phial, 0x120) = { 1246428, 852224, 18415637, 2490496, 6684673, 52432300, 0 };
s32 D_80800D6C_chklungophial [9] BT_DATA(4, overlays_ch_klungo_phial, 0x13C) = { 17825821, 136380459, 33555072, 2228608, 33555584, 83886101, 128, 3342339, 0 };
s32 D_80800D90_chklungophial [15] BT_DATA(4, overlays_ch_klungo_phial, 0x160) = { 68157469, 165478427, 9830575, 720916, 2621440, 32, -16288, 2228326, 8388761, 11730965, 153, 2752512, 655616, 25165839, 0 };
s32 D_80800DCC_chklungophial [5] BT_DATA(4, overlays_ch_klungo_phial, 0x19C) = { 1246239, 1572877, 10879168, 0, 0 };
