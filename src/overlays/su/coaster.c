#include "common.h"

/* extern */

 s32 sucoaster_entrypoint_0(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 pad0[0xC];
        s16 scale;
        u8 padE[9];
        s8 sector;
        u32 track : 4;
        u32 pad18_24 : 4;
        u32 route : 1;
        u32 active : 1;
        u32 pad18_0 : 22;
    } CoasterData;
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    s32 _subaddiesect_entrypoint_1(Actor *);
    s32 _sucoasterdata_entrypoint_0(Actor *);
    u32 *func_80100074(Actor *, u32, u32);
    void func_80107200(Actor *);
    void func_80802130_sucoaster(Actor *, void *, s16);
    CoasterData *temp_s0;

    temp_s0 = (CoasterData *)func_80100074(arg0, 0, arg1 + 0x1C);
    temp_s0->track = _sucoasterdata_entrypoint_0(arg0);
    temp_s0->sector = _subaddiesect_entrypoint_1(arg0);
    _subaddierouteDll_entrypoint_3(arg0, temp_s0, arg0->position);
    func_80802130_sucoaster(arg0, temp_s0, 0x190);
    temp_s0->route = 1;
    temp_s0->active = 1;
    temp_s0->scale = arg0->scale * 256.0f;
    func_80107200(arg0);
    return 1;
}

/* extern */

