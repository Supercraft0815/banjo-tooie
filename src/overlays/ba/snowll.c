#include "common.h"

s32 basnowball_entrypoint_0() 
{
    return 0x30;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_80800008_basnowball.s")

f32 func_80800084_basnowball(s32 arg0) {
    extern f32 D_80801020_basnowball[];
    return ((f32 *)&D_80801020_basnowball)[arg0];
}

s32 func_80800098_basnowball(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    extern f32 D_80801038_basnowball[];
    f32 *temp_v0;

    temp_v0 = (f32 *)((u8 *)D_80801038_basnowball + arg1 * 8);
    *(f32 *)arg2 = temp_v0[0];
    *(f32 *)arg3 = temp_v0[1];
}

/* extern */

void func_808000C0_basnowball(s32 arg0) {
    s32 func_8009590C(s32, s32);
    s32 func_800959C8(s32, s32, s32);
    s32 func_800A1718();
    s32 func_80800098_basnowball(s32, s32, s32 *, s32 *);
    s32 sp24;
    s32 sp20;

    func_80800098_basnowball(arg0, func_800A1718(), &sp24, &sp20);
    func_800959C8(arg0, sp24, sp20);
    func_8009590C(arg0, sp24);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_80800110_basnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_80800150_basnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_808001B8_basnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/basnowball_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/basnowball_entrypoint_2.s")

f32 basnowball_entrypoint_3(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 272) + 8);
}

f32 basnowball_entrypoint_4(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 272) + 28);
}

void basnowball_entrypoint_5(void) {
    s32 func_800A1718();
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    func_800F10B4((f32) func_800A1718(), 1.0f, 5.0f, 0.0f, 1.0f);
}

/* extern */

s32 basnowball_entrypoint_6(void) {
    s32 func_800A1718();
    return func_800A1718() >= 5;
}

void basnowball_entrypoint_7(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x110)))) + (0x2C))) = 1;
}

/* extern */

void basnowball_entrypoint_8(s32 arg0, s32 arg1) {
    s32 func_80800150_basnowball(s32, s32);
    if (arg1 != 0) {
        func_80800150_basnowball(arg0, 2);
        return;
    }
    func_80800150_basnowball(arg0, 1);
}

void basnowball_entrypoint_9(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 272) + 12) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/basnowball_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_808007CC_basnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_8080099C_basnowball.s")

void basnowball_entrypoint_11(s32 arg0)
{
    func_800F796C(arg0,0x3);
}

