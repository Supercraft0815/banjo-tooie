#include "common.h"

void func_8080050C_chdoor(Actor *);

void chdoor_entrypoint_0(s32 arg0)
{
    func_80800028_chdoor();
    func_8080050C_chdoor(arg0);
}
int func_80800028_chdoor(u8 *arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    u8 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_8010108C();
    void func_8080032C_chdoor(u8 *, f32);
    void func_8080069C_chdoor(Actor *, s32);
    void func_80800754_chdoor(u8 *);
    void func_808008A0_chdoor(u8 *);
    void func_80800B14_chdoor(u8 *, s32);
    u8 *data;

    data = func_80100094(arg0, 0);
    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
    case 1:
        if (*(s32 *)data & 4) {
            if (func_800DA298(*(s16 *)(data + 4))) {
                func_80800754_chdoor(arg0);
            }
        } else {
            s32 cutscene = data[0x20];
            if (cutscene && _glcutDll_entrypoint_19(cutscene)) {
                func_80800754_chdoor(arg0);
            }
        }
        break;
    case 2:
        if (func_800D9078((f32 *)(arg0 + 0x58))) {
            func_80800B14_chdoor(arg0, 3);
        }
        break;
    case 3: {
        f32 oldOpen;
        s32 openDone;
        oldOpen = *(f32 *)(arg0 + 0x58);
        openDone = func_800D9078((f32 *)(arg0 + 0x58));
        func_8080032C_chdoor(arg0, func_800F12D4(*(f32 *)(arg0 + 0x58), 0.0f,
            (f32)*(s16 *)(data + 0xA) * 0.00390625f, 1.0f, 0.0f));
        if (oldOpen >= 0.2f && *(f32 *)(arg0 + 0x58) < 0.2f) {
            func_8080069C_chdoor(arg0, 1);
        }
        if (openDone) {
            func_80800B14_chdoor(arg0, 4);
            func_8010108C(arg0, 0x9D, 0);
        }
        break;
    }
    case 4:
        if (*(s32 *)data & 2) {
            if (*(s32 *)data & 4) {
                if (!func_800DA298(*(s16 *)(data + 4))) {
                    func_808008A0_chdoor(arg0);
                }
            } else {
                s32 cutscene = data[0x28];
                if (cutscene && _glcutDll_entrypoint_19(cutscene)) {
                    func_808008A0_chdoor(arg0);
                }
            }
            if (*(s32 *)data & 0x400) {
                func_808008A0_chdoor(arg0);
            }
        }
        break;
    case 5:
        if (func_800D9078((f32 *)(arg0 + 0x58))) {
            func_80800B14_chdoor(arg0, 6);
        }
        break;
    case 6: {
        f32 fraction;
        f32 oldClose;
        s32 closeDone;
        oldClose = *(f32 *)(arg0 + 0x58);
        closeDone = func_800D9078((f32 *)(arg0 + 0x58));
        fraction = func_800F12D4(*(f32 *)(arg0 + 0x58), 0.0f,
            (f32)*(s16 *)(data + 0xA) * 0.00390625f, 0.0f, 1.0f);
        func_8080032C_chdoor(arg0, fraction);
        if (oldClose >= 0.2f && *(f32 *)(arg0 + 0x58) < 0.2f) {
            func_8080069C_chdoor(arg0, 0);
        }
        if (closeDone) {
            func_80800B14_chdoor(arg0, 1);
            func_8010108C(arg0, 0x9E, 0);
        }
        break;
    }
    }
}

