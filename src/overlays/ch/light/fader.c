#include "common.h"

OSThread *chlightfader_entrypoint_0(void)
{
    extern ActorData D_808003A0_chlightfader[];

    return (OSThread *) D_808003A0_chlightfader;
}

void func_8080000C_chlightfader(s32 arg0) 
{
}
void func_80800014_chlightfader(Actor *arg0) {
    s32 func_8001210C(s32);
    BtIntPtr func_800A93F8(s32 arg0);
    s32 func_800A9420(s32);
    s32 func_800A946C(void);
    void func_800C8B84(s32);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    s32 func_800CACEC(f32 *, f32 *, f32);
    s32 func_800D9078(f32 *);
    s32 func_800E3E8C(f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F2E60(s32 arg0[3], s32 arg1[3]);
    void func_800F2F60(void *, void *, f32);
    s32 func_800F6438(BtUIntPtr);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 finished;
    f32 fade;
    f32 inverse;
    s32 i;
    f32 *position;
    u32 color[3];
    s32 changed;
    s32 visible;
    struct {
        s32 source;
        f32 duration;
        s32 mode;
        s32 flag;
        f32 value;
        f32 original[2];
        u32 originalColor[3];
        f32 current[2];
        u32 currentColor[3];
    } *data;
    s32 player;

    data = func_80100094(arg0, 0);
    changed = 0;
    finished = func_800D9078(&arg0->unk58);
    fade = func_800F10B4(arg0->unk58, 0.0f, data->duration, 1.0f, 0.1f);
    inverse = 1.0f - fade;
    if (data->mode & 1) {
        for (i = 0; i < 2; i++) {
            data->current[i] = data->original[i] * inverse;
        }
        changed = 1;
    }
    if (data->mode & 2) {
        func_800F2F60(data->currentColor, data->originalColor, 1.0f - fade);
    }
    func_800F2E60(color, data->currentColor);
    if (data->mode & 4) {
        func_800F2F60(color, color, func_8001210C(1) ? 1.0f : 0.6f);
    }
    if (func_800A946C() >= 2) {
        visible = 0;
        for (player = 0; player < 8; player++) {
            if (func_800F6438(player) && func_800A9420(player) &&
                (position = func_800A93F8(player)) != NULL &&
                func_800CACEC(position, arg0->position, data->value)) {
                visible = 1;
                break;
            }
        }
    } else {
        visible = func_800E3E8C(arg0->position, data->value);
    }
    if (visible) {
        data->value = data->current[1];
        func_800C8E84(data->source, color);
        if (changed) {
            func_800C8D4C(data->source, data->current);
        }
    }
    if (finished) {
        func_800C8B84(data->source);
        func_800FFA88(arg0->unk0);
    }
}

s32 chlightfader_entrypoint_1(s32 arg0, s32 arg1, s32 arg2) {
    void _chbaddiesetup_entrypoint_3(s32 *, s32, s32, s32);
    void func_800C8B84(s32);
    s32 func_800C954C(void);
#ifdef BT_NATIVE
    void chlightfader_entrypoint_2(s32 arg0, f32 arg1, s32 arg2);
#else
    extern s32 _chlightfader_entrypoint_2;
#endif
    if (func_800C954C() == 0) {
        _chbaddiesetup_entrypoint_3(&_chlightfader_entrypoint_2, arg0, arg1, arg2);
    } else {
        func_800C8B84(arg0);
    }
    return 0;
}

/* extern */

void chlightfader_entrypoint_2(s32 arg0, f32 arg1, s32 arg2) {
    void func_800C8800(BtIntPtr, f32 *);
    void func_800C883C(s32, void *);
    void func_800C8900(s32, u8 *);
    u8 func_800C89A8(s32);
    void *func_80100094(Actor *, u32);
    Actor *func_80108474(u32, f32 *, s32);
    Actor *sp5C;
    f32 *duration_arg = &arg1;
    f32 sp54;
    f32 sp48[3];
    f32 duration;
    s32 var_s0;
    struct {
        s32 source;
        f32 duration;
        s32 mode;
        s32 flag;
        f32 value;
        struct {
            s32 unk0;
            f32 unk4;
            u8 unk8[12];
        }
        lights[2];
    }
    *temp_s5;
    Actor *temp_v0;
    u8 *var_s1;
    u8 *var_s2;
    sp54 = *duration_arg;
    func_800C8800(arg0, sp48);
    temp_v0 = func_80108474(0x33C, sp48, 0);
    sp5C = temp_v0;
    temp_s5 = func_80100094(temp_v0, 0);
    temp_s5->flag = func_800C89A8(arg0);
    var_s0 = 0;
    var_s1 = temp_s5->lights[0].unk8;
    var_s2 = (u8 *)&temp_s5->lights[0];
    do {
        func_800C8900(arg0, var_s1);
        func_800C883C(arg0, var_s2);
        var_s0 += 0x14;
        var_s1 += 0x14;
        var_s2 += 0x14;
    }
    while (var_s0 != 0x28);
    duration = sp54;
    temp_s5->source = arg0;
    temp_s5->duration = duration;
    temp_s5->mode = arg2;
    temp_s5->value = temp_s5->lights[1].unk4;
    sp5C->unk58 = duration;
}
/* data_to_c.py: from asm/data/overlays/ch/light/fader.data.s */
void func_80105834(Actor*);
void func_8010A730();
void func_80107C2C();
ActorData D_808003A0_chlightfader [1] BT_DATA(4, overlays_ch_light_fader, 0x0) = { { 820, 828, 0, 1, 0, (void (*)(struct Actor *))func_80800014_chlightfader, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 4, 0, 0, 60, 0, (void (*)(struct Actor *))func_8080000C_chlightfader, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8706, 0, 0 } };
