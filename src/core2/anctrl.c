#include "core2/anctrl.h"

f32 func_8008A990(AnimCtrl *this) {
    struct Flags { u8 padding[0x18]; u32 high : 27; u32 mode : 2; u32 low : 3; };
    f32 func_800D8FF8(void);
    f32 _glintrosyncDll_entrypoint_5(void);
    extern f32 D_80124A90;

    switch (((struct Flags *)this)->mode) {
        case 0:
            return func_800D8FF8();
        case 1:
            return D_80124A90;
        case 2:
            return _glintrosyncDll_entrypoint_5();
        default:
            return func_800D8FF8();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/anctrl/func_8008AA0C.s")

void func_8008AAC0(AnimCtrl *this) {
    struct Flags { u8 padding[0x1B]; u8 high : 1; u8 smooth : 1; u8 low : 6; };
    void *func_8008AEDC(void *);
    void func_8008AA0C(AnimCtrl *);
    f32 func_8008C0C8(f32 *);
    f32 func_8008A990(AnimCtrl *);
    f32 func_8008B2AC(f32 *arg0);
    void func_8008C1C0(f32 *arg0, f32 arg1);
    void *anim;
    f32 delta;
    f32 tmp;

    anim = func_8008AEDC(this);
    func_8008AA0C(this);
    *(f32 *)this = func_8008C0C8(anim);
    delta = func_8008A990(this) / func_8008B2AC((f32 *)this);
    if (((struct Flags *)this)->high == 0) {
        delta = -delta;
    }
    tmp = *(f32 *)this + delta;
    if (tmp < 0.0f) {
        tmp += 1.0f;
    }
    tmp -= (f32)(s32)tmp;
    func_8008C1C0(anim, tmp);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/anctrl/func_8008AB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/anctrl/func_8008AC4C.s")

/* extern */

AnimCtrl *func_8008AD80(s32 arg0) {
    s32 func_8008C0B8();
    void* heap_alloc(s32 size);
    s32 func_8008B518(AnimCtrl *, s32);
    AnimCtrl *sp1C;
    AnimCtrl *temp_v0;

    temp_v0 = heap_alloc(func_8008C0B8() + 0x1C);
    sp1C = temp_v0;
    func_8008B518(temp_v0, arg0);
    return sp1C;
}

void func_8008ADBC(AnimCtrl *arg0)
{
    void func_8008B5E8(AnimCtrl *);
    func_8008B5E8(arg0);
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/anctrl/func_8008ADE4.s")

AnimCtrl* func_8008AEB4(AnimCtrl* arg0)
{
    return defrag(arg0);
}
void anctrl_setIndex(AnimCtrl *arg0, AssetId arg1)
{
    ((s16 *)arg0)[12] = arg1;
}

void *func_8008AEDC(void *arg0)
{
    return (u8 *)arg0 + 0x1C;
}

/* extern */

void func_8008AEE4(AnimCtrl *arg0, void (*arg1)(s32 *, f32)) {
    void func_8008C1D4(void *, void (*)(s32 *, f32));
    func_8008C1D4((u8 *)arg0 + 0x1C, arg1);
}

/* extern */

void func_8008AF04(AnimCtrl *arg0, s32 arg1) {
    void func_8008C1DC(void *, s32);
    func_8008C1DC((u8 *)arg0 + 0x1C, arg1);
}

void anctrl_reset(AnimCtrl *control) {
    typedef struct { f32 start; u8 padding4[0x10]; f32 time; u8 padding18[2]; u8 type; u8 high : 2; u8 flag : 1; u8 low : 5; } ResetState;
    s32 func_800E6A00(void);
    ResetState *state = (ResetState *)control;
    s32 mode;
    state->type = 2;
    state->flag = 1;
    state->start = 0.0f;
    state->time = 0.0f;
    anctrl_setSmoothTransition(control, 1);
    anctrl_setSubrange(control, 0.0f, 1.0f);
    anctrl_setDuration(control, 2.5678f);
    func_8008B1C8(control, 0.2f);
    func_8008B188(control, 1);
    mode = func_800E6A00() ? 2 : 0;
    func_8008B2E8(control, mode);
}

void func_8008AFCC(AnimCtrl *control) {
    struct StartState {
        f32 timer;
        u8 padding[0x10];
        f32 start;
        u32 high : 26;
        u32 default_start : 1;
        u32 low : 5;
        f32 animation[1];
    };
    struct StartState *state = (struct StartState *)control;
    f32 func_8008C0C8(f32 *);
    void func_8008C1C0(f32 *, f32);

    if (state->default_start) {
        if (((u32)*((u8 *)control + 0x1B) >> 7) == 1) {
            func_8008C1C0(state->animation, 0.0f);
        } else {
            func_8008C1C0(state->animation, 0.99999899f);
        }
    } else {
        func_8008C1C0(state->animation, state->start);
    }
    state->timer = func_8008C0C8(state->animation);
}

void anctrl_start(AnimCtrl *control) {
    struct StartFlags {
        u8 padding[0x18];
        s32 index : 16;
        u32 high : 9;
        u32 smooth : 1;
        u32 low : 6;
        s8 animation[1];
    };
    struct StartFlags *state = (struct StartFlags *)control;
    void func_8008C0AC(s8 *);
    s32 func_8008C0C0(s16 *);
    void func_8008C1B8(s16 *, s32);
    void func_8008C1E4(f32 *, f32);
    void func_8008C270(s8 *);

    if (state->smooth && func_8008C0C0((s16 *)state->animation) != 0) {
        func_8008C0AC(state->animation);
        func_8008C1B8((s16 *)state->animation, state->index);
        func_8008AFCC(control);
        func_8008C1E4((f32 *)state->animation, 0.0f);
    } else {
        func_8008C270(state->animation);
        func_8008C1B8((s16 *)state->animation, state->index);
        func_8008AFCC(control);
        func_8008C1E4((f32 *)state->animation, 1.0f);
    }
}

void func_8008B10C(AnimCtrl *arg0, f32 arg1) {
    void func_8008C1C0(f32 *arg0, f32 arg1);
    func_8008C1C0((f32 *) (arg0 + 0x1C), arg1);
}

void anctrl_setPlaybackType(AnimCtrl *arg0, s32 arg1) {
    struct PlaybackFlags { u8 padding[0x18]; u32 prefix : 16; u32 type : 8; u32 high : 5; u32 playback : 1; u32 low : 2; };
    struct PlaybackFlags *flags = (struct PlaybackFlags *)arg0;
    flags->type = arg1 & 0xFF;
    switch (arg1) {
    case 1:
    case 3:
        *((u8 *)arg0 + 0x1B) &= ~4;
        return;
    case 2:
    case 4:
        flags->playback = 1;
        return;
    }
}

void func_8008B188(AnimCtrl *arg0, s32 arg1) {
    struct Flags { u8 padding[0x1B]; u8 high : 1; u8 smooth : 1; u8 low : 6; };
    ((struct Flags *)arg0)->high = arg1;
}

void anctrl_setSmoothTransition(AnimCtrl *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1B];
        u8 high : 1;
        u8 smooth : 1;
        u8 low : 6;
    };
    ((struct Flags *)arg0)->smooth = arg1;
}

void anctrl_setDuration(AnimCtrl *arg0, f32 arg1) {
    (*(f32 *)((s8 *)(arg0) + (0xC))) = arg1;
}

void func_8008B1C8(AnimCtrl *arg0, f32 arg1) {
    (*(f32 *)((s8 *)(arg0) + (0x10))) = arg1;
}

void anctrl_setSubrange(AnimCtrl *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) (arg1 - (f32) (s32) arg1);
    if (arg2 != 1.0f) {
        (*(f32 *)((s8 *)(arg0) + (8))) = (f32) (arg2 - (f32) (s32) arg2);
        return;
    }
    (*(f32 *)((s8 *)(arg0) + (8))) = arg2;
}

void func_8008B238(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (*(f32 *)((s8 *)(arg0) + (4)));
    *arg2 = (*(f32 *)((s8 *)(arg0) + (8)));
}

void anctrl_setStart(AnimCtrl *arg0, f32 arg1) {
    (*(u8 *)((s8 *)(arg0) + (0x1B))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x1B))) & 0xFFDF);
    (*(f32 *)((s8 *)(arg0) + (0x14))) = arg1;
}

