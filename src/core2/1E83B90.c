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

s32 func_800ABCE0(void *arg0, void *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 arg5, u32 arg6, void **arg7) {
    typedef struct { u16 start; u16 count; } Geometry;
    typedef struct { u16 vertex[3]; u16 pad; u32 flags; } Triangle;
    typedef struct { s16 point[3]; u8 pad[10]; } Vertex;
    typedef struct {
        f32 edgeAB[3];
        f32 edgeAC[3];
        f32 normal[3];
        Triangle *triangle;
        f32 point[3][3];
    } ProcessedTriangle;
    void func_800AA4D4(void *, f32 *, f32 *, Geometry ***, Geometry ***);
    void func_800ABB34(ProcessedTriangle **, void **);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE88C(f32 *, s16 *);
    void func_800EE97C(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFB24(void *, void *, void *);
    extern void *D_8012798C;
    Geometry **start_geo, **i_geo, **end_geo;
    f32 delta[3];
    Triangle *start_tri;
    Triangle *end_tri;
    f32 min_bounds[3], max_bounds[3];
    Triangle *i_tri;
    Vertex *vertex_pool;
    Vertex *i_vtx;
    s32 i, j;
    f32 tri_min_coord[3];
    f32 tri_max_coord[3];
    f32 vtx_radius;
    void *buffer;
    ProcessedTriangle *cur_processed_tri;

    func_800ABC58(arg2, arg3, arg5, min_bounds, max_bounds);
    vtx_radius = (u32)*(u16 *)((u8 *)arg1 + 0x14);
    for (i = 0; i < 3; i++) {
        if ((max_bounds[i] <= -vtx_radius) || (min_bounds[i] >= vtx_radius)) {
            return 0;
        }
    }
    func_800AA4D4(arg0, min_bounds, max_bounds, &start_geo, &end_geo);
    vertex_pool = (Vertex *)((u8 *)arg1 + 0x18);
    buffer = D_8012798C;
    cur_processed_tri = (ProcessedTriangle *)((u8 *)D_8012798C + 0x10);
    for (i_geo = start_geo; i_geo < end_geo; i_geo++) {
        start_tri = (Triangle *)((Geometry *)((u8 *)arg0 + 0x18) + *(u16 *)((u8 *)arg0 + 0x10)) + (*i_geo)->start;
        end_tri = start_tri + (*i_geo)->count;
        for (i_tri = start_tri; i_tri < end_tri; i_tri++) {
            if (!(i_tri->flags & arg6)) {
                for (i = 0; i < 3; i++) {
                    i_vtx = vertex_pool + i_tri->vertex[i];
                    func_800EE88C(cur_processed_tri->point[i], i_vtx->point);
                }
                func_800EE7F8(tri_min_coord, cur_processed_tri->point[0]);
                func_800EE7F8(tri_max_coord, cur_processed_tri->point[0]);
                for (i = 1; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        if (tri_min_coord[j] > cur_processed_tri->point[i][j]) {
                            tri_min_coord[j] = cur_processed_tri->point[i][j];
                        }
                        if (tri_max_coord[j] < cur_processed_tri->point[i][j]) {
                            tri_max_coord[j] = cur_processed_tri->point[i][j];
                        }
                    }
                }
                if ((tri_min_coord[0] > max_bounds[0]) || (tri_max_coord[0] < min_bounds[0])) continue;
                if ((tri_min_coord[1] > max_bounds[1]) || (tri_max_coord[1] < min_bounds[1])) continue;
                if ((tri_min_coord[2] > max_bounds[2]) || (tri_max_coord[2] < min_bounds[2])) continue;
                func_800EFB24(cur_processed_tri->edgeAB, cur_processed_tri->point[1], cur_processed_tri->point[0]);
                func_800EFB24(cur_processed_tri->edgeAC, cur_processed_tri->point[2], cur_processed_tri->point[0]);
                func_800EE97C(cur_processed_tri->normal, cur_processed_tri->edgeAB, cur_processed_tri->edgeAC);
                func_800EF2A0(cur_processed_tri->normal);
                if (i_tri->flags & 0x10000) {
                    func_800EFB24(delta, arg2, cur_processed_tri->point[0]);
                    if (func_800EEAA4(delta, cur_processed_tri->normal) < 0.0f) {
                        cur_processed_tri->normal[0] = -cur_processed_tri->normal[0];
                        cur_processed_tri->normal[1] = -cur_processed_tri->normal[1];
                        cur_processed_tri->normal[2] = -cur_processed_tri->normal[2];
                    }
                }
                if (func_800EEAA4(cur_processed_tri->normal, arg4) > 0.0f) continue;
                cur_processed_tri->triangle = i_tri;
                func_800ABB34(&cur_processed_tri, &buffer);
            }
        }
    }
    *arg7 = cur_processed_tri;
    return cur_processed_tri != (ProcessedTriangle *)((u8 *)D_8012798C + 0x10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AD1AC.s")

s32 func_800AD2C8(void *arg0, void *arg1, f32 *arg2, f32 *arg3, f32 *arg4, s16 (**arg5)[3], s32 arg6, f32 arg7) {
    typedef struct { u16 vertex[3]; u16 pad; u32 flags; } Triangle;
    typedef struct { s16 point[3][3]; s16 pad; } CachedTriangle;
    typedef struct { CachedTriangle triangles[64]; CachedTriangle *end; } TriangleCache;
    void func_800AA7FC(void *, s32 *, s32 *, u16 ***, u16 ***);
    void *func_800B2190(void *);
    void func_800EE8CC(s32 *, s16 *);
    void func_800EE9EC(f32 *, s32 *, s32 *);
    void func_800EF2A0(f32 *);
    void func_800EFB58(void *, void *, void *);
    extern TriangleCache D_80127990;
    s32 i;
    s32 j;
    s32 count = 0;
    u16 **begin;
    u16 **end;
    u16 **geometry;
    u8 *vertices;
    Triangle *triangle_end;
    Triangle *triangle;
    s32 start[3];
    s32 finish[3];
    s32 offset[3];
    s32 minimum[3];
    s32 maximum[3];
    s32 points[3][3];
    s32 edge1[3];
    s32 edge2[3];
    register s16 *vertex;
    register Triangle *first;
    register CachedTriangle *cached;
    f32 normal[3];

    for (i = 0; i < 3; i++) {
        start[i] = arg2[i] - arg4[i];
        finish[i] = arg3[i] - arg4[i];
        offset[i] = arg4[i];
    }
    func_800AA7FC(arg0, start, finish, &begin, &end);
    vertices = func_800B2190(arg1);
    D_80127990.end = D_80127990.triangles;
    for (geometry = begin; geometry < end; geometry++) {
        first = (Triangle *)((u8 *)arg0 + ((u16 *)arg0)[8] * 4 + 0x18) + (*geometry)[0];
        triangle_end = first + (*geometry)[1];
        for (triangle = first; count < arg6 && triangle < triangle_end; triangle++) {
            if (triangle->flags & 0x20020) {
                continue;
            }
            vertex = (s16 *)(vertices + triangle->vertex[0] * 16);
            minimum[0] = maximum[0] = vertex[0];
            minimum[1] = maximum[1] = vertex[1];
            minimum[2] = maximum[2] = vertex[2];
            func_800EE8CC(points[0], vertex);
            for (i = 1; i < 3; i++) {
                vertex = (s16 *)(vertices + triangle->vertex[i] * 16);
                for (j = 0; j < 3; j++) {
                    if (vertex[j] < minimum[j]) {
                        minimum[j] = vertex[j];
                    }
                    if (maximum[j] < vertex[j]) {
                        maximum[j] = vertex[j];
                    }
                }
                func_800EE8CC(points[i], vertex);
            }
            if (maximum[0] < start[0] || finish[0] < minimum[0]) {
                continue;
            }
            if (maximum[1] < start[1] || finish[1] < minimum[1]) {
                continue;
            }
            if (maximum[2] < start[2] || finish[2] < minimum[2]) {
                continue;
            }
            for (cached = D_80127990.triangles; cached < D_80127990.end; cached++) {
                if (points[0][0] == cached->point[0][0] &&
                    points[0][1] == cached->point[0][1] &&
                    points[0][2] == cached->point[0][2] &&
                    points[1][0] == cached->point[1][0] &&
                    points[1][1] == cached->point[1][1] &&
                    points[1][2] == cached->point[1][2] &&
                    points[2][0] == cached->point[2][0] &&
                    points[2][1] == cached->point[2][1] &&
                    points[2][2] == cached->point[2][2]) {
                    break;
                }
            }
            if (cached != D_80127990.end) {
                continue;
            }
            func_800EFB58(edge1, points[1], points[0]);
            func_800EFB58(edge2, points[2], points[0]);
            func_800EE9EC(normal, edge1, edge2);
            if (normal[1] <= 0.0f) {
                continue;
            }
            func_800EF2A0(normal);
            if (normal[1] < arg7) {
                continue;
            }
            if (D_80127990.end - D_80127990.triangles < 64) {
                D_80127990.end->point[0][0] = points[0][0];
                D_80127990.end->point[0][1] = points[0][1];
                D_80127990.end->point[0][2] = points[0][2];
                D_80127990.end->point[1][0] = points[1][0];
                D_80127990.end->point[1][1] = points[1][1];
                D_80127990.end->point[1][2] = points[1][2];
                D_80127990.end->point[2][0] = points[2][0];
                D_80127990.end->point[2][1] = points[2][1];
                D_80127990.end->point[2][2] = points[2][2];
                D_80127990.end++;
            }
            if (count < arg6) {
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        (*arg5)[i][j] = points[i][j] + offset[j];
                    }
                }
                *arg5 += 3;
                count++;
            }
        }
    }
    return count;
}

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
