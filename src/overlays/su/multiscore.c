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

s32 sumultiscore_entrypoint_2(s32 *arg0, s32 *arg1, s32 *arg2, s32 arg3, s32 arg4) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_11();
    void func_800AA200(s32);
    void func_800AA20C(s32, s32);
    s32 func_800D3948(void);
    s32 indices[4];
    s32 ranks[4];
    s32 scores[4];
    s32 ties[4];
    s32 i;
    s32 count;

    for (i = 0; i < arg4; i++) {
        indices[i] = i;
        scores[i] = arg0[i];
        ties[i] = 0;
    }
    if (arg3 == 0) {
        sumultiscore_entrypoint_0(scores, indices, arg4);
        func_800AA200(0);
    } else {
        sumultiscore_entrypoint_1(scores, indices, arg4);
        func_800AA200(1);
    }
    func_80800140_sumultiscore(scores, ties, ranks, arg4);
    for (i = 0; i < arg4; i++) {
        arg1[indices[i]] = ranks[i];
        arg2[indices[i]] = ties[i];
    }
    if (func_800D3948() != 0) {
        count = _gcstatusDll_entrypoint_11();
        for (i = 0; i < count; i++) {
            func_800AA20C(i, arg0[i]);
        }
    }
    if (ranks[0] == ranks[1]) {
        return 0;
    }
    return indices[0] + 1;
}                    typedef struct { u8 pad0[0x12]; s16 unk12; s16 unk14; s16 unk16; } Objmultiscore_sumultiscore_entrypoint_3_temp_s1; /* offsets.py genstruct: fields from raw offsets on temp_s1; rename once understood */ typedef struct { s32 unk0; u8 pad4[0x514]; s32 unk518; } Objmultiscore_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void sumultiscore_entrypoint_3(u8 *arg0) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_11();
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

    (((Objmultiscore_arg0 *)arg0)->unk518) = _gcstatusDll_entrypoint_11();
    var_s2 = 0;
    if ((((Objmultiscore_arg0 *)arg0)->unk518) > 0) {
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
            (((Objmultiscore_sumultiscore_entrypoint_3_temp_s1 *)temp_s1)->unk12) = (s16) ((sp48 + sp50) - 0xE);
            (((Objmultiscore_sumultiscore_entrypoint_3_temp_s1 *)temp_s1)->unk14) = (s16) ((sp4C / 2) + sp54);
            (((Objmultiscore_sumultiscore_entrypoint_3_temp_s1 *)temp_s1)->unk16) = (s16) ((sp48 / 2) + sp50);
        } while (var_s2 < (((Objmultiscore_arg0 *)arg0)->unk518));
    }
    (((Objmultiscore_arg0 *)arg0)->unk0) = 0;
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
            entry = (struct ScoreEntry *)((BtUIntPtr)row - (0U - (*(u32 *)arg0 << 5)) + 0x40);
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
    BT_NATIVE_ONLY(return 0;)}

struct player_state_s;
struct player_state_s *func_800F53D0(BtIntPtr);

struct Entry {
    u8 unk0, unk1;
    s16 unk2;
    u8 unk4, unk5, unk6, unk7;
    s16 unk8;
    u8 padA[6];
    f32 unk10, unk14;
    f32 unk18;
    s32 unk1C;
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
    s32 _badeathmatch_entrypoint_9(void *arg0, s32 arg1);
    extern s32 D_808014B0_sumultiscore[];
    struct Row *row;
    struct Entry *src;
    struct Entry *dst;
    BtIntPtr var_a1;

