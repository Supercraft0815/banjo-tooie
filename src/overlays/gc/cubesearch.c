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

Actor *gccubesearch_entrypoint_4(s32 *arg0, f32 *arg1, s32 arg2) {
    s32 gccubesearch_entrypoint_7(s32 *, Actor **, s32);
    s32 gccubesearch_entrypoint_8(s32 *, Actor **, s32, f32 *);
    s32 i;
    Actor *results[40];
    Actor *closest;
    s32 min_dist_sq;
    s32 count;
    s32 dist_sq;
    s16 position[3];

    min_dist_sq = 0x7FFFFFFF;
    closest = NULL;
    position[0] = (s16)arg1[0];
    position[1] = (s16)arg1[1];
    position[2] = (s16)arg1[2];
    if (arg2 == 0) {
        count = gccubesearch_entrypoint_7(arg0, results, 40);
    } else {
        count = gccubesearch_entrypoint_8(arg0, results, 40, arg1);
    }
    if (count == 0) {
        return NULL;
    }
    for (i = 0; i < count; i++) {
        dist_sq = func_80800160_gccubesearch(
            position[0] - ((s16 *)results[i])[0],
            position[1] - ((s16 *)results[i])[1],
            position[2] - ((s16 *)results[i])[2]);
        if (dist_sq < min_dist_sq) {
            min_dist_sq = dist_sq;
            closest = results[i];
        }
    }
    return closest;
}

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

/* extern */

s32 func_80800590_gccubesearch(f32 arg0[3], s32 arg1, f32 arg2[3], f32 (*arg3)(f32[3], f32[3])) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    f32 sp50[40][3];
    f32 var_f20;
    s32 var_s1;
    s32 temp_v0;
    f32 temp_f0;

    func_800EFD24(arg0);
    var_f20 = 3.40282347e+38f;
    temp_v0 = gccubesearch_entrypoint_11(arg1, sp50[0], 0x28);
    if (temp_v0 == 0) {
        return 0;
    }
    for (var_s1 = 0; var_s1 < temp_v0; var_s1++) {
        temp_f0 = arg3(arg2, sp50[var_s1]);
        if (temp_f0 < var_f20) {
            var_f20 = temp_f0;
            func_800EE7F8(arg0, sp50[var_s1]);
        }
    }
    if (var_f20 == 3.40282347e+38f) return 0;
    return 1;
}

void gccubesearch_entrypoint_12(s32 arg0, s32 arg1, s32 arg2) {
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_80800590_gccubesearch();

    func_80800590_gccubesearch(arg0, arg1, arg2, func_800EEB40);
}

s32 gccubesearch_entrypoint_13(s32 arg0, s32 arg1, s32 arg2) {
    f32 func_800EFC7C(f32 *, f32 *);
    s32 func_80800590_gccubesearch();
    return func_80800590_gccubesearch(arg0, arg1, arg2, func_800EFC7C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubesearch/gccubesearch_entrypoint_14.s")

Prop *gccubesearch_entrypoint_15(u32 arg0, u32 arg1, f32 *arg2) {
    Prop *_gspropmarker_entrypoint_0(s32, u32);
    void func_800BD64C(s32 *, f32 *);
    s32 func_800BDAD4(s32 position[3]);
    void func_800BE554(s32 *, s32 *);
    s32 position[3];
    s32 i;
    s32 low[3];
    s32 high[3];
    s32 min[3];
    s32 max[3];
    Prop *prop;

    func_800BE554(min, max);
    func_800BD64C(position, arg2);
    for (i = 0; i < 3; i++) {
        low[i] = position[i] - 1;
        high[i] = position[i] + 1;
        if (low[i] < min[i]) {
            low[i] = min[i];
        }
        if (high[i] > max[i]) {
            high[i] = max[i];
        }
    }
    for (position[0] = low[0]; position[0] <= high[0]; position[0]++) {
        for (position[1] = low[1]; position[1] <= high[1]; position[1]++) {
            for (position[2] = low[2]; position[2] <= high[2]; position[2]++) {
                prop = _gspropmarker_entrypoint_0(func_800BDAD4(position), arg0);
                if (prop != NULL && (arg1 == 0 || arg1 == (*(u32 *)&prop->unk10 >> 21))) {
                    return prop;
                }
            }
        }
    }
    return NULL;
}

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

Prop *gccubesearch_entrypoint_17(s32 arg0, s32 *arg1) {
    s32 func_800BDAD4(s32 position[3]);
    void func_800BE554(s32 *, s32 *);
    s32 func_800D2E90(s32);
    Prop *func_800E9D68(s16 *);
    u32 func_800E9D90(s16 *);
    s32 position[3];
    s32 cube;
    s32 min[3];
    s32 max[3];
    Prop *prop;
    u32 end;

    func_800BE554(min, max);
    for (position[1] = min[1]; position[1] <= max[1]; position[1]++) {
        if (func_800D2E90(position[1] - min[1])) {
            for (position[0] = min[0]; position[0] <= max[0]; position[0]++) {
                for (position[2] = min[2]; position[2] <= max[2]; position[2]++) {
                    cube = func_800BDAD4(position);
                    if (cube) {
                        prop = func_800E9D68((s16 *)cube);
                        end = func_800E9D90((s16 *)cube);
                        for (; (u32)prop < end; prop++) {
                            if (arg0 == (((u32 *)prop)[4] >> 21)) {
                                if (arg1 != NULL) {
                                    *arg1 = cube;
                                }
                                return prop;
                            }
                        }
                    }
                }
            }
        }
    }
    if (arg1 != NULL) {
        *arg1 = 0;
    }
    return NULL;
}

u32 gccubesearch_entrypoint_18(s32 arg0, s32 *arg1, u32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5, Prop **arg6) {
    s32 func_800BDAD4(s32 position[3]);
    void func_800BE554(s32 *, s32 *);
    s32 func_800E9BF4(s16 *, s32);
    s32 func_800E9DC4(s16 *);
    s32 cube;
    u32 word;
    s32 min[3];
    s32 max[3];
    u32 result = 0;

    func_800BE554(min, max);
    if (arg0 == 0) {
        arg4[0] = min[0];
        arg4[1] = min[1];
        arg4[2] = min[2];
        *arg5 = 0;
        return 0;
    }
    do {
        if (max[0] < arg4[0]) {
            return -1;
        }
        cube = func_800BDAD4(arg4);
        if (cube && func_800E9DC4((s16 *)cube)) {
            *arg6 = (Prop *)func_800E9BF4((s16 *)cube, *arg5);
            word = ((u32 *)*arg6)[4];
            *arg2 = (word << 11) >> 21;
            result = word >> 21;
            *arg3 = ((u32 *)*arg6)[1] & 1;
            arg1[0] = (*arg6)->position[0];
            arg1[1] = (*arg6)->position[1];
            arg1[2] = (*arg6)->position[2];
            (*arg5)++;
        }
        if (!cube || *arg5 >= func_800E9DC4((s16 *)cube)) {
            *arg5 = 0;
            arg4[2]++;
            if (max[2] < arg4[2]) {
                arg4[2] = min[2];
                arg4[1]++;
                if (max[1] < arg4[1]) {
                    arg4[1] = min[1];
                    arg4[0]++;
                    if (max[0] < arg4[0]) {
                        return result ? result : -1;
                    }
                }
            }
        }
    } while (!result);
    return result;
}
