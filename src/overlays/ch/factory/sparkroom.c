#include "common.h"
#include "core2/switch_animations.h"
void func_80800000_chfactorysparkroom(Actor *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 _glsplinefind_entrypoint_3(f32 *);
    void _gspropctrl_entrypoint_11(Prop *, f32 *);
    s32 _gspropctrl_entrypoint_8(Prop *);
    u8 _subaddieaudioloop_entrypoint_7(u8 arg0, f32 *arg1, u32 arg2, u32 *arg3, s32 arg4);
    void *func_80100094(Actor *, u32);
    extern s32 D_80801070_chfactorysparkroom[3];
    Prop *sp68[16];
    Prop **var_s0;
    u32 var_s2;
    f32 sp54[3];
    struct SparkRoomActorData {
        u8 pad0[0x38];
        u8 audio;
        u8 pad39[0x1F];
        BT_BITFIELD_ORDER(u32 pad58 : 31, u32 active : 1);
        BT_BITFIELD_ORDER(u32 active : 1, u32 pad58 : 31);
    };
    struct SparkRoomEntry {
        f32 unk0[4];
        f32 unk10;
        f32 unk14;
        s32 unk18;
        s32 unk1C;
    } *temp_s3, *var_s1;

    temp_s3 = func_80100094(arg0, 0);
    arg0->unk6C_0 = _gccubesearch_entrypoint_9(0x299, sp68, 0x10);
    var_s2 = 0;
    var_s0 = sp68;
    var_s1 = temp_s3;
    if (arg0->unk6C_0) {
        do {
            var_s1->unk10 = (f32)_gspropctrl_entrypoint_8(*var_s0) * 10.0f;
            var_s1->unk14 = (f32)_gspropctrl_entrypoint_8(*var_s0) * 20.0f;
            _gspropctrl_entrypoint_11(*var_s0, sp54);
            var_s1->unk18 = _glsplinefind_entrypoint_3(sp54);
            var_s2 += 1;
            var_s0++;
            var_s1++;
        } while (var_s2 < arg0->unk6C_0);
    }
    ((struct SparkRoomActorData *)arg0->actorData)->audio = _subaddieaudioloop_entrypoint_7(((struct SparkRoomActorData *)arg0->actorData)->audio, arg0->position, 0, D_80801070_chfactorysparkroom, ((struct SparkRoomActorData *)arg0->actorData)->active);
}

