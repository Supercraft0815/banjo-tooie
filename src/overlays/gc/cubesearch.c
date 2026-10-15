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

void gccubesearch_entrypoint_5(s32 arg0, s32 arg1) {
    gccubesearch_entrypoint_4(arg0, arg1, 0);
}

void gccubesearch_entrypoint_6(s32 arg0,s32 arg1)
{
    gccubesearch_entrypoint_4(arg0,arg1,0x1);
}

/* extern */

s32 gccubesearch_entrypoint_7(s32 *arg0, Actor **arg1, s32 arg2) {
    s32 _gspropmarker_entrypoint_1(s32, s32 *, Actor **, s32);
    void func_800BE52C(s32 *, s32 *);
    s32 var_s0;
    s32 sp30;
    s32 sp2C;

    var_s0 = 0;
    func_800BE52C(&sp30, &sp2C);
    if ((u32)sp30 < (u32)sp2C) {
        do {
            var_s0 += _gspropmarker_entrypoint_1(sp30, arg0, arg1 + var_s0, arg2 - var_s0);
            sp30 += 8;
        } while ((u32)sp30 < (u32)sp2C);
    }
    return var_s0;
}

/* extern */

s32 gccubesearch_entrypoint_8(s32 *arg0, Actor **arg1, s32 arg2, f32 *arg3) {
    s32 _gspropmarker_entrypoint_1(s32, s32 *, Actor **, s32);
    s32 *func_800BDD24(s32 *);
    void func_800EE904(s32 dst[3], f32 src[3]);
    s32 *var_s0;
    s32 temp_v0_2;
    s32 sp3C[3];
    s32 var_s2;

    var_s2 = 0;
    func_800EE904(sp3C, arg3);
    var_s0 = func_800BDD24(sp3C);
    while (*var_s0 != 0) {
        temp_v0_2 = _gspropmarker_entrypoint_1(*var_s0, arg0, arg1 + var_s2, arg2 - var_s2);
        var_s0++;
        var_s2 += temp_v0_2;
    }
    return var_s2;
}

/* extern */

s32 gccubesearch_entrypoint_9(s32 arg0, Actor **arg1, s32 arg2) {
    s32 gccubesearch_entrypoint_7(s32 *, Actor **, s32);
    s32 sp18[2];

    sp18[0] = arg0;
    sp18[1] = -1;
    return gccubesearch_entrypoint_7(sp18, arg1, arg2);
}

s32 gccubesearch_entrypoint_10(s32 arg0, u32 arg1) {
    extern Actor *B_80800EB0_gccubesearch[40];
    s32 var_v1;

    arg0 = gccubesearch_entrypoint_9(arg0, B_80800EB0_gccubesearch, 0x28) - 1;
    var_v1 = 0;
    while (arg0 >= 0) {
        if (((u32)B_80800EB0_gccubesearch[arg0]->pointerToSyscallEntry >> 0x15) < arg1) {
            var_v1 += 1;
        }
        arg0--;
    }
    return var_v1;
}

/* extern */

s32 gccubesearch_entrypoint_11(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gspropmarker_entrypoint_2(s32, s32, s32, s32);
    void func_800BE52C(s32 *, s32 *);
    s32 var_s0;
    s32 sp38;
    s32 sp34;

    var_s0 = 0;
    func_800BE52C(&sp38, &sp34);
    if ((u32)sp38 < (u32)sp34) {
        do {
            var_s0 += _gspropmarker_entrypoint_2(sp38, arg0, (var_s0 * 0xC) + arg1, arg2 - var_s0);
            sp38 += 8;
        } while ((u32)sp38 < (u32)sp34);
    }
    return var_s0;
}

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

/* extern */

s32 gccubesearch_entrypoint_16(s32 *arg0, s32 *arg1, s32 *arg2, s32 arg3, s32 arg4) {
    void func_800BE52C(s32 *, s32 *);
    void func_800EB880(s32 *, s32, s32);
    s32 func_800EB8C0(s32);
    s32 func_800EBB30(s32 *, s32 *);
    s32 sp1C;
    s32 sp18;

    func_800EB880(arg0, arg3, arg4);
    func_800BE52C(&sp1C, &sp18);
    if ((u32)sp1C < (u32)sp18) {
        do {
            func_800EB8C0(sp1C);
            sp1C += 8;
        } while ((u32)sp1C < (u32)sp18);
    }
    return func_800EBB30(arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_18.s")
