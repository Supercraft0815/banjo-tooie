#ifdef BT_NATIVE
#include "native_world_collision.h"
#include "native_cube.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

void gccubeDll_entrypoint_0(NativeWorldGrid *grid) {
    s32 i, capacity = 0, count = 0;
    Prop **props;
    for (i = 0; i < grid->count; ++i) capacity += grid->cells[i].models[1];
    props = heap_alloc(capacity * sizeof(*props));
    for (i = 0; i < grid->count; ++i) _gspropsDll_entrypoint_0(grid->cells + i, props, &count);
    _gspropsDll_entrypoint_1(props, count);
    heap_free(props);
}

static u32 native_cube_word(const u8 *bytes, s32 width) {
    u32 result = 0;
    while (width--) result = (result << 8) | *bytes++;
    return result;
}

static void native_cube_records(GsFile *file, s32 count, int models, s32 skip, s32 tag) {
    s32 i, j, width = models ? 20 : 12;
    s32 allocated;
    u8 *data, *record, *current;
    if (!file || file->failed) return;
    if (tag >= 0 && !gsmaker_entrypoint_16(file, tag)) {
        if (count) file->failed = 1;
        return;
    }
    current = file->mode == 2 ? file->asset_current_ptr : file->current_ptr;
    if (count < 0 || count > INT32_MAX / width || file->mode < 2 || file->mode > 3 ||
        (count && (!current || count > (file->end_ptr - current) / width))) {
        file->failed = 1;
        return;
    }
    if (!skip) {
        allocated = models ? native_world_grid.fallback.models[1] : native_world_grid.fallback.dynamic[1];
        for (i = 0; i < native_world_grid.count; ++i)
            allocated += models ? native_world_grid.cells[i].models[1] : native_world_grid.cells[i].dynamic[1];
        if (count > INT16_MAX - 1 - allocated) { file->failed = 1; return; }
    }
    data = heap_alloc(count * width);
    gsmaker_entrypoint_13(file, data, count * width);
    for (i = 0; i < count && !skip && !file->failed; ++i) {
        record = data + i * width;
        if (models) {
            Prop prop = {0};
            NativeWorldCell *cell;
            s32 position[3];
            for (j = 0; j < 3; ++j) position[j] = prop.position[j] = native_cube_word(record + j * 2, 2);
            prop.flags6 = native_cube_word(record + 6, 2);
            prop.ItemID = native_cube_word(record + 8, 2);
            prop.unkA = native_cube_word(record + 10, 2);
            prop.flagsC = native_cube_word(record + 12, 4);
            prop.unk10 = native_cube_word(record + 16, 2);
            prop.unk12 = native_cube_word(record + 18, 2);
            cell = func_800BDBC4(position);
            if (func_808004E0_gspropsDll(&prop) && *func_800BE5C4(cell) == UINT8_MAX) {
                file->failed = 1;
                break;
            }
            _gspropsDll_entrypoint_3(&prop);
        } else {
            NativeMarkerProp prop = {0};
            prop.sprite = native_cube_word(record, 4);
            for (j = 0; j < 3; ++j) prop.position[j] = native_cube_word(record + 4 + j * 2, 2);
            prop.flags = native_cube_word(record + 10, 2);
            /* Serialized sprite records cannot contain a live actor pointer. */
            if (prop.flags & 1) { file->failed = 1; break; }
            _gspropsDll_entrypoint_4(&prop);
        }
    }
    heap_free(data);
}

s32 func_808000B8_gccubeDll(GsFile *file, s32 skip) {
    u8 count;
    if (!file) return 0;
    if (_gsmaker_entrypoint_17(file, 10, &count)) native_cube_records(file, count, 1, skip, 11);
    if (_gsmaker_entrypoint_17(file, 8, &count)) native_cube_records(file, count, 0, skip, 9);
    return !file->failed;
}

s32 func_80800230_gccubeDll(GsFile *file, s32 skip) {
    s32 count;
    if (!file) return 0;
    if (_gsmaker_entrypoint_21(file, 10, &count)) native_cube_records(file, count, 1, skip, -1);
    if (_gsmaker_entrypoint_21(file, 8, &count)) native_cube_records(file, count, 0, skip, -1);
    return !file->failed;
}

void func_808003A0_gccubeDll(GsFile *file, s32 skip) {
    s32 position[3];
    if (!file) return;
    while (!file->failed && !_gsmaker_entrypoint_16(file, 1)) {
        if (_gsmaker_entrypoint_22(file, 0, position, 3)) {
            _gsmaker_entrypoint_12(file, position, 3);
        } else if (_gsmaker_entrypoint_22(file, 2, position, 3)) {
        } else if (_gsmaker_entrypoint_16(file, 3)) {
            func_808000B8_gccubeDll(file, skip);
        } else {
            file->failed = 1;
        }
    }
}