void func_8080032C_chdoor(u8 *arg0, f32 arg1) {
    struct DoorMotionData {
        u32 flags;
        u32 unk4;
        u32 motion : 6;
        u32 other : 26;
        u32 unkC;
        s16 first;
        s16 second;
        s16 third;
        s16 destination[3];
        s16 roll;
    };
    s32 _subaddiefade_entrypoint_1(s32, s32);
    void _sudeflect_entrypoint_3(f32 *, f32 *, f32 *, f32 *, s32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EFE50(f32 *, void *, void *, f32);
    f32 func_800F1DCC(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80103014(u8 *);
    s32 func_80104004(Actor *, f32 *, f32 *);
    Actor *actor = (Actor *)arg0;
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    struct DoorMotionData *data;
    f32 sp44[3];
    f32 sp38[3];
    f32 angle;

    data = func_80100094(actor, 0);
    switch (data->motion) {
    case 1:
        angle = func_800F1DCC((f32)data->first, (f32)data->second);
        actor->rotation[1] = angle * arg1 + (f32)data->second;
        break;
    case 2:
        func_800EE88C(sp78, &data->first);
        func_800EE88C(sp6C, data->destination);
        func_800EFE50(actor->position, sp78, sp6C, arg1);
        break;
    case 3:
        angle = func_800F1DCC((f32)data->first, (f32)data->second);
        actor->rotation[0] = angle * arg1 + (f32)data->second;
        break;
    case 4:
        func_800EE88C(sp60, &data->first);
        func_800EE88C(sp54, data->destination);
        func_800EFE50(actor->position, sp60, sp54, arg1);
        actor->rotation[2] = data->roll * 0.00390625f * arg1;
        break;
    case 5:
        _subaddiefade_entrypoint_1(arg0, (s32)((1.0f - arg1) * 255.0f));
        break;
    }
    func_80103014(arg0);
    if (data->flags & 0x10000) {
        func_80104004(actor, sp44, sp38);
        _sudeflect_entrypoint_3(actor->position, actor->rotation, sp44, sp38, 2);
    }
}

void func_8080050C_chdoor(Actor *arg0) {
    struct DoorLoopSoundData {
        u8 pad[0x2E];
        s16 sound;
        s16 volume;
        s16 pitch;
    };
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    void *func_80100094(Actor *, u32);
    extern s32 D_808015B0_chdoor;
    struct DoorLoopSoundData *sp20;
    struct DoorLoopSoundData *data;
    s32 loop;

    loop = 0;
    data = func_80100094(arg0, 0);
    if (arg0->unk70_10 == 3 || arg0->unk70_10 == 6) {
        loop = 1;
    }
    if (data->sound != 0 && (loop != 0 || (loop == 0 && arg0->unk5F != 0))) {
        sp20 = data;
        func_800C4B7C(data->sound);
        func_800C4B70(sp20->volume);
        func_800C4B64((f32)sp20->pitch * 0.00390625f);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, loop, &D_808015B0_chdoor);
    }
}

void func_808005E4_chdoor(Actor *arg0, s32 arg1) {
    struct DoorSoundData {
        u8 pad[0x34];
        s16 opening;
        s16 closing;
        s16 sound;
        s16 volume;
        s16 pitch;
    };
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    void *func_80100094(Actor *, u32);
    extern s32 D_808015B0_chdoor;
    struct DoorSoundData *temp_v0;
    struct DoorSoundData *sp1C;

    temp_v0 = func_80100094(arg0, 0);
    if (temp_v0->sound != 0 && ((arg1 != 0 && temp_v0->opening != 0) || (arg1 == 0 && temp_v0->closing != 0))) {
        sp1C = temp_v0;
        func_800C4B7C(temp_v0->sound);
        func_800C4B70(sp1C->volume);
        func_800C4B64((f32)sp1C->pitch * 0.00390625f);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808015B0_chdoor);
    }
}

void func_8080069C_chdoor(Actor *arg0, s32 arg1) {
    struct DoorSoundData {
        u8 pad[0x3E];
        s16 opening;
        s16 closing;
        s16 sound;
        s16 volume;
        s16 pitch;
    };
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    void *func_80100094(Actor *, u32);
    extern s32 D_808015B0_chdoor;
    struct DoorSoundData *temp_v0;
    struct DoorSoundData *sp1C;

    temp_v0 = func_80100094(arg0, 0);
    if (temp_v0->sound != 0 && ((arg1 != 0 && temp_v0->opening != 0) || (arg1 == 0 && temp_v0->closing != 0))) {
        sp1C = temp_v0;
        func_800C4B7C(temp_v0->sound);
        func_800C4B70(sp1C->volume);
        func_800C4B64((f32)sp1C->pitch * 0.00390625f);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808015B0_chdoor);
    }
}

