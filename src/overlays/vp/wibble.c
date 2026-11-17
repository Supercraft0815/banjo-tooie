#include "common.h"

s32 *func_80800000_vpwibble(s32 arg0) {
    struct WibbleEntry {
        s32 words[3];
        s16 unkC;
        s16 id;
    };
    extern struct WibbleEntry D_80800700_vpwibble[];
    struct WibbleEntry *temp_v1;
    s32 i;

    arg0 -= arg0 % 100;
    for (i = 0; i < 6; i++) {
        temp_v1 = &D_80800700_vpwibble[i];
        if (arg0 == temp_v1->id) {
            return temp_v1->words;
        }
    }
    return D_80800700_vpwibble[0].words;
}

s32 func_808000B0_vpwibble(u8 *arg0, s32 arg1) {
    s32 *entry;
    f32 low, high, value;

    entry = func_80800000_vpwibble(arg1);
    arg1 %= 100;
    *(f32 *)(arg0 + 0x1C) = ((u8 *)entry)[0xD] << 6;
    if (((u8 *)entry)[0xD]) {
        arg0[0x33] = 1;
    } else {
        arg0[0x33] = 0;
    }
    high = *(f32 *)(arg0 + 0x10);
    low = *(f32 *)(arg0 + 4);
    *(s16 *)(arg0 + 0x18) = (s32)((high + low) / 2);
    value = ((f32 *)entry)[1];
    if (value < 0.0f) {
        *(s16 *)(arg0 + 0x1A) = (s32)-value;
        arg0[0x31] = 2;
    } else if (value > 0.0f) {
        *(s16 *)(arg0 + 0x1A) = (s32)value;
        arg0[0x31] = 0;
    } else {
        *(s16 *)(arg0 + 0x1A) = (s32)((high - low) * 0.5f);
        arg0[0x31] = 1;
    }
    *(f32 *)(arg0 + 0x20) = (f32)(u32)((u8 *)entry)[0xC] / *(s16 *)(arg0 + 0x1A);
    arg0[0x30] = 255 - ((u8 *)entry)[0xC];
    if (((u8 *)entry)[0xC]) {
        arg0[0x32] = 1;
    } else {
        arg0[0x32] = 0;
    }
    *(f32 *)(arg0 + 0x24) = 0.0f;
    *(f32 *)(arg0 + 0x28) = 6.2831855f / ((f32 *)entry)[0];
    value = ((f32 *)entry)[2];
    if (value < 0.0f) {
        *(f32 *)(arg0 + 0x2C) = -value;
    } else {
        *(f32 *)(arg0 + 0x2C) = (f32)arg1 * value;
    } BT_NATIVE_ONLY(return 0;)
}                          typedef struct { u8 pad0[0x34]; s32 unk34; } Objwibble_vpwibble_entrypoint_0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x2]; u16 unk2; } Objwibble_vpwibble_entrypoint_0_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */ typedef struct { u8 pad0[0x14]; s32 unk14; s16 unk18; s16 unk1A; f32 unk1C; f32 unk20; f32 unk24; f32 unk28; u8 pad2C[0x4]; u8 unk30; u8 unk31; u8 unk32; u8 unk33; } Objwibble_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

u8 *vpwibble_entrypoint_0(u8 *arg0, u8 *arg1) {
    void func_800EE88C(f32 *, s16 *);
    s32 func_808000B0_vpwibble(u8 *, s32);
    void *heap_alloc(s32);
    BtUIntPtr temp_a0;
    BtUIntPtr temp_a1;
    BtUIntPtr var_v1;
    u8 *temp_v0;

    temp_v0 = heap_alloc(((((Objwibble_arg0 *)arg0)->unk14) * 2) + 0x38);
    temp_a0 = arg1 + 0x14;
    temp_a1 = ((((Objwibble_arg0 *)arg0)->unk14) * 4) + arg1 + 0x14;
    (((Objwibble_vpwibble_entrypoint_0_temp_v0 *)temp_v0)->unk34) = 0;
    var_v1 = temp_a0;
    if (temp_a0 < temp_a1) {
        do {
            if ((((Objwibble_vpwibble_entrypoint_0_var_v1 *)var_v1)->unk2) != 0) {
                (*(s16 *)((s8 *)((temp_v0 + ((((Objwibble_vpwibble_entrypoint_0_temp_v0 *)temp_v0)->unk34) * 2))) + (0x38))) = (s16) ((s32) (var_v1 - temp_a0) >> 2);
                (((Objwibble_vpwibble_entrypoint_0_temp_v0 *)temp_v0)->unk34) = (s32) ((((Objwibble_vpwibble_entrypoint_0_temp_v0 *)temp_v0)->unk34) + 1);
            }
            var_v1 += 4;
        } while (var_v1 < temp_a1);
    }
    func_800EE88C((f32 *)temp_v0, (s16 *)(arg1 + 8));
    func_800EE88C((f32 *)(temp_v0 + 0xC), (s16 *)(arg1 + 0xE));
    func_808000B0_vpwibble(temp_v0, *(s32 *)arg1);
    return temp_v0;
}

