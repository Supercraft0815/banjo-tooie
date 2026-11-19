#include "light_defaults.inc"
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_lights.h"
#include "memory.h"
NativeLighting native_lighting;

static NativeLight *native_light(s32 id) {
    return native_lighting.entries && id>0 && id<=vector_size(native_lighting.entries) ? vector_at(native_lighting.entries,id-1) : NULL;
}
s32 func_800C84B0(s32 flags) {
    s32 mask=flags&0x1F00;
    if(flags&0x20000)return 4;
    if(!mask)return 0;
    for(s32 i=0;i<17;++i)if(mask==D_8011A930.rows[i].flags)return D_8011A930.rows[i].category;
    return 1;
}
u32 func_800C8560(NativeLight *light,s32 mask) {return light->dirty && (light->mask&mask);}
u32 func_800C8588(NativeLight *light,s32 mask) {(void)mask;return light->permanent;}
u32 func_800C8594(NativeLight *light,s32 mask) {return light->mask&mask;}
s32 func_800C8678(s32 previous,NativeLightPredicate predicate,s32 mask) {
    s32 i;
    if(!native_lighting.entries || previous<0 || !predicate) return 0;
    for(i=previous;i<vector_size(native_lighting.entries);++i) {
        NativeLight *light=vector_at(native_lighting.entries,i);
        if(light->mask && predicate(light,mask) && (light->enabled || light->disabled)) return i+1;
    }
    return 0;
}
s32 func_800C85A0(NativeLightPredicate predicate,s32 mask) {return func_800C8678(0,predicate,mask);}
s32 func_800C8760(s32 kind,s32 mask) {
    return kind>=0 && kind<3 ? func_800C85A0(D_8011A9C0[kind],mask) : 0;
}
s32 func_800C878C(s32 previous,s32 kind,s32 mask) {
    return kind>=0 && kind<3 ? func_800C8678(previous,D_8011A9C0[kind],mask) : 0;
}
void func_800C87B8(s32 *out) {rare_memcpy(out,native_lighting.ambient,12);}
void func_800C87DC(s32 *out) {rare_memcpy(out,native_lighting.primary_color,12);}
void func_800C8800(BtIntPtr id,f32 *out) {
    NativeLight *light=native_light(id);if(light)for(s32 i=0;i<3;++i)out[i]=light->position[i];
}
void func_800C883C(s32 id,void *out) {
    NativeLight *light=native_light(id);if(light){((f32 *)out)[0]=light->range[0];((f32 *)out)[1]=light->range[1];}
}
void func_800C8898(s32 id,f32 *out) {
    NativeLight *light=native_light(id);if(light){out[0]=light->range[0];out[1]=light->range[1];out[2]=light->inverse_range;}
}
void func_800C8900(s32 id,s32 *out) {
    NativeLight *light=native_light(id);for(s32 i=0;i<3;++i)out[i]=light && light->enabled ? light->color[i] : 0;
}
void func_800C8960(s32 *color,f32 *direction) {
    if(color)rare_memcpy(color,native_lighting.secondary_color,12);
    if(direction)rare_memcpy(direction,native_lighting.secondary_direction,12);
}
u8 func_800C89A8(s32 id) {NativeLight *light=native_light(id);return light ? light->mask : 0;}
u8 func_800C89D8(s32 id) {NativeLight *light=native_light(id);return light ? light->moved : 0;}
void func_800C8A08(void) {
    if(!native_lighting.entries)return;
    for(s32 i=0;i<vector_size(native_lighting.entries);++i) {
        NativeLight *light=vector_at(native_lighting.entries,i);
        if(light->mask) {
            if(light->dirty==2)light->mask=0;else light->dirty=0;
            light->disabled=0;light->moved=0;
        }
    }
}
s32 func_800C8A98(void) {
    NativeLight *light; s32 i;
    if(!native_lighting.entries)func_800C90AC();
    for(i=0;i<vector_size(native_lighting.entries);++i)if(!((NativeLight *)vector_at(native_lighting.entries,i))->mask)break;
    if(i==vector_size(native_lighting.entries)) {light=vector_push_back(&native_lighting.entries);*light=(NativeLight){0};}
    else light=vector_at(native_lighting.entries,i);
    light->mask=11;light->dirty=light->enabled=1;
    light->permanent=light->disabled=light->moved=0;
    func_800C8CB8(i+1,D_8011A9CC);func_800C8D4C(i+1,D_8011A9D8);func_800C8E84(i+1,D_8011A9E0);
    return i+1;
}
void func_800C8B84(volatile s32 id) {
    NativeLight *light=native_light(id);
    if(!light)return;
    func_800C8CB8(id,D_8011A9EC);func_800C8D4C(id,D_8011A9F8);func_800C8E84(id,D_8011AA00);light->dirty=2;
}
s32 func_800C8BF4(void) {return native_lighting.entries ? vector_size(native_lighting.entries) : 0;}
s32 func_800C8C18(void) {
    s32 count=0;
    for(s32 i=0;i<func_800C8BF4();++i){NativeLight *light=vector_at(native_lighting.entries,i);if(light->mask && light->permanent)++count;}
    return count;
}
void func_800C8C90(s32 *color) {rare_memcpy(native_lighting.ambient,color,12);}
void func_800C8CB8(s32 id,f32 *position) {
    void func_800EE940(s16 *,f32 *);
    s16 converted[3];NativeLight *light=native_light(id);if(!light)return;
    func_800EE940(converted,position);
    if(light->position[0]!=converted[0] || light->position[1]!=converted[1] || light->position[2]!=converted[2]) {
        rare_memcpy(light->position,converted,6);light->moved=light->dirty=1;
    }
}
void func_800C8D4C(s32 id,f32 *input) {
    NativeLight *light=native_light(id);s16 first=(s32)input[0],last=(s32)input[1];if(!light)return;
    if(last<first)last=first;if(last<first)first=last;if(first==last)++last;
    if(light->range[0]!=first || light->range[1]!=last) {
        light->range[0]=first;light->range[1]=last;light->inverse_range=1.0f/(last-first);light->moved=light->dirty=1;
    }
}
void func_800C8E54(s32 id,f32 first,f32 last) {f32 range[2]={first,last};func_800C8D4C(id,range);}
void func_800C8E84(s32 id,u32 *color) {
    NativeLight *light=native_light(id);if(!light)return;
    if(light->color[0]!=color[0] || light->color[1]!=color[1] || light->color[2]!=color[2]) {
        for(s32 i=0;i<3;++i)light->color[i]=color[i];light->dirty=1;
    }
}
void func_800C8F08(s32 *color,f32 *direction) {
    void func_800EF2A0(f32 *);
    if(color)rare_memcpy(native_lighting.secondary_color,color,12);
    if(direction){rare_memcpy(native_lighting.secondary_direction,direction,12);func_800EF2A0(native_lighting.secondary_direction);}
}
void func_800C8F64(s32 id,s32 mask) {
    NativeLight *light=native_light(id);if(light && light->mask!=mask){light->mask=mask;light->dirty=1;}
}
void func_800C8FB0(s32 id,u32 r,u32 g,u32 b) {u32 color[3]={r,g,b};func_800C8E84(id,color);}
void func_800C8FE0(s32 id,s32 enabled) {
    NativeLight *light=native_light(id);if(!light)return;
    if(!light->dirty)light->dirty=enabled!=light->enabled;
    light->enabled=enabled;if(!enabled)light->disabled=1;
}
u8 func_800C9044(s32 id) {NativeLight *light=native_light(id);return light ? light->enabled : 0;}
void func_800C9074(void) {if(native_lighting.entries)native_lighting.entries=vector_defrag(native_lighting.entries);}
void func_800C90AC(void) {_gclightsDll_entrypoint_0(&native_lighting);}
void func_800C90D0(void) {_gclightsDll_entrypoint_1(&native_lighting);}
void func_800C90F4(void *stream) {_gclightsDll_entrypoint_2(&native_lighting,stream);}
NativeLighting *func_800C911C(void) {return &native_lighting;}
s32 func_800C9128(f32 *position) {return _gclightsDll_entrypoint_3(&native_lighting,position);}
#else
#include "core2/1EA1DA0.h"

