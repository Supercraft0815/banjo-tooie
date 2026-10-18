#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/sect/subaddiesect_entrypoint_0.s")

/* extern */

void subaddiesect_entrypoint_1(s32 arg0) {
    s32 _gcmapsects_entrypoint_4(s32);
    _gcmapsects_entrypoint_4(arg0 + 0x4);
}

s32 subaddiesect_entrypoint_2(Actor *arg0, s32 arg1, s32 arg2) {
    s32 *_gcmapsects_entrypoint_25(void *, s32, f32 *, f32 *, f32 *, u32);
    void *func_800BF704(void);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F1B78(f32 *, f32 *, f32, f32);
    void func_801045AC(Actor *, f32 *, f32 *, s32);
    f32 upper[3];
    f32 lower[3];
    f32 normal[3];
    s32 *section;
    f32 rotation[3];

    func_800EE7F8(upper, arg0->position);
    func_800EE7F8(lower, arg0->position);
    upper[1] += 100.0f;
    lower[1] -= 100.0f;
    section = _gcmapsects_entrypoint_25(func_800BF704(), arg1, upper, lower, normal, arg0->unk14);
    if (section != NULL) {
        if (arg2 != 0) {
            arg0->position[1] = lower[1];
            if (func_800F1B78(rotation, normal, arg0->rotation[1], 1.0f)) {
                arg0->rotation[0] = rotation[0];
                arg0->rotation[2] = rotation[2];
            }
        }
        func_801045AC(arg0, normal, lower, section[2]);
        return 1;
    }
    return 0;
}
