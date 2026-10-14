#include "common.h"

void sucoasterplayer_entrypoint_0(void *arg0) {
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _sucoaster_entrypoint_11(void *, f32);
    s32 _sucoaster_entrypoint_16(void *, s32);
    s32 _sucoaster_entrypoint_19(void *);
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    s32 _sucoasterdata_entrypoint_2(u32);
    s32 _sucoasterdata_entrypoint_3(u32);
    s32 _sucoasterhit_entrypoint_1(void *);
    s32 _sucoasterhit_entrypoint_2(void *);
    s32 func_80016B54(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_801021BC(void *, s32);
    void func_80102BF8(void *, s32, f32, f32);
    s32 func_8080076C_sucoasterplayer(void *, void *);
    s32 sucoasterplayer_entrypoint_2(void *, f32);
    int sucoasterplayer_entrypoint_3(void *);
    struct CoasterFlags {
        u8 pad[0x18];
        u32 : 10;
        u32 hit : 1;
    };
    void *sp24;

    sp24 = func_80100094(arg0, 0);
    switch ((u32)*(u16 *)((s8 *)arg0 + 0x72) >> 10) {
    case 2:
        if (func_8080076C_sucoasterplayer(arg0, sp24) == 0) {
            if (sucoasterplayer_entrypoint_3(arg0) != 0) {
                if ((f32)*(s16 *)((s8 *)sp24 + 0xE) >=
                    ((f32)*(s16 *)((s8 *)sp24 + 0xC) * 0.00390625f) *
                    (f32)_sucoasterdata_entrypoint_2(*(u32 *)((s8 *)sp24 + 0x18) >> 28)) {
                    _sucoaster_entrypoint_9(arg0, 3, 6);
                }
            } else if (func_801021BC(arg0, 7) != 0 &&
                       func_80016B54((u32)(*(s32 *)((s8 *)arg0 + 0x64) * 8) >> 30, 1) == 1) {
                _sucoaster_entrypoint_9(arg0, 7, 6);
            }
        }
        sucoasterplayer_entrypoint_2(arg0, 30.0f);
        break;
    case 3:
        _sucoaster_entrypoint_11(arg0, (f32)_sucoasterdata_entrypoint_2(*(u32 *)((s8 *)sp24 + 0x18) >> 28));
        if (func_8080076C_sucoasterplayer(arg0, sp24) == 0) {
            if (sucoasterplayer_entrypoint_3(arg0) != 0) {
                if ((f32)_sucoasterdata_entrypoint_3(*(u32 *)((s8 *)sp24 + 0x18) >> 28) *
                    ((f32)*(s16 *)((s8 *)sp24 + 0xC) / 256.0f) <
                    (f32)*(s16 *)((s8 *)sp24 + 0xE)) {
                    _sucoaster_entrypoint_9(arg0, 8, 6);
                }
                if ((f32)*(s16 *)((s8 *)sp24 + 0xE) <
                    ((f32)*(s16 *)((s8 *)sp24 + 0xC) * 0.00390625f) *
                    (f32)_sucoasterdata_entrypoint_2(*(u32 *)((s8 *)sp24 + 0x18) >> 28)) {
                    _sucoaster_entrypoint_9(arg0, 2, 6);
                }
            } else {
                _sucoaster_entrypoint_9(arg0, 2, 6);
            }
        }
        sucoasterplayer_entrypoint_2(arg0, 30.0f);
        break;
    case 8:
        _sucoaster_entrypoint_11(arg0, (f32)_sucoasterdata_entrypoint_3(*(u32 *)((s8 *)sp24 + 0x18) >> 28));
        if (func_8080076C_sucoasterplayer(arg0, sp24) == 0) {
            if (sucoasterplayer_entrypoint_3(arg0) != 0) {
                if ((f32)_sucoasterdata_entrypoint_3(*(u32 *)((s8 *)sp24 + 0x18) >> 28) *
                    ((f32)*(s16 *)((s8 *)sp24 + 0xC) / 256.0f) >=
                    (f32)*(s16 *)((s8 *)sp24 + 0xE)) {
                    _sucoaster_entrypoint_9(arg0, 3, 6);
                }
            } else {
                _sucoaster_entrypoint_9(arg0, 3, 6);
            }
        }
        sucoasterplayer_entrypoint_2(arg0, 30.0f);
        break;
    case 9:
        _sucoaster_entrypoint_19(arg0);
        _subaddiejoy_entrypoint_9(arg0, (s8 *)arg0 + 0x54, 1);
        func_80102BF8(arg0, 0x3E99999A, 1.0f, 1000.0f);
        sucoasterplayer_entrypoint_2(arg0, 30.0f);
        _sucoaster_entrypoint_16(arg0, 1);
        _sucoaster_entrypoint_16(arg0, 6);
        if (!((struct CoasterFlags *)sp24)->hit &&
            _sucoaster_entrypoint_16(arg0, 5) != 0) {
            _sucoasterhit_entrypoint_2(arg0);
        }
        if (func_80101DDC(arg0) != 0) {
            _sucoaster_entrypoint_9(arg0, 3, 6);
        }
        break;
    case 11:
        _sucoaster_entrypoint_16(arg0, 2);
        if (func_80101DDC(arg0) != 0) {
            _sucoaster_entrypoint_9(arg0, 3, 6);
        }
        break;
    case 12:
    case 13:
    case 18:
        *(u8 *)((s8 *)arg0 + 0x64) &= ~1;
        break;
    case 15:
        _sucoasterhit_entrypoint_1(arg0);
        break;
    case 7:
        _sucoaster_entrypoint_19(arg0);
        sucoasterplayer_entrypoint_3(arg0);
        _sucoaster_entrypoint_16(arg0, 0);
        func_80102BF8(arg0, 0x3E99999A, 1.0f, 1000.0f);
        if (func_80101DDC(arg0) != 0) {
            _sucoaster_entrypoint_9(arg0, 2, 6);
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/player/sucoasterplayer_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/player/sucoasterplayer_entrypoint_2.s")

/* extern */

int sucoasterplayer_entrypoint_3(void *arg0) {
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _sucoaster_entrypoint_6(void *, f32);
    s32 _sucoasterdata_entrypoint_4(u32);
    void *func_80100094(Actor *, u32);
    Actor *sp1C;
    f32 sp18;

    sp1C = func_80100094(arg0, 0);
    sp18 = _subaddiejoy_entrypoint_9(arg0, &((Actor *)arg0)->unk54, 1);
    _sucoaster_entrypoint_6(arg0, (f32) _sucoasterdata_entrypoint_4(sp1C->actorData[0] >> 28) * sp18);
    return sp18 != 0.0f;
}

/* extern */

s32 func_8080076C_sucoasterplayer(void *arg0, void *arg1) {
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    void *_sucoasterdata_entrypoint_1(u32);
    s32 func_80016B30(u32, s32);
    if (((*(u16 *)((s8 *)(_sucoasterdata_entrypoint_1((u32) (*(u32 *)((s8 *)(arg1) + (0x18))) >> 0x1C)) + (0x4A))) != 0) && (func_80016B30((u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) * 8) >> 0x1E, 1) == 1)) {
        return _sucoaster_entrypoint_9(arg0, 9, 6);
    }
    return 0;
}
