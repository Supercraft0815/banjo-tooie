#include "common.h"
#include "core2/1EB93C0.h"
/* IDO keeps overlapping linker-symbol views; the host uses actual struct fields. */
#ifdef BT_NATIVE
#include "memory.h"
#include "core2/animation.h"
#include "core2/animation_resource.h"
#include "core2/1EAF950.h"
#define ANIM_FIELD(p, field, original) (((Animation *)(p))->field)
#define POSE_START D_80126CC0_storage.start
#define POSE_END D_80126CC0_storage.end
#else
#define ANIM_FIELD(p, field, original) (original)
#define POSE_START D_80126CC0
#define POSE_END D_80126CC4
#endif


typedef struct { s16 fields[3]; } SoundListEntry;
#ifndef BT_NATIVE
extern s32 D_80126CC0;
extern SoundListEntry *D_80126CC4;
#endif
void func_8008BBC0(void *, void *);
#ifndef BT_NATIVE
void *heap_realloc(void *, s32);
#endif
void func_800DFCC0(s16);
#ifdef BT_NATIVE
BoneTransformList *func_800DFCE8(s16);
#endif
s16 func_800DFD10(void);
void func_800DFAD0(BoneTransformList *);
void func_800DFD64(BoneTransformList *, BoneTransformList *, BoneTransformList *, f32);

typedef struct {
    SoundListEntry *start;
    SoundListEntry *end;
    u8 padding[8];
} SoundListStorage;

SoundListStorage D_80126CC0_storage;

#ifdef BT_NATIVE
void func_8008B610(void) {
    u8 *temp_a1;
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x3C);
    temp_a1 = temp_v0 + 0x3C;
    POSE_START = (SoundListEntry *)temp_v0;
    POSE_END = (SoundListEntry *)temp_a1;
    func_8008BBC0(temp_v0, temp_a1);
}
#else
void func_8008B610(void) {
    s32 heap_alloc(s32);
    extern s32 D_80126CC0;
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = heap_alloc(0x3C);
    temp_a1 = temp_v0 + 0x3C;
    (*(s32 *)((s8 *)(&D_80126CC0) + (0))) = temp_v0;
    (*(s32 *)((s8 *)(&D_80126CC0) + (4))) = temp_a1;
    func_8008BBC0(temp_v0, temp_a1);
}
#endif

void func_8008B64C(void) { void func_800DFCC0(s16); void heap_free(void *); SoundListEntry *entry; s16 value; entry = D_80126CC0_storage.start; while (entry < D_80126CC0_storage.end) { if (entry->fields[2] != 0) { value = entry->fields[0]; if (value != 0) { func_800DFCC0(value); entry->fields[0] = 0; } entry->fields[2] = 0; } entry++; } heap_free(D_80126CC0_storage.start);
    D_80126CC0_storage.start = D_80126CC0_storage.end = NULL;
}

#ifdef BT_NATIVE
void func_8008B6E0(void) {
    void func_800DFCC0(s16);
    s16 temp_a0;
    s16 *var_s0;

    var_s0 = (s16 *)POSE_START;
    while (var_s0 < (s16 *)POSE_END) {
            if (var_s0[2] != 0) {
                temp_a0 = var_s0[0];
                if ((temp_a0 != 0) && (var_s0[1] < 0x3B)) {
                    func_800DFCC0(temp_a0);
                    var_s0[0] = 0;
                }
            }
            var_s0 += 3;
    }
}
#else
void func_8008B6E0(void) {
    void func_800DFCC0(s16);
    extern s32 D_80126CC0;
    s16 temp_a0;
    s16 *var_s0;

    var_s0 = (s16 *)D_80126CC0;
    while (var_s0 < *(s16 **)((s8 *)&D_80126CC0 + 4)) {
            if (var_s0[2] != 0) {
                temp_a0 = var_s0[0];
                if ((temp_a0 != 0) && (var_s0[1] < 0x3B)) {
                    func_800DFCC0(temp_a0);
                    var_s0[0] = 0;
                }
            }
            var_s0 += 3;
    }
}
#endif

