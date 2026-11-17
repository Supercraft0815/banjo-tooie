#include "common.h"

typedef struct { BtIntPtr unk0; u32 * unk4; s32 unk8; s32 unkC; u8 pad10[0x4]; s8 unk14; } Objrecord_D_8012D5B0; /* offsets.py genstruct: fields from raw offsets on &D_8012D5B0; rename once understood */ s32 glrecord_entrypoint_0(OSContPad *arg0, s32 *arg1) {
    extern s32 D_8012D5B0;
    struct Record { u8 x; u8 y; u16 button; u8 lag; u8 pad; } *record;
    s32 count;
    int valid;

    count = ((Objrecord_D_8012D5B0 *)&D_8012D5B0)->unk8;
    record = (struct Record *)*(s32 *)((s8 *)&D_8012D5B0) + (((Objrecord_D_8012D5B0 *)&D_8012D5B0)->unk8)++;
    valid = ((Objrecord_D_8012D5B0 *)&D_8012D5B0)->unk8 < ((Objrecord_D_8012D5B0 *)&D_8012D5B0)->unkC;
    if (!valid) {
        record = (struct Record *)((s8 *)&D_8012D5B0 + 0x10);
    }
    arg0->stick_x = record->x;
    arg0->stick_y = record->y;
    arg0->button = record->button;
    *arg1 = record->lag;
    return valid;
}

void glrecord_entrypoint_1(BtIntPtr arg0, u32 arg1, s32 arg2) {
    extern s32 D_8012D5B0;
    (((Objrecord_D_8012D5B0 *)&D_8012D5B0)->unk0) = arg0;
    (*(u32 *)((s8 *)(&D_8012D5B0) + (0xC))) = (u32) (arg1 / 6U);
    (((Objrecord_D_8012D5B0 *)&D_8012D5B0)->unk8) = 0;
}

s32 glrecord_entrypoint_2(void) {
    extern s32 D_8012D5B0;
    return (((Objrecord_D_8012D5B0 *)&D_8012D5B0)->unk8) * 6;
}

void glrecord_entrypoint_3(s32 arg0, s32 arg1) {
    u8 _gcsectionDll_entrypoint_4(s32 arg0);
    void func_800D5B24(void);
    u32 *func_800D5B34(s32);
    void glrecord_entrypoint_4(void);
    extern s32 D_8012D5B0;
    u32 *data;
    u32 size;

    if (((Objrecord_D_8012D5B0 *)&D_8012D5B0)->unk4 != NULL) {
        glrecord_entrypoint_4();
    }
    ((Objrecord_D_8012D5B0 *)&D_8012D5B0)->unk14 = 2;
    func_800D5B24();
    ((Objrecord_D_8012D5B0 *)&D_8012D5B0)->unk4 = func_800D5B34(_gcsectionDll_entrypoint_4(arg0) + arg1 * 13 + 0xC57);
    data = ((Objrecord_D_8012D5B0 *)&D_8012D5B0)->unk4;
    size = data[0];
    glrecord_entrypoint_1((BtIntPtr)(data + 1), size, 0);
}

void glrecord_entrypoint_4(void) {
    s32 func_800D56C4(s32);
    extern s32 D_8012D5B0;
    if ((*(s32 *)((s8 *)(&D_8012D5B0) + (4))) != 0) {
        func_800D56C4((*(s32 *)((s8 *)(&D_8012D5B0) + (4))));
        (*(s32 *)((s8 *)(&D_8012D5B0) + (4))) = 0;
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012D5B0 BT_DATA(4, bss_core2bss2_1, 0xC70);
#endif
