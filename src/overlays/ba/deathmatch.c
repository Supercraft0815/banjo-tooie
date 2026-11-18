#include "common.h"

typedef struct { u8 pad0[0x158]; union { void * unk158; u8 * unk158_u8p; }; u8 pad15C[0x28]; s32 unk184; } Objdeathmatch_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_badeathmatch(void *arg0) {
    (*(s8 *)((s8 *)((((Objdeathmatch_arg0 *)arg0)->unk158)) + (0x20))) = 1;
    (*(s8 *)((s8 *)((((Objdeathmatch_arg0 *)arg0)->unk158)) + (0x21))) = 0;
    (*(s8 *)((s8 *)((((Objdeathmatch_arg0 *)arg0)->unk158)) + (0x22))) = 0;
    (*(s8 *)((s8 *)((((Objdeathmatch_arg0 *)arg0)->unk158)) + (0x23))) = 0;
}

s32 func_80800028_badeathmatch(s32 arg0) {
    extern u8 D_80800550_badeathmatch[];
    return D_80800550_badeathmatch[arg0 - 1];
}    typedef struct { u8 pad0[0x20]; u8 unk20; } Objdeathmatch_badeathmatch_entrypoint_0_temp_s2; /* offsets.py genstruct: fields from raw offsets on temp_s2; rename once understood */ typedef struct { s16 unk0; } Objdeathmatch_badeathmatch_entrypoint_0_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */

/* extern */

s32 badeathmatch_entrypoint_0(u8 *arg0) {
    s16 _gcegg_entrypoint_2(s32 arg0);
    void func_800FC6B0(u32);
    s16 *temp_v1;
    s32 var_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s1;
    u8 *temp_s2;

    temp_s2 = (((Objdeathmatch_arg0 *)arg0)->unk158_u8p);
    var_s0 = 1;
    var_s1 = (((Objdeathmatch_badeathmatch_entrypoint_0_temp_s2 *)temp_s2)->unk20);
loop_1:
    temp_v0 = func_80800028_badeathmatch(var_s1);
    temp_v1 = &((s16 *)temp_s2)[temp_v0];
    var_s0 += 1;
    var_s1 = temp_v0;
    if (temp_v1[8] == 0) {
        if (var_s0 != 8) {
            goto loop_1;
        }
    }
    if ((((Objdeathmatch_badeathmatch_entrypoint_0_temp_v1 *)temp_v1)->unk0) == 0) {
        do {
            temp_v0_2 = func_80800028_badeathmatch(var_s1);
            var_s1 = temp_v0_2;
        } while (((s16 *)temp_s2)[temp_v0_2] == 0);
    }
    (*(u8 *)((s8 *)((((Objdeathmatch_arg0 *)arg0)->unk158_u8p)) + (0x20))) = var_s1;
    func_800FC6B0(_gcegg_entrypoint_2(var_s1));
    return var_s1;
}

/* extern */

void badeathmatch_entrypoint_1(void *arg0) {
    void aligned8_memset(void *dst, u32 value, u32 n);
    s32 func_800EA068(s32);
    BtIntPtr heap_alloc(s32);
    BtIntPtr temp_v0;

    if (func_800EA068(0x40) != 0) {
        temp_v0 = heap_alloc(0x30);
        (*(s32 *)((s8 *)(arg0) + (0x158))) = temp_v0;
        aligned8_memset(temp_v0, 0, 0x30);
        func_80800000_badeathmatch(arg0);
    }
}

/* extern */

void badeathmatch_entrypoint_2(void *arg0) {
    s32 func_800A4C68(void *);
    s32 func_800C968C(s32, s32);
    s32 heap_free(s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x158))) != 0) {
        heap_free((*(s32 *)((s8 *)(arg0) + (0x158))));
        (*(s32 *)((s8 *)(arg0) + (0x158))) = 0;
        func_800C968C(func_800A4C68(arg0), 9);
    }
}

