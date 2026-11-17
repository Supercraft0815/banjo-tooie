#include "common.h"

BtIntPtr func_80800000_baeggcursor(s32 arg0) {
    extern BtIntPtr D_80800690_baeggcursor[];
    return ((s32 *)&D_80800690_baeggcursor)[arg0];
}

s32 baeggcursor_entrypoint_0() 
{
    return 0x1C;
}

s32 baeggcursor_entrypoint_7(void *, s32);    typedef struct { u8 pad0[0x8]; u8 unk8; u8 pad9[0x1]; u8 unkA; } Objcursor_baeggcursor_entrypoint_1_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x68]; void * unk68; } Objcursor_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void baeggcursor_entrypoint_1(void *arg0) {
    int func_800A4C68(void *);
    s32 *func_800A7180(void);
    s32 func_800A89F8();
    s32 func_800A9C98(void);
    BtIntPtr func_800D674C(s32);
    void func_800E2434(s32);
    void func_800E24CC(s32);
    void func_800E253C(f32);
    void func_800E257C(s32);
    void func_800E30E0(s32 *, void *, s32, void *);
    s32 sp30[2];
    s32 sp2C;
    s32 *temp_s0;
    void *temp_v0;

    sp2C = func_800A89F8();
    if (func_800A4C68(arg0) == sp2C) {
        temp_v0 = (((Objcursor_arg0 *)arg0)->unk68);
        if (((((Objcursor_baeggcursor_entrypoint_1_temp_v0 *)temp_v0)->unk8) != 0) && ((((Objcursor_baeggcursor_entrypoint_1_temp_v0 *)temp_v0)->unkA) != 0) && (func_800A9C98() == 0)) {
            func_800E253C((*(f32 *)((s8 *)((((Objcursor_arg0 *)arg0)->unk68)) + (0x18))));
            func_800E257C((*(s32 *)((s8 *)((((Objcursor_arg0 *)arg0)->unk68)) + (0x14))));
            func_800E2434(1);
            func_800E24CC(1);
            sp30[0] = (s32) ((*(f32 *)((s8 *)((((Objcursor_arg0 *)arg0)->unk68)) + (0))) * 4.0f);
            sp30[1] = (s32) ((*(f32 *)((s8 *)((((Objcursor_arg0 *)arg0)->unk68)) + (4))) * 4.0f);
            temp_s0 = func_800A7180();
            func_800E30E0(temp_s0, func_800D674C(0x64E), 0, sp30);
        }
    }
}

u32 baeggcursor_entrypoint_2(void *arg0) {
    return *(u8 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 9);
}

void baeggcursor_entrypoint_3(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (*(f32 *)((s8 *)((((Objcursor_arg0 *)arg0)->unk68)) + (0)));
    *arg2 = (*(f32 *)((s8 *)((((Objcursor_arg0 *)arg0)->unk68)) + (4)));
}

void baeggcursor_entrypoint_4(BtIntPtr arg0)
{
    baeggcursor_entrypoint_7(arg0,0);
}

void baeggcursor_entrypoint_5(void *arg0) { *(s8 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 9) = 0; baeggcursor_entrypoint_7(arg0, 1); }

void baeggcursor_entrypoint_6(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 10) = arg1;
}    typedef struct { u8 pad0[0x8]; u8 unk8; u8 unk9; u8 padA[0xA]; s32 unk14; } Objcursor_baeggcursor_entrypoint_7_cursor; /* offsets.py genstruct: fields from raw offsets on cursor; rename once understood */