extern s32 D_8012AB00;

s32 func_800C84B0(s32 arg0) {
    extern LightCategoryList D_8011A930;
    s32 i;
    s32 temp_v0;

    temp_v0 = arg0 & 0x1F00;
    if (arg0 & 0x20000) {
        return 4;
    }
    if (temp_v0 == 0) {
        return 0;
    }
    for (i = 0; i < 17; i++) {
        if (temp_v0 == D_8011A930.rows[i].flags) {
            return D_8011A930.rows[i].category;
        }
    }
    return 1;
}

int func_800C8560(void *arg0, s32 arg1) {
    return ((u8 *)arg0)[0x16] && (((u8 *)arg0)[0x15] & arg1);
}

u32 func_800C8588(u8 *arg0, s32 arg1) {
    return arg0[0x14];
}

u32 func_800C8594(u8 *arg0, u32 arg1) {
    return arg0[0x15] & arg1;
}

s32 func_800C85A0(s32 (*arg0)(u32, s32), s32 arg1) {
    u32 vector_begin(s32);
    u32 vector_end(s32);
    u32 begin;
    u32 end;
    u32 current;

    begin = vector_begin(D_8012AB00);
    end = vector_end(D_8012AB00);
    for (current = begin; current < end; current += 0x1C) {
        if (((u8 *)current)[0x15] && arg0(current, arg1)
            && (((u8 *)current)[0x17] || ((u8 *)current)[0x18])) {
            return (s32)(current - begin) / 28 + 1;
        }
    }
    return 0;
}

