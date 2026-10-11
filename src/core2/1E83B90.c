#include "common.h"

void func_800AA2A0(s16 *arg0, s32 *arg1, f32 *arg2) {
    s32 i;

    if (arg0[9] == 0) {
        arg1[0] = arg1[1] = arg1[2] = 0;
        return;
    }
    for (i = 0; i < 3; i++) {
        if (arg2[i] >= 0.0f) {
            arg1[i] = (s32)arg2[i] / arg0[9];
        } else {
            arg1[i] = (s32)arg2[i] / arg0[9] - 1;
        }
        if (arg1[i] < arg0[i]) {
            arg1[i] = arg0[i];
        }
        if (arg0[i + 3] < arg1[i]) {
            arg1[i] = arg0[i + 3];
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AA3B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AA4D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AA7FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AAAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AAD28.s")

s32 func_800AAD80(u16 *list) {
    typedef struct { u16 vertices[3]; u16 padding; u32 flags; } CollisionTriangle;
    CollisionTriangle *start, *end, *triangle;
    int count;
    count = 0;
    start = (CollisionTriangle *)((u8 *)list + 0x18 + list[8] * 4);
    end = start + list[10];
    for (triangle = start; triangle < end; triangle++) {
        if (triangle->flags & 0x20020) count++;
    }
    return count;
}

u32 func_800AADE4(u16 *arg0) {
    return arg0[10];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AADEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AAEF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AAFEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AB0BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AB868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AB980.s")

void func_800AB9D0(void) {
    s32 heap_free(void *);
    extern void *D_8012798C;
    void *temp_s1;
    void *var_s0;

    var_s0 = D_8012798C;
    if (var_s0 != NULL) {
        do {
            temp_s1 = (*(void **)((s8 *)(var_s0) + (4)));
            heap_free(var_s0);
            var_s0 = temp_s1;
        } while (temp_s1 != NULL);
    }
    D_8012798C = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800ABA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800ABA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800ABB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800ABC0C.s")

void func_800ABC58(f32 start_point[3], f32 end_point[3], f32 margin, f32 min_bounds[3], f32 max_bounds[3]) {
    int i;

    for (i = 0; i < 3; i++) {
        if (start_point[i] < end_point[i]) {
            min_bounds[i] = start_point[i];
            max_bounds[i] = end_point[i];
        } else {
            min_bounds[i] = end_point[i];
            max_bounds[i] = start_point[i];
        }

        min_bounds[i] -= margin;
        max_bounds[i] += margin;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800ABCE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AD1AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AD2C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AD894.s")
