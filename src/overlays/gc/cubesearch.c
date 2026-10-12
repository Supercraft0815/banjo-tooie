#include "common.h"

void *gccubesearch_entrypoint_0(s32 actor_id, Actor *actor) {
    void *gccubesearch_entrypoint_14(s32, s32 *);
    s32 pos[3];
    s32 *position;
    if (actor != NULL) {
        pos[0] = actor->position[0];
        pos[1] = actor->position[1];
        pos[2] = actor->position[2];
    }
    if (actor == NULL) position = NULL;
    else position = pos;
    return gccubesearch_entrypoint_14(actor_id, position);
}

void *gccubesearch_entrypoint_1(s32 actor_id, f32 *position) {
    void *gccubesearch_entrypoint_14(s32, s32 *);
    s32 pos[3];
    pos[0] = (s32)position[0];
    pos[1] = (s32)position[1];
    pos[2] = (s32)position[2];
    return gccubesearch_entrypoint_14(actor_id, pos);
}

int gccubesearch_entrypoint_2(s32 actor_id, s32 *position) {
    void *gccubesearch_entrypoint_14(s32, s32 *);
    s16 *ptr = gccubesearch_entrypoint_14(actor_id, NULL);
    if (ptr != NULL) {
        position[0] = ptr[0];
        position[1] = ptr[1];
        position[2] = ptr[2];
        return 1;
    }
    return 0;
}

s32 gccubesearch_entrypoint_3(s32 actor_id, f32 dst[3]) {
    void func_800EE84C(f32 *, s32 *);
    s32 position[3];
    if (gccubesearch_entrypoint_2(actor_id, position) == 0) return 0;
    func_800EE84C(dst, position);
    return 1;
}

s32 func_80800160_gccubesearch(s32 arg0, s32 arg1, s32 arg2) {
    return (arg0 * arg0) + (arg1 * arg1) + (arg2 * arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_5.s")

void gccubesearch_entrypoint_6(s32 arg0,s32 arg1)
{
    gccubesearch_entrypoint_4(arg0,arg1,0x1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_8.s")

/* extern */

void gccubesearch_entrypoint_9(s32 arg0) {
    s32 gccubesearch_entrypoint_7(s32 *);
    s32 sp18[2];

    sp18[0] = arg0;
    sp18[1] = -1;
    gccubesearch_entrypoint_7(sp18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/func_80800590_gccubesearch.s")

void gccubesearch_entrypoint_12(s32 arg0, s32 arg1, s32 arg2) {
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_80800590_gccubesearch(s32, s32, s32, f32 (*)(f32 *, f32 *));

    func_80800590_gccubesearch(arg0, arg1, arg2, func_800EEB40);
}

s32 gccubesearch_entrypoint_13(s32 arg0, s32 arg1, s32 arg2) {
    f32 func_800EFC7C(f32 *, f32 *);
    s32 func_80800590_gccubesearch(s32, s32, s32, f32 (*)(f32 *, f32 *));
    return func_80800590_gccubesearch(arg0, arg1, arg2, func_800EFC7C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_18.s")
