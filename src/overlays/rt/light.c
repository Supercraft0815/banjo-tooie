#include "common.h"

typedef struct {
    u8 lights[15];
    s8 dirty;
    s16 min[3];
    s16 max[3];
    s16 first;
    s16 count;
} Cell;                     typedef struct { s32 unk0; s32 unk4; s32 unk8; } Objlight_arg2; /* offsets.py genstruct: fields from raw offsets on arg2; rename once understood */

void func_80800000_rtlight(void *arg0, s32 arg1, void *arg2) {
    (((Objlight_arg2 *)arg2)->unk8) = (s32) (arg1 / (s32) (*(u16 *)((s8 *)(arg0) + (0xE))));
    (((Objlight_arg2 *)arg2)->unk4) = (s32) ((s32) (arg1 % (s32) (*(u16 *)((s8 *)(arg0) + (0xE)))) / (s32) (*(u16 *)((s8 *)(arg0) + (0xC))));
    (((Objlight_arg2 *)arg2)->unk0) = (s32) (arg1 % (s32) (*(u16 *)((s8 *)(arg0) + (0xE)))) % (s32) (*(u16 *)((s8 *)(arg0) + (0xC)));
    (((Objlight_arg2 *)arg2)->unk0) += (*(s16 *)((s8 *)(arg0) + (0)));
    (((Objlight_arg2 *)arg2)->unk4) += (*(s16 *)((s8 *)(arg0) + (2)));
    (((Objlight_arg2 *)arg2)->unk8) += (*(s16 *)((s8 *)(arg0) + (4)));
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) rtlight_entrypoint_0(void* arg0) 
{
    BT_NATIVE_ONLY(return) heap_free(arg0);
}
void *rtlight_entrypoint_1(void *arg0, void *arg1, BtIntPtr arg2) {
    typedef struct {
        s16 origin[3];
        u16 pad[5];
        u16 count;
        s16 scale;
        s32 vertexCount;
    } Source;
    typedef struct {
        u8 lights[15];
        s8 dirty;
        s16 min[3];
        s16 max[3];
        u16 first;
        u16 count;
    } Cell;
    typedef struct {
        Source *source;
        s16 scale;
        u16 count;
        f32 inverseScale;
    } Header;
    typedef struct {
        s16 pos[3];
        s16 index;
        u8 color[3];
        u8 pad;
    } Vertex;
    typedef struct { u16 first; u16 count; } Pair;
    void *func_800B2190(void *);
    void *heap_alloc(s32);
    Header *result;
    Source *source = arg0;
    Vertex *vertexEnd;
    Cell *cell;
    u8 *base;
    Cell *end;
    Vertex *vertex;
    u8 *vertices;
    u16 count;
    Pair *input;
    s16 *indices;
    u8 *color;
    s32 coords[3];
    s32 i;

    count = source->count;
    result = heap_alloc(count * sizeof(Cell) + source->vertexCount * sizeof(Vertex) + sizeof(Header));
    *(Source **)result = source;
    result->scale = source->scale;
    result->count = count;
    result->inverseScale = 1.0f / source->scale;
    input = (Pair *)(source + 1);
    base = (u8 *)(result + 1);
    cell = (Cell *)base;
    end = (Cell *)((u8 *)(count + (Cell *)result) + sizeof(Header));
    if (cell < end) {
      do {
        if (input->count == 0) {
            cell->dirty = -1;
        } else {
            for (i = 0; i < 15; i++) {
                cell->lights[i] = 0;
            }
            func_80800000_rtlight(result->source, (s32)((u8 *)cell - base) >> 5, coords);
            for (i = 0; i < 3; i++) {
                cell->min[i] = coords[i] * source->scale - 20;
                cell->max[i] = (coords[i] + 1) * source->scale + 20;
            }
            cell->first = ((u16 *)input)[0];
            cell->count = ((u16 *)input)[1];
            cell->dirty = 0;
        }
        cell++;
        input++;
      } while (cell < end);
    }
    vertex = (Vertex *)cell;
    vertexEnd = vertex + source->vertexCount;
    indices = (s16 *)input;
    vertices = func_800B2190(arg1);
    if ((BtUIntPtr)vertex < (BtUIntPtr)vertexEnd) { do { base = (u8 *)vertex; vertex++; vertex[-1].index = *indices; i = 0; color = vertices + *indices * 16; do { base[8 + i] = color[12 + i]; i++; } while (i != 3); indices++; } while ((BtUIntPtr)vertex < (BtUIntPtr)vertexEnd); }
    return result;
}

