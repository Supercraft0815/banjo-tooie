#include "common.h"

void sutempleboss_entrypoint_0(s16 *arg0, s32 *arg1, s32 *arg2) {
    Prop *_gccubesearch_entrypoint_15(u32, u32, f32 *);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    s32 func_800EA05C(void);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800F4BE4(s32);
    u32 func_800F54E4(void);
    s32 result;
    s32 side;
    s32 pad;
    f32 position[3];
    f32 destination[3];
    f32 distance;

    if (!func_800F4BE4(func_800F54E4())) {
        *arg2 = 0;
        *arg1 = 0;
        return;
    }
    switch (func_800EA05C()) {
    case 0x177:
        *arg1 = 0x178;
        if (func_800DA298(0x9D2)) {
            *arg2 = 2;
        } else {
            *arg2 = 1;
        }
        break;
    case 0x17A:
        *arg1 = 0x178;
        if (func_800DA298(0x9D2)) {
            *arg2 = 1;
        } else {
            *arg2 = 2;
        }
        break;
    case 0x178:
        func_800EE88C(position, arg0);
        func_800EE88C(destination, _gccubesearch_entrypoint_15(1, 0, position));
        distance = func_800EEB40(position, destination);
        func_800EE88C(destination, _gccubesearch_entrypoint_15(2, 0, position));
        side = distance < func_800EEB40(position, destination) ? 0 : 1;
        if (func_800D0B68(2, 1)) {
            result = func_800DA298(0x9D2) ? side ^ 1 : side;
        } else {
            result = 0;
            func_800DA3B8(0x9D2, side);
        }
        if (result) {
            *arg1 = 0x17A;
        } else {
            *arg1 = 0x177;
        }
        *arg2 = 1;
        break;
    }
}
