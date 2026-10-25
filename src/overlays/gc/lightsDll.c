#include "common.h"
struct Vector;
void vector_free(struct Vector *vec);
struct Vector *vector_new(u32, u32);
void func_800C8C90(s32);
void func_800C8F08(s32, f32 *);
void gclightsDll_entrypoint_1();

void func_80800000_gclightsDll(s32 arg0)
{
    gclightsDll_entrypoint_1();
    _gclightsDll_entrypoint_0(arg0);
}
void gclightsDll_entrypoint_0(struct Vector **arg0) {
    void gclightsDll_entrypoint_5(f32 *);
    extern f32 D_80800560_gclightsDll[3];
    extern f32 D_8080056C_gclightsDll[3];
    extern f32 D_80800578_gclightsDll[3];
    *arg0 = vector_new(0x1C, 1);
    func_800C8C90((s32) D_80800560_gclightsDll);
    gclightsDll_entrypoint_5(D_8080056C_gclightsDll);
    func_800C8F08((s32) D_8080056C_gclightsDll, D_80800578_gclightsDll);
}

void gclightsDll_entrypoint_1(struct Vector **arg0) {
    vector_free(*arg0);
}

void gclightsDll_entrypoint_2(s32 arg0, s32 arg1) {
    s32 _gsmaker_entrypoint_16(s32, s32);
    s32 _gsmaker_entrypoint_17(s32, s32, u8 *);
    s32 _gsmaker_entrypoint_20(s32, s32, f32 *, s32);
    s32 _gsmaker_entrypoint_22(s32, s32, s32 *, s32);
    u32 vector_begin(s32);
    u32 vector_end(s32);
    void *vector_push_back(struct Vector **);
    s32 gclightsDll_entrypoint_4(void);
    void gclightsDll_entrypoint_5(f32 *);
    void func_800C8F64(s32, s32);
    u32 current;
    u32 end;
    struct Vector *vec;
    f32 position[3];
    f32 range[2];
    s32 color[3];
    u8 flag;
    s32 light;
    s32 ambient[3];
    f32 direction[3];
    s32 queuedLight;
    s32 *queuedSlot;
    s32 otherColor[3];
    f32 otherPosition[3];
    s32 unusedColor[3];

    vec = vector_new(4, 16);
    func_80800000_gclightsDll(arg0);
    while (!_gsmaker_entrypoint_16(arg1, 0)) {
        if (_gsmaker_entrypoint_16(arg1, 1) &&
            _gsmaker_entrypoint_20(arg1, 2, position, 3) &&
            _gsmaker_entrypoint_20(arg1, 3, range, 2) &&
            _gsmaker_entrypoint_22(arg1, 4, color, 3)) {
            light = gclightsDll_entrypoint_4();
            func_800C8CB8(light, position);
            func_800C8D4C(light, range);
            func_800C8E84(light, color);
            if (_gsmaker_entrypoint_17(arg1, 7, &flag)) {
                func_800C8F64(light, flag);
            }
        } else if (_gsmaker_entrypoint_16(arg1, 5) &&
                   _gsmaker_entrypoint_22(arg1, 4, ambient, 3)) {
            func_800C8C90((s32)ambient);
        } else if (_gsmaker_entrypoint_16(arg1, 6) &&
                   _gsmaker_entrypoint_22(arg1, 4, direction, 3)) {
            gclightsDll_entrypoint_5(direction);
        } else if (_gsmaker_entrypoint_16(arg1, 8)) {
            queuedLight = gclightsDll_entrypoint_4();
            queuedSlot = vector_push_back(&vec);
            *queuedSlot = queuedLight;
        } else if (_gsmaker_entrypoint_16(arg1, 9) &&
                   _gsmaker_entrypoint_20(arg1, 2, otherPosition, 3) &&
                   _gsmaker_entrypoint_22(arg1, 4, otherColor, 3)) {
            func_800C8F08((s32)otherColor, otherPosition);
        } else if (_gsmaker_entrypoint_16(arg1, 10)) {
            _gsmaker_entrypoint_22(arg1, 4, unusedColor, 3);
        }
    }
    end = vector_end((s32)vec);
    for (current = vector_begin((s32)vec); current < end; current += 4) {
        func_800C8B84(*(s32 *)current);
    }
    vector_free(vec);
}

/* extern */

s32 gclightsDll_entrypoint_3(s32 *arg0, f32 *arg1) {
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEAD4(f32 *, f32 *);
    u32 vector_begin(s32);
    u32 vector_end(s32);
    u32 sp5C;
    f32 temp_f0;
    f32 var_f20;
    s32 var_v1;
    u32 temp_v0;
    u32 var_s0;
    f32 sp3C[3];
    u32 var_s2;

    sp5C = vector_begin(*arg0);
    temp_v0 = vector_end(*arg0);
    var_s0 = sp5C;
    var_f20 = -1.0f;
    var_s2 = 0;
    if (var_s0 < temp_v0) {
        do {
            if (((*(u8 *)((s8 *)(var_s0) + (0x15))) != 0) && ((*(u8 *)((s8 *)(var_s0) + (0x14))) != 0) && ((*(u8 *)((s8 *)(var_s0) + (0x17))) != 0) && ((func_800EE88C(sp3C, (s16 *) var_s0), temp_f0 = func_800EEAD4(arg1, sp3C), (var_s2 == 0)) || (temp_f0 < var_f20))) {
                var_s2 = var_s0;
                var_f20 = temp_f0;
            }
            var_s0 += 0x1C;
        } while (var_s0 < temp_v0);
    }
    if (var_s2 != 0) {
        var_v1 = (s32) ((var_s2 - sp5C) + 0x1C) / 28;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

s32 gclightsDll_entrypoint_4(void) {
    s32 func_800C8A98(void);
    void *func_800C911C(void);
    void *vector_at(s32, s32);
    u32 vector_begin(s32);
    u32 vector_end(s32);
    s32 *lights;
    u32 begin;
    s32 unused;
    s32 handle;
    u32 end;
    u32 current;
    u8 *light;

    lights = func_800C911C();
    begin = vector_begin(*lights);
    end = vector_end(*lights);
    current = begin;
    if (current < end) {
        do {
            if (*(u8 *)(current + 0x14) == 0) {
                *(u8 *)(current + 0x15) = 0;
            }
            current += 0x1C;
        } while (current < end);
    }
    handle = func_800C8A98();
    light = vector_at(*lights, handle - 1);
    light[0x14] = 1;
    light[0x15] = 0xD;
    return handle;
}

/* extern */

void gclightsDll_entrypoint_5(f32 *arg0) {
    void *func_800C911C(void);
    s32 func_800EE830(s32, f32 *);
    u8 *lights;
    lights = func_800C911C();
    func_800EE830(lights + 0x10, arg0);
}