void basnowball_entrypoint_12(void *arg0) {
    typedef struct {
        f32 distance;
        f32 timer;
        f32 angle;
        f32 speed;
        f32 turnSpeed;
        u8 turnState;
        u8 pad15[3];
        f32 transitionTimer;
        f32 scale;
        f32 targetScale;
        f32 startScale;
        u8 state;
        u8 pad29[3];
        u8 active;
        u8 mode;
    } Snowball;
    typedef struct {
        u8 pad0[0x110];
        Snowball *snow;
        u8 pad114[0x70];
        s32 id;
    } SnowPlayer;
    f32 func_800D8FF8(void);
    s32 func_800EA068(s32);
    s32 func_8008DE50();
    s32 func_800A1760(void *);
    void func_8009919C(void *, s32, s32);
    s32 func_800A1718(void *);
    s32 func_800A17A8(s32, s32);
    s32 func_800958A4(void *, s32, s32);
    void func_80096394(void *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800FC660(u32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_8009E55C(void *, s32, f32);
    f32 func_800136E4(f32);
    f32 func_800F13F0(f32, f32);
    f32 func_800F0E00(f32, f32);
    void func_800E0AF0(void *, f32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    void func_80093230(void *, f32);
    extern void _basnowball_entrypoint_11(s32);
    f32 dt;
    void *model;
    f32 position[4];
    f32 scale;
    s32 size;
    s32 width;
    s32 height;
    s32 change;
    f32 oldAngle;
    s32 pad[2];

    dt = func_800D8FF8();
    if (func_800EA068(1) && !func_8009E674(arg0, 0x10)) {
        size = func_800A1718(arg0);
        if (size > 0 && ((SnowPlayer *)arg0)->snow->state == 1) {
            ((SnowPlayer *)arg0)->snow->timer -= dt;
            if (((SnowPlayer *)arg0)->snow->timer < 0.0f) {
                if (size == 1) {
                    func_8009919C(arg0, (s32)_basnowball_entrypoint_11, ((SnowPlayer *)arg0)->id);
                } else {
                    ((SnowPlayer *)arg0)->snow->timer = 7.5f;
                    func_800A17A8((s32)arg0, -1);
                }
            }
        }
    } else if (func_8008DE50(arg0) && player_isStable(arg0) && ((SnowPlayer *)arg0)->snow->speed > 100.0f) {
        func_8080099C_basnowball(arg0);
        if (func_800A1718(arg0) < func_800A1760(arg0) && ((SnowPlayer *)arg0)->snow->state == 1) {
            func_80096394(arg0, position);
            ((SnowPlayer *)arg0)->snow->distance += func_800EEF94(position);
            if (((SnowPlayer *)arg0)->snow->distance > 1000.0f) {
                ((SnowPlayer *)arg0)->snow->distance = 0.0f;
                func_800A17A8((s32)arg0, 1);
                func_800FC660(8);
            }
        }
    }
    switch (((SnowPlayer *)arg0)->snow->state) {
    case 1:
        size = func_800A1718(arg0);
        scale = func_80800084_basnowball(size);
        if (scale != ((SnowPlayer *)arg0)->snow->scale) {
            func_80800098_basnowball((s32)arg0, size, &width, &height);
            change = 0;
            if (scale < ((SnowPlayer *)arg0)->snow->scale) {
                change = 1;
            } else if (!func_800958A4(arg0, width, height)) {
                change = 1;
            }
            if (change) {
                func_808001B8_basnowball(arg0, 2);
            }
        }
        break;
    case 2:
        ((SnowPlayer *)arg0)->snow->scale = func_800F10B4(((SnowPlayer *)arg0)->snow->transitionTimer, 0.0f, 1.0f, ((SnowPlayer *)arg0)->snow->startScale, ((SnowPlayer *)arg0)->snow->targetScale);
        func_8009E55C(arg0, 0, ((SnowPlayer *)arg0)->snow->scale * 50.0f);
        if (func_800D9078(&((SnowPlayer *)arg0)->snow->transitionTimer)) {
            func_808001B8_basnowball(arg0, 1);
        }
        break;
    }
    switch (((SnowPlayer *)arg0)->snow->turnState) {
    case 1:
        ((SnowPlayer *)arg0)->snow->angle = func_800136E4(((SnowPlayer *)arg0)->snow->angle + (((SnowPlayer *)arg0)->snow->speed / ((SnowPlayer *)arg0)->snow->scale) * dt);
        break;
    case 2:
        oldAngle = ((SnowPlayer *)arg0)->snow->angle;
        if (((SnowPlayer *)arg0)->snow->angle != 0.0f) {
            scale = func_800F0E00(func_800F13F0(((SnowPlayer *)arg0)->snow->turnSpeed / ((SnowPlayer *)arg0)->snow->scale, (360.0f - oldAngle) * 7.0f) * dt, 1.5f);
            ((SnowPlayer *)arg0)->snow->angle = func_800136E4(((SnowPlayer *)arg0)->snow->angle + scale);
            if (((SnowPlayer *)arg0)->snow->angle < oldAngle) {
                ((SnowPlayer *)arg0)->snow->angle = 0.0f;
            }
        }
        break;
    }
    model = func_80092AD8(arg0);
    func_800E0AF0(model, 1.0f);
    func_800E0AFC(model, 0x43, 1.0f, ((SnowPlayer *)arg0)->snow->angle, 0.0f, 0.0f);
    func_80093230(arg0, ((SnowPlayer *)arg0)->snow->scale);
    _bawobble_entrypoint_8(arg0);
    if (((SnowPlayer *)arg0)->snow->mode == 2) {
        if (!((SnowPlayer *)arg0)->snow->active) {
            func_80800008_basnowball(arg0, 1);
        } else {
            func_808007CC_basnowball(arg0);
            ((SnowPlayer *)arg0)->snow->active = 0;
        }
    } else if (((SnowPlayer *)arg0)->snow->active) {
        func_80800008_basnowball(arg0, 2);
        ((SnowPlayer *)arg0)->snow->active = 0;
    }
}
