#include "common.h"

void func_80026CB0(ALVoice *arg0, ALWaveTable *arg1, f32 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, f32 arg7, u8 arg8, s32 arg9) {
    s32 *func_80021794(void);
    s32 func_80021928(s32);
    s32 func_8002B684(void *, s32, void *);
    extern s32 *D_800411F4;
    s32 *update;

    if (arg0->pvoice != NULL) {
        update = func_80021794();
        if (update == NULL) {
            return;
        }
        update[1] = *(s32 *)((u8 *)arg0->pvoice + 0x88) + D_800411F4[7];
        update[0] = 0;
        *(s16 *)((u8 *)update + 8) = 0xD;
        *(s16 *)((u8 *)update + 0xA) = arg0->unityPitch;
        *(u8 *)((u8 *)update + 0x12) = arg4;
        *(s16 *)((u8 *)update + 0x10) = arg3;
        *(u8 *)((u8 *)update + 0x13) = arg5;
        *(f32 *)((u8 *)update + 0xC) = arg2;
        *(u8 *)((u8 *)update + 0x14) = arg8;
        *(u8 *)((u8 *)update + 0x15) = arg6;
        *(f32 *)((u8 *)update + 0x18) = arg7;
        *(s32 *)((u8 *)update + 0x1C) = func_80021928(arg9);
        *(ALWaveTable **)((u8 *)update + 0x20) = arg1;
        func_8002B684(arg0->pvoice, 3, update);
    }
}