void gccubeDll_entrypoint_1(NativeWorldGrid *grid) {
    s16 _gcmapDll_entrypoint_5(void);
    void func_800BEC4C(s32 *, s32 *, s32);
    void func_800CE2DC(void);
    s32 func_800EA05C(void);
    s32 i, count = 1;
    s64 dimension;
    grid->cell_size = _gcmapDll_entrypoint_5();
    if (grid->cell_size <= 0) goto invalid;
    grid->scale = 1.0f / grid->cell_size;
    func_800BEC4C(grid->lower, grid->upper, grid->cell_size);
    for (i = 0; i < 3; ++i) {
        dimension = (s64)grid->upper[i] - grid->lower[i] + 1;
        if (dimension <= 0 || dimension > INT16_MAX || count > INT16_MAX / dimension) goto invalid;
        grid->dimensions[i] = dimension;
        count *= dimension;
    }
    grid->row_stride = grid->dimensions[0];
    grid->plane_stride = grid->row_stride * grid->dimensions[1];
    grid->count = count;
    grid->cells = heap_alloc(count * sizeof(*grid->cells));
    grid->model_counts = heap_alloc(count);
    for (i = 0; i < count; ++i) func_800E9E4C(grid->cells + i, 0);
    func_800E9E4C(&grid->fallback, 0);
    func_800CD230(func_800EA05C() == 0xD7 ? 1000.0f : 200.0f);
    if(!func_800C6A08(func_800CD23C, func_800CD3A8, func_800CD544)) {
        fprintf(stderr,"Banjo-Tooie native world: collision callback table is full\n");abort();
    }
    func_800CE2DC();
    func_800E9708();
    return;
invalid:
    fprintf(stderr, "Banjo-Tooie native world: invalid grid bounds or cell size\n");
    abort();
}

void gccubeDll_entrypoint_2(NativeWorldGrid *grid) {
    s32 i;
    for (i = 0; i < grid->count; ++i) func_800E9C44(grid->cells + i);
    func_800E9C44(&grid->fallback);
    heap_free(grid->cells); heap_free(grid->model_counts);
    grid->cells = NULL; grid->model_counts = NULL; grid->count = 0;
}

void gccubeDll_entrypoint_3(NativeWorldGrid *grid, void *stream) {
    GsFile *file = stream;
    s32 start[3], end[3], i;
    s64 cells = 1, dimension;
    if (!file) return;
    if (!_gsmaker_entrypoint_22(file, 1, start, 3)) { file->failed = 1; return; }
    _gsmaker_entrypoint_12(file, end, 3);
    if (file->failed) return;
    for (i = 0; i < 3; ++i) {
        dimension = (s64)end[i] - start[i] + 1;
        if (dimension <= 0) { cells = 0; break; }
        if (dimension > INT32_MAX || cells > INT32_MAX / dimension) { file->failed = 1; return; }
        cells *= dimension;
    }
    for (i = 0; i < cells && !file->failed; ++i) func_808003A0_gccubeDll(file, 0);
    if (!_gsmaker_entrypoint_16(file, 0)) { file->failed = 1; return; }
    func_80800868_gccubeDll(grid, file);
}

void gccubeDll_entrypoint_4(NativeWorldGrid *grid, void *stream) {
    GsFile *file = stream;
    if (!file) return;
    func_80800230_gccubeDll(file, 0);
    if (!_gsmaker_entrypoint_16(file, 1)) { file->failed = 1; return; }
    func_80800868_gccubeDll(grid, file);
}

void func_80800868_gccubeDll(NativeWorldGrid *grid, GsFile *file) {
    void func_800CE308(void);
    (void)grid; (void)file;
    func_800CE308();
}

void gccubeDll_entrypoint_5(NativeWorldGrid *grid) {
    void _gccollectDll_entrypoint_8(NativeWorldCell *);
    s32 i;
    for (i = 0; i < grid->count; ++i) _gccollectDll_entrypoint_8(grid->cells + i);
}

void gccubeDll_entrypoint_6(NativeWorldGrid *grid) {
    void func_800CB9FC(void), func_800CBA20(void), func_800CBA44(void);
    s32 i;
    for (i = 0; i < grid->count; ++i) _gspropsDll_entrypoint_2(grid->cells + i, 0);
    func_800CBA20();
    for (i = 0; i < grid->count; ++i) _gspropsDll_entrypoint_2(grid->cells + i, 1);
    func_800CB9FC(); func_800CBA44();
}

