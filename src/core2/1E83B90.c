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

s32 func_800AD894(void *arg0, void *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 arg6) {
    typedef struct { u16 vertex[3]; u16 flags[3]; } Triangle;
    void func_800AA7FC(void *, s32 *, s32 *, u16 ***, u16 ***);
    void *func_800B2190(void *);
    void func_800EE8CC(s32 *, s16 *);
    void func_800EE9EC(f32 *, s32 *, s32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    s32 func_800EED58(s32 *, s32 *);
    void func_800EF2A0(f32 *);
    void func_800EFB58(void *, void *, void *);
    u16 *entry;
    s16 *first_vertex;
    u16 **begin;
    u16 **end;
    u16 **geometry;
    Triangle *triangle;
    Triangle *triangle_end;
    u8 *vertices;
    s32 start[3];
    s32 finish[3];
    s32 minimum[3];
    s32 maximum[3];
    s32 triangle_min[3];
    s32 triangle_max[3];
    s32 points[3][3];
    s32 edge1[3];
    s32 edge2[3];
    s32 i;
    u32 j;
    f32 normal[3];
    s16 *vertex;

    for (i = 0; i < 3; i++) {
        start[i] = arg2[i] - arg5[i];
        finish[i] = arg3[i] - arg5[i];
    }
    for (i = 0; i < 3; i++) {
        if (start[i] < finish[i]) {
            minimum[i] = start[i];
        } else {
            minimum[i] = finish[i];
        }
    }
    for (i = 0; i < 3; i++) {
        if (finish[i] < start[i]) {
            maximum[i] = start[i];
        } else {
            maximum[i] = finish[i];
        }
    }
    func_800AA7FC(arg0, minimum, maximum, &begin, &end);
    vertices = func_800B2190(arg1);
    for (geometry = begin; geometry < end; geometry++) {
        entry = *geometry;
        triangle_end = (triangle = (Triangle *)((u8 *)arg0 + ((u16 *)arg0)[8] * 4 + 24) + entry[0]) + entry[1];
        if (triangle < triangle_end) {
            do {
            first_vertex = (s16 *)(vertices + triangle->vertex[0] * 16);
            triangle_min[0] = triangle_max[0] = first_vertex[0];
            triangle_min[1] = triangle_max[1] = first_vertex[1];
            triangle_min[2] = triangle_max[2] = first_vertex[2];
            func_800EE8CC(points[0], first_vertex);
            for (i = 1; i < 3; i++) {
                first_vertex = (s16 *)(vertices + triangle->vertex[i] * 16);
                j = 0;
                do {
                    if (first_vertex[j] < triangle_min[j]) {
                        triangle_min[j] = first_vertex[j];
                    }
                    if (triangle_max[j] < first_vertex[j]) {
                        triangle_max[j] = first_vertex[j];
                    }
                } while (++j < 3);
                func_800EE8CC(points[i], first_vertex);
            }
            if (triangle_max[0] >= minimum[0] && maximum[0] >= triangle_min[0]
                && triangle_max[1] >= minimum[1] && maximum[1] >= triangle_min[1]
                && triangle_max[2] >= minimum[2] && maximum[2] >= triangle_min[2]) {
                func_800EFB58(edge1, points[1], points[0]);
                func_800EFB58(edge2, points[2], points[0]);
                func_800EE9EC(normal, edge1, edge2);
                func_800EF2A0(normal);
                if (!(normal[1] <= arg6) || !(func_800EEAA4(normal, arg4) > 0.0f)) {
                    if (func_800EED58(finish, points[0]) && func_800EED58(start, points[1])) {
                        return 0;
                    }
                    if (func_800EED58(finish, points[1]) && func_800EED58(start, points[2])) {
                        return 0;
                    }
                    if (func_800EED58(finish, points[2]) && func_800EED58(start, points[0])) {
                        return 0;
                    }
                }
            }
            } while (++triangle < triangle_end);
        }
    }
    return 1;
}