void sucoaster_entrypoint_1(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void func_80802728_sucoaster(Actor *, u8 * volatile);
    func_80802728_sucoaster(arg0, func_80100094(arg0, 0U));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_2.s")

void func_8080027C_sucoaster(Actor *arg0, void *arg1) {
    typedef struct {
        u8 pad0[0x10];
        s16 radius;
        u8 unk12;
        s8 speed;
        u8 pad14[2];
        u8 counter;
        u8 pad17;
        u32 track : 4;
        u32 pad18_26 : 2;
        u32 alternate : 1;
        u32 direction : 1;
        u32 route : 1;
        u32 pad18_22 : 1;
        u32 hit : 1;
        u32 pad18_0 : 21;
    } CoasterData;
    typedef struct {
        u8 pad0[0x78];
        u32 pad78_4 : 28;
        u32 busy : 1;
        u32 pad78_0 : 3;
    } ActorFlags;
    void _subaddiefade_entrypoint_3(Actor *);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    void _subaddierouteDll_entrypoint_6(Actor *, void *, u8, s32, f32, s32, s32);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    void *_sucoasterdata_entrypoint_1(u32);
    s32 _sucoasterdata_entrypoint_3(u32);
    s32 _sucoasterhit_entrypoint_1(void *);
    s32 _sucoasterhit_entrypoint_2(void *);
    s32 func_8001210C(s32);
    s32 func_800D9058(f32);
    f32 func_800DC178(f32, f32);
    s32 func_800DC298(f32);
    s32 func_80101DDC(Actor *);
    void func_80102924(void *, f32);
    void func_80102BF8(void *, f32, f32, f32);
    s32 func_80102CF4(Actor *, f32);
    s32 func_80107070(Actor *, s32);
    void func_808020B8_sucoaster(Actor *, void *, f32);
    f32 func_8080230C_sucoaster(Actor *, void *);
    s32 func_80802400_sucoaster(Actor *, void *);
    s32 func_80802550_sucoaster(s32, s32);
    f32 func_8080264C_sucoaster(void *, s32);
    s32 sucoaster_entrypoint_7(Actor *, s32, f32);
    void sucoaster_entrypoint_8(Actor *);
    s32 sucoaster_entrypoint_9(Actor *, s32, s32);
    s32 sucoaster_entrypoint_10(Actor *, s32);
    void sucoaster_entrypoint_11(Actor *, f32);
    s32 sucoaster_entrypoint_13(Actor *);
    s32 sucoaster_entrypoint_14(Actor *);
    void sucoaster_entrypoint_15(Actor *);
    s32 sucoaster_entrypoint_16(Actor *, s32);
    void sucoaster_entrypoint_19(Actor *);
    u8 *config;
    s32 choice1;
    s32 choice2;
    s32 choice3;
    f32 turn;
    u8 counter;
    f32 direction;

    config = _sucoasterdata_entrypoint_1(((CoasterData *)arg1)->track);
    switch (arg0->unk70_10) {
    case 1:
        choice1 = func_800DC298(0.5f) ? 2 : 3;
        if (!sucoaster_entrypoint_9(arg0, choice1, 0)) {
            sucoaster_entrypoint_9(arg0, 3, 0);
        }
        break;
    case 2:
        sucoaster_entrypoint_19(arg0);
        if (arg0->unk58 <= 0.0f && func_800DC298(0.03f)) {
            if (((CoasterData *)arg1)->alternate) {
                sucoaster_entrypoint_9(arg0, 3, 2);
                ((CoasterData *)arg1)->alternate = 0;
            } else if (sucoaster_entrypoint_9(arg0, 3, 0)) {
                _subaddierouteDll_entrypoint_6(arg0, arg1, ((CoasterData *)arg1)->counter, 0, 1.0f, 10, 45);
            }
        }
        sucoaster_entrypoint_13(arg0);
        sucoaster_entrypoint_8(arg0);
        break;
    case 3:
        _subaddierouteDll_entrypoint_6(arg0, arg1, ((CoasterData *)arg1)->counter, 7, 0.6f, 4, 8);
        if (!(((CoasterData *)arg1)->counter & 7) && arg0->unk58 <= 0.0f && func_800DC298(0.01f)) {
            choice2 = func_800DC298(0.3f) ? 4 : 2;
            sucoaster_entrypoint_9(arg0, choice2, 0);
        }
        if (!sucoaster_entrypoint_7(arg0, 0x802, 30.0f)) {
            sucoaster_entrypoint_13(arg0);
        }
        break;
    case 4:
        _subaddierouteDll_entrypoint_6(arg0, arg1, ((CoasterData *)arg1)->counter, 7, 0.6f, 4, 8);
        if (arg0->unk58 <= 0.0f && func_800DC298(0.02f)) {
            sucoaster_entrypoint_9(arg0, 3, 0);
        }
        if (!sucoaster_entrypoint_7(arg0, 0x802, 30.0f)) {
            sucoaster_entrypoint_13(arg0);
        }
        break;
    case 5:
        if (sucoaster_entrypoint_14(arg0)) {
            if (sucoaster_entrypoint_9(arg0, 2, 0)) {
                arg0->unk6C_0 = func_800D9058(2.0f);
            }
        } else if (!_subaddierouteDll_entrypoint_7(arg0, arg1, arg0->unk54, func_8080264C_sucoaster(arg0, (s32)arg1), ((CoasterData *)arg1)->radius, 0x5802)) {
            if (sucoaster_entrypoint_9(arg0, 2, 0)) {
                arg0->unk6C_0 = func_800D9058(2.0f);
            }
        } else {
            func_808020B8_sucoaster(arg0, arg1, 1.0f);
            if (func_80102CF4(arg0, 15.0f)) {
                choice3 = ((CoasterData *)arg1)->unk12 ? 8 : 7;
                sucoaster_entrypoint_9(arg0, choice3, 0);
            }
        }
        sucoaster_entrypoint_8(arg0);
        break;
    case 6:
        func_80102BF8(arg0, *(f32 *)(config + 0x4C), *(s16 *)(config + 0x50), *(s16 *)(config + 0x52));
        if (func_80102CF4(arg0, 20.0f)) {
            if (((u8 *)arg0)[0x74] & 1) {
                sucoaster_entrypoint_9(arg0, 18, 0);
                ((CoasterData *)arg1)->alternate = 0;
            } else {
                sucoaster_entrypoint_9(arg0, 3, 2);
                ((CoasterData *)arg1)->alternate = 0;
            }
        }
        sucoaster_entrypoint_8(arg0);
        break;
    case 7:
        sucoaster_entrypoint_16(arg0, 0);
        arg0->unk54 = func_8080264C_sucoaster(arg0, (s32)arg1);
        func_808020B8_sucoaster(arg0, arg1, 1.0f);
        if (func_80101DDC(arg0)) {
            if (sucoaster_entrypoint_14(arg0)) {
                if (sucoaster_entrypoint_9(arg0, 3, 0)) {
                    _subaddierouteDll_entrypoint_6(arg0, arg1, ((CoasterData *)arg1)->counter, 0, 1.0f, 40, 70);
                    arg0->unk6C_0 = func_800D9058(2.0f);
                }
            } else {
                sucoaster_entrypoint_9(arg0, 8, 0);
            }
        }
        sucoaster_entrypoint_8(arg0);
        break;
    case 8:
        sucoaster_entrypoint_11(arg0, _sucoasterdata_entrypoint_3(((CoasterData *)arg1)->track));
        if (sucoaster_entrypoint_14(arg0)) {
            sucoaster_entrypoint_15(arg0);
        } else {
            if (((CoasterData *)arg1)->route || _subaddierouteDll_entrypoint_4(arg0)) {
                arg0->unk54 = func_8080264C_sucoaster(arg0, (s32)arg1);
            }
            if (*(u16 *)(config + 0x4A) && func_80102CF4(arg0, 80.0f) && func_80802400_sucoaster(arg0, arg1)) {
                sucoaster_entrypoint_9(arg0, 9, 0);
            }
        }
        sucoaster_entrypoint_7(arg0, 0x5802, 30.0f);
        break;
    case 9:
        if (((CoasterData *)arg1)->route || _subaddierouteDll_entrypoint_4(arg0)) {
            arg0->unk54 = func_8080264C_sucoaster(arg0, (s32)arg1);
        }
        sucoaster_entrypoint_7(arg0, 0x5802, 30.0f);
        sucoaster_entrypoint_16(arg0, 1);
        sucoaster_entrypoint_16(arg0, 6);
        if (!((CoasterData *)arg1)->hit && sucoaster_entrypoint_16(arg0, 5)) {
            _sucoasterhit_entrypoint_2(arg0);
        }
        if (func_80101DDC(arg0)) {
            if (!sucoaster_entrypoint_13(arg0)) {
                sucoaster_entrypoint_9(arg0, 3, 0);
            }
        }
        break;
    case 10:
        sucoaster_entrypoint_11(arg0, _sucoasterdata_entrypoint_3(((CoasterData *)arg1)->track));
        if (func_80802550_sucoaster((s32)arg0, (s32)arg1)) {
            sucoaster_entrypoint_15(arg0);
        } else if (((CoasterData *)arg1)->route || _subaddierouteDll_entrypoint_4(arg0)) {
            arg0->unk54 = func_8080230C_sucoaster(arg0, arg1);
        }
        sucoaster_entrypoint_7(arg0, 0x4802, 30.0f);
        break;
    case 11:
        sucoaster_entrypoint_16(arg0, 2);
        if (func_80101DDC(arg0) && !((ActorFlags *)arg0)->busy) {
            if (((u8 *)arg0)[0x74] & 1) {
                sucoaster_entrypoint_9(arg0, 18, 0);
            } else {
                sucoaster_entrypoint_9(arg0, 3, 0);
            }
        }
        sucoaster_entrypoint_8(arg0);
        break;
    case 12:
        sucoaster_entrypoint_19(arg0);
        if (func_80101DDC(arg0) && !((ActorFlags *)arg0)->busy && !func_80107070(arg0, 2)) {
            sucoaster_entrypoint_10(arg0, 13);
            _subaddiefade_entrypoint_3(arg0);
        }
        sucoaster_entrypoint_16(arg0, 3);
        break;
    case 13:
        sucoaster_entrypoint_19(arg0);
        break;
    case 14:
        sucoaster_entrypoint_19(arg0);
        break;
    case 15:
        _sucoasterhit_entrypoint_1(arg0);
        break;
    case 17:
        sucoaster_entrypoint_19(arg0);
        break;
    case 18:
        sucoaster_entrypoint_11(arg0, _sucoasterdata_entrypoint_3(((CoasterData *)arg1)->track));
        choice1 = ((CoasterData *)arg1)->counter;
        if ((!choice1 & 0x1B) && !func_8001210C(7)) {
            direction = ((CoasterData *)arg1)->direction ? 1.0f : -1.0f;
            turn = func_800DC178(30.0f, 40.0f);
            func_80102924(arg0, arg0->unk54 + turn * direction);
        }
        if (!(((u8 *)arg0)[0x74] & 1)) {
            sucoaster_entrypoint_9(arg0, 3, 0);
        } else {
            sucoaster_entrypoint_7(arg0, 0x4000, 30.0f);
        }
        break;
    }
}

u8 *sucoaster_entrypoint_3(Actor *arg0) { void *func_80100094(Actor *, u32); return (u8 *)func_80100094(arg0, 0U) + 0x1C; }

void sucoaster_entrypoint_4(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (temp_v0 != NULL) {
        (*(u8 *)((s8 *)(temp_v0) + (0x19))) = (u8) ((*(u8 *)((s8 *)(temp_v0) + (0x19))) & 0xFFBF);
    }
}

void sucoaster_entrypoint_5(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    struct {
        u8 pad[0x19];
        u8 low : 4;
        u8 flag : 1;
        u8 high : 3;
    } *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (temp_v0 != NULL) {
        temp_v0->flag = 1;
    }
}

/* extern */

void func_80800C68_sucoaster(void *arg0, void *arg1, f32 arg2) {
    f32 func_800F15F8(f32, f32, f32);
    s32 func_800F20BC(f32, f32, s32);
    f32 func_80107C00();
    if (((0.6f * (f32) (*(s16 *)((s8 *)(arg1) + (0xE)))) < (*(f32 *)((s8 *)(arg0) + (0x24)))) && (func_800F20BC((*(f32 *)((s8 *)(arg0) + (0x48))), (*(f32 *)((s8 *)(arg0) + (0x54))), 0x42700000) == 0)) {
        (*(f32 *)((s8 *)(arg0) + (0x24))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x24))) * 0.95f);
        return;
    }
    (*(f32 *)((s8 *)(arg0) + (0x24))) = func_800F15F8((*(f32 *)((s8 *)(arg0) + (0x24))), (f32) (*(s16 *)((s8 *)(arg1) + (0xE))), func_80107C00() * arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_7.s")

void sucoaster_entrypoint_8(Actor *arg0) {
    s32 func_8010BA80(Actor *, s32, s32);
    func_8010BA80(arg0, 0x505410, 0x20);
}

/* extern */

s32 sucoaster_entrypoint_9(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_8010108C();
    s32 sucoaster_entrypoint_10(Actor *, s32);
    union {
        s32 words[2];
        struct {
            s16 index;
            s8 type;
        } parts;
    } sp18;

    sp18.parts.type = arg2;
    sp18.parts.index = arg1;
    if (func_8010108C(arg0, 0x42, sp18.words[0]) > 0) {
        sucoaster_entrypoint_10(arg0, (s32) arg1);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_808015F8_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_17.s")

void sucoaster_entrypoint_18(s32 arg0)
{
    func_80105230(arg0,0);
}

/* extern */

void sucoaster_entrypoint_19(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _suexpression_entrypoint_18(u8 *, s32);
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_18(func_80100094(arg0, 1U), 1);
    }
}

void sucoaster_entrypoint_20()
{
    func_80101870();
}

s32 sucoaster_entrypoint_21(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x64];
        u32 pad64_31 : 1;
        u32 enabled : 1;
        u32 pad64_25 : 5;
        u32 active : 1;
        u32 pad64_0 : 24;
        u8 pad68[0xC];
        u32 pad74_4 : 28;
        u32 mode : 4;
        u32 pad78_3 : 29;
        u32 player : 1;
        u32 pad78_0 : 2;
    } CoasterFlags;
    typedef struct {
        u8 pad0[0x13];
        s8 speed;
        u8 pad14[4];
        u32 track : 4;
        u32 pad18_22 : 6;
        u32 ready : 1;
        u32 pad18_0 : 21;
    } CoasterData;
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void _subaddierouteDll_entrypoint_1(Actor *);
    void *_sucoasterdata_entrypoint_1(u32);
    s32 _sucoasterdata_entrypoint_5(u32, u32, s32 *);
    void _sucoasterplayer_entrypoint_1(Actor *);
    void _suexpression_entrypoint_13(void *, f32 *, f32 *);
    s32 func_800D9058(f32);
    void *func_80100094(Actor *, u32);
    void func_80101010(s32);
    void func_80101074(s32);
    s32 func_80107070(Actor *, s32);
    s32 func_8010A590(u8 *);
    s32 func_80802690_sucoaster(Actor *, u8 *);
    void func_80802728_sucoaster(Actor *, u8 * volatile);
    s32 sucoaster_entrypoint_10(Actor *, s32);
    s32 sucoaster_entrypoint_9(Actor *, s32, s32);

    switch (arg1) {
        case 1:
        case 2:
            if (!((CoasterFlags *)arg0)->player) {
                _sucoasterplayer_entrypoint_1(arg0);
            }
            break;
        case 3:
            ((CoasterFlags *)arg0)->enabled = 0;
            ((CoasterFlags *)arg0)->active = 0;
            break;
        case 4:
            ((CoasterFlags *)arg0)->enabled = 1;
            ((CoasterFlags *)arg0)->active = 1;
            break;
        case 0x2B: {
            CoasterData *data;
            s32 enabled;
            data = func_80100094(arg0, 0);
            enabled = arg2 == 0;
            ((CoasterFlags *)arg0)->enabled = enabled;
            ((CoasterFlags *)arg0)->active = enabled;
            if (arg2 != 0) {
                data->speed = func_800D9058(1.8f);
            }
            break;
        }
        case 0x50: {
            CoasterData *data;
            s16 *trackData;
            if (arg0->unk70_10 == 9) {
                data = func_80100094(arg0, 0);
                if (data->ready) {
                    trackData = _sucoasterdata_entrypoint_1(data->track);
                    return trackData[0x2C] + ((arg2 >> 16) & 0xFFFF) + 1;
                }
            }
            return 0;
        }
        case 0x4D:
            if (func_80107070(arg0, 3) == 0) {
                return 0;
            }
            break;
        case 0x8F:
            switch (arg2) {
                case 0:
                    func_8010A590((u8 *)arg0);
                    sucoaster_entrypoint_9(arg0, 2, 8);
                case 4:
                    ((CoasterFlags *)arg0)->mode = 1;
                    break;
            }
            break;
        case 0x29: {
            u8 *data;
            data = func_80100094(arg0, 0);
            func_80802690_sucoaster(arg0, data);
            break;
        }
        case 0x2A: {
            u8 *data;
            data = func_80100094(arg0, 0);
            func_80802728_sucoaster(arg0, data);
            break;
        }
        case 0x94: {
            void *data;
            f32 rotation[3];
            if (func_80100094(arg0, 1) == NULL) {
                return 0;
            }
            rotation[2] = 0.0f;
            data = func_80100094(arg0, 1);
            _suexpression_entrypoint_13(data, &rotation[1], &rotation[0]);
            func_80101010((s32)rotation);
            break;
        }
        case 0x95:
            _subaddierouteDll_entrypoint_1(arg0);
            break;
        case 0x38: {
            CoasterData *data;
            s32 result;
            data = func_80100094(arg0, 0);
            func_80101074(_sucoasterdata_entrypoint_5(data->track, arg0->unk6C_9, &result));
            return result;
        }
        case 0x9A:
            if (arg0->unk70_10 != 0xC) {
                sucoaster_entrypoint_10(arg0, 0xC);
                _subaddieDll_entrypoint_4(arg0, 1);
            }
            break;
        case 0x42:
            break;
        default:
            return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_22.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_8080202C_sucoaster.s")

/* extern */

void func_808020B8_sucoaster(Actor *arg0, void *arg1, f32 arg2) {
    typedef struct {
        u8 pad0[0x18];
        u32 track : 4;
        u32 pad18 : 28;
    } CoasterData;
    typedef struct {
        u8 pad0[0x4C];
        f32 acceleration;
        s16 speed;
        s16 distance;
    } CoasterConfig;
    void *_sucoasterdata_entrypoint_1(u32);
    void func_80102BF8(void *, f32, f32, f32);
    CoasterConfig *config;

    config = _sucoasterdata_entrypoint_1(((CoasterData *)arg1)->track);
    func_80102BF8(arg0, config->acceleration * arg2, (f32)config->speed * arg2, (f32)config->distance * arg2);
}

void func_80802130_sucoaster(Actor *arg0, void *arg1, s16 arg2) {
    typedef struct {
        u8 pad0[0x10];
        s16 value;
        u8 pad12[7];
        u8 pad19_5 : 3;
        u8 flag : 1;
        u8 pad19_0 : 4;
    } CoasterData;
    CoasterData *data = arg1;
    u32 temp_t1;

    if (arg0->unk7A_5) {
        temp_t1 = arg0->unk74_7;
        if (temp_t1 != 0x32) {
            data->value = temp_t1;
            data->flag = 1;
            return;
        }
    }
    data->value = (s32)(arg0->scale * (f32)arg2);
    data->flag = 0;
}

/* extern */

f32 func_808021A8_sucoaster(Actor *arg0, void *arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0xC];
        s16 scale;
        s16 distance;
        s16 value;
        u8 pad12[6];
        u32 track : 4;
        u32 pad18 : 7;
        u32 flag : 1;
        u32 pad19 : 20;
    } CoasterData;
    s32 _sucoasterdata_entrypoint_4(u32);
    f32 func_800F0E00(f32, f32);
    f32 func_80103EAC(Actor *);
    f32 sp1C;
    CoasterData *data = arg1;

    if ((arg2 & 0x1000) || data->flag) {
        return (f32)data->value;
    }
    sp1C = ((f32)data->distance / (f32)_sucoasterdata_entrypoint_4(data->track)) * ((f32)data->scale * 0.00390625f) * (f32)data->value;
    return func_800F0E00(func_80103EAC(arg0) + 50.0f, sp1C);
}