struct Unk800C7A68;     
struct SparkRoomUpdateColor { s32 values[3]; };
void func_8080013C_chfactorysparkroom(Actor *arg0) {
    void _chelectricfence_entrypoint_1(Actor *, f32 *);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    u8 _subaddieaudioloop_entrypoint_7(u8 arg0, f32 *arg1, u32 arg2, u32 *arg3, s32 arg4);
    void func_80018820(s32, f32, f32);
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E84(s32 id,u32 *color);
    void *func_800D7520(s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC0C0(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EFC7C(void *, void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    int func_800F3214(void *, void *, void *, f32);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F55FC(BtIntPtr);
    s32 func_800F581C(BtIntPtr);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6C5C(BtIntPtr);
    void func_800F796C(BtIntPtr arg0,s32 arg1);
    void *func_80100094(Actor *, u32);
    void func_808005E0_chfactorysparkroom(Actor *, f32 *);
    void func_808006D0_chfactorysparkroom(Actor *, f32);
    void func_808007E0_chfactorysparkroom(Actor *);
    void func_80800B60_chfactorysparkroom(Actor *, s32);
    void func_80800BE0_chfactorysparkroom(Actor *, s32);
    struct SparkRoomUpdateData {
        s32 pad0[7];
        s32 count;
        u8 pad20[0x18];
        u8 audio;
    };
    struct SparkRoomEntry {
        f32 unk0[4];
        f32 unk10;
        f32 unk14;
        s32 unk18;
        s32 unk1C;
    };

    extern s32 D_80801060_chfactorysparkroom[4];
    extern s32 D_80801070_chfactorysparkroom[3];
    extern struct SparkRoomUpdateColor D_8080107C_chfactorysparkroom;
    extern struct SparkRoomUpdateColor D_80801088_chfactorysparkroom;
    f32 spCC[3];
    f32 minDistance = 10000000.0f;
    s32 i;
    struct SparkRoomEntry *entry;
    f32 spB4[3];
    f32 spA8[3];
    f32 progress;
    f32 distance;
    struct SparkRoomUpdateColor sp94;
    struct SparkRoomUpdateColor sp88;
    s32 sp7C[3];
    f32 sp70[3];
    struct SparkRoomEntry *entries;

    entries = func_80100094(arg0, 0);
    i = 0;
    entry = entries;
    if (arg0->unk6C_0) {
        do {
            if (entry->unk0[1] == 0.0f) {
                if (func_800D90A4(&entry->unk0[0]) &&
                    ((struct SparkRoomUpdateData *)arg0->actorData)->count < 4) {
                    func_80800BE0_chfactorysparkroom(arg0, i);
                }
            } else if (func_800D90A4(&entry->unk0[1])) {
                func_80800B60_chfactorysparkroom(arg0, i);
            } else {
                progress = func_800F10B4(entry->unk0[1], entry->unk0[0], 0.0f, entry->unk0[2], entry->unk0[3]);
                sp94 = D_8080107C_chfactorysparkroom;
                sp88 = D_80801088_chfactorysparkroom;
                func_800F5A00(func_800F54E4(), spA8);
                func_800C7A68(func_800D7520(entry->unk18), progress, spB4);
                distance = func_800EFC7C(spA8, spB4);
                if (distance < minDistance) {
                    minDistance = distance;
                    func_800EE7F8(spCC, spB4);
                }
                spB4[1] += 50.0f;
                func_800F3214(sp7C, &sp94, &sp88, func_800DC0C0() * 0.2f + 0.8f);
                func_800C8E84(entry->unk1C, sp7C);
                func_800C8CB8(entry->unk1C, spB4);
            }
            i++;
            entry++;
        } while (i < arg0->unk6C_0);
    }
    if (minDistance < 10000000.0f) {
        ((struct SparkRoomUpdateData *)arg0->actorData)->audio = _subaddieaudioloop_entrypoint_7(((struct SparkRoomUpdateData *)arg0->actorData)->audio, spCC, 1, D_80801060_chfactorysparkroom, arg0->unk70_0);
    } else {
        ((struct SparkRoomUpdateData *)arg0->actorData)->audio = _subaddieaudioloop_entrypoint_7(((struct SparkRoomUpdateData *)arg0->actorData)->audio, spCC, 0, D_80801060_chfactorysparkroom, arg0->unk70_0);
    }
    if (arg0->unk54 == 0.0f) {
        if (((func_800F581C(func_800F54E4()) & 0x08000000) ||
             (func_800F55FC(func_800F54E4()) & 0x08000000)) &&
            func_800F6C5C(func_800F54E4())) {
            func_800F5A00(func_800F54E4(), arg0->position);
            func_800F796C(func_800F54E4(), 3);
            _chelectricfence_entrypoint_1(arg0, arg0->position);
            func_80018820(0, 5.0f, (f32)arg0->unk74_7 / 10.0f);
            arg0->unk54 = (f32)arg0->unk74_7 / 10.0f;
            func_800EE7F8(sp70, arg0->position);
            sp70[1] += 500.0f;
            func_808005E0_chfactorysparkroom(arg0, sp70);
        }
    } else {
        if (func_800D90A4(&arg0->unk54)) {
            func_808007E0_chfactorysparkroom(arg0);
            _subaddieaudioloop_entrypoint_2(arg0);
            return;
        }
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80801070_chfactorysparkroom);
        distance = arg0->unk54;
        if (distance < ((f32)arg0->unk74_7 / 10.0f) * 0.3f) {
            func_808006D0_chfactorysparkroom(arg0, func_800F10B4(distance, 0.0f, ((f32)arg0->unk74_7 / 10.0f) * 0.3f, 0.0f, 1.0f));
        }
    }
}
struct SparkRoomInitColor { s32 values[3]; };
void func_808005E0_chfactorysparkroom(Actor *arg0, f32 *arg1) {
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32[3]);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32 id,u32 *color);
    void func_800C8F64(s32, s32);
    void func_800C8FE0(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);

    struct SparkRoomLight { u8 pad[0x200]; s32 light; };
    extern struct SparkRoomInitColor D_80801094_chfactorysparkroom;
    extern f32 D_808010A0_chfactorysparkroom[];
    extern f32 D_808010A8_chfactorysparkroom[4][3];
    extern f32 D_808010D8_chfactorysparkroom[3];
    struct { struct SparkRoomInitColor color; s32 alpha; } sp40;
    f32 (*var_s1)[3];
    s32 temp_v0;
    struct SparkRoomLight *temp_s2;
    struct SparkRoomLight *var_s0;

    sp40.color = D_80801094_chfactorysparkroom;
    temp_s2 = func_80100094(arg0, 0);
    func_800EE7F8(D_808010A8_chfactorysparkroom[4], arg1);
    var_s0 = temp_s2;
    var_s1 = D_808010A8_chfactorysparkroom; do {
        temp_v0 = func_800C8A98();
        var_s0->light = temp_v0;
        func_800C8CB8(temp_v0, *var_s1);
        func_800C8D4C(var_s0->light, D_808010A0_chfactorysparkroom);
        func_800C8F64(var_s0->light, 3);
        func_800C8FE0(var_s0->light, 3);
        func_800C8E84(var_s0->light, sp40.color.values);
        var_s1++;
        var_s0 = (struct SparkRoomLight *)((u8 *)var_s0 + 4);
    } while (var_s1 != &D_808010D8_chfactorysparkroom);
}
struct SparkRoomColor { s32 values[3]; };
void func_808006D0_chfactorysparkroom(Actor *arg0, f32 arg1) {
    void func_800C8E84(s32 id,u32 *color);
    f32 func_800DC0C0(void);
    int func_800F3214(void *, void *, void *, f32);
    void *func_80100094(Actor *, u32);

    extern struct SparkRoomColor D_808010E4_chfactorysparkroom;
    extern struct SparkRoomColor D_808010F0_chfactorysparkroom;
    struct SparkRoomColor sp54 = D_808010E4_chfactorysparkroom;
    struct SparkRoomColor sp48 = D_808010F0_chfactorysparkroom;
    s32 sp38[4];
    s32 var_s0;
    u8 *temp_s3;
    u8 *var_s1;

    temp_s3 = func_80100094(arg0, 0);
    if (arg1 > 0.5f) {
        arg1 = (func_800DC0C0() * 0.2f) + 0.8f;
    } else {
        arg1 = 2.0f * arg1;
    }
    func_800F3214(sp38, &sp54, &sp48, arg1);
    for (var_s0 = 0, var_s1 = temp_s3; var_s0 != 0x10; var_s0 += 4, var_s1 += 4) {
        func_800C8E84(*(s32 *)(var_s1 + 0x200), sp38);
    }
}    typedef struct { u8 pad0[0x1FC]; s32 unk1FC; s32 unk200; } Objsparkroom_func_808007E0_chfactorysparkroom_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */

