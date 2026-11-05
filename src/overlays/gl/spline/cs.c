#include "common.h"
#ifdef BT_NATIVE
#include "native_spline.h"
#include "native_actor.h"
#include "native_spawn_queue.h"
#include "core2/anctrl.h"
typedef NativeSplineContext SplineCSController;
typedef AnimCtrl *SplineCSAnim;
#define CS_ANIM(v) ((AnimCtrl *)(v))
#define CS_ANIM_VALUE(v) ((uintptr_t)(v))
#define CS_PATH(v) ((s8 *)(v))
#else
typedef s32 SplineCSAnim;
#define CS_ANIM(v) (v)
#define CS_ANIM_VALUE(v) (v)
#define CS_PATH(v) (v)
#define SPLINE_FIELD(c, field, original) (original)
#endif

/* extern */

void glsplinecs_entrypoint_0(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800D035C(s32);
    func_800D035C(1);
}

#ifndef BT_NATIVE
typedef struct SplineCSController SplineCSController;
#endif

void func_8080002C_glsplinecs(SplineCSController *arg0, Actor *arg1, s32 arg2) {
    void *func_80105494(Actor *);
    struct {
        u32 pad[16];
        union {
            u32 word;
            struct {

#ifdef BT_NATIVE_LITTLE_ENDIAN
    u32 pad40:5; u32 pitch:9; u32 yaw:9; u32 yawEnd:9;
#else
u32 yawEnd:9;
                u32 yaw:9;
                u32 pitch:9;
                u32 pad40:5;
#endif
} fields;
        } angles;

#ifdef BT_NATIVE_LITTLE_ENDIAN
    unsigned int pad45:20; unsigned int pitchEnd:9; unsigned int pad44:3;
#else
unsigned int pad44:3;
        unsigned int pitchEnd:9;
        unsigned int pad45:20;
#endif
} *state;

    state = func_80105494(arg1);
    state->angles.word = (((((u32)arg1->rotation[1] & 0x1FF) ^ (state->angles.word >> 14)) << 23) >> 9) ^ state->angles.word;
    state->angles.fields.yawEnd = (arg2 >> 16) & 0xFFFF;
    state->angles.fields.pitch = arg1->rotation[0];
    state->pitchEnd = arg2 & 0xFFFF;
    arg1->unk54 = state->angles.fields.yaw;
    arg1->unk50 = state->angles.fields.pitch;
}


typedef struct {

#ifdef BT_NATIVE_LITTLE_ENDIAN
    u32 bit0:1; s32 signedId:10; u32 index:13; u32 id:8;
#else
u32 id:8;
    u32 index:13;
    s32 signedId:10;
    u32 bit0:1;
#endif
f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;

#ifdef BT_NATIVE_LITTLE_ENDIAN
    u32 pad24:6; u32 target:3; u32 wait:4; u32 bit13:1; u32 bit14:1; u32 bit15:1; u32 bit16:1; u32 anim:15;
    u32 actorTarget:6; u32 bit6:1; u32 message:9; u32 pad16:2; u32 counter:8; u32 pad28:3; u32 mode:3;
#else
u32 anim:15;
    u32 bit16:1;
    u32 bit15:1;
    u32 bit14:1;
    u32 bit13:1;
    u32 wait:4;
    u32 target:3;
    u32 pad24:6;
    u32 mode:3;
    u32 pad28:3;
    u32 counter:8;
    u32 pad16:2;
    u32 message:9;
    u32 bit6:1;
    u32 actorTarget:6;
#endif
f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
#ifdef BT_NATIVE_LITTLE_ENDIAN
    u32 pad44:29, splineMode:2, relative:1;
#else
    u8 relative:1;
    u8 splineMode:2;
    u8 pad44:5;
#endif
} SplineCSState;

typedef struct { u8 pad:4; u8 mode:4; } SplineCSActorMode;
typedef struct { u8 pad:6; u8 direction:2; } SplineCSActorDirection;
#ifdef BT_NATIVE
typedef NativeSplineTarget SplineCSTarget;
_Static_assert(sizeof(SplineCSState) == 0x48, "script path-state layout");
#else
typedef struct {
    s32 used:1;
    s32 kind:1;
    u32 pad:14;
    s16 position[3];
    void *object;
} SplineCSTarget;
struct SplineCSController {
    u8 counters[0x80];
    u8 initialCounters[0x80];
    Unk80132ED0 *actors[36];
    f32 elapsed;
    s32 pad194;
    s32 dataId;
    s32 *offsets;
    s32 pad1A0;
    SplineCSTarget *entries;
};