s32 func_800C8678(s32 arg0, s32 (*arg1)(u32, s32), s32 arg2) {
    void *vector_at(s32, s32);
    u32 vector_begin(s32);
    u32 vector_end(s32);
    u32 begin;
    u32 end;
    u32 current;

    begin = vector_begin(D_8012AB00);
    current = (u32)vector_at(D_8012AB00, arg0 - 1);
    end = vector_end(D_8012AB00);
    for (current += 0x1C; current < end; current += 0x1C) {
        if (((u8 *)current)[0x15] && arg1(current, arg2)
            && (((u8 *)current)[0x17] || ((u8 *)current)[0x18])) {
            return (s32)(current - begin) / 28 + 1;
        }
    }
    return 0;
}

s32 func_800C8760(s32 arg0, s32 arg1) {
    extern LightPredicate D_8011A9C0[3];
    return func_800C85A0(D_8011A9C0[arg0], arg1);
}

 s32 func_800C878C(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800C8678(s32, s32 (*)(u32, s32), s32);
    extern LightPredicate D_8011A9C0[3];
    return func_800C8678(arg0, D_8011A9C0[arg1], arg2);
}

void func_800C87B8(s32 *arg0) {
    s32 func_800EE830();
    extern s32 D_8012AB04;
    func_800EE830(arg0, &D_8012AB04);
}

void func_800C87DC(s32 *arg0) {
    s32 func_800EE830();
    extern s32 D_8012AB10;
    func_800EE830(arg0, &D_8012AB10);
}

void func_800C8800(s32 arg0, f32 *arg1) {
    void func_800EE88C(f32 dst[3], s16 src[3]);
    void *vector_at(s32, s32);
    func_800EE88C(arg1, vector_at(D_8012AB00, arg0 - 1));
}

/* extern */

void func_800C883C(s32 arg0, void *arg1) {
    void *vector_at(s32, s32);
    void *temp_v0;

    temp_v0 = vector_at(D_8012AB00, arg0 - 1);
    (*(f32 *)((s8 *)(arg1) + (0))) = (f32) (*(s16 *)((s8 *)(temp_v0) + (6)));
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) (*(s16 *)((s8 *)(temp_v0) + (8)));
}