void badeathmatch_entrypoint_3(void *arg0) {
    struct player_state_s;
    int _batimer_decrement(struct player_state_s *, s32);
    int bainput_func_80097D28(struct player_state_s *);
    s32 bs_getCurrentState(struct player_state_s *);
    int func_800A3274(struct player_state_s *);
    void badeathmatch_entrypoint_8(void *, f32);
    u8 *temp_v0;
    s32 temp_v1;

    if ((func_800A3274(arg0) != 0x11) && (bs_getCurrentState(arg0) != 0xD7)) {
        temp_v0 = ((Objdeathmatch_arg0 *)arg0)->unk158;
        if (temp_v0[0x21] == 0) {
            temp_v1 = temp_v0[0x23];
            if (((temp_v1 == 0) & 1) && (bainput_func_80097D28(arg0) != 0)) {
                badeathmatch_entrypoint_0(arg0);
            }
        } else if ((temp_v0[0x22] != 0) && (_batimer_decrement(arg0, 0xD) != 0)) {
            badeathmatch_entrypoint_8(arg0, 0.0f);
        }
    }
}

s32 badeathmatch_entrypoint_4(s32 arg0) {
    switch (arg0) {
    case 0x40:
        return 1;
    case 0x41:
        return 2;
    case 0x42:
        return 3;
    case 0x43:
        return 4;
    case 0x44:
        return 5;
    case 0x45:
        return 6;
    default:
        return 0;
    }
}

/* extern */

s32 badeathmatch_entrypoint_5(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800F0D90(s32, s32, s32);
    s32 func_80101238(s32, s32);
    s16 sp2E;
    s32 temp_v1;

    temp_v1 = arg1 * 2;
    sp2E = *(s16 *)(*(u8 **)(arg0 + 0x158) + temp_v1);
    if (sp2E < 0) {
        return 1;
    }
    {
        s32 sum;
        sum = *(s16 *)(*(u8 **)(arg0 + 0x158) + temp_v1 + 0x10) + arg2;
        (*(s16 *)((s8 *)(((((Objdeathmatch_arg0 *)arg0)->unk158_u8p) + temp_v1)) + (0x10))) = func_800F0D90(sum, 0, sp2E);
    }
    if (arg2 > 0) {
        s32 sp1C;
        sp1C = (arg1 << 4);
        sp1C += (((Objdeathmatch_arg0 *)arg0)->unk184);
        if (((s16 *)*(u8 **)(arg0 + 0x158))[(*(u8 *)(*(u8 **)(arg0 + 0x158) + 0x20)) + 8] == 0) {
            (*(u8 *)(*(u8 **)(arg0 + 0x158) + 0x20)) = (u8) arg1;
        }
        func_80101238(0x72, sp1C);
    }
    return (*(s16 *)((s8 *)(((((Objdeathmatch_arg0 *)arg0)->unk158_u8p) + temp_v1)) + (0x10)));
}    typedef struct { u8 pad0[0x20]; u8 unk20; u8 unk21; } Objdeathmatch_badeathmatch_entrypoint_6_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

s32 badeathmatch_entrypoint_6(void *arg0) {
    void *temp_v0;
    u8 result;

    temp_v0 = (((Objdeathmatch_arg0 *)arg0)->unk158);
    if ((((Objdeathmatch_badeathmatch_entrypoint_6_temp_v0 *)temp_v0)->unk21) != 0) {
        result = 7;
    } else {
        result = (((Objdeathmatch_badeathmatch_entrypoint_6_temp_v0 *)temp_v0)->unk20);
    }
    return result;
}

void badeathmatch_entrypoint_7(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Objdeathmatch_arg0 *)arg0)->unk158 + 32) = arg1;
}

/* extern */