int anctrl_getIndex(AnimCtrl *arg0) {
    s32 func_8008C0C0(s16 *arg0);
    return func_8008C0C0((s16 *) (arg0 + 0x1C));
}

u32 anctrl_getPlaybackType(u8 *arg0) {
    return arg0[26];
}

s32 func_8008B28C(AnimCtrl *arg0) {
    return (u32) (*(u8 *)((s8 *)arg0 + 0x1B)) >> 7;
}

u32 func_8008B29C(void *arg0) {
    return (u32) ((*(s32 *)((s8 *)(arg0) + (0x18))) << 0x19) >> 0x1F;
}

f32 func_8008B2AC(f32 *arg0) {
    return arg0[3];
}

f32 anctrl_getAnimTimer(AnimCtrl *arg0) { f32 func_8008C0C8(f32 *); return func_8008C0C8((f32 *) ((u8 *) arg0 + 0x1C)); }

f32 func_8008B2D4(f32 *arg0) {
    return arg0[0];
}

void func_8008B2DC(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 0) = arg1;
}

void func_8008B2E8(AnimCtrl *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1B];
        u8 high : 3;
        u8 smooth : 2;
        u8 low : 3;
    };
    ((struct Flags *)arg0)->smooth = arg1;
}

/* extern */

void func_8008B304(s32 arg0) {
    s32 func_8008C038(s32);
    func_8008C038(arg0 + 0x1C);
}

