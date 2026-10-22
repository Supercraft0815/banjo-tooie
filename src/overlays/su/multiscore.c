#include "common.h"

void sumultiscore_entrypoint_0(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 i;
    s32 j;
    s32 temp;

    for (i = 1; i < arg2; i++) {
        for (j = i; j > 0 && arg0[j - 1] < arg0[j]; j--) {
            temp = arg0[j];
            arg0[j] = arg0[j - 1];
            arg0[j - 1] = temp;
            temp = arg1[j];
            arg1[j] = arg1[j - 1];
            arg1[j - 1] = temp;
        }
    }
}

void sumultiscore_entrypoint_1(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 i;
    s32 j;
    s32 temp;

    for (i = 1; i < arg2; i++) {
        for (j = i; j > 0 && arg0[j] < arg0[j - 1]; j--) {
            temp = arg0[j];
            arg0[j] = arg0[j - 1];
            arg0[j - 1] = temp;
            temp = arg1[j];
            arg1[j] = arg1[j - 1];
            arg1[j - 1] = temp;
        }
    }
}

void func_80800140_sumultiscore(s32 *arg0, s32 *arg1, s32 *arg2, s32 arg3) {
    s32 i;
    s32 rank = 1;

    for (i = 0; i < arg3; i++) {
        if (rank >= 2 && arg0[i] == arg0[i - 1]) {
            arg2[i] = arg2[i - 1];
            arg1[i] = 1;
            arg1[i - 1] = 1;
        } else {
            arg2[i] = rank;
        }
        rank++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_2.s")

/* extern */

void sumultiscore_entrypoint_3(u8 *arg0) {
    s32 _gcstatusDll_entrypoint_11();
    void func_800A8A04(s32, s32 *, s32 *, s32 *, s32 *);
    s32 func_800A940C(s32);
    s32 sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    register s32 var_s2;
    register u8 *temp_s1;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    register u8 *var_s0;

    (*(s32 *)((s8 *)(arg0) + (0x518))) = _gcstatusDll_entrypoint_11();
    var_s2 = 0;
    if ((*(s32 *)((s8 *)(arg0) + (0x518))) > 0) {
        var_s0 = arg0 + 0x28;
        do {
            temp_s1 = var_s0;
            func_800A8A04(func_800A940C(var_s2), &sp54, &sp50, &sp4C, &sp48);
            var_s2 += 1;
            var_s0 += 0x13C;
            (*(s16 *)((s8 *)(var_s0) + (-0x13C))) = (s16) (sp54 + 0x1C);
            (*(s16 *)((s8 *)(var_s0) + (-0x13A))) = (s16) (sp50 + 0xE);
            (*(s16 *)((s8 *)(var_s0) + (-0x138))) = (s16) ((sp4C / 2) + sp54);
            (*(s16 *)((s8 *)(var_s0) + (-0x136))) = (s16) (sp50 + 0xE);
            (*(s16 *)((s8 *)(var_s0) + (-0x134))) = (s16) ((sp4C + sp54) - 0x1C);
            (*(s16 *)((s8 *)(var_s0) + (-0x132))) = (s16) (sp50 + 0xE);
            (*(s16 *)((s8 *)(var_s0) + (-0x130))) = (s16) (sp54 + 0x1C);
            (*(s16 *)((s8 *)(var_s0) + (-0x12E))) = (s16) ((sp48 + sp50) - 0xE);
            (*(s16 *)((s8 *)(var_s0) + (-0x12C))) = (s16) ((sp4C + sp54) - 0x1C);
            (*(s16 *)((s8 *)(temp_s1) + (0x12))) = (s16) ((sp48 + sp50) - 0xE);
            (*(s16 *)((s8 *)(temp_s1) + (0x14))) = (s16) ((sp4C / 2) + sp54);
            (*(s16 *)((s8 *)(temp_s1) + (0x16))) = (s16) ((sp48 / 2) + sp50);
        } while (var_s2 < (*(s32 *)((s8 *)(arg0) + (0x518))));
    }
    (*(s32 *)((s8 *)(arg0) + (0))) = 0;
    sumultiscore_entrypoint_4(arg0, 0, 5, 0);
}

s32 sumultiscore_entrypoint_4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_80801340_sumultiscore(void *, s32);
    struct ScoreEntry {
        u8 kind, mode;
        s16 image;
        u8 frame, alpha, flag, pad7;
        s16 value;
        s8 x, y;
        volatile s8 dx;
        s8 dy;
        u8 padE[2];
        f32 scale;
        u8 pad14[12];
    };
    s32 i;
    struct ScoreEntry *entry;
    u8 *row;

    i = 0;
    row = arg0;
    if (*(s32 *)(arg0 + 0x518) > 0) {
        do {
            entry = (struct ScoreEntry *)((u32)row - (0U - (*(u32 *)arg0 << 5)) + 0x40);
            ((volatile struct ScoreEntry *)entry)->kind = arg1;
            ((volatile struct ScoreEntry *)entry)->mode = arg2;
            entry->flag = arg3;
            ((volatile struct ScoreEntry *)entry)->frame = 0;
            ((volatile struct ScoreEntry *)entry)->alpha = 0xFF;
            ((volatile struct ScoreEntry *)entry)->value = 0;
            ((volatile struct ScoreEntry *)entry)->x = 5;
            ((volatile struct ScoreEntry *)entry)->y = 0;
            ((volatile struct ScoreEntry *)entry)->dx = -5;
            ((volatile struct ScoreEntry *)entry)->dy = 0;
            switch (arg1) {
                case 0:
                    entry->alpha = 0;
                    break;
                case 1:
                    entry->image = 0xB4D;
                    entry->scale = 0.4f;
                    break;
                case 2:
                case 5:
                    func_80801340_sumultiscore(entry, i);
                    break;
                case 3:
                    entry->image = 0xB81;
                    entry->scale = 0.5f;
                    break;
                case 4:
                    entry->image = 0xC14;
                    entry->scale = 0.5f;
                    break;
                case 6:
                    entry->image = 0xB89;
                    entry->scale = 0.75f;
                    entry->x = 10;
                    entry->dx -= 5;
                    break;
                case 7:
                    entry->image = 0xB8B;
                    entry->scale = 0.75f;
                    entry->dx -= 5;
                    break;
                case 8:
                    func_80801340_sumultiscore(entry, i);
                    break;
            }
            i++;
            row += 0x13C;
        } while (i < *(s32 *)(arg0 + 0x518));
    }
    *(s32 *)(arg0 + arg1 * 4 + 4) = *(s32 *)arg0;
    *(s32 *)arg0 += 1;
}

struct player_state_s;
struct player_state_s *func_800F53D0(s32);

struct Entry {
    u8 unk0, unk1;
    s16 unk2;
    u8 unk4, unk5, unk6, unk7;
    s16 unk8;
    u8 padA[6];
    f32 unk10, unk14;
    s32 unk18, unk1C;
};
struct Row {
    u8 pad0[0x18];
    struct Entry entries[9];
    s32 previous;
};
struct Multi {
    s32 unk0;
    s32 order[9];
    struct Row rows[4];
};

void sumultiscore_entrypoint_5(struct Multi *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 _badeathmatch_entrypoint_9(s32, s32);
    extern s32 D_808014B0_sumultiscore[];
    struct Row *row;
    struct Entry *src;
    struct Entry *dst;
    s32 var_a1;

    var_a1 = arg1;
    row = &arg0->rows[var_a1];
    src = arg0->order[arg2] + row->entries;
    dst = arg0->order[0] + row->entries;
    if (row->previous != 0) {
        var_a1 = (s32)(arg0->order[row->previous] + row->entries);
        ((struct Entry *)var_a1)->unk6 = dst->unk6;
    }
    row->previous = arg2;
    dst->unk1 = src->unk1;
    dst->unk10 = src->unk10;
    dst->unk1C = arg3;
    dst->unk6 = src->unk6;
    src->unk6 = 0;
    if (arg2 == 3) {
        dst->unk2 = D_808014B0_sumultiscore[arg3];
        dst->unk4 = 0;
        dst->unk8 = _badeathmatch_entrypoint_9(func_800F53D0(arg1), arg3);
        dst->unk5 = 0;
        dst->unk14 = 1.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_6.s")

/* extern */

void func_80800BFC_sumultiscore(struct Multi *arg0, s32 arg1, struct Entry *arg2) {
    s16 _badeathmatch_entrypoint_9(s32, s32);
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
    s32 func_800F1574(f32 *, f32);
    f32 mlAbsF(f32);
    s32 var_a1;
    s32 sp38;
    struct Multi *row;
    f32 temp_f0;
    s32 integerPart;

    if (arg2->unk6 != 0) {
        row = (struct Multi *)((u8 *)arg0 + arg1 * sizeof(struct Row));
        if (row->rows[0].previous == 3) {
            sp38 = arg2->unk1C;
            arg2->unk8 = _badeathmatch_entrypoint_9(func_800F53D0(arg1), sp38);
        }
        if (func_800F1574(&arg2->unk14, func_800D8FF8()) != 0) {
            var_a1 = (s32)(row->rows[0].entries + arg0->order[row->rows[0].previous]);
            ((struct Entry *)var_a1)->unk6 = arg2->unk6;
            row->rows[0].previous = 0;
            arg2->unk6 = 0;
        } else {
        temp_f0 = arg2->unk14;
        integerPart = (s32)temp_f0;
        temp_f0 -= (f32)integerPart;
        arg2->unk5 = (s32)(mlAbsF(func_80013970(temp_f0 * 720.0f)) * 255.99f);
        }
    }
}

/* extern */

void func_80800D24_sumultiscore(s32 arg0, s32 arg1, void *arg2) {
    s16 func_800F5578(s32);
    (*(s16 *)((s8 *)(arg2) + (8))) = func_800F5578(arg1);
}

void func_80800D54_sumultiscore(s32 arg0, s32 arg1, s32 arg2) {
}
void func_80800D64_sumultiscore(s32 arg0, s32 arg1, void *arg2) {
    s32 _badeathmatch_entrypoint_6(s32);
    s16 _badeathmatch_entrypoint_9(s32, s32);
    extern s32 D_808014B0_sumultiscore[];
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = _badeathmatch_entrypoint_6(func_800F53D0(arg1));
    sp1C = temp_v0;
    (*(s16 *)((s8 *)(arg2) + (2))) = (s16) D_808014B0_sumultiscore[temp_v0];
    (*(s16 *)((s8 *)(arg2) + (8))) = _badeathmatch_entrypoint_9(func_800F53D0(arg1), sp1C);
}

/* extern */

void func_80800DD0_sumultiscore(s32 arg0, s32 arg1, u8 *arg2) {
    f32 func_800D8FF8();
    u8 func_800F1418(s32, s32);
    s32 func_800F1574(f32 *, f32);
    u8 temp_v0;

    if ((*(f32 *)((s8 *)(arg2) + (0x14))) != 0.0f) {
        func_800F1574(arg2 + 0x14, func_800D8FF8());
        if ((*(u8 *)((s8 *)(arg2) + (6))) == 0) {
            (*(u8 *)((s8 *)(arg2) + (6))) = 1U;
            (*(u8 *)((s8 *)(arg2) + (5))) = 0U;
            return;
        }
        (*(u8 *)((s8 *)(arg2) + (5))) = func_800F1418((*(u8 *)((s8 *)(arg2) + (5))) + 0x20, 0xFF);
        return;
    }
    if ((*(u8 *)((s8 *)(arg2) + (6))) != 0) {
        temp_v0 = (*(u8 *)((s8 *)(arg2) + (5)));
        if ((s32) temp_v0 >= 0x21) {
            (*(u8 *)((s8 *)(arg2) + (5))) = (u8) (temp_v0 - 0x20);
            return;
        }
        (*(u8 *)((s8 *)(arg2) + (6))) = 0U;
    }
}

void func_80800E84_sumultiscore(s32 arg0, s32 arg1, s32 arg2) {
}
void sumultiscore_entrypoint_7(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void sumultiscore_entrypoint_9(s32, s32, s32, s32);
    s8 *table = (s8 *)arg0 + (arg2 << 2);
    s32 index = *(s32 *)(table + 4);
    s32 offset = arg1 * 0x13C;
    arg3 += *(s16 *)((s8 *)(arg0 + offset + (index << 5)) + 0x48);
    sumultiscore_entrypoint_9(arg0, arg1, arg2, arg3);
}

s16 sumultiscore_entrypoint_8(s32 arg0, s32 arg1, s32 arg2) {
    s8 *table = (s8 *)arg0 + (arg2 << 2);
    s32 index = *(s32 *)(table + 4);
    s32 offset = arg1 * 0x13C;
    return *(s16 *)((s8 *)(arg0 + offset + (index << 5)) + 0x48);
}

void sumultiscore_entrypoint_9(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 base;
    s32 index;
    s32 offset;
    offset = arg1 * 0x13C;
    base = arg0 + offset;
    index = *(s32 *)((s8 *)arg0 + (arg2 << 2) + 4);
    *(s16 *)((s8 *)base + (index << 5) + 0x48) = arg3;
    if (arg2 == 4) {
        *(f32 *)((s8 *)base + (index << 5) + 0x54) = 1.0f;
    }
}

void sumultiscore_entrypoint_10(u8 *arg0, s32 arg1) {
    s32 value = *(s32 *)(arg0 + 0x18);
    arg0[arg1 * 0x13C + (value << 5) + 0x47] = 1;
}

void sumultiscore_entrypoint_11(s32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 index = arg0[arg2 + 1];
    s32 offset = arg1 * 0x13C;
    *(f32 *)((s8 *)arg0 + offset + (index << 5) + 0x58) = arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_12.s")

/* extern */

void func_80801160_sumultiscore(u16 (*arg0)[2], void *arg1, s32 arg2) {
    void _fxdialog_entrypoint_1(s32, s32);
    void _fxdialog_entrypoint_2(f32);
    void _fxdialog_entrypoint_4(s32, u16, u8, f32, f32, s32, s32);
    u16 *temp_v0;
    s32 x;
    s32 y;

    temp_v0 = arg0[*(u8 *)((s8 *)arg1 + 1)];
    x = temp_v0[0] + *(s8 *)((s8 *)arg1 + 0xC);
    y = temp_v0[1] + *(s8 *)((s8 *)arg1 + 0xD);
    _fxdialog_entrypoint_1(x, y);
    _fxdialog_entrypoint_2((*(f32 *)((s8 *)(arg1) + (0x10))));
    _fxdialog_entrypoint_4(arg2, (*(u16 *)((s8 *)(arg1) + (2))), (*(u8 *)((s8 *)(arg1) + (4))), 0.0f, 0.0f, (s32) (*(u8 *)((s8 *)(arg1) + (5))), 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/func_808011E0_sumultiscore.s")

void func_80801340_sumultiscore(void *arg0, s32 arg1) {
    s32 _gcstatusDll_entrypoint_13();

    switch (_gcstatusDll_entrypoint_13(arg1)) {
        default:
            *(s16 *)((s8 *)arg0 + 2) = 0xB50; *(s8 *)((s8 *)arg0 + 0xA) += 10; *(f32 *)((s8 *)arg0 + 0x10) = 0.5f;
            break;
        case 2:
            *(s16 *)((s8 *)arg0 + 2) = 0xBD9;
            *(f32 *)((s8 *)arg0 + 0x10) = 0.6f;
            *(s8 *)((s8 *)arg0 + 0xC) -= 5;
            break;
        case 3:
            *(s16 *)((s8 *)arg0 + 2) = 0xBD0;
            *(f32 *)((s8 *)arg0 + 0x10) = 0.6f;
            *(s8 *)((s8 *)arg0 + 0xC) -= 5;
            break;
        case 4:
            *(s16 *)((s8 *)arg0 + 2) = 0xBAB;
            *(f32 *)((s8 *)arg0 + 0x10) = 0.7f;
            *(s8 *)((s8 *)arg0 + 0xC) -= 7;
            break;
        case 5:
            *(s16 *)((s8 *)arg0 + 2) = 0xBA2;
            *(f32 *)((s8 *)arg0 + 0x10) = 0.6f;
            *(s8 *)((s8 *)arg0 + 0xC) -= 6;
            break;
    }
}
