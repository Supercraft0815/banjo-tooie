#include "common.h"

void dblight_entrypoint_0(u8 *arg0, void *arg1, s32 *arg2) {
    void *func_800B2190(void *);
    s32 pad[4];
    s16 *index;
    Vtx *vertices;
    s32 i;
    s32 j;
    s32 *color;
    Vtx *vertex;

    if (arg2[0] != 255 || arg2[1] != 255 || arg2[2] != 255) {
        index = (s16 *)(*(u16 *)(arg0 + 0x10) * 4 + arg0 + 0x18);
        vertices = func_800B2190(arg1);
        i = 0;
        if (*(s32 *)(arg0 + 0x14) > 0) {
          do {
            vertex = vertices + *index;
            for (j = 0; j < 3; j++) {
                vertex->v.cn[j] = (vertex->v.cn[j] * arg2[j]) >> 8;
            }
            i++;
            index++;
          } while (i < *(s32 *)(arg0 + 0x14));
        }
    }
}

void dblight_entrypoint_1(u8 *arg0, void *arg1, s32 arg2) {
    typedef struct {
        s16 position[3];
        u16 flags;
        s16 uv[2];
        u8 color[4];
    } LightVertex;
    void *func_800B2190(void *);
    s8 *_dbvtxnormal_entrypoint_0(s32, s32);
    s32 func_800C8760(s32, s32);
    s32 func_800C878C(s32, s32, s32);
    void func_800C8800(s32, f32 *);
    void func_800C8898(s32, f32 *);
    void func_800C8900(s32, s32 *);
    s16 *index;
    s16 *end;
    s8 *normal;
    u8 *vertices;
    s32 light;
    s32 red, green, blue;
    LightVertex *vertex;
    f32 nx, ny, nz;
    f32 distance;
    f32 delta[3];
    f32 range[3];
    s32 color[3];
    f32 position[3];
    f32 reciprocal;
    f32 dot;
    f32 lengthSquared;
    f32 attenuation;

    vertices = func_800B2190(arg1);
    index = (s16 *)(arg0 + *(u16 *)(arg0 + 0x10) * 4 + 0x18);
    end = index + *(s32 *)(arg0 + 0x14);
    if ((u32)index < (u32)end) {
      do {
        vertex = (LightVertex *)(vertices + *index * 0x10);
        normal = _dbvtxnormal_entrypoint_0(arg2, *index);
        red = vertex->color[0];
        green = vertex->color[1];
        blue = vertex->color[2];
        nx = normal[0] * 0.007874015f;
        ny = normal[1] * 0.007874015f;
        nz = normal[2] * 0.007874015f;
        light = func_800C8760(0, 4);
        if (light != 0) {
          do {
            func_800C8800(light, position);
            delta[0] = position[0] - (f32)vertex->position[0];
            delta[1] = position[1] - (f32)vertex->position[1];
            delta[2] = position[2] - (f32)vertex->position[2];
            lengthSquared = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
            distance = sqrtf(lengthSquared);
            func_800C8898(light, range);
            if (!(range[1] < distance)) {
                func_800C8900(light, color);
                if (distance != 0.0f) {
                    reciprocal = 1.0f / distance;
                    delta[0] *= reciprocal;
                    delta[1] *= reciprocal;
                    delta[2] *= reciprocal;
                    dot = delta[0] * nx + delta[1] * ny + delta[2] * nz;
                    if (dot < 0) {
                        if (vertex->flags & 0x8000) {
                            dot = -dot;
                            goto scale_color;
                        }
                    } else {
scale_color:
                        color[0] = (s32)(color[0] * dot);
                        color[1] = (s32)(color[1] * dot);
                        color[2] = (s32)(color[2] * dot);
                        goto add_color;
                    }
                } else {
add_color:
                if (distance <= range[0]) {
                    red += color[0];
                    green += color[1];
                    blue += color[2];
                } else {
                    attenuation = 1.0f - (distance - range[0]) * range[2];
                    red += attenuation * color[0];
                    green += attenuation * color[1];
                    blue += attenuation * color[2];
                }
                }
            }
            light = func_800C878C(light, 0, 4);
          } while (light != 0);
        }
        if (red >= 0x100) red = 0xFF;
        if (green >= 0x100) green = 0xFF;
        if (blue >= 0x100) blue = 0xFF;
        vertex->color[0] = red;
        vertex->color[1] = green;
        vertex->color[2] = blue;
        index++;
      } while ((u32)index < (u32)end);
    }
}