void func_8080036C_rtlight(u8 *arg0, f32 *arg1, f32 arg2, Cell ***arg3, Cell ***arg4) {
    typedef struct {
        Cell *entries[150];
        Cell **end;
    } CellList;
    extern CellList D_80135550;
    typedef struct {
        s16 min[3];
        s16 max[3];
        u16 yStride;
        u16 zStride;
    } GridSource;
    typedef struct {
        GridSource *source;
        s16 scale;
        u16 count;
        f32 inverseScale;
        Cell cells[1];
    } Grid;
    s32 low[3];
    s32 high[3];
    f32 lo, hi;
    GridSource *bounds;
    s32 l, h;
    s16 min, max;
    s32 axis, z, y, x;
    Cell *cell;
    Cell **end;
    Cell **list;

    bounds = ((Grid *)arg0)->source;
    for (axis = 0; axis < 3; axis++) {
        lo = arg1[axis] - arg2;
        hi = arg1[axis] + arg2;
        l = (s32)(((Grid *)arg0)->inverseScale * lo);
        h = (s32)(((Grid *)arg0)->inverseScale * hi);
        if (lo < 0.0f) l--;
        if (hi < 0.0f) h--;
        min = bounds->min[axis];
        max = bounds->max[axis];
        if (l < min) l = min;
        if (max < l) l = max;
        if (h < min) h = min;
        if (max < h) h = max;
        low[axis] = l - min;
        high[axis] = h - min;
    }
    D_80135550.end = D_80135550.entries;
    for (z = low[2]; z <= high[2]; z++) {
        for (y = low[1]; y <= high[1]; y++) {
            for (x = low[0]; x <= high[0]; x++) {
                cell = bounds->zStride * z + ((Grid *)arg0)->cells
                     + x + y * bounds->yStride;
                if (cell->dirty >= 0) {
                    end = D_80135550.end;
                    if (end < &D_80135550.entries[150]) {
                        *end = cell;
                        D_80135550.end++;
                    }
                }
            }
        }
    }
    list = D_80135550.entries;
    *arg3 = list;
    *arg4 = D_80135550.end;
}

void func_80800544_rtlight(void *arg0, s32 position[3]) {
    void func_800C8800(BtIntPtr id,f32 *out);
    f32 pos[3];
    func_800C8800(arg0, pos);
    position[0] = (s32)pos[0];
    position[1] = (s32)pos[1];
    position[2] = (s32)pos[2];
}

void func_808005AC_rtlight(s32 arg0, s32 *range) {
    void func_800C8898(s32, f32 *);
    f32 values[3];

    func_800C8898(arg0, values);
    range[0] = (s32)(values[0] * 256.0f);
    range[1] = (s32)(values[1] * values[1]);
    range[2] = (s32)(values[2] * 16384.0f);
}

