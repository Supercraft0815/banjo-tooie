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

void func_8080019C_chfpsgame(Actor **arg0) {
    u32 _bsfirstp_entrypoint_3(s32, s32, s32);
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 _gcstatusDll_entrypoint_19(void);
    s32 func_800EA05C(void);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_801085CC(s32, s16 *, u32);
    Actor *spawned;
    Prop *prop;
    Prop *props[28];
    Actor *actor;
    Unk80132ED0 *marker;
    s32 count;
    s32 map;
    s32 mode;
    s32 id;
    s32 i;

    actor = *arg0;
    marker = actor->unk0;
    count = _gccubesearch_entrypoint_9(0x2BA, props, 28);
    map = func_800EA05C();
    mode = _gcstatusDll_entrypoint_19();
    i = 0;
    if (count > 0) {
        do {
            switch (_bsfirstp_entrypoint_3(map, mode, props[i]->unk6_7 - 0x32)) {
                case 0: id = 0; break;
                case 1: id = 0x1C8; break;
                case 2: id = 0x1C9; break;
                case 3: id = 0x1CA; break;
                case 4: id = 0x1CB; break;
                case 5: id = 0x1CC; break;
                case 6: id = 0x2B8; break;
                case 7: id = 0x1CD; break;
            }
            if (id != 0) {
                prop = props[i];
                spawned = func_801085CC(id, prop->position, prop->FlagOrRotation);
                spawned->unk74_7 = 0x33;
                actor = func_80106790(marker);
            }
            i++;
        } while (i < count);
    }
    *arg0 = actor;
}

/* extern */

void func_808002FC_chfpsgame(Actor *arg0) {
    void func_808003D0_chfpsgame(Actor *arg0, s32 arg1);
    void func_808004E0_chfpsgame(Actor *arg0);
    void func_808005B0_chfpsgame(Actor *arg0);
    void func_808006A8_chfpsgame(Actor *arg0);
    void func_8080075C_chfpsgame(Actor *arg0);
    void func_80801C5C_chfpsgame(Actor *arg0);
    s32 _gcstatusDll_entrypoint_11();
    s32 _gcstatusDll_entrypoint_14();
    void* func_80100094();
    s32 func_80800CF8_chfpsgame(Actor *, s32);
    void *sp24;
    s32 sp20;

    sp24 = func_80100094(arg0, 0);
    sp20 = _gcstatusDll_entrypoint_14();
    (*(s32 *)((s8 *)(sp24) + (4))) = 0;
    func_80800CF8_chfpsgame(arg0, 0);
    func_80801C5C_chfpsgame(arg0);
    (*(s32 *)((s8 *)(sp24) + (0))) = _gcstatusDll_entrypoint_11();
    switch (sp20) {
    case 1:
    case 4:
        func_808003D0_chfpsgame(arg0, sp20);
        return;
    case 3:
        func_808004E0_chfpsgame(arg0);
        return;
    case 2:
        func_808005B0_chfpsgame(arg0);
        return;
    case 6:
        func_808006A8_chfpsgame(arg0);
        return;
    case 5:
        func_8080075C_chfpsgame(arg0);
        /* fallthrough */
    default:
        return;
    }
}

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

