#include "core2/1EA1DA0.h"
#include "core2/transition.h"
#include "1EA1DA0_lights.inc"

#ifdef BT_NATIVE
extern Transition *D_8012AB40[5];
#define TRANSITION_SLOTS D_8012AB40
#define TRANSITION_COUNT D_8012AB54
#else
extern s32 D_8012AB40;
typedef struct { s32 slots[5]; u8 count; } OriginalTransitionSlots;
#define TRANSITION_SLOTS ((Transition **)&D_8012AB40)
#define TRANSITION_COUNT (((OriginalTransitionSlots *)&D_8012AB40)->count)
#endif

BtIntPtr func_800C9150(s32 arg0) {
    BtIntPtr func_800C91C8(s32);
    void *heap_alloc(s32);
    void bzero(void *, int);
    void _gctransitionDll_entrypoint_8(void *, s32);
    Transition *result;

    result = (void *)func_800C91C8(arg0);
    if (result == NULL) {
        result = heap_alloc(sizeof(Transition));
        bzero(result, sizeof(Transition));
        TRANSITION_SLOTS[TRANSITION_COUNT] = result;
        TRANSITION_COUNT += 1;
        _gctransitionDll_entrypoint_8(result, arg0);
    }
    return (BtIntPtr)result;
}

BtIntPtr func_800C91C8(s32 arg0) {
    register s32 key = arg0;
    s32 i = 0; register s32 count = D_8012AB54; Transition **p = TRANSITION_SLOTS;
    Transition *entry;
    if (count > 0) {
        loop:
        entry = *p;
        i++;
        if (key == entry->id) return (BtIntPtr)entry;
        p++;
        count = D_8012AB54;
        if (i < count) goto loop;
    }
    return 0;
}

void func_800C9214(void *arg0)
{
    void heap_free(void *);
    register s32 i;
    register u8 last;

    for (i = 0; i < (s32)TRANSITION_COUNT; i++) {
        if (arg0 == TRANSITION_SLOTS[i]) {
            heap_free(TRANSITION_SLOTS[i]);
            last = TRANSITION_COUNT - 1; TRANSITION_COUNT = last; TRANSITION_SLOTS[i] = TRANSITION_SLOTS[last];
            break;
        }
    }
}

void func_800C929C()
{
	D_8012AB54 = 0;
}

/* extern */

void func_800C92A8(void) {
    void _gctransitionDll_entrypoint_9(Transition *arg0);
    s32 i;
    for (i = 0; i < (s32)TRANSITION_COUNT; i++) {
        _gctransitionDll_entrypoint_9(TRANSITION_SLOTS[i]);
    }
}

void func_800C9310(void) {
    void _gctransitionDll_entrypoint_5(Transition *arg0);
    if (TRANSITION_COUNT != 0) {
        do {
            _gctransitionDll_entrypoint_5(TRANSITION_SLOTS[0]);
        } while (TRANSITION_COUNT != 0);
    }
}

void func_800C9358(Gfx **arg0, s32 arg1) {
    BT_IDO_ONLY(s32 _gctransitionDll_entrypoint_0(Transition *, BtIntPtr);) BT_NATIVE_ONLY(void _gctransitionDll_entrypoint_0(Transition *, Gfx **);)
    s32 func_800A8BD4(Gfx **, s32, s32);
    void func_800A8CCC(BtIntPtr, s32);
    s32 value;
    s32 i;
    u8 count = D_8012AB54;

    if (count != 0) {
        for (i = 0; i < (s32)D_8012AB54; i++) {
                value = TRANSITION_SLOTS[i]->id;
                if (value != 4) {
                    func_800A8BD4(arg0, value, arg1);
                    _gctransitionDll_entrypoint_0(TRANSITION_SLOTS[i], arg0);
                }
        }
        func_800A8CCC((BtIntPtr)arg0, arg1);
    }
}

