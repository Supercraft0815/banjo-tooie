#include "common.h"

OSThread *chsquits_entrypoint_0(void)
{
    extern ActorData D_808006D8_chsquits[];

    return (OSThread *) D_808006D8_chsquits;
}                 typedef struct { u8 pad0[0x2C]; f32 unk2C; u8 pad30[0x3E]; u16 unk6E; } Objsquits_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080000C_chsquits(u8 *arg0) {
    f32 func_800DC178(f32, f32);
    (((Objsquits_arg0 *)arg0)->unk6E) = (u16) (((((Objsquits_arg0 *)arg0)->unk6E) & 0xFE00) | 1);
    (((Objsquits_arg0 *)arg0)->unk2C) = func_800DC178(5.0f, 8.0f);
}

void func_80800054_chsquits(Actor *arg0) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);
    s32 func_8010CAC0(f32 *, u32);
    s32 func_808001A4_chsquits(Actor *);
    void func_80800358_chsquits(Actor *);
    f32 *sp2C;

    if (arg0->unk70_10 == 1) {
        if (func_800D90A4(&arg0->unk58) != 0) {
            sp2C = arg0->position;
            if (func_8010CAC0(sp2C, 0x190) != 0) {
                if (_subaddiedialog_entrypoint_11(arg0->unk0, func_808001A4_chsquits(arg0), 0, sp2C, 0x8F) != 0) {
                    func_80101FDC(arg0, 2);
                }
                arg0->unk58 = func_800DC178(5.0f, 8.0f);
            }
        }
    }
    func_80800358_chsquits(arg0);
}

s32 func_80800108_chsquits(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800BF744(s32, s32);
    int func_800DC298(f32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
        case 0x2E:
            func_80101FDC(arg0, 1);
            return 1;
        case 0x95:
            if (func_800DC298(0.2f) == 0) {
                func_800BF744(1, 0);
                func_800FFAB0(arg0);
                break;
            } else {
                func_800BF744(1, 1);
                break;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_808001A4_chsquits(Actor *arg0) {
    s32 func_800DC128(s32, s32);
    extern s16 D_808006C4_chsquits[10];
    s32 count;
    s32 available;
    u32 i;
    s32 selected;

    available = 0;
    for (i = 0; i < 10; i++) {
        if (!(arg0->actorData[6] & (1 << i))) {
            available++;
        }
    }
    if (available == 0) {
        arg0->actorData[6] = 0;
        available = 10;
    }
    selected = func_800DC128(0, available);
    count = 0;
    for (i = 0; i < 10; i++) {
        if (!(arg0->actorData[6] & (1 << i))) {
            if (count == selected) {
                arg0->actorData[6] |= 1 << i;
                return D_808006C4_chsquits[i];
            }
            count++;
        }
    }
    return D_808006C4_chsquits[0];
}

void func_80800358_chsquits(Actor *arg0) {
    s32 func_800D90A4(f32 *);
    void func_808003C4_chsquits(Actor *);
    void func_80800564_chsquits(void *);

    if (arg0->unk6C_0 != 0) {
        if (arg0->unk6C_0 == 1 && func_800D90A4((f32 *)&arg0->actorData[5])) {
            arg0->unk6C_0 = 0;
            func_80800564_chsquits(arg0);
        }
    } else {
        func_808003C4_chsquits(arg0);
    }
}

typedef struct {
    s16 sound;
    s16 volume;
    f32 pitch;
    f32 time;
} SquitsSound;
typedef struct {
    SquitsSound *sounds;
    s32 count;
    f32 duration;
} SquitsSequence;
void func_808003C4_chsquits(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    int func_800D91EC(f32 *, f32);
    f32 func_800DC178(f32, f32);
    s32 func_80800528_chsquits(f32, f32, f32);
    extern SquitsSequence D_80800694_chsquits[];
    extern s16 D_80800720_chsquits[7];
    s32 pad[2];
    s32 finished;
    f32 previous;
    s32 i;
    s32 offset;
    SquitsSound *sound;
    SquitsSequence *sequence;

    sequence = &D_80800694_chsquits[(s32)arg0->actorData[4]];
    previous = *(f32 *)&arg0->actorData[5];
    finished = func_800D91EC((f32 *)&arg0->actorData[5], sequence->duration);
    for (i = 0, offset = 0; i < sequence->count; i++, offset += sizeof(SquitsSound)) {
        sound = (SquitsSound *)((u8 *)sequence->sounds + offset);
        if (func_80800528_chsquits(*(f32 *)&arg0->actorData[5], previous, sound->time)) {
            func_800C4B7C(sound->sound);
            func_800C4B70(sound->volume);
            func_800C4B64(func_800DC178(-0.05f, 0.05f) + sound->pitch);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800720_chsquits);
        }
    }
    if (finished) {
        arg0->unk6C_0 = 1;
        *(f32 *)&arg0->actorData[5] = func_800DC178(5.0f, 8.0f);
    }
}

s32 func_80800528_chsquits(f32 arg0, f32 arg1, f32 arg2) {
    if ((arg2 < arg0) && (arg1 <= arg2)) {
        return 1;
    }
    return 0;
}

/* extern */
void func_80800564_chsquits(void *arg0) {
    s32 func_800DC128(s32, s32);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = func_800DC128(0, 4);
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 0.0f;
}
#include "squits_data.inc"
