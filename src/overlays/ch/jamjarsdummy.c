#include "common.h"
typedef struct { u16 animation; s16 state; } JamjarsAnimation;
void func_80800000_chjamjarsdummy(Actor *arg0, s32 arg1) {
    void _subaddiefade_entrypoint_8(Actor *, s32);

    arg0->unk79_4 = arg1;
    switch (arg0->unk79_4) {
    case 0:
        arg0->unk58 = 2.0f;
        _subaddiefade_entrypoint_8(arg0, 0xFF);
        break;
    case 1:
        switch (arg0->unk6C_0) {
        case 0:
            arg0->unk58 = 5.0f;
            break;
        case 1:
            arg0->unk58 = 5.0f;
            break;
        case 2:
            arg0->unk58 = 5.0f;
            break;
        }
        break;
    case 2:
        arg0->unk58 = 2.0f;
        ((f32 *)arg0->actorData)[4] = 0.0f;
        break;
    }
}

void func_808000E0_chjamjarsdummy(Actor *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_800DA9E4(s32, s32);
    void func_800FFAB0(Actor *);
    void _chswappy_entrypoint_0(Actor *, s32);
    void _subaddiefade_entrypoint_8(Actor *, s32);
    s32 fadeIn;
    s32 fadeOut;

    ((f32 *)arg0->actorData)[4] += func_800D8FF8();
    if (arg0->unk6C_0 == 2) {
        _chswappy_entrypoint_0(arg0, 0);
    }
    switch (arg0->unk79_4) {
    case 0:
        fadeIn = (s32)func_800F10B4(((f32 *)arg0->actorData)[4], 0.0f, arg0->unk58, 0.0f, 255.0f);
        _subaddiefade_entrypoint_8(arg0, fadeIn);
        if (fadeIn >= 255) {
            func_80800000_chjamjarsdummy(arg0, 1);
        }
        break;
    case 1:
        if (func_800DA9E4(0x9F1, 0)) {
            func_800FFAB0(arg0);
        }
        if (arg0->unk58 < ((f32 *)arg0->actorData)[4]) {
            func_80800000_chjamjarsdummy(arg0, 2);
        }
        break;
    case 2:
        fadeOut = (s32)func_800F10B4(((f32 *)arg0->actorData)[4], 0.0f, arg0->unk58, 255.0f, 0.0f);
        _subaddiefade_entrypoint_8(arg0, fadeOut);
        if (fadeOut <= 0) {
            func_800FFAB0(arg0);
        }
        break;
    }
}

void func_80800238_chjamjarsdummy(s32 arg0) 
{
}
void func_80800240_chjamjarsdummy(Actor *arg0) {
    void func_80800000_chjamjarsdummy(Actor *, s32);
    extern JamjarsAnimation D_8080032C_chjamjarsdummy[];

    func_80103140(arg0, D_8080032C_chjamjarsdummy[arg0->unk6C_0].animation, arg0->unk0->unk16); func_80102424(arg0, D_8080032C_chjamjarsdummy[arg0->unk6C_0].state); func_80800000_chjamjarsdummy(arg0, 0);
}

/* extern */

void func_808002AC_chjamjarsdummy(Actor *arg0, void *arg1) {
    void func_80101870(Actor *, void *);
    if (arg0->unk6C_0 == 2) {
        arg0->unk7C_12 = 1;
        return;
    }
    func_80101870(arg0, arg1);
}

OSThread *chjamjarsdummy_entrypoint_0(void)
{
    extern ActorData D_80800338_chjamjarsdummy[];
    return (OSThread *) D_80800338_chjamjarsdummy;
}
#include "jamjarsdummy_data.inc"