void func_80800754_chdoor(u8 *arg0) {
    struct DoorInitialData {
        u32 flags;
        u32 unused4;
        u32 mode : 6;
        u32 unused8 : 26;
        s16 state;
        s16 unusedE;
        s16 position[3];
        u8 unused16[0xC];
        u16 flag;
    };
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(s32);
    void func_80800B14_chdoor(u8 *, s32);
    void func_800EE88C(f32 *, s16 *);
    s32 _subaddiefade_entrypoint_1(s32, s32);
    void func_80103014(u8 *);
    struct DoorInitialData *data;
    s32 state;
    Actor *actor = (Actor *)arg0;

    data = func_80100094(actor, 0);
    state = data->state != 0 ? 2 : 3;
    if (func_800DA298(0x9CC)) {
        if ((data->flags & 0x4000) &&
            (!(data->flags & 0x80) || !func_800DA298(data->flag & 0x7FFF))) {
            state = 7;
        }
        func_80800B14_chdoor(arg0, state);
        switch (data->mode) {
        case 1:
            actor->rotation[1] = data->position[1];
            break;
        case 2:
            func_800EE88C(actor->position, data->position);
            break;
        case 3:
            actor->rotation[0] = data->position[1];
            break;
        case 4:
            func_800EE88C(actor->position, data->position);
            actor->rotation[2] = 0.0f;
            break;
        case 5:
            _subaddiefade_entrypoint_1(arg0, 0xFF);
            break;
        }
        func_80103014(arg0);
    }
}

void func_808008A0_chdoor(u8 *arg0) {
    struct DoorInitialData {
        u32 flags;
        u32 unused4;
        u32 mode : 6;
        u32 unused8 : 26;
        s16 unusedC;
        s16 state;
        s16 angle;
        s16 unused12[2];
        s16 position[3];
        s16 rotation;
        u8 unused1E[0xC];
        u16 flag;
    };
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(s32);
    void func_80800B14_chdoor(u8 *, s32);
    void func_800EE88C(f32 *, s16 *);
    s32 _subaddiefade_entrypoint_1(s32, s32);
    void func_80103014(u8 *);
    struct DoorInitialData *data;
    s32 state;
    Actor *actor = (Actor *)arg0;

    data = func_80100094(actor, 0);
    state = data->state != 0 ? 5 : 6;
    if ((data->flags & 0x4000) &&
        (!(data->flags & 0x80) || !func_800DA298(data->flag & 0x7FFF))) {
        state = 8;
    }
    func_80800B14_chdoor(arg0, state);
    switch (data->mode) {
    case 1:
        actor->rotation[1] = data->angle;
        break;
    case 2:
        func_800EE88C(actor->position, data->position);
        break;
    case 3:
        actor->rotation[0] = data->angle;
        break;
    case 4:
        func_800EE88C(actor->position, data->position);
        actor->rotation[2] = data->rotation * 0.00390625f;
        break;
    case 5:
        _subaddiefade_entrypoint_1(arg0, 0);
        break;
    }
    func_80103014(arg0);
}

void func_808009F4_chdoor(u8 *arg0) {
    struct DoorTransitionData {
        u32 flags;
        u32 unused4;
        s16 unused8;
        s16 duration;
        s16 openState;
        s16 closedState;
    };
    void *func_80100094(Actor *, u32);
    void func_80800B14_chdoor(u8 *, s32);
    struct DoorTransitionData *data;
    f32 time;
    s16 state;
    Actor *actor = (Actor *)arg0;

    data = func_80100094(actor, 0);
    switch (actor->unk70_10) {
    case 1:
    case 2:
    case 7:
        state = data->openState;
        data->openState = 0;
        func_80800754_chdoor(arg0);
        data->openState = state;
        return;
    case 6:
        time = data->duration * 0.00390625f - actor->unk58;
        func_80800B14_chdoor(arg0, 3);
        actor->unk58 = time;
        return;
    case 3:
        time = data->duration * 0.00390625f - actor->unk58;
        func_80800B14_chdoor(arg0, 6);
        actor->unk58 = time;
        return;
    case 4:
    case 5:
    case 8:
        state = data->closedState;
        data->closedState = 0;
        func_808008A0_chdoor(arg0);
        data->closedState = state;
        break;
    }
}