void func_808007E0_chfactorysparkroom(Actor *arg0) {
    void func_800C8B84(volatile s32);
    void* func_80100094(Actor*, u32);
    s32 var_s1;
    u8 *var_s0;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    var_s1 = 0;
    var_s0 = temp_v0;
    do {
        func_800C8B84((((Objsparkroom_func_808007E0_chfactorysparkroom_var_s0 *)var_s0)->unk200));
        var_s1 += 1;
        var_s0 += 4;
        (((Objsparkroom_func_808007E0_chfactorysparkroom_var_s0 *)var_s0)->unk1FC) = 0;
    } while (var_s1 != 4);
}

void func_80800838_chfactorysparkroom(Actor *arg0, void *arg1) {
    struct SparkRoomEntry {
        f32 values[6];
        s32 spline;
        s32 handle;
    };
    f32 func_80013970(f32);
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    struct ImageStruct *func_800D674C(s32);
    void *func_800D7520(s32);
    f32 func_800DC0C0(void);
    s32 func_800DC128(s32, s32);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF744(s32, s32);
    void func_800DF830(s32);
    void func_800E3980(f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1828(f32 *, f32 *);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    BtUIntPtr func_800F54E4(void);
    void func_800F5A2C(BtIntPtr, s32, f32 *);
    void *func_80100094(Actor *, u32);
    BtIntPtr func_8010347C(Unk80132ED0 *);
    struct SparkRoomEntry *entries;
    struct SparkRoomEntry *entry;
    f32 pos[3];
    f32 rot[3];
    f32 progress;
    BtIntPtr model;
    f32 point[3];
    f32 angles[3];
    f32 scale;
    s32 i;

    entries = func_80100094(arg0, 0U);
    for (i = 0, entry = entries; i < arg0->unk6C_0; i++, entry++) {
        if (entry->values[1] > 0.0f) {
            progress = func_800F10B4(entry->values[1], entry->values[0], 0.0f, entry->values[2], entry->values[3]);
            func_800C7A68(func_800D7520(entry->spline), progress, pos);
            func_800E3980(rot);
            func_800F1E6C(pos, rot, &arg0->rotation[1]);
            arg0->scale = func_80013970(progress * 180.0f);
            if (arg0->scale > 0.5f) {
                arg0->scale = func_800DC0C0() * 0.2f + 0.8f;
            } else {
                arg0->scale = 2.0f * arg0->scale;
            }
            rot[0] = -90.0f;
            rot[1] = arg0->rotation[1] - 90.0f;
            rot[2] = 0.0f;
            func_800DF830(1);
            func_800DF744(1, func_800DC128(1, 5));
            func_800DE498(arg1, pos, rot, arg0->scale, NULL, func_8010347C(arg0->unk0));
        }
    }
    if ((arg0->unk74_7 / 10.0f) * 0.3f < arg0->unk54) {
        model = (BtIntPtr)func_800D674C(0x6B9);
        for (i = 0; i != 10; i++) {
            func_800F5A2C(func_800F54E4(), i, point);
            func_800F1E6C(arg0->position, point, &angles[1]);
            angles[0] = func_800F1828(point, arg0->position);
            angles[2] = 0.0f;
            angles[1] -= 90.0f;
            scale = func_800EEAD4(arg0->position, point) / 100.0f;
            func_800DF830(1);
            func_800DF744(1, func_800DC128(1, 5));
            func_800DE498(arg1, arg0->position, angles, scale, NULL, model);
        }
    }
}

/* extern */

void func_80800B60_chfactorysparkroom(Actor *arg0, s32 arg1) {
    void func_800C8B84(volatile s32);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    struct Spark {
        f32 values[7];
        s32 handle;
    };
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    ((struct Spark *)(sp1C + (arg1 << 5)))->values[0] = func_800DC178(1.0f, 3.0f);
    ((struct Spark *)(sp1C + (arg1 << 5)))->values[1] = 0.0f;
    func_800C8B84(((struct Spark *)(sp1C + (arg1 << 5)))->handle);
    ((struct Spark *)(sp1C + (arg1 << 5)))->handle = 0;
    arg0->actorData[7]--;
}
struct SparkColor { s32 values[3]; };
void func_80800BE0_chfactorysparkroom(Actor *arg0, s32 arg1) {
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32 id,u32 *color);
    void func_800C8F64(s32, s32);
    void func_800C8FE0(s32, s32);
    void *func_800D7520(s32);
    s32 func_800DC090(void);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);

    struct Spark {
        f32 timer;
        f32 duration;
        f32 start;
        f32 end;
        f32 values[2];
        s32 spline;
        s32 handle;
    };
    extern struct SparkColor D_808010FC_chfactorysparkroom;
    struct SparkColor color;
    f32 position[3];
    struct Spark *data;

    color = D_808010FC_chfactorysparkroom;
    data = func_80100094(arg0, 0);
    data[arg1].duration = func_800DC178(4.0f, 5.0f);
    data[arg1].timer = data[arg1].duration;
    if (func_800DC090() & 1) {
        data[arg1].start = 0.0f;
        data[arg1].end = 1.0f;
    } else {
        data[arg1].start = 1.0f;
        data[arg1].end = 0.0f;
    }
    func_800C7A68(func_800D7520(data[arg1].spline), data[arg1].start, position);
    position[1] += 50.0f;
    if (data[arg1].handle == 0) {
        data[arg1].handle = func_800C8A98();
        func_800C8F64(data[arg1].handle, 3);
    }
    func_800C8FE0(data[arg1].handle, 1);
    func_800C8E84(data[arg1].handle, color.values);
    func_800C8CB8(data[arg1].handle, position);
    func_800C8D4C(data[arg1].handle, data[arg1].values);
    arg0->actorData[7]++;
}                  typedef struct { u8 pad0[0x50]; u8 unk50; u8 pad51[0x1B]; s32 unk6C; } Objsparkroom_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800D30_chfactorysparkroom(void *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8 arg0);
    u32 var_s0;

    var_s0 = 0;
    if ((((Objsparkroom_arg0 *)arg0)->unk6C) & 0x1FF) {
        do {
            _subaddieaudioloop_entrypoint_3((((Objsparkroom_arg0 *)arg0)->unk50));
            var_s0 += 1;
            (((Objsparkroom_arg0 *)arg0)->unk50) = 0U;
        } while (var_s0 < (u32) ((((Objsparkroom_arg0 *)arg0)->unk6C) & 0x1FF));
    }
}

