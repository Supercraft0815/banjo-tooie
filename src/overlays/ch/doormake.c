#include "common.h"

void *func_80800000_chdoormake(Actor *arg0, s32 arg1, u32 arg2, s32 arg3) {
    struct DoorPart {
        u8 state;
        u8 unused1;
        u8 active : 1;
        u8 unused2 : 7;
        u8 unused3[5];
    };
    struct DoorData {
        u32 flags;
        s16 value;
        u8 unused6[2];
        u8 kind : 6;
        u8 unused8 : 2;
        u8 unused9;
        s16 scale;
        s16 angle;
        s16 angle2;
        u8 unused10[16];
        struct DoorPart parts[2];
    };
    u32 *func_80100074(Actor *, u32, u32);
    void func_80103110(Actor *, u32);
    struct DoorData *data;
    s32 i;

    data = (struct DoorData *)func_80100074(arg0, 0, 0x48);
    data->kind = arg1;
    data->flags = arg2;
    data->value = arg3;
    data->scale = 0x200;
    data->angle = 0;
    data->angle2 = 0;
    for (i = 0; i < 2; i++) {
        data->parts[i].active = 0;
        data->parts[i].state = 0;
    }
    if (arg2 & 4) {
        func_80103110(arg0, 1);
    }
    return data;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/func_808000B8_chdoormake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_4.s")

void chdoormake_entrypoint_5(Actor *arg0, f32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0xA))) = (s16) (s32) (256.0f * arg1);
}

void chdoormake_entrypoint_6(Actor *arg0, f32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0xC))) = (s16) (s32) (256.0f * arg1);
}

void chdoormake_entrypoint_7(Actor *arg0, f32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0xE))) = (s16) (s32) (256.0f * arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_8.s")

void chdoormake_entrypoint_9(Actor *arg0, s32 arg1, u16 arg2, s32 arg3) {
    void *func_80100094(Actor *, u32);
    struct DoorData {
        u8 pad[0x1E];
        s16 amount;
        u8 pad20;
        s8 kind;
        u16 flag : 1;
        u16 value : 15;
    } *data;
    data = (struct DoorData *)((s8 *)func_80100094(arg0, 0U) + arg1 * 8);
    data->kind = arg2;
    *(s16 *)((s8 *)data + 0x1E) = arg3;
    data->flag = 1;
    data->value = 0;
}

void chdoormake_entrypoint_10(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    struct DoorField {
        u16 flag : 1;
        u16 value : 15;
    } *data;

    data = (struct DoorField *)((s8 *)func_80100094(arg0, 0U) + arg1 * 8 + 0x22);
    data->value = arg2;
}

void chdoormake_entrypoint_11(Actor *arg0, s32 arg1, f32 arg2) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)func_80100094(arg0, 0U) + (arg1 * 8) + 0x24)) = (s16) (s32) (256.0f * arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/func_808008C4_chdoormake.s")

void chdoormake_entrypoint_12(Actor *arg0, s32 arg1, u16 arg2) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)func_80100094(arg0, 0U) + (arg1 * 8) + 0x20)) = (s8) arg2;
}