void func_80800B14_chdoor(u8 *arg0, s32 arg1) {
    struct DoorFlags {
        u32 unused : 6;
        u32 special : 1;
        u32 rest : 25;
    };
    struct DoorActorFlags {
        u8 unused : 7;
        u8 active : 1;
    };
    void *func_80100094(Actor *, u32);
    void func_80101FDC(u8 *, s32);
    void func_80103110(u8 *, s32);
    void func_80800FC0_chdoor(Actor *, s32);
    void func_808005E4_chdoor(Actor *, s32);
    void func_80801330_chdoor(Actor *, s32);
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    void func_800FC660(u32);
    void func_800FFAB0(u8 *);
    void func_8010A624(u8 *);
    void func_8010A63C(u8 *);
    s32 func_800E1610(s32, s32, s32, u8 *);
    void func_800E148C(s32, s32, s32);
    void func_80018820(s32, s32, s32);
    u8 *data;
    u32 state;
    s32 flag4;
    s32 flag8;

    data = func_80100094(arg0, 0);
    state = (u32)*(u16 *)(arg0 + 0x72) >> 10;
    if (*(s32 *)data & 4) {
        flag4 = 1;
    } else {
        flag4 = 0;
    }
    if (*(s32 *)data & 8) {
        flag8 = 1;
    } else {
        flag8 = 0;
    }
    if (((struct DoorFlags *)(data + 8))->special) {
        switch (state) {
        case 3:
            func_80101FDC(arg0, 6);
            func_80800FC0_chdoor(arg0, 1);
            *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xA) * 0.00390625f;
            break;
        case 6:
            func_80101FDC(arg0, 3);
            if (*(s16 *)(data + 0xC) == 0) {
                func_80800FC0_chdoor(arg0, 0);
            }
            *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xA) * 0.00390625f;
            break;
        }
        data[8] &= ~2;
        return;
    }
    func_80101FDC(arg0, arg1);
    switch (arg1) {
    case 1:
        _subaddieaudioloop_entrypoint_2(arg0);
        func_80103110(arg0, flag4 | flag8);
        func_80801330_chdoor(arg0, 0);
        if (*(s32 *)data & 0x100) {
            func_800E148C(func_800E1610(2, 0x42C80000, 0x3F59999A, arg0 + 4), 0x447A0000, 0x457A0000);
            func_80018820(0, 0x3F800000, 0x3ECCCCCD);
        }
        break;
    case 2:
        func_80800FC0_chdoor(arg0, 0);
        *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xC) * 0.00390625f;
        func_80103110(arg0, 1);
        break;
    case 3:
        if (*(s32 *)data & 0x40) {
            func_800FC660(0x10);
        }
        if (*(s16 *)(data + 0xC) == 0) {
            func_80800FC0_chdoor(arg0, 0);
        }
        *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xA) * 0.00390625f;
        func_808005E4_chdoor(arg0, 1);
        func_80103110(arg0, 1);
        func_80801330_chdoor(arg0, 1);
        break;
    case 4:
        _subaddieaudioloop_entrypoint_2(arg0);
        func_80103110(arg0, flag4 | flag8);
        if (*(s32 *)data & 0x800) {
            func_8010A624(arg0);
        }
        if (*(s32 *)data & 0x2000) {
            arg0[0x65] &= ~1;
        }
        if (*(s32 *)data & 1) {
            func_800FFAB0(arg0);
        }
        break;
    case 5:
        func_80800FC0_chdoor(arg0, 1);
        *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xE) * 0.00390625f;
        func_80103110(arg0, 1);
        break;
    case 6:
        if (*(s32 *)data & 0x1000) {
            func_800FC660(0x17);
        }
        if (*(s16 *)(data + 0xE) == 0) {
            func_80800FC0_chdoor(arg0, 1);
        }
        if (*(s32 *)data & 0x800) {
            func_8010A63C(arg0);
        }
        if (*(s32 *)data & 0x2000) {
            ((struct DoorActorFlags *)(arg0 + 0x65))->active = 1;
        }
        *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xA) * 0.00390625f;
        func_808005E4_chdoor(arg0, 0);
        func_80103110(arg0, 1);
        break;
    case 7:
        func_80800FC0_chdoor(arg0, 0);
        func_80103110(arg0, flag8);
        break;
    case 8:
        func_80800FC0_chdoor(arg0, 1);
        func_80103110(arg0, flag8);
        break;
    }
}

