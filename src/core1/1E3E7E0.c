#include "common.h"

typedef struct { u8 pad0[0x8]; s16 unk8; s16 unkA; f32 unkC; s16 unk10; u8 unk12; u8 unk13; u8 unk14; u8 unk15; u8 pad16[0x2]; f32 unk18; s32 unk1C; } Obj1E3E7E0_func_80026CB0_update; /* offsets.py genstruct: fields from raw offsets on update; rename once understood */ void func_80026CB0(ALVoice *arg0, ALWaveTable *arg1, f32 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, f32 arg7, u8 arg8, s32 arg9) {
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
        ((Obj1E3E7E0_func_80026CB0_update *)update)->unk8 = 0xD;
        ((Obj1E3E7E0_func_80026CB0_update *)update)->unkA = arg0->unityPitch;
        ((Obj1E3E7E0_func_80026CB0_update *)update)->unk12 = arg4;
        ((Obj1E3E7E0_func_80026CB0_update *)update)->unk10 = arg3;
        ((Obj1E3E7E0_func_80026CB0_update *)update)->unk13 = arg5;
        ((Obj1E3E7E0_func_80026CB0_update *)update)->unkC = arg2;
        ((Obj1E3E7E0_func_80026CB0_update *)update)->unk14 = arg8;
        ((Obj1E3E7E0_func_80026CB0_update *)update)->unk15 = arg6;
        ((Obj1E3E7E0_func_80026CB0_update *)update)->unk18 = arg7;
        ((Obj1E3E7E0_func_80026CB0_update *)update)->unk1C = func_80021928(arg9);
        *(ALWaveTable **)((u8 *)update + 0x20) = arg1;
        func_8002B684(arg0->pvoice, 3, update);
    }
}
