#include "common.h"

s32 sudeathmatch_entrypoint_0(s32 arg0, f32 *arg1, f32 *arg2) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _gspropctrl_entrypoint_12(Prop *);
    s32 _gspropctrl_entrypoint_8(Prop *);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    f32 func_800EFC7C(void *, void *);
    s32 func_800F5898(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6438(u32);
    extern Prop *B_80800300_sudeathmatch[40];
    extern u8 B_808003A0_sudeathmatch[40];
    extern s32 B_808003C8_sudeathmatch;
    s32 radius;
    s32 angle;
    f32 positions[8][3];
    s32 i;
    s32 count;
    s32 remaining;
    f32 position[3];
    s32 choice;
    s32 index;
    Prop *prop;
    f32 scale;
    f32 offset[3];

    i = 0;
    count = 0;
    for (; i < func_800F5898(); i++) {
        if (i != arg0 && func_800F6438(i)) {
            func_800F5A00(i, positions[count++]);
        }
    }
    remaining = _gccubesearch_entrypoint_9(0x2B7, B_80800300_sudeathmatch, 40);
    if (remaining == 0) {
        return 0;
    }
    for (i = 0; i < remaining; i++) {
        B_808003A0_sudeathmatch[i] = i;
    }
    B_808003A0_sudeathmatch[B_808003C8_sudeathmatch] = B_808003A0_sudeathmatch[--remaining];
    while (remaining > 0) {
        choice = func_800DC0C0() * ((f32)remaining - 0.5f);
        index = B_808003A0_sudeathmatch[choice];
        prop = B_80800300_sudeathmatch[index];
        _gspropctrl_entrypoint_11(prop, position);
        for (i = 0; i < count; i++) {
            if (func_800EFC7C(position, positions[i]) < 160000.0f) {
                if (remaining >= 2) {
                    B_808003A0_sudeathmatch[choice] = B_808003A0_sudeathmatch[--remaining];
                } else {
                    i = count;
                }
                break;
            }
        }
        if (i == count) {
            radius = _gspropctrl_entrypoint_8(prop);
            angle = _gspropctrl_entrypoint_12(prop);
            offset[0] = (scale = radius) * func_800DC178(-1.0f, 1.0f);
            offset[1] = 0.0f;
            offset[2] = func_800DC178(-1.0f, 1.0f) * scale;
            func_800EE780(arg1, position, offset);
            arg2[0] = arg2[2] = 0.0f;
            arg2[1] = angle;
            B_808003C8_sudeathmatch = index;
            return 1;
        }
    }
    return 0;
}