void func_800C8898(s32 arg0, f32 *arg1) {
    void *vector_at(s32, s32);
    u8 *temp_v0;

    temp_v0 = vector_at(D_8012AB00, arg0 - 1);
    (*(f32 *)((s8 *)(arg1) + (0))) = (f32) (*(s16 *)((s8 *)(temp_v0) + (6)));
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) (*(s16 *)((s8 *)(temp_v0) + (8)));
    (*(f32 *)((s8 *)(arg1) + (8))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0x10)));
}

void func_800C8900(s32 arg0, s32 *arg1) {
    void func_800EFA88(void *arg0, s32 arg1, s32 arg2, s32 arg3);
    void func_800F2EE0(void *arg0, void *arg1);
    void *vector_at(s32, s32);
    u8 *temp_v0;

    temp_v0 = vector_at(D_8012AB00, arg0 - 1);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x17))) == 0) {
        func_800EFA88(arg1, 0, 0, 0);
        return;
    }
    func_800F2EE0(arg1, temp_v0 + 0xA);
}

void func_800C8960(s32 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 func_800EE830(s32 *, s32);
    extern s32 D_8012AB1C;
    extern f32 D_8012AB28;
    if (arg0 != NULL) {
        func_800EE830(arg0, (s32) &D_8012AB1C);
    }
    if (arg1 != NULL) {
        func_800EE7F8(arg1, &D_8012AB28);
    }
}

/* extern */

u8 func_800C89A8(s32 arg0) {
    void *vector_at(s32, s32);
    return (*(u8 *)((s8 *)(vector_at(D_8012AB00, arg0 - 1)) + (0x15)));
}

/* extern */

u8 func_800C89D8(s32 arg0) {
    void *vector_at(s32, s32);
    return (*(u8 *)((s8 *)(vector_at(D_8012AB00, arg0 - 1)) + (0x19)));
}

void func_800C8A08(void) {
    u32 vector_begin(s32);
    u32 vector_end(s32);
    extern s32 D_8012AB00;
    u32 sp1C;
    u32 temp_v0;
    u32 var_v1;

    sp1C = vector_begin(D_8012AB00);
    temp_v0 = vector_end(D_8012AB00);
    var_v1 = sp1C;
    if (var_v1 < temp_v0) {
        do {
            if ((*(u8 *)((s8 *)(var_v1) + (0x15))) != 0) {
                if ((*(u8 *)((s8 *)(var_v1) + (0x16))) == 2) {
                    (*(u8 *)((s8 *)(var_v1) + (0x15))) = 0U;
                } else {
                    (*(u8 *)((s8 *)(var_v1) + (0x16))) = 0U;
                }
                if ((*(u8 *)((s8 *)(var_v1) + (0x18))) != 0) {
                    (*(u8 *)((s8 *)(var_v1) + (0x18))) = 0U;
                }
                (*(s8 *)((s8 *)(var_v1) + (0x19))) = 0;
            }
            var_v1 += 0x1C;
        } while (var_v1 < temp_v0);
    }
}

