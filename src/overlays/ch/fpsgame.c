#include "common.h"

OSThread *chfpsgame_entrypoint_0(void)
{
    extern u8 D_808021A0_chfpsgame[];

    return (OSThread *) D_808021A0_chfpsgame;
}

void func_8080000C_chfpsgame(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (arg2 != 0) {
        (*(s32 *)((s8 *)(temp_v0) + (4))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (4))) | (1 << arg1));
        return;
    }
    (*(s32 *)((s8 *)(temp_v0) + (4))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (4))) & ~(1 << arg1));
}

s32 func_80800074_chfpsgame(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 var_v1;

    if ((*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (4))) & (1 << arg1)) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

s32 func_808000BC_chfpsgame(u16 arg0) {
    s32 _gcstatusDll_entrypoint_11();
    s32 func_80016BBC(s32, u16);
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;
    s32 var_v1;

    var_s1 = 0;
    var_s0 = 0;
    if (_gcstatusDll_entrypoint_11() > 0) {
        do {
            temp_v0 = func_80016BBC(var_s0, arg0 & 0xFFFF);
            var_s0 += 1;
            var_s1 |= temp_v0;
        } while (var_s0 < _gcstatusDll_entrypoint_11());
    }
    if (var_s1 != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

void func_80800138_chfpsgame(u32 arg0) {
    s32 func_800F5898();
    s32 func_800F6BE4(s32);
    s32 func_800F7F98(s32, u32);
    s32 var_s0;

    var_s0 = 0;
    if (func_800F5898() > 0) {
        do {
            if (func_800F6BE4(var_s0) != 0) {
                func_800F7F98(var_s0, arg0);
            }
            var_s0 += 1;
        } while (var_s0 < func_800F5898());
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_8080019C_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808002FC_chfpsgame.s")

typedef struct player_state_s PlayerState;

void func_808003D0_chfpsgame(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    PlayerState *func_800F53D0(s32);
    void _bsfirstp_entrypoint_4(PlayerState *, s32);
    void _bsfirstp_entrypoint_5(PlayerState *, s32, s32);
    s32 _gcstatusDll_entrypoint_13();
    s32 _gcstatusDll_entrypoint_19(void);
    s32 _sumultiscore_entrypoint_3(u8 *);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    struct {
        s32 count;
        u8 unk4[0x10];
        u8 score[1];
    } *data;
    u8 *score;
    PlayerState *player;
    s32 status;
    s32 mode;
    s32 i;

    data = func_80100094(arg0, 0);
    score = data->score;
    mode = _gcstatusDll_entrypoint_19();
    i = 0;
    if (data->count > 0) {
        do {
            player = func_800F53D0(i);
            status = _gcstatusDll_entrypoint_13(i);
            _bsfirstp_entrypoint_4(player, mode);
            _bsfirstp_entrypoint_5(player, 1, status);
            i += 1;
        } while (i < data->count);
    }
    _sumultiscore_entrypoint_3(score);
    _sumultiscore_entrypoint_4(score, 1, 0, 1);
    _sumultiscore_entrypoint_4(score, 2, 1, 1);
    _sumultiscore_entrypoint_4(score, 3, 2, 1);
    _sumultiscore_entrypoint_4(score, 4, 3, 0);
}

void func_808004E0_chfpsgame(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    PlayerState *func_800F53D0(s32);
    void _bsfirstp_entrypoint_4(PlayerState *, s32);
    void _bsfirstp_entrypoint_5(PlayerState *, s32, s32);
    s32 _gcstatusDll_entrypoint_13();
    s32 _sumultiscore_entrypoint_3(u8 *);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    struct {
        s32 count;
        u8 unk4[0x10];
        u8 score[1];
    } *data;
    u8 *score;
    PlayerState *player;
    s32 status;
    s32 i;

    data = func_80100094(arg0, 0);
    score = data->score;
    i = 0;
    if (data->count > 0) {
        do {
            player = func_800F53D0(i);
            status = _gcstatusDll_entrypoint_13(i);
            _bsfirstp_entrypoint_4(player, 0);
            _bsfirstp_entrypoint_5(player, 3, status);
            i += 1;
        } while (i < data->count);
    }
    _sumultiscore_entrypoint_3(score);
    _sumultiscore_entrypoint_4(score, 2, 0, 1);
    _sumultiscore_entrypoint_4(score, 3, 2, 1);
}

void func_808005B0_chfpsgame(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    PlayerState *func_800F53D0(s32);
    void _bsfirstp_entrypoint_4(PlayerState *, s32);
    void _bsfirstp_entrypoint_5(PlayerState *, s32, s32);
    s32 _gcstatusDll_entrypoint_13();
    s32 _gcstatusDll_entrypoint_19(void);
    s32 _sumultiscore_entrypoint_3(u8 *);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    struct {
        s32 count;
        u8 unk4[0x10];
        u8 score[1];
    } *data;
    u8 *score;
    PlayerState *player;
    s32 status;
    s32 mode;
    s32 i;

    data = func_80100094(arg0, 0);
    score = data->score;
    mode = _gcstatusDll_entrypoint_19();
    i = 0;
    if (data->count > 0) {
        do {
            player = func_800F53D0(i);
            status = _gcstatusDll_entrypoint_13(i);
            _bsfirstp_entrypoint_4(player, mode);
            _bsfirstp_entrypoint_5(player, 2, status);
            i += 1;
        } while (i < data->count);
    }
    _sumultiscore_entrypoint_3(score);
    _sumultiscore_entrypoint_4(score, 2, 0, 1);
    _sumultiscore_entrypoint_4(score, 3, 2, 1);
    _sumultiscore_entrypoint_4(score, 4, 3, 0);
}

void func_808006A8_chfpsgame(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    PlayerState *func_800F53D0(s32);
    void func_800A18C8();
    void func_800A1870(PlayerState *, s32);
    void _badeathmatch_entrypoint_11(PlayerState *, s32, s32);
    s32 _sumultiscore_entrypoint_3(u8 *);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    struct {
        s32 count;
        u8 unk4[0x10];
        u8 score[1];
    } *data;
    u8 *score;
    PlayerState *player;
    s32 i;

    data = func_80100094(arg0, 0);
    score = data->score;
    i = 0;
    if (data->count > 0) {
        do {
            player = func_800F53D0(i);
            func_800A18C8(player, 1);
            func_800A1870(player, 1);
            _badeathmatch_entrypoint_11(player, 1, 1);
            i += 1;
        } while (i < data->count);
    }
    _sumultiscore_entrypoint_3(score);
    _sumultiscore_entrypoint_4(score, 2, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_8080075C_chfpsgame.s")

/* extern */

void func_808008D4_chfpsgame(s32 arg0) {
    s32 func_80800FF4_chfpsgame(s32);
    s32 func_808015EC_chfpsgame();
    s32 func_80801758_chfpsgame(s32);
    s32 func_808018E0_chfpsgame(s32);
    func_808015EC_chfpsgame();
    func_80800FF4_chfpsgame(arg0);
    func_80801758_chfpsgame(arg0);
    func_808018E0_chfpsgame(arg0);
}

void func_8080090C_chfpsgame(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80800914_chfpsgame.s")

void func_80800BCC_chfpsgame(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 _gcstatusDll_entrypoint_16(s32);
    void _sumultiscore_entrypoint_7(u8 *, s32, s32, s32);
    void _sumultiscore_entrypoint_11(u8 *, s32, s32, f32);
    struct {
        s32 count;
        u8 unk4[0x10];
        u8 score[1];
    } *data;
    s32 amount;
    u8 *score;
    s32 team;
    s32 i;

    data = func_80100094(arg0, 0);
    team = _gcstatusDll_entrypoint_16(arg1);
    amount = 1;
    if ((arg2 >= 0) && (_gcstatusDll_entrypoint_16(arg2) == team)) {
        amount = -1;
    }
    score = data->score;
    if (team < 4) {
        _sumultiscore_entrypoint_7(score, arg1, 2, amount);
        _sumultiscore_entrypoint_11(score, arg1, 2, 0.75f);
        return;
    }
    i = 0;
    if (data->count > 0) {
        do {
            score = data->score;
            if (_gcstatusDll_entrypoint_16(i) == team) {
                _sumultiscore_entrypoint_7(score, i, 2, amount);
                _sumultiscore_entrypoint_11(score, i, 2, 0.75f);
            }
            i += 1;
        } while (i < data->count);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80800CF8_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80800FF4_chfpsgame.s")

s32 func_8080121C_chfpsgame(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _gcstatusDll_entrypoint_11();
    s32 _gcstatusDll_entrypoint_18(void);
    s32 _sumultiscore_entrypoint_8(void *, s32, s32);
    s32 func_80801ADC_chfpsgame(Actor *);
    u8 *data;
    s32 status;
    s32 i;

    data = func_80100094(arg0, 0);
    status = _gcstatusDll_entrypoint_18();
    if (func_80801ADC_chfpsgame(arg0) != 0) {
        return 1;
    }
    if (status != 0) {
        i = 0;
        if (_gcstatusDll_entrypoint_11() > 0) {
            do {
                if (_sumultiscore_entrypoint_8(data + 0x14, i, 2) == status) {
                    return 1;
                }
                i++;
            } while (i < _gcstatusDll_entrypoint_11());
        }
    }
    return 0;
}

/* extern */

s32 func_808012CC_chfpsgame(s32 arg0) {
    s16 _badeathmatch_entrypoint_9(void *, s32);
    s32 _gcstatusDll_entrypoint_11();
    s32 _gcstatusDll_entrypoint_14();
    struct player_state_s *func_800F53D0(s32);
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    if (_gcstatusDll_entrypoint_14() == 3) {
        var_s1 = 0;
        var_s0 = 0;
        if (_gcstatusDll_entrypoint_11() > 0) {
            do {
                temp_v0 = _badeathmatch_entrypoint_9(func_800F53D0(var_s0), 1);
                var_s0 += 1;
                var_s1 += temp_v0;
            } while (var_s0 < _gcstatusDll_entrypoint_11());
        }
        return var_s1 ? 0 : 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_8080135C_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808013DC_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808015EC_chfpsgame.s")

s32 func_80801758_chfpsgame(s32 arg0) {
    void *func_80100094(Actor *, u32);
    s32 _sumultiscore_entrypoint_6(u8 *);
    return _sumultiscore_entrypoint_6((u8 *)func_80100094((Actor *)arg0, 0U) + 0x14);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801780_chfpsgame.s")

void func_80801814_chfpsgame(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _gcstatusDll_entrypoint_17();
    void func_80801A8C_chfpsgame(Actor *, f32);
    s32 temp_v0;
    u8 *temp_s0;

    temp_s0 = func_80100094(arg0, 0U);
    temp_v0 = _gcstatusDll_entrypoint_17();
    if (temp_v0 != 0) {
        *(s8 *)(temp_s0 + 0x55A) = temp_v0;
        *(s8 *)(temp_s0 + 0x55B) = 0;
        *(f32 *)(temp_s0 + 0x55C) = (f32)temp_v0 * 60.0f + 0.99f;
        func_80801A8C_chfpsgame(arg0, 10.99f);
    } else {
        *(f32 *)(temp_s0 + 0x55C) = 0;
        func_80801A8C_chfpsgame(arg0, 0.0f);
    }
    *(f32 *)(temp_s0 + 0x560) = *(f32 *)(temp_s0 + 0x55C);
}

void func_808018B0_chfpsgame(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s8 *)((s8 *)(temp_v0) + (0x558))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0x559))) = 0;
    (*(f32 *)((s8 *)(temp_v0) + (0x55C))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808018E0_chfpsgame.s")

void func_80801A8C_chfpsgame(Actor *arg0, f32 arg1) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(f32 *)((s8 *)(temp_v0) + (0x564))) = arg1;
    if (arg1 != 0.0f) {
        (*(s8 *)((s8 *)(temp_v0) + (0x558))) = 1;
        return;
    }
    (*(s8 *)((s8 *)(temp_v0) + (0x558))) = 0;
}

/* extern */

s32 func_80801ADC_chfpsgame(Actor *arg0) { void *func_80100094(Actor *, u32); s32 var_v1; void *temp_v0; temp_v0 = func_80100094(arg0, 0U); var_v1 = ((*(f32 *)((s8 *)temp_v0 + 0x55C)) != 0.0f) && ((*(f32 *)((s8 *)temp_v0 + 0x560)) == 0.0f) ? 1 : 0; return var_v1; }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801B30_chfpsgame.s")

void func_80801C5C_chfpsgame(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s32 *)((s8 *)(temp_v0) + (0x5BC))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x5C0))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x610))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x614))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x664))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x668))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x568))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x56C))) = 0;
}