s32 func_800C940C(volatile BtIntPtr arg0, volatile s32 arg1) {
    BT_IDO_ONLY(s32 _gctransitionDll_entrypoint_0(Transition *, BtIntPtr);) BT_NATIVE_ONLY(void _gctransitionDll_entrypoint_0(Transition *, Gfx **);)
    s32 count = D_8012AB54;
    s32 value;
    s32 i;
    s32 limit;
    Transition *transition;

    if (count != 0) {
        i = 0;
        limit = count;
        for (; i < limit; i++) {
            transition = TRANSITION_SLOTS[i];
            value = transition->id;
            if (value == 4) {
                BT_IDO_ONLY(return) _gctransitionDll_entrypoint_0(transition, BT_DATA_FIELD((Gfx **)arg0, arg0)); BT_NATIVE_ONLY(return 0;)
            }
        }
    }
BT_NATIVE_ONLY(return 0;) }

void func_800C9484(void) {
    void *defrag(void *);
    struct anctrl_s *func_8008AEB4(struct anctrl_s *);
    s32 i;
    Transition **slot;
    Transition *entry;
    struct anctrl_s *anim;

    i = 0;
    if ((s32)D_8012AB54 > 0) {
        slot = TRANSITION_SLOTS;
        do {
            entry = *slot;
            if (entry != NULL) {
                anim = entry->control;
                if (anim != NULL) {
                    (*slot)->control = func_8008AEB4(anim);
                }
                *slot = defrag(*slot);
            }
            i++;
            slot++;
        } while (i < (s32)D_8012AB54);
    }
}

/* extern */

s32 func_800C9510(void) {
    s32 _gctransitionDll_entrypoint_4(BtIntPtr);
    BtIntPtr func_800C91C8(s32);
    BtIntPtr temp_v0;

    temp_v0 = func_800C91C8(4);
    if (temp_v0 != 0) {
        return _gctransitionDll_entrypoint_4(temp_v0);
    }
    return 0;
}

/* extern */

s32 func_800C954C(void) {
    s32 _gctransitionDll_entrypoint_3(BtIntPtr);
    BtIntPtr func_800C91C8(s32);
    BtIntPtr temp_v0;

    temp_v0 = func_800C91C8(4);
    if (temp_v0 != 0) {
        return _gctransitionDll_entrypoint_3(temp_v0);
    }
    return 0;
}

f32 func_800C9588(void) {
    return 300.0f;
}

/* extern */