s32 func_800C8A98(void) {
    struct Entry { u8 pad[0x14]; u8 flag14; u8 flag15; u8 flag16; u8 flag17; u8 flag18; u8 flag19; u8 tail[2]; };
    u32 vector_begin(s32);
    u32 vector_end(s32);
    s32 vector_index_of(s32, void *);
    void *vector_push_back(s32 *);
    extern f32 D_8011A9CC[];
    extern f32 D_8011A9D8[];
    extern u32 D_8011A9E0[];
    u32 sp24;
    u32 temp_v0;
    u32 var_a2;
    s32 sp18;

    sp24 = vector_begin(D_8012AB00);
    temp_v0 = vector_end(D_8012AB00);
    for (var_a2 = sp24; var_a2 < temp_v0; var_a2 += 0x1C) {
        if (*(u8 *)(var_a2 + 0x15) == 0) {
            break;
        }
    }
    if (var_a2 == temp_v0) {
        var_a2 = vector_push_back(&D_8012AB00);
    }
    sp18 = vector_index_of(D_8012AB00, (void *) var_a2) + 1;
    ((struct Entry *)var_a2)->flag15 = 0xB;
    ((struct Entry *)var_a2)->flag16 = ((struct Entry *)var_a2)->flag17 = 1;
    ((struct Entry *)var_a2)->flag14 = 0;
    ((struct Entry *)var_a2)->flag18 = 0;
    ((struct Entry *)var_a2)->flag19 = 0;
    func_800C8CB8(sp18, D_8011A9CC);
    func_800C8D4C(sp18, D_8011A9D8);
    func_800C8E84(sp18, D_8011A9E0);
    return sp18;
}

void func_800C8B84(volatile s32 arg0) {
    void *vector_at(s32, s32);
    void *sp1C;
    extern f32 D_8011A9EC[];
    extern f32 D_8011A9F8[];
    extern u32 D_8011AA00[];

    sp1C = vector_at(D_8012AB00, arg0 - 1);
    func_800C8CB8(arg0, D_8011A9EC);
    func_800C8D4C(arg0, D_8011A9F8);
    func_800C8E84(arg0, D_8011AA00);
    ((s8 *)sp1C)[0x16] = 2;
}

/* extern */

void func_800C8BF4(void) {
    s32 vector_size(s32);
    vector_size(D_8012AB00);
}

/* extern */

s32 func_800C8C18(void) {
    struct Entry { u8 pad[0x14]; u8 flag14; u8 flag15; u16 rest; u32 tail; };
    u32 vector_begin(s32);
    u32 vector_end(s32);
    struct Entry *sp24 = (struct Entry *)vector_end(D_8012AB00);
    s32 pad20;
    s32 var_a1;
    s32 pad18;
    struct Entry *temp_v0_2;
    struct Entry *var_v1;

    var_a1 = 0; temp_v0_2 = (struct Entry *)vector_begin(D_8012AB00);
    var_v1 = temp_v0_2;
    if (temp_v0_2 < sp24) {
        do {
            if ((var_v1->flag15 != 0) && (var_v1->flag14 != 0)) {
                var_a1 += 1;
            }
            var_v1++;
        } while (var_v1 < sp24);
    }
    return var_a1;
}

void func_800C8C90(s32 arg0) {
    s32 func_800EE830(s32 *, s32);
    extern s32 D_8012AB04;
    func_800EE830(&D_8012AB04, arg0);
}

void func_800C8CB8(s32 arg0, f32 *arg1) {
    void *vector_at(s32, s32);
    void func_800EE814(s16 dst[3], s16 src[3]);
    void func_800EE940(s16 dst[3], f32 src[3]);
    s16 *entry;
    s16 position[3];

    entry = vector_at(D_8012AB00, arg0 - 1);
    func_800EE940(position, arg1);
    if (entry[0] != position[0] || entry[1] != position[1] || entry[2] != position[2]) {
        func_800EE814(entry, position);
        ((u8 *)entry)[0x19] = 1;
        ((u8 *)entry)[0x16] = ((u8 *)entry)[0x19];
    }
}

void func_800C8D4C(s32 arg0, f32 *arg1) {
    void *vector_at(s32, s32);
    s16 range[3];
    s16 *entry;

    entry = vector_at(D_8012AB00, arg0 - 1);
    range[0] = (s32)arg1[0];
    range[1] = (s32)arg1[1];
    if (range[1] < range[0]) {
        range[1] = range[0];
    }
    if (range[1] < range[0]) {
        range[0] = range[1];
    }
    if (range[0] == range[1]) {
        range[1] += 1;
    }
    if (entry[3] != range[0] || entry[4] != range[1]) {
        entry[3] = range[0];
        entry[4] = range[1];
        *(f32 *)(entry + 8) = 1.0f / (range[1] - range[0]);
        ((u8 *)entry)[0x19] = 1;
        ((u8 *)entry)[0x16] = ((u8 *)entry)[0x19];
    }
}

