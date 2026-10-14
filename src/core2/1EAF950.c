#include "core2/1EAF950.h"
struct Unk800C7A68;

extern s32 D_8012BE70;

s32 func_800D6060(s32 arg0) {
    void aligned4_memmove(void *, void *, int);
    extern u8 D_8012B800[];
    extern s16 D_8012BE62;
    s32 mid;
    u32 size = 12;
    {
    u32 value;
    s32 high;
    s32 low;

    high = D_8012BE62 - 1;
    mid = 0;
    low = 0;
    while (high >= low) {
        mid = (high + low) >> 1;
        value = *(u32 *)(D_8012B800 + mid * size + 8);
        if ((s32)(value >> 18) < arg0) {
            low = mid + 1;
            if (low < D_8012BE62) {
                if (arg0 < (s32)(*(u32 *)(D_8012B800 + low * size + 8) >> 18)) {
                    mid = low;
                    break;
                }
            } else {
                mid = D_8012BE62;
                break;
            }
        } else {
            high = mid - 1;
            if (high >= 0) {
                if ((s32)(*(u32 *)(D_8012B800 + high * size + 8) >> 18) < arg0) {
                    break;
                }
            } else {
                mid = 0;
                break;
            }
        }
    }
    }
    if (mid < 0) {
        mid = 0;
    } else if (D_8012BE62 < mid) {
        mid = D_8012BE62;
    }
    if (mid < D_8012BE62) {
        s32 remaining = D_8012BE62 - mid;
        aligned4_memmove(D_8012B800 + mid * size + size, D_8012B800 + mid * size, remaining * size);
    }
    return mid;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D61B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D62E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6550.s")

void func_800D66AC(void) {
    extern s16 D_8011B910;
    extern u8 D_8012B800[];
    extern u8 D_8012BE60[];
    extern s16 D_8012BE62;
    struct Entry {
        u32 unused : 27;
        u32 flags : 4;
        u32 low : 1;
        s32 value;
        u16 index : 14;
        u16 low2 : 2;
        s16 tail;
    } *ptr;

    s32 i;

    ptr = (struct Entry *)D_8012B800;
    for (i = 0; i < 136; i++) {
        ptr[i].flags = 0;
        ptr[i].index = -1;
        ptr[i].value = 0;
    }
    D_8011B910 = -1;
    D_8012BE62 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D674C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6B0C.s")

/* extern */

s32 func_800D6C34(void) {
    s32 func_800D6254();
    if (func_800D6254() != -1) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6E54.s")

s32 func_800D7050(s32 arg0, s32 arg1) {
    extern u8 D_8012B800[];
    struct Entry {
        u8 pad[10];
        u16 upper : 4;
        u16 rest : 12;
    };
    struct Entry *temp_v0;
    struct Entry *temp_v0_2;
    if (arg1 != 0) {
        temp_v0_2 = (struct Entry *)D_8012B800 + arg0;
        temp_v0_2->upper++;
        return (s32) temp_v0_2;
    }
    temp_v0 = (struct Entry *)D_8012B800 + arg0;
    temp_v0->upper--;
    return (s32) temp_v0;
}

void func_800D70D0(s32 arg0) {
    s32 func_800D7050(s32, s32);
    extern s16 D_8011B910;
    func_800D7050(D_8011B910, arg0);
}

s32 func_800D70F8(s32 arg0, s32 arg1) {
    s32 func_800D6254(s32);
    s32 func_800D7050(s32, s32);
    s32 temp_v0;

    temp_v0 = func_800D6254(arg0);
    if (temp_v0 != -1) {
        func_800D7050(temp_v0, arg1);
        return 1;
    }
    return 0;
}

u32 func_800D7138(void) {
    s32 func_800D6254();
    extern u8 D_8012B80A[];
    s32 temp_v0;

    temp_v0 = func_800D6254();
    if (temp_v0 != -1) {
        return (u32) *(u16 *) (D_8012B80A + (temp_v0 * 0xC)) >> 0xC;
    }
    return -1U;
}

s32 func_800D7184(s32 arg0, s32 arg1) {
    extern u8 D_8012B800[];
    struct Entry {
        u8 pad[10];
        u8 upper : 4;
        u8 count : 4;
        u8 tail;
    };
    struct Entry *temp_v0;
    struct Entry *temp_v0_2;
    if (arg1 != 0) {
        temp_v0_2 = (struct Entry *)D_8012B800 + arg0;
        temp_v0_2->count++;
        return (s32) temp_v0_2;
    }
    temp_v0 = (struct Entry *)D_8012B800 + arg0;
    temp_v0->count--;
    return (s32) temp_v0;
}

void func_800D71F4(s32 arg0) {
    s32 func_800D7184(s32, s32);
    extern s16 D_8011B910;
    func_800D7184(D_8011B910, arg0);
}

s32 func_800D721C(s32 arg0, s32 arg1) {
    s32 func_800D6254(s32);
    s32 func_800D7184(s32, s32);
    s32 temp_v0;

    temp_v0 = func_800D6254(arg0);
    if (temp_v0 != -1) {
        func_800D7184(temp_v0, arg1);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D725C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D731C.s")

void func_800D738C()
{
    func_800D58FC();
}

void func_800D73AC()
{
    func_800D59C0();
}

/* extern */

s32 func_800D73CC(void) {
    s32 func_800D6254();
    s32 var_v1;

    if (func_800D6254() == -1) {
        var_v1 = 0;
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void * func_800D7400(void) {
    return &D_8012BE70;
}

void func_800D740C(void)
{
    extern s32 D_8012BFFC;

    D_8012BFFC = 0;
}

void func_800D7418()
{
    _glsplineDll_entrypoint_0(&D_8012BE70);
}

void func_800D743C()
{
    _glsplineDll_entrypoint_1(&D_8012BE70);
}

void func_800D7460()
{
    func_800D743C();
    func_800D7418();
}

/* extern */

s32 func_800D7488(s16 arg0, s16 arg1) {
    void *func_8001B710(s16, s32);
    s16 *sp1C;
    s32 temp_t7;
    s16 *temp_v0;

    ++(*(s32 *)((s8 *)(&D_8012BE70) + (0x188)));
    sp1C = func_8001B710((*(s16 *)((s8 *)(&D_8012BE70) + (0x184))), (*(s32 *)((s8 *)&D_8012BE70 + 0x188)) * 2);
    temp_v0 = func_8001B710((*(s16 *)((s8 *)(&D_8012BE70) + (0x186))), (*(s32 *)((s8 *)(&D_8012BE70) + (0x188))) * 2);
    sp1C[(*(s32 *)((s8 *)&D_8012BE70 + 0x188)) - 1] = arg0;
    temp_v0[(*(s32 *)((s8 *)&D_8012BE70 + 0x188)) - 1] = arg1;
    return (*(s32 *)((s8 *)(&D_8012BE70) + (0x188))) - 1;
}

void *func_800D7520(s32 arg0) { void *func_8001B798(s16); extern s16 D_8012BFF4; if (arg0 == -1) { return NULL; } return func_8001B798(*(s16 *)((s8 *)func_8001B798(D_8012BFF4) + arg0 * 2)); }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D75DC.s")

f32 func_800D7708(s32 arg0, f32 arg1, s32 arg2) {
    void *func_800D7520(s32);
    f32 func_800C7AE4(void *, f32, f32);
    return func_800C7AE4(func_800D7520(arg0), arg1, 1.0f) / ((f32)arg2 / 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7754.s")

void func_800D7900(s32 arg0) 
{
}
void func_800D7908(void *arg0, f32 *arg1) { void func_800A516C(f32 *, f32 *, f32 *); f32 sp1C[3]; func_800A516C(sp1C, arg1, (f32 *)((u8 *)arg0 + 4)); *(f32 *)((u8 *)arg0 + 0x54) = sp1C[1]; *(f32 *)((u8 *)arg0 + 0x50) = sp1C[0]; }

void func_800D7948(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct {
        u8 unused[0x44];
        f32 pitch, yaw, roll, idealPitch, idealYaw;
    } Object;
    typedef struct {
        s32 unused0:21;
        s32 path:10;
        u32 unused1:1;
        f32 unused4[2];
        f32 time;
        f32 unused10;
        f32 speed;
        u32 unused18[3];
        u32 unused24:18;
        u32 player:1;
        u32 unused25:4;
        u32 target:3;
        u32 unused26:6;
        u32 unused28:26;
        u32 actor:6;
        u32 unused2C;
        f32 speedStart;
        f32 speedEnd;
        f32 start;
        f32 end;
        u32 yawEnd:9;
        u32 yawStart:9;
        u32 pitchStart:9;
        u32 unused40:5;
        u32 globalTime:1;
        u32 mode:2;
        u32 pitchEnd:9;
        u32 unused44:20;
    } PathState;
    typedef struct {
        u32 unused:1;
        u32 fixed:1;
        u32 rest:30;
        u32 unused4;
        s16 **actor;
    } Target;
    void *func_80105494(Actor *);
    void func_800C810C(void *, f32, f32 *, f32 *);
    void func_800D7908(void *, f32 *);
    void func_8008FE68(f32 *);
    void *func_80106790(s32);
    f32 func_800136E4(f32);
    f32 func_800F1DCC(f32, f32);
    extern s32 D_8012BF70[];
    extern f32 D_8012C000;
    extern s32 *D_8012C014;
    PathState *state;
    f32 position[3];
    f32 rotation[3];
    s32 i;
    f32 targetPosition[3];
    Target *target;
    Object *object;
    f32 playerPosition[3];
    f32 time;
    f32 fraction;

    object = arg0;
    state = func_80105494(object);
    if (arg1 & 0x300) {
        func_800C810C(func_800D7520(state->path), state->time, position, rotation);
        if (arg1 & 1) {
            if (arg1 & 0x100) {
                object->idealYaw = rotation[1];
            }
            if (arg1 & 0x200) {
                object->idealPitch = rotation[0];
            }
        } else {
            if (arg1 & 0x100) {
                if (rotation[1] >= 180.0f) {
                    object->idealYaw = rotation[1] - 180.0f;
                } else {
                    object->idealYaw = rotation[1] + 180.0f;
                }
            }
            if (arg1 & 0x200) {
                object->idealPitch = 360.0f - rotation[0];
            }
        }
    }
    if (state->target) {
        target = (Target *)D_8012C014 + state->target - 1;
        if (target->fixed) {
            for (i = 0; i != 3; i++) {
                targetPosition[i] = ((s16 *)target)[i + 1];
            }
        } else {
            for (i = 0; i != 3; i++) {
                targetPosition[i] = (*target->actor)[i + 2];
            }
        }
        func_800D7908(object, targetPosition);
    } else if (state->actor) {
        func_800D7908(object, (f32 *)((u8 *)func_80106790(D_8012BF70[state->actor]) + 4));
    } else if (state->player) {
        func_8008FE68(playerPosition);
        func_800D7908(object, playerPosition);
    } else {
        time = state->globalTime ? D_8012C000 : state->time;
        if (time >= state->start && time < state->end) {
            fraction = (time - state->start) / (state->end - state->start);
            if (state->mode & 1) {
                if (arg1 & 0x800) {
                    object->idealYaw = func_800136E4(func_800F1DCC(state->yawEnd, state->yawStart) * fraction + state->yawStart);
                }
                if (arg1 & 0x1000) {
                    object->idealPitch = func_800136E4(func_800F1DCC(state->pitchEnd, state->pitchStart) * fraction + state->pitchStart);
                }
            }
            if (state->mode & 2) {
                state->speed = (state->speedEnd - state->speedStart) * fraction + state->speedStart;
            }
        } else if (0.0f != state->start || 0.0f != state->end) {
            state->globalTime = 0;
            state->end = state->start = 0;
        }
    }
    func_800D7900((s32)object);
    object->yaw = object->idealYaw;
    object->pitch = object->idealPitch;
}

s32 func_800D7DE8(Actor *arg0) { typedef struct { u32 pad[9]; u32 unused:16; u32 flag:1; u32 flag2:1; u32 rest:14; } State; void *func_80105494(Actor *); s32 var_a0; s32 var_v1; State *temp_v0; temp_v0 = func_80105494(arg0); if (temp_v0->flag) { var_a0 = 0x800; } else { var_a0 = 0x100; } var_v1 = temp_v0->flag2 ? 0x1000 : 0x200; return var_v1 + var_a0; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7E38.s")

s32 func_800D8070(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct {
        s32 unused0:21;
        s32 path:10;
        u32 initialized:1;
        f32 unused4[2];
        f32 time;
        f32 previousTime;
        f32 speed;
        u32 unused18:1;
        u32 realTime:1;
        u32 unused19:30;
        u32 unused1C;
        f32 delay;
        u32 unused24:19;
        u32 pause:4;
        u32 unused25:9;
        u32 unused28:6;
        u32 condition:8;
        u32 unused29:2;
        u32 flag:9;
        u32 clearFlag:1;
        u32 actor:6;
        f32 pod;
    } PathState;
    s32 _capod_entrypoint_16(f32);
    f32 _glintrosyncDll_entrypoint_5(void);
    s32 _seqdefine_entrypoint_0(s32);
    void *func_8001B798(s16);
    void func_800C7A68(struct Unk800C7A68 *, f32, s32);
    f32 func_800C7E28(void *);
    f32 func_800C8070(s32, f32, f32, s32 *);
    s32 func_800D75DC(s32, f32);
    s32 func_800D7DE8(Actor *);
    s32 func_800D7E38(void *, s32, s32, s32, s32, s32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    void *func_80105494();
    extern u8 D_8012BE6F[];
    extern s16 D_8012BFF4;
    extern s32 D_8012BFFC;
    s32 start;
    s32 end;
    s32 wrapped;
    PathState *state;
    f32 speed;
    s32 path;
    s32 node;
    s32 oldFlags;
    s32 newFlags;
    f32 delta;
    f32 duration;

    wrapped = 0;
    state = func_80105494();
    speed = state->speed;
    if (state->path == -1) {
        return 0;
    }
    state->previousTime = state->time;
    start = func_800D75DC(state->path, state->time);
    if (0.0f == state->delay && state->pause == 0 && state->flag == 0 && state->condition == 0 && 0.0f == state->pod) {
        path = func_8001B798(((s16 *)func_8001B798(D_8012BFF4))[state->path]);
        state->time = func_800C8070(path, state->time, speed, &wrapped);
        func_800C7A68(path, state->time, (f32 *)arg0 + 1);
    } else {
        if (0.0f != state->delay) {
            delta = state->realTime ? _glintrosyncDll_entrypoint_5() : func_800D8FF8();
            state->delay -= delta;
            if (state->delay < 0.0f) {
                state->delay = 0.0f;
            }
        }
        if (state->flag != 0 && func_800DA298(_seqdefine_entrypoint_0(state->flag - 1))) {
            if (state->clearFlag) {
                state->clearFlag = 0;
                func_800DA524(_seqdefine_entrypoint_0(state->flag - 1));
            }
            state->flag = 0;
        }
        if (state->condition != 0 && D_8012BE6F[state->condition] == 0) {
            state->condition = 0;
        }
        if (state->pod > 0.0f && _capod_entrypoint_16(state->pod)) {
            state->pod = 0.0f;
        }
    }
    end = func_800D75DC(state->path, state->time);
    if (!state->initialized) {
        state->initialized = 1;
        ((f32 *)arg0)[0x48 / 4] = ((f32 *)arg0)[0x54 / 4];
        ((f32 *)arg0)[0x44 / 4] = ((f32 *)arg0)[0x50 / 4];
    }
    if (start == end && wrapped == 0) {
        func_800D7948(arg0, arg1, arg2, arg3);
    } else {
        oldFlags = func_800D7DE8(arg0);
        if (speed > 0.0f) {
            if (wrapped == 0) {
                if (func_800D7E38(arg0, state->path, start, end, 0, 1) == 2) {
                    D_8012BFFC = 1;
                }
            } else if (func_800D7E38(arg0, state->path, start, -9999, 0, 1) == 0) {
                duration = func_800C7E28(func_800D7520(state->path));
                node = func_800D75DC(state->path, duration);
                func_800D7E38(arg0, state->path, node, end, 0, 1);
            }
        } else if (speed < 0.0f) {
            if (wrapped == 0) {
                func_800D7E38(arg0, state->path, start - 1, end - 1, 0, -1);
            } else if (func_800D7E38(arg0, state->path, start - 1, -1, 0, -1) == 0) {
                func_800D7E38(arg0, state->path, -9999, end - 1, 0, -1);
            }
        }
        newFlags = func_800D7DE8(arg0);
        if (oldFlags == newFlags || (oldFlags != newFlags && oldFlags != (arg1 & 0x3F00))) {
            func_800D7948(arg0, arg1, arg2, arg3);
        } else {
            func_800D7948(arg0, (arg1 & ~0x3F00) | (newFlags & 0x3F00), arg2, arg3);
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D8588.s")

void func_800D8648(s32 arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8((f32 *)((u8 *)func_800D7520(arg0) + 0x14), arg1);
}

/* extern */

void func_800D8674(void) {
    s32 defrag(s32);
    s32 i;

    if ((*(s32 *)((s8 *)(&D_8012BE70) + (0x1A4))) != 0) {
        (*(s32 *)((s8 *)(&D_8012BE70) + (0x1A4))) = defrag((*(s32 *)((s8 *)(&D_8012BE70) + (0x1A4))));
    }
    for (i = 0; i < (*(s32 *)((s8 *)(&D_8012BE70) + (0x188))); i++) {
    }
    if ((*(s32 *)((s8 *)(&D_8012BE70) + (0x19C))) != 0) {
        (*(s32 *)((s8 *)(&D_8012BE70) + (0x19C))) = defrag((*(s32 *)((s8 *)(&D_8012BE70) + (0x19C))));
    }
}

void func_800D86F0(s32 arg0, f32 arg1, s32 arg2) {
    void *func_8001B798(s16);
    void func_800C7A68(struct Unk800C7A68 *, f32, s32);
    extern s16 D_8012BFF4;
    func_800C7A68(func_8001B798(((s16 *)func_8001B798(D_8012BFF4))[arg0]), arg1, arg2);
}

void func_800D8744(void) {
    f32 _glintrosyncDll_entrypoint_5();
    f32 func_800D8FF8();
    extern f32 D_8012C000;
    f32 var_f0;

    (*(f32 *)((s8 *)(&D_8012BE70) + (0x194))) = (f32) (*(f32 *)((s8 *)(&D_8012BE70) + (0x190)));
    if ((*(u8 *)((s8 *)(&D_8012BE70) + (0x1A8))) != 0) {
        var_f0 = _glintrosyncDll_entrypoint_5();
    } else {
        var_f0 = func_800D8FF8();
    }
    D_8012C000 = (*(f32 *)((s8 *)(&D_8012BE70) + (0x190))) + (var_f0 * 60.0f);
}

void func_800D87B0()
{
    _glsplineDll_entrypoint_2(&D_8012BE70);
}

void func_800D87D4(s32 *arg0, s32 arg1) {
    extern s32 D_8012BF70[];
    D_8012BF70[arg1] = *arg0;
}

s32 func_800D87EC(s32 arg0) {
    extern s32 D_8012BF70[];
    return ((s32 *)&D_8012BF70)[arg0];
}

void func_800D8800(void) {
}

void func_800D8808(s32 arg0) {
    extern s32 *D_8012C014;

    if (arg0 != 0) {
        ((s8 *)D_8012C014)[arg0 * 12 - 12] &= 0xFF7F;
    }
}
