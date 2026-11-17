#include "common.h"

s32 bapulse_entrypoint_0() 
{
    return 0xC;
}    typedef struct { u8 pad0[0x4]; f32 unk4; f32 unk8; } Objpulse_bapulse_entrypoint_1_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(f32) bapulse_entrypoint_1(u8 *arg0) {
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xE8)));
    BT_NATIVE_ONLY(return) func_800F10B4((((Objpulse_bapulse_entrypoint_1_temp_v0 *)temp_v0)->unk8), 0.0f, (((Objpulse_bapulse_entrypoint_1_temp_v0 *)temp_v0)->unk4), 0.0f, 1.0f);
}

void bapulse_entrypoint_2(BtIntPtr arg0) 
{
}    typedef struct { u8 pad0[0xE8]; void * unkE8; } Objpulse_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
void bapulse_entrypoint_3(void *arg0, f32 arg1, f32 arg2) {
    (*(s8 *)((s8 *)((((Objpulse_arg0 *)arg0)->unkE8)) + (0))) = 0;
    (*(f32 *)((s8 *)((((Objpulse_arg0 *)arg0)->unkE8)) + (8))) = arg1;
    (*(f32 *)((s8 *)((((Objpulse_arg0 *)arg0)->unkE8)) + (4))) = arg2;
}    typedef struct { u8 unk0; u8 pad1[0x3]; f32 unk4; f32 unk8; } Objpulse_bapulse_entrypoint_4_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void bapulse_entrypoint_4(void *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800F13C4(f32, f32);
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f20;
    void *temp_v0;

    temp_f0 = func_800D8FF8();
    temp_v0 = (((Objpulse_arg0 *)arg0)->unkE8);
    if ((((Objpulse_bapulse_entrypoint_4_temp_v0 *)temp_v0)->unk0) == 0) {
        (((Objpulse_bapulse_entrypoint_4_temp_v0 *)temp_v0)->unk8) = (f32) ((((Objpulse_bapulse_entrypoint_4_temp_v0 *)temp_v0)->unk8) + temp_f0);
        temp_v0 = (((Objpulse_arg0 *)arg0)->unkE8);
        temp_f20 = (((Objpulse_bapulse_entrypoint_4_temp_v0 *)temp_v0)->unk8);
        temp_f14 = (((Objpulse_bapulse_entrypoint_4_temp_v0 *)temp_v0)->unk4);
        if (temp_f14 <= temp_f20) {
            temp_f0 = func_800F13C4(temp_f20, temp_f14);
            temp_v0 = (((Objpulse_arg0 *)arg0)->unkE8);
            (((Objpulse_bapulse_entrypoint_4_temp_v0 *)temp_v0)->unk8) = (((Objpulse_bapulse_entrypoint_4_temp_v0 *)temp_v0)->unk4) - temp_f0;
            (*(s8 *)((s8 *)((((Objpulse_arg0 *)arg0)->unkE8)) + (0))) = 1;
        }
    } else {
        (((Objpulse_bapulse_entrypoint_4_temp_v0 *)temp_v0)->unk8) = (f32) ((((Objpulse_bapulse_entrypoint_4_temp_v0 *)temp_v0)->unk8) - temp_f0);
        temp_v0 = (((Objpulse_arg0 *)arg0)->unkE8);
        temp_f20 = (((Objpulse_bapulse_entrypoint_4_temp_v0 *)temp_v0)->unk8);
        if (temp_f20 < 0.0f) {
            (*(f32 *)((s8 *)((((Objpulse_arg0 *)arg0)->unkE8)) + (8))) = func_800F13C4(-temp_f20, (((Objpulse_bapulse_entrypoint_4_temp_v0 *)temp_v0)->unk4));
            (*(s8 *)((s8 *)((((Objpulse_arg0 *)arg0)->unkE8)) + (0))) = 0;
        }
    }
}