u32 func_80800D90_chfactorysparkroom(BtIntPtr unused, s32 arg1, s32 arg2) {
    void func_80800DC8_chfactorysparkroom(Actor *);

    if (arg1 == 0x95) {
        func_80800DC8_chfactorysparkroom((Actor *) unused);
        return 1;
    }
    return 0;
}

/* extern */

void func_80800DC8_chfactorysparkroom(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    struct Spark {
        f32 values[7];
        s32 handle;
    };
    struct SparkData {
        struct Spark sparks[16];
        s32 handles[4];
    };
    u32 var_s1;
    struct SparkData *temp_s3;
    struct SparkData *temp_v0;
    struct Spark *var_s0;

    temp_v0 = func_80100094(arg0, 0);
    temp_s3 = temp_v0;
    arg0->actorData[7] = 0;
    var_s1 = 0;
    arg0->unk54 = 0.0f;
    if (arg0->unk6C_0) {
        var_s0 = temp_v0->sparks;
        do {
            var_s0->handle = 0;
            var_s0->values[0] = func_800DC178(0.0f, 3.0f);
            var_s0->values[1] = 0.0f;
            var_s1 += 1;
            var_s0++;
        } while (var_s1 < arg0->unk6C_0);
    }
    temp_s3->handles[1] = 0;
    temp_s3->handles[2] = 0;
    temp_s3->handles[3] = 0;
    temp_s3->handles[0] = 0;
}