void func_800C9598(void) {
    void _gctransitionDll_entrypoint_1(BtIntPtr arg0);
    BtIntPtr func_800C9150(s32);
    BtIntPtr func_800C91C8(s32);
    BtIntPtr temp_v0;
    BtIntPtr var_a0;

    temp_v0 = func_800C91C8(4);
    var_a0 = temp_v0;
    if (temp_v0 == 0) {
        var_a0 = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_1(var_a0);
}

/* extern */

s32 func_800C95D4(void) {
    s32 _gctransitionDll_entrypoint_2(BtIntPtr);
    BtIntPtr func_800C91C8(s32);
    BtIntPtr temp_v0;

    temp_v0 = func_800C91C8(4);
    if (temp_v0 != 0) {
        return _gctransitionDll_entrypoint_2(temp_v0);
    }
    return 1;
}

/* extern */

void func_800C9610(void) {
    void _gctransitionDll_entrypoint_6(BtIntPtr arg0);
    BtIntPtr func_800C9150(s32);
    BtIntPtr func_800C91C8(s32);
    BtIntPtr temp_v0;
    BtIntPtr var_a0;

    temp_v0 = func_800C91C8(4);
    var_a0 = temp_v0;
    if (temp_v0 == 0) {
        var_a0 = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_6(var_a0);
}

/* extern */

void func_800C964C(s32 arg0) {
    void _gctransitionDll_entrypoint_7(BtIntPtr arg0, s32 arg1);
    BtIntPtr func_800C9150(s32);
    BtIntPtr func_800C91C8(s32);
    BtIntPtr temp_v0;
    BtIntPtr var_a0;

    temp_v0 = func_800C91C8(4);
    var_a0 = temp_v0;
    if (temp_v0 == 0) {
        var_a0 = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_7(var_a0, arg0);
}

/* extern */

void func_800C968C(s32 arg0, s32 arg1) {
    void _gctransitionDll_entrypoint_7(BtIntPtr arg0, s32 arg1);
    BtIntPtr func_800C9150(s32);
    BtIntPtr func_800C91C8(BT_NATIVE_ONLY(s32));
    BtIntPtr temp_v0;
    BtIntPtr var_a0;

#ifdef BT_NATIVE
    temp_v0 = func_800C91C8(arg0);
#else
    temp_v0 = func_800C91C8();
#endif
    var_a0 = temp_v0;
    if (temp_v0 == 0) {
        var_a0 = func_800C9150(arg0);
    }
    _gctransitionDll_entrypoint_7(var_a0, arg1);
} 

s32 func_800C96CC(BT_PARAM_OR_VOID(s32 bt_a0)) {
    BtIntPtr func_800C91C8(BT_NATIVE_ONLY(s32));
    BtIntPtr temp_v0;

#ifdef BT_NATIVE
    temp_v0 = func_800C91C8(bt_a0);
#else
    temp_v0 = func_800C91C8();
#endif
    if (temp_v0 != 0) {
        return (*(u8 *)((s8 *)temp_v0 + 0xA) == *(u8 *)((s8 *)temp_v0 + 0x1C)) ? 1 : 0;
    }
    return 0;
}

/* extern */

s32 func_800C9714(BT_PARAM_OR_VOID(s32 bt_a0)) {
    s32 _gctransitionDll_entrypoint_3(BtIntPtr);
    BtIntPtr func_800C91C8(BT_NATIVE_ONLY(s32));
    BtIntPtr temp_v0;

#ifdef BT_NATIVE
    temp_v0 = func_800C91C8(bt_a0);
#else
    temp_v0 = func_800C91C8();
#endif
    if (temp_v0 != 0) {
        return _gctransitionDll_entrypoint_3(temp_v0);
    }
    return 1;
}

typedef struct {
    f32 time;
    s8 arg_cnt;
    void *func;
    BtIntPtr arg[5];
    union { BtIntPtr alignment; u8 bytes[0x50]; } rest;
} TimedFunction;
#ifdef BT_NATIVE
#ifdef BT_ILP32
_Static_assert(sizeof(TimedFunction) == 0x70, "ILP32 timer entry must retain N64 record size");
#else
_Static_assert(sizeof(TimedFunction) == 0x88, "LP64 timer entry must include native pointer widths");
#endif
#endif

typedef struct {
    u32 id;
    f32 volume;
    u32 rate;
    f32 position[3];
    f32 near;
    f32 far;
} TimerSoundPayload;

typedef struct {
    BtIntPtr actor;
    s32 dialog;
    s32 arg2;
    f32 position[3];
    s16 arg5;
} TimerDialogPayload;

typedef struct Vector Vector;
void func_800C9B30(u8 *, volatile s32, volatile s32);

void *func_800C9750(f32 time, s32 cnt, void *funcPtr, BtIntPtr arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
#ifndef BT_NATIVE
    u32 vector_begin(s32);
#endif
#ifndef BT_NATIVE
    u32 vector_end(s32);
#endif
#ifndef BT_NATIVE
    s32 vector_new(s32, s32);
#endif
#ifndef BT_NATIVE
    void *vector_insert(Vector **, s32);
#endif
#ifdef BT_NATIVE
    extern Vector *D_8012AB60;
    extern f32 D_8012AB64;
#else
    extern s32 D_8012AB60;
#endif
    TimedFunction *startPtr;
    TimedFunction *retVal;
    TimedFunction *iPtr;
    TimedFunction *endPtr;

    if (D_8012AB60 == 0) {
        D_8012AB60 = vector_new(sizeof(TimedFunction), 8);
    }
    startPtr = (TimedFunction *)vector_begin(D_8012AB60);
    endPtr = (TimedFunction *)vector_end(D_8012AB60);
    if (endPtr == startPtr) {
#ifdef BT_NATIVE
        D_8012AB64 = 0.0f;
#else
        ((f32 *)&D_8012AB60)[1] = 0.0f;
#endif
    } else {
#ifdef BT_NATIVE
        time += D_8012AB64;
#else
        time += ((f32 *)&D_8012AB60)[1];
#endif
    }
    for (iPtr = startPtr; iPtr < endPtr; iPtr++) {
        if (iPtr->time > time)
            break;
    }
    retVal = vector_insert((Vector **)&D_8012AB60, ((BtIntPtr)iPtr - (BtIntPtr)startPtr) / (s32)sizeof(TimedFunction));
    retVal->time = time;
    retVal->arg_cnt = cnt;
    retVal->func = funcPtr;
    retVal->arg[0] = arg0;
    retVal->arg[1] = arg1;
    retVal->arg[2] = arg2;
    retVal->arg[3] = arg3;
    retVal->arg[4] = arg4;
    return retVal;
}

void func_800C986C(void *arg0) {
    TimedFunction *entry = (TimedFunction *)arg0;

    switch (entry->arg_cnt) {
        case 0:
            ((void (*)(void))entry->func)();
            break;
        case 1:
            ((void (*)(s32))entry->func)((s32)entry->arg[0]);
            break;
        case 2:
            ((void (*)(s32, s32))entry->func)((s32)entry->arg[0], (s32)entry->arg[1]);
            break;
        case 3:
#ifdef BT_NATIVE
            if (entry->func == (void *)func_800C9B30)
                ((void (*)(u8 *, s32, s32))entry->func)((u8 *)entry->arg[0], (s32)entry->arg[1], (s32)entry->arg[2]);
            else
                ((void (*)(s32, s32, s32))entry->func)((s32)entry->arg[0], (s32)entry->arg[1], (s32)entry->arg[2]);
#else
            ((void (*)(s32, s32, s32))entry->func)(entry->arg[0], entry->arg[1], entry->arg[2]);
#endif
            break;
        case 4:
            ((void (*)(s32, s32, s32, s32))entry->func)((s32)entry->arg[0], (s32)entry->arg[1], (s32)entry->arg[2], (s32)entry->arg[3]);
            break;
        case 5:
            ((void (*)(s32, s32, s32, s32, s32))entry->func)((s32)entry->arg[0], (s32)entry->arg[1], (s32)entry->arg[2], (s32)entry->arg[3], (s32)entry->arg[4]);
            break;
        case 6:
            ((void (*)(void *))entry->func)(entry->rest.bytes);
            break;
    }
}

void func_800C9974(BT_NATIVE_ONLY(s32 bt_a0) BT_PASS2(, s32 bt_a1))
{
#ifdef BT_NATIVE
    void func_800FC63C(u32, u32);
#endif
    func_800FC63C(BT_NATIVE_ONLY(bt_a0) BT_PASS2(, bt_a1));
}

void func_800C9994(BT_NATIVE_ONLY(s32 bt_a0) BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2))
{
#ifdef BT_NATIVE
    void func_800FCAE0(u32, u32, u32);
#endif
    func_800FCAE0(BT_NATIVE_ONLY(bt_a0) BT_PASS2(, bt_a1) BT_PASS2(, bt_a2));
}

void func_800C99B4(s32 arg0, s32 arg1, s32 arg2) {
    void func_800C3FF0(s32, f32, s32);
    func_800C3FF0(arg0, arg1 / 1000.0f, arg2);
}    typedef struct { s32 unk0; u32 unk4; u32 unk8; f32 unkC; u8 pad10[0x8]; s16 unk18; u8 pad1A[0x2]; f32 unk1C; } Obj1EA1DA0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_800C99F0(u8 *arg0) {
    BT_IDO_ONLY(s32 func_800C4244(s32, s32, s32, u8 *, f32, f32);)
#ifdef BT_NATIVE
    void func_800C4244(s32, f32, u32, f32 *, f32, f32);
    TimerSoundPayload *payload = (TimerSoundPayload *)arg0;
    func_800C4244(payload->id, payload->volume, payload->rate, payload->position, payload->near, payload->far);
#else
    func_800C4244((((Obj1EA1DA0_arg0 *)arg0)->unk0), (*(s32 *)((s8 *)(arg0) + (4))), (*(s32 *)((s8 *)(arg0) + (8))), arg0 + 0xC, (*(f32 *)((s8 *)(arg0) + (0x18))), (((Obj1EA1DA0_arg0 *)arg0)->unk1C));
#endif
}

/* extern */

void func_800C9A38(void *arg0) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    int func_800EEEA8(f32 vec[3]);
#ifdef BT_NATIVE
    TimerDialogPayload *payload = (TimerDialogPayload *)arg0;
    f32 *position = payload->position;
#else
    f32 *position = &((Obj1EA1DA0_arg0 *)arg0)->unkC;
#endif

    if (func_800EEEA8(position) != 0) {
#ifdef BT_NATIVE
        _subaddiedialog_entrypoint_11((Unk80132ED0 *)payload->actor, payload->dialog, payload->arg2, NULL, payload->arg5);
#else
        _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, ((Obj1EA1DA0_arg0 *)arg0)->unk4, ((Obj1EA1DA0_arg0 *)arg0)->unk8, NULL, ((Obj1EA1DA0_arg0 *)arg0)->unk18);
#endif
    } else {
#ifdef BT_NATIVE
        _subaddiedialog_entrypoint_11((Unk80132ED0 *)payload->actor, payload->dialog, payload->arg2, position, payload->arg5);
#else
        _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, ((Obj1EA1DA0_arg0 *)arg0)->unk4, ((Obj1EA1DA0_arg0 *)arg0)->unk8, position, ((Obj1EA1DA0_arg0 *)arg0)->unk18);
#endif
    }
}