#endif

void func_80800228_glsplinecs(SplineCSController *arg0, Actor *arg1, s32 arg2, s32 arg3, s32 *arg4) {
    void *func_80105494(Actor *);
    SplineCSState *state;
    s32 command;

    state = func_80105494(arg1);
    state->splineMode = arg3;
    command = *arg4;
    if (command == 0x10006) {
        state->unk38 = state->unkC;
        state->unk3C = (f32)arg2 / 4000000.0f;
        state->relative = 0;
        return;
    }
    if (command == 0x10005) {
        state->unk38 = SPLINE_FIELD(arg0, value0, arg0->elapsed);
        state->unk3C = (f32)arg4[state->index] + SPLINE_FIELD(arg0, value0, arg0->elapsed);
        state->relative = 1;
    }
}

void func_80800310_glsplinecs(SplineCSController *arg0, Actor *arg1, s32 arg2, s32 arg3) {
    void *func_80105494(Actor *);
#ifdef BT_NATIVE
    void *func_800D7520(s32);
#else
    s32 func_800D7520(s32);
#endif
    f32 func_800C7AE4(u8 *, f32, f32);
    SplineCSState *state;

    state = func_80105494(arg1);
    state->unk30 = state->unk14;
    state->unk34 = func_800C7AE4(func_800D7520(state->signedId), (f32)arg2 / 4000000.0f, 1.0f) / ((f32)arg3 * 0.25f);
}

/* extern */

SplineCSAnim func_808003A8_glsplinecs(Actor *arg0) {
#ifdef BT_NATIVE
    AnimCtrl *func_80104248(void *);
    AnimCtrl *func_801042B8(Actor *);
#else
    s32 func_80104248(void *);
    s32 func_801042B8(s32);
#endif
#ifndef BT_NATIVE
    struct anctrl_s;
#endif
    void anctrl_reset(struct anctrl_s *);
    SplineCSAnim var_v1;
    SplineCSAnim temp_v0_2;

    var_v1 = func_80104248(arg0);
    if (var_v1 == 0) {
#ifdef BT_NATIVE
        temp_v0_2 = func_801042B8(arg0);
#else
        temp_v0_2 = func_801042B8((s32) arg0);
#endif
        var_v1 = temp_v0_2;
        anctrl_reset((struct anctrl_s *) var_v1);
    }
    return var_v1;
}

#ifdef BT_NATIVE
static void native_spline_spawn_queued(uintptr_t id, uintptr_t word, uintptr_t path) {
    glsplinefuncs_entrypoint_1((s32)id, (SplineSpawnWord){(s32)word}, (s32)path);
}
#endif

