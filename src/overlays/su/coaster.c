#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_0.s")

/* extern */

void sucoaster_entrypoint_1(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_80802728_sucoaster(Actor *, u8 *);
    func_80802728_sucoaster(arg0, func_80100094(arg0, 0U));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_8080027C_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_3.s")

void sucoaster_entrypoint_4(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (temp_v0 != NULL) {
        (*(u8 *)((s8 *)(temp_v0) + (0x19))) = (u8) ((*(u8 *)((s8 *)(temp_v0) + (0x19))) & 0xFFBF);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80800C68_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/sucoaster_entrypoint_9.s")

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
    s32 func_80802728_sucoaster(Actor *, u8 *);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_808020B8_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802130_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_808021A8_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802260_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_8080230C_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802384_sucoaster.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802728_sucoaster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/func_80802760_sucoaster.s")