void func_800C9AB0(s32 arg0) {
    void func_80090708(s32);
    void func_800A51C0();
    switch (arg0) {
        case 1: func_80090708(1); break;
        case 2: func_80090708(3); break;
        case 3: func_80090708(2); break;
        case 0: func_80090708(0); break;
        case 5: func_800A51C0(); break;
    }
}    typedef struct { u8 pad0[0x12]; u16 unk12; } Obj1EA1DA0_func_800C9B30_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

void func_800C9B30(u8 *arg0, volatile s32 arg1, volatile s32 arg2) {
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 func_801069A4();
    u8 *sp1C;
    u8 **arg0_home = &arg0;
    sp1C = *arg0_home;
    if ((func_801069A4(sp1C) != 0) && (arg1 == ((u32) (((Obj1EA1DA0_func_800C9B30_sp1C *)sp1C)->unk12) >> 1))) {
        func_8010114C((BtIntPtr)sp1C, 0x22, arg2);
    }
}

void func_800C9B84(void) {
#ifndef BT_NATIVE
    s32 vector_clear(s32);
#endif
#ifdef BT_NATIVE
    extern Vector *D_8012AB60;
#else
    extern s32 D_8012AB60;
#endif
    if (D_8012AB60 != 0) {
        vector_clear(D_8012AB60);
    }
}

