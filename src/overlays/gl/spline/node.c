#include "common.h"
#ifdef BT_NATIVE
#include "native_spline.h"
#include "native_actor.h"
#define SPLINE_VECTOR(v) (v)
#define NODE_BYTE(node, offset) ((u8)(((u32 *)(node))[(offset) / 4] >> (24 - 8 * ((offset) % 4))))
#else
#define SPLINE_VECTOR(v) (&v)
#define SPLINE_ACTOR(actor, field, original) (original)
#define NODE_BYTE(node, offset) (*(u8 *)((node) + (offset)))
#endif

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
        struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low:1; u32 type:3; u32 playback:3; u32 pitch:9; u32 interp:2; u32 mode:2; u32 unused:1; u32 link:11;
#else
u32 link:11, unused:1, mode:2, interp:2, pitch:9, playback:3, type:3, low:1;
#endif
} bits;
        struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low:16; u32 duration:15; u32 mode:1;
#else
u32 mode:1, duration:15, low:16;
#endif
} wait;
    } NodeWord4;
    typedef union {
        u32 word;
        u8 byte[4];
        struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low:8; u32 param:1; u32 speed:1; u32 animate:1; u32 duration:11; u32 sequence:10;
#else
u32 sequence:10, duration:11, animate:1, speed:1, param:1, low:8;
#endif
} bits;
    } NodeWord8;
    typedef union {
        u32 word;
        u8 byte[4];
        struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 special:1; u32 spline:11; u32 unused12:1; u32 state:8; u32 dialog:1; u32 unused:2; u32 mode:8;
#else
u32 mode:8, unused:2, dialog:1, state:8, unused12:1, spline:11, special:1;
#endif
} flags;
        struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low:12; u32 speed:11; u32 yaw:9;
#else
u32 yaw:9, speed:11, low:12;
#endif
} movement;
        struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low:1; u32 param:11; u32 high:20;
#else
u32 high:20, param:11, low:1;
#endif
} value;
    } NodeWordC;
    typedef union {
        u32 word;
        u8 byte[4];
        struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low:3; u32 wait:1; u32 dialog:6; u32 unused:11; u32 link:11;
#else
u32 link:11, unused:11, dialog:6, wait:1, low:3;
#endif
} bits;
        struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low:7; u32 param:1; u32 high:24;
#else
u32 high:24, param:1, low:7;
#endif
} flags;
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
            struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low:1; s32 spline:10; u32 count:13; u32 mode:8;
#else
u32 mode:8, count:13; s32 spline:10; u32 low:1;
#endif
} bits;
        } first;
        f32 timer, elapsed, position, unused10, speed, unused18, duration, param;
        union {
            u32 word;
            struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low:6; u32 flags:3; u32 param:4; u32 disabled:1; u32 pitch:1; u32 yaw:1; u32 unused16:1; u32 animation:15;
#else
u32 animation:15, unused16:1, yaw:1, pitch:1, disabled:1, param:4, flags:3, low:6;
#endif
} bits;
        } w24;
        union {
            u32 word;
            struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 flags:6; u32 unused:20; u32 direction:2; u32 flag:1; u32 mode:3;
#else
u32 mode:3, flag:1, direction:2, unused:20, flags:6;
#endif
} bits;
        } w28;
        f32 unused2c, startSpeed, endSpeed, start, end;
        union {
            u32 word;
            struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low:5; u32 pitch:9; u32 yaw:9; u32 endYaw:9;
#else
u32 endYaw:9, yaw:9, pitch:9, low:5;
#endif
} bits;
        } w40;
        struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low:20; u32 pitch:9; u32 mode:2; u32 flag:1;
#else
u32 flag:1, mode:2, pitch:9, low:20;
#endif
} w44;
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

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 unused7a:16; u32 waitState:2; u32 unused78:14;
#else
u32 unused78:14, waitState:2, unused7a:16;
#endif
u8 unused7c[0x114];
        f32 time;
    } SplineActor;
    struct anctrl_s;
#ifndef BT_NATIVE
    s32 _glsplinefuncs_entrypoint_0(s32, s32 *, f32 *, void *, s32, f32 *, f32 *);
#endif
    s32 _seqdat_entrypoint_0(s32, s32);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void func_8008B188(struct anctrl_s *, s32);
#ifdef BT_NATIVE
    s32 func_800C04C8(s32, s32, s32, s32, void (*)(s32, s32, s32));
#else
    s32 func_800C04C8(s32, s32, s32, s32, s32 *);
#endif
#ifdef BT_NATIVE
    f32 func_800C7AE4(void *, f32, f32);
#else
    f32 func_800C7AE4(s32, f32, f32);
#endif
#ifdef BT_NATIVE
    void *func_800D7520(s32);
#else
    s32 func_800D7520(s32);
#endif
    f32 func_800D7708(s32, f32, s32);
#ifdef BT_NATIVE
    void func_800D7754(Actor *, s32);
#else
    s32 func_800D7754(u8 *, s32);
#endif
    void func_800DA3B8(s32, s32);
#ifdef BT_NATIVE
    void func_800EE7F8(void *, f32 *);
#else
    void func_800EE7F8(u8 *, f32 *);