void func_8080075C_chfpsgame(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    PlayerState *func_800F53D0(s32);
    s32 _gcstatusDll_entrypoint_15(void);
    s32 _sumultiscore_entrypoint_3(u8 *);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    void _badeathmatch_entrypoint_10(PlayerState *, s32, s32, s32);
    void _badeathmatch_entrypoint_7(PlayerState *, s32);
    struct ScoreEntry {
        u8 unk0[0x86];
        u8 active;
        u8 unk87[0xB5];
    };
    union Score {
        u8 bytes[1];
        struct ScoreEntry entries[1];
    };
    struct {
        s32 count;
        u8 unk4[8];
        f32 timer;
        f32 duration;
        union Score score;
    } *data;
    union Score *score;
    struct ScoreEntry *entry;
    PlayerState *player;
    s32 i;
    s32 selected;

    data = func_80100094(arg0, 0);
    score = &data->score;
    selected = _gcstatusDll_entrypoint_15();
    switch (data->count) {
        case 2:
            data->duration = 6.0f;
            break;
        case 3:
            data->duration = 4.0f;
            break;
        case 4:
            data->duration = 2.0f;
            break;
    }
    data->timer = data->duration;
    _sumultiscore_entrypoint_3(score->bytes);
    _sumultiscore_entrypoint_4(score->bytes, 2, 0, 1);
    _sumultiscore_entrypoint_4(score->bytes, 3, 2, 1);
    i = 0;
    if (data->count > 0) {
        do {
            player = func_800F53D0(i);
            if (i == selected) {
                _badeathmatch_entrypoint_10(player, 3, 25, 25);
                _badeathmatch_entrypoint_7(player, 3);
            } else {
                entry = &score->entries[i];
                _badeathmatch_entrypoint_10(player, 1, 1, -1);
                entry->active = 0;
            }
            i += 1;
        } while (i < data->count);
    }
}

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
s32 func_80800914_chfpsgame(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 _gcstatusDll_entrypoint_14();
    s32 _gcstatusDll_entrypoint_15();
    u32 _suegg_entrypoint_7(void *);
    void _sumultiscore_entrypoint_5(u8 *, s32, s32, s32);
    void _sumultiscore_entrypoint_9(u8 *, s32, s32, s32);
    s32 func_800F5410(s32);
    s32 func_800F7C0C(s32, s32, f32);
    void func_800FC660(u32);
    void func_80800BCC_chfpsgame(Actor *, s32, s32);
    s32 func_80800CF8_chfpsgame(Actor *, s32);
    void func_808013DC_chfpsgame(Actor *, s32, u32);
    void func_80801D40_chfpsgame(Actor *, s32, Unk80132ED0 *);
    void func_80802020_chfpsgame(Actor *, s32, s32);
    struct {
        s32 count;
        s32 flags;
        s32 kills;
        f32 timer;
        f32 duration;
        u8 score[1];
    } *data;
    s32 player;
    s32 victim;
    s32 mode;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x49:
        func_8080019C_chfpsgame(&arg0);
        break;
    case 0x70:
        player = arg2 & 0xF;
        victim = arg2 >> 4;
        mode = _gcstatusDll_entrypoint_14();
        switch (mode) {
        case 5:
            if (_gcstatusDll_entrypoint_15() == victim) {
                func_800FC660(0x19);
                func_80800BCC_chfpsgame(arg0, player, victim);
                data->timer = data->duration;
            } else {
                data->kills++;
            }
            break;
        case 3:
            func_800FC660(0x19);
            func_80800BCC_chfpsgame(arg0, player, victim);
            break;
        case 6:
            func_80800BCC_chfpsgame(arg0, player, victim);
            if (func_800F5410(victim) == 0xC) {
                data->kills++;
            }
            break;
        default:
            func_80800BCC_chfpsgame(arg0, player, victim);
            data->kills++;
            break;
        }
        break;
    case 0x71:
        if (_gcstatusDll_entrypoint_14() == 6) {
            func_800F7C0C(arg2, 0x83, 4.0f);
        } else {
            func_808013DC_chfpsgame(arg0, arg2, 1);
        }
        data->kills--;
        break;
    case 0x72:
        _sumultiscore_entrypoint_5(data->score, arg2 & 0xF, 3, (arg2 >> 4) & 0xF);
        break;
    case 0x73:
        {
            s32 owner;
            Unk80132ED0 *egg = (Unk80132ED0 *)arg2;
            owner = _suegg_entrypoint_7(egg);
            func_80801D40_chfpsgame(arg0, owner, egg);
        }
        break;
    case 0x74:
        {
            s32 owner;
            s32 egg = arg2;
            owner = _suegg_entrypoint_7((void *)egg);
            func_80802020_chfpsgame(arg0, owner, egg);
        }
        break;
    case 0x75:
        _sumultiscore_entrypoint_9(data->score, arg2 & 0xFFFF, 4, (arg2 >> 16) & 0xFFFF);
        break;
    case 0x2E:
        if (*(s16 *)&arg2 == 0xCEC) {
            func_80800CF8_chfpsgame(arg0, 2);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

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

s32 func_80800FF4_chfpsgame(s32 arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    int func_800A4C68(void *);
    s32 func_800C954C(void);
    s32 func_800C96CC();
    f32 func_800D8FF8(void);
    s32 func_800F1574(f32 *, f32);
    PlayerState *func_800F53D0(s32);
    void *func_80100094(Actor *, u32);
    s32 func_80800CF8_chfpsgame(Actor *, s32);
    s32 func_8080121C_chfpsgame(Actor *);
    s32 func_808012CC_chfpsgame(s32);
    void func_8080135C_chfpsgame(Actor *);
    struct Data {
        s32 count;
        s32 unk4;
        s32 unk8;
        u8 unkC[0x544];
        u32 state;
        f32 timer;
    } *data;
    s32 pad[2];
    s32 ready;
    s32 i;

    data = func_80100094((Actor *)arg0, 0);
    switch (data->state) {
    case 0:
        if (func_800C954C() == 0) {
            _subaddiedialog_entrypoint_11(((Actor *)arg0)->unk0, 0xCEC, 0x22, NULL, 0x6F);
            func_80800CF8_chfpsgame((Actor *)arg0, 1);
        }
        break;
    case 2:
        func_8080135C_chfpsgame((Actor *)arg0);
        if (func_8080121C_chfpsgame((Actor *)arg0) != 0) {
            func_80800CF8_chfpsgame((Actor *)arg0, 4);
            break;
        }
        if (func_808012CC_chfpsgame(arg0) != 0) {
            func_80800CF8_chfpsgame((Actor *)arg0, 3);
        }
        break;
    case 3:
        func_8080135C_chfpsgame((Actor *)arg0);
        if (func_800F1574(&data->timer, func_800D8FF8()) != 0) {
            func_80800CF8_chfpsgame((Actor *)arg0, 4);
            break;
        }
        if (func_8080121C_chfpsgame((Actor *)arg0) != 0) {
            func_80800CF8_chfpsgame((Actor *)arg0, 4);
        }
        break;
    case 4:
        if (data->unk8 == 0) {
            func_80800CF8_chfpsgame((Actor *)arg0, 5);
        }
        break;
    case 5:
        ready = 1;
        i = 0;
        if (data->count > 0) {
            do {
                if (func_800C96CC(func_800A4C68(func_800F53D0(i))) == 0) {
                    ready = 0;
                    break;
                }
                i++;
            } while (i < data->count);
        }
        if (ready != 0) {
            func_80800CF8_chfpsgame((Actor *)arg0, 6);
        }
    case 6:
        if (func_800F1574(&data->timer, func_800D8FF8()) != 0) {
            func_80800CF8_chfpsgame((Actor *)arg0, 7);
            break;
        }
        if (data->timer < 4.5f && func_808000BC_chfpsgame(0xD000) != 0) {
            func_80800CF8_chfpsgame((Actor *)arg0, 7);
        }
        break;
    }
}

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

void func_8080135C_chfpsgame(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _gcstatusDll_entrypoint_14();
    s32 _gcstatusDll_entrypoint_15();
    f32 func_800D8FF8(void);
    s32 func_800F1574(f32 *, f32);
    void func_800FC660(u32);
    f32 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    if ((_gcstatusDll_entrypoint_14() == 5) && (func_800F1574(&sp1C[3], func_800D8FF8()) != 0)) {
        func_800FC660(0xE);
        sp1C[3] = sp1C[4];
        func_80800BCC_chfpsgame(arg0, _gcstatusDll_entrypoint_15(), -1);
    }
}

void func_808013DC_chfpsgame(Actor *arg0, s32 arg1, u32 arg2) {
    void _bainvisible_entrypoint_3(PlayerState *);
    void _bainvisible_entrypoint_8(PlayerState *, s32, f32, f32);
    s32 _sudeathmatch_entrypoint_0(s32, f32 *, f32 *);
    void func_80093370(void *, s32);
    void func_8009337C(void *, s32);
    s32 func_800A1760(PlayerState *);
    void func_800A1870(PlayerState *, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    int func_800A4C68(void *);
    void func_800C968C(s32, s32);
    void func_800F44DC(void *, s32);
    PlayerState *func_800F53D0(s32);
    s32 func_800F7C0C(s32, s32, f32);
    s32 func_800F7F98(s32, u32);
    void func_800F8294(s32, f32 *);
    s32 func_800F832C(s32, f32 *);
    void *func_80100094(Actor *, u32);
    struct {
        u8 pad[0x530];
        struct {
            u32 state;
            f32 timer;
        } players[4];
    } *sp44;
    PlayerState *temp_s0;
    f32 sp34[3];
    f32 sp28[3];
    s32 temp_v0;

    sp44 = func_80100094(arg0, 0U);
    temp_s0 = func_800F53D0(arg1);
    switch (arg2) {
    case 1:
        func_800C968C(func_800A4C68(temp_s0), 0x13);
        _bainvisible_entrypoint_8(temp_s0, 1, 0.0f, 1.0f);
        _bainvisible_entrypoint_8(temp_s0, 2, 1.0f, 0.01f);
        break;
    case 2:
        func_800A38F0(temp_s0, 0, 0);
        func_800F44DC(temp_s0, 0);
        func_80093370(temp_s0, 0);
        sp44->players[arg1].timer = 5.0f;
        break;
    case 3:
        func_800C968C(func_800A4C68(temp_s0), 0x12);
        if (_sudeathmatch_entrypoint_0(arg1, sp34, sp28) != 0) {
            func_800F832C(arg1, sp28);
            func_800F8294(arg1, sp34);
        }
        func_800A1870(temp_s0, func_800A1760(temp_s0));
        func_800A38F0(temp_s0, 1, 1);
        _bainvisible_entrypoint_3(temp_s0);
        func_80093370(temp_s0, 1);
        func_8009337C(temp_s0, 1);
        func_800F44DC(temp_s0, 1);
        func_800F7C0C(arg1, 0x83, 0.0f);
        func_800F7F98(arg1, 1U);
        break;
    case 0:
        func_800F7F98(arg1, 0U);
        break;
    case 4:
        temp_v0 = sp44->players[arg1].state;
        if ((temp_v0 == 0) || (temp_v0 == 3)) {
            func_800C968C(func_800A4C68(temp_s0), 0x13);
        }
        break;
    }
    sp44->players[arg1].state = arg2;
}

s32 func_808015EC_chfpsgame(Actor *arg0) {
    s32 _gcstatusDll_entrypoint_11(void);
    s32 func_80016BBC(s32, u16);
    int func_800A4C68(void *);
    s32 func_800C96CC();
    s32 func_800C9714();
    f32 func_800D8FF8(void);
    s32 func_800F1574(f32 *, f32);
    PlayerState *func_800F53D0(s32);
    s32 func_800F54F0(s32);
    void *func_80100094(Actor *, u32);
    struct {
        u8 pad[0x530];
        struct {
            u32 state;
            f32 timer;
        } players[4];
    } *data, *current;
    PlayerState *player;
    u32 state;
    s32 i;

    data = func_80100094(arg0, 0U);
    i = 0;
    if (_gcstatusDll_entrypoint_11() <= 0) {
        return;
    }
loop:
        player = func_800F53D0(i);
        current = (void *)((u8 *)data + (i << 3));
        state = current->players[0].state;
        switch (state) {
        case 1:
            if (func_800C96CC(func_800A4C68(player))) {
                func_808013DC_chfpsgame(arg0, i, 2U);
            }
            break;
        case 2:
            if (!func_80800074_chfpsgame(arg0, 0) &&
                (func_800F1574(&current->players[0].timer, func_800D8FF8()) ||
                 func_80016BBC(func_800F54F0(i), 0xD000))) {
                func_808013DC_chfpsgame(arg0, i, 3U);
            }
            break;
        case 3:
            if (func_800C9714(func_800A4C68(player))) {
                func_808013DC_chfpsgame(arg0, i, 0U);
            }
            break;
        }
        i++;
    if (i < _gcstatusDll_entrypoint_11()) {
        goto loop;
    }
}

s32 func_80801758_chfpsgame(s32 arg0) {
    void *func_80100094(Actor *, u32);
    s32 _sumultiscore_entrypoint_6(u8 *);
    return _sumultiscore_entrypoint_6((u8 *)func_80100094((Actor *)arg0, 0U) + 0x14);
}

void func_80801780_chfpsgame(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_800EB854(void);
    s32 _sumultiscore_entrypoint_12(s32, s32, s32);
    void _scradar_entrypoint_0(void);
    void _scradar_entrypoint_1(s32);
    void func_80801B30_chfpsgame(Actor *, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    switch (func_800EB854()) {
        case 3:
            _sumultiscore_entrypoint_12((s32)(sp1C + 0x14), arg1, 1);
            _scradar_entrypoint_0();
            _scradar_entrypoint_1(arg1);
            break;
        case 4:
            func_80801B30_chfpsgame(arg0, arg1);
            _sumultiscore_entrypoint_12((s32)(sp1C + 0x14), arg1, 2);
            break;
    }
}

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

s32 func_808018E0_chfpsgame(s32 arg0) {
    f32 func_800D8FF8(void);
    s32 func_800F0E28(s32, s32);
    s32 func_800F1418(s32, s32);
    s32 func_800F1574(f32 *, f32);
    void *func_80100094(Actor *, u32);
    void func_80801A8C_chfpsgame(Actor *, f32);
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;
    s32 sp20;
    s32 pad;
    u8 *temp_v0;

    temp_v0 = func_80100094((Actor *)arg0, 0U);
    if (*(f32 *)(temp_v0 + 0x55C) != 0.0f) {
        func_800F1574((f32 *)(temp_v0 + 0x560), func_800D8FF8());
        temp_f0 = *(f32 *)(temp_v0 + 0x560) * (1.0f / 60.0f);
        temp_f2 = (f32)(s32)temp_f0;
        *(s8 *)(temp_v0 + 0x55A) = (s8)(s32)temp_f2;
        temp_v0[0x55B] = (u8)(s32)((temp_f0 - temp_f2) * 60.0f);
        if (temp_v0[0x558] != 0) {
            sp20 = (s32)(func_800D8FF8() * 256.0f);
            if (func_800F1574((f32 *)(temp_v0 + 0x564), func_800D8FF8()) != 0) {
                func_80801A8C_chfpsgame((Actor *)arg0, 0.0f);
            }
            if (*(f32 *)(temp_v0 + 0x564) > 1.0f) {
                temp_v0[0x559] = func_800F1418(temp_v0[0x559] + sp20 * 4, 255);
                return;
            }
            if (*(f32 *)(temp_v0 + 0x564) < 0.5f) {
                temp_v0[0x559] = func_800F0E28(temp_v0[0x559] - sp20 * 2, 0);
            }
        } else {
            if (*(f32 *)(temp_v0 + 0x560) < 10.99f) {
                func_80801A8C_chfpsgame((Actor *)arg0, 60.0f);
                return;
            }
            if (temp_v0[0x55B] == 0) {
                func_80801A8C_chfpsgame((Actor *)arg0, 2.5f);
            }
        }
    }
}

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

void func_80801B30_chfpsgame(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void _fxdialog_entrypoint_1(s32, s32);
    void _fxdialog_entrypoint_2(f32);
    void _fxdialog_entrypoint_4(s32, s32, s32, f32, f32, s32, s32);
    void func_800B7F14(Gfx **);
    void func_800B811C(Gfx **);
    void func_800B8C50(void);
    void func_800B8C8C(s32);
    void func_800B8C98(s32);
    void func_800B8CBC(u8, u8, u8);
    s32 func_800B8E28(Gfx **, s32, s32, char *);
    char text[8];
    f32 scaled;
    f32 fraction;
    f32 phase;
    u8 *data;

    data = func_80100094(arg0, 0U);
    if (data[0x558] != 0) {
        phase = *(f32 *)(data + 0x560) * 0.5f;
        phase -= (s32)phase;
        _fxdialog_entrypoint_1(0x8F, 0x72);
        _fxdialog_entrypoint_2(0.75f);
        _fxdialog_entrypoint_4(arg1, 0xB4F, (s32)(phase * 20.0f), 0.0f, 0.0f, data[0x559], 0);
        func_800B8C50();
        func_800B8C8C(data[0x559]);
        func_800B8C98(3);
        func_800B8CBC(255, 255, 255);
        func_800B7F14((Gfx **)arg1);
        sprintf(text, "%d:%02d", data[0x55A], data[0x55B]);
        func_800B8E28((Gfx **)arg1, 0x99, 0x72, text);
        func_800B811C((Gfx **)arg1);
    }
}

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

void func_80801D40_chfpsgame(Actor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_8001211C(void);
    void func_80801DF0_chfpsgame(Actor *, s32, Unk80132ED0 *);
    void func_80801F34_chfpsgame(Actor *, s32);
    struct Entry { Unk80132ED0 *marker; s32 frame; };
    struct Group { s32 count; struct Entry entries[10]; };
    struct Data { s8 pad[0x568]; struct Group groups[4]; };
    struct Data *data;
    struct Group *group;
    struct Entry *entry;

    data = func_80100094(arg0, 0U);
    group = &data->groups[arg1];
    func_80801DF0_chfpsgame(arg0, arg1, arg2);
    if (group->count >= 10) {
        func_80801F34_chfpsgame(arg0, arg1);
    }
    entry = &group->entries[group->count];
    entry->marker = arg2;
    entry->frame = func_8001211C();
    group->count++;
}

void func_80801DF0_chfpsgame(Actor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    f32 func_800EEB40(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010108C(Actor *, s32, s32);
    struct Entry { Unk80132ED0 *marker; s32 unused; };
    struct Group { s32 count; struct Entry entries[10]; };
    struct Data { s32 count; s8 pad[0x564]; struct Group groups[4]; };
    struct Data *data;
    Actor *actor;
    struct Group *group;
    Actor *other;
    f32 *position;
    s32 hit;
    s32 i;
    s32 j;

    data = func_80100094(arg0, 0U);
    actor = func_80106790(arg2);
    hit = 0;
    for (i = 0; i < data->count; i++) {
        group = &data->groups[i];
        j = 0;
        if (group->count > 0) {
            position = actor->position;
            do {
                other = func_80106790(group->entries[j].marker);
                if (func_800EEB40(position, other->position) < 90000.0f) {
                    hit = 1;
                    func_8010108C(other, 0x40, 0);
                }
                j++;
            } while (j < group->count);
        }
    }
    if (hit) {
        func_8010108C(actor, 0x40, 0);
    }
}

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
