#include "common.h"

void func_80800000_rtlight(void *arg0, s32 arg1, void *arg2) {
    (*(s32 *)((s8 *)(arg2) + (8))) = (s32) (arg1 / (s32) (*(u16 *)((s8 *)(arg0) + (0xE))));
    (*(s32 *)((s8 *)(arg2) + (4))) = (s32) ((s32) (arg1 % (s32) (*(u16 *)((s8 *)(arg0) + (0xE)))) / (s32) (*(u16 *)((s8 *)(arg0) + (0xC))));
    (*(s32 *)((s8 *)(arg2) + (0))) = (s32) (arg1 % (s32) (*(u16 *)((s8 *)(arg0) + (0xE)))) % (s32) (*(u16 *)((s8 *)(arg0) + (0xC)));
    (*(s32 *)((s8 *)(arg2) + (0))) += (*(s16 *)((s8 *)(arg0) + (0)));
    (*(s32 *)((s8 *)(arg2) + (4))) += (*(s16 *)((s8 *)(arg0) + (2)));
    (*(s32 *)((s8 *)(arg2) + (8))) += (*(s16 *)((s8 *)(arg0) + (4)));
}

void rtlight_entrypoint_0(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/rt/light/rtlight_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/rt/light/func_8080036C_rtlight.s")

void func_80800544_rtlight(void *arg0, s32 position[3]) {
    void func_800C8800(void *, f32 *);
    f32 pos[3];
    func_800C8800(arg0, pos);
    position[0] = (s32)pos[0];
    position[1] = (s32)pos[1];
    position[2] = (s32)pos[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/rt/light/func_808005AC_rtlight.s")

void rtlight_entrypoint_2(u8 *arg0, void *arg1, s32 arg2, s32 arg3) {
    typedef struct {
        u8 lights[15];
        s8 dirty;
        s16 min[3];
        s16 max[3];
        s16 first;
        s16 count;
    } Cell;
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
    void func_800C8800(void *, f32 *);
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