void func_800C8E54(s32 arg0, f32 arg1, f32 arg2) { f32 sp18[2]; sp18[0] = arg1; sp18[1] = arg2; func_800C8D4C(arg0, sp18); }

void func_800C8E84(s32 arg0, u32 *arg1) {
    void *vector_at(s32, s32);
    u8 *entry;

    entry = vector_at(D_8012AB00, arg0 - 1);
    if (entry[0xA] != arg1[0] || entry[0xB] != arg1[1] || entry[0xC] != arg1[2]) {
        entry[0xA] = arg1[0];
        entry[0xB] = arg1[1];
        entry[0xC] = arg1[2];
        entry[0x16] = 1;
    }
}

void func_800C8F08(s32 arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 func_800EE830(s32 *, s32);
    void func_800EF2A0(f32[3]);
    extern s32 D_8012AB1C;
    extern f32 D_8012AB28;
    if (arg0 != 0) {
        func_800EE830(&D_8012AB1C, arg0);
    }
    if (arg1 != NULL) {
        func_800EE7F8(&D_8012AB28, arg1);
        func_800EF2A0(&D_8012AB28);
    }
}

/* extern */

void func_800C8F64(s32 arg0, s32 arg1) {
    void *vector_at(s32, s32);
    void *temp_v0;

    temp_v0 = vector_at(D_8012AB00, arg0 - 1);
    if (arg1 != (*(u8 *)((s8 *)(temp_v0) + (0x15)))) {
        (*(u8 *)((s8 *)(temp_v0) + (0x15))) = (u8) arg1;
        (*(s8 *)((s8 *)(temp_v0) + (0x16))) = 1;
    }
}

void func_800C8FB0(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 sp1C[3];
    sp1C[0] = arg1;
    sp1C[1] = arg2;
    sp1C[2] = arg3;
    func_800C8E84(arg0, sp1C);
}

void func_800C8FE0(s32 arg0, s32 arg1) {
    void *vector_at(s32, s32);
    u8 *temp_v0;

    temp_v0 = vector_at(D_8012AB00, arg0 - 1);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x16))) == 0) {
        (*(u8 *)((s8 *)(temp_v0) + (0x16))) = (u8) (arg1 != (*(u8 *)((s8 *)(temp_v0) + (0x17))));
    }
    (*(u8 *)((s8 *)(temp_v0) + (0x17))) = (u8) arg1;
    if (arg1 == 0) {
        (*(s8 *)((s8 *)(temp_v0) + (0x18))) = 1;
    }
}

/* extern */

u8 func_800C9044(s32 arg0) {
    void *vector_at(s32, s32);
    return (*(u8 *)((s8 *)(vector_at(D_8012AB00, arg0 - 1)) + (0x17)));
}

/* extern */

void func_800C9074(void) {
    s32 vector_defrag(s32);
    if (D_8012AB00 != 0) {
        D_8012AB00 = vector_defrag(D_8012AB00);
    }
}

void func_800C90AC()
{
    _gclightsDll_entrypoint_0(&D_8012AB00);
}

void func_800C90D0()
{
    _gclightsDll_entrypoint_1(&D_8012AB00);
}

/* extern */

void func_800C90F4(s32 arg0) {
    s32 _gclightsDll_entrypoint_2(s32 *, s32);
    _gclightsDll_entrypoint_2(&D_8012AB00, arg0);
}

void * func_800C911C(void) {
    return &D_8012AB00;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800C9128(s32 arg0) {
    s32 _gclightsDll_entrypoint_3(s32 *, s32);
    BT_NATIVE_ONLY(return) _gclightsDll_entrypoint_3(&D_8012AB00, arg0);
}


#endif