void func_80800FC0_chdoor(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 func_800DA9E4(s32, s32);
    void *func_80100094(Actor *, u32);
    struct DoorData {
        s32 flags;
        u8 padding[0x1A];
        struct {
            u16 pod;
            u8 unused20;
            u8 action;
            u16 flag;
            u16 unused24;
        } entries[2];
    };
    struct DoorData *data;

    data = func_80100094(arg0, 0);
    if (((u32)data->entries[arg1].flag >> 15) != 0) {
        if ((data->flags & 0x80) && (data->entries[arg1].flag & 0x7FFF)) {
            if (func_800DA9E4(data->entries[arg1].flag & 0x7FFF, 1) == 0) {
                _capod_entrypoint_13(arg0->unk0, 0, data->entries[arg1].action, data->entries[arg1].pod);
            }
        } else {
            _capod_entrypoint_13(arg0->unk0, 0, data->entries[arg1].action, data->entries[arg1].pod);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/chdoor_entrypoint_1.s")

void func_80801330_chdoor(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_800DA3B8(s32, s32);
    struct DoorData {
        s32 flags;
        s16 index;
    };
    s32 temp_v1;
    s32 var_a1;
    s32 var_a1_2;
    struct DoorData *data;

    data = func_80100094(arg0, 0);
    if (data->index != -1 && (temp_v1 = data->flags, (temp_v1 & 0x20) == 0)) {
        var_a1 = arg1 != 0 ? 1 : 0;
        if (temp_v1 & 0x10) {
            if (var_a1 != 0) {
                var_a1_2 = 0;
            } else {
                var_a1_2 = 1;
            }
            func_800DA3B8(data->index, var_a1_2);
            return;
        }
        func_800DA3B8(data->index, var_a1);
    }
}

s32 func_808013C0_chdoor(Actor *arg0, s32 arg1) {
    f32 func_800137AC(f32);
    f32 func_800137C4(void);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    s32 func_800F0AA4(f32 *, f32 *, f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    f32 func_800F5F24(u32);
    void *func_80100094(Actor *, u32);
    f32 mlAbsF(f32);
    struct DoorData {
        s32 flags;
        s16 index;
        s16 pad6;
        u32 mode;
        s32 padC;
        s16 pad10;
        s16 height;
    } *data;
    f32 position[3];
    f32 height;
    f32 start[3];
    f32 end[3];
    f32 direction[3];
    f32 x;
    f32 z;

    data = func_80100094(arg0, 0);
    func_800F5A00(arg1, position);
    if ((data->mode >> 26) == 2) {
        height = data->height;
    } else {
        height = arg0->position[1];
    }
    if (mlAbsF(position[1] - height) > 100.0f) {
        return 0;
    }
    x = func_800137AC(arg0->rotation[1]) * 100.0f;
    z = func_800137C4() * 100.0f;
    start[0] = arg0->position[0] - x;
    start[2] = arg0->position[2] - z;
    end[0] = arg0->position[0] + x;
    end[2] = arg0->position[2] + z;
    func_800EEB9C(direction, func_800F5F24(arg1), 200.0f);
    func_800EF04C(direction, position);
    if (func_800F0AA4(start, end, position, direction) == 0) {
        return 0;
    }
    func_808009F4_chdoor((u8 *)arg0);
    return 1;
}
