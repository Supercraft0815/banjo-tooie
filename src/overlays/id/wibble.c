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
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wibble/func_80800324_idwibble.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wibble/idwibble_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wibble/idwibble_entrypoint_3.s")

void idwibble_entrypoint_4(void *arg0, s32 arg1, s32 arg2) { s32 _glid_entrypoint_0(s32, s32, s32 *, void *); f32 func_800D8FF8(void); extern s32 _idwibble_entrypoint_0; f32 dt = func_800D8FF8(); f32 *velocity = (f32 *) ((s8 *) arg0 + 0x2C); f32 *position = (f32 *) ((s8 *) arg0 + 0x24); *position += dt * *velocity; _glid_entrypoint_0(arg1, arg2, &_idwibble_entrypoint_0, arg0); }

void idwibble_entrypoint_5(void *arg0, s16 arg1) {
    (*(s16 *)((s8 *)(arg0) + (0x34))) = arg1;
}
