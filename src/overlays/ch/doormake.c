#include "common.h"
#include "gameflags.h"

void *func_80800000_chdoormake(Actor *arg0, s32 arg1, u32 arg2, s32 arg3) {
    struct DoorPart {
        u8 state;
        u8 unused1;
        BT_BITFIELD_ORDER(u8 active : 1, u8 unused2 : 7);
        BT_BITFIELD_ORDER(u8 unused2 : 7, u8 active : 1);
        u8 unused3[5];
    };
    struct DoorData {
        u32 flags;
        s16 value;
        u8 unused6[2];
        BT_BITFIELD_ORDER(u8 kind : 6, u8 unused8 : 2);
        BT_BITFIELD_ORDER(u8 unused8 : 2, u8 kind : 6);
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

s32 func_808000B8_chdoormake(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_8010A624(Actor *);
    void func_8010A63C(Actor *);
    s32 *data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 4:
            if (*data & 0x800) {
                func_8010A624(arg0);
            }
            if (*data & 0x2000) {
                arg0->unk64_16 = 0;
            }
            break;
        case 1:
            if (*data & 0x800) {
                func_8010A63C(arg0);
            }
            if (*data & 0x2000) {
                arg0->unk64_16 = 1;
            }
            break;
    } BT_NATIVE_ONLY(return 0;)
}

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
    int func_808008C4_chdoormake(Actor *);
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

/* extern */

s32 chdoormake_entrypoint_1(Actor *arg0, f32 arg1, u32 arg2, s32 arg3) {
    struct DoorAngles {
        u8 unused[0x10];
        s16 angle;
        s16 angle2;
    };
    f32 func_800136E4(f32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    s32 func_808000B8_chdoormake(Actor *);
    int func_808008C4_chdoormake(Actor *);
    struct DoorAngles *data;

    data = func_80800000_chdoormake(arg0, 3, arg2, arg3);
    data->angle = (s32) func_800136E4(arg0->rotation[0] + arg1);
    data->angle2 = (s32) arg0->rotation[0];
    if ((func_808008C4_chdoormake(arg0) != 0) || (arg0->unk70_10 == 4)) {
        if (arg2 & 1) {
            func_800FFAB0(arg0);
            return 0;
        }
        arg0->rotation[0] = data->angle;
        func_80101FDC(arg0, 4);
        func_808000B8_chdoormake(arg0);
        return 2;
    }
    func_808000B8_chdoormake(arg0);
    return 1;
}

s32 chdoormake_entrypoint_2(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, u32 arg4, s32 arg5) {
    struct DoorPositions {
        u8 pad[0x10];
        s16 start[3];
        s16 end[3];
        s16 angle;
    };
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE940(s16 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80103014(u8 *);
    f32 func_80103EAC(Actor *);
    int func_808008C4_chdoormake(Actor *);
    struct DoorPositions *data;
    f32 position[3];

    data = func_80800000_chdoormake(arg0, 4, arg4, arg5);
    func_800EE940(data->start, arg0->position);
    func_800EE7F8(position, arg0->position);
    func_800EF214(position, arg2, arg1, arg3);
    func_800EE940(data->end, position);
    data->angle = (s32) ((func_800EEAD4(arg0->position, position) / (func_80103EAC(arg0) * 6.2831855f)) * -360.0f * 256.0f);
    if ((func_808008C4_chdoormake(arg0) != 0) || (arg0->unk70_10 == 4)) {
        if (arg4 & 1) {
            func_800FFAB0(arg0);
            return 0;
        }
        func_800EE7F8(arg0->position, position);
        arg0->rotation[2] = data->angle * 0.00390625f;
        func_80101FDC(arg0, 4);
        func_80103014(arg0);
        func_808000B8_chdoormake(arg0);
        return 2;
    }
    func_808000B8_chdoormake(arg0);
    return 1;
}

s32 chdoormake_entrypoint_3(Actor *arg0, f32 arg1, f32 arg2, f32 arg3, u32 arg4, s32 arg5) {
    struct DoorPositions {
        u8 pad[0x10];
        s16 start[3];
        s16 end[3];
    };
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE940(s16 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80103014(u8 *);
    int func_808008C4_chdoormake(Actor *);
    struct DoorPositions *data;
    f32 position[3];

    data = func_80800000_chdoormake(arg0, 2, arg4, arg5);
    func_800EE940(data->start, arg0->position);
    func_800EE7F8(position, arg0->position);
    func_800EF214(position, arg2, arg1, arg3);
    func_800EE940(data->end, position);
    if ((func_808008C4_chdoormake(arg0) != 0) || (arg0->unk70_10 == 4)) {
        if (arg4 & 1) {
            func_800FFAB0(arg0);
            return 0;
        }
        func_800EE7F8(arg0->position, position);
        func_80101FDC(arg0, 4);
        func_80103014(arg0);
        func_808000B8_chdoormake(arg0);
        return 2;
    }
    func_808000B8_chdoormake(arg0);
    return 1;
}

/* extern */

s32 chdoormake_entrypoint_4(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    s32 func_808000B8_chdoormake(Actor *);
    int func_808008C4_chdoormake(Actor *);
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

void chdoormake_entrypoint_8(Actor *arg0, u32 arg1) {
    void *func_80100094(Actor *, u32);
    void rare_memcpy(void *, void *, int);
    extern u8 D_808009A0_chdoormake[];
    extern u8 D_80800A0C_chdoormake[];
    extern u8 D_80800AC0_chdoormake[];
    u8 *data;

    data = func_80100094(arg0, 0U);
    rare_memcpy(data + 0x2E, D_808009A0_chdoormake + arg1 * 6, 6);
    rare_memcpy(data + 0x34, D_80800A0C_chdoormake + arg1 * 10, 10);
    rare_memcpy(data + 0x3E, D_80800AC0_chdoormake + arg1 * 10, 10);
}

void chdoormake_entrypoint_9(Actor *arg0, s32 arg1, u16 arg2, s32 arg3) {
    void *func_80100094(Actor *, u32);
    struct DoorData {
        u8 pad[0x1E];
        s16 amount;
        u8 pad20;
        s8 kind;
        BT_BITFIELD_ORDER(u16 flag : 1, u16 value : 15);
        BT_BITFIELD_ORDER(u16 value : 15, u16 flag : 1);
    } *data;
    data = (struct DoorData *)((s8 *)func_80100094(arg0, 0U) + arg1 * 8);
    data->kind = arg2;
    data->amount = arg3;
    data->flag = 1;
    data->value = 0;
}

void chdoormake_entrypoint_10(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    struct DoorField {
        BT_BITFIELD_ORDER(u16 flag : 1, u16 value : 15);
        BT_BITFIELD_ORDER(u16 value : 15, u16 flag : 1);
    } *data;

    data = (struct DoorField *)((s8 *)func_80100094(arg0, 0U) + arg1 * 8 + 0x22);
    data->value = arg2;
}

void chdoormake_entrypoint_11(Actor *arg0, s32 arg1, f32 arg2) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)func_80100094(arg0, 0U) + (arg1 * 8) + 0x24)) = (s16) (s32) (256.0f * arg2);
}

int func_808008C4_chdoormake(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(GameFlag);
    struct DoorState {
        s32 flags;
        s16 gameFlag;
    } *data;

    data = func_80100094(arg0, 0U);
    if (data->gameFlag == -1) {
        return 0;
    }
    if (data->flags & 0x10) {
        return func_800DA298(data->gameFlag) == 0;
    }
    return (int)func_800DA298(data->gameFlag) && (int)func_800DA298(0x9CC);
}

void chdoormake_entrypoint_12(Actor *arg0, s32 arg1, u16 arg2) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)func_80100094(arg0, 0U) + (arg1 * 8) + 0x20)) = (s8) arg2;
}
/* data_to_c.py: from asm/data/overlays/ch/doormake.data.s */
u8 D_808009A0_chdoormake [108] BT_DATA(4, overlays_ch_doormake, 0x0) = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0xC0, 0x46, 0x50, 1, 0, 5, 7, 0x55, 0xF0, 1, 0, 5, 0x28, 0x55, 0xF0, 0, 0xC0, 4, 0xAD, 0x55, 0xF0, 1, 0, 5, 0xB0, 0x55, 0xF0, 1, 0x33, 4, 0xA9, 0x55, 0xF0, 0, 0x80, 5, 0xB9, 0x7D, 0, 0, 0xCC, 6, 0x38, 0x3A, 0x98, 0, 0xE6, 4, 0xAD, 0x55, 0xF0, 1, 0, 0, 0, 0x55, 0xF0, 0, 0, 6, 0x72, 0x55, 0xF0, 0, 0xCC, 4, 0xAD, 0x55, 0xF0, 1, 0, 6, 0x95, 0x7D, 0, 1, 0, 6, 0x95, 0x7D, 0, 0, 0xCC, 5, 0xB9, 0x7D, 0, 1, 0, 5, 0xB9, 0x7D, 0, 1, 0 };
u8 D_80800A0C_chdoormake [180] BT_DATA(4, overlays_ch_doormake, 0x6C) = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 4, 0xAB, 0x55, 0xF0, 0, 0xE6, 0, 1, 0, 1, 4, 0xC7, 0x46, 0x50, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 4, 0xC7, 0x46, 0x50, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 4, 0xC7, 0x46, 0x50, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 0x2B, 0x55, 0xF0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 4, 0xAF, 0x55, 0xF0, 0, 0xB3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 4, 0xC7, 0x55, 0xF0, 1, 0, 0, 1, 0, 1, 4, 0xC7, 0x55, 0xF0, 1, 0 };
u8 D_80800AC0_chdoormake [192] BT_DATA(4, overlays_ch_doormake, 0x120) = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 4, 0xC7, 0x55, 0xF0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 4, 0xC7, 0x55, 0xF0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 0xCC, 0x46, 0x50, 0, 0xCC, 0, 0, 0, 1, 4, 0xC7, 0x55, 0xF0, 0, 0xCC, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 4, 0xC7, 0x55, 0xF0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 4, 0xC7, 0x55, 0xF0, 1, 0, 0, 1, 0, 1, 4, 0xCC, 0x46, 0x50, 0, 0xCC, 0, 1, 0, 1, 6, 0x96, 0x7D, 0, 1, 0, 0, 1, 0, 1, 4, 0xCC, 0x7D, 0, 0, 0xCC, 0, 1, 0, 1, 4, 0xC7, 0x55, 0xF0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
