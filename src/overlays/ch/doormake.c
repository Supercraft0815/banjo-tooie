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

/* extern */

s32 chdoormake_entrypoint_0(Actor *arg0, f32 arg1, u32 arg2, s32 arg3) {
    struct DoorAngles {
        u8 unused[0x10];
        s16 angle;
        s16 angle2;
    };
    f32 func_800136E4(f32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    s32 func_808000B8_chdoormake(Actor *);
    s32 func_808008C4_chdoormake(Actor *);
    struct DoorAngles *data;

    data = func_80800000_chdoormake(arg0, 1, arg2, arg3);
    data->angle = (s32) func_800136E4(arg0->rotation[1] + arg1);
    data->angle2 = (s32) arg0->rotation[1];
    if ((func_808008C4_chdoormake(arg0) != 0) || (arg0->unk70_10 == 4)) {
        if (arg2 & 1) {
            func_800FFAB0(arg0);
            return 0;
        }
        arg0->rotation[1] = data->angle;
        func_80101FDC(arg0, 4);
        func_808000B8_chdoormake(arg0);
        return 2;
    }
    func_808000B8_chdoormake(arg0);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/doormake/chdoormake_entrypoint_3.s")

/* extern */

s32 chdoormake_entrypoint_4(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiefade_entrypoint_1(s32, s32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    s32 func_808000B8_chdoormake(Actor *);
    s32 func_808008C4_chdoormake(Actor *);
    func_80800000_chdoormake(arg0, 5, arg1, arg2);
    if ((func_808008C4_chdoormake(arg0) != 0) || (arg0->unk70_10 == 4)) {
        if (arg1 & 1) {
            func_800FFAB0(arg0);
            return 0;
        }
        _subaddiefade_entrypoint_1(arg0, 0);
        func_80101FDC(arg0, 4);
        func_808000B8_chdoormake(arg0);
        return 2;
    }
    func_808000B8_chdoormake(arg0);
    return 1;
}

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
