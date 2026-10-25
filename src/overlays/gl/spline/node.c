#include "common.h"

/* extern */

void glsplinenode_entrypoint_0(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800D035C(s32);
    func_800D035C(1);
}

s32 glsplinenode_entrypoint_1(u8 *arg0, Actor *arg1, u8 *arg2, u8 *arg3) {
    typedef union {
        u32 word;
        u16 half[2];
        u8 byte[4];
        struct { u32 link:11, unused:1, mode:2, interp:2, pitch:9, playback:3, type:3, low:1; } bits;
        struct { u32 mode:1, duration:15, low:16; } wait;
    } NodeWord4;
    typedef union {
        u32 word;
        u8 byte[4];
        struct { u32 sequence:10, duration:11, animate:1, speed:1, param:1, low:8; } bits;
    } NodeWord8;
    typedef union {
        u32 word;
        u8 byte[4];
        struct { u32 mode:8, unused:2, dialog:1, state:8, unused12:1, spline:11, special:1; } flags;
        struct { u32 yaw:9, speed:11, low:12; } movement;
        struct { u32 high:20, param:11, low:1; } value;
    } NodeWordC;
    typedef union {
        u32 word;
        u8 byte[4];
        struct { u32 link:11, unused:11, dialog:6, wait:1, low:3; } bits;
        struct { u32 high:24, param:1, low:7; } flags;
    } NodeWord10;
    typedef struct {
        f32 position;
        NodeWord4 w4;
        NodeWord8 w8;
        NodeWordC wc;
        NodeWord10 w10;
    } Node;
    typedef struct { s32 count; Node nodes[1]; } NodeList;
    typedef struct {
        union {
            u32 word;
            struct { u32 mode:8, count:13; s32 spline:10; u32 low:1; } bits;
        } first;
        f32 timer, elapsed, position, unused10, speed, unused18, duration, param;
        union {
            u32 word;
            struct { u32 animation:15, unused16:1, yaw:1, pitch:1, disabled:1, param:4, flags:3, low:6; } bits;
        } w24;
        union {
            u32 word;
            struct { u32 mode:3, flag:1, direction:2, unused:20, flags:6; } bits;
        } w28;
        f32 unused2c, startSpeed, endSpeed, start, end;
        union {
            u32 word;
            struct { u32 endYaw:9, yaw:9, pitch:9, low:5; } bits;
        } w40;
        struct { u32 flag:1, mode:2, pitch:9, low:20; } w44;
    } Spline;
    typedef struct {
        u8 unused0[4];
        f32 position[3];
        u8 unused10[8];
        f32 wait, elapsed;
        u8 unused20[0x24];
        f32 pitch, yaw;
        u8 unused4c[4];
        f32 targetPitch, targetYaw;
        u8 unused58[0x20];
        u32 unused78:14, waitState:2, unused7a:16;
        u8 unused7c[0x114];
        f32 time;
    } SplineActor;
    struct anctrl_s;
    s32 _glsplinefuncs_entrypoint_0(s32, s32 *, f32 *, void *, s32, f32 *, f32 *);
    s32 _seqdat_entrypoint_0(s32, s32);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void func_8008B188(struct anctrl_s *, s32);
    s32 func_800C04C8(s32, s32, s32, s32, s32 *);
    f32 func_800C7AE4(s32, f32, f32);
    s32 func_800D7520(s32);
    f32 func_800D7708(s32, f32, s32);
    s32 func_800D7754(u8 *, s32);
    void func_800DA3B8(s32, s32);
    void func_800EE7F8(u8 *, f32 *);
    void func_80101D4C(Actor *);
    void func_80101D7C(Actor *);
    struct anctrl_s *func_80104248(void *);
    struct anctrl_s *func_801042B8(Actor *);
    Spline *func_80105494(Actor *);
    extern s16 D_808009B0_glsplinenode[];
    extern s32 _glsplinenode_entrypoint_0;
    Spline *sp7C;
    s32 sp78;
    s32 sp74;
    s32 link;
    Node *end;
    f32 sp68;
    f32 sp5C[3];
    f32 sp58;
    f32 sp54;
    struct anctrl_s *sp50;
    u8 *sp4C;
    s32 mode;
    register Actor *actor;

    sp7C = func_80105494(*(Actor **)&arg1);
    sp78 = 0;
    if ((*(u32 *)(arg2 + 0xC)) & 1) {
        switch (((Node *)arg2)->w4.bits.type) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            break;
        case 0:
            if (((Node *)arg2)->wc.flags.mode != 0) {
                sp7C->first.bits.mode = ((Node *)arg2)->wc.flags.mode;
                sp7C->timer = ((SplineActor *)arg0)->time;
                sp7C->first.bits.count = 0;
                sp7C->elapsed = 0.0f;
            }
            break;
        case 7: {
            mode = ((Node *)arg2)->w4.wait.mode;
            if ((((Node *)arg2)->w10.bits.wait) == 1) {
                if (mode == 0) {
                    ((SplineActor *)arg1)->waitState = 2;
                } else {
                    sp4C = (u8 *)arg1;
                    if (mode == 1) {
                        mode = 1;
                    } else {
                        mode = 0;
                    }
                    ((SplineActor *)sp4C)->waitState = mode;
                }
                if (((Node *)arg2)->w4.wait.duration != 0) {
                    ((SplineActor *)arg1)->wait = (f32)((Node *)arg2)->w4.wait.duration * 0.25f;
                } else {
                    ((SplineActor *)arg1)->wait = 0.0f;
                }
                ((SplineActor *)arg1)->elapsed = 0.0f;
            }
            if ((((Node *)arg2)->wc.flags.dialog) == 1) {
                func_800C04C8(((Node *)arg2)->wc.flags.state,
                    ((Node *)arg2)->w10.bits.dialog, (*(u8 *)(arg2 + 6)),
                    (u32)(*(u8 *)(arg2 + 7)) >> 4, &_glsplinenode_entrypoint_0);
            }
            break;
        }
        case 6:
            func_800DA3B8((*(u16 *)(arg2 + 4)), 1);
            break;
        }
        if ((((Node *)arg2)->wc.flags.spline) != 0) {
            arg2 = (u8 *)_glsplinefuncs_entrypoint_0(((Node *)arg2)->wc.flags.spline,
                &sp74, &sp68, &sp5C, sp7C->first.bits.spline, &sp58, &sp54);
            sp78 = 2;
            sp7C->first.bits.spline = sp74;
            sp7C->position = sp68;
            func_800EE7F8((u8 *)arg1 + 4, sp5C);
            if (arg2) {
                mode = (s32)arg1;
                if (sp58 != -9999.0f) {
                    ((SplineActor *)mode)->yaw = sp58;
                    ((SplineActor *)mode)->targetYaw = ((SplineActor *)mode)->yaw;
                }
                mode = (s32)*(Actor **)&arg1;
                if (sp54 != -9999.0f) {
                    ((SplineActor *)mode)->pitch = sp54;
                    ((SplineActor *)mode)->targetPitch = ((SplineActor *)mode)->pitch;
                }
            }
        }
    } else {
        if ((*(u8 *)(arg2 + 0xA)) & 1) {
            if (((Node *)arg2)->w10.flags.param) {
                sp7C->w24.bits.param = ((Node *)arg2)->wc.flags.spline - 0x69;
            } else {
                sp7C->param = ((Node *)arg2)->wc.value.param / (f32)4;
            }
        }
        if (((Node *)arg2)->w8.bits.animate) {
            sp50 = func_80104248(arg1);
            sp7C->duration = ((Node *)arg2)->w8.bits.duration / (f32)4;
            sp7C->w24.bits.animation = _seqdat_entrypoint_0(((Node *)arg2)->w8.bits.sequence, 0);
            if (sp50 == 0) {
                sp50 = func_801042B8(arg1);
                anctrl_reset(sp50);
            }
            anctrl_setIndex(sp50, sp7C->w24.bits.animation);
            anctrl_setDuration(sp50, sp7C->duration);
            func_8008B188(sp50, 1);
            if (sp50) {
                anctrl_start(sp50);
            }
        }
        func_800D7754(arg1, ((Node *)arg2)->w4.bits.playback);
        switch (((Node *)arg2)->w4.bits.type) {
        case 2:
            sp7C->w28.bits.direction = 0;
            sp7C->speed = sp7C->speed < 0.0f ? -sp7C->speed : sp7C->speed;
            func_80101D4C(arg1);
            break;
        case 3:
            sp7C->w28.bits.direction = 0;
            sp7C->speed = sp7C->speed < 0.0f ? sp7C->speed : -sp7C->speed;
            func_80101D4C(arg1);
            break;
        case 4:
            sp7C->w28.bits.direction = 1;
            sp7C->speed = sp7C->speed < 0.0f ? -sp7C->speed : sp7C->speed;
            func_80101D7C(arg1);
            break;
        case 5:
            sp7C->w28.bits.direction = 1;
            sp7C->speed = sp7C->speed < 0.0f ? sp7C->speed : -sp7C->speed;
            func_80101D7C(arg1);
            break;
        case 6:
            sp7C->w28.bits.direction = 2;
            break;
        }
        if ((((Node *)arg2)->w4.bits.mode) != 0) {
            sp7C->w28.bits.mode = D_808009B0_glsplinenode[((Node *)arg2)->w4.bits.mode];
        }
        mode = (*(u8 *)(arg2 + 0x12)) & 1;
        if (mode != sp7C->w28.bits.flag) {
            sp7C->w28.bits.flag = mode;
        }
        if (((Node *)arg2)->w8.bits.speed) {
            sp7C->speed = func_800D7708(sp7C->first.bits.spline,
                sp7C->position, ((Node *)arg2)->wc.movement.speed);
        }
        if (((Node *)arg2)->w4.bits.link != 0) {
            end = (Node *)(((NodeList *)arg3)->count * 0x14 + arg3 + 4);
            sp4C = (u8 *)((NodeList *)arg3)->nodes;
            link = ((Node *)arg2)->w4.bits.link;
            while (((Node *)sp4C)->w10.bits.link != link && (Node *)sp4C < end) {
                sp4C += 0x14;
            }
            sp7C->w44.mode = ((Node *)arg2)->w4.bits.interp;
            sp7C->w44.flag = 0;
            sp7C->start = (*(f32 *)(arg2 + 0));
            sp7C->end = (*(f32 *)(sp4C + 0));
            if (((Node *)arg2)->w4.bits.interp & 1) {
                actor = (Actor *)arg1;
                sp7C->w40.bits.yaw = ((Node *)arg2)->wc.movement.yaw;
                sp7C->w40.bits.endYaw = ((Node *)sp4C)->wc.movement.yaw;
                sp7C->w40.bits.pitch = ((Node *)arg2)->w4.bits.pitch;
                sp7C->w44.pitch = ((Node *)sp4C)->w4.bits.pitch;
                actor->rotation[1] = actor->unk54 = (f32)(sp7C->w40.bits.yaw);
                actor->rotation[0] = actor->unk50 = (f32)(sp7C->w40.bits.pitch);
            }
            /* Keep the link live through the rotation update for IDO register allocation. */
            if (link > 0) {}
            if (((Node *)arg2)->w4.bits.interp & 2) {
                sp7C->startSpeed = sp7C->speed;
                sp7C->endSpeed = func_800C7AE4(func_800D7520(sp7C->first.bits.spline), (*(f32 *)(sp4C + 0)), 1.0f)
                    / (((Node *)sp4C)->wc.movement.speed / (f32)4);
            }
        }
        actor = (Actor *)arg1;
        if (!sp7C->w24.bits.disabled && !sp7C->w28.bits.flags && !sp7C->w24.bits.flags) {
            if (sp7C->w24.bits.yaw) {
                actor->unk54 = (f32)((*(u32 *)(arg2 + 0xC)) >> 23);
            }
            if (sp7C->w24.bits.pitch) {
                actor->unk50 = (f32)(((Node *)arg2)->w4.bits.pitch);
            }
        }
    }
    return sp78;
}