u32 gccubeDll_entrypoint_7(void) {
    NativeWorldCell *cell, *end;
    Prop *prop, *prop_end;
    u32 maximum = 0;
    func_800BE52C(&cell, &end);
    for (; cell && cell < end; ++cell) {
        prop = func_800E9D68(cell); prop_end = func_800E9D90(cell);
        for (; prop && prop < prop_end; ++prop)
            if (maximum < (prop->unk10 >> 5)) maximum = prop->unk10 >> 5;
    }
    return maximum;
}
#else
#include "common.h"

/* extern */

void gccubeDll_entrypoint_0(void *arg0) {
    s32 _gspropsDll_entrypoint_0(u32, s32 *, s32 *);
    s32 _gspropsDll_entrypoint_1(s32 *, s32);
    u32 var_s0;
    s32 sp34[500];
    s32 i;
    s32 sp2C;

    for (i = 0; i < 500; i++) {
        sp34[i] = 0;
    }
    sp2C = 0;
    var_s0 = (*(u32 *)((s8 *)(arg0) + (0)));
    if (var_s0 < (u32) (((*(s32 *)((s8 *)(arg0) + (0x24))) * 8) + var_s0)) {
        do {
            _gspropsDll_entrypoint_0(var_s0, sp34, &sp2C);
            var_s0 += 8;
        } while (var_s0 < (*(u32 *)((s8 *)arg0 + 0)) + (*(s32 *)((s8 *)arg0 + 0x24)) * 8);
    }
    _gspropsDll_entrypoint_1(sp34, sp2C);
}

s32 func_808000B8_gccubeDll(s32 arg0, s32 arg1) {
    s32 _gsmaker_entrypoint_17(s32, s32, u8 *);
    s32 _gsmaker_entrypoint_18(s32, s32, void *, s32);
    s32 _gspropsDll_entrypoint_3(void *);
    s32 _gspropsDll_entrypoint_4(void *);
    void *heap_alloc(s32);
    s32 heap_free(u32);
    u8 count;
    s32 i;
    struct { s32 data[5]; } *first;
    struct { s32 data[3]; } *second;

    if (_gsmaker_entrypoint_17(arg0, 10, &count)) {
        first = heap_alloc(count * sizeof(*first));
        _gsmaker_entrypoint_18(arg0, 11, first, count * sizeof(*first));
        for (i = 0; i < count && arg1 == 0; i++) {
            _gspropsDll_entrypoint_3(&first[i]);
        }
        heap_free(first);
    }
    if (_gsmaker_entrypoint_17(arg0, 8, &count)) {
        second = heap_alloc(count * sizeof(*second));
        _gsmaker_entrypoint_18(arg0, 9, second, count * sizeof(*second));
        for (i = 0; i < count && arg1 == 0; i++) {
            _gspropsDll_entrypoint_4(&second[i]);
        }
        heap_free(second);
    }
}

s32 func_80800230_gccubeDll(s32 arg0, s32 arg1) {
    s32 _gsmaker_entrypoint_21(s32, s32, s32 *);
    s32 _gsmaker_entrypoint_8(s32, void *, s32);
    s32 _gspropsDll_entrypoint_3(void *);
    s32 _gspropsDll_entrypoint_4(void *);
    void *heap_alloc(s32);
    s32 heap_free(u32);
    s32 count;
    s32 i;
    struct { s32 data[5]; } *first;
    struct { s32 data[3]; } *second;

    if (_gsmaker_entrypoint_21(arg0, 10, &count)) {
        first = heap_alloc(count * sizeof(*first));
        _gsmaker_entrypoint_8(arg0, first, count * sizeof(*first));
        for (i = 0; i < count && arg1 == 0; i++) {
            _gspropsDll_entrypoint_3(&first[i]);
        }
        heap_free(first);
    }
    if (_gsmaker_entrypoint_21(arg0, 8, &count)) {
        second = heap_alloc(count * sizeof(*second));
        _gsmaker_entrypoint_8(arg0, second, count * sizeof(*second));
        for (i = 0; i < count && arg1 == 0; i++) {
            _gspropsDll_entrypoint_4(&second[i]);
        }
        heap_free(second);
    }
}