void badeathmatch_entrypoint_8(void *arg0, f32 arg1) {
    BT_IDO_ONLY(s32 _batimer_set(f32, s32, f32);) BT_NATIVE_ONLY(void _batimer_set(void *, s32, f32);)
    s32 func_80101180(s32, s32, BtIntPtr);
    if (arg1 != 0.0f) {
        (*(s8 *)((s8 *)((((Objdeathmatch_arg0 *)arg0)->unk158)) + (0x21))) = 1;
    } else {
        (*(s8 *)((s8 *)((((Objdeathmatch_arg0 *)arg0)->unk158)) + (0x21))) = 0;
    }
    if (arg1 > 0.0f) {
        (*(s8 *)((s8 *)((((Objdeathmatch_arg0 *)arg0)->unk158)) + (0x22))) = 1;
    } else {
        (*(s8 *)((s8 *)((((Objdeathmatch_arg0 *)arg0)->unk158)) + (0x22))) = 0;
    }
    BT_IDO_ONLY(_batimer_set(arg1, 0xD, arg1);) BT_NATIVE_ONLY(_batimer_set(arg0, 0xD, arg1);)
    if ((*(u8 *)((s8 *)((((Objdeathmatch_arg0 *)arg0)->unk158)) + (0x21))) == 0) {
        func_80101180(0x1CD, 0x76, 0);
    }
}    typedef struct { u8 pad0[0x21]; u8 unk21; } Objdeathmatch_badeathmatch_entrypoint_9_temp_a2; /* offsets.py genstruct: fields from raw offsets on temp_a2; rename once understood */

/* extern */

s32 badeathmatch_entrypoint_9(void *arg0, s32 arg1) {
    f32 _batimer_get(void *, s32);
    s32 var_v1;
    s32 temp_a0;
    u8 *temp_a2;
    BtIntPtr temp_v0;

    temp_a2 = (((Objdeathmatch_arg0 *)arg0)->unk158_u8p);
    temp_v0 = (BtIntPtr)temp_a2 + (arg1 * 2);
    if ((((Objdeathmatch_badeathmatch_entrypoint_9_temp_a2 *)temp_a2)->unk21) != 0) {
        return (s32) (_batimer_get(arg0, 0xD) + 0.5f);
    }
    var_v1 = *(s16 *)temp_v0;
    temp_a0 = *(s16 *)(temp_v0 + 0x10);
    if (var_v1 < 0) {
        var_v1 = 1;
    } else {
        var_v1 = temp_a0;
    }
    return (s32) var_v1;
}

void badeathmatch_entrypoint_10(void *arg0, s32 arg1, s32 arg2, s32 arg3) { *(s16 *)(*(s32 *)((s8 *)arg0 + 0x158) + (arg1 * 2) + 0x10) = arg2; *(s16 *)(*(s32 *)((s8 *)arg0 + 0x158) + (arg1 * 2)) = arg3; }    typedef struct { u8 pad0[0x23]; u8 unk23; } Objdeathmatch_badeathmatch_entrypoint_11_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x23]; u8 unk23; } Objdeathmatch_badeathmatch_entrypoint_11_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */

void badeathmatch_entrypoint_11(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    void *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (((Objdeathmatch_arg0 *)arg0)->unk158);
        (((Objdeathmatch_badeathmatch_entrypoint_11_temp_v0 *)temp_v0)->unk23) = (u8) ((((Objdeathmatch_badeathmatch_entrypoint_11_temp_v0 *)temp_v0)->unk23) | arg1);
        return;
    }
    temp_v0_2 = (((Objdeathmatch_arg0 *)arg0)->unk158);
    (((Objdeathmatch_badeathmatch_entrypoint_11_temp_v0_2 *)temp_v0_2)->unk23) = (u8) ((((Objdeathmatch_badeathmatch_entrypoint_11_temp_v0_2 *)temp_v0_2)->unk23) & ~arg1);
}
/* data_to_c.py: from asm/data/overlays/ba/deathmatch.data.s */
u8 D_80800550_badeathmatch [16] BT_DATA(4, overlays_ba_deathmatch, 0x0) = { 2, 4, 5, 3, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
