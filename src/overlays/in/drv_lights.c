#include "common.h"

void indrv_lights_entrypoint_0(s32 arg0, s32 arg1, s32 arg2) {
    void _sulights_entrypoint_1(s32, s32 *, f32);
    void _sulights_entrypoint_3(s32, f32 *, f32);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    void func_800C8FE0(s32, s32);
    void func_800DBEFC(s32 *, s32, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 sp64;
    s32 sp60;
    s32 sp54[3];
    u32 sp48[3];
    f32 sp40[2];
    f32 sp38[2];
    s32 sp34;
    register s32 index;
    f32 sp24[3];
    Actor *actor;

    (void)&arg2;

    switch (arg0 & 0xFFFF) {
    case 0:
        sp54[0] = (u32) (arg1 & 0xFF000000) >> 24;
        sp54[1] = (arg1 & 0xFF0000) >> 16;
        sp54[2] = (arg1 & 0xFF00) >> 8;
        _sulights_entrypoint_1((u32) (arg0 & 0xFFFF0000) >> 16, sp54, (f32) arg2 * 0.00390625f);
        return;
    case 5:
        sp48[0] = (u32) (arg1 & 0xFF000000) >> 24;
        sp48[1] = (arg1 & 0xFF0000) >> 16;
        sp48[2] = (arg1 & 0xFF00) >> 8;
        func_800C8E84((u32) (arg0 & 0xFFFF0000) >> 16, sp48);
        return;
    case 1:
        func_800C8FE0((u32) (arg0 & 0xFFFF0000) >> 16, 1);
        return;
    case 2:
        func_800C8FE0((u32) (arg0 & 0xFFFF0000) >> 16, 0);
        return;
    case 3:
        sp40[0] = (f32) (u32) (arg2 & 0xFFFF);
        sp40[1] = (f32) (u32) (arg1 & 0xFFFF);
        _sulights_entrypoint_3((u32) (arg0 & 0xFFFF0000) >> 16, sp40, (f32) arg2 * 0.00390625f);
        return;
    case 4:
        sp38[0] = (f32) (u32) (arg2 & 0xFFFF);
        sp38[1] = (f32) (u32) (arg1 & 0xFFFF);
        func_800C8D4C((u32) (arg0 & 0xFFFF0000) >> 16, sp38);
        return;
    case 6:
        actor = func_80106790((Unk80132ED0 *) arg1);
        index = arg2;
        if (!actor->unk7C_12 || index == -1) {
            func_800C8CB8((u32) (arg0 & 0xFFFF0000) >> 16, actor->position);
        } else {
            func_800DBEFC(((Unk80132ED0 *) arg1)->unk4, index, sp24);
            func_800C8CB8((u32) (arg0 & 0xFFFF0000) >> 16, sp24);
        }
    default:
        return;
    }
}