#ifdef BT_NATIVE
void func_8008B768(void) {
    void func_800DFCC0(s16);
    void *heap_realloc(void *, s32);
    struct Entry { s16 value, age, active; };
    struct Entry *entry;
    s32 count;
    s32 size;
    struct Entry *data;

    count = 0;
    entry = (struct Entry *)POSE_START;
    while (entry < (struct Entry *)POSE_END) {
        if (entry->active != 0) {
            entry->age = 0;
            func_800DFCC0(entry->value);
            entry->value = 0;
            count = entry - (struct Entry *)POSE_START + 1;
        }
        entry++;
    }
    if (count < 10) {
        count = 10;
    }
    size = count * 6;
    data = heap_realloc(POSE_START, size);
    POSE_START = (SoundListEntry *)data;
    POSE_END = (SoundListEntry *)(size + (u8 *)POSE_START);
}
#else
void func_8008B768(void) {
    void func_800DFCC0(s16);
    void *heap_realloc(void *, s32);
    extern s32 D_80126CC0;
    struct Entry { s16 value, age, active; };
    struct Entry *entry;
    s32 count;
    s32 size;
    struct Entry *data;

    count = 0;
    entry = *(struct Entry **)&D_80126CC0;
    while (entry < ((struct Entry **)&D_80126CC0)[1]) {
        if (entry->active != 0) {
            entry->age = 0;
            func_800DFCC0(entry->value);
            entry->value = 0;
            count = entry - *(struct Entry **)&D_80126CC0 + 1;
        }
        entry++;
    }
    if (count < 10) {
        count = 10;
    }
    size = count * 6;
    data = heap_realloc(*(void **)&D_80126CC0, size);
    D_80126CC0 = (s32)data;
    *(s32 *)((s32)&D_80126CC0 + 4) = size + D_80126CC0;
}
#endif

#ifdef BT_NATIVE
void func_8008B850(void) {
    void func_800DFCC0(s16);
    struct Entry { s16 value, age, active; };
    struct Entry *entry;

    for (entry = (struct Entry *)POSE_START;
         entry < (struct Entry *)POSE_END; entry++) {
        switch (entry->active) {
        case 0:
            break;
        default:
            if (entry->value != 0) {
                entry->age--;
                if (entry->age <= 0) {
                    func_800DFCC0(entry->value);
                    entry->value = 0;
                }
            }
            break;
        }
    }
}
#else
void func_8008B850(void) {
    void func_800DFCC0(s16);
    extern s32 D_80126CC0;
    struct Entry { s16 value, age, active; };
    struct Entry *entry;

    for (entry = (struct Entry *)D_80126CC0;
         entry < *(struct Entry **)((s8 *)&D_80126CC0 + 4); entry++) {
        switch (entry->active) {
        case 0:
            break;
        default:
            if (entry->value != 0) {
                entry->age--;
                if (entry->age <= 0) {
                    func_800DFCC0(entry->value);
                    entry->value = 0;
                }
            }
            break;
        }
    }
}
#endif

s16 func_8008B8E0(void) {
    s16 *func_8008BAC0(s32 *);
    s32 sp1C;
    s16 *temp_v0;

    temp_v0 = func_8008BAC0(&sp1C);
    temp_v0[1] = 0;
    temp_v0[0] = 0;
#ifdef BT_NATIVE
    return (s16)sp1C;
#else
    return *(s16 *)((s8 *)&sp1C + 2);
#endif
}

#ifdef BT_NATIVE
s32 func_8008B90C(s16 arg0) {
    s16 *entry;
    entry = (s16 *)((u8 *)POSE_START + arg0 * 6 - 6);
    return entry[0] ? 1 : 0;
}
#else
s32 func_8008B90C(s16 arg0) {
    extern s32 D_80126CC0;
    s16 *entry;
    entry = (s16 *)(D_80126CC0 + arg0 * 6 - 6);
    return entry[0] ? 1 : 0;
}
#endif

#ifdef BT_NATIVE
void func_8008B954(s16 arg0) {
    void func_800DFCC0(s16 arg0);
    s16 *entry;
    entry = (s16 *)((u8 *)POSE_START + arg0 * 6 - 6);
    if (entry[0] != 0) {
        func_800DFCC0(entry[0]);
        entry[0] = 0;
    }
    entry[2] = 0;
    entry[1] = entry[2];
}
#else
void func_8008B954(s16 arg0) {
    extern s32 D_80126CC0;
    void func_800DFCC0(s16 arg0);
    s16 *entry;
    entry = (s16 *)(D_80126CC0 + arg0 * 6 - 6);
    if (entry[0] != 0) {
        func_800DFCC0(entry[0]);
        entry[0] = 0;
    }
    entry[2] = 0;
    entry[1] = entry[2];
}
#endif

