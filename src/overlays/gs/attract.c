#include "common.h"

typedef struct { u8 pad0[0x4]; u8 unk4; u8 pad5[0x3]; f32 unk8; } Objattract_D_8013546C; /* offsets.py genstruct: fields from raw offsets on &D_8013546C; rename once understood */ void gsattract_entrypoint_0(void) {
    extern s32 D_8013546C;
    (((Objattract_D_8013546C *)&D_8013546C)->unk8) = 0.0f;
}

void gsattract_entrypoint_1(void) {
    void _chattract_entrypoint_1(s32 arg0);
    s32 func_80015FA0(s32 arg0);
    u8 func_800167F4(void);
    void func_800A9C50(void);
    s32 func_800C95D4(void);
    f32 func_800D9004(void);
    extern s32 D_80800490_gsattract;
    f32 previous;
    struct AttractState {
        u8 index;
        u8 scene;
        f32 time;
    };
    extern struct AttractState D_80135470;
    u8 *entry;
    s32 flags;
    s32 mode;

    previous = D_80135470.time;
    if (func_800C95D4()) {
        D_80135470.time += func_800D9004();
    }
    entry = (u8 *)&D_80800490_gsattract + D_80135470.index * 12;
    flags = entry[8];
    if ((flags & 1) && D_80135470.time >= 6.0f && previous < 6.0f) {
        if (func_800167F4()) {
            mode = 3;
        } else {
            mode = 1;
        }
        _chattract_entrypoint_1(mode);
        entry = (u8 *)&D_80800490_gsattract + D_80135470.index * 12;
        flags = entry[8];
    }
    if ((flags & 2) && D_80135470.time >= 0.5f && previous < 0.5f) {
        _chattract_entrypoint_1(2);
        entry = (u8 *)&D_80800490_gsattract + D_80135470.index * 12;
    }
    if (((*(u8 **)(entry + 4))[D_80135470.scene * 6 + 3] & 1) &&
        D_80135470.time >= 1.0f && previous < 1.0f) {
        _chattract_entrypoint_1(0);
    }
    if (func_800C95D4() && func_80015FA0(0)) {
        func_800A9C50();
    }
}

void gsattract_entrypoint_2(s32 arg0) 
{
}
void gsattract_entrypoint_3(void) {
    int func_800A8264(void);
    void func_808002A4_gsattract(s32);
    extern s32 D_8013546C;
    extern s32 D_80800493_gsattract;
    s32 var_a0;
    u8 *state;

    if (func_800A8264() == 0) {
        state = (u8 *)(BtUIntPtr)(&D_8013546C + 1);
        var_a0 = state[1] + 1;
        if (var_a0 >= *((u8 *)&D_80800493_gsattract + state[0] * 12)) {
            var_a0 = 0;
        }
        func_808002A4_gsattract(var_a0);
    }
}

void gsattract_entrypoint_4(void) {
    extern s32 D_8013546C;
    (*(s8 *)((s8 *)(&D_8013546C) + (4))) = 2;
}

void func_80800274_gsattract(s32 arg0) {
    extern s32 D_8013546C;
    extern s32 D_80800493_gsattract;
    s8 *state;
    s32 index;

    index = arg0 & 0xFF;
    state = (s8 *)&D_8013546C;
    state += 4;
    *state = arg0;
    *(u8 *)(state + 1) = *(u8 *)((s8 *)&D_80800493_gsattract + index * 12);
}

void func_808002A4_gsattract(s32 arg0) {
    void func_800A791C(s32, s32, s32);
    void func_800A9BA0(s32, s32, s32);
    void func_800D3A14(s32);
    extern s32 D_8013546C;
    extern s8 *D_80800494_gsattract[];
    s8 *temp_v0;
    s32 index;
    u8 (*state)[2];

    index = 1;
    state = (u8 (*)[2])(&D_8013546C + index);
    (*state)[index] = arg0;
    temp_v0 = *(s8 **)((u8 *)D_80800494_gsattract + (*state)[0] * 12) + arg0 * 6;
    if (temp_v0[2] < 0) {
        func_800A791C(*(s16 *)temp_v0, 1, 1);
        return;
    }
    func_800D3A14((u8)temp_v0[4]);
    func_800A9BA0(2, *(s16 *)temp_v0, temp_v0[2]);
}    typedef struct { s16 unk0; u8 unk2; } Objattract_gsattract_entrypoint_5_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void gsattract_entrypoint_5(s32 arg0) {
    void func_800A9B84(void);
    void func_800A9B8C(s32, s32);
    s32 func_800FE4E4(void);
    extern s32 D_8013546C;
    extern s32 D_80800490_gsattract;
    extern s16 widescreen_enabled;
    void *temp_v0;

    if (func_800A8264() == 0) {
        if (widescreen_enabled != 0) {
            arg0 = 1;
        }
        if (arg0 != (((Objattract_D_8013546C *)&D_8013546C)->unk4)) {
            func_80800274_gsattract(arg0);
        }
        func_800FE4E4();
        func_800A9B84();
        temp_v0 = ((((Objattract_D_8013546C *)&D_8013546C)->unk4) * 0xC) + (u8 *)&D_80800490_gsattract;
        func_800A9B8C((((Objattract_gsattract_entrypoint_5_temp_v0 *)temp_v0)->unk0), (((Objattract_gsattract_entrypoint_5_temp_v0 *)temp_v0)->unk2));
        gsattract_entrypoint_3();
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8013546C BT_DATA(4, bss_core2bss2_2, 0x25CC);
#endif