/* extern */

void func_80802260_sucoaster(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 pad0[0x64];
        u32 flag31 : 1;
        u32 flag30 : 1;
        u32 pad64 : 30;
        u8 pad68[8];
        u32 upper : 7;
        u32 pad70 : 15;
        u32 lower : 6;
        u32 pad73 : 4;
        u32 pad74 : 28;
        u32 mode : 4;
    } CoasterFlags;
    void func_8010A570(Actor *);
    CoasterFlags *flags = (void *)arg0;

    func_8010A570(arg0);
    arg0->unk64_24 = 0;
    flags->lower = 0;
    flags->upper = flags->lower;
    flags->flag30 = 0;
    flags->flag31 = flags->flag30;
    arg0->unk14 &= ~0x80000;
    flags->mode = 2;
}

/* extern */

f32 func_8080230C_sucoaster(Actor *arg0, void *arg1) { f32 func_800136E4(f32); f32 func_800F1DCC(f32, f32); f32 func_80102D78(Actor *, void *); void **p = &arg1; f32 sp18; f32 var_f0; (void)p; sp18 = func_80102D78(arg0, arg0->actorData); var_f0 = func_800F1DCC(arg0->rotation[1], sp18) > 0.0f ? 110.0f : -110.0f; return func_800136E4(var_f0 + sp18); }

