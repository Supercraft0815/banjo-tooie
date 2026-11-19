#include "common.h"
#include "attract_tables.h"

struct AttractState {
    u8 index, scene;
    f32 time;
};
BT_IDO_ONLY(extern) struct AttractState D_80135470;

typedef struct { u8 pad0[0x4]; u8 unk4; u8 pad5[0x3];
    f32 unk8;
    } Objattract_D_8013546C; /* offsets.py genstruct: fields from raw offsets on &D_8013546C; rename once understood */ void gsattract_entrypoint_0(void) {
    BT_IDO_ONLY(extern s32 D_8013546C;)
    BT_DATA_FIELD(D_80135470.time, (((Objattract_D_8013546C *)&D_8013546C)->unk8)) = 0.0f;
}

void gsattract_entrypoint_1(void) {
    void _chattract_entrypoint_1(s32 arg0);
    s32 func_80015FA0(s32 arg0);
    u8 func_800167F4(void);
    void func_800A9C50(void);
    s32 func_800C95D4(void);
    f32 func_800D9004(void);
    f32 previous;

    DemoSequence *entry;
    s32 flags;
    s32 mode;

    previous = D_80135470.time;
    if (func_800C95D4()) {
        D_80135470.time += func_800D9004();
    }
    entry = &D_80800490_gsattract[D_80135470.index];
    flags = entry->flags;
    if ((flags & 1) && D_80135470.time >= 6.0f && previous < 6.0f) {
        if (func_800167F4()) {
            mode = 3;
        } else {
            mode = 1;
        }
        _chattract_entrypoint_1(mode);
        entry = &D_80800490_gsattract[D_80135470.index];
        flags = entry->flags;
    }
    if ((flags & 2) && D_80135470.time >= 0.5f && previous < 0.5f) {
        _chattract_entrypoint_1(2);
        entry = &D_80800490_gsattract[D_80135470.index];
    }
    if ((entry->scenes[D_80135470.scene].flags & 1) &&
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
    BT_IDO_ONLY(extern s32 D_8013546C;)
    s32 var_a0;
    u8 *state;

    if (func_800A8264() == 0) {
        state = BT_DATA_FIELD((u8 *)&D_80135470, (u8 *)(BtUIntPtr)(&D_8013546C + 1));
        var_a0 = state[1] + 1;
        if (var_a0 >= D_80800490_gsattract[state[0]].sceneCount) {
            var_a0 = 0;
        }
        func_808002A4_gsattract(var_a0);
    }
}

void gsattract_entrypoint_4(void) {
    BT_IDO_ONLY(extern s32 D_8013546C;)
    BT_DATA_FIELD(D_80135470.index, (*(s8 *)((s8 *)(&D_8013546C) + (4)))) = 2;
}

void func_80800274_gsattract(s32 arg0) {
    BT_IDO_ONLY(extern s32 D_8013546C;)
    s8 *state;
    s32 index;

    index = arg0 & 0xFF;
    BT_NATIVE_ONLY(state = (s8 *)&D_80135470;) BT_IDO_ONLY(state = (s8 *)&D_8013546C; state += 4;)
    *state = arg0;
    *(u8 *)(state + 1) = D_80800490_gsattract[index].sceneCount;
}

void func_808002A4_gsattract(s32 arg0) {
    void func_800A791C(s32, s32, s32);
    void func_800A9BA0(s32, s32, s32);
    void func_800D3A14(s32);
    BT_IDO_ONLY(extern s32 D_8013546C;)
    DemoScene *temp_v0;
    s32 index;
    u8 (*state)[2];

    index = 1;
    state = BT_DATA_FIELD((u8 (*)[2])&D_80135470, (u8 (*)[2])(&D_8013546C + index));
    (*state)[index] = arg0;
    temp_v0 = &D_80800490_gsattract[(*state)[0]].scenes[arg0];

    if (temp_v0->exit < 0) {
        func_800A791C(temp_v0->map, 1, 1);
        return;
    }
    func_800D3A14(temp_v0->setup);
    func_800A9BA0(2, temp_v0->map, temp_v0->exit);
}

void gsattract_entrypoint_5(s32 arg0) {
    void func_800A9B84(void);
    void func_800A9B8C(s32, s32);
    s32 func_800FE4E4(void);
    BT_IDO_ONLY(extern s32 D_8013546C;)
    extern s16 widescreen_enabled;
    DemoSequence *temp_v0;


    if (func_800A8264() == 0) {
        if (widescreen_enabled != 0) {
            arg0 = 1;
        }
        if (arg0 != (BT_DATA_FIELD(D_80135470.index, ((Objattract_D_8013546C *)&D_8013546C)->unk4))) {
            func_80800274_gsattract(arg0);
        }
        func_800FE4E4();
        func_800A9B84();
        temp_v0 = &D_80800490_gsattract[BT_DATA_FIELD(D_80135470.index, ((Objattract_D_8013546C *)&D_8013546C)->unk4)];
        func_800A9B8C(temp_v0->map, temp_v0->exit);
        gsattract_entrypoint_3();
    }
}
#include "attract_data.inc"