void vpwibble_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
/* extern */

void vpwibble_entrypoint_2(u8 *arg0, u8 *arg1) {
    f32 func_800D8FF8(void);
    s32 i;
    s16 *indices;
    u8 *base;
    f32 delta;

    delta = func_800D8FF8();
    i = 0;
    *(f32 *)(arg0 + 0x24) += delta * *(f32 *)(arg0 + 0x2C);
    base = arg1;
    base += *(s32 *)(arg1 + 0x1C);
    if (*(s32 *)(arg0 + 0x34) > 0) {
        indices = (s16 *)(arg0 + 0x38);
        do {
            i++;
            (base + *indices++ * 0x14)[3] = 1;
        } while (i < *(s32 *)(arg0 + 0x34));
    }
}

/* extern */

f32 func_808003F0_vpwibble(void *arg0, void *arg1, void *arg2) {
    f32 func_800136D0(f32);
    f32 func_80013788(f32);
    f32 func_800137D4(f32);
    f32 func_800EEF94(f32 *);
    f32 sp3C;
    f32 temp_f12;
    f32 vec[4];
    f32 temp_f0_2;
    f32 temp_f2;

    vec[0] = (f32) (*(s16 *)((s8 *)(arg1) + (0)));
    vec[1] = (f32) (*(s16 *)((s8 *)(arg1) + (2)));
    vec[2] = (f32) (*(s16 *)((s8 *)(arg1) + (4)));
    sp3C = func_800EEF94(vec);
    temp_f12 = (sp3C - (*(f32 *)((s8 *)(arg0) + (0x24)))) * (*(f32 *)((s8 *)(arg0) + (0x28)));
    temp_f12 = func_800136D0(temp_f12);
    temp_f12 = func_800137D4(temp_f12);
    temp_f12 *= (f32) (*(s16 *)((s8 *)(arg0) + (0x1A)));
    if ((*(u8 *)((s8 *)(arg0) + (0x33))) != 0) {
        temp_f2 = (*(f32 *)((s8 *)(arg0) + (0x28))) * ((f32) (*(s16 *)((s8 *)(arg0) + (0x1A))) * func_80013788(temp_f12));
        if (sp3C > 0.0001f) {
            temp_f0_2 = temp_f2 / sp3C;
            (*(f32 *)((s8 *)(arg2) + (0))) = (f32) (vec[0] * temp_f0_2);
            (*(f32 *)((s8 *)(arg2) + (4))) = (f32) (vec[2] * temp_f0_2);
        } else {
            (*(f32 *)((s8 *)(arg2) + (0))) = (f32) (vec[0] * temp_f2);
            (*(f32 *)((s8 *)(arg2) + (4))) = (f32) (vec[2] * temp_f2);
        }
    }
    return temp_f12;
}

void vpwibble_entrypoint_3(void *arg0, s32 arg1, BtUIntPtr arg2, BtIntPtr arg3) {
    f32 height;
    s32 shade;
    f32 offsets[2];

    arg3 = arg3 * 0x10 + arg2;
    if (arg2 < (u32)arg3) {
        do {
            height = func_808003F0_vpwibble(arg0, (void *)arg2, offsets);
            if (*(u8 *)((s8 *)arg0 + 0x31) == 1) {
                *(s16 *)((s8 *)arg2 + 2) = (s32)((f32)*(s16 *)((s8 *)arg0 + 0x18) + height);
            } else if (*(u8 *)((s8 *)arg0 + 0x31) == 2) {
                *(s16 *)((s8 *)arg2 + 2) = (s32)((f32)*(s16 *)((s8 *)arg2 + 2) + height);
            }
            if (*(u8 *)((s8 *)arg0 + 0x32)) {
                shade = (s32)((height * *(f32 *)((s8 *)arg0 + 0x20)) + (f32)*(u8 *)((s8 *)arg0 + 0x30));
                *(u8 *)((s8 *)arg2 + 0xC) = (*(u8 *)((s8 *)arg2 + 0xC) * shade) >> 8;
                *(u8 *)((s8 *)arg2 + 0xD) = (*(u8 *)((s8 *)arg2 + 0xD) * shade) >> 8;
                *(u8 *)((s8 *)arg2 + 0xE) = (*(u8 *)((s8 *)arg2 + 0xE) * shade) >> 8;
            }
            if (*(u8 *)((s8 *)arg0 + 0x33)) {
                *(s16 *)((s8 *)arg2 + 8) = (s32)((f32)*(s16 *)((s8 *)arg2 + 8) + *(f32 *)((s8 *)arg0 + 0x1C) * offsets[0]);
                *(s16 *)((s8 *)arg2 + 0xA) = (s32)((f32)*(s16 *)((s8 *)arg2 + 0xA) + *(f32 *)((s8 *)arg0 + 0x1C) * offsets[1]);
            }
            arg2 += 0x10;
        } while (arg2 < (u32)arg3);
    }
}