void func_800C9BB4(f32 time, s32 sound_id, f32 volume, s32 rate) {
    void func_800C9E64(f32, void *, s32, s32, s32);
    func_800C9E64(time, func_800C99B4, sound_id, (s32)(volume * 1000.0f), rate);
}

void func_800C9C04(f32 arg0, u32 arg1, u32 arg2) {
    func_800C9E20(arg0, (u32 *) func_800C9974, arg1, arg2);
}

void func_800C9C34(f32 time, s32 track_id, s32 volume, s32 duration) {
    void func_800C9E64(f32, void *, s32, s32, s32);
    func_800C9E64(time, func_800C9994, track_id, volume, duration);
}

void func_800C9C70(f32 time, u32 id, f32 volume, u32 rate, f32 position[3], f32 near, f32 far) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800C9EF8(f32, void *, void * BT_PASS2(, size_t));
    TimerSoundPayload data;
    data.id = id;
    data.rate = rate;
    data.volume = volume;
    data.near = near;
    data.far = far;
    func_800EE7F8(data.position, position);
    func_800C9EF8(time, func_800C99F0, &data BT_PASS2(, sizeof(data)));
}

void func_800C9CD0(f32 time, BtIntPtr arg1, s32 arg2, s32 arg3, f32 *position, s16 arg5) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    void func_800C9EF8(f32, void *, void * BT_PASS2(, size_t));
    void func_800C9A38(void *);
    TimerDialogPayload data;
    data.actor = arg1;
    data.dialog = arg2;
    data.arg2 = arg3;
    data.arg5 = arg5;
    if (position != NULL) {
        func_800EE7F8(data.position, position);
    } else {
        func_800EFD24(data.position);
    }
    func_800C9EF8(time, func_800C9A38, &data BT_PASS2(, sizeof(data)));
}

