#include "common.h"

void func_80800000_chfactorysparkroom(Actor *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 _glsplinefind_entrypoint_3(f32 *);
    void _gspropctrl_entrypoint_11(Prop *, f32 *);
    s32 _gspropctrl_entrypoint_8(Prop *);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, u8, s32 *, s32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80801070_chfactorysparkroom;
    Prop *sp68[16];
    Prop **var_s0;
    u32 var_s2;
    f32 sp54[3];
    struct SparkRoomActorData {
        u8 pad0[0x38];
        u8 audio;
        u8 pad39[0x1F];
        u32 pad58 : 31;
        u32 active : 1;
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
    ((struct SparkRoomActorData *)arg0->actorData)->audio = _subaddieaudioloop_entrypoint_7(((struct SparkRoomActorData *)arg0->actorData)->audio, arg0->position, 0, &D_80801070_chfactorysparkroom, ((struct SparkRoomActorData *)arg0->actorData)->active);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_8080013C_chfactorysparkroom.s")

void func_808005E0_chfactorysparkroom(Actor *arg0, f32 *arg1) {
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32[3]);
    void func_800C8D4C(s32, f32 *);
    s32 func_800C8E84(s32, s32 *);
    void func_800C8F64(s32, s32);
    void func_800C8FE0(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    struct SparkRoomInitColor { s32 values[3]; };
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

void func_808006D0_chfactorysparkroom(Actor *arg0, f32 arg1) {
    s32 func_800C8E84(s32, s32 *);
    f32 func_800DC0C0(void);
    int func_800F3214(void *, void *, void *, f32);
    void *func_80100094(Actor *, u32);
    struct SparkRoomColor { s32 values[3]; };
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
}

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
        func_800C8B84((*(s32 *)((s8 *)(var_s0) + (0x200))));
        var_s1 += 1;
        var_s0 += 4;
        (*(s32 *)((s8 *)(var_s0) + (0x1FC))) = 0;
    } while (var_s1 != 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_80800838_chfactorysparkroom.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_80800BE0_chfactorysparkroom.s")

/* extern */

void func_80800D30_chfactorysparkroom(void *arg0) {
    s32 _subaddieaudioloop_entrypoint_3(u8);
    u32 var_s0;

    var_s0 = 0;
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        do {
            _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x50))));
            var_s0 += 1;
            (*(u8 *)((s8 *)(arg0) + (0x50))) = 0U;
        } while (var_s0 < (u32) ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF));
    }
}

u32 func_80800D90_chfactorysparkroom(s32 unused, s32 arg1, s32 arg2) {
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
    extern u8 D_80801108_chfactorysparkroom[];

    return (OSThread *) D_80801108_chfactorysparkroom;
}

/* extern */

void func_80800E94_chfactorysparkroom(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _subaddiefade_entrypoint_14();
    s32 func_8010A63C(s32);
    _subaddiefade_entrypoint_14();
    func_8010A63C(arg0);
    _chswitch_entrypoint_7(arg0, 0xA2F);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/sparkroom/func_80800EC8_chfactorysparkroom.s")

OSThread *chfactorysparkroom_entrypoint_1(void)
{
    extern u8 D_8080115C_chfactorysparkroom[];

    return (OSThread *) D_8080115C_chfactorysparkroom;
}