OSThread *chfactorysparkroom_entrypoint_0(void)
{
    extern ActorData D_80801108_chfactorysparkroom[];

    return (OSThread *) D_80801108_chfactorysparkroom;
}

/* extern */

void func_80800E94_chfactorysparkroom(BtIntPtr arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2) BT_PASS2(, s32 bt_a3)) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    s32 _subaddiefade_entrypoint_14();
    void func_8010A63C(Actor *arg0);
    _subaddiefade_entrypoint_14();
    func_8010A63C(arg0);
    _chswitch_entrypoint_7(arg0, 0xA2F);
}
struct SparkRoomPosition { f32 position[3]; };
s32 func_80800EC8_chfactorysparkroom(Actor *arg0, s32 arg1, s32 arg2) {
    void _chmrtannoy_entrypoint_0(void);
    s32 _chswitch_entrypoint_10(Actor *, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    void func_800DA524(s32 index);
    void func_800DA544(s32 index);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_80108B04(Actor *, u32);
    struct SparkRoomPosition sp24;
    extern struct SparkRoomPosition D_80801150_chfactorysparkroom;

    switch (arg1) {
        case 7:
            if (func_800DA298(0x1BD)) {
                if (!func_800DA298(0x1BC)) {
                    func_800DA544(0xA04);
                    _glcutDll_entrypoint_6(0x10D, 0x41);
                    return 1;
                }
                _chmrtannoy_entrypoint_0();
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1365, 7, arg0->position, 0xA3);
                func_800DA524(0x1BD);
                func_80108B04(arg0, 0);
                return 1;
            }
            if (!func_800DA298(0x1BD) && !arg0->unk74_30) {
                arg0->unk74_30 = 1;
                _chmrtannoy_entrypoint_0();
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x133C, 7, arg0->position, 0xA3);
            }
            return 1;
        case 0x3D:
            sp24 = D_80801150_chfactorysparkroom;
            func_80108528(0x47C, sp24.position, 0, &arg0);
            return 1;
        default:
            return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
}

