#include "common.h"


/* extern */
f32 func_80800000_idwibble(void *arg0, void *arg1, void *arg2) {
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

void idwibble_entrypoint_0(s32 arg0, BtUIntPtr arg1, u8 *arg2, BtIntPtr arg3, void *arg4) {
    f32 height;
    s32 shade;
    f32 offsets[2];

    arg3 = arg3 * 0x10 + arg1;
    if (arg1 < (u32)arg3) {
        do {
            height = func_80800000_idwibble(arg4, (void *)arg1, offsets);
            if (*(u8 *)((s8 *)arg4 + 0x31) == 1) {
                *(s16 *)(arg2 + 2) = (s16)(s32)((f32)*(s16 *)((s8 *)arg4 + 0x34) + ((f32)*(s16 *)((s8 *)arg4 + 0x18) + height));
            } else if (*(u8 *)((s8 *)arg4 + 0x31) == 2) {
                *(s16 *)(arg2 + 2) = (s16)(s32)((f32)*(s16 *)((s8 *)arg4 + 0x34) + ((f32)*(s16 *)(arg1 + 2) + height));
            }
            if (*(u8 *)((s8 *)arg4 + 0x32) == 1) {
                shade = (s32)((height * *(f32 *)((s8 *)arg4 + 0x20)) + (f32)(u32)*(u8 *)((s8 *)arg4 + 0x30));
                arg2[0xC] = ((s32)(*(u8 *)(arg1 + 0xC) * shade)) >> 8;
                arg2[0xD] = ((s32)(*(u8 *)(arg1 + 0xD) * shade)) >> 8;
                arg2[0xE] = ((s32)(*(u8 *)(arg1 + 0xE) * shade)) >> 8;
            }
            if (*(u8 *)((s8 *)arg4 + 0x33)) {
                *(s16 *)(arg2 + 8) = (s32)((f32)*(s16 *)(arg1 + 8) + *(f32 *)((s8 *)arg4 + 0x1C) * offsets[0]);
                *(s16 *)(arg2 + 0xA) = (s32)((f32)*(s16 *)(arg1 + 0xA) + *(f32 *)((s8 *)arg4 + 0x1C) * offsets[1]);
            }
            arg1 += 0x10;
            arg2 += 0x10;
        } while (arg1 < (u32)arg3);
    }
}

void idwibble_entrypoint_1(s32 arg0) 
{
}
s32 *func_80800324_idwibble(s32 arg0) {
    struct WibbleEntry {
        s32 words[3];
        s16 unkC;
        s16 id;
    };
    extern struct WibbleEntry D_80800770_idwibble[];
    struct WibbleEntry *temp_v1;
    s32 i;

    arg0 -= arg0 % 100;
    for (i = 0; i < 6; i++) {
        temp_v1 = &D_80800770_idwibble[i];
        if (arg0 == temp_v1->id) {
            return temp_v1->words;
        }
    }
    return D_80800770_idwibble[0].words;
}               typedef struct { u8 pad0[0x18]; s16 unk18; s16 unk1A; u8 pad1C[0x8]; f32 unk24; f32 unk28; f32 unk2C; u8 pad30[0x3]; u8 unk33; s16 unk34; u8 pad36[0x1]; u8 unk37; } Objwibble_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void idwibble_entrypoint_2(f32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void _glidmake_entrypoint_2(BtIntPtr, s32, u8 *, u8 *);
    void func_800EE88C(f32 *, s16 *);
    s32 *entry;
    s16 first[3];
    s16 second[3];
    f32 value;

    entry = func_80800324_idwibble(arg1);
    arg1 %= 100;
    _glidmake_entrypoint_2(arg2, arg3, (u8 *)first, (u8 *)second);
    ((Objwibble_arg0 *)arg0)->unk18 = (first[1] + second[1]) / 2;
    func_800EE88C(arg0, first);
    func_800EE88C(arg0 + 3, second);
    arg0[7] = *((u8 *)entry + 0xD) << 6;
    if (*((u8 *)entry + 0xD)) {
        *((u8 *)arg0 + 0x33) = 1;
    } else {
        *((u8 *)arg0 + 0x33) = 0;
    }
    value = ((f32 *)entry)[1];
    if (value < 0.0f) {
        ((Objwibble_arg0 *)arg0)->unk1A = (s32)-value;
        *((u8 *)arg0 + 0x31) = 2;
    } else if (value > 0.0f) {
        ((Objwibble_arg0 *)arg0)->unk1A = (s32)value;
        *((u8 *)arg0 + 0x31) = 0;
    } else {
        ((Objwibble_arg0 *)arg0)->unk1A = (s32)((arg0[4] - arg0[1]) * 0.5f);
        *((u8 *)arg0 + 0x31) = 1;
    }
    if (0.0f == ((Objwibble_arg0 *)arg0)->unk1A) {
        ((Objwibble_arg0 *)arg0)->unk1A = 1;
    }
    arg0[8] = (f32)(u32)*((u8 *)entry + 0xC) / ((Objwibble_arg0 *)arg0)->unk1A;
    *((u8 *)arg0 + 0x30) = 0xFF - *((u8 *)entry + 0xC);
    if (*((u8 *)entry + 0xC)) {
        *((u8 *)arg0 + 0x32) = 1;
    } else {
        *((u8 *)arg0 + 0x32) = 0;
    }
    arg0[9] = 0.0f;
    arg0[10] = 6.2831855f / ((f32 *)entry)[0];
    value = ((f32 *)entry)[2];
    if (value < 0.0f) {
        arg0[11] = -value;
    } else {
        arg0[11] = (f32)arg1 * value;
    }
    ((Objwibble_arg0 *)arg0)->unk34 = 0;
    if (arg4 != 1 && arg4 != 2) {
        *((u8 *)arg0 + 0x37) = 1;
    } else {
        *((u8 *)arg0 + 0x37) = 0;
    }
}

void idwibble_entrypoint_3(f32 *arg0, s32 arg1, s32 arg2) {
    s32 _glid_entrypoint_0(BtIntPtr, s32, s32 *, void *);
    f32 func_800D8FF8(void);
    s32 func_800E3D0C(void *, void *);
    void func_800EE7F8(f32 *, f32 *);
#ifndef BT_NATIVE
#ifndef BT_NATIVE
    extern s32 _idwibble_entrypoint_0;
#endif
#endif
    arg0[9] += func_800D8FF8() * arg0[11];
    {
    struct { f32 x, y, z; } sp34, sp28;
    func_800EE7F8(&sp34.x, arg0);
    func_800EE7F8(&sp28.x, arg0 + 3);
    sp34.y += ((Objwibble_arg0 *)arg0)->unk34;
    sp28.y += ((Objwibble_arg0 *)arg0)->unk34;
    if (((Objwibble_arg0 *)arg0)->unk37 || func_800E3D0C(arg0, arg0 + 3)) {
        _glid_entrypoint_0(arg1, arg2, &_idwibble_entrypoint_0, arg0);
    }
    }
}

#ifdef BT_NATIVE
void idwibble_entrypoint_4(void *arg0, s32 arg1, s32 arg2) { s32 _glid_entrypoint_0(BtIntPtr, s32, s32 *, void *); f32 func_800D8FF8(void); f32 dt = func_800D8FF8(); f32 *velocity = (f32 *) ((s8 *) arg0 + 0x2C); f32 *position = (f32 *) ((s8 *) arg0 + 0x24); *position += dt * *velocity; _glid_entrypoint_0(arg1, arg2, &_idwibble_entrypoint_0, arg0); }
#else
void idwibble_entrypoint_4(void *arg0, s32 arg1, s32 arg2) { s32 _glid_entrypoint_0(s32, s32, s32 *, void *); f32 func_800D8FF8(void); extern s32 _idwibble_entrypoint_0; f32 dt = func_800D8FF8(); f32 *velocity = &((Objwibble_arg0 *)arg0)->unk2C; f32 *position = &((Objwibble_arg0 *)arg0)->unk24; *position += dt * *velocity; _glid_entrypoint_0(arg1, arg2, &_idwibble_entrypoint_0, arg0); }
#endif

void idwibble_entrypoint_5(void *arg0, s16 arg1) {
    (((Objwibble_arg0 *)arg0)->unk34) = arg1;
}