void func_808003A0_gccubeDll(s32 arg0, s32 arg1) {
    s32 _gsmaker_entrypoint_12(s32, s32 *, s32);
    s32 _gsmaker_entrypoint_16(s32, s32);
    s32 _gsmaker_entrypoint_22(s32, s32, s32 *, s32);
    s32 func_808000B8_gccubeDll(s32, s32);
    s32 pad[3];

    while (!_gsmaker_entrypoint_16(arg0, 1)) {
        if (_gsmaker_entrypoint_22(arg0, 0, pad, 3)) {
            _gsmaker_entrypoint_12(arg0, pad, 3);
        } else if (!_gsmaker_entrypoint_22(arg0, 2, pad, 3)
                   && _gsmaker_entrypoint_16(arg0, 3)) {
            func_808000B8_gccubeDll(arg0, arg1);
        }
    }
}

void gccubeDll_entrypoint_1(u8 *arg0) {
    s16 _gcmapDll_entrypoint_5(void);
    void func_800BEC4C(s32 *, s32 *, s32);
    void func_800C6A08(s32, s32, s32);
    void func_800CD230(f32);
    s32 func_800CD23C(s32, s32, s32, s32);
    s32 func_800CD3A8(s32, s32, f32, s32, s32, s32);
    s32 func_800CD544(s32, f32, s32, s32);
    void func_800CE2DC(void);
    void func_800E9708(void);
    void func_800E9E4C(u8 *, s32 *);
    s32 func_800EA05C(void);
    void func_800EFB58(void *, void *, void *);
    void *heap_alloc(s32);
    s32 pos[3];
    s32 relative[3];
    s32 i;
    s32 *p;
    f32 distance;

    *(s16 *)(arg0 + 0x3C) = _gcmapDll_entrypoint_5();
    *(f32 *)(arg0 + 0x40) = 1.0f / *(s16 *)(arg0 + 0x3C);
    func_800BEC4C((s32 *)(arg0 + 4), (s32 *)(arg0 + 0x10), *(s16 *)(arg0 + 0x3C));
    for (i = 0, p = (s32 *)arg0; i != 3; i++, p++) {
        p[10] = p[4] - p[1] + 1;
    }
    *(s32 *)(arg0 + 0x1C) = *(s32 *)(arg0 + 0x28);
    *(s32 *)(arg0 + 0x20) = *(s32 *)(arg0 + 0x1C) * *(s32 *)(arg0 + 0x2C);
    *(s32 *)(arg0 + 0x24) = *(s32 *)(arg0 + 0x20) * *(s32 *)(arg0 + 0x30);
    *(void **)arg0 = heap_alloc(*(s32 *)(arg0 + 0x24) * 8);
    *(void **)(arg0 + 0x44) = heap_alloc(*(s32 *)(arg0 + 0x24));
    for (pos[0] = *(s32 *)(arg0 + 4); pos[0] <= *(s32 *)(arg0 + 0x10); pos[0]++) {
        for (pos[1] = *(s32 *)(arg0 + 8); pos[1] <= *(s32 *)(arg0 + 0x14); pos[1]++) {
            for (pos[2] = *(s32 *)(arg0 + 0xC); pos[2] <= *(s32 *)(arg0 + 0x18); pos[2]++) {
                func_800EFB58(relative, pos, arg0 + 4);
                func_800E9E4C((u8 *)(*(u8 (**)[8])arg0 + relative[0] + relative[1] * *(s32 *)(arg0 + 0x1C) + relative[2] * *(s32 *)(arg0 + 0x20)), pos);
            }
        }
    }
    func_800E9E4C(arg0 + 0x34, 0);
    distance = func_800EA05C() == 0xD7 ? 1000.0f : 200.0f;
    func_800CD230(distance);
    func_800C6A08(func_800CD23C, func_800CD3A8, func_800CD544);
    func_800CE2DC();
    func_800E9708();
}

/* extern */

void gccubeDll_entrypoint_2(u8 *arg0) {
    s32 func_800E9C44(u8 *);
    s32 heap_free(u32);
    u32 var_s0;

    var_s0 = (*(u32 *)((s8 *)(arg0) + (0)));
    if (var_s0 < (u32) (((*(s32 *)((s8 *)(arg0) + (0x24))) * 8) + var_s0)) {
        do {
            func_800E9C44((u8 *) var_s0);
            var_s0 += 8;
        } while (var_s0 < (*(u32 *)((s8 *)arg0 + 0)) + (*(s32 *)((s8 *)arg0 + 0x24)) * 8);
    }
    func_800E9C44(arg0 + 0x34);
    heap_free((*(u32 *)((s8 *)(arg0) + (0))));
    (*(u32 *)((s8 *)(arg0) + (0))) = 0U;
    heap_free((*(u32 *)((s8 *)(arg0) + (0x44))));
    (*(u32 *)((s8 *)(arg0) + (0x44))) = 0U;
}