void func_800C9D38(f32 arg0, s32 arg1) {
    void func_800C9DE4(f32, void *, s32);
    void func_800C9AB0(s32);
    func_800C9DE4(arg0, &func_800C9AB0, arg1);
}

void func_800C9D60(f32 time, s32 arg0) {
    void func_800C9DE4(f32, void *, s32);
    void func_800A54F8(s32);
    func_800C9DE4(time, func_800A54F8, arg0);
}

void func_800C9D88(f32 arg0) {
    void func_800C9DAC(f32, void *);
    extern s32 func_800A5524;
    func_800C9DAC(arg0, &func_800A5524);
}

void func_800C9DAC(f32 time, void *funcPtr) {
    void *func_800C9750(f32, s32, void *, BtIntPtr, s32, s32, s32, s32);
    func_800C9750(time, 0, funcPtr, 0, 0, 0, 0, 0);
}

void func_800C9DE4(f32 time, void *funcPtr, s32 arg0) {
    void *func_800C9750(f32, s32, void *, BtIntPtr, s32, s32, s32, s32);
    func_800C9750(time, 1, funcPtr, arg0, 0, 0, 0, 0);
}

void func_800C9E20(f32 time, u32 *funcPtr, u32 arg0, u32 arg1) {
    void *func_800C9750(f32, s32, void *, BtIntPtr, s32, s32, s32, s32);
    func_800C9750(time, 2, funcPtr, arg0, arg1, 0, 0, 0);
}

void func_800C9E64(f32 time, void *funcPtr, s32 arg0, s32 arg1, s32 arg2) {
    void *func_800C9750(f32, s32, void *, BtIntPtr, s32, s32, s32, s32);
    func_800C9750(time, 3, funcPtr, arg0, arg1, arg2, 0, 0);
}

void func_800C9EAC(f32 time, void *funcPtr, s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *func_800C9750(f32, s32, void *, BtIntPtr, s32, s32, s32, s32);
    func_800C9750(time, 4, funcPtr, arg0, arg1, arg2, arg3, 0);
}

void func_800C9EF8(f32 time, void *funcPtr, void *argPtr BT_PASS2(, size_t payloadSize)) {
    void *func_800C9750(f32, s32, void *, BtIntPtr, s32, s32, s32, s32);
    void rare_memcpy(void *, void *, int);
    BT_NATIVE_ONLY(if (payloadSize > sizeof(((TimedFunction *)0)->rest.bytes)) return;)
    TimedFunction *q = func_800C9750(time, 6, funcPtr, 0, 0, 0, 0, 0);
#ifdef BT_NATIVE
    rare_memcpy(q->rest.bytes, argPtr, payloadSize);
#else
    rare_memcpy((u8 *)q + 0x20, argPtr, 0x50);
#endif
}

void func_800C9F48(f32 time, u8 *arg1, s32 arg2) {
    void *func_800C9750(f32, s32, void *, BtIntPtr, s32, s32, s32, s32);
    extern void func_800C9B30(u8 *, volatile s32, volatile s32);
    u8 **q = &arg1;
    func_800C9750(time, 3, func_800C9B30, (BtIntPtr)*q, (u32) (*(u16 *)(*q + 0x12)) >> 1, arg2, 0, 0);
}