s32 baeggcursor_entrypoint_7(void *arg0, s32 arg1) {
    void func_8009ADF0(void *, s32, s32);
    void baeggcursor_entrypoint_10(void *, f32, f32);
    u8 state;
    void *cursor;

    cursor = ((Objcursor_arg0 *)arg0)->unk68;
    state = ((Objcursor_baeggcursor_entrypoint_7_cursor *)cursor)->unk9;
    switch (state) {
    case 0:
        ((Objcursor_baeggcursor_entrypoint_7_cursor *)cursor)->unk8 = 0;
        *(u8 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 0xA) = 1;
        cursor = ((Objcursor_arg0 *)arg0)->unk68;
        break;
    case 1:
        ((Objcursor_baeggcursor_entrypoint_7_cursor *)cursor)->unk8 = 1;
        *(s32 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 0x14) = 0x78;
        cursor = ((Objcursor_arg0 *)arg0)->unk68;
        break;
    case 3:
        ((Objcursor_baeggcursor_entrypoint_7_cursor *)cursor)->unk14 = 0x78;
        cursor = ((Objcursor_arg0 *)arg0)->unk68;
        break;
    }
    ((Objcursor_baeggcursor_entrypoint_7_cursor *)cursor)->unk9 = arg1;
    switch (arg1) {
    case 0:
    case 1:
        func_8009ADF0(arg0, 8, 0);
        cursor = ((Objcursor_arg0 *)arg0)->unk68;
        if (((Objcursor_baeggcursor_entrypoint_7_cursor *)cursor)->unk8 != 0) {
            ((Objcursor_baeggcursor_entrypoint_7_cursor *)cursor)->unk8 = 0;
        }
        break;
    case 2:
        func_8009ADF0(arg0, 8, 1);
        *(f32 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 0x18) = 1.0f;
        *(s32 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 0x14) = 0x78;
        break;
    case 3:
        func_8009ADF0(arg0, 8, 1);
        *(f32 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 0xC) = 0.3f;
        baeggcursor_entrypoint_10(arg0, 152.0f, 114.0f);
        *(f32 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 0x18) = 16.0f;
        *(s32 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 0x14) = 0;
        break;
    case 4:
        func_8009ADF0(arg0, 8, 1);
        *(f32 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 0xC) = 0.2f;
        break;
    case 5:
        func_8009ADF0(arg0, 8, 1);
        *(f32 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 0xC) = 0.0f;
        *(u8 *)((u8 *)*&((Objcursor_arg0 *)arg0)->unk68 + 0x10) = 0;
        break;
    }
    BT_NATIVE_ONLY(return 0;)}

void baeggcursor_entrypoint_8(void *arg0) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)((((Objcursor_arg0 *)arg0)->unk68)) + (9)));
    if ((temp_v0 != 0) && (temp_v0 != 1) && (temp_v0 != 4)) {
        baeggcursor_entrypoint_7(arg0, 5);
    }
}

s32 baeggcursor_entrypoint_9(void *arg0) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)((((Objcursor_arg0 *)arg0)->unk68)) + (9)));
    if ((temp_v0 != 0) && (temp_v0 != 1) && (temp_v0 != 4)) {
        return 1;
    }
    return 0;
}

void baeggcursor_entrypoint_10(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((((Objcursor_arg0 *)arg0)->unk68)) + (0))) = arg1;
    (*(f32 *)((s8 *)((((Objcursor_arg0 *)arg0)->unk68)) + (4))) = arg2;
}

s32 baeggcursor_entrypoint_11(void *arg0) {
    s32 func_800D9078(f32 *);
    f32 func_800D91B8(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 scale;
    f32 time;
    s32 i;
    f32 (*table)[2];
    u8 state;

    state = *(u8 *)(*(s8 **)((s8 *)arg0 + 0x68) + 9);
    switch (state) {
    case 3:
        if (*(f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0xC) < 0.1f) {
            scale = func_800F10B4(*(f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0xC), 0.0, 0.1f, 1.0f, 0.8f);
        } else {
            scale = func_800F10B4(*(f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0xC), 0.1f, 0.3f, 0.8f, 16.0f);
        }
        *(f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0x18) = scale;
        *(s32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0x14) = func_800F10B4(*(f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0xC), 0.0, 0.3f, 120.0, 0.0);
        if (func_800D9078((f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0xC))) {
            baeggcursor_entrypoint_7(arg0, 2);
        }
        break;
    case 4:
        *(f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0x18) = func_800F10B4(*(f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0xC), 0.0, 0.2f, 16.0f, 1.0f);
        *(s32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0x14) = func_800F10B4(*(f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0xC), 0.0, 0.2f, 0.0f, 120.0);
        if (func_800D9078((f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0xC))) {
            baeggcursor_entrypoint_7(arg0, 1);
        }
        break;
    case 5:
        time = *(f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0xC);
        table = (f32 (*)[2])func_80800000_baeggcursor(*(u8 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0x10));
        for (i = 0; table[i][0] <= time; i++) {
            if (table[i][1] == 0.0f) {
                baeggcursor_entrypoint_7(arg0, 2);
                break;
            }
        }
        *(f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0x18) = func_800F10B4(time, table[i - 1][0], table[i][0], table[i - 1][1], table[i][1]);
        func_800D91B8((f32 *)(*(s8 **)((s8 *)arg0 + 0x68) + 0xC));
        break;
    }
    BT_NATIVE_ONLY(return 0;)}
/* data_to_c.py: from asm/data/overlays/ba/egg/cursor.data.s */
extern u8 D_80800670_baeggcursor[];
u8 D_80800670_baeggcursor[32] BT_DATA(4, overlays_ba_egg_cursor, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x3D, 0xA3, 0xD7, 0x0A, 0x3F, 0x00, 0x00, 0x00, 0x3E, 0x99, 0x99, 0x9A, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
BtIntPtr D_80800690_baeggcursor [4] BT_DATA(4, overlays_ba_egg_cursor, 0x20) = { (BtIntPtr)D_80800670_baeggcursor, 0, 0, 0 };