#ifdef BT_NATIVE
s32 func_8008B9C4(s16 arg0, BoneTransformList **arg1) {
    s16 func_800DFD10(void);
    s16 *entry;

    entry = (s16 *)((u8 *)POSE_START + arg0 * 6 - 6);
    entry[1] = 0x3C;
    if (entry[0]) {
        *arg1 = func_800DFCE8(entry[0]);
        return 0;
    } else {
        entry[0] = func_800DFD10();
        *arg1 = func_800DFCE8(entry[0]);
        return 1;
    }
}
#else
s32 func_8008B9C4(s16 arg0, s32 *arg1) {
    extern s32 D_80126CC0;
    s32 func_800DFCE8(s16 arg0);
    s16 func_800DFD10(void);
    s16 *entry;

    entry = (s16 *)(D_80126CC0 + arg0 * 6 - 6);
    entry[1] = 0x3C;
    if (entry[0]) {
        *arg1 = func_800DFCE8(entry[0]);
        return 0;
    } else {
        entry[0] = func_800DFD10();
        *arg1 = func_800DFCE8(entry[0]);
        return 1;
    }
}
#endif

#ifdef BT_NATIVE
void func_8008BA5C(void) {
    s32 sp1C;
    SoundListEntry *temp_v0;

    sp1C = (s32)((u8 *)POSE_END - (u8 *)POSE_START) / 6;
    temp_v0 = defrag(POSE_START);
    POSE_START = temp_v0;
    POSE_END = (SoundListEntry *)((sp1C * 6) + (u8 *)POSE_START);
}
#else
void func_8008BA5C(void) {
    s32 defrag(s32);
    extern s32 D_80126CC0;
    s32 sp1C;
    s32 temp_v0;

    sp1C = (s32) ((*(s32 *)((s8 *)(&D_80126CC0) + (4))) - (*(s32 *)((s8 *)(&D_80126CC0) + (0)))) / 6;
    temp_v0 = defrag((*(s32 *)((s8 *)(&D_80126CC0) + (0))));
    (*(s32 *)((s8 *)(&D_80126CC0) + (0))) = temp_v0;
    (*(s32 *)((s8 *)(&D_80126CC0) + (4))) = (sp1C * 6) + D_80126CC0;
}
#endif

s16 *func_8008BAC0(s32 *arg0) {
    void *heap_realloc(void *, s32);
    SoundListEntry *entry;
    s32 count;

    entry = D_80126CC0_storage.start;
    if (entry < D_80126CC0_storage.end) {
        do {
            if (entry->fields[2] == 0) {
                break;
            }
            entry++;
        } while (entry < D_80126CC0_storage.end);
    }
    if (entry == D_80126CC0_storage.end) {
        count = D_80126CC0_storage.end - D_80126CC0_storage.start;
        D_80126CC0_storage.start = heap_realloc(D_80126CC0_storage.start, count * sizeof(*entry) + 60);
        {
            s32 end_size;
            /* Keep IDO's end-pointer calculation separate from the allocation size. */
            end_size = count | 0;
            POSE_END = (SoundListEntry *)(end_size * sizeof(*entry) + (u8 *)D_80126CC0_storage.start + 60);
        }
        entry = &D_80126CC0_storage.start[count];
        func_8008BBC0(entry, D_80126CC0_storage.end);
    }
    entry->fields[2] = 1;
    *arg0 = entry - D_80126CC0_storage.start + 1;
    return (s16 *)entry;
}

void func_8008BBC0(void *arg0, void *arg1) {
    u8 *var_v0;

    var_v0 = arg0;
    if ((uintptr_t)arg0 < (uintptr_t)arg1) {
        do {
            (*(s16 *)((s8 *)var_v0)) = 0;
            (*(s16 *)((s8 *)var_v0 + 2)) = ((*(s16 *)((s8 *)var_v0 + 4)) = 0);
            var_v0 += 6;
        } while ((uintptr_t)var_v0 < (uintptr_t)arg1);
    }
}

/* extern */

void func_8008BBF0(void *arg0, s32 arg1) {
    BoneTransformList *sp1C;

    if (func_8008B9C4(ANIM_FIELD(arg0, poses[arg1], (*(s16 *)((s8 *)arg0 + (arg1 << 1) + 0xA))), &sp1C) == 0) {
        func_800DFAD0(sp1C);
    }
}