#endif
    void func_80101D4C(Actor *);
    void func_80101D7C(Actor *);
    struct anctrl_s *func_80104248(void *);
    struct anctrl_s *func_801042B8(Actor *);
#ifndef BT_NATIVE
    Spline *func_80105494(Actor *);
#endif
    extern s16 D_808009B0_glsplinenode[];
#ifdef BT_NATIVE
    void _glsplinenode_entrypoint_0(s32, s32, s32);
#else
    extern s32 _glsplinenode_entrypoint_0;
#endif
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
#ifdef BT_NATIVE
    s32 jumped;
#endif
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
#ifdef BT_NATIVE
                sp7C->timer = ((NativeSplineContext *)arg0)->value0;
#else
                sp7C->timer = ((SplineActor *)arg0)->time;
#endif
                sp7C->first.bits.count = 0;
                sp7C->elapsed = 0.0f;
            }
            break;
        case 7: {
            mode = ((Node *)arg2)->w4.wait.mode;
            if ((((Node *)arg2)->w10.bits.wait) == 1) {
                if (mode == 0) {
#ifdef BT_NATIVE
                    arg1->unk79_1 = 1; arg1->unk79_0 = 0;
#else
                    ((SplineActor *)arg1)->waitState = 2;
#endif
                } else {
                    sp4C = (u8 *)arg1;
                    if (mode == 1) {
                        mode = 1;
                    } else {
                        mode = 0;
                    }
#ifdef BT_NATIVE
                    arg1->unk79_1 = (mode >> 1); arg1->unk79_0 = mode;
#else
                    ((SplineActor *)sp4C)->waitState = mode;
#endif
                }
                if (((Node *)arg2)->w4.wait.duration != 0) {
                    (*(f32 *)&SPLINE_ACTOR(arg1, actorData[0], ((SplineActor *)arg1)->wait)) = (f32)((Node *)arg2)->w4.wait.duration * 0.25f;
                } else {
                    (*(f32 *)&SPLINE_ACTOR(arg1, actorData[0], ((SplineActor *)arg1)->wait)) = 0.0f;
                }
                (*(f32 *)&SPLINE_ACTOR(arg1, actorData[1], ((SplineActor *)arg1)->elapsed)) = 0.0f;
            }
            if ((((Node *)arg2)->wc.flags.dialog) == 1) {
                func_800C04C8(((Node *)arg2)->wc.flags.state,
                    ((Node *)arg2)->w10.bits.dialog, NODE_BYTE(arg2, 6),
                    (u32)NODE_BYTE(arg2, 7) >> 4, &_glsplinenode_entrypoint_0);
            }
            break;
        }
        case 6:
#ifdef BT_NATIVE
            func_800DA3B8(((Node *)arg2)->w4.word >> 16, 1);
#else
            func_800DA3B8((*(u16 *)(arg2 + 4)), 1);
#endif
            break;
        }
        if ((((Node *)arg2)->wc.flags.spline) != 0) {
#ifdef BT_NATIVE
            jumped = _glsplinefuncs_entrypoint_0
#else
            arg2 = (u8 *)_glsplinefuncs_entrypoint_0
#endif
                (((Node *)arg2)->wc.flags.spline,
                &sp74, &sp68, SPLINE_VECTOR(sp5C), sp7C->first.bits.spline, &sp58, &sp54);
#ifdef BT_NATIVE
            if (!jumped) return sp78;
#endif
            sp78 = 2;
            sp7C->first.bits.spline = sp74;
            sp7C->position = sp68;
            func_800EE7F8(SPLINE_ACTOR(arg1, position, (u8 *)arg1 + 4), sp5C);
#ifdef BT_NATIVE
            if (jumped) {
#else
            if (arg2) {
#endif
#ifndef BT_NATIVE
                mode = (s32)arg1;
#endif
                if (sp58 != -9999.0f) {
                    SPLINE_ACTOR(arg1, rotation[1], ((SplineActor *)mode)->yaw) = sp58;
                    SPLINE_ACTOR(arg1, unk54, ((SplineActor *)mode)->targetYaw) = SPLINE_ACTOR(arg1, rotation[1], ((SplineActor *)mode)->yaw);
                }
#ifndef BT_NATIVE
                mode = (s32)*(Actor **)&arg1;
#endif
                if (sp54 != -9999.0f) {
                    SPLINE_ACTOR(arg1, rotation[0], ((SplineActor *)mode)->pitch) = sp54;
                    SPLINE_ACTOR(arg1, unk50, ((SplineActor *)mode)->targetPitch) = SPLINE_ACTOR(arg1, rotation[0], ((SplineActor *)mode)->pitch);
                }
            }
        }
    } else {
        if (NODE_BYTE(arg2, 0xA) & 1) {
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
        mode = NODE_BYTE(arg2, 0x12) & 1;
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
#ifdef BT_NATIVE
            while ((Node *)sp4C < end && ((Node *)sp4C)->w10.bits.link != link) {
#else
            while (((Node *)sp4C)->w10.bits.link != link && (Node *)sp4C < end) {
#endif
                sp4C += 0x14;
            }
#ifdef BT_NATIVE
            if ((Node *)sp4C == end) return sp78;
#endif
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