void rtlight_entrypoint_2(u8 *arg0, void *arg1, s32 arg2, s32 arg3) {
    typedef struct {
        s16 r, g, b, index;
        u8 color[3];
        u8 pad;
    } Color;
    typedef struct {
        s16 pos[3];
        u8 pad[6];
        u8 color[4];
    } Vertex;
    void *func_800B2190(void *);
    s32 func_800C8760(s32, s32);
    s32 func_800C878C(s32, s32, s32);
    void func_800C8800(BtIntPtr id,f32 *out);
    void func_800C883C(s32, void *);
    void func_800C8900(s32, void *);
    s32 func_800E3DC0(s16 *, s16 *);
    void func_8080036C_rtlight(u8 *, f32 *, f32, Cell ***, Cell ***);
    void func_808005AC_rtlight(s32, s32 *);
    s32 i;
    s32 squaredDistance;
    Cell *cell;
    Color *colors;
    u8 *slot;
    Vertex *outputVertex;
    f32 position[3];
    f32 radius[2];
    Cell **selected;
    Cell **selectedEnd;
    s32 dx, dy, dz;
    s32 distance;
    s32 strength;
    s32 attenuation;
    s32 light;
    s32 lightPosition[3];
    s32 lightRadius[3];
    s32 lightColor[3];
    Vertex *vertices;
    Color *start;
    Color *end;
    Color *color;
    Vertex *vertex;
    Cell *scan;
    Vertex *copyVertex;
    u8 *removeSlot;
    u8 *addSlot;
    s32 addIndex;
    s32 j;
    s16 value;

    colors = (Color *)(arg0 + (*(s16 *)(arg0 + 6) << 5) + 12);
    light = func_800C8760(2, 2);
    while (light != 0) {
        for (scan = (Cell *)(arg0 + 12); scan < (Cell *)colors; scan++) {
            i = 0;
            removeSlot = scan->lights;
            if (scan->dirty >= 0) {
                do {
                    i++;
                    if (light == *removeSlot) {
                        *removeSlot = 0;
                        scan->dirty = arg3;
                        break;
                    }
                    removeSlot++;
                } while (i != 15);
            }
        }
        func_800C8800((void *)light, position);
        func_800C883C(light, radius);
        func_8080036C_rtlight(arg0, position, radius[1], &selected, &selectedEnd);
        while (selected < selectedEnd) {
            addIndex = 0;
            addSlot = (*selected)->lights;
            do {
                addIndex++;
                if (*addSlot == 0) {
                    *addSlot = light;
                    (*selected)->dirty = arg3;
                    break;
                }
                addSlot++;
            } while (addIndex != 15);
            selected++;
        }
        light = func_800C878C(light, 2, 2);
    }
    cell = (Cell *)(arg0 + 12);
    vertices = func_800B2190(arg1);
    for (; cell < (Cell *)colors; cell++) {
        if (cell->dirty <= 0) {
            continue;
        }
            if (func_800E3DC0(cell->min, cell->max) == 0) {
                continue;
            }
            j = 0;
            slot = cell->lights;
            for (; j < 15; j++, slot++) {
                if (*slot != 0) {
                    break;
                }
            }
            start = colors + cell->first;
            end = start + cell->count;
            if (j == 15) {
                for (; start < end; start++) {
                    copyVertex = vertices + start->index;
                    copyVertex->color[0] = start->color[0];
                    copyVertex->color[1] = start->color[1];
                    copyVertex->color[2] = start->color[2];
                }
            } else {
                for (color = start; color < end; color++) {
                    color->r = color->color[0];
                    color->g = color->color[1];
                    color->b = color->color[2];
                }
                for (; j < 15; j++, slot++) {
                    value = *slot;
                    if (value == 0) {
                        continue;
                    }
                        func_80800544_rtlight((void *)(u32)value, lightPosition);
                        color = start;
                        func_808005AC_rtlight(*slot, lightRadius);
                        func_800C8900(*slot, lightColor);
                        for (; color < end; color++) {
                            vertex = vertices + color->index;
                            dx = lightPosition[0] - vertex->pos[0];
                            dy = lightPosition[1] - vertex->pos[1];
                            dz = lightPosition[2] - vertex->pos[2];
                            squaredDistance = dx * dx + dy * dy + dz * dz;
                            distance = squaredDistance;
                            if (squaredDistance < lightRadius[1]) {
                                if (squaredDistance != 0) {
                                    distance = (s32)(sqrtf((f32)squaredDistance) * 256.0f);
                                }
                                if (distance > lightRadius[0]) {
                                    attenuation = 0x4000 - (((distance - lightRadius[0]) * lightRadius[2]) >> 8);
                                    strength = attenuation * 4;
                                } else {
                                    strength = 0x10000;
                                }
                                color->r += (lightColor[0] * strength) >> 16;
                                color->g += (lightColor[1] * strength) >> 16;
                                color->b += (lightColor[2] * strength) >> 16;
                            }
                        }
                }
                for (; start < end; start++) {
                    outputVertex = vertices + start->index;
                    value = start->r;
                    if (value > 255) value = 255;
                    outputVertex->color[0] = value;
                    value = start->g;
                    if (value > 255) value = 255;
                    outputVertex->color[1] = value;
                    value = start->b;
                    if (value > 255) value = 255;
                    outputVertex->color[2] = value;
                }
            }
            cell->dirty--;
    }
}
