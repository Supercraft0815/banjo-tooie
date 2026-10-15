#include "common.h"

typedef struct {
    f32 position[3];
    s32 id;
    f32 rotation;
    f32 radius;
} BossMarker;

s32 subaddiemarker_entrypoint_0(Actor *arg0, s32 arg1, BossMarker *arg2, s32 arg3) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    f32 _gspropmarker_entrypoint_3(Prop *);
    void func_800EE88C(f32 *, s16 *);
    extern Prop *B_808001E0_subaddiemarker[];
    s32 count;
    s32 i;

    count = _gccubesearch_entrypoint_9(arg1, B_808001E0_subaddiemarker, 0x28);
    for (i = 0; i < count; i++) {
        arg2->radius = _gspropmarker_entrypoint_3(B_808001E0_subaddiemarker[i]);
        arg2->rotation = B_808001E0_subaddiemarker[i]->FlagOrRotation;
        arg2->id = B_808001E0_subaddiemarker[i]->unk6_7;
        func_800EE88C(arg2->position, B_808001E0_subaddiemarker[i]->position);
        arg2++;
    }
    return count;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/marker/subaddiemarker_entrypoint_1.s")