void func_80801C9C_chfpsgame(Actor *arg0) { void *func_80100094(Actor *, u32); s32 func_8010114C(s32, s32, s32); struct Entry { s32 actor; s32 unused; }; struct Group { s32 count; struct Entry entries[10]; }; struct Data { s8 pad[0x568]; struct Group groups[4]; }; struct Data *data; struct Group *cursor; s32 *count; s32 offset; s32 index; data = func_80100094(arg0, 0U); for (offset = 0; offset < 4; offset++) { cursor = &data->groups[offset]; count = &cursor->count; if (data->groups[offset].count != 0) { do { index = cursor->count - 1; cursor->count = index; func_8010114C(cursor->entries[index].actor, 0x45, 0); } while (*count != 0); } } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801D40_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801DF0_chfpsgame.s")

void func_80801F34_chfpsgame(Actor *arg0, s32 arg1) {
    s32 func_8001211C(void);
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(s32, s32, s32);
    struct Entry { s32 actor; u32 time; };
    struct Group { s32 count; struct Entry entries[10]; };
    struct Data { s8 pad[0x568]; struct Group groups[4]; };
    struct Data *data;
    struct Group *group;
    s32 i;
    u32 minimum;
    s32 oldest;
    struct Group *entry;

    data = func_80100094(arg0, 0U);
    group = &data->groups[arg1];
    minimum = func_8001211C();
    for (i = 0; i < group->count; i++) {
        if (group->entries[i].time < minimum) {
            minimum = group->entries[i].time;
            oldest = i;
        }
    }
    entry = (struct Group *)((struct Entry *)group + oldest);
    func_8010114C(entry->entries[0].actor, 0x4F, 0);
    group->count--;
    entry->entries[0].actor = group->entries[group->count].actor;
    entry->entries[0].time = group->entries[group->count].time;
}

void func_80802020_chfpsgame(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    struct Entry { s32 actor; s32 unused; };
    struct Group { s32 count; struct Entry entries[10]; };
    struct Data { s8 pad[0x568]; struct Group groups[4]; };
    struct Data *data;
    struct Group *group;
    s32 i;

    data = func_80100094(arg0, 0U);
    i = 0;
    group = &data->groups[arg1];
    group->count--;
    for (; i < group->count; i++) {
        if (arg2 == group->entries[i].actor) {
            group->entries[i].actor = group->entries[group->count].actor;
            group->entries[i].unused = group->entries[group->count].unused;
            return;
        }
    }
}
