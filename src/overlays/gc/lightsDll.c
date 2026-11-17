#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_lights.h"
#include <math.h>

void func_80800000_gclightsDll(NativeLighting *state) {
    gclightsDll_entrypoint_1(state);_gclightsDll_entrypoint_0(state);
}
void gclightsDll_entrypoint_0(NativeLighting *state) {
    s32 ambient[3]={0},color[3]={255,255,255};f32 direction[3]={0,1,0};
    if(state->entries)vector_free(state->entries);
    state->entries=vector_new(sizeof(NativeLight),1);
    func_800C8C90(ambient);gclightsDll_entrypoint_5(color);func_800C8F08(color,direction);
}
void gclightsDll_entrypoint_1(NativeLighting *state) {
    if(state->entries)vector_free(state->entries);state->entries=NULL;
}
static int native_light_coordinates(f32 *values,s32 count) {
    for(s32 i=0;i<count;++i)
        if(!isfinite(values[i]) || values[i]<-2147483648.0f || values[i]>=2147483648.0f)return 0;
    return 1;
}
void gclightsDll_entrypoint_2(NativeLighting *state,GsFile *file) {
    s32 light,color[3],*queued;
    f32 position[3],range[2];u8 mask;
    Vector *pending;
    if(!file || file->failed)return;
    pending=vector_new(sizeof(s32),16);func_80800000_gclightsDll(state);
    while(!file->failed && !_gsmaker_entrypoint_16(file,0)) {
        if(_gsmaker_entrypoint_16(file,1)) {
            if(!_gsmaker_entrypoint_20(file,2,position,3) || !_gsmaker_entrypoint_20(file,3,range,2) ||
               !_gsmaker_entrypoint_22(file,4,color,3) || !native_light_coordinates(position,3) || !native_light_coordinates(range,2)) {
                file->failed=1;break;
            }
            light=gclightsDll_entrypoint_4();func_800C8CB8(light,position);func_800C8D4C(light,range);func_800C8E84(light,(u32 *)color);
            if(_gsmaker_entrypoint_17(file,7,&mask))func_800C8F64(light,mask);
        } else if(_gsmaker_entrypoint_16(file,5)) {
            if(!_gsmaker_entrypoint_22(file,4,color,3)){file->failed=1;break;}
            func_800C8C90(color);
        } else if(_gsmaker_entrypoint_16(file,6)) {
            if(!_gsmaker_entrypoint_22(file,4,color,3)){file->failed=1;break;}
            gclightsDll_entrypoint_5(color);
        } else if(_gsmaker_entrypoint_16(file,8)) {
            light=gclightsDll_entrypoint_4();queued=vector_push_back(&pending);*queued=light;
        } else if(_gsmaker_entrypoint_16(file,9)) {
            if(!_gsmaker_entrypoint_20(file,2,position,3) || !_gsmaker_entrypoint_22(file,4,color,3) || !native_light_coordinates(position,3)) {
                file->failed=1;break;
            }
            func_800C8F08(color,position);
        } else if(_gsmaker_entrypoint_16(file,10)) {
            _gsmaker_entrypoint_22(file,4,color,3);
        } else {file->failed=1;break;}
    }
    if(!file->failed)for(s32 i=0;i<vector_size(pending);++i)func_800C8B84(*(s32 *)vector_at(pending,i));
    else gclightsDll_entrypoint_1(state);
    vector_free(pending);
}
s32 gclightsDll_entrypoint_3(NativeLighting *state,f32 *position) {
    void func_800EE88C(f32 *,s16 *);f32 func_800EEAD4(f32 *,f32 *);
    s32 closest=0;f32 minimum=-1,point[3],distance;
    if(!state->entries)return 0;
    for(s32 i=0;i<vector_size(state->entries);++i) {
        NativeLight *light=vector_at(state->entries,i);
        if(light->mask && light->permanent && light->enabled) {
            func_800EE88C(point,light->position);distance=func_800EEAD4(position,point);
            if(!closest || distance<minimum){closest=i+1;minimum=distance;}
        }
    }
    return closest;
}
s32 gclightsDll_entrypoint_4(void) {
    NativeLighting *state=func_800C911C();
    if(state->entries)for(s32 i=0;i<vector_size(state->entries);++i) {
        NativeLight *light=vector_at(state->entries,i);if(!light->permanent)light->mask=0;
    }
    s32 id=func_800C8A98();NativeLight *light=vector_at(state->entries,id-1);
    light->permanent=1;light->mask=13;return id;
}
void gclightsDll_entrypoint_5(s32 *color) {
    NativeLighting *state=func_800C911C();for(s32 i=0;i<3;++i)state->primary_color[i]=color[i];
}
#else
#include "common.h"
struct Vector;
void vector_free(struct Vector *vec);
struct Vector *vector_new(u32, u32);
void func_800C8C90(s32);
void func_800C8F08(s32, f32 *);
void gclightsDll_entrypoint_1(); BT_NATIVE_ONLY(void gclightsDll_entrypoint_0(struct Vector **);)

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

#endif
/* data_to_c.py: from asm/data/overlays/gc/lightsDll.data.s */
f32 D_80800560_gclightsDll [ 3 ] BT_DATA(4, overlays_gc_lightsDll, 0x0) = { 0.0f, 0.0f, 0.0f };
f32 D_8080056C_gclightsDll [ 3 ] BT_DATA(4, overlays_gc_lightsDll, 0xC) = { 3.57331e-43f, 3.57331e-43f, 3.57331e-43f };
f32 D_80800578_gclightsDll [ 3 ] BT_DATA(4, overlays_gc_lightsDll, 0x18) = { 0.0f, 1.0f, 0.0f };