void func_8008BC2C(u8 *arg0) {
    func_8008BBF0(arg0, ANIM_FIELD(arg0, current_pose, arg0[8]));
}

void func_8008BC4C(void *arg0)
{
    func_8008BBF0(arg0,0x2);
}

/* extern */

s32 func_8008BC6C(u8 *arg0, s32 arg1) {
    s32 func_8008B90C(s16);
    return func_8008B90C(ANIM_FIELD(arg0, poses[arg1], ((s16 *)arg0)[arg1 + 5]));
}

/* extern */

s32 func_8008BC94(u8 *arg0) {
    s32 func_8008BC6C(u8 *, s32);
    return func_8008BC6C(arg0, ANIM_FIELD(arg0, current_pose, arg0[8]));
}

s32 func_8008BCB4(u8 *arg0) {
    s32 func_8008BC6C(u8 *, s32);
    s32 value;

    value = ANIM_FIELD(arg0, current_pose, arg0[8]) ? 0 : 1;
    return func_8008BC6C(arg0, value);
}

/* extern */

BoneTransformList *func_8008BCEC(void *arg0, s32 arg1) {
    BoneTransformList *sp1C;

    func_8008B9C4(ANIM_FIELD(arg0, poses[arg1], (*(s16 *)((s8 *)arg0 + 0xA + (arg1 << 1)))), &sp1C);
    return sp1C;
}

BoneTransformList *func_8008BD1C(void *arg0) {
    return func_8008BCEC(arg0, ANIM_FIELD(arg0, current_pose, *(u8 *)((u8 *)arg0 + 8)));
}

BoneTransformList *func_8008BD3C(void *arg0) {
    s32 value;

    value = ANIM_FIELD(arg0, current_pose, *(u8 *)((u8 *)arg0 + 8)) ? 0 : 1;
    return func_8008BCEC(arg0, value);
}

BoneTransformList *func_8008BD74(void *arg0)
{
    return func_8008BCEC(arg0,0x2);
}

void func_8008BD94(void *arg0) {
#ifdef BT_NATIVE
    struct ImageStruct *func_800D674C(s32);
#else
    s32 func_800D674C(s32);
    void func_800E0170(s32, f32, u8, s32);
#endif

    if (ANIM_FIELD(arg0, pending, *(u8 *)((u8 *)arg0 + 0x1B)) == 1 && func_8008BC94(arg0)) {
        if (ANIM_FIELD(arg0, current_pose, *(u8 *)((u8 *)arg0 + 8))) {
            ANIM_FIELD(arg0, current_pose, *(u8 *)((u8 *)arg0 + 8)) = 0;
        } else {
            ANIM_FIELD(arg0, current_pose, *(u8 *)((u8 *)arg0 + 8)) = 1;
        }
    }
    ANIM_FIELD(arg0, pending, *(u8 *)((u8 *)arg0 + 0x1B)) = 0;
    if (ANIM_FIELD(arg0, blend, *(f32 *)((u8 *)arg0 + 0x14)) < 1.0f && func_8008BCB4(arg0)) {
        func_800E0170((void *)func_800D674C(ANIM_FIELD(arg0, index, *(s16 *)((u8 *)arg0 + 0x18))), ANIM_FIELD(arg0, timer, *(f32 *)((u8 *)arg0 + 0x10)), ANIM_FIELD(arg0, loop, *(u8 *)((u8 *)arg0 + 0x1E)), func_8008BD1C(arg0));
        func_800DFD64(func_8008BD1C(arg0), func_8008BD3C(arg0), func_8008BD1C(arg0), ANIM_FIELD(arg0, blend, *(f32 *)((u8 *)arg0 + 0x14)));
    } else {
        func_800E0170((void *)func_800D674C(ANIM_FIELD(arg0, index, *(s16 *)((u8 *)arg0 + 0x18))), ANIM_FIELD(arg0, timer, *(f32 *)((u8 *)arg0 + 0x10)), ANIM_FIELD(arg0, loop, *(u8 *)((u8 *)arg0 + 0x1E)), func_8008BD1C(arg0));
    }
}

