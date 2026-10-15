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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wibble/idwibble_entrypoint_0.s")

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
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wibble/idwibble_entrypoint_2.s")

void idwibble_entrypoint_3(f32 *arg0, s32 arg1, s32 arg2) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, void *);
    f32 func_800D8FF8(void);
    s32 func_800E3D0C(void *, void *);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 _idwibble_entrypoint_0;
    arg0[9] += func_800D8FF8() * arg0[11];
    {
    struct { f32 x, y, z; } sp34, sp28;
    func_800EE7F8(&sp34.x, arg0);
    func_800EE7F8(&sp28.x, arg0 + 3);
    sp34.y += *(s16 *)((s8 *)arg0 + 0x34);
    sp28.y += *(s16 *)((s8 *)arg0 + 0x34);
    if (*(u8 *)((s8 *)arg0 + 0x37) || func_800E3D0C(arg0, arg0 + 3)) {
        _glid_entrypoint_0(arg1, arg2, &_idwibble_entrypoint_0, arg0);
    }
    }
}

void idwibble_entrypoint_4(void *arg0, s32 arg1, s32 arg2) { s32 _glid_entrypoint_0(s32, s32, s32 *, void *); f32 func_800D8FF8(void); extern s32 _idwibble_entrypoint_0; f32 dt = func_800D8FF8(); f32 *velocity = (f32 *) ((s8 *) arg0 + 0x2C); f32 *position = (f32 *) ((s8 *) arg0 + 0x24); *position += dt * *velocity; _glid_entrypoint_0(arg1, arg2, &_idwibble_entrypoint_0, arg0); }

void idwibble_entrypoint_5(void *arg0, s16 arg1) {
    (*(s16 *)((s8 *)(arg0) + (0x34))) = arg1;
}