int func_800C9F94(void) {
#ifndef BT_NATIVE
    s32 vector_size(s32);
#endif
#ifdef BT_NATIVE
    extern Vector *D_8012AB60;
#else
    extern s32 D_8012AB60;
#endif
    return D_8012AB60 == 0 || vector_size(D_8012AB60) == 0;
}

void func_800C9FD0(void) {
    void func_800C986C(void *);
    void rare_memcpy(void *, void *, int);
#ifndef BT_NATIVE
    u32 vector_begin(s32);
#endif
#ifndef BT_NATIVE
    void vector_erase(s32, s32);
#endif
#ifndef BT_NATIVE
    s32 vector_free(s32);
#endif
#ifndef BT_NATIVE
    s32 vector_size(s32);
#endif
#ifdef BT_NATIVE
    extern Vector *D_8012AB60;
#else
    extern s32 D_8012AB60;
#endif
    void *iPtr;
    TimedFunction iFunc;

    if (D_8012AB60 != 0) {
        while (vector_size(D_8012AB60) > 0) {
            iPtr = vector_begin(D_8012AB60);
            rare_memcpy(&iFunc, iPtr, sizeof(iFunc));
            vector_erase(D_8012AB60, 0);
            func_800C986C(&iFunc);
        }
        vector_free(D_8012AB60);
        D_8012AB60 = 0;
    }
}

void func_800CA060(void) {
#ifndef BT_NATIVE
    s32 vector_free(s32);
#endif
#ifdef BT_NATIVE
    extern Vector *D_8012AB60;
#else
    extern s32 D_8012AB60;
#endif
    if (D_8012AB60 != 0) {
        vector_free(D_8012AB60);
        D_8012AB60 = 0;
    }
}

void func_800CA098(void) {
    extern f32 D_8012AB64;
    D_8012AB64 = 0.0f;
}

void func_800CA0A8(void) {
    void func_800C986C(void *);
    f32 func_800D8FF8(void);
    void rare_memcpy(void *, void *, int);
#ifndef BT_NATIVE
    u32 vector_begin(s32);
#endif
#ifndef BT_NATIVE
    void vector_erase(s32, s32);
#endif
#ifndef BT_NATIVE
    s32 vector_free(s32);
#endif
#ifndef BT_NATIVE
    s32 vector_size(s32);
#endif
#ifdef BT_NATIVE
    extern Vector *D_8012AB60;
    extern f32 D_8012AB64;
#else
    extern s32 D_8012AB60;
#endif
    f32 *iPtr;
    TimedFunction iFunc;

    if (func_800C9F94() == 0) {
#ifdef BT_NATIVE
        D_8012AB64 += func_800D8FF8();
#else
        ((f32 *)&D_8012AB60)[1] += func_800D8FF8();
#endif
        while (vector_size(D_8012AB60) > 0) {
            iPtr = (f32 *)vector_begin(D_8012AB60);
#ifdef BT_NATIVE
            if (D_8012AB64 < *iPtr)
#else
            if (((f32 *)&D_8012AB60)[1] < *iPtr)
#endif
                break;
            rare_memcpy(&iFunc, iPtr, sizeof(iFunc));
            vector_erase(D_8012AB60, 0);
            func_800C986C(&iFunc);
        }
        if (vector_size(D_8012AB60) == 0) {
            vector_free(D_8012AB60);
            D_8012AB60 = 0;
        }
    }
}

void func_800CA174(void) {
#ifndef BT_NATIVE
    s32 vector_defrag(s32);
#endif
#ifdef BT_NATIVE
    extern Vector *D_8012AB60;
#else
    extern s32 D_8012AB60;
#endif
    if (D_8012AB60 != 0) {
        D_8012AB60 = vector_defrag(D_8012AB60);
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
Transition *D_8012AB40[5] BT_DATA(4, bss_core2bss1_1, 0x60);
Vector *D_8012AB60 BT_DATA(4, bss_core2bss1_1, 0x80);
f32 D_8012AB64 BT_DATA(4, bss_core2bss1_1, 0x84);
#endif
