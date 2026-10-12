#include "common.h"
#include "overlays/ba/playerstate.h"

s32 func_80800000_bsstand(s32 *arg0) {
    extern s32 D_80800D90_bsstand[];
    return D_80800D90_bsstand[arg0[0x160 / 4]];
}

s32 func_80800018_bsstand(s32 *arg0, s32 arg1) {
    arg1++;
    if (arg1 >= arg0[0x164 / 4]) {
        arg1 = 0;
    }
    return arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/func_80800038_bsstand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/func_80800274_bsstand.s")

void bsstand_entrypoint_1(PlayerState *arg0) {
    void *baanim_getAnimCtrlPtr(PlayerState *);
    f32 anctrl_getAnimTimer(void *);
    s32 anctrl_getIndex(void *);
    int anctrl_isAt(void *, f32);
    void anctrl_reset(void *);
    void anctrl_setDuration(void *, f32);
    void anctrl_setIndex(void *, s32);
    void anctrl_setPlaybackType(void *, s32);
    void anctrl_setStart(void *, f32);
    void anctrl_start(void *);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    f32 bastick_distance(PlayerState *);
    s32 bastick_getZone(PlayerState *);
    void bs_setState(PlayerState *, s32);
    void func_8008B1C8(void *, f32);
    s32 func_8008DD04(PlayerState *);
    void func_800909CC(PlayerState *);
    s32 func_80090A2C();
    void func_8009D874(PlayerState *);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    void func_8009DF94(PlayerState *, s32, f32, s32);
    s32 func_800A0CF4(PlayerState *, s32);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    void yaw_setUpdateType(PlayerState *, s32);
    void yaw_setVelocityBounded(PlayerState *, f32, f32);
    s32 next_state;
    void *anim;
    f32 start;
    s32 flags;

    anim = baanim_getAnimCtrlPtr(arg0);
    if (bastick_getZone(arg0) == 0 && bastick_distance(arg0) > 0.0f) {
        ((s32 *)arg0)[0x168 / 4] = 1;
        yaw_setUpdateType(arg0, 3);
        yaw_setVelocityBounded(arg0, 200.0f, 14.0f);
    } else {
        if (((s32 *)arg0)[0x168 / 4] != 0) {
            yaw_setIdeal(arg0, yaw_get(arg0));
        }
        ((s32 *)arg0)[0x168 / 4] = 0;
        yaw_setUpdateType(arg0, 1);
    }
    next_state = func_80800038_bsstand(arg0, 0);
    flags = *(u8 *)(((s32 *)arg0)[0x15C / 4] + func_80800000_bsstand((s32 *)arg0));
    if (flags & 8) {
        if (flags & 4) {
            if (anctrl_isAt(anim, 0.0909f)) {
                func_8009D874(arg0);
            }
            if (anctrl_isAt(anim, 0.0909f)) {
                func_800A0CF4(arg0, 1);
            }
            if (anctrl_isAt(anim, 0.6818f)) {
                func_800A0CF4(arg0, 0);
            }
        }
        if (flags & 2) {
            if (anctrl_isAt(anim, 0.7727f)) {
                func_800A0CF4(arg0, 1);
            }
            if (anctrl_isAt(anim, 0.9999f)) {
                func_800A0CF4(arg0, 0);
            }
        }
    } else if (flags & 0x20) {
        if (anctrl_getIndex(anim) == 0x95) {
            func_80800274_bsstand(arg0, anim);
            if (anctrl_isAt(anim, 0.37f)) {
                anctrl_reset(anim);
                func_8008B1C8(anim, 0.1f);
                anctrl_setIndex(anim, 0xF6);
                anctrl_setDuration(anim, 5.0f);
                anctrl_setPlaybackType(anim, 1);
                anctrl_start(anim);
            }
        } else {
            if (anctrl_isAt(anim, 0.069f)) {
                func_8009DF94(arg0, 0x434, 1.4f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.1677f)) {
                func_8009DF94(arg0, 0x4454, 1.0f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.2441f)) {
                func_8009DF94(arg0, 0x4454, 1.03f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.3141f)) {
                func_8009DF94(arg0, 0x4454, 1.06f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.3859f)) {
                func_8009DF94(arg0, 0x4454, 1.5f, 0x7D00);
            }
            if (anctrl_isAt(anim, 0.414f)) {
                func_8009DF18(arg0, 0x41E, 1.0f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.6187f)) {
                func_8009DF94(arg0, 0x445B, 1.7f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.7108f)) {
                func_8009DF94(arg0, 0x445B, 1.6f, 0x4650);
            }
            if (anctrl_isAt(anim, 0.7927f)) {
                func_8009DF94(arg0, 0x445B, 1.5f, 0x4650);
            }
        }
    } else if (flags & 0x10) {
        func_80800274_bsstand(arg0, anim);
    }
    if (anctrl_isAt(anim, 0.9999f)) {
        ((s32 *)arg0)[0x15C / 4] = func_80800018_bsstand(arg0, ((s32 *)arg0)[0x15C / 4]);
        flags = *(u8 *)(((s32 *)arg0)[0x15C / 4] + func_80800000_bsstand((s32 *)arg0));
        if (flags & 0x10) {
            baanim_playForDuration_onceSmooth(arg0, 0x95, 5.5f);
            anctrl_start(anim);
            func_800A0CF4(arg0, 1);
            func_80090A2C(arg0);
        } else if (flags & 0x40) {
            baanim_playForDuration_onceSmooth(arg0, 0xAE, 4.3f);
            anctrl_start(anim);
            func_800A0CF4(arg0, 0);
            func_80090A2C(arg0);
        } else if (flags & 0x20) {
            baanim_playForDuration_onceSmooth(arg0, 0x95, 5.5f);
            func_800A0CF4(arg0, 1);
            func_80090A2C(arg0);
        } else if (flags & 8) {
            if (anctrl_getIndex(anim) == 0x6F) {
                start = anctrl_getAnimTimer(anim);
            } else {
                start = 0.0f;
                func_800909CC(arg0);
            }
            anctrl_reset(anim);
            anctrl_setIndex(anim, 0x6F);
            anctrl_setDuration(anim, 5.5f);
            anctrl_setPlaybackType(anim, 2);
            anctrl_setStart(anim, start);
            anctrl_start(anim);
            func_800A0CF4(arg0, 0);
        }
    }
    if (func_8008DD04(arg0)) {
        next_state = 0x2F;
    }
    bs_setState(arg0, next_state);
}

void bsstand_entrypoint_2(PlayerState *arg0) {
    s32 func_800A0CF4(PlayerState *, s32);
    s32 func_80090A2C();
    void func_800951B4(void* mem);
    func_800A0CF4(arg0, 0);
    func_80090A2C(arg0);
    func_800951B4(arg0);
}

s32 bsstand_entrypoint_3(s32 arg0) {
    extern s32 D_80800D98_bsstand[];
    return ((s32 *)&D_80800D98_bsstand)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stand/bsstand_entrypoint_5.s")

void bsstand_entrypoint_6(s32 arg0) 
{
}
s32 bsstand_entrypoint_7(s32 arg0) {
    extern s32 D_80800DA8_bsstand[];
    return ((s32 *)&D_80800DA8_bsstand)[arg0];
}

void bsstand_entrypoint_8()
{
    func_80800038_bsstand();
}

void bsstand_entrypoint_9()
{
    _bsdrone_entrypoint_0();
}

void bsstand_entrypoint_10(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void bsstand_entrypoint_11(s32 arg0)
{
    _bafpctrl_entrypoint_10(arg0,0);
    _bsdrone_entrypoint_2(arg0);
}

s32 bsstand_entrypoint_12(s32 arg0) {
    extern s32 D_80800DB8_bsstand[];
    return ((s32 *)&D_80800DB8_bsstand)[arg0];
}