void gccubeDll_entrypoint_3(s32 arg0, s32 arg1) {
    s32 _gsmaker_entrypoint_12(s32, s32 *, s32);
    s32 _gsmaker_entrypoint_16(s32, s32);
    s32 _gsmaker_entrypoint_22(s32, s32, s32 *, s32);
    void func_80800868_gccubeDll(s32, s32);
    s32 pos[3];
    s32 start[3];
    s32 end[3];

    _gsmaker_entrypoint_22(arg1, 1, start, 3);
    _gsmaker_entrypoint_12(arg1, end, 3);
    for (pos[0] = start[0]; pos[0] <= end[0]; pos[0]++) {
        for (pos[1] = start[1]; pos[1] <= end[1]; pos[1]++) {
            for (pos[2] = start[2]; pos[2] <= end[2]; pos[2]++) {
                func_808003A0_gccubeDll(arg1, 0);
            }
        }
    }
    _gsmaker_entrypoint_16(arg1, 0);
    func_80800868_gccubeDll(arg0, arg1);
}

void gccubeDll_entrypoint_4(s32 arg0, s32 arg1) {
    s32 func_80800230_gccubeDll(s32, s32);
    s32 _gsmaker_entrypoint_16(s32, s32);
    void func_80800868_gccubeDll(s32, s32);
    func_80800230_gccubeDll(arg1, 0);
    _gsmaker_entrypoint_16(arg1, 1);
    func_80800868_gccubeDll(arg0, arg1);
}

/* extern */

void func_80800868_gccubeDll(s32 arg0, s32 arg1) {
    s32 func_800CE308();
    func_800CE308();
}

/* extern */

void gccubeDll_entrypoint_5(struct gccubeDll_entrypoint_5_arg *arg0) {
    struct gccubeDll_entrypoint_5_arg { s32 *base; u8 pad[0x20]; s32 count; };
    s32 _gccollectDll_entrypoint_8(void *);
    s32 var_s0;

    var_s0 = 0;
    if (arg0->count > 0) {
        do {
            _gccollectDll_entrypoint_8((u8 *)arg0->base + (var_s0 << 3));
            var_s0 += 1;
        } while (var_s0 < arg0->count);
    }
}

/* extern */

void gccubeDll_entrypoint_6(void *arg0) {
    s32 _gspropsDll_entrypoint_2(s32, s32);
    s32 func_800CB9FC();
    s32 func_800CBA20();
    s32 func_800CBA44();
    s32 var_s0;

    var_s0 = 0;
    if ((*(s32 *)((s8 *)(arg0) + (0x24))) > 0) {
        do {
            _gspropsDll_entrypoint_2((*(s32 *)((s8 *)(arg0) + (0))) + (var_s0 << 3), 0);
            var_s0 += 1;
        } while (var_s0 < (*(s32 *)((s8 *)(arg0) + (0x24))));
        var_s0 = 0;
    }
    func_800CBA20();
    if ((*(s32 *)((s8 *)(arg0) + (0x24))) > 0) {
        do {
            _gspropsDll_entrypoint_2((*(s32 *)((s8 *)(arg0) + (0))) + (var_s0 << 3), 1);
            var_s0 += 1;
        } while (var_s0 < (*(s32 *)((s8 *)(arg0) + (0x24))));
    }
    func_800CB9FC();
    func_800CBA44();
}

/* extern */

u32 gccubeDll_entrypoint_7(void) {
    void func_800BE52C(s32 *, s32 *);
    Prop *func_800E9D68(s16 *);
    u32 func_800E9D90(s16 *);
    struct CubeProp { u8 pad[0x10]; u32 value : 11; u32 other : 21; };
    u32 temp_t7;
    s32 sp30;
    s32 sp2C;
    struct CubeProp *temp_v0;
    struct CubeProp *var_s0;
    u32 var_s1;

    var_s1 = 0;
    func_800BE52C(&sp30, &sp2C);
    if ((u32)sp30 < (u32)sp2C) {
        do {
            var_s0 = (struct CubeProp *)func_800E9D68((s16 *)sp30);
            temp_v0 = (struct CubeProp *)func_800E9D90((s16 *)sp30);
            if (var_s0 < temp_v0) {
                do {
                    temp_t7 = var_s0->value;
                    var_s0++;
                    if (var_s1 < temp_t7) {
                        var_s1 = temp_t7;
                    }
                } while (var_s0 < temp_v0);
            }
            sp30 += 8;
        } while ((u32)sp30 < (u32)sp2C);
    }
    return var_s1;
}

#endif
