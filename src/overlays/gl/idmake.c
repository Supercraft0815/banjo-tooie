#include "common.h"

s32 func_80800000_glidmake(s32 arg0) {
    int func_800EEEA8(f32 vec[3]);
    s32 var_v1;
    f32 *vec;

    vec = (f32 *) (arg0 + 8);
    arg0 = (s32) vec;
    if (func_800EEEA8(vec) != 0) {
        var_v1 = 0;
    } else {
        var_v1 = (s32) vec;
    }
    return var_v1;
}

void glidmake_entrypoint_0(void *model, s32 mesh_id, s16 dst[3]) {
    void glidmake_entrypoint_2(void *, s32, s16 *, s16 *);
    s16 min[3];
    s16 max[3];
    glidmake_entrypoint_2(model, mesh_id, min, max);
    dst[0] = (min[0] + max[0]) / 2;
    dst[1] = (min[1] + max[1]) / 2;
    dst[2] = (min[2] + max[2]) / 2;
}

/* extern */

void glidmake_entrypoint_1(s32 *arg0) {
    s32 func_800B274C(s32);
    s32 func_800D674C(s32);
    func_800B274C(func_800D674C(*arg0));
}

void glidmake_entrypoint_2(void *arg0, s32 arg1, s16 *arg2, s16 *arg3) {
    void *_dbid_entrypoint_2(s32, s32);
    void *func_800B2190(void *);
    s32 func_800B274C(s32);
    s32 func_800D674C(s32);
    void func_800EFD4C(s16 *);
    void func_800EF0B4(s16 *, f32 *);
    u32 index;
    u32 end;
    s16 *mesh;
    u8 *vertices;
    s16 *vertex;
    s32 i;
    f32 *scale;
    s32 asset;

    func_800EFD4C(arg2);
    func_800EFD4C(arg3);
    asset = func_800D674C(*(s32 *)arg0);
    mesh = _dbid_entrypoint_2(func_800B274C(asset), arg1);
    if (mesh != NULL) {
        vertices = func_800B2190(*(void **)((u8 *)arg0 + 0x14));
        index = (u32)mesh + 4;
        end = (u32)mesh + mesh[1] * 2 + 4;
        for (; index < end; index += 2) {
            vertex = (s16 *)(vertices + *(s16 *)index * 0x10);
            for (i = 0; i < 3; i++) {
                if (mesh == (s16 *)(index - 4)) {
                    arg2[i] = arg3[i] = vertex[i];
                } else {
                    arg2[i] = vertex[i] < arg2[i] ? vertex[i] : arg2[i];
                    arg3[i] = arg3[i] < vertex[i] ? vertex[i] : arg3[i];
                }
            }
        }
        scale = (f32 *)func_80800000_glidmake((s32)arg0);
        if (scale != NULL) {
            func_800EF0B4(arg2, scale);
            func_800EF0B4(arg3, scale);
        }
    }
}

/* extern */

s16 glidmake_entrypoint_3(s32 *arg0, s32 arg1) {
    void *_dbid_entrypoint_2(s32, s32);
    s32 func_800B274C(s32);
    s32 func_800D674C(s32);
    s16 var_v1;
    void *temp_v0;

    temp_v0 = _dbid_entrypoint_2(func_800B274C(func_800D674C(*arg0)), arg1);
    if (temp_v0 != NULL) {
        var_v1 = (*(s16 *)((s8 *)(temp_v0) + (2)));
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void glidmake_entrypoint_4(void* arg0) 
{
    heap_free(arg0);
}
void *glidmake_entrypoint_5(s32 arg0, f32 *arg1) {
    s32 func_800D674C(s32);
    s32 func_800B274C(s32);
    s32 func_800B2840(s32);
    s16 _dbid_entrypoint_0(s16 *, s16);
    s32 _dbid_entrypoint_1(s16 *);
    void aligned4_memcpy(void *, void *, int);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    s16 *data;
    s16 *loaded;
    u8 *result;
    s32 count;
    s32 total;
    s32 next;
    s32 unused;
    s32 i;
    s16 *first;
    s16 *cursor;
    s16 *indices;
    s32 run;
    s32 start;
    s32 model;
    u8 *vertices;
    s32 size;
    s32 j;
    u8 *ranges;
    u8 *dest;
    u8 *entry;

    model = func_800D674C(arg0);
    data = (s16 *)func_800B274C(model);
    if (data == NULL) {
        return NULL;
    }
    vertices = (u8 *)func_800B2840(model);
    total = _dbid_entrypoint_1(data);
    count = data[0];
    size = total * 16 + count * 8 + 28;
    first = data + 1;
    cursor = first;
    i = 0;
    if (data[0] > 0) {
        do {
            size += _dbid_entrypoint_0(data, cursor[0]) * 4;
            cursor += cursor[1];
            cursor += 2;
            i++;
        } while (i < data[0]);
        cursor = first;
        i = 0;
    }
    result = heap_alloc(size);
    *(s32 *)(result + 0) = arg0;
    *(s32 *)(result + 4) = data[0];
    if (arg1 != NULL) {
        func_800EE7F8((f32 *)(result + 8), arg1);
    } else {
        func_800EFD24((f32 *)(result + 8));
    }
    *(u8 **)(result + 20) = vertices;
    *(s32 *)(result + 24) = 0;
    entry = result + 28;
    if (data[0] > 0) {
        do {
            run = 1;
            *(s16 *)entry = cursor[0];
            *(s16 *)(entry + 2) = _dbid_entrypoint_0(data, cursor[0]);
            j = 1;
            start = cursor[2];
            ranges = entry + 8;
            dest = *(s16 *)(entry + 2) * 4 + entry + 8;
            aligned4_memcpy(dest, start * 16 + vertices + 24, 16);
            dest += 16;
            indices = cursor + 1;
            if (cursor[1] >= 2) {
                do {
                    if (indices[2] != indices[1] + 1) {
                        *(s16 *)ranges = start;
                        *(s16 *)(ranges + 2) = run;
                        run = 0;
                        ranges += 4;
                        start = indices[2];
                    }
                    aligned4_memcpy(dest, indices[2] * 16 + vertices + 24, 16);
                    j++;
                    indices++;
                    dest += 16;
                    run++;
                } while (j < cursor[1]);
            }
            *(s16 *)ranges = start;
            *(s16 *)(ranges + 2) = run;
            *(s32 *)(entry + 4) = dest - entry;
            i++;
            cursor += cursor[1];
            cursor += 2;
            entry = dest;
        } while (i < data[0]);
    }
    return result;
}