s32 anctrl_isStopped(AnimCtrl *arg0) {
    return anctrl_getPlaybackType(&arg0->unk0) == 3;
}

int anctrl_isAt(AnimCtrl *arg0, f32 arg1) {
    f32 func_8008C0C8(f32 *);
    f32 current;
    f32 previous;

    current = func_8008C0C8((f32 *)((u8 *)arg0 + 0x1C));
    previous = *(f32 *)arg0;
    if (current == previous) {
        return 0;
    }
    if (((u32)*(u8 *)((u8 *)arg0 + 0x1B) >> 7) == 1) {
        if (previous < current) {
            return previous <= arg1 && arg1 < current;
        }
        return previous <= arg1 || arg1 < current;
    }
    if (current < previous) {
        return arg1 <= previous && current < arg1;
    }
    return arg1 <= previous || current < arg1;
}

void func_8008B4A8(AnimCtrl *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1B];
        u8 high : 5;
        u8 smooth : 1;
        u8 low : 2;
    };
    ((struct Flags *)arg0)->smooth = arg1;
}

u32 func_8008B4C4(void *arg0) {
    return (u32) ((*(s32 *)((s8 *)(arg0) + (0x18))) << 0x1D) >> 0x1F;
}

/* extern */

s32 func_8008B4D4(AnimCtrl *arg0) {
    s32 func_8008C27C(AnimCtrl *);
    return func_8008C27C(arg0 + 0x1C);
}

/* extern */

s32 func_8008B4F4(void) {
    s32 func_8008C0B8();
    return func_8008C0B8() + 0x1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/anctrl/func_8008B518.s")

void func_8008B5E8(AnimCtrl *arg0) {
    void func_8008C0D8(void *);
    func_8008C0D8((u8 *)arg0 + 0x1C);
}