void glsplinecs_entrypoint_1(SplineCSController *arg0, Actor *arg1) {
    void *func_80105494(Actor *);
    u8 *func_800D674C(s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_800FFA88(Unk80132ED0 *);
    void func_800DA544(s32);
#ifdef BT_NATIVE
    void *func_800D7520(s32);
#else
    s32 func_800D7520(s32);
#endif
    f32 func_800D7708(s32, f32, s32);
    void func_800D7754(Actor *, s32);
    void func_8009086C(s32);
    void func_80090708(s32);
    s32 func_8008FFE8(void);
    s32 _seqdefine_entrypoint_0(s32);
#ifdef BT_NATIVE
    Actor *_subaddiefind_entrypoint_12(s32);
#else
    Unk80132ED0 *_subaddiefind_entrypoint_12(s32);
#endif
    void _subaddiefade_entrypoint_1(Actor *, s32);
    void func_80105BE0(Actor *, s32);
#ifdef BT_NATIVE
    SplineCSAnim func_808003A8_glsplinecs(Actor *);
#else
    s32 func_808003A8_glsplinecs(Actor *);
#endif
#ifndef BT_NATIVE
    void func_8008B10C(s32, f32);
#endif
#ifndef BT_NATIVE
    void _chbaddiesetup_entrypoint_3(s32 *, s32, s32, s32);
#endif
    void _chintrotext_entrypoint_1(s32, s32, s32, s32);
#ifdef BT_NATIVE
    void *_gccubesearch_entrypoint_17(s32, void *);
#else
    s32 _gccubesearch_entrypoint_17(s32, s32);
#endif
#ifndef BT_NATIVE
    void _glsplinefuncs_entrypoint_0(s32, s32 *, f32 *, f32 *, s32, s32 *, s32 *);
#endif
#ifndef BT_NATIVE
    void _gspropctrl_entrypoint_10(s32, u8 *);
#endif
    s32 _seqdat_entrypoint_0(s32, s32);
#ifndef BT_NATIVE
    void anctrl_setDuration(s32, f32);
#endif
#ifndef BT_NATIVE
    void anctrl_setIndex(s32, u32);
#endif
#ifndef BT_NATIVE
    void anctrl_setPlaybackType(s32, s32);
#endif
#ifndef BT_NATIVE
    void anctrl_start(s32);
#endif
#ifndef BT_NATIVE
    void func_8008B188(s32, s32);
#endif
#ifndef BT_NATIVE
    void func_8008B1C8(s32, f32);
#endif
    void func_800A50B0(s32);
#ifdef BT_NATIVE
    void func_800C04C8(s32, s32, s32, s32, void (*)(s32, s32, s32));
#else
    void func_800C04C8(s32, s32, s32, s32, s32 *);
#endif
#ifdef BT_NATIVE
    void func_800C84A4(s8 *, s32);
#else
    void func_800C84A4(s32, s32);
#endif
    void func_800DA3B8(s32, s32);
    void func_8010FD38(s32, f32);
    void func_8080002C_glsplinecs(SplineCSController *, Actor *, s32);
    void func_80800228_glsplinecs(SplineCSController *, Actor *, s32, s32, s32 *);
    void func_80800310_glsplinecs(SplineCSController *, Actor *, s32, s32);
#ifndef BT_NATIVE
    extern s32 _glsplinecs_entrypoint_0;
#endif
#ifndef BT_NATIVE
    extern s32 _glsplinefuncs_entrypoint_1;
#endif
    Actor *var_a0;
    uintptr_t var_a1_2;
    SplineCSState *temp_s2;
    SplineCSState *temp_v0_7;
    SplineCSTarget *temp_a0_4;
    SplineCSTarget *temp_v0_13;
    Unk80132ED0 *var_a1_4;
    s32 *var_s1;
    f32 var_f0;
    s32 spD8;
    f32 spD4;
    f32 spC8[3];
#ifdef BT_NATIVE
    f32 spC4, spC0;
#else
    s32 spC4;
    s32 spC0;
#endif
    s32 sp84;
    f32 spDC;
    s32 *temp_s5;
    s32 temp_a0;
    uintptr_t temp_a0_7;
    uintptr_t var_s0;
    /* Keep the script index available across the state writes below. */
    u32 indexTemp;
    s32 temp_t9_2;
    s32 temp_v0_10;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_a0_3;
    s32 temp_v0_8;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1_3;
    u32 temp_t3_2;
    u8 *temp_a0_5;
    u8 *temp_a0_6;
    s32 temp_a2;

#ifdef BT_NATIVE
    s32 command_count, opcode, operand;
#endif
    temp_s2 = func_80105494(arg1);
#ifdef BT_NATIVE
    if (!temp_s2) return;
    temp_s5 = native_spline_script(arg0, temp_s2->id, &command_count);
    if (!temp_s5) goto invalid_script;
#else
    temp_s5 = (s32 *) ((u8 *) func_800D674C(arg0->dataId) + arg0->offsets[temp_s2->id - 1]);
#endif
    if (temp_s2->index == 0) {
        temp_s2->index = 1;
    }
    if ((temp_s2->unk20 == 0.0f) && ((temp_s2->wait) == 0) && ((temp_s2->message) == 0) && ((temp_s2->counter) == 0) && !(temp_s2->unk2C > 0.00f)) {
        if (temp_s2->unk8 != 0.000f) {
            if (*temp_s5 == 0x10005) {
                temp_s2->unk4 = SPLINE_FIELD(arg0, value0, arg0->elapsed) - temp_s2->unk8;
            }
            temp_s2->unk8 = 0.0000f;
        }

#ifdef BT_NATIVE
        if (!native_spline_command_words(temp_s5, command_count, temp_s2->index)) goto invalid_script;
#endif
        var_s1 = (s32 *)((u8 *)temp_s5 + temp_s2->index * 4);

        while ((var_s1[1] != 2) && (((*temp_s5 == 0x10005) && ((f32) (*(s32 *)((s8 *)(var_s1) + (0))) <= (SPLINE_FIELD(arg0, value0, arg0->elapsed) - temp_s2->unk4))) || ((*temp_s5 == 0x10006) && (((f32) (*(s32 *)((s8 *)(var_s1) + (0))) / 4000000.0f) <= temp_s2->unkC))) && (temp_s2->unk20 == 0.00000f) && ((temp_s2->wait) == 0) && ((temp_s2->message) == 0) && ((temp_s2->counter) == 0) && !(temp_s2->unk2C > 0.000000f)) {
#ifdef BT_NATIVE
            opcode = (u32)var_s1[1] >> 16; operand = var_s1[1] & 0xFFFF;
            if (((opcode == 0x20 || opcode == 0x21) && operand >= 128) ||
                ((opcode == 0x22 || opcode == 0x23 || opcode == 0x25 || opcode == 0x2B || opcode == 0x2C) && operand >= 33) ||
                (opcode == 0x2A && (operand & 0xFFF) > 255) ||
                (opcode == 0xA && ((operand & 63) >= 33 || ((operand >> 6) & 63) >= 33))) goto invalid_script;
#endif
            switch (var_s1[1] >> 0x10) {
            case 0x9:
                func_800D7754(arg1, var_s1[1] & 0xFFFF);
                break;
            case 0x7:
                if (!temp_s2->bit13 && !temp_s2->actorTarget && ((temp_s2->target) == 0) && temp_s2->bit15) {
                    arg1->unk54 = (f32) (var_s1[1] & 0xFFFF);

                }
                break;
            case 0x8:
                if (!temp_s2->bit13 && !temp_s2->actorTarget && ((temp_s2->target) == 0) && temp_s2->bit14) {
                    arg1->unk50 = (f32) (var_s1[1] & 0xFFFF);

                }
                break;
            case 0xE:
                var_s0 = CS_ANIM_VALUE(func_808003A8_glsplinecs(arg1));
                var_s1 = (s32 *)((u8 *)temp_s5 + temp_s2->index * 4);
                temp_s2->unk1C = (f32) (*(s32 *)((s8 *)(var_s1) + (8))) / 4000000.00f;
                temp_s2->anim = _seqdat_entrypoint_0((*(s32 *)((s8 *)(var_s1) + (4))) & 0xFFFF, 0);
                anctrl_setIndex(CS_ANIM(var_s0), temp_s2->anim);
                anctrl_setDuration(CS_ANIM(var_s0), temp_s2->unk1C);
                func_8008B188(CS_ANIM(var_s0), 1);
                anctrl_start(CS_ANIM(var_s0));
                func_8008B10C(CS_ANIM(var_s0), 0.00001f);
                temp_s2->index += 1;
                break;
            case 0xF:
                var_s0 = CS_ANIM_VALUE(func_808003A8_glsplinecs(arg1));
                var_f0 = (f32) temp_s5[temp_s2->index + 2] / 4000000.000f;
                func_8008B1C8(CS_ANIM(var_s0), var_f0);
                temp_s2->index += 1;
                break;
            case 0x10:
                anctrl_setPlaybackType(func_808003A8_glsplinecs(arg1), 1);
                break;
            case 0x11:
                anctrl_setPlaybackType(func_808003A8_glsplinecs(arg1), 2);
                break;
            case 0x30:
                arg1->unk64_19 = var_s1[1] & 0xFFFF;
                break;
            case 0x38:
                func_80105BE0(arg1, var_s1[1] & 0xFFFF);
                break;
            case 0x36:
                arg1->unk7A_11 = var_s1[1] & 0xFFFF;
                break;
            case 0x37:
#ifdef BT_NATIVE
                arg1->pad74_0 = (arg1->pad74_0 & ~15u) | (var_s1[1] & 15);
#else
                ((SplineCSActorMode *)((u8 *)arg1 + 0x77))->mode = var_s1[1] & 0xFFFF;
#endif
                break;
            case 0x35:
                var_f0 = 0.0000000f;
                if (var_s1[1] & 0xFFFF) {
                    var_f0 = 5.0f;
                }
                spDC = var_f0;
                func_8010FD38(func_8008FFE8(), var_f0);
                break;
            case 0x34:
                func_800DA544(0);
                break;
            case 0x12:

                temp_s2->unk14 = func_800D7708(temp_s2->signedId, temp_s2->unkC, var_s1[1] & 0xFFFF);
                break;
            case 0x15:
#ifdef BT_NATIVE
                if (!_glsplinefuncs_entrypoint_0(var_s1[1] & 0xFFFF, &spD8, &spD4, &spC8[0], temp_s2->signedId, &spC4, &spC0)) break;
#else
                _glsplinefuncs_entrypoint_0(var_s1[1] & 0xFFFF, &spD8, &spD4, &spC8[0], temp_s2->signedId, &spC4, &spC0);
#endif
                temp_s2->signedId = spD8;
                temp_s2->unkC = spD4;
                arg1->position[0] = spC8[0];
                arg1->position[1] = spC8[1];
                arg1->position[2] = spC8[2];
                break;
            case 0x28:
                temp_v0_2 = var_s1[1] & 0xFFFF;
                var_v1_3 = (temp_v0_2 & 0x8000) ? (temp_v0_2 | 0xFFFF0000) : temp_v0_2;
                var_v0 = (var_v1_3 >= 0) ? var_v1_3 : -var_v1_3;
                if (var_v1_3 < 0) {
#ifdef BT_NATIVE
                    arg1->unk79_1 = 1; arg1->unk79_0 = 0;
#else
                    ((SplineCSActorDirection *)((u8 *)arg1 + 0x79))->direction = 2;
#endif
                } else {
                    var_a1_2 = (var_v1_3 > 0) ? 1 : 0;
#ifdef BT_NATIVE
                    arg1->unk79_1 = 0; arg1->unk79_0 = var_a1_2;
#else
                    ((SplineCSActorDirection *)((u8 *)arg1 + 0x79))->direction = var_a1_2;
#endif
                }
                if (var_v0 != 0) {
                    *(f32 *)&arg1->actorData[0] = (f32) var_v0 * 0.25f;
                } else {
                    *(f32 *)&arg1->actorData[0] = 0.00000000f;
                }
                *(f32 *)&arg1->actorData[1] = 0.000000000f;
                break;
            case 0x31:
                _subaddiefade_entrypoint_1(arg1, var_s1[1] & 0xFFFF);
                break;
            case 0x29:
                temp_v0_3 = (*(s32 *)((s8 *)(var_s1) + (8)));
                func_800C04C8(var_s1[1] & 0xFFFF, (temp_v0_3 >> 0x18) & 0x3F, temp_v0_3 & 0xFFFF, (temp_v0_3 >> 0x10) & 0xF, &_glsplinecs_entrypoint_0);
                temp_s2->index += 1;
                break;
            case 0x1B:
                temp_a0 = _seqdefine_entrypoint_0((u16)(var_s1[1] & 0x3FFF));
                var_a1_2 = (((*(s32 *)((s8 *)((s32 *)((u8 *)temp_s5 + temp_s2->index * 4)) + (4))) & 0xFFFF) & 0x4000) ? 1 : 0;
                func_800DA3B8(temp_a0, var_a1_2);
                break;
            case 0x22:
                temp_v0_4 = var_s1[1] & 0xFFFF;
                if (temp_v0_4 == 0) {
                    var_a1_2 = (uintptr_t)arg1->unk0;
                } else {
                    var_a1_2 = (uintptr_t)arg0->actors[temp_v0_4];
                }
#ifdef BT_NATIVE
                if (!var_a1_2) goto invalid_script;
#endif
                func_800FFA88((Unk80132ED0*)var_a1_2);
                break;
            case 0x23:
                temp_v0_5 = var_s1[1] & 0xFFFF;
                if (temp_v0_5 == 0) {
                    var_a1_2 = (uintptr_t)arg1->unk0;
                } else {
                    var_a1_2 = (uintptr_t)arg0->actors[temp_v0_5];
                }
#ifdef BT_NATIVE
                if (!var_a1_2) goto invalid_script;
#endif
                func_800FFA88((Unk80132ED0*)var_a1_2);
                func_800A50B0(2);
                break;
            case 0x24:
#ifdef BT_NATIVE
            {
                Unk80132ED0 *marker = arg1->unk0;
#endif
#ifdef BT_NATIVE
                _chbaddiesetup_entrypoint_3(native_spline_spawn_queued, var_s1[1] & 0xFFFF, var_s1[2], temp_s2->signedId);
#else
                _chbaddiesetup_entrypoint_3(&_glsplinefuncs_entrypoint_1, var_s1[1] & 0xFFFF, (*(s32 *)((s8 *)(var_s1) + (8))), temp_s2->signedId);
#endif
#ifdef BT_NATIVE
                if (marker) {
                    arg1 = func_80106790(marker);
                    if (!arg1) return;
                }
                temp_s2 = func_80105494(arg1);
                if (!temp_s2) return;
            }
#endif
                temp_s2->index += 1;
                break;
            case 0x13:
                indexTemp = temp_s2->index;
                temp_s2->unk20 = (f32) (var_s1[1] & 0xFFFF) * 0.25f;
                if (*temp_s5 == 0x10005) {

                    temp_s2->unk8 = SPLINE_FIELD(arg0, value0, arg0->elapsed) - temp_s2->unk4;
                }
                break;
            case 0x14:
                indexTemp = temp_s2->index;
                temp_s2->wait = (var_s1[1] & 0xFFFF) - 0x69;
                if (*temp_s5 == 0x10005) {

                    temp_s2->unk8 = SPLINE_FIELD(arg0, value0, arg0->elapsed) - temp_s2->unk4;
                }
                break;
            case 0x1F:
                indexTemp = temp_s2->index;
                temp_s2->unk2C = (f32) (var_s1[1] & 0xFFFF);
                break;
            case 0x1C:
                indexTemp = temp_s2->index;
                temp_s2->message = (var_s1[1] & 0xFFFF) + 1;
                temp_s2->bit6 = 0;
                if (*temp_s5 == 0x10005) {

                    temp_s2->unk8 = SPLINE_FIELD(arg0, value0, arg0->elapsed) - temp_s2->unk4;
                }
                break;
            case 0x1D:
                indexTemp = temp_s2->index;
                temp_s2->message = (var_s1[1] & 0xFFFF) + 1;
                temp_s2->bit6 = 1;
                if (*temp_s5 == 0x10005) {

                    temp_s2->unk8 = SPLINE_FIELD(arg0, value0, arg0->elapsed) - temp_s2->unk4;
                }
                break;
            case 0x1E:
                func_800DA544(0x644);
                break;
            case 0x2A:
                temp_v0_6 = var_s1[1] & 0xFFFF;
                var_v1_3 = (temp_v0_6 >> 0xC) & 0x3F;
                var_s0 = temp_v0_6 & 0xFFF;
                temp_v0_6 = 0;
#ifdef BT_NATIVE
                var_a0 = native_spline_actor(arg0, arg1, var_v1_3);
                if (!var_a0) goto invalid_script;
#else
                if (var_v1_3 == 0) {
                    var_a0 = arg1;
                } else {
                    var_a0 = func_80106790(arg0->actors[var_v1_3]);
                }
#endif
                temp_v0_7 = func_80105494(var_a0);
#ifdef BT_NATIVE
                if (!temp_v0_7) goto invalid_script;
#endif
                temp_v0_7->id = var_s0;
                temp_v0_7->unk4 = SPLINE_FIELD(arg0, value0, arg0->elapsed);
                temp_v0_7->index = 0;
                temp_v0_7->unk8 = 0.0000000000f;
                break;
            case 0x25:
                arg0->actors[var_s1[1] & 0xFFFF] = arg1->unk0;
                break;
            case 0x2B:
                temp_v0_8 = var_s1[1] & 0xFFFF;
#ifdef BT_NATIVE
                var_a0 = native_spline_actor(arg0, arg1, temp_v0_8);
                if (!var_a0) goto invalid_script;
#else
                if (temp_v0_8 == 0) {
                    var_a0 = arg1;
                } else {
                    var_a0 = func_80106790(arg0->actors[temp_v0_8]);
                }
#endif
                temp_v0_7 = func_80105494(var_a0);
#ifdef BT_NATIVE
                if (!temp_v0_7) goto invalid_script;
#endif
                temp_v0_7->unk20 = 1700000.0f;
                if (*temp_s5 == 0x10005) {
                    temp_v0_7->unk8 = SPLINE_FIELD(arg0, value0, arg0->elapsed) - temp_s2->unk4;
                }
                break;
            case 0x2C:
                temp_v0_10 = var_s1[1] & 0xFFFF;
#ifdef BT_NATIVE
                var_a0 = native_spline_actor(arg0, arg1, temp_v0_10);
                if (!var_a0) goto invalid_script;
#else
                if (temp_v0_10 == 0) {
                    var_a0 = arg1;
                } else {
                    var_a0 = func_80106790(arg0->actors[temp_v0_10]);
                }
#endif
                temp_v0_7 = func_80105494(var_a0);
#ifdef BT_NATIVE
                if (!temp_v0_7) goto invalid_script;
#endif
                temp_v0_7->unk20 = 0.00000000000f;
                break;
            case 0xA:
                var_s0 = (var_s1[1] >> 6) & 0x3F;
                var_v1_3 = var_s1[1] & 0x3F;
#ifdef BT_NATIVE
                var_a0 = native_spline_actor(arg0, arg1, var_v1_3);
                if (!var_a0) goto invalid_script;
#else
                if (var_v1_3 == 0) {
                    var_a0 = arg1;
                } else {
                    var_a0 = func_80106790(arg0->actors[var_v1_3]);
                }
#endif
                temp_v0_7 = func_80105494(var_a0);
#ifdef BT_NATIVE
                if (!temp_v0_7) goto invalid_script;
#endif
                temp_v0_7->actorTarget = var_s0;
                temp_v0_7->target = 0;
                temp_v0_7->bit13 = 0;
                temp_v0_7->bit15 = 0;
                temp_v0_7->bit14 = 0;
                break;
            case 0x2F:
                var_a1_2 = (var_s1[1] & 0xFFFF) ? 0 : 2;
                func_80090708(var_a1_2);
                break;
#ifdef BT_NATIVE
            case 0xB: {
                void *_gccubesearch_entrypoint_17(s32, void *);
                void _gspropctrl_entrypoint_10(void *, void *);
                s32 id = var_s1[1] & 0xFFFF, slot;
                Actor *target_actor;
                Unk80132ED0 *marker;
                void *prop;
                if (!arg0->cache) goto invalid_script;
                if (!id) {
                    if (temp_s2->target) arg0->cache[temp_s2->target - 1].used = 0;
                    temp_s2->target = 0;
                    break;
                }
                target_actor = _subaddiefind_entrypoint_12(id);
                marker = target_actor ? target_actor->unk0 : NULL;
                prop = marker ? NULL : _gccubesearch_entrypoint_17(id, NULL);
                if (!marker && !prop) break;
                for (slot = 0; slot < 7 && arg0->cache[slot].used; ++slot) {}
                if (slot == 7) break;
                temp_s2->actorTarget = temp_s2->bit13 = temp_s2->bit15 = temp_s2->bit14 = 0;
                temp_s2->target = slot + 1;
                arg0->cache[slot].used = 1;
                arg0->cache[slot].fixed = marker == NULL;
                if (marker) arg0->cache[slot].marker = marker;
                else _gspropctrl_entrypoint_10(prop, arg0->cache[slot].position);
                break;
            }
#else
            case 0xB:
                temp_a0_3 = var_s1[1] & 0xFFFF;
                if (temp_a0_3 != 0) {
                    var_s0 = 0;
                    sp84 = temp_a0_3;
                    var_s1 = (s32 *)_subaddiefind_entrypoint_12(temp_a0_3);
                    if (var_s1 == NULL) {
                        var_s0 = _gccubesearch_entrypoint_17((s32) sp84, 0);
                    }
                    var_v1_3 = 0;
                    temp_s2->actorTarget = 0;
                    temp_s2->bit13 = 0;
                    temp_s2->bit15 = 0;
                    temp_s2->bit14 = 0;
                    do {
                        temp_a0_3 = (s32)&arg0->entries[var_v1_3];
                        temp_v0_13 = (SplineCSTarget *)temp_a0_3;
                        if (((SplineCSTarget *)temp_a0_3)->used == 0) {
                            temp_s2->target = var_v1_3 + 1;
                            if (var_s1 != NULL) {
                                ((SplineCSTarget *)temp_a0_3)->used = 1;
                                ((SplineCSTarget *)temp_a0_3)->kind = 0;
                                ((SplineCSTarget *)temp_a0_3)->object = ((Unk80132ED0 *)var_s1)->unk0;
                            } else if (var_s0 != 0) {
                                temp_a0_3 = (s32)var_s0;
                                temp_v0_13->used = 1;
                                temp_v0_13->kind = 1;
                                _gspropctrl_entrypoint_10((s32)temp_a0_3, (u8 *)temp_v0_13->position);
                            }
                            var_v1_3 = 7;
                        }
                        var_v1_3 += 1;
                    } while (var_v1_3 < 7);
                } else {
                    temp_v0_13 = &arg0->entries[temp_s2->target];
                    temp_v0_13--;
                    temp_v0_13->used = 0;
                    temp_s2->target = 0;
                }
                break;
#endif
            case 0xD:
                if (var_s1[1] & 0xFFFF) {
                    arg1->unk64_18 = 1;
                } else {
                    arg1->unk64_18 = 0;
                }
                break;
            case 0x20:
                temp_v0_6 = var_s1[1] & 0xFFFF;
                temp_a0_5 = &arg0->counters[temp_v0_6];
                temp_a2 = *temp_a0_5;
                if (temp_a2 != 0) {
                    *temp_a0_5 = temp_a2 - 1;

                    temp_t3_2 = temp_s2->index;

                    temp_v0_6 = (*(s32 *)((s8 *)((s32 *)((u8 *)temp_s5 + temp_t3_2 * 4)) + (4))) & 0xFFFF;
                }
                indexTemp = temp_s2->index;
                temp_s2->counter = temp_v0_6 + 1;
                if (*temp_s5 == 0x10005) {

                    temp_s2->unk8 = SPLINE_FIELD(arg0, value0, arg0->elapsed) - temp_s2->unk4;
                }
                break;
#ifdef BT_NATIVE
            case 0x21:
                arg0->counters[var_s1[1] & 0xFFFF] = arg0->initial_counters[var_s1[1] & 0xFFFF];
                break;
#else
            case 0x21:
                temp_a0_3 = (s32)&arg0->counters[var_s1[1] & 0xFFFF];
                (*(u8 *)((s8 *)(((u8 *)temp_a0_3)) + (0))) = (*(u8 *)((s8 *)(((u8 *)temp_a0_3)) + (0x80)));
                break;
#endif
            case 0xC:
                indexTemp = temp_s2->index;
                temp_s2->mode = var_s1[1] & 0xFFFF;
                break;
            case 0x2D:
                temp_a0_7 = (uintptr_t)func_800D7520(temp_s2->signedId);
                var_a1_2 = ((*(s32 *)((s8 *)((s32 *)((u8 *)temp_s5 + temp_s2->index * 4)) + (4))) & 0xFFFF) ? 1 : 0;
                func_800C84A4(CS_PATH(temp_a0_7), var_a1_2);
                break;
            case 0x2E:
                func_8009086C(var_s1[1] & 0xFFFF);
                break;
            case 0x26:
                func_80800228_glsplinecs(arg0, arg1, (*(s32 *)((s8 *)(var_s1) + (0xC))), 1, temp_s5);
                func_8080002C_glsplinecs(arg0, arg1, (*(s32 *)((s8 *)((s32 *)((u8 *)temp_s5 + temp_s2->index * 4)) + (8))));
                temp_s2->index += 2;
                break;
            case 0x27:
                func_80800228_glsplinecs(arg0, arg1, (*(s32 *)((s8 *)(var_s1) + (0xC))), 2, temp_s5);
                var_s1 = (s32 *)((u8 *)temp_s5 + temp_s2->index * 4);
                func_80800310_glsplinecs(arg0, arg1, (*(s32 *)((s8 *)(var_s1) + (0xC))), (*(s32 *)((s8 *)(var_s1) + (8))));
                temp_s2->index += 2;
                break;
            case 0x33:
                _chintrotext_entrypoint_1(0x18BC, var_s1[1] & 0xFFFF, 2, 2);
                break;
            }
#ifdef BT_NATIVE
            if (temp_s2->index > 0x1FFD || !native_spline_command_words(temp_s5, command_count, temp_s2->index + 2)) goto invalid_script;
#endif
            var_s1 = (temp_s2->index += 2, (s32 *)((u8 *)temp_s5 + temp_s2->index * 4));
        }
        if (var_s1[1] == 2) {
            temp_s2->id = 0;
            temp_s2->index = 0;
            temp_s2->unk4 = 0.000000000000f;
            temp_s2->unk8 = 0.0000000000000f;
        }
    }
#ifdef BT_NATIVE
    return;
invalid_script:
    temp_s2->id = temp_s2->index = 0;
    temp_s2->unk4 = temp_s2->unk8 = 0;
#endif

}
