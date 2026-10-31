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

void func_800AA3B4(void *arg0, void *arg1) {
    void func_800EE88C(f32 *, s16 *);
    extern f32 D_80127938[];
    s32 i;
    s32 j;
    u16 *index;
    f32 *position;
    Vtx *base;
    Vtx *vertex;
    Vtx_t *data;

    if (arg0 != NULL) {
        /* Keep the address expressions and line grouping for IDO scheduling. */
        base = (Vtx *)((u8 *)arg1 + 0x18);
        if (base) {} position = D_80127938; base = (Vtx *)((u8 *)arg1 + 0x18); index = arg0; for (i = 0; i < 3; i++) {
            if ((index && index) && index) {
            }
            vertex = &base[*index];
            func_800EE88C(position, vertex->v.ob);
            index++;
            position += 3;
            data = &vertex->v;
            for (j = 0; j < 4; j++) {
                D_80127938[9 + ((i * 2) * 2) + j] = (f32)data->cn[j];
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AA4D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AA7FC.s")

void func_800AAAE0(u8 *arg0) {
    extern f32 D_80127938[];
    s32 i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            arg0[i * 4 + j] = (u32)D_80127938[i * 4 + j + 9];
        }
    }
}

void func_800AAD28(f32 *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    extern f32 D_80127938[];
    extern f32 D_8012795C[];
    f32 *var_s0;
    f32 *var_s1;
    f32 *end;

    var_s0 = D_80127938; end = D_8012795C;
    var_s1 = arg0;
    do {
        func_800EE7F8(var_s1, var_s0);
        var_s0 += 3;
        var_s1 += 3;
    } while (var_s0 != end);
}

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

s32 func_800AADEC(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void func_800EE97C(f32 *, f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800EEFD4(f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 sqrtf(f32);

    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    f32 temp_f0;
    f32 temp_f2;

    func_800EFB24(sp3C, arg1, arg0);
    temp_f0 = func_800EEFD4(sp3C);
    if (temp_f0 < 0.01f) {
        return func_800EEB40(arg0, arg2) < arg3;
    }
    temp_f2 = 1.0f / sqrtf(temp_f0);
    sp3C[0] *= temp_f2;
    sp3C[1] *= temp_f2;
    sp3C[2] *= temp_f2;
    func_800EFB24(sp30, arg2, arg0);
    func_800EE97C(sp24, sp30, sp3C);
    return func_800EEFD4(sp24) < arg3;
}

/* extern */

s32 func_800AAEF4(f32 *arg0, f32 arg1, f32 *arg2, f32 *arg3) {
    s32 func_800AADEC(f32 *, f32 *, f32 *, f32);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp3C[3];
    f32 temp_f0;
    f32 sp34;
    f32 temp_f20;

    temp_f20 = arg1 * arg1;
    if (func_800AADEC(arg2, arg3, arg0, temp_f20) == 0) {
        return 0;
    }
    func_800EFA4C(sp3C, (arg2[0] + arg3[0]) * 0.5f, (arg2[1] + arg3[1]) * 0.5f, (arg2[2] + arg3[2]) * 0.5f);
    sp34 = func_800EEB40(sp3C, arg0);
    temp_f0 = func_800EEB40(sp3C, arg2);
    if ((temp_f0 + temp_f20 + (2.0f * temp_f20 * temp_f0)) <= sp34) {
        return 0;
    }
    return 1;
}

/* extern */

void func_800AAFEC(f32 *arg0, f32 *arg1, s32 *arg2, s32 *arg3, f32 *arg4) {
    void func_800EFB24(void *, void *, void *);
    int i;

    for (i = 0; i < 3; i++) {
        if (arg0[i] < arg1[i]) {
            arg2[i] = (s32) arg0[i];
            arg3[i] = (s32) arg1[i];
        } else {
            arg2[i] = (s32) arg1[i];
            arg3[i] = (s32) arg0[i];
        }
        arg2[i] -= 1;
        arg3[i] += 1;
    }
    func_800EFB24(arg4, arg1, arg0);
}

void *func_800AB0BC(u16 *list, u16 *vertices, f32 line_start[3], f32 line_end[3], f32 normal[3], u32 flag_filter) {
    typedef struct { u16 vertices[3]; u16 padding; u32 flags; } CollisionTriangle;
    typedef struct { s16 position[3]; s16 padding[5]; } CollisionVertex;
    void func_800AA3B4(void *, void *);
    void func_800AA7FC(void *, s32 *, s32 *, u16 ***, u16 ***);
    void func_800AAFEC(f32 *, f32 *, s32 *, s32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE97C(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    f32 mlAbsF(f32);
    int i;
    u16 **start_geo, **i_geo, **end_geo, *geo;
    s32 min_bounds[3], max_bounds[3];
    f32 direction_vector[3];
    CollisionTriangle *start_tri, *result_collision, *i_tri;
    CollisionVertex *vtx_pool;
    CollisionTriangle *end_tri;
    f32 tri_edge_ab[3], tri_edge_ac[3];
    f32 local_line_start[3], local_line_end[3];
    f32 t;
    f32 line_current_pos[3];
    f32 row1[3], row2[3];
    f32 start_distance, plane_distance, direction_distance, inverse_determinant;
    f32 vtx_radius;
    f32 end_distance, barycentric_a;
    f32 tri_normal[3];
    s32 primary_axis;
    f32 barycentric_b;
    f32 tri[3][3];
    CollisionVertex *vtx0, *vtx1, *vtx2;
    s32 coordinate0, coordinate1, coordinate2;

    result_collision = NULL;
    vtx_radius = vertices[10];
    func_800AAFEC(line_start, line_end, min_bounds, max_bounds, direction_vector);
    for (i = 0; i < 3; i++) {
        if (max_bounds[i] <= -vtx_radius || vtx_radius <= min_bounds[i]) {
            return NULL;
        }
    }
    func_800AA7FC(list, min_bounds, max_bounds, &start_geo, &end_geo);
    i_geo = start_geo;
    if (i_geo < end_geo) {
    t = 100000.0f;
    do {
        start_tri = (CollisionTriangle *)((u8 *)list + list[8] * 4 + 0x18) + (*i_geo)[0];
        end_tri = start_tri + (*i_geo)[1];
        for (i_tri = start_tri; i_tri < end_tri; i_tri++) {
            vtx_pool = (CollisionVertex *)((u8 *)vertices + 0x18);
            if (i_tri->flags & flag_filter) continue;
            vtx0 = &vtx_pool[i_tri->vertices[0]];
            vtx1 = &vtx_pool[i_tri->vertices[1]];
            vtx2 = &vtx_pool[i_tri->vertices[2]];
            coordinate0 = vtx0->position[0];
            coordinate1 = vtx1->position[0];
            coordinate2 = vtx2->position[0];
            if (coordinate0 < min_bounds[0] && coordinate1 < min_bounds[0] && coordinate2 < min_bounds[0]) continue;
            if (coordinate0 > max_bounds[0] && coordinate1 > max_bounds[0] && coordinate2 > max_bounds[0]) continue;
            tri[0][0] = coordinate0;
            tri[1][0] = coordinate1;
            tri[2][0] = coordinate2;
            coordinate0 = vtx0->position[1];
            coordinate1 = vtx1->position[1];
            coordinate2 = vtx2->position[1];
            if (coordinate0 < min_bounds[1] && coordinate1 < min_bounds[1] && coordinate2 < min_bounds[1]) continue;
            if (coordinate0 > max_bounds[1] && coordinate1 > max_bounds[1] && coordinate2 > max_bounds[1]) continue;
            tri[0][1] = coordinate0;
            tri[1][1] = coordinate1;
            tri[2][1] = coordinate2;
            coordinate0 = vtx0->position[2];
            coordinate1 = vtx1->position[2];
            coordinate2 = vtx2->position[2];
            if (coordinate0 < min_bounds[2] && coordinate1 < min_bounds[2] && coordinate2 < min_bounds[2]) continue;
            if (coordinate0 > max_bounds[2] && coordinate1 > max_bounds[2] && coordinate2 > max_bounds[2]) continue;
            tri[0][2] = coordinate0;
            tri[1][2] = coordinate1;
            tri[2][2] = coordinate2;
            func_800EFB24(tri_edge_ab, tri[1], tri[0]);
            func_800EFB24(tri_edge_ac, tri[2], tri[0]);
            func_800EE97C(tri_normal, tri_edge_ab, tri_edge_ac);
            if (t < mlAbsF(tri_normal[0]) || t < mlAbsF(tri_normal[1]) || t < mlAbsF(tri_normal[2])) {
                tri_normal[0] *= 0.00001f;
                tri_normal[1] *= 0.00001f;
                tri_normal[2] *= 0.00001f;
            }
            func_800EFB24(local_line_start, line_start, tri[0]);
            func_800EFB24(local_line_end, line_end, tri[0]);
            start_distance = func_800EEAA4(local_line_start, tri_normal);
            end_distance = func_800EEAA4(local_line_end, tri_normal);
            if (!((start_distance >= 0.0f) && (end_distance >= 0.0f)) && !((start_distance <= 0.0f) && (end_distance <= 0.0f))) {
                if ((i_tri->flags & 0x10000) && start_distance < 0.0f) {
                    tri_normal[0] = -tri_normal[0];
                    tri_normal[1] = -tri_normal[1];
                    tri_normal[2] = -tri_normal[2];
                }
                plane_distance = -func_800EEAA4(tri[0], tri_normal);
                direction_distance = func_800EEAA4(tri_normal, direction_vector);
                if (direction_distance >= 0.0f) continue;
                direction_distance = -(func_800EEAA4(tri_normal, line_start) + plane_distance) / direction_distance;
                if (direction_distance <= 0.0f || direction_distance >= 1.0f) continue;
                func_800EFA4C(line_current_pos, line_start[0] + direction_vector[0] * direction_distance, line_start[1] + direction_vector[1] * direction_distance, line_start[2] + direction_vector[2] * direction_distance);
                primary_axis = mlAbsF(tri_normal[0]) > mlAbsF(tri_normal[1]) ? 0 : 1;
                if (mlAbsF(tri_normal[2]) > mlAbsF(tri_normal[primary_axis])) primary_axis = 2;
                i = (primary_axis + 1) % 3;
                func_800EFA4C(row1, line_current_pos[i] - tri[0][i], tri_edge_ab[i], tri_edge_ac[i]);
                i = (primary_axis + 2) % 3;
                func_800EFA4C(row2, line_current_pos[i] - tri[0][i], tri_edge_ab[i], tri_edge_ac[i]);
                inverse_determinant = 1.0f / (row1[1] * row2[2] - row2[1] * row1[2]);
                barycentric_a = (row1[0] * row2[2] - row2[0] * row1[2]) * inverse_determinant;
                if (barycentric_a < 0.0f || barycentric_a > 1.0f) {
                    continue;
                }
                barycentric_b = (row1[1] * row2[0] - row2[1] * row1[0]) * inverse_determinant;
                if (barycentric_b < 0.0f || barycentric_b > 1.0f || barycentric_a + barycentric_b > 1.0f) {
                    continue;
                }
                result_collision = i_tri;
                func_800EE7F8(line_end, line_current_pos);
                func_800EE7F8(normal, tri_normal);
                func_800AAFEC(line_start, line_end, min_bounds, max_bounds, direction_vector);
            }
        }
    } while (++i_geo < end_geo);
    }
    if (result_collision != NULL) func_800EF2A0(normal);
    func_800AA3B4(result_collision, vertices);
    return result_collision;
}

s32 func_800AB868(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 *arg5, f32 *arg6, f32 *arg7, s32 arg8) {
    void func_80019224(f32 *, f32 *);
    void func_800193C4(f32 *, f32 *);
    void func_80019750(f32 *, f32 *, f32, f32 *);
    void func_8001980C(f32 *, f32 *, f32, f32 *);
    s32 func_80019CD4(void);
    void *func_800AB0BC(u16 *, u16 *, f32 *, f32 *, f32 *, u32);
    extern f32 D_80127938[];
    extern f32 D_8012795C[];
    f32 sp44[3];
    f32 sp38[3];
    s32 sp34;
    f32 *var_s0;
    f32 *end;
    s32 temp_v0;

    func_80019CD4();
    func_8001980C(arg2, arg3, arg4, 0);
    func_800193C4(sp44, arg5);
    func_800193C4(sp38, arg6);
    temp_v0 = func_800AB0BC(arg0, arg1, sp44, sp38, arg7, arg8);
    sp34 = temp_v0;
    if (temp_v0 == 0) {
        return 0;
    }
    func_80019CD4();
    func_80019750(arg2, arg3, arg4, 0);
    func_800193C4(arg6, sp38);
    var_s0 = D_80127938; end = D_8012795C;
    do {
        func_80019224(var_s0, var_s0);
        var_s0 += 3;
    } while (var_s0 != end);
    func_80019CD4();
    func_80019750(NULL, arg3, 1.0f, NULL);
    func_80019224(arg7, arg7);
    return sp34;
}

void func_800AB980(void) {
    extern void *D_8012798C;
    void* heap_alloc(s32 size);
    D_8012798C = heap_alloc(0x484);
    *(s32 *)D_8012798C = 0;
    (*(s32 *)((s8 *)(D_8012798C) + (4))) = 0;
    (*(s32 *)((s8 *)(D_8012798C) + (0xC))) = 0xF;
    (*(s32 *)((s8 *)(D_8012798C) + (8))) = 0x40000000;
}

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

void func_800ABA20(void) {
    void *defrag(void *);
    extern void *D_8012798C;
    void *current;
    void *old;
    void *neighbor;

    current = D_8012798C;
    if (current != NULL) {
        do {
            old = current;
            current = defrag(current);
            if (current != old) {
                neighbor = *(void **)current;
                if (neighbor != NULL) {
                    *(void **)((u8 *)neighbor + 4) = current;
                } else {
                    D_8012798C = current;
                }
                neighbor = *(void **)((u8 *)current + 4);
                if (neighbor != NULL) {
                    *(void **)neighbor = current;
                }
            }
            current = *(void **)((u8 *)current + 4);
        } while (current != NULL);
    }
}

void func_800ABA9C(void) {
    s32 func_8001211C(void);
    s32 heap_free(void *);
    extern void *D_8012798C;
    s32 cutoff;
    void *next;
    void *current;

    cutoff = func_8001211C() - 0x28;
    current = *(void **)((u8 *)D_8012798C + 4);
    while ((current != NULL) && (cutoff < *(s32 *)((u8 *)current + 8))) {
        current = *(void **)((u8 *)current + 4);
    }
    if (current != NULL) {
        *(s32 *)((u8 *)*(void **)current + 4) = 0;
        if (current != NULL) {
            do {
                next = *(void **)((u8 *)current + 4);
                heap_free(current);
                current = next;
            } while (next != NULL);
        }
    }
}

void func_800ABB34(void *arg0, void **arg1) {
    s32 func_8001211C(void);
    void *heap_alloc(s32);
    u8 **cursor = arg0;
    u8 *temp_v1;
    void *var_a0;

    *cursor += 0x4C;
    temp_v1 = *arg1;
    if (((s32) ((*cursor - temp_v1) - 0x10) / 76) >= *(s32 *)(temp_v1 + 0xC)) {
        var_a0 = *(void **)(temp_v1 + 4);
        if (var_a0 == NULL) {
            *(void **)((u8 *)*arg1 + 4) = heap_alloc(0xEE8);
            temp_v1 = *arg1;
            **(void ***)(temp_v1 + 4) = temp_v1;
            *(s32 *)((u8 *)*(void **)((u8 *)*arg1 + 4) + 4) = 0;
            *(s32 *)((u8 *)*(void **)((u8 *)*arg1 + 4) + 0xC) = 0x32;
            var_a0 = *(void **)((u8 *)*arg1 + 4);
        }
        *arg1 = var_a0;
        *(s32 *)((u8 *)*arg1 + 8) = func_8001211C();
        *cursor = (u8 *)*arg1 + 0x10;
    }
}

void func_800ABC0C(u8 **arg0, u8 **arg1) {
    u8 *temp_v0;

    *arg0 += 0x4C;
    temp_v0 = *arg1;
    if (((s32) ((*arg0 - temp_v0) - 0x10) / 76) >= (*(s32 *)((s8 *)(temp_v0) + (0xC)))) {
        *arg1 = (*(u8 **)((s8 *)(temp_v0) + (4)));
        *arg0 = *arg1 + 0x10;
    }
}

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
    void func_800ABB34(void *, void **);
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

void *func_800AC100(void *end, f32 position[3], f32 radius, f32 normal[3]) {
    typedef struct {
        f32 edgeAB[3];
        f32 edgeAC[3];
        f32 normal[3];
        s32 flags;
        f32 vertex[3][3];
    } Triangle;
    void func_800ABC0C(u8 **arg0, u8 **arg1);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 func_800EEFD4(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFD24(f32 *);
    f32 mlAbsF(f32);
    extern void *D_8012798C;
    int i;
    u8 *block;
    union { u8 *cursor; Triangle *tri; } current;
    f32 edges[3][3];
    f32 deltas[3][3];
    f32 determinant;
    f32 edge_length;
    f32 beta;
    f32 alpha;
    f32 theta;
    f32 projection;
    f32 row1[3];
    f32 row2[3];
    u32 first_axis;
    s32 second_axis;
    s32 axis;
    f32 projected[3];
    Triangle *collision;
    f32 *plane_normal;

    collision = NULL;
    func_800EFD24(normal);
    /* IDO assigns the cutoff spill slot after first seeing radius squared. */
    edge_length = radius * radius;
    block = D_8012798C;
    for (current.cursor = block + 0x10; current.cursor != end; func_800ABC0C(&current.cursor, &block)) {
        func_800EFB24(deltas[0], position, current.tri->vertex[0]);
        plane_normal = current.tri->normal;
        theta = func_800EEAA4(deltas[0], plane_normal);
        if ((radius - 0.5f) <= mlAbsF(theta)) {
            continue;
        }
        projected[0] = position[0] - current.tri->normal[0] * theta;
        projected[1] = position[1] - current.tri->normal[1] * theta;
        projected[2] = position[2] - current.tri->normal[2] * theta;
        axis = mlAbsF(current.tri->normal[0]) > mlAbsF(current.tri->normal[1]) ? 0 : 1;
        if (mlAbsF(current.tri->normal[2]) > mlAbsF(current.tri->normal[axis])) {
            axis = 2;
        }
        first_axis = (axis + 1) % 3;
        func_800EFA4C(row1, projected[first_axis] - current.tri->vertex[0][first_axis], current.tri->edgeAB[first_axis], current.tri->edgeAC[first_axis]);
        second_axis = (axis + 2) % 3;
        func_800EFA4C(row2, projected[second_axis] - current.tri->vertex[0][second_axis], current.tri->edgeAB[second_axis], current.tri->edgeAC[second_axis]);
        determinant = row1[1] * row2[2] - row2[1] * row1[2];
        if (determinant == 0.0f) {
            continue;
        }
        determinant = 1.0f / determinant;
        alpha = (row1[0] * row2[2] - row2[0] * row1[2]) * determinant;
        beta = (row1[1] * row2[0] - row2[1] * row1[0]) * determinant;
        if (0.0f <= alpha && alpha <= 1.0f && 0.0f <= beta && beta <= 1.0f && alpha + beta <= 1.0f) {
            collision = current.tri;
            func_800EF04C(normal, current.tri->normal);
            continue;
        }
        for (i = 0; i < 3; i++) {
            func_800EFB24(deltas[i], position, current.tri->vertex[i]);
            if (func_800EEFD4(deltas[i]) < radius * radius) {
                collision = current.tri;
                func_800EF04C(normal, current.tri->normal);
                break;
            }
        }
        if (i < 3) {
            continue;
        }
        for (i = 0; i < 3; i++) {
            func_800EFB24(edges[i], current.tri->vertex[(i + 1) % 3], current.tri->vertex[i]);
            edge_length = func_800EEFD4(edges[i]);
            func_800EF2A0(edges[i]);
            projection = func_800EEAA4(edges[i], deltas[i]);
            if (0 <= projection && projection * projection <= edge_length) {
                projected[0] = deltas[i][0] - edges[i][0] * projection;
                projected[1] = deltas[i][1] - edges[i][1] * projection;
                projected[2] = deltas[i][2] - edges[i][2] * projection;
                if (func_800EEFD4(projected) < radius * radius) {
                    collision = current.tri;
                    func_800EF04C(normal, current.tri->normal);
                    break;
                }
            }
        }
    }
    return collision;
}

s32 func_800AC638(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 *arg5, s32 arg6, s32 arg7) {
    typedef struct {
        f32 edgeAB[3];
        f32 edgeAC[3];
        f32 normal[3];
        void *triangle;
        f32 point[3][3];
    } ProcessedTriangle;
    void func_800AA3B4(void *, void *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFB24(void *, void *, void *);
    void *end_ptr;
    f32 distance[3];
    f32 current, start, end;
    s32 i;
    f32 current_pos[3];
    f32 temp_normal[3];
    ProcessedTriangle *coll_tri, *cur_coll_tri;
    f32 velocity[3];

    func_800EFB24(velocity, arg3, arg2);
    if (!func_800ABCE0((void *)arg0, (void *)arg1, arg2, arg3, velocity, arg4 + 0.5f, arg7, &end_ptr)) {
        return 0;
    }
    coll_tri = func_800AC100(end_ptr, arg3, arg4, temp_normal);
    if (!coll_tri) {
        return 0;
    }
    func_800EE7F8(arg5, temp_normal);
    func_800EFB24(distance, arg3, arg2);
    func_800EE7F8(arg3, arg2);
    start = 0.0f;
    end = 1.0f;
    for (i = 0; i < arg6; i++) {
        current = (start + end) * 0.5f;
        current_pos[0] = arg2[0] + current * distance[0];
        current_pos[1] = arg2[1] + current * distance[1];
        current_pos[2] = arg2[2] + current * distance[2];
        cur_coll_tri = func_800AC100(end_ptr, current_pos, arg4, temp_normal);
        if (cur_coll_tri) {
            end = current;
            coll_tri = cur_coll_tri;
            func_800EE7F8(arg5, temp_normal);
        } else {
            start = current;
            func_800EE7F8(arg3, current_pos);
        }
    }
    if (!coll_tri) {
        return 0;
    }
    func_800EF2A0(arg5);
    func_800AA3B4(coll_tri->triangle, (void *)arg1);
    return (s32)coll_tri->triangle;
}

s32 func_800AC848(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 *arg5, f32 *arg6, f32 arg7, f32 *arg8, s32 arg9, s32 arg10) {
    void func_80019224(f32 *, f32 *);
    void func_80019750(f32 *, f32 *, f32, f32 *);
    void func_8001980C(f32 *, f32 *, f32, f32 *);
    s32 func_80019CD4(void);
    s32 func_800AC638(s32, s32, f32 *, f32 *, f32, f32 *, s32, s32);
    extern f32 D_80127938[];
    extern f32 D_8012795C[];
    f32 sp4C[3];
    f32 sp40[3];
    f32 *var_s0;
    s32 sp38;
    f32 *end;
    s32 temp_v0;

    func_80019CD4();
    func_8001980C(arg2, arg3, arg4, 0);
    func_80019224(sp4C, arg5);
    func_80019224(sp40, arg6);
    temp_v0 = func_800AC638(arg0, arg1, sp4C, sp40, arg7 / arg4, arg8, arg9, arg10);
    sp38 = temp_v0;
    if (temp_v0 == 0) {
        return 0;
    }
    func_80019CD4();
    func_80019750(arg2, arg3, arg4, 0);
    func_80019224(arg6, sp40);
    var_s0 = D_80127938; end = D_8012795C;
    do {
        func_80019224(var_s0, var_s0);
        var_s0 += 3;
    } while (var_s0 != end);
    func_80019CD4();
    func_80019750(0, arg3, 1.0f, 0);
    func_80019224(arg8, arg8);
    return sp38;
}

void *func_800AC978(u16 *list, u16 *vertices, f32 position[3], f32 radius, f32 normal[3], u32 flag_filter)
{
  typedef struct 
  {
    u16 vertices[3];
    u16 padding;
    u32 flags;
  } CollisionTriangle;
  typedef struct 
  {
    u16 start_tri_index;
    u16 tri_count;
  } CollisionGeometry;
  void func_800AA3B4(void *, void *);
  void func_800AA4D4();
  void func_800EE7F8(f32 *, f32 *);
  void func_800EE88C(f32 *, s16 *);
  void func_800EE97C(f32 *, f32 *, f32 *);
  f32 func_800EEAA4(f32 *, f32 *);
  f32 func_800EEFD4(f32 *);
  void func_800EF04C(f32 *, f32 *);
  void func_800EF2A0(f32 *);
  void func_800EF410(f32 *, f32 *);
  void func_800EFA4C(f32 *, f32, f32, f32);
  void func_800EFB24(void *, void *, void *);
  void func_800EFD24(f32 *);
  f32 mlAbsF(f32);
  CollisionGeometry **start_geo;
  CollisionGeometry **i_geo;
  CollisionGeometry **end_geo;
  int i;
  f32 min[3];
  f32 max[3];
  f32 vtx_radius;
  f32 sum[3];
  CollisionTriangle *matched_tri;
  s32 primary_axis;
  int j;
  CollisionTriangle *start_tri;
  CollisionTriangle *i_tri;
  CollisionTriangle *end_tri;
  s16 (*vtx_pool)[8];
  s16 *i_vtx;
  CollisionGeometry *temp_geo;
  f32 tri_edge[3][3];
  f32 delta[3][3];
  f32 length_sq;
  f32 radius_sq;
  f32 distance;
  f32 tri_normal[3];
  f32 row_x[3];
  f32 row_y[3];
  register f32 u;
  register f32 reciprocal;
  register f32 v;
  f32 min_coord[3];
  f32 max_coord[3];
  f32 projected_position[3];
  f32 tri_vtx_coord[3][3];
  f32 plane_distance;
  f32 edge_projection;
  for (i = 0; i < 3; i++)
  {
    min[i] = position[i] - (radius + 0.5f);
    max[i] = position[i] + (radius + 0.5f);
  }

  vtx_radius = (u32) vertices[10];
  for (i = 0; i < 3; i++)
  {
    if ((max[i] <= (-vtx_radius)) || (min[i] >= vtx_radius))
    {
      return NULL;
    }
  }

  matched_tri = NULL;
  func_800EFD24(sum);
  func_800AA4D4(list, min, max, &start_geo, &end_geo);
  for (i_geo = start_geo; i_geo < end_geo; i_geo++)
  {
    start_tri = ((CollisionTriangle *) ((((u8 *) list) + (list[8] * 4)) + 0x18)) + (*i_geo)->start_tri_index;
    end_tri = start_tri + (*i_geo)->tri_count;
    for (i_tri = start_tri; i_tri < end_tri; i_tri++)
    {
      if (i_tri->flags & flag_filter)
      {
        continue;
      }
      {
        vtx_pool = (s16 (*)[8]) (((u8 *) vertices) + 0x18);
        for (i = 0; i < 3; i++)
        {
          i_vtx = (s16 *) ((i_tri->vertices[i] * 0x10) + ((u8 *) vtx_pool));
          func_800EE88C(tri_vtx_coord[i], i_vtx);
        }

        func_800EE7F8(min_coord, tri_vtx_coord[0]);
        func_800EE7F8(max_coord, tri_vtx_coord[0]);
        for (i = 1; i < 3; i++)
        {
          for (j = 0; j < 3; j++)
          {
            if (tri_vtx_coord[i][j] < min_coord[j])
            {
              min_coord[j] = tri_vtx_coord[i][j];
            }
            if (max_coord[j] < tri_vtx_coord[i][j])
            {
              max_coord[j] = tri_vtx_coord[i][j];
            }
          }

        }

        if ((max[0] < min_coord[0]) || (max_coord[0] < min[0]))
        {
          continue;
        }
        if ((max[1] < min_coord[1]) || (max_coord[1] < min[1]))
        {
          continue;
        }
        if ((max[2] < min_coord[2]) || (max_coord[2] < min[2]))
        {
          continue;
        }
        func_800EFB24(tri_edge[0], tri_vtx_coord[1], tri_vtx_coord[0]);
        func_800EFB24(tri_edge[1], tri_vtx_coord[2], tri_vtx_coord[0]);
        func_800EE97C(tri_normal, tri_edge[0], tri_edge[1]);
        func_800EF2A0(tri_normal);
        if (((tri_normal[0] == 0) && (tri_normal[1] == 0)) && (tri_normal[2] == 0))
        {
          continue;
        }
        distance = radius - 0.5f;
        func_800EFB24(delta[0], position, tri_vtx_coord[0]);
        if ((i_tri->flags & 0x10000) && (func_800EEAA4(delta[0], tri_normal) < 0.0f))
        {
          tri_normal[0] = -tri_normal[0];
          tri_normal[1] = -tri_normal[1];
          tri_normal[2] = -tri_normal[2];
        }
        plane_distance = func_800EEAA4(delta[0], tri_normal);
        if (mlAbsF(plane_distance) >= distance)
        {
          continue;
        }
        projected_position[0] = position[0] - (tri_normal[0] * plane_distance);
        projected_position[1] = position[1] - (tri_normal[1] * plane_distance);
        projected_position[2] = position[2] - (tri_normal[2] * plane_distance);
        primary_axis = (mlAbsF(tri_normal[0]) > mlAbsF(tri_normal[1])) ? (0) : (1);
        primary_axis = (mlAbsF(tri_normal[2]) > mlAbsF(tri_normal[primary_axis])) ? (2) : (primary_axis);
        func_800EFA4C(row_x, projected_position[(primary_axis + 1) % 3] - tri_vtx_coord[0][(primary_axis + 1) % 3], tri_edge[0][(primary_axis + 1) % 3], tri_edge[1][(primary_axis + 1) % 3]);
        func_800EFA4C(row_y, projected_position[(primary_axis + 2) % 3] - tri_vtx_coord[0][(primary_axis + 2) % 3], tri_edge[0][(primary_axis + 2) % 3], tri_edge[1][(primary_axis + 2) % 3]);
        reciprocal = 1.0f / ((row_x[1] * row_y[2]) - (row_y[1] * row_x[2]));
        u = ((row_x[0] * row_y[2]) - (row_y[0] * row_x[2])) * reciprocal;
        if ((u >= 0.0f) && (u <= 1.0f))
        {
          edge_projection = ((row_x[1] * row_y[0]) - (row_y[1] * row_x[0])) * reciprocal;
          if (((edge_projection >= 0.0f) && (edge_projection <= 1.0f)) && ((u + edge_projection) <= 1.0f))
          {
            matched_tri = i_tri;
            func_800EF04C(sum, tri_normal);
            continue;
          }
        }
        radius_sq = radius * radius;
        for (i = 0; i < 3; i++)
        {
          func_800EFB24(delta[i], position, tri_vtx_coord[i]);
          if (func_800EEFD4(delta[i]) < radius_sq)
          {
            matched_tri = i_tri;
            func_800EF04C(sum, tri_normal);
            break;
          }
        }

        if (i < 3)
        {
          continue;
        }
        for (i = 0; i < 3; i++)
        {
          func_800EFB24(tri_edge[i], tri_vtx_coord[(i + 1) % 3], tri_vtx_coord[i]);
          length_sq = func_800EEFD4(tri_edge[i]);
          func_800EF2A0(tri_edge[i]);
          edge_projection = func_800EEAA4(tri_edge[i], delta[i]);
          if ((edge_projection >= 0) && ((edge_projection * edge_projection) <= length_sq))
          {
            if (1)
            {
              projected_position[0] = delta[i][0] - (tri_edge[i][0] * edge_projection);
              projected_position[1] = delta[i][1] - (tri_edge[i][1] * edge_projection);
            }
            projected_position[2] = delta[i][2] - (tri_edge[i][2] * edge_projection);
            if (func_800EEFD4(projected_position) < radius_sq)
            {
              matched_tri = i_tri;
              func_800EF04C(sum, tri_normal);
              break;
            }
          }
        }

      }
    }

  }

  if (matched_tri != NULL)
  {
    func_800EF410(normal, sum);
  }
  func_800AA3B4(matched_tri, vertices);
  return matched_tri;
}

void *func_800AD1AC(u16 *arg0, u16 *arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 *arg5, f32 arg6, f32 *arg7, u32 arg8) {
    void func_80019224(f32 *, f32 *);
    void func_80019750(f32 *, f32 *, f32, f32 *);
    void func_8001980C(f32 *, f32 *, f32, f32 *);
    s32 func_80019CD4(void);
    extern f32 D_80127938[];
    extern f32 D_8012795C[];
    f32 sp3C[3];
    f32 *var_s0;
    void *sp34;
    f32 *end;
    void *temp_v0;

    func_80019CD4();
    func_8001980C(arg2, arg3, arg4, 0);
    func_80019224(sp3C, arg5);
    temp_v0 = func_800AC978(arg0, arg1, sp3C, arg6 / arg4, arg7, arg8);
    sp34 = temp_v0;
    if (temp_v0 == NULL) {
        return NULL;
    }
    func_80019CD4();
    func_80019750(arg2, arg3, arg4, 0);
    func_80019224(arg5, sp3C);
    var_s0 = D_80127938; end = D_8012795C;
    do {
        func_80019224(var_s0, var_s0);
        var_s0 += 3;
    } while (var_s0 != end);
    func_80019CD4();
    func_80019750(0, arg3, 1.0f, 0);
    func_80019224(arg7, arg7);
    return sp34;
}

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