    var_a1 = arg1;
    row = &arg0->rows[var_a1];
    src = arg0->order[arg2] + row->entries;
    dst = arg0->order[0] + row->entries;
    if (row->previous != 0) {
        var_a1 = (BtIntPtr)(arg0->order[row->previous] + row->entries);
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

void sumultiscore_entrypoint_6(struct Multi *arg0) {
    f32 func_800138D0(f32);
    f32 func_800D8FF8(void);
    s32 func_800F1574(f32 *, f32);
    f32 mlAbsF(f32);
    void func_80800BFC_sumultiscore(struct Multi *, s32, struct Entry *);
    void func_80800D24_sumultiscore(BtIntPtr, s32, void *);
    void func_80800D54_sumultiscore(BtIntPtr, s32, s32);
    void func_80800D64_sumultiscore(BtIntPtr, s32, void *);
    void func_80800DD0_sumultiscore(BtIntPtr, s32, u8 *);
    void func_80800E84_sumultiscore(BtIntPtr, s32, s32);
    s32 i;
    s32 j;
    struct Row *slot;
    BtIntPtr entry;
    f32 timer;

    for (i = 0; i < *(s32 *)((u8 *)arg0 + 0x518); i++) {
        for (j = 0; j < arg0->unk0; j++) {
            slot = (struct Row *)((BtIntPtr)&arg0->rows[i] + (j << 5));
            entry = (BtIntPtr)&slot->entries[0];
            if (slot->entries[0].unk18 != 0.0f) {
                func_800F1574(&((struct Entry *)entry)->unk18, func_800D8FF8());
                timer = ((struct Entry *)entry)->unk18;
                timer -= (s32)timer;
                ((struct Entry *)entry)->unk5 = (s32)(mlAbsF(func_800138D0(timer * 720.0f)) * 255.99f);
            }
            switch (((struct Entry *)entry)->unk0) {
                case 0: func_80800BFC_sumultiscore(arg0, i, (struct Entry *)entry); break;
                case 1: func_80800D24_sumultiscore((BtIntPtr)arg0, i, (struct Entry *)entry); break;
                case 2: func_80800D54_sumultiscore((BtIntPtr)arg0, i, (s32)entry); break;
                case 3: func_80800D64_sumultiscore((BtIntPtr)arg0, i, (struct Entry *)entry); break;
                case 4: func_80800DD0_sumultiscore((BtIntPtr)arg0, i, &((struct Entry *)entry)->unk0); break;
                case 5: func_80800E84_sumultiscore((BtIntPtr)arg0, i, (s32)entry); break;
            }
        }
    }
}

/* extern */

void func_80800BFC_sumultiscore(struct Multi *arg0, s32 arg1, struct Entry *arg2) {
    s32 _badeathmatch_entrypoint_9(void *arg0, s32 arg1);
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
    s32 func_800F1574(f32 *, f32);
    f32 mlAbsF(f32);
    BtIntPtr var_a1;
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
            var_a1 = (BtIntPtr)(row->rows[0].entries + arg0->order[row->rows[0].previous]);
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
}                    typedef struct { u8 pad0[0x2]; s16 unk2; u8 pad4[0x1]; u8 unk5; u8 unk6; u8 pad7[0x1]; s16 unk8; u8 padA[0xA]; f32 unk14; } Objmultiscore_arg2; /* offsets.py genstruct: fields from raw offsets on arg2; rename once understood */

/* extern */

void func_80800D24_sumultiscore(BtIntPtr arg0, s32 arg1, void *arg2) {
    s32 func_800F5578(BtIntPtr arg0);
    (((Objmultiscore_arg2 *)arg2)->unk8) = func_800F5578(arg1);
}

void func_80800D54_sumultiscore(BtIntPtr arg0, s32 arg1, s32 arg2) {
}
void func_80800D64_sumultiscore(BtIntPtr arg0, s32 arg1, void *arg2) {
    s32 _badeathmatch_entrypoint_6(BtIntPtr);
    s32 _badeathmatch_entrypoint_9(void *arg0, s32 arg1);
    extern s32 D_808014B0_sumultiscore[];
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = _badeathmatch_entrypoint_6(func_800F53D0(arg1));
    sp1C = temp_v0;
    (((Objmultiscore_arg2 *)arg2)->unk2) = (s16) D_808014B0_sumultiscore[temp_v0];
    (((Objmultiscore_arg2 *)arg2)->unk8) = _badeathmatch_entrypoint_9(func_800F53D0(arg1), sp1C);
}

/* extern */

void func_80800DD0_sumultiscore(BtIntPtr arg0, s32 arg1, u8 *arg2) {
    f32 func_800D8FF8();
    s32 func_800F1418(s32 arg0, s32 arg1);
    s32 func_800F1574(f32 *, f32);
    u8 temp_v0;

    if ((((Objmultiscore_arg2 *)arg2)->unk14) != 0.0f) {
        func_800F1574(arg2 + 0x14, func_800D8FF8());
        if ((((Objmultiscore_arg2 *)arg2)->unk6) == 0) {
            (((Objmultiscore_arg2 *)arg2)->unk6) = 1U;
            (((Objmultiscore_arg2 *)arg2)->unk5) = 0U;
            return;
        }
        (((Objmultiscore_arg2 *)arg2)->unk5) = func_800F1418((((Objmultiscore_arg2 *)arg2)->unk5) + 0x20, 0xFF);
        return;
    }
    if ((((Objmultiscore_arg2 *)arg2)->unk6) != 0) {
        temp_v0 = (((Objmultiscore_arg2 *)arg2)->unk5);
        if ((s32) temp_v0 >= 0x21) {
            (((Objmultiscore_arg2 *)arg2)->unk5) = (u8) (temp_v0 - 0x20);
            return;
        }
        (((Objmultiscore_arg2 *)arg2)->unk6) = 0U;
    }
}

void func_80800E84_sumultiscore(BtIntPtr arg0, s32 arg1, s32 arg2) {
}
void sumultiscore_entrypoint_7(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3) {
    void sumultiscore_entrypoint_9(BtIntPtr, BtIntPtr, s32, s32);
    s8 *table = (s8 *)arg0 + (arg2 << 2);
    s32 index = *(s32 *)(table + 4);
    BtIntPtr offset = arg1 * 0x13C;
    arg3 += *(s16 *)((s8 *)(arg0 + offset + (index << 5)) + 0x48);
    sumultiscore_entrypoint_9(arg0, arg1, arg2, arg3);
}

s16 sumultiscore_entrypoint_8(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s8 *table = (s8 *)arg0 + (arg2 << 2);
    s32 index = *(s32 *)(table + 4);
    BtIntPtr offset = arg1 * 0x13C;
    return *(s16 *)((s8 *)(arg0 + offset + (index << 5)) + 0x48);
}

void sumultiscore_entrypoint_9(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3) {
    BtIntPtr base;
    s32 index;
    BtIntPtr offset;
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

void sumultiscore_entrypoint_12(BtIntPtr arg0, BtIntPtr arg1, s32 arg2) {
    void func_800B7F14(Gfx **);
    void func_800B811C(Gfx **);
    void func_800B8C50(void);
    void func_800B8C98(s32);
    void func_800B8CBC(u8, u8, u8);
    void func_80801160_sumultiscore(u16 (*)[2], void *, BtIntPtr);
    void func_808011E0_sumultiscore(u16 (*)[2], u8 *, s32, Gfx **);
    s32 i;
    s32 j;
    u8 *base;
    u8 *entry;

    for (j = 0; j < *(s32 *)(arg0 + 0x518); j++) {
        base = (u8 *)arg0 + j * 0x13C + 0x28;
        for (i = 0; i < *(s32 *)arg0; i++) {
            entry = base + (u32)i * 0x20;
            if (arg2 == entry[0x1E]) {
                func_80801160_sumultiscore((u16 (*)[2])base, (void *)((BtIntPtr)base + (i << 5) + 0x18), arg1);
            }
        }
    }
    func_800B8C50();
    func_800B8C98(3);
    func_800B8CBC(255, 255, 255);
    func_800B7F14((Gfx **)arg1);
    for (j = 0; j < *(s32 *)(arg0 + 0x518); j++) {
        base = (u8 *)arg0 + j * 0x13C + 0x28;
        for (i = 0; i < *(s32 *)arg0; i++) {
            entry = base + (u32)i * 0x20;
            if (arg2 == entry[0x1E]) {
                func_808011E0_sumultiscore((u16 (*)[2])base, (u8 *)((BtIntPtr)base + (i << 5) + 0x18), j, (Gfx **)arg1);
            }
        }
    }
    func_800B811C((Gfx **)arg1);
} 

/* extern */

void func_80801160_sumultiscore(u16 (*arg0)[2], void *arg1, BtIntPtr arg2) {
    void _fxdialog_entrypoint_1(s32, s32);
    void _fxdialog_entrypoint_2(f32);
    void _fxdialog_entrypoint_4(BtIntPtr arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6);
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

void func_808011E0_sumultiscore(u16 (*positions)[2], u8 *entry, s32 player, Gfx **graphics) {
    s32 func_8001210C(s32);
    void func_800B80D0(Gfx **);
    void func_800B8C8C(s32);
    void func_800B8C98(s32);
    s32 func_800B8E28(BtIntPtr, s32, s32, u8 *);
    char buf[16];
    s32 x, y;
    s32 alpha;
    u16 *position = positions[entry[1]];
    x = position[0] + (s8)entry[10];
    y = position[1] + (s8)entry[11];
    if (entry[0] == 5) {
        if (entry[7] && func_8001210C(8)) {
            alpha = entry[5];
        } else {
            alpha = entry[5] >> 1;
        }
        func_800B8C98(0);
        func_800B8C8C(alpha);
        func_800B80D0(graphics);
        sprintf(buf, "PLAYER %d", player + 1);
        func_800B8E28((BtIntPtr)graphics, x - 0x20, y - 0xC, (u8 *)buf);
    }
    alpha = (s32)((f32)(u32)entry[5] * 0.667f);
    func_800B8C98(3);
    func_800B8C8C(alpha);
    func_800B80D0(graphics);
    sprintf(buf, "%d", *(s16 *)(entry + 8));
    func_800B8E28((BtIntPtr)graphics, x, y, (u8 *)buf);
}

void func_80801340_sumultiscore(void *arg0, s32 arg1) {
    u8 _gcstatusDll_entrypoint_13(s32 arg0);

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
/* data_to_c.py: from asm/data/overlays/su/multiscore.data.s */
s32 D_808014B0_sumultiscore [8] BT_DATA(4, overlays_su_multiscore, 0x0) = { 0, 2945, 2947, 2946, 2948, 2949, 2501, 2499 };