void func_8008BEB4(u8 *arg0) {
#ifdef BT_NATIVE
    struct ImageStruct *func_800D674C(s32);
#else
    s32 func_800D674C(s32);
    void func_800E0170(s32, f32, u8, s32);
#endif

    if (ANIM_FIELD(arg0, pending, arg0[0x1B]) == 1 && ANIM_FIELD(arg0, fresh, arg0[0x1D]) == 0) {
        if (func_8008BC94(arg0)) {
            if (ANIM_FIELD(arg0, current_pose, arg0[8])) {
                ANIM_FIELD(arg0, current_pose, arg0[8]) = 0;
            } else {
                ANIM_FIELD(arg0, current_pose, arg0[8]) = 1;
            }
            func_8008BC4C(arg0);
        }
    } else if (ANIM_FIELD(arg0, pending, arg0[0x1B]) == 2) {
        func_8008BC2C(arg0);
    }
    ANIM_FIELD(arg0, pending, arg0[0x1B]) = 0;
    if ((ANIM_FIELD(arg0, blend, *(f32 *)(arg0 + 0x14)) < 1.0f || ANIM_FIELD(arg0, blend_complete, arg0[0x1A])) && func_8008BCB4(arg0) && ANIM_FIELD(arg0, fresh, arg0[0x1D]) == 0) {
        ANIM_FIELD(arg0, blend_complete, arg0[0x1A]) = 0;
        func_800E0170((void *)func_800D674C(ANIM_FIELD(arg0, index, *(s16 *)(arg0 + 0x18))), ANIM_FIELD(arg0, timer, *(f32 *)(arg0 + 0x10)), ANIM_FIELD(arg0, loop, arg0[0x1E]), func_8008BD74(arg0));
        func_800DFD64(func_8008BD1C(arg0), func_8008BD3C(arg0), func_8008BD74(arg0), ANIM_FIELD(arg0, blend, *(f32 *)(arg0 + 0x14)));
    } else {
        func_800E0170((void *)func_800D674C(ANIM_FIELD(arg0, index, *(s16 *)(arg0 + 0x18))), ANIM_FIELD(arg0, timer, *(f32 *)(arg0 + 0x10)), ANIM_FIELD(arg0, loop, arg0[0x1E]), func_8008BD1C(arg0));
        if (ANIM_FIELD(arg0, fresh, arg0[0x1D]) && ANIM_FIELD(arg0, index, *(s16 *)(arg0 + 0x18))) {
            ANIM_FIELD(arg0, fresh, arg0[0x1D]) = 0;
        }
    }
}

/* extern */

void func_8008C038(void *arg0) {
    void func_8008BD94(void *);
    void func_8008BEB4(u8 *);
    if (ANIM_FIELD(arg0, mode, (*(u8 *)((s8 *)(arg0) + (0x1C)))) == 1) {
        func_8008BEB4(arg0);
    } else {
        func_8008BD94(arg0);
    }
#ifdef BT_NATIVE
    if (((Animation *)arg0)->callback != NULL) {
        ((Animation *)arg0)->callback(func_8008BD1C(arg0), ((Animation *)arg0)->context);
    }
#else
    if ((*(s32 (**)(s32, s32))((s8 *)(arg0) + (0))) != NULL) {
        (*(s32 (**)(s32, s32))((s8 *)(arg0) + (0)))(func_8008BD1C(arg0), (*(s32 *)((s8 *)(arg0) + (4))));
    }
#endif
}

void func_8008C0AC(s8 *arg0)
{
    ANIM_FIELD(arg0, pending, arg0[0x1B]) = 1;
}

s32 func_8008C0B8(void)
{
#ifdef BT_NATIVE
    return sizeof(Animation);
#else
    return 0x20;
#endif
}

s32 func_8008C0C0(s16 *arg0)
{
    return ANIM_FIELD(arg0, index, arg0[12]);
}

f32 func_8008C0C8(f32 *arg0)
{
    return ANIM_FIELD(arg0, timer, arg0[4]);
}

f32 func_8008C0D0(f32 *arg0)
{
    return ANIM_FIELD(arg0, blend, arg0[5]);
}

/* extern */