/* extern */

s32 func_80802384_sucoaster(Actor *arg0, void *arg1, f32 arg2) {
    typedef struct {
        u8 pad0[0x10];
        s16 value;
    } CoasterData;
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    f32 func_800136E4(f32);
    f32 func_800DC178(f32, f32);
    CoasterData *data = arg1;
    f32 temp_f0;

    temp_f0 = func_800136E4(func_800DC178(-20.0f, 20.0f) + arg2);
    if (_subaddierouteDll_entrypoint_7(arg0, arg1, temp_f0, temp_f0, (f32)data->value, 2) == 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802400_sucoaster.s")

/* extern */

s32 func_80802550_sucoaster(s32 arg0, s32 arg1) {
    s32 func_8080202C_sucoaster();
    s32 func_80802594_sucoaster(s32, s32);
    if (func_8080202C_sucoaster() != 0) {
        return func_80802594_sucoaster(arg0, arg1) == 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802594_sucoaster.s")

/* extern */

f32 func_8080264C_sucoaster(void *arg0, s32 arg1) {
    f32 func_8010CD50(void *, s32);
    s32 func_80802760_sucoaster(s32);
    s32 temp_v0;

    temp_v0 = func_80802760_sucoaster(arg1);
    if (temp_v0 == -1) {
        return (*(f32 *)((s8 *)(arg0) + (0x48)));
    }
    return func_8010CD50(arg0, temp_v0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802690_sucoaster.s")

void func_80802728_sucoaster(Actor *arg0, u8 * volatile arg1) {
    void *func_80100094(Actor *, u32);
    s32 _suexpression_entrypoint_8(Actor *, s32);
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}

s32 func_80802760_sucoaster(s32 arg0) {
    typedef struct {
        u8 pad0[0x18];
        u32 track : 4;
        u32 pad18_20 : 8;
        u32 flag : 1;
        u32 pad18_0 : 19;
    } CoasterData;
    u32 func_800F54E4(void);
    s32 func_8010D290(s32);
    void *_sucoasterdata_entrypoint_1(u32);
    CoasterData *data = (CoasterData *)arg0;

    if (data->flag) {
        return func_800F54E4();
    }
    return func_8010D290(*(s32 *)((s8 *)_sucoasterdata_entrypoint_1(data->track) + 0x3C));
}
