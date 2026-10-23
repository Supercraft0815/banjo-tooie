#include "common.h"

void func_80800000_chping(Actor *arg0, s32 arg1) {
    f32 func_80013970(f32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, u8 *);
    void func_800DF410(s32);
    void func_800DF830(s32);
    void func_800E3A58(f32 *);
    f32 func_800F0F9C(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094();
    u8 *func_801039E4(Unk80132ED0 *);
    f32 elapsed;
    f32 alpha;
    f32 scale;
    u8 *model;
    f32 rotation[3];
    s32 i;
    struct { s32 source; f32 time; } *data;
    f32 phase;
    f32 wave;

    data = func_80100094(arg0, 0);
    model = func_801039E4(arg0->unk0);
    func_800E3A58(rotation);
    for (i = 0; i < 3; i++) {
        elapsed = data->time;
        elapsed -= (f32)i * 0.4f;
        if (elapsed < 0.0f || elapsed > 3.0f) {
            continue;
        }
            scale = func_800F10B4(elapsed, 0.0f, 3.0f, 0.5f, 30.0f);
            alpha = func_800F10B4(data->time, 0.0f, 3.0f, 40.0f, 0.0f);
            phase = func_800F0F9C(data->time, 0.5);
            wave = func_80013970(phase * 360.0f);
            func_800DF410((s32)(10.0f + alpha + alpha * wave));
            func_800DF830(2);
            func_800DE448(arg0->position, rotation, scale, NULL, model);
    }
}

void func_808001B8_chping(Actor *arg0) {
    f32 func_80013970(f32);
    s32 func_800A940C(s32);
    void func_800C4B90(s32, f32, f32);
    void func_800CB840(s32, s32);
    void func_800CB870(void);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F0F9C(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F5A00(s32, f32 *);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80100094();
    s32 func_80109CC4(f32 *, f32, void *);
    s32 func_8010A570();
    void func_8010A590(Actor *);
    f32 phase;
    f32 wave1;
    f32 wave2;
    f32 scale;
    f32 radius;
    f32 elapsed;
    f32 position[3];
    s32 source;
    struct { s32 source; f32 time; } *data;

    data = func_80100094(arg0, 0);
    source = data->source;
    func_800F5A00(source, position);
    position[1] += 60.0f;
    func_800EE7F8(arg0->position, position);
    elapsed = data->time;
    phase = func_800F0F9C(elapsed, 0.5f);
    wave1 = func_80013970(phase * 360.0f);
    wave2 = func_80013970(phase * 360.0f + 180.0f);
    scale = func_800F10B4(elapsed, 0.0f, 3.0f, 3.0f, 0.01f);
    func_800C4B90(func_800A940C(source), wave1 * scale, wave2 * scale);
    if (elapsed < 3.0f) {
        radius = func_800F10B4(elapsed, 0.0f, 3.0f, 14.0f, 840.0f);
        func_8010A590(arg0);
        func_800CB840(5, (s32)arg0);
        func_80109CC4(arg0->position, radius, arg0->unk0);
        func_800CB870();
        func_8010A570(arg0);
    }
    data->time += func_800D8FF8();
    if (data->time > 4.2f) {
        func_800FFA88(arg0->unk0);
    }
}

/* extern */

s32 chping_entrypoint_0(s32 arg0) {
    void func_800F5A00(s32, f32 *);
    void *func_80100094(s32 *, s32);
    s32 *func_80108474(s32, s32 *, s32);
    s32 func_8010A570(s32 *);
    s32 *sp2C;
    s32 sp20[3];
    s32 *temp_v0;
    void *temp_v0_2;

    func_800F5A00(arg0, sp20);
    temp_v0 = func_80108474(0x169, sp20, 0);
    sp2C = temp_v0;
    temp_v0_2 = func_80100094(temp_v0, 0);
    (*(f32 *)((s8 *)(temp_v0_2) + (4))) = 0.0f;
    (*(s32 *)((s8 *)(temp_v0_2) + (0))) = arg0;
    func_8010A570(sp2C);
    return *sp2C;
}

OSThread *chping_entrypoint_1(void)
{
    extern u8 D_80800410_chping[];

    return (OSThread *) D_80800410_chping;
}