void func_8008C0D8(void *arg0) {
    void func_8008B954(s16);
    func_8008B954(ANIM_FIELD(arg0, poses[0], (*(s16 *)((s8 *)(arg0) + (0xA)))));
    func_8008B954(ANIM_FIELD(arg0, poses[1], (*(s16 *)((s8 *)(arg0) + (0xC)))));
    if (ANIM_FIELD(arg0, mode, (*(u8 *)((s8 *)(arg0) + (0x1C)))) == 1) {
        func_8008B954(ANIM_FIELD(arg0, poses[2], (*(s16 *)((s8 *)(arg0) + (0xE)))));
    }
}

void func_8008C124(s16 *arg0, s32 arg1) {
    void func_8008C1B8(s16 *arg0, s32 arg1);
    void func_8008C1C0(f32 *arg0, f32 arg1);
#ifndef BT_NATIVE
    void func_8008C1D4(s32 *arg0, s32 arg1);
#endif
    void func_8008C1E4(f32 *arg0, f32 arg1);

    ANIM_FIELD(arg0, mode, ((u8 *)arg0)[0x1C]) = arg1;
    func_8008C1B8(arg0, 0);
    func_8008C1C0((f32 *)arg0, 0.0f);
    func_8008C1E4((f32 *)arg0, 1.0f);
    func_8008C1D4((s32 *)arg0, 0);
    ANIM_FIELD(arg0, pending, ((s8 *)arg0)[0x1B]) = 0;
    ANIM_FIELD(arg0, fresh, ((s8 *)arg0)[0x1D]) = 1;
    ANIM_FIELD(arg0, blend_complete, ((s8 *)arg0)[0x1A]) = 0;
    ANIM_FIELD(arg0, current_pose, ((s8 *)arg0)[8]) = 0;
    ANIM_FIELD(arg0, poses[0], arg0[5]) = func_8008B8E0();
    ANIM_FIELD(arg0, poses[1], arg0[6]) = func_8008B8E0();
    if (ANIM_FIELD(arg0, mode, ((u8 *)arg0)[0x1C]) == 1) {
        ANIM_FIELD(arg0, poses[2], arg0[7]) = func_8008B8E0();
    }
}

void func_8008C1B8(s16 *arg0, s32 arg1) {
    ANIM_FIELD(arg0, index, arg0[12]) = arg1;
}

void func_8008C1C0(f32 *arg0, f32 arg1) {
    ANIM_FIELD(arg0, timer, arg0[4]) = arg1;
}

void func_8008C1CC(s8 *arg0, s32 arg1) {
    ANIM_FIELD(arg0, loop, arg0[30]) = arg1;
}

#ifdef BT_NATIVE
void func_8008C1D4(void *arg0, AnimCallback arg1) {
    ((Animation *)arg0)->callback = arg1;
}
#else
void func_8008C1D4(s32 *arg0, s32 arg1) {
    arg0[0] = arg1;
}
#endif

#ifdef BT_NATIVE
void func_8008C1DC(void *arg0, uintptr_t arg1) {
    ((Animation *)arg0)->context = arg1;
}
#else
void func_8008C1DC(s32 *arg0, s32 arg1) {
    arg0[1] = arg1;
}
#endif

void func_8008C1E4(f32 *arg0, f32 arg1) {
    ANIM_FIELD(arg0, blend, arg0[5]) = arg1;
}

void func_8008C1F0(void *arg0, s32 arg1) {
    ANIM_FIELD(arg0, blend_complete, (*(s8 *)((s8 *)(arg0) + (0x1A)))) = 1;
}

/* extern */

#ifdef BT_NATIVE
void func_8008C200(s16 arg0, void *arg1, void *arg2) {
    void func_800AE1E8(s16, void *, BoneTransformList *);
#else
void func_8008C200(s16 arg0, s32 arg1, s32 arg2) {
    s32 func_800AE1E8(s16, s32, s32);
#endif
    func_800AE1E8(arg0, arg1, func_8008BD1C(arg2));
}

/* extern */

#ifdef BT_NATIVE
void func_8008C238(s16 arg0, void *arg1, void *arg2) {
    void func_800AE290(s16, void *, BoneTransformList *);
#else
void func_8008C238(s16 arg0, s32 arg1, s32 arg2) {
    s32 func_800AE290(s16, s32, s32);
#endif
    func_800AE290(arg0, arg1, func_8008BD1C(arg2));
}

void func_8008C270(s8 *arg0) {
    ANIM_FIELD(arg0, pending, arg0[0x1B]) = 2;
}

/* extern */

void *func_8008C27C(void *arg0) {
    return func_8008BD1C(arg0);
}