OSThread *chfactorysparkroom_entrypoint_1(void)
{
    extern ActorData D_8080115C_chfactorysparkroom[];

    return (OSThread *) D_8080115C_chfactorysparkroom;
}
/* data_to_c.py: from asm/data/overlays/ch/factory/sparkroom.data.s */
void func_80105834(Actor*);
void func_80108ED0();
void func_80107C2C();

void _chswitch_entrypoint_6();
void func_80101870(Actor* arg0, void* arg1);
s32 D_80801060_chfactorysparkroom[4] BT_DATA(4, overlays_ch_factory_sparkroom, 0x0) = { 1246510, 1461792, 852198, 18415616 };
s32 D_80801070_chfactorysparkroom[3] BT_DATA(4, overlays_ch_factory_sparkroom, 0x10) = { 1246510, 1469792, 0 };
struct SparkRoomUpdateColor D_8080107C_chfactorysparkroom BT_DATA(4, overlays_ch_factory_sparkroom, 0x1C) = { { 0, 0, 0 } };
struct SparkRoomUpdateColor D_80801088_chfactorysparkroom BT_DATA(4, overlays_ch_factory_sparkroom, 0x28) = { { 255, 255, 255 } };
struct SparkRoomInitColor D_80801094_chfactorysparkroom BT_DATA(4, overlays_ch_factory_sparkroom, 0x34) = { { 255, 255, 255 } };
f32 D_808010A0_chfactorysparkroom [2] BT_DATA(4, overlays_ch_factory_sparkroom, 0x40) = { 875.0f, 1700.0f };
f32 D_808010A8_chfactorysparkroom [ 4 ] [ 3 ] BT_DATA(4, overlays_ch_factory_sparkroom, 0x48) = { { 875.0f, 500.0f, 875.0f }, { 875.0f, 500.0f, -875.0f }, { -875.0f, 500.0f, 875.0f }, { -875.0f, 500.0f, -875.0f } };
f32 D_808010D8_chfactorysparkroom [ 3 ] BT_DATA(4, overlays_ch_factory_sparkroom, 0x78) = { 0.0f, 0.0f, 0.0f };
struct SparkRoomColor D_808010E4_chfactorysparkroom BT_DATA(4, overlays_ch_factory_sparkroom, 0x84) = { { 0, 0, 0 } };
struct SparkRoomColor D_808010F0_chfactorysparkroom BT_DATA(4, overlays_ch_factory_sparkroom, 0x90) = { { 255, 255, 255 } };
struct SparkColor D_808010FC_chfactorysparkroom BT_DATA(4, overlays_ch_factory_sparkroom, 0x9C) = { { 255, 255, 255 } };
ActorData D_80801108_chfactorysparkroom [1] BT_DATA(4, overlays_ch_factory_sparkroom, 0xA8) = { { 344, 1043, 1721, 1, 0, (void (*)(struct Actor *))func_8080013C_chfactorysparkroom, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800838_chfactorysparkroom, 0, 0, 0, 0, 2, 1024, (void (*)(struct Actor *))func_80800D30_chfactorysparkroom, (BtIntPtr)func_80108ED0, 528, 0, (void (*)(struct Actor *))func_80800000_chfactorysparkroom, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1024, (void (*)(struct Actor *, long, long))func_80800D90_chfactorysparkroom, 0 } };
struct SparkRoomPosition D_80801150_chfactorysparkroom BT_DATA(4, overlays_ch_factory_sparkroom, 0xF0) = { { -2500.0f, 0.0f, 0.0f } };
ActorData D_8080115C_chfactorysparkroom [1] BT_DATA(4, overlays_ch_factory_sparkroom, 0xFC) = { { 835, 1005, 2179, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800E94_chfactorysparkroom, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_80800EC8_chfactorysparkroom, 0 } };
