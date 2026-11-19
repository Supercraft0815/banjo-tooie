#include "common.h"

typedef struct { s8 flag; s32 value; } Entry; extern u8 D_80124730[13]; extern Entry D_80136F90[13][2]; 

void func_8010D790(void) { int i; u32 j; u8 *counts; int count; i = 0; j = 0; do { counts = &D_80124730[i]; count = *counts; j = 0; if (count > 0) { loop: j++; D_80136F90[i][(s32)j - 1].flag = 0; D_80136F90[i][(s32)j - 1].value = -1; count = D_80124730[i]; if ((s32)j < count) goto loop; } i++; } while (i != 13); }

void func_8010D7EC(void) {
    int func_800C3D78(u8);
    void func_8010DA30(u8 *arg0);
    int j;
    u32 i;
    u8 *counts;
    u8 id;

    counts = D_80124730;
    i = 0;
    do {
        for (j = 0; j < (s32)*counts; j++) {
            id = (u8)D_80136F90[i][j].flag;
            if (id != 0 && func_800C3D78(id) == 0) {
                func_8010DA30((u8 *)&D_80136F90[i][j]);
            }
        }
        i++;
        counts++;
    } while (i != 13);
}

void func_8010D89C(void) {
    void func_8010DA30(u8 *arg0);
    int j;
    u32 i;
    u8 *counts;

    counts = D_80124730;
    i = 0;
    do {
        for (j = 0; j < (s32)*counts; j++) {
            func_8010DA30((u8 *)&D_80136F90[i][j]);
        }
        i++;
        counts++;
    } while (i != 13);
}    typedef struct { u8 unk0; u8 pad1[0x3]; s32 unk4; } Obj1EE7080_func_8010D930_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 func_8010D930(s32 arg0, s32 arg1, f32 *arg2, s32 *arg3) {
    s32 func_8001211C(void);
    u8 func_800C2E04(void);
    void func_800C2E40(u8);
    void func_800C32C4(u8, s32);
    void func_800C330C(u8, s32);
    void func_800C3418(u8, s32);
    void func_800C3584(u8, f32, f32);
    void func_800C3B8C(u8, s32);
    void func_800C3BDC(u8);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    u8 *func_8010DA70(s32);
    u8 *temp_v0;

    temp_v0 = func_8010DA70(arg0);
    if ((((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0) == 0) {
        (((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0) = func_800C2E04();
    } else {
        func_800C2E40((((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0));
    }
    if (arg2 != 0) {
        func_800C3584((((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0), 200.0f, 3000.0f);
    }
    func_800C330C((((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0), 3);
    if (arg1 >= 0) {
        if (arg1 != 0) {
            func_800C3418((((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0), 1);
            func_800C32C4((((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0), 0x40);
        } else {
            func_800C3418((((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0), 2);
        }
    } else {
        func_800C3418((((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0), 0);
    }
    func_800C4350((((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0), arg2, arg3);
    func_800C3B8C((((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0), 0);
    func_800C3BDC((((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk0));
    (((Obj1EE7080_func_8010D930_temp_v0 *)temp_v0)->unk4) = func_8001211C();
    return 1;
}

/* extern */

void func_8010DA30(u8 *arg0) {
    BT_IDO_ONLY(s32 func_800C2FDC(s32, u8 *, u8);) BT_NATIVE_ONLY(s32 func_800C2FDC(u8);)
    u8 temp_a2;

    temp_a2 = (*(u8 *)((s8 *)(arg0) + (0)));
    if (temp_a2 != 0) {
        BT_IDO_ONLY(func_800C2FDC(temp_a2 & 0xFF, arg0, temp_a2);) BT_NATIVE_ONLY(func_800C2FDC(temp_a2 & 0xFF);)
        (*(u8 *)((s8 *)(arg0) + (0))) = 0;
    }
    (((Entry *)arg0)->value) = -1;
}

u8 *func_8010DA70(s32 arg0) { s32 i; s32 count; Entry *best; i = 0; best = (Entry *)((arg0 << 4) + (u8 *)D_80136F90); count = D_80124730[arg0]; if (count >= 2) { i = 8; do { if (((Entry *)((arg0 * 16 + i) + (u8 *)D_80136F90))->value < best->value) { best = (Entry *)((arg0 * 16 + i) + (u8 *)D_80136F90); } i += 8; } while (i < count * 8); } return (u8 *)best; }

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
Entry D_80136F90 [ 13 ] [ 2 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x1570);
#endif
